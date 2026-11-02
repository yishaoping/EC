package freechips.rocketchip.guardiancouncil


import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import org.chipsalliance.cde.config.{Field, Parameters}
import freechips.rocketchip.subsystem.{BaseSubsystem, HierarchicalLocation, HasTiles, TLBusWrapperLocation}
import freechips.rocketchip.diplomacy._
//===== GuardianCouncil Function: Start ====//
import freechips.rocketchip.guardiancouncil._
//===== GuardianCouncil Function: End   ====//

// import boom.common.{BoomTile}
import freechips.rocketchip.util._

case class GHMParams(
  number_of_little_cores: Int,
  width_GH_packet: Int
)


class GHMIO(params: GHMParams) extends Bundle {
  val ghm_clock                                  = Input(Vec(params.number_of_little_cores + GH_GlobalParams.GH_NUM_BIG_CORES, Bool()))
  val ghm_reset                                  = Input(Vec(params.number_of_little_cores + GH_GlobalParams.GH_NUM_BIG_CORES, Bool()))

  val ghm_packet_in                              = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS).W)))
  val ghm_packet_dest                            = Input(UInt((params.number_of_little_cores*2).W))
  val ghm_status_in                              = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt(32.W)))
  val ghm_packet_outs                            = Output(Vec(params.number_of_little_cores, UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS+1).W)))
  val ghm_status_outs                            = Output(Vec(params.number_of_little_cores, UInt(32.W)))
  val ghe_event_in                               = Input(Vec(params.number_of_little_cores, UInt(6.W)))
  val clear_ic_status                            = Input(Vec(params.number_of_little_cores, UInt(1.W)))

  val clear_ic_status_tomain                     = Output(UInt(GH_GlobalParams.GH_NUM_CORES.W))
  val bigcore_hang                               = Output(Vec(params.number_of_little_cores, UInt(1.W)))  // per-checker backpressure
  val bigcore_comp                               = Output(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt(3.W)))
  val debug_bp                                   = Output(UInt(2.W))
  val ic_counter                                 = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt((16*GH_GlobalParams.GH_NUM_CORES).W)))
  val debug_maincore_status                      = Input(UInt(4.W))
  val icsl_counter                               = Output(Vec(params.number_of_little_cores, UInt(20.W)))
  val ghe_revent_in                              = Input(Vec(params.number_of_little_cores, UInt(1.W)))
  val ghm_cdc_empty_out                          = Output(Vec(params.number_of_little_cores, Bool()))
  val icsl_na                                    = Output(UInt((GH_GlobalParams.GH_NUM_CORES).W))

  // Global ic_status: OR-merge of all big cores' ic_status, broadcast back to all big cores
  val ic_status_bigcore                          = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt(GH_GlobalParams.GH_NUM_CORES.W)))
  val ic_status_global                           = Output(UInt(GH_GlobalParams.GH_NUM_CORES.W))

  // Global checker_big_owner: OR-merge of all big cores' checker_big_owner, broadcast back
  val checker_big_owner_bigcore                  = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt((GH_GlobalParams.GH_NUM_CORES * 4).W)))
  val checker_big_owner_global                   = Output(UInt((GH_GlobalParams.GH_NUM_CORES * 4).W))

  val debug_gcounter                             = Output(UInt(64.W))
  val if_agg_free                                = Input(UInt(1.W))
  val core_r_arfs_in                             = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt((params.width_GH_packet+1+8+8).W)))
  val core_r_arfs_c                              = Output(Vec(params.number_of_little_cores, UInt((params.width_GH_packet+1+8).W)))
}

trait HasGHMIO extends BaseModule {
  val params: GHMParams
  val io = IO(new GHMIO(params))
}

//==========================================================
// Implementations
//==========================================================
class GHM (val params: GHMParams)(implicit p: Parameters) extends LazyModule
{
  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val io                                         = IO(new GHMIO(params))

