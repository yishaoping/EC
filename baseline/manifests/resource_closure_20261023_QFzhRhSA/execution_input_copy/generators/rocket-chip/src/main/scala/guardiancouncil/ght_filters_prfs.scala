package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}

//==========================================================
// Parameters
//==========================================================
case class GHT_FILTERS_PRFS_Params(
  xlen: Int,
  packet_size: Int,
  core_width: Int,
  use_prfs: Boolean
)

//==========================================================
// I/Os
//==========================================================
class GHT_FILTERS_PRFS_IO (params: GHT_FILTERS_PRFS_Params) extends Bundle {
  val ght_ft_cfg_in                             = Input(UInt(32.W))
  val ght_ft_cfg_valid                          = Input(UInt(1.W))

  val ght_ft_inst_in                            = Input(Vec(params.core_width, UInt(32.W)))
  val ght_ft_pc_in                              = Input(Vec(params.core_width, UInt(32.W)))
  val ght_ft_newcommit_in                       = Input(Vec(params.core_width, Bool()))
  val ght_ft_alu_in                             = Input(Vec(params.core_width, UInt((2*params.xlen).W)))
  val ght_ft_is_rvc_in                          = Input(Vec(params.core_width, UInt(1.W)))

  val ght_ft_inst_index                         = Output(UInt(8.W))
  val packet_out                                = Output(UInt((GH_GlobalParams.GH_TOTAL_PACKETS*(params.packet_size)).W))

  // val ght_stall                                 = Input(Bool())
  val core_hang_up                              = Output(UInt(1.W))
  val ght_buffer_status                         = Output(UInt(2.W))
  val ght_prfs_rd_ft                            = Input(Vec(params.core_width, UInt(params.xlen.W)))
  val ght_csr_addr_ft                           = Input(Vec(params.core_width, UInt(12.W)))

  val ght_prfs_forward_ldq                      = Output(Vec(params.core_width, Bool()))
  val ght_prfs_forward_stq                      = Output(Vec(params.core_width, Bool()))
  val ght_prfs_forward_ftq                      = Output(Vec(params.core_width, Bool()))
  val ght_prfs_forward_prf                      = Output(Vec(params.core_width, Bool()))

  val ght_filters_empty                         = Output(UInt(1.W))
  val debug_filter_width                        = Input(UInt(4.W))

  /* R Features */
  val ght_filters_ready                         = Output(UInt(1.W))
  val core_r_arfs                               = Input(Vec(params.core_width, UInt(params.packet_size.W)))
  val core_r_arfs_index                         = Input(Vec(params.core_width, UInt(8.W)))
  val rsu_merging                               = Input(UInt(1.W))
  val ic_crnt_target                            = Input(UInt(5.W)) 
  val gtimer                                    = Input(UInt(62.W))
  val gtimer_reset                              = Input(UInt(1.W))
  val use_fi_mode                               = Input(UInt(1.W))
}



trait HasGHT_FILTERS_PRFS_IO extends BaseModule {
  val params: GHT_FILTERS_PRFS_Params
  val io = IO(new GHT_FILTERS_PRFS_IO(params))
}

//==========================================================
// Implementations
//==========================================================
class GHT_FILTERS_PRFS (val params: GHT_FILTERS_PRFS_Params) extends Module with HasGHT_FILTERS_PRFS_IO
{
  // val numPackets                                = 2
  val buffer_width                              = (2*params.xlen+8)

  // val u_ght_filters                             = Seq.fill(params.core_width) {Module(new GHT_FILTER_PRFS(GHT_FILTER_PRFS_Params(params.xlen, params.packet_size, params.use_prfs)))}
  //
  val u_ght_filters = Seq.tabulate(params.core_width) { id =>
    Module(new GHT_FILTER_PRFS(GHT_FILTER_PRFS_Params(params.xlen, params.packet_size, params.use_prfs, id)))
  }
  
  val u_buffer                                  = Seq.fill(params.core_width) {Module(new GH_FIFO(FIFOParams (params.packet_size, 32)))}
  

  val core_hang_up                              = u_buffer(params.core_width-1).io.status_threeslots

