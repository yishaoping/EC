# 原版 SVB 昨夜故障与实际恢复（2026-11-12 09:23 CST）

两条原实现都完成全部布线并保留 routed DCP，但未通过时序。原版 WNS −10.999 ns / WHS −0.084 ns；spread WNS −2.010 ns / WHS +0.001 ns、0 routing errors。尚无认证 bitstream、尚无 FPGA 样本。

spread 的最坏目标路径 line_1_reg[14]→depthHistogramReg_1_reg[32]/CE 包含 64 层逻辑，21.753 ns 数据路径中15.272 ns（70.2%）为布线延迟。shell 自身还有 XDMA、AXI、MIG 路径时序失败，不能只检查目标时钟。

旧四个 strict-r2 恢复均因 load<48 守卫在启动 Vivado 前失败，并不是四次物理候选试完。r51 安全恢复后真实运行 spread post-route 优化，历时约3小时，WNS −2.010→−1.373 ns，WHS保持+0.001 ns，physical-1 DCP已保存。随后工具实际拒绝 -preserve 与 -directive Explore 组合。spread replicate 则因 net 查询未得到预期两条 activeIdx net 在真正复制前退出。所有失败原件保留。

本轮已实际提交并由 broker 启动 svb-physical-resume-r3-v1-8491167d，在独立 CPU252–253 /64GiB 进程中复用已优化 physical-1 DCP，并移除不兼容的 -preserve 参数。它立即从已有物理优化继续路由，保留19.998ns目标时钟及完整时序/DRC/全布线门，增加bus-skew审计，不重复原DUT综合或三小时physopt。r51 original-postroute活作业在254–255继续，不终止、不改输入。

新作业 controller2377491/start25815868，状态 `Opt4-svb-physical-resume-r3-state.json`。真实输出在 `cycleprecise-svb-postroute-recovery-r1-20261111/resume-r3-spread-physical1/`。成功才提交 chosen-result，原独立认证和21-only组件/应用replay follower后继继续检查。当前只确认实际启动，未称已完成路由、生成bitstream或上板。

唯一功能基线8491167d，source_id b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f。本子任务无任何 FPGA、JTAG、驱动、PCIe 操作。

## Exact activeIdx physical-query recovery and follower audit

2026-11-12 01:34 UTC: the new read-only pin query completed successfully against the sealed real spread physopt DCP (140.8603s). The two exact original sequential cells drive nets `dut/activeIdx_reg[0]_0` (FDRE,5794 leaf loads) and `dut/activeIdx_reg[1]_0` (FDSE,5774 leaf loads). The old glob matched3332 nets and could not identify the intended pair. Exact NAME equality plus Q-pin, FD primitive and leaf driver checks are now independently verified. Raw probe and TSV: `../cycleprecise-svb-activeidx-pinquery-r1-20261112/`.

A new versioned r4 CPU recovery request waits for the r51 service and its exact cgroup to be empty before replacing CPUs254-255; r3 continues252-253. It preserves both active jobs, the unchanged 128GiB/96GiB/load48 guards and all original source/19.998ns clock gates. It corrects both the overbroad net query and the Vivado preserve/Explore incompatibility. No third component route or FPGA access is allowed. Broker initially deferred it because the eight ordinary synthesis slots were occupied; the immutable request remains pending for automatic retry. State: `../Opt4-svb-physical-pinreplicate-r4-state.json`; request: `../unattended-opt4/requests/svb-physical-pinreplicate-r4-v1-8491167d.json`.

`r3-follower-schema-audit.json` passed14 current-source/sealed-checkpoint/producer-state/final-gate-order/schema checks and the live follower `--offline` binding test. The final checkpoint, bus-skew report and bitstream hashes will be bound into the immutable result and independently certified before any deployment. This is compatibility evidence, not final timing/bitstream certification. No bitstream or FPGA SVB measurement is claimed at this stage.
