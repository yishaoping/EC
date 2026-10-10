# `assert__assert_24` at 1187000: comprehensive signal-chain analysis

This report reconstructs the failure from the current generated collateral,
the Scala/C sources, and
`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`.  The
waveform has an FST payload despite its `.vcd` suffix.  This investigation is
read-only: it did not run simulation, replay Verilator, elaborate RTL, or
generate hardware.

## Executive diagnosis

`assert__assert_24` is the BOOM ownership watchdog for checker slot 3.  Its
threshold did not become shorter.  Slot 3 was allocated sequence 45 at FST
time 277813 and remained owned until `large_3[15]` asserted at 2374965:

```text
2374965 - 277813 = 2097152 FST units
                  = 2 * 2^20
```

The factor two is the BOOM clock period in this trace.  The direct failing
chain is:

```text
seq40 enters R_ICSL postchecking
  -> a machine-timer interrupt arrives after the state transition
  -> postchecking does not enter the self-exception state
  -> package completion redirects directly to pc_special
  -> the architectural trap is abandoned without mret
  -> RocketCore.excpt_mode remains set
  -> cleanup/admission nevertheless reports the checker reusable
  -> seq45 is admitted and COPY starts R_ICSL checking
  -> excpt_mode masks R_ICSL.if_correct_process
  -> checker mode and sl_counter remain zero
  -> 474 seq45 memory logs enter LSL, but none can be requested
  -> LSL remains non-empty
  -> both existing package timeouts remain disabled
  -> no PASS/FAIL/CANCELLED result reaches GHM
  -> no slot-3 release reaches BOOM
  -> the unchanged 2^20-cycle ownership watchdog expires
```

This is not a missing seq45 data anchor and not a recurrence of the old seq57
admission self-lock.  The previous admission change worked: seq45 is
sequenced, started, and active.  It exposed trap-lifecycle and progress-timeout
holes which were previously hidden by the earlier slot-1 failure.

The same waveform also contains an independent LSL backpressure failure on
checker4.  It is important because a trap-only fix would merely move the first
watchdog failure again.

## 1. Assertion and ownership mapping

Generated `BoomCore.sv` contains:

```verilog
wire _T_309 = ~_ic_master_io_ic_status_3 |
              io_clear_ic_status_tomain[3];

if (_T_309)
  large_3 <= 0;
else if (nextSmall_3[5])
  large_3 <= large_3 + 1;

assert__assert_24: assert(~large_3[15]);
```

The source assertion is `boom/.../exu/core.scala:2057`.  Global slot 3 maps to
Rocket hart3, `tile_prci_domain_3`, and GHM checker index 2.  Its only normal
external release path is:

```text
Rocket package_result {status, seq}
  -> GHM u_result_cdc(2)
  -> ghm_result_deq_fire_2
  -> result_release_pending_2
  -> clear_ic_status_tomain[3]
  -> R_IC.ic_status(3) clears
```

At the FST end all those result/release signals are zero while
`ic_status_3=1` and `checker_segment_id_3=45`.

## 2. The seq40 trap leaks across the package boundary

The decisive events are:

| FST time | Evidence | Meaning |
| ---: | --- | --- |
| 277417 | `ICSL.fsm_state=110`, `package_exec_done=1` | seq40 has entered normal postchecking. |
| 277429 | `trace.exception=1`, cause `0x8000000000000007` | machine-timer interrupt occurs after entry to postchecking. |
| 277433 | `excpt_mode=1`, `ICSL.if_correct_process=0` | RocketCore records the outstanding trap. |
| 277593 | `full_check_complete/result_fire=1`, result `{FAIL, seq40}` | seq40's package result is valid. |
| 277597 | `ICSL.if_ret_special_pc=1` | postchecking requests a direct redirect despite the outstanding trap. |
| 277607 | `ghm_result_deq_fire_2=1`, clear mask `01000` | seq40 releases BOOM slot 3 correctly. |
| 277697 | WB PC equals `pc_special=0x80001dd8` | the forced return reaches checker management code. |
| 277701..277705 | ICSL reset then nonchecking | local cleanup completes, but `excpt_mode` is still one. |

The interrupted PC was `0x800007d8` in `gapbs_bfs_run`; `pc_special` is
`0x80001dd8` in `checker`.  This is not an `mret`.  RocketCore clears
`excpt_mode` only on a matching `csr.io.eret`, so direct `pc_special` return
leaves the exception bookkeeping asserted.

