# Frozen C4 U280 capacity evidence

Observed UTC: 2026-11-10T16:27:08.916769+00:00

Frozen commit: `8491167d84b6d9521b151a743673c1516926a1f8`; DCP SHA256 `0dbdabf283669fd45d4389742fa9c05fa0163d01496e86e558c77d2bb3be86ae`.

**Current mapped DUT: NOT FIT.** CLB LUTs 5938927.0 / 1303680.0 (455.55098%). This is a real flat physical utilization report; independent recursive EDIF instance census passed duplicate-definition checks.

**Complete top after optimization: NOT_FIT_POSTOPT.** DUT-only optimization cannot establish what top integration removes. Capacity fit would still require routing, setup/hold, DRC, bitstream certification, and FPGA validation.

Independent DUT audit: COMPLETE; latest marker: EC_CAPACITY_POSTOPT_REPORTS_COMPLETE. DCP build: FAILED_WITH_EVIDENCE / implementation.

DUT after opt_design: **NOT_FIT**. This scope is distinct from complete-top integration. The independent Opt4-fit branch is `/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-20261110`, with module preparation/mapping/verification states under the Experiment root. It preserves frozen RTL and records a new hardware identity; no full DUT rebuild or admission occurs before capacity verification.

| Scope | LUTs | CARRY8 | DSP |
|---|---:|---:|---:|
| mapped_dut | 5,938,927/1,303,680 | 424,714/162,960 | 9,024/9,024 |
| reopened_dut_preopt | 5,938,927/1,303,680 | 424,714/162,960 | 9,024/9,024 |
| optimized_dut | 5,741,353/1,303,680 | 366,817/162,960 | 9,024/9,024 |
| optimized_complete_top | 5,825,558/1,303,680 | 367,889/162,960 | 9,027/9,024 |

Physical LUT hierarchy before optimization (reported subtree rows; do not add ancestors):

| Scope | Physical LUTs | FF | DSP |
|---|---:|---:|---:|
| tile_reset_domain_boom_tile (BoomTile) | 3,687,855 | 927,794 | 4,100 |
| l2 (InclusiveCache) | 925,534 | 90,677 | 4,924 |
| (design_1_firesim_wrapper_0_0) ((top)) | 873,070 | 0 | 0 |
| tile_reset_domain_tile (RocketTile_2) | 76,169 | 70,516 | 0 |
| tile_reset_domain_tile (RocketTile) | 76,162 | 70,517 | 0 |
| tile_reset_domain_tile (RocketTile_1) | 76,162 | 70,513 | 0 |
| tile_reset_domain_tile (RocketTile_3) | 76,161 | 70,516 | 0 |

These report rows total 361 LUTs above the flat count; cross-hierarchy LUT combining means the authoritative device count is the flat report. Four Rocket checker tile subtrees total only 304,654 LUTs; reducing checker count alone cannot resolve the present excess. Top-direct combinational cells include logic moved across hierarchy and cannot be assigned to a source function from their module name.

Largest direct module populations (raw primitive counts, **not physical packed LUTs**):

| Module | LUT primitives | LUT6 | CARRY8 | DSP | FF |
|---|---:|---:|---:|---:|---:|
| PackageAddressStats | 1,664,889 | 757,492 | 58,194 | 0 | 390,791 |
| design_1_firesim_wrapper_0_0 | 1,413,744 | 15,053 | 145,365 | 0 | 0 |
| GHBarrierLatencyStats_2025 | 576,225 | 287,713 | 51,852 | 2,048 | 41,601 |
| GHBarrierLatencyStats | 474,373 | 206,114 | 35,173 | 2,048 | 41,601 |
| CSRFile | 473,178 | 208,289 | 39,502 | 0 | 2,984 |
| GHBarrierLatencyStats_1713 | 445,774 | 195,725 | 36,270 | 2,048 | 41,601 |
| InclusiveCache | 325,146 | 160,989 | 30,345 | 2,876 | 42,159 |
| AsyncResetSynchronizerPrimitiveShiftReg_d3_i0_2052 | 209,354 | 5,148 | 6,467 | 0 | 12 |
| SpeculativeVersionBuffer | 177,510 | 43,181 | 11,299 | 0 | 20,710 |
| BoomMSHR | 137,297 | 90,234 | 32 | 0 | 820 |
| BoomProbeUnit | 111,918 | 46,022 | 18 | 0 | 61 |
| R_IC | 93,378 | 48,649 | 1,110 | 0 | 998 |

Source findings and independent candidate:

- Three GHBarrierLatencyStats instances and the L2 writeback reduction instantiate 1,024 per-bucket 64x64 multiplies. They calculate the same current-cycle factor repeatedly.
- Independent candidate factors sum(cycle * count) into cycle * sum(count), retaining the 137-bit result, reset, state, overflow consumers and all events. Four 64x73 multiplies replace 1,024 operators. This is a candidate only, outside live/frozen sources.
- Arithmetic distributivity and exact unsigned bounds checked; 2,120 boundary/random arithmetic vectors passed. Generated-leaf sequential comparison passed 2,048 cycles. These are not full-design equivalence proof.
- Real candidate-leaf mapping: 83,179 physical LUTs; 41,601 FF; 2,955 CARRY8; 16 DSP, versus 2,048 DSP in the original instance. Original raw LUTs cannot be directly compared to candidate physical LUTs. Full design capacity/timing remains unverified.
- PackageAddressStats alone contains 1,664,889 raw LUT primitives and 390,791 FF. Its packet bucket updates/deltas and associative tracking require further exact restructuring; the set tables already use SyncReadMem. Reducing queue/window/table sizes or disabling observation is not an approved equivalent solution.
- dcache STOP snapshot waits for addressStats.idle and barrier pending==0. Deleting statistics changes the measurement/drain contract; it is not a safe shortcut.
- Prefer no-RTL netlist optimization first. If it remains over capacity, the prepared arithmetic candidate is the smallest tested source-level option, but may be insufficient. It requires an explicitly approved derived profile and full validation before formal use.
- A failed early DCP gate was diagnosed separately: Vivado creates dbg_hub_CV as an IS_DEBUG_CORE placeholder, implemented by the original place-stage implement_debug_core command. The confirmed-dead failed DCP controller was resumed with a precise placeholder rule and a later all-zero black-box gate. Failed logs are preserved. No live original CAD or Native was interrupted.
- Full-top opt_design now writes utilization/DRC and keeps its checkpoint before placement. An actual excess blocks place/route automatically, without admitting any bitstream or changing frozen RTL.

Evidence:

- mapped_dut: [dut-utilization.rpt](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-dcp-20261110T071734Z/dut-utilization.rpt) (present).
- reopened_dut_preopt: [vivado-preopt.rpt](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-preopt.rpt) (present).
- optimized_dut: [vivado-postopt.rpt](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-postopt.rpt) (present).
- optimized_complete_top: [utilization.rpt](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/top-postopt/utilization.rpt) (present).
- [edif-capacity-census.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/edif-capacity-census.json).
- [edif-name-attribution.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/edif-name-attribution.json).
- [candidate.json](/data1/gzh/EC/firesim/final-opt4-20261106/candidates/capacity-exact-factor-20261110/candidate.json).