  // Connecting filters
  val filter_inst_index                         = WireInit(VecInit(Seq.fill(params.core_width)(0.U(8.W))))
  val filter_packet                             = WireInit(VecInit(Seq.fill(params.core_width)(0.U((2*params.xlen).W))))
  for (i <- 0 to params.core_width - 1) {
    u_ght_filters(i).io.ic_crnt_target         := this.io.ic_crnt_target
    u_ght_filters(i).io.ght_ft_cfg_in          := this.io.ght_ft_cfg_in
    u_ght_filters(i).io.ght_ft_cfg_valid       := this.io.ght_ft_cfg_valid
    u_ght_filters(i).io.ght_ft_inst_in         := this.io.ght_ft_inst_in(i)
    u_ght_filters(i).io.ght_ft_pc_in           := this.io.ght_ft_pc_in(i)
    u_ght_filters(i).io.ght_ft_newcommit_in    := this.io.ght_ft_newcommit_in(i)
    u_ght_filters(i).io.ght_ft_alu_in          := this.io.ght_ft_alu_in(i)
    u_ght_filters(i).io.ght_ft_is_rvc_in       := this.io.ght_ft_is_rvc_in(i)
    u_ght_filters(i).io.gtimer                 := this.io.gtimer
    u_ght_filters(i).io.gtimer_reset           := this.io.gtimer_reset
    u_ght_filters(i).io.use_fi_mode            := this.io.use_fi_mode
    u_ght_filters(i).io.ght_csr_addr_in        := this.io.ght_csr_addr_ft(i)

    filter_inst_index(i)                       := u_ght_filters(i).io.ght_ft_inst_index
    filter_packet(i)                           := u_ght_filters(i).io.packet_out
    u_ght_filters(i).io.ght_prfs_rd            := this.io.ght_prfs_rd_ft(i)
    if (params.use_prfs) {
      this.io.ght_prfs_forward_ldq(i)          := u_ght_filters(i).io.ght_prfs_forward_ldq
      this.io.ght_prfs_forward_stq(i)          := u_ght_filters(i).io.ght_prfs_forward_stq
      this.io.ght_prfs_forward_ftq(i)          := u_ght_filters(i).io.ght_prfs_forward_ftq
      this.io.ght_prfs_forward_prf(i)          := u_ght_filters(i).io.ght_prfs_forward_prf
    } else {
      this.io.ght_prfs_forward_ldq(i)          := false.B
      this.io.ght_prfs_forward_stq(i)          := false.B
      this.io.ght_prfs_forward_ftq(i)          := false.B
      this.io.ght_prfs_forward_prf(i)          := false.B
    }
  }

