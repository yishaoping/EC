package opt4packedpair
import chisel3._
class PackedAddressPair extends Module {
  val a = Module(new opt4packedreference.PackageAddressStats(3,40,64,256))
  val b = Module(new opt4packedcandidate.PackageAddressStats(3,40,64,256))
  val io = IO(new Bundle {
    val reference = chiselTypeOf(a.io)
    val candidate = chiselTypeOf(b.io)
  })
  io.reference <> a.io
  io.candidate <> b.io
}
object EmitPair extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new PackedAddressPair,
    Array("--target-dir", args(0)))
}