The state-machine hole is in `R_ICSL.scala:213-225`: normal postchecking
unconditionally remains in checker mode and issues `if_rh_cp_pc` when package
completion arrives.  Only `fsm_checking` handles `io.self_xcpt`; an interrupt
arriving after the transition to postchecking has no exception transition.

## 3. seq45 is admitted in a non-runnable context

The admission/start sequence is healthy in isolation:

| FST time | Evidence |
| ---: | --- |
| 277811..277813 | BOOM allocates slot3; sequence and segment ID become 45. |
| 277825 | data anchor dequeues; `incoming_package_seq=1`, `new_package=1`. |
| 277829 | `package_seq_reg=45`, `package_start_pending=1`. |
| 278029..278033 | COPY arrives and `package_start_accepted=1`. |
| 278037 | `package_check_active=1`, ICSL enters checking. |

Admission checks `ICSL.cleanup_done`, RSUSL idle, and LSL empty, but does not
check `excpt_mode`, a completed trap/`mret`, or whether the management context
has really been restored.  Consequently the clean local storage state is
mistaken for an executable checker state.

Once checking starts, RocketCore drives:

```scala
icsl.io.if_correct_process := io.if_correct_process & !excpt_mode
```

The external process match is one, but `excpt_mode` is also one.  R_ICSL is in
`fsm_checking` while its effective process match is zero, so
`icsl_checkermode=0` and `sl_counter=0` for the rest of the trace.

## 4. seq45 data arrived and was not consumed

Every data CDC payload in the seq45 window carries sequence 45.  The empty
anchor is followed by real data, so these are not delayed seq40 fragments.
R_LSL receives 474 memory-log records between 277837 and 281005:

```text
446 stores, 28 loads
first: store data=0x1b8 addr=0x800000008000a7a4
last:  store data=0x1c8 addr=0x800000008000a960
```

The first local FIFO writes occur at 277841.  `lsl.io_if_empty` falls at
277845.  Because checker mode is zero, `lsl.io.req_valid`, both memory FIFO
`deq_ready` signals, and `sl_counter` remain zero.  At the assertion edge:

```text
package_seq_reg              = 45
package_check_active         = 1
excpt_mode                   = 1
ICSL fsm_state               = checking
ICSL if_correct_process      = 0
ICSL checker_mode            = 0
ICSL sl_counter              = 0
io_cdc_empty                 = 1
LSL if_empty                 = 0
RSUSL internal status        = 3
package_data_complete        = 0
package_exec_waiting         = 0
package_exec_timeout_counter = 0
package_cancelled            = 0
package_result_valid         = 0
```

This also identifies a timeout coverage bug.  The ARF timeout requires
`lsl.empty`, and the execution timeout requires `package_data_complete`, which
itself requires `lsl.empty`.  Thus an active package with a non-empty LSL and
zero forward progress is outside every bounded cancellation path.

## 5. RoCC status is a downstream amplifier, not the seq45 anchor cause

After being redirected out of the trap, checker3 eventually reaches the
application loop at `0x8000039c..0x800003a8`:

```c
while ((status = ght_get_status()) < 0x1FFFF) {}
```

Instruction `0x0cc5f52b` at `0x800003a4` is a writeback RoCC command with
`funct=0x06`.  The BOOM GHE latched `bigComp_reg=3` at time 207, but every
Rocket checker GHE retains zero.  This follows directly from
`HasTiles.scala:491-521`: checker tiles receive an undriven/dummy
`bigcore_comp` source, whereas the BOOM tile is connected to GHM.

At 2298997, for example, checker3 gets a valid local RoCC response with data
zero and writes zero to `a0`.  Since sticky `excpt_mode` has already forced
`icsl_checkermode=0`, `lsl_req_valid_rocc=0`; the local result is used rather
than a BOOM log replay.  The branch therefore repeats every 24 FST units.

This command is beyond seq45's intended replay progress: seq45 contains only
memory packet types 1 and 2 and no type-5 RoCC record.  Therefore “missing
RoCC log caused seq45 not to start” would invert causality.  The checker first
lost checker mode; only then did it execute beyond the intended boundary and
become trapped in a non-replayed, topology-dependent status loop.

