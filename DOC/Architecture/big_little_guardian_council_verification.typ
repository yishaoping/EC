= 大核/小核验证机制架构总结

本文根据 `/home/gzh/EC/chipyard/generators` 中的硬件代码整理，重点覆盖 EC 自定义的 GuardianCouncil 大核-小核验证机制。标准 Chipyard 中的 Dromajo/Cospike 属于仿真 harness 参考模型对比，和这里的大核/小核硬件协同校验是两条不同路径。

== 1. 总体结论

当前 `v0Config` 采用“1 个大核 + 多个小核 checker”的 checkpoint-and-replay 验证框架：

- 大核：hart 0，`Large BOOM`，负责正常高速执行、切分检查窗口、产生检查包、保存/转发上下文。
- 小核：hart 1..N，`GCChecker`，本质是裁剪配置的 Rocket core，负责从大核检查点恢复上下文，然后重放大核片段并进行 load/store/CSR/branch/寄存器状态校验。
- 控制入口：`GHE` 作为 RoCC 挂在各 tile 上，软件通过自定义 RoCC 指令配置、启动、查询状态。
- 事件过滤/打包：BOOM 大核使用 `GH_BUF`，Rocket 大核路径使用 `GHT`。在 `v0Config` 中实际使用的是 BOOM hart 0，因此主路径是 `GH_BUF`。
- 跨核传输：`GHM` 负责大核到小核的数据包、ARFS 上下文包和双向控制信号 CDC。
- 聚合反馈：`GAGG` 聚合 checker 状态和 fault-injection 结果，目前大部分聚合 packet 路由仍是 tie-off，主要有效功能是 checker 空闲状态归约和 `fi_d` 汇总。

核心思想不是 cycle-by-cycle lockstep，而是：

1. 大核运行到检查窗口边界。
2. 大核把当前 architectural state 快照发给某个 checker。
3. 大核继续执行，并把该窗口中的关键不可重复事件打包发给 checker。
4. checker 从快照开始重放，使用大核提供的 memory/CSR/branch 结果约束非确定行为。
5. checker 执行到窗口结束后，上报完成/拥塞/错误状态。
6. 大核根据 checker 状态进行清零、切换 checker、反压或继续执行。

== 2. 配置入口

主配置在：

`chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala`

关键配置为 `v0Config`：

- `WithTileFrequency(200, Some(0))`：hart 0 大核运行在 200 MHz。
- `WithTileFrequency(100, Some(1..3))`：checker 小核运行在 100 MHz。
- `WithGCBusFrequency(100)`：新增 GuardianCouncil bus 使用 100 MHz。
- `WithSystemBusFrequency(200)` / `WithMemoryBusFrequency(200)` / `WithPeripheryBusFrequency(200)`：常规系统总线频率。
- `WithGHE`：向 `BuildRoCC` 添加 `GHE(OpcodeSet.custom1)`。
- `WithDisableROBDebug`：关闭 BOOM ROB debug。
- `WithAsynchronousRocketTiles(...)`：Rocket checker tile 采用异步 crossing。
- `WithNLargeBooms(1, overrideIdOffset = Some(0))`：hart 0 为 BOOM 大核。
- `WithNGCCheckers(GH_NUM_CORES - 1, overrideIdOffset = Some(1))`：hart 1 起实例化 checker 小核。

`GH_GlobalParams` 定义全局规模：

`chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`

- `GH_NUM_CORES = 5`：总共 5 个 hart，约定为 1 大核 + 4 checker。
- `GH_TOTAL_PACKETS = 2`：每次最多输出两个检查包。
- `GH_WIDITH_PERF = 64`。
- `GH_WIDITH_PACKETS = 2 * 64 + 8 = 136`：每个包为 8 bit header + 128 bit payload。
- `IF_THERE_IS_CDC = true`：默认存在跨时钟域。

checker 的配置在：

`chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala`

`WithNGCCheckers` 使用 RocketTileParams 实例化小核：

