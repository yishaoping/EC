# Precise production token horizon R5

The unchanged compiled production model reproduced R2's counter mismatch when
the oracle read after step. R4's added precise peek failed at its first check:
DONE was 1 while PRECISE_PEEKABLE was 0. A four-mode bounded diagnostic showed
all 52 outputs matching the trace for the checked non-reset tokens when inputs
were poked and outputs precisely peeked before step(1).

R5 moves the existing single step after the complete 52-output comparison.
Its reverse edit must recover R4's driver exactly. All 3,003 input rows, output
oracle fields, three reset exclusions, negative mutation at token 100, and the
total of 3,003 step calls are retained. The 32-token diagnostic is not accepted
as validation; run the complete threaded and plain host oracle and negative.

The threaded RTL and compiled hardware model are reused exactly, with only the
driver recompiled privately. Plain generation and validation follow only after
threaded full-token PASS. Hardware, geometry, target-cycle semantics, functional
baseline and the public ABI are unchanged. No CAD, area or FIT claim.
