#!/usr/bin/env python3
"""Require real CLINT/MSIP effects, complete handlers and a strict fault pair."""
import argparse
import json
from pathlib import Path
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'rollback'))
import fullcore_scoreboard as full
import io_effect_scoreboard as io


def validate(normal, fault, effects, irq=None):
    full.check(normal, fault, 18, require_trap_io=True)
    for p in [normal, fault]:
        with Path(p).open(errors='replace') as stream:
            markers = [m for s in stream for m in re.findall(
                r'PALIMPSEST_MSIP_RESULT checks=(\d+) last=([0-9a-f]+)', s)]
        assert markers == [('16', '0000000000000010')], 'missing/incorrect interrupt handler oracle'
    chain = io.check(effects, fault, 18)
    assert chain['identity'][1:] == (0x2000000, 1, 2), 'fault does not own actual 32-bit MSIP store'
    decimal = {'tick','clock','old_state','state','journal','replay','mem_access_fire'}
    operations = []
    for s in Path(effects).read_text().splitlines():
        if not s.startswith('IO_EFFECT_OBSERVER '):
            continue
        fields = {k: int(v, 10 if k in decimal else 16)
                  for k, v in re.findall(r'(\w+)=([0-9a-f]+)', s)}
        if fields['mem_access_fire'] and fields['addr'] == 0x2000000 and fields['seq'] != 0:
            operations.append(fields)
    assert len(operations) == 32, 'missing or duplicate actual MSIP device write'
    rounds = []
    for i in range(16):
        set_, clear = operations[2*i:2*i+2]
        assert set_['cmd'] == clear['cmd'] == 1 and set_['size'] == clear['size'] == 2
        assert set_['operand'] & 0xffffffff == 1 and clear['operand'] & 0xffffffff == 0
        assert set_['tick'] < clear['tick']
        rounds.append(dict(round=i, set=set_, clear=clear))
    report = dict(scope='complete_program_actual_msip_handlers_fault_and_effect_replay',
                  effect_chain=chain, actual_device_rounds=rounds)
    if irq:
        rows = []
        for s in Path(irq).read_text().splitlines():
            assert s.startswith('IRQ '), 'damaged IRQ observer'
            row = {k:int(v,16 if k=='cause' else 10) for k,v in re.findall(r'(\w+)=([0-9a-f]+)',s)}
            assert row.keys() == {'tick','clock','pending','irq','cause','stop','boundary','effect','seq','trap'}
            if row['irq']:
                assert not row['stop'] and not row['boundary'] and not row['effect'], 'IRQ escaped recovery/I/O hold'
            rows.append(row)
        held = [r for r in rows if r['pending'] and r['stop'] and r['effect'] and r['seq']==18]
        assert held, 'UNCOVERED: real pending interrupt overlaps unresolved effect and rollback'
        accepted = [r for r in rows if r['pending'] and r['irq'] and r['cause']==0x8000000000000003]
        assert accepted and min(r['tick'] for r in accepted)>held[0]['tick']
        report['pending_over_recovery'] = held
        report['later_real_irq'] = accepted
    return report


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--normal', type=Path, required=True)
    p.add_argument('--fault', type=Path, required=True)
    p.add_argument('--effects', type=Path, required=True)
    p.add_argument('--irq', type=Path)
    p.add_argument('--report', type=Path, required=True)
    a = p.parse_args()
    result = validate(a.normal,a.fault,a.effects,a.irq)
    with a.report.open('x') as f:
        json.dump(result,f,indent=2)
        f.write('\n')
    print('PALIMPSEST_MSIP_INTERRUPT=PASS actual_set_clear_rounds=16 no_duplicate_A=1')


if __name__ == '__main__':
    main()
