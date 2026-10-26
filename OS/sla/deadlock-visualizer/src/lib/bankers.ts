export type Process = {
  id: string;
  name: string;
};

export type Resource = {
  id: string;
  name: string;
  totalInstances: number;
};

// matrix[processId][resourceId] = number
export type ResourceMatrix = Record<string, Record<string, number>>;

export type ExecutionStep = {
  stepNumber: number;
  processId: string;
  processName: string;
  workBefore: Record<string, number>;
  need: Record<string, number>;
  allocation: Record<string, number>;
  workAfter: Record<string, number>;
  isSatisfied: boolean;
  explanation: string;
  finishSnapshot: Record<string, boolean>;
};

export type CandidateCheck = {
  processId: string;
  processName: string;
  work: Record<string, number>;
  need: Record<string, number>;
  canAllocate: boolean;
  reason: string;
};

export type PassTrace = {
  passNumber: number;
  workAtStart: Record<string, number>;
  checks: CandidateCheck[];
  executedProcessId?: string;
  executedProcessName?: string;
  workAtEnd: Record<string, number>;
};

export type DeadlockAnalysis = {
  processId: string;
  processName: string;
  need: Record<string, number>;
  work: Record<string, number>;
  allocationHeld: Record<string, number>;
  missingResources: {
    resourceId: string;
    resourceName: string;
    needed: number;
    available: number;
    deficit: number;
  }[];
};

export type TextbookStep = {
  stepLetter: string; // 'a', 'b', 'c', 'd', 'e', ...
  title: string;      // "(a) Initial state", "(b) P2 runs to completion", etc.
  completedProcessId?: string;
  completedProcessName?: string;
  maxMatrixSnapshot: ResourceMatrix;
  allocationMatrixSnapshot: ResourceMatrix;
  availableSnapshot: Record<string, number>;
  explanationLines: string[];
  isDeadlocked?: boolean;
};

export type BankersResult = {
  isSafe: boolean;
  safeSequence: string[];
  deadlockedProcesses: string[];
  deadlockDetails: DeadlockAnalysis[];
  initialAvailable: Record<string, number>;
  needMatrix: ResourceMatrix;
  steps: ExecutionStep[];
  passTraces: PassTrace[];
  textbookSteps: TextbookStep[];
};

function cloneMatrix(mat: ResourceMatrix): ResourceMatrix {
  const res: ResourceMatrix = {};
  for (const p in mat) {
    res[p] = { ...mat[p] };
  }
  return res;
}

