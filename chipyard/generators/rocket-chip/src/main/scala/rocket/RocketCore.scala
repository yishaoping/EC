// See LICENSE.Berkeley for license details.
// See LICENSE.SiFive for license details.

package freechips.rocketchip.rocket

import chisel3._
import chisel3.util._
import chisel3.withClock
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.tile._
import freechips.rocketchip.util._
import freechips.rocketchip.util.property
import freechips.rocketchip.scie._
import scala.collection.mutable.ArrayBuffer
//===== GuardianCouncil Function: Start ====//
import freechips.rocketchip.r._
import freechips.rocketchip.guardiancouncil._
//===== GuardianCouncil Function: End   ====//
case class RocketCoreParams(
  bootFreqHz: BigInt = 0,
  useVM: Boolean = true,
  useUser: Boolean = false,
  useSupervisor: Boolean = false,
  useHypervisor: Boolean = false,
  useDebug: Boolean = true,
  useAtomics: Boolean = true,
  useAtomicsOnlyForIO: Boolean = false,
  useCompressed: Boolean = true,
  useRVE: Boolean = false,
  useSCIE: Boolean = false,
  useBitManip: Boolean = false,
  useBitManipCrypto: Boolean = false,
  useCryptoNIST: Boolean = false,
  useCryptoSM: Boolean = false,
  nLocalInterrupts: Int = 0,
  useNMI: Boolean = false,
  nBreakpoints: Int = 1,
  useBPWatch: Boolean = false,
  mcontextWidth: Int = 0,
  scontextWidth: Int = 0,
  nPMPs: Int = 8,
  nPerfCounters: Int = 0,
  haveBasicCounters: Boolean = true,
  haveCFlush: Boolean = false,
  misaWritable: Boolean = true,
  nL2TLBEntries: Int = 0,
  nL2TLBWays: Int = 1,
  nPTECacheEntries: Int = 8,
  mtvecInit: Option[BigInt] = Some(BigInt(0)),
  mtvecWritable: Boolean = true,
  fastLoadWord: Boolean = true,
  fastLoadByte: Boolean = false,
  branchPredictionModeCSR: Boolean = false,
  clockGate: Boolean = false,
  mvendorid: Int = 0, // 0 means non-commercial implementation
  mimpid: Int = 0x20181004, // release date in BCD
  mulDiv: Option[MulDivParams] = Some(MulDivParams()),
  fpu: Option[FPUParams] = Some(FPUParams())
) extends CoreParams {
  val lgPauseCycles = 5
  val haveFSDirty = false
  val pmpGranularity: Int = if (useHypervisor) 4096 else 4
  val fetchWidth: Int = if (useCompressed) 2 else 1
  //  fetchWidth doubled, but coreInstBytes halved, for RVC:
  val decodeWidth: Int = fetchWidth / (if (useCompressed) 2 else 1)
  val retireWidth: Int = 1
  val instBits: Int = if (useCompressed) 16 else 32
  val lrscCycles: Int = 80 // worst case is 14 mispredicted branches + slop
  val traceHasWdata: Boolean = false // ooo wb, so no wdata in trace
  override val customIsaExt = Some("Xrocket") // CEASE instruction
  override def minFLen: Int = fpu.map(_.minFLen).getOrElse(32)
  override def customCSRs(implicit p: Parameters) = new RocketCustomCSRs
}

trait HasRocketCoreParameters extends HasCoreParameters {
  lazy val rocketParams: RocketCoreParams = tileParams.core.asInstanceOf[RocketCoreParams]

  val fastLoadWord = rocketParams.fastLoadWord
  val fastLoadByte = rocketParams.fastLoadByte

  val mulDivParams = rocketParams.mulDiv.getOrElse(MulDivParams()) // TODO ask andrew about this

  val usingABLU = usingBitManip || usingBitManipCrypto
  val aluFn = if (usingABLU) new ABLUFN else new ALUFN

  require(!fastLoadByte || fastLoadWord)
  require(!rocketParams.haveFSDirty, "rocket doesn't support setting fs dirty from outside, please disable haveFSDirty")
}

class RocketCustomCSRs(implicit p: Parameters) extends CustomCSRs with HasRocketCoreParameters {
  override def bpmCSR = {
    rocketParams.branchPredictionModeCSR.option(CustomCSR(bpmCSRId, BigInt(1), Some(BigInt(0))))
  }

  private def haveDCache = tileParams.dcache.get.scratch.isEmpty

  override def chickenCSR = {
    val mask = BigInt(
      tileParams.dcache.get.clockGate.toInt << 0 |
      rocketParams.clockGate.toInt << 1 |
      rocketParams.clockGate.toInt << 2 |
      1 << 3 | // disableSpeculativeICacheRefill
      haveDCache.toInt << 9 | // suppressCorruptOnGrantData
      tileParams.icache.get.prefetch.toInt << 17
    )
    Some(CustomCSR(chickenCSRId, mask, Some(mask)))
  }

  def disableICachePrefetch = getOrElse(chickenCSR, _.value(17), true.B)

  def marchid = CustomCSR.constant(CSRs.marchid, BigInt(1))

  def mvendorid = CustomCSR.constant(CSRs.mvendorid, BigInt(rocketParams.mvendorid))

  // mimpid encodes a release version in the form of a BCD-encoded datestamp.
  def mimpid = CustomCSR.constant(CSRs.mimpid, BigInt(rocketParams.mimpid))

  override def decls = super.decls :+ marchid :+ mvendorid :+ mimpid
}

