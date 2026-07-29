package freechips.rocketchip.r

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import freechips.rocketchip.guardiancouncil._

case class R_BJLParams(
  nEntries: Int,
  xLen: Int,
  pcLen: Int
)

class R_BJLIO(params: R_BJLParams) extends Bundle {

  val bj_valid = Input(Vec(GH_GlobalParams.GH_TOTAL_PACKETS, Bool()))
  val bj_npc   = Input(Vec(GH_GlobalParams.GH_TOTAL_PACKETS, UInt((params.xLen * 2).W)))

  val bj_req_ready = Output(Bool())
  val bj_req_valid = Input(Bool())
  val bj_resp_npc = Output(UInt(params.pcLen.W))
  val bj_resp_cpc = Output(UInt(params.pcLen.W))
  

  val cdc_ready = Output(Bool())
  val near_full = Output(Bool())
  val bjl_highwatermark = Output(Bool())
  
}

trait HasR_RBJLIO extends BaseModule {
  val params: R_BJLParams
  val io = IO(new R_BJLIO(params))
}

class R_BJL(val params: R_BJLParams) extends Module with HasR_RBJLIO {
  val u_channel_bj            = Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS) {Module(new GH_FIFO(FIFOParams (params.pcLen * 2, params.nEntries)))} 

  /*
BJ ENQ logic
*/
  val bj_enq_ptr                            = RegInit(0.U((log2Ceil(GH_GlobalParams.GH_TOTAL_PACKETS)+1).W))//to avoid overflow
  val bj_deq_ptr                            = RegInit(0.U((log2Ceil(GH_GlobalParams.GH_TOTAL_PACKETS)+1).W))
  //这里打了一拍
  val bj_enq_data                = RegInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((params.pcLen * 2 + 1).W)))//1 bit for taken
  val bj_enq_valid               = RegInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(false.B)))

  for(i<- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
    bj_enq_data(i)  := Cat(io.bj_npc(i)(params.xLen + params.pcLen, params.xLen), io.bj_npc(i)(params.pcLen - 1, 0))
    bj_enq_valid(i) := io.bj_valid(i)
  }
  val bj_numEnq = WireInit(PopCount(bj_enq_valid))

  when(bj_enq_valid.reduce(_|_)){//需要保证回绕正确
    bj_enq_ptr := Mux(bj_enq_ptr + bj_numEnq>=GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_enq_ptr+bj_numEnq-GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_enq_ptr + bj_numEnq)
  }

  val bj_enq_idxs    = VecInit.tabulate(GH_GlobalParams.GH_TOTAL_PACKETS)(i => PopCount(bj_enq_valid.take(i)))
  val bj_enq_offset  = bj_enq_idxs.map(i=>Mux(bj_enq_ptr + i>=GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_enq_ptr+i-GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_enq_ptr+i))
  
  for (i <- 0 to GH_GlobalParams.GH_TOTAL_PACKETS - 1) {
    val bj_enq_OH    = (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map(idx => (bj_enq_offset(idx) === i.U)&(bj_enq_valid(idx)))
    val bj_wdata  = Mux1H(bj_enq_OH, bj_enq_data) 
    u_channel_bj(i).io.enq_valid := bj_enq_OH.reduce(_|_)//
    u_channel_bj(i).io.enq_bits  := bj_wdata
  }

/*
BJ DEQ logic
*/
  val bj_deq_data                = RegInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U((params.pcLen * 2 + 1).W)))
  val bj_deq_valid               = WireInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(false.B))
  val bj_lsl_empty               = WireInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(true.B))
  val bj_out_packet              = WireInit(bj_deq_data(bj_deq_ptr))
  val bj_nearly_full             = WireInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(false.B))
  val bj_highwatermark           = WireInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(false.B))

  dontTouch(bj_deq_data)
  dontTouch(bj_deq_valid)
  dontTouch(bj_out_packet)
  for (i <- 0 to GH_GlobalParams.GH_TOTAL_PACKETS - 1) {
    bj_deq_valid(i)                               := bj_deq_ptr===i.U && io.bj_req_valid & !u_channel_bj(i).io.empty
    u_channel_bj(i).io.deq_ready                  := bj_deq_valid(i)
    bj_deq_data(i)                                := u_channel_bj(i).io.deq_bits
    bj_lsl_empty(i)                               := u_channel_bj(i).io.empty
    bj_nearly_full(i)                             := u_channel_bj(i).io.status_twoslots
    bj_highwatermark(i)                           := u_channel_bj(i).io.status_threeslots
  }

  when(bj_deq_valid.reduce(_|_)){
    bj_deq_ptr := Mux(bj_deq_ptr + 1.U>=GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_deq_ptr+1.U-GH_GlobalParams.GH_TOTAL_PACKETS.U,bj_deq_ptr + 1.U)
  }
  io.bj_resp_npc           := bj_out_packet(params.pcLen - 1, 0)
  io.bj_resp_cpc           := bj_out_packet(params.pcLen + params.pcLen - 1, params.pcLen)
  io.bj_req_ready          := !bj_lsl_empty(bj_deq_ptr)


  //之前有数据来过?

  io.cdc_ready               := (!io.near_full )
  io.near_full               := bj_nearly_full.reduce(_|_)
  io.bjl_highwatermark       := bj_highwatermark.reduce(_|_)
}


