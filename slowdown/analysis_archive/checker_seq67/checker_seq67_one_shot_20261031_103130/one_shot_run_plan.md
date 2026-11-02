# One user-run B only

NUMBER_OF_FULL_RUNS_REQUESTED = 1
RUN_TARGET = B_ONLY_64K_2WAY
A_NON_INTERFERENCE_PROVEN = NO

From `/data1/gzh/EC`, execute exactly:

```bash
bash AI/Debug/scripts/run_checker_seq67_one_shot.sh --report AI/TMP/checker_seq67_one_shot_20261031_103130 --jobs 4
```

The real wrapper sources chipyard/env.sh, verifies the new immutable `sealed/` fingerprint,
checks saved A/proof hashes and offline validation, creates an exclusive B_LAUNCH_CLAIM,
and invokes the existing Opt4 launcher in B-only causal mode. The source seal rejects armA.
It performs required Scala/Chisel elaboration, RTL generation and Verilator build, then
one benchmark invocation with pinned ELF/loadmem/seed1/maxcycles500000000/threads1 and
the same actual runtime arguments as old A. Failed builds/simulations never auto-retry.
An existing claim prevents accidental duplicate use. `--analyze-only` is offline-only.

## Build reuse

Scala RTL changed, so old generated Rocket RTL and the old B executable cannot be reused
as the corrected design. Existing causal launcher uses a fresh isolated build, preserving
old r2 collateral. It invokes make verilog/default without clean/all-clean. Software,
loadmem, compiler/toolchain artifacts, cached dependencies and normal incremental Scala
compilation are reused. The old causal fresh-run mode has no safe cross-fingerprint C++
resume path; no false promise of reusing stale Verilator objects is made. No clean command
or forced global dependency rebuild was added.

## Files available after this command

- `sealed/arms/B/runs/<id>/run_manifest.json`: actual source/software/phase/argv/exit.
- Same run `analysis/summary.json`: checker/benchmark verified1/checksum43439728,
  protocol, integrity, ordering, STOP40–45, observer gates.
- Same run `analysis/seq67_diagnostics.json`: lifecycle, trap/deferral events,
  full result/clean handoff and BOOM accepted PASS. Missing/capped evidence rejects PASS.
- Same run `roi.json`, `cache_opportunity.jsonl`: complete software ROI/native counters,
  real L1 misses, ROB-head wait, nack retry, MSHR busy/full, RPQ replay, scheduler overlap,
  and latency cohorts; L2 snapshot/key/S0 validity.
- Report `runtime_provenance.json`, `runtime_validation.json`, `one_shot_result.json`,
  `runtime_result.md`: combined verdict. No overwrite of pre-run validation_result.json.
- If all B gates PASS: `reference_comparison.json` contains old-A/new-B differences,
  explicitly unpaired because current noninterference proof isNO.

## Decision after this B

If B fails or lacks complete ROI/observer/diagnostics, stay inconclusive, preserve all
artifacts, and do not automatically launch another run. If all B gates PASS, close
correctness and mark `CORRECTNESS_CLOSED_BUT_STRICT_PAIRING_REQUIRES_BASELINE_REFRESH`.
An apparent large gain can motivate discussing one later A; it is not yet a geometry-only
causal performance conclusion. No such A is arranged now. Keep SVB16 and MSHR6; no other
geometry/promotion/scheduler/replay/L2 experiment is part of this command.

## Agent execution boundary

This turn ran only source/log/old-generated-RTL inspection, offline Python/native CPU
unit tests, hashes, shell syntax and `scala.tools.nsc.Main -Ystop-after:typer`.
It did **not** execute elaboration, RTL generation, Verilator build or a benchmark.
Those phases remain exclusively for this user-run command.

## Build-failure recovery revision

The parent seal 1fc6abc9 failed RTL_GENERATION before Verilator or simulation. Its claim/build/logs are preserved. This new report has a new immutable seal and a fresh B-only claim; it does not request an additional benchmark beyond the original one B. No clean is added.
