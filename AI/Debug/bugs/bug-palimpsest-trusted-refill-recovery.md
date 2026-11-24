# 冷恢复候选覆盖可信主机更新

状态：V1 的 13 项定向回归通过，但新增 SW/Grant 反例已推翻本地 SW 分类规则。V2 响应证书已实现，13 项定向回归通过；整核 Fault8 尚待完成。

修复前生产 RTL 的真实 Hierarchy 对照也已失败：
`AI/TMP/singlecore_checker_20261122_082540/host_hierarchy_before/run_hierarchy.log`
在 cycle 1156 报告 `cold recovery replaced trusted fromhost response with archived bytes`，
当时 SW=3、epoch=1。该模型使用 `sources.before.json` 中的硬件；
构建期间工作树继续演进导致 driver 的最终 before/after 比较失败，原失败保留。
实际 host 激励另存于 `host_stimulus_v2.cpp` 和对应 SHA256，不能用当前工作树
或该目录的 sources.after.json 代替它的硬件输入。

## 证据边界

旧模型来自 `AI/TMP/singlecore_rtl_20261121_171154/sourcec_full_PalimpsestFault8Config`，
其源码清单独立保存。详细 RTL 日志位于同一归档的
`sourcec_direct12_PalimpsestFault8Config_fastlink_compact/run.log`。
只读 HTIF link-wrap 复跑位于
`AI/TMP/singlecore_checker_20261122_082540/fault_host_trace/`，
含 `trace.cc`、`trace.mk`、`inputs.sha256`、`trace.log` 和 `run.exit`。
探针使用 `sc_time_stamp()`，下表为 emulator 系统周期，不能当作退休周期。

| 系统周期 | 主机事务 |
|---|---|
| 497234 | 读取 tohost=`0x80032d50`，发起清零 tohost |
| 498731 | 已完成清零后，读取 syscall buffer，编号为 64、长度为 125 |
| 500556 | 输出 RESULT，并将 syscall buffer 首字改为返回值 125 |
| 501441 | 发起 fromhost=1 |
| 501822 | fromhost 写已完成后，再次读到原 tohost 指针，发起清零 |
| 502404 | 读回 syscall buffer，首字为 125，随后 `bad syscall #125` |

独立的详细旧轨迹显示：SW 已到 Seq35；Main 最后一次 tohost store 仅产生一次
`STAGE2_TX MODIFY ... new_seq=00000023`。此后冷查询多次返回同一
`Seq35/serial1/data0=0x80032d50`，并多次 IMPORT 该行。slot epoch 的变化不是新 rollback。

## 根因与修复原则

直接症状（已证实）：主机第二次看到已经处理过的 syscall 指针，返回值被作为编号执行。

阻塞/错误条件（源码及旧日志支持）：DCache 在查询完成后无条件用候选整行和 key
替代后来取得的一致性 refill；MSHR 也在取得 Grant 前锁存该候选。查询与 Grant
之间，History 可以完成安全发布，主机也可以完成后继 Put。候选不代表之后的
一致性所有权，不能重新覆盖可信写。

V1 将候选选择放在 MSHR 首个 Grant 的实际 fire，但用 Main 本地 SW 分类仍有竞态。
V2 在 L2 选择 SourceD 响应时分类候选，将一位证书随响应冻结；Main 首个 Grant
fire 按此证书选择。安全历史通过 L2 发布顺序进入一致性基线，采用真实 Grant。
选择结果复用已有 `recoveryActive/recoveryData` 保持到 install/replay 结束。
DCache 不再第二次覆盖已由 MSHR 确定的 payload/key。

配套收紧 Scheduler 的 D 准入：`publishPending` 在 preservation 持有其他 set
期间仍然阻止响应越过安全历史。原有 Probe、外存 Grant/E 和 baseline receipt
drain 继续完成，不新增全局队列或扫描器。

验证使用长期 Hierarchy 夹具新增的独立普通 TL host client，覆盖主机 Get、
清零 tohost、更新 fromhost，以及 Main 冷查询后暂时撤回重试的真实并发。
最终必须检查 fromhost=1 和 tohost=0，另保留 Pending7 的 Figure4 等旧用例。
定向 PASS 不能替代 Fault8 整核 END/正常退出。

## 定向验证

`AI/TMP/singlecore_checker_20261122_082540/rtl_regression_v1/` 的 sources.before/after.json
完全一致，driver exit=0。Hierarchy 两个用例实际通过：查询时 Seq3 已安全；查询先
返回 Pending3、暂停 LSU 重试后推进 SW，再等待主机写完成。两者都读取 fromhost=1，
并从独立 host 读取 tohost=0。轨迹可见旧 Seq3 候选被查询到，但最终 IMPORT 采用
真实 BASE；未重新贴回指针。其后原有 Pending7、AMO、慢 Checker、迟到 owner
以及 34 次维护仍通过。`directed_results_v1.json` 列出全部 13 项结果。

## 第二个 first bad：SW 在 Grant 排队后推进

`AI/TMP/singlecore_checker_20261122_082540/grant_sw_before_v2/run_hierarchy.log`
实际失败 cycle1037：`SW advancement after Grant offer discarded the surviving predecessor`，
SW=8、epoch=1。先令 SW6、Pending7=A7、Seq8=A8，FAIL8 后分配9；冷请求进入
MSHR 并完成旧 ReleaseAck 后，gate 扣住已出现的 Grant。此时再 pass7，等待 SW
推进至8，放开 Grant，V1 返回旧 BASE，丢失 A7。精确激励与哈希是归档中的
`grant_sw_stimulus_v3.cpp/.sha256`；来源差异见反例目录 provenance_note.md。

根因已动态证实：Grant 选择时 L2 仍按 SW6 处理，Main 接收时的 SW8 不能证明
该 Grant 已包含 A7。跨域 SW 延迟也遵循同一边界，不能靠 Main 的宽比较修复。

V2：Acquire 的 CacheImage 只传候选身份。L2 MSHR 输出 recoverySeq，Scheduler
用选中 MSHR 和 bank SW 做一次比较，SourceDRequest.recoverySafe 随现有流水冻结。
SourceD 将其作为 D.CacheRecoverySafe；L1 使用证书，移除 recoverySafe 本地输入。
保留 publishPending D 屏障，多拍证书一致和缺失证书 assertion。该 hint 不改变
目录 key。无新队列、FSM、per-line 标签或整行副本；增加一位响应流水元数据。

V2 验证在 grant_sw_v2 与 components_v2，两个 driver 均 exit0，所有 before/after 源码清单和 sources_v2.json 完全一致。directed_results_v2.json 记录 13 项 PASS，无 assertion/UNCOVERED。watermark_after_grant_offer、两个 host 用例以及原 Figure4/AMO/慢 Checker/维护全部通过。V1 的历史记录保留独立边界；三个 V2 整核尚在执行。
