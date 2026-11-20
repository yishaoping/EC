package resultcdcprobe
import chisel3._
import chisel3.util._
import midas.widgets.{PeekPokeBridge,RationalClock,RationalClockBridge}
import org.chipsalliance.cde.config.{Config,Parameters}

class QueuePairHost(implicit p:Parameters) extends RawModule {
  val clocks=RationalClockBridge(RationalClock("Checker",1,2)).io.clocks
  val reset=WireInit(false.B)
  val inputs=Wire(Input(UInt(38.W)))
  val pair=withClockAndReset(clocks.head,reset){Module(new QueuePair)}
  // The result direction is checker -> BOOM, opposite to the data CDC.
  pair.io.enqClock:=clocks(1);pair.io.deqClock:=clocks(0)
  pair.io.enqReset:=reset||inputs(0);pair.io.deqReset:=reset||inputs(1)
  pair.io.enqValid:=inputs(2);pair.io.deqReady:=inputs(3);pair.io.enqBits:=inputs(37,4)
  val equal=pair.io.readyFlat===pair.io.readyLocal && pair.io.validFlat===pair.io.validLocal &&
    (!pair.io.validFlat || pair.io.bitsFlat===pair.io.bitsLocal)
  val outputs=Wire(Output(UInt(3.W)))
  outputs:=withClockAndReset(clocks.head,reset){RegNext(Cat(equal,pair.io.readyFlat,pair.io.validFlat),0.U)}
  PeekPokeBridge(clocks.head,reset,"inputs"->inputs,"outputs"->outputs)
}
class PlainConfig extends Config(new Config((site,here,up)=>{
  case midas.GenerateMultiCycleRamModels=>true
  case midas.EnableModelMultiThreading=>false
})++new firesim.configs.DacXilinxAlveoConfig)
object EmitHost extends App {
  implicit val p:Parameters=new PlainConfig
  (new chisel3.stage.ChiselStage).emitVerilog(new QueuePairHost,Array("--target-dir",args(0)))
}
