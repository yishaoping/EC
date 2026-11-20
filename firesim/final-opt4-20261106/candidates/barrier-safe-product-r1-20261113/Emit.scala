package barrierbankexperiment

import chisel3._
import org.chipsalliance.cde.config.{Config, Parameters}

class Host16(implicit p: Parameters) extends CompleteHost(16)
class Host8(implicit p: Parameters) extends CompleteHost(8)

class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class ThreadedConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)

object Emit extends App {
  val lanes = args(1).toInt
  val dut = if (args(0) == "Reference") {
    () => new barrierbankreference.GHBarrierLatencyStats(256) {
      override def desiredName = "BarrierReference"
    }
  } else {
    () => new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256, lanes) {
      override def desiredName = "BarrierCandidate"
    }
  }
  (new chisel3.stage.ChiselStage).emitVerilog(dut(), Array("--target-dir", args(2), "--output-file", "Barrier"))
}
