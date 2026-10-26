import { 
  CheckCircle2, 
  AlertTriangle, 
  Cpu,
  Info,
  Check
} from 'lucide-react';
import type { Process, Resource, BankersResult, TextbookStep } from '../lib/bankers';

interface BankersTableProps {
  processes: Process[];
  resources: Resource[];
  result: BankersResult;
}

export function BankersTable({ processes, resources, result }: BankersTableProps) {
  const renderVectorBadges = (vec: Record<string, number> | undefined, colorClass = 'bg-slate-100 text-slate-800') => {
    if (!vec) return null;
    return (
      <div className="flex flex-wrap items-center gap-1.5 font-mono text-xs">
        {resources.map(r => (
          <span 
            key={r.id} 
            className={`px-2 py-0.5 rounded border-2 border-slate-300 font-bold ${colorClass}`}
            title={`${r.name}: ${vec[r.id] ?? 0}`}
          >
            <span className="text-[10px] text-slate-500 mr-1">{r.name}:</span>
            {vec[r.id] ?? 0}
          </span>
        ))}
      </div>
    );
  };

  return (
    <div className="bg-white rounded-2xl shadow-sm border-2 border-slate-300 overflow-hidden flex flex-col">
      {/* Header Banner */}
      <div className="p-5 border-b-2 border-slate-300 bg-slate-900 text-white flex flex-col sm:flex-row justify-between sm:items-center gap-4">
        <div>
          <div className="flex items-center gap-2">
            <span className="p-1.5 bg-blue-600/30 border border-blue-500/40 rounded-lg text-blue-400">
              <Cpu size={22} />
            </span>
            <h2 className="text-2xl font-black tracking-tight">Banker's Algorithm</h2>
          </div>
          <p className="text-slate-400 text-xs sm:text-sm mt-1">
            Step-by-step state determination showing how processes run to completion, free their resources, and update available resources.
          </p>
        </div>

        {result.isSafe && (
          <div className="flex items-center gap-2 bg-slate-800 px-3.5 py-2 rounded-xl border border-slate-700 self-start sm:self-auto text-xs">
            <span className="text-slate-400 font-bold uppercase tracking-wider text-[11px]">Safe Sequence:</span>
            <span className="font-extrabold font-mono text-emerald-400 text-sm">
              &lt; {result.safeSequence.map(id => processes.find(p => p.id === id)?.name || id).join(' → ')} &gt;
            </span>
          </div>
        )}
      </div>

      {/* Sub-header status bar */}
      <div className="px-5 py-3.5 bg-slate-50 border-b-2 border-slate-300 flex flex-wrap items-center justify-between gap-3 text-sm">
        <div className="flex flex-wrap items-center gap-3">
          <span className="text-slate-700 font-bold text-xs uppercase tracking-wider">Initial Available Resources (A):</span>
          {renderVectorBadges(result.initialAvailable, 'bg-emerald-50 text-emerald-900 border-emerald-300')}
        </div>

        <div className="flex items-center gap-2">
          <span className="text-slate-700 font-bold text-xs uppercase tracking-wider">Safety Determination:</span>
          {result.isSafe ? (
            <span className="inline-flex items-center gap-1.5 text-xs font-bold px-3 py-1 rounded-full bg-emerald-100 text-emerald-900 border-2 border-emerald-400">
              <CheckCircle2 size={15} className="text-emerald-700" />
              SAFE STATE
            </span>
          ) : (
            <span className="inline-flex items-center gap-1.5 text-xs font-bold px-3 py-1 rounded-full bg-rose-100 text-rose-900 border-2 border-rose-400">
              <AlertTriangle size={15} className="text-rose-700" />
              UNSAFE STATE (DEADLOCK)
            </span>
          )}
        </div>
      </div>

      {/* Step-by-Step Cards */}
      <div className="p-6 flex flex-col gap-8 bg-slate-100/50">
        <div className="space-y-8">
          {result.textbookSteps.map((step: TextbookStep) => {
            const isInitial = step.stepLetter === 'a';
            const isDeadlock = step.isDeadlocked;

            return (
              <div 
                key={step.stepLetter}
                className={`bg-white rounded-xl border-2 transition-all p-5 shadow-sm ${
                  isDeadlock 
                    ? 'border-rose-400 bg-rose-50/20' 
                    : isInitial 
                      ? 'border-slate-400' 
                      : 'border-slate-400'
                }`}
              >
                {/* Step Title Header */}
                <div className="flex items-center justify-between border-b-2 border-slate-200 pb-3 mb-4">
                  <div className="flex items-center gap-2">
                    <span className={`px-3 py-1 rounded-lg text-sm font-extrabold tracking-wide uppercase ${
                      isDeadlock 
                        ? 'bg-rose-600 text-white shadow-sm' 
                        : isInitial 
                          ? 'bg-slate-900 text-white shadow-sm' 
                          : 'bg-blue-600 text-white shadow-sm'
                    }`}>
                      {step.title}
                    </span>
                  </div>

                  {step.completedProcessName && (
                    <span className="inline-flex items-center gap-1.5 text-xs font-bold text-emerald-800 bg-emerald-100 px-3 py-1 rounded-lg border-2 border-emerald-300">
                      <Check size={15} className="text-emerald-700 font-extrabold" /> Process {step.completedProcessName} Runs to Completion & Releases Resources
                    </span>
                  )}

                  {isDeadlock && (
                    <span className="inline-flex items-center gap-1.5 text-xs font-bold text-rose-800 bg-rose-100 px-3 py-1 rounded-lg border-2 border-rose-300">
                      <AlertTriangle size={15} className="text-rose-700" /> Deadlock (System Stalled)
                    </span>
                  )}
                </div>

                {/* 3 Tables Side-by-Side (C, R, A) with Dark, High-Contrast Borders */}
                <div className="grid grid-cols-1 lg:grid-cols-12 gap-5 items-start">
                  
                  {/* Maximum claim matrix (C) */}
                  <div className="lg:col-span-5 bg-white p-3.5 rounded-xl border-2 border-slate-300 shadow-sm">
                    <h4 className="text-xs font-black text-slate-800 uppercase tracking-wider text-center mb-2.5">
                      Maximum claim matrix (C)
                    </h4>
                    <div className="overflow-x-auto">
                      <table className="w-full border-collapse text-xs text-center border-2 border-slate-600 bg-white">
                        <thead>
                          <tr className="bg-slate-200 border-b-2 border-slate-600">
                            <th className="p-2 border-r-2 border-slate-600 text-slate-800 font-black w-14"></th>
                            {resources.map(r => (
                              <th key={r.id} className="p-2 border-r border-slate-600 last:border-r-0 font-black text-slate-900 text-xs">
                                {r.name}
                              </th>
                            ))}
                          </tr>
                        </thead>
                        <tbody>
                          {processes.map(p => {
                            const isCompleted = step.maxMatrixSnapshot[p.id] && 
                              resources.every(r => (step.maxMatrixSnapshot[p.id][r.id] ?? 0) === 0);
                            const isJustCompleted = step.completedProcessId === p.id;

                            return (
                              <tr 
                                key={p.id} 
                                className={`border-b border-slate-400 last:border-b-0 ${
                                  isJustCompleted 
                                    ? 'bg-emerald-50' 
                                    : isCompleted 
                                      ? 'bg-slate-50 text-slate-400' 
                                      : 'hover:bg-slate-50'
                                }`}
                              >
                                <td className="p-2 border-r-2 border-slate-600 font-extrabold text-slate-900 bg-slate-100">
                                  {p.name}
                                </td>
                                {resources.map(r => {
                                  const val = step.maxMatrixSnapshot[p.id]?.[r.id] ?? 0;
                                  return (
                                    <td 
                                      key={r.id} 
                                      className={`p-2 border-r border-slate-400 last:border-r-0 font-mono text-sm font-bold ${
                                        isJustCompleted && val === 0 ? 'text-emerald-700 font-extrabold' : 'text-slate-800'
                                      }`}
                                    >
                                      {val}
                                    </td>
                                  );
                                })}
                              </tr>
                            );
                          })}
                        </tbody>
                      </table>
                    </div>
                  </div>

                  {/* Allocation matrix (R) */}
                  <div className="lg:col-span-5 bg-white p-3.5 rounded-xl border-2 border-slate-300 shadow-sm">
                    <h4 className="text-xs font-black text-slate-800 uppercase tracking-wider text-center mb-2.5">
                      Allocation matrix (R)
                    </h4>
                    <div className="overflow-x-auto">
                      <table className="w-full border-collapse text-xs text-center border-2 border-slate-600 bg-white">
                        <thead>
                          <tr className="bg-slate-200 border-b-2 border-slate-600">
                            <th className="p-2 border-r-2 border-slate-600 text-slate-800 font-black w-14"></th>
                            {resources.map(r => (
                              <th key={r.id} className="p-2 border-r border-slate-600 last:border-r-0 font-black text-slate-900 text-xs">
                                {r.name}
                              </th>
                            ))}
                          </tr>
                        </thead>
                        <tbody>
                          {processes.map(p => {
                            const isCompleted = step.allocationMatrixSnapshot[p.id] && 
                              resources.every(r => (step.allocationMatrixSnapshot[p.id][r.id] ?? 0) === 0);
                            const isJustCompleted = step.completedProcessId === p.id;

                            return (
                              <tr 
                                key={p.id} 
                                className={`border-b border-slate-400 last:border-b-0 ${
                                  isJustCompleted 
                                    ? 'bg-emerald-50' 
                                    : isCompleted 
                                      ? 'bg-slate-50 text-slate-400' 
                                      : 'hover:bg-slate-50'
                                }`}
                              >
                                <td className="p-2 border-r-2 border-slate-600 font-extrabold text-slate-900 bg-slate-100">
                                  {p.name}
                                </td>
                                {resources.map(r => {
                                  const val = step.allocationMatrixSnapshot[p.id]?.[r.id] ?? 0;
                                  return (
                                    <td 
                                      key={r.id} 
                                      className={`p-2 border-r border-slate-400 last:border-r-0 font-mono text-sm font-bold ${
                                        isJustCompleted && val === 0 ? 'text-emerald-700 font-extrabold' : 'text-slate-800'
                                      }`}
                                    >
                                      {val}
                                    </td>
                                  );
                                })}
                              </tr>
                            );
                          })}
                        </tbody>
                      </table>
                    </div>
                  </div>

                  {/* Available Resources (A) */}
                  <div className="lg:col-span-2 bg-white p-3.5 rounded-xl border-2 border-slate-300 shadow-sm">
                    <h4 className="text-xs font-black text-slate-800 uppercase tracking-wider text-center mb-2.5">
                      Available Resources (A)
                    </h4>
                    <div className="overflow-x-auto">
                      <table className="w-full border-collapse text-xs text-center border-2 border-slate-600 bg-white">
                        <thead>
                          <tr className="bg-slate-200 border-b-2 border-slate-600">
                            {resources.map(r => (
                              <th key={r.id} className="p-2 border-r border-slate-600 last:border-r-0 font-black text-slate-900 text-xs">
                                {r.name}
                              </th>
                            ))}
                          </tr>
                        </thead>
                        <tbody>
                          <tr>
                            {resources.map(r => (
                              <td key={r.id} className="p-2.5 border-r border-slate-400 last:border-r-0 font-extrabold text-base font-mono text-blue-800 bg-blue-50/50">
                                {step.availableSnapshot[r.id] ?? 0}
                              </td>
                            ))}
                          </tr>
                        </tbody>
                      </table>
                    </div>
                  </div>

                </div>

                {/* Short lines explanation below each step */}
                <div className="mt-4 pt-3.5 border-t-2 border-slate-300 bg-slate-50 p-4 rounded-xl border border-slate-200">
                  <h5 className="text-xs font-black text-slate-700 uppercase tracking-wider mb-2 flex items-center gap-1.5">
                    <Info size={14} className="text-blue-600" />
                    What happened in this step:
                  </h5>
                  <ul className="space-y-1.5 text-xs text-slate-800 font-medium">
                    {step.explanationLines.map((line, idx) => (
                      <li key={idx} className="flex items-start gap-2">
                        <span className="text-blue-600 mt-0.5 font-black text-sm leading-none">•</span>
                        <span className="leading-relaxed">{line}</span>
                      </li>
                    ))}
                  </ul>
                </div>

              </div>
            );
          })}
        </div>
      </div>
    </div>
  );
}
