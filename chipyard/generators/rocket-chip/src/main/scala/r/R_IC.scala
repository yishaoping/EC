package freechips.rocketchip.r

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import freechips.rocketchip.guardiancouncil._

case class R_ICParams(
  totalnumber_of_cores: Int,
  width_of_ic: Int
)

// Revisit: add check of the correct_process!
class R_ICIO(params: R_ICParams) extends Bundle {
  val ic_run_isax                                = Input(UInt(1.W))
  val ic_exit_isax                               = Input(UInt(1.W))
  val ic_syscall                                 = Input(UInt(1.W))
  val ic_syscall_back                            = Input(UInt(1.W))
  val rsu_busy                                   = Input(UInt(1.W))

  val priv_higher                                = Input(Bool())
  val priv_lower                                 = Input(Bool())
  val mode_switch                                = Input(Bool())
  val mode_ret                                   = Input(Bool())
  val excp_mode                                  = Input(Bool())

  val ic_threshold                               = Input(UInt((params.width_of_ic-1).W))
  val icsl_na                                    = Input(Vec(params.totalnumber_of_cores, UInt(1.W))) // FIFO快满了
  val ic_incr                                    = Input(UInt((3.W)))
  val if_ready_snap_shot                         = Input(UInt((1.W)))
  // The BOOM-side architectural boundary.  This is intentionally separate
  // from the older "can commit" hint, which only describes the current ROB
  // head and does not mean that the ROB is empty.
  val rob_empty                                   = Input(Bool())

  val crnt_target                                = Output(UInt(6.W))
  val old_crnt_target                            = Output(UInt(5.W))//used for ERCP
  val if_filtering                               = Output(UInt(1.W)) // 1: filtering; 0: non-filtering
  val if_pipeline_stall                          = Output(UInt(1.W))
  val if_dosnap                                  = Output(UInt(1.W))
  val if_dosnap_priv                             = Output(UInt(1.W))
  // Freeze new dispatch while the ROB drains and while the snapshot request
  // is accepted.  Retirement is controlled separately by if_pipeline_stall.
  val snapshot_drain                             = Output(Bool())
  val snapshot_capture                           = Output(Bool())
  val closing_valid                              = Output(Bool())
  val closing_seq                                = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val close_tail_ready                           = Input(Bool())

  val icsl_na_ack                                = Output(Vec(params.totalnumber_of_cores, Bool()))
  val big_checker_switch                         = Output(Vec(params.totalnumber_of_cores, Bool()))//大核事件导致切换

  val ic_counter                                 = Output(Vec(params.totalnumber_of_cores, UInt(params.width_of_ic.W)))
  val ic_status                                  = Output(Vec(params.totalnumber_of_cores, UInt(1.W)))
  val clear_ic_status                            = Input(Vec(params.totalnumber_of_cores, UInt(1.W)))
  val if_correct_process                         = Input(UInt((1.W)))
  val num_of_checker                             = Input(UInt((8.W)))
  val changing_num_of_checker                    = Input(UInt((1.W)))
  val core_trace                                 = Input(UInt((1.W)))
  val ic_trace                                   = Input(UInt((1.W)))

  val debug_perf_reset                           = Input(UInt((1.W)))
  val debug_perf_sel                             = Input(UInt(3.W))
  val debug_perf_val                             = Output(UInt(64.W))
  val debug_maincore_status                      = Output(UInt(4.W))
  val shared_CP_CFG                              = Output(UInt(13.W))
  //===== Runtime Configurable Mapping =====//
  val big_core_id                                = Input(UInt(4.W))                                      // which big core this R_IC belongs to (1-indexed: 1=hartId0, 2=hartId1)
  val checker_enable_mask                        = Input(UInt(GH_GlobalParams.GH_CHECKER_MASK_WIDTH.W)) // per-checker enable bitmap
  val checker_enable_we                          = Input(UInt(1.W))                                     // write strobe
  val checker_enable_rd                          = Output(UInt(GH_GlobalParams.GH_CHECKER_MASK_WIDTH.W))// readback
  val checker_big_owner                          = Output(Vec(params.totalnumber_of_cores, UInt(4.W)))  // which big core owns this checker
  val checker_segment_id                         = Output(Vec(params.totalnumber_of_cores, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
  val active_packet_seq                          = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val packet_alloc_valid                         = Output(Bool())
  val packet_alloc_seq                           = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val barrier_force_close                        = Input(Bool())
  val barrier_force_close_seq                    = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val barrier_close_ack                          = Output(Bool())
  val barrier_close_ack_seq                      = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))

