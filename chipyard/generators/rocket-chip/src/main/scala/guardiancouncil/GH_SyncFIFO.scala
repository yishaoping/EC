package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._

class GH_SyncMEMFIFO[T <: Data](ioType: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    val in            = Flipped(Decoupled(ioType))
    val out           = Decoupled(ioType)
    val count         = Output(UInt((log2Ceil(depth) + 1).W))
    val full          = Output(Bool())
    val empty         = Output(Bool())
    
    val widx          = Output(UInt((log2Ceil(depth)).W))
    val ridx          = Output(UInt((log2Ceil(depth)).W))

    val status_fiveslots = Output(Bool())
    val status_threeslots = Output(Bool())
    val status_twoslots = Output(Bool())
    val high_watermark = Output(Bool())
  })
  require(depth > 0)

  val queue = Module(new Queue(gen = ioType, entries = depth, useSyncReadMem = true))

  io.in <> queue.io.enq
  queue.io.deq <> io.out
  // queue.io.enq.bits  := io.in.bits
  // queue.io.enq.valid := io.in.valid
  // io.in.ready        := queue.io.enq.ready
  //io.in <> queue.io.enq
  // when(queue.io.count <= 1.U){
  //   queue.io.deq.ready := false.B
  //   io.out.bits        := 0.U
  //   io.out.valid       := false.B
  // }.otherwise{
  //   queue.io.deq.ready := io.out.ready
  //   io.out.bits        := queue.io.deq.bits
  //   io.out.valid       := queue.io.deq.valid
  // }
  
  
  //queue.io.deq <> io.out

  io.widx := Counter(io.in.valid && io.in.ready && !io.full, depth)._1
  io.ridx := Counter(io.out.valid && io.out.ready && !io.empty, depth)._1

  io.full         := queue.io.count === depth.U
  io.empty        := queue.io.count === 0.U
  io.count        := queue.io.count
  io.status_fiveslots  := (queue.io.count >= (depth.U - 5.U))
  io.status_threeslots := (queue.io.count >= (depth.U - 3.U))
  io.status_twoslots   := (queue.io.count >= (depth.U - 2.U))
  if(depth > 100){
    io.high_watermark := (queue.io.count >= (depth.U - 50.U))
  }
  else{
    io.high_watermark := false.B
  }
}


class GH_SyncFIFO[T <: Data](ioType: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    val in            = Flipped(Decoupled(ioType))
    val out           = Decoupled(ioType)
    val count         = Output(UInt((log2Ceil(depth) + 1).W))
    val full          = Output(Bool())
    val empty         = Output(Bool())
    
    val widx          = Output(UInt((log2Ceil(depth)).W))
    val ridx          = Output(UInt((log2Ceil(depth)).W))

    val status_fiveslots = Output(Bool())
    val status_threeslots = Output(Bool())
    val status_twoslots = Output(Bool())
    val high_watermark = Output(Bool())
  })
  require(depth > 0)

  val queue = Module(new Queue(gen = ioType, entries = depth, useSyncReadMem = false))

  io.in <> queue.io.enq
  queue.io.deq <> io.out
  // queue.io.enq.bits  := io.in.bits
  // queue.io.enq.valid := io.in.valid
  // io.in.ready        := queue.io.enq.ready
  //io.in <> queue.io.enq
  // when(queue.io.count <= 1.U){
  //   queue.io.deq.ready := false.B
  //   io.out.bits        := 0.U
  //   io.out.valid       := false.B
  // }.otherwise{
  //   queue.io.deq.ready := io.out.ready
  //   io.out.bits        := queue.io.deq.bits
  //   io.out.valid       := queue.io.deq.valid
  // }
  
  
  //queue.io.deq <> io.out

  io.widx := Counter(io.in.valid && io.in.ready && !io.full, depth)._1
  io.ridx := Counter(io.out.valid && io.out.ready && !io.empty, depth)._1

  io.full         := queue.io.count === depth.U
  io.empty        := queue.io.count === 0.U
  io.count        := queue.io.count
  io.status_fiveslots  := (queue.io.count >= (depth.U - 5.U))
  io.status_threeslots := (queue.io.count >= (depth.U - 3.U))
  io.status_twoslots   := (queue.io.count >= (depth.U - 2.U))

  if(depth > 100){
    io.high_watermark := (queue.io.count >= (depth.U - 50.U))
  }
  else{
    io.high_watermark := false.B
  }
}
