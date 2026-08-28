package freechips.rocketchip.r

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import freechips.rocketchip.guardiancouncil._

case class R_ICSLParams(
  width_of_ic: Int
)

class R_ICSLIO(params: R_ICSLParams) extends Bundle {
  val ic_counter                                 = Input(UInt((params.width_of_ic).W))
  val icsl_run                                   = Input(UInt(1.W))
  // val icsl_ack                                   = Input(Bool())
  val big_switch                                 = Input(Bool())
  val cdc_empty                                  = Input(Bool())
  val lsl_empty                                  = Input(Bool())
  val new_commit                                 = Input(UInt(1.W))
  val if_correct_process                         = Input(UInt(1.W))
  val returned_to_special_address_valid          = Input(UInt(1.W))

  val self_xcpt                                  = Input(Bool())
  val self_ret                                   = Input(Bool())

  val if_check_done                              = Output(Bool())
  val if_check_privrun                           = Input(Bool())
  val if_check_privret                           = Output(Bool())

  val excpt_mode                                 = Input(Bool())
  ///////////not used////
  // val if_big_complete                            = Output(Bool())
  // val big_complete                               = Input(Bool()) 
  //////////////////////
  val kill_pipe                                  = Output(Bool())
  val icsl_checkermode                           = Output(UInt(1.W))
  val icsl_checkerpriv_mode                      = Output(UInt(1.W))
  val clear_ic_status                            = Output(UInt(1.W))
  val if_overtaking                              = Output(UInt(1.W))
  val if_overtaking_next_cycle                   = Output(UInt(1.W))
  val if_ret_special_pc                          = Output(UInt(1.W))
  val if_rh_cp_pc                                = Output(UInt(1.W))
  val if_check_completed                         = Input(UInt(1.W))
  val if_check_cancelled                         = Input(Bool())
  // Sticky execution completion is separate from the one-cycle package-tail
  // notification.  RocketCore uses it to keep result creation ordered with
  // the instruction stream without making BOOM release depend on local reset.
  val package_exec_done                          = Output(Bool())
  // The checker has reached a trap-free postchecking boundary. RocketCore
  // adds register-file writeback quiescence before taking the ARF snapshot.
  val arch_compare_ready                         = Output(Bool())
  // Indicates that this FSM can accept a new package after local cleanup.
  val cleanup_done                               = Output(Bool())
  // Package storage can be clean while an architectural trap or a held return
  // is still outstanding.  New package admission must use context_idle rather
  // than cleanup_done so execution contexts cannot leak across packages.
  val context_idle                               = Output(Bool())
  val return_pending                             = Output(Bool())
  val trap_depth                                 = Output(UInt(4.W))
  val icsl_status                                = Output(UInt(2.W))
  val debug_sl_counter                           = Output(UInt(params.width_of_ic.W))
  val core_trace                                 = Input(UInt(1.W))
  val something_inflight                         = Input(UInt(1.W))
  val num_valid_insts_in_pipeline                = Input(UInt(4.W))
  val icsl_stalld                                = Output(Bool())
  val core_id                                    = Input(UInt(4.W))
  val already_done                               = Output(Bool())

  val debug_perf_reset                           = Input(UInt(1.W))
  val debug_perf_start                           = Input(Bool())
  val debug_perf_stop                            = Input(Bool())
  val debug_state                                = Output(UInt(3.W))
  val debug_perf_sel                             = Input(UInt(4.W))
  val debug_perf_val                             = Output(UInt(64.W))   
  val csr_cycle                                  = Input(UInt(64.W))
  val traffic_counter                            = Output(Vec(GH_GlobalParams.GH_TRAFFIC_COUNTERS, UInt(64.W)))
  val debug_starting_CPS                         = Input(UInt(1.W))
  val main_core_status                           = Input(UInt(4.W))
  val checker_core_status                        = Output(UInt(4.W))
  val st_deq                                     = Input(UInt(1.W))
  val ld_deq                                     = Input(UInt(1.W))
  val st_cache_deq                               = Input(UInt(1.W))
  val st_uncache_deq                             = Input(UInt(1.W))
  val ld_cache_deq                               = Input(UInt(1.W))
  val ld_uncache_deq                             = Input(UInt(1.W))
  val lr_deq                                     = Input(UInt(1.W))
  val sc_success_deq                             = Input(UInt(1.W))
  val sc_fail_deq                                = Input(UInt(1.W))
  val amo_cache_deq                              = Input(UInt(1.W))
  val amo_uncache_deq                            = Input(UInt(1.W))
}

trait HasR_ICSLIO extends BaseModule {
  val params: R_ICSLParams
  val io = IO(new R_ICSLIO(params))
}

