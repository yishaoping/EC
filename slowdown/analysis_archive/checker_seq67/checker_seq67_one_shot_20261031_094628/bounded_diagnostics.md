# Bounded diagnostics — same hardware version as the fix

No diagnostic-only hardware/run. All new state is observation-only and has no functional
consumer. Existing corrected L2 observer, causal counters and STOP40–45 are unchanged.
No new global printf, fetch log, waveform, or per-memory-operation trace is enabled.

- **SC46**: per hart up to64 seq67 lifecycle rows plus16 conflict examples from any
  package. The change key reuses SC6's masked lifecycle key: ordinary LSL empty toggles
  before execution completion are excluded. Real trap/eret/dispatch events and local
  trap state supplement it. At most320 SC46 rows across4 checkers.
- **SC47**: ten saturating32-bit cumulative event counters. Snapshot on local result
  handoff or CANCEL, capped128 per hart. At most512 SC47 rows. Total new records≤832,
  about0.3MiB of fixed16-word TSV, plus small footers. No cycle feedback/stall output.
- SC46/47 are mandatory in the existing capture classifier (all kinds outside its
  optional range); no capture-policy weakening. A missing footer, host/producer loss,
  schema mismatch, exhausted summary budget, bad context or cancelled result rejects
  runtime validation. Workload never stops because of trace-budget exhaustion.

SC46 word0 effective package seq,1 schema1,2 diagnostic flags,3 old SC6 lifecycle flags,
4 old SC6 context flags,5 ICSL state,6 architectural trap depth,7 CSR trace PC,8 cause,
9 pending priv_status,10 check_priv,11 rsu_pc,12 ICSL trap depth,13 requested redirect PC,
14 prior seq67 row count,15 prior conflict-example count.

Diagnostic flag bits0..15: CPS done, request pending, ready, actual synthetic dispatch,
registered privileged entry, real CSR exception, CSR eret, excpt_mode, blocked rising,
entry/trap coincidence, stale-trap entry, result fire, result handoff, CANCEL, exec_done,
returned_to_special_address_valid. CSR.eret includes ECALL/EBREAK; interpret with bit5.

SC47 word0 seq,1 schema1,2 flags; words3..12 cumulative counters (including current edge):
CPS requests, actual dispatches, deferral episodes, entry/trap coincidences, stale-trap
entries, CANCELs, seq67 accepted starts, seq67 exec completions, seq67 full-result fires,
seq67 handoffs. Word13 seq67 row count; word14 `(summary_rows_before<<5)|conflict_rows`;
word15 context flags. Counters do not count every deferred cycle, only episodes.

Postanalysis joins seq67 admission/start/exec/full compare/local result/handoff and
mandatory BOOM SC3 accepted PASS, checks ordering/clean context and no CANCEL. Nonzero
deferral/entry-trap events confirm that a repaired hazard was exercised. If all hazard
counters are0, a complete lifecycle is correctness evidence, not runtime proof of the
specific collision hypothesis. Old failed run evidence remains separate.
