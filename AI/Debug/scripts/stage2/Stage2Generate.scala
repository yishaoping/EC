package stage2

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import chisel3.stage.ChiselStage
import chisel3.internal.sourceinfo.UnlocatableSourceInfo
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tile.{TileKey, TileVisibilityNodeKey}
import freechips.rocketchip.subsystem.{TilesLocated, InSubsystem}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.rocket.constants.MemoryOpConstants
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
import boom.common.BoomTileAttachParams
import boom.lsu.BoomNonBlockingDCache
import sifive.blocks.inclusivecache._
import firrtl.{AnnotationSeq, CircuitState, Transform, DependencyAPIMigration}
import firrtl.options.{Dependency, TargetDirAnnotation}
import firrtl.passes.wiring.{SourceAnnotation, SinkAnnotation, WiringTransform}
import firrtl.stage.RunFirrtlTransformAnnotation

/** Report every malformed bore before WiringTransform's generic first error.
  * Observe only: never drop annotations, invent sources or change the circuit.
  */
// FIRRTL reconstructs ordinary transforms from their class, even when an
// instance is registered. Keep a public no-argument constructor; all per-run
// state must come from annotations, not constructor parameters or globals.
class Stage2WiringAudit extends Transform with DependencyAPIMigration {
  override def prerequisites = firrtl.stage.Forms.MidForm
  override def optionalPrerequisiteOf = Seq(Dependency[WiringTransform])
  override def invalidates(transform: Transform) = false
  override def execute(state: CircuitState): CircuitState = {
    val targetDir = state.annotations.toSeq.collectFirst {
      case TargetDirAnnotation(directory) => directory
    }.getOrElse(throw new IllegalArgumentException("Stage2 wiring audit requires TargetDirAnnotation"))
    val reportPath = new java.io.File(targetDir, "stage2.wiring.out")
    val sources = state.annotations.toSeq.collect { case a: SourceAnnotation => a }.groupBy(_.pin)
    val sinks = state.annotations.toSeq.collect { case a: SinkAnnotation => a }.groupBy(_.pin)
    val pins = (sources.keySet ++ sinks.keySet).toSeq.sorted
    val rows = pins.map { pin =>
      val src = sources.getOrElse(pin, Seq.empty)
      val dst = sinks.getOrElse(pin, Seq.empty)
      val bad = src.size != 1 || dst.isEmpty
      (bad, s"STAGE2_WIRING${if (bad) "_ERROR" else ""} pin=$pin sources=${src.size} sinks=${dst.size} " +
        s"source=${src.map(_.target.toString).mkString(";")} sink=${dst.map(_.target.toString).mkString(";")}")
    }
    val errors = rows.filter(_._1)
    val valid = pins.nonEmpty && errors.isEmpty
    val summary = s"STAGE2_WIRING=${if (valid) "PASS" else "FAIL"} pins=${pins.size} errors=${errors.size}"
    val report = new java.io.PrintWriter(reportPath)
    try { rows.foreach { case (_, row) => report.println(row) }; report.println(summary) }
    finally { report.close() }
    errors.foreach { case (_, row) => println(row) }
    println(summary)
    require(valid,
      s"Stage2 wiring audit: ${pins.size} pins, ${errors.size} malformed; see $reportPath")
    state
  }
}

/** Real L1 pipeline/MSHR/WB, SourceD, and L2 MSHR/SourceD regression. The C++ lower
  * agent controls data/ACK timing; it does not implement the preservation gate.
  * TL monitors are disabled here solely to inject an intentionally stale D key.
  */
object EmitModule extends App {
  // Exercise FIRRTL's actual reflective construction before elaborating the
  // large L1 fixture. This does not execute the transform or build hardware.
  val wiringAudit = Dependency[Stage2WiringAudit].getObject()
  val base = (new chipyard.v1Config).alterPartial { case MonitorsEnabled => false }
  val tile = base(TilesLocated(InSubsystem)).collectFirst {
    case t: BoomTileAttachParams => t.tileParams
  }.get
  val managers = TLManagerPortParameters(Seq(TLManagerParameters(
    address = Seq(AddressSet(BigInt("80000000", 16), BigInt("0fffffff", 16))),
    regionType = RegionType.CACHED,
    supportsAcquireB = TransferSizes(64, 64), supportsAcquireT = TransferSizes(64, 64),
    supportsGet = TransferSizes(1, 64), supportsPutFull = TransferSizes(1, 64),
    supportsPutPartial = TransferSizes(1, 64), supportsArithmetic = TransferSizes(1, 8))),
    beatBytes = 16, endSinkId = 1,
    requestKeys = Seq(CacheImage), responseFields = Seq(CacheImageField()))