class R_ICSL (val params: R_ICSLParams) extends Module with HasR_ICSLIO {
  val fsm_reset :: fsm_nonchecking :: fsm_checking :: fsm_checking_priv :: fsm_self_xcpt :: fsm_self_xcpt_priv :: fsm_postchecking :: fsm_postchecking_priv :: Nil = Enum(8)
  val fsm_state                                  = RegInit(fsm_reset)

  io.debug_state := fsm_state

  val ic_counter_shadow                          = RegInit(0.U((params.width_of_ic-1).W))
  val ic_counter_done                            = RegInit(0.U(1.W))
  val icsl_run                                   = WireInit(0.U(1.W))
  
  val icsl_checkermode                           = WireInit(0.U(1.W))
  val icsl_checkerpriv_mode                      = WireInit(0.U(1.W))
  val clear_ic_status                            = WireInit(0.U(1.W))

  val if_overtaking                              = RegInit(0.U(1.W))
  val if_overtaking_priv                         = RegInit(0.U(1.W))
  val if_ret_special_pc                          = RegInit(0.U(1.W))

  // Keep exception context orthogonal to package progress.  In particular, an
  // interrupt in postchecking resumes postchecking after the matching xRET;
  // it must never fall through to the management PC while the trap is live.
  val trap_depth                                 = RegInit(0.U(4.W))
  val trap_depth_overflow                        = RegInit(false.B)
  val resume_state                               = RegInit(fsm_nonchecking)

  val if_rh_cp_pc                                = WireInit(0.U(1.W))

  val sl_counter                                  = RegInit(0.U(params.width_of_ic.W))
  // ARF/CSR/LSL completion is the common terminal condition for normal and
  // privileged packages. Keep an early pulse until either postchecking state
  // consumes it.
  val package_completion_seen                     = RegInit(false.B)
  val package_completion_ready                    = io.if_check_completed.asBool ||
                                                    package_completion_seen
  val package_exec_done_seen                      = RegInit(false.B)
  val privileged_return_issued                    = RegInit(false.B)
  val cancellation_return_pending                 = RegInit(false.B)
  val if_completion                              = Mux((io.if_correct_process.asBool && (fsm_state === fsm_checking) && ((sl_counter>= (ic_counter_shadow+1.U)) || (io.new_commit.asBool && ((sl_counter + 1.U) >= (ic_counter_shadow + 1.U)))) && ic_counter_done.asBool), true.B, false.B)
  val if_completion_priv                         = Mux((io.if_correct_process.asBool && (fsm_state === fsm_checking_priv) && ((sl_counter>= (ic_counter_shadow)) || (io.new_commit.asBool && ((sl_counter + 1.U) >= (ic_counter_shadow)))) && ic_counter_done.asBool), true.B, false.B)
  // val if_slow_completion                         = Mux((io.if_correct_process.asBool && (sl_counter >= ic_counter_shadow) && ic_counter_done.asBool), true.B, false.B)
  val if_just_overtaking                         = Mux((io.if_correct_process.asBool && io.new_commit.asBool && ((sl_counter + 1.U) >= ic_counter_shadow + 1.U) && (fsm_state === fsm_checking)), 1.U, 0.U)
  val if_just_overtaking_priv                    = Mux((io.if_correct_process.asBool && io.new_commit.asBool && ((sl_counter + 1.U) >= ic_counter_shadow) && (fsm_state === fsm_checking_priv)), 1.U, 0.U)
  val instruction_completion                     = (if_completion || if_completion_priv) &&
                                                    !io.something_inflight

  

  // val icsl_check_speed                           = sl_counter===(GH_GlobalParams.GH_TOTAL_INSTS-4).U //
  // val icsl_exec_done                             = sl_counter===(ic_counter_shadow+1.U)&&(fsm_state===fsm_speed_check)
  // val exec_last_one                              = RegInit(false.B)
  
