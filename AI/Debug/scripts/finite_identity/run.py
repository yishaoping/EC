#!/usr/bin/env python3
"""Exercise production L1/L2 finite slot tags at the 16-bit boundary.

Generate HierarchyHarness with the existing rollback/user_build.sh first.
Only two empty slots' reset initial values are accelerated from 0 to 0xffff;
the original generated model, exact two replacements and both hashes are
saved. All reservation/install/refill/completion logic runs unchanged.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import resource
import subprocess

ROOT = Path(__file__).resolve().parents[4]


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--generated', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--generation-inputs', type=Path, required=True)
    parser.add_argument('--kind', choices=['slot', 'generation'], default='slot')
    parser.add_argument('--jobs', type=int, default=8)
    args = parser.parse_args()
    generated, out, provenance = (p.resolve() for p in [args.generated, args.out, args.generation_inputs])
    assert all(p.is_relative_to(ROOT / 'AI/TMP') for p in [generated, out, provenance])
    assert not out.exists()
    out.mkdir()
    original = generated / 'HierarchyHarness.v'
    text = original.read_text()
    substitutions = []
    if args.kind == 'slot':
        for way in [0, 1]:
            source = f"slotEpoch_64_{way} <= 16'h0;"
            target = f"slotEpoch_64_{way} <= 16'hffff;"
            assert text.count(source) == 1, 'fixture geometry or reset changed; re-audit before seeding'
            text = text.replace(source, target)
            substitutions.append({'before': source, 'after': target})
    else:
        match = re.search(r'(?ms)^module PalimpsestExecutionHistory\(.*?^endmodule', text)
        assert match, 'production ExecutionHistory module missing'
        body = match[0]
        for name in ['epoch', 'generation']:
            source, target = name + " <= 32'h0;", name + " <= 32'hffffffdd;"
            assert body.count(source) == 2, 'reset/physical compact assignments changed; re-audit seed'
            body = body.replace(source, target, 1)  # Keep actual compact-to-zero logic.
            substitutions.append({'before': source, 'after': target, 'reset_only': True})
        text = text[:match.start()] + body + text[match.end():]
    seeded = out / 'HierarchyHarness.v'
    seeded.write_text(text)
    bench = Path(__file__).with_name('slot_epoch_test.cpp' if args.kind == 'slot' else 'generation_test.cpp')
    inputs = [original, seeded, provenance, bench, Path(__file__).resolve(),
              ROOT / 'AI/Debug/scripts/rollback/hierarchy_test.cpp',
              generated / 'CacheOpportunityObserver.sv', generated / 'cache_opportunity.cc']
    hashes = {str(p): digest(p) for p in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    (out / 'boundary_acceleration.json').write_text(json.dumps({
        'scope': 'Only initial labels accelerated; no protocol, compact, acknowledgement or result predicates modified',
        'replacements': substitutions}, indent=2) + '\n')
    cmd = [os.environ.get('PALIMPSEST_VERILATOR', 'verilator'), '--cc', '--exe', '--build',
           '-j', str(args.jobs), '--assert', '-Wno-fatal', '-Werror-UNOPTFLAT', '-Werror-PINMISSING',
           '-y', str(generated), '--top-module', 'HierarchyHarness', '--Mdir', str(out / 'obj'),
           '-CFLAGS', '-std=c++17', str(seeded), str(inputs[-2]), str(inputs[-1]), str(bench)]
    (out / 'build.command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (out / 'build.log').open('x') as log:
        ret = subprocess.run(cmd, stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'build.exit').write_text(str(ret) + '\n')
    if ret:
        return ret
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
    with (out / 'run.log').open('x') as log:
        ret = subprocess.run([str(out / 'obj/VHierarchyHarness')], stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'run.exit').write_text(str(ret) + '\n')
    assert all(digest(Path(p)) == h for p, h in hashes.items()), 'boundary verification input changed'
    text = (out / 'run.log').read_text()
    marker = 'PALIMPSEST_SLOT_EPOCH_BOUNDARY=PASS' if args.kind == 'slot' else 'PALIMPSEST_GENERATION_BOUNDARY=PASS'
    passed = ret == 0 and marker in text and \
        not re.search(r'Assertion failed|UNCOVERED|FAIL', text)
    (out / 'result.json').write_text(json.dumps({'status': 'PASS' if passed else 'FAIL',
        'run_exit': ret, 'kind': args.kind,
        'scope': 'Production L1/L2 owner and real physical maintenance certificate; only initial labels accelerated'}, indent=2) + '\n')
    print('PALIMPSEST_FINITE_SLOT_OWNER=' + ('PASS' if passed else 'FAIL'))
    return 0 if passed else 1


if __name__ == '__main__':
    raise SystemExit(main())
