# Resource priorities, weighted by actual instance counts

2026-11-10T10:47:30.075634+00:00

Frozen mapped direct primitive census weighted by real instance counts; derived whole-system mapping remains pending. Counts below are raw primitives, **not physical LUT capacity**. Direct module rows are disjoint; inclusive BOOM/L2 rows are listed separately and must not be added to them.

| Module | Instances | Total direct LUT primitives | CARRY8 | DSP | FF |
|---|---:|---:|---:|---:|---:|
| PackageAddressStats | 1 | 1,664,889 | 58,194 | 0 | 390,791 |
| design_1_firesim_wrapper_0_0 | 1 | 1,413,744 | 145,365 | 0 | 0 |
| GHBarrierLatencyStats_2025 | 1 | 576,225 | 51,852 | 2,048 | 41,601 |
| GHBarrierLatencyStats | 1 | 474,373 | 35,173 | 2,048 | 41,601 |
| CSRFile | 1 | 473,178 | 39,502 | 0 | 2,984 |
| GHBarrierLatencyStats_1713 | 1 | 445,774 | 36,270 | 2,048 | 41,601 |
| InclusiveCache | 1 | 325,146 | 30,345 | 2,876 | 42,159 |
| AsyncResetSynchronizerPrimitiveShiftReg_d3_i0_2052 | 1 | 209,354 | 6,467 | 0 | 12 |
| SpeculativeVersionBuffer | 1 | 177,510 | 11,299 | 0 | 20,710 |
| BoomMSHR | 1 | 137,297 | 32 | 0 | 820 |
| BoomProbeUnit | 1 | 111,918 | 18 | 0 | 61 |
| R_IC | 1 | 93,378 | 1,110 | 0 | 998 |
| BoomWritebackUnit | 1 | 86,845 | 75 | 0 | 801 |
| BoomNonBlockingDCache | 1 | 76,673 | 2,360 | 4 | 274,986 |
| LSU | 1 | 62,664 | 306 | 0 | 14,786 |
| QueueCompatibility | 1 | 48,736 | 39 | 0 | 9 |
| Queue_45 | 1 | 42,075 | 25 | 0 | 3 |
| Rob | 1 | 36,637 | 371 | 0 | 12,329 |
| BoomMSHR_5 | 1 | 35,716 | 7 | 0 | 821 |
| MSHR_1 | 1 | 33,380 | 26 | 0 | 422 |
| L1MetadataArray | 1 | 32,415 | 11 | 0 | 9 |
| Queue_44 | 1 | 30,926 | 8 | 0 | 9 |
| RegisterFileSynthesizable_1 | 1 | 28,909 | 0 | 0 | 8,213 |
| ALUUnit | 1 | 21,706 | 0 | 0 | 99 |
| BranchKillableQueue | 1 | 21,437 | 68 | 0 | 1,380 |
| BoomDuplicatedDataArray | 1 | 21,218 | 24 | 0 | 0 |
| AsyncQueueSource_20_2681 | 1 | 20,633 | 2 | 0 | 77,586 |
| AsyncQueueSource_20_2634 | 1 | 20,633 | 2 | 0 | 77,586 |
| AsyncQueueSource_20_2587 | 1 | 20,633 | 2 | 0 | 77,586 |
| AsyncQueueSource_20 | 1 | 20,633 | 2 | 0 | 77,586 |
| RegisterFileSynthesizable | 1 | 18,224 | 0 | 0 | 8,473 |
| ALUUnit_2 | 1 | 17,216 | 0 | 0 | 284 |
| FPU_1_471 | 1 | 14,607 | 32 | 0 | 2,275 |
| FPU_1_353 | 1 | 14,607 | 32 | 0 | 2,275 |
| FPU_1_235 | 1 | 14,607 | 32 | 0 | 2,275 |

Frozen physical inclusive subtrees: BOOM 3,687,855 LUT; L2 925,534 LUT; four Rocket tiles together 304,654 LUT. Generated hierarchy migrates arithmetic into CSR/reset/top scopes; name alone does not establish its source.

Next area target: Use derived full-DUT report to confirm residual PackageAddressStats versus migrated barrier/L2 arithmetic. Within address statistics inspect 3x256x4 exact 65-bit bucket update/carry cones and 256x4 masked 80-term strict reductions. Any further transformation requires the existing full-size comparison and matched mapping; no counter width/table/event removal.

Current build: `ec-parsec-opt4-fit-cad.service`, state `Opt4-fit-cad-state.json`. Actual new DUT and top post-opt reports will be under `build-logs/Opt4-fit-cad-8da24a26/`. Do not estimate whole-system FIT by subtracting standalone module savings.
