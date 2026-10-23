# 共用 ROI、计算正确性与退出

## 性能定义

[DIRECT_EVIDENCE] 共用 `test.c` 的执行顺序为：

```
GHT/filter/map/mask、interrupt/timer/setup
hart0 shared observer RESET/clear、START/clear（不是主计时）
monitor START funct31
checking START funct70 rs1=1
common_roi_start: rdcycle（hart0）
  AMO.W 自测
  gapbs_bfs_run_512（含建图、BFS、原验证、汇总）
  result.verified &= amo_ok
  checking STOP funct70 rs1=2
  26 次 NOP C 循环（含循环控制，不是固定26 cycles）
  monitor STOP funct32
  GHT funct06 rs1=rs2=0，等待 status >= 0x1ffff
common_roi_stop: rdcycle（hart0）
打印 computation result；等待4个 checker software ready
hart0 shared observer STOP/clear；打印 ROI、completion、PASS/FAIL
unset monitor context、funct30
return 0/1 -> finite HTIF _exit
```

[STATIC_INFERENCE] 保留候选的统一 **AMO+BFS+STOP/session-completion** 边界，而不是另选 BFS-only 边界。ROI 内不读取 0x7B/0x79/0x55，不作硬件版本选择，不输出报告。checker 仍可能在期间运行必要 replay、timer 和 completion store，但没有旧统计 snapshot 循环或 Current-only START/STOP 高位命令。

[DIRECT_EVIDENCE] 旧 PC `0x80000368 -> 0x800003d4` 只对应 f5f84a17... ELF。新 PC 由未来链接后 `common_roi_start/stop` 的符号和实际 rdcycle 指令记录，不沿用旧地址。builder 检查符号唯一、起止顺序、CSR0xc00/CSRRS rs1=x0 编码，拒绝 ROI 内的 0x76 observer 命令；实际指令/边界仍需首次编译后的人工复核。

## rdcycle 的两版语义

[DIRECT_EVIDENCE] b3 `rocket/CSR.scala:699-703,847,864,1364` 与 Current `CSR.scala:773-777,921,938,1451` 均以同一 reg_cycle 映射 cycle/mcycle。`tile/Core.scala:140` 的 enableCommitLog=false；normal 分支在 ungated_clock 且 !csr_stall、!mcountinhibit(0) 时计数。csr_stall=reg_wfi || status.cease。BOOM `exu/core.scala` 的 ungated_clock 分别在1421/1453连接 clock。

[STATIC_INFERENCE] 同一 BOOM hart0、相同配置下可用该 CSR 差值；普通 ROB/memory stall 并不是上述 CSR 停计条件。timer interrupt 时间自然计入差值。共用 ROI 没有 WFI、CEASE 或 mcountinhibit 写入。最终 simulator 必须确认这些源码身份和生成配置，不能从源码直接推断某个既有二进制。

[UNRESOLVED] 两版最终生成模型、frequency/clock ratio、CLINT timebase、实际 counter inhibit/WFI/cease 状态和运行身份尚未验证。正式实验应记录这些条件；不能把 cycle 差转换为时间或跨时钟域直接相加。

## 三个不同的完成条件

| 层级 | 共同判断 | 能证明什么 | 不能证明什么 |
|---|---|---|---|
| computation | AMO.W checks、BFS原 verified=1、nodes512/source0/reached512/edges8192；两版 parent_checksum 和其他结果字段一致 | [STATIC_INFERENCE] 两版相同工作下的共同 architectural self-check | 未独立证明完整最短路径性质或每个 checker package PASS；当前未运行 |
| ROI | 一个 hart0 `[ROI] start=... stop=... cycles=...`；stop>start；cycles严格等于差值 | [DIRECT_EVIDENCE] 主计时口径，禁止缺失、重复、其他hart、算术不一致 | 不是退出 drain、所有事务完成或可避免等待的证明 |
| process/completion | 所有 checker software ready、无 ERROR/FAIL、tohost 退出、simulator成功 | [STATIC_INFERENCE] 软件尾部通过且仿真器正常终止 | release/session bit/ready不等于逐包结果释放、cache/L2/DRAM drain |

[DIRECT_EVIDENCE] 新 main 不再无条件返回0。所有计算/边界检查成功才打印 computation PASS 和 `[END] hart=0 status=PASS`；否则返回1，finite `_exit` 编码 `(code<<1)|1`。报告文字没有把 package statistics 删除后的空检查叫成协议 PASS。

[DIRECT_EVIDENCE] `common_benchmark_contract.py` 统一 PASS/failure patterns，解析一个 result 和一个 ROI，保留 parent_checksum。启动器同时要求 simulator rc=0、唯一 harness成功计数、所有必需 marker 和无 failure marker。synthetic parser 校验不是 workload 执行，也不产生真实 cycles。

[UNRESOLVED] 必须另外审核运行日志/断言/既有观测确认 checker 和硬件保护机制无错误。b3/Current GHE 所查 0x66 默认返回0，ELU 软件轮询不能充当完整检错通过的证据。有限 self-check 的成功不应升级为完整恢复/保护机制正确性声明。

## harness exit/drain 与主指标

[DIRECT_EVIDENCE] 历史 emulator.cc 的 host success 路径不等待 post-exit cache drain。Current 在生成编译启用 STAGE1_EXIT_PORTS 时等待 stage1_l1_drained；否则也走 host success。该状态不是全系统 L2/DRAM drain。它们发生在软件 ROI 之后，保留原实现，不以补常数、加 cycle 修正或假 valid 来抹平差异。

[STATIC_INFERENCE] 统一报告 `ROI_cycles = stop-start`，harness Completed cycles 仅辅助。**主指标不含退出后的 drain，但 ROI 内仍包含因硬件保护/资源/必要 checker 进展造成的真实等待**；本轮未缩短那些等待，也未关闭 barrier。

## 未来公平比较的接受条件

1. 完全相同的 ELF SHA256、loadmem SHA256、软件 build manifest 和 workload 输入；只构建一次，不按硬件分别编译。
2. 两边相同 hart 拓扑、cacheline64、内存/DRAM配置、clock ratio、CLINT timebase、seed及重置/启动策略；硬件revision与生成器身份分别记录，不强行宣称全部参数本来相同。
3. 两边使用新 ELF 的同一 start/stop PC、同一 ROI scope，无版本分支。保持 timer delta/limit/布局，不人为补偿中断次数差异。
4. 共同 computation PASS、相同所有 result 字段（包括 checksum）、无错误断言，日志及manifest身份闭合。若不同或未完成，不报告有效 slowdown。
5. 单独记录 total simulation cycles、exit/drain语义、超时。每次使用fresh reset；GHE bigComp 为锁存状态，不能在未复位 simulator 内把重复 ROI 当独立实验。

在满足这些条件之后，才计算 `(ROI_current - ROI_baseline) / ROI_baseline`。本轮不提供任何净开销数值，也不从旧 FST 区间估算新共用软件性能。
