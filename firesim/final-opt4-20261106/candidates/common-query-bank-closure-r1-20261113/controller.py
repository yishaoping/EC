#!/usr/bin/python3
"""Close the measured selector against every actual common-bank state cone.

Deterministic, isolated bank validation. No host/whole-CAD or board IO.
"""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-common-query-bank-closure-r1-20261113'
T = W / 'Opt4-area-common-query-bank-closure-r1-20261113'
Q = D / 'build-logs/Opt4-common-query-select-r1-20261113'
P = D / 'build-logs/Opt4-common-stats-transition-proof-r1-20261113'
R = 'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ecstatscommon/'
CPUS = {204, 205}
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


m = load('query_closure_stages', W / 'candidates/address-histogram-fame5-r6-20261112/controller.py')
m.C, m.O, m.CPUS = C, O, CPUS
b = load('query_closure_bank_harness', W / 'candidates/common-stats-bank-r3-20261113/controller.py')
b.TREE, b.O, b.m = T, O, m
p = load('query_closure_cones', W / 'candidates/common-stats-transition-proof-r1-20261113/controller.py')
original_stage = m.stage


def stage(name, argv, outputs=(), cwd=None, **kwargs):
    assert cwd is None or Path(cwd) == O
    original_stage(name, argv, outputs, **kwargs)
    return O / (name + '.log')


m.stage = stage


def members(unit):
    found = []
    for path in Path('/proc').iterdir():
        if not path.name.isdigit():
            continue
        try:
            if any(line.split(':', 2)[-1].endswith('/' + unit) or
                   ('/' + unit + '/') in line.split(':', 2)[-1]
                   for line in (path / 'cgroup').read_text().splitlines()):
                found.append(identity(int(path.name)))
        except OSError:
            pass
    return found


def extract(rtl, name, top):
    script = O / (name + '.ys')
    script.write_text(f'read_verilog -sv {rtl}\nhierarchy -top {top}\nproc\nopt_clean\nwrite_json {O}/{name}.json\n')
    m.stage(name, ['/usr/local/bin/yosys', '-Q', '-T', '-s', script],
            [O / (name + '.json')])
    return read(O / (name + '.json'))['modules']


