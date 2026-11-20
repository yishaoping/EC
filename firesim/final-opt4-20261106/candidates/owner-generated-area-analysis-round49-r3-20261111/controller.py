#!/usr/bin/python3
"""Recover sealed module area reports without CAD, RTL edits, or FPGA access."""
import argparse
import copy
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess

C = Path(__file__).resolve().parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
OLD = D / 'build-logs/Opt4-mcrams-owner-generated-area-r1-20261111'
O = D / 'build-logs/Opt4-owner-generated-area-analysis-round49-r3-20261111'
UNIT = 'ec-opt4-auto-owner-generated-area-r1-3656aec4.service'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def save(p, value):
    p = Path(p)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert not p['fpga_access']
    return sha(U / 'campaign-policy.json')


def producer_guard():
    f = read(OLD / 'failure.json')
    assert f['status'] == 'FAILED_WITH_EVIDENCE'
    assert f['error'] == "AssertionError('CARRY8 primitive mismatch')"
    assert f['functional_baseline'] == BASE
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    identities = []
    for item in [f, f['child']]:
        path = Path('/proc') / str(item['pid']) / 'stat'
        actual = None
        if path.exists():
            actual = path.read_text().rsplit(')', 1)[1].split()[19]
        live = actual == item['start_ticks'] and boot == item['boot_id']
        assert not live, ('producer identity still live', item)
        identities.append(dict(expected=item, actual_start_ticks=actual, identity_live=live))
    cmd = ['systemctl', 'show', UNIT, '-p', 'ActiveState', '-p', 'SubState',
           '-p', 'MainPID', '-p', 'ControlGroup', '-p', 'TasksCurrent', '-p', 'Result']
    r = subprocess.run(cmd, check=True, text=True, capture_output=True)
    props = dict(l.split('=', 1) for l in r.stdout.splitlines() if '=' in l)
    assert props['MainPID'] == '0' and props['ActiveState'] in ('inactive', 'failed')
    paths = {Path('/sys/fs/cgroup/system.slice') / UNIT}
    if props['ControlGroup']:
        paths.add(Path('/sys/fs/cgroup') / props['ControlGroup'].lstrip('/'))
    groups = {}
    for path in paths:
        assert path.name == UNIT
        groups[str(path)] = {}
        if path.exists():
            for fpath in path.rglob('cgroup.procs'):
                procs = fpath.read_text().split()
                assert not procs, ('producer cgroup occupied', str(fpath), procs)
                groups[str(path)][str(fpath)] = procs
    return dict(unit=UNIT, properties=props, exact_cgroups=groups, identities=identities)


def load_parser():
    spec = importlib.util.spec_from_file_location('sealed_parser', C / 'resource_parser.py')
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def crosschecks(m, text, total):
    rows = m.table(m.section(text, '8. Primitives'), 'Ref Name')
    counts = {}
    for row in rows:
        name = row['Ref Name']
        assert name not in counts, ('duplicate primitive', name)
        counts[name] = m.number(row['Used'])
    # Vivado omits unused primitives. Absence is valid only when the
    # independently required main-table row says exactly zero.
    carry = counts.get('CARRY8', 0)
    assert carry == total['CARRY8']['used'], 'CARRY8 primitive mismatch'
    flipflops = sum(v for k, v in counts.items() if re.fullmatch(r'FD\w+', k))
    assert flipflops == total['CLB Registers']['used'], 'FF primitive mismatch'
    bram = counts.get('RAMB36E2', 0) + counts.get('RAMB18E2', 0) / 2
    assert bram == total['Block RAM Tile']['used'], 'BRAM primitive mismatch'
    assert counts.get('DSP48E2', 0) == total['DSPs']['used']
    assert counts.get('URAM288', 0) == total['URAM']['used']
    boxes = m.table(m.section(text, '9. Black Boxes'), 'Ref Name')
    assert not boxes, ('unresolved blackboxes', boxes)
    return dict(CARRY8_primitive_total=carry, CARRY8_row_present='CARRY8' in counts,
                register_primitive_total=flipflops, BRAM_primitive_total=bram,
                blackboxes=0, primitive_counts=counts,
                packed_LUT_source='Main CLB total corroborated by hierarchy; never LUT1-6 sum')


