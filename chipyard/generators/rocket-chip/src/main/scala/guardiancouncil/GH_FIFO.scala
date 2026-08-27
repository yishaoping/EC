package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._
import chisel3.experimental.{BaseModule}

case class FIFOParams(
  width: Int,
  depth: Int
)

class FIFOIO(params: FIFOParams) extends Bundle {
  val enq_valid = Input(Bool())
  val enq_ready = Output(Bool())
  val full = Output(Bool())
  val enq_bits = Input(UInt(params.width.W))
  val deq_ready= Input(Bool())
  val empty = Output(Bool())
  val deq_bits = Output(UInt(params.width.W))
  val status_fiveslots = Output(UInt(1.W))
  val status_threeslots = Output(UInt(1.W))
  val status_twoslots = Output(UInt(1.W))
  val num_content = Output(UInt(log2Ceil(params.depth).W))
  val high_watermark = Output(UInt(1.W))

  val debug_fcounter = Output(UInt(64.W))
  val debug_fdcounter = Output(UInt(64.W))
}

trait HasFIFOIO extends BaseModule {
  val params: FIFOParams
  val io = IO(new FIFOIO(params))
}

class GH_FIFO(val params: FIFOParams) extends Module with HasFIFOIO {

  def counter(depth: Int, incr: Bool): (UInt, UInt) = {
    val cntReg                  = RegInit(0.U(log2Ceil(depth).W))
    val nextVal                 = Mux(cntReg === (depth-1).U, 0.U, cntReg + 1.U)
    when (incr) {
      cntReg                   := nextVal
    }
    (cntReg, nextVal)
  }

  def counter_candec(depth: Int, incr: Bool, dec: Bool): (UInt, UInt, UInt) = {
    val cntReg                  = RegInit(0.U(log2Ceil(depth).W))
    val nextVal                 = Mux(cntReg === (depth-1).U, 0.U, cntReg + 1.U)
    val lastVal                 = Mux(cntReg === 0.U, (depth-1).U, cntReg - 1.U)
    when (incr) {
      cntReg                   := nextVal
    }.elsewhen(dec) {
      cntReg                   := lastVal
    }
    (cntReg, nextVal, lastVal)
  }

  // the register based memory
  val memReg                    = RegInit(VecInit(Seq.fill(params.depth)(0.U(params.width.W))))

  val incrRead                  = WireInit(false.B)
  val decRead                   = WireInit(false.B)
  val incrWrite                 = WireInit(false.B)

  val (readPtr, nextRead)       = counter(params.depth, incrRead)
  val (writePtr, nextWrite)     = counter(params.depth, incrWrite)
  val (readPtr1, nextRead1, decRead1)       = counter_candec(params.depth, incrRead, decRead)

  val emptyReg                  = RegInit(true.B)
  val fullReg                   = RegInit(false.B)
  val num_contentReg            = RegInit(0.U(log2Ceil(params.depth).W))
  val debug_fcounter            = RegInit(0.U(64.W))
  val debug_fdcounter           = RegInit(0.U(64.W))

  when ((io.enq_valid && !fullReg) && (io.deq_ready && !emptyReg)) {
    memReg(writePtr)           := io.enq_bits
    emptyReg                   := false.B
    fullReg                    := false.B
    incrWrite                  := true.B
    incrRead                   := true.B
    num_contentReg             := num_contentReg
    debug_fcounter             := debug_fcounter + 1.U
    debug_fdcounter            := debug_fdcounter + 1.U
  }

  when ((io.enq_valid && !fullReg) && !(io.deq_ready && !emptyReg)){
    memReg(writePtr)           := io.enq_bits
    emptyReg                   := false.B
    fullReg                    := nextWrite === readPtr
    incrWrite                  := true.B
    num_contentReg             := num_contentReg + 1.U
    debug_fcounter             := debug_fcounter + 1.U
  }
    
  when (!(io.enq_valid && !fullReg) && (io.deq_ready && !emptyReg)) {
    emptyReg                   := nextRead === writePtr
    fullReg                    := false.B
    incrRead                   := true.B
    num_contentReg             := num_contentReg - 1.U
    debug_fdcounter            := debug_fdcounter + 1.U
  }
  
