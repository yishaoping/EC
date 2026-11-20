# EC Performance-Only：保护当前 routing，按实际失败网络筛选既有候选

2026-11-16 晚，本轮不修改 SVB/MSHR/Chisel，不增加 40 位关系缓存，不运行第二个
Vivado。当前仍为原 SSI_SpreadSLLs、host 99.960ns / DDR 3.332ns。

有界只读检查确认节点重叠从 384 继续下降：262、176、126、91、69。
两次采样间 CPU 时间增加 555.37 秒，日志持续更新，没有停滞证据。
这些是 routing Phase 4.1 中间计数，不是完成率、冲突网络数或最终合法性。
尚无 post-route timing / route-status，也尚无 bitstream。

最近有效 timing 属于本轮 post-phys-opt：WNS +0.377ns、TNS 0、WHS -0.612ns、
THS -1894.950ns、17273 个 hold 端点。这些是布线前估计，不代表最终 hold。
原 run.tcl 已有合法路由门槛、post-route hold fixing、setup/hold/DDR/clock-group/
DRC/methodology 严格门槛和 write_bitstream。原 21-only pidfd 认证接续进程仍存在。
未修改原控制器或上述任何实际约束。

## 补齐既有筛选证据

七个原定成对模块综合仍在等待当前 CAD 和失败 DCP 独占诊断退出。没有模块
实际 LUT/FF/MUXF 数值可以报告。SVB＋MSHR balanced 完整 Golden Gate 已完成，
不重复运行。

`module-cones.tcl` 补充保存实际映射 primitive Verilog、关系状态 reset driver
类型；常量 GND reset pin 与功能性 reset broadcast 区分。保留原派生状态 Q、
CE、D 连接、key 源 fanout、目标控制网络、min/max 路径、MUXF 逻辑锥。

新增 `mapped-screen-summary.py` 从**已测报告**统一统计 LUT、FF、MUXF7/8、
LUTRAM、BRAM、URAM、CARRY8，以及新增状态和 enable 的实际映射成本。
报告缺失时用 null/缺失，不记作 0。模块 min/max 为未布局筛选估计，不作 signoff。

该汇总要求本轮 SSI_SpreadSLLs 最终 route status 与恢复 DCP 的冲突数一致，
再统计其与 SVB、MSHR/installArb、FTQ/trace 直接连接的冲突网络。
组间可重叠；connected-module 标签不冒充已经证明的原始 Chisel 因果归属。
若恢复证据缺失或不一致，禁止自动新物理实现，保留待分析状态。

## 调整自动准入：优先真实网络收益

此前 r5 的“控制 LUT 至少降 10%”硬门槛取消；纯 LUT 减少不再作为物理改善证明。
现在要求：

- 实际第二轮失败网络仍直接涉及目标 SVB 逻辑。
- 映射后 key 源扇出下降至少 20%，或目标宽算术结构至少减少 512 个 CARRY8。
- 新增关系状态和 CE 负载在保守界限内，LUT/FF 增长有界、不增加 RAM。
- 分配译码复用必须有实际目标网络改善；仅源码更短或 LUT 少一点不自动采用。
- MSHR 候选必须消除实际 MUXF 驱动、输出变为可复制 LUT，且本轮剩余冲突
  涉及 install 逻辑，未布局 setup 估计未显著恶化。没有收益不强行合并。

无论 SVB 是否被接纳，已完成的 MSHR 与分配译码候选筛选结果均保存；不为凑
迭代轮数新增 RTL。任何候选完整 shell 的资源必须实测，不累加模块节省。

本轮只替换尚未持 CAD 锁、没有子进程的末端等待筛选控制器，使它加载上述
新准入规则；保留旧控制器状态与 PID 证据。原 Vivado、两把锁、上游诊断与
模块综合等待进程均不触碰。仍用一次 pidfd 完成事件等待，没有周期巡检。

当前版本若成功：所有后续筛选跳过，原 bitstream/21-only 认证优先。
当前版本若失败：先全量 DCP 取证、实际模块筛选；只有证明相关热点改善的组合
才进入完整 shell post-opt 和一次新网表物理实现。不得自动重试原网表第三种策略。
