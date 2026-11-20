Private mixed-host compiler recovery r4

Preserves exact r3 hardware, frozen256slots,64selected16-laneStatsBank instances,
73publicoutputs and3003token oracle. No target cycles or state changed.

The stock FIRRTL1.5.5 CheckCombLoops analysis failed at48GiB while expanding dense
module port summaries. This private override keeps statement dependency extraction,
SCC and error checks, memory/ExtModule paths and loop opt-out interface. Port
reachability is computed with integer BFS and stored as packed bits; instance
port edges are subdivided through shared64-bit chunk nodes. Subdividing each
exact edge preserves reachability and cycles. Synthetic nodes exist only in the
analysis, are removed from diagnostic paths, and never enter circuit output.
Analysis APIs expand them to the original graph. CheckCombLoops remains enabled.

Mandatory stock comparison:260valid circuits compare exact combinational paths,
expanded dependency edges and circuit text;5loop cases must be rejected by both.
The stock implementation has an existing PathNotFound diagnostic failure on
some hierarchical loops; this still rejects the loop and is retained as evidence.
No claim of complete host equivalence, area saving or FIT before real receipts.

Compiler classes are private and source-hashed; installed jars are untouched.
Actual mixed-host Plain/Threaded outputs must pass3003tokens/73outputs and negative
mutation before paired OOC maps. Complete DCache/caller/ABI/wholehost/shell gates
remain independent. No FPGA IO.