  // Connecting buffers: Enqueue Phase
  val buffer_enq_valid                          = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_enq_data                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U(((params.packet_size)).W))))
  val buffer_empty                              = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_full                               = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))
  val buffer_deq_data                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U((params.packet_size).W))))
  val buffer_deq_valid                          = WireInit(false.B)
  val is_valid_packet                           = WireInit(VecInit(Seq.fill(params.core_width)(0.U(13.W))))

  val new_packet                                = WireInit(VecInit(Seq.fill(params.core_width)(false.B)))

  val buffer_inst_type                          = WireInit(VecInit(Seq.fill(params.core_width)(0.U(8.W))))
  val bp                                        = WireInit(VecInit(Seq.fill(params.core_width)(0.U((2*(params.xlen)).W))))
  val doPull                                    = WireInit(0.U(1.W))

  val buffer_enq_ptr                            = RegInit(0.U((log2Ceil(params.core_width)+1).W))//to avoid overflow
  val buffer_deq_ptr                            = RegInit(0.U((log2Ceil(params.core_width)+1).W))
  dontTouch(new_packet)

  val numEnq = WireInit(PopCount(new_packet))
  for (i <- 0 to params.core_width - 1) {
    new_packet(i)                              := filter_packet(i) =/= 0.U         //判断一个new_packet这样是否合理？                                    
    buffer_enq_data(i)                         := Mux(((filter_inst_index(i) =/= 0.U) && (filter_packet(i) =/= 0.U)),  
                                                    Cat(filter_inst_index(i), filter_packet(i)), 0.U)//包含目的核心
  }
  //有新数据
  when(new_packet.reduce(_|_)){//需要保证回绕正确
    buffer_enq_ptr := Mux(buffer_enq_ptr + numEnq>=params.core_width.U,buffer_enq_ptr+numEnq-params.core_width.U,buffer_enq_ptr + numEnq)
  }
  val enq_idxs    = VecInit.tabulate(params.core_width)(i => PopCount(new_packet.take(i)))
  val enq_offset  = enq_idxs.map(i=>Mux(buffer_enq_ptr + i>=params.core_width.U,buffer_enq_ptr+i-params.core_width.U,buffer_enq_ptr+i))
  for (i <- 0 to params.core_width - 1) {
    val enq_OH    = (0 until params.core_width).map(idx => (enq_offset(idx) === i.U)&(new_packet(idx)))
    val enq_data  = Mux1H(enq_OH, buffer_enq_data) 
    u_buffer(i).io.enq_valid                   := enq_OH.reduce(_|_)//四个buffer共享入队信号？有可能会出现无效的数据？
    u_buffer(i).io.enq_bits                    := enq_data
  }

  
  // Connecting buffers: Dequeue Phase
  /* Buffer Finite State Machine */
  val buf_all_empty     = WireInit(buffer_empty.reduce(_&_))//全部fifo空
  val buf_almost_empty  = WireInit(PopCount(buffer_empty)>2.U)//此时凑不齐两个data
  val buf_deq_valid     = (!buf_all_empty)


  //这里有重复逻辑!!!
  val deq_idxs          = VecInit.tabulate(GH_GlobalParams.GH_TOTAL_PACKETS)(i => Mux(buffer_deq_ptr+i.U>=params.core_width.U,buffer_deq_ptr+i.U-params.core_width.U,buffer_deq_ptr+i.U))
  dontTouch(deq_idxs)
  dontTouch(buf_deq_valid)
  //vec
  val deq_OH= (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{i=>
    (0 until params.core_width).map{j=>
      j.U===Mux(buffer_deq_ptr+i.U>=params.core_width.U,buffer_deq_ptr+i.U-params.core_width.U,buffer_deq_ptr+i.U)
    }
  }
  val deq_valid = WireInit(VecInit.fill(params.core_width)(false.B))
  val numDeq    = WireInit(PopCount(deq_valid))
  assert(numDeq<=GH_GlobalParams.GH_TOTAL_PACKETS.U,"Deq too much packet")
  // dontTouch(deq_OH)
  for (i <- 0 to params.core_width - 1) {
    deq_valid(i)                               := (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{idx=>
      buf_deq_valid&&deq_idxs(idx)===i.U&&(!buffer_empty(i))
    }.reduce(_|_)
    buffer_empty(i)                            := u_buffer(i).io.empty
    buffer_full(i)                             := u_buffer(i).io.full
    buffer_deq_data(i)                         := Mux(deq_valid(i),u_buffer(i).io.deq_bits,0.U)
    buffer_inst_type(i)                        := buffer_deq_data(i)(buffer_width - 1, (2*params.xlen))
    bp(i)                                      := buffer_deq_data(i)((2*params.xlen) - 1, 0)
    u_buffer(i).io.deq_ready                   := deq_valid(i)
    is_valid_packet(i)                         := Mux(buffer_inst_type(i) =/= 0.U, 1.U, 0.U)
  }


  val out_buf                                   = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(((2*params.xlen)).W))))
  val out_inst_type                             = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((8).W))))
  // val out_packet                                = RegInit(VecInit(Seq.fill(numPackets)(0.U((params.packet_size).W))))
  val packet_out                                = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((params.packet_size).W))))
  // ((7,0),(127,0)) 只需要136bit
  for(i <- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
    out_buf(i)        := Mux1H(deq_OH(i),bp)
    out_inst_type(i)  := Mux1H(deq_OH(i),buffer_inst_type) 
    packet_out(i)     := Cat(out_inst_type(i),out_buf(i))
  }
  dontTouch(out_buf)
  dontTouch(out_inst_type)
  dontTouch(packet_out)
  when(deq_valid.reduce(_|_)){
    buffer_deq_ptr := Mux(buffer_deq_ptr + numDeq>=params.core_width.U,buffer_deq_ptr+numDeq-params.core_width.U,buffer_deq_ptr + numDeq)
  }

  //这个为什么会去stall
  val filter_width                              = io.debug_filter_width
  val s_num_packets                             = WireInit(0.U(3.W))
  val s_not_enough_filter_width                 = WireInit(0.U(1.W))
  val s_delay_counter                           = WireInit(0.U(3.W))
  val s_delay_counter_reg                       = RegInit(0.U(3.W))
  val zeros_2bits                               = WireInit(0.U(2.W))

  s_num_packets                                := io.ght_ft_newcommit_in.fold(0.U)(_+_)
  s_not_enough_filter_width                    := Mux((s_num_packets > filter_width), 1.U, 0.U)
  
  s_delay_counter                              := MuxCase(0.U,
                                                    Array(((s_not_enough_filter_width === 0.U) || (filter_width === 0.U)) -> 0.U,
                                                          ((s_not_enough_filter_width === 1.U) && (filter_width === 1.U)) -> (s_num_packets - 1.U),
                                                          ((s_not_enough_filter_width === 1.U) && (filter_width === 2.U)) -> 1.U
                                                          ))

  when (s_not_enough_filter_width === 1.U) {
    s_delay_counter_reg                        := s_delay_counter_reg + s_delay_counter
  } .otherwise {
    when (core_hang_up =/= 1.U) {
      s_delay_counter_reg                      := Mux(s_delay_counter_reg =/= 0.U, (s_delay_counter_reg - 1.U), 0.U)
    } .otherwise {
      s_delay_counter_reg                      := s_delay_counter_reg
    }
  }

  val filter_stall                              = Mux((s_delay_counter_reg =/= 0.U), 1.U, 0.U)

  // Outputs
  io.ght_ft_inst_index                        := out_inst_type(0)
  io.packet_out                               := Cat(packet_out.reverse) // Added inst_type for checker cores
  io.core_hang_up                             := core_hang_up | filter_stall
  io.ght_buffer_status                        := Cat(buffer_full(params.core_width-1), buf_all_empty)
  io.ght_filters_empty                        := buf_all_empty

  /* R Features */
  io.ght_filters_ready                        := 0.U//UNUSED
}
