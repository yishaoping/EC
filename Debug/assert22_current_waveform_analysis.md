# `assert__assert_22` signal-chain analysis

This is a read-only analysis of the checked-in Scala sources, the current
generated collateral, and
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.
The waveform file has a `.vcd` suffix but is an FST container. No simulation,
Verilator replay, RTL generation, or hardware generation was run.

## 1. Assertion meaning

The reported line is the checker-1 watchdog:

```text
BoomCore.sv:6760: assert__assert_22
```

Generated RTL maps it to:

```verilog
wire _T_299 = ~_ic_master_io_ic_status_1 |
              io_clear_ic_status_tomain[1];

if (_T_299)
  large_1 <= 27'h0;
else if (nextSmall_1[5])
  large_1 <= large_1 + 27'h1;

assert__assert_22: assert(~(large_1[15]));
```

References: generated [BoomCore.sv](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv:6679),
[BoomCore.sv](/data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv:6760),
and source [core.scala](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2037).

`little_status1` is a 32-bit `WideCounter`. Its low counter is 5 bits and the
asserted bit is bit 20 of the combined count (`large_1[15]`), so the condition
is approximately:

```text
ic_status_1 == 1
and clear_ic_status_tomain[1] == 0
for 2^20 BOOM counter increments
```

The assertion is therefore an ownership-release watchdog. It does not identify
an illegal BOOM instruction by itself.

## 2. Complete signal chain

```text
BOOM R_IC allocates checker slot 1, sequence 1
  -> R_IC.ic_status(1) = 1
  -> BOOM little_status1 watchdog is enabled

BOOM R_RSU emits CPS/ARF stream for sequence 1
  -> GHM ARF CDC and data CDC
  -> Rocket checker receives data anchor and ARF entries
  -> R_RSUSL receives the ECP tail and raises if_cp_check_completed

software issues COPY (RoCC funct 0x60)
  -> RocketCore.io_arf_copy_in
  -> arf_paste_reg
  -> icsl_copy_start_accepted
  -> R_ICSL enters fsm_checking
  -> package_check_active = 1

data/LSL/ARF/CSR package predicates become true
  -> full_check_complete = 1
  -> package_result_event = 1
  -> package_result_queue enqueues {status=FAIL, seq=1}
  -> package_check_active = 0
  -> package_result_outstanding = 1

result handoff gate remains closed
  -> package_result_queue.deq.valid = 1, but package_locally_ready = 0
  -> io_package_result_valid = 0
  -> GHM result CDC enq.valid = 0
  -> GHM result_deq_fire_0 = 0
  -> checker_result_release(0) = 0
  -> clear_ic_status_tomain[1] = 0
  -> R_IC.ic_status(1) remains 1
  -> little_status1 reaches bit 20
  -> assert__assert_22 fires
```

The index mapping is important: GHM checker index `0` is global core/slot
index `1`, because global index `0` is the BOOM core. Consequently GHM's
`checker_result_release(0)` drives `clear_ic_status_tomain[1]`.

## 3. Waveform evidence

The useful events are in FST time units:

| Time | Signal evidence | Interpretation |
| ---: | --- | --- |
| 80433 | `R_IC.io_packet_alloc_valid = 1` | package allocation begins |
| 80435 | `packet_seq_counter = 1`, `ic_status_1 = 1` | sequence 1 owns BOOM slot 1 |
| 80443..80589 | `R_RSU.io_rsu_merging_valid` and ARF indices advance through CPS tail `0x20` | BOOM produces the sequence-1 ARF/CPS stream |
| 80457 | `ghm_u_data_cdc_0.io_deq_valid = 1`, `ghm_u_arfs_cdc_0.io_deq_valid/ready = 1` | first data/ARF transfer reaches checker 0 |
| 80461..80465 | data anchor is consumed; ARF entries continue | sequence 1 has a data anchor; this is not an ARF7/no-anchor stall |
| 80773 | `io_arf_copy_in = 1`, RoCC funct is `0x60` | software starts COPY |
| 80777 | `icsl_copy_start_accepted = 1`, `arf_paste_reg = 1` | R_ICSL start request accepted |
| 80781 | `package_check_active = 1` | package tracker owns sequence 1 |
| 91641 | `rsu_slave.io_if_cp_check_completed = 1`, `arf_check_complete = 1` | ARF/ECP comparison completes |
| 91673 | `full_check_complete = 1`, `package_result_event = 1`, `package_result_fire = 1` | result `{status=01, seq=1}` is enqueued locally; status `01` is FAIL |
| 91677 | `package_result_queue.io_deq_valid = 1`, `package_check_active = 0`, `package_result_outstanding = 1` | result is waiting in the local queue |
| 91677 onward | `io_package_result_valid = 0`, `package_locally_ready = 0`, `package_local_clear_event = 0`, `icsl.io_clear_ic_status = 0` | result cannot cross into GHM |
| final FST time 2177588 | `ic_status_1 = 1`, `clear_ic_status_tomain[1] = 0`, `result_deq_fire_0 = 0`, `result_release_pending_0 = 0`, `large_1[15] = 1` | ownership was never released before the watchdog threshold |