    // Adding a register to avoid the critical path
    // val packet_dest                                = WireInit(0.U((params.number_of_little_cores).W))
    //加入了flag
    val packet_out_wires                           = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS+1).W))))
    val cdc_busy                                   = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val arfs_cdc_busy                              = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val cdc_empty                                  = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))

    // OR-merge ic_counters from all big cores (each big core only fills its own checkers)
    val ic_counter_merged                          = io.ic_counter.reduce(_|_)

    val data_cdc_ready                             = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    // val arfs_dest                                  = WireInit(0.U((params.number_of_little_cores).W))

    // Per-big-core packet destination extraction
    val packet_dest                                = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(4.W))))))
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      for(i <- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
        packet_dest(b)(i)                         := io.ghm_packet_in(b)((i+1)*params.width_GH_packet-1, (i+1)*params.width_GH_packet-8)(6,3)
      }
    }
    // Per-big-core ARF destination extraction
    val arfs_dest_vec                              = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(0.U(3.W))))
    val arfs_ecp_dest_vec                          = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(0.U(3.W))))
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      arfs_dest_vec(b)                            := io.core_r_arfs_in(b)(params.width_GH_packet+7+1, params.width_GH_packet+1)(5,3)
      arfs_ecp_dest_vec(b)                        := io.core_r_arfs_in(b)(params.width_GH_packet+15+1, params.width_GH_packet+8+1)(5,3)
    }
