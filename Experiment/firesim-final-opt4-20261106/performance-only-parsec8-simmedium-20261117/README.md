# EC Performance-Only: eight PARSEC simmedium runs

This independent runtime suite uses certified 4915b82 BJL + four result CDC Mem on 0000:21:00.0 / 21770433G02LA only. Full PALIMPSEST functionality is not claimed.

One simmedium invocation per program, one thread and no warmup. Order: blackscholes, fluidanimate, bodytrack, swaptions, ferret, dedup, streamcluster, freqmine. The long-running freqmine runs last. No test/simsmall inputs are scheduled.

The suite reuses the existing application ELFs, official medium inputs, validated outputs, kernel/firmware, memory model and 2 GiB guest memory configuration. Twenty-four existing valid Native FPGA samples are exactly matched; slowdown uses each program's median Native ROI target cycles. Wall-clock host speed is reported separately. Fluidanimate and Ferret retain their explicitly documented existing repaired software profiles.

A fresh certified target-card deployment precedes every independent guest. All program output validation, positive checker accounting, installed/parked checker context, matching real package BEGIN/RESULT events with full comparison, drain, error checks and FASED readback gates remain enabled. Package logs are verified in a streaming pass to avoid loading large logs into RAM. Errors and timeouts are retained; no failed attempt becomes a performance sample. No periodic patrol or model service is installed.

The original 600-second boot limit proved too short: a first attempt reached 400,953,002 target cycles at 659,265 cycles/s, while the matching Native run reached ROI begin at 1,752,562,345 cycles. The corrected plan allows 3,600 seconds for boot, 12 hours per medium benchmark, and 48 hours for freqmine. The old orchestrator is changed only at a deployment boundary after its current child has naturally exited; no running FPGA simulator is signalled by that handoff. Attempts that expired before any application command are preserved in boot-limit600-attempts and are not counted as completed benchmark repetitions.

Live evidence: state.json, launcher.log, runs/<program>/uart.log, runs/<program>/host.log. Final and per-attempt outcomes: results.md, runs/<program>/result.json and attempt.json. Native bindings: plan.json. Credentials are never written to these files.
