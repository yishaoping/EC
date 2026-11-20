#!/usr/bin/python3
"""Audit existing frozen SVB wrapper observation coverage; never run a simulator."""
from pathlib import Path
import datetime
import hashlib
import json
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = Path(__file__).resolve().parent
SOURCE = D / 'cycleprecise-frozen-svb-gg-r1-20261111'
OUT = D / 'build-logs/Opt4-route-a-svb-observation-audit-round33-v1-20261111'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            digest.update(block)
    return digest.hexdigest()


def flat(path):
    return re.sub(r'[.\[\]]', '_', path).replace('__', '_').rstrip('_')


def main():
    policy = read(U / 'campaign-policy.json')
    baseline = '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['functional_baseline_commit'] == baseline
    assert policy['area_equivalence_only'] and not policy['fpga_access']
    assert policy['native_paused'] and not policy['functional_extensions_allowed']
    assert not OUT.exists(), 'Preserve immutable earlier audit; use a new version.'
    state = read(SOURCE / 'state.json')
    assert state['status'] == 'FAILED_WITH_EVIDENCE'
    assert state['stage'] == 'run' and state['functional_baseline'] == baseline
    binding = read(SOURCE / 'binding.json')
    assert binding['functional_baseline'] == baseline
    assert binding['extracted_module_verbatim'] and binding['wrapper_only']
    target = SOURCE / 'SVBProbe.fir'
    annotation = SOURCE / 'SVBProbe.anno.json'
    assert sha(target) == binding['target_sha256']
    assert sha(annotation) == binding['annotations_sha256']
    text = target.read_text()
    module = re.search(r'^  module SpeculativeVersionBuffer :\n.*?(?=^  (?:ext)?module |\Z)',
                       text, re.M | re.S)[0]
    assert hashlib.sha256(module.encode()).hexdigest() == binding['extracted_module_sha256']
    assert len(module.encode()) == binding['module_bytes']
    bridge = next(row for row in read(annotation)
                  if row.get('target') == '~SVBProbe|PeekPokeBridge')
    peeks = bridge['widgetConstructorKey']['peeks']
    pokes = bridge['widgetConstructorKey']['pokes']
    peekmap = {row['name']: row['fieldWidth'] for row in peeks}
    pokemap = {row['name']: row['fieldWidth'] for row in pokes}
    assert len(peekmap) == len(peeks) and len(pokemap) == len(pokes)
    channels = {row['name']: row for row in bridge['bridgeChannels']}
    assert len(channels) == len(bridge['bridgeChannels'])
    driver = SOURCE / 'SVBTest.cc'
    code = driver.read_text()
    body = code[code.index('void run_test()override'):]
    mentioned = set(re.findall(r'\bd\.(io_\w+)', body))
    rows = []
    names = set()
    for path, width, output in binding['ports']:
        name = flat(path)
        assert name not in names
        names.add(name)
        assert (peekmap if output else pokemap)[name] == width
        connection = ('peekPokeBridge.' + path + ' <= dut.' + path if output
                      else 'dut.' + path + ' <= peekPokeBridge.' + path)
        assert text.count('    ' + connection + '\n') == 1
        channel = channels[name]
        ref = '~SVBProbe|PeekPokeBridge>' + path
        assert channel['sources'] == ([ref] if output else [])
        assert channel['sinks'] == ([] if output else [ref])
        assert channel['latency'] == 0
        assert channel['clock'] == '~SVBProbe|PeekPokeBridge>clock'
        assert 'Signal ' + name + ';' in code
        rows.append(dict(path=path, name=name, width=width,
                         direction='output' if output else 'input',
                         wrapper_connected=True, bridge_annotation_verified=True,
                         driver_proxy_exists=True, test_body_mentions=name in mentioned,
                         cycle_comparison_verified=False))
    outputs = [row for row in rows if row['direction'] == 'output']
    inputs = [row for row in rows if row['direction'] == 'input']
    assert len(outputs) == 127 and sum(row['width'] for row in outputs) == 5902
    assert set(peekmap) == {row['name'] for row in outputs}
    assert set(pokemap) == {'reset'} | {row['name'] for row in inputs}
    assert pokemap['reset'] == 1
    receipt_path = SOURCE / 'receipts/run.json'
    receipt = read(receipt_path)
    log_path = SOURCE / 'run.log'
    log = log_path.read_text()
    assert 'old versions not retained' in log
    allocations = [line for line in log.splitlines() if 'SVB_ENTRY_ALLOC' in line]
    files = [Path(__file__), SOURCE / 'binding.json', target, annotation, driver,
             SOURCE / 'state.json', receipt_path, log_path]
    audit = dict(
        schema='ec-opt4-route-a-original-svb-observation-audit/1',
        created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        functional_baseline=baseline, fpga_access=False, target_modified=False,
        source_state=state['status'], scope='Static wrapper and test coverage audit only.',
        original_target_fir=binding['target_fir'],
        original_target_fir_sha256_from_authenticated_binding=binding['target_fir_sha256'],
        original_large_target_rehashed_this_audit=False,
        extracted_module_sha256=binding['extracted_module_sha256'],
        outputs=len(outputs), output_bits=sum(row['width'] for row in outputs),
        inputs=len(inputs), all_original_output_connections_verified=True,
        all_original_output_peek_widths_channels_verified=True,
        test_body_mentioned_outputs=sum(row['test_body_mentions'] for row in outputs),
        test_body_unmentioned_outputs=[row['path'] for row in outputs
                                      if not row['test_body_mentions']],
        mention_is_not_value_or_cycle_coverage=True,
        all_output_cycle_comparison_verified=False,
        observations=rows,
        failure=dict(receipt=str(receipt_path), returncode=receipt.get('returncode'),
                     first_failed_harness_condition='occupancy==2 && releaseBlocked[0]',
                     message='old versions not retained',
                     allocation_events=allocations,
                     cause='Unproven; target vs host transport scheduling requires foreground diagnosis.',
                     rtl_bug_confirmed=False),
        complete_opt4=False, whole_fit=False, formal_fpga_sample=False,
        bindings={str(path): sha(path) for path in files},
        next_verification='After foreground transport recovery passes, compare all 127 outputs (5902 bits) at every required original target cycle against direct frozen RTL using identical stimuli, reset and handshake events. Retain instrumentation, diagnostics, target clocks and collision behavior. No functional recovery gate added.')
    # Recheck policy before writing only new audit artifacts.
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['fpga_access']
    OUT.mkdir()
    with (OUT / 'observation-inventory.json').open('x') as stream:
        json.dump(audit, stream, indent=2, sort_keys=True)
        stream.write('\n')
    mentioned_count = audit['test_body_mentioned_outputs']
    report = f'''The existing frozen SVB GoldenGate wrapper connects all 127 original outputs (5902 bits), and every output has the matching PeekPoke width and zero-latency target-clock channel. All 32 functional inputs plus reset have matching poke entries. This is a static coverage audit, not a passing metasimulation or cycle comparison.

The directed test body mentions {mentioned_count} of the 127 outputs. A mention can be an ACK input copy or a condition; it does not establish full-width or cycle coverage. The inventory records every original output so the subsequent frozen RTL/GoldenGate comparison can check all values, including histogram, accounting and release diagnostics.

The immutable r1 run failed at `occupancy==2 && releaseBlocked[0]` with `old versions not retained`. Its log contains {len(allocations)} allocation event(s). This evidence does not establish a DUT bug or the cause of the transport discrepancy. Foreground owns the recovery; this audit changes no harness, RTL, controller, active job or admission rule.

The original full target FIR identity is inherited from its extraction binding; the exact wrapper and extracted module hashes were checked here. No FPGA sample, full Opt4 result, universal equivalence proof or whole-system area gain follows from this audit.
'''
    with (OUT / 'REPORT.md').open('x') as stream:
        stream.write(report)
    print(json.dumps(dict(inventory=str(OUT / 'observation-inventory.json'),
                          outputs=len(outputs), output_bits=audit['output_bits'],
                          test_body_mentions=mentioned_count, cycle_comparison=False)))


if __name__ == '__main__':
    main()
