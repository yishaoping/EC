# Minimal waitAck bypass and correctness contract

L2Preservation exports waitingAck=(state==waitAck). Scheduler defines
`sourceCReserved = lock.valid && !waitingAck` and substitutes this only in C schedule
admission and the shared SourceC bank-address mux/ready. Idle pre-capture drain and
capture/read/delay1/delay2/send/failed remain protected. No queue, port, geometry, MSHR,
SVB, source ID or hit-pipeline stage is added. Physical timing requires the later build.
Review the exact B→Opt5 delta in evidence/sourcec_delta.patch.

WHY_BYPASS_IS_SAFE = all checkpoint A beats, including final data, are accepted before
waitAck. No checkpoint bank read or A beat remains. An unrelated set may use SourceC,
while locked(target set), four physical overwrite assertions, safe-watermark checks,
version/snapshot provenance and matching terminal AccessAck(source/size/txn/denied/corrupt)
remain unchanged. No early completion or outerPreserved promotion occurs.

Checkpoint uses outer A; normal SourceC C packets keep the existing SourceC queue,
beat pipeline, hazards and last-C/ReleaseAck protocol. The checkpoint source cannot
alias a normal MSHR source. This allows concurrent independent transactions without
relaxing same-transaction ordering. A matching ACK may arrive while the C packet is
active: the next capture still requires sourceC.idle (including busy/pipeline/queue),
and the existing drain stops new C admissions while that capture is pending.
Zero-latency final-A ACK is still legal and unchanged; denied completion stays failed.

Two assertions check waitAck path inactivity and accepted C request reservation/set
safety. Existing target set/version/source/packet guards are retained. Scala typing and
CPU protocol witnesses do not replace Chisel elaboration, combinational-loop, TileLink
monitor, data/checksum or whole-system validation. Those remain PENDING.

SC48/schema1 emits one 16-word STOP record; no per-cycle trace. word0=1, word1=sample_cycles;
words2–9 are these eight overlapping counts; words10–15=0:

|Name|Unit/predicate|
|---|---|
|sourcec_reserved_cycles|cycles actual narrowed SourceC lease held|
|sourcec_reserved_with_pending_release|cycles lease held AND raw voluntary MSHR Release/ReleaseData opportunity|
|release_bypass_count|accepted voluntary SourceC requests during waitAck, not beats or completions|
|release_still_blocked_count|cycles any raw voluntary request pending AND no voluntary request accepted anywhere; other blockers may contribute|
|waitAck_cycles|cycles checkpoint state==waitAck|
|waitAck_with_pending_release|cycles waitAck AND raw voluntary opportunity|
|target_set_locked_cycles|cycles original lock held; shadow of old global reservation on the NEW schedule|
|old_reserved_with_pending_release|cycles original lock AND raw voluntary opportunity on the NEW schedule|

Window is the existing hardware traffic START→STOP, wider than exact software ROI.
ProbeAck opcodes are excluded. Raw pending is measured before stage3Allowed, avoiding
using an already gated SourceC.valid as evidence. Multiple pending requests collapse
to one pending-cycle predicate; these are not unique blocked requests or causal savings.
The old-reservation shadow is not a replay of the old B schedule. No ROB overlap added.

Analyzer requires one SC48/footer/producer, lossless mandatory capture, schema/ranges,
`reserved+waitAck=targetLocked`, analogous pending partition and subset checks.
Capture overlay only raises the two host identity dictionaries128→256 (the new producer
makes134 identities); budgets, byte limits, event priority and mandatory loss policy stay
identical. Old B raw FAIL remains untouched; existing lossless recovery is the reference.
