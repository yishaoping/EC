# BOOM checker watchdog signal chain

This note records a read-only analysis of
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.
The file has a `.vcd` suffix but is a Verilated FST.  No simulation, RTL
generation, or source-code change was performed for this analysis.

## Direct assertion logic

The reported assertion is generated in `gen-collateral/BoomCore.sv`:

```verilog
wire _T_299 = ~_ic_master_io_ic_status_1 | io_clear_ic_status_tomain[1];
...
if (_T_299)
  large_1 <= 27'h0;
else if (nextSmall_1[5])
  large_1 <= large_1 + 27'h1;
...
assert__assert_22: assert(~(large_1[15]));
```

The corresponding current Scala source is
`boom/src/main/scala/exu/core.scala:2037-2055`:

```scala
when (!ic_master.io.ic_status(1) || io.clear_ic_status_tomain(1)) {
  little_status1 := 0.U
}
assert(!little_status1(20), "little core 1 has hung")
```

Therefore the assertion means: BOOM checker slot 1 stayed allocated while no
release was observed for `2^20` watchdog increments.  It is a symptom of an
unfinished checker transaction, not a BOOM pipeline invariant failure.

## Waveform event sequence

The saved FST gives the following sequence for checker 1 (times are FST time
units):

| Time | Evidence | Meaning |
| ---: | --- | --- |
| 80433 | `ic_master.io_packet_alloc_valid=1` | R_IC allocates a package |
| 80435 | `packet_seq_counter=1`, `ic_status_1=1` | seq 1 owns checker slot 1; watchdog is enabled |
| 80443..80575 | BOOM `rsu_master.io_rsu_merging_valid` pulses; `merge_counter`/`io_arfs_index_0` run 0..32 | BOOM produces the complete 33-entry ARF stream, including CPS tail index `0x20` |
| 80445.. | `ghm_u_arfs_cdc_0.io_enq_valid` pulses | GHM sees the ARF stream |
| 80465 | `ghm_u_data_cdc_0.io_deq_valid=1`; `ghm_u_arfs_cdc_0.io_deq_ready=1` | One data fragment and one ARF fragment reach checker 1 |
| 80469 | checker `packet_seq_reg=1`; `rsu_slave.packet_valid=1`, `packet_index=0` | checker sees seq 1 and only the first CPS ARF entry |
| 80479 | `ghm_u_arfs_cdc_0.io_enq_ready=0` | the depth-8 ARF CDC is full; later producer pulses cannot enqueue |
| after 80469 | `ghm_u_arfs_cdc_0.io_deq_valid=1`, `io_deq_ready=0` | queued ARF entries, including index `0x20`, remain stuck |
| 2177587 | `large_1=1<<15` | watchdog bit 15 in the saved collateral becomes set |
| 2177588 | FST end | `ic_status_1=1`, `io_clear_ic_status_tomain=0`, no result release |

The saved log's `1089000` timestamp and `BoomCore.sv:6739` line do not match
this FST's `2177587` threshold transition or the current generated file's line
6759.  Treat the log and FST as evidence from different time/RTL revisions;
the logical chain is nevertheless identical.

## CDC deadlock that prevents COPY

The relevant current GHM implementation is
`rocket-chip/src/main/scala/guardiancouncil/GHM.scala`:

```scala
u_data_cdc(i).io.deq.ready := data_cdc_ready(i) && dataHeadInOrder
u_arfs_cdc(i).io.deq.ready := u_data_cdc(i).io.deq.valid && arfHeadInOrder
io.core_r_arfs_c(i) := Mux(u_arfs_cdc(i).io.deq.fire,
  Cat(true.B, u_arfs_cdc(i).io.deq.bits), 0.U)
```

This rule is safe for an *early* ARF fragment only while a matching data
fragment has not arrived.  In the observed transaction the data fragment is
consumed at 80465.  After that cycle `u_data_cdc_0.io.deq.valid` is low, so the
ARF dequeue permission is also low forever.  The ARF producer continues to
pulse valid for indices 1..32; once the eight-entry queue fills, `enq.ready`
goes low and the remaining pulses are not accepted.  This is a loss of the
package tail, not a sequence-number mismatch.

The checker consequently receives only ARF index 0.  In
`r/R_RSUSL.scala`, `rsu_status` becomes 1 only when a non-privileged CPS entry
with `packet_index == 0x20` is received.  Since the tail is missing,
`io_rsu_status` remains 0.  The software loop in
`Software/Test/core/checker.c:34-38` therefore never satisfies:

```c
(ghe_rsur_status() & 0x18) == 0x08
```

and never issues `ROCC funct=0x60`.

## Closed-loop consequence

```text
BOOM R_IC allocation (seq=1)
  -> BOOM R_RSU emits ARF/CPS entries 0..0x20
  -> GHM ARF CDC accepts only the prefix; dequeue stalls after one entry
  -> Rocket checker receives seq=1 and packet index 0 only
  -> R_RSUSL rsu_status stays 0
  -> software keeps polling funct=0x61 / funct=0x07
  -> no funct=0x60 COPY
  -> no io_arf_copy_in / arf_paste_reg
  -> no icsl_copy_start_accepted or package_check_active
  -> no package_result_valid
  -> no GHM result_deq_fire / result_release_pending
  -> clear_ic_status_tomain[1] stays 0
  -> BOOM ic_status_1 stays 1
  -> little_status1/large_1 reaches the assertion bit
```

The normal release path, which is not reached in this FST, is:

```text
Rocket package result
  -> GHM result CDC dequeue
  -> checker_result_release (held until BOOM status clears)
  -> clear_ic_status_tomain[1]
  -> BOOM R_IC clear_ic_status[1]
  -> ic_status_1=0
  -> watchdog counter reset
```

Do not replace this ownership release with `ghe_release()` or a session FINISH
pulse: those are software/session notifications and do not prove that the
sequenced package result was delivered.

## Source fix applied

The source now keeps a per-checker `dataConsumedSeq` in the Rocket checker
clock domain.  GHM holds an early ARF until the matching data transfer fires;
after that anchor fires, ARF/CPS entries of the consumed sequence may drain
even when the one-shot data vector is no longer valid.  A newer ARF sequence is
still held until its own data anchor arrives.  The BOOM tile also feeds the GHM
CDC-full indication into `R_RSU.io.big_hang`, so the producer merge counter is
paused while the ARF CDC queue is full instead of dropping one-cycle entries.

The edits are in:

- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala`
- `chipyard/generators/boom/src/main/scala/common/tile.scala`

These source changes were compile-checked with `sbt -batch 'project chipyard'
compile`; no RTL generation or simulation was run, so waveform validation of
the fix remains a later step.

## Reusable trace

Build `Debug/fst_signal_trace` as described in
`Debug/signal_chain_analysis.md`, then run:

```sh
Debug/trace_watchdog_chain.sh test.vcd 80435 80600
Debug/trace_watchdog_chain.sh test.vcd 2177400 2177588
```

The first window is the useful CDC diagnosis.  The second window shows the
watchdog threshold and the still-busy BOOM ownership state.  The script is
read-only and does not touch generated collateral.

## Version boundary

The generated RTL, saved FST, saved log, and current Scala tree are not one
guaranteed revision: line numbers differ and earlier Debug notes document
additional intermediate Rocket/BootROM changes.  Generated RTL must not be
edited as a workaround.  Before validating a future source fix, regenerate
normal Chipyard collateral and capture a new waveform; this analysis itself
does not do that.