  // Global ic_status: OR of all big cores' local ic_status, broadcast from GHM
  // Used by scheduler to avoid dispatching to a checker already busy under another big core
  val global_ic_status                           = Input(Vec(params.totalnumber_of_cores, UInt(1.W)))
}

trait HasR_ICIO extends BaseModule {
  val params: R_ICParams
  val io = IO(new R_ICIO(params))
}

class R_IC (val params: R_ICParams) extends Module with HasR_ICIO {
  val crnt_target                               = RegInit(0.U(3.W))
  val old_crnt_target                           = RegInit(0.U(5.W))
  val crnt_mask                                 = RegInit(0.U(6.W))
  val nxt_target                                = RegInit(0.U(3.W))
  val ctrl                                      = RegInit(0.U(3.W))

  val if_filtering                              = WireInit(0.U(1.W))
  val if_pipeline_stall                         = WireInit(0.U(1.W))
  val if_dosnap                                 = WireInit(0.U(1.W))
  val if_dosnap_priv                            = WireInit(0.U(1.W))
  val sch_reset                                 = WireInit(0.U(1.W))

  val ic_counter                                = RegInit(VecInit(Seq.fill(params.totalnumber_of_cores)(0.U(params.width_of_ic.W))))
  val ic_status                                 = RegInit(VecInit(Seq.fill(params.totalnumber_of_cores)(0.U(1.W)))) // 0: idle; 1: running
  val clear_ic_status                           = WireInit(VecInit(Seq.fill(params.totalnumber_of_cores)(0.U(1.W)))) // 0: idle; 1: running
  // Keep a local ownership bit in addition to the broadcast ic_status.  The
  // latter crosses from BOOM/GHM and can be observed low for a cycle while a
  // previous package is still being handed off.  Allocation must be
  // serialized until the matching result-release clear is observed locally.
  val package_owned                              = RegInit(VecInit(Seq.fill(params.totalnumber_of_cores)(false.B)))

  // Multi-big-core: checker indices in the full ic_status vector are offset by GH_NUM_BIG_CORES
  val num_checkers                               = params.totalnumber_of_cores - GH_GlobalParams.GH_NUM_BIG_CORES
  val chk_adj                                    = (GH_GlobalParams.GH_NUM_BIG_CORES - 1).U

  //===== Runtime Configurable Mapping =====//
  // checker_enable_mask: per-checker enable, default all enabled (padded to CHECKER_MASK_WIDTH)
  val checker_enable_reg                         = RegInit(((1 << num_checkers) - 1).U(GH_GlobalParams.GH_CHECKER_MASK_WIDTH.W))
  when (io.checker_enable_we === 1.U) {
    checker_enable_reg                          := io.checker_enable_mask
  }
  io.checker_enable_rd                          := checker_enable_reg

