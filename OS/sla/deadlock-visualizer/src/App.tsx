import { useMemo, useEffect } from 'react';
import { PlusCircle, ShieldCheck, ShieldAlert, Trash2, Info, Undo2, Redo2, BookOpen } from 'lucide-react';
import type { Process, Resource, ResourceMatrix } from './lib/bankers';
import { runBankersAlgorithm } from './lib/bankers';
import { GraphView } from './components/GraphView';
import { BankersTable } from './components/BankersTable';
import { useUndo } from './hooks/useUndo';

type AppState = {
  processes: Process[];
  resources: Resource[];
  allocation: ResourceMatrix;
  max: ResourceMatrix;
};

const initialState: AppState = {
  processes: [
    { id: 'p1', name: 'P1' },
    { id: 'p2', name: 'P2' },
    { id: 'p3', name: 'P3' }
  ],
  resources: [
    { id: 'r1', name: 'R1', totalInstances: 10 },
    { id: 'r2', name: 'R2', totalInstances: 5 },
    { id: 'r3', name: 'R3', totalInstances: 7 }
  ],
  allocation: {
    p1: { r1: 0, r2: 1, r3: 0 },
    p2: { r1: 2, r2: 0, r3: 0 },
    p3: { r1: 3, r2: 0, r3: 2 }
  },
  max: {
    p1: { r1: 7, r2: 5, r3: 3 },
    p2: { r1: 3, r2: 2, r3: 2 },
    p3: { r1: 9, r2: 0, r3: 2 }
  }
};

