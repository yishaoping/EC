# `assert__assert_21` pipeline-hang analysis

## Scope and conclusion

This analysis is read-only.  It uses the generated `BoomCore.sv` that emitted
the failure and the matching saved `test.vcd` FST container; no simulation or
RTL/hardware generation was run.  Where the Scala tree has since changed, the
generated collateral and waveform remain the authoritative pair for this
failure, while source references identify the intended logic.

The reported assertion is:

```verilog
assert__assert_21: assert(~(large_0[15]));
// BoomCore.sv:6758, @[core.scala:1755]
```

It is BOOM's main pipeline idle watchdog, not the per-checker `little_status`
watchdog (`assert__assert_22` and later).  The source is
`boom/src/main/scala/exu/core.scala:1747-1755`:

```scala
val idle_cycles = WideCounter(32)
when (rob.io.commit.valids.asUInt.orR ||
      csr.io.csr_stall || io.rocc.busy || reset.asBool) {
  idle_cycles := 0.U
}
assert (!(idle_cycles.value(20)), "Pipeline has hung.")
```

In the generated `WideCounter`, `small_0` is the low five bits and `large_0`
counts groups of 32 cycles.  Therefore `large_0[15]` means 2^20 consecutive
cycles without any of the four reset conditions.

## Exact waveform evidence

The waveform ends at FST time `2202728`.  The assertion bit rises at
`2202727`:

```text
large_0 = 0x8000       // large_0[15] = 1
```

The last BOOM ROB commit activity is at FST `105575`; from there to the
assertion is exactly `2202727 - 105575 = 2097152 = 2 * 2^20` FST units.  The
saved waveform therefore shows a genuine full watchdog interval, not a
one-cycle assertion glitch.  At the assertion window:

```text
reset                         = 0
rob.io_commit_valids[2:0]     = 000
csr.io_csr_stall              = 0
io_rocc_busy                  = 0
io_gh_stall                   = 0
io_big_hang                   = 1
ic_master.io_if_pipeline_stall = 1
```

`io_gh_stall` and `io_big_hang` are not counted as watchdog reset sources.
They can nevertheless prevent ROB commit through `rob.io.gh_stall`.

## Full signal chain

```text
R_IC.if_pipeline_stall
  -> BOOM core ic_stall
  -> rob.io.gh_stall = io.gh_stall | rsu_stall | ic_stall | io.big_hang
  -> ROB can_commit is false / rob.io.commit_valids = 0
  -> idle_cycles increments every BOOM cycle
  -> large_0[15] = 1
  -> assert__assert_21
```

The relevant RTL/source links are:

* `core.scala:2084`: `ic_stall := ic_master.io.if_pipeline_stall`.
* `core.scala:1112`: `rob.io.gh_stall := io.gh_stall | rsu_stall | ic_stall | io.big_hang`.
* `boom/src/main/scala/exu/rob.scala:446`: commit requires `!io.gh_stall`.
* `core.scala:1749-1755`: the idle watchdog reset/ assert condition.

## Guardian packet/ARF evidence before the hang

The first persistent stop occurs around FST `105575`:

1. `gh_buf` emits the final visible data packet(s), then reports
   `buf_all_empty=1` and `io_ght_filters_empty=1` between bursts.
2. `R_IC` moves through postcheck/scheduling and asserts
   `io_if_dosnap` and `io_packet_alloc_valid` at `105583`.
3. At `105585`, `packet_seq_counter` is 7, `packet_alloc_seq` is 8, while
   `active_packet_seq` and `checker_segment_id_4` are still 7.  The generated
   sequence fields are registered, so the allocation pulse and the segment
   watermark are observed on adjacent edges.
4. The data CDC producer has no valid data anchor for the new sequence at the
   allocation edge.  The ARF CDC then enqueues sequence-7 entries from
   `105595` through `105623`; its `io_enq_ready` becomes 0 at `105625`.
5. `gh_buf.io_cdc_not_ready` and BOOM `io_big_hang` become 1 at `105625`.
   `GH_BUF` correctly stops dequeuing while CDC is not ready, but the already
   asserted `R_IC.if_pipeline_stall` keeps the ROB stopped.

### Why sequence 7 has no data anchor

The missing anchor is produced by a control-plane/data-plane race, not by a
late dequeue of an existing sequence-7 data item:

| FST time | Control/data observation |
|---|---|
| `105577` | `GH_BUF` has a valid packet for checker 4; GHM data `enq_valid=1`, and the 32-bit sequence prefix is `6`. |
| `105579` | `GH_BUF.buf_all_empty=1`, `io_ght_filters_empty=1`, `io_gh_packet_dest=0`, and data `enq_valid=0`. |
| `105583` | `R_IC.io_if_dosnap=1` and `io_packet_alloc_valid=1`; with the pre-edge counter at 6, this allocates the next actual package sequence, 7. |
| `105585` | The registered segment watermark becomes 7 (`active_packet_seq=7`, `checker_segment_id_4=7`), but data `enq_valid` is still 0. The visible data `enq_bits` prefix 7 is only invalid combinational metadata, not a packet. `io_packet_alloc_seq=8` here is the continuously computed *next* sequence after the register update, not the sequence allocated by the pulse. |
| `105595` onward | R_RSU starts emitting sequence-7 ARF/CPS entries; there is still no sequence-7 data enqueue. |

