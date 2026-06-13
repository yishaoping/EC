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

  val if_check_completed = Output(Bool())
  val if_overtaking = Output(Bool())
  val if_check_already_done = Output(Bool())
}

class Frontend(val icacheParams: ICacheParams, staticIdForMetadataUseOnly: Int)(implicit p: Parameters) extends LazyModule {
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

  val BJL = withReset(reset.asBool || io.cpu.if_check_already_done) { Module(new R_BJLR(R_BJLParams(
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
  
  val hasSpecialJalr = Wire(Bool())

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

  val s1_valid = Reg(Bool())
  val s2_valid = RegInit(false.B)
  val s0_fq_has_space =
    !fq.io.mask(fq.io.mask.getWidth-3) ||
    (!fq.io.mask(fq.io.mask.getWidth-2) && (!s1_valid || !s2_valid)) ||
    (!fq.io.mask(fq.io.mask.getWidth-1) && (!s1_valid && !s2_valid))
  val s0_valid = io.cpu.req.valid || s0_fq_has_space || !io.cpu.if_overtaking
  dontTouch(s0_fq_has_space)
  s1_valid := s0_valid
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
  val bjl_base_npc = ~(~BJL.io.bj_resp_npc | (fetchBytes - 1).U)
  val bjl_base_cpc = ~(~BJL.io.bj_resp_cpc | (fetchBytes - 1).U)
  val ntpc = s1_base_pc + fetchBytes.U
  val predicted_npc = WireDefault(ntpc)
  val predicted_taken = WireDefault(false.B)
  dontTouch(s1_base_pc)
  dontTouch(bjl_base_npc)
  dontTouch(bjl_base_cpc)
  dontTouch(ntpc)
  val s2_hascfi = Wire(Bool())
  val bjl_use_target = Wire(Bool())
  val bjl_taken_idx = WireInit(0.U(fetchWidth.W))
  // 步骤1：对齐 PC（确保与 BJL 存储的分支 PC 地址格式一致，避免低位错位）
  val aligned_cpu_cpc = alignPC(s1_pc)  // 即将发起取指的 PC（ICache 请求地址）
  val aligned_bjl_cpc = alignPC(BJL.io.bj_resp_cpc)  // BJL 头部的分支 PC
  val s2_bjl_cpc = RegEnable(alignPC(BJL.io.bj_resp_cpc), BJL.io.bj_req_valid && !BJL.io.bj_rollback)
  // 步骤2：PC 匹配条件（当前要取指的 PC == BJL 存储的分支 PC）
  // val pc_match = s1_valid && ((aligned_cpu_cpc - aligned_bjl_cpc) <= 2.U) && (Mux(BJL.io.bj_resp_is_rvc, true.B, aligned_bjl_cpc === bjl_base_cpc))
  val pc_match= s1_valid && (Mux(aligned_cpu_cpc === aligned_bjl_cpc, 
                                Mux(aligned_bjl_cpc === bjl_base_cpc, true.B, 
                                    Mux(BJL.io.bj_resp_is_rvc, true.B, false.B)), 
                                Mux((aligned_cpu_cpc - aligned_bjl_cpc) <= 2.U, true.B, 
                                    Mux(((aligned_bjl_cpc - aligned_cpu_cpc) <= 2.U) && BJL.io.bj_resp_is_rvc && (aligned_bjl_cpc =/= bjl_base_cpc), true.B, false.B))))
  val s2_pc_match = ((alignPC(s2_pc) - s2_bjl_cpc) <= 2.U) && s2_valid
  // 步骤3：BJL 有可用数据（FIFO 头部非空）
  val bjl_has_valid_data = BJL.io.bj_req_ready
  val bjl_just_have_data_at_s2 = !BJL.io.bj_data_ready_but_flow && s2_pc_match
  val bjl_need_replay = (!RegNext(bjl_has_valid_data) || bjl_just_have_data_at_s2) && checkerMode && !RegNext(bjl_use_target) && s2_hascfi && !(io.cpu.if_check_already_done) && !hasSpecialJalr //bjl空了导致的replay
  val bjl_redirect_replay = s2_redirect && !io.cpu.req.valid && RegNext(bjl_use_target) && !bjl_has_valid_data && checkerMode && s2_valid //pc包含两条rvc br/jal指令,同时bjl空造成的redirect replay
  val s2_bjl_taken = Reg(Bool())
  val s2_bjl_is_rvc = Reg(Bool())
  val s2_bjl_npc   = RegEnable(alignPC(BJL.io.bj_resp_npc), BJL.io.bj_req_valid && !BJL.io.bj_rollback)
  s2_bjl_taken := Mux(BJL.io.bj_req_valid && !BJL.io.bj_rollback, BJL.io.bj_resp_taken, false.B)
  s2_bjl_is_rvc := Mux(BJL.io.bj_req_valid && !BJL.io.bj_rollback, BJL.io.bj_resp_is_rvc, false.B)

  val s2_replay = Wire(Bool())
  s2_replay := (s2_valid && !fq.io.enq.fire) || RegNext(s2_replay && !s0_valid, true.B) || bjl_need_replay || bjl_redirect_replay
  val bjl_redirect_replay_continue = RegNext(bjl_redirect_replay)
  val npc = Mux(bjl_redirect_replay || bjl_redirect_replay_continue, s2_bjl_npc, Mux(s2_replay, s2_pc, predicted_npc))

  val replay_pc_cfi = RegInit(0.U(vaddrBitsExtended.W))
  replay_pc_cfi := Mux(bjl_need_replay && io.cpu.req.valid && (io.cpu.req.bits.pc === s2_pc), s2_pc, Mux(bjl_use_target || io.cpu.if_check_completed, 0.U, replay_pc_cfi))
  dontTouch(replay_pc_cfi)

  dontTouch(bjl_need_replay)
  dontTouch(pc_match)
  dontTouch(aligned_cpu_cpc)
  dontTouch(aligned_bjl_cpc)
  dontTouch(bjl_redirect_replay)
  dontTouch(s2_bjl_npc)

  s1_pc := io.cpu.npc
  // consider RVC fetches across blocks to be non-speculative if the first
  // part was non-speculative
  val s0_speculative =
    if (usingCompressed) s1_speculative || s2_valid && !s2_speculative || predicted_taken
    else true.B
  s1_speculative := Mux(io.cpu.checker_mode, false.B, Mux(io.cpu.req.valid, io.cpu.req.bits.speculative, Mux(s2_replay, s2_speculative, s0_speculative)))
  dontTouch(s0_speculative)

  
  s2_valid := false.B
  when (!s2_replay) {
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
  tlb.io.req.valid := s1_valid && !s2_replay
  tlb.io.req.bits.cmd := M_XRD // Frontend only reads
  tlb.io.req.bits.vaddr := s1_pc
  tlb.io.req.bits.passthrough := false.B
  tlb.io.req.bits.size := log2Ceil(coreInstBytes*fetchWidth).U
  tlb.io.req.bits.prv := io.ptw.status.prv
  tlb.io.req.bits.v := io.ptw.status.v
  tlb.io.sfence := io.cpu.sfence
  tlb.io.kill := !s2_valid || s2_kill_speculative_tlb_refill

  icache.io.req.valid := s0_valid
  icache.io.req.bits.addr := io.cpu.npc
  icache.io.invalidate := io.cpu.flush_icache
  icache.io.s1_paddr := tlb.io.resp.paddr
  icache.io.s2_vaddr := s2_pc
  icache.io.s1_kill := s2_redirect || tlb.io.resp.miss || s2_replay
  val s2_can_speculatively_refill = s2_tlb_resp.cacheable && !io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableSpeculativeICacheRefill
  icache.io.s2_kill := s2_speculative && !s2_can_speculatively_refill || s2_xcpt
  icache.io.s2_cacheable := s2_tlb_resp.cacheable
  icache.io.s2_prefetch := s2_tlb_resp.prefetchable && !io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableICachePrefetch

  fq.io.enq.valid := RegNext(s1_valid) && s2_valid && !bjl_need_replay && (icache.io.resp.valid || (s2_kill_speculative_tlb_refill && s2_tlb_resp.miss) || (!s2_tlb_resp.miss && icache.io.s2_kill))
  fq.io.enq.bits.pc := s2_pc
  val s1_pc_need_replay = s1_valid && (s1_pc === replay_pc_cfi) && !bjl_use_target && !io.cpu.if_check_completed
  dontTouch(s1_pc_need_replay)
  io.cpu.npc := alignPC(Mux(s1_pc_need_replay, s1_pc, Mux(io.cpu.req.valid, io.cpu.req.bits.pc, npc)))

  fq.io.enq.bits.data := icache.io.resp.bits.data
  fq.io.enq.bits.mask := ((1 << fetchWidth)-1).U << s2_pc.extract(log2Ceil(fetchWidth)+log2Ceil(coreInstBytes)-1, log2Ceil(coreInstBytes))
  fq.io.enq.bits.replay := (icache.io.resp.bits.replay || icache.io.s2_kill && !icache.io.resp.valid && !s2_xcpt) || (s2_kill_speculative_tlb_refill && s2_tlb_resp.miss)
  fq.io.enq.bits.btb := s2_btb_resp_bits
  fq.io.enq.bits.btb.bridx := Mux(checkerMode, bjl_taken_idx, s2_btb_resp_bits.bridx)
  fq.io.enq.bits.btb.taken := Mux(checkerMode, s2_bjl_taken, s2_btb_taken)
  fq.io.enq.bits.xcpt := s2_tlb_resp
  assert(!(s2_speculative && io.ptw.customCSRs.asInstanceOf[RocketCustomCSRs].disableSpeculativeICacheRefill && !icache.io.s2_kill))
  when (icache.io.resp.valid && icache.io.resp.bits.ae) { fq.io.enq.bits.xcpt.ae.inst := true.B }

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
    when (!s2_replay && !checkerMode) {
      btb.io.req.valid := !s2_redirect
      s2_btb_resp_valid := btb.io.resp.valid
      s2_btb_resp_bits := btb.io.resp.bits
    }
    when (!checkerMode && btb.io.resp.valid && btb.io.resp.bits.taken) {
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

   
    // val s2_bjl_npc   = RegEnable(alignPC(BJL.io.bj_resp_npc), BJL.io.bj_req_valid && !BJL.io.bj_rollback)

    val s2_bjl_replay = s2_replay && RegNext(BJL.io.bj_req_valid) && s2_valid && !s2_redirect // 到达s2的match的pc由于icache miss replay，排除由于pc包含两条br/jal指令造成的redirect replay

    bjl_taken_idx := Mux(s2_pc_match, Mux(s2_bjl_cpc === s2_base_pc, Mux(s2_bjl_is_rvc && s2_bjl_taken, 0.U, 1.U), Mux(s2_bjl_cpc > s2_base_pc, 1.U, 0.U)), 1.U)
    dontTouch(s2_pc_match)
    // val s2_bjl_npc   = RegEnable(alignPC(BJL.io.bj_resp_npc), BJL.io.bj_req_valid)
    dontTouch(bjl_taken_idx)
    
    // val bjl_taken = Mux(rvc, s2_bjl_npc =/= s2_bjl_cpc + 2.U, s2_bjl_npc =/= s2_bjl_cpc + 4.U)
    dontTouch(s2_btb_resp_bits)
    def scanInsns(idx: Int, prevValid: Bool, prevBits: UInt, prevTaken: Bool, prevHasCF: Bool): (Bool, Bool) = {
      def insnIsRVC(bits: UInt) = bits(1,0) =/= 3.U
      val prevRVI = prevValid && !insnIsRVC(prevBits)
      val valid = fq.io.enq.bits.mask(idx) && !prevRVI
      val bits = fq.io.enq.bits.data(coreInstBits*(idx+1)-1, coreInstBits*idx)
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

      // bjl_taken_idx := Mux((s2_bjl_cpc === s2_base_pc), Mux(rvc && s2_bjl_taken && !prevRVI, 0.U, 1.U), 0.U)

      when (s2_valid && s2_btb_resp_valid && s2_btb_resp_bits.bridx === idx.U && valid && !rvc && !checkerMode) {
        // The BTB has predicted that the middle of an RVI instruction is
        // a branch! Flush the BTB and the pipeline.
        btb.io.flush := true.B
        fq.io.enq.bits.replay := true.B
        wrong_path := true.B
        ccover(wrong_path, "BTB_NON_CFI_ON_WRONG_PATH", "BTB predicted a non-branch was taken while on the wrong path")
      }

      when (!prevTaken) {
        taken_idx := idx.U
        after_idx := (idx + 1).U
        btb.io.ras_update.valid := fq.io.enq.fire && !wrong_path && (prevRVI && (rviCall || rviReturn) || valid && (rvcCall || rvcReturn))
        btb.io.ras_update.bits.cfiType := Mux(Mux(prevRVI, rviReturn, rvcReturn), CFIType.ret,
                                          Mux(Mux(prevRVI, rviCall, rvcCall), CFIType.call,
                                          Mux(Mux(prevRVI, rviBranch, rvcBranch) && !force_taken, CFIType.branch,
                                          CFIType.jump)))

        when (!s2_btb_taken && !checkerMode) {
          when (fq.io.enq.fire && taken && !predictBranch && !predictJump && !predictReturn) {
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
          btb.io.bht_advance.valid := fq.io.enq.fire && !wrong_path
          btb.io.bht_advance.bits := s2_btb_resp_bits
        }
        when (!s2_btb_resp_valid && (predictBranch && s2_btb_resp_bits.bht.strongly_taken || predictJump || predictReturn)) {
          updateBTB := true.B
        }
      }

      if (idx == fetchWidth-1) {
        when (fq.io.enq.fire) {
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
      btb.io.btb_update.valid := fq.io.enq.fire && !wrong_path && fetch_bubble_likely && updateBTB && !checkerMode
      btb.io.btb_update.bits.prediction.entry := tileParams.btb.get.nEntries.U
      btb.io.btb_update.bits.isValid := true.B
      btb.io.btb_update.bits.cfiType := btb.io.ras_update.bits.cfiType
      btb.io.btb_update.bits.br_pc := s2_base_pc | (taken_idx << log2Ceil(coreInstBytes))
      btb.io.btb_update.bits.pc := s2_base_pc
    }

    btb.io.ras_update.bits.returnAddr := s2_base_pc + (after_idx << log2Ceil(coreInstBytes))

    val (taken, hasControlFlow) = scanInsns(0, s2_partial_insn_valid, s2_partial_insn, false.B, false.B)
    s2_hascfi := hasControlFlow 
    dontTouch(hasControlFlow)
    hasSpecialJalr := specialJalrVec.reduce(_||_)
    when (useRAS) {
      predicted_npc := btb.io.ras_head.bits
    }
    when (fq.io.enq.fire && (Mux(checkerMode, s2_bjl_taken, s2_btb_taken) || taken)) {
      s2_partial_insn_valid := false.B
    }
    when (!Mux(checkerMode, s2_bjl_taken, s2_btb_taken)) {
      when (taken) {
        fq.io.enq.bits.btb.bridx := taken_idx
        fq.io.enq.bits.btb.taken := true.B
        fq.io.enq.bits.btb.entry := tileParams.btb.get.nEntries.U
        when (fq.io.enq.fire) { s2_redirect := true.B }
      }
    }

    assert(!s2_partial_insn_valid || fq.io.enq.bits.mask(0))
    when (s2_redirect) { s2_partial_insn_valid := false.B }
    when (io.cpu.req.valid) { wrong_path := false.B }
    dontTouch(specialJalrVec)
    dontTouch(hasSpecialJalr)

    // 在 checker 模式下：如果是“特殊 JALR”（bit12=1 的 JALR），则不从 BJL 取目标地址
    bjl_use_target := checkerMode && pc_match && bjl_has_valid_data && !s2_replay
    BJL.io.bj_req_valid := bjl_use_target
    BJL.io.bj_rollback := (io.cpu.req.valid) && checkerMode && !io.cpu.if_check_completed
    BJL.io.bj_s2_replay := s2_bjl_replay && checkerMode
    BJL.io.bj_commit_valid := io.cpu.bjl_commit && checkerMode
    val bjl_notaken_npc = Mux(BJL.io.bj_resp_npc =/= bjl_base_npc, 
                              Mux(BJL.io.bj_resp_is_rvc || ((BJL.io.bj_resp_cpc =/= bjl_base_cpc)), bjl_base_npc + fetchBytes.U, BJL.io.bj_resp_npc), 
                              Mux(BJL.io.bj_resp_npc === aligned_cpu_cpc, bjl_base_npc + fetchBytes.U, BJL.io.bj_resp_npc))
    when (bjl_use_target && bjl_has_valid_data) {
      predicted_npc := Mux(BJL.io.bj_resp_taken, BJL.io.bj_resp_npc, bjl_notaken_npc)
      // predicted_taken := true.B
    }
    // when (bjl_use_target && !BJL.io.bj_req_ready) {
    //   s2_replay := true.B
    // }
  }
  dontTouch(icache.io)
  dontTouch(predicted_taken)
  dontTouch(io)
  dontTouch(npc)
  io.cpu.resp <> fq.io.deq

  // supply guest physical address to commit stage
  val gpa_valid = Reg(Bool())
  val gpa = Reg(UInt(vaddrBitsExtended.W))
  when (fq.io.enq.fire && s2_tlb_resp.gf.inst) {
    when (!gpa_valid) {
      gpa := s2_tlb_resp.gpa
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