- `useDebug = false`。
- DCache：`nSets = 32`, `nWays = 2`, `nMSHRs = 0`。
- ICache：`nSets = 64`, `nWays = 8`。
- hartId 从 `overrideIdOffset` 开始分配，在 `v0Config` 中是 1..4。

== 3. 顶层模块关系

新增模块挂载在：

`chipyard/generators/chipyard/src/main/scala/System.scala`

`ChipyardSystem` 中：

- `GHMCore.attach(..., SBUS)`：GHM 挂在 subsystem 中，逻辑时钟使用大核 tile clock，内部按每个 tile clock 建 `AsyncQueue`。
- `GAGGCore.attach(..., GBUS)`：GAGG 挂在新增 `GBUS`。

新增 bus 在：

`chipyard/generators/rocket-chip/src/main/scala/subsystem/BusTopology.scala`

- 新增 `GCBusKey`。
- 新增 `GBUS extends TLBusWrapperLocation("subsystem_gbus")`。
- `HierarchicalBusTopologyParams` 新增 `gbus` wrapper。当前 `GBUS` 只实例化，不和 PBUS/CBUS 建 TL 连接，主要提供 clock/reset 域给 GuardianCouncil 聚合逻辑。

== 4. BundleBridge 信号网络

tile 层新增 GuardianCouncil 信号在：

`chipyard/generators/rocket-chip/src/main/scala/tile/BaseTile.scala`

subsystem 收集节点在：

`chipyard/generators/rocket-chip/src/main/scala/subsystem/HasTiles.scala`

`connectGHSingals` 中按 hartId 区分：

- hart 0：连接大核 GHT/GH_BUF 输出、IC 计数、checker 反馈、反压输入等。
- hart != 0：大核侧 GHT 输出被 tie-off；checker 侧的 GHE packet/status/event、ARFS、CDC empty、LSL/ICSL 状态等接入 `GHM/GAGG`。

主要 BundleBridge 信号如下。

大核到 GHM/GAGG：

- `ght_packet_out_SRNode`：大核输出的检查包，宽度 `GH_TOTAL_PACKETS * GH_WIDITH_PACKETS`。
- `ght_packet_dest_SRNode`：目标 checker bitmap/status，GHM 实际路由主要从 packet header 中解析目标。
- `core_r_arfs_SRNode`：大核 ARFS/FARFS/FCSR/PC 快照包。
- `ic_counter_SRNode`：每个 checker 对应的指令计数窗口。
- `debug_maincore_status_SRNode`：主核调度状态。
- `ghm_agg_core_id_out_SRNode`：聚合目标 core id，目前 BOOM 路径固定为 0。

GHM/GAGG 到大核：

- `bigcore_hang_in_SKNode`：GHM 反压，表示 CDC 或 ARFS FIFO 不可接收。
- `bigcore_comp_in_SKNode`：checker 完成聚合结果。
- `debug_bp_in_SKNode`：调试用反压来源，bit 1 表示 CDC，bit 0 表示 checker。
- `sch_na_inSKNode`：scheduler no-available 信息，当前 GAGG 输出基本为 0。
- `debug_gcounter_SKNode`：GHM 统计发送到 checker 的 packet 次数。

GHM 到 checker：

- `ghe_packet_in_SKNode`：下发给 checker 的检查包，额外带 1 bit 标志。
- `core_r_arfs_c_SKNode`：下发给 checker 的 ARFS 上下文。
- `ghe_status_in_SKNode`：从主核/调度传来的状态。
- `ic_counter_SKNode`：该 checker 当前窗口的 instruction count。
- `clear_ic_status_tomainSKNode` / `icsl_naSKNode` / `cdc_empty_tocheckerSKNode`：控制和状态反馈。

checker 到 GHM/GAGG：

- `ghe_event_out_SRNode`：checker GHE 事件、初始化、packet ready、near full 等状态。
- `ghe_revent_out_SRNode`：checker high-watermark/不可用提示。
- `clear_ic_status_SRNode`：checker 完成窗口后请求大核清对应状态。
- `agg_packet_out_SRNode` / `report_fi_detection_SRNode` / `agg_core_status_SRNode`：聚合/错误/空闲状态。

