#!/usr/bin/python3
"""Narrow the bank boundary; retain all state in a separate proof build.

The existing complete-module candidate remains immutable. This successor
changes combinational views/queries only, without changing a state update.
"""
from pathlib import Path
import hashlib
import json

C = Path(__file__).resolve().parent
W = C.parent.parent
P = W/'candidates/address-banked-complete-module-r1-20261112'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def exact(p, text):
    if p.exists():
        assert p.read_text() == text, ('immutable input differs', str(p))
    else:
        p.write_text(text)


def prepare():
    parent = (P/'CandidateModule.scala').read_text()
    text = parent
    edits = []

    def change(old, new, label):
        nonlocal text
        assert text.count(old) == 1, (label, text.count(old))
        offset = text.index(old)
        edits.append(dict(label=label, offset=offset, old=old, new=new))
        text = text[:offset]+new+text[offset+len(old):]

    def span(start, end, new, label):
        a = text.index(start)
        b = text.index(end, a)
        change(text[a:b], new, label)

    change('package opt4bankedcandidate', 'package opt4bankedproduction', 'private namespace')
    span('  val bucketValid = Wire(', '  val processLineTag =', '''  // Each query result is reduced inside the shared bank. Carry is a
  // separate channel from state-only retirement/query results.
  def queryMatch(q: Int): Bool = bucketBanks.map(_.io.queryMatch(q)).reduce(_ || _)
  val retiringValid = bucketBanks.map(_.io.retiringValid).reduce(_ || _)
  val retiringCollision = bucketBanks.map(_.io.retiringCollision).reduce(_ || _)
  val retiringWords = Wire(Vec(5, Vec(4, UInt(64.W))))
  for (m <- 0 until 5; g <- 0 until 4) {
    retiringWords(m)(g) := bucketBanks.map(_.io.retiringWords(m)(g)).reduce(_ | _)
  }

''', 'replace full state transport with production consumers')
    change('''  val currentBucketCollision = bucketValid(currentBucketIdx) &&
    !bucketSequenceMatches(currentBucketIdx, processEvent.packetSeq)''',
           '''  val currentBucketCollision = bucketBanks.map(_.io.currentCollision).reduce(_ || _)''',
           'current sequence collision reduction')
    checks = [
        ('mask.orR && (!bucketValid(idx) || !bucketSequenceMatches(idx, seq))', 'mask.orR && !queryMatch(w)'),
        ('mask.orR && (!bucketValid(idx) || !bucketSequenceMatches(idx, seq))', 'mask.orR && !queryMatch(8 + w)'),
        ('mask.orR && (!bucketValid(idx) || !bucketSequenceMatches(idx, seq))', 'mask.orR && !queryMatch(24 + i)')]
    # These three occurrences have distinct lexical owners. Replace one
    # at a time while recording exact offsets for a reversible edit ledger.
    for old, new in checks:
        offset = text.index(old)
        edits.append(dict(label='qualified bucket query', offset=offset, old=old, new=new))
        text = text[:offset]+new+text[offset+len(old):]
    change('bucketOverflows.asUInt.orR', 'bucketBanks.map(_.io.overflow).reduce(_ || _)', 'all bucket carries')
    change('''  val retiringSlotCollision = safeAdvance && bucketValid(retiringIdx) &&
    !bucketSequenceMatches(retiringIdx, retiringSeq)''',
           '  val retiringSlotCollision = safeAdvance && retiringCollision', 'retirement collision')
    text_before = text
    # All remaining dynamic bucket reads select the retiring slot. No value
    # is gated by valid here; invalid payload remains present in proof builds.
    for metric, name in enumerate(['bucketStore','bucketFirstStore','bucketLoadFirst',
                                   'bucketStoreFirst','bucketStrictWriteRead']):
        old = name+'(retiringIdx)(g)'
        while old in text:
            at = text.index(old)
            new = f'retiringWords({metric})(g)'
            edits.append(dict(label='retiring payload query',offset=at,old=old,new=new))
            text = text[:at]+new+text[at+len(old):]
    while 'bucketValid(retiringIdx)' in text:
        old, new = 'bucketValid(retiringIdx)', 'retiringValid'
        at = text.index(old)
        edits.append(dict(label='retiring validity query',offset=at,old=old,new=new))
        text = text[:at]+new+text[at+len(old):]
    change('''    bank.io.processSeq := processEvent.packetSeq
''', '''    bank.io.processSeq := processEvent.packetSeq
    for (q <- 0 until 8) bank.io.querySeq(q) := packageReadData(q).packetSeq
    for (q <- 0 until 16) bank.io.querySeq(8 + q) := strictReadData(q).packetSeq
    for (q <- 0 until 64) bank.io.querySeq(24 + q) := strictOverflowData(q).packetSeq
''', 'full sequence query inputs')
    for e in reversed(edits):
        assert text[e['offset']:e['offset']+len(e['new'])] == e['new']
        text = text[:e['offset']]+e['old']+text[e['offset']+len(e['new']):]
    assert text == parent
    # Replay and preserve the production module.
    text = parent
    for e in edits:
        assert text[e['offset']:e['offset']+len(e['old'])] == e['old']
        text = text[:e['offset']]+e['new']+text[e['offset']+len(e['old']):]
    exact(C/'CandidateModule.scala', text)
    debug = '''
    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))
    val debugBucketValid = Output(Vec(packetWindow, Bool()))
    val debugBucketSeq = Output(Vec(packetWindow, UInt(32.W)))'''
    proof = text.replace('    val idle = Output(Bool())', '    val idle = Output(Bool())'+debug, 1)
    order = [0,2,3,4,1]  # Existing proof ABI: store/load/storefirst/strict/firststore.
    obs = '\n'.join(f'  for (i <- 0 until 256; g <- 0 until 4) io.debugBuckets({k})(i)(g) := bucketBanks(i / 16).io.observe(i % 16)(64 * ({m} * 4 + g) + 63, 64 * ({m} * 4 + g))' for k,m in enumerate(order))
    obs += '\n  for (i <- 0 until 256) {\n    io.debugBucketValid(i) := bucketBanks(i / 16).io.observe(i % 16)(1312)\n    io.debugBucketSeq(i) := bucketBanks(i / 16).io.observe(i % 16)(1311, 1280)\n  }\n'
    at = proof.rfind('\n}')
    proof = proof[:at]+'\n'+obs+proof[at:]
    assert proof.replace(debug, '').replace('\n'+obs, '') == text
    exact(C/'CandidateProof.scala', proof)

    original_bank = (P/'BucketBank.scala').read_text()
    bank = original_bank.replace('package opt4bankedcandidate', 'package opt4bankedproduction', 1)
    begin = bank.index('    // Exact finite verification observations.')
    end = bank.index('\n  })', begin)
    bank = bank[:begin]+'''    val querySeq = Input(Vec(88, UInt(32.W)))
    val queryMatch = Output(Vec(88, Bool()))
    val currentCollision = Output(Bool())
    val retiringValid = Output(Bool())
    val retiringCollision = Output(Bool())
    val retiringWords = Output(Vec(5, Vec(4, UInt(64.W))))
    val overflow = Output(Bool())
__PROOF_IO__'''+bank[end:]
    bank = bank.replace('  for (i <- 0 until 16) {\n', '  val laneOverflows = Wire(Vec(16, Bool()))\n  for (i <- 0 until 16) {\n', 1)
    begin = bank.index('    // Low field first:')
    bank = bank[:begin]+'''    laneOverflows(i) := overflows.reduce(_ || _)
__PROOF_ASSIGN__
  }
  val keys = (0 until 16).map(i => (io.base + i.U)(7, 0))
  for (q <- 0 until 88) {
    io.queryMatch(q) := (0 until 16).map(i =>
      io.querySeq(q)(7, 0) === keys(i) && bucketValid(i) &&
      bucketSeq(i)(31, 8) === io.querySeq(q)(31, 8)).reduce(_ || _)
  }
  io.currentCollision := (0 until 16).map(i =>
    io.processSeq(7, 0) === keys(i) && bucketValid(i) &&
    bucketSeq(i)(31, 8) =/= io.processSeq(31, 8)).reduce(_ || _)
  val retireSelect = keys.map(_ === io.retiringSeq(7, 0))
  io.retiringValid := (0 until 16).map(i => retireSelect(i) && bucketValid(i)).reduce(_ || _)
  io.retiringCollision := (0 until 16).map(i => retireSelect(i) && bucketValid(i) &&
    bucketSeq(i)(31, 8) =/= io.retiringSeq(31, 8)).reduce(_ || _)
  val metrics = Seq(bucketStore, bucketFirstStore, bucketLoadFirst,
    bucketStoreFirst, bucketStrictWriteRead)
  for (m <- 0 until 5; g <- 0 until 4) {
    io.retiringWords(m)(g) := Mux1H(retireSelect, (0 until 16).map(i => metrics(m)(i)(g)))
  }
  io.overflow := laneOverflows.asUInt.orR
}
'''
    # State declarations and every write expression must remain exact.
    old_state = original_bank[original_bank.index('  val bucketValid ='):original_bank.index('    // Low field first:')]
    new_state = bank[bank.index('  val bucketValid ='):bank.index('    laneOverflows(i) :=')]
    assert new_state.replace('  val laneOverflows = Wire(Vec(16, Bool()))\n','') == old_state
    observation = '''    val values = bucketStore(i).toSeq ++ bucketFirstStore(i).toSeq ++
      bucketLoadFirst(i).toSeq ++ bucketStoreFirst(i).toSeq ++ bucketStrictWriteRead(i).toSeq
    io.observe(i) := Cat(laneOverflows(i), bucketValid(i), bucketSeq(i), Cat(values.reverse))'''
    exact(C/'BucketBankModule.scala', bank.replace('__PROOF_IO__','').replace('__PROOF_ASSIGN__',''))
    exact(C/'BucketBankProof.scala', bank.replace('__PROOF_IO__','    val observe = Output(Vec(16, UInt(1314.W)))').replace('__PROOF_ASSIGN__',observation))
    for n in ['SourceProjected.scala','AddressBucketUpdate.scala']:
        exact(C/n,(P/n).read_text())
    exact(C/'ReferenceModule.scala',(P/'ReferenceModule.scala').read_text())
    exact(C/'ReferenceProof.scala',(P/'ReferenceProof.scala').read_text())
    exact(C/'ReferenceHelper.scala',(P/'ReferenceHelper.scala').read_text())
    outputs = ['CandidateModule.scala','CandidateProof.scala','BucketBankModule.scala','BucketBankProof.scala',
               'SourceProjected.scala','AddressBucketUpdate.scala','ReferenceModule.scala','ReferenceProof.scala','ReferenceHelper.scala']
    receipt = dict(parent=str(P/'source-binding.json'), parent_sha256=sha(P/'source-binding.json'),
        source_inverse_byte_equal=True,bank_state_declarations_and_update_expressions_byte_equal=True,
        geometry=dict(slots=256,banks=16,lanes=16),extra_target_registers=0,extra_target_cycles=0,
        production_bank_output_bits=1372,proof_bank_output_bits_added=21024,
        all_state_observed_in_proof=True,scope='Production query/carry/retirement boundary; not yet equivalent or area measured.',
        generated={str(C/n):sha(C/n) for n in outputs},edits=edits)
    exact(C/'source-binding.json',json.dumps(receipt,indent=2,sort_keys=True)+'\n')
    return receipt


if __name__ == '__main__':
    r = prepare()
    print(json.dumps({k:r[k] for k in ['source_inverse_byte_equal','bank_state_declarations_and_update_expressions_byte_equal','geometry']}))