The saved error timestamp (`1089000`) and the FST threshold/end time
(`2177588`) are not numerically identical. The line numbers and generated
collateral also identify different revisions/time scales. The final logical
state is consistent, but the FST must not be used to claim an exact cycle for
the saved log.

## 4. Why the result is blocked

The current RocketCore source explicitly gates result dequeue:

```scala
val package_local_clear_event = icsl.io.clear_ic_status.asBool &&
  (package_check_active || package_result_waiting || package_result_queue.io.deq.valid)
val package_locally_ready = package_local_clear_seen || package_local_clear_event
package_result_queue.io.deq.ready := io.package_result_ready && package_locally_ready
io.package_result_valid := package_result_queue.io.deq.valid && package_locally_ready
```

References: [RocketCore.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:1368).

At the failure point the queue is valid and the external ready is `1`, but the
local-clear term is `0`, so `io_package_result_valid` remains `0`.

The local clear comes from R_ICSL's reset state only:

```scala
is (fsm_reset) {
  clear_ic_status := 1.U
  fsm_state := fsm_nonchecking
}
```

In the saved waveform `R_ICSL.fsm_state` is still `2` (`fsm_checking`) at the
end of the trace. In that state `clear_ic_status` is hard-coded to `0`. The
normal transition out of checking is controlled by the instruction-count
predicate:

```scala
fsm_state := Mux(io.self_xcpt, fsm_self_xcpt,
  Mux(if_completion && !io.something_inflight,
      fsm_postchecking, fsm_checking))
```

`io.if_check_completed` is only latched as `package_completion_seen`; it does
not itself transition `fsm_checking` to `fsm_postchecking`. At the final FST
state, `if_completion = 0`, `io_if_check_done = 0`, and `sl_counter` is below
`ic_counter_shadow`, while `package_completion_ready = 1`. Thus the package
tracker has declared its data/ARF/LSL/CSR tail complete before R_ICSL has
reached its own instruction-completion/reset boundary.

This is the direct blocking condition in this run: **package result creation
and R_ICSL execution completion are not ordered, while result delivery waits
for R_ICSL local clear**.

## 5. Why BOOM never clears the slot

GHM's result path is intentionally separate from the legacy local clear path:

```scala
u_result_cdc(i).io.enq.valid := io.checker_result_in(i)(valid)
u_result_cdc(i).io.deq.ready := !result_release_pending(i)
checker_result_release(i) := result_release_pending(i) || result_deq_fire
io.clear_ic_status_tomain := Cat(Cat(checker_result_release.reverse), 0.U(...))
```

References: [GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:459),
[GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:479),
[GHM.scala](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:524).

Because the Rocket result valid bit is zero, the result CDC never enqueues and
`result_deq_fire_0` never occurs. `R_IC` only clears its ownership bit when its
input clear is asserted; no allocation-side signal can clear this slot. The
watchdog therefore counts exactly the condition it was designed to detect.

## 6. What this trace does and does not prove

This trace does prove:

- checker slot 1 was allocated and remained owned;
- sequence 1 reached the data anchor and ARF/ECP completion;
- the checker result was locally generated but not handed to GHM;
- no BOOM-side release occurred before the watchdog threshold.

It does **not** prove that the current Scala tree has exactly the same runtime
behavior, because the saved FST was produced from generated collateral that is
not guaranteed to be the same revision as the working tree. Existing Debug
notes also document an earlier ARF CDC deadlock; the present sequence-1 FST
contains the newer `dataConsumedSeq/arfAfterData` behavior and reaches the ARF
tail. Do not conflate that earlier ARF-prefix failure with this result-handoff
deadlock.

## Reusable trace command

The existing reader can be reused without converting the complete FST:

```sh
Debug/trace_watchdog_chain.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  80425 80790

Debug/trace_watchdog_chain.sh \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  91635 91700
```

The first window shows allocation, anchor consumption, and COPY. The second
shows result enqueue followed by the closed local-clear gate. This report and
the trace script are intended for later static/waveform debugging; no RTL was
modified in this analysis.
