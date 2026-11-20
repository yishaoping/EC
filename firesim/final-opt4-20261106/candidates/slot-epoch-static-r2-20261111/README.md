Candidate3d29eff9: area-only slot epoch register representation.

Only dcache.scala, new SlotEpochBank.scala and lineage.json differ from e0c3737f. Frozen behavior, 16-bit width, synchronous reset, independent simultaneous writes, probe/clear/refill source order, read cycles, overflow assertions and complete512x16 debug snapshot remain.

The module broker request runs changed DCache typecheck, exact512-entry bitwise write/read transition cut with priority mutation,8192-cycle actual16-bit helper comparison, then matched storage maps with12variable readers and full snapshot. These are storage-boundary results; complete frozen DCache comparison/map and composed verification remain prerequisites to any admission. No whole build or FPGA action is requested.

Preserved failures: first worktree had a source-formatting preparation error; first broker request named an input outside W. Both remain immutable. controller-r4.py binds the exact frozen source copy under W and validates it against original.
