#!/usr/bin/python3
"""Sole gated mixed73-output token/area continuation; no duplicate generation."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import re
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-common-stats-token-area-r3-20261113'
P = D/'build-logs/Opt4-common-stats-host-r6-20261113'
R5 = D/'build-logs/Opt4-common-stats-host-r5-20261113'
R1 = D/'build-logs/Opt4-common-stats-host-r1-20261113'
TREE = W/'Opt4-area-common-stats-token-area-r3-20261113'
UNIT = 'ec-opt4-common-stats-host-r6-20261113.service'
PASS = 'PASS_MIXED_HOST_BATCH_REMAP_AND_EXACT_HOST_GENERATION_TOKEN_VALIDATION_PENDING'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec); spec.loader.exec_module(value)
    return value


generation = module('original_mixed_host_generation', W/'candidates/common-stats-host-r6-20261113/controller.py')
m = generation.m
m.C, m.O, m.CPUS = C, O, {206, 207}
oracle = module('exact_mixed_target_oracle', C/'oracle.py'); oracle.O, oracle.m = O, m
oracle.save, oracle.sha = save, sha
runtime = module('exact_mixed_host_simulator', C/'runtime.py'); runtime.O, runtime.m = O, m
mapper = module('unchanged_serial_OOC_mapper', W/'candidates/address-banked-production-area-pair-r1-20261112/controller.py')
mapper.C, mapper.O, mapper.P = C, O, P
# Share state/resource admission with the actual token owner, without using the
# address-only prerequisites or public interface. CAD functions remain intact.
mapper.m = m


def verify_binding():
    binding = read(C/'source-binding.json')
    assert binding['hardware_changed'] is False
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE,
                                   text=True).strip() == binding['experiment_commit']
    for rel, h in binding['committed_files'].items():
        data = subprocess.check_output(['git', 'show', binding['experiment_commit']+':'+rel], cwd=TREE)
        assert hashlib.sha256(data).hexdigest() == h
    # Exact original oracle body, including SystemVerilog newline escaping.
    previous = (W/'candidates/common-stats-host-r2-20261113/controller.py').read_text()
    original_oracle = previous[previous.index('def ports('):previous.index('\ndef simulate(')]
    actual_oracle = 'def ports('+(C/'oracle.py').read_text().split('def ports(', 1)[1]
    assert actual_oracle == original_oracle
    original_runtime = previous[previous.index('def simulate('):previous.index('\ndef area(')]
    actual_runtime = 'def simulate('+(C/'runtime.py').read_text().split('def simulate(', 1)[1]
    assert actual_runtime == original_runtime
    old_driver = (W/'candidates/common-stats-host-r2-20261113/TestMixed.cc').read_text()
    old_boundary = '''      step(1);
      // step() reaches the requested cycle horizon. Each output channel may
      // still be producing its next registered token. The mpz peek overload
      // reads MMIO immediately, so first require the bridge's common precise
      // token boundary, then read all seven unchanged 64-bit expectations.
'''
    new_boundary = '''      // Inputs are poked before the precise public-token observation, as
      // validated by the production full3003-token oracle. Consume exactly
      // one target step after comparing all73 original output expectations.
'''
    reversed_driver = (C/'TestMixed.cc').read_text().replace(new_boundary, old_boundary)
    reversed_driver = reversed_driver.replace('        ++checked;\n      }\n      step(1);\n    }',
                                               '        ++checked;\n      }\n    }')
    assert reversed_driver == old_driver
    return binding


def accepted(path):
    receipt = read(path)
    assert receipt['accepted'] and receipt['returncode'] == 0 and not receipt['missing_outputs']
    assert sha(receipt['log']) == receipt['log_sha256']
    assert all(sha(name) == h for name, h in receipt['outputs'].items())
    return receipt


def same_bytes(first, second):
    assert first.stat().st_size == second.stat().st_size, (str(first), str(second))
    with first.open('rb') as a, second.open('rb') as b:
        while True:
            chunk = a.read(4*2**20)
            assert chunk == b.read(4*2**20), (str(first), str(second))
            if not chunk: break


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt this exact continuation owner'
    prior_unit = 'ec-opt4-common-stats-token-area-r2-20261113.service'
    assert not generation.members(prior_unit)
    prior = read(D/'build-logs/Opt4-common-stats-token-area-r2-20261113/recovery-handoff.json')
    assert prior['status'] == 'RELEASED_QUEUED_ONLY_FOR_DIAGNOSED_ORACLE_ENCODING_RECOVERY'
    binding = verify_binding()
    # Resolve each helper's actual globals before waiting or compiling.
    import builtins
    import symtable
    for helper_path, helper in [(C/'oracle.py', oracle), (C/'runtime.py', runtime)]:
        table = symtable.symtable(helper_path.read_text(), str(helper_path), 'exec')
        for function in table.get_children():
            missing = [symbol.get_name() for symbol in function.get_symbols()
                if symbol.is_referenced() and symbol.is_global()
                and symbol.get_name() not in vars(helper)
                and not hasattr(builtins, symbol.get_name())]
            assert not missing, (str(helper_path), function.get_name(), missing)
    save(O/'helper-global-resolution.json', dict(utc=now(), PASS=True,
        exact_predecessor_cgroup_released=True, oracle_IO_injected=True,
        hardware_stimulus_and_expectations_changed=False))
    # Wait without taking the predecessor's two CPU pins or compiling anything.
    while True:
        state, result = read(P/'state.json'), read(P/'result.json')
        if result.get('status') == PASS and not live(state) and not generation.members(UNIT):
            break
        if state.get('status', '').startswith('FAILED'):
            save(O/'state.json', dict(schema='ec-mixed-token-area-queue/1', **identity(),
                status='PREREQUISITE_FAILED_NO_TOKEN_OR_AREA_STARTED', updated_utc=now(),
                prerequisite=str(P/'failure.json'), fpga_access=False, full_system_fit=False))
            return
        save(O/'queue.json', dict(schema='ec-mixed-token-area-queue/1', **identity(),
            status='WAITING_EXACT_MIXED_GENERATED_HOSTS_AND_CGROUP_RELEASE', updated_utc=now(),
            prerequisite_status=state.get('status'), no_compile_or_CAD_started=True))
        time.sleep(30)
    verify_binding()
    assert result['experiment_commit'] == '26554222fceed33ebd05c9e2d90bd00bc31b33af'
    generation_binding = W/'candidates/common-stats-host-r6-20261113/source-binding.json'
    assert all(sha(path) == h for path, h in read(generation_binding)['files'].items())
    assert result['source_binding_sha256'] == sha(generation_binding)
    os.sched_setaffinity(0, {206, 207}); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-complete-mixed-token-serial-area/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        experiment_commit=binding['experiment_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=[206, 207], memory_limit_gib=64, fpga_access=False, whole_EC_CAD=False,
        full_system_fit=False, hardware_changed=False, production_admission=False,
        scope='Actual full256 mixed64bank one-type caller Plain/Threaded73-output3003-token and serial OOC area. No whole EC/caller functional equivalence, DCache or shell FIT claim.')
    m.update('ADOPTING_COMPLETED_MIXED_HOSTS')
    save(O/'predecessor-release.json', dict(utc=now(), unit=UNIT, members=[],
        result=str(P/'result.json'), result_sha256=sha(P/'result.json')))
    save(O/'admission.json', m.admission())
    pins = dict(binding['files']); pins[str(C/'source-binding.json')] = sha(C/'source-binding.json')
    equivalence = {}
    for name in ['Threaded', 'Plain']:
        accepted(P/('goldengate-'+name+'-receipt.json'))
        audit = read(P/(name+'-threading-audit.json'))
        assert audit['selected_instances'] == 64 and audit['selected_types'] == ['StatsBank']
        assert audit['public_outputs'] == 73 and not audit['proof_outputs']
        assert audit['host_RTL_sha256'] == sha(P/name/'FireSim-generated.sv')
        assert 'Skipping Combinational Loop Detection' not in (P/('goldengate-'+name+'.log')).read_text()
        for path in (P/name).iterdir():
            if path.is_file(): pins[str(path)] = sha(path)
    for filename in ['post-gen-sram-models.fir', 'post-fame-transform.fir', 'post-sim-mapping.fir']:
        first, second = R5/'Threaded'/filename, P/'Threaded'/filename
        same_bytes(first, second)
        equivalence[filename] = dict(byte_equal=True, bytes=first.stat().st_size, sha256=sha(first))
    save(O/'compiler-circuit-identity.json', dict(circuits=equivalence,
        old_failed_annotation_remap_only=True, annotation_checks_preserved=True,
        stock288_batch_tests_sha256=sha(P/'batch-remap-semantic-regression-receipt.json')))
    # Reuse the exact already compiled emitter; this is the sole target-oracle
    # elaboration, not another GoldenGate host or proof-port generation.
    receipt = accepted(P/'goldengate-Threaded-receipt.json')
    cp = receipt['argv'][receipt['argv'].index('-cp')+1]
    cfg = read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    target = O/'Target-oracle'; target.mkdir()
    m.stage('elaborate-token-target', [cfg['java'], '-Xmx24G', '-Xss32M', '-XX:ActiveProcessorCount=2',
        '-cp', cp, 'commonstatshost.Emit', target], [target/'MixedTarget.v'])
    trace = oracle.oracle(target/'MixedTarget.v')
    pins[str(trace)] = sha(trace); pins[str(O/'trace-ports.h')] = sha(O/'trace-ports.h')
    save(O/'inputs.json', dict(files=pins))
    tokens = {}
    for name in ['Threaded', 'Plain']:
        host = O/(name+'-simulation'); host.mkdir()
        source = P/name
        for path in source.iterdir():
            if path.is_file(): (host/path.name).symlink_to(path)
        tokens[name] = runtime.simulate(host, name, trace)
        save(O/'token-progress.json', tokens)
    assert tokens['Threaded']['digest'] == tokens['Plain']['digest']
    assert all(row['target_tokens'] == 3003 and row['checked_outputs'] == 219000 for row in tokens.values())
    save(O/'host-validation.json', dict(tokens=tokens, target_tokens=3003, public_outputs=73,
        source_binding_sha256=sha(C/'source-binding.json'), full_formal=False, whole_EC_equivalence=False))
    # The original mapper checks exact directives, completed compatible DCPs,
    # identical live maps, no blackboxes and real current resource admission.
    hosts = {name: mapper.prepare_host(name) for name in ['Plain', 'Threaded']}
    measured = {}
    for name, (host, signature) in hosts.items():
        measured[name] = mapper.map_or_reuse(host, name, signature)
        save(O/'paired-progress.json', measured)
    savings = {key: measured['Plain']['resources'][key]-measured['Threaded']['resources'][key]
               for key in measured['Plain']['resources']}
    verify_binding()
    assert all(sha(path) == h for path, h in pins.items())
    m.update('COMPLETE_MIXED_ROLE_HOST_TOKENS_AND_AREA_PAIR_NOT_WHOLE_EC',
        tokens=tokens, area=measured, savings=savings, ended_utc=now(), full_formal=False,
        next='Choose next structure from actual compatible same-scope area. Material gain still requires exact caller/frozenDCache/completehost/ABI and complete shell postopt before physical certification or card21 IO.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        else:
            O.mkdir(exist_ok=True)
            save(O/'preflight-failure.json', dict(utc=now(), error=repr(exc), no_CAD_started=True))
        raise