  io.status_fiveslots          := Mux(num_contentReg >= ((params.depth).U - 5.U),
                                      1.U, 
                                      0.U)

  io.status_threeslots         := Mux(num_contentReg >= ((params.depth).U - 3.U),
                                      1.U, 
                                      0.U)
  
  io.status_twoslots           := Mux(num_contentReg >= ((params.depth).U - 2.U),
                                      1.U, 
                                      0.U)
  
  io.deq_bits                  := memReg(readPtr)
  io.full                      := fullReg
  io.enq_ready                 := !fullReg
  io.empty                     := emptyReg
  io.num_content               := num_contentReg
  io.debug_fcounter            := debug_fcounter
  io.debug_fdcounter           := debug_fdcounter
  if (params.depth > 100){
    io.high_watermark          := Mux(num_contentReg >= ((params.depth).U - 20.U),
                                      1.U, 
                                      0.U)
  } else {
    io.high_watermark          := 0.U
  }
}


class GH_MemFIFO(val params: FIFOParams) extends Module with HasFIFOIO {
  def counter(depth: Int, incr: Bool): (UInt, UInt) = {
    val cntReg                  = RegInit(0.U(log2Ceil(depth).W))
    val nextVal                 = Mux(cntReg === (depth-1).U, 0.U, cntReg + 1.U)
    when (incr) {
      cntReg                   := nextVal
    }
    (cntReg, nextVal)
  }

  val mem                       = SyncReadMem(params.depth, UInt(params.width.W))
  val incrRead                  = WireInit(false.B)
  val incrWrite                 = WireInit(false.B)

  val (readPtr, nextRead)       = counter(params.depth, incrRead)
  val (writePtr, nextWrite)     = counter(params.depth, incrWrite)

  val emptyReg                  = RegInit(true.B)
  val fullReg                   = RegInit(false.B)
  val num_contentReg            = RegInit(0.U(log2Ceil(params.depth).W))
  val debug_fcounter            = RegInit(0.U(64.W))
  val debug_fdcounter           = RegInit(0.U(64.W))

  when ((io.enq_valid && !fullReg) && (io.deq_ready && !emptyReg)) {
    mem.write                     (writePtr, io.enq_bits)
    emptyReg                   := false.B
    fullReg                    := false.B
    incrWrite                  := true.B
    incrRead                   := true.B
    num_contentReg             := num_contentReg
    debug_fcounter             := debug_fcounter + 1.U
    debug_fdcounter            := debug_fdcounter + 1.U
  }

  when ((io.enq_valid && !fullReg) && !(io.deq_ready && !emptyReg)){
    mem.write                     (writePtr, io.enq_bits)
    emptyReg                   := false.B
    fullReg                    := nextWrite === readPtr
    incrWrite                  := true.B
    num_contentReg             := num_contentReg + 1.U
    debug_fcounter             := debug_fcounter + 1.U
  }
    
  when (!(io.enq_valid && !fullReg) && (io.deq_ready && !emptyReg)) {
    emptyReg                   := nextRead === writePtr
    fullReg                    := false.B
    incrRead                   := true.B
    num_contentReg             := num_contentReg - 1.U
    debug_fdcounter            := debug_fdcounter + 1.U
  }
  
  io.status_fiveslots          := Mux(num_contentReg >= ((params.depth).U - 5.U),
                                      1.U, 
                                      0.U)

  io.status_threeslots         := Mux(num_contentReg >= ((params.depth).U - 3.U),
                                      1.U, 
                                      0.U)
  
  io.status_twoslots           := Mux(num_contentReg >= ((params.depth).U - 2.U),
                                      1.U, 
                                      0.U)
  
  io.deq_bits                  := mem.read(readPtr, io.deq_ready)
  io.full                      := fullReg
  io.enq_ready                 := !fullReg
  io.empty                     := emptyReg
  io.num_content               := num_contentReg
  io.debug_fcounter            := debug_fcounter
  io.debug_fdcounter           := debug_fdcounter

  if (params.depth > 100){
    io.high_watermark          := Mux(num_contentReg >= ((params.depth).U - 20.U),
                                      1.U, 
                                      0.U)
  } else {
    io.high_watermark          := 0.U
  }
}

