package opt4retirestatic
object Emit extends App {
 require(args(0)=="address")
 (new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
}
