# Opt3 checker frontend experiment

This directory preserves the validated Opt3 hardware source identity and the
user-run build/capture/analysis entry. The detailed design is
[`AI/Design/opt3_checker_frontend_optimization_20261028.md`](../../AI/Design/opt3_checker_frontend_optimization_20261028.md).

The measured GAPBS512 ROI is 2,928,347 main cycles, compared with Opt2b's
3,760,243: a reduction of 831,896 (22.123464%). The hardware identity remains
`dece4a35a99eb0c2ed30fb917a9f8946e9d8d53a48d7f99c36e51f15a15e1fae`.
The small measurement record is in `manifests/measured_result.json`. Original
run directories are local evidence and are never replaced by this record.

## Static verification

```bash
bash slowdown/run_optimization_3_checker.sh --static-check
python3 -I -B slowdown/optimization_3_checker/scripts/offline_contract_tests.py
python3 -I -B slowdown/optimization_3_checker/scripts/offline_release_tests.py
```

These commands do not load SBT, generate hardware, compile or simulate.
The launcher recreates missing empty runtime directories after checkout.

## User-only repetition

The default command refuses a second simulation after an attempt. An explicit
repetition of the latest successful, complete run is available:

```bash
bash slowdown/run_optimization_3_checker.sh \
  --repeat-from optimization_3_checker_20261028_090640_a56794e2
```

Add `--static-check` to validate that reference without starting a build.
Repetition creates fresh run/build/temp directories, preserves all old guards
and evidence, checks the same source/workload, and never retries a failed or
incomplete latest attempt. It does not authorize changed hardware source.

## Artifact and validation boundaries

`build/`, `runs/`, `tmp/`, `cache/`, lock files and bytecode stay local.
No full ROI FST/VCD is generated. Event capture is capped at 48 MiB plus
2 MiB each for stdout/stderr. The same pinned Baseline software is referenced
in place; external toolchain/dependency caches remain host prerequisites.

315 PASS results, 71 complete observers and Stage1 L1/LSU exit drain passed in
the measured run. Full package/cache/DRAM durable drain and RUN_PROVENANCE
remain unresolved; FAIL/probe recovery was not exercised.

The standalone analyzer writes a fresh output directory and now explicitly
compares Opt3 against Opt2b. Old run summaries retain their historical field
names and are not overwritten.
Historical comparison inputs are small versioned reference snapshots; the
safe-chain snapshot retains the original summary path and SHA256 and does not
require that old run directory to be present.