== 5. 大核侧：BOOM 的事件提取和打包

`v0Config` 的大核是 BOOM，因此主路径在：

`chipyard/generators/boom/src/main/scala/common/tile.scala`

hart 0 中实例化：

- `GH_BUF(GH_BUF_Params(...))`：把 BOOM commit 信息打成检查包。
- `R_FIU`：汇总 checker fault-injection 检测延迟信息。

BOOM core 对外暴露：

`chipyard/generators/boom/src/main/scala/exu/core.scala`

- `commit_valids` / `commit_uops`：ROB commit 端口，作为检查包事件源。
- `jalr_target`：JALR 目标。
- `prf_rd`：物理寄存器读数据，用于 CSR/AMO/branch 等需要的结果。
- `ic_crnt_target`：当前检查窗口目标 checker。
- `r_arfs` / `r_arfs_pidx` / `arfs_ecp_dest`：上下文/结束点快照输出。
- `ic_counter`：每个 checker 的窗口指令数。
- `debug_maincore_status`：主核 IC 状态。

反压路径：

`ROB.can_commit` 增加 `!io.gh_stall`：

`rob.io.gh_stall := io.gh_stall | rsu_stall | ic_stall | io.big_hang`

来源含义：

- `io.gh_stall`：GH_BUF 内部 FIFO 近满。
- `rsu_stall`：RSU 正在 snapshot/merge。
- `ic_stall`：R_IC 调度器要求暂停 commit。
- `io.big_hang`：GHM CDC 或 ARFS CDC 不 ready。

这条路径保证大核在 checker/CDC 无法接收时不继续越过需要被验证的边界。

== 6. `GH_BUF` 包生成

代码：



输入：

- `commit_valids` / `commit_uops`。
- `jalr_target`。
- `alu_in`：对 load/store，BOOM tile 用 LDQ/STQ head 组合出地址和数据。
- `gh_prfs_rd`。
- `ic_crnt_target`：来自 `R_IC`，决定目标 checker。
- `gh_can_fwd`：GHE/GHT mask 与 `if_correct_process` 共同决定是否允许转发。
- `cdc_not_ready`：来自 GHM 的大核反压。

内部：

- 每个 BOOM commit lane 一个 `GH_FIFO(depth = 32)`。
- enqueue 时根据 commit uop 过滤 load/store/CSR/branch。
- dequeue 时每周期最多取 `GH_TOTAL_PACKETS = 2` 个包。
- 当 FIFO 进入 three-slots 状态，`core_hang_up` 置位，最终反压 ROB。
- 当 `cdc_not_ready` 为真时不 dequeue，避免跨域 FIFO 溢出。

包格式：

```text
packet[135:128] = header
packet[127:0]   = payload

header[7]   = one/enable，ic_crnt_target 非 0 时置 1
header[6:3] = target checker hart id，通常为 1..4
header[2:0] = subtype
```

已观察到的 subtype：

- `1`：load。
- `2`：store。
- `3`：CSR。
- `4`：branch/jump。
- `7`：ARFS/上下文相关包，走 `core_r_arfs` 旁路，不作为 LSL/BJL 普通包处理。

payload：

- load/store：通常为 `{data, addr}` 或 AMO 特例 `{prf_rd, addr}`。
- CSR：CSR/PRF 读值。
- branch/jump：`{pc, target/npc, taken, rvc}` 等信息；checker 前端用它替代本地预测。

== 7. `R_IC`：大核调度和窗口切分

代码：

`chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala`

职责：

- 选择当前 checker：`crnt_target`。
- 维护每个 checker 的 `ic_counter` 和 `ic_status`。
- 判断何时 snapshot、何时进入 checking、何时 postcheck。
- 根据 checker 可用状态和 `num_of_checker` 做调度。
- 处理模式切换、异常、返回等特殊边界。

状态机：

