# 2026-10-04 snapshot/commit boundary root cause

## Evidence files

- Current run: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd`
- Previous run: `Debug/test_before_snapshot_fix_20261003.vcd`
- Current log: `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log`

Both waveforms span FST time `0..3360766`. The `snapshot_quiet` guard exists
only in the current waveform; the d7 snapshot, ECP, compare failure, and final
stall occur at the same times in both runs.

## d7 event chain (FST time)

The d7 data segment was allocated earlier at `2803979` with
`packet_alloc_seq=0xd7`; later allocations were `0xd8` at `2818775` and
`0xd9` at `2836367`. The `0xd9` snapshot drives the delayed R_RSU merge that
is routed to checker 1 as the ECP for the still-owned `0xd7` segment, so the
ARF capture at `2836369` is the relevant boundary for the d7 comparison.

| Time | Signal/event | Meaning |
|---:|---|---|
| 2836357 | `rob.io_commit_arch_valids_[0..2]=0`; `snapshot_commit_prev=1` | A commit bubble follows a commit burst. |
| 2836359 | `snapshot_quiet=1`, `io_if_ready_snap_shot=1` | The new guard declares the boundary ready. |
| 2836367 | `ic_master.if_dosnap=1`, `packet_alloc_valid=1` | R_IC accepts the snapshot and allocates the next packet. |
| 2836369 | `rsu_master.doSnapshot=1` | R_RSU captures `arfs`; x12 is `0x2b`. |
| 2836371 | `rob.io_commit_arch_valids_[0..2]=1` | BOOM resumes retirement immediately after the capture. |
| 2836373 | commit uop at `0x80004892` (`addi a2,a2,-1`) | x12 changes from `0x2b` toward `0x2a` after the capture. |
| 2836397..2836529 | ECP sequence `0xd7`, index 12 = `0x2b` | R_RSU sends the captured boundary state to checker 1. |
| 2847981 | checker `sl_counter=0xb75`, `ic_counter_shadow=0xb75` | Counters are equal before the tail commit. |
| 2847989 | `io_new_commit=1`, `if_completion=1` | `R_ICSL` `+1` look-ahead completes on this commit. |
| 2847993 | `sl_counter=0xb76`, state enters postchecking | The checker has advanced one count beyond the shadow. |
| 2847997 | `compare_start=1` | Checker captures its ARF; x12 is `0x2c`. |
| 2848049 | `arf_mismatch=1` | ECP x12 `0x2b` differs from checker x12 `0x2c`. |
| 2848129 | `compare_done_error=1`, sequence `0xd7` | d7 is rejected. |

The FST timestamps are twice the BOOM Verilator cycle timestamps in this run;
the ratio is derived from the final watchdog time (`3360766 / 2` ≈
`1680383`).

## Source-level cause

`rob.io.can_commit_withoutGC` is the OR of `can_commit_noGC` in
`exu/rob.scala`; it means that a ROB head *can* commit and deliberately ignores
`gh_stall`. It does not mean that the ROB is empty or that no commit can appear
in the next cycle. `core.scala` uses this signal as `snapshot_quiet`, with only
one-cycle previous-commit guards. Therefore a normal commit bubble can satisfy
the guard while older/in-flight ROB entries remain.

`R_IC.scala` accepts `if_dosnap` in `fsm_snap` in the same cycle that it sees
`if_ready_snap_shot`. `R_RSU.scala` then captures ARF on delayed
`doSnapshot := io.snapshot`. The snapshot stalls the ROB for only the short
capture interval; after the state transition the pending ROB entries retire.
The packet allocation edge, ARF capture edge, and retirement boundary are thus
not one atomic event.

`R_RSU` later emits the saved snapshot as the ECP for the previous packet. The
mis-captured boundary becomes a deterministic one-register mismatch at the
checker, rather than a transport loss.

`R_ICSL.scala` contains a second boundary hazard: normal completion uses
`sl_counter + 1` when `io.new_commit` is high. The d7 trace proves this
look-ahead fires at equality (`sl_counter == ic_counter_shadow == 0xb75`) and
then advances to `0xb76`. This is a contributing off-by-one risk, but the
waveform does not justify treating it as the sole cause before the BOOM
snapshot/retirement boundary is corrected.

## Downstream watchdog chain

`d7 compare_done_error` prevents the safe packet watermark from advancing past
d6. The final current waveform has `safeWatermark=0xd6` and
`crossPackagePendingSeq=0xd7`; store nacks and STQ execute-head retries then
hold the oldest store. The STQ fills, ROB retirement stops, and the BOOM idle
watchdog reaches `2^18` cycles, producing the current
`BoomCore.sv:6875` assertion at log time `1680000`.

## Conclusion

The previous `snapshot_quiet` change did not solve the failure because it filters
only the immediately preceding commit and still uses a positive
“can-commit” signal as readiness. The primary fix must make package sequence,
ARF capture, and the last BOOM architectural commit share an explicit quiescent
handshake. The `R_ICSL +1` completion rule must then be re-evaluated against that
same boundary.

No source RTL, generated collateral, software, or simulation was changed in
this analysis.
