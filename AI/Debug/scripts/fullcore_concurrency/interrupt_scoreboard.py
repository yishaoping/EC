#!/usr/bin/env python3
"""Require full MSIP programs, one injected rollback and all 16 device/IRQ rounds."""
import argparse
import json
from pathlib import Path
import re
import sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'rollback'))
import fullcore_scoreboard
import io_effect_scoreboard
from build_io_observer import digest


def effects(path):
    samples, footer = [], None
    decimal = {'tick', 'clock', 'old_state', 'state', 'journal', 'replay', 'mem_access_fire'}
    with Path(path).open() as stream:
        for line in stream:
            if line.startswith('IO_EFFECT_OBSERVER_END '):
                assert footer is None, 'duplicate effect footer'
                footer = {k: int(v) for k, v in re.findall(r'(\w+)=(\d+)', line)}
                continue
            assert footer is None and line.startswith('IO_EFFECT_OBSERVER ')
            s = {k: int(v, 10 if k in decimal else 16)
                 for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
            assert s['mem_access_fire'] == int(s['old_state'] == 1 and s['state'] == 2)
            if samples:
                assert s['old_state'] == samples[-1]['state'] and s['tick'] >= samples[-1]['tick']
            else:
                assert s['old_state'] == (1 << 64) - 1 and s['state'] == 0
            samples.append(s)
    assert samples and footer and footer['events'] == len(samples)
    assert footer['last_tick'] >= samples[-1]['tick']
    operations = [s for s in samples if s['mem_access_fire'] and s['seq'] and s['addr'] == 0x2000000]
    assert len(operations) == 32, 'missing or duplicated protected MSIP device effect'
    rounds = []
    for i in range(16):
        enable, clear = operations[2*i:2*i+2]
        assert enable['cmd'] == clear['cmd'] == 1 and enable['size'] == clear['size'] == 2
        assert enable['operand'] & 0xffffffff == 1 and clear['operand'] & 0xffffffff == 0
        assert enable['pc'] == operations[0]['pc'] and clear['pc'] == operations[1]['pc']
        assert enable['tick'] < clear['tick']
        if i:
            assert operations[2*i-1]['tick'] < enable['tick']
        rounds.append({'set': enable, 'clear': clear})
    return rounds


def interrupts(path, rounds, require_overlap):
    samples, footer = [], None
    with Path(path).open() as stream:
        for line in stream:
            if line.startswith('IRQ_OBSERVER_END '):
                assert footer is None, 'duplicate interrupt footer'
                footer = {k: int(v) for k, v in re.findall(r'(\w+)=(\d+)', line)}
                continue
            assert footer is None and line.startswith('IRQ ')
            s = {k: int(v, 16 if k in {'seq', 'cause', 'trap_cause', 'epc'} else 10)
                 for k, v in re.findall(r'(\w+)=([0-9a-f]+)', line)}
            required = {'tick','clock','pending','irq','cause','stop','boundary','effect','seq','trap'}
            required |= {'safe', 'effect_pending', 'starting', 'hold', 'trap_cause', 'ret', 'epc', 'owner'}
            assert set(s) == required, 'closure requires actual I/O gate and trap/return fields'
            assert s['effect_pending'] == int(s['owner'] or (s['effect'] and not s['safe'])), \
                'IOMSHR pending disagrees with retained journal safety'
            assert s['hold'] == int(s['starting'] or s['boundary'] != 0 or s['effect_pending'])
            if samples:
                assert s['tick'] >= samples[-1]['tick']
            samples.append(s)
    assert samples and footer and footer['events'] == len(samples)
    assert footer['last_tick'] >= samples[-1]['tick']
    # Boot-time CLINT initialization can toggle MSIP before the protected
    # workload starts. Align the interrupt window with the first real device
    # set, then require exactly one pending interval per protected round.
    first_set_tick = rounds[0]['set']['tick']
    scoped = [(i, s) for i, s in enumerate(samples) if s['tick'] >= first_set_tick]
    rises = [s for n, (i, s) in enumerate(scoped)
             if s['pending'] and (n == 0 or not scoped[n-1][1]['pending'])]
    falls = [s for n, (i, s) in enumerate(scoped)
             if n and not s['pending'] and scoped[n-1][1]['pending']]
    assert len(rises) == len(falls) == 16, 'missing or duplicate CLINT pending transition'
    for i, (rise, fall) in enumerate(zip(rises, falls)):
        assert rounds[i]['set']['tick'] <= rise['tick'] < rounds[i]['clear']['tick'] <= fall['tick']
        offers = [s for s in samples if rise['tick'] <= s['tick'] <= fall['tick'] and s['irq']]
        assert offers and all(s['cause'] == 0x8000000000000003 for s in offers)
        # journalValid is a retained replay record. Admission is controlled by
        # the live effectPending/starting/boundary hold, which is now observed
        # directly in current-source runs.
        assert all(not s['stop'] and s['boundary'] == 0 for s in offers), \
            'interrupt admitted while recovery or I/O barrier owns execution'
        if offers:
            assert all(not s['effect_pending'] and not s['starting'] and not s['hold']
                       for s in offers), \
                'interrupt admitted while live I/O admission hold is asserted'
            traps = [s for s in samples if rise['tick'] <= s['tick'] <= fall['tick']
                     and s['trap'] and s['trap_cause'] == 0x8000000000000003]
            assert traps, 'missing software-interrupt trap cause'
            assert len(traps) == 1, 'duplicate software-interrupt trap in one pending round'
            assert not traps[0]['stop'] and not traps[0]['hold'], \
                'software interrupt reached trap while recovery or an I/O owner held admission'
            next_trap_tick = min((s['tick'] for s in samples
                if s['tick'] > traps[0]['tick'] and s['trap']), default=float('inf'))
            returns = [s for s in samples if s['ret'] and
                       traps[0]['tick'] < s['tick'] < next_trap_tick]
            assert len(returns) == 1, 'missing or duplicate xRET before the next trap'
            saved_epc = next(s['epc'] for s in samples if s['tick'] > traps[0]['tick'])
            assert saved_epc and returns[0]['epc'] == saved_epc, \
                'software-interrupt xRET changed the saved architectural MEPC'
        assert any(s['trap'] for s in samples if rise['tick'] <= s['tick'] <= fall['tick']), \
            'missing actual architectural trap for MSIP'
    overlap = [s for _, s in scoped if s['pending'] and s['stop'] and
               (s.get('effect_pending', s['effect'])) and not s['irq']]
    if require_overlap:
        assert overlap, 'UNCOVERED: pending MSIP with recovery and outstanding effect'
    software_traps = [s for _, s in scoped if s['trap'] and
                      s['trap_cause'] == 0x8000000000000003]
    assert len(software_traps) == 16, 'missing or duplicate software-interrupt trap'
    return {'rounds': 16, 'pending_rises': len(rises), 'pending_falls': len(falls),
            'software_traps': len(software_traps), 'matched_returns': 16,
            'recovery_effect_overlap': overlap}


def check(normal, fault, normal_effects, fault_effects, normal_irq, fault_irq, failed_seq=18):
    fullcore_scoreboard.check(normal, fault, failed_seq, True)
    for path in (normal, fault):
        markers = []
        with Path(path).open(errors='replace') as stream:
            for line in stream:
                markers += re.findall(r'PALIMPSEST_MSIP_RESULT checks=(\d+) last=([0-9a-f]+)', line)
        assert markers == [('16', '0000000000000010')], 'missing actual handler count oracle'
    replay = io_effect_scoreboard.check(fault_effects, fault, failed_seq)
    assert replay['identity'][1:] == (0x2000000, 1, 2)
    good, bad = effects(normal_effects), effects(fault_effects)
    return {'status': 'PASS', 'failed_seq': failed_seq, 'replay': replay,
            'normal': interrupts(normal_irq, good, False),
            'fault': interrupts(fault_irq, bad, True),
            'normal_device_rounds': good, 'fault_device_rounds': bad}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('normal', 'fault', 'normal-effects', 'fault-effects', 'normal-irq', 'fault-irq', 'report'):
        p.add_argument('--' + name, type=Path, required=True)
    p.add_argument('--failed-seq', type=int, default=18)
    a = p.parse_args()
    assert not a.report.exists(), 'preserve prior verdict'
    paths = [a.normal, a.fault, a.normal_effects, a.fault_effects, a.normal_irq, a.fault_irq,
             Path(__file__).resolve(), Path(fullcore_scoreboard.__file__), Path(io_effect_scoreboard.__file__)]
    hashes = {str(x): digest(x) for x in paths}
    result = check(a.normal, a.fault, a.normal_effects, a.fault_effects,
                   a.normal_irq, a.fault_irq, a.failed_seq)
    assert all(digest(Path(x)) == h for x, h in hashes.items()), 'scoreboard input changed'
    result['inputs'] = hashes
    a.report.write_text(json.dumps(result, indent=2) + '\n')
    print('PALIMPSEST_INTERRUPT_FULLCORE=PASS rounds=16 set=16 clear=16 replay_device_A=1')


if __name__ == '__main__':
    main()
