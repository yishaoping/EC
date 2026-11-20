#!/usr/bin/python3
"""Build a separate, reversible one-type address/barrier bank experiment."""
from pathlib import Path
import hashlib
import json
import re
import subprocess

C = Path(__file__).resolve().parent
W = C.parent.parent
TREE = W/'Opt4-area-common-stats-bank-r1-20261113'
PARENT = '16b2d8945f6e17385a4fe136eadd9597ee1ac4fc'
BOOM = Path('chipyard/generators/boom/src/main/scala/lsu')
ROCKET = Path('chipyard/generators/rocket-chip/src/main/scala/guardiancouncil')

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def original(rel):
    return subprocess.check_output(['git','show',PARENT+':'+str(rel)],cwd=TREE,text=True)

def exact(p, text):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    if p.exists():
        assert p.read_text() == text, ('immutable source differs', str(p))
    else:
        p.write_text(text)

def derive(write=False):
    address = original(BOOM/'opt4bankedproduction/BucketBank.scala')
    barrier = original(ROCKET/'BarrierBucketBank.scala')
    projected = original(BOOM/'opt4bankedproduction/SourceProjected.scala')
    update = original(BOOM/'AddressBucketUpdate.scala')
    # The common type contains the two original disjoint sequential cones.
    # They remain on the clock/reset of their original owning module. No
    # state, event, error qualification, or target edge is shared between them.
    a0 = address.index('  val bucketValid =')
    b0 = barrier.index('  val buckets =')
    abody = address[a0:address.rfind('\n}')]
    bbody = barrier[b0:barrier.rfind('\n}')]
    fields = re.findall(r'^    val (\w+) = (?:Input|Output)', barrier, re.M)
    assert fields == ['base','resetStats','event','safeWatermark','currentCycle',
                      'resolvedCount','resolvedRequest','eventAvailable','countOverflow','cycleOverflow']
    rename = {k:'barrier'+k[0].upper()+k[1:] for k in fields}
    bports = barrier[barrier.index('    val base ='):barrier.index('\n  })')]
    for old, new in rename.items():
        bports = re.sub(r'\bval '+old+r'\b', 'val '+new, bports)
        bbody = re.sub(r'\bio\.'+old+r'\b', 'io.'+new, bbody)
    bports = bports.replace('indexBits.W','8.W').replace('sumBits.W','68.W')
    header = address[:a0].replace('package opt4bankedproduction', 'package ecstatscommon', 1)
    header = header.replace('class BucketBank extends Module {',
        'class StatsBank extends Module {\n  private val indexBits = 8\n  val lanes = 16')
    header = header.replace('  val io = IO(new Bundle {',
        '  val io = IO(new Bundle {\n'+bports+'\n', 1)
    abody = abody.replace('sourceprojected.AddressBucketGrouped', 'ecstatscommon.AddressBucketGrouped')
    abody = abody.replace('boom.lsu.AddressBucketUpdate', 'ecstatscommon.AddressBucketUpdate')
    # All ports are a real production consumer boundary. Retain the common
    # interface through target optimization so the 16 address + 48 barrier
    # instances remain the same single selected FAME5 model type.
    common = header + '  dontTouch(io)\n' + abody + '\n' + bbody + '\n}\n'
    common = common.replace('import org.chipsalliance.cde.config.{Config, Parameters}',
        'import freechips.rocketchip.guardiancouncil.{GH_GlobalParams, GHBarrierLatencyBucket}')
    # Check the sequential/compute cones separately, with only namespace and
    # IO-path renaming reversed. This is an exact structural embedding check.
    ra = abody.replace('ecstatscommon.AddressBucketGrouped','sourceprojected.AddressBucketGrouped')
    ra = ra.replace('ecstatscommon.AddressBucketUpdate','boom.lsu.AddressBucketUpdate')
    rb = bbody
    for old, new in rename.items():
        rb = re.sub(r'\bio\.'+new+r'\b', 'io.'+old, rb)
    assert ra == address[a0:address.rfind('\n}')]
    assert rb == barrier[b0:barrier.rfind('\n}')]
    paths = {
        ROCKET/'ecstatscommon/StatsBank.scala': common,
        ROCKET/'ecstatscommon/AddressBucketGrouped.scala': projected.replace(
            'package sourceprojected','package ecstatscommon',1),
        ROCKET/'ecstatscommon/AddressBucketUpdate.scala': update.replace(
            'package boom.lsu','package ecstatscommon',1),
    }
    edits = {}
    def caller(rel, changes):
        old = original(rel); text = old; journal = []
        for a,b in changes:
            assert text.count(a) == 1, (str(rel),a[:90],text.count(a))
            at = text.index(a); journal.append(dict(offset=at, old=a, new=b))
            text = text[:at] + b + text[at+len(a):]
        undo = text
        for e in reversed(journal):
            assert undo[e['offset']:e['offset']+len(e['new'])] == e['new']
            undo = undo[:e['offset']] + e['old'] + undo[e['offset']+len(e['new']):]
        assert undo == old
        paths[rel] = text; edits[str(rel)] = journal
    caller(BOOM/'PackageAddressStats.scala', [
        ('import opt4bankedproduction.BucketBank','import ecstatscommon.StatsBank'),
        ('Seq.fill(16)(Module(new BucketBank))','Seq.fill(16)(Module(new StatsBank))'),
        ('    val bank = bucketBanks(b)\n', '''    val bank = bucketBanks(b)
    // Inactive barrier half has no consumers and cannot affect address state.
    bank.io.barrierBase := (b * 16).U
    bank.io.barrierResetStats := true.B
    bank.io.barrierEvent.valid := false.B
    bank.io.barrierEvent.bits := 0.U
    bank.io.barrierSafeWatermark := 0.U
    bank.io.barrierCurrentCycle := 0.U
''')])
    oldbar = original(ROCKET/'BarrierLatencyStats.scala')
    bar = oldbar.replace('import chisel3.util._','import chisel3.util._\nimport ecstatscommon.StatsBank',1)
    bar = bar.replace('  require(isPow2(bankLanes) && bankLanes <= window)',
        '  require(window == 256 && bankLanes == 16)\n  require(isPow2(bankLanes) && bankLanes <= window)',1)
    bar = bar.replace('new GHBarrierBucketBank(window, bankLanes)', 'new StatsBank',1)
    for old, new in rename.items():
        bar = re.sub(r'\b(bank|_)\.io\.'+old+r'\b', r'\1.io.'+new, bar)
    before = '    val bank = Module(new StatsBank)\n'
    inactive = '''    // Inactive address half is independent of all live barrier inputs.
    bank.io.base := (b * bankLanes).U
    bank.io.loadSources := 0.U.asTypeOf(bank.io.loadSources)
    bank.io.storeSources := 0.U.asTypeOf(bank.io.storeSources)
    bank.io.strictSources := 0.U.asTypeOf(bank.io.strictSources)
    bank.io.newStore := 0.U.asTypeOf(bank.io.newStore)
    bank.io.newFirstStore := 0.U.asTypeOf(bank.io.newFirstStore)
    bank.io.processSeq := 0.U
    bank.io.retiringSeq := 0.U
    bank.io.processCommit := false.B
    bank.io.safeAdvance := false.B
    bank.io.safeError := false.B
    bank.io.resetStats := true.B
    bank.io.querySeq := 0.U.asTypeOf(bank.io.querySeq)
'''
    bar = bar.replace(before,before+inactive,1)
    # Record one complete reversible caller replacement; the arithmetic,
    # global counters, overflow, observation, and update priority stay intact.
    caller(ROCKET/'BarrierLatencyStats.scala', [(oldbar,bar)])
    if write:
        for rel,text in paths.items():
            dest = TREE/rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            if str(rel) in edits:
                assert dest.read_text() == original(rel)
                dest.write_text(text)
            else:
                exact(dest,text)
    assert all((TREE/rel).read_text() == text for rel,text in paths.items())
    return dict(schema='ec-common-stats-bank-source/1', parent_commit=PARENT,
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source_files={str(TREE/r):sha(TREE/r) for r in paths},
        parent_files={str(r):hashlib.sha256(original(r).encode()).hexdigest() for r in
            [BOOM/'opt4bankedproduction/BucketBank.scala',ROCKET/'BarrierBucketBank.scala']},
        reversible_caller_edits=edits, address_sequential_compute_body_byte_equal=True,
        barrier_sequential_compute_body_byte_equal=True,
        source_registers_added_to_live_cones=0, extra_target_cycles=0,
        clocks_and_resets_owned_by_original_parents=True,
        production_slots=256, lanes=16, address_instances=16, barrier_instances=48,
        selected_model_types=1, selected_instances=64,
        inactive_half_storage_and_transport_area_unknown=True,
        production_admission=False, full_system_fit=False,
        scope='Separate full-size common-bank preparation. Exact structural source embedding; no target/host equivalence, area, or complete EC FIT claim.')

if __name__ == '__main__':
    import sys
    result = derive('--write-source' in sys.argv)
    exact(C/'source-binding.precommit.json',json.dumps(result,indent=2,sort_keys=True)+'\n')
    print('COMMON_BANK_SOURCE_PREPARED_NO_AREA_OR_PARITY_CLAIM')
