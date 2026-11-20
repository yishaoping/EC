#!/usr/bin/python3
"""Prepare a source-bound combinational alternative; no active input changes."""
import hashlib
import json
from pathlib import Path

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
SOURCE = W/'candidates/mcrams-full-address-storage-r2-20261112/AddressBucketGrouped.scala'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def put(name, text):
    p = C/name
    if p.exists():
        assert p.read_text() == text
    else:
        p.write_text(text)


def main():
    source = SOURCE.read_text()
    old = '''    VecInit((0 until slots).map { i =>
      VecInit(bounds.indices.map { g =>
        sum(groups.map(group => (scatter(group, i.U(log2Ceil(slots).W), g, bounds(g)),
          4 * bounds(g)))).pad(64)
      })
    })'''
    new = '''    // Each scatter lane is unchanged. Size the packed lanes for every
    // possible input bit pattern, so addition never carries into another
    // granularity. All registers, outputs and target edges remain unchanged.
    val inputWidths = bounds.map(b => log2Ceil(4 * b + 1))
    val laneWidths = inputWidths.map(w =>
      (BigInt(groups.size) * ((BigInt(1) << w) - 1)).bitLength)
    val offsets = laneWidths.scanLeft(0)(_ + _)
    def packedSum(xs: Seq[UInt]): UInt = {
      if (xs.size == 1) xs.head
      else packedSum(xs.grouped(2).map {
        case Seq(a, b) => a + b
        case Seq(a) => a
      }.toSeq)
    }
    VecInit((0 until slots).map { i =>
      val terms = groups.map { group =>
        Cat(bounds.indices.reverse.map { g =>
          scatter(group, i.U(log2Ceil(slots).W), g, bounds(g)).pad(laneWidths(g))
        })
      }
      val total = packedSum(terms)
      VecInit(bounds.indices.map { g =>
        total(offsets(g + 1) - 1, offsets(g)).pad(64)
      })
    })'''
    assert source.count(old) == 1
    put('AddressBucketGrouped.scala', source.replace(old, new))
    # An actual-size arbitrary-bit combinational miter for the new reduction.
    n, widths = 20, [9, 7, 6, 3]
    lanes = [(n*((1 << w)-1)).bit_length() for w in widths]
    stride, total = sum(widths), sum(lanes)
    offsets = [sum(lanes[:g]) for g in range(4)]
    code = [f'module PackedGroupProof(input [{n*stride-1}:0] values, output equivalent, output mutant_equivalent);']
    refs = []
    for g, iw in enumerate(widths):
        terms = [f"{{{lanes[g]-iw}'b0,values[{i*stride+sum(widths[:g])}+:{iw}]}}" for i in range(n)]
        code.append(f'wire [{lanes[g]-1}:0] ref{g} = ' + ' + '.join(terms) + ';')
        refs.append(f'ref{g}')
    for i in range(n):
        terms = [f"{{{lanes[g]-widths[g]}'b0,values[{i*stride+sum(widths[:g])}+:{widths[g]}]}}" for g in reversed(range(4))]
        code.append(f'wire [{total-1}:0] term{i} = '+'{'+','.join(terms)+'};')
    names = [f'term{i}' for i in range(n)]
    level = 0
    while len(names) > 1:
        next_names = []
        for k in range(0, len(names), 2):
            if k+1 == len(names):
                next_names.append(names[k])
            else:
                name = f'packed_{level}_{k//2}'
                code.append(f'wire [{total-1}:0] {name} = {names[k]} + {names[k+1]};')
                next_names.append(name)
        names = next_names
        level += 1
    code.append(f'wire [{total-1}:0] reference = '+'{'+','.join(reversed(refs))+'};')
    code += [f'assign equivalent = reference == {names[0]};', f"assign mutant_equivalent = reference == ({names[0]} ^ {total}'b1);", 'endmodule']
    put('reduction-proof.v', '\n'.join(code)+'\n')
    plan = dict(schema='ec-source-bound-packed-group-reduction-preparation/2',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source=str(SOURCE), source_sha256=sha(SOURCE), candidate_sha256=sha(C/'AddressBucketGrouped.scala'),
        change='Only final20group four-granule combinational reduction; retain group4 sorting/scatter, all64bitcounterstate, full observations and update priority',
        proof_scope='Arbitrary500inputbits;20termsx(9,7,6,3), packed45bit sum vs four independent sums; mutation must fail',
        lane_input_widths=widths, lane_widths=lanes, lane_offsets=offsets, packed_width=total,
        measured_predecessor='Prior local packed37bit probe saved156LUT perbucket; this is a different exact45bit actualsize probe, no transferred saving claim',
        blocked_integration_gates=['Actual helper Scala compilation', 'Full actual-size histogram vectors including everygranule', 'Complete frozen PackageAddressStats parity including invalid state/debugwords', 'Paired complete generated-host module area and unchanged latency', 'New wholehost postoptcapacity before physicaladmission'],
        selected_for_production=False, hardware_integrated=False, full_host_synthesis=False, fpga_access=False,
        negative_area_candidate_rejected=str(W/'candidates/mcrams-full-address-storage-r2-20261112/area-admission-rejected.json'))
    put('plan.json', json.dumps(plan, indent=2, sort_keys=True)+'\n')
    print('Prepared packed45bit finalgroup reduction; no active sources or CAD changed.')


if __name__ == '__main__':
    main()