  // checker_big_owner: which big core last dispatched to this checker (persists across segments)
  val checker_big_owner_reg                      = RegInit(VecInit(Seq.fill(params.totalnumber_of_cores)(0.U(4.W))))
  val checker_segment_id_reg                     = RegInit(VecInit(Seq.fill(params.totalnumber_of_cores)(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))))
  val packet_seq_counter                         = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val active_packet_seq                          = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val barrierCloseAckReg                         = RegInit(false.B)
  val barrierCloseAckSeqReg                      = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  // Retirement ownership is independent of the scheduler's next target.
  val producer_open                              = RegInit(false.B)
  val producer_target                            = RegInit(0.U(3.W))
  val boundary_has_old                           = RegInit(false.B)
  val boundary_seq                               = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val boundary_priv                              = RegInit(false.B)
  // Snapshot readiness is intentionally two-phase.  The core-side quiet
  // predicate may rise immediately after the edge that drains the ROB; keep
  // an armed bit so acceptance is evaluated on a later full cycle rather
  // than as a half-cycle combinational pulse.
  val snapshot_armed                            = RegInit(false.B)
  val packet_alloc_valid_reg                    = RegInit(false.B)
  val packet_alloc_seq_reg                      = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))


  // Track owner: capture on first idle→busy transition, clear when idle & excluded from mask
  for (i <- 0 until num_checkers) {
    val idx = i + GH_GlobalParams.GH_NUM_BIG_CORES  // full ic_status index
    when ((ic_status(idx) === 1.U) && (checker_big_owner_reg(idx) === 0.U)) {
      checker_big_owner_reg(idx)                := io.big_core_id
    }
    // Release owner when checker becomes idle AND is no longer in our partition mask
    when ((!checker_enable_reg(i))) {
      checker_big_owner_reg(idx)                := 0.U
    }
    io.checker_big_owner(idx)                   := checker_big_owner_reg(idx)
    io.checker_segment_id(idx)                  := checker_segment_id_reg(idx)
  }
  for (i <- 0 until GH_GlobalParams.GH_NUM_BIG_CORES) {
    io.checker_big_owner(i)                     := 0.U
    io.checker_segment_id(i)                    := 0.U
  }

  // FPS scheduler — checker_enable_mask restricts available checkers
  val sch_result                                = WireInit(0.U(5.W))
  val u_sch_fp                                  = Module (new GHT_SCH_ANYAVILIABLE(GHT_SCH_Params (num_checkers)))
  u_sch_fp.io.core_s                           := 1.U
  u_sch_fp.io.core_e                           := num_checkers.U
  u_sch_fp.io.inst_c                           := 1.U // Holding the scheduling results

  for (i <- 0 until num_checkers) {
    // core_na = 1 means checker is NOT available (busy under ANY big core OR disabled by mask)
    u_sch_fp.io.core_na(i)                     := io.global_ic_status(i + GH_GlobalParams.GH_NUM_BIG_CORES) |
                                                     package_owned(i + GH_GlobalParams.GH_NUM_BIG_CORES) |
                                                     (!checker_enable_reg(i))
  }
  sch_result                                   := u_sch_fp.io.sch_dest
  u_sch_fp.io.rst_sch                          := sch_reset

  // Full-core-index views — use these everywhere in the FSM
  val crnt_target_ic                             = WireInit(crnt_target + chk_adj)
  val sch_result_ic                              = WireInit(sch_result  + chk_adj)


  // FSM to control the R_IC
  val fsm_reset :: fsm_presch :: fsm_sch :: fsm_cooling :: fsm_snap :: fsm_trans :: fsm_check :: fsm_postcheck :: Nil = Enum(8)
  val fsm_state                                 = RegInit(fsm_reset)
  val fsm_ini                                   = RegInit(0.U(1.W))
  val cooling_counter                           = RegInit(0.U(4.W))
  val cooling_threshold                         = 0.U
  cooling_counter                              := Mux((fsm_state =/= fsm_cooling), 0.U, Mux(cooling_counter < cooling_threshold, cooling_counter + 1.U, cooling_counter))
  val if_cooled                                 = Mux((cooling_counter >= cooling_threshold) && !io.rsu_busy.asBool, true.B, false.B)
  sch_reset                                    := Mux((fsm_state === fsm_reset) || (io.changing_num_of_checker.asBool), 1.U, 0.U)
  val producer_target_ic = producer_target + chk_adj
  val scheduler_available = sch_result >= 1.U && sch_result <= num_checkers.U &&
    !io.global_ic_status(sch_result_ic).asBool && !package_owned(sch_result_ic) &&
    !io.clear_ic_status(sch_result_ic).asBool && checker_enable_reg(sch_result - 1.U)
  val selected_available = crnt_target >= 1.U && crnt_target <= num_checkers.U &&
    !io.global_ic_status(crnt_target_ic).asBool && !package_owned(crnt_target_ic) &&
    !io.clear_ic_status(crnt_target_ic).asBool && checker_enable_reg(crnt_target - 1.U)
  val ic_exit_isax_buffer = RegInit(false.B)
  // PASS cannot release an open producer. An early CANCEL/FAIL must first
  // close its source; keep the owner/sequence until the old tail is sealed.
  val producer_release = producer_open && io.clear_ic_status(producer_target_ic).asBool
  when (fsm_state === fsm_reset) {
    ic_exit_isax_buffer := false.B
  }.elsewhen (io.ic_exit_isax.asBool || producer_release) {
    ic_exit_isax_buffer := true.B
  }
  val exit_requested = ic_exit_isax_buffer || io.ic_exit_isax.asBool || producer_release
  val capture_priv = boundary_priv || io.mode_switch || io.mode_ret || io.excp_mode
  val capture_ctrl = Mux(exit_requested, 3.U,
    Mux(!ctrl(0) && ctrl =/= 2.U && !selected_available,
      Mux(capture_priv, 5.U, 1.U), ctrl))
  // Keep the architectural boundary checked in both domains.  The core-side
  // guard prevents a combinational feedback path; this local check prevents a
  // stale/incorrect ready pulse from accepting a snapshot with a live ROB.
  val snapshot_ready                            = io.if_ready_snap_shot.asBool && io.rob_empty
  snapshot_armed                                := Mux(fsm_state =/= fsm_snap, false.B,
                                                       Mux(snapshot_ready, true.B, snapshot_armed))
  val snapshot_accept_candidate                  = (fsm_state === fsm_snap) &&
                                                   snapshot_armed &&
                                                   snapshot_ready
  val snapshot_allowed = snapshot_accept_candidate &&
    (producer_open || (!exit_requested && selected_available)) &&
    (capture_ctrl(0) || io.if_correct_process.asBool)
  if_dosnap := (snapshot_allowed && !capture_priv).asUInt
  if_dosnap_priv := (snapshot_allowed && capture_priv).asUInt
  val snapshot_accepted = (if_dosnap | if_dosnap_priv).asBool
  val close_capture = snapshot_accepted && producer_open
  // This edge is R_RSU's delayed architectural capture, not postcheck entry.
  val final_pending = RegNext(close_capture, false.B)
  val final_target = RegEnable(producer_target_ic, close_capture)
  val snapshot_drain_active = (fsm_state === fsm_postcheck) ||
    (fsm_state === fsm_cooling) || (fsm_state === fsm_snap) ||
    (fsm_state === fsm_trans) || (fsm_state === fsm_sch)
  val barrierCloseRequest = io.barrier_force_close && producer_open &&
    io.barrier_force_close_seq =/= 0.U &&
    active_packet_seq =/= 0.U &&
    active_packet_seq === io.barrier_force_close_seq
  // ACK is command acceptance, independent of instruction finalization/PASS.
  // A delayed/repeated request for an already closed sequence is idempotent.
  val barrierAlreadyClosed = io.barrier_force_close_seq =/= 0.U &&
    io.barrier_force_close_seq <= packet_seq_counter &&
    (!producer_open || io.barrier_force_close_seq < active_packet_seq)
  when (!io.barrier_force_close) {
    barrierCloseAckReg := false.B
  }.elsewhen (barrierAlreadyClosed ||
    (barrierCloseRequest && (fsm_state === fsm_check || fsm_state === fsm_postcheck ||
      fsm_state === fsm_cooling || fsm_state === fsm_snap))) {
    barrierCloseAckReg := true.B
    barrierCloseAckSeqReg := io.barrier_force_close_seq
  }
  val package_allocated = snapshot_accepted && !capture_ctrl(0)
  val allocated_packet_seq = packet_seq_counter + 1.U
  packet_alloc_valid_reg := false.B
  for (i <- 0 until params.totalnumber_of_cores) {
    when (clear_ic_status(i).asBool) {
      package_owned(i)                         := false.B
      checker_segment_id_reg(i)                 := 0.U
    }
  }
  when (package_allocated) {
    assert(!package_owned(crnt_target_ic) && !io.clear_ic_status(crnt_target_ic).asBool,
      "allocation before sequenced checker release")
    assert(allocated_packet_seq =/= 0.U, "packet sequence wrapped into reserved zero")
    producer_target := crnt_target
    packet_seq_counter := allocated_packet_seq
    active_packet_seq := allocated_packet_seq
    packet_alloc_valid_reg := true.B
    packet_alloc_seq_reg := allocated_packet_seq
    checker_segment_id_reg(crnt_target_ic) := allocated_packet_seq
    package_owned(crnt_target_ic)            := true.B
  }
  when (snapshot_accepted) {
    assert(io.ic_incr === 0.U, "snapshot accepted with counted retirement")
    boundary_has_old := producer_open
    boundary_seq := Mux(producer_open, active_packet_seq, 0.U)
    old_crnt_target := Mux(producer_open, producer_target, 0.U)
    producer_open := package_allocated
  }
  io.closing_valid := boundary_has_old && fsm_state === fsm_trans
  io.closing_seq := boundary_seq
  io.active_packet_seq := active_packet_seq
  // Registered allocation outputs form a complete-cycle fire event and keep
  // the allocated sequence stable while LSU/DCache sample it.  This prevents
  // the old combinational pulse from being visible externally without the
  // corresponding active_packet_seq update.
  io.packet_alloc_valid := packet_alloc_valid_reg
  io.packet_alloc_seq := packet_alloc_seq_reg
  io.barrier_close_ack := barrierCloseAckReg
  io.barrier_close_ack_seq := barrierCloseAckSeqReg
  // val if_t_and_na                               = Mux(((io.ic_exit_isax.asBool || io.ic_syscall.asBool || (ic_counter(crnt_target) >= io.ic_threshold) || io.icsl_na(crnt_target).asBool) && (ic_status(sch_result).asBool)), 1.U, 0.U)
  // val if_t_and_a                                = Mux(((io.ic_exit_isax.asBool || io.ic_syscall.asBool || (ic_counter(crnt_target) >= io.ic_threshold) || io.icsl_na(crnt_target).asBool) && (!ic_status(sch_result).asBool)), 1.U, 0.U)
  val if_t_and_na                               = Mux(((io.ic_exit_isax.asBool || io.mode_switch || io.mode_ret || (ic_counter(crnt_target_ic) >= io.ic_threshold) || io.icsl_na(crnt_target_ic).asBool) && (ic_status(sch_result_ic).asBool)), 1.U, 0.U)
  val if_t_and_a                                = Mux(((io.ic_exit_isax.asBool || io.mode_switch || io.mode_ret || (ic_counter(crnt_target_ic) >= io.ic_threshold) || io.icsl_na(crnt_target_ic).asBool) && (!ic_status(sch_result_ic).asBool)), 1.U, 0.U)
  fsm_ini                                      := Mux(fsm_state === fsm_reset, 1.U, Mux(fsm_state === fsm_presch, fsm_ini, 0.U))
  dontTouch(if_t_and_a)
  dontTouch(if_t_and_na)
  // Count every owned architectural retirement, including cooling/snap and
  // the closing edge. A future scheduling target must never receive this tail.
  for (i <- 0 until params.totalnumber_of_cores) {
    val count_owned = producer_open && producer_target_ic === i.U && io.if_correct_process.asBool
    val count_next = ic_counter(i)(params.width_of_ic - 2, 0) +& Mux(count_owned, io.ic_incr, 0.U)
    when (clear_ic_status(i).asBool) {
      ic_counter(i) := 0.U
    }.elsewhen (final_pending && final_target === i.U) {
      assert(ic_counter(i)(params.width_of_ic - 2, 0) <= GH_GlobalParams.GH_TOTAL_INSTS.U,
        "drained package exceeds configured instruction limit")
      ic_counter(i) := Cat(1.U(1.W), ic_counter(i)(params.width_of_ic - 2, 0))
    }.elsewhen (count_owned) {
      assert(!count_next(params.width_of_ic - 1), "package instruction count overflow")
      assert(!ic_counter(i)(params.width_of_ic - 1), "retirement after final package count")
      ic_counter(i) := count_next
    }
    when (package_allocated && crnt_target_ic === i.U) {
      ic_counter(i) := 0.U
    }
  }
  when (fsm_state === fsm_postcheck || fsm_state === fsm_cooling || fsm_state === fsm_snap) {
    boundary_priv := capture_priv
  }

  switch (fsm_state) {
    is (fsm_reset){ // 000
      boundary_priv                             := false.B
      ctrl                                      := 2.U
      crnt_target                               := 0.U
      crnt_mask                                 := 0.U
      nxt_target                                := 0.U
      if_filtering                              := 0.U
      if_pipeline_stall                         := 0.U
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      fsm_state                                 := fsm_presch
    }

    is (fsm_presch){ // 001
      boundary_priv                             := false.B
      ctrl                                      := 2.U
      crnt_target                               := crnt_target
      crnt_mask                                 := crnt_mask
      nxt_target                                := nxt_target
      if_filtering                              := 0.U
      if_pipeline_stall                         := Mux(fsm_ini.asBool, 0.U, io.if_correct_process.asBool)
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      fsm_state                                 := Mux(exit_requested, fsm_reset, Mux(fsm_ini.asBool, Mux(io.ic_run_isax.asBool, fsm_sch, fsm_presch), fsm_sch))
    }

    is (fsm_sch){ // 010
      // ctrl                                      := Mux(ctrl === 0.U, Mux(io.ic_syscall.asBool, 1.U, ctrl), ctrl)
      ctrl                                      := Mux((io.mode_switch || io.excp_mode) && if_t_and_a.asBool && (ctrl === 0.U), 4.U, ctrl)
      crnt_target                               := crnt_target
      crnt_mask                                 := crnt_mask
      nxt_target                                := Mux(scheduler_available && io.if_correct_process.asBool, sch_result, nxt_target)
      if_filtering                              := 0.U
      if_pipeline_stall                         := io.if_correct_process.asBool
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      // fsm_state                                 := Mux(!ic_status(sch_result).asBool && io.if_correct_process.asBool, fsm_cooling, Mux(io.ic_syscall.asBool, fsm_cooling, fsm_sch))
      fsm_state                                 := Mux(exit_requested, fsm_reset, Mux(scheduler_available && io.if_correct_process.asBool, fsm_cooling, fsm_sch))
    }

    is (fsm_cooling){ // 011
      ctrl                                      := Mux((io.mode_switch || io.excp_mode) && if_t_and_a.asBool && (ctrl === 0.U), 4.U, ctrl)
      crnt_target                               := Mux(if_cooled, nxt_target, crnt_target)
      crnt_mask                                 := crnt_mask
      nxt_target                                := nxt_target
      if_filtering                              := 0.U
      // New dispatch is blocked by snapshot_drain, but existing ROB entries
      // must still retire so rob_empty can become true.  Stalling here would
      // deadlock the rob_empty-gated snapshot handshake whenever cooling
      // begins with in-flight BOOM instructions.
      if_pipeline_stall                         := 0.U
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      fsm_state                                 := Mux(if_cooled, fsm_snap, fsm_cooling)
    }

    is (fsm_snap){ // 100
      // ctrl                                      := Mux(ctrl === 0.U, Mux(io.ic_syscall.asBool, 1.U, ctrl), ctrl)
      ctrl                                      := Mux((io.mode_switch || io.excp_mode) && if_t_and_a.asBool && (ctrl === 0.U), 4.U, ctrl)
      crnt_target                               := crnt_target
      // crnt_mask                                 := Mux((ctrl === 2.U) || (ctrl === 0.U), Mux(io.if_ready_snap_shot.asBool && io.if_correct_process.asBool, Cat(ctrl, crnt_target), crnt_mask), Mux(io.if_ready_snap_shot.asBool, Cat(ctrl, crnt_target), crnt_mask))      
      crnt_mask := Mux(snapshot_accepted, Cat(capture_ctrl, Mux(package_allocated, crnt_target, 0.U(3.W))), crnt_mask)
      nxt_target                                := nxt_target
      if_filtering                              := 0.U
      // Do not block retirement while waiting for the ROB to drain.  Once the
      // atomic snapshot pulse is accepted, the BOOM-side RSU hold freezes the
      // architectural state through R_RSU's delayed capture.
      if_pipeline_stall                         := Mux(snapshot_accepted,
                                                       io.if_correct_process.asBool,
                                                       false.B)
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U, Mux((crnt_target_ic === i.U) && package_allocated, 1.U, ic_status(i)))
      }
      //  fsm_state                                 := Mux((ctrl === 2.U) || (ctrl === 0.U), Mux(io.if_ready_snap_shot.asBool && io.if_correct_process.asBool, fsm_trans, fsm_snap), Mux(io.if_ready_snap_shot.asBool, fsm_trans, fsm_snap))
      when (snapshot_accepted) {
        ctrl := capture_ctrl
        fsm_state := fsm_trans
      }.elsewhen (!producer_open && (exit_requested || !selected_available)) {
        fsm_state := Mux(exit_requested, fsm_reset, fsm_sch)
      }
    }

    is (fsm_trans) {
      if_pipeline_stall := io.if_correct_process
      for (i <- 0 until params.totalnumber_of_cores) {
        ic_status(i) := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      // Hold frame routing through delayed capture, merge and source seal.
      when (!io.rsu_busy.asBool && (!boundary_has_old || io.close_tail_ready)) {
        when (exit_requested && producer_open) {
          ctrl := 3.U
          nxt_target := producer_target
          boundary_priv := io.excp_mode || io.mode_switch || io.mode_ret
          fsm_state := fsm_postcheck
        }.elsewhen (exit_requested || ctrl === 3.U) {
          fsm_state := fsm_reset
        }.elsewhen (ctrl === 1.U || ctrl === 5.U) {
          fsm_state := fsm_presch
        }.otherwise {
          boundary_priv := false.B
          fsm_state := fsm_check
        }
      }
    }

    is (fsm_check){ // 110
      boundary_priv := io.mode_switch || io.mode_ret || io.excp_mode
      // ctrl                                      := Mux(io.ic_exit_isax.asBool, 3.U, Mux(io.ic_syscall.asBool || if_t_and_na.asBool, 1.U, Mux(if_t_and_a.asBool, 0.U, ctrl)))
      // A barrier closes the current package, then continues normal checker
      // scheduling so the next snapshot allocates a fresh packet sequence.
      // ctrl=3 means "exit the whole checking session"; using it here sends
      // fsm_trans to fsm_reset and suppresses package_allocated because
      // package_allocated requires !ctrl(0). Keep the barrier path on the
      // ordinary package boundary (ctrl=0) while retaining the postcheck
      // transition below.
      ctrl                                      := Mux(io.ic_exit_isax.asBool, 3.U, Mux(barrierCloseRequest, 0.U, Mux(if_t_and_na.asBool && !(io.mode_switch || io.mode_ret || io.excp_mode), 1.U, Mux(if_t_and_na.asBool && (io.mode_switch || io.mode_ret || io.excp_mode), 5.U, Mux((io.mode_switch || io.mode_ret || io.excp_mode) && if_t_and_a.asBool, 4.U, Mux(if_t_and_a.asBool, 0.U, ctrl))))))
      crnt_target                               := crnt_target
      crnt_mask                                 := crnt_mask
      nxt_target                                := nxt_target 
      if_filtering                              := Mux(io.ic_exit_isax.asBool || io.ic_syscall.asBool || (ic_counter(crnt_target_ic) >= io.ic_threshold) || io.icsl_na(crnt_target_ic).asBool, 0.U, 1.U)
      if_pipeline_stall                         := Mux(io.ic_exit_isax.asBool || (io.mode_switch || io.mode_ret) || (ic_counter(crnt_target_ic) >= io.ic_threshold) || io.icsl_na(crnt_target_ic).asBool, 1.U, 0.U)
      for (i <- 0 to params.totalnumber_of_cores - 1) {
        ic_status(i)                            := Mux(clear_ic_status(i).asBool, 0.U,  ic_status(i))
      }
      fsm_state                                 := Mux(exit_requested || barrierCloseRequest || (io.mode_switch || io.mode_ret) || (ic_counter(crnt_target_ic) >= io.ic_threshold) || io.icsl_na(crnt_target_ic).asBool, fsm_postcheck, fsm_check)
    }

    is (fsm_postcheck) {
      val priv = capture_priv
      ctrl := Mux(exit_requested, 3.U,
        Mux(scheduler_available, Mux(priv, 4.U, 0.U), Mux(priv, 5.U, 1.U)))
      nxt_target := Mux(scheduler_available && !exit_requested, sch_result, producer_target)
      if_pipeline_stall := 0.U
      for (i <- 0 until params.totalnumber_of_cores) {
        ic_status(i) := Mux(clear_ic_status(i).asBool, 0.U, ic_status(i))
      }
      fsm_state := fsm_cooling
    }
  }


  if (GH_GlobalParams.GH_DEBUG == 1) {
    when ((io.ic_incr =/= 0.U) && (fsm_state === fsm_check) && (io.core_trace.asBool)) {
      printf(midas.targetutils.SynthesizePrintf("sl_counter=[%x]\n", (ic_counter(crnt_target_ic)+io.ic_incr)))
    }

    val fsm_state_delay                          = RegInit(fsm_reset)
    fsm_state_delay                              := fsm_state
    when ((fsm_state_delay =/= fsm_state) && (io.ic_trace.asBool)) {
      printf(midas.targetutils.SynthesizePrintf("fsm_state=[%x]\n", fsm_state))
    }
  }



  io.crnt_target                                := crnt_mask
  io.if_filtering                               := if_filtering & io.if_correct_process // Not used yet
  io.if_pipeline_stall                          := if_pipeline_stall & io.if_correct_process
  io.if_dosnap                                  := if_dosnap
  io.if_dosnap_priv                             := if_dosnap_priv
  io.snapshot_drain                             := snapshot_drain_active
  io.snapshot_capture                           := snapshot_accepted
  io.old_crnt_target                            := old_crnt_target
  // Preserve the boundary state in generated collateral for focused traces.
  dontTouch(fsm_state)
  dontTouch(snapshot_ready)
  dontTouch(snapshot_armed)
  dontTouch(snapshot_accept_candidate)
  dontTouch(snapshot_drain_active)
  dontTouch(producer_open)
  dontTouch(producer_target)
  dontTouch(final_pending)
  dontTouch(boundary_seq)
  dontTouch(snapshot_accepted)
  dontTouch(packet_alloc_valid_reg)
  dontTouch(packet_alloc_seq_reg)
  dontTouch(io.rob_empty)
  dontTouch(io.snapshot_drain)
  dontTouch(io.snapshot_capture)
  for (i <- 0 to params.totalnumber_of_cores - 1){
    io.icsl_na_ack(i)         := RegNext(io.icsl_na(i)&(fsm_state===fsm_check))
    io.big_checker_switch(i)  := (io.ic_exit_isax.asBool || io.ic_syscall.asBool || (ic_counter(i) >= io.ic_threshold))&&(crnt_target_ic===i.U)&&(fsm_state===fsm_check)
  }

  io.ic_counter                                 := ic_counter
  io.ic_status                                  := ic_status
  for (i <- 0 to params.totalnumber_of_cores - 1){
    val source_live = (producer_open && producer_target_ic === i.U) ||
      (boundary_has_old && fsm_state === fsm_trans && old_crnt_target + chk_adj === i.U) ||
      (final_pending && final_target === i.U)
    clear_ic_status(i) := (io.clear_ic_status(i).asBool && !source_live).asUInt
  }
  var nocore_available                           = WireInit(1.U(1.W))
  for (i <- GH_GlobalParams.GH_NUM_BIG_CORES to params.totalnumber_of_cores - 1){
    nocore_available                             = nocore_available & ic_status(i)
  }

  val debug_perf_CCounter                        = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_BCounter                        = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_SchState                        = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_CheckState                      = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_OtherThread                     = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_SchState_Allbusy                = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))
  val debug_perf_SchState_OT                     = RegInit(0.U(GH_GlobalParams.GH_WIDITH_PERF.W))



  val if_blocked_bySched                         = WireInit(false.B)
  if_blocked_bySched                            := ((fsm_state === fsm_sch) && io.if_correct_process.asBool) && ic_status(sch_result_ic).asBool

  debug_perf_CCounter                           := Mux(io.debug_perf_reset.asBool, 0.U, debug_perf_CCounter + 1.U)
  debug_perf_BCounter                           := Mux(io.debug_perf_reset.asBool, 0.U, Mux(if_blocked_bySched && !nocore_available.asBool, debug_perf_BCounter + 1.U, debug_perf_BCounter))
  debug_perf_SchState_Allbusy                   := Mux(io.debug_perf_reset.asBool, 0.U, Mux(if_blocked_bySched && nocore_available.asBool, debug_perf_SchState_Allbusy + 1.U, debug_perf_SchState_Allbusy))
  debug_perf_SchState                           := Mux(io.debug_perf_reset.asBool, 0.U, Mux(fsm_state === fsm_sch, debug_perf_SchState + 1.U, debug_perf_SchState))
  debug_perf_CheckState                         := Mux(io.debug_perf_reset.asBool, 0.U, Mux(fsm_state === fsm_check, debug_perf_CheckState + 1.U, debug_perf_CheckState))
  debug_perf_OtherThread                        := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_sch) && (!io.if_correct_process.asBool), debug_perf_OtherThread + 1.U, debug_perf_OtherThread))
  debug_perf_SchState_OT                        := Mux(io.debug_perf_reset.asBool, 0.U, Mux(!io.if_correct_process.asBool, debug_perf_SchState_OT + 1.U, debug_perf_SchState_OT))


  io.debug_perf_val                             := Mux(io.debug_perf_sel === 7.U, debug_perf_CCounter, 
                                                   Mux(io.debug_perf_sel === 1.U, debug_perf_BCounter,
                                                   Mux(io.debug_perf_sel === 2.U, debug_perf_SchState, 
                                                   Mux(io.debug_perf_sel === 3.U, debug_perf_CheckState,
                                                   Mux(io.debug_perf_sel === 4.U, debug_perf_OtherThread, 
                                                   Mux(io.debug_perf_sel === 5.U, debug_perf_SchState_Allbusy, 
                                                   Mux(io.debug_perf_sel === 6.U, debug_perf_SchState_OT, 0.U)))))))

  io.debug_maincore_status                      := Mux(!io.if_correct_process.asBool, 3.U,
                                                   Mux(fsm_state === fsm_sch, 1.U,
                                                   Mux(fsm_state === fsm_check, 2.U, 0.U)))
  // io.debug_perf_val                             := 0.U

  val one                                        = WireInit(1.U(1.W))
  val one_fourbits                               = WireInit(1.U(4.W))
  val seven_threebits                            = WireInit(7.U(3.W))
  val core_bitmap                                = WireInit(0.U(4.W))
  val cp_bitmap                                  = WireInit(0.U(8.W))
  

  core_bitmap                                   := (one_fourbits << (crnt_target - 1.U)) | (one_fourbits << (sch_result - 1.U))
  cp_bitmap                                     := Cat(sch_result, seven_threebits)
  

  io.shared_CP_CFG                              := Mux(((fsm_state === fsm_postcheck) && scheduler_available && io.if_correct_process.asBool && !exit_requested), Cat(one, cp_bitmap, core_bitmap), 0.U)
}
