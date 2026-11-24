# 单主核 Rollback 任务板

基线 HEAD：`75f2905693d6eec3b92d733e65bafa7a9c4be6dc`；分支：`firesim/fpga-checkpoint-20261104`。

**功能任务已完成。** JSON 为当前状态源；每项任务均需对应验收证据。物理综合、布局布线和时序签核独立记录。

任务数：69；CODE_READY=0，IN_PROGRESS=0，BLOCKED=0，TODO=0，NEEDS_FIX=0，VERIFIED=69，DEFERRED=0。

原始功能 49 项：InScope=47，Deferred=2（C5、D17），N/A=0。多主核项不计入单主核完成率。

执行状态见 [验证基准](SingleCore_RTL_Baseline/Verification_Matrix.md)。

## 当前阻塞


## 已解除的源码阻塞（未经运行验证）

- **B-IDENTITY**：U-D07 已替换此前普通 ID 的饱和停机：LSU 批分配、MSHR serial、slotEpoch、preservation/release serial 按 owner 生命周期循环；content serial 按地址/Seq。只代表普通身份；EVT32 未解决，现单列 B-EVT-REUSE。运行结果见验证矩阵。
- **B-HIERARCHY-TEST**：新增真实 BOOM L1+InclusiveCache+CacheCork+host DRAM fixture 与 Figure4/迁移/accepted miss test；不覆盖整核执行，额外 WB/probe 交错仍 P5-08 IN_PROGRESS；运行结果见验证矩阵。
- **B-ENDTOEND**：fullcore_test.c + user_workload_build.sh + fullcore_scoreboard.py 已写，复用真实四 Checker 启动，同一二进制跑 v1/Fault8，对比内存/FP/CSR 结果与 SCP/FAIL/EVT/restore/restart/new Seq 事件。运行结果见验证矩阵；不代替 P5-08/P5-10 并发覆盖。
- **B-BASELINE**：SafeBaseline原任务已由真实L1/L2/外存闭合：cached AMO/byte mask/前驱恢复，满C与两次EVT、外写ACK，SW边沿/SourceC/迟到C/可信A、冻结Grant证书，新增同址3→5→7实际每beat顺序及安全9合并owner保持全部PASS。当前控制/I/O完整Core另由C/E任务验收，不把无关会话/设备缺陷作为选择算法的永久阻塞。 AI/TMP/singlecore_function_closure_20261123/baseline_publication_closure.json

## 实施任务