//==========================================================
// Multi Bits CDC
//==========================================================


    val u_data_cdc                                      = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS).W), AsyncQueueParams(256,2)))}
    val u_arfs_cdc                                      = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((params.width_GH_packet+1+8).W), AsyncQueueParams(8,2)))}//留8个余量防止写入太快
    val u_l2b_ctrl_cdc                                  = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt(9.W), AsyncQueueParams(64,2)))}
    val u_b2l_ctrl_cdc                                  = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((22).W), AsyncQueueParams(64,2)))}//早晚会满

    val l_wctrl = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U(8.W))))
    val b_rctrl = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U(8.W))))

    //如果添加控制信号，必须去加位宽!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    val l_rctrl = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U((22).W))))
    val b_wctrl = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U((22).W))))
    // Per-checker routing: check ALL big cores' packets for destination match
    for (i <- 0 to params.number_of_little_cores - 1) {
      // Which big core targets checker i?
      val sel_data = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(false.B)))
      val sel_arfs = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(false.B)))
      for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
        sel_data(b) := (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{j=>
          packet_dest(b)(j)===(i+1).U
        }.reduce(_|_)
        sel_arfs(b) := arfs_dest_vec(b)===(i+1).U || arfs_ecp_dest_vec(b)===(i+1).U
      }
      val if_data_en = sel_data.reduce(_|_)
      val if_arfs_en = sel_arfs.reduce(_|_)
      dontTouch(if_data_en)
      //data  
      u_data_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_data_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_data_cdc(i).io.deq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_data_cdc(i).io.deq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)

      u_data_cdc(i).io.enq.valid := if_data_en
      u_data_cdc(i).io.enq.bits  := Mux1H(sel_data, io.ghm_packet_in)
      data_cdc_ready(i)          := io.ghe_event_in(i)(4)&(!io.ghe_event_in(i)(0))
      u_data_cdc(i).io.deq.ready := data_cdc_ready(i)
      packet_out_wires(i)        := Mux(u_data_cdc(i).io.deq.fire,u_data_cdc(i).io.deq.bits,0.U)
      cdc_busy(i)                := (!u_data_cdc(i).io.enq.ready)
      cdc_empty(i)               := (!u_data_cdc(i).io.deq.valid)


      //arfs 
      u_arfs_cdc(i).io.deq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_arfs_cdc(i).io.deq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)

      u_arfs_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_arfs_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_arfs_cdc(i).io.enq.valid := if_arfs_en
      u_arfs_cdc(i).io.enq.bits  := Mux1H(sel_arfs, io.core_r_arfs_in)
      u_arfs_cdc(i).io.deq.ready := true.B
      io.core_r_arfs_c(i)        := Mux(u_arfs_cdc(i).io.deq.fire,u_arfs_cdc(i).io.deq.bits,0.U)

      arfs_cdc_busy(i)          := (!u_arfs_cdc(i).io.enq.ready)
      dontTouch(u_arfs_cdc(i).io.enq.ready)
      //little to big CDC
      l_wctrl(i)                     := Cat(io.clear_ic_status(i),io.ghe_revent_in(i),io.ghe_event_in(i))
      u_l2b_ctrl_cdc(i).io.deq_clock := io.ghm_clock(0).asClock
      u_l2b_ctrl_cdc(i).io.deq_reset := io.ghm_reset(0)
      u_l2b_ctrl_cdc(i).io.enq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_l2b_ctrl_cdc(i).io.enq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)
      u_l2b_ctrl_cdc(i).io.enq.valid := io.clear_ic_status(i)|io.ghe_revent_in(i)|io.ghe_event_in(i)=/=0.U
      u_l2b_ctrl_cdc(i).io.enq.bits  := l_wctrl(i)
      u_l2b_ctrl_cdc(i).io.deq.ready := true.B
      dontTouch(u_l2b_ctrl_cdc(i).io.enq.ready)
      b_rctrl(i)                     := Mux(u_l2b_ctrl_cdc(i).io.deq.fire,u_l2b_ctrl_cdc(i).io.deq.bits,0.U)

      //big to little CDC

      // Per-checker: route status based on checker_big_owner (which big core owns this checker)
      val global_owner_packed = io.checker_big_owner_bigcore.reduce(_|_)  // OR-merge per-big-core views
      val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
      val owner_4bit = global_owner_packed(full_idx*4+3, full_idx*4)
      // owner=0 means unowned; owner values 1..N select big cores 0..N-1.
      val routed_status = MuxLookup(owner_4bit, 0.U(5.W),
        (0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
          (b + 1).U -> io.ghm_status_in(b)(4, 0)
        })
      // if_filters_empty (bit 31): take from big0 (single-source for now)
      b_wctrl(i)                     := Cat(ic_counter_merged((i+1+GH_GlobalParams.GH_NUM_BIG_CORES)*16-1,(i+GH_GlobalParams.GH_NUM_BIG_CORES)*16),io.ghm_status_in(0)(31),routed_status)
      u_b2l_ctrl_cdc(i).io.deq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_b2l_ctrl_cdc(i).io.deq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)
      u_b2l_ctrl_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_b2l_ctrl_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_b2l_ctrl_cdc(i).io.enq.valid := io.ghm_status_in(0)(31)|routed_status=/=0.U|ic_counter_merged((i+1+GH_GlobalParams.GH_NUM_BIG_CORES)*16-1)=/=0.U
      u_b2l_ctrl_cdc(i).io.enq.bits  := b_wctrl(i)
      u_b2l_ctrl_cdc(i).io.deq.ready := true.B
      l_rctrl(i)                     := Mux(u_b2l_ctrl_cdc(i).io.deq.fire,u_b2l_ctrl_cdc(i).io.deq.bits,0.U)
      dontTouch(u_b2l_ctrl_cdc(i).io.enq.ready)
    }
    dontTouch(l_wctrl)
    dontTouch(b_wctrl)
    dontTouch(data_cdc_ready)
    dontTouch(packet_dest)
    dontTouch(arfs_dest_vec)
    dontTouch(arfs_ecp_dest_vec)
    
    //所有信号都需要展宽
    val cdc_ghe_event                              = WireInit(VecInit(b_rctrl.map{i=>i(5,0)}))  //可以采样，3周期一采样,但这样做就无法去得到正确的反压信号
    val cdc_ghe_revent                             = WireInit(VecInit(b_rctrl.map{i=>i(6)} ))   //只采样高信号
    val cdc_clear_ic_status                        = WireInit(VecInit(b_rctrl.map{i=>i(7)} ))   //只采样高信号
    // val cdc_if_big_complete                        = WireInit(VecInit(b_rctrl.map{i=>i(8)} ))   //只采样高信号 not uesd
    
    val cdc_icsl_cnt                               = l_rctrl.map{i=>i(21,6)}
    val cdc_filter_empty                           = l_rctrl.map{i=>i(5)} //只采样高信号
    val cdc_ghm_status                             = l_rctrl.map{i=>i(4,0)} //3个周期一采样
    // val cdc_icsl_ack                               = l_rctrl.map{i=>i(6)}//只采样高信号
    // val cdc_big_complete_ack                       = WireInit(VecInit(l_rctrl.map{i=>i(7)}))//只采样高信号 not used
    
    // dontTouch(cdc_big_complete_ack)
    // val cdc_big_switch_req                         = l_rctrl.map{i=>i(27)}

    val zero                                       = WireInit(0.U(1.W))

    val ghe_event                                  = WireInit(0.U(3.W))
    val initalised                                 = WireInit(0.U(1.W))
    val debug_gcounter                             = RegInit (0.U(64.W))
    val big_bp                                     = WireInit(false.B)//大核反压
    val little_bp                                  = WireInit(false.B)//小核反压

    val if_filters_empty                           = io.ghm_status_in(0)(31)

    val if_cdc_empty                               = cdc_empty.reduce(_&_)//这个信号不知道会不会出问题？
    val if_no_inflight_packets                     = WireInit(VecInit((0 until params.number_of_little_cores).map{i=>cdc_filter_empty(i) & cdc_empty(i) } )) 
    big_bp := u_b2l_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    little_bp := u_l2b_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    //need CDC
    dontTouch(big_bp)
    io.clear_ic_status_tomain                     := Cat(Cat(cdc_clear_ic_status.reverse), 0.U(GH_GlobalParams.GH_NUM_BIG_CORES.W))// 2-bit zero pad for big0/big1
    // io.if_big_complete_req                        := Cat(cdc_if_big_complete.reverse)



    dontTouch(if_no_inflight_packets)
    dontTouch(if_filters_empty)
    dontTouch(if_cdc_empty)
    dontTouch(cdc_busy)
    // dontTouch(if_no_inflight_packets)
    val zeros_59bit                                = WireInit(0.U(59.W))
    //这里也需要CDC，可以考虑将这个ghm_status_outs存入CDC FIFO //to little 
    for(i <- 0 to params.number_of_little_cores - 1) {
      io.ghm_packet_outs(i)                       := packet_out_wires(i)
      io.ghm_status_outs(i)                       := Mux(if_no_inflight_packets(i)===1.U, Cat(zeros_59bit, cdc_ghm_status(i)), 1.U)
      // io.ghm_big_complete(i)                      := cdc_big_complete_ack(i)
    }

    dontTouch(io.ghm_packet_outs)
    dontTouch(io.ghm_status_outs)


    when (io.ghm_packet_dest(params.number_of_little_cores-1,0) =/= 0.U) {
      debug_gcounter                             := debug_gcounter + 1.U
    }

    // Per-checker backpressure: each checker's CDC busy is broadcast to all big cores
    // Each big core filters with its own checker_enable_mask in BoomTile
    for (i <- 0 until params.number_of_little_cores) {
      io.bigcore_hang(i) := cdc_busy(i) | arfs_cdc_busy(i)
    }
    // Per-big-core bigcore_comp: AND only checkers owned by each big core.
    // Unrelated checkers contribute 0x7 (all 1s) so they don't block the AND.
    val global_owner_for_comp = io.checker_big_owner_bigcore.reduce(_|_)
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val owned_events = WireInit(VecInit((0 until params.number_of_little_cores).map { i =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        val owner_4bit = global_owner_for_comp(full_idx*4+3, full_idx*4)
        Mux(owner_4bit === (b+1).U, cdc_ghe_event(i)(3,1), 0x7.U(3.W))
      }))
      io.bigcore_comp(b) := owned_events.reduce(_&_)
    }
    dontTouch(cdc_ghe_event)
    io.debug_gcounter                            := debug_gcounter//cdc

    val debug_collecting_checker_status           = cdc_ghe_event.reduce(_|_)//小->大
    val debug_backpressure_checkers               = debug_collecting_checker_status(0)
    io.debug_bp                                  := Cat(cdc_busy.reduce(_|_), debug_backpressure_checkers) // [1]: CDC; [0]: Checker

    for (i <- 0 to params.number_of_little_cores - 1) {
      io.icsl_counter(i)                         := cdc_icsl_cnt(i)
      // io.ghm_icsl_ack_out(i)                     := cdc_icsl_ack(i)
      io.ghm_cdc_empty_out(i)                    := cdc_empty(i)
      // io.ghm_big_switch_out(i)                   := cdc_big_switch_req(i)
    }
    io.icsl_na := Cat(Cat(cdc_ghe_revent.reverse), 0.U(GH_GlobalParams.GH_NUM_BIG_CORES.W))// bit[N-1:0]=0(big), bit[2+N-1:2]=chk1..chkN

    // Global ic_status: OR of all big cores' local ic_status
    io.ic_status_global                          := io.ic_status_bigcore.reduce(_|_)
    // Global checker_big_owner: OR of all big cores' local checker_big_owner
    io.checker_big_owner_global                  := io.checker_big_owner_bigcore.reduce(_|_)
  }
}

