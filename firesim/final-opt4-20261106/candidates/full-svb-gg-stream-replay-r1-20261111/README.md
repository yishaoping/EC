# Original SVB complete-port streaming replay (independent driver)

Functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`.
Component profile: `OriginalSVB32-component-trace`, source ID `b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f`.

This compiles a new host test class and links existing Golden Gate adapter/model objects. The target and host RTL, model object archive, existing synthetic372cycle driver and FPGA bitstream are unchanged. The hardware executable is independently linked with the existing platform object that refuses any BDF except `0000:21:00.0` before device setup. Building it does not access a board.

Binary replay preserves every reset, idle and backpressure target cycle. After a reset edge, it compares every defined output among the **62 original emitted SVB ports**, not all127 component observations. Promotion payload is compared only while valid; active-slot identity only during selected/promotion/ACK; blocking identity only while blocked. Undefined initial payload is neither zeroed nor claimed as a comparison. Three unobserved component inputs remain fixed to zero (`io_currentEpoch`, `io_resetStats`, `io_countStats`) as in the standalone reference replay; only omitted diagnostic counters/unused epoch depend on them.

Preparation tests run the genuine10k original full-system startup trace (zero real SVB traffic), then separately the labeled original synthetic directed372cycle trace, and require an expected valid promotion-payload mutation to fail. A full real application run is admitted only after the complete r5 full-system trace and its standalone original SVB replay pass; it must reject a mutation of a real application promotion payload too. Startup success cannot satisfy the real application gate.

`run.py --prepare` is submitted once to the existing persistent broker. No direct duplicate process. `dispatch.py` makes one finite check and atomically submits `run.py --full` only after valid prerequisites. The system timer installed by `install_timer.py` runs every300s independent of SSH and user lingering. PID/start_ticks/boot_id, logs and atomically replaced state live in `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106`; the per-run record snapshot is progress evidence, **not a simulator checkpoint**. A failed/interrupted run needs a fresh unique run directory and reset replay; passed receipts are never overwritten.

Outputs:

- `cycleprecise-original-svb-gg-stream-replay-r1-20261111/result.json`: CPU preparation.
- Same directory `full-result.json`: actual full application CPU GG replay/mutation result, once complete.
- Same directory `board-admission-ready.json`: conditional receipt only, not deployment. It requires exact certified bitstream/header ABI, existing21-only task/device locks and a safe task boundary. Parent owns deployment.
- `Opt4-original-svb-gg-stream-replay-r1-state.json` and `...-dispatch-state.json`: atomic state.

No driver here performs global XDMA, PCIe reset/rescan or FPGA deployment. All figures are component CPU GG simulation until a separate authenticated FPGA run receipt exists. MMIO replay host throughput is not autonomous SVB throughput; target-cycle event latencies remain separate from host wall time. No complete Opt4, checker completion or architectural rollback proof is claimed.
