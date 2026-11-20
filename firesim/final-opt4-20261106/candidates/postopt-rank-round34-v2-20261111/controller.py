#!/usr/bin/python3
"""Expose useful 9ae ranks across shared Vivado attribution, without adding rows.

Raw inclusive rows remain measurements. Reconciled ranks are explicitly only
accounting allocations. Preserve the v1 exact cut (which stopped at a 5-LUT
overlap near the DUT root), and do not represent allocations as candidate gains.
"""
from pathlib import Path
import datetime
import runpy

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
BASE = W / 'candidates/postopt-rank-round34-v1-20261111/controller.py'
B = runpy.run_path(str(BASE), run_name='preserved_exact_cut')
E = BASE.parent / 'evidence'
L = D / 'build-logs/Opt4-postopt-rank-round34-v2-20261111'
S = D / 'Opt4-postopt-rank-round34-v2-state.json'


def main():
    policy = B['read'](D / 'unattended-opt4/campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['functional_baseline_commit'] == B['FROZEN']
    assert not L.exists() and not S.exists()
    inputs = B['read'](C / 'input-hashes.json')
    assert all(B['sha'](p) == h for p, h in inputs.items())
    rows = B['parse'](E / 'top-postopt-hierarchical.rpt')
    overlaps = []

    def allocate(row, factor):
        used = row['resources']['total_luts']
        subtotal = sum(c['resources']['total_luts'] for c in row['children'])
        row['allocation_factor'] = factor
        row['owned_allocation_luts'] = max(0, used - subtotal) * factor
        row['signed_raw_direct_delta_luts'] = used - subtotal
        local = min(1.0, used / subtotal) if subtotal else 1.0
        if subtotal > used:
            overlaps.append(dict(**B['compact'](row), children_luts=subtotal,
                                 shared_attribution_overlap=subtotal - used, local_factor=local))
        for child in row['children']:
            allocate(child, factor * local)

    allocate(rows[0], 1.0)
    total = sum(r['owned_allocation_luts'] for r in rows)
    assert abs(total - 2847382) < 1e-6
    raw_ledger = sum(r['signed_raw_direct_delta_luts'] for r in rows)
    assert raw_ledger == 2847382
    ranked = sorted(rows, key=lambda r: r['owned_allocation_luts'], reverse=True)
    def entry(row):
        return dict(**B['compact'](row), accounting_allocation_luts=row['owned_allocation_luts'],
                    allocation_factor=row['allocation_factor'],
                    signed_raw_direct_delta_luts=row['signed_raw_direct_delta_luts'])
    original = B['read'](D / 'build-logs/Opt4-postopt-rank-round34-v1-20261111/result.json')
    result = dict(schema='ec-opt4-shared-hierarchy-accounting/1',
        status='PASS_9AE_INCLUSIVE_AND_RECONCILED_HIERARCHY_RANKING_NOT_FIT',
        hardware_commit=B['COMMIT'], source_id=B['SOURCE'],
        functional_baseline_commit=B['FROZEN'], input_sha256=inputs,
        top_postopt_resources=original['top_postopt_resources'],
        capacity_lut_excess=original['capacity_lut_excess'],
        hypothetical_address_deletion_bound=original['hypothetical_address_deletion_bound'],
        raw_inclusive_module_rows_do_not_add=original['raw_inclusive_module_rows_do_not_add'],
        accounting_owned_ranking=[entry(r) for r in ranked if r['owned_allocation_luts'] >= 5000],
        allocation_sum=total, signed_raw_ledger_sum=raw_ledger,
        shared_attribution_overlaps=overlaps,
        methodology=['Inclusive module rows are actual report values and cannot be added to descendants.',
                    'At shared attribution, child allocations are scaled only for accounting; these are not measured module counts.',
                    'Owned allocations form a 2,847,382-LUT partition; signed raw direct deltas independently telescope to the same total.',
                    'The preserved v1 cut is exact but stops at a 5-LUT DUT-wrapper overlap; this version exposes descendants without claiming raw children are disjoint.',
                    'Hoisted DCache arrays and instrumentation retain their original source ownership; instance labels do not prove causality.'],
        whole_fit=False, fpga_access=False,
        ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    L.mkdir()
    B['save'](L / 'result.json', result)
    B['save'](S, dict(status=result['status'], hardware_commit=B['COMMIT'],
                      result=str(L / 'result.json'), result_sha256=B['sha'](L / 'result.json')))


if __name__ == '__main__':
    main()