  ic_counter_done                               := io.ic_counter(params.width_of_ic-1)
  dontTouch(if_completion)
  dontTouch(if_completion_priv)
  switch (fsm_state) {
    is (fsm_reset) {
      trap_depth                                := 0.U
      trap_depth_overflow                       := false.B
      resume_state                              := fsm_nonchecking
      sl_counter                                := 0.U
      clear_ic_status                           := 1.U
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := 0.U
      if_rh_cp_pc                               := 0.U
      fsm_state                                 := fsm_nonchecking
    }
    is (fsm_nonchecking) {
      sl_counter                                := sl_counter
      clear_ic_status                           := 0.U
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := 0.U
      if_rh_cp_pc                               := 0.U
      fsm_state                                 := Mux(icsl_run.asBool, fsm_checking, Mux(io.if_check_privrun, fsm_checking_priv, fsm_nonchecking))
    }
    //并未对lsl满作出处理
    is (fsm_checking){
      sl_counter                                := Mux(io.if_correct_process.asBool && io.new_commit.asBool, sl_counter + 1.U, sl_counter)
      clear_ic_status                           := 0.U
      icsl_checkermode                          := Mux(io.if_correct_process.asBool, 1.U, 0.U)
      icsl_checkerpriv_mode                     := 0.U
      if_rh_cp_pc                               := 0.U
      when (io.self_xcpt) {
        trap_depth                              := 1.U
        resume_state                            := fsm_checking
        fsm_state                               := fsm_self_xcpt
      }.elsewhen (if_completion && !io.something_inflight) {
        fsm_state                               := fsm_postchecking
      }
    }
    //进行高特权级检测
    is (fsm_checking_priv){
      sl_counter                                := Mux(io.if_correct_process.asBool && io.new_commit.asBool, sl_counter + 1.U, sl_counter)
      clear_ic_status                           := 0.U
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := Mux(io.if_correct_process.asBool, 1.U, 0.U)
      if_rh_cp_pc                               := 0.U
      when (io.self_xcpt) {
        trap_depth                              := 1.U
        resume_state                            := fsm_checking_priv
        fsm_state                               := fsm_self_xcpt_priv
      }.elsewhen (if_completion_priv && !io.something_inflight) {
        fsm_state                               := fsm_postchecking_priv
      }
    }
    // //cdc 真空期
    // is (fsm_cdc_clear){
    //   sl_counter                                := Mux(io.if_correct_process.asBool && io.new_commit.asBool, sl_counter + 1.U, sl_counter)
    //   clear_ic_status                           := 0.U
    //   icsl_checkermode                          := Mux(io.if_correct_process.asBool, 1.U, 0.U)
    //   if_rh_cp_pc                               := 0.U
    //   //注意这里需要添加流水线是否为空
    //   fsm_state                                 := Mux(if_completion, fsm_postchecking, fsm_cdc_clear)//错误的状态转换
    // }
    is (fsm_self_xcpt){
      sl_counter                                := sl_counter
      clear_ic_status                           := 0.U
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := 0.U
      if_rh_cp_pc                               := 0.U
      when (io.self_xcpt) {
        when (trap_depth.andR) {
          trap_depth_overflow                   := true.B
        }.otherwise {
          trap_depth                            := trap_depth + 1.U
        }
      }.elsewhen (io.self_ret && trap_depth =/= 0.U && !trap_depth_overflow) {
        when (trap_depth === 1.U) {
          trap_depth                            := 0.U
          fsm_state                             := resume_state
        }.otherwise {
          trap_depth                            := trap_depth - 1.U
        }
      }
    }
    is (fsm_self_xcpt_priv){
      sl_counter                                := sl_counter
      clear_ic_status                           := 0.U
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := 0.U
      if_rh_cp_pc                               := 0.U
      when (io.self_xcpt) {
        when (trap_depth.andR) {
          trap_depth_overflow                   := true.B
        }.otherwise {
          trap_depth                            := trap_depth + 1.U
        }
      }.elsewhen (io.self_ret && trap_depth =/= 0.U && !trap_depth_overflow) {
        when (trap_depth === 1.U) {
          trap_depth                            := 0.U
          fsm_state                             := resume_state
        }.otherwise {
          trap_depth                            := trap_depth - 1.U
        }
      }
    }
    // 后检查必须持续冻结 checker，直到完整包校验和返回重定向均已完成。
    // RSUSL 在该状态取得稳定 ARF 快照；若此处提前退出 checker mode，
    // 管理软件可能在快照前改写寄存器，导致同一 ECP 出现伪失配。
    is (fsm_postchecking){//post check阶段会去将流水线指令执行完成，然后去return
      sl_counter                                := Mux(package_completion_ready, 0.U, sl_counter)
      clear_ic_status                           := 0.U
      icsl_checkermode                          := 1.U
      icsl_checkerpriv_mode                     := 0.U
      // 完成事件是退出冻结区的唯一授权。不能再由 if_correct_process 门控：
      // checker 被冻结后该信号可能为 0，否则会永远到不了 pc_special。
      if_rh_cp_pc                               := !io.self_xcpt.asBool &&
                                                   !io.excpt_mode && trap_depth === 0.U &&
                                                   package_completion_ready
      when (io.self_xcpt) {
        trap_depth                              := 1.U
        resume_state                            := fsm_postchecking
        fsm_state                               := fsm_self_xcpt
      }.elsewhen (io.returned_to_special_address_valid.asBool) {
        fsm_state                               := fsm_reset
      }
    }
    is(fsm_postchecking_priv){
      sl_counter                                := Mux(package_completion_ready, 0.U, sl_counter)
      clear_ic_status                           := 0.U
      // 特权检查使用独立模式，但同样必须覆盖包尾校验至返回完成。
      icsl_checkermode                          := 0.U
      icsl_checkerpriv_mode                     := 1.U
      if_rh_cp_pc                               := !io.self_xcpt && !io.excpt_mode &&
                                                   trap_depth === 0.U && package_completion_ready
      when (io.self_xcpt) {
        trap_depth                              := 1.U
        resume_state                            := fsm_postchecking_priv
        fsm_state                               := fsm_self_xcpt_priv
      }.elsewhen (io.returned_to_special_address_valid.asBool) {
        fsm_state                               := fsm_reset
      }
    }
  }

