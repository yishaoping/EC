package freechips.rocketchip.r

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}
import freechips.rocketchip.guardiancouncil._
import freechips.rocketchip.rocket.RegFileshadow

case class R_RSUSLParams(
  xLen: Int,
  numARFS: Int
)

class R_RSUSLIO(params: R_RSUSLParams) extends Bundle {
  val rf_sp = Output(UInt(params.xLen.W))
  val rf_gp = Output(UInt(params.xLen.W))

  val rf_wen = Input(Bool())
  val rf_waddr = Input(UInt(5.W))
  val rf_wdata = Input(UInt(params.xLen.W))
  val checker_mode = Input(Bool())


  val arfs_out = Output(UInt(params.xLen.W))
  val farfs_out = Output(UInt(params.xLen.W))
  val arfs_idx_out = Output(UInt(8.W))
  val arfs_valid_out = Output(UInt(1.W))

  val check_priv = Input(UInt(2.W))
  val excpt      = Input(Bool())
  val eret       = Input(Bool())

  // val id_raddr = Input(Vec(2, UInt(5.W)))

  // val id_rs    = Output(Vec(2, UInt(64.W)))

  val check_done = Input(UInt(1.W))

  val pcarf_out = Output(UInt(40.W))
  val fcsr_out = Output(UInt(8.W))
  val pfarf_valid_out = Output(UInt(1.W))
  val core_hang_up = Output(UInt(1.W))

  val arfs_merge = Input(UInt((params.xLen*2).W))
  val arfs_index = Input(UInt(7.W))
  val arfs_if_ARFS = Input(UInt(1.W))
  val arfs_if_CPS = Input(UInt(1.W))
  val paste_arfs = Input(UInt(1.W))
  val rsu_status = Output(UInt(2.W))
  val clear_ic_status = Input(UInt(1.W))

  val cdc_ready = Output(UInt(1.W))

  // Package and compare ownership are explicit.  ARF CDC beats already carry
  // a sequence at the RocketTile boundary; keeping it through this block
  // prevents a late ECP or compare result from being assigned to a newer
  // package.
  val package_start = Input(Bool())
  val package_clear = Input(Bool())
  val package_seq = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val arfs_seq = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val compare_start = Input(Bool())
  val compare_abort = Input(Bool())
  val compare_done_ack = Input(Bool())

  // ECP tail has reached the checker. Valid gaps are allowed while receiving
  // the transaction and therefore do not affect this state.
  val cp_check_ready = Output(Bool())
  val ecp_complete = Output(Bool())
  val ecp_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val ecp_epoch = Output(UInt(8.W))
  val ecp_frame_start = Output(Bool())
  val ecp_protocol_error = Output(Bool())
  val ecp_protocol_error_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val ecp_idle = Output(Bool())
  val compare_busy = Output(Bool())
  val compare_idle = Output(Bool())
  val compare_done = Output(Bool())
  val compare_done_seq = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val compare_done_epoch = Output(UInt(8.W))
  val compare_done_error = Output(Bool())
  val if_cp_check_completed = Output(UInt(1.W))
  // Per-entry mismatch remains visible for the legacy ELU diagnostic FIFO. It
  // is not a package-scoped error; compare_done_error is the owned result.
  val check_error = Output(Bool())
  val core_arfs_in = Input(Vec(params.numARFS, UInt(params.xLen.W)))
  val core_farfs_in = Input(Vec(params.numARFS, UInt(params.xLen.W)))
  val elu_cp_deq = Input(UInt(1.W))
  val elu_cp_data = Output(UInt((4*params.xLen+8).W))
  val elu_status = Output(UInt(1.W))

  val core_trace = Input(UInt(1.W))
  val record_context = Input(UInt(1.W))
  val store_from_checker = Input(UInt(1.W)) // 0: from main; 1: from checker.
  val core_id = Input(UInt(4.W)) // 0: from main; 1: from checker.
  
  val starting_CPS = Output(UInt(1.W))
}