export function runBankersAlgorithm(
  processes: Process[],
  resources: Resource[],
  allocation: ResourceMatrix,
  max: ResourceMatrix
): BankersResult {
  const numProcesses = processes.length;

  // Calculate Need matrix: Need[i][j] = Math.max(0, Max[i][j] - Allocation[i][j])
  const need: ResourceMatrix = {};
  processes.forEach(p => {
    need[p.id] = {};
    resources.forEach(r => {
      const alloc = allocation[p.id]?.[r.id] || 0;
      const m = max[p.id]?.[r.id] || 0;
      need[p.id][r.id] = Math.max(0, m - alloc);
    });
  });

  // Calculate Initial Available: Available[j] = Total[j] - Sum(Allocation[i][j])
  const available: Record<string, number> = {};
  resources.forEach(r => {
    let allocated = 0;
    processes.forEach(p => {
      allocated += allocation[p.id]?.[r.id] || 0;
    });
    available[r.id] = Math.max(0, r.totalInstances - allocated);
  });

  const finish: Record<string, boolean> = {};
  processes.forEach(p => {
    finish[p.id] = false;
  });

  const safeSequence: string[] = [];
  const steps: ExecutionStep[] = [];
  const passTraces: PassTrace[] = [];
  const textbookSteps: TextbookStep[] = [];

  // Work tracking
  let work = { ...available };
  let currentMax = cloneMatrix(max);
  let currentAlloc = cloneMatrix(allocation);

  // Helper to format vector as (x, y, z)
  const vecStr = (vec: Record<string, number>) =>
    `(${resources.map(r => `${r.name}: ${vec[r.id] ?? 0}`).join(', ')})`;

  // Find initial candidate to mention in Initial state
  const initialCandidate = processes.find(p => {
    for (const r of resources) {
      if ((need[p.id]?.[r.id] || 0) > (available[r.id] || 0)) return false;
    }
    return true;
  });

  const initialLines: string[] = [
    `System initialized with Available Resources A = ${vecStr(available)}.`,
  ];
  if (initialCandidate) {
    const candNeedStr = `(${resources.map(r => `${r.name}: ${need[initialCandidate.id]?.[r.id] || 0}`).join(', ')})`;
    initialLines.push(
      `Candidate check: Process ${initialCandidate.name} has Need ${candNeedStr} ≤ Available ${vecStr(available)}.`,
      `Therefore, ${initialCandidate.name} can be safely granted its needed resources and run to completion first.`
    );
  } else {
    initialLines.push(
      `No process has Need ≤ Available resources. System cannot safely begin execution.`,
      `Initial state is UNSAFE (Immediate Deadlock risk).`
    );
  }

  // Record Step (a) Initial state
  textbookSteps.push({
    stepLetter: 'a',
    title: '(a) Initial state',
    maxMatrixSnapshot: cloneMatrix(currentMax),
    allocationMatrixSnapshot: cloneMatrix(currentAlloc),
    availableSnapshot: { ...work },
    explanationLines: initialLines
  });

  let count = 0;
  let passNumber = 1;

  while (count < numProcesses) {
    let found = false;
    const currentPassChecks: CandidateCheck[] = [];
    const workAtStart = { ...work };

    for (const p of processes) {
      if (!finish[p.id]) {
        // Check if Need_i <= Work for all resources
        let canAllocate = true;
        const lacking: string[] = [];
        for (const r of resources) {
          const pNeed = need[p.id]?.[r.id] || 0;
          const currWork = work[r.id] || 0;
          if (pNeed > currWork) {
            canAllocate = false;
            lacking.push(`${r.name} (Need ${pNeed} > Available ${currWork})`);
          }
        }

        currentPassChecks.push({
          processId: p.id,
          processName: p.name,
          work: { ...work },
          need: { ...need[p.id] },
          canAllocate,
          reason: canAllocate
            ? `Need ≤ Work for all resources. Process can be satisfied.`
            : `Insufficient resources: ${lacking.join(', ')}.`
        });

        if (canAllocate) {
          const workBefore = { ...work };
          const pAlloc = { ...(allocation[p.id] || {}) };

          // Work = Work + Allocation[i]
          for (const r of resources) {
            work[r.id] = (work[r.id] || 0) + (pAlloc[r.id] || 0);
          }

          finish[p.id] = true;
          safeSequence.push(p.id);
          found = true;
          count++;

          const releasedStr = `(${resources.map(r => `${r.name}: ${pAlloc[r.id] || 0}`).join(', ')})`;
          const stepExplanation = `Free resources satisfy ${p.name}'s remaining needs. ${p.name} executes to completion and releases its held allocation (${releasedStr}). Available pool increases to ${vecStr(work)}.`;

          steps.push({
            stepNumber: count,
            processId: p.id,
            processName: p.name,
            workBefore,
            need: { ...need[p.id] },
            allocation: pAlloc,
            workAfter: { ...work },
            isSatisfied: true,
            explanation: stepExplanation,
            finishSnapshot: { ...finish }
          });

          passTraces.push({
            passNumber,
            workAtStart,
            checks: currentPassChecks,
            executedProcessId: p.id,
            executedProcessName: p.name,
            workAtEnd: { ...work }
          });

          // Update snapshots for textbook view:
          // Row for process P becomes 0 in both Maximum Claim (C) and Allocation (R)
          for (const r of resources) {
            if (currentMax[p.id]) currentMax[p.id][r.id] = 0;
            if (currentAlloc[p.id]) currentAlloc[p.id][r.id] = 0;
          }

          const stepLetter = String.fromCharCode(97 + count); // 'b', 'c', 'd', ...
          
          // Determine next candidate if any
          const remainingUnfinished = processes.filter(proc => !finish[proc.id]);
          const nextCandidate = remainingUnfinished.find(proc => {
            for (const r of resources) {
              if ((need[proc.id]?.[r.id] || 0) > (work[r.id] || 0)) return false;
            }
            return true;
          });

          const stepLines: string[] = [
            `Process ${p.name} acquired required resources and executed to completion.`,
            `In Maximum claim matrix (C) and Allocation matrix (R), row ${p.name} is cleared to 0.`,
            `${p.name} releases held allocation ${releasedStr}. Available Resources (A) increase: ${vecStr(workBefore)} + ${releasedStr} = ${vecStr(work)}.`
          ];

          if (nextCandidate) {
            const nextNeedStr = `(${resources.map(r => `${r.name}: ${need[nextCandidate.id]?.[r.id] || 0}`).join(', ')})`;
            stepLines.push(
              `Next candidate: Process ${nextCandidate.name} has Need ${nextNeedStr} ≤ Available ${vecStr(work)}, so ${nextCandidate.name} can now run to completion.`
            );
          } else if (remainingUnfinished.length === 0) {
            stepLines.push(
              `All processes have completed safely! The system is verified to be in a SAFE state.`
            );
          }

          textbookSteps.push({
            stepLetter,
            title: `(${stepLetter}) ${p.name} runs to completion`,
            completedProcessId: p.id,
            completedProcessName: p.name,
            maxMatrixSnapshot: cloneMatrix(currentMax),
            allocationMatrixSnapshot: cloneMatrix(currentAlloc),
            availableSnapshot: { ...work },
            explanationLines: stepLines
          });

          passNumber++;
          // Break to restart scan from beginning with updated Work
          break;
        }
      }
    }

    if (!found) {
      // Record final pass where no candidate could be satisfied
      passTraces.push({
        passNumber,
        workAtStart,
        checks: currentPassChecks,
        workAtEnd: { ...work }
      });

      const deadlockedProcesses = processes.filter(p => !finish[p.id]).map(p => p.id);
      const deadlockDetails: DeadlockAnalysis[] = processes
        .filter(p => !finish[p.id])
        .map(p => {
          const missingResources = resources
            .filter(r => (need[p.id]?.[r.id] || 0) > (work[r.id] || 0))
            .map(r => ({
              resourceId: r.id,
              resourceName: r.name,
              needed: need[p.id]?.[r.id] || 0,
              available: work[r.id] || 0,
              deficit: (need[p.id]?.[r.id] || 0) - (work[r.id] || 0)
            }));

          return {
            processId: p.id,
            processName: p.name,
            need: { ...(need[p.id] || {}) },
            work: { ...work },
            allocationHeld: { ...(allocation[p.id] || {}) },
            missingResources
          };
        });

      const deadlockLetter = String.fromCharCode(97 + count + 1);
      const deadlockedNames = deadlockedProcesses
        .map(id => processes.find(proc => proc.id === id)?.name || id)
        .join(', ');

      textbookSteps.push({
        stepLetter: deadlockLetter,
        title: `(${deadlockLetter}) Deadlock Occurred (System Stalled)`,
        isDeadlocked: true,
        maxMatrixSnapshot: cloneMatrix(currentMax),
        allocationMatrixSnapshot: cloneMatrix(currentAlloc),
        availableSnapshot: { ...work },
        explanationLines: [
          `No remaining unfinished process has Need ≤ Available resources.`,
          `Deadlocked processes: [${deadlockedNames}]. Available ${vecStr(work)} is insufficient.`,
          `Each blocked process holds resources needed by others, forming a circular wait.`,
          `The system cannot proceed and is in an UNSAFE state (Deadlock).`
        ]
      });

      return {
        isSafe: false,
        safeSequence,
        deadlockedProcesses,
        deadlockDetails,
        initialAvailable: available,
        needMatrix: need,
        steps,
        passTraces,
        textbookSteps
      };
    }
  }

  return {
    isSafe: true,
    safeSequence,
    deadlockedProcesses: [],
    deadlockDetails: [],
    initialAvailable: available,
    needMatrix: need,
    steps,
    passTraces,
    textbookSteps
  };
}
