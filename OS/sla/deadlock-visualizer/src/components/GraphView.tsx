import { useEffect, useCallback } from 'react';
import {
  ReactFlow,
  MiniMap,
  Controls,
  Background,
  MarkerType,
  useNodesState,
  useEdgesState
} from '@xyflow/react';
import type { Connection, Edge, Node } from '@xyflow/react';
import '@xyflow/react/dist/style.css';
import type { Process, Resource, ResourceMatrix } from '../lib/bankers';

interface GraphViewProps {
  processes: Process[];
  resources: Resource[];
  allocation: ResourceMatrix;
  max: ResourceMatrix;
  deadlockedProcesses: string[];
  onUpdateAllocation: (pId: string, rId: string, diff: number) => void;
  onUpdateMax: (pId: string, rId: string, diff: number) => void;
}

export function GraphView({ processes, resources, allocation, max, deadlockedProcesses, onUpdateAllocation, onUpdateMax }: GraphViewProps) {
  const [nodes, setNodes, onNodesChange] = useNodesState<Node>([]);
  const [edges, setEdges, onEdgesChange] = useEdgesState<Edge>([]);

  // Sync nodes when processes/resources change
  useEffect(() => {
    setNodes(prevNodes => {
      // Keep existing positions if available
      const positionMap = new Map(prevNodes.map(n => [n.id, n.position]));
      
      const resNodes: Node[] = resources.map((r, i) => {
        const id = `res-${r.id}`;
        return {
          id,
          type: 'default',
          position: positionMap.get(id) || { x: 150 + i * 200, y: 100 },
          data: { label: `${r.name} (Max: ${r.totalInstances})` },
          style: { 
            backgroundColor: '#fecaca', 
            borderColor: '#ef4444', 
            borderWidth: 2, 
            width: 110, 
            height: 90, 
            display: 'flex', 
            alignItems: 'center', 
            justifyContent: 'center', 
            borderRadius: 8, 
            fontWeight: 'bold',
            color: '#7f1d1d',
            boxShadow: '0 4px 6px -1px rgb(0 0 0 / 0.1)'
          },
        };
      });

      const procNodes: Node[] = processes.map((p, i) => {
        const id = `proc-${p.id}`;
        const isDeadlocked = deadlockedProcesses.includes(p.id);
        return {
          id,
          type: 'default',
          position: positionMap.get(id) || { x: 150 + i * 200, y: 400 },
          data: { label: p.name },
          style: { 
            backgroundColor: isDeadlocked ? '#fee2e2' : '#bfdbfe', 
            borderColor: isDeadlocked ? '#dc2626' : '#3b82f6', 
            borderWidth: isDeadlocked ? 4 : 2, 
            width: 90, 
            height: 90, 
            borderRadius: '50%', 
            display: 'flex', 
            alignItems: 'center', 
            justifyContent: 'center', 
            fontWeight: 'bold',
            color: isDeadlocked ? '#991b1b' : '#1e3a8a',
            boxShadow: isDeadlocked ? '0 0 15px rgba(220, 38, 38, 0.5)' : '0 4px 6px -1px rgb(0 0 0 / 0.1)'
          },
        };
      });

      return [...resNodes, ...procNodes];
    });
  }, [processes, resources, deadlockedProcesses, setNodes]);

  // Sync edges when matrices change
  useEffect(() => {
    setEdges(prevEdges => {
      const selectedEdges = new Set(prevEdges.filter(e => e.selected).map(e => e.id));
      const e: Edge[] = [];
      processes.forEach(p => {
        resources.forEach(r => {
          const alloc = allocation[p.id]?.[r.id] || 0;
          const m = max[p.id]?.[r.id] || 0;
          const need = Math.max(0, m - alloc);

          if (alloc > 0) {
            const id = `alloc|${r.id}|${p.id}`;
            e.push({
              id,
              source: `res-${r.id}`,
              target: `proc-${p.id}`,
              label: `Alloc: ${alloc}`,
              selected: selectedEdges.has(id),
              markerEnd: { type: MarkerType.ArrowClosed, color: '#10b981' },
              style: { strokeWidth: 3, stroke: '#10b981' },
              labelBgPadding: [8, 4],
              labelBgBorderRadius: 4,
              labelStyle: { fill: '#065f46', fontWeight: 700 }
            });
          }
          
          if (need > 0) {
            const id = `req|${p.id}|${r.id}`;
            e.push({
              id,
              source: `proc-${p.id}`,
              target: `res-${r.id}`,
              label: `Need: ${need}`,
              selected: selectedEdges.has(id),
              animated: true,
              style: { strokeWidth: 3, stroke: '#ef4444', strokeDasharray: '5 5' },
              markerEnd: { type: MarkerType.ArrowClosed, color: '#ef4444' },
              labelBgPadding: [8, 4],
              labelBgBorderRadius: 4,
              labelStyle: { fill: '#991b1b', fontWeight: 700 }
            });
          }
        });
      });
      return e;
    });
  }, [processes, resources, allocation, max, setEdges]);

  const onConnect = useCallback((connection: Connection) => {
    if (!connection.source || !connection.target) return;
    
    const isSourceRes = connection.source.startsWith('res-');
    const isTargetProc = connection.target.startsWith('proc-');
    const isSourceProc = connection.source.startsWith('proc-');
    const isTargetRes = connection.target.startsWith('res-');

    if (isSourceRes && isTargetProc) {
      // Resource -> Process = Allocation
      const rId = connection.source.replace('res-', '');
      const pId = connection.target.replace('proc-', '');
      onUpdateAllocation(pId, rId, 1);
    } else if (isSourceProc && isTargetRes) {
      // Process -> Resource = Request (Need)
      const pId = connection.source.replace('proc-', '');
      const rId = connection.target.replace('res-', '');
      onUpdateMax(pId, rId, 1);
    }
  }, [onUpdateAllocation, onUpdateMax]);

  const onEdgesDelete = useCallback((edgesToDelete: Edge[]) => {
    edgesToDelete.forEach(edge => {
      const parts = edge.id.split('|');
      if (parts.length === 3) {
        const type = parts[0];
        if (type === 'alloc') {
          const rId = parts[1];
          const pId = parts[2];
          onUpdateAllocation(pId, rId, -9999);
        } else if (type === 'req') {
          const pId = parts[1];
          const rId = parts[2];
          onUpdateMax(pId, rId, -9999);
        }
      }
    });
  }, [onUpdateAllocation, onUpdateMax]);

  return (
    <div style={{ width: '100%', height: '100%', minHeight: '600px' }} className="rounded-xl overflow-hidden bg-slate-50">
      <ReactFlow 
        nodes={nodes} 
        edges={edges} 
        onNodesChange={onNodesChange}
        onEdgesChange={onEdgesChange}
        onConnect={onConnect}
        onEdgesDelete={onEdgesDelete}
        fitView
        deleteKeyCode={['Backspace', 'Delete']}
        panOnDrag={[2]}
        selectionOnDrag={true}
        onPaneContextMenu={(e) => e.preventDefault()}
      >
        <Controls />
        <MiniMap nodeStrokeColor="#ccc" nodeColor="#fff" />
        <Background gap={16} size={2} color="#e2e8f0" />
      </ReactFlow>
    </div>
  );
}