- `fsm_reset`：初始化。
- `fsm_presch`：等待启动。
- `fsm_sch`：选择空闲 checker。
- `fsm_cooling`：等待 RSU/流水线可安全 snapshot。
- `fsm_snap`：发起大核上下文快照。
- `fsm_trans`：等待 RSU 合并/转发上下文。
- `fsm_check`：大核继续执行并累计该 checker 对应窗口指令数。
- `fsm_postcheck`：标记窗口结束，给 checker 发完成计数。

触发窗口结束的条件：

- `ic_exit_isax`。
- 特权级/模式切换：`mode_switch` / `mode_ret`。
- 当前 checker 的 `ic_counter >= GH_TOTAL_INSTS`。
- checker 报告不可用：`icsl_na(crnt_target)`。

输出关键含义：

- `if_dosnap` / `if_dosnap_priv`：触发 RSU 保存上下文。
- `if_pipeline_stall`：反压 ROB，让快照边界清晰。
- `ic_counter(i)`：每 4 个大核周期向 checker 侧 CDC 一次，最高位作为 done 标志。
- `debug_maincore_status`：
  - `1`：调度态。
  - `2`：检查态。
  - `3`：不是当前进程/线程。
- `shared_CP_CFG`：当调度新的 checkpoint 时，向 GHT mapper 共享 CP 配置。

== 8. `R_RSU`：大核上下文快照和 ARFS 发送

代码：

`chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala`

职责：

- 在 snapshot 时保存大核 ARF/FARF/FCSR/PC，以及高特权检查需要的 CSR shadow。
- 在 merge 阶段按包发送上下文给目标 checker。
- 发送时受 `big_hang` 反压，GHM 不 ready 时暂停计数器。

输出格式：

- `arfs_merge`：128 bit，通常为 `{FARF, ARF}`，PC/FCSR 包为 `{fcsr, pc}`。
- `arfs_index`：标记当前上下文字段编号和特权/CSR 属性。
- `arfs_pidx`：目标 checker + subtype 7。
- `arfs_ecp_dest`：结束检查点 ECP 目标。

BOOM tile 将这些拼接成：

```text
core_r_arfs = {arfs_ecp_dest[7:0], r_arfs_pidx[7:0], r_arfs[136:0]}
```

GHM 根据 `arfs_pidx[5:3]` 或 `arfs_ecp_dest[5:3]` 路由到对应 checker。

== 9. GHM：跨核/跨时钟消息中心

代码：

`chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala`

GHM 是大小核之间最关键的信号搬运模块。

输入：

- `ghm_clock`: 大核和各小核 clock。
- `ghm_reset`: 大核和各小核 reset。
- `ghm_packet_in`: 大核检查包。
- `core_r_arfs_in`: 大核 ARFS 上下文包。
- `ghm_status_in`: 大核 GHT/GHE 状态。
- `ic_counter`: 大核发给各 checker 的窗口计数。
- `ghe_event_in`: checker 回传事件。
- `ghe_revent_in`: checker high watermark/不可用。
- `clear_ic_status`: checker 请求清状态。

为每个 checker 建四类 `AsyncQueue`：

- `u_data_cdc`: 大核 packet -> checker，深度 256。
- `u_arfs_cdc`: 大核 ARFS -> checker，深度 8。
- `u_l2b_ctrl_cdc`: little -> big 控制，宽度 9，深度 64。
- `u_b2l_ctrl_cdc`: big -> little 控制，宽度 22，深度 64。

packet 路由：

```text
packet_dest(j) = ghm_packet_in[(j+1)*packet_width-1 : (j+1)*packet_width-8][6:3]
if_data_en(i) = OR(packet_dest(j) == i + 1)
```

也就是说 GHM 真正按 packet header 的 `target[6:3]` 路由，而不是只依赖 `ghm_packet_dest`。

checker 何时 dequeue：

```text
data_cdc_ready(i) = ghe_event_in(i)(4) & !ghe_event_in(i)(0)
```

在 checker tile 中，`ghe_event_out` 由 GHE 事件、`packet_cdc_ready`、`log_near_full` 合成，因此 checker FIFO/LSL/BJL 近满会阻止继续拉取大核 packet。

