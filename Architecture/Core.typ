#set document(
  title: "BoomCore 当前输入输出与连接部件分类",
  author: "基于 Chipyard/BOOM 源码的静态分析",
)
#set page(paper: "a4", margin: (x: 17mm, y: 16mm), numbering: "1 / 1")
#set text(font: ("Noto Sans CJK SC", "Droid Sans Fallback"), size: 10.5pt, lang: "zh")
#set par(justify: true, leading: 0.72em)
#set heading(numbering: "1.1")
#set table(stroke: rgb("d8dee8"), inset: 4pt, align: (left, top))
#show raw: set text(font: "Noto Sans Mono CJK SC", size: 8pt)

#align(center)[
  #text(size: 20pt, weight: "bold")[BoomCore 当前输入输出与连接部件分类]
  #v(4pt)
  #text(size: 10pt, fill: rgb("536174"))[Rocket 小核校验 BOOM 大核的接口整理]
  #v(3pt)
  #text(size: 8.8pt, fill: rgb("697586"))[分析对象：`/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala`]
]

#v(8pt)

#block(fill: rgb("eef5ff"), stroke: rgb("a9c8ef"), inset: 8pt, radius: 4pt)[
  *范围。* 本文只做静态源码分析，不运行仿真、elaboration、综合或硬件生成。每个一级章节对应一个实际连接的部件或通道；章节内同时列出 BoomCore 发出的输出、接收的输入，并按功能继续细分。相同信号连接到多个部件时，在各章节重复记录。
]

#block(fill: rgb("fff7e8"), stroke: rgb("e5bd68"), inset: 8pt, radius: 4pt)[
  *标记。* 三大类为：`无关`（当前纠错不消费，如 IFU/PTW 的取指和翻译控制）；`校验相关`，细分为 `校验-直接`（直接给 Rocket 顺序重放/结果比较的提交 uop、写回值、JALR 目标）和 `校验-配套`（快照、包、调度、所有权、计数或诊断协议）；`外部改写`（会推进 cache、CSR、设备或加速器状态）。副作用另标为 `无`、`隔离`、`隔离+回滚`、`隔离+不可回滚`。`隔离+回滚` 只适用于尚未越过接受点的推测状态；一旦 cache/设备/CSR/加速器接受写入，就只能隔离，不能靠 BOOM 的 ROB rollback 撤销。
]

#outline(indent: auto)

= 端口范围、方向与连接总览

`BoomCore.io` 的当前顶层声明位于 `/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:58-141`。源码按实际连接部件分组，声明顺序为：标准 Tile/CSR、IFU、PTW/TLB、LSU、RoCC、trace/FPU、DCache、GH_BUF、GHM/CDC、R_RSU、R_IC/命令路由和运行时映射。

本文按 *BoomCore 视角的叶子方向* 解释 `Flipped` Bundle，而不是只看 Bundle 定义中的方向。例如 `val lsu = Flipped(new LSUCoreIO)`（`core.scala:76`），所以 `dis_uops`、`commit`、`brupdate` 是 BoomCore 输出，`stq_debug`、`clr_bsy`、`ld_miss` 是 BoomCore 输入。

`Decoupled` 必须拆成叶子：`valid/bits` 与 `ready` 方向相反。当前 `rocc.cmd.valid/bits` 是 BoomCore 输出而 `cmd.ready` 是输入；`rocc.resp.valid/bits` 是输入而 `resp.ready` 是输出。本文表格中的方向均遵循这一规则。

== 当前声明的顶层端口

#table(
  columns: (1.7fr, 3.7fr, 1.2fr),
  table.header([*主要连接部件/通道*], [*当前 `BoomCore.io` 字段*], [*声明位置*]),
  [Tile / CSRFile], [`hartid`、`interrupts`], [`65-66`],
  [IFU / BoomFrontend], [`ifu`], [`69`],
  [PTW / TLB], [`ptw`、`ptw_tlb`], [`72-73`],
  [LSU], [`lsu`], [`76`],
  [RoCC], [`rocc`], [`79`],
  [Trace / FPU], [`trace`、`fcsr_rm`], [`82-83`],
  [DCache / LSU 包归因], [`csr_cycle`、`active_packet_seq`、`packet_alloc_valid`、`packet_alloc_seq`], [`87-90`],
  [GH_BUF], [`commit_valids`、`commit_uops`、`prf_rd`、`jalr_target`、`ic_crnt_target`、`gh_stall`], [`94-99`],
  [GHM / CDC], [`ic_status`、`checker_big_owner`、`ic_counter`、`checker_segment_id`、`clear_ic_status_tomain`、`icsl_na`、`global_ic_status`、`global_checker_big_owner`], [`102-105, 117-118, 140-141`],
  [R_RSU / GHM 快照], [`r_arfs`、`r_arfs_pidx`、`arfs_ecp_dest`、`big_hang`], [`108-111`],
  [R_IC / 命令路由], [`icctrl`、`num_of_checker`、`if_correct_process`、`debug_maincore_status`、`debug_perf_ctrl`、`debug_perf_val`、`ght_prv`、`csr_counter`、`bigComp`、`checker_state_sel`、`checker_state_data`、`checker_enable_rd`、`core_trace`、`ic_trace`], [`114-134`],
  [运行时 checker 映射], [`big_core_id`、`checker_enable_mask`、`checker_enable_we`、`global_ic_status`、`global_checker_big_owner`], [`137-141`],
)

表中按主要连接对象归类；一个信号可能有多个消费者。例如 `ic_crnt_target` 同时送 GH_BUF 与 R_RSU，`active_packet_seq` 同时送 LSU 与 DCache，`debug_maincore_status` 同时供 Tile 观测并控制 DCache 统计窗口。后文章节会在每个实际连接处分别解释。

== 当前接口注意事项

- 已移除无消费者的 `t_value` 完整死链路：包括 BoomCore 顶层端口、Boom Tile 桥接器、公共 RoCC/命令路由端口以及 GHE 中仅写不读的寄存器。
- `ptw_tlb` 在 `core.scala:73` 声明，Tile 在 `common/tile.scala:376` 把它加入 PTW requestor 列表，但 `core.scala` 没有产生 `ptw_tlb.req`。它是接口预留，不能当作当前活跃校验输出。
- `core.scala:1858` 先对 `io.rocc` 整体赋 `DontCare`，随后显式驱动 `exception`，并在启用 RoCC 时通过 shim 连接 `cmd/resp`。因此 `mem` 与 GuardianCouncil 扩展字段虽存在于公共 `RoCCCoreIO` 类型中，却不是 BoomCore 的活动数据路径。
- `ic_crnt_target` 在 BoomCore/R_IC 侧为 6 位，而 `GH_BUF_IO.ic_crnt_target` 为 5 位；当前 Tile 直接连接两者。现有 checker 编号未使用高位时功能不受影响，但扩展到 32 以上目标前必须统一位宽。
- `checker_state_sel` 的非零值会加上 `(GH_NUM_BIG_CORES - 1)` 后直接索引状态 Vec，当前没有越界保护；软件/命令路由必须把选择值限制在已配置的 checker 编号范围。

= IFU / BOOM 前端

