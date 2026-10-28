// See LICENSE.Berkeley for license details.
// See LICENSE.SiFive for license details.

package freechips.rocketchip.rocket

import chisel3._
import chisel3.util._
import chisel3.{withClock,withReset}
import chisel3.internal.sourceinfo.SourceInfo
import org.chipsalliance.cde.config._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tile._
import freechips.rocketchip.util._
import freechips.rocketchip.r._
import freechips.rocketchip.util.property
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

class FrontendReq(implicit p: Parameters) extends CoreBundle()(p) {
  val pc = UInt(vaddrBitsExtended.W)
  val speculative = Bool()
}

class FrontendExceptions extends Bundle {
  val pf = new Bundle {
    val inst = Bool()
  }
  val gf = new Bundle {
    val inst = Bool()
  }
  val ae = new Bundle {
    val inst = Bool()
  }
}

class FrontendResp(implicit p: Parameters) extends CoreBundle()(p) {
  val btb = new BTBResp
  val pc = UInt(vaddrBitsExtended.W)  // ID stage PC
  val data = UInt((fetchWidth * coreInstBits).W)
  val mask = Bits(fetchWidth.W)
  val xcpt = new FrontendExceptions
  val replay = Bool()
  val prefixLength = UInt(math.max(1, log2Ceil(fetchWidth + 1)).W)
  val bjlEndMask = UInt(fetchWidth.W)
}

class FrontendPerfEvents extends Bundle {
  val acquire = Bool()
  val tlbMiss = Bool()
}

class FrontendIO(implicit p: Parameters) extends CoreBundle()(p) {
  val might_request = Output(Bool())
  val clock_enabled = Input(Bool())
  val req = Valid(new FrontendReq)
  val sfence = Valid(new SFenceReq)
  val resp = Flipped(Decoupled(new FrontendResp))
  val gpa = Flipped(Valid(UInt(vaddrBitsExtended.W)))
  val btb_update = Valid(new BTBUpdate)
  val bht_update = Valid(new BHTUpdate)
  val ras_update = Valid(new RASUpdate)
  val flush_icache = Output(Bool())
  val npc = Input(UInt(vaddrBitsExtended.W))
  val perf = Input(new FrontendPerfEvents())
  val progress = Output(Bool())

  val checker_mode = Output(Bool())
  val bjl_nearfull = Input(Bool())
  val bjl_cdc_ready = Input(Bool())
  val bjl_highwatermark = Input(Bool())
  val bjl_commit = Output(Bool()) 
  val checker_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val checker_clear = Output(Bool())
  val checker_clear_done = Input(Bool())

  val if_check_completed = Output(Bool())
  val if_overtaking = Output(Bool())
  val if_check_already_done = Output(Bool())
}

class Frontend(val icacheParams: ICacheParams, val staticIdForMetadataUseOnly: Int)(implicit p: Parameters) extends LazyModule {
  lazy val module = new FrontendModule(this)
  val icache = LazyModule(new ICache(icacheParams, staticIdForMetadataUseOnly))
  val masterNode = icache.masterNode
  val slaveNode = icache.slaveNode
  val resetVectorSinkNode = BundleBridgeSink[UInt](Some(() => UInt(masterNode.edges.out.head.bundle.addressBits.W)))
}

class FrontendBundle(val outer: Frontend) extends CoreBundle()(outer.p) {
  val cpu = Flipped(new FrontendIO())
  val ptw = new TLBPTWIO()
  val errors = new ICacheErrors
  val packet_bj = Input(Vec(GH_GlobalParams.GH_TOTAL_PACKETS, UInt((xLen * 2).W)))
}

