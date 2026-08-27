# `assert__assert_22` analysis for the 1359000 failure

This report is a read-only reconstruction of the failure using the generated
collateral that emitted the assertion, the current Scala sources, and
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.
The file has a `.vcd` suffix but is an FST container. No hardware source was
modified, and no simulation, Verilator replay, RTL generation, or hardware
generation was run.

## 1. Assertion meaning

The failing line is the checker-1 BOOM watchdog:

```verilog
wire _T_299 = ~_ic_master_io_ic_status_1 |
              io_clear_ic_status_tomain[1];

if (_T_299)
  large_1 <= 27'h0;
else if (nextSmall_1[5])
  large_1 <= large_1 + 27'h1;

assert__assert_22: assert(~(large_1[15]));
```

The generated source is
[`BoomCore.sv`](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv:6760),
with the counter update at line 8407. The source-level checker is
[`core.scala`](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2037).
`small_1` is the low five bits of a `WideCounter`; `large_1[15]` is reached
after `2^20` BOOM-cycle increments. Therefore the assertion means:

```text
BOOM checker slot 1 is owned (ic_status_1 = 1)
and no release has been observed (clear_ic_status_tomain[1] = 0)
for approximately 2^20 BOOM cycles.
```

It is an ownership-release watchdog, not an instruction-semantic assertion.

## 2. High-level causal chain

```text
seq=1 result is cancelled and released
  -> BOOM slot 1 clears
  -> R_IC allocates seq=57 into the same slot
  -> seq=57 data anchor and ARF/CPS/ECP beats cross CDC
  -> RocketTile consumes those beats into LSL/RSUSL
  -> data sequence pulse is seen while checker_cleanup_done is false
  -> new_package is rejected; pending_package_seq stores 57
  -> the already-consumed seq=57 state keeps RSUSL/LSL non-idle
  -> checker_cleanup_done never becomes true, so seq=57 is never promoted
  -> no seq=57 result is produced
  -> GHM has no result dequeue/release pulse
  -> clear_ic_status_tomain[1] stays low while ic_status_1 stays high
  -> large_1[15] reaches one and assert__assert_22 fires
```

The central failure is an admission/consumption ordering deadlock. It is not
the old seq=1 result being stuck, and it is not evidence that seq=57 data was
absent.

## 3. Sequence 1: the old owner is released correctly

The useful FST events are:

| FST time | Evidence | Meaning |
| ---: | --- | --- |
| 80457 | `new_package=1`, `incoming_package_seq=1` | `package_seq_reg` takes ownership of seq=1. |
| 80773..80781 | `io_arf_copy_in=1`, `icsl_copy_start_accepted=1`, then `package_check_active=1` | COPY starts R_ICSL and the tracker owns seq=1. |
| 91641 | `arf_check_complete=1` | ARF/ECP side has reached its completion boundary. |
| 620153..620185 | `package_exec_timeout_counter` counts to `FFFF` | Instruction completion boundary was not observed in time. |
| 620185 | `package_cancelled=1`, `package_result_event=1`, `package_result_fire=1` | Existing bounded cancellation path creates a result. |
| 620189 | result valid with `status=CANCELLED`, `seq=1`; `package_check_active=0` | Result is queued and local package ownership ends. |
| 620193..620197 | result handoff completes; cleanup pending drops | Rocket-side result bookkeeping finishes. |
| 620199 | `ghm_result_deq_fire=1`, `io_clear_ic_status_tomain=10110` | GHM consumes the result and asserts BOOM slot-1 release. |
| 620201 | `ic_status_1=0`, `large_1=0` | BOOM observes the release and resets its watchdog. |

Thus seq=1 is not the owner at the time of the eventual timeout. Its
cancellation status is a normal release result for this trace.

## 4. Sequence 57 ingress and consumption

After the release, BOOM reuses checker slot 1:

| FST time | Evidence | Meaning |
| ---: | --- | --- |
| 620205 | `ic_master.io_packet_alloc_valid=1` | R_IC emits a new allocation pulse. |
| 620207 | `ic_status_1=1`, `packet_seq_counter=57`, `fsm_state=101` | The pulse allocates actual sequence 57. `io_packet_alloc_seq=58` is the continuously computed next value. |
| 620207 | data CDC `io_enq_valid=1`, sequence prefix 57, zero payload | The empty/anchor beat for seq=57 is enqueued. |
| 620213 | data CDC enqueues another seq=57 payload | A real data beat is present; this is not a missing-data case. |
| 620217..620229 | ARF CDC enqueue; `arfsSeqAccepted=1` at 620229 | ARF/CPS stream for seq=57 reaches the RocketTile. |
| 620221 | data CDC `io_deq_valid=1`; Rocket `io_packet_seq=57`, `io_packet_seq_valid=1` | The data head is consumed by the tile and raises `incoming_package_seq`. |
| 620237..620361 | CPS packet indices advance through index `0x20` | RSUSL stores the CPS tail and becomes non-idle. |
| 620381..620505 | ECP packet indices advance through index `0x20` | RSUSL stores the ECP tail; its internal status becomes `3`. |
| 620233 onward | `lsl.io_if_empty=0` | The seq=57 data is resident in LSL rather than being checked. |

