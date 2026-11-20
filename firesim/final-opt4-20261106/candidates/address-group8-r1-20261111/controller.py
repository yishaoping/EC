#!/usr/bin/python3
"""Verify an eight-key grouped histogram before mapping the complete module."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import shutil
import subprocess
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-fit-address-group8-r1-20261111'
S = D/'Opt4-fit-address-group8-r1-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()

def read(path):
    return json.loads(Path(path).read_text()) if Path(path).is_file() else {}

def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(tmp, path)

def identity(pid):
    try:
        tail = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=tail[19], process_state=tail[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except (FileNotFoundError, IndexError):
        return {}

def live(item):
    current = identity(item.get('pid', 0))
    return bool(current and all(current.get(k) == str(item.get(k))
        for k in ('start_ticks', 'host_boot_id')) and current['process_state'] not in ('Z', 'X'))

def resource_gate():
    available = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                         if line.startswith('MemAvailable:')))
    return available >= 48 * 2**20 and shutil.disk_usage(W).free >= 40 * 2**30

def parse_resources(path):
    values = {}
    for line in Path(path).read_text().splitlines():
        match = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|', line)
        if match:
            values[match[1].rstrip('*')] = float(match[2].replace(',', ''))
    assert set(values) == {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    return values

def main():
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    cfg = read(C/'config.json'); binding = cfg['binding']; F = Path(cfg['worktree'])
    inputs = read(C/'input-hashes.json')
    assert inputs and all(sha(path) == digest for path, digest in inputs.items()), 'input hash mismatch'
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == binding['hardware_commit']
    parent = binding['parent_commit']
    source_path = REL + 'PackageAddressStats.scala'
    helper_path = REL + 'AddressBucketGrouped.scala'
    assert (F/source_path).read_bytes() == subprocess.check_output(
        ['git', 'show', parent + ':' + source_path], cwd=F)
    assert (F/helper_path).read_bytes() == subprocess.check_output(
        ['git', 'show', binding['hardware_commit'] + ':' + helper_path], cwd=F)
    spec = importlib.util.spec_from_file_location('group8_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(spec); spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    assert source_id == binding['source_id']
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt existing controller or child'
    state = dict(schema='ec-opt4-group8-validation/1', **identity(os.getpid()),
        hardware_commit=binding['hardware_commit'], source_id=source_id,
        status='STARTING', updated_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        stages=old.get('stages', {}), input_sha256=inputs, fpga_access=False,
        full_dut_synthesis=False, formal_admission=False, production_selected=False,
        proof_limits='Local combinational SAT and finite actual-size/full-module regressions only; no full-DUT formal equivalence.')
    save(S, state)

    def update(**fields):
        state.update(fields, updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(S, state)

    env = {**os.environ, 'LD_LIBRARY_PATH':'', 'JAVA_TOOL_OPTIONS':'',
           'OMP_NUM_THREADS':'8', 'MAKEFLAGS':'-j8'}
    def run(label, argv, directory, outputs=(), negative=False):
        directory = Path(directory); directory.mkdir(parents=True, exist_ok=True)
        receipt = directory/(label+'-result.json')
        previous = read(receipt)
        if previous:
            assert previous['hardware_commit'] == binding['hardware_commit']
            assert previous['source_id'] == source_id and previous['accepted_result']
            assert all(sha(path) == digest for path, digest in previous['outputs'].items())
            assert not previous['missing_outputs']
            state['stages'][label] = previous; save(S, state)
            return Path(previous['log'])
        assert not (directory/(label+'-attempt-1.log')).exists(), 'incomplete prior attempt needs separate recovery'
        while not resource_gate():
            update(status='WAITING_RESOURCE_GATE', next_stage=label); time.sleep(30)
        log = directory/(label+'-attempt-1.log')
        args = list(map(str, ['nice', '-n', '10', *argv]))
        with log.open('xb', buffering=0) as stream:
            child = subprocess.Popen(args, cwd=directory, env=env, stdin=subprocess.DEVNULL,
                                     stdout=stream, stderr=subprocess.STDOUT)
            child_identity = identity(child.pid)
            result = dict(hardware_commit=binding['hardware_commit'], source_id=source_id,
                argv=args, log=str(log), started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                **child_identity, returncode=None)
            state['stages'][label] = result
            update(status='RUNNING_'+label.upper(), child=child_identity, active_stage=label)
            while child.poll() is None:
                try: child.wait(timeout=20)
                except subprocess.TimeoutExpired: pass
                update()
                os.fsync(stream.fileno())
        accepted = child.returncode != 0 if negative else child.returncode == 0
        result.update(returncode=child.returncode, accepted_result=accepted, negative=negative,
            ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
            outputs={str(path):sha(path) for path in outputs if Path(path).is_file()},
            missing_outputs=[str(path) for path in outputs if not Path(path).is_file()])
        save(receipt, result); state['stages'][label] = result; update(child={})
        assert accepted and not result['missing_outputs'], (label, child.returncode, log)
        return log

    classes = O/'classes'; classes.mkdir(exist_ok=True)
    cfg_cp = ':'.join(cfg['classpath'])
    java = cfg['java']
    run('compile', [java, '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4',
        '-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', cfg_cp,
        '-Xplugin:'+cfg['plugin'], '-d', classes, F/(REL+'PackageAddressStats.scala'),
        F/(REL+'AddressBucketGrouped.scala'), C/'EmitGroup8.scala'], O,
        [classes/'opt4group/EmitGroup8$.class'])
    cp = str(classes) + ':' + cfg_cp
    def elaborate(mode, top):
        target = O/mode; target.mkdir(exist_ok=True)
        rtl = target/(top+'.v')
        run('elaborate-'+mode, [java, '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4',
            '-cp', cp, 'opt4group.EmitGroup8', mode, target], target, [rtl])
        return rtl

    proof_rtl = elaborate('proof8', 'Group8Proof')
    for prop in ('equivalent', 'topology', 'bounds'):
        log = run('sat-'+prop, ['/usr/local/bin/yosys', '-Q', '-T', '-p',
            f'read_verilog {proof_rtl}; prep -top Group8Proof -flatten; sat -verify -prove io_{prop} 1 -timeout 300'],
            O/'proof')
        assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log = run('sat-negative-mutation', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {proof_rtl}; prep -top Group8Proof -flatten; sat -verify -prove io_mutantEquivalent 1 -show-inputs -timeout 60'],
        O/'proof', negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_8_INPUT_8BIT_KEY_BOUNDED_GRANULE_REFERENCE_AND_SORT_TOPOLOGY',
           negative_mutation_rejected=True)

    histogram_rtl = elaborate('histogram', 'HistogramProbe'); hist_dir = O/'histogram'
    group4 = W/'candidates/address-group4-r1-20261111/controller.py'
    helper_spec = importlib.util.spec_from_file_location('group4_boundary_helper', group4)
    helper = importlib.util.module_from_spec(helper_spec); helper_spec.loader.exec_module(helper)
    cpp = hist_dir/'boundary.cpp'; cpp.write_text(helper.boundary_cpp())
    exe = hist_dir/'obj/VHistogramProbe'
    run('boundary-compile', ['/usr/local/bin/verilator', '--cc', '--exe', '--build',
        '--top-module', 'HistogramProbe', '--Mdir', hist_dir/'obj', '-j', 8,
        '--output-split', 10000, '--output-split-cfuncs', 200, '-Wno-fatal',
        '-CFLAGS', '-O0', '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', histogram_rtl, cpp],
        hist_dir, [exe])
    log = run('boundary-run', [exe], hist_dir)
    assert 'HISTOGRAM_ACTUAL_SIZE_PASS vectors=8192 inputs=80 outputs=1024 slots=256 width=64 overflow=1 reset=1' in log.read_text()
    update(actual_size_boundary='PASS_8192_VECTORS_80_INPUTS_1024_OUTPUTS_256_BUCKETS_64BIT_OVERFLOW_RESET')

    address_rtl = elaborate('address', 'PackageAddressStats'); compare = O/'compare'
    compare.mkdir(exist_ok=True)
    for source, target in (('frozen-original.v', 'original.v'), ('frozen-tb.v', 'tb.v')):
        target_path = compare/target
        expected = (C/source).read_bytes()
        if target_path.exists(): assert target_path.read_bytes() == expected
        else: target_path.write_bytes(expected)
    exe = compare/'obj/Vtb'
    run('compare-compile', ['/usr/local/bin/verilator', '--binary', '--timing', '--top-module', 'tb',
        '--Mdir', compare/'obj', '-j', 8, '--output-split', 10000, '--output-split-cfuncs', 200,
        '--x-initial', 0, '--x-assign', 0, '-Wno-fatal', '-DRANDOMIZE_REG_INIT',
        '-DRANDOMIZE_MEM_INIT', "-DRANDOM=32'h0", '-CFLAGS', '-O0',
        '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', compare/'original.v', address_rtl, compare/'tb.v'],
        compare, [exe])
    log = run('compare', [exe], compare)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL', rtl_sha256=sha(address_rtl))
    save(O/'verified-local.json', dict(hardware_commit=binding['hardware_commit'], source_id=source_id,
        rtl_sha256=sha(address_rtl), local_formal=state['local_formal'],
        actual_size_boundary=state['actual_size_boundary'],
        full_module_regression=state['full_module_regression'], full_dut_formal=False))

    map_dir = O/'map-full-module'; map_dir.mkdir(exist_ok=True)
    report = map_dir/'utilization.rpt'; dcp = map_dir/'module.dcp'; tcl = map_dir/'map.tcl'
    tcl_text = ('set_param general.maxThreads 4\n'+f'read_verilog {{{address_rtl}}}\n'
        +'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        +f'report_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{map_dir/"hierarchical.rpt"}}}\n'
        +f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
    if tcl.exists(): assert tcl.read_text() == tcl_text
    else: tcl.write_text(tcl_text)
    run('map-full-module', ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
        '-log', map_dir/'vivado.log', '-source', tcl], map_dir, [report, dcp])
    update(status='VERIFIED_AND_MAPPED_MODULE_ONLY', child={}, ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        full_module_map=dict(resources=parse_resources(report), report=str(report), report_sha256=sha(report),
            rtl_sha256=sha(address_rtl), tcl_sha256=sha(tcl), checkpoint=str(dcp),
            scope='Complete module OOC; not whole-DUT FIT'))
    save(O/'result.json', state)

if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        state = read(S)
        if state.get('pid') == os.getpid():
            state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc),
                ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(S, state)
        raise
