# R2 B：checker3 ownership timeout，性能比较无效

## 结论与边界

**INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT**。

B 的真实仿真已执行，Verilator process exit1；`stdout.log` 报告
`[1202000] ... BoomCore.sv:6977 ... assert__assert_24`。这是一个断言的两行报错，
不是两个独立 RTL 失败。没有 benchmark verified/checksum、软件 stop marker、ROI 或最终 cache/counter summaries。
A 已完整 PASS，ROI1,707,863；不得用 A 的完整区间与 B 的失败前缀计算收益。

这是已有功能/协议 ownership watchdog 的真实运行时触发，不是 L2 S0/shadow mismatch 报警。
但没有最终 L2 summary，所以 B 的 L2 observer correctness 仍为 **UNVALIDATED**，不能声称全部 PASS。
没有证据把本次失败归因为缓存数据损坏、SVB 容量不足或 MSHR 数量不足。

## 断言含义（源码与生成物分别核对）

- 生成物：`revisions/r2/arms/B/build/optimization_4_svb_20261030_135736_b3958002/generated/gen-collateral/BoomCore.sv:6977`。
- 映射到源码 `boom/exu/core.scala:2211`：`!little_status3(checkerHangWatchdogBit)`。
- `checkerHangWatchdogBit=ecWatchdogBit=18`，阈值为 **2^18=262,144 BOOM cycles**。
- `WideCounter(32)` 的低5位+高27位实现，使 generated `large_3[13]` 对应总计数 bit18；不能把13误读成8192cycles。
- 此 counter 仅在 checker3 `ic_status` 清零或 `clear_ic_status_tomain(3)` 到达时复位。
  它与 `CORE_WATCHDOG_SNAPSHOT` 的 pipeline watchdog 是不同断言，因此旧 hang analyzer
  给出的 `ABNORMAL_EXIT_WITHOUT_WATCHDOG_EVIDENCE` 只表示没找到那类 snapshot，不表示没有 ownership timeout。

## 保存日志的时间与事件

下表使用 SC 行的 **fields[2] global BOOM cycle**。fields[3] 是各 producer 的 local counter，
不同 observer 的 local 基准不强行混同。Verilator `[1202000]` 保留为原始 host tick，不把它充作 ROI stop。

|global cycle|直接观察|解释|
|---:|---|---|
|698,301|native start marker，requested=observed，lookup_valid1|B 的软件 ROI 起点有效；尚无终点|
|939,331|checker3 前包63生命周期记录，new_package_seq67|新包到达|
|939,333|checker3 package_seq67、start_pending1|seq67 本地接管待启动|
|939,415|package_start_accepted1；context_idle0、excpt_mode1|有 start 接受，但所采上下文不是 idle；不能从这个 aggregate 区分 privileged-start 或 running fallback 路径|
|939,417|package_check_active1|seq67 checking active|
|939,817|producer_sealed1、ECP complete1、CSR required1；exec_done0|生产端 seal/ECP 到达不等于 checker 执行和比较完成|
|1,070,889|package_progress_timeout1、package_cancelled1、package_result_fire1；enqueue payload `2<<32 \| 67`|CANCEL67 在本地 result queue 成功入队|
|1,070,891|result_queue_deq_valid1、result_outstanding1、cleanup_pending1；handoff_allowed0|本地完成/取消不是 BOOM ownership release|
|1,070,897|context_idle0、return_pending1、excpt_mode1、R_ICSL trap_depth1；checker_clear_done1；handoff_allowed0|Frontend clear ack 已到，但 context cleanup 条件仍不满足；不能归因为单纯漏了 clear ack|
|1,162,525|GHM 观测 checker1 的 CANCEL93|是另一 checker/sequence，不能误当 seq67 已释放|
|原始host tick1,202,000|assert24 / checker3 ownership watchdog|seq67 路径未闭合，进程终止|

kind13 在 seq67 起点与取消/clear 阶段的累积 accepted-response / handoff counters 均保持
14,763 / 14,730，支持该包没有新的 Frontend 检查指令交付进展。这个事实不单独证明
首个 trap、start 分支或 missing xRET 的具体触发条件。

## 证据层级

1. **Proven symptom**：checker3 ownership watchdog；软件没有完成。
2. **Proven immediate block**：CANCEL67 已入队，但本地 `context_idle` / cleanup 未闭合，result handoff gate 未开放；缺少 seq67 的 BOOM-domain release。
3. **Supported upstream trigger**：seq67 从启动后缺少 Frontend 交付进展，所录生命周期持续处于 excpt_mode；随后 no-progress timeout。
4. **Unproven root trigger**：具体 trap/start/return/privileged boundary 序列，以及 L1 geometry 改变如何使其暴露。没有本 run 的 FST，不把历史 assert24 case 的根因直接套用。
5. **Downstream amplifier**：本地取消结果被 cleanup gate 保留，ownership 继续计时；其它 checker 的取消不能释放 checker3。

源码 `rocket/RocketCore.scala:1553` 的 handoff 条件为 cleanup_done 且 !active 且 !pending，
而 cleanup 在1349行需要 context_idle、RSUSL/LSL idle、Frontend clear ack 等条件。
记录与这个阻塞链一致。不存在“本地 CANCEL 已生成，所以 checker3 已 release”的推断。

## 未实施的变化与下一步

本轮只保留 geometry perturbation、只读 instrumentation、observer 和分析工具改动。
未修 checker trap/release 策略，未放宽断言，未增加 MSHR，未改 SVB16，未启动4way或其它优化。
下一步应首先针对 **checker3 seq67 的 trap/start/return → cleanup → CANCEL handoff → BOOM release**
做独立 correctness 审查与最小验证；修复需单独界定范围。正确性闭合后才有依据重建新的同 instrumentation 成对实验。

## 复现与原始证据

- 原始 run：`revisions/r2/arms/B/runs/optimization_4_svb_20261030_135736_b3958002/`。
- 原始 stdout/stderr、`safe_chain_events.tsv`、`hang_ringbuffer.tsv`、launcher post-analysis 均保留。
- [结构化精简证据/flags解码/hash](r2_B_failure_evidence.json)。
- [输入/执行 provenance](simulation_execution_provenance.json)。
- 分析命令：`python3 -B AI/Debug/scripts/summarize_l1_causal_failure.py`。
- 没有额外执行 waveform 或纯 observation 仿真；只分析本次已保存的 bounded evidence。

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

L1 miss reduction → critical-path cycle reduction：**NOT YET PROVEN**。