  // A bounded package failure releases BOOM through the independent result
  // CDC, but an executing checker must still return to its management PC.
  // If a trap is live, resume into postchecking after the matching xRET and
  // only then request the special-PC redirect.
  val package_start = io.icsl_run.asBool || io.if_check_privrun
  val cancel_privileged = fsm_state === fsm_checking_priv ||
    fsm_state === fsm_self_xcpt_priv || fsm_state === fsm_postchecking_priv ||
    resume_state === fsm_checking_priv || resume_state === fsm_postchecking_priv
  when (io.if_check_cancelled) {
    sl_counter                                := 0.U
    cancellation_return_pending              := true.B
    resume_state                              := fsm_nonchecking
    if_rh_cp_pc                               := 0.U
    when (fsm_state === fsm_reset || fsm_state === fsm_nonchecking) {
      fsm_state                               := fsm_reset
      cancellation_return_pending            := false.B
      trap_depth                              := 0.U
      trap_depth_overflow                     := false.B
    }.elsewhen (io.self_xcpt || io.excpt_mode || trap_depth =/= 0.U) {
      when (trap_depth === 0.U) {
        trap_depth                            := 1.U
      }
      resume_state                            := Mux(cancel_privileged,
        fsm_postchecking_priv, fsm_postchecking)
      fsm_state                               := Mux(cancel_privileged,
        fsm_self_xcpt_priv, fsm_self_xcpt)
    }.otherwise {
      fsm_state                               := Mux(cancel_privileged,
        fsm_postchecking_priv, fsm_postchecking)
    }
  }.elsewhen (io.returned_to_special_address_valid.asBool ||
    fsm_state === fsm_reset) {
    cancellation_return_pending              := false.B
  }
  when (io.if_check_cancelled &&
    fsm_state =/= fsm_reset && fsm_state =/= fsm_nonchecking) {
    package_completion_seen                   := true.B
  }.elsewhen (fsm_state === fsm_reset ||
    (fsm_state === fsm_nonchecking && package_start)) {
    package_completion_seen                   := false.B
  }.elsewhen (io.if_check_completed.asBool && fsm_state =/= fsm_nonchecking) {
    package_completion_seen                   := true.B
  }
  when (fsm_state === fsm_reset ||
    (fsm_state === fsm_nonchecking && package_start)) {
    package_exec_done_seen                    := false.B
  }.elsewhen (instruction_completion) {
    package_exec_done_seen                    := true.B
  }
  // 特权返回同样只依赖完整包尾。if_correct_process/excpt_mode 在冻结期间
  // 可能保持低/高电平，不能把它们作为返回握手的必要条件，否则会造成
  // checker 资源和 BOOM ic_status 永久占用。
  val privileged_return_ready =
    fsm_state === fsm_postchecking_priv && package_completion_ready &&
    !io.self_xcpt && !io.excpt_mode && trap_depth === 0.U &&
    !io.returned_to_special_address_valid.asBool &&
    !io.if_check_cancelled && !cancellation_return_pending
  when (fsm_state === fsm_reset || io.if_check_cancelled ||
    (fsm_state === fsm_nonchecking && package_start)) {
    privileged_return_issued                  := false.B
  }.elsewhen (privileged_return_ready) {
    privileged_return_issued                  := true.B
  }
  val fsm_state_delay                            = RegInit(fsm_reset)
  fsm_state_delay                               := fsm_state
  if (GH_GlobalParams.GH_DEBUG == 1) {
    val ic_counter_shadow_delay                  = RegInit(0.U((params.width_of_ic-1).W))
    // ic_counter_shadow_delay                     := ic_counter_shadow
    when ((fsm_state_delay =/= fsm_state) && (io.core_trace.asBool)) {
      printf(midas.targetutils.SynthesizePrintf("C%d:fsm_state=[%x]\n", io.core_id, fsm_state))
    }
  }

  
  val check_done = RegInit(false.B)
  when(io.if_check_completed.asBool || io.if_check_cancelled){
    check_done := false.B
  }.elsewhen(((if_completion && icsl_checkermode.asBool) || (icsl_checkerpriv_mode.asBool && if_completion_priv)) && !io.something_inflight && !(io.returned_to_special_address_valid.asBool)){
    check_done := true.B
  }

