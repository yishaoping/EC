#!/usr/bin/python3
"""Reuse completed threaded tokens; recover Plain's missing output directory."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-host-r6-20261113'
P = D/'build-logs/Opt4-address-banked-production-host-r5-20261113'
R2 = D/'build-logs/Opt4-address-banked-production-host-r2-20261113'
R1 = D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
TREE = W/'Opt4-area-address-production-host-r6-20261113'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

spec = importlib.util.spec_from_file_location('precise_token_validator',
    W/'candidates/address-banked-production-host-r5-20261113/controller.py')
old = importlib.util.module_from_spec(spec); spec.loader.exec_module(old)
m = old.m
m.C, m.O, old.old.C, old.old.O = C, O, C, O


def verify_binding():
    binding = read(C/'source-binding.json')
    assert binding['hardware_changed'] is False
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE,
                                   text=True).strip() == binding['experiment_commit']
    for rel, h in binding['committed_files'].items():
        data = subprocess.check_output(['git', 'show', binding['experiment_commit']+':'+rel], cwd=TREE)
        assert hashlib.sha256(data).hexdigest() == h
    assert sha(C/'TestComplete.cc') == sha(old.C/'TestComplete.cc')
    return binding


def accepted(path, negative=False):
    receipt = read(path)
    assert receipt['accepted'] and not receipt['missing_outputs']
    assert receipt['negative'] == negative and (receipt['returncode'] != 0) == negative
    assert sha(receipt['log']) == receipt['log_sha256']
    assert all(sha(name) == h for name, h in receipt['outputs'].items())
    return receipt


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt this exact recovery owner'
    units = ['ec-opt4-address-banked-production-host-r5-20261113.service',
             'ec-opt4-address-banked-production-area-pair-r4-20261113.service']
    assert not any(old.old.members(unit) for unit in units)
    binding = verify_binding()
    failure = read(P/'failure.json')
    assert failure['active_stage'] == 'goldengate-Plain'
    failure_log = (P/'goldengate-Plain.log').read_text()
    assert 'FileNotFoundException' in failure_log
    assert str(P/'Plain/post-bridge-extraction.fir')+' (No such file or directory)' in failure_log
    parent_pins = read(P/'inputs.json')['files']
    assert all(sha(path) == h for path, h in parent_pins.items())
    os.sched_setaffinity(0, {212, 213}); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-production-plain-directory-recovery/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        experiment_commit=binding['experiment_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=[212, 213], memory_limit_gib=64, fpga_access=False, no_CAD=True, full_system_fit=False,
        hardware_changed=False, reused_exact_target_and_threaded_host=True,
        finite_target_parity_reused=True, host_area_gain_unknown=True,
        scope='Directory-only Plain generation recovery; full threaded3003-token positive/negative receipts reused, complete Plain oracle unchanged. No area or FIT claim.')
    m.update('ADMITTING_DIRECTORY_ONLY_PLAIN_RECOVERY')
    save(O/'predecessor-release.json', dict(utc=now(), units=units, members=[],
        failure_sha256=sha(P/'failure.json'), failure_log_sha256=sha(P/'goldengate-Plain.log')))
    save(O/'admission.json', m.admission())
    pins = dict(binding['files']); pins[str(C/'source-binding.json')] = sha(C/'source-binding.json')
    save(O/'inputs.json', dict(files=pins))
    for name in ['full-target-parity', 'full-target-negative']:
        accepted(R1/(name+'-receipt.json'), 'negative' in name)
    for name in ['token-oracle-Threaded', 'token-negative-Threaded']:
        accepted(P/(name+'-receipt.json'), 'negative' in name)
        for suffix in ['.log', '-receipt.json']:
            (O/(name+suffix)).symlink_to(P/(name+suffix))
    tokens = read(P/'token-progress.json')
    assert set(tokens) == {'Threaded'}
    assert tokens['Threaded']['target_tokens'] == 3003
    assert tokens['Threaded']['checked_outputs'] == 156000
    (O/'Threaded').symlink_to(P/'Threaded', target_is_directory=True)
    (O/'trace-ports.h').symlink_to(P/'trace-ports.h')
    save(O/'reused-threaded-validation.json', dict(tokens=tokens['Threaded'],
        positive_receipt_sha256=sha(P/'token-oracle-Threaded-receipt.json'),
        negative_receipt_sha256=sha(P/'token-negative-Threaded-receipt.json'),
        model_archive_sha256=sha(P/'Threaded/VCompleteAddressStats.csrc/Vemul__ALL.a'),
        recompiled=False, rerun=False, RTL_regenerated=False))
    save(O/'token-progress.json', tokens)
    plain = O/'Plain'; plain.mkdir()
    failed = read(P/'goldengate-Plain-receipt.json')
    argv = failed['argv'][:]
    assert argv[argv.index('-td')+1] == str(P/'Plain')
    argv[argv.index('-td')+1] = str(plain)
    save(O/'plain-directory-recovery.json', dict(old_argv=failed['argv'], argv=argv,
        only_output_directory_changed=True, directory_created_before_GoldenGate=plain.is_dir(),
        failed_receipt_sha256=sha(P/'goldengate-Plain-receipt.json')))
    m.stage('goldengate-Plain', argv, [plain/'FireSim-generated.sv', plain/'FireSim-generated.synthesis.xdc'])
    assert 'Skipping Combinational Loop Detection' not in (O/'goldengate-Plain.log').read_text()
    old.old.link_inputs(plain, O/'Plain-linked')
    trace = R1/'positive-reference-public-tokens.txt'
    assert len(trace.read_text().splitlines()) == 3003
    tokens['Plain'] = old.old.simulate(O/'Plain-linked', 'Plain', trace)
    assert tokens['Plain']['target_tokens'] == 3003 and tokens['Plain']['checked_outputs'] == 156000
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    verify_binding()
    assert all(sha(path) == h for path, h in pins.items())
    m.update('PASS_PRODUCTION_HOST_PRECISE_3003_TOKEN_ORACLE_AND_PLAIN_THREADED_PARITY_NO_AREA',
        tokens=tokens, target_tokens=3003, public_outputs=52, target_cycles=6144, monitor_outputs=5684,
        geometry=dict(banks=16, lanes=16, slots=256), full_formal=False, ended_utc=now(),
        next='One exact serial area successor after full validator cgroup release. Complete source/caller/DCache/host/ABI/shell certification gates remain mandatory.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
