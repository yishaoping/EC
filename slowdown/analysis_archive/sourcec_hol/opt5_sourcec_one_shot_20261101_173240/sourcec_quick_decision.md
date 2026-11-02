# Quick decision: GO

STATIC_HOL_ROOT_CAUSE = PROVEN
SOURCEC_OPT5_GO = YES (user rules B/D: explicit global serialization, small safe phase narrowing)
ESTIMATED_UPPER_BOUND = UNKNOWN
CONFIDENCE = HIGH for structure; LOW for predicted gain

|Question|RTL answer|
|---|---|
|Global reservation?|YES: Scheduler gates every C-bearing MSHR schedule and the shared SourceC read port on preservation.lock.|
|Held through waitAck?|YES: lock=active||capture; active includes waitAck; only matching terminal ACK clears it.|
|Unrelated victim Release blocked?|YES: C gate is independent of set/source, beyond the separate locked(set) check.|
|Unrelated set/source/bank row blocked?|YES within this Scheduler/L2 bank; current configuration has one L2 bank. No claim about independent L2 bank instances.|
|ACK ordering?|Checkpoint Put uses dedicated source2 and echoed txn/size. Normal source0/1 victim Release keeps its own ReleaseAck→Acquire ordering. No cross-source ACK order is required by this implementation.|
|Safe bypass?|YES: pure waitAck has no pending checkpoint bank read or A beat. Keep target-set protection, source IDs, SourceC packet machinery and next-capture drain.|

Proven chain: global lease is the immediate blocker; checkpoint waiting for its terminal ACK
is the trigger; victim ReleaseAck/new Acquire dependency is the downstream amplifier.
No runtime assertion symptom is alleged: this is a conservative resource serialization.
Dynamic frequency, exclusive blockage and critical-cycle magnitude remain unproven.

Current B has no direct SourceC reservation counters. Previous 6,735 inner releases,
2,231 ROI releases and transfer durations are different traffic/phase measurements,
not this mechanism's runtime budget. The 34,104 outer-A intrinsic-gap bound does not bound
SourceC waitAck HOL. No extra observation run or request-to-ROB reconstruction is needed
for this user-authorized small one-shot intervention.

Evidence: evidence/before_{Scheduler,L2Preservation}.scala plus pre_edit_inputs.json;
current B source seal and recovered all-gate result are hash-bound in sourcec_contract.json.
