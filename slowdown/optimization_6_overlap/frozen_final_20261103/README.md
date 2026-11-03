# Frozen final Opt4 BFS result — 2026-11-03

Hardware: **5343ea33f7ccc1b4d140eef09e2d07ab775ae72c**, local annotated tag
`opt4-final-bfs-20261103`, branch `opt4/perf-20261103`, private worktree
`/data1/gzh/EC-opt4-perf`. Documentation HEAD before this freeze is
`2012af65d249cf206a4fcd2d87b5fe399cf3d731`. Complete pre-freeze status is
`git_status.txt` (only the intentional tool symlink). Main/FPGA work is independent.
No further performance changes are authorized during cross-workload validation.

## Result and attribution

Pinned GAPBS BFS: 512 nodes, 8,192 edges, source 0, reached 512,
checksum **43439728**, verified=1. Shared ELF:
`/data1/gzh/EC/check/software_common_builds/gapbs512_20261023_03/test.riscv`,
SHA256 `da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c`;
loadmem SHA256 `f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad`.

| Stage | Commit | ROI cycles | / native 1,001,675 | Increment saved |
| --- | --- | ---: | ---: | ---: |
| Frozen Opt4 | 476a760910f3bfbd3c111000ebe40343870ab439 | 1,707,863 | 1.705007113 | — |
| A | 4250b35fea54eea0c321bf35bfc634ff38e74f2f | 1,426,845 | 1.424459031 | 281,018 |
| B | 40c8a18ca747cda97a8ced9a0aa10d73bd194244 | 1,174,774 | 1.172809544 | 252,071 |
| C/final | 5343ea33f7ccc1b4d140eef09e2d07ab775ae72c | 1,128,052 | 1.126165672 | 46,722 |

**281,018 + 252,071 + 46,722 = 579,811 cycles**, 33.9495% less than frozen.
Final ROI samples: 579,235 to 1,707,287; total harness count 1,732,174
(includes reset/startup/reporting; not the ROI). Excess over native falls by 82.1043%.
A combines direct checker/package delivery with SourceC waitAck overlap; B combines
accepted store terminal bypass, completion flow-through, fetch8 and prefix/CFI
fusion. Their component savings were not separately measured. SourceC overlap
occurs only 3/1/3 times in A/B/C: large SourceC-specific savings are unsupported.
C alone measures retaining acknowledged T-permission L1 copies, saving 46,722.
Local stall/phase counters are supporting activity evidence, not additive BOOM-cycle
attribution. The copied PERFORMANCE_REPORT, OPTIMIZATION_LOG, CANDIDATE_AUDIT and
CACHE_VERSION_STATE give exact changes, ownership/order invariants and decisions.
Exact A/B/C incremental source patches and seals remain committed in ../results/.

## Configuration and evidence

`chipyard.v1Config`: BOOM at 200 MHz, 4 Rocket checkers at 100 MHz; unchanged
scalar checker decode/retire, fetch 4→8 bytes. BOOM L1D 32 KiB, 256 sets × 2 ways,
64-byte blocks, 6 MSHRs; SVB16. L2 1 MiB, 1,024 sets × 16 ways, 1 bank.
Checker I$ 2 KiB/32 sets/1 way, D$ 4 KiB/32 sets/2 ways, both 64-byte blocks.
Generated configuration JSON and complete frequency summaries are preserved.
Verilator 5.048, assertions enabled, 1 simulator thread; host clang16.0.6,
-O3 plus generated -Os options. Full original build invocation is in exact_commands.json.

All source/binary/software/tool/resource identities are in binary_seal.json,
SIMULATION_STARTED.json and manifest.json. Measured binary SHA256:
`66ab0661ba28dc040cc2fb6dae6bf5f6be6d21ed4bf035a94861dff7c9110e6a`.
The original build recorded HEAD=A with dirty B+C. Every sealed hardware hash
has been checked against final C and current files; the recorded HEAD alone
must not be called the final implementation.

The complete final event stream is committed as safe_chain_events.tsv.gz;
its uncompressed hash is in manifest.json. summary.json includes full counters,
correctness, integrity, same-line ordering, ACK protocol, SVB occupancy and cache
traffic. checker_profile.json, preservation_profile.json, capture_summary.json,
cache_opportunity.jsonl and raw stdout/stderr preserve supporting measurements.
All original runs/builds, including unsuccessful attempts, are retained locally.

Final counters: 61,219 store effects, all terminal-enqueued on effect edge;
55,601 effect-edge deliveries; terminal enqueue=delivery=61,268; 39,364 forwarded
successor admissions; 6,588 terminal queued/blocked cycles; zero applied-S3 blocking.
SC51: 859 WB requests=TtoT=retained receipts, zero invalidating clears/mismatches/
probe revocations. SC48: reserved52,338, waitAck14,738, target lock67,076; three accepted releases
during waitAck. The target-set lock and ACK owner remain held until receipt.
The performance report and ../results/retained_copy/overlap_analysis.json preserve
all counters without relying on a partial transcription.

Correctness, integrity, ordering, protocol, capture and SC48–51 PASS; zero FAIL,
CANCELLED or assertion. 7,381 releases=ACKs, no conflicting/invalid/outstanding
source. SVB allocations373=completed368+coalesced3+discarded2. All128 mandatory
observer/producer identities close, optional loss538. Actual IBuf RTL both widths
PASS; actual WB RTL300 publications/100 probes while ACK pending PASS; 11 overlap,
7 retained-copy and 4 checker-profile CPU contracts PASS.

Known gaps: one workload/seed; L1/L2 shadow fidelity FAIL (exclude derived cache
geometry estimates); no top-level retention probe-revoke event in this benchmark;
no exhaustive injected rollback/exception/durable full recovery/drain proof;
CPU models are not RTL evidence; no synthesis timing or FPGA signoff.

## Reproduction

From the private worktree, check out the hardware tag in another private checkout
if needed. Never alter the concurrent main/FPGA tree. Restore the six ignored
BlackBoxes from restored_resources/ to the paths in restored_resources.json,
checking their hashes. Supply the existing read-only chipyard/.conda-env tool link
and private SBT caches/configuration (the old JGit requires linked-worktree private
gitdir config/worktree plus refs/object links; no main git config changes).
The runner verifies protected sources and software before building.

```sh
cd /data1/gzh/EC-opt4-perf
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --static-check
python3 -I -B slowdown/optimization_6_overlap/scripts/run_experiment.py --jobs 16 --label frozen_final_reproduction
# Runner prints a fresh RUN_DIRECTORY; use it below:
python3 -I -B slowdown/optimization_6_overlap/scripts/analyze_overlap.py RUN_DIRECTORY --output RESULT.json
python3 -I -B slowdown/optimization_6_overlap/scripts/verify_configuration.py BUILD_DIRECTORY/generated
```

This rebuilds in fresh private directories. To replay the already sealed simulator
without rebuilding, make a fresh output directory, chdir there, and run the exact
`simulation` argv in exact_commands.json through the existing compact_capture.capture
function. Enable both safe-chain events and cache-opportunity, use seed1 and the
pinned ELF/loadmem; never rerun inside the original evidence directory. The two
exact make commands and simulation argv are preserved in exact_commands.json.
