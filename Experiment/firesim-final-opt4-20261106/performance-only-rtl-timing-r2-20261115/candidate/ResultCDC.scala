package resultcdcprobe
import chisel3._
import freechips.rocketchip.util.{AsyncQueue,AsyncQueueParams,LocalMemAsyncQueue}
class QueuePair extends RawModule {
  val io=IO(new Bundle {
    val enqClock=Input(Clock());val deqClock=Input(Clock())
    val enqReset=Input(Bool());val deqReset=Input(Bool())
    val enqValid=Input(Bool());val enqBits=Input(UInt(34.W));val deqReady=Input(Bool())
    val readyFlat=Output(Bool());val readyLocal=Output(Bool())
    val validFlat=Output(Bool());val validLocal=Output(Bool())
    val bitsFlat=Output(UInt(34.W));val bitsLocal=Output(UInt(34.W))
  })
  val flat=withClockAndReset(io.enqClock,io.enqReset) {
    Module(new AsyncQueue(UInt(34.W),AsyncQueueParams(256,2)))
  }
  val local=withClockAndReset(io.enqClock,io.enqReset) {
    Module(new LocalMemAsyncQueue(UInt(34.W),AsyncQueueParams(256,2,narrow=true)))
  }
  for(q<-Seq(flat,local)) {
    q.io.enq_clock:=io.enqClock;q.io.deq_clock:=io.deqClock
    q.io.enq_reset:=io.enqReset;q.io.deq_reset:=io.deqReset
    q.io.enq.valid:=io.enqValid;q.io.enq.bits:=io.enqBits;q.io.deq.ready:=io.deqReady
  }
  io.readyFlat:=flat.io.enq.ready;io.readyLocal:=local.io.enq.ready
  io.validFlat:=flat.io.deq.valid;io.validLocal:=local.io.deq.valid
  io.bitsFlat:=flat.io.deq.bits;io.bitsLocal:=local.io.deq.bits
}
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new QueuePair,Array("--target-dir",args(0)))
}
