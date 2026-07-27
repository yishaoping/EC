//==============================================================================
// GH_BUF — Guardian Heart Buffer（守护之心缓冲区）
//==============================================================================
// 功能概述：
//   GH_BUF 是 Guardian Council（守护者委员会）子系统的核心模块，位于 BOOM 大核
//   ROB Commit 阶段与 GHE/GHM 校验管理器之间。它负责：
//
//   1. 收集 BOOM 大核每条提交指令的关键信息（PC、分支目标、ALU 结果、CSR 数据等）
//   2. 按照指令类型进行过滤和分类编码（load/store/csr/branch）
//   3. 将过滤后的指令信息打包成 GC 校验包（Guardian Council Packet）
//   4. 通过 core_width 路 GH_FIFO 缓冲区进行流水化缓冲
//   5. 每个周期出队 GH_TOTAL_PACKETS（默认 2）个校验包，发送给 GHE/GHM
//   6. 提供反压信号（core_hang_up）防止 FIFO 溢出导致丢包
//
// 架构位置：
//   BOOM ROB Commit --> GH_BUF --> GHE (RoCC) --> GHM --> CDC Bridge --> Rocket Checkers
//
// 命名约定：
//   GH  = Guardian Heart（守护之心）
//   GHE = Guardian Heart Engine（RoCC 加速器，校验控制）
//   GHM = Guardian Heart Manager（校验包管理分发）
//   GHT = Guardian Heart Table（校验调度表）
//==============================================================================

package boom.trans

import boom.exu._
import boom.ifu._
import boom.lsu._
import boom.util._
import boom.util.{ImmGen}
import boom.common._

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.guardiancouncil._
import freechips.rocketchip.rocket._
import freechips.rocketchip.util._

//==============================================================================
// GH_BUF_Params — GH_BUF 配置参数
//==============================================================================
// xlen        : RISC-V 位宽（32/64），决定寄存器宽度
// packet_size : 单个 GC 校验包的总位宽 = 2*GH_WIDITH_PERF + 8 + 8 = 2*xlen + 16
//               (136 bit for RV64: 128bit数据 + 8bit指令类型 + 8bit目标核心)
// core_width  : BOOM 大核的提交宽度（v0Config 中为 6-wide）
// use_prfs    : 是否使用物理寄存器堆（Physical Register File）
//==============================================================================
case class GH_BUF_Params(
  xlen: Int,
  packet_size: Int,
  core_width: Int,
  use_prfs: Boolean
)

//==============================================================================
// GH_BUF_IO — GH_BUF 模块的 IO 端口定义
//==============================================================================
// --- 来自大核 ROB Commit 的输入 ---
// commit_valids : 每条流水线的提交有效信号
// commit_uops   : 每条流水线的微操作（MicroOp），包含指令类型、PC、立即数等
// jalr_target   : JALR 指令的跳转目标地址（由 ALU 计算）
// alu_in        : ALU 的输入/输出数据（用于 load/store 地址和数据）
// gh_prfs_rd    : CSR 读数据 / 物理寄存器堆读数据
//
// --- 来自 CDC / GHT 的控制输入 ---
// cdc_not_ready  : CDC 跨时钟域 FIFO 未就绪（反压信号，阻止出队）
// ic_crnt_target : 当前 IC（Instruction Counter）目标核心编号
// gh_can_fwd     : GHE 允许转发标志（=0 表示允许转发新包）
//
// --- 输出到 GHE/GHM ---
// packet_out      : 拼接后的 GC 校验包输出（GH_TOTAL_PACKETS * packet_size 位）
// gh_packet_dest  : 校验包目标 Checker 核心的 one-hot 编码
//
// --- 状态反馈 ---
// core_hang_up      : 大核挂起信号（FIFO 近满，需暂停 ROB Commit）
// ght_filters_empty : 所有 filter FIFO 均为空（通知 GHT 无待发送数据）
// ght_buffer_status : 缓冲区状态（{FIFO_full, all_empty}），供 GHT 调度使用
//==============================================================================
class GH_BUF_IO (params: GH_BUF_Params)(implicit p: Parameters) extends Bundle {
  // --- 大核 ROB Commit 输入 ---
  val commit_valids                             = Input(Vec(params.core_width, Bool()))
  val commit_uops                               = Input(Vec(params.core_width, new MicroOp()))
  val jalr_target                               = Input(Vec(params.core_width, UInt(params.xlen.W)))
  val alu_in                                    = Input(Vec(params.core_width, UInt((2*params.xlen).W)))
  val gh_prfs_rd                                = Input(Vec(params.core_width, UInt(params.xlen.W)))  // CSR 读数据

