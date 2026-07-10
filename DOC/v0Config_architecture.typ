
#figure(
  align(center,
    ```mermaid
    graph TB
      subgraph "v0Config Top-Level"
        direction TB
        
        subgraph "Big Core Domain (200MHz)"
          BOOM["BOOM Big Core<br/>hartId=0<br/>6-wide OoO, FPU"]
          GH_BUF["GH_BUF<br/>Commit Packet Gen"]
          R_Modules_B["R_RSUSL / R_LSL / R_ICSL / R_ELU"]
        end
        
        subgraph "Checker Domain 1 (100MHz)"
          RC1["Rocket Checker<br/>hartId=1<br/>in-order"]
          R_Modules_1["R-Modules"]
        end
        
        subgraph "Checker Domain 2 (100MHz)"
          RC2["Rocket Checker<br/>hartId=2"]
        end
        
        subgraph "Checker Domain 3 (100MHz)"
          RC3["Rocket Checker<br/>hartId=3"]
        end
        
        subgraph "Checker Domain 4 (100MHz)"
          RC4["Rocket Checker<br/>hartId=4"]
        end
        
        subgraph "GHE Interconnect"
          GHE_M["GHE / GHM Manager<br/>(RoCC accelerator)"]
          GHT["GHT Scheduler/Table"]
          CDC["CDC Bridges<br/>(Async FIFOs)"]
        end
        
        subgraph "Shared"
          L2["L2 Cache"]
          BUS["TileLink Crossbar<br/>(sbus/cbus/pbus)"]
        end
        
        BOOM --> GH_BUF --> GHE_M
        GHE_M <--> CDC
        CDC <--> RC1 & RC2 & RC3 & RC4
        BOOM --> BUS
        RC1 & RC2 & RC3 & RC4 --> BUS
        BUS --> L2
      end
    ```
  ),
  caption: "v0Config 整体架构框图"
)

== v0Config 配置参数

#table(
  columns: 2,
  [*参数*], [*值*],
  [大核类型], [BOOM (WithNLargeBooms x1)],
  [大核频率], [200 MHz],
  [小核/Checker 类型], [RocketTile (WithNGCCheckers x4)],
  [小核频率], [100 MHz],
  [GC Bus 频率], [100 MHz],
  [System Bus 频率], [200 MHz],
  [Memory Bus 频率], [200 MHz],
  [HartId 分配], [大核 hartId=0, Checker hartId=1-4],
  [Tile 跨域], [AsynchronousCrossing (异步FIFO)],
  [GHE 使能], [WithGHE (RoCC attacher)],
)

= 大核 (BOOM Big Core) 详细架构

== BOOM 核心特征

BOOM (Berkeley Out-of-Order Machine) 是一个高性能 6 发射乱序执行 RISC-V 处理器：

- *流水线*：取指(IF) → 译码(ID) → 发射(Issue) → 执行(EX) → 写回(WB) → 提交(Commit)
- *关键模块*：ROB, Issue Queue, Register Rename, Branch Predictor (BTB/BHT/RAS)
- *FPU*：集成 HardFloat/FPU 单元（支持 F/D 扩展）
- *内存*：L1 ICache + L1 DCache，通过 TileLink 连接 L2

== BOOM 中集成 GuardianCouncil 的关键信号

在 BOOM 的 `tile_prci_domain.auto_tile_reset_domain.tile` 内部，GC 相关子模块包括：

#table(
  columns: 3,
  [*子模块*], [*功能*], [*波形路径前缀*],
  [GH_BUF], [从 ROB Commit 生成 GC 校验包], [`...boom_tile...gh_buf`],
  [GH_Bridge], [跨模块信号桥接], [`...boom_tile...gh_bridge`],
  [R_FIU], [故障注入单元（可选）], [`...boom_tile...r_fiu`],
  [cmdRouter], [RoCC 命令路由], [`...boom_tile...cmdRouter`],
)

== BOOM 大核关键调试信号

- `tile_prci_domain.auto_tile_reset_domain.tile.core.rob.io.commit` — ROB 提交事件
- `tile_prci_domain.auto_tile_reset_domain.tile.gh_buf.io_gh_can_fwd` — GC 包可转发
- `tile_prci_domain.auto_tile_reset_domain.tile.ght_status_out` — GHT 状态输出
- `tile_prci_domain.auto_tile_reset_domain.boom_tile.ght_status_out_sr_out` — GHT 状态（CDC后）

