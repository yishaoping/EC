#!/usr/bin/python3
"""Finite deterministic proof and full-size combinational query area pair.

No whole EC CAD, host transform, board IO, or intelligent supervision.
"""
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
O = D / 'build-logs/Opt4-common-query-select-r1-20261113'
T = W / 'Opt4-area-common-query-select-r1-20261113'
R = 'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ecstatscommon/'
CPUS = {204, 205}
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

spec = importlib.util.spec_from_file_location('query_screen_stage_tools',
    W / 'candidates/address-histogram-fame5-r6-20261112/controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.C, m.O, m.CPUS = C, O, CPUS
spec = importlib.util.spec_from_file_location('query_screen_resources',
    W / 'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
parser = importlib.util.module_from_spec(spec)
spec.loader.exec_module(parser)


def members(unit):
    found = []
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():
            continue
        try:
            if any(l.split(':', 2)[-1].endswith('/' + unit)
                   for l in (p / 'cgroup').read_text().splitlines()):
                found.append(identity(int(p.name)))
        except OSError:
            pass
    return found


def prove(rtl):
    prefix = f'read_verilog -sv {rtl}\nprep -top Contract\nflatten\nopt_clean\ncheck -assert\n'
    script = O / 'query-contract.ys'
    script.write_text(prefix + 'sat -verify -timeout 180 -prove io_same 1 -show-inputs -show-outputs\n')
    m.stage('arbitrary-query-contract', ['/usr/local/bin/yosys', '-Q', '-T', '-s', script],
            marker='SAT proof finished - no model found: SUCCESS!')
    negative = O / 'query-negative.ys'
    negative.write_text(prefix + 'sat -timeout 60 -prove io_same 0 -show-inputs -show-outputs\n')
    m.stage('negative-inverted-match', ['/usr/local/bin/yosys', '-Q', '-T', '-s', negative],
            marker='SAT proof finished - model found: FAIL!')
    save(O / 'query-contract.json', dict(
        arbitrary_full_32bit_sequence_state=True, arbitrary_valid_state=True,
        arbitrary_8bit_base_and_32bit_query=True, aligned_base_not_assumed=True,
        invalid_payload_unconstrained=True, negative_inverted_equality_rejected=True,
        lanes=16, template_repeated_queries=88, production_banks=16,
        source_helper_sha256=sha(T / R / 'BankTagRead.scala'),
        proof_RTL_sha256=sha(rtl), local_combinational_only=True,
        whole_EC_equivalence=False))


def area(rtl, name):
    save(O / (name + '-admission.json'), m.admission())
    target = rtl.parent
    script = target / 'map.tcl'
    script.write_text('set_param general.maxThreads 2\n' +
        f'read_verilog -sv {{{rtl}}}\n' +
        'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n' +
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n' +
        f'report_utilization -file {{{target}/utilization.rpt}}\n' +
        f'report_utilization -hierarchical -file {{{target}/hierarchical.rpt}}\n' +
        f'write_checkpoint -force {{{target}/query.dcp}}\nexit 0\n')
    pins = {str(p): sha(p) for p in [rtl, script]}
    save(O / (name + '-map-inputs.json'), dict(files=pins))
    m.stage('map-' + name, ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch',
            '-nojournal', '-log', target / 'vivado.log', '-source', script],
            [target / 'utilization.rpt', target / 'hierarchical.rpt', target / 'query.dcp'])
    assert all(sha(p) == h for p, h in pins.items())
    total = parser.parse_total((target / 'utilization.rpt').read_text())
    parser.parse_hier((target / 'hierarchical.rpt').read_text(), total)
    parser.crosschecks((target / 'utilization.rpt').read_text(), total)
    return dict(resources={k: v['used'] for k, v in total.items()},
        files={str(target / p): sha(target / p) for p in
               ['utilization.rpt', 'hierarchical.rpt', 'query.dcp']})


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt exact existing owner'
    prior = 'ec-opt4-common-stats-transition-proof-r1-20261113.service'
    assert not members(prior)
    save(O / 'predecessor-release.json', dict(unit=prior, members=[], utc=now()))
    os.sched_setaffinity(0, CPUS)
    resource.setrlimit(resource.RLIMIT_AS, (32 * 2**30,) * 2)
    binding = read(C / 'source-binding.json')
    assert all(sha(p) == h for p, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T, text=True).strip() == binding['hardware_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show',
            binding['hardware_commit'] + ':' + rel], cwd=T)).hexdigest() == h
    # The only production edit replaces the query expression; all registers,
    # state-update priorities, reset, overflow and feedback bytes are unchanged.
    bank = (T / R / 'StatsBank.scala').read_text()
    replacement = '''    io.queryMatch(q) := BankTagRead.matches(
      bucketValid.toSeq, bucketSeq.toSeq, io.base, io.querySeq(q))'''
    original = '''    io.queryMatch(q) := (0 until 16).map(i =>
      io.querySeq(q)(7, 0) === keys(i) && bucketValid(i) &&
      bucketSeq(i)(31, 8) === io.querySeq(q)(31, 8)).reduce(_ || _)'''
    parent = subprocess.check_output(['git', 'show', binding['parent_commit'] + ':' +
                                     R + 'StatsBank.scala'], cwd=T, text=True)
    assert bank.count(replacement) == 1 and bank.replace(replacement, original) == parent
    save(O / 'production-source-audit.json', dict(
        restored_parent_sha256=hashlib.sha256(parent.encode()).hexdigest(),
        only_query_expression_changed=True, target_state_and_update_bytes_unchanged=True,
        added_target_registers=0, added_target_cycles=0))
    m.ST.update(schema='ec-common-query-full-size-screen/1', **identity(),
        started_utc=now(), functional_baseline=binding['functional_baseline'],
        hardware_commit=binding['hardware_commit'], source_binding_sha256=sha(C / 'source-binding.json'),
        cpus=sorted(CPUS), memory_limit_gib=32, fpga_access=False,
        production_slots=256, lanes=16, banks=16, queries=88, full_system_fit=False,
        host_equivalence=False, production_admission=False,
        scope='Full256-slot88-query combinational state-cut production query plane. Local arbitrary-state selector contract. Not complete AddressStats, host area or shell FIT.')
    m.update('VERIFYING_IMMUTABLE_QUERY_SCREEN_INPUTS')
    save(O / 'admission.json', m.admission())
    cfg = read(W / 'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java = [cfg['java'], '-Xmx12G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    classes = O / 'classes'
    classes.mkdir()
    composed = D / 'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    prod = D / 'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
    prior_validation = read(D / 'build-logs/Opt4-common-stats-bank-r3-20261113/reused-production-classes.json')
    assert all(sha(p) == h for p, h in prior_validation['files'].items())
    base = ':'.join(map(str, [prod, composed])) + ':' + ':'.join(cfg['classpath'])
    m.stage('compile-query-and-production-bank', java + ['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', base, '-Xplugin:' + cfg['plugin'], '-d', classes,
        T / R / 'BankTagRead.scala', T / R / 'StatsBank.scala', C / 'Query.scala'],
        [classes / 'ecstatscommon/StatsBank.class', classes / 'ecstatscommon/BankTagRead.class',
         classes / 'commonqueryscreen/Emit.class'])
    cp = str(classes) + ':' + base
    for name in ['Contract', 'Reference', 'Candidate']:
        target = O / name
        target.mkdir()
        rtl = target / (name + '.v')
        m.stage('elaborate-' + name, java + ['-cp', cp, 'commonqueryscreen.Emit', name, target], [rtl])
        if name == 'Contract':
            prove(rtl)
    measured = {}
    for name in ['Reference', 'Candidate']:
        measured[name] = area(O / name / (name + '.v'), name)
        save(O / 'paired-progress.json', measured)
    assert all(sha(p) == h for p, h in binding['files'].items())
    savings = {k: measured['Reference']['resources'][k] - measured['Candidate']['resources'][k]
               for k in measured['Reference']['resources']}
    m.update('COMPLETE_FULL_SIZE_QUERY_CONTRACT_AND_AREA_NOT_WHOLE_MODULE',
        ended_utc=now(), area=measured, savings=savings,
        next='Use actual projected query-plane gain to choose source version. Full bank/target/host/ABI/DCache validation still required; no automatic whole build.')
    save(O / 'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O / 'failure.json', m.ST)
        raise