连接关系：`BoomCore.io.ifu` 声明于 `/boom/src/main/scala/exu/core.scala:69`，Bundle 叶子声明于 `/boom/src/main/scala/ifu/frontend.scala:257-289`；Tile 在 `/boom/src/main/scala/common/tile.scala:390` 将它连接到 `outer.frontend.module.io.cpu`。本章中 `输出` 指 BoomCore 发给 IFU，`输入` 指 IFU 返回 BoomCore。

== 取指与 FTQ 查询

- *输出* `ifu.fetchpacket.ready`（`frontend.scala:260`，驱动 `core.scala:884`）：BoomCore 对 FetchBuffer 的反压/消费许可。`ready && valid` 会消费前端指令包并推进 FetchBuffer，功能分类 `无关`，副作用 `隔离`（BOOM 私有前端队列）。
- *输出* `ifu.get_pc(0).ftq_idx`、`ifu.get_pc(1).ftq_idx`（Bundle 声明 `frontend.scala:263`，叶子 `fetch-target-queue.scala:79`，驱动 `core.scala:918`、`:943`）：选择异常/JALR/flush 或错预测对应的 FTQ 项。分类 `无关`，副作用 `隔离`。
- *输入* `ifu.fetchpacket.valid/bits`（`frontend.scala:260`）：前端返回待译码指令包，包含 uop、FTQ/预测上下文；BoomCore 只读，不向 checker 直接转发，分类 `无关`，副作用 `无`。
- *输入* `ifu.get_pc(*).entry/ghist/pc/com_pc/next_val/next_pc`（`fetch-target-queue.scala:81-89`）：返回目标 FTQ 条目、全局历史、当前 PC、提交 PC 和下一 PC，供跳转、异常和 ROB 计算使用，分类 `无关`，副作用 `无`。
- *输出* `ifu.debug_ftq_idx(w)`（`frontend.scala:264`，驱动 `core.scala:1885`；trace 关闭时 `:1927` 置 `DontCare`）：trace 重算提交指令地址的 FTQ 索引，分类 `无关/诊断`，副作用 `无`。
- *输入* `ifu.debug_fetch_pc(w)`（`frontend.scala:265`）：trace 计算 PC 的前端调试输入，分类 `无关`，副作用 `无`。

== 前端配置与分支恢复

- *输出* `ifu.status`、`ifu.bp`、`ifu.mcontext`、`ifu.scontext`（`frontend.scala:268-271`，驱动 `core.scala:765-768`）：把 CSR 特权状态、断点和上下文送入 BPU/前端，分类 `无关`，副作用 `隔离`（配置传播，不应与 checker 共享）。
- *输出* `ifu.brupdate`（`frontend.scala:275`，驱动 `core.scala:316`）：广播分支解析、taken、目标、分支 mask 和错预测信息；前端据此更新预测历史并清理错误路径，分类 `无关`，副作用 `隔离+回滚`。
- *输出* `ifu.redirect_val`、`ifu.redirect_flush`、`ifu.redirect_pc`、`ifu.redirect_ftq_idx`、`ifu.redirect_ghist`（`frontend.scala:278-282`，驱动 `core.scala:761-844`）：异常、唯一指令或分支错预测时重定向 PC、重置 FTQ 和全局历史，分类 `无关`，副作用 `隔离+回滚`。
- *输出* `ifu.commit.valid/bits`（`frontend.scala:284`，驱动 `core.scala:849-852`，system PC-to-EPC 特例在 `core.scala:1131-1132`）：通知 FTQ 回收已提交项；它不是 Rocket checker 的提交包，分类 `无关`，副作用 `隔离`。

== ICache/TLB 维护

- *输出* `ifu.flush_icache`（`frontend.scala:286`，驱动 `core.scala:770-773`）：已提交 `FENCE.I` 或 debug JALR 触发 ICache 失效，分类 `外部改写`，副作用 `隔离+不可回滚`；checker 不得在共享 ICache 上重复执行。
- *输出* `ifu.sfence.valid/bits`（`frontend.scala:273`，`SFenceReq` 叶子 `/rocket-chip/src/main/scala/rocket/TLB.scala:38-44`，驱动 `core.scala:857-859`）：从内存执行单元转发 SFENCE，清理前端 TLB/地址翻译状态，分类 `外部改写`，副作用 `隔离+不可回滚`。当前源码只在条件块内赋值，未见显式默认 `valid=0`，后续应检查该接口的确定性。
- *输入* `ifu.perf`（`frontend.scala:288`）：前端性能事件输入，当前仅被事件统计逻辑消费，分类 `无关/诊断`，副作用 `无`。

= PTW 与 TLB 翻译通道

`BoomCore.io.ptw = Flipped(new DatapathPTWIO())` 声明于 `/boom/src/main/scala/exu/core.scala:72`，叶子声明于 `/rocket-chip/src/main/scala/rocket/PTW.scala:98-112`；Tile 在 `/boom/src/main/scala/common/tile.scala:594` 连接 `core.io.ptw <> ptw.io.dpath`。

== Core 到 PTW 的配置输出

- *输出* `ptw.ptbr`、`ptw.status`、`ptw.pmp`（`PTW.scala:100`、`:104`、`:107`，驱动 `core.scala:1850-1852`）：当前页表根、特权状态和 PMP 配置，供 PTW 进行页表遍历，分类 `无关`，副作用 `隔离`（仅 PTW 私有翻译状态）。
- *输出* `ptw.hgatp`、`ptw.vsatp`、`ptw.hstatus`、`ptw.gstatus`、`ptw.customCSRs`（`PTW.scala:101-109`）：由于外层 `Flipped`，在类型上是 BoomCore 输出，但当前 `core.scala` 没有赋值；分类 `无关/未驱动`，副作用 `无`。
- *输出* `ptw.sfence.valid/bits`（`PTW.scala:103`，驱动 `core.scala:1853`）：把 IFU SFENCE 转给 PTW，刷新页表遍历和翻译相关状态，分类 `外部改写`，副作用 `隔离+不可回滚`；若 checker 判错，不能依靠 ROB rollback 恢复已完成的 TLB/PTW 失效。
- *输入* `ptw.perf.l2miss/l2hit/pte_miss/pte_hit`、`ptw.clock_enabled`（`PTW.scala:108-111`）：PTW 性能与时钟门控状态，分类 `无关/诊断`，副作用 `无`。

== `ptw_tlb` 请求端口

- *输出（形式上）* `ptw_tlb.req.valid`、`ptw_tlb.req.bits.addr/need_gpa/vstage1/stage2`（`TLBPTWIO` 聚合声明 `/rocket-chip/src/main/scala/rocket/PTW.scala:71-83`，`PTWReq` 叶子 `:23-28`）：TLB 向 PTW 发出的 PTE 请求；但当前 `core.scala` 没有驱动，Tile 仅把端口加入 requestor 列表（`common/tile.scala:376`），分类 `无关/未活动`，副作用 `无`。
- *输入* `ptw_tlb.req.ready`、`ptw_tlb.resp.valid/bits`（`PTW.scala:73-74`）：PTW 对请求的接收和 PTE 响应，分类 `无关`，副作用 `隔离`（TLB/PTW 私有状态）。
- *输入* `ptw_tlb.ptbr/hgatp/vsatp/status/hstatus/gstatus/pmp/customCSRs`（`PTW.scala:75-82`）：PTW 通过 `requestor` 批量连接返回给各 TLB 的翻译配置。当前 BoomCore 内部没有读取这些叶子，因此属于 `无关/未消费输入`，不能接入 checker。

= LSU / Load-Store Unit