def compare_state_and_queries(current, contract):
    previous = read(P / 'state-boundary.json')['modules']['StatsBankProof']
    old = p.Cones(previous, 'common')
    new = p.Cones(current['StatsBankProof'], 'common')
    expected, actual = old.transitions(), new.transitions()
    assert set(expected) == set(actual)
    unequal = [k for k in expected if expected[k] != actual[k]]
    save(O / 'transition-comparison.json', dict(state_bits=len(expected),
         exact_equal=len(expected)-len(unequal), unequal=unequal,
         arbitrary_state_and_inputs=True,
         expected_digest=p.digest(sorted((list(k), v) for k, v in expected.items())),
         actual_digest=p.digest(sorted((list(k), v) for k, v in actual.items()))))
    assert not unequal, ('changed next-state cone', unequal[:10])
    assert old.initial() == new.initial(), 'Initialization changed'
    expected_out, actual_out = old.outputs(), new.outputs()
    assert set(expected_out) == set(actual_out)
    queries = {('address', f'io_queryMatch_{q}') for q in range(88)}
    assert queries.issubset(expected_out)
    unequal_out = [k for k in expected_out if k not in queries and expected_out[k] != actual_out[k]]
    assert not unequal_out, ('changed non-query output', unequal_out[:10])
    # The already-proved arbitrary-state Contract has exactly two Boolean
    # branches. Bind its inputs to each actual bank's state and query port,
    # then require bit-exact generated cone isomorphism on both sides.
    # This lifts the SAT proof through every actual generated query replica.
    cm = contract['Contract']
    checks = []
    for q in range(88):
        c = p.Cones(cm, 'common')
        for name, port in cm['ports'].items():
            if port['direction'] != 'input':
                continue
            for i, bit in enumerate(port['bits']):
                if name.startswith('io_valid_'):
                    lane = int(name.rsplit('_', 1)[1])
                    c.leaves[bit] = p.digest(['state', 'address', f'bucketValid_{lane}', i])
                elif name.startswith('io_seq_'):
                    lane = int(name.rsplit('_', 1)[1])
                    c.leaves[bit] = p.digest(['state', 'address', f'bucketSeq_{lane}', i])
                elif name == 'io_query':
                    c.leaves[bit] = p.digest(['input', 'address', f'io_querySeq_{q}', i])
                elif name == 'io_base':
                    c.leaves[bit] = p.digest(['input', 'address', 'io_base', i])
                else:
                    assert name in ['clock', 'reset'], name
        cell, port, index = c.drivers[cm['ports']['io_same']['bits'][0]]
        assert cell['type'] == '$eq' and port == 'Y' and index == 0
        ah = p.digest([c.h(bit) for bit in cell['connections']['A']])
        bh = p.digest([c.h(bit) for bit in cell['connections']['B']])
        key = ('address', f'io_queryMatch_{q}')
        assert expected_out[key] == ah, ('reference query cone differs from SAT contract', q)
        assert actual_out[key] == bh, ('candidate query cone differs from SAT contract', q)
        checks.append(dict(query=q, reference_cone=ah, candidate_cone=bh))
    save(O / 'output-comparison.json', dict(
        outputs=len(expected_out), exact_unchanged_outputs=len(expected_out)-88,
        arbitrary_state_query_SAT_lifts=checks,
        local_SAT_contract=str(Q / 'query-contract.json'),
        local_SAT_contract_sha256=sha(Q / 'query-contract.json'),
        all_state_bits_compared=len(expected), no_state_assumption=True,
        initial_state_equal=True, clock_reset_transition_controls_equal=True))
    return dict(state_bits=len(expected), exact_next_state_cones=len(expected),
                public_and_proof_outputs=len(expected_out), SAT_query_replicas=88,
                exact_nonquery_outputs=len(expected_out)-88,
                arbitrary_state_and_inputs=True, local_bank_only=True)


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt existing owner'
    unit = 'ec-opt4-common-query-select-r1-20261113.service'
    assert not members(unit), 'Preserve exact predecessor until cgroup release'
    save(O / 'predecessor-release.json', dict(unit=unit, members=[], utc=now()))
    os.sched_setaffinity(0, CPUS)
    resource.setrlimit(resource.RLIMIT_AS, (32 * 2**30,) * 2)
    binding = read(C / 'source-binding.json')
    assert all(sha(path) == h for path, h in binding['files'].items())
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T, text=True).strip()
    assert commit == binding['hardware_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show', commit + ':' + rel], cwd=T)).hexdigest() == h
    m.ST.update(schema='ec-query-full-bank-closure/1', **identity(), started_utc=now(),
        hardware_commit=commit, hardware_source_parent=binding['hardware_source_parent'],
        functional_baseline=binding['functional_baseline'], cpus=sorted(CPUS),
        memory_limit_gib=32, fpga_access=False, no_CAD=True,
        production_admission=False, full_system_fit=False,
        source_binding_sha256=sha(C / 'source-binding.json'),
        scope='Actual16-lane common bank finite all-state miter and arbitrary-state generated next-state/output-cone closure of measured query selector; no complete caller, host, whole EC or shell claim.')
    m.update('ADMITTING_EXACT_QUERY_BANK_CLOSURE')
    save(O / 'admission.json', m.admission())
    query_receipt = read(Q / 'compile-query-and-production-bank-receipt.json')
    assert query_receipt['accepted'] and all(sha(path) == h for path, h in query_receipt['outputs'].items())
    assert read(Q / 'arbitrary-query-contract-receipt.json')['accepted']
    assert read(Q / 'negative-inverted-match-receipt.json')['accepted']
    assert sha(Q / 'Contract/Contract.v') == read(Q / 'query-contract.json')['proof_RTL_sha256']
    assert read(P / 'result.json')['status'] == 'PASS_EXACT_COMMON_BANK_STATE_TRANSITION_AND_OUTPUT_CONES'
    assert sha(P / 'state-boundary.json') == read(P / 'result.json')['netlist_sha256']
    cfg = read(W / 'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java = [cfg['java'], '-Xmx12G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    prod = D / 'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
    composed = D / 'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    base = ':'.join(map(str, [Q / 'classes', prod, composed])) + ':' + ':'.join(cfg['classpath'])
    save(O / 'reused-query-production-classes.json', dict(
        receipt=str(Q / 'compile-query-and-production-bank-receipt.json'),
        receipt_sha256=sha(Q / 'compile-query-and-production-bank-receipt.json'),
        files={str(path): sha(path) for path in (Q / 'classes').rglob('*.class')},
        source_helper_sha256=sha(T / R / 'BankTagRead.scala'),
        source_bank_sha256=sha(T / R / 'StatsBank.scala')))
    proof_sources = b.proof_sources()
    classes = O / 'proof-classes'
    classes.mkdir()
    m.stage('compile-full-bank-miter', java + ['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', base, '-Xplugin:' + cfg['plugin'],
        '-d', classes] + proof_sources, [classes / 'commonbanktest/Emit.class'])
    target = O / 'target'
    target.mkdir()
    m.stage('emit-full-bank-miter', java + ['-cp', str(classes) + ':' + base,
        'commonbanktest.Emit', target], [target / 'Pair.v'])
    b.target_test(target / 'Pair.v')
    current = extract(target / 'Pair.v', 'bank-state-boundary', 'Pair')
    contract = extract(Q / 'Contract/Contract.v', 'query-contract-boundary', 'Contract')
    proof = compare_state_and_queries(current, contract)
    assert all(sha(path) == h for path, h in binding['files'].items())
    m.update('PASS_QUERY_BANK_ALL_STATE_FINITE_AND_GENERATED_TRANSITION_CONTRACT',
        child={}, ended_utc=now(), proof=proof, cycles=8192,
        finite_validation=str(O / 'target-validation.json'),
        finite_validation_sha256=sha(O / 'target-validation.json'),
        local_bank_transition_equivalence=True, complete_caller_equivalence=False,
        host_equivalence=False, whole_EC_equivalence=False,
        next='Use bank closure with material mixed-host area/token receipt; source-composed complete caller/frozen-DCache/host/ABI and complete-shell capacity remain required. No standalone whole build from65111query-plane saving.')
    save(O / 'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O / 'failure.json', m.ST)
        raise