The source code permits this ordering:

1. `R_IC` defines `package_allocated` solely as
   `snapshot_accepted && !ctrl(0)` (`R_IC.scala:161-171`). It does not require a
   GH_BUF packet, a data CDC `enq.fire`, or even a non-empty instruction segment.
2. `GH_BUF` generates data only from committed uops and drives `gh_packet_dest`
   to zero when its FIFOs are empty (`GH_BUF.scala:120-130, 205-253`). There is
   no allocation/anchor handshake and no sequence stored with each buffered
   packet.
3. GHM asserts data CDC valid only from the current packet destination
   (`GHM.scala:164-184`), while it obtains the sequence tag from the live
   `checker_segment_id_bigcore`. Thus a new segment watermark can exist with no
   data transaction; the sequence prefix on `enq_bits` is not a validity bit.
4. R_RSU starts its merge after the snapshot through independent delayed
   pulses (`core.scala:2110-2141`, `R_RSU.scala:94-102`). Its ARF/CPS valid path
   does not wait for a data anchor or a data CDC fire.

The BOOM pipeline is already stalled at the boundary (`io_if_pipeline_stall=1`),
so once the empty segment allocates sequence 7 there is no later commit from
which GH_BUF could create a first data packet. This is the fundamental protocol
invariant violation: the producer can issue an ARF/CPS package for every
snapshot, but the consumer assumes every sequence has a data anchor.

At the final waveform edge, checker 4's queue state is:

```text
ghm_dataConsumedSeq_3              = 6
ghm_u_data_cdc_3.io_deq_valid      = 0
ghm_u_arfs_cdc_3.io_deq_valid      = 1
ghm_u_arfs_cdc_3.io_deq_ready      = 0
ghm_u_arfs_cdc_3.io_enq_ready      = 0
ghm_checkerSessionDone_3_checkerDone = 0
```

The current GHM ordering equations explain the stall:

```scala
val dataHeadInOrder = !arf.valid || dataSeq <= arfSeq
val arfHeadInOrder  = !data.valid || arfSeq <= dataSeq
u_data_cdc.deq.ready := data_cdc_ready && dataHeadInOrder
u_arfs_cdc.deq.ready := arfHeadInOrder &&
  (u_data_cdc.deq.fire || arfAfterData)
val arfAfterData = dataConsumedSeq =/= 0.U && arfSeq <= dataConsumedSeq
```

With no data anchor for sequence 7, `dataConsumedSeq_3=6` cannot authorize the
sequence-7 ARF head.  The ARF FIFO remains full, `arfs_cdc_busy` remains high,
and `GHM.io.bigcore_hang` drives the BOOM tile's `cdc_not_ready` path:

```text
GHM cdc_busy/arfs_cdc_busy
  -> GHM bigcore_hang
  -> BoomTile hang_bits & checker mask
  -> cdc_not_ready
  -> GH_BUF.io_cdc_not_ready and core.io_big_hang
```

The generated hierarchy exposes the propagated checker bit at FST `105625` as
`tile_reset_domain_boom_tile.hang_bits = 4'b1000` (checker 4), together with
`gh_buf.io_cdc_not_ready = 1` and `core.io_big_hang = 1`.  This closes the
cross-domain path; it is not an inferred connection from the assertion alone.

This is consistent with the final signals: the data FIFO is empty and ready,
while checker 4's ARF FIFO is valid but blocked.  No result release is present,
and no checker-session completion is observed.

The deadlock then becomes self-sustaining: `arfs_cdc_busy` asserts
`bigcore_hang`, which is fed back as `core.io.big_hang`; BOOM cannot commit a new
instruction, while R_RSU freezes `merge_counter` whenever `io.big_hang` is true
(`R_RSU.scala:156-158`). Therefore the missing anchor cannot be recovered by
waiting for the merge to finish.

## Root cause versus assertion symptom

* **Direct assertion symptom:** BOOM has no ROB commit, CSR stall, RoCC busy, or
  reset for 2^20 BOOM cycles, so `idle_cycles.value(20)` becomes true.
* **Immediate blocking condition:** `R_IC.io_if_pipeline_stall=1` reaches
  `rob.io.gh_stall`; the later `io_big_hang=1` adds CDC backpressure.
* **Upstream protocol condition supported by the waveform:** the data stream's
  last consumed sequence is 6, while ARF sequence 7 is present without a
  corresponding data anchor.  The ARF queue fills and cannot advance.
* **Not established by this assertion alone:** a generic claim that every
  packet was only partially consumed.  The precise failure is a sequence-7
  data/ARF anchor mismatch.  The earlier data packets were consumed; the tail
  ARF/CPS entries are held because their data package anchor is absent.

The older `Debug/watchdog_signal_chain.md` describes the related checker
watchdog path (`assert__assert_22`).  This file distinguishes that downstream
watchdog from the present main-pipeline `assert__assert_21`, while retaining
the same reusable CDC/package ownership evidence.

## Reuse

Run the read-only extractor around a future assertion with FST time units:

```bash
Debug/trace_pipeline_hang_assert21.sh test.vcd 2200000 2202728
```

The script selects only the counter, ROB commit reset sources, BOOM stall
inputs, GH buffer, GHM data/ARF CDC, sequence watermark, and release/session
signals needed to reconstruct this chain.
