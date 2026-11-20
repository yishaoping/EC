Performance-Only routability recovery — observed 2026-11-14T10:13:46.690809+08:00

Original `6fada307` post-opt: 1,023,687 / 1,303,680 LUT. Capacity FIT only. Original final route is illegal: 741,299 / 1,790,138 fully routed (41.4102%), 1,048,839 conflicting nets, 2,702,263 overlapping nodes. WNS −19.489 ns, TNS −5,276,071.500 ns. No bitstream.

Measured hotspots from the reused checkpoint (overlapping windows, contributions must not be added):

| Region | Level | Main RTL hierarchy |
| --- | --- | --- |
| CLEL_R_X8Y336 to LAG_LAG_X134Y719 | 8 | ghm_u_data_cdc_1/2/3/source |
| CLEM_X64Y315 to CLEL_L_X127Y474 | 7 | ghm_u_data_cdc_0/source, BOOM dcache, mshrs/mshrs_0 |
| CLEM_X22Y300 to CLEM_X53Y395 | 6 | BOOM dcache/svb (67%) |

Per-SLR CLB site occupancy: 99.82%, 99.93%, 100%. Total SLL use 25.68% (SLR2/1), 29% (SLR1/0); one local column estimated 101%. Four CDC selection nets have 9,698 loads each; ic_master packet_alloc_valid has 8,733 loads. Worst path ends at a data-CDC memory CE, 98.038% routing delay on the failed netlist. No target Pblock/SLICE LOC restriction was found in the completed audit.

Existing physical candidate remains active: equivalent remap of 153,042 MUXFs, real 1,242,046 LUT (95.27%), placement AltSpreadLogic_high in Phase 2.5 Global Placement Core at the last check. New legal-route rate and WNS are not available. Finite SLR/targeted alternatives are queued; the same failed implementation is not restarted.

Independent hardware candidate `6e1e9b9` changes only four GHM data queues to same-capacity 1R1W Mem with source-local selection. Single complete-module OOC result: 21,073 → 44 LUT, 78,479 → 88 FF, 0 → 4.5 BRAM; no DSP/CARRY8. Four copies remove 84,116 LUT and 313,564 FF in the paired module measurements; this is not a full-shell delta.

Actual full-width state/output proof passed (315 state words, 78,475 bits, arbitrary independent clock/reset inputs); generated multi-cycle-memory Golden Gate host passed 8,192 tokens and a failing negative control. Full Chipyard elaboration completed with four LocalMem queue instances. Full Golden Gate conversion completed at 10:14:57 Beijing time. New DUT synthesis actually started at 10:14:59; the controller then reuses only the 11 unchanged shell IP checkpoints, measures complete-shell post-opt and proceeds through strict physical gates. New full-shell LUT remains unmeasured.

Clock warnings are still open: invalid internal primary clock redefinition/hierarchical-pin creation and two PCIe scoped clock groups. Exact original Golden Gate 1/0 and 2/1 generated-clock constraints are restored at actual BUFG paths for new physical candidates. Unresolved critical methodology/timing/DRC prevents bitstream admission; warnings are not waived.

Evidence: audit/, state.json, recovery-snapshot-20261114.json, and ../performance-only-memory-cdc-r2-20261114/{formal-r4/result.json,host-r2/state.json,area-r1/state.json,complete-shell-r3/state.json}.

Full EC `8491167d` and Performance-Only baseline remain unchanged. Workflow artifacts committed as `f230cea` and `64683de`. No FPGA access or model requests. Board path remains strictly 21-only after real bitstream certification.