def analyze():
    policy_sha = policy()
    manifest = read(C / 'inputs.json')
    for path, expected in manifest['inputs'].items():
        assert sha(path) == expected, ('changed immutable input', path)
    guard = producer_guard()
    m = load_parser()
    text = (OLD / 'utilization.rpt').read_text()
    hier = (OLD / 'hierarchical.rpt').read_text()
    total = m.parse_total(text)
    detail = m.parse_hier(hier, total)
    checks = crosschecks(m, text, total)
    assert detail['ram_model_instances'] and total['CLB LUTs']['used'] > 0
    # Retain all earlier section/SLR/capacity/hierarchy mutation tests and
    # extend them to omission of an actual zero primitive.
    m.crosschecks = lambda t, v: crosschecks(m, t, v)
    tests = m.test_parser(text, hier)
    for label in ['CARRY8', 'CLB Registers', 'Block RAM Tile', 'DSPs', 'URAM']:
        bad = copy.deepcopy(total)
        bad[label]['used'] += 1
        tests[label + '_primitive_mismatch_rejected'] = m.rejected(lambda: crosschecks(m, text, bad))
    primitive_row = next(l for l in text.splitlines() if re.match(r'^\| FDRE\s+\|', l))
    tests['duplicate_primitive_rejected'] = m.rejected(
        lambda: crosschecks(m, text.replace(primitive_row, primitive_row + '\n' + primitive_row), total))
    boxes = m.section(text, '9. Black Boxes')
    tests['blackbox_rejected'] = m.rejected(
        lambda: crosschecks(m, text.replace(boxes, boxes + '| unexpected | 1 |\n'), total))
    log = (OLD / 'map.log').read_text()
    assert 'synth_design completed successfully' in log
    assert 'OWNER_ACTUAL_HOST_AREA_ZERO_BLACKBOX_PASS' in log
    assert 'ERROR:' not in log
    ext = read(manifest['extraction'])
    rtl = Path(manifest['closure']).read_text()
    modules = {x[1]: x[0] for x in re.finditer(r'^module (\w+)\b.*?^endmodule\b[^\n]*', rtl, re.M | re.S)}
    assert set(modules) == set(ext['modules']) == {'RamModel', 'ownerImageMemory_flattened'}
    assert all(hashlib.sha256(modules[n].encode()).hexdigest() == h for n, h in ext['modules'].items())
    top = modules['ownerImageMemory_flattened']
    ports = re.findall(r'(?m)^\s*(input|output)\s+(?:\[([^\]]+)\]\s+)?(\w+)', top[:top.index(');')+2])
    assert [list(x) for x in ports] == ext['ports']
    result = dict(schema='ec-owner-generated-area-readonly-recovery/2',
                  status='PASS_ACTUAL_GENERATED_OWNER_HOST_MODULE_AREA_READONLY_RECOVERY',
                  functional_baseline=BASE, derived_hardware=manifest['derived_hardware'],
                  source_id=manifest['source_id'], resources={k: v['used'] for k, v in total.items()},
                  primitive_crosschecks=checks, hierarchy=detail, parser_tests=tests,
                  preserved_ports=len(ports), extraction=ext, input_sha256=manifest['inputs'],
                  producer_exit_guard=guard, policy_sha256=policy_sha,
                  recovery_reason='Original parser demanded a CARRY8 primitive row even for zero use',
                  original_failure_preserved=True, synthesis_rerun=False, target_changed=False,
                  fpga_access=False, whole_fit=False, full_dcache_area=False,
                  production_admission=False, saving_vs_plain_claimed=False,
                  scope='Exact emitted owner RAM host wrapper and RamModel closure only; excludes DCache and FAMETop scheduler')
    return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--preflight', action='store_true')
    args = ap.parse_args()
    if args.preflight:
        value = analyze()
        print(json.dumps(dict(status=value['status'], resources=value['resources'],
                              tests=value['parser_tests'], ports=value['preserved_ports'])))
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if (O / 'complete.json').exists():
        receipt = read(O / 'complete.json')
        assert sha(O / 'result.json') == receipt['result_sha256']
        assert read(O / 'result.json')['input_sha256'] == read(C / 'inputs.json')['inputs']
        producer_guard()
        print('IMMUTABLE_RESULT_REVALIDATED')
        return
    assert not (O / 'result.json').exists(), 'partial result needs separate recovery'
    try:
        value = analyze()
        value['completed_utc'] = datetime.datetime.now(datetime.timezone.utc).isoformat()
        save(O / 'result.json', value)
        save(O / 'complete.json', dict(status='COMPLETE', result_sha256=sha(O / 'result.json')))
        save(O / 'state.json', dict(status=value['status'], result=str(O / 'result.json')))
        print(value['status'], json.dumps(value['resources']))
    except Exception as e:
        save(O / 'failure.json', dict(status='FAILED_WITH_EVIDENCE', error=repr(e)))
        raise


if __name__ == '__main__':
    main()
