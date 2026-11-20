package opt4packedfull
import chisel3._

object Emit extends App {
  val reference = args(0) == "Reference"
  val top = if (args(1) == "Module") "FPGATop" else "Packed" + args(1) + args(0)
  val stage = new chisel3.stage.ChiselStage
  if (reference) stage.emitVerilog(new opt4packedref.PackageAddressStats(3,40,64,256) {
    override def desiredName = top
  }, Array("--target-dir", args(2)))
  else stage.emitVerilog(new opt4packedcandidate.PackageAddressStats(3,40,64,256) {
    override def desiredName = top
  }, Array("--target-dir", args(2)))
}