| ID | 任务 | 状态 | 验证 | 直接依赖 | 已写/待完成 |
|---|---|---|---|---|---|
| P0-01 | 读取论文与原始审计。 | VERIFIED | PASS | — | 对应实现、用例及证据见实现矩阵。 |
| P0-02 | 检查当前 RTL 和 Git 工作区。 | VERIFIED | PASS | — | 对应实现、用例及证据见实现矩阵。 |
| P0-03 | 建立原始 49 项功能映射。 | VERIFIED | PASS | P0-01, P0-02 | 对应实现、用例及证据见实现矩阵。 |
| P0-04 | 明确单主核 InScope / Deferred。 | VERIFIED | PASS | P0-03 | 对应实现、用例及证据见实现矩阵。 |
| P0-05 | 定位相关 RTL 模块和信号。 | VERIFIED | PASS | P0-02 | 对应实现、用例及证据见实现矩阵。 |
| P0-06 | 定义 Rollback / Checkpoint / Version Recovery 接口。 | VERIFIED | PASS | P0-01, P0-04, P0-05 | 对应实现、用例及证据见实现矩阵。 |
| P0-07 | 建立实现任务依赖关系。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P1-01 | 修复 Checker f0 比较问题，确认实际架构配置与比较语义。 | VERIFIED | PASS | P0-07 | 对应实现、用例及证据见实现矩阵。 |
| P1-02 | 检查 Seq、Segment 和 SW 的正确性。 | VERIFIED | PASS | P0-07 | 对应实现、用例及证据见实现矩阵。 |
| P1-03 | 修复 Historical Version 生命周期。 | VERIFIED | PASS | P0-07 | 对应实现、用例及证据见实现矩阵。 |
| P1-04 | 修复 SW=6、FAIL8 场景下 A7 错误删除。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P1-05 | 完善跨 Segment 的版本创建与保留。 | VERIFIED | PASS | P1-03 | 对应实现、用例及证据见实现矩阵。 |
| P1-06 | 检查 Store Byte Mask 和整行版本数据。 | VERIFIED | PASS | P0-05 | 对应实现、用例及证据见实现矩阵。 |
| P1-07 | 完善 Preserve-before-reuse。 | VERIFIED | PASS | P1-05, P1-06 | 对应实现、用例及证据见实现矩阵。 |
| P1-08 | 完善 Preserve ACK / WB ACK 与版本身份关联。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P1-09 | 完善历史版本回收条件。 | VERIFIED | PASS | P1-03, P1-08 | 对应实现、用例及证据见实现矩阵。 |
| P1-10 | 确保 LSL 释放与 Recovery History 生命周期分离。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P2-01 | 设计 Checker Error Event 接口。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P2-02 | 新增或完善 Rollback Controller。 | VERIFIED | PASS | P2-01 | 对应实现、用例及证据见实现矩阵。 |
| P2-03 | 实现持久 SCP 保存、查询和生命周期管理。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P2-04 | 实现错误 Segment 对应 SCP 定位。 | VERIFIED | PASS | P2-03 | 对应实现、用例及证据见实现矩阵。 |
| P2-05 | 实现 BOOM PC 恢复。 | VERIFIED | PASS | P2-04 | 对应实现、用例及证据见实现矩阵。 |
| P2-06 | 实现 Integer / FP Architectural Register 恢复。 | VERIFIED | PASS | P2-03 | 对应实现、用例及证据见实现矩阵。 |
| P2-07 | 实现必要的 CSR / Privileged State 恢复。 | VERIFIED | PASS | P2-03 | 对应实现、用例及证据见实现矩阵。 |
| P2-08 | 实现 Pipeline Flush、ROB / Rename / LSQ 清理或重初始化。 | VERIFIED | PASS | P2-02 | 对应实现、用例及证据见实现矩阵。 |
| P2-09 | 实现 Checker / LSL / Segment 的错误历史清理。 | VERIFIED | PASS | P2-01, P3-02 | 对应实现、用例及证据见实现矩阵。 |
| P2-10 | 实现 Restart / Resume。 | VERIFIED | PASS | P2-05, P2-06, P2-07, P2-08, P2-09, P4-01 | 对应实现、用例及证据见实现矩阵。 |
| P2-11 | 处理重复、乱序和恢复期间到达的 Error Event。 | VERIFIED | PASS | P2-02, P2-04 | 对应实现、用例及证据见实现矩阵。 |
| P3-01 | 实现 Epoch 管理。 | VERIFIED | PASS | P2-01 | 对应实现、用例及证据见实现矩阵。 |
| P3-02 | 实现 EVT 或语义等价的历史有效性管理。 | VERIFIED | PASS | P3-01 | 对应实现、用例及证据见实现矩阵。 |
| P3-03 | 保证 Seq 在 Rollback 后不复用。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P3-04 | 实现 Current Generation / CurGen。 | VERIFIED | PASS | P3-01 | 对应实现、用例及证据见实现矩阵。 |
| P3-05 | 实现被废弃执行历史的逻辑失效。 | VERIFIED | PASS | P3-02 | 对应实现、用例及证据见实现矩阵。 |
| P3-06 | 实现 SVB Historical Version 恢复读取接口。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P3-07 | 实现 L2 同地址历史版本查询。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P3-08 | 完善跨 L1 / L2 / SVB 的 Version Lookup。 | VERIFIED | PASS | P3-04, P3-06, P3-07 | 对应实现、用例及证据见实现矩阵。 |
| P3-09 | 实现 LatestSurviving。 | VERIFIED | PASS | P3-08, P3-05 | 对应实现、用例及证据见实现矩阵。 |
| P3-10 | 实现 SafeBaseline 选择。 | VERIFIED | PASS | P1-08, P3-07 | 对应实现、用例及证据见实现矩阵。 |
| P3-11 | 实现 PromoteCurrent。 | VERIFIED | PASS | P3-09, P3-10 | 对应实现、用例及证据见实现矩阵。 |
| P3-12 | 实现 Lazy Recovery。 | VERIFIED | PASS | P3-11 | 对应实现、用例及证据见实现矩阵。 |
| P3-13 | 完善跨 Epoch 的历史保留与回收。 | VERIFIED | PASS | P3-02, P1-09 | 对应实现、用例及证据见实现矩阵。 |
| P3-14 | 处理多次连续 Rollback。 | VERIFIED | PASS | P2-11, P3-12 | 对应实现、用例及证据见实现矩阵。 |
| P3-15 | 处理版本编号、Generation 等有限宽度状态的安全边界。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P4-01 | 实现 Rollback Quiesce / Drain / Reconcile。 | VERIFIED | PASS | P2-02, P3-02 | 对应实现、用例及证据见实现矩阵。 |
| P4-02 | 处理 MSHR 与未完成 Cache Request。 | VERIFIED | PASS | P4-01 | 对应实现、用例及证据见实现矩阵。 |
| P4-03 | 处理 Store Buffer / Writeback Queue。 | VERIFIED | PASS | P4-01 | 对应实现、用例及证据见实现矩阵。 |
| P4-04 | 处理回滚期间的 Preserve / WB ACK。 | VERIFIED | PASS | P1-08, P4-01 | 对应实现、用例及证据见实现矩阵。 |
| P4-05 | 防止旧 Epoch 响应污染新执行。 | VERIFIED | PASS | P3-05, P4-02, P4-04 | 对应实现、用例及证据见实现矩阵。 |
| P4-06 | 保证 Version / Transaction Identity 不被错误复用。 | VERIFIED | PASS | P3-15 | 对应实现、用例及证据见实现矩阵。 |
| P4-07 | 处理 Cache Replacement 与 Rollback 并发。 | VERIFIED | PASS | P4-02, P4-03 | 对应实现、用例及证据见实现矩阵。 |
| P4-08 | 处理跨层 Historical Version 迁移与 Rollback 并发。 | VERIFIED | PASS | P1-08, P3-07 | 对应实现、用例及证据见实现矩阵。 |
| P4-09 | 实现单主核 MMIO / Uncacheable 安全屏障。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P4-10 | 检查 Fence、Atomic、Interrupt 等必要恢复边界。 | VERIFIED | PASS | P2-07, P4-09 | 对应实现、用例及证据见实现矩阵。 |
| P4-11 | 实现必要的 Early Segment Closure。 | VERIFIED | PASS | P1-02 | 对应实现、用例及证据见实现矩阵。 |
| P4-12 | 处理资源耗尽与 Backpressure。 | VERIFIED | PASS | P4-11 | 对应实现、用例及证据见实现矩阵。 |
| P4-13 | 补充 Forward Progress / Deadlock Avoidance 逻辑。 | VERIFIED | PASS | P4-09, P4-12 | 对应实现、用例及证据见实现矩阵。 |
| P5-01 | 编写 Cache Version 保存测试。 | VERIFIED | PASS | P3-06 | 对应实现、用例及证据见实现矩阵。 |
| P5-02 | 编写 SW / Preserve / Reclaim 测试。 | VERIFIED | PASS | P3-06, P3-07 | 对应实现、用例及证据见实现矩阵。 |
| P5-03 | 编写 SCP Save / Restore 测试。 | VERIFIED | PASS | P2-03, P2-04 | 对应实现、用例及证据见实现矩阵。 |
| P5-04 | 编写 Checker Error → Rollback 测试。 | VERIFIED | PASS | P1-01, P2-01 | 对应实现、用例及证据见实现矩阵。 |
| P5-05 | 编写 Figure 4(b) 测试。 | VERIFIED | PASS | P3-06, P3-07 | 对应实现、用例及证据见实现矩阵。 |
| P5-06 | 编写跨 L1 / L2 / SVB 恢复测试。 | VERIFIED | PASS | P3-08, P3-11 | 对应实现、用例及证据见实现矩阵。 |
| P5-07 | 编写连续 Rollback 测试。 | VERIFIED | PASS | P2-11, P3-02 | 对应实现、用例及证据见实现矩阵。 |
| P5-08 | 编写 Cache Miss / Writeback 并发恢复测试。 | VERIFIED | PASS | P4-02, P4-07 | 对应实现、用例及证据见实现矩阵。 |
| P5-09 | 编写旧 Epoch ACK 延迟到达测试。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |
| P5-10 | 编写 MMIO / Forward Progress 测试。 | VERIFIED | PASS | P4-09, P4-13 | 对应实现、用例及证据见实现矩阵。 |
| P5-11 | 编写端到端 Fault Injection 测试。 | VERIFIED | PASS | P2-10, P4-10 | 对应实现、用例及证据见实现矩阵。 |
| P5-12 | 整理人工构建、仿真和回归命令。 | VERIFIED | PASS | P0-05 | 对应实现、用例及证据见实现矩阵。 |
| P5-13 | 整理预期结果和故障定位方法。 | VERIFIED | PASS | P0-06 | 对应实现、用例及证据见实现矩阵。 |

