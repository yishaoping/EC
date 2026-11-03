#!/usr/bin/env python3
"""Check generated core count, cache capacity/sets/lines and clock ratios."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
REFERENCE = ROOT / 'slowdown/opt4/reference'


def verify(generated):
    config = generated / 'chipyard.TestHarness.v1Config.json'
    frequency = generated / 'chipyard.TestHarness.v1Config.buildTopClockGenerator.freq-summary'
    reference = json.loads((REFERENCE / 'generated_config.json').read_text())
    actual = json.loads(config.read_text())
    expected_cpus = {k: v for k, v in reference['cpus'].items() if k.startswith('cpu@')}
    cpus = {k: v for k, v in actual['cpus'].items() if k.startswith('cpu@')}
    errors = []
    if set(cpus) != set(expected_cpus):
        errors.append('generated hart set changed')
    checked = {}
    for key, expected in expected_cpus.items():
        fields = [k for k in expected if k.startswith(('d-cache-', 'i-cache-'))]
        fields += ['compatible', 'riscv,isa', 'reg']
        checked[key] = {k: cpus.get(key, {}).get(k) for k in fields}
        for field in fields:
            if checked[key][field] != expected[field]:
                errors.append(key + '/' + field + ' changed')
    l2key = 'cache-controller@2010000'
    if actual.get('soc', {}).get(l2key) != reference['soc'][l2key]:
        errors.append('generated L2 geometry/description changed')
    if frequency.read_text().strip() != (REFERENCE / frequency.name).read_text().strip():
        errors.append('generated clock frequencies/ratios changed')
    return dict(status='FAIL' if errors else 'PASS', errors=errors,
        generated_cpus=checked, l2=actual.get('soc', {}).get(l2key),
        sha256={p.name: hashlib.sha256(p.read_bytes()).hexdigest() for p in (config, frequency)},
        scope='generated capacity/sets/line sizes/ways, core identities and clock ratios; fetch bandwidth may differ')


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('generated', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    report = verify(args.generated)
    result = json.dumps(report, indent=2, sort_keys=True) + '\n'
    if args.output:
        args.output.write_text(result)
    print(result)
    raise SystemExit(0 if report['status'] == 'PASS' else 1)
