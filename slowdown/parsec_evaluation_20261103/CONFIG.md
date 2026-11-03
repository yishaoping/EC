# Frozen configuration

Canonical corrected hardware is `1532923803d7451b0c7843e9abad1c90ef9eb9ed`,
tag `opt4-final-corrected-20261103`. The last hardware change is snapshot ownership
repair `83dec9d4c10ab8c097fe5ab5c8af1c0a270fba6d`. Evaluation documentation commits
descend from this revision; they do not revise hardware. The old BFS-only tag is
historical. `reproducibility_manifest.json` contains ancestry, exact source hashes,
configuration, build references and a clean source checkpoint. Every new primary
run must start from a clean evaluation worktree; the launcher enforces this.

| Parameter | Setting |
|---|---|
| Application hart | BOOM hart 0, fetch 8 / decode and retire 3 |
| ROB / integer PRF / FP PRF | 42 / 128 / 128 |
| Issue queues MEM / INT / FP | 16 / 32 / 24 entries; issue widths 1 / 3 / 1 |
| LQ / SQ / FTQ / fetch buffer | 16 / 16 / 32 / 24 |
| Checkers | Rocket harts 1–4, decode/retire 1 |
| BOOM L1I | 32 KiB, 64 sets × 8 ways, fetch 16 bytes |
| BOOM L1D | 32 KiB, 256 sets × 2 ways, 6 MSHRs |
| Checker L1I / L1D | 2 KiB (32×1) / 4 KiB (32×2) |
| L2 | 1 MiB, 1024 sets × 16 ways, outer latency 12 cycles |
| Coherence block / SVB | 64 bytes / 16 entries |
| Per-checker data / ARF CDC | 256 / 8 entries |
| Per-checker l2b / b2l / session / result CDC | 64 / 64 / 4 / 256 entries |
| CDC synchronizer | 2 stages |
| Segment limit | 5000 instructions |
| BOOM / checker clocks | 200 MHz / 100 MHz each |
| System / memory / GC bus | 200 / 200 / 100 MHz |
| Target compiler | GCC 12.2.0, `-O2`, `rv64imafd`, `lp64d`, no fast-math |
| Simulator | Verilator 5.048, Clang 16.0.6; assertions enabled |
| Simulation | One model thread, seed 1, DRAMSim2, no waveform, no verbose |

The detection model uses historical detection commit
`b3d7adddd1e2d2cf428dd933529de878226420cd` plus the previously sealed configuration
patch. It matches the BOOM, cache and clock configuration. Checker fetch bytes are
4 for detection and 8 for correction, an intentional final-design difference.
No detection datapath or protocol changes were made for evaluation. The Verilator
and compiler audit and DRAMSim member equivalence are preserved in
`../blackscholes_validation/evidence/`.

## Native execution mode

Native uses the corrected model with the protected session disabled in software.
The checker cores remain present and execute their existing idle/wait firmware;
this is a native **execution mode**, not an area/power comparison against a
physically checker-free chip. The mode must generate zero protected packages and
zero SVB allocations, with complete mandatory capture. No separate unprotected
RTL build has been established. Any ratio using this baseline must retain this
scope label.

The two ELF files differ only in the initialized 64-bit `eval_protected` word
(1 vs 0). Their entire executable code, addresses, input and all iteration bounds
are identical. Detection and correction use the exact same protected ELF.
The input and kernel are initialized before the ROI. The established firmware,
interrupt handlers, timer policy and finite HTIF exit are reused unchanged.

## Measurement windows

Application ROI surrounds only `workload_run()`, with adjacent `rdcycle` and
`rdinstret` samples at the two labeled boundaries. The sampling instructions add
the same fixed boundary work in every mode. STOP/session readiness, result drain,
output verification and HTIF termination are outside this ROI.

Software session completion is not proof of hardware result completion. Correction
drain is measured from the BOOM-domain accepted-result ledger, using the last
accepted result from packages allocated before the application endpoint. Full
session package coverage is validated independently; a package can include boundary
or STOP instructions. Detection lacks the equivalent sequenced accepted-result
ledger, so its fully verified completion may be N/A. A completion ratio is not
computed from mismatched definitions.

Existing traffic/cache counters cover their hardware observation window, which
starts during setup and ends after checker software completion. Their cycle count
is recorded separately from application ROI cycles. Checker profile partitions
use only fully captured packages entirely inside the application ROI; missing
optional samples are excluded, never zero-filled. Counter categories overlap across
domains and must not be summed into a causal BOOM-cycle attribution.

Host seconds measure simulation cost. Concurrent host load and observation volume
can affect these seconds; they cannot change the architectural slowdown definition.

Cache shadow geometry predictions failed the prior fidelity check. Physical event
and conservation counters may be used after their validators pass; shadow capacity
predictions are excluded from bottleneck claims.
