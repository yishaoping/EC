package opt4spacetime

import chisel3._
import chisel3.experimental.annotate
import midas.models.sram.{AsyncMemChiselModel, AsyncMemChiselRTL, RegfileModelIO, RegfileRTLIO}
import midas.targetutils.MemModelAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}

// Host-only experiment. No original EC source or target configuration changes.
class SpaceTimePair(depth: Int, width: Int, reads: Int, writes: Int) extends Module {
  val io = IO(new Bundle {
    val targetClock = Input(Clock())
    val targetReset = Input(Bool())
    val model = new RegfileModelIO(depth, width, reads, writes)
    val reference = new RegfileRTLIO(depth, width, reads, writes)
  })
  val host = Module(new AsyncMemChiselModel(depth, width, reads, writes))
  val target = withClockAndReset(io.targetClock, io.targetReset) {
    Module(new AsyncMemChiselRTL(depth, width, reads, writes))
  }
  host.channels <> io.model
  target.channels <> io.reference
}

class ProbeDUT extends Module {
  val io = IO(new Bundle {
    val address = Input(Vec(35, UInt(9.W)))
    val data = Output(Vec(35, UInt(81.W)))
    val writeAddress = Input(UInt(9.W))
    val writeData = Input(UInt(81.W))
    val writeEnable = Input(Bool())
  })
  val image = Mem(512, UInt(81.W))
  annotate(MemModelAnnotation(image))
  for (i <- 0 until 35) io.data(i) := image(io.address(i))
  when(io.writeEnable && !reset.asBool) { image(io.writeAddress) := io.writeData }
}

class Probe(implicit p: Parameters)
  extends firesim.midasexamples.PeekPokeMidasExampleHarness(() => new ProbeDUT)

class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => false
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

class MCConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

object EmitPair {
  def main(args: Array[String]): Unit = {
    val root = args(0); val reads = args(1).toInt; val writes = args(2).toInt; val width = args(3).toInt
    (new chisel3.stage.ChiselStage).emitVerilog(new SpaceTimePair(512, width, reads, writes), Array("--target-dir", root + "/pair"))
    (new chisel3.stage.ChiselStage).emitVerilog(new AsyncMemChiselRTL(512, width, reads, writes), Array("--target-dir", root + "/reference"))
    (new chisel3.stage.ChiselStage).emitVerilog(new AsyncMemChiselModel(512, width, reads, writes), Array("--target-dir", root + "/model"))
  }
}
