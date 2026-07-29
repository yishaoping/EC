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
  val ghm_clock                                  = Input(Vec(params.number_of_little_cores+1,Bool()))
  val ghm_reset                                  = Input(Vec(params.number_of_little_cores+1,Bool()))

  // val ghm_icsl_ack_in                            = Input(UInt((params.number_of_little_cores).W))
  // val ghm_big_checker_switch                     = Input(UInt((params.number_of_little_cores).W))
  val ghm_packet_in                              = Input(UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS).W))
  val ghm_packet_dest                            = Input(UInt((params.number_of_little_cores*2).W))
  val ghm_status_in                              = Input(UInt(32.W))
  val ghm_packet_outs                            = Output(Vec(params.number_of_little_cores, UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS+1).W)))
  val ghm_status_outs                            = Output(Vec(params.number_of_little_cores, UInt(32.W)))
  val ghe_event_in                               = Input(Vec(params.number_of_little_cores, UInt(6.W)))
  val clear_ic_status                            = Input(Vec(params.number_of_little_cores, UInt(1.W)))
  // val ghm_big_complete                           = Output(Vec(params.number_of_little_cores, Bool()))

  // val ghm_big_complete                           = I(Vec(params.number_of_little_cores, Bool()))//from big
  val clear_ic_status_tomain                     = Output(UInt(GH_GlobalParams.GH_NUM_CORES.W))
  // val if_big_complete_req                        = Output(UInt((GH_GlobalParams.GH_NUM_CORES-1).W))
  // val if_big_complete_ack                        = Input(UInt((GH_GlobalParams.GH_NUM_CORES-1).W))
  val bigcore_hang                               = Output(UInt(1.W))
  val bigcore_comp                               = Output(UInt(3.W))
  val debug_bp                                   = Output(UInt(2.W))
  val ic_counter                                 = Input(UInt((16*GH_GlobalParams.GH_NUM_CORES).W))
  val debug_maincore_status                      = Input(UInt(4.W))
  val icsl_counter                               = Output(Vec(params.number_of_little_cores, UInt(20.W)))
  val ghe_revent_in                              = Input(Vec(params.number_of_little_cores, UInt(1.W)))
  // val ghm_icsl_ack_out                           = Output(Vec(params.number_of_little_cores, Bool()))
  // val ghm_if_big_complete                        = Input(Vec(params.number_of_little_cores, Bool()))
  // val ghm_big_switch_out                         = Output(Vec(params.number_of_little_cores, Bool()))
  val ghm_cdc_empty_out                          = Output(Vec(params.number_of_little_cores, Bool()))
  val icsl_na                                    = Output(UInt((GH_GlobalParams.GH_NUM_CORES).W))

  val debug_gcounter                             = Output(UInt(64.W))
  val if_agg_free                                = Input(UInt(1.W))
  val core_r_arfs_in                             = Input(UInt((params.width_GH_packet+1+8+8).W))
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

    val data_cdc_ready                             = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    // val arfs_dest                                  = WireInit(0.U((params.number_of_little_cores).W))

    // packet_dest                                   := io.ghm_packet_dest(params.number_of_little_cores-1, 0)
    val packet_dest                                = WireInit(VecInit(Seq.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(4.W))))
    val arfs_pidx                                  = WireInit(io.core_r_arfs_in(params.width_GH_packet+7+1, params.width_GH_packet+1))
    val arfs_ecp_idx                               = WireInit(io.core_r_arfs_in(params.width_GH_packet+15+1, params.width_GH_packet+8+1))

    val arfs_dest                                  = arfs_pidx(5, 3)
    val arfs_ecp_dest                              = arfs_ecp_idx(5, 3)
    dontTouch(arfs_dest)
    dontTouch(arfs_ecp_dest)
    dontTouch(packet_dest)
    for(i<- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
      packet_dest(i)                              := io.ghm_packet_in((i+1)*params.width_GH_packet-1, (i+1)*params.width_GH_packet-8)(6,3)
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

    //需要对控制信号扩展，以此来防止信号出错,控制信号大部分都是一系列高电平，需要去转换为单个高电平,同时需要保证CDC FIFO不能满
    for (i <- 0 to params.number_of_little_cores - 1) {
      val if_data_en = (0 until GH_GlobalParams.GH_TOTAL_PACKETS).map{j=>
        packet_dest(j)===(i+1).U
      }.reduce(_|_)
      dontTouch(if_data_en)
      //data  
      u_data_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_data_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_data_cdc(i).io.deq_clock := io.ghm_clock(i+1).asClock
      u_data_cdc(i).io.deq_reset := io.ghm_reset(i+1)

      u_data_cdc(i).io.enq.valid := if_data_en
      u_data_cdc(i).io.enq.bits  := io.ghm_packet_in
      data_cdc_ready(i)          := io.ghe_event_in(i)(4)&(!io.ghe_event_in(i)(0))
      u_data_cdc(i).io.deq.ready := data_cdc_ready(i)
      packet_out_wires(i)        := Mux(u_data_cdc(i).io.deq.fire,u_data_cdc(i).io.deq.bits,0.U)
      cdc_busy(i)                := (!u_data_cdc(i).io.enq.ready)
      cdc_empty(i)               := (!u_data_cdc(i).io.deq.valid)


      //arfs 
      
      u_arfs_cdc(i).io.deq_clock := io.ghm_clock(i+1).asClock
      u_arfs_cdc(i).io.deq_reset := io.ghm_reset(i+1)

      u_arfs_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_arfs_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_arfs_cdc(i).io.enq.valid := arfs_dest===(i+1).U||arfs_ecp_dest===(i+1).U//每个都会接到数据，但是有的是用来check
      u_arfs_cdc(i).io.enq.bits  := io.core_r_arfs_in
      u_arfs_cdc(i).io.deq.ready := true.B
      io.core_r_arfs_c(i)        := Mux(u_arfs_cdc(i).io.deq.fire,u_arfs_cdc(i).io.deq.bits,0.U)

      arfs_cdc_busy(i)          := (!u_arfs_cdc(i).io.enq.ready)
      dontTouch(u_arfs_cdc(i).io.enq.ready)
      //little to big CDC
      l_wctrl(i)                     := Cat(io.clear_ic_status(i),io.ghe_revent_in(i),io.ghe_event_in(i))
      u_l2b_ctrl_cdc(i).io.deq_clock := io.ghm_clock(0).asClock
      u_l2b_ctrl_cdc(i).io.deq_reset := io.ghm_reset(0)
      u_l2b_ctrl_cdc(i).io.enq_clock := io.ghm_clock(i+1).asClock
      u_l2b_ctrl_cdc(i).io.enq_reset := io.ghm_reset(i+1)
      u_l2b_ctrl_cdc(i).io.enq.valid := io.clear_ic_status(i)|io.ghe_revent_in(i)|io.ghe_event_in(i)=/=0.U
      u_l2b_ctrl_cdc(i).io.enq.bits  := l_wctrl(i)
      u_l2b_ctrl_cdc(i).io.deq.ready := true.B
      dontTouch(u_l2b_ctrl_cdc(i).io.enq.ready)
      b_rctrl(i)                     := Mux(u_l2b_ctrl_cdc(i).io.deq.fire,u_l2b_ctrl_cdc(i).io.deq.bits,0.U)

      //big to little CDC

      val source_counter = io.ic_counter((i+2)*16-1,(i+1)*16)
      val source_status = Cat(io.ghm_status_in(31), io.ghm_status_in(4,0))
      val completion_active = source_counter(15)

      /*
       * Send one CDC transaction for each completed counter.  The old
       * level-sensitive valid condition enqueued the same 0x8000 value every
       * big-core cycle and allowed stale completions to survive into the next
       * checker session.  completion_sent is cleared only after R_IC clears
       * the source counter in response to the checker's acknowledgement.
       */
      val completion_sent = withClockAndReset(io.ghm_clock(0).asClock, io.ghm_reset(0).asAsyncReset) {
        RegInit(false.B)
      }
      val status_sent = withClockAndReset(io.ghm_clock(0).asClock, io.ghm_reset(0).asAsyncReset) {
        RegInit(0.U(6.W))
      }
      val completion_needs_send = completion_active && !completion_sent
      val status_needs_send = source_status =/= status_sent

      b_wctrl(i)                     := Cat(Mux(completion_needs_send, source_counter, 0.U(16.W)), source_status)
      u_b2l_ctrl_cdc(i).io.deq_clock := io.ghm_clock(i+1).asClock
      u_b2l_ctrl_cdc(i).io.deq_reset := io.ghm_reset(i+1)
      u_b2l_ctrl_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_b2l_ctrl_cdc(i).io.enq_reset := io.ghm_reset(0)
      // Defer status-only updates while a completion is awaiting acknowledgement.
      u_b2l_ctrl_cdc(i).io.enq.valid := completion_needs_send || (!completion_active && status_needs_send)
      u_b2l_ctrl_cdc(i).io.enq.bits  := b_wctrl(i)
      u_b2l_ctrl_cdc(i).io.deq.ready := true.B

      when (!completion_active) {
        completion_sent := false.B
      }.elsewhen (u_b2l_ctrl_cdc(i).io.enq.fire) {
        completion_sent := true.B
      }
      when (u_b2l_ctrl_cdc(i).io.enq.fire) {
        status_sent := source_status
      }

      /*
       * Hold the received counter/status in the checker clock domain.  A
       * completed counter therefore cannot be missed if it arrives before
       * software executes the replay jump.  The local acknowledgement clears
       * the counter immediately; the status bits remain available as levels.
       */
      val received_ctrl = withClockAndReset(io.ghm_clock(i+1).asClock, io.ghm_reset(i+1).asAsyncReset) {
        val ctrl = RegInit(0.U(22.W))
        when (io.clear_ic_status(i).asBool) {
          ctrl := Cat(0.U(16.W), ctrl(5,0))
        }.elsewhen (u_b2l_ctrl_cdc(i).io.deq.fire) {
          ctrl := u_b2l_ctrl_cdc(i).io.deq.bits
        }
        ctrl
      }
      l_rctrl(i)                     := received_ctrl
      dontTouch(u_b2l_ctrl_cdc(i).io.enq.ready)
    }
    dontTouch(l_wctrl)
    dontTouch(b_wctrl)
    dontTouch(data_cdc_ready)
    
    //所有信号都需要展宽
    // 改为锁存型 (sticky)：一旦收到 checker 完成信号就不再清零，
    // 避免不同 checker 的 CDC 脉冲不对齐导致 reduce(_&_) 永远为 0。
    val cdc_ghe_event                              = RegInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U(6.W))))
    for (i <- 0 until params.number_of_little_cores) {
      when (b_rctrl(i) =/= 0.U) {
        cdc_ghe_event(i) := b_rctrl(i)(5, 0)
      }
    }
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

    val if_filters_empty                           = io.ghm_status_in(31)

    val if_cdc_empty                               = cdc_empty.reduce(_&_)//这个信号不知道会不会出问题？
    val if_no_inflight_packets                     = WireInit(VecInit((0 until params.number_of_little_cores).map{i=>cdc_filter_empty(i) & cdc_empty(i) } )) 
    big_bp := u_b2l_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    little_bp := u_l2b_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    //need CDC
    dontTouch(big_bp)
    io.clear_ic_status_tomain                     := Cat(Cat(cdc_clear_ic_status.reverse), zero)//小核心到大核心//1bit 会延迟2个周期
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

    io.bigcore_hang                              := cdc_busy.reduce(_|_)|arfs_cdc_busy.reduce(_|_)
    io.bigcore_comp                              := cdc_ghe_event.map{i=>i(3,1)}.reduce(_&_)//cdc
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
    io.icsl_na                                   := Cat(Cat(cdc_ghe_revent.reverse), zero)//小->大 1bit
  }
}

