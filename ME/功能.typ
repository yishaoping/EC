
正常执行时，BOOM 按 Segment 连续运行，多个 Rocket Checker 并行检查已经分派的片段。片段边界保存架构快照：同一边界既是前段的 ECP，也是后段的 SCP；供 Main 回滚的 SCP 另有持久目录保存。Main 将已提交的访存地址和数据送入日志，Checker 通过 LSL 取得记录的 Load 值，并核对访存顺序、地址和 Store 数据，最后比较结束状态。Store 修改缓存时，跨 Segment 覆盖前需要保存旧行，因此 A7、A8 可以同时分布在 L1、SVB 或 L2 历史存储中。Checker 结果进入 DCache 的 Verification Bitmap；SW 是保存的寄存器，每周期最多前进一步。假设 SW=6，PASS8 会被记录，但 Pending7 会阻止 SW 前进；随后 PASS7，SW 才依次走到 7、8。尚未安全的数据可以在可恢复的缓存域内迁移，对外写回还必须满足有效历史、SW 覆盖及相应事务条件。LSL 在检查结束后可以释放，因为它服务于重放检查；历史版本还可能承担回滚前驱或最新安全基线的职责，生命周期更长。

FAIL8 是另一条独立执行分支。恢复目标是 **Seq8 开始前的 SCP8**，此时架构状态应包含 Seq7 的执行结果。当前控制顺序是阻止 Main 继续推进，定位并固定 SCP8，提交 EVT 更新、废弃 `[8,旧 tail]`，等待相关事务排空，然后清理后端并导入整数、浮点、映射和 CSR 状态，最后重定向 PC。旧 Seq7 仍然有效；若旧 tail=10，重新执行使用新 Seq11。内存恢复按访问发生：缓存保留数据，但旧 Current 映射通过代际检查失效。第一次 Load A 查询 SVB/L2 历史候选，按 EVT 排除 A8，再从存活候选中选择最大的 `(Seq,内容 serial)`，取得正常一致性权限后，由 MSHR 将选中的 A7 数据用于返回和安装。这里选择 A7 **不要求 Seq7 已被 SW 覆盖**：A7 是恢复 SCP8 所需的前驱值，即使仍 Pending，也应被保留。SW=6 因而允许恢复使用 A7，却仍禁止将 A7 对外发布；DRAM 中的 A1 虽然安全，却缺少 Seq7 的合法修改，不能替代 A7。

当前 RTL 已经存在上述过程的实质数据通路：持久 SCP 存储、Checker 结果队列与跨时钟传输、位图/SW、覆盖前整行捕获及租约、SVB 到 L2 的历史保存 ACK、EVT 查询、架构寄存器恢复和 MSHR 恢复数据替换。保存 ACK、L1 ReleaseAck 和外部写回 ACK 分别确认不同的责任转移，不能互相替代。现有实现仍有明确边界：**通用的 MMIO 前切段、重放及恢复下界控制尚未接通**；历史候选是否完整、SafeBaseline 是否总能返回正确前驱、同地址版本是否始终按正确顺序对外发布，仍缺充分保证。架构恢复完成采用固定延迟契约；`rollbackQuiesced` 汇合了 LSU、DCache、Checker 等局部条件，但仍需证明未纳入等待的后台事务能够安全隔离，以及各等待条件最终能够完成。这些属于已存在链路的正确性与进展问题，文档没有把它们描述成已经解决。

我认为最值得确认五个设计选择。① **恢复候选与安全基线的边界**：推荐明确完整候选域，并让同地址对外发布保持单调，避免已释放的新值被旧基线覆盖。② **SCP 的退休条件**：推荐用“所有仍可能失败的片段都能恢复”约束退休，同时检查各地址前驱版本的存续，不能只看单个 Checker 完成。③ **旧事务与 ACK 的故障模型**：推荐冻结合法 TileLink 恰好一次语义下的保证；若要求抵抗任意重复旧 ACK，就需要更强的逐事务身份与匹配。④ **恢复完成契约**：推荐列全恢复状态、异步事件处理和各单元完成条件，再决定哪些可用固定延迟、哪些需要显式确认。⑤ **MMIO 与容量不足时的前进方式**：推荐在不可逆 I/O 之前切段并验证前驱，明确恢复下界，同时为关闭、排空和恢复保留资源；仅等待当前 Seq≤SW，可能形成“I/O 等验证、验证等片段关闭、关闭又等 I/O”的循环。以上均记录为待讨论建议，没有替你确认。

交付文档：

- [13_SingleCore_Mechanism_Walkthrough.md](/data1/gzh/EC/AI/Design/13_SingleCore_Mechanism_Walkthrough.md)：完整机制说明、A–H 分析和两条端到端时序。
- [14_SingleCore_Mechanism_Questions.md](/data1/gzh/EC/AI/Design/14_SingleCore_Mechanism_Questions.md)：按风险排序的十项问题、建议、备选方案及代码影响。

相关 Task ID：`P1-02`、`P2-03`、`P3-08/09/10`、`P4-01/06/09/11/12/13`。代表性代码证据：[结果位图与 SW](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:2809)、[恢复控制与状态导入](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2094)、[历史有效性与候选选择](/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/tilelink/PalimpsestHistory.scala:102)、[MMIO 放行条件](/data1/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/mshrs.scala:1119)。

本轮仅新增这两份文档；原有修改保持不变，未修改 RTL、配置、测试或任务状态，未执行硬件构建或仿真。已停止后续开发，等待审阅。


不要着急生成新的提示词。根据codex上述内容，简要回答几个问题。

1. svb是什么？起什么作用？
2. SW 为什么每周期最多前进一步？是因为这样实现更加简单吗？我感觉一次推进到8可能会让core跑的更快一点？
3. 缺少 Seq7 的合法修改。这个表述是不是有点问题，不用这个应该是因为同地址只用最新的，而a1老于a7。
4. 对于回滚后的内容和处理好像说的比较少，也不太详细，我不能确定是否有错误。
5. 还有没有哪些问题等待我决定和处理。
