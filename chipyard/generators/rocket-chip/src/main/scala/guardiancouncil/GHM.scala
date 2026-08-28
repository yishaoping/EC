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
  val checker_segment_id_bigcore                 = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt((GH_GlobalParams.GH_NUM_CORES * GH_GlobalParams.GH_PACKET_SEQ_BITS).W)))
  val ghm_packet_dest                            = Input(UInt((params.number_of_little_cores*2).W))
  val ghm_status_in                              = Input(Vec(GH_GlobalParams.GH_NUM_BIG_CORES, UInt(32.W)))
  val ghm_packet_outs                            = Output(Vec(params.number_of_little_cores, UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS+GH_GlobalParams.GH_PACKET_SEQ_BITS+1).W)))
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
  val core_r_arfs_c                              = Output(Vec(params.number_of_little_cores, UInt((params.width_GH_packet+1+8+GH_GlobalParams.GH_PACKET_SEQ_BITS+1).W)))
  val checker_result_in                         = Input(Vec(params.number_of_little_cores, UInt(GH_GlobalParams.GH_CHECKER_RESULT_BITS.W)))
  val checker_result_ready                      = Output(Vec(params.number_of_little_cores, Bool()))
  val checker_results_out                       = Output(Vec(params.number_of_little_cores, UInt(GH_GlobalParams.GH_CHECKER_RESULT_BITS.W)))
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
    val packet_out_wires                           = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(0.U((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS+GH_GlobalParams.GH_PACKET_SEQ_BITS+1).W))))
    val cdc_busy                                   = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val arfs_cdc_busy                              = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val cdc_empty                                  = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val packet_ingress_empty                       = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    // 每个 checker 的完成位属于其 Rocket 时钟域，并直接送往同域 GHE。
    val checkerSessionDone                         = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))

    // OR-merge ic_counters from all big cores (each big core only fills its own checkers)
    val ic_counter_merged                          = io.ic_counter.reduce(_|_)

    val data_cdc_ready                             = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    val checker_result_release                     = WireInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    // Result delivery and BOOM ownership release are separate transactions.
    // Keep a release request asserted until the global BOOM status confirms
    // that this checker is actually free.  A one-cycle dequeue pulse is not
    // sufficient across clock domains and was the source of the watchdog
    // deadlock seen in the previous protocol.
    val result_release_pending = RegInit(VecInit(Seq.fill(params.number_of_little_cores)(false.B)))
    // ghm_status_in(0)(31) is a stable BOOM-domain level.  It remains in the
    // legacy control path for diagnostics; session completion itself uses the
    // acknowledged control protocol below rather than this edge.
    val filterEmptyPrev = withClockAndReset(io.ghm_clock(0).asClock, io.ghm_reset(0).asAsyncReset) {
      RegNext(io.ghm_status_in(0)(31), false.B)
    }
    val filterEmptyRise = io.ghm_status_in(0)(31) && !filterEmptyPrev
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


    val packetCdcBits = params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS + GH_GlobalParams.GH_PACKET_SEQ_BITS
    val u_data_cdc                                      = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt(packetCdcBits.W), AsyncQueueParams(256,2)))}
    // core_r_arfs_in contains an additional 8-bit ECP destination above the
    // checker-visible ARF payload.  That field is consumed by GHM for routing
    // and must be removed before the package sequence is prepended; relying on
    // UInt assignment truncation here would instead discard sequence MSBs.
    val arfPayloadBits = params.width_GH_packet + 1 + 8
    val arfRoutingBits = 8
    require(io.core_r_arfs_in.head.getWidth == arfPayloadBits + arfRoutingBits,
      "GHM ARF input must contain checker payload plus ECP routing metadata")
    require(io.core_r_arfs_c.head.getWidth ==
      arfPayloadBits + GH_GlobalParams.GH_PACKET_SEQ_BITS + 1,
      "GHM checker ARF output width must contain valid, sequence, and payload")
    val u_arfs_cdc                                      = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((arfPayloadBits+GH_GlobalParams.GH_PACKET_SEQ_BITS).W), AsyncQueueParams(8,2)))}//留8个余量防止写入太快
    val u_l2b_ctrl_cdc                                  = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt(9.W), AsyncQueueParams(64,2)))}
    val u_b2l_ctrl_cdc                                  = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((22).W), AsyncQueueParams(64,2)))}//早晚会满
    val u_session_ctrl_cdc                              = Seq.fill(params.number_of_little_cores) {
      Module(new AsyncQueue(UInt(GH_GlobalParams.GH_SESSION_CTRL_BITS.W), AsyncQueueParams(4, 2)))
    }
    val resultPayloadBits = GH_GlobalParams.GH_PACKET_SEQ_BITS + GH_GlobalParams.GH_CHECKER_STATUS_BITS
    val u_result_cdc                                    = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt(resultPayloadBits.W), AsyncQueueParams(256,2)))}

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

      val selected_packet_seq = Mux1H((0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        sel_data(b) -> io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
          full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS)
      })
      // A segment can be allocated after the last BOOM instruction has
      // committed. In that case GH_BUF has no entry, but the sequence still
      // needs one data-side transaction before ARF/CPS may be consumed.
      // A real data beat is the anchor; otherwise emit one empty anchor.
      val selected_segment_seq = Mux1H((0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        (io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
          full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS) =/= 0.U) ->
          io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
            full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS)
      })
      val selected_segment_valid = (0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
          full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS) =/= 0.U
      }.reduce(_|_)
      val selected_producer_empty = Mux1H((0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        val segment_seq = io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
          full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS)
        (segment_seq =/= 0.U) -> io.ghm_status_in(b)(31)
      })
      // A segment id is allocated before the last committing instruction is
      // necessarily visible at GH_BUF.  Therefore a low `if_data_en` in the
      // allocation cycle means only "no data is visible yet".  Do not turn
      // that observation into an empty packet.  The source-side empty level
      // must remain high for a settling window that starts after this segment
      // id is observed.  A later real data beat resets the window and always
      // wins over the empty-anchor path.
      val emptyAnchorSettleCycles = 3
      val emptyAnchorSettleWidth = log2Ceil(emptyAnchorSettleCycles + 1)
      val emptyAnchorReady = withClockAndReset(
        io.ghm_clock(0).asClock, io.ghm_reset(0).asAsyncReset) {
        val waitSeq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
        val waitCount = RegInit(0.U(emptyAnchorSettleWidth.W))
        val waitActive = RegInit(false.B)
        val producerEmpty = selected_producer_empty

        when (!selected_segment_valid) {
          waitActive := false.B
          waitCount := 0.U
        } .elsewhen (!waitActive || selected_segment_seq =/= waitSeq) {
          waitSeq := selected_segment_seq
          waitCount := 0.U
          waitActive := true.B
        } .elsewhen (if_data_en || !producerEmpty) {
          // Data may still be produced after the allocation edge.  Restart
          // the observation window whenever the producer is non-empty or a
          // real packet is visible.
          waitCount := 0.U
        } .elsewhen (waitCount < emptyAnchorSettleCycles.U) {
          waitCount := waitCount + 1.U
        }
        waitActive && producerEmpty && !if_data_en &&
          waitCount >= emptyAnchorSettleCycles.U
      }
      val anchor_seq_sent = withClockAndReset(
        io.ghm_clock(0).asClock, io.ghm_reset(0).asAsyncReset) {
        val seq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
        when (u_data_cdc(i).io.enq.fire) {
          seq := Mux(if_data_en, selected_packet_seq, selected_segment_seq)
        }
        seq
      }
      val empty_anchor_en = selected_segment_valid &&
        selected_segment_seq =/= anchor_seq_sent && !if_data_en && emptyAnchorReady
      u_data_cdc(i).io.enq.valid := if_data_en || empty_anchor_en
      u_data_cdc(i).io.enq.bits  := Cat(
        Mux(if_data_en, selected_packet_seq, selected_segment_seq),
        Mux(if_data_en, Mux1H(sel_data, io.ghm_packet_in), 0.U))
      // Bit 4 is the dedicated checker-side packet dequeue permission.  Bit 0
      // is a legacy event/near-full indication and is not a reliable level:
      // it may be sampled from an older GHE event while the checker is already
      // able to accept a packet.  Gating dequeue with !bit0 creates a cycle:
      // the checker waits for CDC empty, while the stale bit0 prevents the CDC
      // queue from being drained.  Use the explicit ready bit only; a checker
      // that cannot accept data must deassert bit4.
      data_cdc_ready(i)          := io.ghe_event_in(i)(4)
      // Data and ARF/CSR use independent CDC queues. Compare their head
      // sequences before dequeue so a fragment from package N+1 cannot pass a
      // still-pending fragment from package N. Keeping the newer item in its
      // AsyncQueue preserves both payloads instead of resolving a mismatch by
      // dropping one after it has reached the Rocket tile.
      val dataHeadSeq = u_data_cdc(i).io.deq.bits(packetCdcBits - 1,
        params.width_GH_packet * GH_GlobalParams.GH_TOTAL_PACKETS)
      val arfHeadSeq = u_arfs_cdc(i).io.deq.bits(
        arfPayloadBits + GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, arfPayloadBits)
      // An older ARF fragment can remain at the head after the data side has
      // advanced to a newer package. It is stale by sequence and must be
      // drained independently; otherwise data waits for ARF while ARF waits
      // for the data dequeue, recreating the very CDC deadlock this ordering
      // check is meant to prevent.
      val arfHeadStale = u_data_cdc(i).io.deq.valid &&
        u_arfs_cdc(i).io.deq.valid && arfHeadSeq < dataHeadSeq
      val dataHeadInOrder = !u_arfs_cdc(i).io.deq.valid ||
        dataHeadSeq <= arfHeadSeq || arfHeadStale
      val arfHeadInOrder = !u_data_cdc(i).io.deq.valid ||
        arfHeadSeq <= dataHeadSeq
      // Present the ordered head independently of ready. RocketTile decodes
      // its sequence and every lane type, then returns one atomic beat-ready
      // level on bit4. This is a standard valid/ready contract: using fire as
      // valid would hide the payload needed to compute type-correct ready.
      u_data_cdc(i).io.deq.ready := data_cdc_ready(i) && dataHeadInOrder
      packet_out_wires(i)        := Mux(u_data_cdc(i).io.deq.valid && dataHeadInOrder,
        Cat(true.B, u_data_cdc(i).io.deq.bits), 0.U)
      // The data vector is the package anchor, but it is dequeued only once
      // while the ARF/CPS stream has one entry per merge index.  Remember the
      // last data sequence consumed in the checker clock domain so remaining
      // ARF entries can continue after the data queue becomes empty.
      val dataConsumedSeq = withClockAndReset(
        io.ghm_clock(i + GH_GlobalParams.GH_NUM_BIG_CORES).asClock,
        io.ghm_reset(i + GH_GlobalParams.GH_NUM_BIG_CORES).asAsyncReset) {
        val seq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
        when (u_data_cdc(i).io.deq.fire) {
          seq := dataHeadSeq
        }
        seq
      }
      cdc_busy(i)                := (!u_data_cdc(i).io.enq.ready)
      cdc_empty(i)               := !u_data_cdc(i).io.deq.valid && !u_arfs_cdc(i).io.deq.valid
      // A locally empty pair of CDC queues is not yet a package tail while
      // GH_BUF still owns packets that have not entered either queue.  Sample
      // the stable producer-empty level in this checker's clock domain before
      // combining it with the two dequeue-side empty indications.
      val filterEmptySynced = withClockAndReset(
        io.ghm_clock(i + GH_GlobalParams.GH_NUM_BIG_CORES).asClock,
        io.ghm_reset(i + GH_GlobalParams.GH_NUM_BIG_CORES).asAsyncReset) {
        AsyncResetSynchronizerShiftReg(selected_producer_empty, sync = 3,
          name = Some(s"ghm_filter_empty_checker_${i}_sync"))
      }
      packet_ingress_empty(i) := cdc_empty(i) && filterEmptySynced


      //arfs 
      u_arfs_cdc(i).io.deq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_arfs_cdc(i).io.deq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)

      u_arfs_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_arfs_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_arfs_cdc(i).io.enq.valid := if_arfs_en
      val selectedArfSeq = Mux1H((0 until GH_GlobalParams.GH_NUM_BIG_CORES).map { b =>
        val full_idx = i + GH_GlobalParams.GH_NUM_BIG_CORES
        sel_arfs(b) -> io.checker_segment_id_bigcore(b)((full_idx + 1) * GH_GlobalParams.GH_PACKET_SEQ_BITS - 1,
          full_idx * GH_GlobalParams.GH_PACKET_SEQ_BITS)
      })
      val selectedArfInput = Mux1H(sel_arfs, io.core_r_arfs_in)
      val selectedArfPayload = selectedArfInput(arfPayloadBits - 1, 0)
      u_arfs_cdc(i).io.enq.bits  := Cat(selectedArfSeq, selectedArfPayload)
      // Before the first data dequeue, hold an early ARF in the CDC queue so
      // RocketTile cannot see a sequence with no package anchor.  After the
      // anchor has been consumed, RocketTile's packet sequence watermark lets
      // it accept the remaining ARF entries even though data.valid is low.
      // Entries older than the last consumed sequence are safe to drain as
      // stale fragments; newer entries remain held until their data arrives.
      val arfAfterData = dataConsumedSeq =/= 0.U && arfHeadSeq <= dataConsumedSeq
      u_arfs_cdc(i).io.deq.ready := arfHeadInOrder &&
        (u_data_cdc(i).io.deq.fire || arfAfterData || arfHeadStale)
      io.core_r_arfs_c(i)        := Mux(u_arfs_cdc(i).io.deq.fire,
        Cat(true.B, u_arfs_cdc(i).io.deq.bits), 0.U)

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
      u_b2l_ctrl_cdc(i).io.enq.valid := filterEmptyRise || routed_status =/= 0.U ||
        ic_counter_merged((i+1+GH_GlobalParams.GH_NUM_BIG_CORES)*16-1) =/= 0.U
      u_b2l_ctrl_cdc(i).io.enq.bits  := b_wctrl(i)
      u_b2l_ctrl_cdc(i).io.deq.ready := true.B
      l_rctrl(i)                     := Mux(u_b2l_ctrl_cdc(i).io.deq.fire,u_b2l_ctrl_cdc(i).io.deq.bits,0.U)
      dontTouch(u_b2l_ctrl_cdc(i).io.enq.ready)

      // 会话控制与旧的 22 位计数控制通道分离。源端将 START/FINISH
      // 保存在 pending 寄存器中，直到 AsyncQueue 接受该消息；因此即使
      // checker 时钟暂停或 FIFO 暂满，也不会丢失一次 workload 边界。
      val sessionEpoch = RegInit(0.U(GH_GlobalParams.GH_SESSION_EPOCH_BITS.W))
      val sessionActive = RegInit(false.B)
      val startPending = RegInit(false.B)
      val finishPending = RegInit(false.B)
      val startEpoch = RegInit(0.U(GH_GlobalParams.GH_SESSION_EPOCH_BITS.W))
      val finishEpoch = RegInit(0.U(GH_GlobalParams.GH_SESSION_EPOCH_BITS.W))
      val globalSessionStatus = io.ghm_status_in(0)(4, 0)
      val startRequested = globalSessionStatus === GH_GlobalParams.GH_SESSION_START.U &&
        !sessionActive && !finishPending
      val finishRequested = globalSessionStatus === GH_GlobalParams.GH_SESSION_FINISH.U &&
        sessionActive

      when (startRequested) {
        sessionEpoch := sessionEpoch + 1.U
        sessionActive := true.B
        startPending := true.B
        startEpoch := sessionEpoch + 1.U
      }
      when (finishRequested) {
        sessionActive := false.B
        finishPending := true.B
        finishEpoch := sessionEpoch
      }

      u_session_ctrl_cdc(i).io.enq_clock := io.ghm_clock(0).asClock
      u_session_ctrl_cdc(i).io.enq_reset := io.ghm_reset(0)
      u_session_ctrl_cdc(i).io.deq_clock := io.ghm_clock(i + GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_session_ctrl_cdc(i).io.deq_reset := io.ghm_reset(i + GH_GlobalParams.GH_NUM_BIG_CORES)
      u_session_ctrl_cdc(i).io.enq.valid := startPending || finishPending
      u_session_ctrl_cdc(i).io.enq.bits := Mux(startPending,
        Cat(GH_GlobalParams.GH_SESSION_PROTOCOL_VERSION.U(GH_GlobalParams.GH_SESSION_VERSION_BITS.W),
          GH_GlobalParams.GH_SESSION_START.U(GH_GlobalParams.GH_SESSION_TYPE_BITS.W),
          startEpoch, GH_GlobalParams.GH_SESSION_START.U(GH_GlobalParams.GH_SESSION_STATUS_BITS.W)),
        Cat(GH_GlobalParams.GH_SESSION_PROTOCOL_VERSION.U(GH_GlobalParams.GH_SESSION_VERSION_BITS.W),
          GH_GlobalParams.GH_SESSION_FINISH.U(GH_GlobalParams.GH_SESSION_TYPE_BITS.W),
          finishEpoch, GH_GlobalParams.GH_SESSION_FINISH.U(GH_GlobalParams.GH_SESSION_STATUS_BITS.W)))
      when (u_session_ctrl_cdc(i).io.enq.fire) {
        when (startPending) {
          startPending := false.B
        } .otherwise {
          finishPending := false.B
        }
      }

      // 接收侧只在 dequeue fire 时更新状态。FINISH 必须匹配已接收的
      // START epoch；完成状态随后保持为电平，直至下一条 START 清除它。
      checkerSessionDone(i) := withClockAndReset(
        io.ghm_clock(i + GH_GlobalParams.GH_NUM_BIG_CORES).asClock,
        io.ghm_reset(i + GH_GlobalParams.GH_NUM_BIG_CORES).asAsyncReset) {
        val receivedEpoch = RegInit(0.U(GH_GlobalParams.GH_SESSION_EPOCH_BITS.W))
        val receivedActive = RegInit(false.B)
        val finishSeen = RegInit(false.B)
        val checkerDone = RegInit(false.B)
        val ctrl = u_session_ctrl_cdc(i).io.deq.bits
        val ctrlVersion = ctrl(GH_GlobalParams.GH_SESSION_CTRL_BITS - 1,
          GH_GlobalParams.GH_SESSION_CTRL_BITS - GH_GlobalParams.GH_SESSION_VERSION_BITS)
        val ctrlType = ctrl(GH_GlobalParams.GH_SESSION_STATUS_BITS + GH_GlobalParams.GH_SESSION_EPOCH_BITS +
          GH_GlobalParams.GH_SESSION_TYPE_BITS - 1,
          GH_GlobalParams.GH_SESSION_STATUS_BITS + GH_GlobalParams.GH_SESSION_EPOCH_BITS)
        val ctrlEpoch = ctrl(GH_GlobalParams.GH_SESSION_STATUS_BITS + GH_GlobalParams.GH_SESSION_EPOCH_BITS - 1,
          GH_GlobalParams.GH_SESSION_STATUS_BITS)
        u_session_ctrl_cdc(i).io.deq.ready := true.B
        when (u_session_ctrl_cdc(i).io.deq.fire &&
          ctrlVersion === GH_GlobalParams.GH_SESSION_PROTOCOL_VERSION.U) {
          when (ctrlType === GH_GlobalParams.GH_SESSION_START.U) {
            receivedEpoch := ctrlEpoch
            receivedActive := true.B
            finishSeen := false.B
            checkerDone := false.B
          } .elsewhen (ctrlType === GH_GlobalParams.GH_SESSION_FINISH.U &&
            receivedActive && ctrlEpoch === receivedEpoch) {
            finishSeen := true.B
          }
        }
        when (receivedActive && finishSeen && packet_ingress_empty(i)) {
          checkerDone := true.B
        }
        checkerDone
      }

      // Complete checker results cross independently from control pulses. The
      // Rocket side holds valid until ready, so a full queue cannot lose one.
      u_result_cdc(i).io.enq_clock := io.ghm_clock(i+GH_GlobalParams.GH_NUM_BIG_CORES).asClock
      u_result_cdc(i).io.enq_reset := io.ghm_reset(i+GH_GlobalParams.GH_NUM_BIG_CORES)
      u_result_cdc(i).io.deq_clock := io.ghm_clock(0).asClock
      u_result_cdc(i).io.deq_reset := io.ghm_reset(0)
      u_result_cdc(i).io.enq.valid := io.checker_result_in(i)(GH_GlobalParams.GH_CHECKER_RESULT_BITS-1)
      u_result_cdc(i).io.enq.bits := io.checker_result_in(i)(resultPayloadBits-1, 0)
      io.checker_result_ready(i) := u_result_cdc(i).io.enq.ready
      // Only accept a new result after the previous release has been observed
      // as cleared in the global BOOM status. The result event is a one-cycle
      // pulse; resource release is the separate held level below.
      u_result_cdc(i).io.deq.ready := !result_release_pending(i)
      val result_deq_fire = u_result_cdc(i).io.deq.fire
      when (result_deq_fire) {
        result_release_pending(i) := true.B
      }.elsewhen (result_release_pending(i) &&
        !io.ic_status_bigcore.reduce(_|_)(i + GH_GlobalParams.GH_NUM_BIG_CORES)) {
        result_release_pending(i) := false.B
      }
      // This level is consumed by the BOOM-side R_IC.  It remains asserted
      // until ic_status is observed low, making the release idempotent.
      checker_result_release(i) := result_release_pending(i) || result_deq_fire
      io.checker_results_out(i) := Mux(result_deq_fire,
        Cat(true.B, u_result_cdc(i).io.deq.bits), 0.U)
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
    // val cdc_if_big_complete                        = WireInit(VecInit(b_rctrl.map{i=>i(8)} ))   //只采样高信号 not uesd
    
    val cdc_icsl_cnt                               = l_rctrl.map{i=>i(21,6)}
    val cdc_filter_empty                           = l_rctrl.map{i=>i(5)} //旧诊断控制字段
    val cdc_ghm_status                             = l_rctrl.map{i=>i(4,0)} //旧诊断控制字段
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
    // Reuse the synchronized level used by package completion.  Requiring a
    // filter-empty control pulse and CDC-empty to coincide could miss the
    // drained state when the pulse arrived a cycle before the final dequeue.
    val if_no_inflight_packets                     = packet_ingress_empty
    big_bp := u_b2l_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    little_bp := u_l2b_ctrl_cdc.map({i=>i.io.enq.ready}).reduce(_&_)
    //need CDC
    dontTouch(big_bp)
    io.clear_ic_status_tomain                     := Cat(Cat(checker_result_release.reverse), 0.U(GH_GlobalParams.GH_NUM_BIG_CORES.W))
    // io.if_big_complete_req                        := Cat(cdc_if_big_complete.reverse)



    dontTouch(if_no_inflight_packets)
    dontTouch(if_filters_empty)
    dontTouch(if_cdc_empty)
    dontTouch(cdc_busy)
    // dontTouch(if_no_inflight_packets)
    val zeros_30bit                                = WireInit(0.U(30.W))
    // GHE 只消费稳定的完成电平。START 清除接收端粘滞状态，FINISH 与
    // 数据 CDC 排空共同置位该电平；不再让软件依赖 FIFO 出队的单周期脉冲。
    for(i <- 0 to params.number_of_little_cores - 1) {
      io.ghm_packet_outs(i)                       := packet_out_wires(i)
      io.ghm_status_outs(i)                       := Mux(checkerSessionDone(i),
        Cat(zeros_30bit, GH_GlobalParams.GH_SESSION_FINISH.U(2.W)), 0.U)
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
      io.ghm_cdc_empty_out(i)                    := packet_ingress_empty(i)
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
    var checker_segment_id_SKNodes                 = Seq[BundleBridgeSink[UInt]]()
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      val ic_counter_SKNode                       = BundleBridgeSink[UInt](Some(() => UInt((16*GH_GlobalParams.GH_NUM_CORES).W)))
      ic_counter_SKNodes                          = ic_counter_SKNodes :+ ic_counter_SKNode
      val segmentNode = BundleBridgeSink[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES * GH_GlobalParams.GH_PACKET_SEQ_BITS).W)))
      checker_segment_id_SKNodes = checker_segment_id_SKNodes :+ segmentNode
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
    var ghm_checker_result_in_SKNodes              = Seq[BundleBridgeSink[UInt]]()
    var checker_result_ready_SRNodes               = Seq[BundleBridgeSource[Bool]]()

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
    val checker_results_SRNode                     = BundleBridgeSource[UInt](Some(() => UInt((params.number_of_little_cores * GH_GlobalParams.GH_CHECKER_RESULT_BITS).W)))


    // val if_big_complete_reqSRNode                 = BundleBridgeSource[UInt](Some(() => UInt((GH_GlobalParams.GH_NUM_CORES-1).W)))
    val if_agg_free_SKNode                         = BundleBridgeSink[UInt](Some(() => UInt(1.W)))


    // big_checker_switch_SKNode                     := subsystem.tile_big_checker_switch_EPNode
    // icsl_ack_SKNode                               := subsystem.tile_icsl_ack_EPNode
    for (b <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
      ghm_ght_packet_in_SKNodes(b)                := subsystem.tile_ght_packet_out_EPNodes(b)
      core_r_arfs_in_SKNodes(b)                   := subsystem.tile_core_r_arfs_EPNodes(b)
      ic_counter_SKNodes(b)                       := subsystem.tile_ic_counter_out_EPNodes(b)
      checker_segment_id_SKNodes(b)               := subsystem.tile_checker_segment_id_out_EPNodes(b)
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

      val resultSink = BundleBridgeSink[UInt](Some(() => UInt(GH_GlobalParams.GH_CHECKER_RESULT_BITS.W)))
      ghm_checker_result_in_SKNodes = ghm_checker_result_in_SKNodes :+ resultSink
      resultSink := subsystem.tile_checker_result_out_EPNodes(i)
      val resultReadySource = BundleBridgeSource[Bool](Some(() => Bool()))
      checker_result_ready_SRNodes = checker_result_ready_SRNodes :+ resultReadySource
      subsystem.tile_checker_result_ready_EPNodes(i) := resultReadySource
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
    subsystem.tile_checker_results_EPNode          := checker_results_SRNode
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
      ghm.module.io.checker_segment_id_bigcore    := checker_segment_id_SKNodes.map(_.bundle)
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
          checker_result_ready_SRNodes(i).bundle  := false.B
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
          ghm.module.io.checker_result_in(ci)    := ghm_checker_result_in_SKNodes(i).bundle
          checker_result_ready_SRNodes(i).bundle := ghm.module.io.checker_result_ready(ci)
          
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
      checker_results_SRNode.bundle               := ghm.module.io.checker_results_out.asUInt
      // if_big_complete_reqSRNode.bundle            := ghm.module.io.if_big_complete_req
    }
    ghm
  }
}