  // --- 控制输入 ---
  val cdc_not_ready                             = Input(Bool())

  // --- GC 校验包输出 ---
  val packet_out                                = Output(UInt((GH_GlobalParams.GH_TOTAL_PACKETS*(params.packet_size)).W))
  val gh_packet_dest                            = Output(UInt((GH_GlobalParams.GH_NUM_CORES-1).W))                                     

  // --- 状态输出 ---
  val core_hang_up                              = Output(UInt(1.W))
  val ght_filters_empty                         = Output(UInt(1.W))

  /* R Features — 可靠性相关特性 */
  val ic_crnt_target                            = Input(UInt(5.W))   // 当前 IC 目标核心（低4位为核心号，高1位使能）
  val gh_can_fwd                                = Input(UInt(1.W))   // GHE 允许转发
  val ght_buffer_status                         = Output(UInt(2.W))  // 缓冲区状态
}

//==============================================================================
// GH_BUF 主体实现
//==============================================================================
// 数据流：
//   Commit UOPs → 指令分类/过滤 → filter_packet 打包 → u_buffer (FIFO) → 轮询出队 → packet_out
//
// 关键设计要点：
//   1. Round-Robin 入队：core_width 条流水线的有效包按顺序写入 core_width 个 FIFO
//   2. Round-Robin 出队：每次最多出队 GH_TOTAL_PACKETS 个包
//   3. 反压机制：FIFO 剩余 ≤ 3 个 slot 时拉高 core_hang_up，暂停大核提交
//   4. 包格式：{dest_core(8bit), inst_type(8bit), payload(2*xlen bit)}
//==============================================================================
class GH_BUF (val params: GH_BUF_Params)(implicit p: Parameters) extends BoomModule
{
  val io = IO(new GH_BUF_IO(params)(p))

  // 缓冲区数据位宽：2 个 xlen（数据） + 8 bit（指令类型编码）
  val buffer_width                              = (2*params.xlen+8)

  //============================================================================
  // 第一阶段：指令分类与信号提取
  // 对每条流水线上的 commit uop 进行分类，提取关键信息
  //============================================================================

  // CSR 指令的目标 CSR 地址（12-bit）
  val csr_addr                                  = Wire(Vec(params.core_width, UInt(12.W)))
  // 是否为分支/跳转指令（BR || JAL || JALR）
  val is_branch                                 = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  // 分支是否 taken（条件分支 taken || JAL || JALR）
  val is_taken                                  = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  // 是否为 RVC（压缩指令，16-bit）
  val is_rvc                                    = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  // 分支/跳转的目标地址
  val branch_target_addr                        = WireInit(VecInit(Seq.fill(params.core_width)(0.U(params.xlen.W))))
  dontTouch(is_branch)
  dontTouch(branch_target_addr)
  
  // core_width 路 GH_FIFO 缓冲区，每路深度 32，宽度 = packet_size
  // 这些 FIFO 作为流水化缓冲，吸收大核提交速率的波动
  val u_buffer                                  = Seq.fill(params.core_width) {Module(new GH_FIFO(FIFOParams (params.packet_size, 32)))}
  // 每路是否可以转发（指令类型符合过滤条件 且 GHE 允许转发）
  val can_fwd                                   = WireInit(VecInit.fill(params.core_width)(false.B))

  // 大核挂起信号：取最后一路 FIFO 的\"仅剩 3 个 slot\"状态
  // 当 FIFO 近满时暂停 ROB Commit，防止丢包
  val core_hang_up                              = u_buffer(params.core_width-1).io.status_threeslots