= 小核 (Rocket Checker) 详细架构

== Checker Core 特征

Checker 核心是简化的 RocketTile，参数如下：

#table(
  columns: 2,
  [*参数*], [*值*],
  [核心类型], [RocketCoreParams],
  [useDebug], [false],
  [MulDiv], [MulDivParams(mulUnroll=8, divUnroll=8, earlyOut=true)],
  [D-Cache], [nSets=32, nWays=2, nTLB=1x4, nMSHRs=0],
  [I-Cache], [nSets=64, nWays=8, nTLB=1x32],
  [FPU], [无],
  [频率], [100 MHz],
)

== Rocket Core 中集成 GuardianCouncil 的关键信号

Checker 核心在 RocketCore.scala 中集成了完整的 R\_\* 模块：

#table(
  columns: 3,
  [*子模块*], [*功能*], [*Chisel 类*],
  [R_RSUSL], [寄存器状态单元：ARF 快照/恢复/比对], [`R_RSUSL`],
  [R_LSL], [Load/Store Logger：内存操作记录与重放], [`R_LSL`],
  [R_ICSL], [指令检查序列器：Checker FSM 控制], [`R_ICSL`],
  [R_ELU], [错误日志单元：记录比对不匹配], [`R_ELU`],
)

== Checker 核中 R\_ 模块的关键调试信号

在每个 checker tile 的 `tile_prci_domain_N.auto_tile_reset_domain.tile` 路径下：

*ICSL 相关：*
- `icsl_checkermode` — checker 模式标志 (1bit)
- `icsl_checkerpriv_mode` — checker privilege mode (1bit)
- `icsl_if_overtaking` — 追赶/超越标志
- `checker_mode_1cycle_delay` — checker 模式延迟1周期

*LSL 相关：*
- `lsl.*.req_valid / req_ready` — load/store 请求握手
- `lsl.*.resp_valid / resp_data` — load/store 响应
- `lsl.*.if_empty` — LSL 队列空标志

*RSU 相关：*
- `rsu_slave.*.arfs_valid_out` — ARF 输出有效
- `rsu_slave.*.rsu_status` — RSU 状态机

*ELU 相关：*
- `elu_data` — ELU 输出数据
- `elu_status` — ELU 状态

= GHE (GuardianCouncil Execution Environment) 详细架构

== GHE 模块结构

GHE 以 *RoCC accelerator* 形式挂载在每个 Tile 上，通过自定义 RoCC 指令与软件交互：

#table(
  columns: 3,
  [*模块*], [*文件*], [*功能*],
  [GHE], [`guardiancouncil/GHE.scala`], [顶层 RoCC 加速器，软件指令接口],
  [GHM], [`guardiancouncil/GHM.scala`], [Manager：全局控制与状态管理],
  [GHT], [`guardiancouncil/GHT.scala`], [Table：调度表与映射],
  [GAGG], [`guardiancouncil/GAGG.scala`], [Aggregation：信号/包聚合],
  [GH_CDC], [`guardiancouncil/GH_CDC.scala`], [时钟域 crossing],
  [GH_FIFO], [`guardiancouncil/GH_FIFO.scala`], [包缓冲 FIFO],
  [GH_Bridge], [`guardiancouncil/GH_Bridge.scala`], [跨模块信号桥接],
)

== GHE 软件指令接口 (funct 码)

GHE 通过自定义 RoCC 指令（funct 字段）提供以下功能：

#table(
  columns: 2,
  [*funct*], [*功能*],
  [0x00], [doCheck — 发起检查],
  [0x01], [doSorR — 选择安全/可靠性模式],
  [0x06], [doBigCheckComp — 大核检查完成],
  [0x07], [doCheckBigStatus — 查询大核状态],
  [0x10], [doCheckAgg — 聚合检查],
  [0x30-0x38], [doMask — 设置各种掩码],
  [0x39], [doCritical — 关键操作],
  [0x40-0x43], [doEvent — 触发事件],
  [0x50-0x51], [doInitialised — 初始化],
  [0x55], [doGetCsrPerf — 获取性能计数器],
  [0x60], [doCopy — 复制操作（R功能）],
  [0x61], [doCheckRSU — RSU检查],
  [0x63], [doDeqELU — ELU出队],
  [0x64], [doRecordPC — 记录PC],
  [0x69], [doCoreTrace — 核心Trace],
  [0x70], [doICCTRL — 指令计数控制],
  [0x71], [doSetTValue — 设置阈值],
  [0x72], [doStoreFromChecker — Checker存储],
  [0x73], [doStoreFromMain — 主核存储],
  [0x75], [doRecord — 记录操作],
  [0x76-0x78], [doPerfCtrl/Read — 性能控制],
)