class Rocket(tile: RocketTile)(implicit p: Parameters) extends CoreModule()(p)
    with HasRocketCoreParameters
    with HasCoreIO {

  val clock_en_reg = RegInit(true.B)
  val long_latency_stall = Reg(Bool())
  val id_reg_pause = Reg(Bool())
  val imem_might_request_reg = Reg(Bool())
  val clock_en = WireDefault(true.B)
  val gated_clock =
    if (!rocketParams.clockGate) clock
    else ClockGate(clock, clock_en, "rocket_clock_gate")

  class RocketImpl { // entering gated-clock domain

  // performance counters
  def pipelineIDToWB[T <: Data](x: T): T =
    RegEnable(RegEnable(RegEnable(x, !ctrl_killd), ex_pc_valid), mem_pc_valid)
  val perfEvents = new EventSets(Seq(
    new EventSet((mask, hits) => Mux(wb_xcpt, mask(0), wb_valid && pipelineIDToWB((mask & hits).orR)), Seq(
      ("exception",   () => (false.B,false.B,0.U)),
      ("load"     ,   () => (id_ctrl.mem && id_ctrl.mem_cmd === M_XRD && !id_ctrl.fp,false.B,0.U)),
      ("store",       () => (id_ctrl.mem && id_ctrl.mem_cmd === M_XWR && !id_ctrl.fp,false.B,0.U)),
      ("amo",         () => (usingAtomics.B && id_ctrl.mem && (isAMO(id_ctrl.mem_cmd) || id_ctrl.mem_cmd.isOneOf(M_XLR, M_XSC)),false.B,0.U)),
      ("system",      () => (id_ctrl.csr =/= CSR.N,false.B,0.U)),
      ("arith",       () => (id_ctrl.wxd && !(id_ctrl.jal || id_ctrl.jalr || id_ctrl.mem || id_ctrl.fp || id_ctrl.mul || id_ctrl.div || id_ctrl.csr =/= CSR.N),false.B,0.U)),
      ("branch",      () => (id_ctrl.branch,false.B,0.U)),
      ("jal",         () => (id_ctrl.jal,false.B,0.U)),
      ("jalr",        () => (id_ctrl.jalr,false.B,0.U)))
      ++ (if (!usingMulDiv) Seq() else Seq(
        ("mul", () => if (pipelinedMul) (id_ctrl.mul,false.B,0.U) else (id_ctrl.div && (id_ctrl.alu_fn & aluFn.FN_DIV) =/= aluFn.FN_DIV,false.B,0.U)),
        ("div", () => if (pipelinedMul) (id_ctrl.div,false.B,0.U) else (id_ctrl.div && (id_ctrl.alu_fn & aluFn.FN_DIV) === aluFn.FN_DIV,false.B,0.U))))
      ++ (if (!usingFPU) Seq() else Seq(
        ("fp load",     () => (id_ctrl.fp && io.fpu.dec.ldst && io.fpu.dec.wen,false.B,0.U)  ),
        ("fp store",    () => (id_ctrl.fp && io.fpu.dec.ldst && !io.fpu.dec.wen,false.B,0.U)),
        ("fp add",      () => (id_ctrl.fp && io.fpu.dec.fma && io.fpu.dec.swap23,false.B,0.U)),
        ("fp mul",      () => (id_ctrl.fp && io.fpu.dec.fma && !io.fpu.dec.swap23 && !io.fpu.dec.ren3,false.B,0.U)),
        ("fp mul-add",  () => (id_ctrl.fp && io.fpu.dec.fma && io.fpu.dec.ren3,false.B,0.U)),
        ("fp div/sqrt", () => (id_ctrl.fp && (io.fpu.dec.div || io.fpu.dec.sqrt),false.B,0.U)),
        ("fp other",    () => (id_ctrl.fp && !(io.fpu.dec.ldst || io.fpu.dec.fma || io.fpu.dec.div || io.fpu.dec.sqrt),false.B,0.U))))),
    new EventSet((mask, hits) => (mask & hits).orR, Seq(
      ("load-use interlock",        () => (id_ex_hazard && ex_ctrl.mem || id_mem_hazard && mem_ctrl.mem || id_wb_hazard && wb_ctrl.mem,false.B,0.U)),
      ("long-latency interlock",    () => (id_sboard_hazard,false.B,0.U)),
      ("csr interlock",             () => (id_ex_hazard && ex_ctrl.csr =/= CSR.N || id_mem_hazard && mem_ctrl.csr =/= CSR.N || id_wb_hazard && wb_ctrl.csr =/= CSR.N,false.B,0.U)),
      ("I$ blocked",                () => (icache_blocked,false.B,0.U)),
      ("D$ blocked",                () => (id_ctrl.mem && dcache_blocked,false.B,0.U)),
      ("branch misprediction",      () => (take_pc_mem && mem_direction_misprediction,false.B,0.U)),
      ("control-flow target misprediction", () => (take_pc_mem && mem_misprediction && mem_cfi && !mem_direction_misprediction && !icache_blocked,false.B,0.U)),
      ("flush",                     () => (wb_reg_flush_pipe,false.B,0.U)),
      ("replay",                    () => (replay_wb,false.B,0.U)))
      ++ (if (!usingMulDiv) Seq() else Seq(
        ("mul/div interlock", () => (id_ex_hazard && (ex_ctrl.mul || ex_ctrl.div) || id_mem_hazard && (mem_ctrl.mul || mem_ctrl.div) || id_wb_hazard && wb_ctrl.div,false.B,0.U))))
      ++ (if (!usingFPU) Seq() else Seq(
        ("fp interlock", () => (id_ex_hazard && ex_ctrl.fp || id_mem_hazard && mem_ctrl.fp || id_wb_hazard && wb_ctrl.fp || id_ctrl.fp && id_stall_fpu,false.B,0.U))))),
    new EventSet((mask, hits) => (mask & hits).orR, Seq(
      ("I$ miss",     () => (io.imem.perf.acquire,false.B,0.U)),
      ("D$ miss",     () => (io.dmem.perf.acquire,false.B,0.U)),
      ("D$ release",  () => (io.dmem.perf.release,false.B,0.U)),
      ("ITLB miss",   () => (io.imem.perf.tlbMiss,false.B,0.U)),
      ("DTLB miss",   () => (io.dmem.perf.tlbMiss,false.B,0.U)),
      ("L2 TLB miss", () => (io.ptw.perf.l2miss,false.B,0.U))))
        ))

  val pipelinedMul = usingMulDiv && mulDivParams.mulUnroll == xLen
  val decode_table = {
    require(!usingRoCC || !rocketParams.useSCIE)
    (if (usingMulDiv) new MDecode(pipelinedMul, aluFn) +: (xLen > 32).option(new M64Decode(pipelinedMul, aluFn)).toSeq else Nil) ++:
    (if (usingAtomics) new ADecode(aluFn) +: (xLen > 32).option(new A64Decode(aluFn)).toSeq else Nil) ++:
    (if (fLen >= 32)    new FDecode(aluFn) +: (xLen > 32).option(new F64Decode(aluFn)).toSeq else Nil) ++:
    (if (fLen >= 64)    new DDecode(aluFn) +: (xLen > 32).option(new D64Decode(aluFn)).toSeq else Nil) ++:
    (if (minFLen == 16) new HDecode(aluFn) +: (xLen > 32).option(new H64Decode(aluFn)).toSeq ++: (fLen >= 64).option(new HDDecode(aluFn)).toSeq else Nil) ++:
    (usingRoCC.option(new RoCCDecode(aluFn))) ++:
    (rocketParams.useSCIE.option(new SCIEDecode(aluFn))) ++:
    (if (usingBitManip) new ZBADecode +: (xLen == 64).option(new ZBA64Decode).toSeq ++: new ZBBMDecode +: new ZBBORCBDecode +: new ZBCRDecode +: new ZBSDecode +: (xLen == 32).option(new ZBS32Decode).toSeq ++: (xLen == 64).option(new ZBS64Decode).toSeq ++: new ZBBSEDecode +: new ZBBCDecode +: (xLen == 64).option(new ZBBC64Decode).toSeq else Nil) ++:
    (if (usingBitManip && !usingBitManipCrypto) (xLen == 32).option(new ZBBZE32Decode).toSeq ++: (xLen == 64).option(new ZBBZE64Decode).toSeq else Nil) ++:
    (if (usingBitManip || usingBitManipCrypto) new ZBBNDecode +: new ZBCDecode +: new ZBBRDecode +: (xLen == 32).option(new ZBBR32Decode).toSeq ++: (xLen == 64).option(new ZBBR64Decode).toSeq ++: (xLen == 32).option(new ZBBREV832Decode).toSeq ++: (xLen == 64).option(new ZBBREV864Decode).toSeq else Nil) ++:
    (if (usingBitManipCrypto) new ZBKXDecode +: new ZBKBDecode +: (xLen == 32).option(new ZBKB32Decode).toSeq ++: (xLen == 64).option(new ZBKB64Decode).toSeq else Nil) ++:
    (if (usingCryptoNIST) (xLen == 32).option(new ZKND32Decode).toSeq ++: (xLen == 64).option(new ZKND64Decode).toSeq else Nil) ++:
    (if (usingCryptoNIST) (xLen == 32).option(new ZKNE32Decode).toSeq ++: (xLen == 64).option(new ZKNE64Decode).toSeq else Nil) ++:
    (if (usingCryptoNIST) new ZKNHDecode +: (xLen == 32).option(new ZKNH32Decode).toSeq ++: (xLen == 64).option(new ZKNH64Decode).toSeq else Nil) ++:
    (usingCryptoSM.option(new ZKSDecode)) ++:
    (if (xLen == 32) new I32Decode(aluFn) else new I64Decode(aluFn)) +:
    (usingVM.option(new SVMDecode(aluFn))) ++:
    (usingSupervisor.option(new SDecode(aluFn))) ++:
    (usingHypervisor.option(new HypervisorDecode(aluFn))) ++:
    ((usingHypervisor && (xLen == 64)).option(new Hypervisor64Decode(aluFn))) ++:
    (usingDebug.option(new DebugDecode(aluFn))) ++:
    (usingNMI.option(new NMIDecode(aluFn))) ++:
    Seq(new FenceIDecode(tile.dcache.flushOnFenceI, aluFn)) ++:
    coreParams.haveCFlush.option(new CFlushDecode(tile.dcache.canSupportCFlushLine, aluFn)) ++:
    Seq(new IDecode(aluFn))
  } flatMap(_.table)

  // val kill_each_pipe  = WireInit(false.B)
  val ex_ctrl = Reg(new IntCtrlSigs(aluFn))
  val mem_ctrl = Reg(new IntCtrlSigs(aluFn))
  val wb_ctrl = Reg(new IntCtrlSigs(aluFn))

  val ex_reg_xcpt_interrupt  = Reg(Bool())
  val ex_reg_valid           = Reg(Bool())
  val ex_reg_rvc             = Reg(Bool())
  val ex_reg_btb_resp        = Reg(new BTBResp)
  val ex_reg_xcpt            = Reg(Bool())
  val ex_reg_flush_pipe      = Reg(Bool())
  val ex_reg_load_use        = Reg(Bool())
  val ex_reg_cause           = Reg(UInt())
  val ex_reg_replay = Reg(Bool())
  val ex_reg_pc = Reg(UInt())
  val ex_reg_mem_size = Reg(UInt())
  val ex_reg_hls = Reg(Bool())
  val ex_reg_inst = Reg(Bits())
  val ex_reg_raw_inst = Reg(UInt())
  val ex_scie_unpipelined = Reg(Bool())
  val ex_scie_pipelined = Reg(Bool())
  val ex_reg_wphit            = Reg(Vec(nBreakpoints, Bool()))

  val mem_reg_xcpt_interrupt  = Reg(Bool())
  val mem_reg_valid           = Reg(Bool())
  val mem_reg_rvc             = Reg(Bool())
  val mem_reg_btb_resp        = Reg(new BTBResp)
  val mem_reg_xcpt            = Reg(Bool())
  val mem_reg_replay          = Reg(Bool())
  val mem_reg_flush_pipe      = Reg(Bool())
  val mem_reg_cause           = Reg(UInt())
  val mem_reg_slow_bypass     = Reg(Bool())
  val mem_reg_load            = Reg(Bool())
  val mem_reg_store           = Reg(Bool())
  val mem_reg_sfence = Reg(Bool())
  val mem_reg_pc = Reg(UInt())
  val mem_reg_inst = Reg(Bits())
  val mem_reg_mem_size = Reg(UInt())
  val mem_reg_hls_or_dv = Reg(Bool())
  val mem_reg_raw_inst = Reg(UInt())
  val mem_scie_unpipelined = Reg(Bool())
  val mem_scie_pipelined = Reg(Bool())
  val mem_reg_wdata = Reg(Bits())
  val mem_reg_rs2 = Reg(Bits())
  val mem_br_taken = Reg(Bool())
  val take_pc_mem = Wire(Bool())
  val mem_reg_wphit          = Reg(Vec(nBreakpoints, Bool()))

  val wb_reg_valid           = Reg(Bool())
  val wb_reg_xcpt            = Reg(Bool())
  val wb_reg_replay          = Reg(Bool())
  val wb_reg_flush_pipe      = Reg(Bool())
  val wb_reg_cause           = Reg(UInt())
  val wb_reg_sfence = Reg(Bool())
  val wb_reg_pc = Reg(UInt())
  val wb_reg_mem_size = Reg(UInt())
  val wb_reg_hls_or_dv = Reg(Bool())
  val wb_reg_hfence_v = Reg(Bool())
  val wb_reg_hfence_g = Reg(Bool())
  val wb_reg_inst = Reg(Bits())
  val wb_reg_raw_inst = Reg(UInt())
  val wb_reg_wdata = Reg(Bits())
  val wb_reg_rs2 = Reg(Bits())
  val take_pc_wb = Wire(Bool())

  val check_exception = Wire(Bool())
  val check_privret  = Wire(Bool())
  val excpt_mode = RegInit(false.B)
  val wb_reg_wphit           = Reg(Vec(nBreakpoints, Bool()))

  val take_pc_mem_wb = take_pc_wb || take_pc_mem
  val take_pc = take_pc_mem_wb

  // decode stage
  val ibuf = Module(new IBuf)
  val id_expanded_inst = ibuf.io.inst.map(_.bits.inst)
  val id_raw_inst = ibuf.io.inst.map(_.bits.raw)
  val id_inst = id_expanded_inst.map(_.bits)
  ibuf.io.imem <> io.imem.resp
  ibuf.io.kill := take_pc

  require(decodeWidth == 1 /* TODO */ && retireWidth == decodeWidth)
  require(!(coreParams.useRVE && coreParams.fpu.nonEmpty), "Can't select both RVE and floating-point")
  require(!(coreParams.useRVE && coreParams.useHypervisor), "Can't select both RVE and Hypervisor")
  val id_ctrl = Wire(new IntCtrlSigs(aluFn)).decode(id_inst(0), decode_table)
  val lgNXRegs = if (coreParams.useRVE) 4 else 5
  val regAddrMask = (1 << lgNXRegs) - 1

  def decodeReg(x: UInt) = (x.extract(x.getWidth-1, lgNXRegs).asBool, x(lgNXRegs-1, 0))
  val (id_raddr3_illegal, id_raddr3) = decodeReg(id_expanded_inst(0).rs3)
  val (id_raddr2_illegal, id_raddr2) = decodeReg(id_expanded_inst(0).rs2)
  val (id_raddr1_illegal, id_raddr1) = decodeReg(id_expanded_inst(0).rs1)
  val (id_waddr_illegal,  id_waddr)  = decodeReg(id_expanded_inst(0).rd)

  val id_load_use = Wire(Bool())
  val id_reg_fence = RegInit(false.B)
  val id_ren = IndexedSeq(id_ctrl.rxs1, id_ctrl.rxs2)
  val id_raddr = IndexedSeq(id_raddr1, id_raddr2)
  val rf = new RegFile(regAddrMask, xLen)
  val id_rs = id_raddr.map(rf.read _)
  val ctrl_killd = Wire(Bool())
  val id_npc = (ibuf.io.pc.asSInt + ImmGen(IMM_UJ, id_inst(0))).asUInt

  val csr = Module(new CSRFile(perfEvents, coreParams.customCSRs.decls))
  val id_csr_en = id_ctrl.csr.isOneOf(CSR.S, CSR.C, CSR.W)
  val id_system_insn = id_ctrl.csr === CSR.I
  val id_csr_ren = id_ctrl.csr.isOneOf(CSR.S, CSR.C) && id_expanded_inst(0).rs1 === 0.U
  val id_csr = Mux(id_system_insn && id_ctrl.mem, CSR.N, Mux(id_csr_ren, CSR.R, id_ctrl.csr))
  val id_csr_flush = id_system_insn || (id_csr_en && !id_csr_ren && csr.io.decode(0).write_flush)
//===== GuardianCouncil Function: Start ====//
  io.pc := wb_reg_pc
  io.inst := wb_reg_inst
  io.new_commit := csr.io.trace(0).valid && !csr.io.trace(0).exception
  io.csr_rw_wdata := csr.io.rw.wdata

  /* R Features */
  val rsu_pc = Reg(UInt(40.W))
  val checker_mode = Wire(UInt(1.W))
  val checker_priv_mode = Wire(UInt(1.W))
  ibuf.io.checker_mode := checker_mode
  dontTouch(io.dmem)

  val lsl_req_ready     = Wire(Bool())
  val lsl_req_valid     = Wire(Bool())
  val lsl_req_addr      = Wire(UInt(40.W))
  val lsl_req_tag       = Wire(UInt(8.W))
  val lsl_req_cmd       = Wire(UInt(2.W))
  val lsl_req_data      = Wire(UInt(xLen.W))

  val lsl_resp_valid    = Wire(Bool())
  val lsl_resp_tag      = Wire(UInt(8.W))
  val lsl_resp_size     = Wire(UInt(2.W))
  val lsl_resp_addr     = Wire(UInt(40.W))
  val lsl_resp_cacheable = Wire(Bool())
  val lsl_resp_data     = Wire(UInt(xLen.W))
  val lsl_resp_has_data = Wire(Bool())
  val lsl_resp_replay   = Wire(Bool())
  val lsl_req_size      = Wire(UInt(2.W))
  val lsl_req_kill      = Wire(Bool())
  
  val lsl_req_valid_csr = Wire(Bool())
  val lsl_req_valid_csr_test = Wire(Bool())
  val lsl_resp_data_csr = Wire(UInt(xLen.W))
  val lsl_resp_replay_csr = Wire(Bool())
  val lsl_req_ready_csr = Wire(Bool())

  val lsl_req_valid_rocc = Wire(Bool())
  val lsl_resp_data_rocc = Wire(UInt(xLen.W))
  val lsl_resp_replay_rocc = Wire(Bool())
  val lsl_req_ready_rocc = Wire(Bool())

  val icsl_if_overtaking = Wire(UInt(1.W))
  // val icsl_just_overtaking = Wire(UInt(1.W))
  val icsl_if_ret_special_pc = Wire(UInt(1.W))
  val if_overtaking_next_cycle = Wire(UInt(1.W))
  //===== GuardianCouncil Function: End   ====//
  val id_scie_decoder = if (!rocketParams.useSCIE) WireDefault(0.U.asTypeOf(new SCIEDecoderInterface)) else {
    val d = Module(new SCIEDecoder)
    assert(!io.imem.resp.valid || PopCount(d.io.unpipelined :: d.io.pipelined :: d.io.multicycle :: Nil) <= 1.U)
    d.io.insn := id_raw_inst(0)
    d.io
  }
  val id_illegal_rnum = if (usingCryptoNIST) (id_ctrl.zkn && aluFn.isKs1(id_ctrl.alu_fn) && id_inst(0)(23,20) > 0xA.U(4.W)) else false.B
  val id_illegal_insn = !id_ctrl.legal ||
    (id_ctrl.mul || id_ctrl.div) && !csr.io.status.isa('m'-'a') ||
    id_ctrl.amo && !csr.io.status.isa('a'-'a') ||
    id_ctrl.fp && (csr.io.decode(0).fp_illegal || io.fpu.illegal_rm) ||
    id_ctrl.dp && !csr.io.status.isa('d'-'a') ||
    ibuf.io.inst(0).bits.rvc && !csr.io.status.isa('c'-'a') ||
    id_raddr2_illegal && !id_ctrl.scie && id_ctrl.rxs2 ||
    id_raddr1_illegal && !id_ctrl.scie && id_ctrl.rxs1 ||
    id_waddr_illegal && !id_ctrl.scie && id_ctrl.wxd ||
    id_ctrl.rocc && csr.io.decode(0).rocc_illegal ||
    id_ctrl.scie && !(id_scie_decoder.unpipelined || id_scie_decoder.pipelined) ||
    id_csr_en && (csr.io.decode(0).read_illegal || !id_csr_ren && csr.io.decode(0).write_illegal) ||
    !ibuf.io.inst(0).bits.rvc && (id_system_insn && csr.io.decode(0).system_illegal) ||
    id_illegal_rnum
  val id_virtual_insn = id_ctrl.legal &&
    ((id_csr_en && !(!id_csr_ren && csr.io.decode(0).write_illegal) && csr.io.decode(0).virtual_access_illegal) ||
     (!ibuf.io.inst(0).bits.rvc && id_system_insn && csr.io.decode(0).virtual_system_illegal))
  // stall decode for fences (now, for AMO.rl; later, for AMO.aq and FENCE)
  val id_amo_aq = id_inst(0)(26)
  val id_amo_rl = id_inst(0)(25)
  val id_fence_pred = id_inst(0)(27,24)
  val id_fence_succ = id_inst(0)(23,20)
  val id_fence_next = id_ctrl.fence || id_ctrl.amo && id_amo_aq
  val id_mem_busy = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), lsl_req_valid.asBool, !io.dmem.ordered || io.dmem.req.valid)
  when (!id_mem_busy) { id_reg_fence := false.B }
  val id_rocc_busy = usingRoCC.B &&
    (io.rocc.busy || ex_reg_valid && ex_ctrl.rocc ||
     mem_reg_valid && mem_ctrl.rocc || wb_reg_valid && wb_ctrl.rocc)
  val id_do_fence = WireDefault(id_rocc_busy && id_ctrl.fence ||
    id_mem_busy && (id_ctrl.amo && id_amo_rl || id_ctrl.fence_i || id_reg_fence && (id_ctrl.mem || id_ctrl.rocc)))

  val bpu = Module(new BreakpointUnit(nBreakpoints))
  bpu.io.status := csr.io.status
  bpu.io.bp := csr.io.bp
  bpu.io.pc := ibuf.io.pc
  bpu.io.ea := mem_reg_wdata
  bpu.io.mcontext := csr.io.mcontext
  bpu.io.scontext := csr.io.scontext

  val id_xcpt0 = ibuf.io.inst(0).bits.xcpt0
  val id_xcpt1 = ibuf.io.inst(0).bits.xcpt1
  val (id_xcpt, id_cause) = checkExceptions(List(
    (csr.io.interrupt, csr.io.interrupt_cause),
    (bpu.io.debug_if,  CSR.debugTriggerCause.U),
    (bpu.io.xcpt_if,   Causes.breakpoint.U),
    (id_xcpt0.pf.inst, Causes.fetch_page_fault.U),
    (id_xcpt0.gf.inst, Causes.fetch_guest_page_fault.U),
    (id_xcpt0.ae.inst, Causes.fetch_access.U),
    (id_xcpt1.pf.inst, Causes.fetch_page_fault.U),
    (id_xcpt1.gf.inst, Causes.fetch_guest_page_fault.U),
    (id_xcpt1.ae.inst, Causes.fetch_access.U),
    (id_virtual_insn,  Causes.virtual_instruction.U),
    (id_illegal_insn,  Causes.illegal_instruction.U)))

  val idCoverCauses = List(
    (CSR.debugTriggerCause, "DEBUG_TRIGGER"),
    (Causes.breakpoint, "BREAKPOINT"),
    (Causes.fetch_access, "FETCH_ACCESS"),
    (Causes.illegal_instruction, "ILLEGAL_INSTRUCTION")
  ) ++ (if (usingVM) List(
    (Causes.fetch_page_fault, "FETCH_PAGE_FAULT")
  ) else Nil)
  coverExceptions(id_xcpt, id_cause, "DECODE", idCoverCauses)

  // val dcache_bypass_data =
  //   if (fastLoadByte) io.dmem.resp.bits.data(xLen-1, 0)
  //   else if (fastLoadWord) io.dmem.resp.bits.data_word_bypass(xLen-1, 0)
  //   else wb_reg_wdata
  //===== GuardianCouncil Function: Start ====//
  // Enabling data bypass for RoCC commands
  val dcache_bypass_data =
    if (fastLoadByte) Mux(wb_ctrl.rocc, io.rocc.resp.bits.data, Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), lsl_resp_data, io.dmem.resp.bits.data(xLen-1, 0)))
    else if (fastLoadWord) Mux(wb_ctrl.rocc, io.rocc.resp.bits.data, Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), lsl_resp_data, io.dmem.resp.bits.data_word_bypass(xLen-1, 0)))
    else wb_reg_wdata
  dontTouch(dcache_bypass_data)
  //===== GuardianCouncil Function: End ====//
  // detect bypass opportunities
  val ex_waddr = ex_reg_inst(11,7) & regAddrMask.U
  val mem_waddr = mem_reg_inst(11,7) & regAddrMask.U
  val wb_waddr = wb_reg_inst(11,7) & regAddrMask.U
  val bypass_sources = IndexedSeq(
    (true.B, 0.U, 0.U), // treat reading x0 as a bypass
    (ex_reg_valid && ex_ctrl.wxd, ex_waddr, mem_reg_wdata),
    (mem_reg_valid && mem_ctrl.wxd && !mem_ctrl.mem && !mem_ctrl.rocc, mem_waddr, wb_reg_wdata),
    (mem_reg_valid && mem_ctrl.wxd, mem_waddr, dcache_bypass_data))
  val id_bypass_src = id_raddr.map(raddr => bypass_sources.map(s => s._1 && s._2 === raddr))


  val bypass_mux_2 = bypass_sources.map(_._2)
  val bypass_mux_1 = bypass_sources.map(_._1)
  dontTouch(ex_waddr)
  dontTouch(mem_waddr)
  dontTouch(wb_waddr)
  
  for(i <- 0 until id_raddr.size){
    dontTouch(id_raddr(i))
  }

  // for(i <- 0 until id_raddr.size){
  //   for(j <- 0 until bypass_sources.size){
  //     dontTouch(id_bypass_src(i)(j))
  //   }
  // }


  // execute stage
  val bypass_mux = bypass_sources.map(_._3)
  val ex_reg_rs_bypass = Reg(Vec(id_raddr.size, Bool()))
  val ex_reg_rs_lsb = Reg(Vec(id_raddr.size, UInt(log2Ceil(bypass_sources.size).W)))
  val ex_reg_rs_msb = Reg(Vec(id_raddr.size, UInt()))
  val ex_rs = for (i <- 0 until id_raddr.size)
    yield Mux(ex_reg_rs_bypass(i), bypass_mux(ex_reg_rs_lsb(i)), Cat(ex_reg_rs_msb(i), ex_reg_rs_lsb(i)))
  val ex_imm = ImmGen(ex_ctrl.sel_imm, ex_reg_inst)
  val ex_op1 = MuxLookup(ex_ctrl.sel_alu1, 0.S, Seq(
    A1_RS1 -> ex_rs(0).asSInt,
    A1_PC -> ex_reg_pc.asSInt))
  val ex_op2 = MuxLookup(ex_ctrl.sel_alu2, 0.S, Seq(
    A2_RS2 -> ex_rs(1).asSInt,
    A2_IMM -> ex_imm,
    A2_SIZE -> Mux(ex_reg_rvc, 2.S, 4.S)))

  //   for(i <- 0 until bypass_sources.size){
  //   dontTouch(bypass_mux_2(i))
  //   dontTouch(bypass_mux_1(i))
  //   dontTouch(bypass_mux(i))
  // }

  val alu = Module(aluFn match {
    case _: ABLUFN => new ABLU
    case _: ALUFN => new ALU
  })
  alu.io.dw := ex_ctrl.alu_dw
  alu.io.fn := ex_ctrl.alu_fn
  alu.io.in2 := ex_op2.asUInt
  alu.io.in1 := ex_op1.asUInt

  val ex_scie_unpipelined_wdata = if (!rocketParams.useSCIE) 0.U else {
    val u = Module(new SCIEUnpipelined(xLen))
    u.io.insn := ex_reg_inst
    u.io.rs1 := ex_rs(0)
    u.io.rs2 := ex_rs(1)
    u.io.rd
  }
  //===== GuardianCouncil Function: Start ====//
  val alu_1cycle_delay_reg = Reg(UInt())
  val alu_2cycle_delay_reg = Reg(UInt())
  alu_1cycle_delay_reg := alu.io.out
  alu_2cycle_delay_reg := alu_1cycle_delay_reg
  io.alu_2cycle_delay := alu_2cycle_delay_reg
  val record_pc = Reg(UInt())
  val pc_special = Reg(UInt())
  record_pc := io.record_pc
  pc_special := Mux(record_pc === 1.U, wb_reg_pc + 4.U, pc_special)
  //===== GuardianCouncil Function: Start ====//

  val mem_scie_pipelined_wdata = if (!rocketParams.useSCIE) 0.U else {
    val u = Module(new SCIEPipelined(xLen))
    u.io.clock := Module.clock
    u.io.valid := ex_reg_valid && ex_scie_pipelined
    u.io.insn := ex_reg_inst
    u.io.rs1 := ex_rs(0)
    u.io.rs2 := ex_rs(1)
    u.io.rd
  }

  val ex_zbk_wdata = if (!usingBitManipCrypto && !usingBitManip) 0.U else {
    val zbk = Module(new BitManipCrypto(xLen))
    zbk.io.fn  := ex_ctrl.alu_fn
    zbk.io.dw  := ex_ctrl.alu_dw
    zbk.io.rs1 := ex_op1.asUInt
    zbk.io.rs2 := ex_op2.asUInt
    zbk.io.rd
  }

  val ex_zkn_wdata = if (!usingCryptoNIST) 0.U else {
    val zkn = Module(new CryptoNIST(xLen))
    zkn.io.fn   := ex_ctrl.alu_fn
    zkn.io.hl   := ex_reg_inst(27)
    zkn.io.bs   := ex_reg_inst(31,30)
    zkn.io.rs1  := ex_op1.asUInt
    zkn.io.rs2  := ex_op2.asUInt
    zkn.io.rd
  }

  val ex_zks_wdata = if (!usingCryptoSM) 0.U else {
    val zks = Module(new CryptoSM(xLen))
    zks.io.fn  := ex_ctrl.alu_fn
    zks.io.bs  := ex_reg_inst(31,30)
    zks.io.rs1 := ex_op1.asUInt
    zks.io.rs2 := ex_op2.asUInt
    zks.io.rd
  }

  // multiplier and divider
  val div = Module(new MulDiv(if (pipelinedMul) mulDivParams.copy(mulUnroll = 0) else mulDivParams, width = xLen, aluFn = aluFn))
  div.io.req.valid := ex_reg_valid && ex_ctrl.div
  div.io.req.bits.dw := ex_ctrl.alu_dw
  div.io.req.bits.fn := ex_ctrl.alu_fn
  div.io.req.bits.in1 := ex_rs(0)
  div.io.req.bits.in2 := ex_rs(1)
  div.io.req.bits.tag := ex_waddr
  val mul = pipelinedMul.option {
    val m = Module(new PipelinedMultiplier(xLen, 2, aluFn = aluFn))
    m.io.req.valid := ex_reg_valid && ex_ctrl.mul
    m.io.req.bits := div.io.req.bits
    m
  }

  ex_reg_valid := !ctrl_killd
  ex_reg_replay := !take_pc && ibuf.io.inst(0).valid && ibuf.io.inst(0).bits.replay
  ex_reg_xcpt := !ctrl_killd && id_xcpt
  ex_reg_xcpt_interrupt := !take_pc && ibuf.io.inst(0).valid && csr.io.interrupt

  when (!ctrl_killd) {
    ex_ctrl := id_ctrl
    ex_reg_rvc := ibuf.io.inst(0).bits.rvc
    ex_ctrl.csr := id_csr
    ex_scie_unpipelined := id_ctrl.scie && id_scie_decoder.unpipelined
    ex_scie_pipelined := id_ctrl.scie && id_scie_decoder.pipelined
    when (id_ctrl.fence && id_fence_succ === 0.U) { id_reg_pause := true.B }
    when (id_fence_next) { id_reg_fence := true.B }
    when (id_xcpt) { // pass PC down ALU writeback pipeline for badaddr
      ex_ctrl.alu_fn := aluFn.FN_ADD
      ex_ctrl.alu_dw := DW_XPR
      ex_ctrl.sel_alu1 := A1_RS1 // badaddr := instruction
      ex_ctrl.sel_alu2 := A2_ZERO
      when (id_xcpt1.asUInt.orR) { // badaddr := PC+2
        ex_ctrl.sel_alu1 := A1_PC
        ex_ctrl.sel_alu2 := A2_SIZE
        ex_reg_rvc := true.B
      }
      when (bpu.io.xcpt_if || id_xcpt0.asUInt.orR) { // badaddr := PC
        ex_ctrl.sel_alu1 := A1_PC
        ex_ctrl.sel_alu2 := A2_ZERO
      }
    }
    ex_reg_flush_pipe := id_ctrl.fence_i || id_csr_flush
    ex_reg_load_use := id_load_use
    ex_reg_hls := usingHypervisor.B && id_system_insn && id_ctrl.mem_cmd.isOneOf(M_XRD, M_XWR, M_HLVX)
    ex_reg_mem_size := Mux(usingHypervisor.B && id_system_insn, id_inst(0)(27, 26), id_inst(0)(13, 12))
    when (id_ctrl.mem_cmd.isOneOf(M_SFENCE, M_HFENCEV, M_HFENCEG, M_FLUSH_ALL)) {
      ex_reg_mem_size := Cat(id_raddr2 =/= 0.U, id_raddr1 =/= 0.U)
    }
    when (id_ctrl.mem_cmd === M_SFENCE && csr.io.status.v) {
      ex_ctrl.mem_cmd := M_HFENCEV
    }
    if (tile.dcache.flushOnFenceI) {
      when (id_ctrl.fence_i) {
        ex_reg_mem_size := 0.U
      }
    }

    for (i <- 0 until id_raddr.size) {
      val do_bypass = id_bypass_src(i).reduce(_||_)
      val bypass_src = PriorityEncoder(id_bypass_src(i))
      ex_reg_rs_bypass(i) := do_bypass
      ex_reg_rs_lsb(i) := bypass_src
      when (id_ren(i) && !do_bypass) {
        ex_reg_rs_lsb(i) := id_rs(i)(log2Ceil(bypass_sources.size)-1, 0)
        ex_reg_rs_msb(i) := id_rs(i) >> log2Ceil(bypass_sources.size)
      }
    }
    when (id_illegal_insn || id_virtual_insn) {
      val inst = Mux(ibuf.io.inst(0).bits.rvc, id_raw_inst(0)(15, 0), id_raw_inst(0))
      ex_reg_rs_bypass(0) := false.B
      ex_reg_rs_lsb(0) := inst(log2Ceil(bypass_sources.size)-1, 0)
      ex_reg_rs_msb(0) := inst >> log2Ceil(bypass_sources.size)
    }
  }
  when (!ctrl_killd || csr.io.interrupt || ibuf.io.inst(0).bits.replay) {
    ex_reg_cause := id_cause
    ex_reg_inst := id_inst(0)
    ex_reg_raw_inst := id_raw_inst(0)
    ex_reg_pc := ibuf.io.pc
    ex_reg_btb_resp := ibuf.io.btb_resp
    ex_reg_wphit := bpu.io.bpwatch.map { bpw => bpw.ivalid(0) }
  }

  // replay inst in ex stage?
  val ex_pc_valid = ex_reg_valid || ex_reg_replay || ex_reg_xcpt_interrupt
  val wb_dcache_miss = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, wb_ctrl.mem && !io.dmem.resp.valid)
  val replay_ex_structural = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), (ex_ctrl.div && !div.io.req.ready), ex_ctrl.mem && !io.dmem.req.ready ||
                                                                                           ex_ctrl.div && !div.io.req.ready)
  val replay_ex_load_use = wb_dcache_miss && ex_reg_load_use
  val replay_ex = ex_reg_replay || (ex_reg_valid && (replay_ex_structural || replay_ex_load_use))
  val ctrl_killx = take_pc_mem_wb || replay_ex || !ex_reg_valid 
  // detect 2-cycle load-use delay for LB/LH/SC
  val ex_slow_bypass = ex_ctrl.mem_cmd === M_XSC || ex_reg_mem_size < 2.U
  val ex_sfence = usingVM.B && ex_ctrl.mem && (ex_ctrl.mem_cmd === M_SFENCE || ex_ctrl.mem_cmd === M_HFENCEV || ex_ctrl.mem_cmd === M_HFENCEG)

  val (ex_xcpt, ex_cause) = checkExceptions(List(
    (ex_reg_xcpt_interrupt || ex_reg_xcpt, ex_reg_cause)))

  val exCoverCauses = idCoverCauses
  coverExceptions(ex_xcpt, ex_cause, "EXECUTE", exCoverCauses)

  // memory stage
  val mem_pc_valid = mem_reg_valid || mem_reg_replay || mem_reg_xcpt_interrupt
  val mem_br_target = mem_reg_pc.asSInt +
    Mux(mem_ctrl.branch && mem_br_taken, ImmGen(IMM_SB, mem_reg_inst),
    Mux(mem_ctrl.jal, ImmGen(IMM_UJ, mem_reg_inst),
    Mux(mem_reg_rvc, 2.S, 4.S)))
  val mem_npc = (Mux(mem_ctrl.jalr || mem_reg_sfence, encodeVirtualAddress(mem_reg_wdata, mem_reg_wdata).asSInt, mem_br_target) & (-2).S).asUInt
  val mem_wrong_npc =
    Mux(ex_pc_valid, mem_npc =/= ex_reg_pc,
    Mux(ibuf.io.inst(0).valid || ibuf.io.imem.valid, mem_npc =/= ibuf.io.pc, Mux(checker_mode.asBool || checker_priv_mode.asBool, false.B, true.B)))
  val mem_npc_misaligned = !csr.io.status.isa('c'-'a') && mem_npc(1) && !mem_reg_sfence
  val mem_int_wdata = Mux(!mem_reg_xcpt && (mem_ctrl.jalr ^ mem_npc_misaligned), mem_br_target, mem_reg_wdata.asSInt).asUInt
  val mem_cfi = mem_ctrl.branch || mem_ctrl.jalr || mem_ctrl.jal
  val mem_cfi_taken = (mem_ctrl.branch && mem_br_taken) || mem_ctrl.jalr || mem_ctrl.jal
  val mem_direction_misprediction = mem_ctrl.branch && mem_br_taken =/= (usingBTB.B && mem_reg_btb_resp.taken)
  val mem_misprediction = if (usingBTB) mem_wrong_npc else mem_cfi_taken
  // take_pc_mem := mem_reg_valid && !mem_reg_xcpt && (Mux((checker_mode.asBool || checker_priv_mode.asBool) && (mem_ctrl.branch || (mem_ctrl.jalr && mem_reg_inst(12) =/= 1.U) || mem_ctrl.jal), false.B, mem_misprediction) || mem_reg_sfence)
  take_pc_mem := mem_reg_valid && !mem_reg_xcpt && (Mux((checker_mode.asBool || checker_priv_mode.asBool), (mem_ctrl.jalr && mem_reg_inst(12) === 1.U), mem_misprediction) || mem_reg_sfence)

  dontTouch(mem_npc)
  dontTouch(mem_br_target)
  dontTouch(mem_reg_wdata)
  dontTouch(mem_ctrl)

  mem_reg_valid := !ctrl_killx
  mem_reg_replay := !take_pc_mem_wb && replay_ex
  mem_reg_xcpt := !ctrl_killx && ex_xcpt
  mem_reg_xcpt_interrupt := !take_pc_mem_wb && ex_reg_xcpt_interrupt

  // on pipeline flushes, cause mem_npc to hold the sequential npc, which
  // will drive the W-stage npc mux
  when (mem_reg_valid && mem_reg_flush_pipe) {
    mem_reg_sfence := false.B
  }.elsewhen (ex_pc_valid) {
    mem_ctrl := ex_ctrl
    mem_scie_unpipelined := ex_scie_unpipelined
    mem_scie_pipelined := ex_scie_pipelined
    mem_reg_rvc := ex_reg_rvc
    mem_reg_load := ex_ctrl.mem && isRead(ex_ctrl.mem_cmd)
    mem_reg_store := ex_ctrl.mem && isWrite(ex_ctrl.mem_cmd)
    mem_reg_sfence := ex_sfence
    mem_reg_btb_resp := ex_reg_btb_resp
    mem_reg_flush_pipe := ex_reg_flush_pipe
    mem_reg_slow_bypass := ex_slow_bypass
    mem_reg_wphit := ex_reg_wphit

    mem_reg_cause := ex_cause
    mem_reg_inst := ex_reg_inst
    mem_reg_raw_inst := ex_reg_raw_inst
    mem_reg_mem_size := ex_reg_mem_size
    mem_reg_hls_or_dv := io.dmem.req.bits.dv
    mem_reg_pc := ex_reg_pc
    // IDecode ensured they are 1H
    mem_reg_wdata := Mux((ex_ctrl.jalr && ex_reg_inst(12) === 1.U), rsu_pc,  
      Mux1H(Seq(
      ex_scie_unpipelined -> ex_scie_unpipelined_wdata,
      ex_ctrl.zbk         -> ex_zbk_wdata,
      ex_ctrl.zkn         -> ex_zkn_wdata,
      ex_ctrl.zks         -> ex_zks_wdata,
      (!ex_scie_unpipelined && !ex_ctrl.zbk && !ex_ctrl.zkn && !ex_ctrl.zks)
                          -> alu.io.out,
    )))
    mem_br_taken := alu.io.cmp_out

    when (ex_ctrl.rxs2 && (ex_ctrl.mem || ex_ctrl.rocc || ex_sfence)) {
      val size = Mux(ex_ctrl.rocc, log2Ceil(xLen/8).U, ex_reg_mem_size)
      mem_reg_rs2 := new StoreGen(size, 0.U, ex_rs(1), coreDataBytes).data
    }
    when (ex_ctrl.jalr && csr.io.status.debug) {
      // flush I$ on D-mode JALR to effect uncached fetch without D$ flush
      mem_ctrl.fence_i := true.B
      mem_reg_flush_pipe := true.B
    }
  }

  val mem_breakpoint = (mem_reg_load && bpu.io.xcpt_ld) || (mem_reg_store && bpu.io.xcpt_st)
  val mem_debug_breakpoint = (mem_reg_load && bpu.io.debug_ld) || (mem_reg_store && bpu.io.debug_st)
  val (mem_ldst_xcpt, mem_ldst_cause) = checkExceptions(List(
    (mem_debug_breakpoint, CSR.debugTriggerCause.U),
    (mem_breakpoint,       Causes.breakpoint.U)))

  val (mem_xcpt, mem_cause) = checkExceptions(List(
    (mem_reg_xcpt_interrupt || mem_reg_xcpt, mem_reg_cause),
    (mem_reg_valid && mem_npc_misaligned,    Causes.misaligned_fetch.U),
    (mem_reg_valid && mem_ldst_xcpt,         mem_ldst_cause)))

  val memCoverCauses = (exCoverCauses ++ List(
    (CSR.debugTriggerCause, "DEBUG_TRIGGER"),
    (Causes.breakpoint, "BREAKPOINT"),
    (Causes.misaligned_fetch, "MISALIGNED_FETCH")
  )).distinct
  coverExceptions(mem_xcpt, mem_cause, "MEMORY", memCoverCauses)

  val dcache_kill_mem = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, mem_reg_valid && mem_ctrl.wxd && io.dmem.replay_next) // structural hazard on writeback port
  val fpu_kill_mem = mem_reg_valid && mem_ctrl.fp && io.fpu.nack_mem
  val replay_mem  = dcache_kill_mem || mem_reg_replay || fpu_kill_mem
  val killm_common = dcache_kill_mem || take_pc_wb || mem_reg_xcpt || !mem_reg_valid
  
  val ctrl_killm = killm_common || mem_xcpt || fpu_kill_mem 

  val if_kill_div_r =  Mux(checker_mode === 0.U && checker_priv_mode === 0.U, false.B, Mux(!ctrl_killm && mem_ctrl.div && if_overtaking_next_cycle.asBool, true.B, false.B))
  div.io.kill := (killm_common && RegNext(div.io.req.fire)) || if_kill_div_r

  val wb_pc_valid = wb_reg_valid || wb_reg_replay || wb_reg_xcpt


  // writeback stage
  wb_reg_valid := !ctrl_killm
  wb_reg_replay := replay_mem && !take_pc_wb
  wb_reg_xcpt := mem_xcpt && !take_pc_wb
  wb_reg_flush_pipe := !ctrl_killm && mem_reg_flush_pipe
  when (mem_pc_valid) {
    wb_ctrl := mem_ctrl
    wb_reg_sfence := mem_reg_sfence
    wb_reg_wdata := Mux(mem_scie_pipelined, mem_scie_pipelined_wdata,
      Mux(!mem_reg_xcpt && mem_ctrl.fp && mem_ctrl.wxd, io.fpu.toint_data, mem_int_wdata))
    when (mem_ctrl.rocc || mem_reg_sfence) {
      wb_reg_rs2 := mem_reg_rs2
    }
    wb_reg_cause := mem_cause
    wb_reg_inst := mem_reg_inst
    wb_reg_raw_inst := mem_reg_raw_inst
    wb_reg_mem_size := mem_reg_mem_size
    wb_reg_hls_or_dv := mem_reg_hls_or_dv
    wb_reg_hfence_v := mem_ctrl.mem_cmd === M_HFENCEV
    wb_reg_hfence_g := mem_ctrl.mem_cmd === M_HFENCEG
    wb_reg_pc := mem_reg_pc
    wb_reg_wphit := mem_reg_wphit | bpu.io.bpwatch.map { bpw => (bpw.rvalid(0) && mem_reg_load) || (bpw.wvalid(0) && mem_reg_store) }

  }

  val (wb_xcpt, wb_cause) = checkExceptions(List(
    (wb_reg_xcpt,  wb_reg_cause),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.pf.st), Causes.store_page_fault.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.pf.ld), Causes.load_page_fault.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.gf.st), Causes.store_guest_page_fault.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.gf.ld), Causes.load_guest_page_fault.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.ae.st), Causes.store_access.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.ae.ld), Causes.load_access.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.ma.st), Causes.misaligned_store.U),
    (wb_reg_valid && wb_ctrl.mem && Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_xcpt.ma.ld), Causes.misaligned_load.U)
  ))
