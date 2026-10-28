package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}

//==========================================================
// Parameters
//==========================================================
case class GHT_SCH_Params(
  totalnumber_of_checkers: Int
)

//==========================================================
// I/Os
//==========================================================
class GHT_SCH_IO (params: GHT_SCH_Params) extends Bundle {
  val rst_sch                                   = Input(UInt(1.W))
  val core_s                                    = Input(UInt(4.W))
  val core_e                                    = Input(UInt(4.W))
  val inst_c                                    = Input(UInt(1.W))
  val core_d                                    = Output(UInt(params.totalnumber_of_checkers.W))
  val core_na                                   = Input(Vec(params.totalnumber_of_checkers, UInt(1.W)))
  val sch_hang                                  = Output(UInt(1.W))
  val sch_dest                                  = Output(UInt(5.W)) // Different from core_d, sch_dest is not BITMAP
}




trait HasGHT_SCH_IO extends BaseModule {
  val params: GHT_SCH_Params
  val io = IO(new GHT_SCH_IO(params))
}

//==========================================================
// Implementations
//==========================================================
class GHT_SCH_RR (val params: GHT_SCH_Params) extends Module with HasGHT_SCH_IO
{
  var core_dest                                 = WireInit(0.U(params.totalnumber_of_checkers.W))
  var new_packet                                = WireInit(false.B)
  new_packet                                    = (io.inst_c === 1.U)
  

  val dest_last                                 = RegInit(0.U(4.W))
  val dest                                      = WireInit(0.U(4.W))
  val out_of_range                              = WireInit(0.U(1.W))
  out_of_range                                 := (dest_last < io.core_s) || (dest_last > io.core_e)

  dest                                         := MuxCase(0.U, 
                                                    Array((new_packet & (out_of_range === 1.U)) -> io.core_s,
                                                          (new_packet & (out_of_range === 0.U) & (dest_last === io.core_e)) -> io.core_s,
                                                          (new_packet & (out_of_range === 0.U) & (dest_last =/= io.core_e)) -> (dest_last + 1.U)
                                                          ))

  when (new_packet === true.B) {
      dest_last                                := dest
  } .otherwise {
      dest_last                                := dest_last
  }

  core_dest                                    := MuxCase(0.U, 
                                                    Array((dest =/= 0.U) -> (1.U << (dest - 1.U)),
                                                          (dest === 0.U) -> 0.U
                                                         ))
  val zero                                      = WireInit(0.U(1.W))
  io.sch_dest                                  := Cat(zero, dest)
  io.core_d                                    := core_dest
  io.sch_hang                                  := 0.U
}

//==========================================================
class GHT_SCH_FP (val params: GHT_SCH_Params) extends Module with HasGHT_SCH_IO
{
  val core_dest                                 = WireInit(0.U(params.totalnumber_of_checkers.W))
  val current_dest                              = RegInit(0.U(4.W))
  val dest                                      = WireInit(0.U(4.W))
  val nxt_dest                                  = WireInit(0.U(4.W))
  val new_packet                                = WireInit(false.B)
  new_packet                                   := (io.inst_c === 1.U)

  val sch_hang_reg                              = RegInit(0.U(1.W))

  when ((io.core_na(current_dest-1.U) === 1.U) && (io.core_na(nxt_dest-1.U) === 1.U)){
    // We hang the big core, when current dest and next_dest are both unaviable.
    sch_hang_reg                               := 1.U
  } .otherwise {
    when ((sch_hang_reg === 1.U) && ((io.core_na(nxt_dest-1.U) === 0.U))){
      sch_hang_reg                             := 0.U 
    }
  }


  val out_of_range                              = WireInit(false.B)
  val change_dest                               = WireInit(false.B)
  out_of_range                                 := (current_dest < io.core_s) || (current_dest > io.core_e)

  // We only change the dest when current core is not avaiable and next core is avaiable 
  // bit 0  checker 1, global ID: 1 
  change_dest                                  := ((io.core_na(current_dest-1.U) === 1.U) && (io.core_na(nxt_dest-1.U) === 0.U) || out_of_range)

  
  io.sch_hang                                  := sch_hang_reg
  
  nxt_dest                                     := MuxCase(0.U, 
                                                    Array((out_of_range) -> io.core_s,
                                                          ((!out_of_range) & (current_dest === io.core_e)) -> io.core_s,
                                                          ((!out_of_range) & (current_dest =/= io.core_e)) -> (current_dest + 1.U)
                                                         ))

  when (change_dest) {
      current_dest                             := Mux((io.rst_sch === 1.U), io.core_s, nxt_dest)
  } .otherwise {
      current_dest                             := Mux((io.rst_sch === 1.U), io.core_s, current_dest)
  }

  dest                                         := MuxCase(0.U, 
                                                    Array((!new_packet) -> 0.U,
                                                          (new_packet & change_dest) -> nxt_dest,
                                                          (new_packet & !change_dest) -> current_dest
                                                          ))

  core_dest                                    := MuxCase(0.U, 
                                                    Array((dest =/= 0.U) -> (1.U << (dest - 1.U)),
                                                          (dest === 0.U) -> 0.U
                                                         ))
                                                         