== GHE 全局参数

#table(
  columns: 2,
  [*参数*], [*值*],
  [GH_NUM_CORES], [5 (1 big + 4 checkers)],
  [GH_TOTAL_PACKETS], [2],
  [GH_WIDITH_PACKETS], [136 bits (2x64 data + 8 status)],
  [GH_WIDITH_PERF], [64],
  [GH_TOTAL_INSTS], [3970],
  [IF_THERE_IS_CDC], [true],
)

= 中间连接与数据流

== GC 包格式与流向

GC 包宽度为 136 bits（由 `GH_GlobalParams.GH_WIDITH_PACKETS` 定义）：

- *data\[63:0\]*：数据低 64 位（load/store 地址/数据）
- *data\[127:64\]*：数据高 64 位（load/store 数据）
- *status\[7:0\]*：包状态/类型标签

== 数据流路径

#figure(
  align(center,
    ```mermaid
    flowchart LR
      A["BOOM Commit<br/>(ROB retire)"] --> B["GH_BUF<br/>封包"]
      B --> C["GHE/GHT<br/>调度/聚合"]
      C --> D["CDC Bridge<br/>(Async FIFO)"]
      D --> E["GHM Manager<br/>分发"]
      E --> F1["Checker 1<br/>LSL 入队"]
      E --> F2["Checker 2<br/>LSL 入队"]
      E --> F3["Checker 3<br/>LSL 入队"]
      E --> F4["Checker 4<br/>LSL 入队"]
      
      F1 --> G1["R_ICSL<br/>比对判断"]
      F2 --> G2["R_ICSL<br/>比对判断"]
      F3 --> G3["R_ICSL<br/>比对判断"]
      F4 --> G4["R_ICSL<br/>比对判断"]
      
      G1 & G2 & G3 & G4 --> H["R_ELU<br/>错误汇总"]
    ```
  ),
  caption: "GC 数据流路径"
)

== 关键连接信号

*BOOM → GHE 方向：*
- `ght_status_out` — GHT 调度状态
- `ght_mask_out` — GHT 掩码输出
- `ghe_packet_in` — GHE 包输入
- `ghe_event_out` — GHE 事件输出

*GHE → Checker 方向：*
- `ghe_event_out_sr_out` — GHE 事件（经CDC同步后）
- `ghe_revent_out_sr_out` — GHE 反向事件

*Checker 间信号：*
- `ghe_store_from_checker` — Checker 的 Store 状态回传
- `if_correct_process` — 正确执行标志
- `bigcore_comp` — 大核完成标志

= 信号层次结构（据 Verilator 生成模型）

== 顶层信号统计

#table(
  columns: 2,
  [*组件路径*], [*信号数*],
  [`TestHarness.chiptop`], [77,224],
  [`TestHarness.ram`], [509],
  [`TestHarness.bits_in_queue`], [74],
  [`TestHarness.bits_out_queue`], [74],
  [`TestHarness.uart_sim_0`], [46],
  [`TestHarness.SimJTAG`], [10],
  [总计], [~82,000],
)

== Chiptop 内部核心层次