  class Harness extends LazyModule()(base) {
    // Visibility node is needed for address/cacheability checks in the real L1.
    val visibility = TLIdentityNode()
    val params = base.alterPartial {
      case TileKey => tile
      case TileVisibilityNodeKey => visibility
    }
    val cache = LazyModule(new BoomNonBlockingDCache(tile.hartId)(params))
    val sink = TLManagerNode(Seq(managers))
    sink := visibility := cache.node
    lazy val module = new LazyModuleImp(this) with MemoryOpConstants {
      override def desiredName = "Stage2Harness"
      val io = IO(new Bundle {
        val req = Input(Bool()); val ready = Output(Bool())
        val addr = Input(UInt(40.W)); val data = Input(UInt(64.W))
        val cmd = Input(UInt(5.W)); val seq = Input(UInt(32.W)); val token = Input(UInt(64.W))
        val doneReady = Input(Bool()); val done = Output(Bool())
        val result = Output(UInt(64.W)); val doneToken = Output(UInt(64.W))
        val nack = Output(Bool()); val response = Output(Bool()); val responseData = Output(UInt(64.W))
        val ordered = Output(Bool()); val forceOrder = Input(Bool())
        val alloc = Input(UInt(32.W)); val pass = Input(UInt(32.W)); val safe = Output(UInt(32.W))
        val aReady = Input(Bool()); val aValid = Output(Bool()); val aAddr = Output(UInt(40.W))
        val aSource = Output(UInt(8.W)); val aParam = Output(UInt(3.W))
        val cReady = Input(Bool()); val cValid = Output(Bool()); val cAddr = Output(UInt(40.W))
        val cOpcode = Output(UInt(3.W)); val cParam = Output(UInt(3.W)); val cSource = Output(UInt(8.W))
        val cLo = Output(UInt(64.W)); val cHi = Output(UInt(64.W)); val cKey = Output(new CacheImageKey)
        val dValid = Input(Bool()); val dReady = Output(Bool()); val dOpcode = Input(UInt(3.W))
        val dParam = Input(UInt(3.W)); val dSource = Input(UInt(8.W))
        val dLo = Input(UInt(64.W)); val dHi = Input(UInt(64.W)); val dKey = Input(new CacheImageKey)
        val probe = Input(Bool()); val probeReady = Output(Bool())
        val probeAddr = Input(UInt(40.W)); val probeParam = Input(UInt(3.W))
        val sdClean = Input(Bool()); val sdRead = Input(Bool()); val sdGrant = Input(Bool())
        val sdReq = Input(Bool()); val sdReady = Output(Bool())
        val sdBankReady = Input(Bool()); val sdAckReady = Input(Bool()); val sdData = Input(UInt(64.W))
        val sdPop = Output(Bool()); val sdWrite = Output(Bool()); val sdBeat = Output(UInt(8.W))
        val sdWriteData = Output(UInt(64.W)); val sdWriteHi = Output(UInt(64.W))
        val sdAck = Output(Bool()); val sdOpcode = Output(UInt(3.W))
        val sdReturn = Output(UInt(64.W)); val sdReturnHi = Output(UInt(64.W)); val sdKey = Output(new CacheImageKey)
        val msAllocate = Input(Bool()); val msDirectory = Input(Bool()); val msGrant = Input(Bool())
        val msDeny = Input(Bool()); val msReady = Input(Bool()); val msOpcode = Input(UInt(3.W))
        val msOldKey = Input(new CacheImageKey)
        val msOldData = Input(UInt(64.W)); val msOperand = Input(UInt(64.W))
        val msActive = Output(Bool()); val msAcquire = Output(Bool()); val msAcquireParam = Output(UInt(3.W))
        val msDir = Output(Bool()); val msDirKey = Output(new CacheImageKey)
        val msDirSeq = Output(UInt(32.W)); val msDirTracked = Output(Bool())
        val msDirState = Output(UInt(2.W)); val msDirDirty = Output(Bool())
        val msWrite = Output(Bool()); val msWriteData = Output(UInt(64.W))
        val msReply = Output(Bool()); val msReplyDenied = Output(Bool()); val msReplyOpcode = Output(UInt(3.W))
        val msReplyData = Output(UInt(64.W)); val msReplyKey = Output(new CacheImageKey)
      })
      val dut = cache.module
      // The standalone fixture has neither InclusiveCache's stats consumers
      // nor TestHarness's exit probes. Consume all 33 real L1 source annotations;
      // otherwise source-only wiring fails before RTL emission. These wires
      // are observation-only and do not drive cache/gate/protocol inputs.
      def observeBore(name: String, bits: Int): Unit = {
        val value = WireDefault(0.U(bits.W))
        BoringUtils.addSink(value, name)
        dontTouch(value)
      }
      observeBore(GH_GlobalParams.GH_L2_STATS_RESET_BORE, 1)
      observeBore(GH_GlobalParams.GH_L2_STATS_ENABLE_BORE, 1)
      observeBore(GH_GlobalParams.GH_L2_BARRIER_FAILURE_BORE, 1)
      observeBore(GH_GlobalParams.GH_L2_BARRIER_FAILURE_SEQ_BORE, GH_GlobalParams.GH_PACKET_SEQ_BITS)
      observeBore(GH_GlobalParams.GH_L1_L2_SAFE_WATERMARK_GRAY_BORE, GH_GlobalParams.GH_PACKET_SEQ_BITS)
      for (i <- 0 until 28) { observeBore(s"stage1_cache_${tile.hartId}_$i", 64) }
      dut.io.traffic_check_state := false.B
      dut.io.traffic_reset := false.B; dut.io.traffic_start := false.B; dut.io.traffic_stop := false.B
      val cycle = RegInit(0.U(64.W)); cycle := cycle + 1.U; dut.io.csr_cycle := cycle
      dut.io.packet_alloc_valid := io.alloc =/= 0.U; dut.io.packet_alloc_seq := io.alloc
      dut.io.packet_seq_baseline := 0.U
      dut.io.checker_results := 0.U.asTypeOf(chiselTypeOf(dut.io.checker_results))
      dut.io.checker_results(0) := Cat(io.pass =/= 0.U, 0.U(2.W), io.pass)
      io.safe := dut.io.traffic_counter(GH_GlobalParams.GH_TRAFFIC_SAFE_PACKET_WATERMARK)(31,0)
      dut.io.lsu.req.valid := io.req; io.ready := dut.io.lsu.req.ready
      dut.io.lsu.req.bits := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.req.bits))
      val r = dut.io.lsu.req.bits(0)
      r.valid := true.B; r.bits.addr := io.addr; r.bits.data := io.data
      r.bits.uop.mem_cmd := io.cmd; r.bits.uop.mem_size := 3.U; r.bits.uop.mem_signed := true.B
      r.bits.uop.uses_stq := isWrite(io.cmd); r.bits.uop.uses_ldq := !isWrite(io.cmd)
      r.bits.packet_seq := io.seq
      r.bits.request_token_valid := true.B; r.bits.request_token := io.token
      r.bits.effect_token_valid := isWrite(io.cmd); r.bits.effect_token := io.token
      r.bits.write_domain_valid := isWrite(io.cmd); r.bits.write_domain_seq := io.seq
      dut.io.lsu.s1_kill := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.s1_kill))
      dut.io.lsu.brupdate.b1 := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.brupdate.b1))
      dut.io.lsu.brupdate.b2.elements.filterNot(_._1 == "target_offset").foreach { case (_, d) =>
        d := 0.U.asTypeOf(chiselTypeOf(d))
      }
      dut.io.lsu.brupdate.b2.target_offset := 0.S(21.W)
      dut.io.lsu.exception := false.B; dut.io.lsu.rob_pnr_idx := 0.U; dut.io.lsu.rob_head_idx := 0.U
      dut.io.lsu.force_order := io.forceOrder
      dut.io.lsu.release.ready := true.B; dut.io.lsu.store_done.ready := io.doneReady
      dut.io.lsu.traffic_lr_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_lr_complete))
      dut.io.lsu.traffic_sc_success_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_sc_success_complete))
      dut.io.lsu.traffic_sc_fail_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_sc_fail_complete))
      dut.io.lsu.traffic_amo_cache_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_amo_cache_complete))
      dut.io.lsu.traffic_amo_uncache_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_amo_uncache_complete))
      dut.io.lsu.traffic_arch_counter := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_arch_counter))
      dut.io.lsu.address_stats_event := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.address_stats_event))
      io.done := dut.io.lsu.store_done.fire
      io.result := dut.io.lsu.store_done.bits.data; io.doneToken := dut.io.lsu.store_done.bits.req.request_token
      io.nack := dut.io.lsu.nack(0).valid
      io.response := dut.io.lsu.resp(0).valid; io.responseData := dut.io.lsu.resp(0).bits.data
      io.ordered := dut.io.lsu.ordered
      val tl = sink.in.head._1
      require(tl.params.dataBits == 128 && tl.params.addressBits <= 40 && tl.params.sourceBits <= 8,
        "Stage2 C++ lower agent requires 16-byte beats and untruncated address/source ports")
      require(GH_GlobalParams.GH_PACKET_SEQ_BITS == 32 && dut.io.lsu.req.bits(0).bits.data.getWidth == 64,
        "Stage2 fixture requires the production 32-bit packet sequence and RV64 data")
      tl.a.ready := io.aReady; io.aValid := tl.a.valid; io.aAddr := tl.a.bits.address
      io.aSource := tl.a.bits.source; io.aParam := tl.a.bits.param
      tl.c.ready := io.cReady; io.cValid := tl.c.valid; io.cAddr := tl.c.bits.address
      io.cOpcode := tl.c.bits.opcode; io.cParam := tl.c.bits.param; io.cSource := tl.c.bits.source
      io.cLo := tl.c.bits.data(63,0); io.cHi := tl.c.bits.data(127,64)
      io.cKey := tl.c.bits.user(CacheImage)
      tl.d.valid := io.dValid; tl.d.bits := 0.U.asTypeOf(chiselTypeOf(tl.d.bits))
      tl.d.bits.opcode := io.dOpcode; tl.d.bits.param := io.dParam; tl.d.bits.source := io.dSource
      tl.d.bits.size := 6.U; tl.d.bits.data := Cat(io.dHi, io.dLo); tl.d.bits.user(CacheImage) := io.dKey
      io.dReady := tl.d.ready; tl.e.ready := true.B
      tl.b.valid := io.probe; tl.b.bits := 0.U.asTypeOf(chiselTypeOf(tl.b.bits))
      tl.b.bits.opcode := TLMessages.Probe; tl.b.bits.address := io.probeAddr
      tl.b.bits.param := io.probeParam; tl.b.bits.size := 6.U
      tl.b.bits.mask := Fill(16, 1.U(1.W)); io.probeReady := tl.b.ready

      // L2's outer edge must describe an UNCACHED terminal (e.g. a corked
      // memory), not the CACHED L1 manager: InclusiveCache requires lastLevel.
      // This parameter edge also explicitly permits the denied upgrade below.
      val outer = new TLEdgeOut(TLClientPortParameters(Seq(TLClientParameters(
        name = "stage2-l2", sourceId = IdRange(0, 8), supportsProbe = TransferSizes(64, 64)))),
        TLManagerPortParameters(Seq(TLManagerParameters(
          address = Seq(AddressSet(BigInt("80000000", 16), BigInt("0fffffff", 16))),
          regionType = RegionType.UNCACHED,
          supportsAcquireB = TransferSizes(64, 64), supportsAcquireT = TransferSizes(64, 64),
          supportsGet = TransferSizes(1, 64), supportsPutFull = TransferSizes(1, 64),
          mayDenyGet = true, mayDenyPut = true)), beatBytes = 16, endSinkId = 1),
        base, UnlocatableSourceInfo)
      val cp = InclusiveCacheParameters(
        CacheParameters(2, 4, 64, 64, 16, false),
        InclusiveCacheMicroParameters(8, innerBuf = InclusiveCachePortParameters.none),
        false, sink.edges.in.head, outer)(base)
      val sd = Module(new SourceD(cp))
      sd.io.req.valid := io.sdReq; io.sdReady := sd.io.req.ready
      sd.io.req.bits := 0.U.asTypeOf(chiselTypeOf(sd.io.req.bits))
      val sdA = io.sdRead || io.sdGrant
      sd.io.req.bits.prio(0) := sdA; sd.io.req.bits.prio(2) := !sdA
      sd.io.req.bits.opcode := Mux(io.sdGrant, TLMessages.AcquireBlock, Mux(io.sdRead, TLMessages.Get,
        Mux(io.sdClean, TLMessages.Release, TLMessages.ReleaseData)))
      sd.io.req.bits.param := Mux(io.sdGrant, TLPermissions.NtoT, Mux(io.sdRead, 0.U, TLPermissions.TtoN))
      sd.io.req.bits.size := Mux(io.sdRead, 4.U, 6.U) // Read both meaningful 64-bit halves.
      sd.io.req.bits.image.valid := true.B; sd.io.req.bits.image.generation := 123.U
      sd.io.req.bits.image.contentSeq := 1.U
      sd.io.req.bits.packetSeq := 1.U; sd.io.req.bits.packetTracked := true.B
      sd.io.pb_pop.ready := false.B; sd.io.pb_beat := 0.U.asTypeOf(chiselTypeOf(sd.io.pb_beat))
      sd.io.rel_pop.ready := true.B; sd.io.rel_beat := 0.U.asTypeOf(chiselTypeOf(sd.io.rel_beat))
      sd.io.rel_beat.data := Cat(~io.sdData, io.sdData)
      sd.io.bs_radr.ready := true.B; sd.io.bs_rdat := 0.U.asTypeOf(chiselTypeOf(sd.io.bs_rdat))
      sd.io.bs_rdat.data := Cat(~io.sdData, io.sdData)
      sd.io.bs_wadr.ready := io.sdBankReady
      sd.io.d.ready := io.sdAckReady
      sd.io.evict_req := 0.U.asTypeOf(chiselTypeOf(sd.io.evict_req))
      sd.io.grant_req := 0.U.asTypeOf(chiselTypeOf(sd.io.grant_req))
      io.sdPop := sd.io.rel_pop.fire; io.sdWrite := sd.io.bs_wadr.fire
      io.sdBeat := sd.io.bs_wadr.bits.beat
      io.sdWriteData := sd.io.bs_wdat.data(63,0); io.sdWriteHi := sd.io.bs_wdat.data(127,64)
      io.sdAck := sd.io.d.valid; io.sdOpcode := sd.io.d.bits.opcode
      io.sdReturn := sd.io.d.bits.data(63,0); io.sdReturnHi := sd.io.d.bits.data(127,64)
      io.sdKey := sd.io.d.bits.user(CacheImage)

      // Trusted A Put/AMO client, independent of L1's coherent request path.
      // Drive production allocate/directory/sinkd ports and consume actual
      // schedule handshakes. Never recreate final_meta_writeback in the fixture.
      val trustedInner = new TLEdgeIn(TLClientPortParameters(Seq(TLClientParameters(
        name = "stage2-trusted-a", sourceId = IdRange(0, 1))),
        requestFields = Seq(CacheImageField()), responseKeys = Seq(CacheImage)),
        managers, base, UnlocatableSourceInfo)
      val mcp = InclusiveCacheParameters(cp.cache, cp.micro, false, trustedInner, outer)(base)
      val ms = Module(new MSHR(mcp))
      ms.io.bank := 0.U
      ms.io.preserved := 0.U.asTypeOf(chiselTypeOf(ms.io.preserved))
      ms.io.releaseSent := 0.U.asTypeOf(chiselTypeOf(ms.io.releaseSent))
      val md = Module(new SourceD(mcp))
      ms.io.allocate.valid := io.msAllocate
      ms.io.allocate.bits := 0.U.asTypeOf(chiselTypeOf(ms.io.allocate.bits))
      ms.io.allocate.bits.prio(0) := true.B
      ms.io.allocate.bits.opcode := io.msOpcode
      ms.io.allocate.bits.param := Mux(io.msOpcode === TLMessages.ArithmeticData, TLAtomics.ADD, 0.U)
      ms.io.allocate.bits.size := 3.U // one low 64-bit lane, including AMO.D
      ms.io.allocate.bits.tag := 0x35.U; ms.io.allocate.bits.set := 1.U
      ms.io.directory.valid := io.msDirectory
      ms.io.directory.bits := 0.U.asTypeOf(chiselTypeOf(ms.io.directory.bits))
      ms.io.directory.bits.hit := true.B
      ms.io.directory.bits.tag := 0x35.U; ms.io.directory.bits.way := 2.U
      ms.io.directory.bits.state := MetaData.BRANCH // clean resident, upgrade needed
      ms.io.directory.bits.dcache := true.B
      ms.io.directory.bits.image := io.msOldKey
      ms.io.directory.bits.packetSeq := io.msOldKey.contentSeq
      ms.io.directory.bits.packetTracked := true.B
      ms.io.sinkc := 0.U.asTypeOf(chiselTypeOf(ms.io.sinkc))
      ms.io.sinke := 0.U.asTypeOf(chiselTypeOf(ms.io.sinke))
      ms.io.nestedwb := 0.U.asTypeOf(chiselTypeOf(ms.io.nestedwb))
      ms.io.sinkd := 0.U.asTypeOf(chiselTypeOf(ms.io.sinkd))
      ms.io.sinkd.valid := io.msGrant
      ms.io.sinkd.bits.opcode := TLMessages.Grant
      ms.io.sinkd.bits.param := TLPermissions.toT
      ms.io.sinkd.bits.last := true.B
      ms.io.sinkd.bits.denied := io.msDeny
      ms.io.schedule.ready := io.msReady && (!ms.io.schedule.bits.d.valid || md.io.req.ready)
      md.io.req.valid := ms.io.schedule.valid && io.msReady && ms.io.schedule.bits.d.valid
      md.io.req.bits := ms.io.schedule.bits.d.bits
      md.io.pb_pop.ready := true.B
      md.io.pb_beat := 0.U.asTypeOf(chiselTypeOf(md.io.pb_beat))
      md.io.pb_beat.mask := 0xff.U; md.io.pb_beat.data := io.msOperand
      md.io.rel_pop.ready := false.B
      md.io.rel_beat := 0.U.asTypeOf(chiselTypeOf(md.io.rel_beat))
      md.io.bs_radr.ready := true.B
      md.io.bs_rdat := 0.U.asTypeOf(chiselTypeOf(md.io.bs_rdat))
      md.io.bs_rdat.data := io.msOldData
      md.io.bs_wadr.ready := true.B; md.io.d.ready := true.B
      md.io.evict_req := 0.U.asTypeOf(chiselTypeOf(md.io.evict_req))
      md.io.grant_req := 0.U.asTypeOf(chiselTypeOf(md.io.grant_req))
      io.msActive := ms.io.status.valid
      io.msAcquire := ms.io.schedule.fire && ms.io.schedule.bits.a.valid
      io.msAcquireParam := ms.io.schedule.bits.a.bits.param
      io.msDir := ms.io.schedule.fire && ms.io.schedule.bits.dir.valid
      io.msDirKey := ms.io.schedule.bits.dir.bits.data.image
      io.msDirSeq := ms.io.schedule.bits.dir.bits.data.packetSeq
      io.msDirTracked := ms.io.schedule.bits.dir.bits.data.packetTracked
      io.msDirState := ms.io.schedule.bits.dir.bits.data.state
      io.msDirDirty := ms.io.schedule.bits.dir.bits.data.dirty
      io.msWrite := md.io.bs_wadr.fire; io.msWriteData := md.io.bs_wdat.data(63,0)
      io.msReply := md.io.d.fire; io.msReplyDenied := md.io.d.bits.denied
      io.msReplyOpcode := md.io.d.bits.opcode; io.msReplyData := md.io.d.bits.data(63,0)
      io.msReplyKey := md.io.d.bits.user(CacheImage)
    }
  }
  (new ChiselStage).emitVerilog(LazyModule(new Harness).module, Array("--target-dir", args(0)),
    AnnotationSeq(Seq(RunFirrtlTransformAnnotation(wiringAudit))))
  println("STAGE2_EMIT=PASS top=Stage2Harness")
}
