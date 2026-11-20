#!/usr/bin/python3
"""Validate and map the immutable bucket-index sharing candidate; no FPGA access."""
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
O = D/'build-logs/Opt4-fit-address-index-share-r1-bind2-20261111'
S = D/'Opt4-fit-address-index-share-r1-bind2-state.json'
REL = Path('chipyard/generators/boom/src/main/scala/lsu')
VIVADO = '/tools/Xilinx/Vivado/2021.1/bin/vivado'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
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
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def identity(pid):
    try:
        fields = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def live(item):
    current = identity(item.get('pid', 0))
    return bool(current and current.get('start_ticks') == str(item.get('start_ticks'))
                and current.get('host_boot_id') == item.get('host_boot_id')
                and current.get('process_state') not in ['Z', 'X'])


def guard(cfg):
    available = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                         if line.startswith('MemAvailable:')))
    return (available >= int(cfg['minimum_memory_gib']*2**20)
            and shutil.disk_usage(W).free >= int(cfg['minimum_disk_gib']*2**30))


def exact_text(path, value):
    path = Path(path)
    if path.exists():
        assert path.read_text() == value, f'immutable output conflict: {path}'
    else:
        path.write_text(value)


def cpp_boundary():
    assignments = '\n'.join(
        f'dut.io_sequences_{w}=sequence[{w}];' for w in range(88))
    checks = '\n'.join(
        f'if(dut.io_direct_{w} != ((sequence[{w}] & 255u) == bucket) || '
        f'dut.io_shared_{w} != dut.io_direct_{w}) fail(t,{w});' for w in range(88))
    return '''#include "VIndexMatchBoundary.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static void fail(unsigned t,unsigned w){std::fprintf(stderr,"INDEX_MATCH_FAIL vector=%u entry=%u\\n",t,w);std::exit(1);}
int main(int argc,char**argv){
Verilated::commandArgs(argc,argv);VIndexMatchBoundary dut;uint32_t sequence[88];
for(unsigned t=0;t<4096;t++){
 unsigned bucket=t%256;
 for(unsigned w=0;w<88;w++){
  unsigned low=0;
  switch(t%8){case 0:low=0;break;case 1:low=255;break;case 2:low=t%256;break;
   case 3:low=(t*37+w*13)%256;break;case 4:low=(255-t)%256;break;
   case 5:low=(w*17)%256;break;case 6:low=(t+w)%256;break;
   default:low=(t^(w*29))%256;break;}
  sequence[w]=((t*2654435761u+w*2246822519u)&0xffffff00u)|low;
 }
''' + assignments + '''
 dut.io_bucket=bucket;dut.eval();
''' + checks + '''
 if(!dut.io_equivalent)fail(t,88);
}
dut.final();std::puts("INDEX_MATCH_ACTUAL_SIZE_PASS vectors=4096 buckets=256 entries=88 seq_bits=32");return 0;}
'''