  io.if_check_done := check_done
  io.package_exec_done := package_exec_done_seen
  val postchecking = fsm_state === fsm_postchecking ||
    fsm_state === fsm_postchecking_priv
  io.arch_compare_ready := postchecking && package_exec_done_seen &&
    !io.self_xcpt && !io.excpt_mode && trap_depth === 0.U &&
    !trap_depth_overflow && !io.something_inflight &&
    !io.returned_to_special_address_valid.asBool
  io.cleanup_done := fsm_state === fsm_reset || fsm_state === fsm_nonchecking
  io.return_pending :=
    (fsm_state === fsm_postchecking || fsm_state === fsm_postchecking_priv) &&
      package_completion_ready && !io.returned_to_special_address_valid.asBool ||
      cancellation_return_pending
  io.context_idle := io.cleanup_done && !io.excpt_mode && trap_depth === 0.U &&
    !trap_depth_overflow && !io.return_pending
  io.trap_depth := trap_depth
  // A privileged return changes the architectural register state.  Issue it
  // only after ARF, CSR, LSL and packet ingress have reached the common package
  // tail, and hold it to one pulse while the redirect is taking effect.
  io.if_check_privret := privileged_return_ready && !privileged_return_issued
  dontTouch(check_done)

  // when()
  // exec_last_one                                 := Mux((fsm_state===fsm_speed_check),Mux(io.big_complete,true.B,exec_last_one),false.B)
  // dontTouch(exec_last_one)
  // if_ret_special_pc                             := Mux(io.if_check_completed.asBool && icsl_checkermode.asBool, 1.U, 0.U)
  // Cancellation returns through pc_special without invoking CSR's
  // synthetic privileged-return path, which would change mstatus.prv/mpp.
  if_ret_special_pc                             := Mux(if_rh_cp_pc.asBool &&
                                                     (icsl_checkermode.asBool || cancellation_return_pending),
                                                     1.U, 0.U)
  icsl_run                                      := io.icsl_run
  
  // io.if_big_complete                            := false.B//(fsm_state===fsm_cdc_clear||fsm_state===fsm_checking)&&(icsl_check_speed)
  // dontTouch(io.if_big_complete)
  // dontTouch(io.big_complete)
  // val if_overtaking                             = RegInit(0.U(1.W))
  if_overtaking                                 := Mux(if_just_overtaking.asBool || (sl_counter >= (ic_counter_shadow + 1.U)), 1.U, 0.U)
  if_overtaking_priv                            := Mux(if_just_overtaking_priv.asBool || (sl_counter >= (ic_counter_shadow)), 1.U, 0.U)
  val if_overtaking_next_cycle                   = WireInit(0.U(1.W))
  val if_overtaking_priv_next_cycle              = WireInit(0.U(1.W))
  if_overtaking_next_cycle                      := Mux(if_just_overtaking.asBool || (sl_counter >= (ic_counter_shadow + 1.U)), 1.U, 0.U)
  if_overtaking_priv_next_cycle                 := Mux(if_just_overtaking_priv.asBool || (sl_counter >= (ic_counter_shadow)), 1.U, 0.U)
  
  val stall_checking                            = RegInit(false.B)
  val stall_checking_priv                       = RegInit(false.B)
  stall_checking           := Mux(ic_counter_shadow + 1.U <= sl_counter + io.num_valid_insts_in_pipeline, true.B,false.B)
  stall_checking_priv      := Mux(ic_counter_shadow <= sl_counter + io.num_valid_insts_in_pipeline, true.B,false.B)


  dontTouch(stall_checking)
  ic_counter_shadow                             := Mux(io.ic_counter=/=0.U,io.ic_counter,ic_counter_shadow)
  io.clear_ic_status                            := clear_ic_status
  io.icsl_checkermode                           := icsl_checkermode
  io.icsl_checkerpriv_mode                      := icsl_checkerpriv_mode
  // io.if_overtaking                              := if_overtaking
  io.if_overtaking                              := Mux((fsm_state === fsm_checking) || (fsm_state === fsm_postchecking), if_overtaking, Mux((fsm_state === fsm_checking_priv) || (fsm_state === fsm_postchecking_priv), if_overtaking_priv, 0.U))
  // io.if_overtaking_next_cycle                   := if_overtaking_next_cycle//(icsl_checkermode & if_overtaking_next_cycle)
  io.if_overtaking_next_cycle                   := Mux((fsm_state === fsm_checking) || (fsm_state === fsm_postchecking), if_overtaking_next_cycle, Mux((fsm_state === fsm_checking_priv) || (fsm_state === fsm_postchecking_priv), if_overtaking_priv_next_cycle, 0.U))
  io.if_ret_special_pc                          := if_ret_special_pc
  io.if_rh_cp_pc                                := if_rh_cp_pc
  io.icsl_status                                := Mux(fsm_state === fsm_nonchecking, 1.U, 0.U)
  io.debug_sl_counter                           := sl_counter
  io.already_done                               := io.ic_counter(params.width_of_ic - 1).asBool && Mux(fsm_state === fsm_checking, sl_counter >= ic_counter_shadow, 
                                                                                                      Mux(fsm_state === fsm_checking_priv, sl_counter >= ic_counter_shadow - 1.U, false.B))

