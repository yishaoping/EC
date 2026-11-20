#!/usr/bin/python3
"""Freeze an independently committed 256-entry banked-barrier experiment."""
from pathlib import Path
import hashlib
import json
import subprocess

C = Path(__file__).resolve().parent
W = C.parent.parent
TREE = W/'Opt4-area-barrier-banked-r1-20261113'
BASE = W/'Opt4-area-sprint-20261112'
REL = Path('chipyard/generators/rocket-chip/src/main/scala/guardiancouncil')
PARENT = 'fd5de2bafb8f5d236dfe240fbecf3436f8c3468a'

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def exact(p, text):
    if p.exists():
        assert p.read_text() == text, ('immutable input differs', str(p))
    else:
        p.write_text(text)

def derive():
    old = subprocess.check_output(['git','show',PARENT+':'+str(REL/'BarrierLatencyStats.scala')],cwd=BASE,text=True)
    text = old
    edits = []
    def change(a,b):
        nonlocal text
        assert text.count(a)==1, (a[:70],text.count(a))
        at=text.index(a);edits.append(dict(offset=at,old=a,new=b))
        text=text[:at]+b+text[at+len(a):]
    change('import chisel3.util._','import chisel3.util._\nimport chisel3.experimental.annotate\nimport midas.targetutils.EnableModelMultiThreadingAnnotation')
    change('class GHBarrierLatencyStats(val window: Int) extends Module {',
           'class GHBarrierLatencyStats(val window: Int, val bankLanes: Int = 16) extends Module {')
    change('  val buckets = RegInit(0.U.asTypeOf(new GHBarrierLatencyBucket(window)))', '''  require(isPow2(bankLanes) && bankLanes <= window)
  val bucketBanks = Seq.tabulate(window / bankLanes) { b =>
    val bank = Module(new GHBarrierBucketBank(window, bankLanes))
    bank.io.base := (b * bankLanes).U
    bank.io.resetStats := io.resetStats
    bank.io.event := io.event
    bank.io.safeWatermark := io.safeWatermark
    bank.io.currentCycle := io.currentCycle
    annotate(EnableModelMultiThreadingAnnotation(bank))
    bank
  }''')
    a=text.index('  val bucketResolve =');b=text.index('  // An exact width-growing',a)
    change(text[a:b],'')
    a=text.index('  val resolvedBucketsWide =');b=text.index('  // Candidate only:',a)
    change(text[a:b],'''  val resolvedBucketsWide = exactBucketSum(bucketBanks.map(_.io.resolvedCount))
  val requestBucketsWide = exactBucketSum(bucketBanks.map(_.io.resolvedRequest))
''')
    a=text.index('  val eventBucketAvailable =');b=text.index('  val eventAccepted =',a)
    change(text[a:b],'  val eventBucketAvailable = bucketBanks.map(_.io.eventAvailable).reduce(_ || _)\n')
    a=text.index('  val bucketCountOverflow =');b=text.index('  val reductionOverflow =',a)
    change(text[a:b],'''  val bucketCountOverflow = bucketBanks.map(_.io.countOverflow).reduce(_ || _)
  val bucketCycleOverflow = bucketBanks.map(_.io.cycleOverflow).reduce(_ || _)
''')
    a=text.index('    for (i <- 0 until window) {',text.index('  when (io.resetStats)'))
    b=text.index('    when (io.event.valid) { seen :=',a)
    change(text[a:b],'  }.otherwise {\n')
    # Counters, pending arithmetic, overflow tests and all public assignments
    # outside the bucket projection must be exactly reversible.
    restored=text
    for e in reversed(edits):
        assert restored[e['offset']:e['offset']+len(e['new'])]==e['new']
        restored=restored[:e['offset']]+e['old']+restored[e['offset']+len(e['new']):]
    assert restored==old
    return old,text,edits

def prepare(write_source=False):
    old,new,edits=derive()
    source=TREE/REL/'BarrierLatencyStats.scala'
    if write_source:
        assert source.read_text()==old
        source.write_text(new)
    assert source.read_text()==new
    bank=TREE/REL/'BarrierBucketBank.scala'
    # Separate proof views keep every 161-bit entry observable while the
    # production module and generated-host area contain seven public outputs.
    debug='\n    val debugView = Output(Vec(window, UInt(161.W)))'
    observe='\n  for (i <- 0 until window) {\n    io.debugView(i) := Cat(buckets.valid(i), buckets.seq(i), buckets.count(i), buckets.requestCycleSum(i))\n  }\n'
    reference=old.replace('package freechips.rocketchip.guardiancouncil',
        'package barrierbankreference\nimport freechips.rocketchip.guardiancouncil.GH_GlobalParams',1)
    proof=reference.replace('    val seen = Output(UInt(64.W))','    val seen = Output(UInt(64.W))'+debug,1)
    at=proof.rfind('\n}');proof=proof[:at]+observe+proof[at:]
    exact(C/'ReferenceProof.scala',proof)
    exact(C/'ReferenceModule.scala',reference)
    cproof=new.replace('    val seen = Output(UInt(64.W))','    val seen = Output(UInt(64.W))'+debug,1)
    obs='\n  for (i <- 0 until window) io.debugView(i) := bucketBanks(i / bankLanes).io.observe(i % bankLanes)\n'
    at=cproof.rfind('\n}');cproof=cproof[:at]+obs+cproof[at:]
    exact(C/'CandidateProof.scala',cproof)
    btext=bank.read_text()
    bproof=btext.replace('    val base = Input(UInt(indexBits.W))','    val observe = Output(Vec(lanes, UInt(161.W)))\n    val base = Input(UInt(indexBits.W))',1)
    obs='\n  for (i <- 0 until lanes) io.observe(i) := Cat(buckets.valid(i), buckets.seq(i), buckets.count(i), buckets.requestCycleSum(i))\n'
    at=bproof.rfind('\n}');bproof=bproof[:at]+obs+bproof[at:]
    exact(C/'BankProof.scala',bproof)
    return dict(parent_commit=PARENT, functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source_inverse_byte_equal=True,global_counter_arithmetic_and_assignment_bytes_preserved=True,
        state_bits_per_entry=161,slots=256,bank_lanes=[16,8],banks=[16,32],
        target_cycle_changes=0,extra_target_registers=0,edits=edits,
        source_files={str(p):sha(p) for p in [source,bank]},
        proof_files={str(C/n):sha(C/n) for n in ['ReferenceProof.scala','ReferenceModule.scala','CandidateProof.scala','BankProof.scala']},
        integration_limit='Isolated module uses one selected FAME5 type with power-of-two instances. Whole-EC adoption must reconcile AddressStats and three barrier instances under the existing one-type/power-of-two rule before any combined-host build.',
        scope='Experimental complete barrier; no target/host parity, area saving, whole EC equivalence or FIT claim yet.')

if __name__=='__main__':
    import sys
    binding=prepare('--write-source' in sys.argv)
    print(json.dumps({k:binding[k] for k in ['source_inverse_byte_equal','slots','bank_lanes']}))
