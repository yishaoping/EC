#!/usr/bin/python3
"""Rank completed 9ae post-opt evidence with an exact LUT hierarchy cut.

At a Vivado shared-attribution overlap, keep the parent intact. Never sum a
parent and descendants, and never turn accounting allocations into measurements.
"""
from pathlib import Path
import datetime
import hashlib
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-postopt-rank-round34-v1-20261111'
S = D / 'Opt4-postopt-rank-round34-v1-state.json'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = '9ae9a7fcf231a75259e23973b12a93896a443cbb'
SOURCE = '3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def read(p):
    return json.loads(Path(p).read_text())


def save(p, value):
    p = Path(p)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def parse(p):
    rows, stack = [], []
    names = ['total_luts', 'logic_luts', 'lutrams', 'srls', 'ffs',
             'ramb36', 'ramb18', 'uram', 'dsp']
    for number, line in enumerate(Path(p).read_text().splitlines(), 1):
        a = line.split('|')
        if len(a) < 12:
            continue
        try:
            values = [int(s.strip().replace(',', '')) for s in a[3:12]]
        except ValueError:
            continue
        raw = a[1]
        indent = len(raw) - len(raw.lstrip())
        while stack and stack[-1]['indent'] >= indent:
            stack.pop()
        row = dict(instance=raw.strip(), indent=indent, module=a[2].strip(),
                   line=number, resources=dict(zip(names, values)), children=[])
        row['parts'] = (stack[-1]['parts'] if stack else []) + [row['instance']]
        if stack:
            stack[-1]['children'].append(row)
        rows.append(row)
        stack.append(row)
    assert rows and sum(r['indent'] == rows[0]['indent'] for r in rows) == 1
    return rows


def compact(row):
    return {k: row[k] for k in ['parts', 'module', 'line', 'resources']}


def main():
    policy = read(D / 'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == FROZEN
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['native_paused'] and not policy['fpga_access']
    assert not L.exists() and not S.exists(), 'Immutable outputs; use a new version.'
    inputs = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items())
    state = read(C / 'evidence/cad-state.json')
    assert state['hardware_commit'] == COMMIT and state['source_id'] == SOURCE
    assert state['status'] == 'NOT_FIT_POSTOPT' and not state['certified_bitstream']
    assert (C / 'evidence/capacity.complete').read_text().strip().startswith('NOT_FIT_POSTOPT')
    rows = parse(C / 'evidence/top-postopt-hierarchical.rpt')
    root = rows[0]
    used = state['top_postopt_resources']['CLB LUTs']['used']
    available = state['top_postopt_resources']['CLB LUTs']['available']
    assert root['resources']['total_luts'] == used == 2847382
    cut, overlaps = [], []

    def visit(row):
        lut = row['resources']['total_luts']
        children = row['children']
        subtotal = sum(c['resources']['total_luts'] for c in children)
        if not children or subtotal > lut:
            if subtotal > lut:
                overlaps.append(dict(**compact(row), children_luts=subtotal,
                                     overlap=subtotal - lut,
                                     handling='Keep this parent; exclude all descendants from the cut.'))
            if lut:
                cut.append(dict(**compact(row), cut_luts=lut, accounting='inclusive intact subtree'))
            return
        for child in children:
            visit(child)
        if lut > subtotal:
            cut.append(dict(**compact(row), cut_luts=lut - subtotal,
                            accounting='parent minus all direct child totals'))

    visit(root)
    assert sum(r['cut_luts'] for r in cut) == used
    # A cut may contain a parent's direct residue and a child's subtree; these
    # are disjoint resource sets. Intact subtree rows never overlap each other.
    intact = [r for r in cut if r['accounting'] == 'inclusive intact subtree']
    for i, a in enumerate(intact):
        for b in intact[i + 1:]:
            n = min(len(a['parts']), len(b['parts']))
            assert a['parts'][:n] != b['parts'][:n]
    address = [r for r in rows if r['module'].endswith('_PackageAddressStats')]
    assert len(address) == 1
    address_luts = address[0]['resources']['total_luts']
    wanted = ['PackageAddressStats', 'BoomNonBlockingDCache', 'BoomMSHRFile',
              'BoomMSHR', 'SpeculativeVersionBuffer', 'InclusiveCache',
              'Scheduler', 'GHBarrierLatencyStats', 'BoomProbeUnit', 'BoomWritebackUnit']
    selected = [compact(r) for r in rows if any(
        r['module'].endswith('_' + name) or ('_' + name + '_') in r['module']
        for name in wanted) and not r['instance'].startswith('(')]
    receipt = dict(
        schema='ec-opt4-exact-postopt-hierarchy-cut/1',
        status='PASS_COMPLETED_9AE_EXACT_NONOVERLAPPING_LUT_PARTITION_NOT_FIT',
        hardware_commit=COMMIT, source_id=SOURCE, functional_baseline_commit=FROZEN,
        input_sha256=inputs, policy_sha256=sha(D / 'unattended-opt4/campaign-policy.json'),
        top_postopt_resources=state['top_postopt_resources'],
        capacity_lut_excess=used - available,
        top=compact(root), cut_lut_sum=sum(r['cut_luts'] for r in cut),
        exact_cut_ranked=sorted(cut, key=lambda r: r['cut_luts'], reverse=True),
        raw_inclusive_module_rows_do_not_add=selected,
        unexpanded_shared_attribution_overlaps=overlaps,
        hypothetical_address_deletion_bound=dict(
            measured_address_inclusive_luts=address_luts,
            whole_luts_minus_address=used - address_luts,
            residual_excess_even_if_address_were_free=used - address_luts - available,
            scope='Arithmetic lower-bound illustration only; deleting instrumentation is forbidden.'),
        limits=['This is the completed 9ae map, not e0 or a candidate gain.',
                'Only exact_cut_ranked.cut_luts may be added. Raw inclusive rows overlap.',
                'Resource hierarchy attribution is not source-level cone ownership.',
                'No local module saving is asserted as a whole-system gain.'],
        fpga_access=False, certified_bitstream=False,
        ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    L.mkdir()
    save(L / 'result.json', receipt)
    save(S, dict(status=receipt['status'], hardware_commit=COMMIT, source_id=SOURCE,
                 result=str(L / 'result.json'), result_sha256=sha(L / 'result.json'),
                 ended_utc=receipt['ended_utc']))


if __name__ == '__main__':
    main()
