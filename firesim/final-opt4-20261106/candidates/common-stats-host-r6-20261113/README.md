# Mixed-role host R6 compiler recovery

R5 completed compact combinational-loop analysis but exhausted its 48 GiB Java
heap during annotation propagation after SimulationMapping. It had 60,369 path
annotations with only 203 distinct source rows; independent remapping expanded
the shared rows again. This is a compiler failure, with no area or inequivalence
conclusion.

R6 applies the exact annotation-update and global ordered-distinct operation in
a single batch at that one transform boundary. Per-call caches reuse identical
reference-target results and identical immutable source rows. Ordinary
CombinationalPath annotations, order, multiplicity within rows, local-target
filtering, other annotation updates, and deduplication remain unchanged. Caches
never survive the invocation, so later RenameMap mutations are observed.

The circuit, compiler loop checks, production 256-slot geometry, 64 selected
StatsBank instances, and 73 public outputs are unchanged. Reuse the exact target
elaboration and the completed R5 checker classes/regression. Compile the new
mapper, compare its behavior against stock propagation including fanout,
deletion, hierarchy, chains, duplicates and mutation negatives, then run one
bounded host generation. No target oracle, token validation, OOC area, whole EC
or shell FIT claim is made by host generation alone.
