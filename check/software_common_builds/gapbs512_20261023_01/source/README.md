# Common performance software

One source tree and one future ELF/loadmem for both b3 baseline and Current.
Prepared on 2026-10-23; NOT COMPILED OR RUN.

The workload is the original AMO.W self-check followed by GAPBS BFS512.
Algorithm, graph input, interrupt handler, per-hart 64-byte timer slots,
checker configuration and required replay/completion controls are retained.
Legacy 0x7B readback/snapshots, 0x55 report counts and 0x79 interval requests
are removed. Shared observer initialization remains; hart-0 observer
START/STOP controls are outside the software ROI and never define PASS.

The primary metric is hart-0 `common_roi_stop - common_roi_start`, including
AMO, BFS, checking STOP and session completion. Final PCs come from the new
ELF, not the old candidate's 0x80000368/0x800003d4.

`layout_contract.json` and `support/htif.ld` pin mutable workload addresses,
timer/AMO alignment, completion storage, HTIF and heap/stack boundaries.
The future builder rejects a changed layout rather than silently moving it.
Report traffic removal may change the old run's total request trace; this
is a new shared measurement profile, not an adjustment to old cycle data.

Manual future build, with a new output directory:

```bash
bash /data1/gzh/EC/baseline/build_common_benchmark.sh \
  --output /data1/gzh/EC/baseline/software_common_builds/paired_bfs512_01
```

That script builds software only, creates one descriptor with real hashes,
and never invokes a simulator. It has not been executed during preparation.
Only use its `workload.json` after reviewing generated layout/disassembly.
No R-Kernel is needed for this static libgloss/HTIF runtime.

Detailed ABI, correctness limits, source evidence and future run instructions:
`../manifests/common_benchmark_20261023_fa82d07b/`.
RUN_PROVENANCE remains UNRESOLVED.