trait HasR_RSUSLIO extends BaseModule {
  val params: R_RSUSLParams
  val io = IO(new R_RSUSLIO(params))
}

class R_RSUSL(val params: R_RSUSLParams) extends Module with HasR_RSUSLIO {
  // Revisit: move it to the instruction counter
  val rsu_status                                  = RegInit(0.U(2.W))
  val if_check_completed                          = WireInit(0.U(1.W))

  /* Loading snapshot from RSU Master */
  val arfs_ss                                     = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val farfs_ss                                    = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val arfs_ss_ECP                                 = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val farfs_ss_ECP                                = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val arfs_ss_GMode                               = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val farfs_ss_GMode                              = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))
  val rf_shadow                                   = new RegFileshadow(32, 64)

  val pcarfs_ss                                   = RegInit(0.U(40.W))

  val if_RSU_packet                               = WireInit(0.U(1.W))
  val packet_valid                                = RegInit(0.U(1.W)) 
  val packet_index                                = RegInit(0.U(8.W))
  val packet_arfs                                 = RegInit(0.U(params.xLen.W))
  val packet_farfs                                = RegInit(0.U(params.xLen.W))

  if_RSU_packet                                  := Mux(io.arfs_if_ARFS.asBool && io.arfs_if_CPS.asBool, 1.U, 0.U) 
  packet_valid                                   := Mux(if_RSU_packet === 1.U, 1.U, 0.U)
  packet_arfs                                    := Mux(if_RSU_packet === 1.U, io.arfs_merge(63,0), 0.U)
  packet_farfs                                   := Mux(if_RSU_packet === 1.U, io.arfs_merge(127,64), 0.U)
  packet_index                                   := Mux(if_RSU_packet === 1.U, io.arfs_index, 0.U)
  io.starting_CPS                                := if_RSU_packet.asBool && (packet_index === 0.U)

  /* Storing the checker's current states */
  val recording_context                           = Reg(Bool())
  val recording_counter                           = RegInit(20.U(7.W))



  when (io.record_context.asBool && !recording_context) {
    recording_context                            := true.B
    recording_counter                            := 0.U
  } .elsewhen (recording_context === 1.U){
    recording_context                            := Mux(recording_counter === 0x20.U, false.B, true.B)
    recording_counter                            := Mux(recording_counter === 0x20.U, 0.U, recording_counter + 1.U)
  } .otherwise {
    recording_context                            := recording_context
    recording_counter                            := recording_counter
  }

  when (recording_context) {
    arfs_ss_GMode.write(recording_counter, io.core_arfs_in(recording_counter))
    farfs_ss_GMode.write(recording_counter, io.core_farfs_in(recording_counter))
  }

  /* Loading snapshot at End of Check Point from RSU Master */
  val if_RSU_packet_ECP                           = WireInit(false.B)
  val packet_valid_ECP                            = RegInit(0.U(1.W)) 
  val packet_index_ECP                            = RegInit(0.U(8.W))
  val packet_arfs_ECP                             = RegInit(0.U(params.xLen.W))
  val packet_farfs_ECP                            = RegInit(0.U(params.xLen.W))
  val packet_seq_ECP                              = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  
  if_RSU_packet_ECP                              := Mux(io.arfs_if_ARFS.asBool && !io.arfs_if_CPS.asBool, 1.U, 0.U) 
  packet_valid_ECP                               := Mux(if_RSU_packet_ECP === 1.U, 1.U, 0.U)
  packet_arfs_ECP                                := Mux(if_RSU_packet_ECP === 1.U, io.arfs_merge(63,0), 0.U)
  packet_farfs_ECP                               := Mux(if_RSU_packet_ECP === 1.U, io.arfs_merge(127,64), 0.U)
  packet_index_ECP                               := Mux(if_RSU_packet_ECP === 1.U, io.arfs_index, 0.U)
  packet_seq_ECP                                 := Mux(if_RSU_packet_ECP === 1.U, io.arfs_seq, 0.U)

  val ecp_active                                  = RegInit(false.B)
  val ecp_complete_reg                            = RegInit(false.B)
  val ecp_owner_seq                               = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val ecp_expected_index                         = RegInit(0.U(7.W))
  val ecp_protocol_error_reg                      = RegInit(false.B)
  val ecp_protocol_error_seq_reg                  = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val ecp_frame_epoch                             = RegInit(0.U(8.W))
  val ecp_beat_accept                             = WireDefault(false.B)
  val ecp_tail_accept                             = WireDefault(false.B)
  val ecp_frame_start                             = WireDefault(false.B)

  when (io.package_clear) {
    ecp_active := false.B
    ecp_complete_reg := false.B
    ecp_owner_seq := 0.U
    ecp_expected_index := 0.U
    ecp_protocol_error_reg := false.B
    ecp_protocol_error_seq_reg := 0.U
    ecp_frame_epoch := 0.U
  }.elsewhen (io.package_start) {
    ecp_active := false.B
    ecp_complete_reg := false.B
    ecp_owner_seq := io.package_seq
    ecp_expected_index := 0.U
    ecp_protocol_error_reg := false.B
    ecp_protocol_error_seq_reg := io.package_seq
    ecp_frame_epoch := 0.U
    // package_start and the first ECP beat can be observed in the same
    // checker cycle. Consume index zero atomically so initialization does not
    // drop the frame boundary.
    when (packet_valid_ECP.asBool && packet_seq_ECP === io.package_seq &&
      packet_index_ECP === 0.U) {
      ecp_beat_accept := true.B
      ecp_frame_start := true.B
      ecp_active := true.B
      ecp_expected_index := 1.U
      ecp_frame_epoch := 1.U
    }
  }.elsewhen (packet_valid_ECP.asBool) {
    val beatOwned = ecp_owner_seq =/= 0.U && packet_seq_ECP === ecp_owner_seq
    when (!beatOwned) {
      ecp_protocol_error_reg := true.B
      // Preserve the sequence of the offending beat. A stale fragment from an
      // older package must not cancel the current owner.
      ecp_protocol_error_seq_reg := packet_seq_ECP
    }.elsewhen (!ecp_active) {
      when (packet_index_ECP === 0.U) {
        ecp_beat_accept := true.B
        ecp_frame_start := true.B
        ecp_active := true.B
        ecp_complete_reg := false.B
        ecp_expected_index := 1.U
        ecp_frame_epoch := ecp_frame_epoch + 1.U
      }.otherwise {
        ecp_protocol_error_reg := true.B
        ecp_protocol_error_seq_reg := packet_seq_ECP
      }
    }.elsewhen (ecp_active) {
      when (packet_index_ECP === ecp_expected_index) {
        ecp_beat_accept := true.B
        when (packet_index_ECP === 0x20.U) {
          ecp_tail_accept := true.B
          ecp_active := false.B
          ecp_complete_reg := true.B
          ecp_expected_index := 0.U
        }.otherwise {
          ecp_expected_index := ecp_expected_index + 1.U
        }
      }.otherwise {
        ecp_protocol_error_reg := true.B
        ecp_protocol_error_seq_reg := packet_seq_ECP
      }
    }.otherwise {
      // A completed frame may be followed by another index-zero frame with
      // the same package sequence. The branch above accepts that new frame
      // and advances the local epoch.
      ecp_protocol_error_reg := true.B
      ecp_protocol_error_seq_reg := packet_seq_ECP
    }
  }
  // val id_rs = io.id_raddr.map(rf_shadow.read _)

  // io.id_rs := VecInit(id_rs)
  // dontTouch(io.id_rs)
  // dontTouch(io.id_raddr)


  when (packet_valid === 1.U) {
    arfs_ss.write(packet_index, packet_arfs)
    farfs_ss.write(packet_index, packet_farfs)
    when(packet_index =/= 0x20.U){
      rf_shadow.write(packet_index, packet_arfs)
    }
    
    /*
    if (GH_GlobalParams.GH_DEBUG == 1) { 
      when (io.core_trace.asBool){
        printf(midas.targetutils.SynthesizePrintf("PACKET_CPS: [Index = %d] [Packet_arfs = %x], [Packet_farfs = %x]. \n", 
        packet_index, packet_arfs, packet_farfs))
      }
    }
    */
  }.elsewhen(io.checker_mode && io.rf_wen && io.rf_waddr === 2.U){
    arfs_ss.write(io.rf_waddr, io.rf_wdata)
  }.elsewhen(io.checker_mode && io.rf_wen && io.rf_waddr === 3.U){
    arfs_ss.write(io.rf_waddr, io.rf_wdata)
  } 
  
  when (ecp_beat_accept) {
    arfs_ss_ECP.write(packet_index_ECP,
      Mux(packet_index_ECP === 0.U, 0.U, packet_arfs_ECP))
    farfs_ss_ECP.write(packet_index_ECP, packet_farfs_ECP)
  }
  

  pcarfs_ss                                      := Mux(packet_valid.asBool && (packet_index === 0x20.U), packet_arfs(39,0), pcarfs_ss)
  when (io.package_clear || io.package_start ||
    (io.compare_done_ack && io.compare_done) || ecp_frame_start) {
    rsu_status := 0.U
  }.elsewhen (packet_valid.asBool && packet_index === 0x20.U && io.check_priv === 0.U) {
    rsu_status := 1.U
  }.elsewhen (ecp_tail_accept) {
    rsu_status := 3.U
  }

  
  /* Applying snapshot to the core */
  val arf_data                                    = WireInit(0.U((params.xLen.W)))
  val farf_data                                   = WireInit(0.U((params.xLen.W)))
  val arf_addr                                    = WireInit(0.U(8.W))
  val farf_addr                                   = WireInit(0.U(8.W))
  
  val arf_data_ECP                                = WireInit(0.U((params.xLen.W)))
  val farf_data_ECP                               = WireInit(0.U((params.xLen.W)))
  val arf_addr_ECP                                = WireInit(0.U(8.W))
  val farf_addr_ECP                               = WireInit(0.U(8.W))

  val apply_snapshot                              = RegInit(0.U(1.W))
  val apply_snapshot_memdelay                     = RegInit(0.U(1.W))
  val apply_counter                               = RegInit(20.U(8.W))
  val apply_counter_memdelay                      = RegInit(0.U(8.W))
  val do_check                                    = RegInit(0.U(1.W))
  val checking_counter                            = RegInit(1.U(8.W))
  val checking_counter_memdelay                   = RegInit(0.U(8.W))
  val compare_reads_issued                        = RegInit(false.B)
  val compare_read_valid                          = RegInit(false.B)
  val compare_error_accum                         = RegInit(false.B)
  val compare_seq_reg                             = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val compare_epoch_reg                           = RegInit(0.U(8.W))
  val compare_done_valid_reg                      = RegInit(false.B)
  val compare_done_seq_reg                        = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val compare_done_epoch_reg                      = RegInit(0.U(8.W))
  val compare_done_error_reg                      = RegInit(false.B)
  val checker_arfs_snapshot = RegInit(VecInit(Seq.fill(params.numARFS)(0.U(params.xLen.W))))
  val checker_farfs_snapshot = RegInit(VecInit(Seq.fill(params.numARFS)(0.U(params.xLen.W))))


  apply_snapshot_memdelay                        := apply_snapshot
  apply_counter_memdelay                         := apply_counter
  arf_addr                                       := Mux(apply_snapshot.asBool, apply_counter, 0.U)
  farf_addr                                      := Mux(apply_snapshot.asBool, apply_counter, 0.U)
  arf_data                                       := Mux(!io.store_from_checker, arfs_ss.read(arf_addr, apply_snapshot.asBool), arfs_ss_GMode.read(arf_addr, apply_snapshot.asBool))
  farf_data                                      := Mux(!io.store_from_checker, farfs_ss.read(farf_addr, apply_snapshot.asBool), farfs_ss_GMode.read(arf_addr, apply_snapshot.asBool))

  val compare_issue = do_check.asBool && !compare_reads_issued
  arf_addr_ECP                                   := Mux(compare_issue, checking_counter, 0.U)
  farf_addr_ECP                                  := Mux(compare_issue, checking_counter, 0.U)
  arf_data_ECP                                   := arfs_ss_ECP.read(arf_addr_ECP, compare_issue)
  farf_data_ECP                                  := farfs_ss_ECP.read(farf_addr_ECP, compare_issue)

  val excpt = Reg(Bool())
  val eret  = Reg(Bool())
  excpt := io.excpt
  eret  := io.eret

  io.rf_sp := Mux(excpt, arfs_ss_GMode.read(2.U, io.excpt), Mux(eret, arfs_ss.read(2.U, io.eret), 0.U))
  io.rf_gp := Mux(excpt, arfs_ss_GMode.read(3.U, io.excpt), Mux(eret, arfs_ss.read(3.U, io.eret), 0.U))


  when ((io.paste_arfs === 0x01.U) && (apply_snapshot === 0.U)) {
    apply_snapshot                               := 1.U
    apply_counter                                := 0.U
  } .elsewhen (apply_snapshot === 1.U){
    apply_snapshot                               := Mux(apply_counter === 0x20.U, 0.U, 1.U)
    apply_counter                                := Mux(apply_counter === 0x20.U, 0.U, apply_counter + 1.U)
  } .otherwise {
    apply_snapshot                               := apply_snapshot
    apply_counter                                := apply_counter
  }

  val arfs_out_printf                             = Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), arf_data, 0.U)
  val arfs_out_valid_printf                       = Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), 1.U, 0.U)
  val arfs_out_idx                                = Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), apply_counter_memdelay, 0.U)

  /*
  if (GH_GlobalParams.GH_DEBUG == 1) {
    when ((arfs_out_valid_printf.asBool) && (io.core_trace.asBool)) {
      printf(midas.targetutils.SynthesizePrintf("[CHECK POINTS --- Checker]: ARFS[%d] = [%x]\n", 
      arfs_out_idx, arfs_out_printf))
    }
  }
  */

  io.arfs_out                                    := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), arf_data, 0.U)
  io.farfs_out                                   := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), farf_data, 0.U)
  io.arfs_idx_out                                := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), apply_counter_memdelay, 0.U)
  io.arfs_valid_out                              := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay =/= 0x20.U)), 1.U, 0.U)

  val pcarfs_ss_delay                             = RegInit(0.U(40.W))
  pcarfs_ss_delay                                := pcarfs_ss

  if (GH_GlobalParams.GH_DEBUG == 1) {
    when ((io.core_trace.asBool) && (pcarfs_ss_delay =/= pcarfs_ss)) {
      printf(midas.targetutils.SynthesizePrintf("[C%x-CPS] = [%x]\n", io.core_id, pcarfs_ss))
    }
  
    when ((io.core_trace.asBool) && (packet_valid_ECP.asBool) && (packet_index_ECP === 0x20.U)) {
      // printf(midas.targetutils.SynthesizePrintf("[C%x-CPE] = [%x]\n", io.core_id, packet_arfs_ECP))
    }

  }
 
  io.pcarf_out                                   := pcarfs_ss
  io.fcsr_out                                    := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay === 0x20.U)), farf_data, 0.U)
  io.pfarf_valid_out                             := Mux(((apply_snapshot_memdelay === 1.U) && (apply_counter_memdelay === 0x20.U)), 1.U, 0.U)
  io.cdc_ready                                   := packet_valid | packet_valid_ECP

  io.rsu_status                                  := Mux(rsu_status === 0.U, 0.U, Mux(rsu_status === 1.U, 1.U, Mux(rsu_status === 3.U, Mux(io.check_done === 0.U, 1.U, 3.U), rsu_status)))
  io.cp_check_ready                              := ecp_complete_reg && !do_check.asBool &&
                                                    !compare_done_valid_reg
  io.ecp_complete                                := ecp_complete_reg
  io.ecp_seq                                     := ecp_owner_seq
  io.ecp_epoch                                   := ecp_frame_epoch
  io.ecp_frame_start                             := ecp_frame_start
  io.ecp_protocol_error                          := ecp_protocol_error_reg
  io.ecp_protocol_error_seq                      := ecp_protocol_error_seq_reg
  io.ecp_idle                                    := !ecp_active && !ecp_complete_reg
  io.compare_busy                                := do_check.asBool
  io.compare_idle                                := !do_check.asBool && !compare_done_valid_reg
  io.compare_done                                := compare_done_valid_reg
  io.compare_done_seq                            := compare_done_seq_reg
  io.compare_done_epoch                          := compare_done_epoch_reg
  io.compare_done_error                          := compare_done_error_reg

  // This is wrong, which is just for reducing the size of the design
  
  val width_of_error_code                         = 4*params.xLen+8
  val u_channel                                   = Module (new GH_MemFIFO(FIFOParams((width_of_error_code), 2)))
  val channel_enq_valid                           = WireInit(false.B)
  val channel_enq_data                            = WireInit(0.U((width_of_error_code).W))
  val channel_deq_ready                           = WireInit(false.B)
  val channel_deq_data                            = WireInit(0.U((width_of_error_code).W))
  val channel_empty                               = WireInit(true.B)
  val channel_full                                = WireInit(false.B)

  u_channel.io.enq_valid                         := channel_enq_valid
  u_channel.io.enq_bits                          := channel_enq_data
  u_channel.io.deq_ready                         := channel_deq_ready
  channel_deq_data                               := u_channel.io.deq_bits
  channel_empty                                  := u_channel.io.empty
  channel_full                                   := u_channel.io.full

  if_check_completed                             := compare_done_valid_reg.asUInt
  io.if_cp_check_completed                       := if_check_completed

  compare_read_valid := compare_issue
  val arf_mismatch = do_check.asBool && compare_read_valid &&
    !ecp_frame_start && !io.compare_abort &&
    ((checker_arfs_snapshot(checking_counter_memdelay) =/= arf_data_ECP) ||
      (checker_farfs_snapshot(checking_counter_memdelay) =/= farf_data_ECP))

  when (io.package_clear || io.package_start) {
    do_check := 0.U
    checking_counter := 1.U
    checking_counter_memdelay := 0.U
    compare_reads_issued := false.B
    compare_read_valid := false.B
    compare_error_accum := false.B
    compare_seq_reg := 0.U
    compare_epoch_reg := 0.U
    compare_done_valid_reg := false.B
    compare_done_seq_reg := 0.U
    compare_done_epoch_reg := 0.U
    compare_done_error_reg := false.B
  }.elsewhen (io.compare_abort || ecp_frame_start) {
    do_check := 0.U
    checking_counter := 1.U
    checking_counter_memdelay := 0.U
    compare_reads_issued := false.B
    compare_read_valid := false.B
    compare_error_accum := false.B
    compare_done_valid_reg := false.B
    compare_done_seq_reg := 0.U
    compare_epoch_reg := 0.U
    compare_done_epoch_reg := 0.U
    compare_done_error_reg := false.B
  }.otherwise {
    when (io.compare_done_ack) {
      compare_done_valid_reg := false.B
      compare_done_seq_reg := 0.U
      compare_done_error_reg := false.B
    }
    when (io.compare_start && !do_check.asBool && !compare_done_valid_reg) {
      do_check := 1.U
      checking_counter := 1.U
      checking_counter_memdelay := 0.U
      compare_reads_issued := false.B
      compare_read_valid := false.B
      compare_error_accum := false.B
      compare_seq_reg := io.package_seq
      compare_epoch_reg := ecp_frame_epoch
      for (i <- 0 until params.numARFS) {
        checker_arfs_snapshot(i) := io.core_arfs_in(i)
        checker_farfs_snapshot(i) := io.core_farfs_in(i)
      }
    }.elsewhen (do_check.asBool) {
      when (compare_issue) {
        checking_counter_memdelay := checking_counter
        when (checking_counter === 0x1f.U) {
          compare_reads_issued := true.B
        }.otherwise {
          checking_counter := checking_counter + 1.U
        }
      }
      when (compare_read_valid) {
        compare_error_accum := compare_error_accum || arf_mismatch
        when (checking_counter_memdelay === 0x1f.U) {
          do_check := 0.U
          compare_done_valid_reg := true.B
          compare_done_seq_reg := compare_seq_reg
          compare_done_epoch_reg := compare_epoch_reg
          compare_done_error_reg := compare_error_accum || arf_mismatch
        }
      }
    }
  }

  // Preserve the legacy ELU FIFO boundary: the terminal compare is reported
  // through check_error but is not enqueued for a later ELU dequeue.
  channel_enq_valid                              := arf_mismatch && checking_counter_memdelay =/= 0x1f.U
  io.check_error                                 := arf_mismatch
  channel_enq_data                               := Mux(channel_enq_valid.asBool,
    Cat(checking_counter_memdelay, farf_data_ECP,
      checker_farfs_snapshot(checking_counter_memdelay), arf_data_ECP,
      checker_arfs_snapshot(checking_counter_memdelay)), 0.U)
  channel_deq_ready                              := io.elu_cp_deq.asBool
  io.elu_cp_data                                 := channel_deq_data
  io.elu_status                                  := ~channel_empty
  io.core_hang_up                                := apply_snapshot | apply_snapshot_memdelay | io.record_context | recording_context
  // if (GH_GlobalParams.GH_DEBUG == 1) {
  //   when (channel_enq_valid && (io.core_trace.asBool)) {
  //       val print_farf_data                       = WireInit(0.U((params.xLen).W))
  //       val print_arf_data                        = WireInit(0.U((params.xLen).W))
  //       print_farf_data                          := io.core_farfs_in(checking_counter_memdelay)
  //       print_arf_data                           := io.core_arfs_in(checking_counter_memdelay)

  //       printf(midas.targetutils.SynthesizePrintf("ELU_ARF: an error is detected! [ARF_ID = %d] [farf_data_ECP = %x], [farf_data = %x], [arf_data_ECP = %x], [arf_data = %x]. \n", 
  //       checking_counter_memdelay, farf_data_ECP, print_farf_data, arf_data_ECP, print_arf_data))
  //   }
  // }
  

  // Faking ELU data
  // val checking_counter_memdelay                   = RegInit(0.U(2.W))
  // checking_counter_memdelay                      := checking_counter
  // val if_check_completed                          = WireInit(0.U(1.W))

  // when (!do_check.asBool) {
  //   do_check                                     := Mux(io.do_cp_check.asBool && !if_check_completed.asBool, 1.U, 0.U)
  //   checking_counter                             := Mux(io.clear_ic_status.asBool, 0.U, checking_counter)
  // } .otherwise {
  //   do_check                                     := Mux(if_check_completed.asBool, 0.U, 1.U)
  //   checking_counter                             := Mux(checking_counter === 0x2.U, checking_counter, checking_counter + 1.U)
  // }
  // if_check_completed                             := (checking_counter_memdelay === 0x2.U).asUInt
  // io.if_cp_check_completed                       := if_check_completed

  // io.core_hang_up                                := apply_snapshot | apply_snapshot_memdelay | io.record_context | recording_context | (do_check.asBool && !if_check_completed.asBool)  
  // io.elu_cp_data                                 := 0.U
  // io.elu_status                                  := 0.U

  assert(!io.compare_start || (ecp_complete_reg && io.package_seq === ecp_owner_seq),
    "ARF compare started without a complete matching ECP")
  assert(!compare_done_valid_reg || compare_done_seq_reg === ecp_owner_seq,
    "ARF compare result lost its ECP sequence ownership")
  assert(!compare_done_valid_reg || compare_done_epoch_reg === ecp_frame_epoch,
    "ARF compare result lost its ECP frame ownership")
}