大核反压：

```text
bigcore_hang = OR(!u_data_cdc.enq.ready) | OR(!u_arfs_cdc.enq.ready)
```

只要任意目标 CDC FIFO 或 ARFS FIFO 不可接收，就反压大核 ROB commit。

完成状态：

```text
bigcore_comp = AND(cdc_ghe_event(i)(3,1))
```

`cdc_ghe_event` 是从 checker 到大核方向锁存的事件向量。当前实现使用 sticky register，避免不同 checker 的 CDC 脉冲不对齐导致完成归约永远不成立。

清状态和不可用反馈：

- `clear_ic_status_tomain = Cat(cdc_clear_ic_status.reverse, 0)`：checker 完成后请求大核清对应 `ic_status/ic_counter`。
- `icsl_na = Cat(cdc_ghe_revent.reverse, 0)`：checker high-watermark/不可用，供 `R_IC` 调度避让。
- `ghm_cdc_empty_out(i)`：对应 checker data CDC empty，送 checker ICSL 判断是否还有在途包。

== 10. checker 小核接包和重放

checker 侧主要在：

`chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala`

对于 hart != 0：

- `ghe_packet_in_SKNode` 输入来自 GHM。
- 按每个 136 bit packet 解析 header。
- 普通 LSL 包：类型不是 0/4/7 且目标匹配本 hart。
- branch/jump 包：类型为 4 且目标匹配本 hart，送前端 `packet_bj`。
- ARFS 包：走 `core_r_arfs_c_SKNode` 旁路，送 core 的 `packet_arfs`。

关键连接：

- `core.io.packet_lsl := packet_vec_in`。
- `outer.frontend.module.io.packet_bj := packet_bjvec_in`。
- `core.io.packet_arfs := packet_rcu`。
- `core.io.ic_counter := outer.ic_counter_SKNode.bundle`。
- `core.io.clear_ic_status -> clear_ic_status_SRNode`。
- `ghe_event_out` 合成 GHE 事件、`packet_cdc_ready` 和 near-full 状态。

== 11. checker 内部验证模块

checker 的核心改动在：

`chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala`

以及：

- `r/R_ICSL.scala`
- `r/R_LSL.scala`
- `r/R_BJL.scala`
- `r/R_RSUSL.scala`
- `r/R_ELU.scala`

=== 11.1 `R_ICSL`：checker 验证状态机

代码：`r/R_ICSL.scala`

职责：

- 接收 `ic_counter`，知道本窗口需要重放多少条提交指令。
- 根据 `arf_copy_in`/RSU 状态进入 checking。
- 统计 checker 已提交指令数 `sl_counter`。
- 到达窗口结束后进入 postchecking，等待流水线清空和 RSU/ECP 比对完成。
- 产生 `clear_ic_status`，让大核清掉对应 checker 的运行状态。

状态：

- `fsm_reset`
- `fsm_nonchecking`
- `fsm_checking`
- `fsm_checking_priv`
- `fsm_self_xcpt`
- `fsm_self_xcpt_priv`
- `fsm_postchecking`
- `fsm_postchecking_priv`

关键输出：

- `icsl_checkermode`：普通 checker 重放模式。
- `icsl_checkerpriv_mode`：高特权/异常相关重放模式。
- `if_overtaking` / `if_overtaking_next_cycle`：checker 已追上或将追上窗口尾部，需要 stall 前端/流水线。
- `if_ret_special_pc`：postcheck 后返回特殊 PC。
- `icsl_stalld`：stall decode，保证 checker 不越过检查窗口。
- `icsl_status`：非检查态时为 1，用于 GAGG/GHM 判断空闲。
- `checker_core_status`：调试/聚合状态。

=== 11.2 `R_LSL`：load/store/CSR 结果重放

代码：`r/R_LSL.scala`

职责：

- 接收大核发来的 load/store/CSR 包。
- 在 checker mode 下，Rocket core 不访问真实 DCache，而是通过 LSL 提供响应。
- 对 CSR 写读也有独立 FIFO。

