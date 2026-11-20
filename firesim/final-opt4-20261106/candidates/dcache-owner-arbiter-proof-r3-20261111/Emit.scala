package opt4ownerarbiter
import chisel3._
import chisel3.util._

/** Exact actual priority Arbiter2 supplies both mutually exclusive write fires.
  * Full512word, arbitrary payload/mask/index synchronous transition cut. Every
  * bit has the same decode/clear topology, so it lifts to all146 payload bits.
  */
class OwnerArbiterTransition extends Module {
 val io=IO(new Bundle {
  val raw=Input(UInt(512.W));val written=Input(UInt(512.W))
  val valid=Input(Vec(2,Bool()));val sinkReady=Input(Bool())
  val refillExtraGuard=Input(Bool())
  val index=Input(Vec(2,UInt(9.W)));val data=Input(Vec(2,Bool()))
  val synchronousReset=Input(Bool())
  val equivalent=Output(Bool());val neverBoth=Output(Bool());val mutationEquivalent=Output(Bool())
 })
 val arb=Module(new Arbiter(Bool(),2))
 for(i<-0 until 2){arb.io.in(i).valid:=io.valid(i);arb.io.in(i).bits:=io.data(i)}
 arb.io.out.ready:=io.sinkReady
 val localWrite=arb.io.in(0).fire
 val refillWrite=arb.io.in(1).fire && io.refillExtraGuard
 val reference=WireDefault(VecInit((io.raw & io.written).asBools))
 when(refillWrite){reference(io.index(1)):=io.data(1)}
 when(localWrite){reference(io.index(0)):=io.data(0)}
 val raw=WireDefault(VecInit(io.raw.asBools));val written=WireDefault(VecInit(io.written.asBools))
 val enabled=localWrite || refillWrite
 val index=Mux(localWrite,io.index(0),io.index(1))
 val data=Mux(localWrite,io.data(0),io.data(1))
 when(enabled && !io.synchronousReset){raw(index):=data;written(index):=true.B}
 when(io.synchronousReset){reference:=0.U.asTypeOf(reference);written:=0.U.asTypeOf(written)}
 val candidate=raw.asUInt & written.asUInt
 io.equivalent:=reference.asUInt===candidate
 io.neverBoth := !(localWrite && refillWrite)
 io.mutationEquivalent:=reference.asUInt===(candidate ^ 1.U)
}
object Emit extends App {
 (new chisel3.stage.ChiselStage).emitVerilog(new OwnerArbiterTransition,Array("--target-dir",args(0)))
}
