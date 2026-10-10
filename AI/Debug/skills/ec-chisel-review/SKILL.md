---
name: ec-chisel-review
description: Check EC Scala/Chisel modifications through type compile, elaboration, FIRRTL initialization/loops and generated semantics; use for interface and fix reviews.
---

# ec-chisel-review

Use ../chisel_firrtl_audit.md and ../../checks/static_dynamic_regression.md. Historical omissions are in ../../checks/historical_omissions.md.

Before compiling, locate every new IO producer/consumer and parameterized instance; inspect types/width/reset/last-connect priority. After Scala compilation, separately validate target elaboration, FIRRTL initialization, dynamic dontTouch targets and CheckCombLoops. Inspect SyncReadMem payload latency and valid hold in generated RTL.

Keep generated directories and logs in AI/TMP; preserve old source/RTL/run identities. Report which gates actually ran, their exit/result, and dynamic limitations. Never call marker checks, Scala compile or FIRRTL success runtime proof.