class R_BJLRIO(params: R_BJLParams) extends Bundle {
  val bj_valid = Input(Vec(GH_GlobalParams.GH_TOTAL_PACKETS, Bool()))
  val bj_npc   = Input(Vec(GH_GlobalParams.GH_TOTAL_PACKETS, UInt((params.xLen * 2).W)))

  // reserve (frontend side)
  val bj_req_ready = Output(Bool())   // peek_valid of current spec bank
  val bj_data_ready_but_flow = Output(Bool())  
  val bj_req_valid = Input(Bool())    // reserve current peek entry

  // commit / rollback (backend side)
  val bj_commit_valid = Input(Bool()) // commit oldest reserved entry
  val bj_rollback     = Input(Bool()) // redirect/flush => rollback all speculative
  val bj_s2_replay    = Input(Bool()) // s2_replay

  // peek outputs (always from current spec bank head)
  val bj_resp_npc = Output(UInt(params.pcLen.W))
  val bj_resp_cpc = Output(UInt(params.pcLen.W))
  val bj_resp_taken = Output(Bool())
  val bj_resp_is_rvc = Output(Bool())

  val cdc_ready = Output(Bool())
  val near_full = Output(Bool())
  val bjl_highwatermark = Output(Bool())

  val need_replay = Output(Bool())
}

trait HasR_RBJLRIO extends BaseModule {
  val params: R_BJLParams
  val io = IO(new R_BJLRIO(params))
}


class R_BJLR(val params: R_BJLParams) extends Module with HasR_RBJLRIO {

  private val N = GH_GlobalParams.GH_TOTAL_PACKETS
  private def incBank(x: UInt): UInt = Mux(x === (N-1).U, 0.U, x + 1.U)
  private def decBank(x: UInt): UInt = Mux(x === 0.U, (N-1).U, x - 1.U)

  // Banked FIFO: each bank has its own (wptr/sptr/cptr)
  val u_channel_bj = Seq.fill(N) {
    Module(new GH_FIFO_SC(FIFOParams(params.pcLen * 2 + 2, params.nEntries)))
  }

  // -----------------------------
  // ENQ: your original round-robin distributor
  // -----------------------------
  val bj_enq_ptr = RegInit(0.U((log2Ceil(N) + 1).W)) // avoid overflow
  // 【修改2】去掉RegInit，改为Wire（组合逻辑），消除打拍延迟
  val bj_enq_data  = Wire(Vec(N, UInt((params.pcLen * 2 + 2).W)))
  val bj_enq_valid = Wire(Vec(N, Bool()))

  for (i <- 0 until N) {
    bj_enq_data(i)  := Cat(
      io.bj_npc(i)(params.xLen + params.pcLen + 1, params.xLen), // cpc
      io.bj_npc(i)(params.pcLen - 1, 0)                          // npc
    )
    bj_enq_valid(i) := io.bj_valid(i)
  }

  val bj_numEnq = PopCount(bj_enq_valid)

  when (bj_enq_valid.reduce(_||_)) {
    val sum = bj_enq_ptr + bj_numEnq
    bj_enq_ptr := Mux(sum >= N.U, sum - N.U, sum)
  }

