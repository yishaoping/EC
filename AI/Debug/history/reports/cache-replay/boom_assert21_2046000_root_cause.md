# BOOM `assert__assert_21` at 2046000

## Conclusion

The assertion is the BOOM pipeline watchdog. This run spends about `2^20`
BOOM cycles without a ROB commit. The immediate architectural cause is a full
LSU STQ pinned by its oldest entry, STQ 0: it is committed and owns strict
store token `0x7108`, but never reaches `succeeded=1` or consumes that token.
The source-level release condition therefore never clears the queue head.

The saved waveform proves this chain through the watchdog. It does **not** yet
prove why the STQ 0 store failed to receive a matching physical DCache
completion. Cross-package barrier nacks are present in the same interval, but
their observed request is STQ 15, so attributing STQ 0's lost progress to that
barrier would be incorrect.

## Evidence boundary

- Log: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`
  (2026-09-30 18:03 +0800).
- Waveform: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
  (2026-09-30 18:03 +0800), time range `0..4092368`.
- Generated assertion: `gen-collateral/BoomCore.sv:6869`.
- Assertion source: `generators/boom/src/main/scala/exu/core.scala:1753-1760`.
- No simulation, RTL generation, or hardware source edit was performed.

For this run, the log's `2046000` is approximately FST `4092368`; the VCD
interval is twice the BOOM cycle count. The last ROB commit is at FST
`1995213`, followed by about `2097154` FST units, or approximately `2^20`
BOOM cycles, without a commit.

## Assertion and signal chain

The watchdog counter resets on any ROB commit, CSR stall, RoCC busy, or reset.
At bit 20 it asserts `Pipeline has hung.` The log assertion is therefore a
long no-retirement symptom, not the original LSU failure.

The observed LSU state at the end of the VCD is:

```text
stq_head=0, stq_tail=15, stq_commit_head=15, stq_execute_head=15
stq[0].valid=1, committed=1, succeeded=0
stq[0].packet_seq=137, strict_store_token_valid=1
stq[0].strict_store_token=0x7108
stq[0].address=0x80001fcb, data=1
```

The STQ has 16 entries. Its full predicate is
`WrapInc(stq_tail, 16) == stq_head`; here `WrapInc(15,16) == 0`, so full is
consistent with the pointers. STQ 0 cannot be reclaimed because
`clear_store` requires `succeeded && !strict_store_token_valid` for an ordinary
store (`lsu.scala:2075-2077`).

The resulting flow is:

```text
STQ 0 strict token has no accepted matching cache/uncache completion
  -> STQ 0 remains succeeded=0 and token_valid=1
  -> clear_store stays low; stq_head remains 0
  -> stores allocate through entry 14; tail reaches 15
  -> WrapInc(tail)==head, so LSU reports STQ full
  -> core dispatch stalls store uops using stq_full (core.scala:1085-1100)
  -> ROB drains; no new instructions retire
  -> idle_cycles reaches 2^20 BOOM cycles
  -> BoomCore.sv:6869 assertion fires
```

The strict completion is accepted only if DCache's completion STQ index and
token match a live, committed STQ entry (`lsu.scala:1932-1947`). The accepted
event sets `succeeded`, clears the token, and advances the execute head where
applicable (`lsu.scala:2030-2046`). DCache creates cache completion at the
physical data-array write (`dcache.scala:1537-1597`). At the final waveform
sample, no completion is active, STQ 0 still has its original token, and the
LSU request interface is idle.

## Barrier evidence and limitation

The VCD does show repeated `crossPackageBlockCondition` /
`l1CrossPackageBlocked` cycles and associated DCache nacks around FST
`1994791..1995299`. The request tagged with those barrier signals is STQ 15
(`s2_req_0_uop_stq_idx=15`, address `0x80011dec`, packet sequence 137). STQ 0
uses address `0x80001fcb`; therefore those observed barrier nacks are not proof
of the STQ 0 completion loss.

STQ 0 also appears in DCache request/nack metadata in this window, and a
token-zero completion metadata value appears for index 0. That value alone
does not establish a completion pulse: completion requires the physical write
fire and strict-token qualification. The current saved VCD is insufficient to
determine whether the token-bearing replay was rejected, never replayed, or
lost through another DCache/MSHR ordering condition.

## Root cause assessment

- **Proven direct symptom:** watchdog reaches `2^20` BOOM cycles without ROB
  commit.
- **Proven immediate blocking condition:** STQ is full and pinned at committed
  STQ 0, whose strict token remains valid and whose `succeeded` bit remains 0.
- **Strongly supported causal trigger:** the STQ 0 store does not complete via
  the matching token-qualified DCache physical-write event. LSU's token guard
  correctly prevents premature STQ reclamation, but turns the missing event
  into permanent queue backpressure.
- **Not proven:** the exact DCache/MSHR event that prevents STQ 0's token from
  completing. The nearby cross-package barrier nack belongs to STQ 15 and must
  not be cited as that cause without a matching-address/token trace.
- **Downstream amplifier:** with the queue head pinned, STQ fills, store
  dispatch stops, the ROB empties, and the generic core watchdog eventually
  fires.

## Focused follow-up trace

For the next run, retain the first store-0 request from LSU through DCache and
MSHR with these fields sampled together: STQ index, address, packet sequence,
strict-token-valid/token, S0-S3 validity, MSHR request-ready/fire, replay-valid,
MSHR response, nack plus nack cause, `dataWriteArb.io.in(0).fire`, and LSU's
`cacheCompletionAccepted`/`stq_0.succeeded`/`stq_0.strict_store_token_valid`.
The decisive question is whether token `0x7108` reaches a physical array-write
fire and, if it does, whether LSU accepts the matching completion. Preserve
the waveform around the first transition into `stq_full` and the final watchdog
boundary; do not infer token completion from completion-index/token fields
without the completion-valid pulse.