输入包：

- subtype 1：load。
- subtype 2：store。
- subtype 3：CSR。

输出到 Rocket 流水线：

- `resp_valid`
- `resp_data`
- `resp_addr`
- `resp_has_data`
- `resp_replay`
- `req_ready`

状态反馈：

- `near_full`：LSL 或 CSR FIFO 近满。
- `cdc_ready = !near_full`：给 GHM 判断是否继续下发 packet。
- `if_empty`：所有 LSL/CSR FIFO 为空。
- `lsl_highwatermark`：高水位告警，上报给 GHM 作为 `icsl_na`。

=== 11.3 `R_BJL/R_BJLR`：branch/jump 路径重放

代码：`r/R_BJL.scala`

Rocket 前端在：

`rocket/Frontend.scala`

实例化 `R_BJLR`：

- 输入 `packet_bj`，来自大核 branch/jump 包。
- checker mode 下，前端使用 BJL 中的 `{cpc, npc, taken, rvc}` 替代本地预测。
- 支持 speculative `reserve`、后端 `commit`、redirect/flush 时 `rollback`。
- 当 BJL 暂无可用目标而前端遇到 CFI，会触发 replay。

这保证 checker 的控制流和大核窗口保持一致，避免分支预测差异导致假错误。

=== 11.4 `R_RSUSL`：checker 侧上下文加载和结束点比较

代码：`r/R_RSUSL.scala`

职责：

- 接收大核发来的 CPS checkpoint ARFS 包。
- 把 ARF/FARF/FCSR/PC 写入 shadow storage。
- `paste_arfs` 后逐项写回 checker 寄存器堆，作为重放起点。
- 接收 ECP end-checkpoint 包后，将 checker 当前 ARF/FARF 与 ECP 比对。
- 发现寄存器不一致时，把错误编码写入内部 ELU FIFO。

关键状态：

- `rsu_status = 1`：checkpoint 已接收，可开始检查。
- `rsu_status = 3`：ECP 已接收，等待或进行结束比对。
- `if_cp_check_completed`：寄存器比对完成。

错误编码宽度：

```text
4 * xLen + 8
```

包括寄存器编号、期望 FARF/ARF、实际 FARF/ARF。

=== 11.5 `R_ELU`：错误/观测输出

`R_ELU` 汇总 checker 执行中的 load/store 观测和 RSU 比对错误。GHE 的 `doPerfRead` / `doPerfCtrl` 等指令可以读取这些调试/性能信息。

== 12. 信号流全景

=== 12.1 启动和配置

```text
software
  -> RoCC custom1
  -> GHE
      - ght_mask_out
      - ght_cfg_out / ght_cfg_valid
      - icctrl_out
      - t_value_out
      - arf_copy_out
      - s_or_r_out
      - core_trace_out
```

GHE 主要 funct：

- `0x00`：查询 channel status。
- `0x01`：设置 security/reliability 模式 `s_or_r`。
- `0x06`：big check complete 查询；当 `rs2` 为 2/3/4 时也作为 GHT cfg。
- `0x07`：查询 big/check 状态。
- `0x08`：查询 GHT/GH_BUF buffer 状态。
- `0x10`：查询 aggregator。
- `0x1b`：查询初始化。
- `0x1c`：设置激活 checker 数量。
- `0x30..0x38`：mask/start/finish 等大核状态控制。
- `0x39` / `0x49`：critical 状态写/读。
- `0x55`：读 CSR perf。
- `0x60`：触发 ARF copy。
- `0x70..0x79`：R features，包括 IC control、T 值、record/store、perf、RAW/store counters。

=== 12.2 大核到 checker 的检查包

```text
BOOM commit/LDQ/STQ/CSR/branch
  -> GH_BUF
  -> ght_packet_out_SRNode
  -> HasTiles subsystem node
  -> GHM.ghm_packet_in
  -> AsyncQueue per checker
  -> checker RocketTile.ghe_packet_in
  -> packet_lsl / packet_bj
  -> R_LSL / R_BJLR
```

