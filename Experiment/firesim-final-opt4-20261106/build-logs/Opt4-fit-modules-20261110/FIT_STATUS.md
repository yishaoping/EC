# Opt4-fit module optimization status

2026-11-10T16:27:08.968801+00:00

Independent branch: `/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-20261110` / `opt4-fit/20261110`. Original frozen hardware remains unchanged. Full Opt4-fit capacity/timing: **NOT YET ESTABLISHED**.

Original DUT after opt_design: 5,741,353 LUT (440.40%), 366,817 CARRY8 (225.10%), 9,024 DSP (100%). Remaining excess over U280: 4,437,673 LUT and 203,857 CARRY8. This is not an estimate of candidate size.

| Module / variant | LUT | CARRY8 | DSP | FF |
|---|---:|---:|---:|---:|
| baseline-address | 1,702,895 | 58,190 | 0 | 391,057 |
| baseline-barrier | 170,241 | 8,173 | 4,096 | 41,601 |
| baseline-scanner | 222,585 | 1,536 | 0 | 0 |
| fit-address | 1,500,571 | 57,446 | 0 | 390,171 |
| fit-barrier | 83,179 | 2,955 | 16 | 41,601 |
| fit-scanner | 8,810 | 1,620 | 0 | 0 |
| round2-barrier | 83,794 | 2,955 | 16 | 41,601 |
| round2-scanner | 8,110 | 515 | 0 | 0 |

Only completed actual maps appear above. Matched OOC results use the same tool, part and directive. Isolated modules have different DSP availability from the full design; no extrapolated full-design fit is claimed.

Changes implemented in independent commits:

- Exact distributive factor of barrier/L2 current-cycle multiplication; no state/event/width removal.
- Address statistics: reuse exact 65-bit sum for state update and overflow carry; share single-selected-bucket Store/FirstStore arithmetic; exact bounded balanced population-count sums. All 256 slots, queue/table capacity, 64-bit state, errors and drain contract preserved.
- BOOM prefix scanner: replace 256 dynamic reads from a 256-entry full-sequence table with one fixed-slot comparison each. The second candidate shares the high-half increment and uses two priority encoders and one subtraction. No PASS/recovery/watermark semantics change.
- Second candidate balances latency reductions using exact growing widths and preserves the original 73-bit results and every overflow consumer.

Verification:

- Original/fit selected modules: `ELABORATED_MODULES_ONLY`; maps: `MODULE_MAPS_COMPLETE`.
- Arithmetic/sequential verification: `FAILED_WITH_EVIDENCE`, active step `address-compile`; all raw failures retained.
- Scanner: `MODULE_VALIDATED_AND_MAPPED`, step `compare`; proof `{'full_design_proof': False, 'index_identity': 'SAT universal 40 input bits PASS', 'permutation_argument': 'For each watermark, offsets 1..256 bijectively cover physical slots; first failing offset equals minimum failing slot distance, or 257 when all pass, minus 1', 'rtl_vectors': 4096}`.
- Second candidate: `MODULES_VALIDATED_AND_MAPPED`, step `barrier-compare`, pinned commit `8da24a269b98a0d6a8f57b030353a310812c4344`.

Whole-DUT synthesis is tracked separately below. Runtime admission requires real whole-system capacity, timing and bitstream certification. Formal pairing must bind the new profile/source ID, identical Native software/input/threads/ROI, common BOOM/cache/memory/target-clock parameters. Never label derived results as the frozen 8491167 bitstream.

Recovery states under Experiment root: `Opt4-fit-modules-state.json`, `Opt4-fit-mapping-state.json`, `Opt4-fit-verification-state.json`, `Opt4-fit-scanner-state.json`, `Opt4-fit-round2-state.json`. All are independently service-managed; reconnect audits PID/start_ticks/boot_id and monitors live workers, never duplicates them.

Universal cyclic priority SAT: `PASS_UNIVERSAL_264_INPUT_BITS`; 264 input bits. Evidence: `Opt4-fit-priority-proof-state.json`. This proves the local combinational identity, not full-design equivalence.

Full-size address verification after original Icarus compile timeout: `PASS_FULL_SIZE_6144_CYCLE_COMPARISON_NOT_FORMAL`, tool `Verilator 5.028 2024-08-21 rev v5.028`. Original timeout evidence remains in `Opt4-fit-verification-state.json`; only the failed address stage is retried, using unchanged RTL/testbench.
All five modified sources compiled together: `PASS_FIVE_MODIFIED_SOURCES_COMPILE_ONLY`.