```
TestHarness
└── chiptop
    ├── dividerOnlyClockGen          (时钟分频器)
    ├── gated_clock_debug            (调试时钟门控)
    ├── SimJTAG                         (JTAG 仿真)
    └── system                       (SoC 子系统)
        ├── tile_prci_domain         (大核Tile域 - BOOM @200MHz)
        │   └── auto_tile_reset_domain
        │       └── tile             ★ BOOM Big Core (hartId=0)
        │           ├── core          (BOOM 核心流水线)
        │           ├── lsu           (Load/Store Unit)
        │           ├── gh_buf        (GC 包缓冲)
        │           ├── gh_bridge     (GC 桥接)
        │           ├── r_fiu         (故障注入)
        │           └── cmdRouter     (RoCC 路由)
        ├── tile_prci_domain_1       (Checker Tile域 - Rocket @100MHz)
        │   └── auto_tile_reset_domain
        │       └── tile             ★ Rocket Checker Core (hartId=1)
        │           ├── core          (RocketCore)
        │           │   ├── ibuf      (指令缓冲)
        │           │   ├── alu       (ALU)
        │           │   ├── csr       (CSR文件)
        │           │   ├── rsu_slave (R_RSUSL实例)
        │           │   ├── lsl       (R_LSL实例)
        │           │   ├── icsl      (R_ICSL实例)
        │           │   ├── elu       (R_ELU实例)
        │           │   └── fpu       (FPU - 可能不存在)
        │           ├── dcache        (L1 D$)
        │           └── icache        (L1 I$)
        ├── tile_prci_domain_2       (Checker Tile - hartId=2)
        ├── tile_prci_domain_3       (Checker Tile - hartId=3)
        ├── tile_prci_domain_4       (Checker Tile - hartId=4)
        ├── ghm                       (GHM Manager)
        │   ├── ghm_b_rctrl_*         (读控制)
        │   ├── ghm_b_wctrl_*         (写控制)
        │   ├── ghm_cdc_ghe_event_*   (GHE事件 CDC)
        │   └── ghm_u_l2b_ctrl_cdc_*  (L2控制 CDC)
        ├── subsystem_sbus            (系统总线)
        ├── subsystem_cbus            (控制总线)
        ├── subsystem_pbus            (外设总线)
        ├── subsystem_l2_wrapper      (L2 Cache)
        ├── clint                     (中断控制器)
        ├── plic                      (平台级中断)
        └── tlDM                      (Debug Module)
```

== 关键 GC/GHE 信号的层次位置

*GHE 事件信号（跨域同步后）：*
```
TestHarness.chiptop.system._tile_prci_domain_N_auto_tile_reset_domain_tile_ghe_event_out_sr_out   [6 bits]
TestHarness.chiptop.system._tile_prci_domain_N_auto_tile_reset_domain_tile_ghe_revent_out_sr_out  [1 bit]
```

*GHM Manager 控制信号：*
```
TestHarness.chiptop.system.ghm_b_rctrl_0~3    (读控制)
TestHarness.chiptop.system.ghm_b_wctrl_0~3    (写控制)
TestHarness.chiptop.system.ghm_cdc_ghe_event_0~3  (CDC后GHE事件)
```

*BOOM 大核内 GC 信号：*
```
...tile_prci_domain.auto_tile_reset_domain.tile.
    gh_buf.io_gh_can_fwd                     (GC包可转发)
    rob.io_gh_stall                           (ROB暂停信号)
    ...boom_tile_ght_status_out_sr_out        (GHT状态)
    ...boom_tile_ghe_event_out_sr_out         (GHE事件)
```

*Checker 核内 R\_ 模块信号：*
```
...tile_prci_domain_N.auto_tile_reset_domain.tile.
    core.icsl_checkermode                     (Checker模式)
    core.icsl_checkerpriv_mode                (Checker特权)
    core.checker_mode_1cycle_delay            (延迟1拍的checker_mode)
    core.lsl.io.req_valid / req_ready         (LSL请求)
    core.lsl.io.resp_valid / resp_data        (LSL响应)
    core.rsu_slave.io.rsu_status              (RSU状态)
    core.store_commit_count                   (Store提交计数)
    core.store_commit_cycle_sum               (Store提交周期和)
```

== 调试常用信号速查表