=== 12.3 大核到 checker 的上下文包

```text
BOOM architectural state
  -> R_RSU snapshot
  -> core_r_arfs_SRNode
  -> GHM.core_r_arfs_in
  -> per-checker ARFS AsyncQueue
  -> checker RocketCore.packet_arfs
  -> R_RSUSL shadow storage
  -> paste_arfs writes checker RF/FPU/CSR state
```

=== 12.4 checker 到大核的完成/反压/状态

```text
checker R_ICSL / R_LSL / R_BJLR / R_RSUSL
  -> packet_cdc_ready / log_near_full / log_highwatermark / clear_ic_status
  -> checker GHE event/revent path
  -> GHM little-to-big ctrl AsyncQueue
  -> bigcore_comp / debug_bp / clear_ic_status_tomain / icsl_na
  -> BOOM R_IC / GHE / ROB stall path
```

=== 12.5 聚合和错误检测

```text
checker report_fi_detection / agg_core_status / agg_packet_out
  -> GAGG
  -> fi_d_out to big core
  -> agg_empty to GHM/big core
```

当前 `GAGG` 的 packet 路由和 scheduler refresh 基本是 tie-off，维护时不要误以为它已经完成完整数据聚合。

== 13. 反压和完成语义

大核会在以下条件 stall commit：

- GH_BUF/GHT FIFO 接近满。
- R_IC 调度器正在 snapshot/切换窗口，需要停止在安全边界。
- R_RSU 正在 snapshot 或 merge 上下文。
- GHM 的 packet CDC 或 ARFS CDC 无法 enqueue。

checker 会在以下条件拒绝继续接收 packet：

- `R_LSL.near_full`。
- `R_BJLR.near_full`。
- RSU/LSL/BJL 的 `cdc_ready` 未置位。

窗口完成链路：

1. 大核 `R_IC` 在 postcheck 时把该 checker 的 `ic_counter` 最高位置 1。
2. GHM 通过 big-to-little ctrl CDC 发送 `ic_counter`。
3. checker `R_ICSL` 看到 done 位，并比较 `sl_counter` 是否达到窗口长度。
4. checker 进入 postchecking，等待流水线清空和 RSU/ECP 完成。
5. checker 输出 `clear_ic_status`。
6. GHM 将其送回大核。
7. 大核 `R_IC` 清对应 `ic_status/ic_counter`，该 checker 可重新调度。

== 14. 和标准 Chipyard co-sim 的区别

代码中仍存在标准仿真验证路径：

- `chipyard/src/main/scala/Cospike.scala`
- `chipyard/src/main/resources/vsrc/cospike.v`
- `chipyard/src/main/resources/csrc/cospike.cc`
- `chipyard/src/main/scala/HarnessBinders.scala`
- `testchipip` 的 Dromajo bridge

这些路径基于 tile trace/retire 信息，在仿真 harness 中调用 Spike/Dromajo 做 ISA 参考模型对比。它们不参与 GuardianCouncil 的大核/小核硬件协同检查。

GuardianCouncil 是设计内部的硬件/微架构机制：

- 数据源来自大核 commit、LDQ/STQ、CSR、branch、ARFS 快照。
- 数据通过 BundleBridge 和 AsyncQueue 在芯片内部传递。
- checker 是真实 Rocket tile，不是 C++ ISS。
- 反压会真实影响大核 commit。

== 15. 维护时重点关注

=== 15.1 包格式必须一致

涉及模块：

- `GH_BUF.scala`
- `GHT.scala`
- `GHT_FILTER_PRFS.scala`
- `GHM.scala`
- `RocketTile.scala`
- `R_LSL.scala`
- `R_BJL.scala`
- `R_RSUSL.scala`

任何修改 `GH_WIDITH_PACKETS`、header bit 分配、subtype 编码、payload 布局，都需要同步修改所有解析点。`GH_GlobalParams.scala` 里已有注释提示“修改 GH_WIDITH_PACKETS 会牵一发动全身”。

=== 15.2 `GH_NUM_CORES` 当前被多处静态假设