//===== GuardianCouncil Function: Start ====//
  /* R Features */
  val rsu_slave = Module(new R_RSUSL(R_RSUSLParams(xLen, 32)))
  val lsl = Module(new R_LSL(R_LSLParams(255, xLen)))
  val icsl = Module(new R_ICSL(R_ICSLParams(16)))
  // val csrshadow_seq = (CSRshadows.allshadows_for_filter.map(_.asUInt)).toSeq
  // val csrshadow_seq                               = Seq(CSRs.fflags.U, CSRs.fcsr.U, CSRs.frm.U)
  // Original design:
  // val wb_wxd = wb_reg_valid && wb_ctrl.wxd
  // val replay_wb_rocc = wb_reg_valid && wb_ctrl.rocc && !io.rocc.cmd.ready
  // In GuardianCouncil, RoCC response can be replied in a single cycle, therefore !io.rocc.resp.valid is added
  val wb_wxd = wb_reg_valid && wb_ctrl.wxd && !io.rocc.resp.valid
  val replay_wb_rocc = wb_reg_valid && wb_ctrl.rocc && (false).B // in guardian council, rocc.cmd.ready is always ready
  val replay_wb_lsl = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), lsl_resp_replay.asBool || lsl_resp_replay_csr.asBool || lsl_resp_replay_rocc.asBool, false.B)
  val wb_csr = (wb_reg_inst(6,0) === 0x73.U) && ((wb_reg_inst(14,12) === 0x2.U) || (wb_reg_inst(14,12) === 0x1.U) || (wb_reg_inst(14,12) === 0x3.U) || (wb_reg_inst(14,12) === 0x5.U) || (wb_reg_inst(14,12) === 0x6.U) || (wb_reg_inst(14,12) === 0x7.U)) && !wb_reg_inst(31, 20).isOneOf(CSRshadows.csrshadow_seq) && wb_reg_valid
  val wb_rocc = wb_reg_valid && wb_ctrl.rocc
  val wb_rocc_wb = wb_rocc && wb_ctrl.wxd  // ROCC with register writeback (ROCC_INSTRUCTION_D/DS/DSS)
  lsl_resp_replay_csr := Mux(checker_mode.asBool, wb_csr && !lsl_req_ready_csr, false.B)
  
  lsl_resp_replay_rocc := Mux(checker_mode.asBool, wb_rocc_wb && !lsl_req_ready_rocc, false.B)

  /* IN GC, ROCC IS NOT A LONG-LATENCY INSTRUCTION ANY MORE */
  val wb_set_sboard = wb_ctrl.div || wb_dcache_miss
  val replay_wb_common = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), false.B, io.dmem.s2_nack) || wb_reg_replay
  val replay_wb_without_overtaken = replay_wb_common || replay_wb_rocc
  val wb_should_be_valid_but_be_overtaken = Mux(checker_mode.asBool || checker_priv_mode.asBool, icsl_if_overtaking.asBool && wb_reg_valid && !replay_wb_without_overtaken && !replay_wb_lsl && !wb_xcpt && !io.rocc.resp.valid, false.B)
  val let_ret_s_commit = wb_reg_valid && !wb_xcpt && !io.rocc.resp.valid && (wb_reg_pc === pc_special)
  val wb_r_replay = ((wb_should_be_valid_but_be_overtaken || replay_wb_lsl) && !let_ret_s_commit)
  val replay_wb = replay_wb_without_overtaken || (wb_r_replay && (icsl.io.debug_state =/= 6.U))
  val if_ret_special = icsl_if_ret_special_pc.asBool && (!RegNext(icsl_if_ret_special_pc.asBool))
  take_pc_wb := replay_wb || wb_xcpt || csr.io.eret || wb_reg_flush_pipe || check_exception || check_privret || if_ret_special

  /*
  if (GH_GlobalParams.GH_DEBUG == 1) {
    when (replay_wb && io.core_trace.asBool) {
      printf(midas.targetutils.SynthesizePrintf("C%d: re-wb[%x], [%x], [%x], [%x].\n",
          io.hartid, replay_wb_common.asUInt, wb_should_be_valid_but_be_overtaken.asUInt, replay_wb_lsl.asUInt, let_ret_s_commit.asUInt))
    }
  } 
  */
  //===== GuardianCouncil Function: End   ====//
  val wbCoverCauses = List(
    (Causes.misaligned_store, "MISALIGNED_STORE"),
    (Causes.misaligned_load, "MISALIGNED_LOAD"),
    (Causes.store_access, "STORE_ACCESS"),
    (Causes.load_access, "LOAD_ACCESS")
  ) ++ (if(usingVM) List(
    (Causes.store_page_fault, "STORE_PAGE_FAULT"),
    (Causes.load_page_fault, "LOAD_PAGE_FAULT")
  ) else Nil) ++ (if (usingHypervisor) List(
    (Causes.store_guest_page_fault, "STORE_GUEST_PAGE_FAULT"),
    (Causes.load_guest_page_fault, "LOAD_GUEST_PAGE_FAULT"),
  ) else Nil)
  coverExceptions(wb_xcpt, wb_cause, "WRITEBACK", wbCoverCauses)

  

  //===== GuardianCouncil Function: Start ====//
  // Original design:
  // val wb_valid = wb_reg_valid && !replay_wb && !wb_xcpt
  // In GuardianCouncil, RoCC response can be replied in a single cycle, therefore !io.rocc.resp.valid is added
  val wb_valid = wb_reg_valid && !replay_wb && !wb_xcpt && !check_exception
  // Rocket 重执行完成路径：LSL 已返回且指令成功通过 WB，才算 checker 执行完成。
  // wb_valid 已排除 replay/exception，精确命令匹配排除 LR/SC/AMO。
  val checker_mem_complete = (checker_mode.asBool || checker_priv_mode.asBool) &&
    wb_valid && wb_ctrl.mem && lsl_resp_valid && !lsl_resp_replay
  val checker_store_complete = checker_mem_complete && wb_ctrl.mem_cmd === M_XWR
  val checker_load_complete = checker_mem_complete && wb_ctrl.mem_cmd === M_XRD
  val checker_lr_complete = checker_mem_complete && wb_ctrl.mem_cmd === M_XLR
  val checker_sc_complete = checker_mem_complete && wb_ctrl.mem_cmd === M_XSC
  val checker_amo_complete = checker_mem_complete && isAMO(wb_ctrl.mem_cmd)
  // SC writes zero on success and a non-zero value on failure. LR has no
  // architectural failure result, so only its successful completion is counted.
  val checker_sc_success_complete = checker_sc_complete && (lsl_resp_data === 0.U)
  val checker_sc_fail_complete = checker_sc_complete && (lsl_resp_data =/= 0.U)
  val checker_amo_cache_complete = checker_amo_complete && lsl_resp_cacheable
  val checker_amo_uncache_complete = checker_amo_complete && !lsl_resp_cacheable
  val checker_store_cache_complete = checker_store_complete && lsl_resp_cacheable
  val checker_store_uncache_complete = checker_store_complete && !lsl_resp_cacheable
  val checker_load_cache_complete = checker_load_complete && lsl_resp_cacheable
  val checker_load_uncache_complete = checker_load_complete && !lsl_resp_cacheable
  /*
  if (GH_GlobalParams.GH_DEBUG == 1) {
    when (wb_reg_valid && !wb_valid && io.core_trace.asBool) {
      printf(midas.targetutils.SynthesizePrintf("C%d: bl-wb[%x], [%x].\n",
          io.hartid, replay_wb.asUInt, wb_xcpt.asUInt))
    }
  }
  */
  
  // writeback arbitration
  val dmem_resp_xpu = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), !lsl_resp_tag(0).asBool, !io.dmem.resp.bits.tag(0).asBool)
  val dmem_resp_fpu = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), lsl_resp_tag(0).asBool, io.dmem.resp.bits.tag(0).asBool)
  val dmem_resp_waddr = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), lsl_resp_tag(5,1), io.dmem.resp.bits.tag(5, 1))
  val dmem_resp_valid = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), lsl_resp_valid.asBool && lsl_resp_has_data.asBool, io.dmem.resp.valid && io.dmem.resp.bits.has_data)
  val dmem_resp_replay = Mux(((checker_mode === 1.U) || (checker_priv_mode === 1.U)), dmem_resp_valid && lsl_resp_replay.asBool, dmem_resp_valid && io.dmem.resp.bits.replay)

  div.io.resp.ready := !wb_wxd
  val ll_wdata = WireInit(div.io.resp.bits.data)
  val ll_waddr = WireInit(div.io.resp.bits.tag)
  val ll_wen = WireInit(div.io.resp.fire())

  if (usingRoCC) {
    io.rocc.resp.ready := (true).B
    when (io.rocc.resp.fire()) {
      div.io.resp.ready := (false).B
      ll_wdata := Mux(checker_mode.asBool || checker_priv_mode.asBool,
                      lsl_resp_data_rocc, io.rocc.resp.bits.data)
      ll_waddr := io.rocc.resp.bits.rd
      // ll_wen := wb_valid /* THIS IS A BLACK HACK, BECAUSE THE ROCC ISA IS NOW HANDLED AT MEM STAGE AND MUST BE REPLIED AT 1 CYCLE */
      ll_wen := wb_valid
    }
  }
  when (dmem_resp_replay && dmem_resp_xpu) {
    div.io.resp.ready := (false).B
    if (usingRoCC)
      io.rocc.resp.ready := (false).B
    ll_waddr := dmem_resp_waddr
    ll_wen := (true).B
  }


  
  
  // // writeback arbitration
  // val dmem_resp_xpu = !io.dmem.resp.bits.tag(0).asBool
  // val dmem_resp_fpu =  io.dmem.resp.bits.tag(0).asBool
  // val dmem_resp_waddr = io.dmem.resp.bits.tag(5, 1)
  // val dmem_resp_valid = io.dmem.resp.valid && io.dmem.resp.bits.has_data
  // val dmem_resp_replay = dmem_resp_valid && io.dmem.resp.bits.replay

  // div.io.resp.ready := !wb_wxd
  // val ll_wdata = WireDefault(div.io.resp.bits.data)
  // val ll_waddr = WireDefault(div.io.resp.bits.tag)
  // val ll_wen = WireDefault(div.io.resp.fire)
  // if (usingRoCC) {
  //   io.rocc.resp.ready := !wb_wxd
  //   when (io.rocc.resp.fire) {
  //     div.io.resp.ready := false.B
  //     ll_wdata := io.rocc.resp.bits.data
  //     ll_waddr := io.rocc.resp.bits.rd
  //     ll_wen := true.B
  //   }
  // }
  // when (dmem_resp_replay && dmem_resp_xpu) {
  //   div.io.resp.ready := false.B
  //   if (usingRoCC)
  //     io.rocc.resp.ready := false.B
  //   ll_waddr := dmem_resp_waddr
  //   ll_wen := true.B
  // }

  // val wb_valid = wb_reg_valid && !replay_wb && !wb_xcpt
  
  val wb_wen = wb_valid && wb_ctrl.wxd && !lsl_resp_replay_csr && !lsl_resp_replay_rocc
  val rf_wen = wb_wen || ll_wen
  val rf_waddr = Mux(ll_wen, ll_waddr, wb_waddr)
  val rf_wdata = Mux(dmem_resp_valid && dmem_resp_xpu, Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), lsl_resp_data, io.dmem.resp.bits.data(xLen-1, 0)),
                  Mux(ll_wen, ll_wdata,
                  Mux(wb_ctrl.csr =/= CSR.N, Mux((checker_mode.asBool || checker_priv_mode.asBool) && wb_csr, lsl_resp_data_csr, csr.io.rw.rdata),
                  Mux(wb_ctrl.mul, mul.map(_.io.resp.bits.data).getOrElse(wb_reg_wdata),
                  wb_reg_wdata))))


  dontTouch(rf_wdata)
  dontTouch(ll_wdata)
  dontTouch(rf_wen)
  dontTouch(ll_wen)
  dontTouch(rf_waddr)
  dontTouch(ll_waddr)
  
  // lsl_req_valid_csr := Mux(rf_wen, 
  //                      Mux(dmem_resp_valid && dmem_resp_xpu, false.B,
  //                      Mux(ll_wen, false.B,
  //                      Mux(wb_ctrl.csr =/= CSR.N, Mux(checker_mode.asBool && wb_csr, true.B, false.B), false.B))), false.B)
  lsl_req_valid_csr := Mux(rf_wen, 
                       Mux(dmem_resp_valid && dmem_resp_xpu, false.B,
                       Mux(ll_wen, false.B,
                       Mux(wb_ctrl.csr =/= CSR.N, Mux((checker_mode.asBool || checker_priv_mode.asBool) && wb_csr, true.B, false.B), false.B))), false.B)
  lsl_req_valid_csr_test := Mux(rf_wen, 
                            Mux(dmem_resp_valid && dmem_resp_xpu, false.B,
                            Mux(ll_wen, false.B,
                            Mux(wb_ctrl.csr =/= CSR.N, Mux((checker_mode.asBool || checker_priv_mode.asBool) && wb_csr && !wb_reg_inst(31, 20).isOneOf(CSRshadows.csrshadow_seq), true.B, false.B), false.B))), false.B)  
  dontTouch(lsl_req_valid_csr_test)          
  dontTouch(lsl_req_valid_csr)
  // ROCC: in checker mode, only forward writeback-type ROCC (ROCC_INSTRUCTION_D/DS/DSS)
  lsl_req_valid_rocc := io.rocc.resp.fire() && (checker_mode.asBool || checker_priv_mode.asBool) && wb_ctrl.rocc && wb_ctrl.wxd         
  // when (rf_wen) { rf.write(rf_waddr, rf_wdata) }
  //===== GuardianCouncil Function: End   ====//
