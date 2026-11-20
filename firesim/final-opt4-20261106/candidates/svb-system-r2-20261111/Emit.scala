package opt4svbtree
import chisel3._
import chisel3.util._
import boom.lsu.NewestSafeEntry

class SelectionProbe(val only: Int = 0) extends RawModule {
  override def desiredName = if (only == 1) "ReferenceSelection" else if (only == 2) "CandidateSelection" else "SelectionProbe"
  val io = IO(new Bundle {
    val valid = Input(Vec(32, Bool()))
    val seq = Input(Vec(32, UInt(32.W)))
    val generation = Input(Vec(32, UInt(32.W)))
    val chosenValid = Output(Bool())
    val chosenIdx = Output(UInt(5.W))
    val equivalent = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val entrySafe = io.valid
  class Key extends Bundle { val contentSeq = UInt(32.W); val generation = UInt(32.W) }
  val key = Wire(Vec(32, new Key))
  for (i <- 0 until 32) { key(i).contentSeq := io.seq(i); key(i).generation := io.generation(i) }
  val entries = 32
  val chooseValid = WireDefault(false.B)
  val chooseIdx = WireDefault(0.U(log2Ceil(entries).W))
  for (i <- 0 until entries) {
    val noNewer = (0 until entries).filter(_ != i).map(j =>
      !(entrySafe(j) && (key(j).contentSeq > key(i).contentSeq ||
        (key(j).contentSeq === key(i).contentSeq &&
          (key(j).generation > key(i).generation ||
           (key(j).generation === key(i).generation && (j > i).B)))))).reduce(_ && _)
    when (entrySafe(i) && noNewer) {
      chooseValid := true.B
      chooseIdx := i.U
    }
  }
  val candidate = NewestSafeEntry(io.valid.toSeq, io.seq.toSeq, io.generation.toSeq)
  io.chosenValid := (if (only == 1) chooseValid else candidate._1)
  io.chosenIdx := (if (only == 1) chooseIdx else candidate._2)
  io.equivalent := (if (only == 0) chooseValid === candidate._1 && chooseIdx === candidate._2 else true.B)
  io.mutantEquivalent := (if (only == 0) chooseValid === candidate._1 && chooseIdx === (candidate._2 ^ 1.U) else true.B)
}

object Emit extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new SelectionProbe, Array("--target-dir", args(1)))
    case "reference" => stage.emitVerilog(new SelectionProbe(1), Array("--target-dir", args(1)))
    case "candidate" => stage.emitVerilog(new SelectionProbe(2), Array("--target-dir", args(1)))
    case "svb" =>
      import freechips.rocketchip.config.Parameters
      import freechips.rocketchip.tile._
      import freechips.rocketchip.subsystem._
      import freechips.rocketchip.diplomacy._
      import freechips.rocketchip.tilelink._
      val base = new firesim.firesim.DacOpt4C4().toInstance
      val tile = base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId == 0).get
      implicit val p: Parameters = base.alterPartial { case TileKey => tile; case MaxHartIdBits => 3 }
      val client = TLMasterPortParameters.v1(Seq(TLMasterParameters.v1("svb-module-proof", supportsProbe=TransferSizes(64,64))))
      val manager = TLSlavePortParameters.v1(Seq(TLSlaveParameters.v1(address=Seq(AddressSet(0, (BigInt(1)<<35)-1)), regionType=RegionType.CACHED, supportsAcquireT=TransferSizes(64,64), supportsAcquireB=TransferSizes(64,64), supportsGet=TransferSizes(1,64), supportsPutFull=TransferSizes(1,64))), beatBytes=tile.dcache.get.rowBits / 8, endSinkId=1)
      val wrapper = LazyModule(new LazyModule()(p) {
        val clientNode = TLClientNode(Seq(client))
        val visibilityNode = TLEphemeralNode()
        val managerNode = TLManagerNode(Seq(manager))
        managerNode := visibilityNode := clientNode
        lazy val module = new LazyModuleImp(this) {
          override def desiredName = "SVBModuleHarness"
          val tileP = p.alterPartial { case TileVisibilityNodeKey => visibilityNode }
          val dut = Module(new boom.lsu.SpeculativeVersionBuffer(32)(clientNode.edges.out.head, tileP))
          val io = IO(chiselTypeOf(dut.io))
          io <> dut.io
        }
      })
      stage.emitVerilog(wrapper.module, Array("--target-dir", args(1)))
  }
}
