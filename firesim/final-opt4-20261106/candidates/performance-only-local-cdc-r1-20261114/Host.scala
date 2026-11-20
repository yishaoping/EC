package localcdcprobe

import chisel3._
import midas.widgets.{PeekPokeBridge, RationalClock, RationalClockBridge}
import org.chipsalliance.cde.config.{Config, Parameters}

class QueueHostIO extends Bundle {
  val enqReset = Input(Bool())
  val deqReset = Input(Bool())
  val enqValid = Input(Bool())
  val enqBits = Input(UInt(305.W))
  val deqReady = Input(Bool())
  val readyFlat = Output(Bool())
  val readyLocal = Output(Bool())
  val validFlat = Output(Bool())
  val validLocal = Output(Bool())
  val bitsFlat = Output(UInt(305.W))
  val bitsLocal = Output(UInt(305.W))
}

class QueuePairHost(implicit p: Parameters) extends RawModule {
  val clocks = RationalClockBridge(RationalClock("Checker", 1, 2)).io.clocks
  val reset = WireInit(false.B)
  val io = Wire(new QueueHostIO)
  val pair = withClockAndReset(clocks.head, reset) { Module(new QueuePair) }
  pair.io.enqClock := clocks(0)
  pair.io.deqClock := clocks(1)
  pair.io.enqReset := reset || io.enqReset
  pair.io.deqReset := reset || io.deqReset
  pair.io.enqValid := io.enqValid
  pair.io.enqBits := io.enqBits
  pair.io.deqReady := io.deqReady
  io.readyFlat := pair.io.readyFlat
  io.readyLocal := pair.io.readyLocal
  io.validFlat := pair.io.validFlat
  io.validLocal := pair.io.validLocal
  io.bitsFlat := pair.io.bitsFlat
  io.bitsLocal := pair.io.bitsLocal
  PeekPokeBridge(clocks.head, reset, "io" -> io)
}

class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

object EmitHost {
  def main(args: Array[String]): Unit = {
    implicit val p: Parameters = new PlainConfig
    (new chisel3.stage.ChiselStage).emitVerilog(new QueuePairHost, Array("--target-dir", args(0)))
  }
}
