package ec528000

import chisel3.stage.ChiselStage
import freechips.rocketchip.r._
import freechips.rocketchip.guardiancouncil._
import freechips.rocketchip.diplomacy.LazyModule
import org.chipsalliance.cde.config.Parameters

// Verification entry point only; loaded by a temporary sbt setting, not by
// the production build. Elaborates the actual source modules without mocks.
object EC528000Generate extends App {
  implicit val p: Parameters = Parameters.empty
  val base = args(0)
  (new ChiselStage).emitVerilog(new R_IC(R_ICParams(GH_GlobalParams.GH_NUM_CORES, 16)),
    Array("--target-dir", base + "/ric"))
  (new ChiselStage).emitVerilog(new R_ICSL(R_ICSLParams(16)),
    Array("--target-dir", base + "/icsl"))
  (new ChiselStage).emitVerilog(LazyModule(new GHM(GHMParams(4, GH_GlobalParams.GH_WIDITH_PACKETS))).module,
    Array("--target-dir", base + "/ghm"))
}
