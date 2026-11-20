package opt4fit
object EmitDiagnostic extends App {(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(0),"--full-stacktrace"))}
