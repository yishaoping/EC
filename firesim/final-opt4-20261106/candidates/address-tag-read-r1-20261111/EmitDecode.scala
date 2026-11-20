package opt4decode
import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketAccess
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/** Proof cut is an arbitrary full-size bank, not a reachable-state assumption. */
class AccessProof extends RawModule {
  val io = IO(new Bundle {
    val index = Input(UInt(8.W))
    val words = Input(Vec(256, UInt(64.W)))
    val valid = Input(UInt(256.W))
    val delta = Input(UInt(64.W))
    val clear = Input(Bool())
    val reset = Input(Bool())
    val selected = Output(UInt(64.W))
    val sum = Output(UInt(65.W))
    val cleared = Output(UInt(256.W))
    val readOk = Output(Bool())
    val arithmeticOk = Output(Bool())
    val clearOk = Output(Bool())
  })
  val selects = AddressBucketAccess.decode(io.index, 256)
  val selected = AddressBucketAccess.select(selects, io.words.toSeq)
  val selectedValid = AddressBucketAccess.select(selects, (0 until 256).map(i => io.valid(i).asUInt)).asBool
  val old = Mux(selectedValid, selected, 0.U(64.W))
  val next = old +& io.delta
  val cleared = VecInit((0 until 256).map(i => !io.reset && io.valid(i) && !(io.clear && selects(i)))).asUInt
  val reference = Wire(Vec(256, Bool()))
  for (i <- 0 until 256) reference(i) := io.valid(i)
  when (io.clear) { reference(io.index) := false.B }
  when (io.reset) { reference := VecInit(Seq.fill(256)(false.B)) }
  val referenceOld = Mux(io.valid(io.index), io.words(io.index), 0.U(64.W))
  io.selected := selected
  io.sum := next
  io.cleared := cleared
  io.readOk := selected === io.words(io.index) && selectedValid === io.valid(io.index)
  io.arithmeticOk := next(63,0) === (referenceOld + io.delta) &&
    next(64) === (io.delta.orR && referenceOld > (~0.U(64.W) - io.delta))
  io.clearOk := cleared === reference.asUInt
}

/** Identical external bank ports for measuring read topology only. */
class ReadProbe(reference: Boolean) extends RawModule {
  val io = IO(new Bundle {
    val index = Input(UInt(8.W))
    val words = Input(Vec(256, UInt(64.W)))
    val result = Output(UInt(64.W))
  })
  io.result := (if (reference) io.words(io.index) else
    AddressBucketAccess.select(AddressBucketAccess.decode(io.index,256), io.words.toSeq))
}
class CombinedTagReadProof extends RawModule {
  val io = IO(new Bundle {
    val index = Input(UInt(8.W))
    val valid = Input(UInt(256.W))
    val sequence = Input(Vec(256, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val combined = Output(UInt((GH_GlobalParams.GH_PACKET_SEQ_BITS + 1).W))
    val reference = Output(UInt((GH_GlobalParams.GH_PACKET_SEQ_BITS + 1).W))
    val equivalent = Output(Bool())
  })
  val tags = VecInit((0 until 256).map(i => Cat(io.valid(i), io.sequence(i))))
  io.combined := tags(io.index)
  io.reference := Cat(io.valid(io.index), io.sequence(io.index))
  io.equivalent := io.combined === io.reference
}
object EmitDecode extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new AccessProof,Array("--target-dir",args(1)))
    case "read-old" => stage.emitVerilog(new ReadProbe(true),Array("--target-dir",args(1)))
    case "read-new" => stage.emitVerilog(new ReadProbe(false),Array("--target-dir",args(1)))
    case "tag-read" => stage.emitVerilog(new CombinedTagReadProof,Array("--target-dir",args(1)))
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
  }
}
