# Corrected resource analysis of real storage-entry area r2

This independent read-only parser corrects the live area controller's `CLB LUTs*` label bug. The old regex skipped the starred total and matched the SLR0 number instead, giving an invalid zero. No controller, CAD input, raw report, checkpoint or old result is overwritten.

Run once:

    python3 analyze.py

Persistent follow-up (system service, no new Vivado process):

    python3 analyze.py --watch

The watcher checks only every 300 seconds. It waits for completed zero-exit stage receipts, verifies original output hashes, and reads existing reports. It never runs synthesis, kills a process or accesses a card.

Parser rules:

- Read the rendered `1. CLB Logic`, `2. BLOCKRAM` and `3. ARITHMETIC` total sections with `Used` and `Available` columns; strip a trailing `*` from the resource label.
- Require the known U280 capacities and `FPGATop`/synthesized/device identity.
- Match LUT, register, BRAM, URAM and DSP totals to the unique hierarchical top row. Match CARRY8 to the primitives table; require zero black boxes.
- In MCConfig require a nonzero retained `RamModel` hierarchy with mapped RAMB primitives.
- Exercise the actual starred label, unstarred label, wrong capacity, duplicate total, missing total while an SLR row remains, changed SLR values, hierarchy disagreement and primitive disagreement. Invalid evidence must fail closed.

Output directory:

`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-area-analysis-r1-20261111/`

`partial-result.json` contains verified configurations only. `result.json` and `complete.json` are published atomically only when both completed configurations have valid receipts and pass crosschecks. The original buggy state is separately preserved as `original-buggy-state.json`; it is not an area authority.

Scope: the full isolated 512x81/35R1W owner-image host-entry harness, including reset/written-mask, observation captures and PeekPoke; this is not complete DCache, whole Opt4, physical FIT, timing or FPGA measurement.
