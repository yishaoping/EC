# PALIMPSEST 冷地址查询结果跨 LSU 重试空窗

Fault8 整核紧凑激励已完成 SCP8 restore 和 Restart，随后分配 Seq10。对 `0x80008300`，L1 收到匹配的 ReleaseAck 后反复开始 cold lookup。该运行最后超过 350000 拍。证据见 `AI/TMP/singlecore_rtl_20261121_171154/final_rtl_PalimpsestFault8Config_fastlink_compact/run.log`，恢复阶段在 978009 行附近。

同一功能在生产 DCache 和 L2 的 Hierarchy 模型中可独立复现。请求在地址查询触发后停发 800 拍，恢复请求后 `0x80001000` 出现第二次查询。反例位于 `hierarchy_cold_gap_before/fast_run.log` 第 79、95、105 行。该日志的模型来自 `amo_svb03`，定向激励单独记录在 `hierarchy_cold_gap_before/fixtures.sha256`。

第一处错误是 DCache 在 `recoveryMiss` 中将请求空拍当作查询结果的结束。BOOM LSU 每拍重做仲裁，初次触发查询的源可能暂时丢失 valid。正确的结束事件是同址安装、不同冷地址在 owner 空闲后接替，或 stop 接管已经排空的旧尝试。停核时仍发出的存活前缀 store 可继续消费匹配的结果。外部 C/D owner 仍以原始握手释放。

定向用例 `coldRecoveryWithRetryGap` 要求同一次冷访问只有一个查询，返回存活的 Seq7，且外存仍为安全 Seq1。整核验收另需正常、Fault8 的最终字节和寄存器 oracle。

## 2026-11-22：不同冷地址接替中的仲裁活锁

V1 Fault8 在正确的 `PALIMPSEST_WORKLOAD_RESULT` 后仍无 END。只读 `eval_step`
探针观察到 `recoveryLine=0x80032d80`、`recoveryFound=0`，缓存和 MSHR 已空闲，
但冷查询反复执行，S0 一直没有接受请求。该探针只读归档模型，不改变请求或状态。

`AI/TMP/singlecore_checker_20261122_082540/cold_handoff_core_evidence.json`
保留原模型清单及事件表。以同一探针的模拟器 tick 为单位，一段重复链为：

| tick | 状态及输入 | 含义 |
|---|---|---|
| 513266 | Lower(3)→Miss(7)，查询结果为空 | 查询和各域ACK均已结束，可进行正常一致性访问。 |
| 513267 | Miss(7)→Idle(0)，valid=1、stale=1、同址=0 | 另一个冷请求使已完成结果被丢弃。 |
| 513268 | Idle(0)→Query(1)，同址=1 | LSU重新仲裁回原地址，又发起相同查询。 |
| 513380–513382 | 同一状态链再次出现 | 没有请求进入S0，重复不是正常的多次缓存缺失。 |

直接阻塞条件和触发链均已证实。LSU的未被接受offer可以重新仲裁，DCache的
一拍Idle交接会重新选择地址，不能把临时选中的另一个地址视为已持有的事务。
未发现外部ACK或历史扫描丢失；每轮查询实际都完成。

未修改的V2真实层次模型也复现：`cold_handoff_before_v3/run.log` 在cycle8665
失败，8000拍内发起51次空查询且没有接受请求。激励只读内部状态来放置精确
交接窗口，不写内部状态；源码、模拟器及库哈希单独保存。

V3 DCache复用现有 `recoveryLine`、查询payload和FSM，由 `beginColdLookup()`
在当前Miss拍直接捕获接替冷地址并开始查询；存活驻留行沿原规则刷新CurGen。
停止旧尝试仍回Idle，空valid间隔仍保留原结果。没有新增寄存器、队列、状态或行副本。
长期 `alternatingColdHandoff` 同时要求接替访问和原冷地址完成，并核对实际字节。
V3 Scala 编译和全部 Chisel/FIRRTL 生成通过，13 项定向测试全部通过，生成前后
源码清单完全一致。原会话没有保留 driver 的 PTY 退出结果，故在
`reviewed_v3_components/` 仅重跑已编译模型，13 个程序均记录 exit0，
没有 assertion/UNCOVERED；没有重复生成或编译硬件。

交接用例输出 `COLD_HANDOFF lookups=3 active=0 issuing=0`；这包含原地址首次查询、
接替地址查询及完成接替后对原地址的访问。另在 `cold_handoff_distinct_v3/` 用
0x1111 和 0x2222 区分两地址的实际基线，整套 Hierarchy 同样 exit0，排除仅因
两地址默认字节相同而掩盖结果错配。该补充输入及模拟器/库哈希独立保存。

正常、Fault8、Seq16 的 V3 整核构建与运行由 `run_fullcore_v3.py` 接续。
尚无修复后的整核完成结论；V1/V2 的诊断或组件 PASS 均不替代该验收。
