#!/usr/bin/python3
"""Reversible full AddressStats integration of the immutable r4 BucketBank."""
import hashlib
import json
from pathlib import Path

C = Path(__file__).resolve().parent
W = C.parent.parent
R = W/'candidates/address-packed-full-module-r1-20261112'
B = W/'candidates/address-banked-state-fame5-r4-20261112'
BUCKETS = ['bucketStore', 'bucketLoadFirst', 'bucketStoreFirst',
           'bucketStrictWriteRead', 'bucketFirstStore']


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def exact(path, text):
    if path.exists():
        assert path.read_text() == text, ('immutable input changed', str(path))
    else:
        path.write_text(text)


def prepare():
    original = (R/'ReferenceModule.scala').read_text()
    assert sha(R/'ReferenceModule.scala') == 'da3380a6ad68db776cab1cb3b1965f47f4884721447785c059934087f2435582'
    reference = original.replace('package opt4packedref', 'package opt4bankedref', 1)
    candidate = original
    edits = []

    def change(old, new, label):
        nonlocal candidate
        assert candidate.count(old) == 1, (label, candidate.count(old))
        candidate = candidate.replace(old, new, 1)
        edits.append(dict(label=label, old=old, new=new))

    def span(start, end, new, label):
        left = candidate.index(start)
        right = candidate.index(end, left)
        change(candidate[left:right], new, label)

    change('package opt4packedref', '''package opt4bankedcandidate
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation''', 'namespace and host annotation imports')
    span('  val bucketValid = RegInit(', "  // A valid bucket's low sequence bits", '''  // Exact original state is owned by 16 identical 16-lane banks.
  // Parent views are combinational wires, without new target registers.
  require(packetWindow == 256 && packageWays == 8 && lineBytes == 64)
  val bucketBanks = Seq.fill(16)(Module(new BucketBank))
  bucketBanks.foreach(bank => annotate(EnableModelMultiThreadingAnnotation(bank)))
  val bucketValid = Wire(Vec(packetWindow, Bool()))
  val bucketSeq = Wire(Vec(packetWindow, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
  val bucketStore = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketLoadFirst = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStoreFirst = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketStrictWriteRead = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketFirstStore = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val bucketOverflows = Wire(Vec(packetWindow, Bool()))
  for (b <- 0 until 16; i <- 0 until 16) {
    val index = b * 16 + i
    val state = bucketBanks(b).io.observe(i)
    bucketOverflows(index) := state(1313)
    bucketValid(index) := state(1312)
    bucketSeq(index) := state(1311, 1280)
    val metrics = Seq(bucketStore, bucketFirstStore, bucketLoadFirst,
      bucketStoreFirst, bucketStrictWriteRead)
    for (m <- 0 until 5; g <- 0 until 4) {
      val lo = 64 * (4 * m + g)
      metrics(m)(index)(g) := state(lo + 63, lo)
    }
  }

''', 'move original bucket registers into identical banks')
    span('  // Compact four source keys locally,', '  val packageBucketKeys =', '',
         'move exact histogram arithmetic into bank')
    span('  val bucketLoadFirstDelta =', '  val evictedLoadFirst =', '',
         'replace parent histogram outputs with bank-local reductions')
    span('  // Multi-bucket hits still update in parallel.',
         '  val processArithmeticErrorParts =', '', 'move exact wide add and carry into bank')
    change('''      addOverflows(onlineStrictWriteRead(g), strictOnlineDelta),
      currentStoreNextWide(g)(64))
    processArithmeticErrorParts += currentFirstStoreNextWide(g)(64)
    for (i <- 0 until packetWindow) {
      processArithmeticErrorParts ++= Seq(
        loadFirstNextWide(i)(g)(64),
        storeFirstNextWide(i)(g)(64),
        strictWriteReadNextWide(i)(g)(64))
    }
''', '''      addOverflows(onlineStrictWriteRead(g), strictOnlineDelta))
''', 'use bank carries without changing global fail-closed checks')
    change('''  val processArithmeticError = processValid &&
    processArithmeticErrorParts.reduce(_ || _)''', '''  val processArithmeticError = processValid &&
    (processArithmeticErrorParts.reduce(_ || _) || bucketOverflows.asUInt.orR)''',
        'aggregate all exact carries including invalid bucket payload')
    span('''    for (i <- 0 until packetWindow) {
      val isCurrent = currentBucketIdx''', '''    for (g <- 0 until 4) {
      val storeDelta''', '', 'move process writes into bank')
    change('      bucketValid(retiringIdx) := false.B\n', '', 'move retirement validity write')
    change(''.join('        '+name+'(retiringIdx)(g) := 0.U\n' for name in
                   ['bucketStore', 'bucketFirstStore', 'bucketLoadFirst',
                    'bucketStoreFirst', 'bucketStrictWriteRead']), '',
           'move retirement payload writes while preserving online decrements')
    span('''    for (i <- 0 until packetWindow) {
      bucketValid(i) := false.B''', '''    for (g <- 0 until 4) {
      metricStoreTotal''', '', 'move stats-reset bucket writes')
    connections = '''
  // All qualification, error, queue and online/global metric logic above is
  // retained. Banks receive original same-cycle controls and source counts.
  for (b <- 0 until 16) {
    val bank = bucketBanks(b)
    bank.io.base := (b * 16).U
    bank.io.processSeq := processEvent.packetSeq
    bank.io.retiringSeq := retiringSeq
    bank.io.processCommit := processCommit
    bank.io.safeAdvance := safeAdvance
    bank.io.safeError := safeError
    bank.io.resetStats := io.resetStats
    for (g <- 0 until 4) {
      bank.io.newStore.values(g) := newStoreCounts(g)
      bank.io.newFirstStore.values(g) := newFirstStoreCounts(g)
    }
    for (w <- 0 until 8) {
      bank.io.loadSources(w).key := packageBucketKeys(w)
      bank.io.storeSources(w).key := packageBucketKeys(w)
      for (g <- 0 until 4) {
        bank.io.loadSources(w).counts.values(g) := unsafeLoadFirstHitCounts(w)(g)
        bank.io.storeSources(w).counts.values(g) := unsafeStoreFirstHitCounts(w)(g)
      }
    }
    val strictCounts = unsafeStrictWriteReadHitCounts ++ unsafeStrictOverflowWriteReadHitCounts
    for (w <- 0 until 80) {
      bank.io.strictSources(w).key := strictBucketKeys(w)
      for (g <- 0 until 4) {
        bank.io.strictSources(w).counts.values(g) := strictCounts(w)(g)
      }
    }
  }
'''
    pos = candidate.rfind('  io.idle :=')
    tail = candidate[pos:]
    end = tail.rfind('\n}')
    change(tail, tail[:end]+'\n'+connections+tail[end:],
           'connect complete bank qualification without target state')
    # Replay records exact offsets at each step; undoing uses those offsets,
    # including deletions, instead of guessing where deleted text belonged.
    replay = original
    offsets = []
    for edit in edits:
        offset = replay.index(edit['old'])
        offsets.append(offset)
        replay = replay[:offset]+edit['new']+replay[offset+len(edit['old']):]
    assert replay == candidate
    for edit, offset in reversed(list(zip(edits, offsets))):
        assert replay[offset:offset+len(edit['new'])] == edit['new']
        replay = replay[:offset]+edit['old']+replay[offset+len(edit['new']):]
    assert replay == original
    bank_original = (B/'BankedState.scala').read_text()
    bank = bank_original.split('\nclass BankedState(', 1)[0]
    bank = bank.replace('package bankedstate', 'package opt4bankedcandidate', 1)
    assert bank.replace('package opt4bankedcandidate', 'package bankedstate', 1) == bank_original.split('\nclass BankedState(', 1)[0]
    exact(C/'BucketBank.scala', bank)
    exact(C/'SourceProjected.scala', (B/'SourceProjected.scala').read_text())
    exact(C/'AddressBucketUpdate.scala', (B/'AddressBucketUpdate.scala').read_text())
    exact(C/'ReferenceHelper.scala', (R/'ReferenceHelper.scala').read_text().replace('package opt4packedref', 'package opt4bankedref', 1))
    debug = '''
    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))
    val debugBucketValid = Output(Vec(packetWindow, Bool()))
    val debugBucketSeq = Output(Vec(packetWindow, UInt(32.W)))'''
    observe = '\n'.join(f'  io.debugBuckets({k}) := {name}' for k, name in enumerate(BUCKETS))
    observe += '\n  io.debugBucketValid := bucketValid\n  io.debugBucketSeq := bucketSeq\n'
    for label, module in [('Reference', reference), ('Candidate', candidate)]:
        exact(C/(label+'Module.scala'), module)
        proof = module.replace('    val idle = Output(Bool())', '    val idle = Output(Bool())'+debug, 1)
        pos = proof.rfind('\n}')
        proof = proof[:pos]+'\n'+observe+proof[pos:]
        assert proof.replace(debug, '').replace('\n'+observe, '') == module
        exact(C/(label+'Proof.scala'), proof)
    receipt = dict(schema='ec-banked-complete-module-source-binding/1',
        source=str(R/'ReferenceModule.scala'), source_sha256=sha(R/'ReferenceModule.scala'),
        bank_source=str(B/'BankedState.scala'), bank_source_sha256=sha(B/'BankedState.scala'),
        exact_bank_class_copy_except_namespace=True, source_inverse_byte_equal=True,
        geometry=dict(slots=256, banks=16, parallel_lanes=16, selected_type='BucketBank'),
        global_queues_tables_error_and_online_metrics_retained=True,
        public_abi_source_unchanged=True, extra_target_registers=0,
        extra_target_pipeline_cycles=0, production_admission=False,
        complete_module_parity=False, whole_host_saving_unknown=True,
        edits=[dict(label=e['label'], offset=o, old=e['old'], new=e['new'])
               for e, o in zip(edits, offsets)],
        generated={str(C/n): sha(C/n) for n in ['CandidateModule.scala', 'ReferenceModule.scala',
            'CandidateProof.scala', 'ReferenceProof.scala', 'BucketBank.scala',
            'ReferenceHelper.scala', 'SourceProjected.scala', 'AddressBucketUpdate.scala']})
    exact(C/'source-binding.json', json.dumps(receipt, indent=2, sort_keys=True)+'\n')
    return receipt


if __name__ == '__main__':
    p = prepare()
    print(json.dumps({k:p[k] for k in ['source_inverse_byte_equal','geometry','production_admission']}))