  val bj_enq_idxs   = VecInit.tabulate(N)(i => PopCount(bj_enq_valid.take(i)))
  val bj_enq_offset = bj_enq_idxs.map(i => {
    val sum = bj_enq_ptr + i
    Mux(sum >= N.U, sum - N.U, sum)
  })

  for (bank <- 0 until N) {
    val bj_enq_OH = (0 until N).map(idx => (bj_enq_offset(idx) === bank.U) && bj_enq_valid(idx))
    val has_enq   = bj_enq_OH.reduce(_||_)
    val wdata     = Mux1H(bj_enq_OH, bj_enq_data)

    u_channel_bj(bank).io.enq_valid := has_enq
    u_channel_bj(bank).io.enq_bits  := wdata
  }

  // -----------------------------
  // SPEC/COMMIT bank pointers
  // -----------------------------
  val spec_bank_ptr   = RegInit(0.U(log2Ceil(N).W))
  val commit_bank_ptr = RegInit(0.U(log2Ceil(N).W))

  // Peek current spec bank
  val peek_bits_vec  = VecInit(u_channel_bj.map(_.io.peek_bits))
  val peek_valid_vec = VecInit(u_channel_bj.map(chan => chan.io.peek_valid || chan.io.enq_valid))
  val peek_data_valid_vec = VecInit(u_channel_bj.map(chan => chan.io.peek_valid))
  val can_commit_vec = VecInit(u_channel_bj.map(_.io.can_commit))

  val spec_peek_valid = peek_valid_vec(spec_bank_ptr)
  val spec_peek_data_valid = peek_data_valid_vec(spec_bank_ptr)
  val spec_peek_bits  = peek_bits_vec(spec_bank_ptr)
  val commit_peek_valid = peek_valid_vec(commit_bank_ptr) // For commit replay check

  io.bj_req_ready := spec_peek_valid
  io.bj_data_ready_but_flow := spec_peek_data_valid
  io.bj_resp_npc  := spec_peek_bits(params.pcLen - 1, 0)
  io.bj_resp_cpc  := spec_peek_bits(params.pcLen + params.pcLen - 1, params.pcLen)
  io.bj_resp_taken := spec_peek_bits(params.pcLen * 2)
  io.bj_resp_is_rvc := spec_peek_bits(params.pcLen * 2 + 1)
  io.need_replay  := !commit_peek_valid

  // Reserve fires when frontend asks and current spec head is valid
  val reserve_fire = io.bj_req_valid && io.bj_req_ready

  // Commit fires when backend asks and current commit bank actually has reserved entries
  val commit_fire = io.bj_commit_valid && can_commit_vec(commit_bank_ptr)

  // Rollback: reset speculative state to committed state
  when (io.bj_rollback) {
    spec_bank_ptr := commit_bank_ptr
  }.elsewhen(io.bj_s2_replay){
    spec_bank_ptr := decBank(spec_bank_ptr)
  }
  .otherwise {
    when (reserve_fire) { spec_bank_ptr := incBank(spec_bank_ptr) }
  }
  when (commit_fire) { commit_bank_ptr := incBank(commit_bank_ptr) }

  // Drive per-bank reserve/commit/rollback signals
  for (bank <- 0 until N) {
    val isSpec   = (spec_bank_ptr === bank.U)
    val isCommit = (commit_bank_ptr === bank.U)
    u_channel_bj(bank).io.reserve  := reserve_fire && isSpec
    u_channel_bj(bank).io.commit   := commit_fire && isCommit
    u_channel_bj(bank).io.rollback := io.bj_rollback
    when(bank.U === decBank(spec_bank_ptr)){
      u_channel_bj(bank).io.need_replay_1 := io.bj_s2_replay
    }.otherwise{
      u_channel_bj(bank).io.need_replay_1 := false.B
    }
  }
  

  // -----------------------------
  // Status (near_full / watermark / cdc_ready)
  // -----------------------------
  val nearly_full_vec = VecInit(u_channel_bj.map(_.io.status_twoslots.asBool))
  val highwm_vec      = VecInit(u_channel_bj.map(_.io.status_threeslots.asBool))
  val full_vec        = VecInit(u_channel_bj.map(_.io.full))

  io.near_full         := nearly_full_vec.reduce(_||_)
  io.bjl_highwatermark := highwm_vec.reduce(_||_)
  io.cdc_ready         := !io.near_full
}