# Production Plain output-directory recovery R6

R5 completed the unchanged full 3,003-token threaded oracle: 156,000 output
comparisons and deliberate mutation rejection. Plain generation then failed in
EmitFirrtl because its output directory did not exist. This controller creates
the new output directory before the exact GoldenGate command, changing only
the destination. It preserves the old failure and reuses completed threaded
receipts without regeneration, recompilation or replay.

The Plain run uses the identical R5 input-poked pre-step C++ driver, trace,
52 outputs, reset exclusions, mutation and step count. Hardware, source baseline,
geometry and target semantics are unchanged. Full Plain positive and negative
receipts and matching digests are required before a separate serial area owner
may run after complete validator cgroup release. No area, whole EC or FIT claim.