class FIFO_SC_IO(params: FIFOParams) extends Bundle {
  val enq_valid = Input(Bool())
  val enq_bits  = Input(UInt(params.width.W))
  val full      = Output(Bool())

  // peek at speculative head (sptr)
  val peek_valid = Output(Bool())
  val peek_bits  = Output(UInt(params.width.W))

  // reserve consumes one entry from speculative head: sptr++
  val reserve    = Input(Bool())

  // commit consumes one entry from committed head: cptr++
  val can_commit = Output(Bool())
  val commit     = Input(Bool())

  // rollback all speculative reservations: sptr := cptr
  val rollback   = Input(Bool())
  val need_replay_1 = Input(Bool())

  // occupancy between cptr and wptr (committed-visible content)
  val num_content        = Output(UInt(log2Ceil(params.depth).W))
  val status_twoslots    = Output(UInt(1.W))
  val status_threeslots  = Output(UInt(1.W))
  val high_watermark     = Output(UInt(1.W))
}

trait HasFIFO_SC_IO extends BaseModule {
  val params: FIFOParams
  val io = IO(new FIFO_SC_IO(params))
}

class GH_FIFO_SC(val params: FIFOParams) extends Module with HasFIFO_SC_IO {

  private def inc(ptr: UInt): UInt =
    Mux(ptr === (params.depth - 1).U, 0.U, ptr + 1.U)

  private def dec(ptr: UInt): UInt = Mux(ptr === 0.U, (params.depth-1).U, ptr - 1.U)

  private def dist(a: UInt, b: UInt): UInt = {
    // distance from b to a in ring [0, depth)
    val d = Wire(UInt((log2Ceil(params.depth) + 1).W))
    d := Mux(a >= b, a - b, a + params.depth.U - b)
    d(log2Ceil(params.depth)-1, 0) // max is depth-1 (we keep one slot empty)
  }

  val mem = RegInit(VecInit(Seq.fill(params.depth)(0.U(params.width.W))))

  val wptr = RegInit(0.U(log2Ceil(params.depth).W))
  val sptr = RegInit(0.U(log2Ceil(params.depth).W))
  val cptr = RegInit(0.U(log2Ceil(params.depth).W))

  // can_commit: there exists reserved entries (cptr != sptr)
  io.can_commit := (cptr =/= sptr)

  // full depends on committed pointer (so we never overwrite uncommitted region)
  val cptr_after_commit = Mux(io.commit && io.can_commit, inc(cptr), cptr)
  val wptr_next = inc(wptr)
  io.full := (wptr_next === cptr_after_commit)

  // allow enqueue if not full (considering same-cycle commit freeing space)
  val do_enq = io.enq_valid && !io.full
  when (do_enq) {
    mem(wptr) := io.enq_bits
    wptr := wptr_next
  }

  // rollback has highest priority for speculative pointer
  when (io.rollback) {
    sptr := cptr_after_commit // if commit also asserted, use the updated committed point
  }.elsewhen(io.need_replay_1){
    sptr := dec(sptr)
  }
  .otherwise {
    // reserve (advance sptr) if peek_valid
    when (io.reserve && ((sptr =/= wptr) || (do_enq && (sptr === wptr)))) {
      sptr := inc(sptr)
    }
  }

  // commit advances cptr
  when (io.commit && io.can_commit) {
    cptr := inc(cptr)
  }

  // peek_valid: there is data between sptr and wptr
  val empty_spec = (sptr === wptr)
  io.peek_valid := !empty_spec

  // bypass: if empty_spec but we enqueue into the same slot this cycle, peek the incoming
  val peek_raw = mem(sptr)
  io.peek_bits := Mux(empty_spec && do_enq && (wptr === sptr), io.enq_bits, peek_raw)

  // occupancy measured between cptr and wptr
  val occ = dist(wptr, cptr)
  io.num_content := occ

  io.status_twoslots   := Mux(occ >= (params.depth.U - 2.U), 1.U, 0.U)
  io.status_threeslots := Mux(occ >= (params.depth.U - 3.U), 1.U, 0.U)
  io.high_watermark    := Mux(
    if (params.depth > 100) (occ >= (params.depth.U - 20.U)) else false.B,
    1.U, 0.U
  )
}