  dontTouch(ic_counter_shadow)
  // dontTouch(icsl_exec_done)
  //这里可能会出问题
  // io.icsl_stalld                                := Mux(icsl_checkermode.asBool,
  //                                                 Mux(fsm_state === fsm_checking, stall_checking, 
  //                                                 Mux(fsm_state === fsm_postchecking, (!io.if_check_completed), false.B)), false.B)
  val waiting_for_package_tail                   =
    (fsm_state === fsm_postchecking || fsm_state === fsm_postchecking_priv) &&
      !package_completion_ready
  io.icsl_stalld                                := waiting_for_package_tail ||
                                                   Mux(icsl_checkermode.asBool,
                                                     fsm_state === fsm_checking && stall_checking,
                                                     icsl_checkerpriv_mode.asBool &&
                                                       fsm_state === fsm_checking_priv && stall_checking_priv)
  io.kill_pipe                                  := false.B//(fsm_state===fsm_speed_check)&&(sl_counter===(ic_counter_shadow))&&(io.new_commit.asBool)||icsl_exec_done//此时需要去清除其他指令，为什么不用-1，因为小核心会多执行一条
  /* Debug Perf */
  val debug_perf_howmany_checkpoints             = RegInit(0.U(64.W))
  val debug_perf_checking                        = RegInit(0.U(64.W))
  val debug_perf_postchecking                    = RegInit(0.U(64.W))
  val debug_perf_otherthread                     = RegInit(0.U(64.W))
  val debug_perf_nonchecking                     = RegInit(0.U(64.W))
  val debug_perf_nonchecking_OtherThreads        = RegInit(0.U(64.W))
  val debug_perf_nonchecking_MOtherThreads       = RegInit(0.U(64.W))
  val debug_perf_nonchecking_MSched              = RegInit(0.U(64.W))
  val debug_perf_nonchecking_MCheck              = RegInit(0.U(64.W))

  val debug_perf_insts                           = RegInit(0.U(64.W))
  val debug_perf_CPStrans                        = RegInit(0.U(64.W))
  val debug_perf_CPStrans_ifGo                   = RegInit(0.U(1.W))

