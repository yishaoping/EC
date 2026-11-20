# Completed 8da24a26 DUT DCP: mapped-name attribution

2026-11-11T00:16:31.198215+00:00

Disjoint primitive groups by mapped name only, not physical LUT count or proven source cones. Cross-name optimization may move logic.

| Mapped name group | LUT primitives | CARRY8 | FF | DSP |
|---|---:|---:|---:|---:|
| design_1_firesim_wrapper_0_0_PackageAddressStats.bucketStrictWriteRead | 741,894 | 18,006 | 65,536 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.errorReg | 206,145 | 3,776 | 6 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.bucketLoadFirst | 149,680 | 16,898 | 65,536 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.bucketStoreFirst | 148,950 | 16,906 | 65,536 | 0 |
| design_1_firesim_wrapper_0_0_SpeculativeVersionBuffer.state | 77,293 | 5,306 | 64 | 0 |
| design_1_firesim_wrapper_0_0_SpeculativeVersionBuffer.activeIdx | 74,671 | 5,734 | 38 | 0 |
| design_1_firesim_wrapper_0_0_BoomMSHR.protocolFault | 63,884 | 0 | 1 | 0 |
| design_1_firesim_wrapper_0_0_BoomWritebackUnit.bucketState_writebackCycleSum | 47,545 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_LSU.queue | 40,771 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_BoomWritebackUnit.bucketState_count | 34,503 | 8 | 0 | 0 |
| design_1_firesim_wrapper_0_0_BoomMSHR.s3_result | 33,944 | 3 | 0 | 0 |
| design_1_firesim_wrapper_0_0_GHBarrierLatencyStats_1713.requestCycleSum | 28,023 | 744 | 64 | 0 |
| design_1_firesim_wrapper_0_0_GHBarrierLatencyStats_2025.requestCycleSum | 28,023 | 744 | 64 | 0 |
| design_1_firesim_wrapper_0_0_GHBarrierLatencyStats.requestCycleSum | 27,263 | 704 | 64 | 0 |
| design_1_firesim_wrapper_0_0_Queue_44.s3_cancelled | 25,572 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_QueueCompatibility.l2Bucket_count | 25,398 | 10 | 0 | 0 |
| design_1_firesim_wrapper_0_0_GHBarrierLatencyStats.buckets_requestCycleSum | 25,362 | 148 | 16,384 | 0 |
| design_1_firesim_wrapper_0_0_BoomDuplicatedDataArray.debug_new_image_generation | 24,734 | 5 | 0 | 0 |
| design_1_firesim_wrapper_0_0_GHBarrierLatencyStats.buckets_count | 23,122 | 8 | 16,384 | 0 |
| design_1_firesim_wrapper_0_0_QueueCompatibility.l2Bucket_writebackCycleSum | 22,337 | 8 | 0 | 0 |
| design_1_firesim_wrapper_0_0_BoomMSHR.installStarted | 21,811 | 0 | 1 | 0 |
| design_1_firesim_wrapper_0_0_AsyncResetSynchronizerPrimitiveShiftReg_d3_i0_2044.l2WritebackCycleSum | 21,364 | 552 | 0 | 0 |
| design_1_firesim_wrapper_0_0_BoomMSHR.array | 21,313 | 6 | 0 | 0 |
| design_1_firesim_wrapper_0_0_BoomNonBlockingDCache.preservationDiagEvents | 20,723 | 4 | 2 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.strictOverflowData | 20,633 | 448 | 19,520 | 0 |
| design_1_firesim_wrapper_0_0_AsyncQueueSource_20.cdc | 20,604 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_AsyncQueueSource_20_2587.cdc | 20,604 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_AsyncQueueSource_20_2634.cdc | 20,604 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_AsyncQueueSource_20_2681.cdc | 20,604 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.onlineStrictWriteRead | 19,424 | 75 | 256 | 0 |
| design_1_firesim_wrapper_0_0_BoomProbeUnit.buckets_count | 18,515 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.bucketStore | 18,447 | 32 | 65,536 | 0 |
| design_1_firesim_wrapper_0_0_MSHR_3.buckets_count | 18,283 | 0 | 0 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.onlineLoadFirst | 18,241 | 65 | 256 | 0 |
| design_1_firesim_wrapper_0_0_BoomProbeUnit.buckets_requestCycleSum | 18,187 | 8 | 0 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.onlineStoreFirst | 18,171 | 65 | 256 | 0 |
| design_1_firesim_wrapper_0_0_MSHR_3.buckets_requestCycleSum | 18,005 | 8 | 0 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.onlineStore | 17,940 | 64 | 256 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.onlineFirstStore | 17,939 | 64 | 256 | 0 |
| design_1_firesim_wrapper_0_0_PackageAddressStats.bucketFirstStore | 17,672 | 32 | 65,536 | 0 |
