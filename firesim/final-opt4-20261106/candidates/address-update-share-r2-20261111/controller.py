#!/usr/bin/python3
"""Verify exact bucket-sequence tag compression, then map the complete module.

No whole-DUT build or device access. Failed stages retain first evidence and
require a different reviewed controller. Live controller/child are adopted.
"""
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
O = D/'build-logs/Opt4-fit-address-update-share-r2-20261111'
S = D/'Opt4-fit-address-update-share-r2-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''): h.update(block)
    return h.hexdigest()

def read(p): return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now(): return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p, value):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True); f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def exact_text(p, value):
    if p.exists(): assert p.read_text() == value, str(p)
    else: p.write_text(value)

def identity(pid):
    try:
        v = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=v[19], process_state=v[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError: return {}

def live(x):
    y = identity(x.get('pid', 0))
    return bool(y and all(y.get(k) == str(x.get(k)) for k in ['start_ticks', 'host_boot_id'])
                and y['process_state'] not in ['Z', 'X'])

def guard():
    mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines()
                   if x.startswith('MemAvailable:')))
    return mem >= 48*2**20 and shutil.disk_usage(W).free >= 40*2**30

def parse_resources(p):
    result = {}
    for line in p.read_text().splitlines():
        m = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|', line)
        if m: result.setdefault(m[1].rstrip('*'), float(m[2].replace(',', '')))
    assert set(result) == {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    assert result['CLB LUTs'] > 0
    return result

def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt live controller or child'
    cfg = read(C/'config.json'); b = cfg['binding']; F = Path(cfg['worktree'])
    inputs = read(C/'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items()), 'immutable input mismatch'
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == b['hardware_commit']
    names = ['PackageAddressStats.scala', 'AddressBucketGrouped.scala', 'AddressBucketUpdate.scala']
    for n in names:
        assert (F/REL/n).read_bytes() == subprocess.check_output(['git', 'show', b['hardware_commit']+':'+REL+n], cwd=F)
    parent = subprocess.check_output(['git','show',b['parent_commit']+':'+REL+'PackageAddressStats.scala'],cwd=F,text=True)
    current = (F/REL/'PackageAddressStats.scala').read_text()
    assert 'Mux(bucketValid(currentBucketIdx)' in current
    assert 'when (AddressBucketUpdate.enabled(isCurrent, bucketLoadFirstDelta(i)(g)))' in current
    assert 'val allocate = isCurrent && !bucketValid(i)' in current
    assert 'bucketLoadFirst(i)(g) := Mux(allocate, bucketLoadFirstDelta(i)(g),' in current
    assert 'bucketLoadFirst(i)(g) := 0.U' in current
    assert 'bucketLoadFirst(retiringIdx)(g) := 0.U' in current
    for n in ['AddressBucketGrouped.scala']:
        assert (F/REL/n).read_bytes()==subprocess.check_output(['git','show',b['parent_commit']+':'+REL+n],cwd=F)
    inherited=read(cfg['parent_local_receipt'])
    assert inherited['hardware_commit']==b['parent_commit'] and inherited['full_dut_formal'] is False
    assert inherited['full_module_regression']['status']=='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL'
    touch=inherited['inherited_group4']
    st = dict(schema='ec-opt4-address-update-share-validation/1', **identity(os.getpid()), hardware_commit=b['hardware_commit'],
              source_id=b['source_id'], status='STARTING', started_utc=now(), stages=old.get('stages', {}),
              input_sha256=inputs, inherited_bucket_tag_verification=inherited['local_formal'],
              inherited_histogram_validation=touch,
              fpga_access=False, full_dut_synthesis=False,
              formal_admission=False, production_selected=False,
              proof_limits='Unconditional allocation and update equivalence SAT over arbitrary 64-bit counter/delta and valid values; actual-size stale-payload/reset/overflow vectors; complete frozen-module regression with independent global reset. No full-DUT formal equivalence.')
    save(S, st)
    def update(**kw): st.update(kw); st['updated_utc'] = now(); save(S, st)
    cache = O/'ccache'; cache.mkdir(exist_ok=True)
    temporary = O/'tmp'; temporary.mkdir(exist_ok=True)
    env = {**os.environ, 'LD_LIBRARY_PATH':'', 'JAVA_TOOL_OPTIONS':'', 'OMP_NUM_THREADS':'8', 'MAKEFLAGS':'-j8',
           'CCACHE_DISABLE':'1', 'CCACHE_DIR':str(cache), 'CCACHE_TEMPDIR':str(temporary), 'TMPDIR':str(temporary)}
    def run(label, argv, directory, outputs=(), negative=False):
        directory.mkdir(parents=True, exist_ok=True); rp = directory/(label+'-result.json'); r = read(rp)
        if r:
            assert r['hardware_commit'] == b['hardware_commit'] and r['source_id'] == b['source_id']
            assert r['accepted_result'] and not r['missing_outputs'], 'failed stage requires separate recovery'
            assert all(sha(p) == h for p, h in r['outputs'].items())
            st['stages'][label] = r; save(S, st); return Path(r['log'])
        while not guard(): update(status='WAITING_RESOURCE_GATE', next_stage=label); time.sleep(30)
        log = directory/(label+'-attempt-1.log'); assert not log.exists(), 'incomplete prior attempt requires audit'
        args = list(map(str, ['nice', '-n', '10', *argv]))
        with log.open('xb', buffering=0) as f:
            p = subprocess.Popen(args, cwd=directory, env=env, stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
            child = identity(p.pid)
            r = dict(hardware_commit=b['hardware_commit'], source_id=b['source_id'], argv=args,
                     log=str(log), started_utc=now(), **child, returncode=None)
            st['stages'][label] = r; update(status='RUNNING_'+label.upper(), child=child, active_stage=label)
            while p.poll() is None:
                try: p.wait(timeout=30)
                except subprocess.TimeoutExpired: pass
                update(); os.fsync(f.fileno())
        accepted = p.returncode != 0 if negative else p.returncode == 0
        r.update(returncode=p.returncode, accepted_result=accepted, negative=negative, ended_utc=now(),
                 outputs={str(p):sha(p) for p in outputs if p.is_file()},
                 missing_outputs=[str(p) for p in outputs if not p.is_file()])
        save(rp, r); st['stages'][label] = r; update(child={})
        assert accepted and not r['missing_outputs'], (label, p.returncode, str(log))
        return log
    classes = O/'classes'; classes.mkdir(exist_ok=True)
    cp = str(classes)+':'+':'.join(cfg['classpath'])
    run('compile', [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', ':'.join(cfg['compiler']),
        'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']), '-Xplugin:'+cfg['plugin'], '-d', classes,
        *[F/REL/n for n in names], C/'EmitUpdate.scala'], O, [classes/'opt4update/EmitUpdate.class'])
    def elaborate(mode, top):
        sub = O/mode; sub.mkdir(exist_ok=True); rtl = sub/(top+'.v')
        run('elaborate-'+mode, [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', cp,
            'opt4update.EmitUpdate', mode, sub], sub, [rtl])
        return rtl
    proof=elaborate('proof','UpdateProof')
    for prop in ['equivalent','resetEquivalent','allocationEquivalent']:
        log=run('sat-'+prop,['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top UpdateProof -flatten; sat -verify -prove io_{prop} 1 -timeout 180'],O/'proof')
        assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log=run('sat-negative-reset-mutation',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top UpdateProof -flatten; sat -verify -prove io_mutationEquivalent 1 -timeout 60'],O/'proof',negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    proof=elaborate('qualified','QualifiedProof')
    log=run('sat-qualified',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {proof}; prep -top QualifiedProof -flatten; sat -verify -prove io_legal 1 -timeout 180'],O/'qualified')
    assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_UNCONDITIONAL_64BIT_ALLOCATION_UPDATE_RESET_AND_256_SLOT_QUALIFICATION',negative_mutation_rejected=True)
    rtl=elaborate('boundary','UpdateProbe'); sub=O/'boundary'
    cpp=sub/'boundary.cpp'; exact_text(cpp,(C/'boundary.cpp').read_text()); exe=sub/'obj/VUpdateProbe'
    run('boundary-compile',['/usr/local/bin/verilator','--cc','--exe','--build','--top-module','UpdateProbe','--Mdir',sub/'obj','-j',8,'--output-split',10000,'--output-split-cfuncs',200,'-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtl,cpp],sub,[exe])
    log=run('boundary-run',[exe],sub)
    assert 'UPDATE_ACTUAL_SIZE_PASS' in log.read_text()
    update(actual_size_boundary='PASS_8192_VECTORS_256_SLOTS_1280_64BIT_COUNTERS_STALE_INVALID_OVERFLOW_RESET_RETIRE')
    rtl = elaborate('address', 'PackageAddressStats'); compare = O/'compare'; compare.mkdir(exist_ok=True)
    for source, target in [('frozen-original.v', 'original.v'), ('frozen-tb.v', 'tb.v')]:
        exact_text(compare/target, (C/source).read_text())
    exe = compare/'obj/Vtb'
    run('compare-compile', ['/usr/local/bin/verilator', '--binary', '--timing', '--top-module', 'tb', '--Mdir', compare/'obj',
        '-j', 8, '--output-split', 10000, '--output-split-cfuncs', 200, '--x-initial', 0, '--x-assign', 0, '-Wno-fatal',
        '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT', "-DRANDOM=32'h0", '-CFLAGS', '-O0',
        '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', compare/'original.v', rtl, compare/'tb.v'], compare, [exe])
    log = run('compare', [exe], compare)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL',independent_global_reset_regression='PASS_GLOBAL_RESET_WITHOUT_RESETSTATS_AT_PHASE_512_513_RESTART_516',rtl_sha256=sha(rtl))
    save(O/'verified-local.json', dict(hardware_commit=b['hardware_commit'], source_id=b['source_id'], rtl_sha256=sha(rtl),
        local_formal=st['local_formal'], actual_size_boundary=st['actual_size_boundary'],
        negative_mutation_rejected=st['negative_mutation_rejected'], independent_global_reset_regression=st['independent_global_reset_regression'],
        full_module_regression=st['full_module_regression'],
        inherited_bucket_tag_verification=inherited['local_formal'], full_dut_formal=False))
    sub = O/'map-full-module'; sub.mkdir(exist_ok=True); report = sub/'utilization.rpt'; dcp = sub/'module.dcp'
    tcl = sub/'map.tcl'
    exact_text(tcl, 'set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\n'
        +'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        +f'report_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    run('map-full-module', ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
        '-log', sub/'vivado.log', '-source', tcl], sub, [report, dcp])
    update(status='VERIFIED_AND_MAPPED_MODULE_ONLY', child={}, ended_utc=now(), full_module_map=dict(
        resources=parse_resources(report), report=str(report), report_sha256=sha(report), rtl_sha256=sha(rtl),
        tcl_sha256=sha(tcl), checkpoint=str(dcp), scope='Complete module OOC; not whole-DUT FIT'))
    save(O/'result.json', st)

if __name__ == '__main__':
    try: main()
    except Exception as exc:
        st = read(S)
        if st.get('pid') == os.getpid():
            st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now()); save(S, st)
        raise
