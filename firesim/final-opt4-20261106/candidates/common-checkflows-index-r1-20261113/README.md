Future-only Golden Gate compiler throughput repair, not a hardware candidate.

A live JVM sample of common-stats-host-r6 shows CheckFlows.get_flow repeatedly
using List.find in wide BundleType fields. Keep that run unchanged. This
implementation indexes immutable BundleType fields by object identity within
one CheckFlows.run invocation. Building the map in reverse preserves the
original first-match semantics even for duplicate names; absent fields retain
Option.get exceptions. Every original flow check, error and circuit is retained.

Direct stock1.5.5-versus-indexed comparison passed293cases, including193negative
cases with exact normalized error type and exact error text, nested flips,
vectors, dynamic indexing, wrong port flows, missing/duplicate fields and a
wide8192port hierarchy. Returns are the same Circuit object, not rewritten RTL.
The wide fixture measured223.36ms stock versus19.02ms indexed; this is a compiler
microbenchmark, not FPGA speed or an estimate of complete EC build duration.
An inverse-source check reconstructs upstream CheckFlows byte for byte.

No live classpath or task is changed. Reuse the authenticated classes first in
a new immutable future compiler invocation only. Keep all existing model-loop,
annotation, target/host-token, area and complete-shell gates. Do not use this
compiler-only result as hardware equivalence, area or FIT evidence.