连接入口：`BoomCore.io.lsu = Flipped(new LSUCoreIO)`，声明 `/boom/src/main/scala/exu/core.scala:76`；`LSUCoreIO` 叶子声明 `/boom/src/main/scala/lsu/lsu.scala:140-190`，`LSUExeIO` 声明 `lsu.scala:61-70`。执行单元在 `core.scala:330` 与 `io.lsu.exe(i)` 连接，Tile 在 `/boom/src/main/scala/common/tile.scala:391` 把 Core LSU 接到 LSU 模块。

== EXU 到 LSU 的请求输出

- *输出* `lsu.exe(i).req.valid/bits`（`LSUExeIO.req`，`lsu.scala:65`，连接 `core.scala:330`）：请求中包含 uop、源数据、有效地址、异常和 SFENCE（`FuncUnitResp` 叶子 `/boom/src/main/scala/exu/execution-units/functional-unit.scala:103-114`）。分类 `外部改写`；load/LR 尚未被 LSU/DCache 接受的请求可回滚，接受后 refill、替换、coherence metadata、LR reservation 不可回滚。
- *输出* `lsu.exe(i).iresp.ready`、`lsu.exe(i).fresp.ready`（`lsu.scala:69-70`）：BoomCore 对 LSU load/AMO 整数/浮点响应的消费许可；`valid/bits` 是 LSU 返回输入。`ready && valid` 会推进 BOOM 回写，分类 `无关/内部执行`，副作用 `隔离+回滚`。
- *输出* `lsu.dis_uops(w).valid/bits`（`lsu.scala:146`，驱动 `core.scala:1518-1519`）：dispatch 时分配 BOOM 私有 LDQ/STQ 项；不直接改写架构内存，分类 `无关/内部控制`，副作用 `隔离+回滚`；错预测必须清理对应队列项。
- *输出* `lsu.fp_stdata.valid/bits`（`lsu.scala:153`，连接 `core.scala:1540`）：FPU store data 进入 LSU 的 SDQ；`ready` 是 LSU 返回输入。未提交项可取消，真正 store 写出后不可回滚，分类 `外部改写`，副作用 `隔离；提交写后不可回滚`。
- *输出* `lsu.commit.*`（聚合 `lsu.scala:155`，`CommitSignals` 叶子 `/boom/src/main/scala/exu/rob.scala:133-152`，驱动 `core.scala:1523`）：传递 ROB commit、arch_valid、uop、fflags、rollback、debug 数据和 GuardianCouncil ALU 结果，供 LSU 回收队列和处理顺序；分类 `无关/内部提交控制`，副作用 `隔离+回滚`。普通 store 在此之后才由 STQ 标为 committed，但这不等价于 checker 已通过。
- *输出* `lsu.commit_load_at_rob_head`（`lsu.scala:156`，驱动 `core.scala:1526`）：允许 ROB 头部等待的 uncached load 发射，分类 `外部改写`，副作用 `隔离`。
- *输出* `lsu.brupdate`（`lsu.scala:173`，驱动 `core.scala:1532`）：更新/清除 LDQ/STQ 分支 mask，属于 BOOM 私有恢复控制，分类 `无关/内部恢复`，副作用 `隔离+回滚`。
- *输出* `lsu.rob_head_idx`、`lsu.rob_pnr_idx`（`lsu.scala:174-175`，驱动 `core.scala:1533-1534`）：提供年龄、提交和不可推测边界，分类 `无关/顺序控制`，副作用 `隔离`。
- *输出* `lsu.exception`（`lsu.scala:176`，驱动 `core.scala:1529`）：异常 flush 后清理未提交访存项，分类 `无关/内部恢复`，副作用 `隔离+回滚`。
- *输出* `lsu.fence_dmem`（`lsu.scala:166`，驱动 `core.scala:1094`）：要求 DCache 清理预取和推测 miss、建立内存顺序，分类 `外部改写`，副作用 `隔离`。
- *输出* `lsu.tsc_reg`（`lsu.scala:182`，驱动 `core.scala:1536`）：调试时间戳输入 LSU，分类 `无关/诊断`，副作用 `无`。
- *输出* `lsu.active_packet_seq`（`lsu.scala:189`，驱动 `core.scala:2151-2154`）：把活动校验包序号带入 STQ/DCache 请求，分类 `校验-配套`，副作用 `隔离+回滚（包状态）`。

== LSU 返回到 BoomCore 的输入

- *输入* `lsu.exe(i).iresp.valid/bits`、`lsu.exe(i).fresp.valid/bits`（`lsu.scala:69-70`）：load/AMO 数据、uop 和异常结果，进入 BOOM 回写端口；分类 `无关/内部执行`，副作用 `隔离+回滚`。
- *输入* `lsu.stq_debug(w).valid/bits`（`lsu.scala:144`）：STQ 地址/数据调试记录，送 ROB 的 `debug_st`（`core.scala:1124`）；分类 `校验-配套/诊断`，副作用 `无`，不能当作可执行 store 请求。
- *输入* `lsu.dis_ldq_idx`、`lsu.dis_stq_idx`（`lsu.scala:147-148`）：分配给 dispatch uop 的队列索引，影响 uop 元数据，分类 `无关/内部控制`，副作用 `隔离+回滚`。
- *输入* `lsu.ldq_full`、`lsu.stq_full`（`lsu.scala:150-151`）：阻止 dispatch 溢出，分类 `无关/内部控制`，副作用 `隔离`。
- *输入* `lsu.clr_bsy`、`lsu.clr_unsafe`（`lsu.scala:160-163`）：清除 ROB busy/unsafe，影响依赖唤醒和提交，分类 `无关/内部控制`，副作用 `隔离+回滚`。
- *输入* `lsu.spec_ld_wakeup`、`lsu.ld_miss`（`lsu.scala:169-171`）：推测 load 唤醒及失败重执行通知，分类 `无关/内部控制`，副作用 `隔离+回滚`。
- *输入* `lsu.fencei_rdy`（`lsu.scala:178`）：指示 Fence.I 能否继续，分类 `无关/内部控制`，副作用 `隔离`。
- *输入* `lsu.lxcpt.valid/bits`（`lsu.scala:180`）：访存异常送 ROB；异常提交会改变 CSR/前端，分类 `外部改写/异常控制`，副作用 `隔离`。
- *输入* `lsu.perf.acquire/release/tlbMiss`（`lsu.scala:184-188`）：访存性能事件，分类 `无关/诊断`，副作用 `无`。

== LSU 内部不可回滚点

普通 store 在 `/boom/src/main/scala/lsu/lsu.scala:1581-1586` 根据 `io.core.commit.valids` 设置 STQ `committed`，随后才在 `lsu.scala:1626-1644` 向 DCache 发出请求。`committed` 只代表 ROB 退休，不代表 checker 通过。

`/boom/src/main/scala/lsu/dcache.scala:1311-1315` 形成 pipeline data-write 候选；仲裁后的真实 data-array 写使能是 `dcache.scala:515-517` 的 `data.io.write.valid := dataWriteArb.io.out.fire`。pipeline store 的完成/dirty 归因点在 `dcache.scala:1331-1339`。成功 SC、AMO、uncacheable store/MMIO 写一旦越过 DCache/TileLink 接受点，均标记 `外部改写 / 隔离+不可回滚`；load 的返回值可重放，但 refill、替换、coherence metadata、MSHR、LR/SC reservation 和 DCache 统计状态不能由 ROB rollback 恢复。