function App() {
  const [state, setState, undo, redo, canUndo, canRedo] = useUndo<AppState>(initialState);
  const { processes, resources, allocation, max } = state;

  useEffect(() => {
    const handleKeyDown = (e: KeyboardEvent) => {
      if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === 'z') {
        if (e.shiftKey) {
          e.preventDefault();
          redo();
        } else {
          e.preventDefault();
          undo();
        }
      } else if ((e.ctrlKey || e.metaKey) && e.key.toLowerCase() === 'y') {
        e.preventDefault();
        redo();
      }
    };
    window.addEventListener('keydown', handleKeyDown);
    return () => window.removeEventListener('keydown', handleKeyDown);
  }, [undo, redo]);

  const addProcess = () => {
    setState(prev => ({
      ...prev,
      processes: [...prev.processes, { id: `p${Date.now()}`, name: `P${prev.processes.length + 1}` }]
    }));
  };

  const removeProcess = (id: string) => {
    setState(prev => {
      const newAlloc = { ...prev.allocation };
      delete newAlloc[id];
      const newMax = { ...prev.max };
      delete newMax[id];
      return {
        ...prev,
        processes: prev.processes.filter(p => p.id !== id),
        allocation: newAlloc,
        max: newMax
      };
    });
  };

  const addResource = () => {
    setState(prev => ({
      ...prev,
      resources: [...prev.resources, { id: `r${Date.now()}`, name: `R${prev.resources.length + 1}`, totalInstances: 1 }]
    }));
  };

  const removeResource = (id: string) => {
    setState(prev => {
      const newAlloc = { ...prev.allocation };
      Object.keys(newAlloc).forEach(pId => { delete newAlloc[pId][id]; });
      const newMax = { ...prev.max };
      Object.keys(newMax).forEach(pId => { delete newMax[pId][id]; });
      return {
        ...prev,
        resources: prev.resources.filter(r => r.id !== id),
        allocation: newAlloc,
        max: newMax
      };
    });
  };

  const updateMatrixValue = (type: 'allocation' | 'max', pId: string, rId: string, value: number) => {
    setState(prev => ({
      ...prev,
      [type]: {
        ...prev[type],
        [pId]: {
          ...prev[type][pId],
          [rId]: Math.max(0, value)
        }
      }
    }));
  };

  const handleGraphUpdateAllocation = (pId: string, rId: string, diff: number) => {
    setState(prev => {
      const current = prev.allocation[pId]?.[rId] || 0;
      let next = current + diff;
      if (diff === -9999) next = 0;
      return {
        ...prev,
        allocation: { ...prev.allocation, [pId]: { ...prev.allocation[pId], [rId]: Math.max(0, next) } }
      };
    });
  };

  const handleGraphUpdateMax = (pId: string, rId: string, diff: number) => {
    setState(prev => {
      const current = prev.max[pId]?.[rId] || 0;
      let next = current + diff;
      if (diff === -9999) {
         const alloc = prev.allocation[pId]?.[rId] || 0;
         next = alloc;
      }
      return {
        ...prev,
        max: { ...prev.max, [pId]: { ...prev.max[pId], [rId]: Math.max(0, next) } }
      };
    });
  };

  const loadTextbookExample = () => {
    setState({
      processes: [
        { id: 'p1', name: 'P1' },
        { id: 'p2', name: 'P2' },
        { id: 'p3', name: 'P3' },
        { id: 'p4', name: 'P4' },
      ],
      resources: [
        { id: 'r1', name: 'R1', totalInstances: 13 },
        { id: 'r2', name: 'R2', totalInstances: 7 },
        { id: 'r3', name: 'R3', totalInstances: 10 },
      ],
      max: {
        p1: { r1: 4, r2: 3, r3: 3 },
        p2: { r1: 7, r2: 2, r3: 4 },
        p3: { r1: 4, r2: 2, r3: 5 },
        p4: { r1: 5, r2: 3, r3: 3 },
      },
      allocation: {
        p1: { r1: 2, r2: 1, r3: 1 },
        p2: { r1: 7, r2: 2, r3: 3 },
        p3: { r1: 3, r2: 2, r3: 2 },
        p4: { r1: 1, r2: 1, r3: 3 },
      }
    });
  };

  const result = useMemo(() => {
    return runBankersAlgorithm(processes, resources, allocation, max);
  }, [processes, resources, allocation, max]);

  return (
    <div className="min-h-screen bg-slate-100 flex flex-col font-sans">
      <header className="bg-slate-900 text-white p-5 shadow-lg border-b border-slate-800 flex justify-between items-center z-10">
        <div>
          <h1 className="text-2xl font-extrabold tracking-tight">Deadlock Visualizer</h1>
          <p className="text-slate-400 text-sm mt-1">Banker's Algorithm & Resource Allocation Graph</p>
        </div>
        <div className="flex flex-col items-end gap-2">
          <div className="flex items-center gap-2">
            <button 
              onClick={loadTextbookExample}
              title="Load Fig. 6.19 Example from Textbook"
              className="p-1.5 px-3 rounded-lg flex items-center gap-1.5 text-xs font-bold transition-all bg-indigo-600 text-white hover:bg-indigo-500 shadow-sm"
            >
              <BookOpen size={14} /> Load Slide Example (Fig. 6.19)
            </button>
            <button 
              onClick={undo} 
              disabled={!canUndo}
              title="Undo (Ctrl+Z)"
              className={`p-1.5 rounded-lg flex items-center gap-1 text-sm font-medium transition-all ${canUndo ? 'bg-slate-800 text-white hover:bg-slate-700' : 'bg-slate-800/50 text-slate-600 cursor-not-allowed'}`}
            >
              <Undo2 size={16} /> Undo
            </button>
            <button 
              onClick={redo} 
              disabled={!canRedo}
              title="Redo (Ctrl+Y)"
              className={`p-1.5 rounded-lg flex items-center gap-1 text-sm font-medium transition-all ${canRedo ? 'bg-slate-800 text-white hover:bg-slate-700' : 'bg-slate-800/50 text-slate-600 cursor-not-allowed'}`}
            >
              <Redo2 size={16} /> Redo
            </button>
          </div>
          <div className="text-right hidden md:block">
            <p className="text-sm text-slate-300 flex items-center gap-2">
              <Info size={16} className="text-blue-400 flex-shrink-0" />
              Right-click to pan. Left-click to select (Backspace to delete). Drag nodes to move. Connect nodes to add edges.
            </p>
          </div>
        </div>
      </header>
      
      <main className="flex-1 flex flex-col p-6 gap-6 max-w-[1800px] mx-auto w-full">
        
        {/* Top Info Bar */}
        <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
          <div className={`col-span-1 lg:col-span-2 p-6 rounded-2xl shadow-sm border-2 flex items-center gap-5 transition-colors ${result.isSafe ? 'bg-green-50 border-green-400 text-green-900' : 'bg-red-50 border-red-400 text-red-900'}`}>
            <div className={`p-3 rounded-full ${result.isSafe ? 'bg-green-100' : 'bg-red-100'}`}>
              {result.isSafe ? <ShieldCheck size={36} className="text-green-600" /> : <ShieldAlert size={36} className="text-red-600" />}
            </div>
            <div className="flex-1">
              <h2 className="text-2xl font-black tracking-tight">
                {result.isSafe ? 'System is in a SAFE state' : 'System is in an UNSAFE state (Deadlock potential)'}
              </h2>
              {result.isSafe ? (
                <p className="mt-1.5 text-lg font-medium flex flex-wrap items-center gap-2">
                  <span className="text-green-700/80">Safe Sequence:</span> 
                  {result.safeSequence.map((id, idx) => (
                    <span key={id} className="inline-flex items-center gap-2">
                      <span className="bg-green-200 px-2 py-0.5 rounded text-green-800 font-bold shadow-sm">{processes.find(p=>p.id===id)?.name}</span>
                      {idx < result.safeSequence.length - 1 && <span className="text-green-400">→</span>}
                    </span>
                  ))}
                </p>
              ) : (
                <p className="mt-1.5 text-lg font-medium flex flex-wrap items-center gap-2">
                  <span className="text-red-700/80">Deadlocked Processes:</span> 
                  {result.deadlockedProcesses.map(id => (
                    <span key={id} className="bg-red-200 px-2 py-0.5 rounded text-red-900 font-bold shadow-sm">{processes.find(p=>p.id===id)?.name}</span>
                  ))}
                </p>
              )}
            </div>
          </div>
          
          <div className="col-span-1 bg-white p-5 rounded-2xl shadow-sm border border-slate-200 flex flex-col justify-center">
            <h3 className="text-sm font-bold text-slate-500 uppercase tracking-wider mb-3 flex items-center gap-2">
              <Info size={16}/> Currently Available Resources
            </h3>
            <div className="flex flex-wrap gap-3">
              {resources.map(r => (
                <div key={r.id} className="bg-slate-100 border border-slate-200 px-4 py-2 rounded-xl flex flex-col items-center min-w-[70px]">
                  <span className="text-xs font-bold text-slate-500">{r.name}</span>
                  <span className="text-2xl font-black text-slate-800">{result.initialAvailable[r.id] ?? 0}</span>
                </div>
              ))}
            </div>
            <p className="text-xs text-slate-400 mt-3">Calculated as: <code className="bg-slate-50 px-1 py-0.5 rounded border border-slate-100">Total Instances - Sum(Allocated)</code></p>
          </div>
        </div>

        <div className="flex-1 flex flex-col xl:flex-row gap-6 min-h-0">
          
          {/* Left Panel: Matrix Editor */}
          <div className="w-full xl:w-[650px] bg-white rounded-2xl shadow-sm border border-slate-200 flex flex-col overflow-hidden">
            <div className="p-4 border-b border-slate-100 bg-slate-50 flex justify-between items-center">
              <h2 className="font-bold text-slate-800">Banker's Matrices</h2>
              <div className="flex gap-2">
                <button onClick={loadTextbookExample} className="flex items-center gap-1 text-xs bg-indigo-50 text-indigo-700 hover:bg-indigo-100 px-2 py-1.5 rounded-lg font-bold transition-colors border border-indigo-200">
                  <BookOpen size={14} /> Slide Example
                </button>
                <button onClick={addResource} className="flex items-center gap-1 text-xs bg-blue-100 text-blue-700 hover:bg-blue-200 px-2 py-1.5 rounded-lg font-bold transition-colors">
                  <PlusCircle size={14} /> Add Resource
                </button>
                <button onClick={addProcess} className="flex items-center gap-1 text-xs bg-blue-100 text-blue-700 hover:bg-blue-200 px-2 py-1.5 rounded-lg font-bold transition-colors">
                  <PlusCircle size={14} /> Add Process
                </button>
              </div>
            </div>
            
            <div className="overflow-y-auto p-4 flex-1">
              
              {/* Resource Definitions */}
              <div className="mb-6 bg-slate-50 p-4 rounded-xl border-2 border-slate-300">
                <h3 className="text-sm font-bold text-slate-800 mb-3">Resource Totals (Max Capacity)</h3>
                <div className="flex flex-wrap gap-3">
                  {resources.map((r, i) => (
                    <div key={r.id} className="flex items-center gap-2 bg-white p-2.5 rounded-lg border-2 border-slate-300 shadow-sm">
                      <input 
                        type="text" 
                        value={r.name}
                        onChange={(e) => {
                          setState(prev => {
                            const newRes = [...prev.resources];
                            newRes[i] = { ...newRes[i], name: e.target.value };
                            return { ...prev, resources: newRes };
                          });
                        }}
                        className="w-12 font-bold text-center bg-transparent border-b-2 border-transparent hover:border-slate-400 focus:border-blue-600 outline-none transition-colors"
                      />
                      <span className="text-slate-400 font-bold">|</span>
                      <input 
                        type="number" 
                        value={r.totalInstances}
                        min="0"
                        onChange={(e) => {
                          setState(prev => {
                            const newRes = [...prev.resources];
                            newRes[i] = { ...newRes[i], totalInstances: parseInt(e.target.value) || 0 };
                            return { ...prev, resources: newRes };
                          });
                        }}
                        className="w-12 text-center bg-slate-100 border border-slate-300 rounded p-1 focus:ring-2 focus:ring-blue-500 outline-none font-bold text-slate-800"
                      />
                      <button onClick={() => removeResource(r.id)} className="text-slate-400 hover:text-red-500 p-1 transition-colors">
                        <Trash2 size={16} />
                      </button>
                    </div>
                  ))}
                </div>
              </div>

              {/* Mega Matrix */}
              <div className="overflow-x-auto rounded-xl border-2 border-slate-400 bg-white shadow-sm">
                <table className="w-full text-sm border-collapse">
                  <thead>
                    <tr className="border-b-2 border-slate-400">
                      <th className="p-2.5 border-r-2 border-slate-400 text-left text-slate-700 font-bold bg-slate-100">Process</th>
                      <th className="p-2.5 border-r-2 border-slate-400 text-center text-slate-900 font-bold bg-slate-100" colSpan={resources.length}>
                        Allocation<br/><span className="text-[10px] font-semibold text-slate-500">Currently Held</span>
                      </th>
                      <th className="p-2.5 border-r-2 border-slate-400 text-center text-slate-900 font-bold bg-slate-100" colSpan={resources.length}>
                        Max<br/><span className="text-[10px] font-semibold text-slate-500">Maximum Claim</span>
                      </th>
                      <th className="p-2.5 text-center text-blue-950 font-bold bg-blue-100/70" colSpan={resources.length}>
                        Need<br/><span className="text-[10px] font-semibold text-blue-600">Max - Alloc</span>
                      </th>
                    </tr>
                    <tr className="border-b-2 border-slate-400 bg-slate-50">
                      <th className="p-2 border-r-2 border-slate-400 bg-slate-100"></th>
                      {/* Alloc headers */}
                      {resources.map((r, rIdx) => (
                        <th key={`a-${r.id}`} className={`p-2 font-bold text-slate-700 text-center border-r ${rIdx === resources.length - 1 ? 'border-r-2 border-slate-400' : 'border-slate-300'}`}>
                          {r.name}
                        </th>
                      ))}
                      {/* Max headers */}
                      {resources.map((r, rIdx) => (
                        <th key={`m-${r.id}`} className={`p-2 font-bold text-slate-700 text-center border-r ${rIdx === resources.length - 1 ? 'border-r-2 border-slate-400' : 'border-slate-300'}`}>
                          {r.name}
                        </th>
                      ))}
                      {/* Need headers */}
                      {resources.map((r, rIdx) => (
                        <th key={`n-${r.id}`} className={`p-2 font-bold text-blue-800 text-center bg-blue-50 border-r ${rIdx === resources.length - 1 ? 'border-r-0' : 'border-blue-200'}`}>
                          {r.name}
                        </th>
                      ))}
                    </tr>
                  </thead>
                  <tbody>
                    {processes.map((p, i) => {
                      const isDeadlocked = result.deadlockedProcesses.includes(p.id);
                      return (
                        <tr key={p.id} className={`border-b border-slate-300 last:border-b-0 hover:bg-slate-50 transition-colors ${isDeadlocked ? 'bg-red-50/40' : ''}`}>
                          <td className="p-2 border-r-2 border-slate-400 flex items-center gap-2 bg-slate-50/60">
                            <button onClick={() => removeProcess(p.id)} className="text-slate-400 hover:text-red-600 p-1 transition-colors rounded-full hover:bg-red-50">
                              <Trash2 size={14} />
                            </button>
                            <input 
                              type="text"
                              value={p.name}
                              onChange={(e) => {
                                setState(prev => {
                                  const newProc = [...prev.processes];
                                  newProc[i] = { ...newProc[i], name: e.target.value };
                                  return { ...prev, processes: newProc };
                                });
                              }}
                              className={`w-12 font-bold bg-transparent outline-none border-b-2 border-transparent focus:border-blue-600 ${isDeadlocked ? 'text-red-700' : 'text-slate-800'}`}
                            />
                          </td>
                          
                          {/* Allocation */}
                          {resources.map((r, rIdx) => (
                            <td key={`a-${r.id}`} className={`p-1.5 border-r ${rIdx === resources.length - 1 ? 'border-r-2 border-slate-400' : 'border-slate-300'}`}>
                              <input 
                                type="number" 
                                min="0"
                                value={allocation[p.id]?.[r.id] || 0}
                                onChange={(e) => updateMatrixValue('allocation', p.id, r.id, parseInt(e.target.value) || 0)}
                                className="w-full p-1.5 text-center bg-white border-2 border-slate-300 hover:border-slate-400 focus:border-blue-600 focus:ring-1 focus:ring-blue-600 rounded-md font-bold text-slate-800 outline-none transition-all shadow-sm"
                              />
                            </td>
                          ))}

                          {/* Max */}
                          {resources.map((r, rIdx) => (
                            <td key={`m-${r.id}`} className={`p-1.5 border-r ${rIdx === resources.length - 1 ? 'border-r-2 border-slate-400' : 'border-slate-300'}`}>
                              <input 
                                type="number" 
                                min="0"
                                value={max[p.id]?.[r.id] || 0}
                                onChange={(e) => updateMatrixValue('max', p.id, r.id, parseInt(e.target.value) || 0)}
                                className="w-full p-1.5 text-center bg-white border-2 border-slate-300 hover:border-slate-400 focus:border-blue-600 focus:ring-1 focus:ring-blue-600 rounded-md font-bold text-slate-800 outline-none transition-all shadow-sm"
                              />
                            </td>
                          ))}

                          {/* Need */}
                          {resources.map((r, rIdx) => {
                            const val = result.needMatrix[p.id]?.[r.id] || 0;
                            const isWaiting = val > (result.initialAvailable[r.id] || 0);
                            return (
                              <td key={`n-${r.id}`} className={`p-1.5 bg-blue-50/50 text-center font-extrabold text-sm border-r ${rIdx === resources.length - 1 ? 'border-r-0' : 'border-blue-200'} ${isWaiting ? 'text-red-600' : 'text-blue-700'}`}>
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
              
              {!result.isSafe && (
                <div className="mt-6 p-4 bg-red-50 border border-red-200 rounded-xl text-red-800 text-sm">
                  <h4 className="font-bold flex items-center gap-2 mb-2"><ShieldAlert size={16}/> Why is this a Deadlock?</h4>
                  <p>The system is in an unsafe state because the <strong>Available Resources</strong> ({resources.map(r => `${r.name}: ${result.initialAvailable[r.id]??0}`).join(', ')}) are not enough to satisfy the <strong>Need</strong> of ANY remaining process.</p>
                  <p className="mt-2">Look at the <strong>Need</strong> columns highlighted in red above. Those processes require more instances of a resource than what is currently available, meaning they are indefinitely stuck waiting for resources that will never be released.</p>
                </div>
              )}
            </div>
          </div>

          {/* Right Panel: Graph */}
          <div className="flex-1 bg-white rounded-2xl shadow-sm border border-slate-200 relative flex flex-col min-h-[600px] overflow-hidden">
            <div className="p-4 border-b border-slate-100 bg-white flex justify-between items-center flex-wrap gap-2">
              <h2 className="text-lg font-bold text-slate-800">Resource Allocation Graph (RAG)</h2>
              <div className="flex gap-4 text-xs font-medium">
                <span className="flex items-center gap-1.5"><span className="w-3 h-3 bg-red-200 border-2 border-red-500 rounded-sm inline-block"></span> Resource</span>
                <span className="flex items-center gap-1.5"><span className="w-3 h-3 bg-blue-200 border-2 border-blue-500 rounded-full inline-block"></span> Process</span>
                <span className="flex items-center gap-1.5"><span className="w-4 h-1 bg-emerald-500 inline-block rounded-full"></span> Allocation</span>
                <span className="flex items-center gap-1.5"><span className="w-4 h-0 border-t-2 border-dashed border-red-500 inline-block"></span> Need</span>
              </div>
            </div>
            <div className="flex-1 p-2">
               <GraphView 
                 processes={processes} 
                 resources={resources} 
                 allocation={allocation} 
                 max={max}
                 deadlockedProcesses={result.deadlockedProcesses}
                 onUpdateAllocation={handleGraphUpdateAllocation}
                 onUpdateMax={handleGraphUpdateMax}
               />
            </div>
          </div>
          
        </div>

        {/* Bottom Panel: Step-by-Step Banker's Algorithm Execution Table */}
        <BankersTable 
          processes={processes}
          resources={resources}
          result={result}
        />
      </main>
    </div>
  );
}

export default App;
