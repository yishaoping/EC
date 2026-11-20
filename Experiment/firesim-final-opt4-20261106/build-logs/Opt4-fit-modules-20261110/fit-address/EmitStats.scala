package opt4fit
object EmitStats extends App {
(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256), Array("--target-dir", args(0)))
}