  debug_perf_howmany_checkpoints                := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_reset) && (fsm_state_delay === fsm_postchecking), debug_perf_howmany_checkpoints + 1.U, debug_perf_howmany_checkpoints))
  debug_perf_checking                           := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_checking), debug_perf_checking + 1.U, debug_perf_checking))
  debug_perf_postchecking                       := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_postchecking), debug_perf_postchecking + 1.U, debug_perf_postchecking))
  debug_perf_otherthread                        := Mux(io.debug_perf_reset.asBool, 0.U, Mux(((fsm_state === fsm_checking) || (fsm_state === fsm_postchecking)) && (!io.if_correct_process.asBool),  debug_perf_otherthread + 1.U, debug_perf_otherthread))
  debug_perf_nonchecking                        := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_nonchecking), debug_perf_nonchecking + 1.U, debug_perf_nonchecking))
  /*
  debug_perf_nonchecking_OtherThreads           := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_nonchecking) && (!io.if_correct_process.asBool), debug_perf_nonchecking_OtherThreads + 1.U, debug_perf_nonchecking_OtherThreads))
  debug_perf_nonchecking_MOtherThreads          := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_nonchecking) && (io.if_correct_process.asBool) && (io.main_core_status === 3.U), debug_perf_nonchecking_MOtherThreads + 1.U, debug_perf_nonchecking_MOtherThreads))
  debug_perf_nonchecking_MCheck                 := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_nonchecking) && (io.if_correct_process.asBool) && (io.main_core_status === 2.U), debug_perf_nonchecking_MCheck + 1.U, debug_perf_nonchecking_MCheck))
  debug_perf_insts                              := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_checking) && io.new_commit.asBool, debug_perf_insts + 1.U, debug_perf_insts))*/
  debug_perf_CPStrans_ifGo                      := Mux(io.debug_starting_CPS.asBool, 1.U, Mux((fsm_state === fsm_checking), 0.U, debug_perf_CPStrans_ifGo))
  debug_perf_CPStrans                           := Mux(io.debug_perf_reset.asBool, 0.U, Mux(debug_perf_CPStrans_ifGo.asBool, debug_perf_CPStrans + 1.U, debug_perf_CPStrans))
  // debug_perf_nonchecking_MSched                 := Mux(io.debug_perf_reset.asBool, 0.U, Mux((fsm_state === fsm_nonchecking) && (io.if_correct_process.asBool) && (io.main_core_status === 1.U), debug_perf_nonchecking_MSched + 1.U, debug_perf_nonchecking_MSched))


  val debug_perf_num_st_cache                    = RegInit(0.U(64.W))
  val debug_perf_num_st_uncache                  = RegInit(0.U(64.W))
  val debug_perf_num_st_uncache_in_packet        = RegInit(0.U(params.width_of_ic.W))
  val debug_perf_st_uncache_cycle_sum            = RegInit(0.U(64.W))
  val debug_perf_num_ld_cache                    = RegInit(0.U(64.W))
  val debug_perf_num_ld_uncache                  = RegInit(0.U(64.W))
  val debug_perf_num_lr                          = RegInit(0.U(64.W))
  val debug_perf_num_sc_success                  = RegInit(0.U(64.W))
  val debug_perf_num_sc_fail                     = RegInit(0.U(64.W))
  val debug_perf_num_amo_cache                   = RegInit(0.U(64.W))
  val debug_perf_num_amo_uncache                 = RegInit(0.U(64.W))
  val debug_perf_num_amo                         = debug_perf_num_amo_cache + debug_perf_num_amo_uncache
  val debug_perf_num_st                          = debug_perf_num_st_cache + debug_perf_num_st_uncache
  val debug_perf_num_ld                          = debug_perf_num_ld_cache + debug_perf_num_ld_uncache
  val debug_L_timer_worest                       = RegInit(0.U(64.W))

  val trafficEnabled                            = RegInit(false.B)
  when (io.debug_perf_reset.asBool) {
    trafficEnabled                              := false.B
  }.elsewhen (io.debug_perf_start) {
    trafficEnabled                              := true.B
  }.elsewhen (io.debug_perf_stop) {
    trafficEnabled                              := false.B
  }
  val trafficCounting                           = (trafficEnabled || io.debug_perf_start) &&
    !io.debug_perf_stop && !io.debug_perf_reset.asBool

  debug_perf_num_st_cache                       := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_st_cache + (io.st_cache_deq & trafficCounting.asUInt))
  debug_perf_num_st_uncache                     := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_st_uncache + (io.st_uncache_deq & trafficCounting.asUInt))
  val measured_st_uncache_deq                   = io.st_uncache_deq & trafficCounting.asUInt
  val st_uncache_count_at_packet_completion      = debug_perf_num_st_uncache_in_packet + measured_st_uncache_deq
  val st_uncache_packet_cycle_contribution       = io.csr_cycle * st_uncache_count_at_packet_completion
  when (io.debug_perf_reset.asBool) {
    debug_perf_num_st_uncache_in_packet          := 0.U
    debug_perf_st_uncache_cycle_sum              := 0.U
  }.elsewhen (io.if_check_completed.asBool) {
    // All uncache stores in this packet share the timestamp at which the
    // complete package result is formed. A STOP may already have disabled new
    // events, but stores admitted before STOP still need their tail timestamp.
    debug_perf_num_st_uncache_in_packet          := 0.U
    debug_perf_st_uncache_cycle_sum              := debug_perf_st_uncache_cycle_sum + st_uncache_packet_cycle_contribution(63, 0)
  }.elsewhen (io.if_check_cancelled) {
    debug_perf_num_st_uncache_in_packet          := 0.U
  }.elsewhen (measured_st_uncache_deq.asBool) {
    debug_perf_num_st_uncache_in_packet          := st_uncache_count_at_packet_completion
  }
  debug_perf_num_ld_cache                       := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_ld_cache + (io.ld_cache_deq & trafficCounting.asUInt))
  debug_perf_num_ld_uncache                     := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_ld_uncache + (io.ld_uncache_deq & trafficCounting.asUInt))
  debug_perf_num_lr                             := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_lr + (io.lr_deq & trafficCounting.asUInt))
  debug_perf_num_sc_success                     := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_sc_success + (io.sc_success_deq & trafficCounting.asUInt))
  debug_perf_num_sc_fail                        := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_sc_fail + (io.sc_fail_deq & trafficCounting.asUInt))
  debug_perf_num_amo_cache                      := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_amo_cache + (io.amo_cache_deq & trafficCounting.asUInt))
  debug_perf_num_amo_uncache                    := Mux(io.debug_perf_reset.asBool, 0.U,
    debug_perf_num_amo_uncache + (io.amo_uncache_deq & trafficCounting.asUInt))
  // Software protocol: [store_total, store_cache, store_uncache,
  //                     load_total, load_cache, load_uncache, load_forward,
  //                     lr, sc_success, sc_fail, amo_total,
  //                     amo_cache, amo_uncache, l1_l2_c_total,
  //                     l1_l2_wb_dirty, l2_dram_wb_total,
  //                     l2_dram_wb_dirty, store_uncache_cycle_sum,
  //                     BOOM-only unverified dirty writeback diagnostics].
  //                     Indices 13--16 are BOOM/shared-L2 metrics and remain
  //                     zero on checker harts. Index 17 is local to each hart.
  // Rocket re-executes loads through LSL and therefore never uses BOOM's
  // STQ-to-load forwarding path.
  io.traffic_counter                            := VecInit(Seq(debug_perf_num_st, debug_perf_num_st_cache,
                                                               debug_perf_num_st_uncache, debug_perf_num_ld,
                                                               debug_perf_num_ld_cache, debug_perf_num_ld_uncache,
                                                               0.U(64.W), debug_perf_num_lr,
                                                               debug_perf_num_sc_success, debug_perf_num_sc_fail,
                                                               debug_perf_num_amo, debug_perf_num_amo_cache,
                                                               debug_perf_num_amo_uncache, 0.U(64.W), 0.U(64.W),
                                                               0.U(64.W), 0.U(64.W),
                                                               debug_perf_st_uncache_cycle_sum) ++
                                                     Seq.fill(GH_GlobalParams.GH_TRAFFIC_COUNTERS - 18)(0.U(64.W)))

  val u_channel                                  = Module(new GH_MemFIFO(FIFOParams (32, 50)))
  val debug_L_timer                              = RegInit(0.U(64.W))
  debug_L_timer                                 := Mux(fsm_state === fsm_nonchecking, 0.U, Mux(fsm_state === fsm_checking, debug_L_timer + 1.U, debug_L_timer))
  u_channel.io.enq_valid                        := Mux((fsm_state === fsm_postchecking) && (fsm_state_delay === fsm_checking) && ((debug_perf_howmany_checkpoints & 0x1FF.U) === 0x00.U), true.B, false.B)
  u_channel.io.enq_bits                         := debug_L_timer
  val debug_perf_sel_delay                       = RegInit(0.U(4.W))
  debug_perf_sel_delay                          := io.debug_perf_sel
  u_channel.io.deq_ready                        := (io.debug_perf_sel === 14.U) && (debug_perf_sel_delay === 15.U)

  debug_L_timer_worest                          := Mux(io.debug_perf_reset.asBool, 0.U, Mux(debug_L_timer > debug_L_timer_worest, debug_L_timer, debug_L_timer_worest))


  io.debug_perf_val                             := Mux(io.debug_perf_sel === 7.U, debug_perf_howmany_checkpoints, 
                                                   Mux(io.debug_perf_sel === 1.U, debug_perf_checking,
                                                   Mux(io.debug_perf_sel === 2.U, debug_perf_postchecking,
                                                   Mux(io.debug_perf_sel === 3.U, debug_perf_otherthread,
                                                   Mux(io.debug_perf_sel === 4.U, debug_perf_nonchecking, 
                                                   Mux(io.debug_perf_sel === 5.U, debug_perf_nonchecking_OtherThreads,
                                                   Mux(io.debug_perf_sel === 6.U, debug_perf_nonchecking_MOtherThreads,
                                                   Mux(io.debug_perf_sel === 8.U, debug_perf_nonchecking_MCheck,
                                                   Mux(io.debug_perf_sel === 9.U, debug_perf_insts, 
                                                   Mux(io.debug_perf_sel === 11.U, debug_L_timer_worest,
                                                   Mux(io.debug_perf_sel === 10.U, debug_perf_CPStrans,
                                                   Mux(io.debug_perf_sel === 12.U, debug_perf_num_st,
                                                   Mux(io.debug_perf_sel === 13.U, debug_perf_num_ld,
                                                   Mux(io.debug_perf_sel === 14.U, u_channel.io.deq_bits, 
                                                   Mux(io.debug_perf_sel === 15.U, u_channel.io.deq_bits, 0.U
                                                   )))))))))))))))
  
  io.checker_core_status                        := Mux(!io.if_correct_process.asBool, 3.U, 
                                                   Mux(fsm_state === fsm_checking, 1.U, 0.U))
 
  // io.debug_perf_val                             := 0.U
}
