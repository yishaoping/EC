package palimpsesttest

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.guardiancouncil._
import boom.exu._

/** P5-04: production RSUSL comparator -> complete GHM result AsyncQueue ->
  * production Controller/SCP/EVT. The host supplies architectural snapshots,
  * local result permission and the Main ownership-release/cache/restore ACKs.
  * This does not instantiate Rocket's full package-tail/cleanup join or BOOM.
  */
object EmitCheckerRecovery extends App {
  require(args.length == 1, "target directory required")
  implicit val p: Parameters = (new chipyard.v1Config).alterPartial {
    case freechips.rocketchip.tilelink.PalimpsestSeqRebaseThreshold => BigInt(0)
  }
  class Harness extends LazyModule {
    val ghm = LazyModule(new GHM(GHMParams(4, GH_GlobalParams.GH_WIDITH_PACKETS)))
    lazy val module = new LazyModuleImp(this) {
      override def desiredName = "CheckerRecoveryHarness"
      val io = IO(new Bundle {
        val checkerClock = Input(Bool())
        val capture = Input(Bool())
        val clear = Input(Bool()); val start = Input(Bool())
        val beat = Input(Bool()); val index = Input(UInt(7.W))
        val mainInt = Input(UInt(64.W)); val mainFP = Input(UInt(64.W))
        val compare = Input(Bool()); val resultEnable = Input(Bool())
        val releaseOwnership = Input(Bool())
        val quiesced = Input(Bool()); val restoreDone = Input(Bool())
        val restartReady = Input(Bool())
        val complete = Output(Bool()); val compared = Output(Bool()); val mismatch = Output(Bool())
        val resultCount = Output(UInt(8.W)); val resultSeq = Output(UInt(32.W))
        val resultStatus = Output(UInt(2.W)); val release = Output(Bool()); val owned = Output(Bool())
        val stop = Output(Bool()); val restore = Output(Bool()); val fatal = Output(Bool())
        val restartValid = Output(Bool()); val restartCount = Output(UInt(8.W))
        val restoredSeq = Output(UInt(32.W)); val pc = Output(UInt(40.W))
        val integer = Output(UInt(64.W)); val floating = Output(UInt(64.W))
        val epoch = Output(UInt(32.W)); val dead8 = Output(Bool())
      })
      val checker = withClockAndReset(io.checkerClock.asClock, reset.asAsyncReset) {
        Module(new F0Harness)
      }
      checker.io.clear := io.clear; checker.io.start := io.start
      checker.io.seq := 8.U
      checker.io.beat := io.beat; checker.io.index := io.index
      checker.io.mainInt := io.mainInt; checker.io.mainFP := io.mainFP
      checker.io.checkerF0 := 0.U; checker.io.compare := io.compare
      io.complete := checker.io.complete; io.compared := checker.io.done
      io.mismatch := checker.io.error
      val transport = ghm.module.io
      transport.ghm_clock := VecInit(Seq(clock.asBool) ++ Seq.fill(4)(io.checkerClock))
      transport.ghm_reset := VecInit(Seq.fill(5)(reset.asBool))
      transport.ghm_packet_in := 0.U.asTypeOf(chiselTypeOf(transport.ghm_packet_in))
      transport.checker_segment_id_bigcore := 0.U.asTypeOf(chiselTypeOf(transport.checker_segment_id_bigcore))
      transport.ghm_packet_dest := 0.U
      transport.ghm_status_in := 0.U.asTypeOf(chiselTypeOf(transport.ghm_status_in))
      transport.producer_seal_bigcore := 0.U.asTypeOf(chiselTypeOf(transport.producer_seal_bigcore))
      transport.ghe_event_in := 0.U.asTypeOf(chiselTypeOf(transport.ghe_event_in))
      transport.clear_ic_status := 0.U.asTypeOf(chiselTypeOf(transport.clear_ic_status))
      transport.ic_counter := 0.U.asTypeOf(chiselTypeOf(transport.ic_counter))
      transport.debug_maincore_status := 0.U
      transport.ghe_revent_in := 0.U.asTypeOf(chiselTypeOf(transport.ghe_revent_in))
      transport.checker_big_owner_bigcore := 0.U.asTypeOf(chiselTypeOf(transport.checker_big_owner_bigcore))
      transport.if_agg_free := 1.U
      transport.core_r_arfs_in := 0.U.asTypeOf(chiselTypeOf(transport.core_r_arfs_in))
      val owned = RegInit(false.B)
      val release = transport.clear_ic_status_tomain(1)
      when (io.capture) { owned := true.B }
        .elsewhen (io.releaseOwnership && release) { owned := false.B }
      transport.ic_status_bigcore(0) := Mux(owned, 2.U, 0.U)
      io.release := release; io.owned := owned
      // RSUSL owns its held result until GHM actually accepts it. Result
      // permission stands for Rocket's local cleanup join in this fixture.
      val sent = withClockAndReset(io.checkerClock.asClock, reset.asAsyncReset) { RegInit(false.B) }
      val resultValid = checker.io.done && io.resultEnable && !sent
      val resultStatus = Mux(checker.io.error, GH_GlobalParams.GH_CHECKER_STATUS_FAIL.U(2.W),
        GH_GlobalParams.GH_CHECKER_STATUS_PASS.U(2.W))
      transport.checker_result_in := 0.U.asTypeOf(chiselTypeOf(transport.checker_result_in))
      transport.checker_result_in(0) := Cat(resultValid, resultStatus, 8.U(32.W))
      checker.io.ack := resultValid && transport.checker_result_ready(0)
      when (io.clear || io.start) { sent := false.B }
        .elsewhen (checker.io.ack) { sent := true.B }

      val ctrl = Module(new PalimpsestRollbackController)
      val cp = Module(new PalimpsestContextMemory(64, 40, 64))
      val evt = Module(new PalimpsestExecutionHistory(32, 1))
      cp.io.capture.valid := io.capture
      cp.io.capture.bits := 0.U.asTypeOf(chiselTypeOf(cp.io.capture.bits))
      cp.io.capture.bits.seq := 8.U; cp.io.capture.bits.pc := "h80000800".U
      cp.io.capture.bits.integer := VecInit(Seq.fill(32)(0x80.U(64.W)))
      cp.io.capture.bits.integer(0) := 0.U
      cp.io.capture.bits.floating := VecInit(Seq.fill(32)(0xf080.U(64.W)))
      cp.io.capture.bits.csr := 0xc080.U
      when (io.capture) { assert(cp.io.capture.ready, "checker fixture SCP unavailable") }
      cp.io.safeWatermark := 6.U; cp.io.read <> ctrl.io.checkpoint
      cp.io.discard.valid := ctrl.io.restart.fire; cp.io.discard.bits := ctrl.io.target
      cp.io.response.ready := ctrl.io.restart.fire; cp.io.abort := ctrl.io.abandonCheckpoint
      evt.io.allocated.valid := io.capture; evt.io.allocated.bits := 8.U
      evt.io.compact := false.B; evt.io.query(0) := 8.U
      evt.io.rollback <> ctrl.io.commitHistory
      val result = transport.checker_results_out(0)
      val resultEvent = result(GH_GlobalParams.GH_CHECKER_RESULT_BITS - 1)
      val status = result(33, 32)
      val error = resultEvent && status =/= GH_GlobalParams.GH_CHECKER_STATUS_PASS.U
      ctrl.io.error.valid := error; ctrl.io.error.bits.seq := result(31, 0)
      ctrl.io.error.bits.cancelled := status === GH_GlobalParams.GH_CHECKER_STATUS_CANCELLED.U
      when (error) { assert(ctrl.io.error.ready, "checker fixture lost Main error receipt") }
      ctrl.io.checkpointReady := cp.io.response.valid; ctrl.io.checkpointMissing := cp.io.missing
      ctrl.io.quiesced := io.quiesced && !owned
      ctrl.io.historyUnavailable := evt.io.full; ctrl.io.identityUnavailable := false.B
      ctrl.io.restored := io.restoreDone; ctrl.io.restart.ready := io.restartReady
      val resultCount = RegInit(0.U(8.W))
      val lastSeq = RegInit(0.U(32.W)); val lastStatus = RegInit(0.U(2.W))
      val restarts = RegInit(0.U(8.W))
      when (resultEvent) { resultCount := resultCount + 1.U; lastSeq := result(31, 0); lastStatus := status }
      when (ctrl.io.restart.fire) { restarts := restarts + 1.U }
      io.resultCount := resultCount; io.resultSeq := lastSeq; io.resultStatus := lastStatus
      io.stop := ctrl.io.stop; io.restore := ctrl.io.restore; io.fatal := ctrl.io.fatal
      io.restartValid := ctrl.io.restart.valid; io.restartCount := restarts
      io.restoredSeq := cp.io.response.bits.seq; io.pc := cp.io.response.bits.pc
      io.integer := cp.io.response.bits.integer(1); io.floating := cp.io.response.bits.floating(0)
      io.epoch := evt.io.epoch; io.dead8 := !evt.io.survives(0)
    }
  }
  (new ChiselStage).emitVerilog(LazyModule(new Harness).module, Array("--target-dir", args(0)))
}