case class GHMCoreLocated(loc: HierarchicalLocation) extends Field[Option[GHMParams]](None)

object GHMCore {

  def attach(params: GHMParams, subsystem: BaseSubsystem with HasTiles, where: TLBusWrapperLocation)
            (implicit p: Parameters) {
    val number_of_ghes                             = subsystem.tile_ghe_packet_in_EPNodes.size
    println("#### Jessica #### Tieing off GHM **Nodes**, core number:", number_of_ghes,"...!!")

    // Creating nodes for connections.
    val bigcore_hang_SRNode                        = BundleBridgeSource[UInt](Some(() => UInt(1.W)))
    val bigcore_comp_SRNode                        = BundleBridgeSource[UInt](Some(() => UInt(3.W)))
    val debug_bp_SRNode                            = BundleBridgeSource[UInt](Some(() => UInt(2.W)))
    val ghm_ght_packet_in_SKNode                   = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_TOTAL_PACKETS*params.width_GH_packet).W)))
    val core_r_arfs_in_SKNode                      = BundleBridgeSink[UInt](Some(() => UInt((params.width_GH_packet+1+8+8).W)))

    val ic_counter_SKNode                          = BundleBridgeSink[UInt](Some(() => UInt((16*GH_GlobalParams.GH_NUM_CORES).W)))
    // val icsl_ack_SKNode                            = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    // val big_complete_ack_SKNode                            = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    // val big_checker_switch_SKNode                  = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))

    val debug_maincore_status_SKNode               = BundleBridgeSink[UInt](Some(() => UInt(4.W)))
    val ghm_ght_packet_dest_SKNode                 = BundleBridgeSink[UInt](Some(() => UInt(32.W)))

    val ghm_ght_status_in_SKNode                   = BundleBridgeSink[UInt](Some(() => UInt(32.W)))

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


    // val if_big_complete_reqSRNode                 = BundleBridgeSource[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    val if_agg_free_SKNode                         = BundleBridgeSink[UInt](Some(() => UInt(1.W)))


    // big_checker_switch_SKNode                     := subsystem.tile_big_checker_switch_EPNode
    // icsl_ack_SKNode                               := subsystem.tile_icsl_ack_EPNode
    core_r_arfs_in_SKNode                         := subsystem.tile_core_r_arfs_EPNode
    ghm_ght_packet_in_SKNode                      := subsystem.tile_ght_packet_out_EPNode
    ic_counter_SKNode                             := subsystem.tile_ic_counter_out_EPNode
    debug_maincore_status_SKNode                  := subsystem.debug_maincore_status_out_EPNode
    ghm_ght_packet_dest_SKNode                    := subsystem.tile_ght_packet_dest_EPNode
    ghm_ght_status_in_SKNode                      := subsystem.tile_ght_status_out_EPNode
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
    subsystem.tile_bigcore_comp_EPNode            := bigcore_comp_SRNode
    subsystem.tile_bigcore_hang_EPNode            := bigcore_hang_SRNode
    subsystem.tile_debug_bp_EPNode                := debug_bp_SRNode
    // subsystem.tile_if_big_complete_req_EPNode     := if_big_complete_reqSRNode 
                                                  // := if_big_complete_reqSRNode


    subsystem.tile_debug_gcounter_EPNode          := debug_gcounter_SRNode
    
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
      ghm.module.io.ghm_packet_in                 := ghm_ght_packet_in_SKNode.bundle
      ghm.module.io.core_r_arfs_in                := core_r_arfs_in_SKNode.bundle
      ghm.module.io.ghm_packet_dest               := ghm_ght_packet_dest_SKNode.bundle
      ghm.module.io.ghm_status_in                 := ghm_ght_status_in_SKNode.bundle
      ghm.module.io.if_agg_free                   := if_agg_free_SKNode.bundle 
      ghm.module.io.ic_counter                    := ic_counter_SKNode.bundle
      ghm.module.io.debug_maincore_status         := debug_maincore_status_SKNode.bundle
      // ghm.module.io.if_big_complete_ack           := big_complete_ack_SKNode.bundle 
      for (i <- 0 to number_of_ghes-1) {
        ghm.module.io.ghm_clock(i)                        :=ghm_clock_in_SKNodes(i).bundle.asBool
        ghm.module.io.ghm_reset(i)                        :=ghm_reset_in_SKNodes(i).bundle.asBool
        if (i == 0) { // The big core
          // GHE is not connected to the big core
          ghm_ghe_packet_out_SRNodes(i).bundle    := 0.U 
          core_r_arfs_c_SRNodes(i).bundle         := 0.U
          ghm_ghe_status_out_SRNodes(i).bundle    := 0.U
          // ghm_big_complete_SRNodes(i).bundle      := 0.U
          clear_ic_status_tomainSRNodes(i).bundle := ghm.module.io.clear_ic_status_tomain
          // if_big_complete_reqSRNodes(i).bundle    := 
          icsl_naSRNodes(i).bundle                := ghm.module.io.icsl_na
          icsl_out_SRNodes(i).bundle              := 0.U
        } else {// -1 big core
          ghm_ghe_packet_out_SRNodes(i).bundle    := ghm.module.io.ghm_packet_outs(i-1)
          core_r_arfs_c_SRNodes(i).bundle         := ghm.module.io.core_r_arfs_c(i-1)
          ghm_ghe_status_out_SRNodes(i).bundle    := ghm.module.io.ghm_status_outs(i-1)
          // ghm_big_complete_SRNodes(i).bundle      := ghm.module.io.ghm_big_complete(i-1)
          clear_ic_status_tomainSRNodes(i).bundle := 0.U
          icsl_naSRNodes(i).bundle                := 0.U
          ghm_cdc_empty_out_SKNodes(i).bundle     := ghm.module.io.ghm_cdc_empty_out(i-1)
          // ghm_icsl_ack_out_SKNodes(i).bundle      := ghm.module.io.ghm_icsl_ack_out(i-1)
          icsl_out_SRNodes(i).bundle              := ghm.module.io.icsl_counter(i-1)
          // ghm_big_complete_SKNodes(i).bundle      := ghm.module.io.ghm_if_big_complete(i-1)

          ghm.module.io.ghe_event_in(i-1)         := ghm_ghe_event_in_SKNodes(i).bundle
          ghm.module.io.ghe_revent_in(i-1)        := ghm_ghe_revent_in_SKNodes(i).bundle
          ghm.module.io.clear_ic_status(i-1)      := clear_ic_status_SkNodes(i).bundle
          // ghm.module.io.ghm_if_big_complete(i-1)  := ghm_if_big_complete_SKNodes(i).bundle
          
        }
      }

      bigcore_hang_SRNode.bundle                  := ghm.module.io.bigcore_hang
      bigcore_comp_SRNode.bundle                  := ghm.module.io.bigcore_comp
      debug_bp_SRNode.bundle                      := ghm.module.io.debug_bp
      debug_gcounter_SRNode.bundle                := ghm.module.io.debug_gcounter
      // if_big_complete_reqSRNode.bundle            := ghm.module.io.if_big_complete_req
    }
    ghm
  }
}
