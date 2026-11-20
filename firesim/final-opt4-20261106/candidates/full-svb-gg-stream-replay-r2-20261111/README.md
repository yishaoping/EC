# Original SVB complete-port streaming replay (independent driver)

Functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`.
Component profile: `OriginalSVB32-component-trace`, source ID `b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f`.

This compiles a new host test class and links existing Golden Gate adapter/model objects. The target and host RTL, model object archive, existing synthetic372cycle driver and FPGA bitstream are unchanged. The hardware executable is independently linked with the existing platform object that refuses any BDF except `0000:21:00.0` before device setup. Building it does not access a board.

Binary replay preserves every reset, idle and backpressure target cycle. After a reset edge, it compares every defined output among the **62 original emitted SVB ports**, not all127 component observations. Promotion payload is compared only while valid; active-slot identity only during selected/promotion/ACK; blocking identity only while blocked. Undefined initial payload is neither zeroed nor claimed as a comparison. Three unobserved component inputs remain fixed to zero (`io_currentEpoch`, `io_resetStats`, `io_countStats`) as in the standalone reference replay; only omitted diagnostic counters/unused epoch depend on them.

Preparation tests run the genuine10k original full-system startup trace (zero real SVB traffic), then separately the labeled original synthetic directed372cycle trace, and require an expected valid promotion-payload mutation to fail. A full real application run is admitted only after the complete r5 full-system trace and its standalone original SVB replay pass; it must reject a mutation of a real application promotion payload too. Startup success cannot satisfy the real application gate.

`run.py --prepare` is submitted once to the existing persistent broker. No direct duplicate process. `dispatch.py` makes one finite check and atomically submits `run.py --full` only after valid prerequisites. The system timer installed by `install_timer.py` runs every300s independent of SSH and user lingering. PID/start_ticks/boot_id, logs and atomically replaced state live in `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106`; the per-run record snapshot is progress evidence, **not a simulator checkpoint**. A failed/interrupted run needs a fresh unique run directory and reset replay; passed receipts are never overwritten.

Outputs:

- `cycleprecise-original-svb-gg-stream-replay-r2-20261111/result.json`: CPU preparation.
- Same directory `full-result.json`: actual full application CPU GG replay/mutation result, once complete.
- Same directory `board-admission-ready.json`: conditional receipt only, not deployment. It requires exact certified bitstream/header ABI, existing21-only task/device locks and a safe task boundary. Parent owns deployment.
- `Opt4-original-svb-gg-stream-replay-r2-state.json` and `...-dispatch-state.json`: atomic state.

No driver here performs global XDMA, PCIe reset/rescan or FPGA deployment. All figures are component CPU GG simulation until a separate authenticated FPGA run receipt exists. MMIO replay host throughput is not autonomous SVB throughput; target-cycle event latencies remain separate from host wall time. No complete Opt4, checker completion or architectural rollback proof is claimed.

## r2 recovery and throughput evidence

r1 was rejected before any target record because its strict header comparison copied13 of the14 magic bytes. r2 checks all14 bytes plus2NUL bytes. r1 receipts remain preserved. r2 caches input vectors: unchanged values need no MMIO rewrite, but every input held by the bridge is exactly the current recorded input by induction (all inputs written on firstrecord), and every target cycle plus defined output check remains present. No idle interval or effective computation is skipped. Preparation runs both cached and force-all modes on the same real10k startup binary and compares counts, followed by the original separate372cycle positive and valid-payload mutation negative.

The future fullCPU deadline is calculated from actual startup(forceall/cached) and directed seconds/record, takes the worst measured value, multiplies by actual fullrecordcount and safetyfactor3, then adds600seconds. It refuses automatic admission if this exceeds24hours. `measured-full-budget.json` records the calculation. The host timeout covers this bounded experiment; it never kills other jobs. Progress snapshots every4096targetrecords do not imply architectural checkpoints.

The full application positive replays every record and compares every defined original emitted output. The negative is a separate run from reset that changes only the expected payload at the first real valid promotion and must return nonzero with `SVB_GG_STREAM_MISMATCH ... port=io_promote_bits_data_0`. A board receipt requires the full positive targetrecordcount, eventcounts, exit0 and `SVB_GG_STREAM_SUMMARY ... mismatches=0 ...` plus `[SVBProbe]PASS Test`. The cached MMIO hostseconds/targetcycles metric describes this external trace replay; it is not autonomous SVB throughput or fullapplication slowdown.
