package opt4recovery
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(
    if (args(0) == "state") new boom.recovery.PackageRecoveryState(6, 96)
    else new boom.recovery.PackageRecoveryMemory(64),
    Array("--target-dir", args(1)))
}
