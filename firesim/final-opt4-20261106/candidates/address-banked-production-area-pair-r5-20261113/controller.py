#!/usr/bin/python3
"""Bind the original serial mapper to the precise-boundary R6 host receipts."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import re
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-area-pair-r5-20261113'
P = D/'build-logs/Opt4-address-banked-production-host-r6-20261113'
R2 = D/'build-logs/Opt4-address-banked-production-host-r2-20261113'
R1 = D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
SOURCE = W/'candidates/address-banked-production-host-r6-20261113'
TREE = W/'Opt4-area-address-production-area-pair-r5-20261113'
UNIT = 'ec-opt4-address-banked-production-host-r6-20261113.service'
BASELINE = '8491167d84b6d9521b151a743673c1516926a1f8'
HARDWARE = '4b0ca01ee8704fe1db70e35c08ab3bd4c00e9ec0'
PASS = 'PASS_PRODUCTION_HOST_PRECISE_3003_TOKEN_ORACLE_AND_PLAIN_THREADED_PARITY_NO_AREA'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

spec = importlib.util.spec_from_file_location('original_serial_production_mapper',
    W/'candidates/address-banked-production-area-pair-r1-20261112/controller.py')
p = importlib.util.module_from_spec(spec)
spec.loader.exec_module(p)
p.C, p.O, p.P, p.SOURCE, p.UNIT, p.PASS = C, O, P, SOURCE, UNIT, PASS
p.m.C, p.m.O, p.m.CPUS = C, O, {212, 213}


def members(unit):
    expected = '/user.slice/user-1008.slice/user@1008.service/'+unit
    result = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit():
            continue
        try:
            paths = [line.split(':', 2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            if any(path == expected or path.startswith(expected+'/') for path in paths):
                row = identity(int(proc.name))
                if row and row['process_state'] not in ['Z', 'X']:
                    result.append(row)
        except OSError:
            pass
    return result


def verify_binding():
    binding = read(C/'source-binding.json')
    assert binding['functional_baseline'] == BASELINE
    assert binding['hardware_commit'] == HARDWARE
    assert all(sha(path) == h for path, h in binding['files'].items()), 'Area inputs changed'
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE, text=True).strip() == binding['experiment_commit']
    for rel, h in binding['committed_files'].items():
        data = subprocess.check_output(['git', 'show', binding['experiment_commit']+':'+rel], cwd=TREE)
        assert hashlib.sha256(data).hexdigest() == h
    return binding


def receipt(path, negative=False):
    value = read(path)
    assert value['accepted'] and not value['missing_outputs'], str(path)
    assert value['negative'] == negative
    assert (value['returncode'] != 0) == negative
    assert sha(value['log']) == value['log_sha256']
    assert all(sha(name) == h for name, h in value['outputs'].items())
    return value


def target_gate():
    # R6 changes only observation synchronization; target regression is R1's
    # exact full-size private miter, including invalid payload and mutation.
    positive = receipt(R1/'full-target-parity-receipt.json')
    negative = receipt(R1/'full-target-negative-receipt.json', True)
    text = Path(positive['log']).read_text()
    assert ('PRODUCTION_COMPLETE_MODULE_PARITY_PASS cycles=6144 public_outputs=52 '
            'bucket_words=5120 valid_words=256 sequence_words=256 checks_per_edge=5684 '
            'invalid_seed=1 normal_reset=1') in text
    assert 'PRODUCTION_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000' in Path(negative['log']).read_text()
    r2binding = read(W/'candidates/address-banked-production-host-r2-20261113/source-binding.json')
    assert r2binding['hardware_commit'] == HARDWARE and r2binding['functional_baseline'] == BASELINE
    assert all(sha(path) == h for path, h in r2binding['files'].items())
    return {str(path): sha(path) for path in [R1/'full-target-parity-receipt.json',
        R1/'full-target-negative-receipt.json']}


def prerequisites(result):
    verify_binding()
    assert result.get('status') == PASS
    assert result.get('hardware_commit') == HARDWARE and result.get('functional_baseline') == BASELINE
    assert result.get('finite_target_parity_reused') is True
    assert result.get('reused_exact_target_and_threaded_host') is True
    assert result.get('target_tokens') == 3003 and result.get('public_outputs') == 52
    tokens = result['tokens']
    for name in ['Plain', 'Threaded']:
        assert tokens[name]['target_tokens'] == 3003
        assert tokens[name]['checked_outputs'] == 3000*52
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    receipts = target_gate()
    for name in ['token-oracle-Plain', 'token-negative-Plain',
                 'token-oracle-Threaded', 'token-negative-Threaded']:
        path = P/(name+'-receipt.json')
        value = receipt(path, 'negative' in name)
        text = Path(value['log']).read_text()
        marker = ('COMPLETE_ADDRESS_HOST_MISMATCH cycle=100 port=io_statsValid'
                  if 'negative' in name else 'COMPLETE_ADDRESS_HOST_TOKEN_PASS ')
        assert marker in text
        receipts[str(path)] = sha(path)
    pins = read(P/'inputs.json')['files']
    assert pins[str(SOURCE/'source-binding.json')] == sha(SOURCE/'source-binding.json')
    assert all(sha(path) == h for path, h in pins.items()), 'R6 production pins changed'
    return dict(result_sha256=sha(P/'result.json'), receipts=receipts,
        production_inputs_sha256=sha(P/'inputs.json'),
        source_binding_sha256=sha(SOURCE/'source-binding.json'),
        area_source_binding_sha256=sha(C/'source-binding.json'),
        hardware_commit=HARDWARE, target_cycles=6144, monitor_outputs=5684,
        host_tokens=3003, production_public_outputs=52,
        geometry=dict(banks=16, lanes=16, slots=256))


def production_abi():
    candidate = R1/'Module-target/ProductionModuleCandidate.v'
    reference = D/'build-logs/Opt4-address-packed-full-module-r1-20261112/Reference-Module/FPGATop.v'
    ports = p.target_ports(candidate, 'ProductionModuleCandidate')
    assert ports == p.target_ports(reference, 'FPGATop')
    outputs = [name for direction, width, name in ports if direction == 'output']
    assert len(outputs) == 52 and all(not name.startswith('io_debug') for name in outputs)
    target_receipt = receipt(R2/'elaborate-host-receipt.json')
    annotation = R2/'Host-target/CompleteAddressStats.anno.json'
    assert target_receipt['outputs'][str(annotation)] == sha(annotation)
    selected = [a for a in read(annotation)
                if a.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected) == 16
    assert all(a['target'].startswith('~CompleteHost|CompleteHost/bucketBanks_') for a in selected)
    audits = {}
    for name, directory in [('Plain', P), ('Threaded', R2)]:
        host = directory/name
        generated = receipt(directory/('goldengate-'+name+'-receipt.json'))
        rtl = host/'FireSim-generated.sv'
        assert generated['outputs'][str(rtl)] == sha(rtl)
        assert sha(P/name/'FireSim-generated.sv') == sha(rtl)
        assert sha(P/name/'FireSim-generated.synthesis.xdc') == sha(host/'FireSim-generated.synthesis.xdc')
        assert 'Skipping Combinational Loop Detection' not in Path(generated['log']).read_text()
        fir = (host/'post-gen-sram-models.fir').read_text()
        assert not re.search(r'io_debug(?:Buckets|Valid|Seq|Bucket)', fir)
        assert ('module BucketBank_threaded :' in fir) == (name == 'Threaded')
        if name == 'Plain':
            fame = (host/'post-fame-transform.fir').read_text()
            types = re.findall(r'(?m)^\s*inst \w+ of (BucketBank(?:_\d+)?)\b', fame)
            assert len(types) == 16 and len(set(types)) == 1
        else:
            audit = read(R2/'Threaded-threading-audit.json')
            assert audit['host_RTL_sha256'] == sha(rtl)
            assert audit['selected_count'] == 16 and audit['proof_ports_absent']
        audits[name] = dict(host_RTL_sha256=sha(rtl), generated_receipt_sha256=sha(
            directory/('goldengate-'+name+'-receipt.json')),
            post_gen_sram_models_sha256=sha(host/'post-gen-sram-models.fir'))
    return dict(reference_RTL_sha256=sha(reference), candidate_RTL_sha256=sha(candidate),
        identical_public_ports=ports, public_outputs=52, proof_ports_absent=True,
        reference_host='Plain', candidate_host='Threaded',
        geometry=dict(banks=16, lanes=16, slots=256), host_audits=audits)


p.prerequisites = prerequisites
p.production_abi = production_abi
p.owner_members = lambda: members(UNIT)


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'waiter.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt the exact area owner'
    binding = verify_binding()
    old_unit = 'ec-opt4-address-banked-production-area-pair-r4-20261113.service'
    assert not members(old_unit), 'Preserve predecessor area cgroup'
    prior = D/'build-logs/Opt4-address-banked-production-area-pair-r4-20261113/state.json'
    assert read(prior)['status'] == 'PREREQUISITE_FAILED_NO_AREA_STARTED'
    save(O/'predecessor-release.json', dict(utc=now(), unit=old_unit, members=[],
        state=str(prior), state_sha256=sha(prior), unchanged_mapper=True))
    while True:
        state, result = read(P/'state.json'), read(P/'result.json')
        if result.get('status') == PASS and not live(state) and not members(UNIT):
            break
        if state.get('status', '').startswith('FAILED'):
            save(O/'state.json', dict(schema='ec-production-r6-host-area-queue/1', **identity(),
                status='PREREQUISITE_FAILED_NO_AREA_STARTED', updated_utc=now(),
                prerequisite=str(P/'failure.json'), fpga_access=False, full_system_fit=False))
            return
        save(O/'queue.json', dict(schema='ec-production-r6-host-area-queue/1', **identity(),
            status='WAITING_R6_PRECISE_TOKENS_AND_EXACT_CGROUP_RELEASE', updated_utc=now(),
            prerequisite=str(P/'state.json'), prerequisite_status=state.get('status'),
            no_CAD_started=True, own_CPU_affinity_unrestricted=True,
            hardware_commit=HARDWARE, experiment_commit=binding['experiment_commit'],
            source_binding_sha256=sha(C/'source-binding.json')))
        time.sleep(30)
    verify_binding()
    prerequisites(result)
    save(O/'validator-release.json', dict(utc=now(), unit=UNIT, members=[],
        validator_result_sha256=sha(P/'result.json')))
    p.m.ST.update(hardware_commit=HARDWARE, experiment_commit=binding['experiment_commit'],
        source_binding_sha256=sha(C/'source-binding.json'),
        validator_source_binding_sha256=sha(SOURCE/'source-binding.json'))
    p.main()


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', p.m.ST)
        else:
            O.mkdir(exist_ok=True)
            save(O/'preflight-failure.json', dict(utc=now(), error=repr(exc), no_CAD_started=True))
        raise
