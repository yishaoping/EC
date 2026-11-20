#!/usr/bin/python3
"""Pinned group-of-four histogram proof, simulation and module mapping.

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
O = D/'build-logs/Opt4-fit-address-group4-r1-20261111'
S = D/'Opt4-fit-address-group4-r1-state.json'
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

def boundary_cpp():
    setters = '\n'.join(f'dut.io_keys_{i}=key[{i}];' + ''.join(
        f'dut.io_counts_{i}_{g}=count[{i}][{g}];' for g in range(4)) for i in range(80))
    pointers = ','.join(f'&dut.io_buckets_{i}_{g}' for i in range(256) for g in range(4))
    accumulators = '\n'.join(f'dut.io_accumulator_{g}=acc[{g}];' for g in range(4))
    next_checks = '\n'.join('''{
unsigned __int128 expected=reset?0:(unsigned __int128)acc[G]+hist[query][G];
if(dut.io_next_G[0]!=(uint32_t)expected || dut.io_next_G[1]!=(uint32_t)(expected>>32) ||
   dut.io_next_G[2]!=(uint32_t)(expected>>64)) fail(t,query,G,"overflow/reset");
}'''.replace('G', str(g)) for g in range(4))
    return '''#include "VHistogramProbe.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng=0x21c4b32a9e3779b9ULL;
static uint64_t random64(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
static void fail(unsigned t,unsigned i,unsigned g,const char* why){
 std::fprintf(stderr,"HISTOGRAM_FAIL t=%u bucket=%u granule=%u %s\\n",t,i,g,why);std::exit(1);}
int main(int argc,char** argv){
Verilated::commandArgs(argc,argv);VHistogramProbe dut;
uint64_t* outputs[1024]={''' + pointers + '''};
unsigned bounds[4]={8,3,2,1};unsigned key[80],count[80][4];uint64_t acc[4];
for(unsigned t=0;t<8192;t++){
 uint64_t hist[256][4]={};unsigned query=t%256;bool reset=t%7==0;
 for(unsigned j=0;j<80;j++){
  switch(t%8){
   case 0:key[j]=0;break;case 1:key[j]=255;break;
   case 2:key[j]=(t+j*3)%256;break;case 3:key[j]=(j%2)?255:0;break;
   case 4:key[j]=(j/4+t)%256;break;case 7:key[j]=(255-j+t)%256;break;
   default:key[j]=random64()%256;
  }
  for(unsigned g=0;g<4;g++){
   count[j][g]=(t%8<=1)?bounds[g]:((t%8==6)?0:random64()%(bounds[g]+1));
   hist[key[j]][g]+=count[j][g];
  }
 }
 for(unsigned g=0;g<4;g++)switch(t%5){
 case 0:acc[g]=UINT64_MAX;break;case 1:acc[g]=UINT64_MAX-1;break;
 case 2:acc[g]=0;break;case 3:acc[g]=1;break;default:acc[g]=random64();}
''' + setters + '\n' + accumulators + '''
 dut.io_query=query;dut.io_reset=reset;dut.eval();
 for(unsigned i=0;i<256;i++)for(unsigned g=0;g<4;g++)
  if(*outputs[i*4+g]!=hist[i][g])fail(t,i,g,"histogram");
''' + next_checks + '''
}
dut.final();std::puts("HISTOGRAM_ACTUAL_SIZE_PASS vectors=8192 inputs=80 outputs=1024 slots=256 width=64 overflow=1 reset=1");return 0;}
'''

def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt live controller or child'
    cfg = read(C/'config.json'); b = cfg['binding']; F = Path(cfg['worktree'])
    inputs = read(C/'input-hashes.json')
    assert all(sha(p) == h for p, h in inputs.items()), 'immutable input mismatch'
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == b['hardware_commit']
    names = ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']
    for n in names:
        assert (F/REL/n).read_bytes() == subprocess.check_output(['git', 'show', b['hardware_commit']+':'+REL+n], cwd=F)
    parent = subprocess.check_output(['git', 'show', b['parent_commit']+':'+REL+'PackageAddressStats.scala'], cwd=F, text=True)
    current = (F/REL/'PackageAddressStats.scala').read_text()
    pa = parent.index('  // Multiple package-table/strict-table ways can qualify')
    ca = current.index('  // Compact four source keys locally')
    assert parent[:pa] == current[:ca]
    assert parent[parent.index('  val evictedLoadFirst ='):] == current[current.index('  val evictedLoadFirst ='):]
    inherited = read(cfg['parent_local_receipt'])
    assert inherited['hardware_commit'] == b['parent_commit']
    touch = inherited['tests']['touch_bounds']
    assert touch['status'] == 'PASS_UNIVERSAL_96_INPUT_BITS' and touch['bounds'] == [8, 3, 2, 1]
    assert 'SUCCESS' in Path(touch['log']).read_text()
    st = dict(schema='ec-opt4-group4-validation/1', **identity(os.getpid()), hardware_commit=b['hardware_commit'],
              source_id=b['source_id'], status='STARTING', started_utc=now(), stages=old.get('stages', {}),
              input_sha256=inputs, outside_histogram_byte_equal=True, inherited_touch_bounds=touch,
              fpga_access=False, full_dut_synthesis=False,
              formal_admission=False, production_selected=False,
              proof_limits='Generated four-input key/segmentation/scatter SAT with bounded payloads; finite actual-size and complete-module regression. No full-DUT formal equivalence.')
    save(S, st)
    def update(**kw): st.update(kw); st['updated_utc'] = now(); save(S, st)
    env = {**os.environ, 'LD_LIBRARY_PATH':'', 'JAVA_TOOL_OPTIONS':'', 'OMP_NUM_THREADS':'8', 'MAKEFLAGS':'-j8'}
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
        *[F/REL/n for n in names], C/'EmitGroup.scala'], O, [classes/'opt4group/EmitGroup.class'])
    def elaborate(mode, top):
        sub = O/mode; sub.mkdir(exist_ok=True); rtl = sub/(top+'.v')
        run('elaborate-'+mode, [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', cp,
            'opt4group.EmitGroup', mode, sub], sub, [rtl])
        return rtl
    rtl = elaborate('proof', 'GroupProof')
    for prop in ['equivalent', 'topology', 'bounds']:
        log = run('sat-'+prop, ['/usr/local/bin/yosys', '-Q', '-T', '-p',
            f'read_verilog {rtl}; prep -top GroupProof -flatten; sat -verify -prove io_{prop} 1 -timeout 240'], O/'proof')
        assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log = run('sat-negative-mutation', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {rtl}; prep -top GroupProof -flatten; sat -verify -prove io_mutantEquivalent 1 -show-inputs -timeout 60'], O/'proof', negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_GENERATED_FOUR_INPUT_8BIT_KEYS_FOUR_BOUNDED_GRANULES_SEGMENT_SCATTER_TOPOLOGY', negative_mutation_rejected=True)
    rtl = elaborate('histogram', 'HistogramProbe'); sub = O/'histogram'
    cpp = sub/'boundary.cpp'; exact_text(cpp, boundary_cpp()); exe = sub/'obj/VHistogramProbe'
    run('boundary-compile', ['/usr/local/bin/verilator', '--cc', '--exe', '--build', '--top-module', 'HistogramProbe',
        '--Mdir', sub/'obj', '-j', 8, '--output-split', 10000, '--output-split-cfuncs', 200, '-Wno-fatal',
        '-CFLAGS', '-O0', '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', rtl, cpp], sub, [exe])
    log = run('boundary-run', [exe], sub)
    assert 'HISTOGRAM_ACTUAL_SIZE_PASS' in log.read_text()
    update(actual_size_boundary='PASS_8192_VECTORS_80_INPUTS_1024_OUTPUTS_256_BUCKETS_64BIT_OVERFLOW_RESET')
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
    update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL', rtl_sha256=sha(rtl))
    save(O/'verified-local.json', dict(hardware_commit=b['hardware_commit'], source_id=b['source_id'], rtl_sha256=sha(rtl),
        local_formal=st['local_formal'], actual_size_boundary=st['actual_size_boundary'],
        full_module_regression=st['full_module_regression'], outside_histogram_byte_equal=True, full_dut_formal=False))
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