## 6. Independent systemic issue: checker4 LSL backpressure loses logs

The final cross-check is not checker3-specific:

| Hart/slot | Sequence | Final state |
| --- | ---: | --- |
| checker1/slot1 | 54 | start pending, LSL/RSUSL non-idle |
| checker2/slot2 | 50 | active, `excpt_mode=1`, checker mode 0, `sl_counter=0` |
| checker3/slot3 | 45 | active, `excpt_mode=1`, checker mode 0, `sl_counter=0` |
| checker4/slot4 | 53 | active, checker mode 1, stalled memory replay |

checker2 repeats the same postchecking race: timer interrupt at 301829,
forced special return at 301945, seq50 admission at 301981, and COPY/start at
302301..302305 while `excpt_mode` remains asserted.

checker4 exposes a separate loss mechanism.  seq53 supplies 746 memory logs.
At 320577 R_LSL asserts near-full and deasserts `lsl.io.cdc_ready`, but
RocketCore's aggregate packet ready remains high until 321041 because it is:

```scala
rsu_slave.io.cdc_ready | lsl.io.cdc_ready | io.imem.bjl_cdc_ready
```

That OR is type-insensitive.  The waveform identifies the bypassing input:
`io.imem.bjl_cdc_ready` remains one until 321041 even though the presented
records are memory types and `lsl.io.cdc_ready` is zero.  During the mismatch
interval GHM dequeues and presents 85 memory records while only 14 memory
dequeues occur.  The per-lane memory FIFOs are already at the `depth-2`
near-full threshold.  `GH_MemFIFO` has no enqueue ready/accepted handshake and
simply ignores `enq_valid` while full, so overflowed records are silently lost.

The observable consequence arrives at 333013..333029: memory channel0 becomes
empty, the round-robin dequeue pointer returns to channel0, but channel1 is
still non-empty.  The checker repeatedly executes the `memset` store at
`0x80002c9c`; `lsl.req_ready=0` and `replay_wb=1`, so the pointer can never
advance to channel1.  At the assertion edge checker4 has retired 3846 of its
4115 target instructions and is still replaying that store.

This proves that fixing only exception-aware admission would leave another
closed wait in the same package-consumption subsystem.

## 7. Why the failure moved from 1359000 to 1187000

The prior FST failed on slot1/seq57.  Its ownership interval began at 620207
and reached the same fixed threshold at 2717359, corresponding to the reported
time near 1359000.  The admission fix removed that earlier seq57 self-lock and
allowed more package traffic to proceed.

In the current FST, stuck slot3/seq45 begins ownership much earlier, at 277813,
and reaches the unchanged threshold at 2374965, corresponding to time near
1187000.  The difference is the start of the oldest unreleased owner, not a
shorter counter:

```text
old first stuck owner start: 620207
new first stuck owner start: 277813
difference / FST-to-log scale: about 171200 reported time units
```

That matches the observed failure moving earlier by roughly 172000.  The last
change therefore did not directly reduce the watchdog.  It removed one
blocking mode and exposed two deeper protocol failures sooner.

## 8. Root-cause hierarchy

The causes should be fixed as protocol invariants rather than as slot3 special
cases:

1. **Trap/package lifecycle is incomplete.**  Postchecking must not abandon an
   outstanding architectural trap, and checker reuse must require a genuinely
   restorable execution context, not only empty local storage.
2. **Packet backpressure is not type-correct.**  A memory packet must advance
   only when the LSL destination can accept every valid lane.  OR-ing unrelated
   destination ready signals violates losslessness.
3. **R_LSL enqueue is not a handshake.**  FIFO-full currently drops data with
   no upstream accounting or assertion.
4. **Progress supervision has a blind region.**  `active && !lsl.empty` and
   `start_pending` have no progress/age timeout, so the BOOM watchdog is the
   first and least local diagnostic.
5. **Nondeterministic RoCC state is not coherent outside checker mode.**  The
   dummy checker `bigcore_comp` source makes local `funct=0x06` behavior differ
   from BOOM.  It is not the first seq45 cause, but it turns an escaped checker
   into an infinite software loop and should not be relied on as a local value.

Use `Debug/trace_assert24_1187.sh` to reproduce the focused `trap`,
`watchdog`, `rocc`, `backpressure`, and `final` views without converting the
full FST.
