package opt4bankedfull
import chisel3._

object Emit extends App {
  val top = "Banked" + args(1) + args(0)
  val stage = new chisel3.stage.ChiselStage
  if (args(0) == "Reference") stage.emitVerilog(
    new opt4bankedref.PackageAddressStats(3,40,64,256) {
      override def desiredName = top
    }, Array("--target-dir", args(2)))
  else stage.emitVerilog(new opt4bankedcandidate.PackageAddressStats(3,40,64,256) {
    override def desiredName = top
  }, Array("--target-dir", args(2)))
}
