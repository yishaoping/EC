package opt4recovery
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(
    new boom.recovery.PackageRecoveryController,
    Array("--target-dir", args(0)))
}