def parse_resources(path):
    result = {}
    for line in Path(path).read_text().splitlines():
        m = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|', line)
        if m:
            result.setdefault(m[1].rstrip('*'), float(m[2].replace(',', '')))
    assert set(result) == {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    assert result['CLB LUTs'] > 0
    return result


def main():
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    cfg = read(C/'config.json')
    binding = cfg['binding']
    F = Path(cfg['worktree'])
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt the live controller/child'
    inputs = read(C/'input-hashes.json')
    assert all(sha(path) == digest for path, digest in inputs.items()), 'immutable input hash mismatch'
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert commit == binding['hardware_commit'] == '470f1291d01608e80be6cd8d42b29fc5fc28d395'
    changed = subprocess.check_output(['git', 'diff', '--name-only', binding['parent_commit'], commit],
                                      cwd=F, text=True).splitlines()
    assert changed == [str(REL/'PackageAddressStats.scala')], changed
    source = F/REL/'PackageAddressStats.scala'
    assert source.read_bytes() == subprocess.check_output(
        ['git', 'show', commit+':'+str(REL/'PackageAddressStats.scala')], cwd=F)
    baseline = (C/'parent-PackageAddressStats.scala').read_text()
    candidate = source.read_text()
    assert 'packageWays: Int = 8' in candidate and 'strictOverflowEntries = packageWays * 8' in candidate
    assert 'packetIndexBits = log2Ceil(packetWindow)' in candidate
    assert 'val packageBucketIndexMatch' in candidate and 'val strictBucketIndexMatch' in candidate
    assert baseline.count('idx === i.U') == 4
    assert candidate.count('idx === i.U') == 0
    st = dict(schema='ec-opt4-address-index-share-validation/1', **identity(os.getpid()),
              hardware_commit=commit, source_id=binding['source_id'], input_sha256=inputs,
              status='STARTING', started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
              stages=old.get('stages', {}), full_dut_synthesis=False, formal_admission=False,
              production_selected=False, fpga_access=False,
              proof_scope='Arbitrary 32-bit sequence/8-bit slot SAT cut, full 256-slot x 88-entry boundary simulation, and finite 6144-cycle x 52-output comparison against the frozen module. No full-DUT formal equivalence.')
    save(S, st)
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'JAVA_TOOL_OPTIONS': '',
           'OMP_NUM_THREADS': '4', 'MAKEFLAGS': '-j8'}

    def update(**kwargs):
        st.update(kwargs)
        st['updated_utc'] = dt.datetime.now(dt.timezone.utc).isoformat()
        save(S, st)

    def run(label, argv, directory, outputs=(), negative=False):
        directory = Path(directory)
        directory.mkdir(parents=True, exist_ok=True)
        receipt_path = directory/(label+'-result.json')
        receipt = read(receipt_path)
        if receipt:
            assert receipt.get('hardware_commit') == commit and receipt.get('source_id') == binding['source_id']
            assert receipt.get('accepted_result') and not receipt.get('missing_outputs'), 'failed stage requires a new recovery controller'
            assert all(sha(path) == digest for path, digest in receipt.get('outputs', {}).items())
            st['stages'][label] = receipt
            save(S, st)
            return Path(receipt['log'])
        while not guard(cfg):
            update(status='WAITING_RESOURCE_GATE', next_stage=label)
            time.sleep(30)
        log = directory/(label+'-attempt-1.log')
        assert not log.exists(), f'incomplete previous attempt requires review: {log}'
        args = list(map(str, ['nice', '-n', '10', *argv]))
        with log.open('xb', buffering=0) as stream:
            child = subprocess.Popen(args, cwd=directory, env=env, stdin=subprocess.DEVNULL,
                                     stdout=stream, stderr=subprocess.STDOUT, start_new_session=True)
            child_identity = identity(child.pid)
            stage = dict(hardware_commit=commit, source_id=binding['source_id'], argv=args,
                         log=str(log), started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                         **child_identity, returncode=None)
            st['stages'][label] = stage
            update(status='RUNNING_'+label.upper(), child=child_identity, active_stage=label)
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update()
                os.fsync(stream.fileno())
        accepted = child.returncode != 0 if negative else child.returncode == 0
        stage.update(returncode=child.returncode, accepted_result=accepted, negative=negative,
                     ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                     outputs={str(path): sha(path) for path in outputs if Path(path).is_file()},
                     missing_outputs=[str(path) for path in outputs if not Path(path).is_file()])
        save(receipt_path, stage)
        st['stages'][label] = stage
        update(child={})
        assert accepted and not stage['missing_outputs'], (label, child.returncode, str(log))
        return log

    classes = O/'classes'
    classes.mkdir(exist_ok=True)
    rel = F/REL
    cp = str(classes)+':'+':'.join(cfg['classpath'])
    run('compile', [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4',
        '-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']),
        '-Xplugin:'+cfg['plugin'], '-d', classes, rel/'PackageAddressStats.scala', C/'EmitIndexShare.scala'],
        O, [classes/'opt4index/EmitIndexShare.class'])

    def elaborate(mode, top):
        out = O/mode
        out.mkdir(exist_ok=True)
        rtl = out/(top+'.v')
        run('elaborate-'+mode, [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4',
            '-cp', cp, 'opt4index.EmitIndexShare', mode, out], out, [rtl])
        return rtl

    proof = elaborate('proof', 'IndexMatchProof')
    log = run('sat-index-match', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {proof}; prep -top IndexMatchProof -flatten; sat -verify -prove io_equivalent 1 -timeout 180'], O/'proof')
    assert 'SUCCESS' in log.read_text() and 'timed out' not in log.read_text()
    log = run('sat-negative-mutation', ['/usr/local/bin/yosys', '-Q', '-T', '-p',
        f'read_verilog {proof}; prep -top IndexMatchProof -flatten; sat -verify -prove io_mutantEquivalent 1 -show-inputs -timeout 60'],
        O/'proof', negative=True)
    assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
    update(local_formal='PASS_ARBITRARY_32BIT_SEQUENCE_8BIT_BUCKET', negative_mutation_rejected=True)

    boundary = elaborate('boundary', 'IndexMatchBoundary')
    sim = O/'boundary'
    cpp = sim/'boundary.cpp'
    exact_text(cpp, cpp_boundary())
    exe = sim/'obj/VIndexMatchBoundary'
    run('boundary-compile', ['/usr/local/bin/verilator', '--cc', '--exe', '--build',
        '--top-module', 'IndexMatchBoundary', '--Mdir', sim/'obj', '-j', 4,
        '--output-split', 10000, '--output-split-cfuncs', 200, '-Wno-fatal',
        '-CFLAGS', '-O0', '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', boundary, cpp], sim, [exe])
    log = run('boundary-run', [exe], sim)
    assert 'INDEX_MATCH_ACTUAL_SIZE_PASS' in log.read_text()
    update(actual_size_boundary='PASS_4096_VECTORS_256_BUCKETS_88_ENTRIES_32BIT_SEQUENCE')

    address = elaborate('address', 'PackageAddressStats')
    compare = O/'compare'
    compare.mkdir(exist_ok=True)
    for src, dst in [(C/'frozen-original.v', compare/'original.v'), (C/'frozen-tb.v', compare/'tb.v')]:
        if dst.exists():
            assert dst.read_bytes() == src.read_bytes(), f'frozen comparison input mismatch: {dst}'
        else:
            shutil.copy2(src, dst)
    exe = compare/'obj/Vtb'
    run('compare-compile', ['/usr/local/bin/verilator', '--binary', '--timing', '--top-module', 'tb',
        '--Mdir', compare/'obj', '-j', 8, '--output-split', 10000, '--output-split-cfuncs', 200,
        '--x-initial', 0, '--x-assign', 0, '-Wno-fatal', '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT',
        "-DRANDOM=32'h0", '-CFLAGS', '-O0', '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0',
        compare/'original.v', address, compare/'tb.v'], compare, [exe])
    log = run('compare', [exe], compare)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
    update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FORMAL', rtl_sha256=sha(address),
           frozen_reference_sha256=sha(compare/'original.v'), frozen_testbench_sha256=sha(compare/'tb.v'))
    save(O/'verified-local.json', dict(hardware_commit=commit, source_id=binding['source_id'],
        rtl_sha256=sha(address), frozen_reference_sha256=sha(compare/'original.v'),
        frozen_testbench_sha256=sha(compare/'tb.v'), local_formal=st['local_formal'],
        actual_size_boundary=st['actual_size_boundary'], full_module_regression=st['full_module_regression'],
        full_dut_formal=False, fpga_access=False))

    sub = O/'map-full-module'
    sub.mkdir(exist_ok=True)
    report = sub/'utilization.rpt'
    dcp = sub/'module.dcp'
    tcl = sub/'map.tcl'
    script = ('set_param general.maxThreads 4\n'
        + f'read_verilog {{{address}}}\n'
        + 'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        + f'report_utilization -file {{{report}}}\n'
        + f'report_utilization -hierarchical -file {{{sub/"hierarchical.rpt"}}}\n'
        + f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
    exact_text(tcl, script)
    run('map-full-module', [VIVADO, '-mode', 'batch', '-nojournal', '-log', sub/'vivado.log', '-source', tcl],
        sub, [report, dcp])
    resources = parse_resources(report)
    mapped = dict(scope='OOC module only; not whole-DUT FIT', resources=resources,
        report=str(report), report_sha256=sha(report), checkpoint=str(dcp), checkpoint_sha256=sha(dcp),
        rtl_sha256=sha(address), tcl_sha256=sha(tcl))
    update(status='VERIFIED_AND_MAPPED_MODULE_ONLY', full_module_map=mapped,
           ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(), child={})
    save(O/'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        state = read(S)
        if state and state.get('pid') == os.getpid():
            state.update(status='FAILED_WITH_EVIDENCE', error=repr(error),
                         ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(S, state)
        raise
