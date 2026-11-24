# PALIMPSEST 论文与 RTL 功能审计入口

审计日期：2026-11-21（Asia/Shanghai）。结论：**当前是具备检查、版本保存和部分可见性控制的正常执行实现，尚未形成论文所述的 Rollback/Recovery 闭环。现有存储和握手可以复用，但恢复控制之外还必须修改历史保留规则、版本选择和跨层协议。**

## 基线与证据边界

- 论文：相对 Chipyard 的 `../AI/Ref/DAC_2027_EC.pdf`，7 页；主要依据 III、IV-A–G、Algorithm 1、Figure 3/4。SHA256：`17a81ade91736262b6d9f14f77336c852a1f692ae020fa498c8bddb82bd307e2`。
- Chipyard 实际属于上层 EC Git 仓库；分支 `firesim/fpga-checkpoint-20261104`，HEAD `75f2905693d6eec3b92d733e65bafa7a9c4be6dc`。审计前唯一 `git status --short` 项为 `?? ../AI/Ref/`；Chipyard 代码无未提交修改。报告写入后新增本组文档。
- 主要配置：`v1Config`，1 个 BOOM 主核、4 个 Rocket Checker，L2 1 MiB/16-way，SVB 默认 16 项。多主核结论属于扩展能力审计，不能用当前单主核配置验证。
- 本轮仅阅读 Chisel/Scala 硬件源、论文及现有清单/日志，未构建、生成 RTL、运行仿真或修改 Chipyard。`Implemented` 表示静态路径闭合，验证情况另记。
- 现有 Opt4 清单的 20 个冻结源码、12 个测量源码、6 个原始证据哈希全部匹配；保存了正常 BFS `verified=1` 和保存/ACK 完整性 PASS。清单自己仍保留 baseline 来源、完整 durable-drain 和故障恢复覆盖限制；本轮没有重新验证波形。见 [验证计划的证据清单](04_PALIMPSEST_Verification_Plan.md#existing-evidence)。

## 已有能力

主核以单调递增的 32 位 Seq 分段，发送寄存器/PC 快照和重执行输入；Checker 比较内存操作及结束架构状态，通过结果队列和 CDC 返回 `{status, Seq}`。DCache 保存乱序检查结果，只推进连续 PASS 前缀的 SW。

检错覆盖仍有明确缺口：当前结束比较共用索引 1–31，跳过了并非零寄存器的浮点 f0；尚无本轮故障注入验证。证据见 01/E24，后续定向测试见 04/T25。

L1 为实际数据写入维护 `CacheImageKey={valid, writer, generation, contentSeq}`，以精确身份和下层保存凭证保护覆盖。普通跨段 Store 可将 unsafe predecessor 整行捕获到 SVB 后继续写；SVB 等旧值安全后向 L2 下推，收到匹配 ReleaseAck 才释放。L2 的保存引擎可在安全后用 PutFullData 保存旧 resident 到 DRAM，并以事务 echo 匹配 ACK；unsafe 外层写回有实际门控。普通 Rocket/DMA 等不识别版本的访问者受到等待/重放门控。

## 核心差异与风险

1. **缺少恢复主控及主核状态恢复。** 没有把 Checker FAIL 连到 SCP 定位、BOOM PRF/rename/CSR 恢复、恢复 PC、历史失效和重启。现有 Rocket 快照恢复服务于 Checker 初始化；BOOM ROB 的 `rollback` 服务于常规流水线恢复。
2. **历史有效性规则不同。** 无论文的执行 Epoch/EVT/Cur/CurGen；当前 `generation` 是逐写内容序号。FAIL 将 SVB 中 `Seq > SW` 的 SPEC 项删除，可能删除仍有效的 A7；常规 exception 和性能 RESET 也会触发 SVB flush。
3. **多版本位置与 L2 能力不同。** 多版本主要是 L1 resident + 有界 SVB，L2 仍是按 tag 查找的单 resident 组织；它等待旧值安全并保存到 DRAM，再允许异 key 覆盖，未提供跨层 Historical 查询和 LatestSurviving。
4. **恢复读取没有接通。** SVB 无按地址的恢复读口；所谓 `promote` 是安全 ReleaseData 下推，`recoveryFromSvb` 统计等于下推 ACK，并非恢复 Load。DRAM 普通 refill 不能保证优先恢复 A7 而非 A1。
5. **外部可见性与前进性仍有边界。** MMIO 路径只有通常的非推测发射条件，未见等检查前缀安全的通用屏障；L2 对 image-aware 请求者豁免安全门控，不能直接扩成两个主核的跨核隔离。已有提前关段、等待槽、drain/interlock，但没有任意压力及 Rollback 并发下的完整活性证明。

**Figure 4(b) 当前不能完成。** 设 SW=6、A7 尚未验证，Seq8 普通 Store 可先保存 A7，再形成 A8。FAIL8 能到 DCache，但首次控制断点是没有 Rollback 请求消费者；同一错误事件还会按 `SW=6` 删除 SVB A7。即使外加 PC 重定向，当前普通 Load 仍可能命中 A8，或在清空后取到 A1。详见 [逐步推演](02_PALIMPSEST_Rollback_Gap.md#figure4b)。

## 下一步顺序

先确定 CP 生命周期、有效历史区间与外部提交边界，并停止把 FAIL/exception/测量 RESET 等同于丢弃恢复历史；再新增单主核错误事件与恢复主控、持久 SCP 和 BOOM 架构状态恢复。随后实现 EVT/逻辑 Current 失效、SVB/跨层恢复查询及 LatestSurviving，并在允许重启前闭合在途事务/ACK。最后扩展 L2 历史容量、多主核可见性、MMIO 和有界前进机制。**仅加 RollbackController 不足以完成论文。**

具体接口与验收见 [实施路线](03_PALIMPSEST_Implementation_Roadmap.md)。论文指定功能与 RTL 组织选择的区别见 [矩阵中的设计待决策](01_PALIMPSEST_Feature_Matrix.md#design-decisions)。

## 详细文档

- [01：全部 49 项功能矩阵、代码证据索引及可信度](01_PALIMPSEST_Feature_Matrix.md)
- [02：Rollback 缺口、Figure 4(b)、竞态与复用条件](02_PALIMPSEST_Rollback_Gap.md)
- [03：分阶段实现路线及最小验收](03_PALIMPSEST_Implementation_Roadmap.md)
- [04：已有验证边界与后续定向验证计划](04_PALIMPSEST_Verification_Plan.md)

这些文档以本次 HEAD 的源码为准。旧 `cache_recovery_gap_analysis_20261011.md` 等只作历史材料；不把其旧行号、旧失败直接认定为当前事实。后续源码变化需重做定位和证据关联。
