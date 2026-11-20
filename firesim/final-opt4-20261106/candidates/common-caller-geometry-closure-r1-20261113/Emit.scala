package geometrycomplete
import chisel3._
object Emit extends App {
  val lanes=args(0).toInt
  val mode=args(1)
  val dut: () => RawModule = if(mode=="Proof")
    () => new geometrycompletecandidate.PackageAddressStats(3,40,64,256,bankLanes=lanes) {
      override def desiredName = "BankedProofCandidate"
    }
  else () => new boom.lsu.PackageAddressStats(3,40,64,256,bankLanes=lanes) {
    override def desiredName = "BankedModuleCandidate"
  }
  (new chisel3.stage.ChiselStage).emitVerilog(dut(),Array("--target-dir",args(2)))
}