//===== GuardianCouncil Function: Start ====//
  /* R Features */
  val arfs_shadow = Reg(Vec(32, UInt(xLen.W)))


  // Instantiate RSU
  val priv_status  = Reg(UInt(2.W))
  val check_priv   = Reg(UInt(2.W))
  val check_ret_priv = Reg(UInt(2.W))
  val arfs_is_CSR  = (io.packet_arfs(135+1) === 0x01.U) && (io.packet_arfs(138+1, 136+1) === 0x07.U)
  val arfs_is_ARFS = (io.packet_arfs(138+1, 136+1) === 0x07.U) && (io.packet_arfs(135+1) === 0x00.U)
  

  val priv_cps_done = io.arfs_if_CPS.asBool && arfs_is_CSR && (io.packet_arfs(134-1, 128) === 7.U) && (io.packet_arfs(135, 134) =/= 0.U)
  priv_status := Mux(priv_cps_done, 1.U, Mux(check_exception, 0.U, priv_status))
  check_priv  := Mux(io.arfs_if_CPS.asBool && arfs_is_CSR, io.packet_arfs(135, 134), Mux(check_exception, 0.U, check_priv))
  check_ret_priv := Mux(!io.arfs_if_CPS.asBool && arfs_is_CSR, io.packet_arfs(135, 134), Mux(csr.io.if_priv_checkcomp, 0.U, check_ret_priv))

  check_exception := (RegNext(priv_cps_done) && !excpt_mode) || ((priv_status === 1.U) && RegNext(csr.io.eret))
  check_privret   := RegNext(icsl.io.if_check_privret)
  csr.io.checker_priv_mode := checker_priv_mode.asBool
  csr.io.checker_mode := checker_mode.asBool
  csr.io.arfs_is_CSR  := arfs_is_CSR
  csr.io.arfs_is_CPS  := io.arfs_if_CPS.asBool
  csr.io.csr_shadows  := Mux(arfs_is_CSR, io.packet_arfs(127, 0), 0.U)
  csr.io.shadow_idx   := Mux(arfs_is_CSR, io.packet_arfs(134-1, 128), 0.U)
  csr.io.check_priv   := check_priv
  csr.io.check_ret_priv := check_ret_priv
  csr.io.check_exception := check_exception
  csr.io.check_priv_ret := check_privret
  csr.io.check_epc    := pc_special
  csr.io.check_tvec   := rsu_pc
  csr.io.ic_check_done := icsl.io.if_check_done && !(!div.io.req.ready || io.fpu.fpu_inflight)
  csr.io.clear_ic_status := icsl.io.clear_ic_status.asBool
  val self_xcpt_flag = RegInit(0.U(3.W))
  val self_eret_flag = RegInit(0.U(3.W))
  self_xcpt_flag := Mux(csr.io.trace(0).exception && excpt_mode, self_xcpt_flag + 1.U, Mux(!excpt_mode, 0.U, self_xcpt_flag))
  self_eret_flag := Mux(csr.io.eret && excpt_mode, self_eret_flag + 1.U, Mux(!excpt_mode, 0.U, self_eret_flag))
  when(csr.io.trace(0).exception){
    excpt_mode := true.B
  }.elsewhen(csr.io.eret && (self_eret_flag === self_xcpt_flag)){
    excpt_mode := false.B
  }
  dontTouch(csr.io)
  dontTouch(check_exception)
  dontTouch(check_privret)
  // rsu_slave.io.id_raddr := VecInit(id_raddr)
  rsu_slave.io.excpt := csr.io.trace(0).exception
  rsu_slave.io.eret  := csr.io.eret
  rsu_slave.io.arfs_if_CPS := io.arfs_if_CPS
  rsu_slave.io.arfs_if_ARFS := Mux(arfs_is_ARFS, 1.U, 0.U)
  rsu_slave.io.arfs_index := Mux(arfs_is_ARFS, io.packet_arfs(134-1, 128), 0.U)
  rsu_slave.io.arfs_merge := Mux(arfs_is_ARFS, io.packet_arfs(127, 0), 0.U)
  rsu_slave.io.check_done := icsl.io.if_check_done
  rsu_slave.io.check_priv := Mux(arfs_is_CSR, io.packet_arfs(135, 134), 0.U)
  val rf_wen_rsu = WireInit(0.U(1.W))
  rf_wen_rsu := rsu_slave.io.arfs_valid_out
  rsu_pc := rsu_slave.io.pcarf_out
  io.rsu_status := rsu_slave.io.rsu_status
  rsu_slave.io.do_cp_check := icsl.io.if_check_done.asUInt & (rsu_slave.io.rsu_status === 3.U).asUInt & (!(!div.io.req.ready || io.fpu.fpu_inflight)).asUInt

  for (i <-0 until 32){
    rsu_slave.io.core_arfs_in(i) := rf.read(i.U)
    rsu_slave.io.core_farfs_in(i) := io.fpu.farfs(i)
  }
  rsu_slave.io.elu_cp_deq := Mux(io.elu_sel.asBool && io.elu_deq.asBool, 1.U, 0.U)
  rsu_slave.io.core_trace := io.core_trace
  csr.io.core_trace := io.core_trace

  csr.io.pfarf_valid := rsu_slave.io.pfarf_valid_out
  csr.io.fcsr_in := rsu_slave.io.fcsr_out

  // Added one cycle delay to ensure the RCU being operated at commited stage 
  // Avodiing uninteded reg write after arf_copy
  val arf_paste_reg = RegInit(0.U(1.W))
  val start_check   = RegInit(false.B)
  arf_paste_reg := io.arf_copy_in
  rsu_slave.io.paste_arfs := arf_paste_reg | check_exception.asUInt
  rsu_slave.io.clear_ic_status := icsl.io.clear_ic_status
  rsu_slave.io.record_context := io.record_and_store(1)
  rsu_slave.io.store_from_checker := io.record_and_store(0)
  rsu_slave.io.core_id := io.hartid

  rsu_slave.io.rf_wen := rf_wen
  rsu_slave.io.rf_waddr := rf_waddr
  rsu_slave.io.rf_wdata := rf_wdata
  rsu_slave.io.checker_mode := checker_mode.asBool || checker_priv_mode.asBool
  icsl.io.core_id := io.hartid
  when(checker_mode.asBool || checker_priv_mode.asBool){
    start_check := true.B
  }.elsewhen(rsu_slave.io.store_from_checker.asBool){
    start_check := false.B
  }
  // Instantiate ICSL
  val r_exception_record = RegInit(0.U(1.W))
  r_exception_record := Mux(csr.io.r_exception.asBool, 1.U, Mux(csr.io.trace(0).valid && !csr.io.trace(0).exception && r_exception_record.asBool, 0.U, r_exception_record))


  icsl.io.ic_counter := io.ic_counter(15,0)
  icsl.io.main_core_status := io.ic_counter(19,16)
  icsl.io.icsl_run := arf_paste_reg & (~io.record_and_store(0))
  icsl.io.new_commit := csr.io.trace(0).valid && !csr.io.trace(0).exception
  icsl.io.if_correct_process := io.if_correct_process & !excpt_mode.asUInt
  checker_mode := icsl.io.icsl_checkermode
  checker_priv_mode := icsl.io.icsl_checkerpriv_mode
  io.clear_ic_status := RegNext(icsl.io.clear_ic_status)
  icsl_if_overtaking := (icsl.io.if_overtaking | rsu_slave.io.core_hang_up) & !r_exception_record
  icsl_if_ret_special_pc := icsl.io.if_ret_special_pc
  if_overtaking_next_cycle := icsl.io.if_overtaking_next_cycle
  val returned_to_special_address_valid = Wire(Bool())
  icsl.io.returned_to_special_address_valid := returned_to_special_address_valid
  icsl.io.if_check_completed := rsu_slave.io.if_cp_check_completed
  icsl.io.core_trace := io.core_trace
  icsl.io.if_check_privrun := RegNext(check_exception)
  icsl.io.self_xcpt := csr.io.trace(0).exception
  icsl.io.self_ret  := csr.io.eret

  val zeros_3bits = WireInit(0.U(3.W))

  val icsl_if_valid = WireInit(0.U(4.W))
  val icsl_ex_valid = WireInit(0.U(4.W))
  val icsl_mem_valid = WireInit(0.U(4.W))
  val icsl_wb_valid = WireInit(0.U(4.W))

  icsl_if_valid := Cat(zeros_3bits, !ctrl_killd.asUInt)
  icsl_ex_valid := Cat(zeros_3bits, ex_reg_valid.asUInt)
  icsl_mem_valid := Cat(zeros_3bits, mem_reg_valid.asUInt)
  icsl_wb_valid := Cat(zeros_3bits, wb_reg_valid.asUInt)
  icsl.io.num_valid_insts_in_pipeline := icsl_if_valid + icsl_ex_valid + icsl_mem_valid + icsl_wb_valid
  
  icsl.io.debug_perf_reset := io.debug_perf_ctrl(0)
  icsl.io.debug_perf_sel := io.debug_perf_ctrl(4,1)
  val debug_perf_reset = WireInit(0.U(1.W))
  val debug_perf_sel = WireInit(0.U(4.W))
  val debug_perf_val = WireInit(0.U(64.W))
  


  icsl.io.debug_perf_reset := io.debug_perf_ctrl(0)
  icsl.io.debug_perf_sel := io.debug_perf_ctrl(4,1)
  // icsl.io.icsl_ack       := io.icsl_ack
  icsl.io.big_switch     := io.big_switch
  icsl.io.cdc_empty      := io.cdc_empty
  icsl.io.lsl_empty      := lsl.io.if_empty
  icsl.io.excpt_mode     := excpt_mode
  // io.if_big_complete     := icsl.io.if_big_complete 
  // icsl.io.big_complete   := io.big_complete    
  /*
  debug_perf_reset := io.debug_perf_ctrl(0)
  debug_perf_sel := io.debug_perf_ctrl(4,1)
  */
  
  icsl.io.debug_starting_CPS := rsu_slave.io.starting_CPS
  icsl.io.st_deq := checker_store_complete
  icsl.io.ld_deq := checker_load_complete
  icsl.io.st_cache_deq := checker_store_cache_complete
  icsl.io.st_uncache_deq := checker_store_uncache_complete
  icsl.io.ld_cache_deq := checker_load_cache_complete
  icsl.io.ld_uncache_deq := checker_load_uncache_complete
  icsl.io.lr_deq := checker_lr_complete
  icsl.io.sc_success_deq := checker_sc_success_complete
  icsl.io.sc_fail_deq := checker_sc_fail_complete
  icsl.io.amo_cache_deq := checker_amo_cache_complete
  icsl.io.amo_uncache_deq := checker_amo_uncache_complete
  io.traffic_counter := icsl.io.traffic_counter
  // kill_each_pipe := icsl.io.kill_pipe
  val lsl_index = WireInit(VecInit.fill(GH_GlobalParams.GH_TOTAL_PACKETS)(0.U(8.W)))
  for(i <- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
    lsl_index(i)          := io.packet_lsl(i)(GH_GlobalParams.GH_WIDITH_PACKETS-1,GH_GlobalParams.GH_WIDITH_PACKETS-8)
    // Instantiate LSL
    lsl.io.m_st_valid(i)  := lsl_index(i)(2,0)=== 2.U
    lsl.io.m_ld_valid(i)  := lsl_index(i)(2,0)=== 1.U
    lsl.io.m_csr_valid(i) := lsl_index(i)(2,0)=== 3.U
    lsl.io.m_csr_data(i)  := io.packet_lsl(i)(63, 0)
    lsl.io.m_rocc_valid(i) := lsl_index(i)(2,0)=== 5.U
    lsl.io.m_rocc_data(i)  := io.packet_lsl(i)(63, 0)
    lsl.io.m_ldst_data(i) := io.packet_lsl(i)(127,64)
    lsl.io.m_ldst_addr(i) := io.packet_lsl(i)(63,0)
  }

  lsl_req_ready     := lsl.io.req_ready
  lsl.io.req_valid  := lsl_req_valid
  lsl.io.req_addr   := lsl_req_addr
  lsl.io.req_tag    := lsl_req_tag
  lsl.io.req_cmd    := lsl_req_cmd
  lsl.io.req_data   := lsl_req_data
  lsl.io.req_size   := lsl_req_size
  lsl.io.req_kill   := lsl_req_kill
  lsl.io.req_valid_csr := lsl_req_valid_csr
  lsl.io.req_valid_rocc := lsl_req_valid_rocc

  lsl_resp_valid := lsl.io.resp_valid
  lsl_resp_tag := lsl.io.resp_tag
  lsl_resp_size := lsl.io.resp_size
  lsl_resp_addr := lsl.io.resp_addr
  lsl_resp_cacheable := lsl.io.resp_cacheable
  lsl_resp_data := lsl.io.resp_data
  lsl_resp_has_data := lsl.io.resp_has_data
  lsl_resp_replay := lsl.io.resp_replay
  io.log_near_full := lsl.io.near_full.asUInt | io.imem.bjl_nearfull.asUInt
  io.log_highwatermark := lsl.io.lsl_highwatermark.asUInt | io.imem.bjl_highwatermark.asUInt
  lsl_resp_data_csr := lsl.io.resp_data_csr
  lsl_req_ready_csr := lsl.io.req_ready_csr
  lsl_resp_data_rocc := lsl.io.resp_data_rocc
  lsl_req_ready_rocc := lsl.io.req_ready_rocc

  // Instantiate ELU
  val elu = Module(new R_ELU(R_ELUParams(4, xLen, 40)))
  elu.io.lsl_req_valid := lsl_req_valid
  elu.io.lsl_req_addr := lsl_req_addr
  elu.io.lsl_req_cmd := lsl_req_cmd
  elu.io.lsl_req_data := lsl_req_data
  elu.io.lsl_req_ready := lsl_req_ready
  elu.io.lsl_req_kill := lsl_req_kill
  elu.io.lsl_req_size := lsl_req_size
  elu.io.lsl_resp_valid := lsl_resp_valid
  elu.io.lsl_resp_addr := lsl_resp_addr
  elu.io.lsl_resp_data := lsl_resp_data
  elu.io.wb_pc := Mux(wb_reg_valid, wb_reg_pc, 0.U)
  elu.io.wb_inst := Mux(wb_reg_valid, wb_reg_inst, 0.U)

  // io.elu_data := Mux(io.elu_sel.asBool, rsu_slave.io.elu_cp_data, elu.io.elu_data)
  // Faking ELU data
  // io.elu_data := debug_perf_val
  io.elu_data := icsl.io.debug_perf_val

  io.elu_status := Cat(rsu_slave.io.elu_status, elu.io.elu_status)
  elu.io.elu_deq := Mux(!io.elu_sel.asBool && io.elu_deq.asBool, 1.U, 0.U)
  elu.io.lsl_resp_addr := lsl_resp_addr
  elu.io.core_trace := io.core_trace


  when (rf_wen_rsu === 1.U) {
    rf.write(rsu_slave.io.arfs_idx_out, rsu_slave.io.arfs_out)
    arfs_shadow(rsu_slave.io.arfs_idx_out) := rsu_slave.io.arfs_out
  } .elsewhen (rf_wen) {
    rf.write(rf_waddr, rf_wdata)
    arfs_shadow(rf_waddr) := rf_wdata
  }
  when(start_check && RegNext(csr.io.trace(0).exception)){
    rf.write(2.U, rsu_slave.io.rf_sp)
    rf.write(3.U, rsu_slave.io.rf_gp)
  }.elsewhen(start_check && RegNext(csr.io.eret) && (checker_mode.asBool || checker_priv_mode.asBool)){
    rf.write(2.U, rsu_slave.io.rf_sp)
    rf.write(3.U, rsu_slave.io.rf_gp)
  }

  dontTouch(rf_wen_rsu)

  io.packet_cdc_ready := rsu_slave.io.cdc_ready | lsl.io.cdc_ready.asUInt | io.imem.bjl_cdc_ready.asUInt
  //===== GuardianCouncil Function: End   ====//

  dontTouch(csr.io.counters)
  // hook up control/status regfile
  csr.io.ungated_clock := clock
  csr.io.decode(0).inst := id_inst(0)
  csr.io.exception := wb_xcpt
  csr.io.cause := wb_cause
  csr.io.retire := wb_valid
  csr.io.inst(0) := (if (usingCompressed) Cat(Mux(wb_reg_raw_inst(1, 0).andR, wb_reg_inst >> 16, 0.U), wb_reg_raw_inst(15, 0)) else wb_reg_inst)
  csr.io.interrupts := io.interrupts
  csr.io.hartid := io.hartid
  io.fpu.fcsr_rm := csr.io.fcsr_rm
  csr.io.fcsr_flags := io.fpu.fcsr_flags
  io.fpu.time := csr.io.time(31,0)
  io.fpu.hartid := io.hartid
  csr.io.rocc_interrupt := io.rocc.interrupt
  csr.io.pc := wb_reg_pc
  val tval_dmem_addr = !wb_reg_xcpt
  val tval_any_addr = tval_dmem_addr ||
    wb_reg_cause.isOneOf(Causes.breakpoint.U, Causes.fetch_access.U, Causes.fetch_page_fault.U, Causes.fetch_guest_page_fault.U)
  val tval_inst = wb_reg_cause === Causes.illegal_instruction.U
  val tval_valid = wb_xcpt && (tval_any_addr || tval_inst)
  csr.io.gva := wb_xcpt && (tval_any_addr && csr.io.status.v || tval_dmem_addr && wb_reg_hls_or_dv)
  csr.io.tval := Mux(tval_valid, encodeVirtualAddress(wb_reg_wdata, wb_reg_wdata), 0.U)
  csr.io.htval := {
    val htval_valid_imem = wb_reg_xcpt && wb_reg_cause === Causes.fetch_guest_page_fault.U
    val htval_imem = Mux(htval_valid_imem, io.imem.gpa.bits, 0.U)
    assert(!htval_valid_imem || io.imem.gpa.valid)

    val htval_valid_dmem = wb_xcpt && tval_dmem_addr && io.dmem.s2_xcpt.gf.asUInt.orR && !io.dmem.s2_xcpt.pf.asUInt.orR
    val htval_dmem = Mux(htval_valid_dmem, io.dmem.s2_gpa, 0.U)

    (htval_dmem | htval_imem) >> hypervisorExtraAddrBits
  }
  io.ptw.ptbr := csr.io.ptbr
  io.ptw.hgatp := csr.io.hgatp
  io.ptw.vsatp := csr.io.vsatp
  (io.ptw.customCSRs.csrs zip csr.io.customCSRs).map { case (lhs, rhs) => lhs := rhs }
  io.ptw.status := csr.io.status
  io.ptw.hstatus := csr.io.hstatus
  io.ptw.gstatus := csr.io.gstatus
  io.ptw.pmp := csr.io.pmp
  val if_sysret = wb_reg_valid && ((wb_reg_inst(31, 20) === 0x30200073.U) || wb_reg_inst(31, 0) === 0x10200073.U)
  csr.io.rw.addr := Mux((checker_priv_mode === 1.U) && if_sysret, 0.U, wb_reg_inst(31,20))
  csr.io.rw.cmd := Mux((checker_priv_mode === 1.U) && if_sysret, 0.U, CSR.maskCmd(wb_reg_valid, wb_ctrl.csr))
  csr.io.rw.wdata := Mux((checker_priv_mode === 1.U) && if_sysret, 0.U, wb_reg_wdata)
  io.trace := csr.io.trace
  for (((iobpw, wphit), bp) <- io.bpwatch zip wb_reg_wphit zip csr.io.bp) {
    iobpw.valid(0) := wphit
    iobpw.action := bp.control.action
  }

  val hazard_targets = Seq((id_ctrl.rxs1 && id_raddr1 =/= 0.U, id_raddr1),
                           (id_ctrl.rxs2 && id_raddr2 =/= 0.U, id_raddr2),
                           (id_ctrl.wxd  && id_waddr  =/= 0.U, id_waddr))
  val fp_hazard_targets = Seq((io.fpu.dec.ren1, id_raddr1),
                              (io.fpu.dec.ren2, id_raddr2),
                              (io.fpu.dec.ren3, id_raddr3),
                              (io.fpu.dec.wen, id_waddr))

  val sboard = new Scoreboard(32, true)
  sboard.clear(ll_wen, ll_waddr)
  def id_sboard_clear_bypass(r: UInt) = {
    // ll_waddr arrives late when D$ has ECC, so reshuffle the hazard check
    if (!tileParams.dcache.get.dataECC.isDefined) ll_wen && ll_waddr === r
    else div.io.resp.fire && div.io.resp.bits.tag === r || dmem_resp_replay && dmem_resp_xpu && dmem_resp_waddr === r
  }
  val id_sboard_hazard = checkHazards(hazard_targets, rd => sboard.read(rd) && !id_sboard_clear_bypass(rd))
  sboard.set(wb_set_sboard && wb_wen, wb_waddr)

  // stall for RAW/WAW hazards on CSRs, loads, AMOs, and mul/div in execute stage.
  val ex_cannot_bypass = ex_ctrl.csr =/= CSR.N || ex_ctrl.jalr || ex_ctrl.mem || ex_ctrl.mul || ex_ctrl.div || ex_ctrl.fp || ex_ctrl.rocc || ex_scie_pipelined
  val data_hazard_ex = ex_ctrl.wxd && checkHazards(hazard_targets, _ === ex_waddr)
  val fp_data_hazard_ex = id_ctrl.fp && ex_ctrl.wfd && checkHazards(fp_hazard_targets, _ === ex_waddr)
  val id_ex_hazard = ex_reg_valid && (data_hazard_ex && ex_cannot_bypass || fp_data_hazard_ex)

  // stall for RAW/WAW hazards on CSRs, LB/LH, and mul/div in memory stage.
  val mem_mem_cmd_bh =
    if (fastLoadWord) (!fastLoadByte).B && mem_reg_slow_bypass
    else true.B
  val mem_cannot_bypass = mem_ctrl.csr =/= CSR.N || mem_ctrl.mem && mem_mem_cmd_bh || mem_ctrl.mul || mem_ctrl.div || mem_ctrl.fp || mem_ctrl.rocc
  val data_hazard_mem = mem_ctrl.wxd && checkHazards(hazard_targets, _ === mem_waddr)
  val fp_data_hazard_mem = id_ctrl.fp && mem_ctrl.wfd && checkHazards(fp_hazard_targets, _ === mem_waddr)
  val id_mem_hazard = mem_reg_valid && (data_hazard_mem && mem_cannot_bypass || fp_data_hazard_mem)
  id_load_use := mem_reg_valid && data_hazard_mem && mem_ctrl.mem

  // stall for RAW/WAW hazards on load/AMO misses and mul/div in writeback.
  val data_hazard_wb = wb_ctrl.wxd && checkHazards(hazard_targets, _ === wb_waddr)
  val fp_data_hazard_wb = id_ctrl.fp && wb_ctrl.wfd && checkHazards(fp_hazard_targets, _ === wb_waddr)
  val id_wb_hazard = wb_reg_valid && (data_hazard_wb && wb_set_sboard || fp_data_hazard_wb)

  val id_stall_fpu = if (usingFPU) {
    val fp_sboard = new Scoreboard(32)
    fp_sboard.set((wb_dcache_miss && wb_ctrl.wfd || io.fpu.sboard_set) && wb_valid, wb_waddr)
    fp_sboard.clear(dmem_resp_replay && dmem_resp_fpu, dmem_resp_waddr)
    fp_sboard.clear(io.fpu.sboard_clr, io.fpu.sboard_clra)

    checkHazards(fp_hazard_targets, fp_sboard.read _)
  } else false.B

  val dcache_blocked = {
    // speculate that a blocked D$ will unblock the cycle after a Grant
    val blocked = Reg(Bool())
    blocked := !io.dmem.req.ready && io.dmem.clock_enabled && !io.dmem.perf.grant && (blocked || io.dmem.req.valid || io.dmem.s2_nack)
    blocked && !io.dmem.perf.grant
  }
  val rocc_blocked = Reg(Bool())
  rocc_blocked := !wb_xcpt && !io.rocc.cmd.ready && (io.rocc.cmd.valid || rocc_blocked)

  val ctrl_stalld =
    //===== GuardianCouncil Function: Start ====//
    // Original design:
    // id_ex_hazard || id_mem_hazard || id_wb_hazard || id_sboard_hazard ||
    // In GuardianCouncil, RoCC response can be replied in a single cycle, therefore RoCC does not cause a hazzard
    rsu_slave.io.core_hang_up.asBool || id_ex_hazard || (id_mem_hazard) || (id_wb_hazard && !wb_ctrl.rocc) || id_sboard_hazard ||
    //===== GuardianCouncil Function: End   ====//
    //id_ex_hazard || id_mem_hazard || id_wb_hazard || id_sboard_hazard ||
    csr.io.singleStep && (ex_reg_valid || mem_reg_valid || wb_reg_valid) ||
    id_csr_en && csr.io.decode(0).fp_csr && !io.fpu.fcsr_rdy ||
    id_ctrl.fp && id_stall_fpu ||
    id_ctrl.mem && dcache_blocked || // reduce activity during D$ misses
    id_ctrl.rocc && rocc_blocked || // reduce activity while RoCC is busy
    id_ctrl.div && (!(div.io.req.ready || (div.io.resp.valid && !wb_wxd)) || div.io.req.valid) || // reduce odds of replay
    !clock_en ||
    id_do_fence ||
    csr.io.csr_stall ||
    id_reg_pause ||
    io.traceStall ||
    !io.clk_enable_gh ||
    icsl.io.icsl_stalld
  
  ctrl_killd := !ibuf.io.inst(0).valid || ibuf.io.inst(0).bits.replay || take_pc_mem_wb || ctrl_stalld || csr.io.interrupt 
  dontTouch(ctrl_stalld)
  dontTouch(id_ex_hazard)
  dontTouch(id_mem_hazard)
  dontTouch(id_wb_hazard)
  dontTouch(id_sboard_hazard)
  dontTouch(id_stall_fpu)

  val load_use_RAW = id_ex_hazard && ex_ctrl.mem || id_mem_hazard && mem_ctrl.mem || id_wb_hazard && wb_ctrl.mem
  dontTouch(load_use_RAW)
  val RAW_counter = RegInit(0.U(32.W))
  RAW_counter := Mux(load_use_RAW && (checker_mode.asBool || checker_priv_mode.asBool), RAW_counter + 1.U, RAW_counter)
  dontTouch(RAW_counter)
  val RAW_Cnt = Counter(load_use_RAW && (checker_mode.asBool || checker_priv_mode.asBool), 100000000)
  dontTouch(RAW_Cnt._1)
  dontTouch(RAW_Cnt._2)

  io.RAW_cnt := RAW_counter

  //===== GuardianCouncil Function: Start ====//
  val debug_perf_blocking_CP                      = RegInit(0.U(64.W))
  val debug_perf_blocking_id_ex_h                 = RegInit(0.U(64.W))
  val debug_perf_blocking_id_mem_h                = RegInit(0.U(64.W))
  val debug_perf_blocking_id_wb_h                 = RegInit(0.U(64.W))
  val debug_perf_blocking_id_sb_h                 = RegInit(0.U(64.W))
  val debug_perf_blocking_CSR_S                   = RegInit(0.U(64.W))
  val debug_perf_blocking_FP                      = RegInit(0.U(64.W))
  val debug_perf_blocking_MEM                     = RegInit(0.U(64.W))
  val debug_perf_blocking_DIV                     = RegInit(0.U(64.W))
  val debug_perf_blocking_FENCE                   = RegInit(0.U(64.W))
  val debug_perf_blocking_ST                      = RegInit(0.U(64.W))
  val checker_blocked                             = (icsl.io.checker_core_status === 1.U) && ctrl_stalld
  val fpu_or_div_not_busy                         = !(id_ctrl.fp && id_stall_fpu) && !(id_ctrl.div && (!(div.io.req.ready || (div.io.resp.valid && !wb_wxd)) || div.io.req.valid))
  debug_perf_blocking_CP                         := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && rsu_slave.io.core_hang_up.asBool, debug_perf_blocking_CP + 1.U, debug_perf_blocking_CP))
  debug_perf_blocking_id_ex_h                    := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_ex_hazard && fpu_or_div_not_busy, debug_perf_blocking_id_ex_h + 1.U, debug_perf_blocking_id_ex_h))
  debug_perf_blocking_id_mem_h                   := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_mem_hazard && fpu_or_div_not_busy, debug_perf_blocking_id_mem_h + 1.U, debug_perf_blocking_id_mem_h))
  debug_perf_blocking_id_wb_h                    := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_wb_hazard && fpu_or_div_not_busy, debug_perf_blocking_id_wb_h + 1.U, debug_perf_blocking_id_wb_h))
  debug_perf_blocking_id_sb_h                    := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_sboard_hazard && fpu_or_div_not_busy, debug_perf_blocking_id_sb_h + 1.U, debug_perf_blocking_id_sb_h))
  debug_perf_blocking_CSR_S                      := 0.U
  debug_perf_blocking_FP                         := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_ctrl.fp && id_stall_fpu, debug_perf_blocking_FP + 1.U, debug_perf_blocking_FP))
  debug_perf_blocking_MEM                        := 0.U
  debug_perf_blocking_DIV                        := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_ctrl.div && (!(div.io.req.ready || (div.io.resp.valid && !wb_wxd)) || div.io.req.valid), debug_perf_blocking_DIV + 1.U, debug_perf_blocking_DIV))
  debug_perf_blocking_FENCE                      := Mux(debug_perf_reset.asBool, 0.U, Mux(checker_blocked && id_do_fence, debug_perf_blocking_FENCE + 1.U, debug_perf_blocking_FENCE))
  debug_perf_blocking_ST                         := 0.U

  debug_perf_val                                := Mux(debug_perf_sel === 7.U, debug_perf_blocking_CP, 
                                                   Mux(debug_perf_sel === 1.U, debug_perf_blocking_id_ex_h,
                                                   Mux(debug_perf_sel === 2.U, debug_perf_blocking_id_mem_h,
                                                   Mux(debug_perf_sel === 3.U, debug_perf_blocking_id_wb_h,
                                                   Mux(debug_perf_sel === 4.U, debug_perf_blocking_id_sb_h, 
                                                   Mux(debug_perf_sel === 5.U, debug_perf_blocking_CSR_S,
                                                   Mux(debug_perf_sel === 6.U, debug_perf_blocking_FP,
                                                   Mux(debug_perf_sel === 8.U, debug_perf_blocking_MEM,
                                                   Mux(debug_perf_sel === 9.U, debug_perf_blocking_DIV, 
                                                   Mux(debug_perf_sel === 11.U, debug_perf_blocking_FENCE,
                                                   Mux(debug_perf_sel === 10.U, debug_perf_blocking_ST, 0.U)))))))))))
  returned_to_special_address_valid := (wb_valid || io.rocc.resp.valid) && (wb_reg_pc === pc_special)
  
  io.imem.bjl_commit := wb_valid && (wb_ctrl.jal || wb_ctrl.jalr || wb_ctrl.branch)
  io.imem.if_check_completed := (icsl.io.debug_state === 6.U) || (icsl.io.debug_state === 7.U)
  io.imem.if_overtaking := icsl.io.icsl_stalld && (icsl.io.debug_state === 2.U) || (icsl.io.debug_state === 3.U)
  io.imem.if_check_already_done := icsl.io.already_done
  io.imem.req.valid := take_pc
  io.imem.req.bits.speculative := !take_pc_wb && !checker_mode.asBool
  io.imem.req.bits.pc :=
    Mux(wb_xcpt || csr.io.eret || check_exception || check_privret, csr.io.evec, // exception or [m|s]ret
    Mux(replay_wb,  wb_reg_pc,   // replay
    Mux(icsl_if_ret_special_pc.asBool, pc_special, mem_npc)))   // flush or branch misprediction
  io.imem.flush_icache := wb_reg_valid && wb_ctrl.fence_i && (Mux(checker_mode === 1.U || checker_priv_mode === 1.U, false.B, !io.dmem.s2_nack))
  io.imem.might_request := {
    imem_might_request_reg := ex_pc_valid || mem_pc_valid || io.ptw.customCSRs.disableICacheClockGate || true.B  // We do not wish the IMM to sleep as it can have a replay at any time!
    imem_might_request_reg
  }
  io.imem.sfence.valid := wb_reg_valid && wb_reg_sfence
  io.imem.sfence.bits.rs1 := wb_reg_mem_size(0)
  io.imem.sfence.bits.rs2 := wb_reg_mem_size(1)
  io.imem.sfence.bits.addr := wb_reg_wdata
  io.imem.sfence.bits.asid := wb_reg_rs2
  io.imem.sfence.bits.hv := wb_reg_hfence_v
  io.imem.sfence.bits.hg := wb_reg_hfence_g
  io.ptw.sfence := io.imem.sfence

  ibuf.io.inst(0).ready := !ctrl_stalld

  io.imem.btb_update.valid := mem_reg_valid && !take_pc_wb && mem_wrong_npc && (!mem_cfi || mem_cfi_taken)
  io.imem.btb_update.bits.isValid := mem_cfi
  io.imem.btb_update.bits.cfiType :=
    Mux((mem_ctrl.jal || mem_ctrl.jalr) && mem_waddr(0), CFIType.call,
    Mux(mem_ctrl.jalr && (mem_reg_inst(19,15) & regAddrMask.U) === BitPat("b00?01"), CFIType.ret,
    Mux(mem_ctrl.jal || mem_ctrl.jalr, CFIType.jump,
    CFIType.branch)))
  io.imem.btb_update.bits.target := io.imem.req.bits.pc
  io.imem.btb_update.bits.br_pc := (if (usingCompressed) mem_reg_pc + Mux(mem_reg_rvc, 0.U, 2.U) else mem_reg_pc)
  io.imem.btb_update.bits.pc := ~(~io.imem.btb_update.bits.br_pc | (coreInstBytes*fetchWidth-1).U)
  io.imem.btb_update.bits.prediction := mem_reg_btb_resp

  io.imem.bht_update.valid := mem_reg_valid && !take_pc_wb
  io.imem.bht_update.bits.pc := io.imem.btb_update.bits.pc
  io.imem.bht_update.bits.taken := mem_br_taken
  io.imem.bht_update.bits.mispredict := mem_wrong_npc
  io.imem.bht_update.bits.branch := mem_ctrl.branch
  io.imem.bht_update.bits.prediction := mem_reg_btb_resp.bht
  io.imem.checker_mode := checker_mode.asBool || checker_priv_mode.asBool

  io.fpu.valid := !ctrl_killd && id_ctrl.fp
  io.fpu.killx := ctrl_killx
  io.fpu.killm := killm_common
  io.fpu.inst := id_inst(0)
  io.fpu.fromint_data := ex_rs(0)
  /* R Features */
  io.fpu.dmem_resp_val := dmem_resp_valid && dmem_resp_fpu
  io.fpu.dmem_resp_data := Mux(checker_mode === 1.U || checker_priv_mode === 1.U, lsl_resp_data, io.dmem.resp.bits.data_word_bypass)
  io.fpu.dmem_resp_type := Mux(checker_mode === 1.U || checker_priv_mode === 1.U, lsl_resp_size, io.dmem.resp.bits.size)
  io.fpu.dmem_resp_tag := dmem_resp_waddr
  io.fpu.keep_clock_enabled := io.ptw.customCSRs.disableCoreClockGate
  
  io.fpu.r_farf_bits := rsu_slave.io.farfs_out
  io.fpu.r_farf_idx := rsu_slave.io.arfs_idx_out
  io.fpu.r_farf_valid := rsu_slave.io.arfs_valid_out
  io.fpu.retire := wb_valid || io.rocc.resp.valid
  io.fpu.checker_mode := checker_mode.asBool
  io.fpu.checker_priv_mode := checker_priv_mode.asBool
  io.fpu.core_trace := io.core_trace.asBool
  io.fpu.if_overtaking := icsl.io.if_overtaking
  io.fpu.if_overtaking_next_cycle := icsl.io.if_overtaking_next_cycle
  icsl.io.something_inflight := !div.io.req.ready || io.fpu.fpu_inflight
  
  // Simply tied-off the signals sent to D$, when the core is in the checker mode.
  // It might be fine only mask the io.dmem.req.valid, but for safety -- let us amsk all dmem.req signals.
  val checker_mode_1cycle_delay = Reg(UInt())
  val checker_priv_mode_1cycle_delay = Reg(UInt())
  checker_mode_1cycle_delay := checker_mode
  checker_priv_mode_1cycle_delay := checker_priv_mode

  io.dmem.req.valid     := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, ex_reg_valid && ex_ctrl.mem)
  val ex_dcache_tag      = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, Cat(ex_waddr, ex_ctrl.fp))
  require(coreParams.dcacheReqTagBits >= ex_dcache_tag.getWidth)
  io.dmem.req.bits.tag  := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, ex_dcache_tag)
  io.dmem.req.bits.cmd  := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, ex_ctrl.mem_cmd)
  io.dmem.req.bits.size := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, ex_reg_mem_size)
  io.dmem.req.bits.signed := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, !Mux(ex_reg_hls, ex_reg_inst(20), ex_reg_inst(14)))
  io.dmem.req.bits.phys := (false).B
  io.dmem.req.bits.addr := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, encodeVirtualAddress(ex_rs(0), alu.io.adder_out))
  io.dmem.req.bits.idx.foreach(_ := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, io.dmem.req.bits.addr))
  io.dmem.req.bits.dprv := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, Mux(ex_reg_hls, csr.io.hstatus.spvp, csr.io.status.dprv))
  io.dmem.req.bits.dv := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, ex_reg_hls || csr.io.status.dv)
  io.dmem.s1_data.data := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), 0.U, (if (fLen == 0) mem_reg_rs2 else Mux(mem_ctrl.fp, Fill((xLen max fLen) / fLen, io.fpu.store_data), mem_reg_rs2)))
  io.dmem.s1_kill := Mux(((checker_mode === 1.U) && (checker_mode_1cycle_delay === 1.U)) || ((checker_priv_mode === 1.U) && (checker_priv_mode_1cycle_delay === 1.U)), 0.U, killm_common || mem_ldst_xcpt || fpu_kill_mem)
  io.dmem.s2_kill := false.B

  if (GH_GlobalParams.GH_DEBUG == 1) {
    val mem_valid = Reg(UInt())
    val mem_addr = Reg(UInt())
    val mem_data = Reg(UInt())
    val mem_cmd = Reg(UInt())
    val mem_s1_kill = Wire(UInt())
    mem_valid := Mux(checker_mode === 1.U, 0.U, ex_reg_valid && ex_ctrl.mem)
    mem_addr := Mux(checker_mode === 1.U, 0.U, encodeVirtualAddress(ex_rs(0), alu.io.adder_out))
    mem_data := Mux(checker_mode === 1.U, 0.U, (if (fLen == 0) mem_reg_rs2 else Mux(mem_ctrl.fp, Fill((xLen max fLen) / fLen, io.fpu.store_data), mem_reg_rs2)))
    mem_cmd := Mux(checker_mode === 1.U, 0.U, ex_ctrl.mem_cmd)
    mem_s1_kill := Mux(checker_mode === 1.U, 0.U, killm_common || mem_ldst_xcpt || fpu_kill_mem)

    when (io.core_trace.asBool && (mem_valid === 1.U) && (mem_s1_kill =/= 1.U)){
      printf(midas.targetutils.SynthesizePrintf("C%d: %d-%x, addr-%x, data-%x, ",
      io.hartid, checker_mode, mem_cmd, mem_addr, mem_data))
    }
  }

  lsl_req_valid             := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), (mem_reg_valid && mem_ctrl.mem), 0.U)
  val mem_dcache_tag         = Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), Cat(mem_waddr, mem_ctrl.fp), 0.U)
  lsl_req_tag               := mem_dcache_tag
  val alu_adder_out          = Reg(UInt())
  val mem_rs0                = Reg(UInt())
  alu_adder_out             := alu.io.adder_out
  mem_rs0                   := ex_rs(0)
  lsl_req_addr              := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), encodeVirtualAddress(mem_rs0, alu_adder_out), 0.U)
  lsl_req_cmd               := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), Cat(isWrite(mem_ctrl.mem_cmd).asUInt, isRead(mem_ctrl.mem_cmd).asUInt), 0.U)
  lsl_req_size              := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), mem_reg_mem_size, 0.U)
  lsl_req_data              := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), (if (fLen == 0) mem_reg_rs2 else Mux(mem_ctrl.fp, Fill((xLen max fLen) / fLen, io.fpu.store_data), mem_reg_rs2)), 0.U)
  lsl_req_kill              := Mux((checker_mode === 1.U) || (checker_priv_mode === 1.U), (killm_common || mem_ldst_xcpt || fpu_kill_mem), 0.U)
  io.icsl_status            := Mux((icsl.io.icsl_status === 1.U) && (rsu_slave.io.rsu_status === 0.U) && (lsl.io.if_empty === 1.U), 1.U, 0.U)
  

  // don't let D$ go to sleep if we're probably going to use it soon
  io.dmem.keep_clock_enabled := ibuf.io.inst(0).valid && id_ctrl.mem && !csr.io.csr_stall
  //===== GuardianCouncil Function: End ====//
