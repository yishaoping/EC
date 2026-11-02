# Cleanup root cause

ROOT_CAUSE = MOST_LIKELY_WITH_BOUNDED_RUNTIME_CONFIRMATION

TYPE_1_PROTOCOL_BUG. No watchdog-bound increase is justified.

## Four levels

1. **Assertion symptom — proven:** B `BoomCore.sv:6977 assert24` is checker3 ownership
   `little_status3(checkerHangWatchdogBit)`; bit18 means262144 BOOM cycles, with reset
   only on inactive ownership or received clear/release. Two printed error lines refer
   to the same assertion, not two independent hardware faults.
2. **Immediate blocker — proven:** CANCEL67 is in the local result queue; result_valid
   remains gated by local cleanup. LSL, RSU, comparison, ECP and Frontend acknowledgement
   are clean in the final row. `context_idle` is false.
3. **Upstream trigger — strongly supported:** privileged start is accepted while
   architectural excpt_mode=1 and the local FSM is still nonchecking, local depth0.
   The original `check_exception = delayed_CPS && !old_excpt_mode ||
   priv_status==1 && delayed_csr_eret` has no current-trap or current-return exclusion.
   Also CSR.eret is `insn_call || insn_break || insn_ret`: ECALL/EBREAK can masquerade
   as the return authorization in its second branch. CSR's synthetic check_tvec mux
   may replace the real exception vector on a collision, while R_ICSL misses that
   trap in nonchecking. Exact CSR cause, selected vector and rsu_pc were not logged;
   runtime confirmation of the corrected route is still pending.
4. **Downstream amplifier — proven/source-backed:** on CANCEL, excpt_mode1 causes
   R_ICSL to fabricate a local trap_depth1 even though it never captured the original
   trap. Cancellation_return_pending remains set until real return/special-PC completion.
   Waiting for a matching xRET does not repair the lost dispatch/vector relationship.
   Raising the ownership bound would retain the same blocked transaction longer.

## Exact conjunctions

```text
checker_cleanup_done =
  icsl.context_idle && rsu_status==0 && lsl.quiescent &&
  compare_idle && ecp_idle && frontend.checker_clear_done && !checker_clear_pending

icsl.cleanup_done = state==reset || state==nonchecking
icsl.return_pending = (state in postchecking* && package_completion_ready &&
                       !returned_to_special_address_valid) || cancellation_return_pending
icsl.context_idle = cleanup_done && !excpt_mode && trap_depth==0 &&
                    !trap_depth_overflow && !return_pending

handoff_allowed = checker_cleanup_done && !package_check_active && !package_start_pending
result_valid = result_queue.deq.valid && handoff_allowed
result_queue.deq.ready = external_result_ready && handoff_allowed
```

Final row1070897: rsu_status0 / lsl.quiescent1 / compare_idle1 / ecp_idle1 /
Frontend clear_done1 / clear_pending0. Context has excpt_mode1 / trap_depth1 /
return_pending1. Source transitions place the cancelled privileged package in
self_xcpt_priv until xRET; cleanup_done is false. Overflow was not directly logged,
and its value cannot make the other false conjuncts true.

This is not evidence of cache-data corruption, L2 observer mismatch, MSHR exhaustion,
SVB capacity shortage, or a BOOM ordinary pipeline watchdog. Prior validated Opt4/SVB16
correctness is retained. Failed B has no ROI endpoint/performance delta.
