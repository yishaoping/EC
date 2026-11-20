#!/usr/bin/python3
"""Immutable production-size delta-plane experiment; no host CAD or board IO."""
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
O = D / 'build-logs/Opt4-common-delta-csa-r1-20261113'
T = W / 'Opt4-area-common-delta-csa-r1-20261113'
R = 'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ecstatscommon/'
CPUS = {222, 223}
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

spec = importlib.util.spec_from_file_location('delta_stage_tools',
    W / 'candidates/address-histogram-fame5-r6-20261112/controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.C, m.O, m.CPUS = C, O, CPUS
spec = importlib.util.spec_from_file_location('delta_resources',
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


def width_audit():
    # Unlike a reachable-input assumption, these maxima allow every encoded
    # scatter word, including patterns not produced by valid source counts.
    traces = []
    for bound in [32, 12, 8, 4]:
        leaf_width = bound.bit_length()
        nodes = [(bound, 2 ** leaf_width - 1, 1)] * 20
        trace = []
        while len(nodes) > 1:
            next_nodes = []
            for start in range(0, len(nodes), 2):
                pair = nodes[start:start + 2]
                if len(pair) == 1:
                    next_nodes += pair
                    continue
                nominal = sum(n[0] for n in pair)
                maximum = sum(n[1] for n in pair)
                leaves = sum(n[2] for n in pair)
                width = nominal.bit_length()
                root = leaves == 20
                assert root or maximum < 2 ** width
                trace.append(dict(leaves=leaves, width=width,
                    encoded_maximum=maximum, truncates_only_at_root=root))
                next_nodes.append((nominal, min(maximum, 2 ** width - 1), leaves))
            nodes = next_nodes
        traces.append(dict(scatter_nominal_bound=bound, scatter_width=leaf_width,
            terms=20, final_width=(20 * bound).bit_length(), reductions=trace))
    return dict(arbitrary_encoded_scatter_words=True, input_range_assumptions=[],
        nonroot_original_additions_exact=True, final_addition_modulo_only=True,
        compressor_congruence_applies_by_induction=True, traces=traces,
        limit='Static width certificate plus SAT of actual compressor template; not a full-bank transition or full-caller proof.')


def prove(rtl):
    prefix = f'read_verilog -sv {rtl}\nprep -top CompressorContracts\nflatten\nopt_clean\ncheck -assert\n'
    script = O / 'compressor-contract.ys'
    script.write_text(prefix + 'sat -verify -timeout 180 -prove io_same 1 -show-inputs -show-outputs\n')
    m.stage('compressor-contract', ['/usr/local/bin/yosys', '-Q', '-T', '-s', script],
            marker='SAT proof finished - no model found: SUCCESS!')
    negative = O / 'compressor-negative.ys'
    negative.write_text(prefix + 'sat -timeout 60 -prove io_same 0 -show-inputs -show-outputs\n')
    m.stage('compressor-negative', ['/usr/local/bin/yosys', '-Q', '-T', '-s', negative],
            marker='SAT proof finished - model found: FAIL!')
    save(O / 'arithmetic-contract.json', dict(widths=[7, 8, 10],
        arbitrary_operand_bits=True, local_three_to_two_compressor_SAT_PASS=True,
        inverted_equality_negative_rejected=True, full_bank_transition_proof=False,
        generated_RTL_sha256=sha(rtl), width_certificate_sha256=sha(O / 'tree-width-certificate.json')))


def finite_reduce(rtl):
    lines = ['module tb;', 'reg clock=0,reset=0;',
        "reg [63:0] rng=64'h8491167d84b6d952;", 'integer i;', 'wire io_same;']
    lines += [f'reg [9:0] io_terms_{i}=0;' for i in range(20)]
    ports = ['.clock(clock)', '.reset(reset)', '.io_same(io_same)'] + [
        f'.io_terms_{i}(io_terms_{i})' for i in range(20)]
    lines += ['ReductionChecks dut('+','.join(ports)+');', 'initial begin',
        'for(i=0;i<8192;i=i+1)begin']
    for j in range(20):
        lines += ['rng=rng^(rng<<13);rng=rng^(rng>>7);rng=rng^(rng<<17);',
            f'io_terms_{j}=(i==0)?0:((i==1)?1023:((i==2)?(1<<({j}%10)):rng[9:0]));']
    lines += ['#1;if(io_same!==1)begin $display("REDUCTION_MISMATCH i=%0d",i);$finish_and_return(1);end',
        'end $display("ACTUAL_20_TERM_REDUCTION_PASS cases=8192 geometries=4");$finish;end endmodule']
    tb = O / 'reduction-tb.v'
    tb.write_text('\n'.join(lines)+'\n')
    exe = O / 'reduction.vvp'
    m.stage('compile-reduction-check', ['/usr/bin/iverilog', '-g2012', '-s', 'tb', '-o', exe, rtl, tb], [exe])
    m.stage('finite-actual-reduction', ['/usr/bin/vvp', exe],
        marker='ACTUAL_20_TERM_REDUCTION_PASS cases=8192 geometries=4')
    save(O / 'reduction-finite.json', dict(cases=8192, geometries=4,
        actual_production_reducer=True, all_encoded_operand_patterns_allowed=True,
        finite_only=True, generated_RTL_sha256=sha(rtl), testbench_sha256=sha(tb)))


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
        f'write_checkpoint -force {{{target}/delta.dcp}}\nexit 0\n')
    pins = {str(p): sha(p) for p in [rtl, script]}
    save(O / (name + '-map-inputs.json'), dict(files=pins))
    m.stage('map-' + name, ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch',
            '-nojournal', '-log', target / 'vivado.log', '-source', script],
            [target / 'utilization.rpt', target / 'hierarchical.rpt', target / 'delta.dcp'])
    assert all(sha(p) == h for p, h in pins.items())
    total = parser.parse_total((target / 'utilization.rpt').read_text())
    parser.parse_hier((target / 'hierarchical.rpt').read_text(), total)
    parser.crosschecks((target / 'utilization.rpt').read_text(), total)
    return dict(resources={k: v['used'] for k, v in total.items()},
        files={str(target / p): sha(target / p) for p in
               ['utilization.rpt', 'hierarchical.rpt', 'delta.dcp']})


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt existing owner'
    prior = 'ec-opt4-address-histogram-fame5-r6-20261112.service'
    assert not members(prior)
    save(O / 'predecessor-release.json', dict(unit=prior, members=[], utc=now()))
    os.sched_setaffinity(0, CPUS)
    resource.setrlimit(resource.RLIMIT_AS, (64 * 2**30,) * 2)
    binding = read(C / 'source-binding.json')
    assert all(sha(p) == h for p, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T, text=True).strip() == binding['hardware_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show',
            binding['hardware_commit'] + ':' + rel], cwd=T)).hexdigest() == h
    parent = subprocess.check_output(['git', 'show', binding['parent_commit'] + ':' +
                                     R + 'AddressBucketGrouped.scala'], cwd=T, text=True)
    expected_reference = parent.replace('package ecstatscommon', 'package deltacsa', 1).replace(
        'object AddressBucketGrouped', 'object ReferenceGrouped', 1)
    assert (C / 'ReferenceGrouped.scala').read_text() == expected_reference
    helper = (T / R / 'AddressBucketGrouped.scala').read_text()
    start, end = helper.index('  private def sum('), helper.index('\n  def histogram(')
    restored = (helper[:start] + helper[end:]).replace(
        'private def balancedSum', 'private def sum').replace(
        'else balancedSum(xs.grouped', 'else sum(xs.grouped').replace(
        '\n\n\n  def histogram', '\n\n  def histogram')
    assert restored == parent, 'Only the production reduction may change'
    bank = T / R / 'StatsBank.scala'
    assert bank.read_bytes() == subprocess.check_output(['git', 'show',
        binding['parent_commit'] + ':' + R + 'StatsBank.scala'], cwd=T)
    m.ST.update(schema='ec-production-size-delta-csa-screen/1', **identity(),
        started_utc=now(), functional_baseline=binding['functional_baseline'],
        hardware_commit=binding['hardware_commit'], source_binding_sha256=sha(C / 'source-binding.json'),
        cpus=sorted(CPUS), memory_limit_gib=64, fpga_access=False,
        slots=256, banks=16, lanes=16, strict_sources=80, load_sources=8, store_sources=8,
        added_target_cycles=0, full_system_fit=False, host_equivalence=False,
        production_admission=False, scope=binding['scope'])
    m.update('VERIFYING_NEW_IMMUTABLE_DELTA_IMPLEMENTATION')
    save(O / 'tree-width-certificate.json', width_audit())
    save(O / 'production-source-audit.json', dict(
        StatsBank_state_update_reset_overflow_and_feedback_bytes_unchanged=True,
        StatsBank_sha256=sha(bank), added_target_state_bits=0,
        added_target_cycles=0, reference_helper_exact_parent_projection=True))
    save(O / 'admission.json', m.admission())
    cfg = read(W / 'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java = [cfg['java'], '-Xmx16G', '-Xss32M', '-XX:ActiveProcessorCount=2']
    classes = O / 'classes'
    classes.mkdir()
    composed = D / 'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    prod = D / 'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
    prior_validation = read(D / 'build-logs/Opt4-common-stats-bank-r3-20261113/reused-production-classes.json')
    assert all(sha(p) == h for p, h in prior_validation['files'].items())
    base = ':'.join(map(str, [prod, composed])) + ':' + ':'.join(cfg['classpath'])
    m.stage('compile-delta-and-production-bank', java + ['-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', base, '-Xplugin:' + cfg['plugin'], '-d', classes,
        T / R / 'WeightedCarrySave.scala', T / R / 'AddressBucketGrouped.scala',
        T / R / 'BankTagRead.scala', T / R / 'StatsBank.scala', C / 'ReferenceGrouped.scala', C / 'Delta.scala'],
        [classes / 'ecstatscommon/StatsBank.class', classes / 'ecstatscommon/WeightedCarrySave.class',
         classes / 'deltacsa/Emit.class'])
    cp = str(classes) + ':' + base
    for name in ['Contract', 'Reduction', 'Reference', 'Candidate']:
        target = O / name
        target.mkdir()
        rtl = target / (name + '.v')
        m.stage('elaborate-' + name, java + ['-cp', cp, 'deltacsa.Emit', name, target], [rtl])
        if name == 'Contract':
            prove(rtl)
        elif name == 'Reduction':
            finite_reduce(rtl)
    measured = {}
    for name in ['Reference', 'Candidate']:
        measured[name] = area(O / name / (name + '.v'), name)
        save(O / 'paired-progress.json', measured)
    assert all(sha(p) == h for p, h in binding['files'].items())
    savings = {k: measured['Reference']['resources'][k] - measured['Candidate']['resources'][k]
               for k in measured['Reference']['resources']}
    m.update('COMPLETE_FULL_SIZE_DELTA_CSA_AREA_PAIR_NOT_WHOLE_EC',
        ended_utc=now(), area=measured, savings=savings,
        next='Choose from measured same-scope gain. Full bank/target/host/ABI/DCache closure mandatory before integration. No automatic whole build from this projection.')
    save(O / 'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O / 'failure.json', m.ST)
        raise