//===== GuardianCouncil Function: Start ====//  
  io.rocc.cmd.valid := mem_reg_valid && mem_ctrl.rocc && !wb_reg_replay
  io.rocc.exception := mem_xcpt && csr.io.status.xs.orR
  io.rocc.cmd.bits.status := csr.io.status
  io.rocc.cmd.bits.inst := mem_reg_inst.asTypeOf(new RoCCInstruction())
  io.rocc.cmd.bits.rs1 := mem_reg_wdata
  io.rocc.cmd.bits.rs2 := mem_reg_rs2

  io.ght_prv := csr.io.status.prv
  //===== GuardianCouncil Function: End  ====//
  // io.rocc.cmd.valid := wb_reg_valid && wb_ctrl.rocc && !replay_wb_common
  // io.rocc.exception := wb_xcpt && csr.io.status.xs.orR
  // io.rocc.cmd.bits.status := csr.io.status
  // io.rocc.cmd.bits.inst := wb_reg_inst.asTypeOf(new RoCCInstruction())
  // io.rocc.cmd.bits.rs1 := wb_reg_wdata
  // io.rocc.cmd.bits.rs2 := wb_reg_rs2

  // gate the clock
  val unpause = csr.io.time(rocketParams.lgPauseCycles-1, 0) === 0.U || csr.io.inhibit_cycle || io.dmem.perf.release || take_pc
  when (unpause) { id_reg_pause := false.B }
  io.cease := csr.io.status.cease && !clock_en_reg
  io.wfi := csr.io.status.wfi
  if (rocketParams.clockGate) {
    long_latency_stall := csr.io.csr_stall || io.dmem.perf.blocked || id_reg_pause && !unpause
    clock_en := clock_en_reg || ex_pc_valid || (!long_latency_stall && io.imem.resp.valid)
    clock_en_reg :=
      ex_pc_valid || mem_pc_valid || wb_pc_valid || // instruction in flight
      io.ptw.customCSRs.disableCoreClockGate || // chicken bit
      !div.io.req.ready || // mul/div in flight
      usingFPU.B && !io.fpu.fcsr_rdy || // long-latency FPU in flight
      io.dmem.replay_next || // long-latency load replaying
      (!long_latency_stall && (ibuf.io.inst(0).valid || io.imem.resp.valid)) // instruction pending

    assert(!(ex_pc_valid || mem_pc_valid || wb_pc_valid) || clock_en)
  }

  // evaluate performance counters
  val ibuf_notvalid_cnt = RegInit(0.U(64.W))
  ibuf_notvalid_cnt := Mux(!ibuf.io.inst(0).valid && (checker_mode.asBool || checker_priv_mode.asBool), ibuf_notvalid_cnt + 1.U, ibuf_notvalid_cnt)
  dontTouch(ibuf_notvalid_cnt)

  val mispred_cnt = RegInit(0.U(64.W))
  mispred_cnt := Mux((take_pc_mem && mem_misprediction) && (checker_mode.asBool || checker_priv_mode.asBool), mispred_cnt + 1.U, mispred_cnt)
  dontTouch(mispred_cnt)

  val imiss_cnt = RegInit(0.U(64.W))
  imiss_cnt := Mux(io.imem.perf.acquire && (checker_mode.asBool || checker_priv_mode.asBool), imiss_cnt + 1.U, imiss_cnt)
  dontTouch(imiss_cnt)

  val icache_blocked = !(io.imem.resp.valid || RegNext(io.imem.resp.valid))
  csr.io.counters foreach { c => c.inc := RegNext(perfEvents.evaluate(c.eventSel)) }

  val coreMonitorBundle = Wire(new CoreMonitorBundle(xLen, fLen))

  coreMonitorBundle.clock := clock
  coreMonitorBundle.reset := reset
  coreMonitorBundle.hartid := io.hartid
  coreMonitorBundle.timer := csr.io.time(31,0)
  coreMonitorBundle.valid := csr.io.trace(0).valid && !csr.io.trace(0).exception
  coreMonitorBundle.pc := csr.io.trace(0).iaddr(vaddrBitsExtended-1, 0).sextTo(xLen)
  coreMonitorBundle.wrenx := wb_wen && !wb_set_sboard
  coreMonitorBundle.wrenf := false.B
  coreMonitorBundle.wrdst := wb_waddr
  coreMonitorBundle.wrdata := rf_wdata
  coreMonitorBundle.rd0src := wb_reg_inst(19,15)
  coreMonitorBundle.rd0val := RegNext(RegNext(ex_rs(0)))
  coreMonitorBundle.rd1src := wb_reg_inst(24,20)
  coreMonitorBundle.rd1val := RegNext(RegNext(ex_rs(1)))
  coreMonitorBundle.inst := csr.io.trace(0).insn
  coreMonitorBundle.excpt := csr.io.trace(0).exception
  coreMonitorBundle.priv_mode := csr.io.trace(0).priv

  if (enableCommitLog) {
    val t = csr.io.trace(0)
    val rd = wb_waddr
    val wfd = wb_ctrl.wfd
    val wxd = wb_ctrl.wxd
    val has_data = wb_wen && !wb_set_sboard

    when (t.valid && !t.exception) {
      when (wfd) {
        printf ("%d 0x%x (0x%x) f%d p%d 0xXXXXXXXXXXXXXXXX\n", t.priv, t.iaddr, t.insn, rd, rd+32.U)
      }
      .elsewhen (wxd && rd =/= 0.U && has_data) {
        printf ("%d 0x%x (0x%x) x%d 0x%x\n", t.priv, t.iaddr, t.insn, rd, rf_wdata)
      }
      .elsewhen (wxd && rd =/= 0.U && !has_data) {
        printf ("%d 0x%x (0x%x) x%d p%d 0xXXXXXXXXXXXXXXXX\n", t.priv, t.iaddr, t.insn, rd, rd)
      }
      .otherwise {
        printf ("%d 0x%x (0x%x)\n", t.priv, t.iaddr, t.insn)
      }
    }

    when (ll_wen && rf_waddr =/= 0.U) {
      printf ("x%d p%d 0x%x\n", rf_waddr, rf_waddr, rf_wdata)
    }
  }
  else {
    when (csr.io.trace(0).valid) {
      printf("C%d: %d [%d] pc=[%x] W[r%d=%x][%d] R[r%d=%x] R[r%d=%x] inst=[%x] DASM(%x)\n",
         io.hartid, coreMonitorBundle.timer, coreMonitorBundle.valid,
         coreMonitorBundle.pc,
         Mux(wb_ctrl.wxd || wb_ctrl.wfd, coreMonitorBundle.wrdst, 0.U),
         Mux(coreMonitorBundle.wrenx, coreMonitorBundle.wrdata, 0.U),
         coreMonitorBundle.wrenx,
         Mux(wb_ctrl.rxs1 || wb_ctrl.rfs1, coreMonitorBundle.rd0src, 0.U),
         Mux(wb_ctrl.rxs1 || wb_ctrl.rfs1, coreMonitorBundle.rd0val, 0.U),
         Mux(wb_ctrl.rxs2 || wb_ctrl.rfs2, coreMonitorBundle.rd1src, 0.U),
         Mux(wb_ctrl.rxs2 || wb_ctrl.rfs2, coreMonitorBundle.rd1val, 0.U),
         coreMonitorBundle.inst, coreMonitorBundle.inst)
    }
  }
  // printf("C%d: lsl_req:%d%d empty:%d%d req_a:%x req_d:%x " +
  //   "enq_v:%d%d%d%d u_enq_v:%d%d deq_i:%x enq_d:%x %x enq_a:%x %x" +
  //   "mcount:%x scount:%x " +
  //   "ck_comp:%d valid_ins:%x\n",
  //   io.hartid, lsl_req_valid, lsl_req_ready, lsl.io.vec_empty(0), lsl.io.vec_empty(1), lsl_req_addr, lsl_req_data,
  //   lsl.io.m_st_valid(0), lsl.io.m_st_valid(1), lsl.io.m_ld_valid(0), lsl.io.m_ld_valid(1), lsl.io.vec_enq_valid(0), lsl.io.vec_enq_valid(1), lsl.io.lsl_deq_ptr, lsl.io.m_ldst_data(0), lsl.io.m_ldst_data(1), lsl.io.m_ldst_addr(0), lsl.io.m_ldst_addr(1),
  //   icsl.io.ic_counter, icsl.io.debug_sl_counter, 
  //   icsl.io.if_check_completed, icsl.io.num_valid_insts_in_pipeline)
  printf("C%d: ibuf_cnt:[%d] mispred:[%d] imiss:[%d]\n",
        io.hartid, ibuf_notvalid_cnt, mispred_cnt, imiss_cnt)
  

  // CoreMonitorBundle for late latency writes
  val xrfWriteBundle = Wire(new CoreMonitorBundle(xLen, fLen))

  xrfWriteBundle.clock := clock
  xrfWriteBundle.reset := reset
  xrfWriteBundle.hartid := io.hartid
  xrfWriteBundle.timer := csr.io.time(31,0)
  xrfWriteBundle.valid := false.B
  xrfWriteBundle.pc := 0.U
  xrfWriteBundle.wrdst := rf_waddr
  xrfWriteBundle.wrenx := rf_wen && !(csr.io.trace(0).valid && wb_wen && (wb_waddr === rf_waddr))
  xrfWriteBundle.wrenf := false.B
  xrfWriteBundle.wrdata := rf_wdata
  xrfWriteBundle.rd0src := 0.U
  xrfWriteBundle.rd0val := 0.U
  xrfWriteBundle.rd1src := 0.U
  xrfWriteBundle.rd1val := 0.U
  xrfWriteBundle.inst := 0.U
  xrfWriteBundle.excpt := false.B
  xrfWriteBundle.priv_mode := csr.io.trace(0).priv

  PlusArg.timeout(
    name = "max_core_cycles",
    docstring = "Kill the emulation after INT rdtime cycles. Off if 0."
  )(csr.io.time)

  } // leaving gated-clock domain
  val rocketImpl = withClock (gated_clock) { new RocketImpl }

  def checkExceptions(x: Seq[(Bool, UInt)]) =
    (x.map(_._1).reduce(_||_), PriorityMux(x))

  def coverExceptions(exceptionValid: Bool, cause: UInt, labelPrefix: String, coverCausesLabels: Seq[(Int, String)]): Unit = {
    for ((coverCause, label) <- coverCausesLabels) {
      property.cover(exceptionValid && (cause === coverCause.U), s"${labelPrefix}_${label}")
    }
  }

  def checkHazards(targets: Seq[(Bool, UInt)], cond: UInt => Bool) =
    targets.map(h => h._1 && cond(h._2)).reduce(_||_)

  def encodeVirtualAddress(a0: UInt, ea: UInt) = if (vaddrBitsExtended == vaddrBits) ea else {
    // efficient means to compress 64-bit VA into vaddrBits+1 bits
    // (VA is bad if VA(vaddrBits) != VA(vaddrBits-1))
    val b = vaddrBitsExtended-1
    val a = (a0 >> b).asSInt
    val msb = Mux(a === 0.S || a === -1.S, ea(b), !ea(b-1))
    Cat(msb, ea(b-1, 0))
  }

  class Scoreboard(n: Int, zero: Boolean = false)
  {
    def set(en: Bool, addr: UInt): Unit = update(en, _next | mask(en, addr))
    def clear(en: Bool, addr: UInt): Unit = update(en, _next & ~mask(en, addr))
    def read(addr: UInt): Bool = r(addr)
    def readBypassed(addr: UInt): Bool = _next(addr)

    private val _r = RegInit(0.U(n.W))
    private val r = if (zero) (_r >> 1 << 1) else _r
    private var _next = r
    private var ens = false.B
    private def mask(en: Bool, addr: UInt) = Mux(en, 1.U << addr, 0.U)
    private def update(en: Bool, update: UInt) = {
      _next = update
      ens = ens || en
      when (ens) { _r := _next }
    }
  }
}

