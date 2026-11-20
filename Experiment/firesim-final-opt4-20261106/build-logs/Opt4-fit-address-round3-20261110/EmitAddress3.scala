package opt4fit
object EmitAddress3 extends App {(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(0)))}
