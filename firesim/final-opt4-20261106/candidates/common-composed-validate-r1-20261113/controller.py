#!/usr/bin/python3
"""One immutable, materially gated common-source DCache/host-generation owner.

No CAD, FPGA IO, compiler bypass, source mutation, or intelligent supervision.
The measured 16-lane structural predecessor is distinguished from the proven
query refinement in these complete sources. Neither supplies a whole-area claim.
"""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-common-composed-validate-r1-20261113'
TREE = W/'Opt4-area-common-composed-validate-r1-20261113'
COMPILE = D/'build-logs/Opt4-common-composed-source-r2-20261113'
MIXED = D/'build-logs/Opt4-common-stats-token-area-r3-20261113'
CALLER = D/'build-logs/Opt4-common-caller-geometry-closure-r1-20261113'
GEN = D/'build-logs/Opt4-common-stats-host-r6-20261113'
DCACHE = D/'build-logs/Opt4-dcache-storage-compose-report-r4-20261113'
CPUS = {220, 221}
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec); spec.loader.exec_module(value)
    return value


m = module('original_composition_stage_guard',
    W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m.C, m.O = C, O
cycle = module('existing_complete_cycle_generator',
    W/'candidates/sprint-composed-validate-r1-20261112/controller.py')
cycle.O, cycle.m = O, m


def members(unit):
    found = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit(): continue
        try:
            paths = [line.split(':', 2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            if any(path.endswith('/'+unit) or '/'+unit+'/' in path for path in paths):
                row = identity(int(proc.name))
                if row and row['process_state'] not in ['X', 'Z']: found.append(row)
        except OSError: pass
    return found


def cpu_owners():
    rows = []
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit() or int(proc.name) == os.getpid(): continue
        try:
            affinity = os.sched_getaffinity(int(proc.name))
            if proc.stat().st_uid == os.getuid() and len(affinity) <= 8 and affinity & CPUS:
                row = identity(int(proc.name))
                if live(row): rows.append(row)
        except OSError: pass
    return rows


def accepted(path):
    row = read(path)
    assert row and row['returncode'] == 0 and not row['missing_outputs'], str(path)
    assert row.get('accepted', True) and sha(row['log']) == row['log_sha256'], str(path)
    assert all(sha(name) == digest for name, digest in row['outputs'].items()), str(path)
    return row


def verify_binding():
    binding = read(C/'source-binding.json')
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE,
        text=True).strip() == binding['hardware_commit']
    assert all(sha(path) == digest for path, digest in binding['files'].items())
    for relative, digest in binding['committed_files'].items():
        blob = subprocess.check_output(['git', 'show', binding['hardware_commit']+':'+relative], cwd=TREE)
        assert hashlib.sha256(blob).hexdigest() == digest, relative
    inventory = read(COMPILE/'compiled-classes.json')
    assert all(sha(path) == digest for path, digest in inventory['files'].items())
    assert inventory['hardware_commit'] == binding['compiled_hardware_commit']
    proofs = {
        'Opt4-common-query-bank-closure-r1-20261113': 'PASS_QUERY_BANK_ALL_STATE_FINITE_AND_GENERATED_TRANSITION_CONTRACT',
        'Opt4-common-stats-transition-proof-r1-20261113': 'PASS_EXACT_COMMON_BANK_STATE_TRANSITION_AND_OUTPUT_CONES',
        'Opt4-common-bank-geometry-r3-20261113': 'PASS_PARAMETERIZED_COMMON_BANK_GEOMETRY_PREREQUISITES_NOT_HOST_OR_AREA'}
    for directory, status in proofs.items():
        assert read(D/'build-logs'/directory/'result.json')['status'] == status
    return binding, inventory


def material_gate(mixed, caller, dcache):
    """Fail closed: finite checks, both complete hosts, actual same-scope pair."""
    assert mixed['status'] == 'COMPLETE_MIXED_ROLE_HOST_TOKENS_AND_AREA_PAIR_NOT_WHOLE_EC'
    assert caller['status'] == 'PASS_COMPLETE_ADDRESS_CALLER_8_16_32_FINITE_ALL_STATE_AND_ABI_NOT_HOST_AREA'
    assert dcache['status'] == 'COMPLETE_FULL_DCACHE_CYCLE_AND_PAIRED_MODULE_AREA_REPORT_RECOVERY_NOT_WHOLE_FIT'
    assert all(row['functional_baseline'] == m.BASE for row in [mixed, caller, dcache])
    assert mixed['hardware_commit'] == 'f4709ea246da55afe4b94c2533247744d90a68f7'
    assert mixed['experiment_commit'] == 'a8ec2fd3df371498630b5931023584ca0106f2ae'
    assert caller['hardware_commit'] == '5a4ec16e4bbd2d6c03e4a5fe8c8965d8aad5af2a'
    assert set(caller['validated']) == {'8', '16', '32'}
    for row in caller['validated'].values():
        assert row['cycles'] == 6144 and row['outputs'] == 5684
        assert row['public_outputs'] == 52 and row['invalid_payload_words'] == 5120
        assert row['before_and_after_edge'] and row['negative_invalid_payload_rejected']
        assert row['oracle_inverse_byte_equal']
    tokens = mixed['tokens']
    assert set(tokens) == {'Plain', 'Threaded'}
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    assert all(row['target_tokens'] == 3003 and row['checked_outputs'] == 219000
        for row in tokens.values())
    assert set(mixed['area']) == {'Plain', 'Threaded'}
    savings = {key: mixed['area']['Plain']['resources'][key] -
        mixed['area']['Threaded']['resources'][key] for key in mixed['savings']}
    assert savings == mixed['savings'] and 'CLB LUTs' in savings
    assert dcache['complete_dcache_cycles_verified']
    assert dcache['target_cycles'] == 8192 and dcache['observations'] == 24575
    return savings['CLB LUTs'] >= 300000 and dcache['module_lut_saved'] >= 0


def prerequisites():
    owners = [(MIXED, 'ec-opt4-common-stats-token-area-r3-20261113.service'),
        (CALLER, 'ec-opt4-common-caller-geometry-closure-r1-20261113.service'),
        (GEN, 'ec-opt4-common-stats-host-r6-20261113.service'),
        (COMPILE, 'ec-opt4-common-composed-source-r2-20261113.service'),
        (DCACHE, 'ec-opt4-dcache-storage-compose-report-r4-20261113.service')]
    while True:
        statuses = {path.name: read(path/'state.json').get('status') for path, _ in owners}
        if any(str(status).startswith(('FAILED', 'PREREQUISITE_FAILED')) for status in statuses.values()):
            m.update('PREREQUISITE_FAILED_NO_ELABORATION_OR_HOST_STARTED',
                prerequisites=statuses, ended_utc=now())
            save(O/'result.json', m.ST); return False
        if all((path/'result.json').is_file() for path, _ in owners):
            if not material_gate(*[read(path/'result.json') for path in [MIXED, CALLER, DCACHE]]):
                m.update('INSUFFICIENT_ACTUAL_MIXED_GAIN_NO_ELABORATION_OR_HOST_STARTED',
                    mixed_savings=read(MIXED/'result.json')['savings'], ended_utc=now())
                save(O/'result.json', m.ST); return False
            release = {unit: members(unit) for _, unit in owners}
            if not any(release.values()) and not cpu_owners():
                # Bind all completed stage artifacts and negative observations,
                # rather than accepting the result's PASS string alone.
                for name in ['Plain', 'Threaded']:
                    for stage in ['token-oracle-', 'token-negative-']:
                        row = read(MIXED/(stage+name+'-receipt.json'))
                        assert row['accepted'] and sha(row['log']) == row['log_sha256']
                        assert (row['returncode'] == 0) == (stage == 'token-oracle-')
                        assert all(sha(path) == digest for path, digest in row['outputs'].items())
                    assert all(sha(path) == digest for path, digest in
                        read(MIXED/'result.json')['area'][name]['outputs'].items())
                for path in MIXED.glob('*receipt.json'):
                    row = read(path)
                    assert row.get('accepted', True) and sha(row['log']) == row['log_sha256']
                caller = read(CALLER/'result.json')
                for lanes, row in caller['validated'].items():
                    root = CALLER/('lanes-'+lanes)
                    assert sha(root/'testbench-binding.json') == row['testbench_binding_sha256']
                    assert sha(root/'public-abi.json') == row['public_abi_sha256']
                    accepted(CALLER/('full-target-'+lanes+'-receipt.json'))
                    negative = read(CALLER/('invalid-payload-negative-'+lanes+'-receipt.json'))
                    assert negative['accepted'] and negative['negative'] and negative['returncode'] != 0
                    assert sha(negative['log']) == negative['log_sha256']
                for path, result in [(MIXED, read(MIXED/'result.json')), (CALLER, caller)]:
                    candidate = W/'candidates'/path.name.removeprefix('Opt4-')
                    assert sha(candidate/'source-binding.json') == result['source_binding_sha256']
                    assert all(sha(name) == digest for name, digest in
                        read(candidate/'source-binding.json')['files'].items())
                gen = read(GEN/'result.json')
                assert gen['status'] == 'PASS_MIXED_HOST_BATCH_REMAP_AND_EXACT_HOST_GENERATION_TOKEN_VALIDATION_PENDING'
                accepted(GEN/'batch-remap-semantic-regression-receipt.json')
                patches = read(GEN/'batch-remap-gate.json')['mapper_classes']
                patches.update(read(D/'build-logs/Opt4-common-stats-host-r5-20261113/compiler-recovery-gate.json')['classes'])
                assert all(sha(path) == digest for path, digest in patches.items())
                save(O/'material-prerequisites.json', dict(utc=now(),
                    results={str(path/'result.json'): sha(path/'result.json') for path, _ in owners},
                    cgroups_released=release, compiler_classes=patches,
                    measured_structural_predecessor_lanes=16, measured_predecessor_query_refinement_absent=True,
                    exact_composed_area_still_unknown=True, gains_not_added_to_whole_estimate=True))
                return True
        m.update('QUEUED_FOR_MATERIAL_MIXED_GAIN_AND_COMPLETE_CALLER_RELEASE',
            prerequisites=statuses, minimum_same_scope_mixed_LUT_gain=300000,
            no_elaboration_started=True, no_host_transform_started=True, no_waiting_CPU_pins=True)
        time.sleep(30)


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt exact live or terminal owner'
    binding, inventory = verify_binding()
    m.ST.update(schema='ec-gated-common-complete-source-validation/1', **identity(), started_utc=now(),
        hardware_commit=binding['hardware_commit'], compiled_hardware_commit=binding['compiled_hardware_commit'],
        functional_baseline=m.BASE, source_variant=binding['source_variant'],
        source_binding_sha256=sha(C/'source-binding.json'), cpus_after_admission=sorted(CPUS),
        memory_limit_gib=64, no_CAD=True, fpga_access=False, full_system_fit=False, production_admission=False,
        scope='Materially gated exact complete-source frozen DCache8192cycle/24575observation comparison and actual common64bank threaded complete-host generation. No whole-host token/ABI, area, shell FIT, or physical certification claim.')
    if not prerequisites(): return
    binding, inventory = verify_binding()
    assert not cpu_owners()
    os.sched_setaffinity(0, CPUS); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    cfg = read(C/'config.json')
    # Reuse the completed compiler repairs without disabling loop detection or
    # replacing any complete-source class with the obsolete seven-argument one.
    cp = ':'.join(map(str, [GEN/'mapper-classes',
        D/'build-logs/Opt4-common-stats-host-r5-20261113/checker-classes']))+':'+inventory['classpath']
    java = [cfg['java'], '-Xmx48G', '-Xss32M', '-XX:ActiveProcessorCount=2', '-Dec.dac.firesim=true', '-cp', cp]
    classes = D/'build-logs/Opt4-common-composed-source-r1-20261113/classes'
    m.stage('class-origin-linkage', java+['eccommoncomposition.CheckComposition', classes])
    parameters = O/'parameters.json'
    m.stage('frozen-parameters', java+['firesim.firesim.DacParameterAudit', 'firesim.firesim.DacOpt4C4', parameters], [parameters])
    assert read(parameters) == read(cfg['frozen_parameters'])
    elab = O/'elaborate'; elab.mkdir()
    fir = elab/'firesim.firesim.FireSim.fir'; anno = elab/'firesim.firesim.FireSim.anno.json'
    log = m.stage('elaborate-complete-source', java[:1]+['-verbose:class']+java[1:]+['chipyard.Generator',
        '--target-dir', elab, '--name', 'firesim.firesim.FireSim', '--top-module', 'firesim.firesim.FireSim',
        '--legacy-configs', 'firesim.firesim:DacOpt4C4'], [fir, anno])
    loaded = log.read_text(errors='replace').splitlines()
    for cls in ['boom.lsu.BoomNonBlockingDCache', 'boom.lsu.PackageAddressStats',
                'ecstatscommon.StatsBank', 'freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats']:
        assert any(cls in line and str(classes) in line for line in loaded), cls
    annotations = read(anno)
    assert not any('DontCheckCombLoops' in row.get('class', '') for row in annotations)
    selected = [row for row in annotations if row.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected) == 64 and all(re.fullmatch(r'StatsBank(?:_\d+)?',
        row['target'].split(':')[-1]) for row in selected)
    plain = O/'plain-target'; plain.mkdir(); rtl = plain/'FireSim-generated.sv'
    m.stage('goldengate-target', java+['midas.stage.GoldenGateMain', '-i', fir, '-td', plain, '-faf', anno,
        '-ggcp', 'firesim.configs', '-ggcs', 'DacXilinxAlveoConfig', '--output-filename-base', 'FireSim-generated', '--no-dedup'], [rtl])
    listing = plain/'firrtl_black_box_resource_files.f'; appended = {}
    with rtl.open('ab') as out:
        for line in listing.read_text().splitlines() if listing.exists() else []:
            if line.strip():
                path = Path(line.strip()); out.write(path.read_bytes()); out.write(b'\n'); appended[str(path)] = sha(path)
    save(O/'plain-target-binding.json', dict(hardware_commit=binding['hardware_commit'],
        source_variant=binding['source_variant'], outputs={str(rtl): sha(rtl)}, appended=appended))
    prepared = cycle.cycle_prepare(binding['source_variant'], rtl)
    prep = read(prepared/'preparation.json')
    # Retain the generator's exact observation inventory in the new receipt.
    save(O/'frozen-cycle-preparation-binding.json', dict(preparation_sha256=sha(prepared/'preparation.json'),
        source_binding_sha256=sha(C/'source-binding.json'), assertions_enabled=True, original_preparation=prep))
    exe = O/'obj/VDCacheCyclePair'
    m.stage('compile-full-dcache-cycle', ['/usr/local/bin/verilator', '--cc', '--exe', '--build', '-j', '2',
        '--compiler', 'clang', '--top-module', 'DCacheCyclePair', '--Mdir', O/'obj', '--output-split', '10000',
        '--output-split-cfuncs', '200', '-Wno-fatal', '--x-initial', '0', '--x-assign', '0',
        '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT', "-DRANDOM=32'h0", '-DSTOP_COND=1', '-DPRINTF_COND=1',
        '-CFLAGS', '-O0 -fbracket-depth=4096 -I'+str(prepared), '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0',
        prepared/'frozen.sv', prepared/'candidate.sv', prepared/'pair.sv', prepared/'stimulus.cpp'], [exe])
    log = m.stage('full-dcache-cycle', [exe])
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
    assert 'observations=24575' in log.read_text()
    save(O/'full-dcache-cycle-receipt.json', dict(hardware_commit=binding['hardware_commit'],
        source_variant=binding['source_variant'], target_cycles=8192, observations=24575,
        full_formal=False, log=str(log), log_sha256=sha(log), assertions_enabled=True,
        source_binding_sha256=sha(C/'source-binding.json')))
    host = O/'threaded-host'; host.mkdir()
    log = m.stage('goldengate-threaded-complete-host', java+['midas.stage.GoldenGateMain', '-i', fir,
        '-td', host, '-faf', anno, '-ggcp', 'eccommoncomposition', '-ggcs', 'ThreadedAlveoConfig',
        '--output-filename-base', 'FireSim-generated'], [host/'FireSim-generated.sv', host/'FireSim-generated.synthesis.xdc'])
    assert 'Skipping Combinational Loop Detection' not in log.read_text()
    fame = (host/'post-fame-transform.fir').read_text()
    types = re.findall(r'(?m)^\s*inst \w+ of (StatsBank(?:_\d+)?)\b', fame)
    assert len(types) == 64 and len(set(types)) == 1
    assert 'module StatsBank_threaded :' in (host/'post-gen-sram-models.fir').read_text()
    binding, _ = verify_binding()
    m.update('PASS_EXACT_COMMON_COMPOSED_DCACHE_CYCLES_AND_THREADED_HOST_GENERATION_NO_AREA_OR_FIT',
        complete_dcache_cycles_verified=True, target_cycles=8192, observations=24575,
        selected_model_types=list(set(types)), selected_instances=64,
        host_RTL_sha256=sha(host/'FireSim-generated.sv'), ended_utc=now(),
        next='Complete exact generated-host token/software/seven-file ABI certification, then one complete-host and complete-shell measurement. Earlier mixed gain and frozen DCache finite parity do not certify whole EC FIT or permit FPGA IO.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try: main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_IMMUTABLE_DIAGNOSED_SUCCESSOR_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
