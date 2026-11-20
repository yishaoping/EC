# Architectural recovery interface: concrete boundary and decision

Hardware f2d2ca3e (child of9ae9a7fc), sourcef678ac80. No source was changed by this audit.

The source still exposes checker FAIL/CANCEL, contiguous safe watermark, SVB invalidation
and promotion ACK. These are implemented and retained by the area optimizations.
The BOOM core defines synchronized `l2BarrierErrorAny` at core.scala:2108 but has no
consumer. R_RSU sends saved integer/floating/PC/FCSR state outward through `io.r_arfs`
(core.scala:2440); this is checker snapshot export, not a write-back restore port.
ROB speculative exception rollback is not a failed-checker checkpoint restore.
OpenSBI explicitly supports one checker context per boot; its trap handler tears down
SATP and parks. It is not application restart. Full source hashes are in audit.json.

Thus this gap cannot be closed by merely exposing a missing status register. A real
checker-triggered architecture recovery path adds behavior absent from the audited
frozen/derived design. It must have an independent functional version; area-equivalence
claims apply to the old behavior, not to the newly introduced fault behavior.

Concrete full-package recovery contract proposed for a separate branch:
1. Atomically identify and retain the last contiguous PASS package checkpoint K,
   with integer/floating registers, restart PC, privilege/FCSR/required CSR state,
   memory visibility generation and immutable sequence identity. A single newest
   export snapshot is insufficient when four checker packages can finish out of order.
2. A real compared FAIL(s>K), carrying the allocated sequence, freezes new retirement
   and admission, captures the failure, and prevents publication beyond K.
3. Quiesce/cancel all younger checker and cache operations with sequence-matched
   completion; retain WB_WAIT ownership until exact ACK. Clear resident younger
   cache effects through a defined data-restoration protocol, not just SVB discard.
4. Restore architectural state and verified memory visibility for K, then redirect
   fetch to the checkpoint restart PC. Match recovery epoch/sequence across CDCs.
5. Reinitialize checker contexts via a generation-safe firmware handshake; no forced
   PASS, stale result reuse or global host reset as evidence.
6. Export actual `fail_accepted(s)`, `checkpoint_selected(K,epoch)`, memory-restore
   completion, architectural restore completion, restart-PC retirement and final
   checker drain/output witnesses on the same target-cycle base.

Acceptance requires a deterministic fault at a real compare input, observed real
FAIL, actual restoration and retired restart, correct full program output and zero
unfinished checker tasks. Negative mismatched ACK and normal checker runs alone
remain insufficient. The actual SVB invalidation/owner/data and negative ACK RTL
validation has passed separately; it is a lower boundary test.

Architecture choice: build the above as a new functional recovery branch, or retain
the present mainline's source-preserving area optimization and normal performance
validation while a separately scoped architecture task defines complete recovery.
Mainline RTL optimization, module mapping, system synthesis, implementation and
bitstream must continue under either choice. No Native or FPGA action is authorized
by this document; the existing21-only deployment safety remains mandatory.
