#!/usr/bin/python3
"""Adopt the idle capacity consumer; keep producers and canonical interfaces.

Submit only the corrected future physical controller. Also expose the first
real complete-host synth report without waiting for post-opt reporting.
"""
import hashlib
import importlib.util
import json
from pathlib import Path
import time

C = Path(__file__).resolve().parent
OLD = C.parent / 'mcrams-full-host-continuation-r2-20261112'
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def main():
    helper = module('mcrams_clock_r3', C / 'physical.py')
    helper.verify()
    m = module('original_mcrams_consumer_r2', OLD / 'continue.py')
    parser = module('strict_complete_host_resource_parser', C.parent / 'mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    original_submit, original_update = m.submit, m.update

    def submit(name, script, outputs, inputs, kind='analysis'):
        if name == 'mcrams-shell-physical-r2-3656aec4':
            name = 'mcrams-shell-physical-r3-clock-3656aec4'
            script = C / 'physical.py'
            inputs = list(inputs) + [script, C / 'inputs.json']
        return original_submit(name, script, outputs, inputs, kind)

    def observe():
        for tag in ['synth', 'postopt']:
            dest = m.O / ('early-' + tag + '-capacity.json')
            u, h = m.AREA / (tag+'-utilization.rpt'), m.AREA / (tag+'-hierarchical.rpt')
            if dest.exists() or not u.is_file() or not h.is_file():
                continue
            before = [(p.stat().st_size, p.stat().st_mtime_ns) for p in [u, h]]
            try:
                ut, ht = u.read_text(), h.read_text()
                totals = parser.parse_total(ut)
                hierarchy = parser.parse_hier(ht, totals)
                cross = parser.crosschecks(ut, totals)
                after = [(p.stat().st_size, p.stat().st_mtime_ns) for p in [u, h]]
                if before != after:
                    continue
                excess = {k:max(0,v['used']-v['available']) for k,v in totals.items()}
                m.save(dest, dict(schema='ec-early-real-complete-host-capacity/1',
                    captured_utc=m.now(), functional_baseline=m.BASE, derived_target_commit=m.HW,
                    stage=tag, scope='complete FPGATop OOC; shell excluded',
                    resources=totals, hierarchy_top=hierarchy['top'], crosschecks=cross,
                    resource_excess=excess, within_device_at_this_stage=not any(excess.values()),
                    postopt_final_result_pending=not (m.AREA/'result.json').exists(),
                    physical_FIT=False, fpga_access=False,
                    evidence={str(p):m.sha(p) for p in [u,h]}))
            except (AssertionError, KeyError, ValueError) as e:
                m.ST['early_report_pending_reason'] = repr(e)

    def update(**values):
        if m.O.is_dir():
            observe()
        return original_update(continuation_revision='r3-generated-clock-contract',
            continuation_source=str(C/'continue.py'),
            continuation_sha256=m.sha(C/'continue.py'),
            existing_capacity_and_parity_producers_preserved=True, **values)

    m.submit, m.update = submit, update
    try:
        m.main()
    except Exception as e:
        if m.ST:
            m.update(status='CONTINUATION_FAILED_WITH_EVIDENCE', error=repr(e))
            m.save(m.O / 'failure.json', m.ST)
        raise


if __name__ == '__main__':
    main()
