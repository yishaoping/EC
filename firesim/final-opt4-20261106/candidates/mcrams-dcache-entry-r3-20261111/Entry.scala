package opt4entry
import chisel3._
import chisel3.experimental.annotate
import midas.targetutils.MemModelAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}
// Isolated storage-interface prototype. No original EC target source is changed.
// Dimensions and raw async memory semantics are checked against 3656aec4 FIRRTL.
class EntryDUT extends Module {
  val io = IO(new Bundle {
    val address = Input(Vec(35, UInt(9.W)))
    val data = Output(Vec(35, UInt(81.W)))
    val captured = Output(Vec(35, UInt(81.W)))
    val writeAddress = Input(UInt(9.W))
    val writeData = Input(UInt(81.W))
    val writeEnable = Input(Bool())
  })
  val ownerImageMemory = Mem(512, UInt(81.W))
  annotate(MemModelAnnotation(ownerImageMemory))
  val ownerWritten = RegInit(VecInit(Seq.fill(512)(false.B)))
  for (i <- 0 until 35) {
    val before = Mux(ownerWritten(io.address(i)), ownerImageMemory.read(io.address(i)), 0.U(81.W))
    io.data(i) := before
    // Observation-only edge capture checks read-old-before-write semantics.
    io.captured(i) := RegNext(before, 0.U)
  }
  when(io.writeEnable && !reset.asBool) {
    ownerImageMemory.write(io.writeAddress, io.writeData)
    ownerWritten(io.writeAddress) := true.B
  }
}
class Entry(implicit p: Parameters) extends firesim.midasexamples.PeekPokeMidasExampleHarness(() => new EntryDUT)
class PlainConfig extends Config(new Config((site,here,up)=> {
  case midas.GenerateMultiCycleRamModels => false
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class MCConfig extends Config(new Config((site,here,up)=> {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
