package opt4fulladdress
import chisel3._
import org.chipsalliance.cde.config.Parameters

class PlainHarness(implicit p:Parameters) extends firesim.midasexamples.PeekPokeMidasExampleHarness(
 () => new opt4addressplain.PackageAddressStats(3,40,64,256))
class MemHarness(implicit p:Parameters) extends firesim.midasexamples.PeekPokeMidasExampleHarness(
 () => new opt4addressmcrams.PackageAddressStats(3,40,64,256))
object EmitAddress extends App {
 val stage=new chisel3.stage.ChiselStage
 implicit val p:Parameters=Parameters.empty
 args(0) match {
  case "Plain" => stage.emitChirrtl(new PlainHarness,Array("--target-dir",args(1)))
  case "MemMC" => stage.emitChirrtl(new MemHarness,Array("--target-dir",args(1)))
 }
}