class RegFile(n: Int, w: Int, zero: Boolean = false) {
  val rf = Mem(n, UInt(w.W))
  private def access(addr: UInt) = rf(~addr(log2Up(n)-1,0))
  private val reads = ArrayBuffer[(UInt,UInt)]()
  private var canRead = true
  def read(addr: UInt) = {
    require(canRead)
    reads += addr -> Wire(UInt())
    reads.last._2 := Mux(zero.B && addr === 0.U, 0.U, access(addr))
    reads.last._2
  }
  def write(addr: UInt, data: UInt) = {
    canRead = false
    when (addr =/= 0.U) {
      access(addr) := data
      for ((raddr, rdata) <- reads)
        when (addr === raddr) { rdata := data }
    }
  }
}

class RegFileshadow(n: Int, w: Int, zero: Boolean = false) {
  val rf = Mem(n, UInt(w.W))
  private def access(addr: UInt) = rf(~addr(log2Up(n)-1,0))
  private val reads = ArrayBuffer[(UInt,UInt)]()
  private var canRead = true
  def read(addr: UInt) = {
    require(canRead)
    reads += addr -> Wire(UInt())
    reads.last._2 := Mux(zero.B && addr === 0.U, 0.U, access(addr))
    reads.last._2
  }
  def write(addr: UInt, data: UInt) = {
    canRead = false
    when (addr =/= 0.U) {
      access(addr) := data
      for ((raddr, rdata) <- reads)
        when (addr === raddr) { rdata := data }
    }
  }
}

object ImmGen {
  def apply(sel: UInt, inst: UInt) = {
    val sign = Mux(sel === IMM_Z, 0.S, inst(31).asSInt)
    val b30_20 = Mux(sel === IMM_U, inst(30,20).asSInt, sign)
    val b19_12 = Mux(sel =/= IMM_U && sel =/= IMM_UJ, sign, inst(19,12).asSInt)
    val b11 = Mux(sel === IMM_U || sel === IMM_Z, 0.S,
              Mux(sel === IMM_UJ, inst(20).asSInt,
              Mux(sel === IMM_SB, inst(7).asSInt, sign)))
    val b10_5 = Mux(sel === IMM_U || sel === IMM_Z, 0.U, inst(30,25))
    val b4_1 = Mux(sel === IMM_U, 0.U,
               Mux(sel === IMM_S || sel === IMM_SB, inst(11,8),
               Mux(sel === IMM_Z, inst(19,16), inst(24,21))))
    val b0 = Mux(sel === IMM_S, inst(7),
             Mux(sel === IMM_I, inst(20),
             Mux(sel === IMM_Z, inst(15), 0.U)))

    Cat(sign, b30_20, b19_12, b11, b10_5, b4_1, b0).asSInt
  }
}
