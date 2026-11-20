package opt4bucket

import chisel3._
import chisel3.experimental.annotate
import midas.targetutils.MemModelAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}

/** An isolated exact state-interface prototype for one address-statistics
  * 256x64 RegVec bank. Arithmetic is deliberately outside this interface:
  * processData is the original full-width per-word arithmetic result.
  * All256 observations remain; no payload/validity masking is introduced.
  */
class BucketIO extends Bundle {
  val process = Input(Bool())
  val enables = Input(Vec(256, Bool()))
  val processData = Input(Vec(256, UInt(64.W)))
  val retire = Input(Bool())
  val retireIndex = Input(UInt(8.W))
  val resetStats = Input(Bool())
  val currentIndex = Input(UInt(8.W))
  val debug = Output(Vec(256, UInt(64.W)))
  val current = Output(UInt(64.W))
  val retiring = Output(UInt(64.W))
}

class RegBucket extends Module {
  val io = IO(new BucketIO)
  val bank = Reg(Vec(256, UInt(64.W)))
  when(io.process) {
    for(i <- 0 until 256) when(io.enables(i)) { bank(i) := io.processData(i) }
  }
  when(io.retire) { bank(io.retireIndex) := 0.U }
  when(io.resetStats) { for(i <- 0 until 256) bank(i) := 0.U }
  io.debug := bank
  io.current := bank(io.currentIndex)
  io.retiring := bank(io.retireIndex)
}

class MemBucket extends Module {
  val io = IO(new BucketIO)
  val bank = Mem(256, UInt(64.W))
  annotate(MemModelAnnotation(bank))
  for(i <- 0 until 256) {
    // Exactly one writer owns each constant word. The original process ->
    // retirement -> resetStats priority is resolved before host serialization.
    val clear = io.resetStats || (io.retire && io.retireIndex === i.U)
    when(clear || (io.process && io.enables(i))) {
      bank.write(i.U, Mux(clear, 0.U(64.W), io.processData(i)))
    }
    io.debug(i) := bank.read(i.U)
  }
  io.current := bank.read(io.currentIndex)
  io.retiring := bank.read(io.retireIndex)
}

class RegHarness(implicit p: Parameters)
 extends firesim.midasexamples.PeekPokeMidasExampleHarness(() => new RegBucket)
class MemHarness(implicit p: Parameters)
 extends firesim.midasexamples.PeekPokeMidasExampleHarness(() => new MemBucket)
class PlainConfig extends Config(new Config((site,here,up)=> {
  case midas.GenerateMultiCycleRamModels => false
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class MCConfig extends Config(new Config((site,here,up)=> {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
