"""Add observation ports to the exact production caller without changing its cone."""
from pathlib import Path
import hashlib
import json

C = Path(__file__).resolve().parent
W = C.parent.parent
T = W / 'Opt4-area-common-caller-geometry-closure-r1-20261113'
REL = 'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'


def derive():
    original = (T / REL).read_text()
    s = original
    edits = []

    def change(old, new):
        nonlocal s
        assert s.count(old) == 1, (old[:100], s.count(old))
        at = s.index(old)
        s = s[:at] + new + s[at + len(old):]
        edits.append(dict(offset=at, old=old, new=new))

    change('package boom.lsu', 'package geometrycompletecandidate')
    change('import ecstatscommon.StatsBank',
           'import ecstatscommon.{GeometryBankProof => StatsBank}')
    debug = '''
    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))
    val debugBucketValid = Output(Vec(packetWindow, Bool()))
    val debugBucketSeq = Output(Vec(packetWindow, UInt(32.W)))'''
    change('    val idle = Output(Bool())', '    val idle = Output(Bool())' + debug)
    # The bank proof exports Cat(valid,seq,store,first,load,storeFirst,strict).
    # Vec.asUInt places granule zero in the least significant position.
    observe = '''
  for (i <- 0 until packetWindow) {
    val state = bucketBanks(i / bankLanes).io.observeAddress(i % bankLanes)
    io.debugBucketValid(i) := state(1312)
    io.debugBucketSeq(i) := state(1311,1280)
    for ((block,m) <- Seq(4,2,1,0,3).zipWithIndex; g <- 0 until 4) {
      val lo = block * 256 + g * 64
      io.debugBuckets(m)(i)(g) := state(lo + 63,lo)
    }
  }
'''
    at = s.rfind('\n}')
    assert at >= 0 and s[at:].strip() == '}'
    s = s[:at] + observe + s[at:]
    edits.append(dict(offset=at, old='', new=observe))
    reverse = s
    for e in reversed(edits):
        at = e['offset']
        assert reverse[at:at + len(e['new'])] == e['new']
        reverse = reverse[:at] + e['old'] + reverse[at + len(e['new']):]
    assert reverse == original
    return s, dict(production_source=REL,
                   production_sha256=hashlib.sha256(original.encode()).hexdigest(),
                   proof_source_sha256=hashlib.sha256(s.encode()).hexdigest(),
                   observation_and_namespace_edits=edits,
                   observation_inverse_byte_equal=True,
                   production_slots=256, compared_outputs=5684,
                   public_outputs=52, bucket_payload_words=5120,
                   extra_target_registers=0, extra_target_cycles=0,
                   bank_observation_source='GeometryBankProof.scala from geometry-r2',
                   state_word_mapping=[4,2,1,0,3])


if __name__ == '__main__':
    s, receipt = derive()
    (C / 'CandidateProof.scala').write_text(s)
    (C / 'proof-derivation.json').write_text(json.dumps(receipt, indent=2) + '\n')
