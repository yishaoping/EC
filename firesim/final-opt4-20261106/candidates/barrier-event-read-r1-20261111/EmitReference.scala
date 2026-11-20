package opt4barrierreference
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(
    new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256),
    Array("--target-dir", args(0)))
}
