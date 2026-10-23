# EC Baseline 软件 ABI 仿真前核实

日期：2026-10-23（Asia/Shanghai）。审查方式：只读源码、Git 历史、ELF/现有 dump、loadmem 与 manifest；没有编译、生成硬件、运行启动器、仿真或 workload。

## 决策

**[STATIC_INFERENCE] 最终分类：`BLOCKED_BY_SOFTWARE_ABI`。**

**当前不能把已保存 fixed_candidate 作为“通过条件明确、可正确判定成功”的 Baseline smoke 配置启动。** 这不是 ELF 格式错误、timer flag 必须回退、或缺少 R-Kernel：格式与软件身份已经静态核对，关键启动/监测指令有历史接口，但完整候选还强制依赖 b3 不提供的 Current 统计/有效位 ABI。

[DIRECT_EVIDENCE] b3 的 custom1 GHE 没有 funct 0x7B 分支，返回 MuxCase 默认 0，且 cmd.ready 恒真、带 xd 的命令产生 response；候选 ELF 确实执行这些读取。report_end 要求 cross-package、L1-L2、L2-DRAM 的 stats_valid 都等于 1。

[STATIC_INFERENCE] 因而**如果到达 report_end**，候选会把历史硬件返回的零判为 PACKAGE_DRAIN_HARD_ERROR，最终软件 verdict 为 FAIL。不能因此断言 BFS 一定不能运行或一定会挂；也不能把这些零当成“drain 已空”。main 仍返回 0，所以 HTIF/harness PASSED 也可能和软件 FAIL 同时出现。

## 用户要求的结论

| 问题 | 结论与等级 |
|---|---|
| 软件身份是否已固定？ | [DIRECT_EVIDENCE] 两份 ELF、候选 loadmem/dump 已核对；候选 manifest 的 40 项源/链接输入哈希全部匹配。见 binary_evidence.json、preservation.before.json。 |
| timer flag 修复能否用于 Baseline？ | [STATIC_INFERENCE] 可以作为共同的软件布局；普通可缓存 DRAM 中每 hart 64-byte 槽，无 Current 专用 MMIO/协议依赖，不改变计数含义或 BFS 算法。保持该修复；不承诺修复所有运行时问题。 |
| 是否需要 Software/R-Kernel？ | [STATIC_INFERENCE] 运行这两份已存在的静态 HTIF ELF 不需要。历史 gitlink 缺失影响该内核自身的身份/重建，不是这些 ELF 的主要运行阻塞。 |
| 能否现在使用相同修复 ELF 完成公平比较？ | [UNRESOLVED] 共同 workload 和 rdcycle 边界已可定义，但当前候选的完整验收 ABI 已知不兼容；尚无通过共同完成/drain 合约的同一软件产物。当前状态为 FAIR_SOFTWARE_COMPARISON_BLOCKED；不表示未来同一二进制方案不可能。 |
| 是否已缺少计时边界？ | [DIRECT_EVIDENCE] 软件 ROI 的两处 rdcycle PC 明确；缺的是可共同验收的结束/drain 语义，不能以 harness 总 cycles 代替 ROI。 |
| 现在能否开始 smoke？ | [STATIC_INFERENCE] 暂不能按本次任务定义批准当前候选；没有生成 REVIEWED_FOR_BASELINE 的可运行描述。 |
| 最小缺失条件？ | [UNRESOLVED] 需要一个可核验的共同软件验收合约/对应产物：保留 64-byte flags、相同 AMO+BFS 和 ROI，将不支持的观测项明确标记“不适用”，使用 b3 实际支持且可验证的 checker 完成与退出条件；不能把缺失 valid 伪造为 1。还需说明 Baseline host-success 后的 drain 验收依据。 |
| 是否恢复旧软件布局或直接换历史 ELF？ | [STATIC_INFERENCE] 不采用。历史 ELF 是混合指令刺激，非 AMO+BFS-512，且 flags 紧密排列；直接替换破坏共同 workload 条件。 |

## 文件

- software_abi_review.md：历史软件、ABI 差异表、timer 修复、R-Kernel 结论。
- timing_exit_contract.md：START/STOP、三个 interval、计时指标、退出/drain 与未来参数契约。
- baseline_workload.proposal.json：已确定字段和阻塞原因；故意保持非 REVIEWED 状态，不能直接用于 --run。
- evidence_index.md：源码路径/行号、Git、命令与证据边界。
- binary_evidence.json：现有 dump 与 ELF 的逐指令字节核对、custom1 位置和 loadmem 检查。
- preservation.before.json / preservation.after.json：保护对象哈希、Git/index 和 build/runs/tmp 状态。

[UNRESOLVED] `RUN_PROVENANCE=UNRESOLVED`。本轮没有新运行；源码、既有二进制、潜在生成模型/仿真器身份不能合并成已验证的运行身份。

本轮完成报告后停止；不修改启动脚本、现有软件描述、Current、Baseline 源码，不恢复或编译 R-Kernel。