case class GHMCoreLocated(loc: HierarchicalLocation) extends Field[Option[GHMParams]](None)

object GHMCore {

  def attach(params: GHMParams, subsystem: BaseSubsystem with HasTiles, where: TLBusWrapperLocation)
            (implicit p: Parameters) {
    val number_of_ghes                             = subsystem.tile_ghe_packet_in_EPNodes.size
    println("#### Jessica #### Tieing off GHM **Nodes**, core number:", number_of_ghes,"...!!")

    // Creating nodes for connections.
    val bigcore_hang_SRNode                        = BundleBridgeSource[UInt](Some(() => UInt(params.number_of_little_cores.W)))  // per-checker bits
    val bigcore_comp_SRNodes                       = Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(BundleBridgeSource[UInt](Some(() => UInt(3.W))))
    val debug_bp_SRNode                            = BundleBridgeSource[UInt](Some(() => UInt(2.W)))
    var ghm_ght_packet_in_SKNodes                  = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val sk = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_TOTAL_PACKETS*params.width_GH_packet).W)))
      ghm_ght_packet_in_SKNodes = ghm_ght_packet_in_SKNodes :+ sk
    }
    var core_r_arfs_in_SKNodes                     = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val sk = BundleBridgeSink[UInt](Some(() => UInt((params.width_GH_packet+1+8+8).W)))
      core_r_arfs_in_SKNodes = core_r_arfs_in_SKNodes :+ sk
    }

    var ic_counter_SKNodes                         = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val ic_counter_SKNode                       = BundleBridgeSink[UInt](Some(() => UInt((16*GH_GlobalParams.GH_NUM_CORES).W)))
      ic_counter_SKNodes                          = ic_counter_SKNodes :+ ic_counter_SKNode
    }
    // val icsl_ack_SKNode                            = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    // val big_complete_ack_SKNode                            = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    // val big_checker_switch_SKNode                  = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))

    val debug_maincore_status_SKNode               = BundleBridgeSink[UInt](Some(() => UInt(4.W)))
    val ghm_ght_packet_dest_SKNode                 = BundleBridgeSink[UInt](Some(() => UInt(32.W)))
    ghm_ght_packet_dest_SKNode                    := subsystem.tile_ght_packet_dest_EPNode
    val ghm_ght_status_in_SKNodes                  = Seq.fill(GH_GlobalParams.GH_NUM_BIG_CORES)(BundleBridgeSink[UInt](Some(() => UInt(32.W))))
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      ghm_ght_status_in_SKNodes(b) := subsystem.tile_ght_status_out_EPNodes(b)
    }

    var ghm_ghe_packet_out_SRNodes                 = Seq[BundleBridgeSource[UInt]]()
    var core_r_arfs_c_SRNodes                      = Seq[BundleBridgeSource[UInt]]()

    var icsl_out_SRNodes                           = Seq[BundleBridgeSource[UInt]]()
    var ghm_ghe_status_out_SRNodes                 = Seq[BundleBridgeSource[UInt]]()
    var ghm_ghe_event_in_SKNodes                   = Seq[BundleBridgeSink[UInt]]()
    var ghm_clock_in_SKNodes                       = Seq[BundleBridgeSink[Clock]]()
    var ghm_reset_in_SKNodes                       = Seq[BundleBridgeSink[Bool]]()

    // var ghm_if_big_complete_SKNodes                = Seq[BundleBridgeSink[Bool]]()
    // var ghm_big_complete_SRNodes                = Seq[BundleBridgeSource[Bool]]()
    var ghm_cdc_empty_out_SKNodes                  = Seq[BundleBridgeSource[Bool]]()
    // var ghm_icsl_ack_out_SKNodes                   = Seq[BundleBridgeSource[Bool]]()
    // var ghm_big_switch_out_SKNodes                 = Seq[BundleBridgeSink[Bool]]()
    var ghm_ghe_revent_in_SKNodes                  = Seq[BundleBridgeSink[UInt]]()
    var clear_ic_status_SkNodes                    = Seq[BundleBridgeSink[UInt]]()
    var clear_ic_status_tomainSRNodes              = Seq[BundleBridgeSource[UInt]]()
    var icsl_naSRNodes                             = Seq[BundleBridgeSource[UInt]]()

    // Global ic_status: per-big-core sinks → GHM, broadcast source ← GHM
    var ic_status_SKNodes                          = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val sk = BundleBridgeSink[UInt](Some(() => UInt(GH_GlobalParams.GH_NUM_CORES.W)))
      ic_status_SKNodes = ic_status_SKNodes :+ sk
    }
    val ic_status_global_SRNode                    = BundleBridgeSource[UInt](Some(() => UInt(GH_GlobalParams.GH_NUM_CORES.W)))

    // Global checker_big_owner: per-big-core sinks → GHM, broadcast source ← GHM
    var checker_big_owner_SKNodes                  = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val sk = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES * 4).W)))
      checker_big_owner_SKNodes = checker_big_owner_SKNodes :+ sk
    }
    val checker_big_owner_global_SRNode            = BundleBridgeSource[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES * 4).W)))


    // val if_big_complete_reqSRNode                 = BundleBridgeSource[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    val if_agg_free_SKNode                         = BundleBridgeSink[UInt](Some(() => UInt(1.W)))


    // big_checker_switch_SKNode                     := subsystem.tile_big_checker_switch_EPNode
    // icsl_ack_SKNode                               := subsystem.tile_icsl_ack_EPNode
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      ghm_ght_packet_in_SKNodes(b)                := subsystem.tile_ght_packet_out_EPNodes(b)
      core_r_arfs_in_SKNodes(b)                   := subsystem.tile_core_r_arfs_EPNodes(b)
      ic_counter_SKNodes(b)                       := subsystem.tile_ic_counter_out_EPNodes(b)
      ic_status_SKNodes(b)                        := subsystem.tile_ic_status_out_EPNodes(b)
      checker_big_owner_SKNodes(b)               := subsystem.tile_checker_big_owner_out_EPNodes(b)
    }
    debug_maincore_status_SKNode                  := subsystem.debug_maincore_status_out_EPNode
    // big_complete_ack_SKNode                       := subsystem.big_complete_ack_EPNode
    if_agg_free_SKNode                            := subsystem.tile_agg_free_EPNode
    for (i <- 0 to number_of_ghes-1) {
      val ghm_ghe_packet_out_SRNode                = BundleBridgeSource[UInt]()
      ghm_ghe_packet_out_SRNodes                   = ghm_ghe_packet_out_SRNodes :+ ghm_ghe_packet_out_SRNode
      subsystem.tile_ghe_packet_in_EPNodes(i)     := ghm_ghe_packet_out_SRNodes(i)

      val core_r_arfs_c_SRNode                     = BundleBridgeSource[UInt]()
      core_r_arfs_c_SRNodes                        = core_r_arfs_c_SRNodes :+ core_r_arfs_c_SRNode
      subsystem.core_r_arfs_c_EPNodes(i)          := core_r_arfs_c_SRNodes(i)

      val icsl_out_SRNode                          = BundleBridgeSource[UInt]()
      icsl_out_SRNodes                             = icsl_out_SRNodes :+ icsl_out_SRNode
      subsystem.tile_icsl_counter_in_EPNodes(i)   := icsl_out_SRNodes(i)

      val ghm_ghe_status_out_SRNode                = BundleBridgeSource[UInt]()
      ghm_ghe_status_out_SRNodes                   = ghm_ghe_status_out_SRNodes :+ ghm_ghe_status_out_SRNode
      subsystem.tile_ghe_status_in_EPNodes(i)     := ghm_ghe_status_out_SRNodes(i)

      val ghm_ghe_event_in_SkNode                  = BundleBridgeSink[UInt]()
      ghm_ghe_event_in_SKNodes                     = ghm_ghe_event_in_SKNodes :+ ghm_ghe_event_in_SkNode
      ghm_ghe_event_in_SKNodes(i)                 := subsystem.tile_ghe_event_out_EPNodes(i)

      val ghm_clock_in_SKNode                      = BundleBridgeSink[Clock]()
      ghm_clock_in_SKNodes                     = ghm_clock_in_SKNodes :+ ghm_clock_in_SKNode
      ghm_clock_in_SKNodes(i)                  := subsystem.tile_clock_EPNodes(i)

      val ghm_reset_in_SKNode                      = BundleBridgeSink[Bool]()
      ghm_reset_in_SKNodes                       = ghm_reset_in_SKNodes :+ ghm_reset_in_SKNode
      ghm_reset_in_SKNodes(i)                   := subsystem.tile_reset_EPNodes(i)

      // tile_big_complete_EPNodes

      // val ghm_big_complete_SRNode                   = BundleBridgeSource[Bool]()
      // ghm_big_complete_SRNodes                       = ghm_big_complete_SRNodes :+ ghm_big_complete_SRNode
      // subsystem.tile_big_complete_EPNodes(i)        := ghm_big_complete_SRNodes(i)


      // val ghm_if_big_complete_SKNode             = BundleBridgeSink[Bool]()
      // ghm_if_big_complete_SKNodes                       = ghm_if_big_complete_SKNodes :+ ghm_if_big_complete_SKNode
      // ghm_if_big_complete_SKNodes(i)                   := subsystem.tile_if_big_complete_EPNodes(i)

      // val ghm_icsl_ack_out_SKNode                    = BundleBridgeSource[Bool]()
      // ghm_icsl_ack_out_SKNodes                       = ghm_icsl_ack_out_SKNodes :+ ghm_icsl_ack_out_SKNode
      // subsystem.icsl_ack_tocheckerEPNodes(i)        := ghm_icsl_ack_out_SKNodes(i)

      // val ghm_big_switch_out_SKNode                   = BundleBridgeSink[Bool]()
      // ghm_big_switch_out_SKNodes                      = ghm_big_switch_out_SKNodes :+ ghm_big_switch_out_SKNode
      // subsystem.big_switch_tocheckerEPNodes(i)       := ghm_big_switch_out_SKNodes(i)

      val ghm_cdc_empty_out_SKNode                    = BundleBridgeSource[Bool]()
      ghm_cdc_empty_out_SKNodes                       = ghm_cdc_empty_out_SKNodes :+ ghm_cdc_empty_out_SKNode
      subsystem.cdc_empty_tocheckerEPNodes(i)        := ghm_cdc_empty_out_SKNodes(i)

      val ghm_ghe_revent_in_SkNode                 = BundleBridgeSink[UInt]()
      ghm_ghe_revent_in_SKNodes                    = ghm_ghe_revent_in_SKNodes :+ ghm_ghe_revent_in_SkNode
      ghm_ghe_revent_in_SKNodes(i)                := subsystem.tile_ghe_revent_out_EPNodes(i)

      val clear_ic_status_SkNode                   = BundleBridgeSink[UInt]()
      clear_ic_status_SkNodes                      = clear_ic_status_SkNodes :+ clear_ic_status_SkNode
      clear_ic_status_SkNodes(i)                  := subsystem.tile_clear_ic_status_out_EPNodes(i)

      val clear_ic_status_tomainSRNode             = BundleBridgeSource[UInt]()
      clear_ic_status_tomainSRNodes                = clear_ic_status_tomainSRNodes :+ clear_ic_status_tomainSRNode
      subsystem.clear_ic_status_tomainEPNodes(i)  := clear_ic_status_tomainSRNodes(i)

      
      val icsl_naSRNode                            = BundleBridgeSource[UInt]()
      icsl_naSRNodes                               = icsl_naSRNodes :+ icsl_naSRNode
      subsystem.icsl_naEPNodes(i)                 := icsl_naSRNodes(i)
    }

    val debug_gcounter_SRNode                      = BundleBridgeSource[UInt](Some(() => UInt(64.W)))
    // val if_big_complete_reqSRNode                  = BundleBridgeSource[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      subsystem.tile_bigcore_comp_EPNodes(b) := bigcore_comp_SRNodes(b)
    }
    subsystem.tile_bigcore_hang_EPNode            :*= bigcore_hang_SRNode
    subsystem.tile_debug_bp_EPNode                :*= debug_bp_SRNode
    subsystem.tile_ic_status_global_EPNode        :*= ic_status_global_SRNode
    subsystem.tile_checker_big_owner_global_EPNode :*= checker_big_owner_global_SRNode
    // subsystem.tile_if_big_complete_req_EPNode     := if_big_complete_reqSRNode 
                                                  // := if_big_complete_reqSRNode


    subsystem.tile_debug_gcounter_EPNode          :*= debug_gcounter_SRNode
    
    val bus = subsystem.locateTLBusWrapper(where)

    // val tile_msg = subsystem.tiles.map{
    //   t=>
    //     t.module.clock
    // }
    // .map {t=>
    //   println("#### Jessica #### Connecting GHM **Clock** on the sub-system, HartID:", t.tileParams.hartId, "...!!")
    //   t.module.clock
    // }

    val ghm = LazyModule (new GHM (GHMParams (params.number_of_little_cores, params.width_GH_packet)))

    
    InModuleBody {
      ghm.module.clock                            := ghm_clock_in_SKNodes(0).bundle

      // ghm.module.io.ghm_big_checker_switch        := 0.U
      // ghm.module.io.ghm_icsl_ack_in               := icsl_ack_SKNode.bundle      
      ghm.module.io.ghm_packet_in                 := ghm_ght_packet_in_SKNodes.map(_.bundle)
      ghm.module.io.core_r_arfs_in                := core_r_arfs_in_SKNodes.map(_.bundle)
      ghm.module.io.ghm_packet_dest               := ghm_ght_packet_dest_SKNode.bundle
      ghm.module.io.ghm_status_in                 := VecInit(ghm_ght_status_in_SKNodes.map(_.bundle))
      ghm.module.io.if_agg_free                   := if_agg_free_SKNode.bundle 
      ghm.module.io.ic_counter                    := ic_counter_SKNodes.map(_.bundle)
      ghm.module.io.ic_status_bigcore             := ic_status_SKNodes.map(_.bundle)
      ghm.module.io.checker_big_owner_bigcore     := checker_big_owner_SKNodes.map(_.bundle)
      ghm.module.io.debug_maincore_status         := debug_maincore_status_SKNode.bundle
      // ghm.module.io.if_big_complete_ack           := big_complete_ack_SKNode.bundle 
      for (i <- 0 to number_of_ghes-1) {
        ghm.module.io.ghm_clock(i)                        :=ghm_clock_in_SKNodes(i).bundle.asBool
        ghm.module.io.ghm_reset(i)                        :=ghm_reset_in_SKNodes(i).bundle.asBool
        if (i < GH_GlobalParams.GH_NUM_BIG_CORES) { // The big cores
          // GHE is not connected to big cores
          ghm_ghe_packet_out_SRNodes(i).bundle    := 0.U 
          core_r_arfs_c_SRNodes(i).bundle         := 0.U
          ghm_ghe_status_out_SRNodes(i).bundle    := 0.U
          clear_ic_status_tomainSRNodes(i).bundle := ghm.module.io.clear_ic_status_tomain
          icsl_naSRNodes(i).bundle                := ghm.module.io.icsl_na
          icsl_out_SRNodes(i).bundle              := 0.U
        } else {// checker cores
          val ci = i - GH_GlobalParams.GH_NUM_BIG_CORES  // checker index (0-based, relative to checker array)
          ghm_ghe_packet_out_SRNodes(i).bundle    := ghm.module.io.ghm_packet_outs(ci)
          core_r_arfs_c_SRNodes(i).bundle         := ghm.module.io.core_r_arfs_c(ci)
          ghm_ghe_status_out_SRNodes(i).bundle    := ghm.module.io.ghm_status_outs(ci)
          clear_ic_status_tomainSRNodes(i).bundle := 0.U
          icsl_naSRNodes(i).bundle                := 0.U
          ghm_cdc_empty_out_SKNodes(i).bundle     := ghm.module.io.ghm_cdc_empty_out(ci)
          icsl_out_SRNodes(i).bundle              := ghm.module.io.icsl_counter(ci)

          ghm.module.io.ghe_event_in(ci)         := ghm_ghe_event_in_SKNodes(i).bundle
          ghm.module.io.ghe_revent_in(ci)        := ghm_ghe_revent_in_SKNodes(i).bundle
          ghm.module.io.clear_ic_status(ci)      := clear_ic_status_SkNodes(i).bundle
          
        }
      }

      bigcore_hang_SRNode.bundle                  := ghm.module.io.bigcore_hang.asUInt
      for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
        bigcore_comp_SRNodes(b).bundle := ghm.module.io.bigcore_comp(b)
      }
      debug_bp_SRNode.bundle                      := ghm.module.io.debug_bp
      debug_gcounter_SRNode.bundle                := ghm.module.io.debug_gcounter
      ic_status_global_SRNode.bundle              := ghm.module.io.ic_status_global
      checker_big_owner_global_SRNode.bundle      := ghm.module.io.checker_big_owner_global
      // if_big_complete_reqSRNode.bundle            := ghm.module.io.if_big_complete_req
    }
    ghm
  }
}
