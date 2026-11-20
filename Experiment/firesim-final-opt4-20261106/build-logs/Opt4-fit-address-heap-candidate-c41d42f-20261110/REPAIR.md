
### 2026-11-10 20:35 CST：完整地址模块实测与独立候选修复

- 第一版完整地址模块的匹配OOC综合/检查点现已完成。Vivado权威 `CLB LUTs` 为 **1,500,571**（不是1,502,571），CARRY8 **57,446**，FF **390,171**，BRAM tile **216**，DSP **0**；对应 `build-logs/Opt4-fit-modules-20261110/fit-address/vivado/{utilization.rpt,module.dcp}`。冻结同设置为1,702,895 LUT / 58,190 CARRY8；减少 **202,324 LUT（11.881%）**。独立模块仍比U280全部1,303,680 LUT多196,891；这不是当前整机post-opt容量或FIT结论。当前整机8da24a26保持运行，不更改其输入。
- 独立80项压缩归约探针实测 **840 LUT、0 CARRY8、0 DSP**，比round3平衡树957 LUT少12.226%，比原探针1843 LUT少54.422%。证明为对实际微RTL解析的局部穷举压缩器/位权守恒及已证明leaf上界；原80项整体SAT超时证据仍保留。这不是完整地址模块收益，也不是全DUT等价。
- 实际Chisel候选06b8731在elaboration中因 `Bool.cloneTypeWidth` 对多位pad的require失败。完整栈见 `build-logs/Opt4-fit-address-heap-candidate-20261110/diagnostic/full-stack.log`。故障进程已自然退出并核对PID/start_ticks/boot_id，未结束活任务。独立候选修复为显式Cat零扩展，commit **c41d42f61aa79d8249125c9e911438b797d007ce** / source ID **6fcb790b0d19e832582166c1940f485a00940f95437b38d297d9533f446721d2**。旧commit、失败日志/收据/patch保留，独立新输出 `build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/`。
- 服务 `ec-parsec-opt4-fit-address-heap-candidate.service` 已重新启动这项已退出的失败候选，仅执行独立compile/elaboration、冻结完整地址模块6144周期/52输出逐周期对照，通过后才综合完整地址模块。不修改当前整机、round3活综合或FPGA。状态 `Opt4-fit-address-heap-candidate-state.json`，候选未经最终验证/整机资源门，不进入当前生产版。
- 派生自动链路服务 `ec-parsec-opt4-fit-runtime.service` 正常等待真实8da24a26 bitstream，不占用维护锁或21卡；13项已绑定软件不重建、不修改。真实capacity/timing/DRC认证之后才发布优先权、等待Native安全边界、21-only部署及严格首验，正式先r1覆盖再补轮次。
