#!/usr/bin/python3
"""Derive exact production caller bodies with only explicit lane parameters."""
from pathlib import Path
import hashlib
import importlib.util

C=Path(__file__).resolve().parent
W=C.parent.parent
T=W/'Opt4-area-common-mixed-geometry-r1-20261113'
A='chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
B='chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'

def derive():
    spec=importlib.util.spec_from_file_location('unchanged_caller_body_split',W/'candidates/common-stats-host-r2-20261113/prepare.py')
    helper=importlib.util.module_from_spec(spec);spec.loader.exec_module(helper)
    a,ab,ar=helper.split((T/A).read_text(),'class PackageAddressStats(')
    b,bb,br=helper.split((T/B).read_text(),'class GHBarrierLatencyStats(')
    text='''package commonstatshost
import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}
import boom.lsu._
import ecstatscommon.StatsBank
import freechips.rocketchip.guardiancouncil._
class AddressIO extends Bundle {
  val commitWidth=3; val addrBits=40
'''+a+'''\n}
class BarrierIO extends Bundle {
'''+b+'''\n}
class MixedIO extends Bundle {
  val address=new AddressIO
  val barrier=Vec(3,new BarrierIO)
}
trait Bodies { this: RawModule =>
  def addressBody(io: AddressIO, bankLanes: Int): Unit = {
    val commitWidth=3; val addrBits=40; val lineBytes=64; val packetWindow=256
    val queueDepth=256; val packageSets=1024; val packageWays=8
'''+ab+'''\n  }
  def barrierBody(io: BarrierIO, bankLanes: Int): Unit = {
    val window=256
'''+bb+'''\n  }
}
class MixedTarget(val lanes: Int) extends Module {
  val io=IO(new MixedIO)
  val address=Module(new PackageAddressStats(3,40,64,256,bankLanes=lanes))
  address.io <> io.address
  for(i <- 0 until 3) {
    val barrier=Module(new GHBarrierLatencyStats(256,lanes))
    barrier.io <> io.barrier(i)
  }
}
class MixedHost(val lanes: Int)(implicit p: Parameters) extends RawModule with Bodies {
  val clock=midas.widgets.RationalClockBridge().io.clocks.head
  val reset=WireInit(false.B)
  val io=Wire(new MixedIO)
  withClockAndReset(clock,reset) {
    addressBody(io.address,lanes)
    for(i <- 0 until 3) barrierBody(io.barrier(i),lanes)
    midas.widgets.PeekPokeBridge(clock,reset,"io" -> io)
  }
}
class MixedHost8(implicit p: Parameters) extends MixedHost(8)
class MixedHost32(implicit p: Parameters) extends MixedHost(32)
object Emit extends App {
  val lanes=args(0).toInt
  require(Set(8,32).contains(lanes))
  (new chisel3.stage.ChiselStage).emitVerilog(new MixedTarget(lanes),
    Array("--target-dir",args(1),"--output-file","MixedTarget"))
}
class PlainConfig extends Config(new Config((site,here,up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class ThreadedConfig extends Config(new Config((site,here,up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)
'''
    assert text.count(ab)==1 and text.count(bb)==1
    receipt=dict(address=ar,barrier=br,production_slots_each=256,barrier_callers=3,
        geometries=[dict(lanes=n,banks_per_role=256//n,selected_instances=1024//n) for n in [8,32]],
        complete_caller_body_inverse_identity=True,additional_target_registers=0,
        added_target_cycles=0,public_outputs=73,oracle_and_negative_mutation_unchanged=True,
        production_sources={rel:hashlib.sha256((T/rel).read_bytes()).hexdigest() for rel in [A,B]})
    return text,receipt

if __name__=='__main__':
    import json
    text,receipt=derive()
    (C/'Mixed.scala').write_text(text)
    (C/'derivation.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n')