  //============================================================================
  // filter 阶段：指令类型编码与数据打包
  //============================================================================
  // filter_inst_index : 8-bit 过滤索引 = {ic_enable(1bit), dest_core(4bit), inst_type(3bit)}
  // inst_type_enc     : 3-bit 指令类型编码
  //                     0 = 不转发（系统指令等）
  //                     1 = Load（加载指令）
  //                     2 = Store（存储指令）
  //                     3 = CSR（控制和状态寄存器指令，非影子 CSR）
  //                     4 = Branch/Jump（分支跳转指令）
  // filter_packet     : 2*xlen bit 有效载荷数据
  // one               : IC 目标核心使能位（ic_crnt_target[3:0] != 0 时有效）
  // dest_OH           : 目标 Checker 核心的 one-hot 编码
  //============================================================================
  val filter_inst_index                         = WireInit(VecInit(Seq.fill(params.core_width)(0.U(8.W))))
  val inst_type_enc                             = WireInit(VecInit(Seq.fill(params.core_width)(0.U(3.W))))
  val filter_packet                             = WireInit(VecInit(Seq.fill(params.core_width)(0.U((2*params.xlen).W))))
  val one                                       = Mux(io.ic_crnt_target(3,0) === 0.U, 0.U, 1.U)
  val dest_OH                                   = WireInit(0.U((GH_GlobalParams.GH_NUM_CORES-1).W))
  val is_amo                                    = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  // 将 IC 目标核心号转换为 one-hot 编码（核心号从 1 开始，0 表示无目标）
  dest_OH                                      := Mux(io.ic_crnt_target(3,0) === 0.U, 0.U, UIntToOH(io.ic_crnt_target(3,0)-1.U))
  dontTouch(dest_OH)
  dontTouch(inst_type_enc)
  //============================================================================
  // 逐条流水线处理：指令分类、目标地址计算、过滤条件判断、数据打包
  //============================================================================
  for(i <- 0 until params.core_width){
    // --- 基础指令属性提取 ---
    // AMO（原子内存操作）检测
    is_amo(i)                                  := io.commit_valids(i)&&io.commit_uops(i).is_amo
    // CSR 地址提取
    csr_addr(i)                                := io.commit_uops(i).csr_addr
    // 分支指令：BR、JAL、JALR
    is_branch(i)                               := io.commit_valids(i) && (io.commit_uops(i).is_br || io.commit_uops(i).is_jal || io.commit_uops(i).is_jalr)
    // 分支 taken：条件分支且 taken、或无条件跳转 JAL/JALR
    is_taken(i)                                := io.commit_valids(i) && ((io.commit_uops(i).is_br && io.commit_uops(i).taken) || io.commit_uops(i).is_jal || io.commit_uops(i).is_jalr)
    // RVC 压缩指令
    is_rvc(i)                                  := io.commit_valids(i) && io.commit_uops(i).is_rvc

    // --- 分支目标地址计算 ---
    // 根据指令类型计算下一条指令的 PC
    val uop = io.commit_uops(i)
    val imm_xprlen = ImmGen(uop.imm_packed, uop.ctrl.imm_sel)  // 立即数生成
    val imm_signed = imm_xprlen.asSInt                          // 有符号立即数
    val pc = uop.debug_pc                                       // 当前指令 PC
    val npc = pc + Mux(uop.is_rvc, 2.U, 4.U)                   // 顺序下一条 PC（RVC=+2, 普通=+4）
    
    when(io.commit_valids(i) && uop.is_br) {
      // 条件分支：taken 时 PC+offset，否则顺序执行
      branch_target_addr(i) := Mux(uop.taken, 
        (pc.asSInt + imm_signed).asUInt,
        npc)
    }.elsewhen(io.commit_valids(i) && uop.is_jal) {
      // JAL：PC + 有符号偏移
      branch_target_addr(i) := (pc.asSInt + imm_signed).asUInt
    }.elsewhen(io.commit_valids(i) && uop.is_jalr) {
      // JALR：来自 ALU 计算的跳转目标（rs1 + imm），最低位清零对齐
      branch_target_addr(i) := io.jalr_target(i)
    }.otherwise {
      branch_target_addr(i) := 0.U
    }

    // --- 指令类型编码（3-bit）---
    // 用于 Checker 核心识别该校验包对应的指令类型
    inst_type_enc(i)                           := MuxCase(0.U, 
                                                      Seq((io.commit_valids(i)&&io.commit_uops(i).uses_ldq) -> 1.U,
                                                          (io.commit_valids(i)&&io.commit_uops(i).uses_stq) -> 2.U,
                                                          (io.commit_valids(i)&&io.commit_uops(i).is_csr&&(!(csr_addr(i)).isOneOf(CSRshadows.csrshadow_seq))) -> 3.U,
                                                          (is_branch(i)) -> 4.U
                                                          ))
                                                            
    // --- 转发条件判断 ---
    // can_fwd = GHE允许转发 && 指令有效 && 属于可校验类型
    // 可校验类型：load、store（非 fence）、CSR（非影子 CSR）、branch/jump
    can_fwd(i)                                 := (io.gh_can_fwd===0.U) && io.commit_valids(i) && (io.commit_uops(i).uses_ldq || (io.commit_uops(i).uses_stq && !io.commit_uops(i).is_fence) || io.commit_valids(i) && io.commit_uops(i).is_csr && (!(csr_addr(i)).isOneOf(CSRshadows.csrshadow_seq)) || is_branch(i))

    // --- 过滤索引：{ic_enable, dest_core[3:0], inst_type[2:0]} ---
    // 如果 can_fwd 为真，生成带目标核心和指令类型的索引；否则为 0（不转发）
    filter_inst_index(i)                       := Mux(can_fwd(i), Cat(one, io.ic_crnt_target(3,0),inst_type_enc(i)), 0.U)

    // --- 数据包载荷打包 ---
    // 根据不同指令类型，将不同的数据拼接为 2*xlen bit 的 payload
    filter_packet(i)                           := MuxCase(0.U, 
                                                      Seq(
                                                        // Load：ALU 结果（load 地址 + 数据）
                                                        (io.commit_valids(i)&&io.commit_uops(i).uses_ldq) -> io.alu_in(i),
                                                        // Store（非 AMO）：ALU 结果（store 地址 + 数据）
                                                        (io.commit_valids(i)&&io.commit_uops(i).uses_stq&(!is_amo(i))) -> io.alu_in(i),
                                                        // Store AMO：{CSR/PRF 读数据, ALU 低 64 位}
                                                        (io.commit_valids(i)&&io.commit_uops(i).uses_stq&(is_amo(i)))  -> Cat(io.gh_prfs_rd(i),io.alu_in(i)(63,0)),
                                                        // CSR：CSR/PRF 读数据
                                                        (io.commit_valids(i)&&io.commit_uops(i).is_csr&&(!(csr_addr(i)).isOneOf(CSRshadows.csrshadow_seq))) -> io.gh_prfs_rd(i),
                                                        // Branch/Jump：{padding, is_rvc, is_taken, debug_pc, branch_target}
                                                        (is_branch(i)) -> Cat(0.U((params.xlen - coreMaxAddrBits - 2).W), is_rvc(i), is_taken(i), io.commit_uops(i).debug_pc, branch_target_addr(i))
                                                      ))
  }
  dontTouch(filter_packet)