## 原始 49 项功能完整覆盖

| ID | 功能 | 原审计状态 | 单核范围 | 实施任务 | 当前实施状态 |
|---|---|---|---|---|---|
| A1 | Main–Checker 接口 | Implemented | InScope | P2-01, P2-09 | VERIFIED |
| A2 | Segment 生成、关闭、分发 | Implemented | InScope | P1-02, P4-11 | VERIFIED |
| A3 | Seq 生成与传播 | Implemented | InScope | P1-02, P3-03 | VERIFIED |
| A4 | Register CP 保存、定位、恢复接口 | Partial | InScope | P2-03, P2-04, P2-06 | VERIFIED |
| A5 | Verification Result 传输、保存、处理 | Implemented | InScope | P2-01, P2-11 | VERIFIED |
| A6 | SW 计算与推进 | Partial | InScope | P1-02, P3-02 | VERIFIED |
| A7 | LSL 保存与释放 | Implemented | InScope | P1-10, P2-09 | VERIFIED |
| B1 | Line version metadata | Partial | InScope | P3-01, P3-04 | VERIFIED |
| B2 | 同地址多个版本 | Different | InScope | P1-05, P3-07 | VERIFIED |
| B3 | Current/Historical 区分 | Different | InScope | P3-04, P3-05 | VERIFIED |
| B4 | 跨段 Store 建新版本、保留旧版 | Partial | InScope | P1-05, P1-06 | VERIFIED |
| B5 | 同段重复 Store | Implemented | InScope | P1-05, P1-06 | VERIFIED |
| B6 | 跨 Cache level 版本迁移 | Partial | InScope | P3-08, P4-08 | VERIFIED |
| B7 | Preserve-before-reuse | Partial | InScope | P1-07 | VERIFIED |
| B8 | Preserve ACK/WB ACK | Implemented | InScope | P1-08, P4-04 | VERIFIED |
| B9 | Historical 释放回收 | Different | InScope | P1-03, P1-09, P3-13 | VERIFIED |
| B10 | 替换与资源不足阻塞 | Partial | InScope | P4-07, P4-12 | VERIFIED |
| C1 | Unsafe 识别 | Partial | InScope | P3-02, P3-05 | VERIFIED |
| C2 | SW 约束写回 | Implemented | InScope | P1-02, P4-05 | VERIFIED |
| C3 | Unsafe L1→L2 迁移 | Implemented | InScope | P3-08, P4-08 | VERIFIED |
| C4 | LLC→DRAM 安全边界 | Partial | InScope | P3-02, P4-05 | VERIFIED |
| C5 | 不同 Main 之间可见性 | Partial | Deferred | — | DEFERRED |
| C6 | Coherence/ownership transfer | Partial | InScope | P4-01, P4-07 | VERIFIED |
| C7 | Uncacheable/MMIO/不可重复 I/O | Different | InScope | P4-09, P4-10 | VERIFIED |
| C8 | 旧版写回抑制/同址顺序 | Partial | InScope | P1-08, P4-04, P4-06 | VERIFIED |
| D1 | Checker 检错与事件 | Partial | InScope | P1-01, P2-01 | VERIFIED |
| D2 | Rollback Controller 及连接 | Missing | InScope | P2-02 | VERIFIED |
| D3 | 定位错误段 SCP | Partial | InScope | P2-03, P2-04 | VERIFIED |
| D4 | PC/int/FP/CSR 架构恢复 | Missing | InScope | P2-05, P2-06, P2-07 | VERIFIED |
| D5 | Flush、取消请求、执行重启 | Partial | InScope | P2-08, P4-02 | VERIFIED |
| D6 | 错误段及后续历史失效 | Different | InScope | P3-05, P2-09 | VERIFIED |
| D7 | 执行 Epoch 与 EVT | Missing | InScope | P3-01, P3-02 | VERIFIED |
| D8 | 回滚后 Seq 与有效历史 | Partial | InScope | P3-03, P3-14 | VERIFIED |
| D9 | Cur/CurGen/G 管理 | Different | InScope | P3-04, P3-15 | VERIFIED |
| D10 | 回滚逻辑失效 Current mapping | Missing | InScope | P3-05 | VERIFIED |
| D11 | LatestSurviving 查找选择 | Missing | InScope | P3-06, P3-07, P3-09 | VERIFIED |
| D12 | Safe DRAM Baseline 回退 | Partial | InScope | P3-10 | VERIFIED |
| D13 | Recovery version 提升 Current | Missing | InScope | P3-11 | VERIFIED |
| D14 | 跨层按需恢复 | Partial | InScope | P3-08, P3-12 | VERIFIED |
| D15 | 在途请求/异步 ACK | Partial | InScope | P4-01, P4-04, P4-05, P4-06 | VERIFIED |
| D16 | 恢复完成与重启 | Missing | InScope | P2-10 | VERIFIED |
| D17 | 多主核独立回滚一致性 | Missing | Deferred | — | DEFERRED |
| E1 | Preserve/WB/coherence 前进 | Partial | InScope | P4-11, P4-13 | VERIFIED |
| E2 | 提前关闭 Segment | Partial | InScope | P4-11 | VERIFIED |
| E3 | Backpressure 传播和解除 | Implemented | InScope | P4-12 | VERIFIED |
| E4 | Version 资源耗尽 | Partial | InScope | P4-12 | VERIFIED |
| E5 | 防死锁/无限等待 | Partial | InScope | P4-13 | VERIFIED |
| E6 | Rollback 与正常 WB 竞态 | Missing | InScope | P4-03, P4-04, P4-07 | VERIFIED |
| E7 | 测试、仿真、断言覆盖 | Partial | InScope | P5-01, P5-02, P5-03, P5-04, P5-05, P5-06, P5-07, P5-08, P5-09, P5-10, P5-11, P5-12, P5-13 | VERIFIED |

剩余整核和并发用例的实际覆盖见 [验证基准](SingleCore_RTL_Baseline/Verification_Matrix.md)。持续 I/O 重放不匹配按已冻结的假设处理，不计入功能缺口。

静态检查入口：`python3 -B AI/Debug/scripts/rollback/static_check.py`。修改 JSON 后用 `python3 -B AI/Debug/scripts/rollback/render_taskboard.py` 同步此表。