= DCache / 访存统计与包元数据

DCache 不是 `BoomCore.io` 的独立 Bundle，而是通过 `LSU -> lsu.io.dmem -> outer.dcache` 连接（`/boom/src/main/scala/common/tile.scala:602`），同时接收 Core 的统计/包输出。DCache Bundle 的相关字段声明在 `/boom/src/main/scala/lsu/dcache.scala:424-434`。

== 直接送入 DCache 的 Core 输出

- *输入到 DCache* `csr_cycle`（顶层声明 `core.scala:87`，驱动 `core.scala:659`，Tile 接收 `common/tile.scala:608`）：CSR cycle/mcycle 时间戳，用于访存统计，分类 `校验-配套`，副作用 `无`。
- *输入到 DCache* `debug_maincore_status`（`core.scala:119`，驱动 `:2075`，Tile 在 `common/tile.scala:604` 判断是否等于 `2.U`）：打开/关闭 traffic check 窗口，分类 `校验-配套`，副作用 `隔离+回滚（统计协议）`。
- *输入到 DCache* `packet_alloc_valid`、`packet_alloc_seq`、`active_packet_seq`（声明 `core.scala:88-90`，驱动 `core.scala:2148-2154`，Tile 接收 `common/tile.scala:609-611`）：建立包统计槽、设置序号水位和 dirty-line 归因，分类 `校验-配套`，副作用 `隔离+回滚（协议状态）`。错误包必须原子 cancel/release，不能留下半个统计窗口。

== DCache 私有状态与不可逆改写

DCache 会改写 data array、tag/coherence metadata、refill/MSHR/替换状态、LR/SC reservation、traffic counters，以及 `dirtyPacketSeq/dirtyPacketTracked`（声明 `/boom/src/main/scala/lsu/dcache.scala:482-485`，更新 `:1317-1339`）。这些不是 Rocket checker 可共享的架构状态。cacheable store/成功 SC/AMO 的 data-array 写、uncacheable store/AMO 的 TileLink A 通道写、dirty writeback 和 MMIO 都标记 `外部改写 / 隔离+不可回滚`。

== LSU-DCache 端口双向清单

`BoomDCacheBundle.lsu = Flipped(new LSUDMemIO)`（`/boom/src/main/scala/lsu/dcache.scala:420-423`），Tile 连接于 `common/tile.scala:602`。因此下列方向以 DCache 模块为参照：

- *LSU 输出到 DCache 输入* `lsu.io.dmem.req.valid/bits`、`s1_kill`、`brupdate`、`exception`、`rob_head_idx`、`rob_pnr_idx`、`force_order`，叶子声明 `/boom/src/main/scala/lsu/lsu.scala:99-119`。`req.valid/bits` 携带 load/store/SC/AMO 地址、数据、uop、`traffic_check` 和 `packet_seq`；分类 `外部改写`，请求在 DCache 接受前可回滚，接受后的 cache/总线状态不可回滚。
- *DCache 输出到 LSU 输入* `lsu.io.dmem.req.ready`（`lsu.scala:102`，驱动 `/boom/src/main/scala/lsu/dcache.scala:522-524`）：DCache 能否接收新请求；`ready && valid` 是请求越过 DCache 入口的接受点，分类 `外部改写/握手`，副作用 `隔离+不可回滚（对已接受写）`。
- *DCache 输出到 LSU 输入* `lsu.io.dmem.resp.valid/bits`、`nack.valid/bits`（`lsu.scala:106-108`，驱动 `dcache.scala:1244-1259`）：返回 load/AMO 数据或要求 replay；分支 mask/exception 会抑制错误路径响应，分类 `无关/内部执行`，副作用 `隔离+回滚`。
- *DCache 输出到 LSU 输入* `lsu.io.dmem.release.valid/bits` 及其 `ready`（`lsu.scala:115`，DCache 驱动 `dcache.scala:883`）：TileLink C 通道的 cache line Release/Probe 应答，由 DCache 释放或写回一致性行；握手后可能改变共享缓存/写回状态，分类 `外部改写`，副作用 `隔离+不可回滚`。
- *DCache 输出到 LSU 输入* `lsu.io.dmem.traffic_check_state`、`ordered`、`perf.acquire/release`（`lsu.scala:119-128`，DCache 驱动 `dcache.scala:1268`、`:1206-1207`、`:1472`）：traffic 窗口、Fence 排空结果和性能事件；其中 `traffic_check_state` 决定 LSU 是否给请求打校验标记，分类 `校验-配套/内部控制`，副作用 `隔离`。
- *LSU 输出到 DCache 输入* `lsu.io.dmem.traffic_load_cache_complete`、`traffic_load_uncache_complete`、`traffic_load_forward_complete`、`traffic_lr_complete`、`traffic_sc_success_complete`、`traffic_sc_fail_complete`、`traffic_amo_cache_complete`、`traffic_amo_uncache_complete`（`lsu.scala:129-136`，LSU 驱动 `lsu.scala:1353-1360`）：访存成功/失败去重事件，DCache 用于更新 traffic counters，分类 `校验-配套`，副作用 `隔离+回滚（统计协议）`。
- *DCache 输出到 Tile/RoCC* `outer.dcache.module.io.traffic_counter`（`dcache.scala:429`，Tile 读取 `common/tile.scala:407`）：按 cacheable/uncacheable load/store、SC、AMO 和 dirty writeback 分类的统计读回，分类 `校验-配套/诊断`，副作用 `无`。

== 命令路由/GHM 直接送入 DCache 的控制

- *输入到 DCache（非 BoomCore 顶层端口）* `traffic_reset`、`traffic_start`、`traffic_stop`（DCache Bundle 声明 `dcache.scala:425-427`，Tile 驱动 `common/tile.scala:605-607`）：清除、开启和停止 traffic 统计窗口；分类 `校验-配套`，副作用 `隔离+回滚（统计状态）`，错误包必须同时撤销窗口和计数快照。
- *输入到 DCache（非 BoomCore 顶层端口）* `checker_results`（DCache Bundle `dcache.scala:433-434`，Tile 驱动 `common/tile.scala:612-614`）：各 checker 对包/dirty writeback 的通过、失败或取消结果，驱动 DCache 统计桶结算；分类 `校验-配套`，副作用 `隔离+回滚（协议状态）`。

= GH_BUF / 提交包缓冲

`GH_BUF` 实例化于 `/boom/src/main/scala/common/tile.scala:213`，IO 声明于 `/boom/src/main/scala/trans/GH_BUF.scala:30-50`。本章只记录 Core 与 GH_BUF 的连接；GH_BUF 再向 GHM/CDC 输出的数据不等同于 BoomCore 顶层端口。

== BoomCore 输出到 GH_BUF 的直接校验字段