class FrontendModule(outer: Frontend) extends LazyModuleImp(outer)
    with HasRocketCoreParameters
    with HasL1ICacheParameters {
  val io = IO(new FrontendBundle(outer))
  val io_reset_vector = outer.resetVectorSinkNode.bundle
  implicit val edge = outer.masterNode.edges.out(0)
  val icache = outer.icache.module
  require(fetchWidth*coreInstBytes == outer.icacheParams.fetchBytes)

  dontTouch(io.packet_bj)

  val fq = withReset(reset.asBool || io.cpu.req.valid) { Module(new ShiftQueue(new FrontendResp, 5, flow = true)) }

  val bjl_clear = WireDefault(false.B)
  val BJL = withReset(reset.asBool || bjl_clear) { Module(new R_BJLR(R_BJLParams(
    nEntries = 256,
    xLen = xLen,
    pcLen = vaddrBitsExtended
  ))) }
  val checkerMode = io.cpu.checker_mode

  for(i <- 0 until GH_GlobalParams.GH_TOTAL_PACKETS){
    BJL.io.bj_valid(i) := io.packet_bj(i) =/= 0.U
    BJL.io.bj_npc(i)   := io.packet_bj(i)
  }
  io.cpu.bjl_nearfull := BJL.io.near_full        // BJL近满信号上报CPU
  io.cpu.bjl_cdc_ready := BJL.io.cdc_ready        // BJL CDC就绪信号上报CPU
  io.cpu.bjl_highwatermark := BJL.io.bjl_highwatermark  // BJL高水位信号上报CPU
  dontTouch(BJL.io)
  
  val clock_en_reg = Reg(Bool())
  val clock_en = clock_en_reg || io.cpu.might_request
  io.cpu.clock_enabled := clock_en
  assert(!(io.cpu.req.valid || io.cpu.sfence.valid || io.cpu.flush_icache || io.cpu.bht_update.valid || io.cpu.btb_update.valid) || io.cpu.might_request)
  val gated_clock =
    if (!rocketParams.clockGate) clock
    else ClockGate(clock, clock_en, "icache_clock_gate")

  icache.clock := gated_clock
  icache.io.clock_enabled := clock_en
  withClock (gated_clock) { // entering gated-clock domain

  val tlb = Module(new TLB(true, log2Ceil(fetchBytes), TLBConfig(nTLBSets, nTLBWays, outer.icacheParams.nTLBBasePageSectors, outer.icacheParams.nTLBSuperpages)))

  val checker_empty :: checker_fetching :: checker_wait_bjl :: checker_ready :: Nil = Enum(4)
  val checker_state = RegInit(checker_empty)
  val checker_resp = Reg(new FrontendResp)
  val checker_fetch_pc = Reg(UInt(vaddrBitsExtended.W))
  val checker_fetch_seq = Reg(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val checker_next_pc = Reg(UInt(vaddrBitsExtended.W))
  val checker_gpa = Reg(UInt(vaddrBitsExtended.W))
  val checker_cfi_pc = Reg(UInt(vaddrBitsExtended.W))
  val checker_cfi_end = Reg(UInt(math.max(1, log2Ceil(fetchWidth)).W))
  val checker_cfi_rvc = Reg(Bool())
  val checker_partial_valid = RegInit(false.B)
  val checker_partial_bits = Reg(UInt(coreInstBits.W))
  val checker_partial_pc = Reg(UInt(vaddrBitsExtended.W))
  val checker_partial_seq = Reg(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  // OPT3: classification and partial-tail capture share the accepted S2
  // response edge. Held responses never depend on the live I$ data bus.
  val checker_tail_valid = RegInit(false.B)
  val checker_tail_bits = Reg(UInt(coreInstBits.W))
  val checker_tail_pc = Reg(UInt(vaddrBitsExtended.W))
  val checker_path_live = RegInit(false.B)
  val checker_clear_ack = RegInit(true.B)
  val checker_seen_seq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val checker_s1_owner = RegInit(false.B)
  val checker_s2_owner = RegInit(false.B)
  // Hold a redirect until I$ accepts it, after delayed checker mode changes.
  val redirect_pending = RegInit(false.B)
  val redirect_pc = Reg(UInt(vaddrBitsExtended.W))
  val redirect_speculative = Reg(Bool())
  val redirect_settle = RegNext(io.cpu.req.valid, false.B)
  val checker_request = checkerMode && !io.cpu.if_check_completed &&
    io.cpu.checker_seq =/= 0.U && !io.cpu.checker_clear
  val checker_busy = checker_state =/= checker_empty || checker_s1_owner || checker_s2_owner
  val checker_flow = checker_request || checker_busy
  val checker_emit = checker_state === checker_ready && !io.cpu.checker_clear
  // OPT2B: accept the already-resolved successor while the current response
  // is handed to FQ. Never look ahead across a held response, replay or fault.
  val checker_handoff = checker_emit && fq.io.enq.ready && checker_request &&
    !checker_resp.replay && !checker_resp.xcpt.asUInt.orR &&
    !redirect_pending && !redirect_settle && !io.cpu.req.valid
  val legacy_resp = Wire(new FrontendResp)
  val legacy_emit = Wire(Bool())
  val legacy_fire = legacy_emit && fq.io.enq.ready

  val s1_valid = Reg(Bool())
  val s2_valid = RegInit(false.B)
  val s0_fq_has_space =
    !fq.io.mask(fq.io.mask.getWidth-3) ||
    (!fq.io.mask(fq.io.mask.getWidth-2) && (!s1_valid || !s2_valid)) ||
    (!fq.io.mask(fq.io.mask.getWidth-1) && (!s1_valid && !s2_valid))
  val redirect_accept = redirect_pending && !redirect_settle && icache.io.req.fire
  // Redirect first changes the PC/mode; accept the target request only after
  // the registered settle cycle, and keep it pending until req.fire.
  val s0_valid = !io.cpu.req.valid && !redirect_settle && Mux(checker_flow,
    (checker_state === checker_empty || checker_handoff) && !io.cpu.checker_clear,
    s0_fq_has_space || !io.cpu.if_overtaking)
  dontTouch(s0_fq_has_space)
  // During the redirect handoff, S1 validity is an acceptance fact.  The
  // legacy path keeps its original attempt/replay behavior once ownership
  // has moved past this boundary.
  s1_valid := Mux(io.cpu.req.valid || redirect_pending || redirect_settle,
    icache.io.req.fire,
    Mux(checker_flow, icache.io.req.fire, s0_valid))
  val s1_pc = Reg(UInt(vaddrBitsExtended.W))
  val s1_speculative = Reg(Bool())
  val s2_pc = RegInit(t = UInt(vaddrBitsExtended.W), alignPC(io_reset_vector))
  val s2_btb_resp_valid = if (usingBTB) Reg(Bool()) else false.B
  val s2_btb_resp_bits = Reg(new BTBResp)
  val s2_btb_taken = s2_btb_resp_valid && s2_btb_resp_bits.taken
  val s2_tlb_resp = Reg(tlb.io.resp.cloneType)
  val s2_xcpt = s2_tlb_resp.ae.inst || s2_tlb_resp.pf.inst || s2_tlb_resp.gf.inst
  val s2_speculative = RegInit(false.B)
  val s2_partial_insn_valid = RegInit(false.B)
  val s2_partial_insn = Reg(UInt(coreInstBits.W))
  val wrong_path = RegInit(false.B)
  val s2_redirect = WireDefault(io.cpu.req.valid)
  dontTouch(s2_btb_resp_bits)

  val s1_base_pc = ~(~s1_pc | (fetchBytes - 1).U)
  val ntpc = s1_base_pc + fetchBytes.U
  val predicted_npc = WireDefault(ntpc)
  val predicted_taken = WireDefault(false.B)
  dontTouch(s1_base_pc)
  dontTouch(ntpc)
  val s2_replay = Wire(Bool())
  val s2_replay_reg = RegInit(true.B)
  s2_replay := !checker_s2_owner && ((s2_valid && !legacy_fire) || s2_replay_reg)
  val npc = Mux(s2_replay, s2_pc, predicted_npc)

  // Do not overwrite S1 with the live NPC during the redirect bubble.  The
  // target PC/speculative bit become S1 state only on the real request fire.
  when (redirect_accept) {
    s1_pc := io.cpu.npc
  }.elsewhen (!io.cpu.req.valid && !redirect_pending && !redirect_settle) {
    s1_pc := io.cpu.npc
  }
  // consider RVC fetches across blocks to be non-speculative if the first
  // part was non-speculative
  val s0_speculative =
    if (usingCompressed) s1_speculative || s2_valid && !s2_speculative || predicted_taken
    else true.B
  when (redirect_accept) {
    s1_speculative := Mux(checker_request, false.B, redirect_speculative)
  }.elsewhen (!redirect_pending && !redirect_settle && !io.cpu.req.valid) {
    s1_speculative := Mux(checker_request, false.B,
      Mux(s2_replay, s2_speculative, s0_speculative))
  }
  dontTouch(s0_speculative)

  
  s2_valid := false.B
  // No old S2 transaction is allowed to survive the redirect handoff.  The
  // accepted target reaches S2 on the following cycle through the normal
  // S1/S2 pipeline, so this guard also prevents a ghost S2 response.
  when (io.cpu.req.valid || redirect_pending || redirect_settle) {
    s2_valid := false.B
  }.elsewhen (!s2_replay || checker_s1_owner) {
    s2_valid := !s2_redirect
    s2_pc := s1_pc
    s2_speculative := s1_speculative
    s2_tlb_resp := tlb.io.resp
  }

  val recent_progress_counter_init = 3.U
  val recent_progress_counter = RegInit(recent_progress_counter_init)
  val recent_progress = recent_progress_counter > 0.U
  when(io.ptw.req.fire && recent_progress) { recent_progress_counter := recent_progress_counter - 1.U }
  when(io.cpu.progress) { recent_progress_counter := recent_progress_counter_init }

  val s2_kill_speculative_tlb_refill = s2_speculative && !recent_progress

  io.ptw <> tlb.io.ptw
  tlb.io.req.valid := checker_s1_owner || s1_valid && !s2_replay
  tlb.io.req.bits.cmd := M_XRD // Frontend only reads
  tlb.io.req.bits.vaddr := s1_pc
  tlb.io.req.bits.passthrough := false.B
  tlb.io.req.bits.size := log2Ceil(coreInstBytes*fetchWidth).U
  tlb.io.req.bits.prv := io.ptw.status.prv
  tlb.io.req.bits.v := io.ptw.status.v
  tlb.io.sfence := io.cpu.sfence
  // Serialized checker retries have S2 bubbles while the same walk is pending.
  tlb.io.kill := Mux(checker_flow,
    io.cpu.req.valid || io.cpu.checker_clear,
    !s2_valid || s2_kill_speculative_tlb_refill)

  icache.io.req.valid := s0_valid
  icache.io.req.bits.addr := io.cpu.npc
  icache.io.invalidate := io.cpu.flush_icache
  icache.io.s1_paddr := tlb.io.resp.paddr
  icache.io.s2_vaddr := s2_pc
  icache.io.s1_kill := Mux(checker_s1_owner,
    io.cpu.req.valid || io.cpu.checker_clear || tlb.io.resp.miss,
    s2_redirect || tlb.io.resp.miss || s2_replay)
  val s2_can_speculatively_refill = s2_tlb_resp.cacheable && !io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableSpeculativeICacheRefill
  icache.io.s2_kill := s2_speculative && !s2_can_speculatively_refill || s2_xcpt
  icache.io.s2_cacheable := s2_tlb_resp.cacheable
  icache.io.s2_prefetch := s2_tlb_resp.prefetchable && !io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableICachePrefetch

  legacy_emit := RegNext(s1_valid) && s2_valid && !checker_s2_owner &&
    checker_state === checker_empty &&
    (icache.io.resp.valid || (s2_kill_speculative_tlb_refill && s2_tlb_resp.miss) || (!s2_tlb_resp.miss && icache.io.s2_kill))
  legacy_resp.pc := s2_pc
  val checker_pc = Mux(checker_state === checker_empty, s1_pc,
    Mux(checker_emit && fq.io.enq.ready, checker_next_pc, checker_fetch_pc))
  io.cpu.npc := alignPC(Mux(io.cpu.req.valid, io.cpu.req.bits.pc,
    Mux(redirect_pending, redirect_pc, Mux(checker_flow, checker_pc, npc))))

  legacy_resp.data := icache.io.resp.bits.data
  val s2_start = s2_pc.extract(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
  legacy_resp.mask := ((BigInt(1) << fetchWidth)-1).U << s2_start
  legacy_resp.replay := (icache.io.resp.bits.replay || icache.io.s2_kill && !icache.io.resp.valid && !s2_xcpt) || (s2_kill_speculative_tlb_refill && s2_tlb_resp.miss)
  legacy_resp.btb := s2_btb_resp_bits
  legacy_resp.btb.taken := s2_btb_taken
  legacy_resp.prefixLength := Mux(legacy_resp.btb.taken, legacy_resp.btb.bridx +& 1.U, fetchWidth.U) - s2_start
  legacy_resp.bjlEndMask := 0.U
  legacy_resp.xcpt := s2_tlb_resp
  assert(!(s2_speculative && io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableSpeculativeICacheRefill && !icache.io.s2_kill))
  when (icache.io.resp.valid && icache.io.resp.bits.ae) { legacy_resp.xcpt.ae.inst := true.B }

  if (usingBTB) {
    val btb = Module(new BTB)
    btb.io.flush := false.B
    btb.io.req.valid := false.B
    btb.io.req.bits.addr := s1_pc
    btb.io.btb_update := io.cpu.btb_update
    btb.io.bht_update := io.cpu.bht_update
    btb.io.ras_update.valid := false.B
    btb.io.ras_update.bits := DontCare
    btb.io.bht_advance.valid := false.B
    btb.io.bht_advance.bits := DontCare
    when (!s2_replay && !checkerMode && !redirect_pending && !redirect_settle) {
      btb.io.req.valid := !s2_redirect
      s2_btb_resp_valid := btb.io.resp.valid
      s2_btb_resp_bits := btb.io.resp.bits
    }
    when (!checkerMode && !redirect_pending && !redirect_settle && btb.io.resp.valid && btb.io.resp.bits.taken) {
      predicted_npc := btb.io.resp.bits.target.sextTo(vaddrBitsExtended)
      predicted_taken := true.B
    }

    val force_taken = io.ptw.customCSRs.bpmStatic
    when (checkerMode) {
      btb.io.bht_update.valid := false.B
      btb.io.btb_update.valid := false.B
    }
    when (io.ptw.customCSRs.flushBTB) { btb.io.flush := true.B }
    when (force_taken) { btb.io.bht_update.valid := false.B }

    val s2_base_pc = ~(~s2_pc | (fetchBytes-1).U)
    val taken_idx = Wire(UInt())
    val after_idx = Wire(UInt())
    val useRAS = WireDefault(false.B)
    val updateBTB = WireDefault(false.B)
    // 标记本次 fetch 包中是否存在“特殊 JALR”（bit 12 为 1 的 JALR），
    // 这种指令在 checker_mode 下不应被 BJL 的目标地址所影响。
    val specialJalrVec = WireInit(VecInit(Seq.fill(fetchWidth)(false.B)))

    // If !prevTaken, ras_update / bht_update is always invalid. 
    taken_idx := DontCare
    after_idx := DontCare
    dontTouch(taken_idx)
    dontTouch(after_idx)  

   
    dontTouch(s2_btb_resp_bits)
    def scanInsns(idx: Int, prevValid: Bool, prevBits: UInt, prevTaken: Bool, prevHasCF: Bool): (Bool, Bool) = {
      def insnIsRVC(bits: UInt) = bits(1,0) =/= 3.U
      val prevRVI = prevValid && !insnIsRVC(prevBits)
      val valid = legacy_resp.mask(idx) && !prevRVI
      val bits = legacy_resp.data(coreInstBits*(idx+1)-1, coreInstBits*idx)
      val rvc = insnIsRVC(bits)
      val rviBits = Cat(bits, prevBits)
      val rviBranch = rviBits(6,0) === Instructions.BEQ.value.U.extract(6,0)
      val rviJump = rviBits(6,0) === Instructions.JAL.value.U.extract(6,0)
      val rviJALR = rviBits(6,0) === Instructions.JALR.value.U.extract(6,0)
      // 自定义 JALR：通过 bit 12 = 1 识别，需要在 checker 模式下屏蔽 BJL 对其的影响
      val isSpecialJalr = prevRVI && rviJALR && (rviBits(12) === 1.U)
      when (isSpecialJalr) {
        specialJalrVec(idx) := true.B
      }
      val rviReturn = rviJALR && !rviBits(7) && BitPat("b00?01") === rviBits(19,15)
      val rviCall = (rviJALR || rviJump) && rviBits(7)
      val rvcBranch = bits === Instructions.C_BEQZ || bits === Instructions.C_BNEZ
      val rvcJAL = (xLen == 32).B && bits === Instructions32.C_JAL
      val rvcJump = bits === Instructions.C_J || rvcJAL
      val rvcImm = Mux(bits(14), new RVCDecoder(bits, xLen).bImm.asSInt, new RVCDecoder(bits, xLen).jImm.asSInt)
      val rvcJR = bits === Instructions.C_MV && bits(6,2) === 0.U
      val rvcReturn = rvcJR && BitPat("b00?01") === bits(11,7)
      val rvcJALR = bits === Instructions.C_ADD && bits(6,2) === 0.U
      val rvcCall = rvcJAL || rvcJALR
      val rviImm = Mux(rviBits(3), ImmGen(IMM_UJ, rviBits), ImmGen(IMM_SB, rviBits))
      
      
      val predict_taken = Mux(checkerMode, false.B, s2_btb_resp_bits.bht.taken) || force_taken
      val taken =
        prevRVI && (rviJump || rviJALR || rviBranch && predict_taken) ||
        valid && (rvcJump || rvcJALR || rvcJR || rvcBranch && predict_taken)
      val predictReturn = btb.io.ras_head.valid && (prevRVI && rviReturn || valid && rvcReturn)
      val predictJump = prevRVI && rviJump || valid && rvcJump
      val predictBranch = predict_taken && (prevRVI && rviBranch || valid && rvcBranch)

      val isnt_valid = s2_valid
      // 2. 新增：仅检测指令类型的 hasCF_this_idx（不依赖任何BTB预测）
      // 只要是分支/跳转指令，不管预测是否执行，都标记为true
      val hasCF_this_idx = isnt_valid &&
        ((prevRVI && (rviJump || rviJALR || rviBranch)) ||  // 32位分支/跳转
        (valid && (rvcJump || rvcJALR || rvcJR || rvcBranch)))  // 16位分支/跳转
      val currHasCF = prevHasCF || hasCF_this_idx

      when (s2_valid && s2_btb_resp_valid && s2_btb_resp_bits.bridx === idx.U && valid && !rvc && !checkerMode) {
        // The BTB has predicted that the middle of an RVI instruction is
        // a branch! Flush the BTB and the pipeline.
        btb.io.flush := true.B
        legacy_resp.replay := true.B
        wrong_path := true.B
        ccover(wrong_path, "BTB_NON_CFI_ON_WRONG_PATH", "BTB predicted a non-branch was taken while on the wrong path")
      }

      when (!prevTaken) {
        taken_idx := idx.U
        after_idx := (idx + 1).U
        btb.io.ras_update.valid := legacy_fire && !wrong_path && (prevRVI && (rviCall || rviReturn) || valid && (rvcCall || rvcReturn))
        btb.io.ras_update.bits.cfiType := Mux(Mux(prevRVI, rviReturn, rvcReturn), CFIType.ret,
                                          Mux(Mux(prevRVI, rviCall, rvcCall), CFIType.call,
                                          Mux(Mux(prevRVI, rviBranch, rvcBranch) && !force_taken, CFIType.branch,
                                          CFIType.jump)))

        when (!s2_btb_taken && !checkerMode) {
          when (legacy_fire && taken && !predictBranch && !predictJump && !predictReturn) {
            wrong_path := true.B
          }
          when (s2_valid && predictReturn) {
            useRAS := true.B
          }
          when (s2_valid && (predictBranch || predictJump)) {
            val pc = s2_base_pc | (idx*coreInstBytes).U
            val npc =
              if (idx == 0) pc.asSInt + Mux(prevRVI, rviImm -& 2.S, rvcImm)
              else Mux(prevRVI, pc - coreInstBytes.U, pc).asSInt + Mux(prevRVI, rviImm, rvcImm)
            predicted_npc := npc.asUInt
          }
        }
        when (prevRVI && rviBranch || valid && rvcBranch) {
          btb.io.bht_advance.valid := legacy_fire && !wrong_path
          btb.io.bht_advance.bits := s2_btb_resp_bits
        }
        when (!s2_btb_resp_valid && (predictBranch && s2_btb_resp_bits.bht.strongly_taken || predictJump || predictReturn)) {
          updateBTB := true.B
        }
      }

      if (idx == fetchWidth-1) {
        when (legacy_fire) {
          s2_partial_insn_valid := false.B
          when (valid && !prevTaken && !rvc) {
            s2_partial_insn_valid := true.B
            s2_partial_insn := bits | 0x3.U
          }
        }
        (prevTaken || taken, currHasCF)
      } else {
        scanInsns(idx + 1, valid, bits, prevTaken || taken, currHasCF)
      }
    }

    when (!io.cpu.btb_update.valid) {
      val fetch_bubble_likely = !fq.io.mask(1)
      btb.io.btb_update.valid := legacy_fire && !wrong_path && fetch_bubble_likely && updateBTB && !checkerMode
      btb.io.btb_update.bits.prediction.entry := tileParams.btb.get.nEntries.U
      btb.io.btb_update.bits.isValid := true.B
      btb.io.btb_update.bits.cfiType := btb.io.ras_update.bits.cfiType
      btb.io.btb_update.bits.br_pc := s2_base_pc | (taken_idx << log2Ceil(coreInstBytes))
      btb.io.btb_update.bits.pc := s2_base_pc
    }

    btb.io.ras_update.bits.returnAddr := s2_base_pc + (after_idx << log2Ceil(coreInstBytes))

    val (taken, hasControlFlow) = scanInsns(0, s2_partial_insn_valid, s2_partial_insn, false.B, false.B)
    dontTouch(hasControlFlow)
    when (useRAS) {
      predicted_npc := btb.io.ras_head.bits
    }
    when (legacy_fire && (s2_btb_taken || taken)) {
      s2_partial_insn_valid := false.B
    }
    when (!s2_btb_taken && !checker_s2_owner) {
      when (taken) {
        legacy_resp.btb.bridx := taken_idx
        legacy_resp.btb.taken := true.B
        legacy_resp.btb.entry := tileParams.btb.get.nEntries.U
        when (legacy_fire) { s2_redirect := true.B }
      }
    }

    assert(!s2_partial_insn_valid || legacy_resp.mask(0))
    when (s2_redirect) { s2_partial_insn_valid := false.B }
    when (io.cpu.req.valid || redirect_pending || redirect_settle || checker_s1_owner) {
      s2_btb_resp_valid := false.B
    }
    when (io.cpu.req.valid) { wrong_path := false.B }
    dontTouch(specialJalrVec)
  }
  // OPT3: classify the incoming owned response before registering it. This
  // removes the unconditional CLASSIFY state; BJL reservation still happens
  // only in WAIT_BJL and FQ delivery still happens only in READY.
  val checker_cache_valid = if (outer.icacheParams.latency == 1)
    RegNext(checker_s1_owner && icache.io.resp.valid, false.B) else icache.io.resp.valid
  val checker_cache_bits = if (outer.icacheParams.latency == 1)
    RegEnable(icache.io.resp.bits, checker_s1_owner) else icache.io.resp.bits
  val checker_incoming = Wire(new FrontendResp)
  checker_incoming := legacy_resp
  checker_incoming.data := checker_cache_bits.data
  checker_incoming.replay := checker_cache_valid && checker_cache_bits.replay ||
    icache.io.s2_kill && !checker_cache_valid && !s2_xcpt
  when (checker_cache_valid && checker_cache_bits.ae) { checker_incoming.xcpt.ae.inst := true.B }
  val checker_classify_fire = checker_s2_owner && checker_state === checker_fetching &&
    !s2_tlb_resp.miss && (checker_cache_valid || icache.io.s2_kill) &&
    !io.cpu.req.valid && !io.cpu.checker_clear
  // One checker response owns its data and reservation until FQ accepts it.
  val checker_start = checker_resp.pc.extract(log2Ceil(fetchBytes)-1, log2Ceil(coreInstBytes))
  val checker_scan_start = checker_incoming.pc.extract(log2Ceil(fetchBytes)-1, log2Ceil(coreInstBytes))
  val checker_base = checker_incoming.pc & ~(fetchBytes-1).U(vaddrBitsExtended.W)
  val cfi_valid = Wire(Vec(fetchWidth, Bool()))
  val cfi_pc = Wire(Vec(fetchWidth, UInt(vaddrBitsExtended.W)))
  val cfi_start = Wire(Vec(fetchWidth, UInt(math.max(1, log2Ceil(fetchWidth+1)).W)))
  val cfi_rvc = Wire(Vec(fetchWidth, Bool()))
  val cfi_special = Wire(Vec(fetchWidth, Bool()))
  var lowValid: Bool = checker_partial_valid && checker_partial_seq === checker_fetch_seq &&
    checker_incoming.pc === checker_partial_pc + coreInstBytes.U
  var lowBits: UInt = checker_partial_bits
  var lowPC: UInt = checker_partial_pc
  for (i <- 0 until fetchWidth) {
    val bits = checker_incoming.data((i+1)*coreInstBits-1, i*coreInstBits)
    val active = i.U >= checker_scan_start
    val high = if (usingCompressed) active && lowValid else false.B
    val first = active && !high
    val rvc = if (usingCompressed) bits(1,0) =/= 3.U else false.B
    val raw = if (usingCompressed) Cat(bits, lowBits) else bits
    val complete = high || first && (if (usingCompressed) rvc else true.B)
    val rviCFI = raw(6,0) === 0x6f.U ||
      raw(6,0) === 0x67.U && raw(14,13) === 0.U ||
      raw(6,0) === 0x63.U && raw(14,12).isOneOf(0.U, 1.U, 4.U, 5.U, 6.U, 7.U)
    val rvcCFI = if (usingCompressed) {
      bits === Instructions.C_BEQZ || bits === Instructions.C_BNEZ ||
      bits === Instructions.C_J || (xLen == 32).B && bits === Instructions32.C_JAL ||
      (bits === Instructions.C_MV || bits === Instructions.C_ADD) &&
        bits(6,2) === 0.U && bits(11,7) =/= 0.U
    } else false.B
    cfi_valid(i) := complete && Mux(first && rvc, rvcCFI, rviCFI)
    cfi_pc(i) := Mux(high, lowPC, checker_base + (i*coreInstBytes).U)
    cfi_start(i) := (if (i == 0) 0.U else Mux(high, (i-1).U, i.U))
    cfi_rvc(i) := first && rvc
    cfi_special(i) := !cfi_rvc(i) && raw(6,0) === 0x67.U && raw(12)
    lowValid = first && !rvc && usingCompressed.B
    lowBits = bits
    lowPC = checker_base + (i*coreInstBytes).U
  }
  val first_cfi = if (fetchWidth == 1) 0.U(1.W) else PriorityEncoder(cfi_valid.asUInt)
  val has_cfi = cfi_valid.asUInt.orR
  val checker_fault = checker_resp.replay || checker_resp.xcpt.asUInt.orR
  val checker_incoming_fault = checker_incoming.replay || checker_incoming.xcpt.asUInt.orR
  val checker_head_match = BJL.io.bj_resp_cpc === checker_cfi_pc &&
    BJL.io.bj_resp_is_rvc === checker_cfi_rvc
  BJL.io.bj_req_valid := checker_state === checker_wait_bjl && checker_head_match &&
    !io.cpu.req.valid && !io.cpu.checker_clear
  BJL.io.bj_rollback := io.cpu.req.valid
  BJL.io.bj_s2_replay := false.B
  BJL.io.bj_commit_valid := io.cpu.bjl_commit
  fq.io.enq.valid := checker_emit || legacy_emit
  fq.io.enq.bits := Mux(checker_emit, checker_resp, legacy_resp)
  when (checker_emit) {
    fq.io.enq.bits.mask := ((UIntToOH(checker_resp.prefixLength, fetchWidth+1) - 1.U) << checker_start)(fetchWidth-1, 0)
  }
  checker_s1_owner := icache.io.req.fire && checker_request && !io.cpu.req.valid
  checker_s2_owner := checker_s1_owner && !io.cpu.req.valid && !io.cpu.checker_clear
  when (icache.io.req.fire && checker_request) {
    checker_state := checker_fetching
    checker_fetch_pc := io.cpu.npc
    checker_fetch_seq := io.cpu.checker_seq
    checker_path_live := true.B
  }
  when (checker_s2_owner && checker_state === checker_fetching) {
    when (!s2_tlb_resp.miss && (checker_cache_valid || icache.io.s2_kill)) {
      // The clear/redirect guard also applies to every incoming metadata
      // field, including the trailing RVC half used after a held FQ response.
      when (checker_classify_fire) {
        checker_resp := checker_incoming
        checker_resp.btb.taken := false.B
        checker_resp.prefixLength := fetchWidth.U - checker_scan_start
        checker_resp.bjlEndMask := 0.U
        checker_gpa := s2_tlb_resp.gpa
        checker_next_pc := checker_base + fetchBytes.U
        checker_tail_valid := lowValid
        checker_tail_bits := lowBits
        checker_tail_pc := lowPC
        when (!has_cfi || checker_incoming_fault) {
          checker_state := checker_ready
        }.elsewhen (cfi_start(first_cfi) > checker_scan_start) {
          checker_resp.prefixLength := cfi_start(first_cfi) - checker_scan_start
          checker_next_pc := cfi_pc(first_cfi)
          checker_state := checker_ready
        }.elsewhen (cfi_special(first_cfi)) {
          checker_resp.prefixLength := (first_cfi +& 1.U) - checker_scan_start
          checker_next_pc := cfi_pc(first_cfi) + 4.U
          checker_state := checker_ready
        }.otherwise {
          checker_cfi_pc := cfi_pc(first_cfi)
          checker_cfi_end := first_cfi
          checker_cfi_rvc := cfi_rvc(first_cfi)
          checker_state := checker_wait_bjl
        }
      }
    }.otherwise {
      // I$ and TLB misses do not promise a later response to this request.
      checker_state := checker_empty
    }
  }
  when (BJL.io.bj_req_valid && BJL.io.bj_req_ready) {
    checker_resp.prefixLength := (checker_cfi_end +& 1.U) - checker_start
    checker_resp.bjlEndMask := UIntToOH(checker_cfi_end, fetchWidth)
    checker_resp.btb.taken := BJL.io.bj_resp_taken
    checker_resp.btb.bridx := checker_cfi_end
    checker_next_pc := BJL.io.bj_resp_npc
    checker_state := checker_ready
  }
  when (checker_emit && fq.io.enq.fire) {
    // A newly accepted S0 request owns the FSM after this edge. If I$ is not
    // ready, keep the original EMPTY retry path and the accepted next PC.
    checker_state := Mux(icache.io.req.fire && checker_request,
      checker_fetching, checker_empty)
    checker_partial_valid := checker_tail_valid &&
      checker_resp.prefixLength === fetchWidth.U - checker_start && !checker_fault &&
      !checker_resp.bjlEndMask.orR
    checker_partial_bits := checker_tail_bits
    checker_partial_pc := checker_tail_pc
    checker_partial_seq := checker_fetch_seq
  }
  val checker_handoff_fire = checker_handoff && icache.io.req.fire
  val checker_classify_prev = RegNext(checker_classify_fire, false.B)
  val checker_classify_wait = RegEnable(has_cfi && !checker_incoming_fault &&
    cfi_start(first_cfi) <= checker_scan_start && !cfi_special(first_cfi), checker_classify_fire)
  val checker_classify_data = RegEnable(checker_incoming.data, checker_classify_fire)
  val checker_classify_pc = RegEnable(checker_incoming.pc, checker_classify_fire)
  when (checker_classify_fire) {
    // checker_s1_owner is the current response owner on this edge; only a
    // second FQ consumer would violate the single-owner boundary.
    assert(!fq.io.enq.fire, "checker classification overlaps FQ delivery")
    assert(checker_incoming.pc === checker_fetch_pc,
      "checker classifier response PC does not match accepted request")
    assert(!BJL.io.bj_req_valid, "checker classifier reserved BJL before WAIT_BJL")
  }
  when (checker_classify_prev && !io.cpu.req.valid && !io.cpu.checker_clear) {
    assert(checker_state === Mux(checker_classify_wait, checker_wait_bjl, checker_ready),
      "checker fused classification lost its response")
    assert(checker_resp.data === checker_classify_data && checker_resp.pc === checker_classify_pc,
      "checker fused classification changed response ownership")
  }
  when (checker_handoff_fire) {
    assert(fq.io.enq.fire && !checker_s1_owner && !checker_s2_owner,
      "checker successor launched without retiring the sole response owner")
    assert(io.cpu.npc === alignPC(checker_next_pc), "checker successor PC mismatch")
  }
  val checker_handoff_prev = RegNext(checker_handoff_fire, false.B)
  when (checker_handoff_prev && !io.cpu.req.valid && !io.cpu.checker_clear) {
    assert(checker_state === checker_fetching && checker_s1_owner,
      "checker handoff lost the accepted successor")
  }
  when (checker_state === checker_ready) {
    // Prefix metadata is authoritative in IBuf, including on the first READY cycle.
    assert(checker_resp.prefixLength > 0.U && checker_resp.prefixLength <= fetchWidth.U - checker_start)
    assert(PopCount(checker_resp.bjlEndMask) <= 1.U)
  }
  val checker_held = RegNext(checker_emit && !fq.io.enq.ready && !io.cpu.req.valid, false.B)
  val checker_held_resp = RegEnable(checker_resp.asUInt, checker_emit && !fq.io.enq.ready)
  when (checker_held && !io.cpu.req.valid && !io.cpu.checker_clear) {
    assert(checker_emit && checker_resp.asUInt === checker_held_resp,
      "checker fetch changed under FQ backpressure")
  }
  when (checker_busy && !io.cpu.checker_clear) {
    assert(checker_fetch_seq === io.cpu.checker_seq, "stale checker fetch owner")
  }

  when (io.cpu.req.valid || io.cpu.checker_clear) {
    checker_state := checker_empty
    checker_s1_owner := false.B
    checker_s2_owner := false.B
    checker_partial_valid := false.B
  }
  when (io.cpu.checker_clear && checker_s1_owner) { s2_valid := false.B }
  when (io.cpu.req.valid) { checker_path_live := false.B }
  when (io.cpu.checker_seq =/= checker_seen_seq) {
    checker_seen_seq := io.cpu.checker_seq
    checker_clear_ack := false.B
  }
  // Reset only after redirect has killed the old FQ/IBuf/pipeline path.
  bjl_clear := io.cpu.checker_clear && !checker_path_live &&
    !checker_s1_owner && !checker_s2_owner && !io.cpu.bjl_commit
  when (io.cpu.checker_clear) { checker_clear_ack := bjl_clear }
  io.cpu.checker_clear_done := checker_clear_ack
  // OPT2B_OBSERVATION_ONLY: cumulative counters, sparse snapshots. These
  // registers feed only the input-only logger; they cannot affect fetching.
  val (opt2bCycle, opt2bRoi) = SafeChainObservation.context()
  val opt2bLocal = RegInit(0.U(64.W))
  opt2bLocal := opt2bLocal + 1.U
  val opt2bFrontendLive = checker_flow && io.cpu.checker_seq =/= 0.U
  val opt2bFrontendEvents = Seq(
    opt2bFrontendLive,
    opt2bFrontendLive && checker_state === checker_empty,
    opt2bFrontendLive && checker_state === checker_fetching,
    false.B, // Retired CLASSIFY state: preserve kind13 counter field position.
    opt2bFrontendLive && checker_state === checker_wait_bjl,
    opt2bFrontendLive && checker_state === checker_ready,
    checker_emit && fq.io.enq.fire,
    checker_handoff_fire,
    icache.io.req.fire && checker_request,
    checker_emit && !fq.io.enq.ready,
    checker_emit && fq.io.enq.fire && (checker_resp.replay || checker_resp.xcpt.asUInt.orR),
    opt2bFrontendLive && icache.io.perf.acquire,
    opt2bFrontendLive && tlb.io.resp.miss,
    opt2bFrontendLive && io.cpu.req.valid)
  val opt2bFrontendCounts = RegInit(VecInit(Seq.fill(14)(0.U(64.W))))
  for ((event, i) <- opt2bFrontendEvents.zipWithIndex) {
    when (event) { opt2bFrontendCounts(i) := opt2bFrontendCounts(i) + 1.U }
  }
  val opt2bFrontendFlags = VecInit(Seq(checkerMode, io.cpu.checker_clear,
    io.cpu.if_check_completed)).asUInt
  SafeChainObservation.emit(13, gated_clock, reset.asBool, opt2bCycle, opt2bLocal,
    outer.staticIdForMetadataUseOnly.U, opt2bRoi, true.B,
    Seq(io.cpu.checker_seq) ++ opt2bFrontendCounts.toSeq ++ Seq(opt2bFrontendFlags),
    Cat(io.cpu.checker_seq, opt2bFrontendFlags, opt2bFrontendCounts(6) >> 10))
  // OPT3_OBSERVATION_ONLY: bounded cumulative snapshots, no per-fetch log.
  // Classification modes partition accepted responses; BJL misses and held
  // READY cycles are overlapping diagnostics, not execution categories.
  val opt3NoCfi = !has_cfi || checker_incoming_fault
  val opt3Prefix = !opt3NoCfi && cfi_start(first_cfi) > checker_scan_start
  val opt3Special = !opt3NoCfi && !opt3Prefix && cfi_special(first_cfi)
  val opt3Events = Seq(checker_classify_fire,
    checker_classify_fire && opt3NoCfi,
    checker_classify_fire && opt3Prefix,
    checker_classify_fire && opt3Special,
    checker_classify_fire && !opt3NoCfi && !opt3Prefix && !opt3Special,
    BJL.io.bj_req_valid && BJL.io.bj_req_ready,
    opt2bFrontendLive && checker_state === checker_wait_bjl && !BJL.io.bj_req_ready,
    opt2bFrontendLive && checker_state === checker_wait_bjl && BJL.io.bj_req_ready && !checker_head_match,
    checker_emit && !fq.io.enq.ready)
  val opt3Counts = RegInit(VecInit(Seq.fill(9)(0.U(64.W))))
  for ((event, i) <- opt3Events.zipWithIndex) {
    when (event) { opt3Counts(i) := opt3Counts(i) + 1.U }
  }
  SafeChainObservation.emit(16, gated_clock, reset.asBool, opt2bCycle, opt2bLocal,
    outer.staticIdForMetadataUseOnly.U, opt2bRoi, true.B,
    Seq(io.cpu.checker_seq) ++ opt3Counts.toSeq ++ Seq(opt2bFrontendFlags),
    Cat(io.cpu.checker_seq, opt2bFrontendFlags, opt2bFrontendCounts(6) >> 10))
  dontTouch(icache.io)
  dontTouch(predicted_taken)
  dontTouch(io)
  dontTouch(npc)
  io.cpu.resp <> fq.io.deq

  // Redirect capture has priority over completion of an older pending target;
  // otherwise a back-to-back redirect could release the newer target early.
  when (io.cpu.req.valid) {
    redirect_pending := true.B
    redirect_pc := alignPC(io.cpu.req.bits.pc)
    redirect_speculative := io.cpu.req.bits.speculative
  }.elsewhen (redirect_accept) {
    redirect_pending := false.B
  }
  // A redirect invalidates the old replay attempt.  Keep the reset value and
  // ordinary retry recurrence unchanged outside the redirect handoff.
  when (io.cpu.req.valid || redirect_pending || redirect_settle) {
    s2_replay_reg := false.B
  }.otherwise {
    s2_replay_reg := s2_replay && !s0_valid
  }

  // supply guest physical address to commit stage
  val gpa_valid = Reg(Bool())
  val gpa = Reg(UInt(vaddrBitsExtended.W))
  when (fq.io.enq.fire && fq.io.enq.bits.xcpt.gf.inst) {
    when (!gpa_valid) {
      gpa := Mux(checker_emit, checker_gpa, s2_tlb_resp.gpa)
    }
    gpa_valid := true.B
  }
  when (io.cpu.req.valid) {
    gpa_valid := false.B
  }
  io.cpu.gpa.valid := gpa_valid
  io.cpu.gpa.bits := gpa

  // performance events
  io.cpu.perf.acquire := icache.io.perf.acquire
  io.cpu.perf.tlbMiss := io.ptw.req.fire
  io.errors := icache.io.errors

  // gate the clock
  clock_en_reg := !rocketParams.clockGate.B ||
    io.cpu.might_request || // chicken bit
    icache.io.keep_clock_enabled || // I$ miss or ITIM access
    checker_busy || io.cpu.checker_clear || redirect_pending || redirect_settle ||
    s1_valid || s2_valid || // some fetch in flight
    !tlb.io.req.ready || // handling TLB miss
    !fq.io.mask(fq.io.mask.getWidth-1) // queue not full
  } // leaving gated-clock domain

  def alignPC(pc: UInt) = ~(~pc | (coreInstBytes - 1).U)

  def ccover(cond: Bool, label: String, desc: String)(implicit sourceInfo: SourceInfo) =
    property.cover(cond, s"FRONTEND_$label", "Rocket;;" + desc)
}

/** Mix-ins for constructing tiles that have an ICache-based pipeline frontend */
trait HasICacheFrontend extends CanHavePTW { this: BaseTile =>
  val module: HasICacheFrontendModule
  val frontend = LazyModule(new Frontend(tileParams.icache.get, staticIdForMetadataUseOnly))
  tlMasterXbar.node := frontend.masterNode
  connectTLSlave(frontend.slaveNode, tileParams.core.fetchBytes)
  frontend.icache.hartIdSinkNodeOpt.foreach { _ := hartIdNexusNode }
  frontend.icache.mmioAddressPrefixSinkNodeOpt.foreach { _ := mmioAddressPrefixNexusNode }
  frontend.resetVectorSinkNode := resetVectorNexusNode
  nPTWPorts += 1

  // This should be a None in the case of not having an ITIM address, when we
  // don't actually use the device that is instantiated in the frontend.
  private val deviceOpt = if (tileParams.icache.get.itimAddr.isDefined) Some(frontend.icache.device) else None
}

trait HasICacheFrontendModule extends CanHavePTWModule {
  val outer: HasICacheFrontend
  ptwPorts += outer.frontend.module.io.ptw
}
