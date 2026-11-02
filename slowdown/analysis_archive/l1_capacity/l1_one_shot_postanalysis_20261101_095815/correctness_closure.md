# Correctness closure

`CHECKER = PASS` for the completed B run, after independent raw evidence review and lossless accounting recovery. Original summary FAIL was a host bookkeeping failure, not a checker result failure; original bytes remain preserved.

320 SC2 allocations (unique seq1–320) match exactly320 clean SC47 handoffs and320 unique BOOM SC3 accepted PASS results. Per hart: checker1=76, checker2=81, checker3=84, checker4=79. No failed/cancelled/stale/held-duplicate result flag, assertion, ownership watchdog or unmatched allocation remains. All mandatory identities have one footer and exact producer/event conservation. All handoffs have context_idle1, return_pending0, excpt_mode0, trap_depth0. No premature release is observed; the complete package ledger has handoff before accepted-result. Global optional SC4/5 traces are incomplete, so they are not claimed to independently prove every electrical release edge.

For seq67, optional SC4/5 are retained at the relevant edges: enqueue940907, BOOM dequeue/accepted PASS940911, ownership busy cleared940912 while release is pending, release deasserted940913. This closes actual ownership release in addition to local completion. See seq67_runtime_confirmation.md for exact lines and fields.

No CANCEL was generated in this run. The repaired successful result path was exercised; a hypothetical CANCEL delivery under a new fault is not dynamically tested. A missing CANCEL is not inferred from silence: complete mandatory result ledgers and cumulative SC47 CANCEL counters are both zero.

`ROOT_CAUSE = ROOT_CAUSE_CONFIRMED` for privileged-dispatch/architectural-trap collision. Original failure: registered privileged entry accepted seq67 at939415 while excpt_mode1 with untracked local trap context, followed by return_pending1/exception1/depth1 and permanently blocked CANCEL handoff. New run matches allocation/admission timing and shows timer trap exactly939413, the gate defers dispatch until the real return clears exception/depth, then all package barriers complete. The alternative trap-at-registered-entry repair branch has counter0 and remains unexercised. This runtime validates this workload, not universal trap nesting or all future inputs.

Evidence: [global_checker_audit.json](global_checker_audit.json), [seq67_events.json](seq67_events.json), original stdout/stderr and mandatory capture records. No hardware was run this turn.