- *输出* `commit_valids(w)`（`core.scala:94`，驱动 `:2173`，GH_BUF 接收 `common/tile.scala:295`）：ROB `arch_valids`，表示 lane 是否有架构退休指令；是所有提交字段的 valid 门控，分类 `校验-直接`，副作用 `无`。
- *输出* `commit_uops(w)`（`core.scala:95`，驱动 `:2174`，GH_BUF 接收 `common/tile.scala:294`）：退休 uop，包含 `uopc`、访存/CSR/分支/AMO/RoCC 类型、寄存器和立即数字段；GH_BUF 据此编码指令类型，分类 `校验-直接`，副作用 `无`。
- *输出* `prf_rd(w)`（`core.scala:96`，驱动 `:1947`，GH_BUF 接收 `common/tile.scala:306`）：以提交 uop 的 `pdst`（地址在 `core.scala:1381`）读取物理寄存器值；用于比较写回结果，分类 `校验-直接`，副作用 `无`。
- *输出* `jalr_target(w)`（`core.scala:97`，驱动 `:2175`，GH_BUF 接收 `common/tile.scala:307`）：ROB 保存的 `gh_effective_alu_out`，用于 JALR 目标及分支包，分类 `校验-直接`，副作用 `无`。
- *输出* `ic_crnt_target`（`core.scala:98`，驱动 `:2077`，GH_BUF 接收 `common/tile.scala:316`）：当前 R_IC checker 目标，写入包头目的字段，分类 `校验-配套`，副作用 `隔离+回滚（路由状态）`。

GH_BUF 同时按 `commit_uops.uses_ldq/uses_stq` 从 LSU 的 `ldq_head/stq_head` 读取地址/数据（`common/tile.scala:261-283`），并将 `commit_valids/uops/prf_rd/jalr_target` 延迟一拍后装入 FIFO（`:294-307`）。因此 checker 必须把 valid、uop 类型、目标 checker 和包序号作为一个原子包处理。

== GH_BUF 返回 BoomCore 的控制输入

- *输入* `gh_stall`（顶层声明 `core.scala:99`，Tile 在 `common/tile.scala:226` 由 `gh_buf.io.core_hang_up` 驱动）：GH_BUF FIFO 接近满时阻止 ROB 继续提交；分类 `校验-配套`，副作用 `隔离`。它只应暂停 BOOM，不应被 Rocket checker 当作架构结果。

= GHM / CDC / 跨核校验网络

GHM 连接位于 `/boom/src/main/scala/common/tile.scala:224-246`、`:337-354`。本章把所有送往或来自 GHM/SRNode/SKNode 的 Core 字段集中列出。

== BoomCore 输出到 GHM 的状态与快照

- *输出* `ic_status`（`core.scala:102`，驱动 `:2169`，送 `common/tile.scala:236`）：本大核各 checker 的 busy/running 位，GHM 做跨大核 OR 合并；分类 `校验-配套`，接收端会改变 checker 分配，副作用 `隔离+回滚`。
- *输出* `checker_big_owner(i)`（`core.scala:103`，驱动 `:2145`，打包送 `common/tile.scala:240-244`）：checker 当前所有大核 owner，分类 `校验-配套`，副作用 `隔离+回滚`；错误包必须释放 owner。
- *输出* `checker_segment_id(i)`（`core.scala:105`，驱动 `:2146`，送 `common/tile.scala:245`）：包/segment 序号，跨域匹配结果，分类 `校验-配套`，副作用 `隔离+回滚`。
- *输出* `ic_counter(i)`（`core.scala:104`，驱动 `:2079`，Tile 打包到 `common/tile.scala:349-351`）：每个 checker 的窗口指令计数，分类 `校验-配套`，副作用 `无`（读出）；计数归属必须绑定 sequence。
- *输出* `r_arfs(0)`、`r_arfs_pidx(0)`、`arfs_ecp_dest`（声明 `core.scala:108-110`，驱动 `:2130-2133`，打包到 `common/tile.scala:337`）：R_RSU 合并后的 ARF/FARF 数据、片段索引和 ECP 目标，分类 `校验-配套`，副作用 `隔离+回滚`。`rsu_merging_valid` 虽仍存在于 R_RSU 内部 IO（`/rocket-chip/src/main/scala/r/R_RSU.scala:37-45`），但未成为 BoomCore 顶层输出，当前 SRNode 也没有接收该 valid 位；checker 不能凭静态数据判断片段有效性。

== GHM 输入到 BoomCore 的控制

- *输入* `clear_ic_status_tomain`（`core.scala:117`，Tile 驱动 `common/tile.scala:232`）：清除指定 checker 的 busy/status，分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `global_ic_status`（`core.scala:140`，Tile 驱动 `common/tile.scala:237`）：全局 OR 后的 checker 状态，R_IC 用于避免重复分配，分类 `校验-配套`，副作用 `隔离`。
- *输入* `global_checker_big_owner`（`core.scala:141`，Tile 驱动 `common/tile.scala:244`）：全局 owner 打包值，`checker_state_data` 查询时拆包，分类 `校验-配套`，副作用 `隔离`。
- *输入* `icsl_na`（`core.scala:118`，Tile 驱动 `common/tile.scala:233`）：checker FIFO/CDC 接近满的通知，R_IC 据此暂缓调度；分类 `校验-配套`，副作用 `隔离`。
- *输入* `big_hang`（`core.scala:111`，Tile 由 `common/tile.scala:320-323` 的 CDC 未就绪状态驱动，Core 在 `core.scala:1115` 合并到 ROB stall，并在 `:2129` 送入 R_RSU）：跨域队列背压/大核暂停控制，不是架构结果；分类 `校验-配套`，副作用 `隔离`。它只能阻止继续推进，不能替代对已发出访存或设备写的回滚。
- *输入* `bigComp`（`core.scala:126`，Tile 驱动 `common/tile.scala:252`）：跨大核比较/控制编码，当前锁存到 `bigcompreg`（`core.scala:237-240`）并用于 commit log（`:1796`），分类 `校验-配套/诊断`，副作用 `无`。

= R_RSU / ARF 快照与恢复单元

R_RSU 实例化于 `/data1/gzh/EC/chipyard/generators/boom/src/main/scala/exu/core.scala:2005`；IO 叶子声明于 `/data1/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:20-52`。它保存和合并整数/浮点 ARF、PC、FCSR 及 CSR shadow，属于校验配套状态，不是 Rocket checker 的架构执行结果。

== Core 输入到 R_RSU：快照源与控制

- *输入* `rsu.arfs_in(i)`、`rsu.farfs_in(i)`（`R_RSU.scala:21-22`，Core 驱动 `core.scala:2094-2095`）：当前 ARF/FARF 寄存器阵列快照，供恢复或合并；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `rsu.pcarf_in`、`rsu.fcsr_in`、`rsu.shadowcsr_in`（`R_RSU.scala:23-25`，Core 驱动 `core.scala:2101-2102`、`:2121`）：下一 PC、FCSR 和 CSR shadow 快照；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `rsu.priv`、`rsu.excp_mode`、`rsu.snapshot_priv`、`rsu.merge_priv`（`R_RSU.scala:27-33`，Core 驱动 `core.scala:2097-2100`）：特权级、异常模式及快照/合并阶段控制；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `rsu.snapshot`、`rsu.merge`（`R_RSU.scala:30-31`，Core 驱动 `core.scala:2103`、`:2122`，其中 `merge` 来自 `snapshot_reg`）：启动快照保存和延迟合并，分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `rsu.ic_crnt_target`、`rsu.ic_old_crnt_target`、`rsu.core_trace`、`rsu.ic_trace`（`R_RSU.scala:43-44、:49-50`，Core 驱动 `core.scala:2124-2127`）：checker 目标、旧目标及跟踪开关，分类 `校验-配套/诊断`，副作用 `隔离`。
- *输入* `rsu.big_hang`（`R_RSU.scala:51`，Core 驱动 `core.scala:2129`）：GHM/CDC 队列背压，阻止 ARF 合并继续推进，分类 `校验-配套`，副作用 `隔离`。

