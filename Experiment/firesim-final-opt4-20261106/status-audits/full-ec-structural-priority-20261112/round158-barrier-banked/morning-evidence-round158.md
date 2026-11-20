EC 面积冲刺实测记录（2026-11-12T16:34:19.626332+00:00）

功能基线：8491167d。完整 shell 最后完成的资源报告：2,789,012 LUT，差额 1,485,332。
另有完整 generated host：2,420,482 LUT，差额 1,116,802，不含 shell。
模块收益不直接相加为整机收益。FIT、bitstream、上板状态必须由新完整 shell/物理认证证据更新。

|任务|实际状态|完成结果|
|---|---|---|
|address-dsp-fullmodule-pair-r1|RUNNING_MAP_CANDIDATE|未完成|
|address-packed-full-module-r1|RUNNING_MAP-CANDIDATE|未完成|
|address-histogram-fame5-r6|RUNNING_GOLDENGATE-THREADED256|未完成|
|address-banked-complete-module-r1|RUNNING_PARITY-COMPILE|未完成|
|address-banked-production-host-r1|RUNNING_COMPILE-FULL-TARGET-PARITY|未完成|
|address-banked-production-area-pair-r1|QUEUED_FOR_COMPLETE_PRODUCTION_TARGET_AND_HOST_TOKEN_PASS|未完成|
|dcache-storage-compose-r3|RUNNING_MAP-COMPLETE-DCACHE|未完成|
|address-banked-production-contract-sat-r2|PASS_ACTUAL_BANK_ARBITRARY_STATE_CONTRACTS_WITH_EXACT_REPLICA_COVERAGE|已完成|
|sprint-composed-validate-r1|QUEUED_FOR_MATERIAL_VALIDATED_MODULE_COMBINATION|未完成|

已完成资源数据与失败证据见同目录 latest.json；原始报告和 checkpoint 保留。
既有智能 supervisor 持续重试网络/模型调用；确定性 CAD、验证及已准备好的门槛续跑独立于 SSH。

Round 158: 新实验提交 16b2d8945f6e17385a4fe136eadd9597ee1ac4fc；完整256项 barrier 16×16 target 8704 cycles / 263 observations PASS，负向寄存器变异被拒绝。r1 GoldenGate nonlocal-instance 失败保留；r2 仅平铺 host harness，硬件不变，host tokens/area 待实测。无新完整 EC FIT。

本轮不可变记录：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/full-ec-structural-priority-20261112/round158-barrier-banked/morning-evidence-round158.json
