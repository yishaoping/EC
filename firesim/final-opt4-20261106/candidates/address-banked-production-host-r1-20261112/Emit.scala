package opt4bankedproduction

import chisel3._
import org.chipsalliance.cde.config.{Config, Parameters}

object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(
    new PackageAddressStats(3, 40, 64, 256) {
      override def desiredName = "Production" + args(0) + "Candidate"
    }, Array("--target-dir", args(1)))
}

class CompleteHost(implicit p: Parameters) extends RawModule {
  val clock = midas.widgets.RationalClockBridge().io.clocks.head
  val reset = WireInit(false.B)
  withClockAndReset(clock, reset) {
    val dut = Module(new PackageAddressStats(3, 40, 64, 256))
    val io = Wire(chiselTypeOf(dut.io))
    io <> dut.io
    midas.widgets.PeekPokeBridge(clock, reset, "io" -> io)
  }
}

class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

class ThreadedConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)
