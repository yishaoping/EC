package opt4fit
object EmitStats extends App {
(new chisel3.stage.ChiselStage).emitVerilog(new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256), Array("--target-dir", args(0)))
}
