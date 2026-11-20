#!/usr/bin/python3
"""Validate and map the immutable epoch-payload candidate; never touches FPGA."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os
import re
import shutil
import subprocess
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-fit-address-epoch-clear-r2-20261111'
S = D/'Opt4-fit-address-epoch-clear-r2-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()

def read(p):
    return json.loads(Path(p).read_text()) if Path(p).is_file() else {}

def save(p, value):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True); f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()

def identity(pid):
    try:
        v = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=v[19], process_state=v[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}

def live(x):
    y = identity(x.get('pid', 0))
    return bool(y and y['start_ticks'] == str(x.get('start_ticks')) and
                y['host_boot_id'] == x.get('host_boot_id') and y['process_state'] not in ['Z', 'X'])

def guard():
    mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines()
                   if x.startswith('MemAvailable:')))
    return mem >= 48*2**20 and shutil.disk_usage(W).free >= 40*2**30

def parse_resources(p):
    out = {}
    for line in p.read_text().splitlines():
        m = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|', line)
        if m:
            out.setdefault(m[1].rstrip('*'), float(m[2].replace(',', '')))
    assert set(out) == {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    return out

def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    cfg = read(C/'config.json'); b = cfg['binding']; F = Path(cfg['worktree'])
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt existing live controller/child'
    inputs = read(C/'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items()), 'immutable input hash mismatch'
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == b['hardware_commit']
    assert subprocess.check_output(['git', 'rev-parse', b['frozen_commit']], cwd=F, text=True).strip() == b['frozen_commit']
    source = F/REL/'PackageAddressStats.scala'
    assert source.read_bytes() == subprocess.check_output(['git', 'show', b['hardware_commit']+':'+REL+'PackageAddressStats.scala'], cwd=F)
    st = dict(schema='ec-opt4-epoch-clear-validation/1', **identity(os.getpid()),
        hardware_commit=b['hardware_commit'], source_id=b['source_id'], status='STARTING',
        started_utc=now(), stages=old.get('stages', {}), input_sha256=inputs,
        packet_window=256, counter_width=64, fpga_access=False, full_dut_synthesis=False,
        formal_admission=False, production_selected=False,
        proof_limits='One-slot inductive invariant with 64-bit counters and bounded 13-bit deltas; 6,144-cycle full-module simulation is not full-DUT formal equivalence.')
    save(S, st)
    env = {**os.environ, 'LD_LIBRARY_PATH':'', 'JAVA_TOOL_OPTIONS':'', 'OMP_NUM_THREADS':'8', 'MAKEFLAGS':'-j8'}
    def update(**kw):
        st.update(kw); st['updated_utc'] = now(); save(S, st)
    def run(label, argv, directory, outputs=(), negative=False):
        directory = Path(directory); directory.mkdir(parents=True, exist_ok=True)
        rp = directory/(label+'-result.json'); r = read(rp)
        if r:
            assert r['hardware_commit'] == b['hardware_commit'] and r['source_id'] == b['source_id']
            assert r.get('accepted_result') and not r.get('missing_outputs'), 'failed stage needs separate recovery'
            assert all(sha(p) == h for p, h in r['outputs'].items())
            st['stages'][label] = r; save(S, st); return Path(r['log'])
        while not guard():
            update(status='WAITING_RESOURCE_GATE', next_stage=label); time.sleep(30)
        log = directory/(label+'-attempt-1.log')
        assert not log.exists(), 'incomplete prior attempt requires evidence audit'
        args = list(map(str, ['nice', '-n', '10', *argv]))
        with log.open('xb', buffering=0) as f:
            p = subprocess.Popen(args, cwd=directory, env=env, stdin=subprocess.DEVNULL,
                                 stdout=f, stderr=subprocess.STDOUT)
            child = identity(p.pid)
            rec = dict(hardware_commit=b['hardware_commit'], source_id=b['source_id'], argv=args,
                       log=str(log), started_utc=now(), **child, returncode=None)
            st['stages'][label] = rec; update(status='RUNNING_'+label.upper(), child=child, active_stage=label)
            while p.poll() is None:
                try: p.wait(timeout=30)
                except subprocess.TimeoutExpired: pass
                update(); os.fsync(f.fileno())
        accepted = p.returncode != 0 if negative else p.returncode == 0
        rec.update(returncode=p.returncode, accepted_result=accepted, negative=negative, ended_utc=now(),
                   outputs={str(x):sha(x) for x in outputs if Path(x).is_file()},
                   missing_outputs=[str(x) for x in outputs if not Path(x).is_file()])
        save(rp, rec); st['stages'][label] = rec; update(child={})
        assert accepted and not rec['missing_outputs'], (label, p.returncode, str(log))
        return log

    classes = O/'classes'; classes.mkdir(exist_ok=True)
    cp = str(classes)+':'+':'.join(cfg['classpath'])
    emit = C/'EmitEpoch.scala'
    run('compile', [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']), '-Xplugin:'+cfg['plugin'], '-d', classes,
        source, emit], O, [classes/'opt4epoch/EmitEpoch.class'])
    def elaborate(mode, top):
        sub = O/mode; sub.mkdir(exist_ok=True); rtl = sub/(top+'.v')
        run('elaborate-'+mode, [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', cp,
            'opt4epoch.EmitEpoch', mode, sub], sub, [rtl])
        return rtl
    proof = elaborate('proof', 'EpochProof')
    log = run('sat-step-invariant', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {proof}; prep -top EpochProof -flatten; sat -verify -prove io_stepOk 1 -timeout 240'], O/'proof')
    assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log = run('sat-negative-stale-carry', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {proof}; prep -top EpochProof -flatten; sat -verify -prove io_unguardedInvalidOverflow 0 -show-inputs -timeout 60'],
        O/'proof', negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_64BIT_FIVE_COUNTER_RESET_RETIRE_ALLOCATE_INVARIANT',
           negative_mutation_rejected=True, delta_bound_bits=13)

    rtl = elaborate('address', 'PackageAddressStats')
    compare = O/'compare'; compare.mkdir(exist_ok=True)
    for src, dst in [(Path(cfg['frozen_original']), compare/'original.v'),
                     (Path(cfg['frozen_tb']), compare/'tb.v')]:
        if dst.exists(): assert sha(dst) == sha(src), 'immutable compare input mismatch'
        else: shutil.copy2(src, dst)
    exe = compare/'obj/Vtb'
    run('compare-compile', ['/usr/local/bin/verilator', '--binary', '--timing', '--top-module', 'tb', '--Mdir', compare/'obj',
        '-j', 8, '--output-split', 10000, '--output-split-cfuncs', 200, '--x-initial', 0, '--x-assign', 0, '-Wno-fatal',
        '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT', "-DRANDOM=32'h0", '-CFLAGS', '-O0',
        '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', compare/'original.v', rtl, compare/'tb.v'], compare, [exe])
    log = run('compare', [exe], compare)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    update(full_module_regression='PASS_6144_CYCLES_52_OUTPUTS_NOT_FORMAL', rtl_sha256=sha(rtl))

    sub = O/'map-full-module'; sub.mkdir(exist_ok=True)
    report = sub/'utilization.rpt'; dcp = sub/'module.dcp'; tcl = sub/'map.tcl'
    script = ('set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\n'
        +'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        +f'report_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\n'
        +f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
    if tcl.exists(): assert tcl.read_text() == script
    else: tcl.write_text(script)
    run('map-full-module', ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
        '-log', sub/'vivado.log', '-source', tcl], sub, [report, dcp])
    update(status='VERIFIED_AND_MAPPED_MODULE_ONLY', child={}, ended_utc=now(), full_module_map=dict(
        resources=parse_resources(report), report=str(report), report_sha256=sha(report), rtl_sha256=sha(rtl),
        tcl_sha256=sha(tcl), checkpoint=str(dcp), scope='Complete module OOC; not whole-DUT FIT'))
    save(O/'verified-local.json', dict(hardware_commit=b['hardware_commit'], source_id=b['source_id'],
        local_formal=st['local_formal'], negative_mutation_rejected=True, full_module_regression=st['full_module_regression'],
        actual_packet_window=256, actual_counter_width=64, rtl_sha256=sha(rtl), full_dut_formal=False))
    save(O/'result.json', st)

if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        st = read(S)
        if st.get('pid') == os.getpid():
            st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now()); save(S, st)
        raise
