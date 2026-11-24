package palimpsesttest

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import chisel3.stage.ChiselStage
import chisel3.experimental.DataMirror
import freechips.rocketchip.r._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.guardiancouncil._

/** Production GHM and hart1 R_ICSL, including all four queue endpoints.
  * Other Checker receipts and RocketCore's RSUSL/LSL/result-owner join remain
  * host supplied. A management trap must block admission, not empty-tag reset.
  */
object EmitSeqTransport extends App {
  implicit val p: Parameters = new chipyard.PalimpsestSeqRebaseTestConfig
  class Harness extends LazyModule {
    val ghm = LazyModule(new GHM(GHMParams(4, GH_GlobalParams.GH_WIDITH_PACKETS)))
    lazy val module = new LazyModuleImp(this) {
      override def desiredName = "SeqTransportHarness"
      val io = IO(new Bundle {
        val clocks = Input(UInt(4.W))
        val managementTrap = Input(Bool())
        val contextIdle = Output(Bool())
        val packageIdle = Output(Bool())
        val localStart = Input(Bool())
        val localTrap = Input(Bool())
        val localRet = Input(Bool())
        val localCancel = Input(Bool())
        val localReturned = Input(Bool())
        val trapDepth = Output(UInt(4.W))
        val specialReturn = Output(Bool())
        val segment = Input(UInt(32.W))
        val ingressReady = Input(Bool())
        val resultValid = Input(Bool())
        val resultSeq = Input(UInt(32.W))
        val owned = Input(Bool())
        val request = Input(Bool())
        val ack = Output(Bool())
        val checkerAcks = Output(UInt(4.W))
        val receivedSeq = Output(UInt(32.W))
        val receivedEnd = Output(Bool())
        val release = Output(Bool())
        val resultSeen = Output(UInt(32.W))
        val anchors = Output(UInt(8.W))
        val dataBeat = Input(Bool())
        val arfBeat = Input(Bool())
        val payload = Input(UInt(64.W))
        val dataSeq = Output(UInt(32.W))
        val dataWord = Output(UInt(64.W))
        val arfCount = Output(UInt(8.W))
        val arfSeq = Output(UInt(32.W))
        val arfWord = Output(UInt(64.W))
        val producerBusy = Output(Bool())
        val session = Input(UInt(2.W))
        val sessionDone = Output(Bool())
      })
      val transport = ghm.module.io
      transport.ghm_clock := VecInit(Seq(clock.asBool) ++ io.clocks.asBools)
      transport.ghm_reset := VecInit(Seq.fill(5)(reset.asBool))
      transport.ghm_packet_in := 0.U.asTypeOf(chiselTypeOf(transport.ghm_packet_in))
      transport.ghm_packet_in(0) := Mux(io.dataBeat,
        Cat(8.U(8.W), 0.U(64.W), io.payload), 0.U)
      transport.checker_segment_id_bigcore(0) := io.segment << 32
      transport.ghm_packet_dest := 0.U
      transport.ghm_status_in(0) := "h80000000".U | io.session
      io.sessionDone := transport.ghm_status_outs(0) === GH_GlobalParams.GH_SESSION_FINISH.U
      transport.producer_seal_bigcore(0) := Cat(io.segment =/= 0.U, io.segment) << 33
      transport.ic_counter(0) := Mux(io.segment =/= 0.U, "h80010000".U, 0.U)
      transport.ghe_event_in := VecInit(Seq(Mux(io.ingressReady, 16.U(6.W), 0.U(6.W))) ++ Seq.fill(3)(16.U(6.W)))
      transport.clear_ic_status := 0.U.asTypeOf(chiselTypeOf(transport.clear_ic_status))
      transport.debug_maincore_status := 0.U
      transport.ghe_revent_in := 0.U.asTypeOf(chiselTypeOf(transport.ghe_revent_in))
      transport.checker_big_owner_bigcore(0) := 0.U
      transport.if_agg_free := 1.U
      transport.core_r_arfs_in := 0.U.asTypeOf(chiselTypeOf(transport.core_r_arfs_in))
      transport.core_r_arfs_in(0) := Mux(io.arfBeat,
        Cat(0.U(8.W), 8.U(8.W), true.B, io.payload.pad(GH_GlobalParams.GH_WIDITH_PACKETS)), 0.U)
      io.producerBusy := transport.bigcore_hang(0).asBool
      transport.ic_status_bigcore(0) := Mux(io.owned, 2.U, 0.U)
      transport.checker_result_in := VecInit(Seq(Cat(io.resultValid, 1.U(2.W), io.resultSeq)) ++ Seq.fill(3)(0.U(35.W)))
      val resultSeen = RegInit(0.U(32.W))
      when (transport.checker_results_out(0)(34)) { resultSeen := transport.checker_results_out(0)(31, 0) }
      io.resultSeen := resultSeen
      io.release := transport.clear_ic_status_tomain(1)
      io.receivedEnd := transport.producer_sealed_out(0)(32)
      io.receivedSeq := transport.icsl_counter(0)(51, 20)
      val anchors = withClockAndReset(io.clocks(0).asClock, reset.asAsyncReset) {
        val n = RegInit(0.U(8.W))
        val packet = transport.ghm_packet_outs(0)
        when (packet(packet.getWidth - 1) && io.ingressReady) { n := n + 1.U }
        n
      }
      io.anchors := anchors
      val dataSeen = withClockAndReset(io.clocks(0).asClock, reset.asAsyncReset) {
        val seq = RegInit(0.U(32.W))
        val word = RegInit(0.U(64.W))
        val packet = transport.ghm_packet_outs(0)
        when (packet(packet.getWidth - 1) && io.ingressReady) {
          seq := packet(packet.getWidth - 2, packet.getWidth - 33)
          word := packet(63, 0)
        }
        (seq, word)
      }
      io.dataSeq := dataSeen._1
      io.dataWord := dataSeen._2
      val arfSeen = withClockAndReset(io.clocks(0).asClock, reset.asAsyncReset) {
        val count = RegInit(0.U(8.W))
        val seq = RegInit(0.U(32.W))
        val word = RegInit(0.U(64.W))
        val packet = transport.core_r_arfs_c(0)
        when (packet(packet.getWidth - 1)) {
          count := count + 1.U
          seq := packet(packet.getWidth - 2, packet.getWidth - 33)
          word := packet(63, 0)
        }
        (count, seq, word)
      }
      io.arfCount := arfSeen._1
      io.arfSeq := arfSeen._2
      io.arfWord := arfSeen._3
      val request = WireInit(io.request)
      val ack = WireDefault(false.B)
      BoringUtils.addSource(request, "PALIMPSEST_SEQ_TRANSPORT_REQUEST")
      BoringUtils.addSink(ack, "PALIMPSEST_SEQ_TRANSPORT_ACK")
      io.ack := ack
      io.checkerAcks := VecInit((0 until 4).map { i =>
        val permit = WireDefault(false.B)
        val localAck = withClockAndReset(io.clocks(i).asClock, reset.asAsyncReset) {
          if (i == 0) {
            val icsl = Module(new R_ICSL(R_ICSLParams(16)))
            icsl.io.elements.values.filter(DataMirror.directionOf(_) == ActualDirection.Input).foreach {
              port => port := 0.U.asTypeOf(chiselTypeOf(port))
            }
            icsl.io.excpt_mode := io.managementTrap
            icsl.io.icsl_run := io.localStart.asUInt
            icsl.io.self_xcpt := io.localTrap
            icsl.io.self_ret := io.localRet
            icsl.io.if_check_cancelled := io.localCancel
            icsl.io.returned_to_special_address_valid := io.localReturned.asUInt
            icsl.io.if_correct_process := 1.U
            io.contextIdle := icsl.io.context_idle
            io.packageIdle := icsl.io.package_idle
            io.trapDepth := icsl.io.trap_depth
            io.specialReturn := icsl.io.if_rh_cp_pc.asBool
            // RocketCore adds its storage/result-owner join to this exact
            // package-idle condition. GHM supplies real FIFO-empty permits.
            val held = RegInit(false.B)
            when (permit && icsl.io.package_idle) { held := true.B }
            when (!permit) { held := false.B }
            held
          } else RegNext(permit, false.B)
        }
        BoringUtils.addSink(permit, s"PALIMPSEST_SEQ_CHECKER_PERMIT_${i + 1}")
        BoringUtils.addSource(localAck, s"PALIMPSEST_SEQ_CHECKER_ACK_${i + 1}")
        localAck
      }).asUInt
    }
  }
  require(args.length == 1)
  (new ChiselStage).emitVerilog(LazyModule(new Harness).module, Array("--target-dir", args(0)))
}