Whole-system RTL: **GOLDENGATE_COMPLETE_NOT_SYNTHESIZED**, commit `8da24a269b98a0d6a8f57b030353a310812c4344`, source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`. Exact configuration equality: `True`; private class origins: `True`.
Whole-system CAD: **RUNNING_DUT_SYNTH** / `dut_synth`; controller PID `2790677`, worker PID `2790743`. Service `ec-parsec-opt4-fit-cad.service`. Reuse only 11 unchanged shell IPs; synthesize derived DUT afresh, then top synthesis, link/black-box checks, opt_design and saved physical capacity report. Stop NOT FIT before placement. FIT proceeds automatically to place/route, setup/hold and bitstream gates. No FPGA access or frozen-profile admission.

DUT synthesized: Actual resource report not produced yet; no extrapolation from modules.

Complete top optimized: Actual resource report not produced yet; no extrapolation from modules.

Original frozen CAD VHDL export intentionally retired after independently optimized DUT NOT FIT; checkpoints and logs retained in `frozen-cad-retirement.json`. Independent frozen full-top opt_design diagnostic remains separate. Native 21-only jobs unchanged.

Independent address round 3: **VERIFIED_AND_MAPPED_MODULE_ONLY** / `full-address-map`; commit `aca893e0aa3f7e23e16067ab40713afea41558e8`, source ID `d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28`. Separate worktree `Opt4-fit-address-round3-20261110`; current 8da24a26 whole-DUT build is unchanged. Hit-count bounds [8,3,2,1] follow from original 1/2/4/8-byte accesses; exact growing subtree widths retain full 64-bit state and outputs, original error/drain/event timing. Proofs and 52-output full-size regression are local validation, not full-DUT equivalence or runtime admission.
- full_address: `PASS_FULL_SIZE_6144_CYCLES_52_OUTPUTS_NOT_FULL_FORMAL`.
- increment-prefix: `PASS_UNIVERSAL_74_INPUT_BITS`.
- increment-split: `PASS_UNIVERSAL_74_INPUT_BITS`.
- increment-wide: `PASS_UNIVERSAL_74_INPUT_BITS`.
- touch_bounds: `PASS_UNIVERSAL_96_INPUT_BITS`.
- tree8: `PASS_UNIVERSAL_BOUNDED_INPUTS`.
- tree80: `PASS_UNIVERSAL_BOUNDED_INPUTS`.

| Address probe | LUT | CARRY8 | DSP |
|---|---:|---:|---:|
| increment-prefix | 2,016 | 32 | 0 |
| increment-split | 368 | 144 | 0 |
| increment-wide | 160 | 144 | 0 |
| tree-after | 957 | 2 | 0 |
| tree-before | 1,843 | 6 | 0 |

Probe maps isolate combinational kernels. They are not measurements of the full address module or full DUT. Specialized update probes have not been installed in production source.

Additional address arithmetic probes: **PROBES_MAPPED_NOT_INSTALLED**. No production hardware changes.
- dsp-module: `PASS_UNIVERSAL_74_INPUT_BITS`.
- dsp-wire: `PASS_UNIVERSAL_74_INPUT_BITS`.
- heap8: `PASS_BOUNDED_UNIVERSAL`.
- heap80: `UNPROVEN_TIMEOUT_NOT_ADMITTED`.
- wide: `PASS_UNIVERSAL_74_INPUT_BITS`.
- dsp-module: Block RAM Tile 0, CARRY8 144, CLB LUTs 160, CLB Registers 0, DSPs 0 (micro probe only).
- dsp-wire: Block RAM Tile 0, CARRY8 144, CLB LUTs 160, CLB Registers 0, DSPs 0 (micro probe only).
- wide: Block RAM Tile 0, CARRY8 144, CLB LUTs 160, CLB Registers 0, DSPs 0 (micro probe only).

Derived software preparation: **13_PROGRAMS_SOFTWARE_PREPARED_NOT_RUNTIME_ADMITTED**; 13 programs with exact Native references. Derived automatic certification/21-only boundary handoff service: **WAITING_FOR_DERIVED_BITSTREAM**. Service ec-parsec-opt4-fit-runtime; no deployment before real capacity/timing/DRC certification; Native live sample is preserved. Frozen C4 IDs are never reused for derived artifacts.

Independent parsed bit-heap compositional arithmetic proof/micro map: **COMPOSITIONALLY_PROVED_MICRO_MAP_COMPLETE_NOT_INSTALLED**. Prior monolithic SAT timeout is retained. Local exhaustive compressor identities plus parsed weighted conservation and explicit proven leaf bounds; not full module/DUT equivalence. Resources: {'Block RAM Tile': 0.0, 'CARRY8': 0.0, 'CLB LUTs': 840.0, 'CLB Registers': 0.0, 'DSPs': 0.0}.

Independent Chisel heap candidate: **RUNNING_FULL-MODULE-MAP**, commit `c41d42f61aa79d8249125c9e911438b797d007ce`, source ID `6fcb790b0d19e832582166c1940f485a00940f95437b38d297d9533f446721d2`. Compile/elaboration and frozen full-module sequential comparison must pass before full-module mapping; no automatic whole-DUT promotion. Failure evidence is retained by revision.

Independent shared-scatter candidate: **RUNNING_MAP-FULL-ADDRESS**, commit `11edd71981aa30ff3a26aab1f2f7327ac0266ee1`. Local generated-RTL proofs, real-size oracle, frozen module cycle comparison, then measured standalone map. No full-DUT promotion. Native scheduling user pause: **PAUSED_BY_USER**; latest authoritative build/recovery notes supersede historical Native scheduling text.
