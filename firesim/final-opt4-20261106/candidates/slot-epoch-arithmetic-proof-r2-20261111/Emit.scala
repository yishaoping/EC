package opt4epocharithmetic
import chisel3._
import chisel3.util._

// Per-word full-width transition cut complementary to the queued 512-entry
// write/decode proof. All addresses/enables and all 16-bit values are arbitrary.
class EpochArithmetic extends RawModule {
  val io=IO(new Bundle {
    val old=Input(UInt(16.W));val refill=Input(UInt(16.W))
    val enable=Input(UInt(3.W));val index=Input(Vec(3,UInt(9.W)))
    val observed=Input(UInt(9.W));val synchronousReset=Input(Bool())
    val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
    val wraps=Output(Bool());val independentWrite=Output(Bool())
  })
  val hit=(0 until 3).map(p => io.enable(p) && io.index(p)===io.observed)
  val original=WireDefault(io.old)
  when(hit(0)) { original:=io.old+1.U }
  when(hit(1)) { original:=io.old+1.U }
  when(hit(2)) { original:=io.refill }
  when(io.synchronousReset) { original:=0.U }
  val inc=(io.old+1.U)(15,0)
  val data=VecInit(Seq(inc,inc,io.refill))
  val represented=Mux(io.synchronousReset,0.U,
    Mux(hit(2),data(2),Mux(hit(1),data(1),Mux(hit(0),data(0),io.old))))
  io.equivalent:=original===represented
  // Incorrectly cascading same-cycle increments changes original semantics.
  val mutant=Mux(!io.synchronousReset && !hit(2) && hit(0) && hit(1),
    (io.old+2.U)(15,0),represented)
  io.mutationEquivalent:=original===mutant
  io.wraps:=io.synchronousReset || hit(2) || !(hit(0)||hit(1)) ||
    io.old=/=65535.U || represented===0.U
  io.independentWrite:=io.synchronousReset || !hit(0) ||
    (io.enable(2) && io.index(2)===io.observed) || represented===inc
}
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new EpochArithmetic,Array("--target-dir",args(0)))
}
