EC 面积冲刺实测记录（2026-11-12T18:13:29.659437+00:00）

功能基线：8491167d。完整 shell 最后完成的资源报告：2,789,012 LUT，差额 1,485,332。
另有完整 generated host：2,420,482 LUT，差额 1,116,802，不含 shell。
模块收益不直接相加为整机收益。FIT、bitstream、上板状态必须由新完整 shell/物理认证证据更新。

|任务|实际状态|完成结果|
|---|---|---|
|address-dsp-fullmodule-pair-r1|RUNNING_MAP_CANDIDATE|未完成|
|address-packed-full-module-r1|COMPLETE_PRIVATE_MODULE_PARITY_AND_PAIRED_AREA_NOT_WHOLE_FIT|已完成|
|address-histogram-fame5-r6|FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED|未完成|
|address-banked-complete-module-r1|RUNNING_PARITY-COMPILE|未完成|
|address-banked-production-host-r1|RUNNING_COMPILE-FULL-TARGET-PARITY|未完成|
|address-banked-production-area-pair-r1|QUEUED_FOR_COMPLETE_PRODUCTION_TARGET_AND_HOST_TOKEN_PASS|未完成|
|dcache-storage-compose-r3|RUNNING_MAP-COMPLETE-DCACHE|未完成|
|address-banked-production-contract-sat-r2|PASS_ACTUAL_BANK_ARBITRARY_STATE_CONTRACTS_WITH_EXACT_REPLICA_COVERAGE|已完成|
|sprint-composed-validate-r1|QUEUED_FOR_MATERIAL_VALIDATED_MODULE_COMBINATION|未完成|

已完成资源数据与失败证据见同目录 latest.json；原始报告和 checkpoint 保留。
既有智能 supervisor 持续重试网络/模型调用；确定性 CAD、验证及已准备好的门槛续跑独立于 SSH。