== R_RSU 输出到 Core/GHM：合并结果与反压

- *输出* `rsu.core_hang_up`（`R_RSU.scala:36`，Core 接收于 `core.scala:2128`，并并入 ROB stall `:1115`）：ARF 快照队列无法继续处理时暂停大核，分类 `校验-配套`，副作用 `隔离`。
- *输出* `rsu.rsu_busy`（`R_RSU.scala:47`，Core 送 R_IC 于 `core.scala:2056`）：R_RSU 正在快照/合并的忙状态，影响 checker 调度，分类 `校验-配套`，副作用 `隔离+回滚`。
- *输出* `rsu.arfs_merge(i)`、`rsu.arfs_index(i)`、`rsu.arfs_pidx(i)`（`R_RSU.scala:39-45`，Core 打包到 `r_arfs/r_arfs_pidx` 于 `core.scala:2132-2133`，再经 `common/tile.scala:337` 送 GHM）：合并后的 ARF/FARF 数据、寄存器/片段索引，分类 `校验-配套`，副作用 `隔离+回滚`。这些输出没有独立 ready/valid，必须与 checker segment/sequence 一起原子接收。
- *输出* `rsu.arfs_ecp_dest`（`R_RSU.scala:48`，Core 输出 `core.scala:2130`，Tile 送 `common/tile.scala:337`）：恢复/ECP 目标位置，分类 `校验-配套`，副作用 `隔离+回滚`。
- *内部输出* `rsu.rsu_merging`、`rsu.rsu_merging_valid`（`R_RSU.scala:37-38`）：R_RSU 内部合并状态，当前没有映射到 BoomCore 顶层端口；分类 `校验-配套/未导出`，副作用 `无`（但不能据此推断 `arfs_merge` 已被 GHM 接收）。

= R_IC / checker 调度与运行时映射

R_IC 实例化于 `/boom/src/main/scala/exu/core.scala:2006`，IO 定义 `/rocket-chip/src/main/scala/r/R_IC.scala:14-70`。R_IC 的输入主要来自 GHM/RoCC 命令路由，输出再分发到 GH_BUF、GHM、DCache 和查询通道。

== R_IC 输入：运行控制与调度条件

- *输入* `icctrl[3:0]`（`core.scala:114`，R_IC 消费 `:2051-2054`，Tile 来自 `common/tile.scala:333`）：依次为 run、exit、syscall、syscall-back 控制；`syscall` 与 Core 内部检测合并，`syscall-back` 与 `mret/sret` 合并。分类 `校验-配套`，副作用 `隔离+回滚`（调度状态）。
- *输入* `if_correct_process`（`core.scala:116`，R_IC 消费 `:2083`）：当前是否处于纠错处理流程，影响指令计数和调度，分类 `校验-配套`，副作用 `隔离`。
- *输入* `num_of_checker`（`core.scala:115`，R_IC 消费 `:2070-2072`）：当前 checker 数量，同时比较上一拍值产生 `changing_num_of_checker`，改变调度边界。分类 `校验-配套`，副作用 `隔离`。
- *输入* `clear_ic_status_tomain`、`icsl_na`（`core.scala:117-118`，R_IC 消费 `:2080-2081`）：分别表示 checker 结果返回后的 owner/status 释放，以及 CDC/FIFO 容量不足；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `core_trace`、`ic_trace`（`core.scala:133-134`，R_IC/CSR/R_RSU 消费 `:2073-2074`、`:2084`、`:2126-2127`）：前者控制 Core、CSR 和快照跟踪，后者控制 R_IC 指令计数跟踪；分类 `校验-配套/诊断`，副作用 `无`。
- *输入* `big_core_id`、`checker_enable_mask`、`checker_enable_we`（`core.scala:137-139`，R_IC 消费 `:2140-2142`）：从 1 开始编码的大核身份、checker 使能位图及其写脉冲；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输入* `global_ic_status`（`core.scala:140`，R_IC 消费 `:2170`）：GHM 对各大核状态按位 OR 后的 checker 忙位图，调度器据此避免跨大核重复占用；分类 `校验-配套`，副作用 `隔离`。
- *输入* `global_checker_big_owner`（`core.scala:141`，Core 在 `:2158` 解包）：GHM 汇总的每 checker 4 位 owner 查询源；分类 `校验-配套`，副作用 `隔离`。
- *输入* `checker_state_sel`（`core.scala:129`，查询逻辑消费 `:2157-2166`）：`0` 查询持久化 checker 使能掩码；非零值是从 `1` 开始编码的 checker 编号。该值会加上 `(GH_NUM_BIG_CORES - 1)` 后直接索引状态 Vec，硬件目前没有越界保护，因此软件/命令路由必须把它限制在已配置 checker 的合法范围。分类 `校验-配套/查询`，副作用 `无`。
- *输入* `debug_perf_ctrl[6:0]`（`core.scala:120`，R_IC 消费 `:2136-2137`）：`[3:1]` 选择 R_IC 性能事件，`[0]` 复位 R_IC 计数，`[5]` 启动 DCache traffic 统计，`[6]` 停止统计并触发快照，`[4]` 当前未使用。后三个 DCache 控制连接位于 `common/tile.scala:605-607`。分类 `校验-配套/诊断`；计数选择无副作用，reset/start/stop 会改写隔离的统计协议状态。

== R_IC 输出：状态、包和查询

- *输出* `debug_maincore_status`（`core.scala:119`，驱动 `:2075`）：R_IC FSM 状态编码；Tile 以值 `2` 打开 DCache traffic check（`common/tile.scala:604`），分类 `校验-配套`，副作用 `隔离+回滚（统计窗口）`。
- *输出* `ic_crnt_target`（`core.scala:98`，驱动 `:2077`）：当前 checker 目标，既送 GH_BUF（`common/tile.scala:316`）也送 R_RSU（`core.scala:2124`），分类 `校验-配套`，副作用 `隔离+回滚`。
- *输出* `ic_status`、`ic_counter`、`checker_big_owner`、`checker_segment_id`（`core.scala:102-105`，驱动 `:2079`、`:2145-2146`、`:2169`）：状态、计数、owner 和 segment/sequence 读出，供 GHM 与状态查询使用；分类 `校验-配套`，副作用 `隔离+回滚`（接收端状态）。
- *输出* `active_packet_seq`、`packet_alloc_valid`、`packet_alloc_seq`（`core.scala:88-90`，驱动 `:2148-2150`）：包序号水位、新包分配脉冲和新序号，送 DCache（`common/tile.scala:609-611`）并经 `lsu.active_packet_seq` 进入 LSU；分类 `校验-配套`，副作用 `隔离+回滚`。
- *输出* `checker_enable_rd`（`core.scala:131`，驱动 `:2143`，Tile 经 `common/tile.scala:578` 返回命令路由）：当前持久化使能掩码的读回，分类 `校验-配套`，副作用 `无`。
- *输出* `checker_state_data`（`core.scala:130`，驱动 `:2157-2166`）：`checker_state_sel=0` 时返回低位使能掩码；非 0 时返回所选 checker 的全局 owner `[36:33]`、本地 owner `[30:27]` 和全局 busy `[26]`，其余位补零。Tile 在 `common/tile.scala:344` 返回查询端；分类 `校验-配套`，副作用 `无`。
- *输出* `debug_perf_val`（`core.scala:121`，驱动 `:2135`，Tile 在 `common/tile.scala:588` 送命令路由）：R_IC 选中的 64 位性能计数值，分类 `校验-配套/诊断`，副作用 `无`。