#table(
  columns: 4,
  [*调试目标*], [*关键信号*], [*位宽*], [*位置*],
  [Checker使能], [`checker_mode`], [1b], [Checker tile.core],
  [ICSL FSM], [`icsl.*.debug_state`], [3b], [Checker tile.core.icsl],
  [Overtaking], [`icsl.*.if_overtaking`], [1b], [Checker tile.core.icsl],
  [LSL请求], [`lsl.*.req_valid`], [1b], [Checker tile.core.lsl],
  [LSL响应], [`lsl.*.resp_valid`], [1b], [Checker tile.core.lsl],
  [RSU状态], [`rsu_slave.*.rsu_status`], [3b], [Checker tile.core],
  [GHE事件], [`ghe_event_out_sr_out`], [6b], [system._tile_prci_domain_N_\*],
  [BOOM提交], [`rob.io.commit.valid`], [1b], [BOOM tile.core.rob],
  [GC包转发], [`gh_buf.io_gh_can_fwd`], [1b], [BOOM tile.gh_buf],
  [GHT状态], [`ght_status_out_sr_out`], [N b], [BOOM tile],
  [RAW冲突], [`RAW_cnt`], [32b], [Checker tile.core],
  [I\$阻塞], [`ibuf_notvalid_cnt`], [64b], [Checker tile.core],
  [分支误预测], [`mispred_cnt`], [64b], [Checker tile.core],
  [I\$缺失], [`imiss_cnt`], [64b], [Checker tile.core],
  [Store计数], [`store_commit_count`], [128b], [Checker tile.core],
  [ELU数据], [`elu_data`], [64b], [Checker tile.core],
)

= 调试策略

== 常见问题排查路径

1. *Checker 不启动*：
   - 检查 `icsl_checkermode` 是否拉高
   - 检查 `ghe_event_out_sr_out` 是否正确传递
   - 检查 `bigcore_comp` 信号（大核初始化完成标志）

2. *Checker 卡住/追赶不上*：
   - 检查 `icsl.*.if_overtaking` 信号
   - 检查 `ibuf_notvalid_cnt`（I\$阻塞计数）
   - 检查 `mispred_cnt`（误预测计数）
   - 检查 LSL 队列 `if_empty` 状态

3. *数据比对错误*：
   - 检查 `elu_data` 和 `elu_status`
   - 检查 LSL `resp_data` 与实际期望值的差异
   - 对比 BOOM 侧 `gh_buf` 产生的包与 Checker 收到的包

4. *CDC 问题*：
   - 检查 `ghm_cdc_ghe_event_*` 的同步链状态
   - 检查 `output_chain.sync_0/1/2` 各级同步寄存器

== 波形查看建议

在 GTKWave 中查看波形时，推荐以下信号分组：

- *Group: BOOM_Core* — `tile_prci_domain.auto_tile_reset_domain.tile.core.rob.*`, `*.gh_buf.*`
- *Group: GHE_Status* — `system._tile_prci_domain_*_auto_*_ghe_*_sr_out`, `system.ghm_*`
- *Group: Checker1_Core* — `tile_prci_domain_1.auto_tile_reset_domain.tile.core.*`
- *Group: Checker1_RMod* — `tile_prci_domain_1.*.lsl.*`, `*.icsl.*`, `*.rsu_slave.*`
- *Group: GCDebug* — `*.checker_mode`, `*.if_overtaking`, `*.RAW_cnt`, `*.store_*`

= 附录

== 源文件索引

#table(
  columns: 3,
  [*模块*], [*路径*], [*语言*],
  [RocketCore (含R\_模块)], [`rocket-chip/.../rocket/RocketCore.scala`], [Chisel],
  [GHE], [`rocket-chip/.../guardiancouncil/GHE.scala`], [Chisel],
  [GHM], [`rocket-chip/.../guardiancouncil/GHM.scala`], [Chisel],
  [GHT], [`rocket-chip/.../guardiancouncil/GHT.scala`], [Chisel],
  [GAGG], [`rocket-chip/.../guardiancouncil/GAGG.scala`], [Chisel],
  [GH_GlobalParams], [`rocket-chip/.../guardiancouncil/GH_GlobalParams.scala`], [Scala],
  [R_RSUSL], [`rocket-chip/.../r/R_RSUSL.scala`], [Chisel],
  [R_LSL], [`rocket-chip/.../r/R_LSL.scala`], [Chisel],
  [R_ICSL], [`rocket-chip/.../r/R_ICSL.scala`], [Chisel],
  [R_ELU], [`rocket-chip/.../r/R_ELU.scala`], [Chisel],
  [GH_BUF (BOOM侧)], [`boom/.../trans/GH_BUF.scala`], [Chisel],
  [BOOM Tile], [`boom/.../common/tile.scala`], [Chisel],
  [v0Config], [`chipyard/.../config/RocketConfigs.scala`], [Scala],
  [Configs (WithNGCCheckers)], [`rocket-chip/.../subsystem/Configs.scala`], [Scala],
  [VTestHarness 生成的根头文件], [`verilator/.../VTestHarness___024root.h`], [C++],
)