  val zero                                      = WireInit(0.U(1.W))
  io.sch_dest                                  := Cat(zero, dest)
  io.core_d                                    := core_dest

}


class GHT_SCH_ANYAVILIABLE (val params: GHT_SCH_Params) extends Module with HasGHT_SCH_IO
{
  // `core_na` is a busy/disabled bitmap.  The old any-available policy
  // restarted its priority search at checker 1 whenever the current checker
  // became busy, so short packages could repeatedly favor the same checker.
  // `inst_c` is driven by R_IC only on a successful package allocation and is
  // used here as a round-robin advance event.  If no allocation occurs, keep
  // the current target unless it is unavailable, in which case fall back to
  // the first available checker exactly as before.
  val all_unavailable                            = io.core_na.map(_.asBool).reduce(_ && _)
  val current_dest                               = RegInit(0.U(4.W))
  val current_in_range                           = current_dest >= io.core_s && current_dest <= io.core_e
  val current_index                              = Mux(current_in_range, current_dest - io.core_s, 0.U)
  val current_unavailable                        = !current_in_range || io.core_na(current_index).asBool

  val first_available = MuxCase(io.core_s,
    (0 until params.totalnumber_of_checkers).map(i =>
      !io.core_na(i) -> (i + 1).U(4.W)))

  val rr_candidates = (0 until params.totalnumber_of_checkers).map { offset =>
    val raw = Mux(current_in_range, current_dest, io.core_s) + (offset + 1).U
    val span = io.core_e - io.core_s + 1.U
    Mux(raw > io.core_e, raw - span, raw)
  }
  val rr_available = MuxCase(current_dest,
    rr_candidates.map(dest =>
      !io.core_na(dest - io.core_s) -> dest))
  val next_dest = Mux(io.inst_c.asBool,
    Mux(all_unavailable, current_dest, rr_available),
    Mux(current_unavailable, Mux(all_unavailable, current_dest, first_available), current_dest))

  current_dest                                 := Mux(io.rst_sch === 1.U, io.core_s, next_dest)
  io.sch_dest                                  := Mux(io.rst_sch === 1.U, io.core_s, next_dest)
  io.core_d                                    := 0.U
  io.sch_hang                                  := 0.U
  dontTouch(rr_available)
}


//==========================================================
class GHT_SCH_RRF (val params: GHT_SCH_Params) extends Module with HasGHT_SCH_IO
{
  var core_dest                                 = WireInit(0.U(params.totalnumber_of_checkers.W))
  var new_packet                                = WireInit(false.B)
  new_packet                                    = (io.inst_c === 1.U)
  

  val t_counter                                 = RegInit(0.U(2.W))
  when (new_packet === true.B) {
    t_counter                                  := t_counter + 1.U
  } .otherwise {
    t_counter                                  := t_counter
  }

  val dest_last                                 = RegInit(0.U(4.W))
  val dest                                      = WireInit(0.U(4.W))
  val out_of_range                              = WireInit(0.U(1.W))
  out_of_range                                 := (dest_last < io.core_s) || (dest_last > io.core_e)

  dest                                         := MuxCase(0.U, 
                                                    Array((new_packet & (out_of_range === 1.U)) -> io.core_s,
                                                          (new_packet & (out_of_range === 0.U) & (t_counter =/= 3.U)) -> dest_last,
                                                          (new_packet & (out_of_range === 0.U) & (dest_last === io.core_e) & (t_counter === 3.U)) -> io.core_s,
                                                          (new_packet & (out_of_range === 0.U) & (dest_last =/= io.core_e) & (t_counter === 3.U)) -> (dest_last + 1.U)
                                                          ))

  when (new_packet === true.B) {
      dest_last                                := dest
  } .otherwise {
      dest_last                                := dest_last
  }

  core_dest                                    := MuxCase(0.U, 
                                                  Array((dest =/= 0.U) -> (1.U << (dest - 1.U)),
                                                        (dest === 0.U) -> 0.U
                                                       ))

  io.core_d                                    := core_dest
  val zero                                      = WireInit(0.U(1.W))
  io.sch_dest                                  := Cat(zero, dest)
  io.sch_hang                                  := 0.U
}


class GHT_SCH_PIN (val params: GHT_SCH_Params) extends Module with HasGHT_SCH_IO
{
  var core_dest                                 = WireInit(0.U(params.totalnumber_of_checkers.W))
  var new_packet                                = WireInit(false.B)
  new_packet                                    = (io.inst_c === 1.U)

  val dest                                      = Mux(new_packet.asBool, io.core_s, 0.U)
  core_dest                                    := MuxCase(0.U, 
                                                    Array((dest =/= 0.U) -> (1.U << (dest - 1.U)),
                                                          (dest === 0.U) -> 0.U
                                                         ))

  val zero                                      = WireInit(0.U(1.W))
  io.sch_dest                                  := Cat(zero, dest)
  io.core_d                                    := core_dest
  io.sch_hang                                  := 0.U
}