= RoCC / 加速器通道

`BoomCore.io.rocc = Flipped(new RoCCCoreIO())` 声明于 `/boom/src/main/scala/exu/core.scala:79`；Bundle 声明 `/rocket-chip/src/main/scala/tile/LazyRoCC.scala:43-108`。RoCC shim 在 `core.scala:1862-1876` 连接，Tile 在 `/boom/src/main/scala/common/tile.scala:520-524` 接入 command router、response arbiter 和加速器。

== 实际活动的命令、响应和异常

- *输出* `rocc.cmd.valid`、`rocc.cmd.bits.inst/rs1/rs2/status`（`LazyRoCC.scala:44`、`RoCCCommand` 叶子 `:31-36`）：RoCC shim 在 `/boom/src/main/scala/exu/execution-units/rocc.scala:138-160` 等待 uop 越过 PNR、操作数和响应队列空间后发出；Tile 在 `common/tile.scala:520` 接收。`valid && ready` 后命令可能改变加速器状态、启动 DMA 或访问设备，分类 `外部改写`，副作用 `隔离+不可回滚`。
- *输入* `rocc.cmd.ready`（`LazyRoCC.scala:44`）：command router/加速器接收许可，分类 `外部改写/握手`，副作用 `隔离`。
- *输出* `rocc.resp.ready`（`LazyRoCC.scala:45`）：BoomCore 消费加速器响应的许可；`resp.valid/bits.rd/data` 是输入，Tile 在 `common/tile.scala:522` 连接。消费会推进响应 arbiter/队列，分类 `无关/内部执行`，副作用 `隔离`。
- *输出* `rocc.exception`（`LazyRoCC.scala:49`，驱动 `core.scala:1859`，Tile 在 `common/tile.scala:521` 广播）：异常时取消尚未发出的 shim 项，分类 `外部改写/异常控制`，副作用 `隔离+回滚`；已经被加速器接受的命令不能撤销。
- *输入* `rocc.busy`、`rocc.interrupt`（`LazyRoCC.scala:47-48`，Tile 汇总于 `common/tile.scala:523-524`）：加速器忙和中断，影响 BOOM dispatch/CSR 异常，分类 `外部改写/控制输入`，副作用 `隔离`。
- *输出* `ght_prv`（`core.scala:124`，驱动 `:1953`，Tile 在 `common/tile.scala:561` 送 `cmdRouter.io.ght_sys_mode`）：延迟一拍的当前特权级上下文，分类 `校验-配套`，副作用 `无`。
- *输出* `csr_counter`（`core.scala:125`，驱动 `:562`，Tile 在 `common/tile.scala:562` 送 `cmdRouter.io.csr_counter_in`）：总提交和 CSR 写分类计数，分类 `校验-配套/诊断`，副作用 `无`。
- *输入* `bigComp`（`core.scala:126`）：GHM 广播的 3 位大核比较编码，Core 只锁存并输出到 commit log，不参与调度或结果比较，分类 `校验-配套/诊断`，副作用 `无`。
- *输出* `debug_perf_val`（`core.scala:121`，驱动 `:2135`，Tile 在 `common/tile.scala:587` 使用）：R_IC 性能值，分类 `校验-配套/诊断`，副作用 `无`。

== RoCC `mem` 与 GuardianCouncil 扩展字段

因 `core.scala:1858` 的 `io.rocc := DontCare`，`core.io.rocc.mem` 当前不是活动路径。`RoCCCoreIO.mem` 的叶子声明为 `/rocket-chip/src/main/scala/rocket/HellaCache.scala:167-188`；按外层 `Flipped` 的 BoomCore 方向，形式上的 *Core 输出* 为 `mem.req.ready`、`mem.s2_nack`、`mem.s2_nack_cause_raw`、`mem.s2_uncached`、`mem.s2_paddr`、`mem.resp.valid/bits`、`mem.replay_next`、`mem.s2_xcpt`、`mem.s2_gpa`、`mem.s2_gpa_is_pte`、`mem.uncached_resp.valid/bits`、`mem.ordered`、`mem.perf.*`、`mem.clock_enabled`；形式上的 *Core 输入* 为 `mem.req.valid/bits`、`mem.s1_kill`、`mem.s1_data`、`mem.s2_kill`、`mem.keep_clock_enabled`。这些字段当前均未形成 `core.io.rocc.mem` 活动路径，分类 `无关/未活动`，副作用 `无`。Tile 实际把每个 `rocc.module.io.mem` 经 `SimpleHellaCacheIF` 接到独立 cache 端口（`/boom/src/main/scala/common/tile.scala:432-438`），不经过 `core.io.rocc.mem`。

实际 RoCC 独立端口中的 store/AMO/MMIO 仍属于 `外部改写 / 隔离+不可回滚`；响应和 replay 属于 `隔离`。不要把 `core.io.rocc.mem` 的 `DontCare` 形式字段接入 checker。RoCC GuardianCouncil 扩展字段（`LazyRoCC.scala:50-107`）同样由 Tile 直接连接 `rocc.module.io.*` 与 `cmdRouter.io.*`（`common/tile.scala:440-490`），不是当前 BoomCore 的有效输出。

为完整列出当前 `BoomCore.io.rocc` 的形式端口：由于外层 `Flipped`，下列 *Core 输出* 是 `RAW_cnt_in`、`csr_counter_in`、`traffic_counter_in`、`ghe_packet_in`、`ghe_status_in`、`bigcore_comp`、`agg_buffer_full`、`ght_sch_refresh`、`ght_buffer_status`、`ght_satp_ppn`、`ght_sys_mode`、`debug_mcounter`、`debug_icounter`、`debug_gcounter`、`debug_bp_checker`、`debug_bp_cdc`、`debug_bp_filter`、`fi_latency`、`rsu_status_in`、`elu_data_in`、`elu_status_in`、`checker_mask_rd`、`checker_state_data`；下列 *Core 输入* 是 `ghe_event_out`、`ght_mask_out`、`ght_status_out`、`ght_cfg_out`、`ght_cfg_valid`、`debug_bp_reset`、`agg_packet_out`、`report_fi_detection_out`、`fi_sel_out`、`agg_core_status`、`ght_sch_na`、`ght_sch_dorefresh`、`if_correct_process`、`icctrl_out`、`arf_copy_out`、`s_or_r_out`、`elu_deq_out`、`elu_sel_out`、`record_pc_out`、`gtimer_reset_out`、`core_trace_out`、`record_and_store_out`、`debug_perf_ctrl`、`checker_mask_out`、`checker_mask_we`、`checker_state_sel`。这些字段在 `core.scala:1858` 的 `io.rocc := DontCare` 下均未由 BoomCore 实际驱动/消费，分类 `无关/未活动`，副作用 `无`；真正需要隔离的 RoCC 命令和设备访存只按前述 `cmd/resp` 及独立 `rocc.module.io.mem` 路径处理。

= CSRFile / 特权状态

CSRFile 实例化于 `/boom/src/main/scala/exu/core.scala:656`。

== CSR 输入与输出

