# 独立 FPGA 会话入口（2026-11-12）

本入口属于 FPGA/Vivado/CAD 会话。CPU 替代对照、metasim 性能图和对应消费者由另一会话负责；不要覆盖其状态或启动重复任务。

唯一功能基线 `8491167d84b6d9521b151a743673c1516926a1f8`，仅允许功能与 target-cycle 等价实现。唯一设备 `0000:21:00.0`，serial `21770433G02LA`。禁止 e2、全局 XDMA/PCIe 操作、双卡和新增目标功能。原正确性、checker、输出、排空、reset 与完整物理认证门继续有效。

策略：[FPGA_SESSION_POLICY.json](./FPGA_SESSION_POLICY.json)。接管证据：[REPORT.md](./status-audits/fpga-exclusive-takeover-20261112T030000Z/REPORT.md)。

## 实际任务与自动衔接

| 路线 | 持久状态 | 实际控制服务 |
| --- | --- | --- |
| 原 SVB host40 B/C/D 物理恢复 r4 | `cycleprecise-svb-host40-shell-recovery-r4-20261112/state.json` | `ec-opt4-svb-host40-shell-physical-r4.service` |
| r4 独立认证与21卡定向测试 | `cycleprecise-original-svb-host40-shell-onboard-r4-20261112/state.json` | `ec-opt4-svb-host40-shell-follow-r4.service` |
| r4 同 bit 完整应用 SVB replay | `cycleprecise-original-svb-host40-shell-application-onboard-r4-20261112/state.json` | `ec-opt4-svb-host40-shell-application-follow-r4.service` |
| 完整 MCRams FPGATop 容量 | `Opt4-mcrams-full-host-capacity-r1-state.json` | `ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service` |
| MCRams 容量/parity → shell/物理 | `Opt4-mcrams-full-host-continuation-r2-state.json` | `ec-opt4-auto-mcrams-host-continuation-r2-3656aec4.service` |
| 完整 EC 八项优先 runtime | `fpga-priority-handoff-r1-20261112/state.json` | `ec-opt4-fpga-priority-handoff-r1.service` |
| 有界上下文监督器交接 | `fpga-unattended-r2-20261112/state.json`、`unattended-opt4/state.json` | `ec-opt4-unattended-r2.service`；等旧轮自然退出再接管 |

原 e0 综合、SVB50 r51 与 resume-r3 的正常活进程均保留。重连同时核对 PID、start_ticks、boot_id、子任务与 exact cgroup。服务 active 不能当作 FIT、认证或样本通过。

完整 EC 一旦可运行：Blackscholes → Fluidanimate → Bodytrack → Freqmine → Swaptions → Ferret → Dedup → Streamcluster，先首轮覆盖，再补第二、第三轮。保留另外五个普通 PARSEC profile，不让单项软件失败阻塞其余已就绪任务。

八项优先服务只适配原 runtime 的任务选择顺序；原软件包、源码/driver/bitstream 哈希、认证、单卡锁和有效完成条件不变。真实完整物理认证后，才释放旧 NOT FIT 8da 的 exact 空闲双 Python 等待器所持 runtime 锁。

## 证据边界

原 SVB 是组件级结果，不能作为完整 EC、完整 PARSEC 或故障回滚验证。完整 MCRams OOC 报告不包含 U280 shell；必须拼接 shell 后复核容量、布局布线和所有时钟。局部 RAM 面积与 CPU metasim 都不能代替真实 EC FPGA 测量。

完整 A 布线结果：WNS −0.416 ns、WHS +0.001 ns，零布线错误，DRC 49 项均 Warning；setup 未过，因此没有 bitstream。r4 的 B 实际失败于 Vivado 2021.1 不支持 post-route `-force_replication_on_nets`，已自动接续 C，失败证据保留。不得重复运行同一不支持的 post-route 命令。

地址单 bank 面积 Reg 57,148 LUT / 122,050 FF；MemMC 117,874 LUT / 161,277 FF / 1 BRAM。这条候选退化，不得晋升或当作完整系统优化收益。完整 ownerImage MCRams 的既有综合独立继续，以其实际全 host 报告判断。

监督器 r2 给每轮只提供关键状态的有界快照，完整原始快照仍封存在 `unattended-opt4/snapshots/full-*.json`。这样避免旧轮次中的上下文膨胀，同时保留故障诊断证据。无人值守已有作业不依赖前台进程存活；后续 AI 优化仍依赖既有模型网络连接。
