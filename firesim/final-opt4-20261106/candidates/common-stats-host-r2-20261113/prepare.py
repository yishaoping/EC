#!/usr/bin/python3
"""Derive a direct-bank mixed-role harness without changing hardware bodies."""
from pathlib import Path
import hashlib
import json
import re

C=Path(__file__).resolve().parent
W=C.parent.parent
T=W/'Opt4-area-common-stats-host-r2-20261113'
BOOM=T/'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
BAR=T/'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def exact(p,s):
    if p.exists():assert p.read_text()==s,('immutable',str(p))
    else:p.write_text(s)

def split(text,decl):
    body=text[text.index(decl):]
    body=body[body.index(' extends Module {')+len(' extends Module {'):]
    body=body[:body.rfind('\n}')]
    start=body.index('  val io = IO(new Bundle {')
    end=body.index('\n  })',start)+len('\n  })')
    ports=body[start+len('  val io = IO(new Bundle {'):end-len('\n  })')]
    # A direct child of RawModule avoids PromoteSubmodule's nonlocal-target
    # limitation. Scope-only visibility keywords are removed inside the method.
    cone=body[:start]+body[end:]
    flattened=cone.replace('  private ','  ')
    return ports,flattened,dict(original_body_sha256=hashlib.sha256(body.encode()).hexdigest(),
        method_body_sha256=hashlib.sha256(flattened.encode()).hexdigest(),
        io_declaration_rebound_only=True,scope_visibility_only=True,
        extra_registers=0,extra_target_cycles=0)

def prepare():
    a,ab,ar=split(BOOM.read_text(),'class PackageAddressStats(')
    b,bb,br=split(BAR.read_text(),'class GHBarrierLatencyStats(')
    s='''package commonstatshost
import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}
import boom.lsu._
import ecstatscommon.StatsBank
import freechips.rocketchip.guardiancouncil._
class AddressIO extends Bundle {
'''+a+'''\n}
class BarrierIO extends Bundle {
'''+b+'''\n}
class MixedIO extends Bundle {
  val address = new AddressIO
  val barrier = Vec(3, new BarrierIO)
}
trait Bodies { this: RawModule =>
  def addressBody(io: AddressIO): Unit = {
    val commitWidth=3; val addrBits=40; val lineBytes=64; val packetWindow=256
    val queueDepth=256; val packageSets=1024; val packageWays=8
'''+ab+'''\n  }
  def barrierBody(io: BarrierIO): Unit = {
    val window=256; val bankLanes=16
'''+bb+'''\n  }
}
// Oracle preserves the committed production callers as actual Modules.
class MixedTarget extends Module {
  val io=IO(new MixedIO)
  val address=Module(new PackageAddressStats(3,40,64,256))
  address.io <> io.address
  for(i <- 0 until 3) {
    val barrier=Module(new GHBarrierLatencyStats(256,16))
    barrier.io <> io.barrier(i)
  }
}
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new MixedTarget,
    Array("--target-dir",args(0),"--output-file","MixedTarget"))
}
class MixedHost(implicit p: Parameters) extends RawModule with Bodies {
  val clock=midas.widgets.RationalClockBridge().io.clocks.head
  val reset=WireInit(false.B)
  val io=Wire(new MixedIO)
  withClockAndReset(clock,reset) {
    addressBody(io.address)
    for(i <- 0 until 3) barrierBody(io.barrier(i))
    midas.widgets.PeekPokeBridge(clock,reset,"io" -> io)
  }
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
    # IO types originally use constructor-local widths.
    s=s.replace('class AddressIO extends Bundle {','class AddressIO extends Bundle {\n  val commitWidth=3; val addrBits=40')
    exact(C/'Mixed.scala',s)
    # Assert each complete sequential/combinational cone occurs exactly once.
    assert s.count(ab)==1 and s.count(bb)==1
    return dict(address=ar,barrier=br,production_callers={str(p):sha(p) for p in [BOOM,BAR]},
        mixed_target_uses_actual_committed_modules=True,host_uses_direct_selected_children=True,
        production_slots=256,selected_type='StatsBank',selected_instances=64,
        address_banks=16,barrier_banks=48,lanes=16,public_outputs=73,
        public_token_sampling='after_target_rising_edge_and_precise_host_boundary',
        scope='Actual mixed-role complete callers, isolated host transform/token and OOC area pair. No whole EC equivalence or shell FIT.')
if __name__=='__main__':print(json.dumps(prepare(),indent=2))
