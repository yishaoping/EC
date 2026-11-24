#!/usr/bin/env python3
"""Validate same-address publication owners with the production Stage3 model.

Generate Stage3 first using user_build.sh (Baseline or Pressure), then supply
that output's generated directory and sources.before.json. This runner checks
every production Scala input and fixture against the generation manifest,
records its own bench/script inputs separately, and preserves every failure.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / 'AI/Debug/scripts/rollback'))
import source_manifest


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--generated', type=Path, required=True)
    parser.add_argument('--manifest', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--jobs', type=int, default=8)
    parser.add_argument('--suite', choices=['publication', 'grantack-preemption'], default='publication')
    args = parser.parse_args()
    generated, manifest, out = (p.resolve() for p in [args.generated, args.manifest, args.out])
    assert all(p.is_relative_to(ROOT / 'AI/TMP') for p in [generated, manifest, out])
    assert not out.exists()
    before = source_manifest.capture()
    recorded = json.loads(manifest.read_text())
    # Code outside the generated model, such as a fullcore scoreboard, may
    # change independently; all production Scala and this fixture must match.
    required = {p for p in before['sources'] if p.startswith('chipyard/') and p.endswith(('.scala', '.sbt'))}
    required |= {'AI/Debug/scripts/stage3/Stage3Generate.scala',
                 'AI/Debug/scripts/stage3/stage3_test.cpp'}
    assert all(recorded['sources'].get(p) == before['sources'][p] for p in required), \
        'production source/Stage3 fixture differs from generation manifest'
    out.mkdir()
    bench = Path(__file__).with_name('publication_test.cpp' if args.suite == 'publication'
                                     else 'grantack_preemption_test.cpp')
    inputs = [generated / 'Stage3Harness.v', generated / 'CacheOpportunityObserver.sv',
              generated / 'cache_opportunity.cc', manifest, bench, Path(__file__).resolve(),
              ROOT / 'AI/Debug/scripts/stage3/stage3_test.cpp',
              ROOT / 'AI/Debug/scripts/rollback/source_manifest.py']
    hashes = {str(p): digest(p) for p in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    (out / 'sources.before.json').write_text(json.dumps(before, indent=2, sort_keys=True) + '\n')
    cmd = [os.environ.get('PALIMPSEST_VERILATOR', 'verilator'), '--cc', '--exe', '--build',
           '-j', str(args.jobs), '--assert', '-Wno-fatal', '-Werror-UNOPTFLAT', '-Werror-PINMISSING',
           '-y', str(generated), '--top-module', 'Stage3Harness', '--Mdir', str(out / 'obj'),
           '-CFLAGS', '-std=c++17'] + [str(p) for p in inputs[:3]] + [str(bench)]
    (out / 'build.command.json').write_text(json.dumps(cmd, indent=2) + '\n')
    with (out / 'build.log').open('x') as log:
        ret = subprocess.run(cmd, stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'build.exit').write_text(str(ret) + '\n')
    if ret:
        return ret
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))
    with (out / 'run.log').open('x') as log:
        ret = subprocess.run([str(out / 'obj/VStage3Harness')], stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'run.exit').write_text(str(ret) + '\n')
    after = source_manifest.capture()
    (out / 'sources.after.json').write_text(json.dumps(after, indent=2, sort_keys=True) + '\n')
    text = (out / 'run.log').read_text()
    cases = re.findall(r'^CASE (\w+) PASS$', text, re.M)
    expected = (['same_address_multiversion_sw_scan_trusted_put',
                 'same_address_multiversion_sw_scan_late_probe',
                 'safe_coalesce_preserves_held_publication_owner',
                 'same_address_multiversion_evt_outer_ack_late_c'] if args.suite == 'publication'
                else ['grantack_same_set_release_history'])
    marker = ('PALIMPSEST_MULTI_OWNER_BASELINE=PASS' if args.suite == 'publication'
              else 'PALIMPSEST_GRANTACK_PREEMPTION=PASS')
    assert ret == 0 and cases == expected, 'publication/preemption regression failed'
    assert marker in text and not re.search(r'UNCOVERED|Assertion failed|=FAIL', text)
    assert before == after and all(digest(Path(p)) == h for p, h in hashes.items()), 'verification inputs changed'
    (out / 'result.json').write_text(json.dumps({'status': 'PASS', 'cases': cases,
        'run_exit': ret, 'fixed_sources': True, 'generation_sources_checked': len(required)}, indent=2) + '\n')
    print('PALIMPSEST_BASELINE_PUBLICATION=PASS cases=' + str(len(cases)) + ' fixed_sources=1')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
