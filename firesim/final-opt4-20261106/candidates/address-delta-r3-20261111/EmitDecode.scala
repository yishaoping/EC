package opt4decode
import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketAccess

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
    val invalidMuxEquivalent = Output(Bool())
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
  io.invalidMuxEquivalent :=
    (!selectedValid && selected =/= 0.U) ||
      (selected +& io.delta === old +& io.delta)
}

class BucketInvariantStepProof extends RawModule {
  val io = IO(new Bundle {
    val valid = Input(Bool())
    val counter = Input(UInt(64.W))
    val delta = Input(UInt(64.W))
    val reset = Input(Bool())
    val retire = Input(Bool())
    val current = Input(Bool())
    val nonCurrentUpdate = Input(Bool())
    val stepOk = Output(Bool())
  })
  val stateInvariant = io.valid || io.counter === 0.U
  val updateGuard = io.valid || !io.nonCurrentUpdate || !io.delta.orR
  val nextValid = !io.reset && !io.retire && (io.valid || io.current)
  val nextCounter = Wire(UInt(64.W))
  when (io.reset || io.retire) {
    nextCounter := 0.U
  }.elsewhen (io.current || (io.nonCurrentUpdate && io.delta.orR)) {
    nextCounter := io.counter + io.delta
  }.otherwise {
    nextCounter := io.counter
  }
  io.stepOk := !stateInvariant || !updateGuard || nextValid || nextCounter === 0.U
}

class QualifiedDeltaProof extends RawModule {
  val io = IO(new Bundle {
    val packetSeq = Input(UInt(64.W))
    val bucketSeq = Input(Vec(256, UInt(64.W)))
    val bucketValid = Input(UInt(256.W))
    val hit = Input(Bool())
    val count = Input(UInt(64.W))
    val legalDeltaImpliesValid = Output(Bool())
  })
  val idx = io.packetSeq(7, 0)
  val matches = io.bucketValid(idx) && io.bucketSeq(idx) === io.packetSeq
  val delta = Mux(io.hit, io.count, 0.U(64.W))
  val commit = !(io.hit && !matches)
  io.legalDeltaImpliesValid := !(commit && delta.orR) || io.bucketValid(idx)
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
object EmitDecode extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new AccessProof,Array("--target-dir",args(1)))
    case "invariant" => stage.emitVerilog(new BucketInvariantStepProof,Array("--target-dir",args(1)))
    case "qualified" => stage.emitVerilog(new QualifiedDeltaProof,Array("--target-dir",args(1)))
    case "read-old" => stage.emitVerilog(new ReadProbe(true),Array("--target-dir",args(1)))
    case "read-new" => stage.emitVerilog(new ReadProbe(false),Array("--target-dir",args(1)))
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
  }
}