At the end of the FST (`2717360`), the relevant state is still:

```text
ic_status_1                  = 1
clear_ic_status_tomain[1]   = 0
package_seq_reg              = 1
pending_package_seq_valid    = 1
pending_package_seq          = 57
pending_new_package          = 1
new_package                  = 0
checker_cleanup_done         = 0
io_rsu_status                = 1       (internal rsu_status = 3)
lsl.io_if_empty              = 0
io_package_result_valid      = 0
```

The sequence-57 data and ARF streams therefore did arrive and were consumed
by ingress logic, but they were never attached to an accepted package
transaction (`package_seq_reg` remained 1).

## 5. Why `new_package` cannot promote sequence 57

The generated [`Rocket.sv`](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/Rocket.sv:1152)
implements the following source predicates (see
[`RocketCore.scala`](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1306)):

```scala
val checker_cleanup_done = icsl.io.cleanup_done &&
  (rsu_slave.io.rsu_status === 0.U) &&
  lsl.io.if_empty && io.cdc_empty

val package_ready_for_new = !package_check_active &&
  !package_start_pending && no_result_pending &&
  (checker_cleanup_done || package_seq_reg === 0.U)

val incoming_package_seq = io.packet_seq_valid &&
  io.packet_seq =/= 0.U && io.packet_seq > package_seq_reg

val pending_new_package = pending_package_seq_valid &&
  pending_package_seq > package_seq_reg

val new_package = package_ready_for_new &&
  (incoming_package_seq || pending_new_package)
```

At 620221, `incoming_package_seq` is true for seq=57, but the CDC/data
queues are still active, so `io.cdc_empty` is false. Since the current owner
is seq=1 (`package_seq_reg != 0`), `checker_cleanup_done` and consequently
`package_ready_for_new` are false. The sequence pulse is retained in
`pending_package_seq`, which avoids losing the pulse but does not prevent the
payload from entering RSUSL/LSL.

Once seq=57 data/ARF have entered those blocks, the pending sequence cannot
be promoted: `checker_cleanup_done` requires both `rsu_status == 0` and
`lsl.io.if_empty`. Those signals cannot return to idle because no package was
accepted to drive the matching check/cleanup lifecycle.

## 6. Closed wait loop and watchdog release path

The resulting loop is:

```text
pending_new_package = 1, but cleanup_done = 0
  -> new_package = 0 and package_seq_reg stays 1
  -> no COPY/start is associated with seq=57
  -> no package_data_complete/full_check_complete for seq=57
  -> no package_result_event or result CDC enqueue
  -> GHM result_deq_fire = 0 and checker_result_release = 0
  -> clear_ic_status_tomain[1] = 0
  -> BOOM ic_status_1 remains 1
```

The non-idle storage that keeps the loop closed is visible independently:

* RSUSL sets its internal status to `1` after CPS index `0x20`, then to `3`
  after ECP index `0x20` when no ECP is required. Its output can remain `1`
  while `io.check_done` is low, so either representation is non-idle for
  `checker_cleanup_done`.
* LSL has `if_empty=0` after the seq=57 data packet is accepted. Because the
  tracker never enters checking for seq=57, no check path drains it.
* GHM has no result to dequeue, so its held release-level protocol never
  starts for seq=57. This is why the clear bit stays low; it is not a missed
  one-cycle pulse.

From 620207 until the end of the FST, the BOOM watchdog sees exactly the
condition in Section 1. The FST end state has `large_1 = 1 << 15` at
2717359. The interval from seq=57 ownership (`620207`) to that edge is
2,097,152 FST units, or `2 * 2^20`; the factor of two is the observed FST to
BOOM-clock time scale. The saved log timestamp `1359000` is from a different
time/unit presentation and should not be equated numerically with the FST
timestamp.

## 7. Root cause statement

The root cause is that the Rocket package tracker waits for a completely
empty ingress/RSUSL/LSL state before accepting a newer sequence, while the
data and ARF consumers are allowed to ingest that newer sequence before
acceptance. The saved sequence pulse is therefore converted into a pending
sequence, but its payload occupies the very resources required for
`checker_cleanup_done`. This is a self-locking admission/consumption order.

The direct assertion symptom is only the final consequence: no result release
can clear BOOM slot 1, so the per-slot ownership watchdog expires.

## 8. Version boundary and reusable commands

The FST and generated collateral are the authoritative pair for this failure.
The working Scala tree contains later protocol changes and may not generate
bit-for-bit identical RTL; generated `.sv` files were not edited. Existing
Debug notes about earlier ARF7/no-anchor and assert-21 failures describe
related but distinct waveform revisions and must not be mixed into this
seq=57 diagnosis.

Use the read-only extractor around the two important windows:

```sh
Debug/trace_assert22_1359.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  620150 620700

Debug/trace_assert22_1359.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  2717300 2717360
```

The script selects only the watchdog, BOOM release, GHM CDC, package tracker,
RSUSL, LSL, and sequence/data acceptance signals; it does not expand or
modify the waveform.
