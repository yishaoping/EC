package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.experimental.{BaseModule}

case class ANDGATEParams(
  width: Int,
  number: Int
)

class ANDGATEIO(params: ANDGATEParams) extends Bundle {
  val in                                        = Input(Vec(params.number, UInt(params.width.W)))
  val out                                       = Output(UInt(params.width.W))
  val num_checker_in                            = Input(UInt(3.W))
  val num_checker_out                           = Output(UInt(3.W))
  val num_checkers_in                           = Input(UInt(3.W))
  val num_checkers_out                          = Output(UInt(3.W))
  val event                                     = Vec(params.number, Input(UInt(3.W)))
  val event_out                                 = Vec(params.number, Output(UInt(3.W)))
  val events                                    = Input(UInt(3.W))
  val events_out                                = Output(UInt(3.W))
  val empty                                     = Input(Bool())
  val empty_out                                 = Output(Bool())
  val empty1                                    = Input(Bool())
  val empty_out1                                = Output(Bool())
  val empty2                                    = Input(Bool())
  val empty_out2                                = Output(Bool())
  val empty3                                    = Input(Bool())
  val empty_out3                                = Output(Bool())
  val empty4                                    = Input(Bool())
  val empty_out4                                = Output(Bool())
}

trait HasANDGATEIO extends BaseModule {
  val params: ANDGATEParams
  val io = IO(new ANDGATEIO(params))
}

class GH_ANDGATE (val params: ANDGATEParams) extends Module with HasANDGATEIO {
  io.out                                       := io.in.reduce(_&_)
  io.num_checker_out                           := io.num_checker_in
  io.num_checkers_out                          := io.num_checkers_in
  io.event_out                                 <> io.event
  io.events_out                                := io.events
  io.empty_out                                 := io.empty
  io.empty_out1                                := io.empty1
  io.empty_out2                                := io.empty2
  io.empty_out3                                := io.empty3
  io.empty_out4                                := io.empty4
  dontTouch(io.num_checker_in)
  dontTouch(io.num_checker_out)
  dontTouch(io.event)
  dontTouch(io.event_out)
  dontTouch(io.events)
  dontTouch(io.events_out)
  dontTouch(io.num_checkers_in)
  dontTouch(io.num_checkers_out)
  dontTouch(io.empty)
  dontTouch(io.empty_out)
  dontTouch(io.empty1)
  dontTouch(io.empty_out1)
  dontTouch(io.empty2)
  dontTouch(io.empty_out2)
  dontTouch(io.empty3)
  dontTouch(io.empty_out3)
  dontTouch(io.empty4)
  dontTouch(io.empty_out4)
}

