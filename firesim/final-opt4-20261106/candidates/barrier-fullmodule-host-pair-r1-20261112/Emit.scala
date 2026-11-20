package barrierpair

import chisel3._
import org.chipsalliance.cde.config.{Config, Parameters}

class ReferenceHarness(implicit p: Parameters)
  extends firesim.midasexamples.PeekPokeMidasExampleHarness(
    () => new barrierpairreference.GHBarrierLatencyStats(256))

class CandidateHarness(implicit p: Parameters)
  extends firesim.midasexamples.PeekPokeMidasExampleHarness(
    () => new barrierpaircandidate.GHBarrierLatencyStats(256))

class MCConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

object Emit extends App {
  val reference = args(0) == "Reference"
  val kind = args(1)
  val output = args(2)
  if (kind == "Proof") {
    (new chisel3.stage.ChiselStage).emitVerilog(
      if (reference) new barrierpairreference.GHBarrierLatencyStats(256) {
        override def desiredName = "BarrierReference"
      } else new barrierpaircandidate.GHBarrierLatencyStats(256) {
        override def desiredName = "BarrierCandidate"
      },
      Array("--target-dir", output, "--output-file", "Barrier"))
  } else {
    val top = if (reference) "barrierpair.ReferenceHarness" else "barrierpair.CandidateHarness"
    freechips.rocketchip.system.Generator.main(Array(
      "--target-dir", output, "--name", "Barrier", "--top-module", top,
      "--configs", "firesim.midasexamples.NoConfig"))
    // Save untransformed target Verilog for the exact source/ports manifest.
    (new chisel3.stage.ChiselStage).emitVerilog(
      if (reference) new barrierpairreference.GHBarrierLatencyStats(256)
      else new barrierpaircandidate.GHBarrierLatencyStats(256),
      Array("--target-dir", output, "--output-file", "TargetOnly"))
    java.nio.file.Files.copy(java.nio.file.Paths.get(output,"TargetOnly.v"),
      java.nio.file.Paths.get(output,"Barrier.v"))
  }
}
