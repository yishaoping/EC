# Owner actual RAM read snapshot, round 53

Nine disjoint 9-bit projections cover 512 words by 81 bits. Each SAT query
starts with the arbitrary selected word related to an independent scalar word.
The selected address is stable across the one edge. The actual memory, async
read and read_data register are unchanged; no memory/read cut is present.
The reference read captures the pre-edge selected word, so a simultaneous
write must not bypass the old data. Reset is unconstrained and retains the
actual ungated pipeline semantics.

Required negatives corrupt pipeline bit 80, change the actual async read address,
and add same-edge write forwarding. Only actual-source counterexamples count;
timeouts/errors never pass. The prior storage induction result is hash-bound.
Writer-control correctness and queue/FAME target-cycle composition remain
separate. This is neither full-system equivalence nor FIT/FPGA evidence.