虽然部分地方参数化为 `number_of_little_cores`，但代码里仍有固定 5 核、4 checker、hart 0 为大核的假设。例如：

- `GH_GlobalParams.GH_NUM_CORES = 5`。
- BOOM core 中对 `little_status1..4` 的 assert。
- packet header `target[6:3]` 默认以 1..4 表示 checker。

扩展 checker 数量时需要全局审查。

=== 15.3 反压路径影响大核性能和正确性

ROB commit 直接受 `gh_stall` 影响。维护时应确保：

- FIFO full/near-full 信号不会假高。
- CDC ready/valid 不会形成永久 backpressure。
- `clear_ic_status` 能可靠返回大核。
- `R_IC` 的状态机不会在 `fsm_sch` 或 `fsm_trans` 卡死。

=== 15.4 CDC 事件需要保持脉冲/电平语义清楚

GHM 中 checker -> big 的事件已经改成 sticky latch：

```text
when (b_rctrl(i) != 0) cdc_ghe_event(i) := b_rctrl(i)(5, 0)
```

这是为了避免多 checker CDC 脉冲不对齐。后续如果修改完成归约或事件位宽，要注意不能重新引入“一拍脉冲错过”的问题。

=== 15.5 GAGG 当前不是完整聚合器

`GAGG.scala` 当前：

- `agg_packet_outs(i) := 0`
- `agg_buffer_full(i) := 0`
- `sch_refresh_out(i) := 0`
- `sch_na_out := 0`

有效部分主要是：

- `agg_no_packet_inflight` 根据 checker `agg_core_status` 归约。
- `fi_d_out` 拼接所有 checker 的 `fi_d`。

如果后续依赖 aggregator 做真实错误包路由，需要先补全这一模块。

=== 15.6 BOOM 和 Rocket 大核路径不同

Rocket hart 0 路径在 `RocketTile.scala` 中实例化 `GHT`，输入为 `core.io.pc/inst/alu/new_commit`。

BOOM hart 0 路径在 `boom/common/tile.scala` 中实例化 `GH_BUF`，输入为 BOOM ROB commit uop、LDQ/STQ head、PRF/JALR target 等。

当前 `v0Config` 使用 BOOM 大核，调试时应优先看 BOOM + GH_BUF，而不是 Rocket + GHT。

== 16. 推荐阅读顺序

后续开发维护建议按以下顺序读代码：

1. `chipyard/src/main/scala/config/RocketConfigs.scala`：确认系统组合。
2. `rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala`：确认规模和包宽。
3. `rocket-chip/src/main/scala/subsystem/HasTiles.scala`：确认 BundleBridge 信号怎样接到每个 tile。
4. `boom/src/main/scala/common/tile.scala`：看 BOOM 大核如何接 GHE/GH_BUF/GHM。
5. `boom/src/main/scala/exu/core.scala`：看 R_IC/R_RSU 和 ROB 反压。
6. `boom/src/main/scala/trans/GH_BUF.scala`：看 packet 生成。
7. `rocket-chip/src/main/scala/guardiancouncil/GHM.scala`：看跨核/跨时钟传输。
8. `rocket-chip/src/main/scala/tile/RocketTile.scala`：看 checker 如何接 packet。
9. `rocket-chip/src/main/scala/rocket/RocketCore.scala` 和 `rocket-chip/src/main/scala/r/*.scala`：看 checker 内部 replay/check。
10. `rocket-chip/src/main/scala/guardiancouncil/GHE.scala`：看软件控制面和状态查询。

== 17. 一句话架构图

```text
BOOM big core
  commit/LDST/CSR/BJ/ARFS
    -> GH_BUF + R_IC + R_RSU
    -> BundleBridge
    -> GHM AsyncQueues
    -> Rocket checker cores
       - R_RSUSL restores context
       - R_LSL replays memory/CSR
       - R_BJLR replays branch targets
       - R_ICSL controls checking window
    -> GHM/GAGG feedback
    -> big core ROB/GHE/R_IC status and backpressure
```

