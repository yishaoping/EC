Complete AddressStats source integration prerequisite, round154

Retain all256target slots as16identical banks with16parallel bucket lanes.
The exact r4 BucketBank class body is copied byte-for-byte; only its package
changes. Each original parent register becomes a combinational view of its
bank register. Source keys/counts and same-cycle qualified controls connect
directly. All upstream queues, tables, sequence membership checks, global
arithmetic checks, errors and online/global metric updates remain in the
complete module. Exact bank carries replace the original carry reduction.
No target register or pipeline stage is introduced. A reversible edit ledger
reconstructs the complete original source byte-for-byte.

This independent prerequisite does not duplicate the r4 token/area screen,
packed/DSP maps or foreground DCache composition. It does not change any
live input, installed source, compiler or board. CPUs226/227,64GiB hard cap,
existing256GiB/load64/disk60GiB/noCPUoverlap admission guard. No CAD follows
this controller. Negative results and all generated inputs stay immutable.

Compile/elaborate complete reference/candidate modules, check exact52public
output ABI, then compare all52public outputs plus5120bucket words and all256
valid/sequence fields before/after every edge for6144target cycles. Reuse the
existing immutable fullmodule testbench stimuli, reset/invalid-payload seeds
and monitor, rebinding only candidate hierarchical register paths. Detect an
actual bank15/lane15 invalid-register mutation with the same monitor.
This is finite evidence, not whole formal equivalence or completeEC parity.

Target integration/parity can progress while the owned r4 host screen runs.
Actual useful r4 fullsize paired savings remain mandatory before area
admission. Complete-module GoldenGate channel/dependency/handshake and token
validation, actual same-harness generated-host paired area, composition with
accepted DCache changes and fresh complete-host postopt are still required.
In particular, source equivalence does not prove a tokenized bank can resolve
its same-target-cycle carry->processCommit and state->safeError feedback.
The observation-heavy screen is not a whole-module saving or throughput
measurement. No validated FIT route currently meets the November18deadline.
