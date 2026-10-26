import { useState, useCallback } from 'react';

export function useUndo<T>(initialState: T) {
  const [state, setStateInternal] = useState<T>(initialState);
  const [past, setPast] = useState<T[]>([]);
  const [future, setFuture] = useState<T[]>([]);

  const setState = useCallback((newState: T | ((curr: T) => T)) => {
    setStateInternal(curr => {
      const resolved = typeof newState === 'function' ? (newState as Function)(curr) : newState;
      // Deep equal check could be added here, but simple ref check is usually enough
      if (resolved === curr) return curr;
      setPast(p => [...p, curr]);
      setFuture([]);
      return resolved;
    });
  }, []);

  const undo = useCallback(() => {
    setPast(p => {
      if (p.length === 0) return p;
      const newPast = [...p];
      const previous = newPast.pop() as T;
      
      setStateInternal(curr => {
        setFuture(f => [curr, ...f]);
        return previous;
      });
      
      return newPast;
    });
  }, []);

  const redo = useCallback(() => {
    setFuture(f => {
      if (f.length === 0) return f;
      const newFuture = [...f];
      const next = newFuture.shift() as T;
      
      setStateInternal(curr => {
        setPast(p => [...p, curr]);
        return next;
      });
      
      return newFuture;
    });
  }, []);

  return [state, setState, undo, redo, past.length > 0, future.length > 0] as const;
}
