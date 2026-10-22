package stage3

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import chisel3.internal.sourceinfo.UnlocatableSourceInfo
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import sifive.blocks.inclusivecache._

/** Production Scheduler/Directory/BankedStore/all sinks and sources, with the
  * production CacheCork. The host models clients and terminal memory only.
  * Monitors are disabled to inject stale/duplicate/early completion echoes.
  */
object EmitModule extends App {
  implicit val p: Parameters = (new chipyard.v1Config).alterPartial { case MonitorsEnabled => false }
  val block = TransferSizes(64, 64)
  val range = Seq(AddressSet(BigInt("80000000", 16), BigInt("0fffffff", 16)))
  val cp = CacheParameters(2, 2, 2, 64, 16, false)
  val mp = InclusiveCacheMicroParameters(8, memCycles = 8,
    innerBuf = InclusiveCachePortParameters.none)
  class Harness extends LazyModule {
    // The hand-built inner edge has no negotiated path. Mark only the BOOM-like
    // coherent origin, using the same endpoint contract as production BOOM.
    val imageOrigin = new TLIdentityNode() with CacheImageClient
    val client = TLClientNode(Seq(TLClientPortParameters(Seq(TLClientParameters(
      name = "stage3-l2", sourceId = IdRange(0, InclusiveCacheParameters.out_mshrs(cp, mp) + 1),
      supportsProbe = block)), echoFields = Seq(CachePreserveTxnField()))))
    val cork = LazyModule(new TLCacheCork)
    val memory = TLManagerNode(Seq(TLManagerPortParameters(Seq(TLManagerParameters(
      address = range, regionType = RegionType.UNCACHED,
      supportsGet = TransferSizes(1,64), supportsPutFull = TransferSizes(1,64),
      mayDenyGet = true, mayDenyPut = true)), beatBytes = 16)))
    memory := cork.node := client
    lazy val module = new LazyModuleImp(this) {
      override def desiredName = "Stage3Harness"
      // Match the host's traffic classes: source 0 is image-aware, source 3 is
      // an ordinary lineage-unaware coherent peer;
      // sources 1/2 issue uncached Get/Put, including two outstanding pressure
      // reads. Advertising these as probe clients incorrectly makes MSHR's
      // configuration exclude uncached miss -> TIP transitions (m = false).
      val inner = new TLEdgeIn(TLClientPortParameters(Seq(
        TLClientParameters(name = "stage3-upper0", sourceId = IdRange(0, 1),
          nodePath = Seq(imageOrigin), supportsProbe = block),
        TLClientParameters(name = "stage3-uncached", sourceId = IdRange(1, 3)),
        TLClientParameters(name = "stage3-unaware-peer", sourceId = IdRange(3, 4), supportsProbe = block)),
        requestFields = Seq(CacheImageField()), responseKeys = Seq(CacheImage)),
        TLManagerPortParameters(Seq(TLManagerParameters(address = range, regionType = RegionType.CACHED,
          supportsAcquireB = block, supportsAcquireT = block, supportsGet = TransferSizes(1,64),
          supportsPutFull = TransferSizes(1,64), supportsArithmetic = TransferSizes(1,8))),
          beatBytes = 16, endSinkId = InclusiveCacheParameters.all_mshrs(cp,mp),
          requestKeys = Seq(CacheImage), responseFields = Seq(CacheImageField())), p, UnlocatableSourceInfo)
      val params = InclusiveCacheParameters(cp, mp, true, inner, client.out.head._2)
      val s = Module(new Scheduler(params, trace = true))
      client.out.head._1 <> s.io.out
      // Match InclusiveCache.Impl's bank-address restoration exactly.
      client.out.head._1.a.bits.address := params.restoreAddress(s.io.out.a.bits.address)
      client.out.head._1.c.bits.address := params.restoreAddress(s.io.out.c.bits.address)
      val io = IO(new Bundle {
        val safe = Input(UInt(32.W))
        val av = Input(Bool()); val ar = Output(Bool()); val aa = Input(UInt(40.W))
        val ao = Input(UInt(3.W)); val ap = Input(UInt(3.W)); val al = Input(UInt(64.W)); val ah = Input(UInt(64.W))
        val asrc = Input(UInt(8.W)); val csrc = Input(UInt(8.W))
        val cv = Input(Bool()); val cr = Output(Bool()); val ca = Input(UInt(40.W))
        val co = Input(UInt(3.W)); val cp = Input(UInt(3.W)); val cl = Input(UInt(64.W)); val ch = Input(UInt(64.W))
        val ck = Input(new CacheImageKey)
        val dv = Output(Bool()); val dr = Input(Bool()); val dop = Output(UInt(3.W))
        val dl = Output(UInt(64.W)); val dh = Output(UInt(64.W)); val dk = Output(new CacheImageKey)
        val dsink = Output(UInt(8.W)); val dsrc = Output(UInt(8.W))
        val ev = Input(Bool()); val esink = Input(UInt(8.W))
        val bv = Output(Bool()); val ba = Output(UInt(40.W)); val bp = Output(UInt(3.W)); val br = Input(Bool())
        val bsrc = Output(UInt(8.W))
        val flush = Input(Bool()); val flushAddr = Input(UInt(40.W)); val flushReady = Output(Bool()); val flushed = Output(Bool())
        val mv = Output(Bool()); val mr = Input(Bool()); val ma = Output(UInt(40.W)); val mo = Output(UInt(3.W))
        val ms = Output(UInt(8.W)); val mt = Output(UInt(64.W)); val ml = Output(UInt(64.W)); val mh = Output(UInt(64.W))
        val rv = Input(Bool()); val rr = Output(Bool()); val ro = Input(UInt(3.W)); val rs = Input(UInt(8.W))
        val rt = Input(UInt(64.W)); val rl = Input(UInt(64.W)); val rh = Input(UInt(64.W))
        val pending = Output(Bool()); val pendingSet = Output(UInt(8.W)); val pendingWay = Output(UInt(8.W))
        val pendingKey = Output(new CacheImageKey); val counts = Output(Vec(6, UInt(64.W)))
        val txn = Output(UInt(64.W))
        val ack = Output(Bool())
        val blocked = Output(Bool()); val blockedSeq = Output(UInt(32.W)); val active = Output(Bool())
        val bankWrite = Output(Bool()); val metaWrite = Output(Bool())
        val drain = Output(new Stage3DrainStatus(params))
        val flushStatus = Output(new MSHRFlushStatus(params))
        val clientWaiting = Output(UInt(8.W))
        val clientValidationBlock = Output(Bool()); val clientValidationSeq = Output(UInt(32.W))
      })
      s.io.safeWatermark := io.safe; s.io.barrier_allow := true.B
      s.io.bank := 0.U
      s.io.ways := 0.U.asTypeOf(chiselTypeOf(s.io.ways)); s.io.divs := 0.U.asTypeOf(chiselTypeOf(s.io.divs))
      val t = s.io.in
      t.a.valid := io.av; t.a.bits := 0.U.asTypeOf(chiselTypeOf(t.a.bits)); io.ar := t.a.ready
      t.a.bits.opcode := io.ao; t.a.bits.param := io.ap; t.a.bits.size := 6.U
      t.a.bits.source := io.asrc
      t.a.bits.address := io.aa; t.a.bits.mask := Fill(16,1.U(1.W)); t.a.bits.data := Cat(io.ah,io.al)
      t.c.valid := io.cv; t.c.bits := 0.U.asTypeOf(chiselTypeOf(t.c.bits)); io.cr := t.c.ready
      t.c.bits.opcode := io.co; t.c.bits.param := io.cp; t.c.bits.size := 6.U
      t.c.bits.source := io.csrc
      t.c.bits.address := io.ca; t.c.bits.data := Cat(io.ch,io.cl); t.c.bits.user(CacheImage) := io.ck
      io.dv := t.d.valid; t.d.ready := io.dr; io.dop := t.d.bits.opcode
      io.dl := t.d.bits.data(63,0); io.dh := t.d.bits.data(127,64)
      io.dk := t.d.bits.user(CacheImage); io.dsink := t.d.bits.sink; io.dsrc := t.d.bits.source
      t.e.valid := io.ev; t.e.bits.sink := io.esink
      io.bv := t.b.valid; io.ba := params.restoreAddress(t.b.bits.address)
      io.bp := t.b.bits.param; t.b.ready := io.br
      io.bsrc := t.b.bits.source
      s.io.req.valid := io.flush; s.io.req.bits.address := io.flushAddr; io.flushReady := s.io.req.ready
      s.io.resp.ready := true.B; io.flushed := s.io.resp.valid
      val m = memory.in.head._1
      io.mv := m.a.valid; m.a.ready := io.mr; io.ma := m.a.bits.address; io.mo := m.a.bits.opcode
      io.ms := m.a.bits.source; io.mt := m.a.bits.echo(CachePreserveTxn)
      io.ml := m.a.bits.data(63,0); io.mh := m.a.bits.data(127,64)
      m.d.valid := io.rv; m.d.bits := 0.U.asTypeOf(chiselTypeOf(m.d.bits)); io.rr := m.d.ready
      m.d.bits.opcode := io.ro; m.d.bits.source := io.rs; m.d.bits.size := 6.U
      m.d.bits.echo(CachePreserveTxn) := io.rt; m.d.bits.data := Cat(io.rh,io.rl)
      m.b.valid := false.B; m.b.bits := 0.U.asTypeOf(chiselTypeOf(m.b.bits))
      m.c.ready := true.B; m.e.ready := true.B
      io.pending := s.io.preservationLock.valid; io.pendingSet := s.io.preservationLock.bits.set
      io.pendingWay := s.io.preservationLock.bits.way; io.pendingKey := s.io.preservationLock.bits.image
      io.counts := s.io.preservationCounters; io.txn := s.io.preservationTxn; io.ack := s.io.preservationAck
      io.blocked := s.io.validationBlock; io.blockedSeq := s.io.validationSeq
      io.active := s.io.active; io.bankWrite := s.io.bankWrite; io.metaWrite := s.io.metaWrite
      io.drain := s.io.drain
      io.flushStatus := s.io.flushStatus
      io.clientWaiting := s.io.clientWaiting
      io.clientValidationBlock := s.io.clientValidationBlock
      io.clientValidationSeq := s.io.clientValidationSeq
    }
  }
  (new ChiselStage).emitVerilog(LazyModule(new Harness).module, Array("--target-dir",args(0)))
  println("STAGE3_EMIT=PASS top=Stage3Harness")
}