- *输入到 Core/CSRFile* `hartid`（顶层 `core.scala:65`，CSR 连接 `core.scala:1471`）：硬件线程 ID，分类 `无关/配置`，副作用 `无`。
- *输入到 Core/CSRFile* `interrupts`（顶层 `core.scala:66`，CSR 连接 `core.scala:1472`）：debug、timer、software、external、local/NMI 中断，分类 `无关/控制`，触发异常/特权状态改变时需 `隔离`。
- *输出* `fcsr_rm`（顶层 `core.scala:83`，驱动 `:1465`）：FPU 舍入模式，送执行单元和 Tile RoCC-FPU（`common/tile.scala:501`），分类 `无关/配置`，副作用 `无`。
- *输出* `csr_cycle`（顶层 `core.scala:87`，驱动 `:659`）：`csr.io.time` 实时 cycle 值，Tile 送 DCache 统计，分类 `校验-配套/诊断`，副作用 `无`。
- *输出* `csr_counter(0..83)`（顶层 `core.scala:125`，驱动 `:562`）：总提交及各类 CSR 写计数，分类 `校验-配套/诊断`，副作用 `无`。

== CSR 不可回滚写入边界

`csr.io.rw.addr/cmd/wdata` 在 `core.scala:1414-1416` 由 CSR 执行单元驱动；CSR 指令通过 `csr_stall` 序列化，但 `cmd` 有效后会更新 mstatus、mepc、satp、PMP、debug CSR、FCSR 等架构状态，分类 `外部改写`，副作用 `隔离+不可回滚`。`csr.io.retire/exception`（`core.scala:1420-1421`）和 `fcsr_flags/set_fs_dirty`（`:1460-1462`）推进 CSR retire、异常上下文和 FCSR，同样不能依赖后续 checker rollback 撤销。

= Trace / 调试输出

`trace` 顶层声明于 `/boom/src/main/scala/exu/core.scala:82`，叶子 `/rocket-chip/src/main/scala/rocket/CSR.scala:242-251`，Tile 通过 `/boom/src/main/scala/common/tile.scala:385` 连接到 `traceSourceNode`。

- *输出* `trace(w).valid`（`core.scala:1882`）：`RegNext(rob.io.commit.arch_valids(w))`，比 ROB commit 晚一拍；分类 `无关/诊断`，副作用 `无`。
- *输出* `trace(w).iaddr`、`insn`、`priv`（`core.scala:1889`、`:1901`、`:1916`）：提交指令地址、指令编码和特权级，分类 `无关/诊断`，副作用 `无`。
- *输出* `trace(w).wdata`（`core.scala:1902`）：按目的寄存器类型输出写回数据，分类 `无关/诊断`，副作用 `无`。
- *输出* `trace(w).exception`、`interrupt`、`cause`、`tval`（`core.scala:1918-1921`）：异常/中断诊断信息，分类 `无关/诊断`，副作用 `无`。`valid` 与 ROB commit 不同拍，不能作为 checker 唯一提交边界。

= 面向纠错框架的连接清单

== Rocket checker 可以只读消费

当前实际进入 GH_BUF 的字段是 `commit_valids`、`commit_uops`、`prf_rd`、`jalr_target`（`common/tile.scala:294-307`）；这些应以 valid、uop 类型、`ic_crnt_target` 和包 sequence 原子打包。`r_arfs/r_arfs_pidx/arfs_ecp_dest` 是快照配套通道；`ic_status`、owner、segment、packet allocation、counter 是调度/协议元数据。

== Rocket checker 必须隔离

- IFU：`redirect_*`、`brupdate`、`commit`、`flush_icache`、`sfence` 及 FetchBuffer 握手。
- LSU/DCache：`lsu.exe.req`、`dis_uops`、`commit`、`fp_stdata`、`fence_dmem`，以及所有 DCache/TileLink 请求和 cache 私有状态。
- CSRFile：`csr.io.rw.*`、异常/retire/FCSR 更新。
- RoCC：`rocc.cmd`、实际 `rocc.module.io.mem`、响应队列消费。
- GHM/R_IC/R_RSU：GH_BUF FIFO、ARF 快照队列、owner/segment/status、packet allocation 和 traffic 统计状态。

== 副作用与回滚边界

- 可回滚：未被 LSU/DCache 接受的 load/store 请求、未提交 LDQ/STQ/ROB/rename 项、分支 mask、尚未发出的 RoCC shim 命令、尚未出队的 checker 包。
- 不可回滚：L1D data/tag/coherence 已写入、成功 SC/AMO、TileLink/MMIO 写、已接受的 RoCC 命令、CSR 写、ICache/TLB 失效以及已改变 LR/SC reservation 的操作。
- 协议状态：`ic_status`、owner/segment、`packet_alloc_*`、ARF 快照和 DCache dirty-line 归因不是应用内存，但错误包必须整体 cancel/release，不能只回滚包的一部分。

当前源码没有看到“checker 通过后才允许 store/SC/AMO/MMIO/CSR/RoCC 发出”的统一门控。因此，仅把 Rocket checker 接到提交输出并不能实现外部状态回滚；若纠错要求失败后恢复这些状态，必须增加延迟提交、私有 speculative buffer 或等价的资源隔离机制。

== 关键声明位置索引

#table(
  columns: (2.4fr, 2.5fr, 2.8fr),
  table.header([*部件*], [*BoomCore 入口*], [*Bundle/最小字段声明*]),
  [`ifu`], [`core.scala:69`], [`/boom/src/main/scala/ifu/frontend.scala:257-289`],
  [`ptw` / `ptw_tlb`], [`core.scala:72-73`], [`/rocket-chip/src/main/scala/rocket/PTW.scala:71-112`],
  [`lsu`], [`core.scala:76`], [`/boom/src/main/scala/lsu/lsu.scala:61-70`、`:140-190`],
  [`GH_BUF`], [`core.scala:94-99`], [`/boom/src/main/scala/trans/GH_BUF.scala:30-50`],
  [`GHM`], [`core.scala:102-105`、`:117-118`、`:140-141`], [`/boom/src/main/scala/common/tile.scala:224-246`、`:337-354`],
  [`R_RSU`], [`core.scala:108-111`、`:2005`], [`/rocket-chip/src/main/scala/r/R_RSU.scala:20-52`],
  [`R_IC`], [`core.scala:88-90`、`:98`、`:114-141`、`:2006`], [`/rocket-chip/src/main/scala/r/R_IC.scala:14-70`],
  [`RoCC`], [`core.scala:79`、`:121`、`:124-131`], [`/rocket-chip/src/main/scala/tile/LazyRoCC.scala:31-108`],
  [`CSRFile`], [`core.scala:65-66`、`:83`、`:87`、`:125`], [`/rocket-chip/src/main/scala/rocket/CSR.scala:242-251`],
  [`DCache`], [`core.scala:87-90`、`:119`], [`/boom/src/main/scala/lsu/dcache.scala:424-434`、`:515-517`],
)

== 结论

按当前接口，Rocket 小核应只读消费 BOOM 的提交级指令/结果和校验协议元数据；IFU、LSU/DCache、CSRFile、RoCC 及其私有队列/缓存/设备资源必须隔离。尤其是 store、成功 SC、AMO、MMIO、CSR 写和已接受的 RoCC 命令，一旦越过外部接受点就不能依赖 BOOM rollback 撤销。