  //============================================================================
  // 第二阶段：缓冲入队（Enqueue）
  //============================================================================
  // 使用 Round-Robin 策略将 core_width 条流水线的有效包轮流写入 core_width 个 FIFO
  // buffer_enq_ptr : 当前入队指针（Round-Robin 写指针）
  // new_packet     : 标记每条流水线是否产生了新的有效校验包
  // numEnq         : 本周期新包总数（PopCount of new_packet）
  //============================================================================

  // FIFO 接口信号
  val buffer_enq_valid                          = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_enq_data                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U(((params.packet_size)).W))))
  val buffer_empty                              = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_full                               = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_deq_data                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U((params.packet_size).W))))
  val buffer_deq_valid                          = WireInit(false.B)
  val is_valid_packet                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U(13.W))))

  // 是否有新的有效包（filter_inst_index 的目标核心字段非零）
  val new_packet                                = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))

  // 出队后的指令类型和数据
  val buffer_inst_type                          = WireInit(VecInit(Seq.fill(params.core_width)(0.U(8.W))))
  val bp                                        = WireInit(VecInit(Seq.fill(params.core_width)(0.U((2*(params.xlen)).W))))
  val doPull                                    = WireInit(0.U(1.W))

  // Round-Robin 入队/出队指针（多 1 bit 防止溢出）
  val buffer_enq_ptr                            = RegInit(0.U((log2Ceil(params.core_width)+1).W))
  val buffer_deq_ptr                            = RegInit(0.U((log2Ceil(params.core_width)+1).W))
  dontTouch(new_packet)

  // 统计本周期新产生的有效包数量
  val numEnq = WireInit(PopCount(new_packet))

  for (i <- 0 to params.core_width - 1) {
    // 判断是否产生新包：filter_inst_index[6:3]（目标核心号）非零
    new_packet(i)                              := (filter_inst_index(i)(6,3) =/= 0.U)
    // 入队数据格式：{filter_inst_index(8bit), filter_packet(2*xlen bit)}
    // filter_inst_index 包含目标核心号和指令类型
    buffer_enq_data(i)                         := Mux((filter_inst_index(i)(6,3) =/= 0.U) ,  
                                                    Cat(filter_inst_index(i), filter_packet(i)), 0.U)
  }

  // 更新入队指针：Round-Robin，处理回绕（wraparound）
  when(new_packet.reduce(_|_)){
    buffer_enq_ptr := Mux(buffer_enq_ptr + numEnq>=params.core_width.U,buffer_enq_ptr+numEnq-params.core_width.U,buffer_enq_ptr + numEnq)
  }

  // 计算每条流水线对应的 FIFO 索引
  // enq_idxs[i] : 前 i 条流水线中有多少个新包（累积计数，用于分配 FIFO 槽位）
  // enq_offset[i] : 第 i 个新包应该写入的 FIFO 编号
  val enq_idxs    = VecInit.tabulate(params.core_width)(i => PopCount(new_packet.take(i)))
  val enq_offset  = enq_idxs.map(i=>Mux(buffer_enq_ptr + i>=params.core_width.U,buffer_enq_ptr+i-params.core_width.U,buffer_enq_ptr+i))

  // 将新包分发到对应的 FIFO
  for (i <- 0 to params.core_width - 1) {
    // 检查第 i 个 FIFO 是否被某个新包选中
    val enq_OH    = (0 until params.core_width).map(idx => (enq_offset(idx) === i.U)&(new_packet(idx)))
    // 选择对应的入队数据
    val enq_data  = Mux1H(enq_OH, buffer_enq_data) 
    // 写入 FIFO
    u_buffer(i).io.enq_valid                   := enq_OH.reduce(_|_)
    u_buffer(i).io.enq_bits                    := enq_data
  }

  
  //============================================================================
  // 第三阶段：缓冲出队（Dequeue）
  //============================================================================
  // 使用 Round-Robin 策略从 core_width 个 FIFO 中轮流取出 GH_TOTAL_PACKETS 个包
  // buffer_deq_ptr : 当前出队指针
  // deq_idxs       : 本轮要出队的 FIFO 编号列表（最多 GH_TOTAL_PACKETS 个）
  // numDeq         : 本周期实际出队的包数
  //============================================================================

  /* Buffer 状态机 */
  val buf_all_empty     = WireInit(buffer_empty.reduce(_&_))          // 所有 FIFO 全空
  val buf_almost_empty  = WireInit(PopCount(buffer_empty)>2.U)       // 超过 2 个 FIFO 为空（凑不齐 2 个包）
  val buf_deq_valid     = (!buf_all_empty)                            // 至少有一个 FIFO 非空时可出队

  // 计算本轮出队的 FIFO 索引（Round-Robin，处理回绕）
  val deq_idxs          = VecInit.tabulate(GH_GlobalParams.GH_TOTAL_PACKETS)(i => Mux(buffer_deq_ptr+i.U>=params.core_width.U,buffer_deq_ptr+i.U-params.core_width.U,buffer_deq_ptr+i.U))
  dontTouch(deq_idxs)
  dontTouch(buf_deq_valid)

  // 生成出队 one-hot 选择信号
  // deq_OH[packet_idx][fifo_idx] : 第 packet_idx 个出队包是否来自第 fifo_idx 个 FIFO
  val deq_OH= (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{i=>
    (0 until params.core_width).map{j=>
      j.U===Mux(buffer_deq_ptr+i.U>=params.core_width.U,buffer_deq_ptr+i.U-params.core_width.U,buffer_deq_ptr+i.U)
    }
  }

  val deq_valid = WireInit(VecInit.fill(params.core_width)(false.B))
  val numDeq    = WireInit(PopCount(deq_valid))
  // 安全检查：每周期出队不能超过 GH_TOTAL_PACKETS 个
  assert(numDeq<=GH_GlobalParams.GH_TOTAL_PACKETS.U,"Deq too much packet")

  for (i <- 0 to params.core_width - 1) {
    // 出队条件：buf_deq_valid && 当前 FIFO 被选中 && FIFO 非空 && CDC 就绪
    deq_valid(i)                               := (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{idx=>
      buf_deq_valid&&deq_idxs(idx)===i.U&&(!buffer_empty(i))&&(!io.cdc_not_ready)
    }.reduce(_|_)

    // 读取 FIFO 状态
    buffer_empty(i)                            := u_buffer(i).io.empty
    buffer_full(i)                             := u_buffer(i).io.full

    // 出队数据提取
    buffer_deq_data(i)                         := Mux(deq_valid(i),u_buffer(i).io.deq_bits,0.U)
    // 从出队数据中分离：指令类型（高 8 bit）和数据负载（低 2*xlen bit）
    buffer_inst_type(i)                        := buffer_deq_data(i)(buffer_width - 1, (2*params.xlen))
    bp(i)                                      := buffer_deq_data(i)((2*params.xlen) - 1, 0)

    // 通知 FIFO 出队
    u_buffer(i).io.deq_ready                   := deq_valid(i)

    // 标记是否为有效包（指令类型非零）
    is_valid_packet(i)                         := Mux(buffer_inst_type(i) =/= 0.U, 1.U, 0.U)
  }


  //============================================================================
  // 第四阶段：输出拼接与状态输出
  //============================================================================
  // 将 GH_TOTAL_PACKETS 个出队包拼接为最终输出
  // 同时生成目标核心的 one-hot 编码和状态信号
  //============================================================================

  // 输出缓冲：按出队包分别存放数据负载和指令类型
  val out_buf                                   = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(((2*params.xlen)).W))))
  val out_inst_type                             = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((8).W))))
  val packet_out                                = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((params.packet_size).W))))

  // 根据 deq_OH 选择对应的数据和指令类型
  for(i <- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
    out_buf(i)        := Mux1H(deq_OH(i),bp)              // 选择数据负载
    out_inst_type(i)  := Mux1H(deq_OH(i),buffer_inst_type) // 选择指令类型
    // 拼接最终包：{inst_type(8bit), payload(2*xlen bit)}
    packet_out(i)     := Cat(out_inst_type(i),out_buf(i))
  }
  dontTouch(out_buf)
  dontTouch(out_inst_type)
  dontTouch(packet_out)

  // 更新出队指针（Round-Robin，处理回绕）
  when(deq_valid.reduce(_|_)){
    buffer_deq_ptr := Mux(buffer_deq_ptr + numDeq>=params.core_width.U,buffer_deq_ptr+numDeq-params.core_width.U,buffer_deq_ptr + numDeq)
  }

  //============================================================================
  // 输出端口连接
  //============================================================================
  // packet_out       : 将所有出队包按高位在前拼接后输出到 GHE
  // core_hang_up     : 大核挂起信号，FIFO 近满时阻止 ROB Commit
  // ght_buffer_status: {FIFO_full, all_empty}，供 GHT 调度
  // ght_filters_empty: 所有 FIFO 空，无待发送数据
  // gh_packet_dest   : 目标 Checker 核心的 one-hot 编码（所有出队包的目标 OR）
  io.packet_out                               := Cat(packet_out.reverse) // 高位在前拼接，包含 inst_type 供 Checker 核心识别
  io.core_hang_up                             := core_hang_up 
  io.ght_buffer_status                        := Cat(buffer_full(params.core_width-1), buf_all_empty)
  io.ght_filters_empty                        := buf_all_empty
  io.gh_packet_dest                           := out_inst_type.map(i=>i(6,3)).reduce(_|_)  // 所有出队包的目标核心 OR
}