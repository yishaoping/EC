"""Expose the exact existing caller body directly under its host wrapper."""
from pathlib import Path
import hashlib

C = Path(__file__).resolve().parent
W = C.parent.parent
SOURCE = W / 'candidates/address-banked-production-host-r1-20261112/CandidateModule.scala'


def derive():
    text = SOURCE.read_text()
    body = text[text.index('class PackageAddressStats('):]
    body = body[body.index(' extends Module {') + len(' extends Module {'):]
    body = body[:body.rfind('\n}')]
    start = body.index('  val io = IO(new Bundle {')
    end = body.index('\n  })', start) + len('\n  })')
    ports = body[start + len('  val io = IO(new Bundle {'):end - len('\n  })')]
    cone = body[:start] + body[end:]
    cone = cone.replace('  private ', '  ')
    header = text[:text.index('class PackageAddressStats(')]
    imports = '\n'.join(line for line in header.splitlines() if line.startswith('import '))
    harness = '''package opt4productiondirect
import chisel3._
import chisel3.util._
import opt4bankedproduction._
import org.chipsalliance.cde.config.{Config, Parameters}
''' + imports + '''
class ProductionIO extends Bundle {
  val commitWidth=3; val addrBits=40
''' + ports + '''
}
class CompleteHost(implicit p: Parameters) extends RawModule {
  val clock = midas.widgets.RationalClockBridge().io.clocks.head
  val reset = WireInit(false.B)
  val io = Wire(new ProductionIO)
  def actualBody(io: ProductionIO): Unit = {
    val commitWidth=3; val addrBits=40; val lineBytes=64; val packetWindow=256
    val queueDepth=256; val packageSets=1024; val packageWays=8
''' + cone + '''
  }
  withClockAndReset(clock,reset) {
    actualBody(io)
    midas.widgets.PeekPokeBridge(clock,reset,"io" -> io)
  }
}
'''
    assert harness.count(cone) == 1
    return harness, dict(
        caller_source_sha256=hashlib.sha256(text.encode()).hexdigest(),
        original_body_sha256=hashlib.sha256(body.encode()).hexdigest(),
        method_body_sha256=hashlib.sha256(cone.encode()).hexdigest(),
        io_rebound_only=True, private_visibility_only=True,
        added_registers=0, added_target_cycles=0, selected_direct_children=16,
        public_outputs=52, proof_channels=False)


if __name__ == '__main__':
    result, _ = derive()
    (C / 'Direct.scala').write_text(result)
