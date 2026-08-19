# GuardianCouncil / BOOM-Rocket Protocol Audit

This note records the static audit of the worktree at 2026-08-15. It uses the
checked-in Rocket/BOOM sources and the existing waveform/log; it does not run a
simulation or generate RTL.

The Scala/Chisel source compiles with Java 17 using
`sbt -batch 'project chipyard' compile`; this check does not elaborate a target
or update `generated-src`.

## Observed failure chain

The first failing run reaches the BootROM load on each Rocket checker. The
relevant sequence is:

1. A checker executes the BootROM load of the BOOM entry address.
2. `wb_dcache_miss` is asserted and the load destination must be marked busy
   until `ll_wen` receives the response.
3. The current `Scoreboard.clearAll(icsl_start_accepted)` is implemented as an
   unconditional `update(en, 0.U)`. Because `Scoreboard.update` uses the final
   `_next` value when any earlier update enabled the register, the generated
   priority is effectively `if (wb_miss || copy_start) scoreboard := 0`, even
   when `copy_start` is false. The dependency is therefore lost.
4. The following `csrw mepc,a0` observes the stale `a0=0x4000` instead of the
   outstanding load value `0x80000000`, then `mret` jumps to `0x4000`.
5. The instruction access faults and the checker loops through the trap vector.
   No checker reaches COPY/R_ICSL, so no package result can ever release BOOM.

The same sequence is visible for checker harts 1--4; the failure is not
hart-specific.

## Signal contract

| Stage | Producer | Signal/field | Consumer | Contract |
|---|---|---|---|---|
| Package allocation | BOOM `R_IC` | `packet_alloc_valid`, `packet_alloc_seq` | BOOM DCache | One monotonically increasing non-zero sequence per accepted CPS. |
| Segment attribution | BOOM `R_IC` | `checker_segment_id` | GHM | The target checker keeps the CPS sequence until result release. |
| Data CDC | GHM | `valid + seq + 2*136-bit packet` | Rocket checker | Dequeue only the oldest sequence shared with the ARF/CSR stream. |
| ARF/CSR CDC | GHM | `valid + seq + ARF payload` | Rocket checker | Routing metadata is consumed in GHM; sequence is not truncated. |
| Checker execution | Rocket `R_ICSL`/RSUSL/CSR | LSL empty, ARF complete, CSR required/complete | RocketCore package tracker | These are independent completion facts; no single one is the package tail. |
| Result CDC | Rocket checker | `valid + seq + PASS/FAIL/CANCELLED` | GHM then BOOM | The result is held until enqueue and released only on BOOM-domain dequeue. |
| BOOM release | GHM | `clear_ic_status_tomain` | BOOM `R_IC` | Exactly one pulse per dequeued sequenced result. |
| Dirty writeback stats | BOOM DCache | first accepted C beat and line attribution | traffic counters | Data-bearing C messages are dirty writebacks; attribution is sampled from the line, not current checker state. |

## Classification

### Must remain for the requested feature

- Packet sequence constants and fixed counter indices.
- Sequence propagation through R_IC, GHM packet/ARF CDC, RocketTile, RocketCore,
  BOOM LSU/MSHR/DCache, and result CDC.
- Package completion tracking and result status encoding.
- DCache line attribution and first C-beat dirty-writeback accounting.
- START/STOP/RESET counter plumbing and the 35-entry software readback vector.

### Compatibility changes that need to be retained but constrained

- The GHM producer-empty indication must be a synchronized level; a pulse can
  be missed by a checker clock and a level can otherwise fill the control FIFO.
- Result release must not be replaced by the old unordered clear pulse; the
  sequenced result is the ownership point for BOOM release.
- ARF mismatch detection must report the final compared entry without changing
  the legacy mismatch FIFO protocol.
- CSR shadow state must be initialized and must not be cleared merely by entering
  checker mode, otherwise CSR post-check never starts.

### Unrelated changes to restore to the baseline design

- Rocket `wb_wen` and scoreboard behavior, except for the required result and
  sequence plumbing. In particular, `Scoreboard.clearAll` must not be used as a
  normal combinational update when its enable is false.
- COPY acceptance/waiting logic that introduces a second start handshake and
  stalls the whole Rocket pipeline. The original one-cycle `arf_paste_reg` and
  `icsl_run` contract is sufficient once scoreboard state is not corrupted.
- R_IC scheduler availability gates that are not needed to carry a packet
  sequence and can prevent the original scheduler FSM from advancing.
- Extra control-path changes that reinterpret a level as a completion pulse.

## Deadlock checks

1. A checker result must remain valid while its CDC enqueue is not ready.
2. BOOM `ic_status` must clear only after that result is dequeued in BOOM's
   clock domain; an early local reset must not release the slot.
3. A failed/cancelled result is a terminal diagnostic state, not a reason to
   leave an allocated bitmap entry permanently pending without reporting it.
4. The package tail must not depend on a one-cycle empty pulse crossing CDC.
5. All checker harts use the same sequence slice `(hartId - NUM_BIG_CORES)`;
   no special case may be applied only to hart1.
6. Normal and privileged `R_ICSL` postchecking use the same latched
   `if_check_completed` predicate. A completion arriving before postchecking is
   retained, while a pulse arriving after reset is not inherited by a later
   package.

## Unified package tail

Normal COPY and privileged checking keep independent start paths, but use the
same terminal predicate:

```text
full_check_complete = package_check_active
                   && packet_ingress_drained
                   && lsl_empty
                   && arf_check_complete
                   && (!csr_check_required || csr_check_complete)
```

This single event determines PASS/FAIL and enqueues the sequenced result used by
the BOOM completion bitmap. Both `fsm_postchecking` states wait for the same
latched event before returning. `R_ICSL.clear_ic_status` is therefore local
cleanup/release ordering only; it does not define package completion.

The result queue preserves the complete result and package sequence until the
local cleanup is visible. GHM dequeues the result in the BOOM clock domain and
uses the same edge for `checker_results_out` and `clear_ic_status_tomain`, so
the bitmap update and BOOM ownership release refer to the same package.

## Source versus generated collateral

The checked-in source and the RTL used by the saved waveform are currently
different revisions.  In particular, the generated `gen-collateral/Rocket.sv`
still contains the intermediate `icsl_start_pending`/`icsl_start_valid` path,
clears the scoreboard when `icsl_start_accepted` is asserted, and masks
`wb_wen` with `!wb_dcache_miss`.  Those signals are absent from the current
`RocketCore.scala`; the current source uses the baseline one-cycle
`arf_paste_reg` path, baseline `wb_wen`, and only sets/clears the scoreboard at
the original load-response points.  Therefore the assertion and the 100-MiB
FST/VCD are evidence for the stale generated revision, not a validation of the
current source tree.

The same warning applies to the generated `BoomCore.sv`: its assertion line
number and signal names describe the old elaborated collateral.  No generated
RTL has been changed in this audit, per the request to avoid hardware
generation.  A future validation run must regenerate collateral before the
new packet-result and sequence wiring can be observed in a waveform.

## Static statistics risks

The result bitmap deliberately advances `safePacketWatermark` only across
PASS results.  FAIL/CANCELLED results are counted and invalidate the latency
window, but they do not advance the PASS watermark; subsequent packages then
remain pending by design.  Software must treat `stats_valid == 0` or a
non-zero `pending` count as an invalid measurement, rather than interpreting
the partial latency sum as a completed sample.  This is a measurement-policy
choice, not a BOOM checker-release deadlock: BOOM `ic_status` is released by
the result CDC dequeue independently of the statistics bitmap.
