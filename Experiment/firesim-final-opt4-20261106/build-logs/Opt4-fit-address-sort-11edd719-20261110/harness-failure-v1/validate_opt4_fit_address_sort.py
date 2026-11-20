#!/usr/bin/env python3
"""Independent shared scatter reduction: prove, regress, map; never promote.

Service checkpoints bind exact committed source and generated artifacts. The
live 8da whole-system and c41 module workers/inputs are never modified.
"""
from pathlib import Path
import concurrent.futures
import datetime as dt
import fcntl
import json
import os
import shutil
import signal
import subprocess
import threading
import time

from board_batch import W, D, save, sha
from job_service import proc, boot
from prepare_opt4_fit_modules import JAVA, CACHE, CPFILE
from summarize_opt4_fit import resources

F = W / 'Opt4-fit-address-sort-20261110'
COMMIT = '11edd71981aa30ff3a26aab1f2f7327ac0266ee1'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
O = D / 'build-logs/Opt4-fit-address-sort-11edd719-20261110'
S = D / 'Opt4-fit-address-sort-state.json'
now = lambda: dt.datetime.now(dt.timezone.utc).isoformat()

WRAPPER = '''package opt4fit
import chisel3._
import chisel3.util._
class Scatter(n: Int, buckets: Int, reference: Boolean) extends RawModule {
  val io = IO(new Bundle {
    val keys = Input(UInt((n*log2Ceil(buckets)).W))
    val terms = Input(UInt((n*9).W))
    val result = Output(UInt((buckets*256).W))
  })
  val kb = log2Ceil(buckets)
  val keys = (0 until n).map(i => io.keys((i+1)*kb-1,i*kb))
  val widths = Seq(4,2,2,1)
  val offsets = Seq(0,4,6,8)
  val values = (0 until n).map(i => widths.indices.map(g =>
    io.terms(i*9+offsets(g)+widths(g)-1,i*9+offsets(g))))
  val out = if (!reference) boom.lsu.AddressBucketReduction(keys,values,Seq(8,3,2,1),buckets)
    else (0 until buckets).map(b => widths.indices.map(g =>
      keys.indices.map(i => Mux(keys(i) === b.U,values(i)(g).pad(64),0.U(64.W))).reduce(_ + _)))
  io.result := VecInit(out.map(x => VecInit(x))).asUInt
}
class SortZeroOne extends RawModule {
  val io = IO(new Bundle { val keys = Input(UInt(128.W)); val ok = Output(Bool()) })
  val keys = (0 until 128).map(i => io.keys(i).asUInt)
  val sorted = boom.lsu.AddressBucketReduction.sortRows(keys,keys.map(_ => Seq(0.U(1.W))),Seq(1),1)
  io.ok := (0 until 127).map(i => sorted(i)._1 <= sorted(i+1)._1).reduce(_ && _)
}
class ComparatorProof extends RawModule {
  val io = IO(new Bundle { val keys = Input(UInt(16.W)); val terms = Input(UInt(18.W)); val ok = Output(Bool()) })
  val keys = Seq(io.keys(7,0),io.keys(15,8))
  val terms = Seq(Seq(io.terms(8,0)),Seq(io.terms(17,9)))
  val s = boom.lsu.AddressBucketReduction.sortRows(keys,terms,Seq(9),8)
  val before = keys.zip(terms).map { case (k,v) => Cat(0.U(1.W),k,v.head) }
  val after = s.map { case (k,v) => Cat(k,v.head) }
  io.ok := (s(0)._1 <= s(1)._1) &&
    ((after(0) === before(0) && after(1) === before(1)) ||
     (after(0) === before(1) && after(1) === before(0)))
}
object EmitSort extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
    case "zero-one" => stage.emitVerilog(new SortZeroOne,Array("--target-dir",args(1)))
    case "comparator" => stage.emitVerilog(new ComparatorProof,Array("--target-dir",args(1)))
    case mode => stage.emitVerilog(new Scatter(args(2).toInt,args(3).toInt,mode == "reference"),Array("--target-dir",args(1)))
  }
}
'''

CPP = r'''#include "VScatter.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng = 0x736f72742d383000ULL;
static uint32_t next32() { rng ^= rng<<13; rng ^= rng>>7; rng ^= rng<<17; return uint32_t(rng); }
template<class T> static void put(T &p,int bit,int width,uint32_t x) {
  for(int b=0;b<width;b++) { uint32_t m=1u<<((bit+b)%32); auto &w=p[(bit+b)/32]; w=(w&~m)|((x&(1u<<b))?m:0); }
}
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv); VScatter dut; const int bound[]={8,3,2,1}, widths[]={4,2,2,1}, offset[]={0,4,6,8};
  for(int trial=0;trial<8192;trial++) {
    for(auto &w:dut.io_keys)w=0; for(auto &w:dut.io_terms)w=0;
    uint64_t expected[256][4]={};
    for(int i=0;i<80;i++) {
      int key;
      switch(trial%8) {
        case 0:key=255;break; case 1:key=trial%256;break;
        case 2:key=i%3;break; case 3:key=255-i;break;
        case 4:key=i;break; default:key=next32()%256;
      }
      put(dut.io_keys,i*8,8,key);
      for(int g=0;g<4;g++) {
        int count=(trial%8==0)?bound[g]:int(next32()%(bound[g]+1));
        if(trial%8==1 && i!=trial%80)count=0;
        put(dut.io_terms,i*9+offset[g],widths[g],count); expected[key][g]+=count;
      }
    }
    dut.eval();
    for(int b=0;b<256;b++)for(int g=0;g<4;g++) {
      int word=b*8+g*2; uint64_t got=(uint64_t(dut.io_result[word+1])<<32)|dut.io_result[word];
      if(got!=expected[b][g]) { std::fprintf(stderr,"SCATTER_MISMATCH trial=%d bucket=%d granule=%d expected=%llu got=%llu\n",trial,b,g,(unsigned long long)expected[b][g],(unsigned long long)got); return 2; }
    }
  }
  puts("SCATTER_80_256_PASS vectors=8192 outputs_per_vector=1024 full_count_bounds=8,3,2,1"); return 0;
}
'''


def main():
    lock = (D / '.opt4-fit-address-sort.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    binding = json.loads((F / 'candidate-binding.json').read_text())
    assert binding['hardware_commit'] == COMMIT
    sources = []
    for name in ['PackageAddressStats.scala', 'AddressBucketReduction.scala']:
        content = subprocess.check_output(['git', 'show', COMMIT + ':' + REL + name], cwd=F)
        path = O / name
        if path.exists():
            assert path.read_bytes() == content
        else:
            path.write_bytes(content)
        sources.append(path)
    parent = subprocess.check_output(['git', 'show', binding['parent_commit'] + ':' + REL + 'PackageAddressStats.scala'], cwd=F, text=True)
    candidate = sources[0].read_text()
    def outside(text):
        start = text.index('  val bucketLoadFirstDelta =')
        end = text.index('  val evictedLoadFirst', start)
        return text[:start] + text[end:]
    assert outside(parent) == outside(candidate), 'state/error/event/cycle logic changed'
    bound_proof = json.loads((D / 'Opt4-fit-address-round3-state.json').read_text())['tests']['touch_bounds']
    assert bound_proof['status'] == 'PASS_UNIVERSAL_96_INPUT_BITS'
    assert bound_proof['bounds'] == [8, 3, 2, 1]
    st = dict(schema='ec-opt4-fit-address-sort/1', status='STARTING', pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'], host_boot_id=boot(),
        hardware_commit=COMMIT, source_id=binding['source_id'], started_utc=now(),
        source_sha256={p.name: sha(p) for p in sources}, stages={},
        invariant_outside_bucket_delta_unchanged=True, fpga_access=False,
        full_dut_synthesis=False, formal_admission=False, production_selected=False,
        proof_scope='Actual generated comparator and 128-input zero-one topology; small scatter SAT; real 80x256 regression; frozen full-module cycle comparison. Not full-DUT formal equivalence.')
    mutex = threading.RLock()
    def update(**kwargs):
        with mutex:
            st.update(kwargs); save(S, st)
    update()
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'JAVA_TOOL_OPTIONS': '', 'OMP_NUM_THREADS': '4'}
    def run(label, argv, cwd, outputs=(), timeout=3600, expect_failure=False):
        receipt = cwd / (label + '-result.json')
        if receipt.exists():
            r = json.loads(receipt.read_text())
            assert r['hardware_commit'] == COMMIT and r['accepted_result']
            assert all(sha(p) == h for p, h in r['outputs'].items())
            with mutex:
                st['stages'][label] = r; save(S, st)
            return Path(r['log'])
        attempt = len(list(cwd.glob(label + '-attempt-*.log'))) + 1
        log = cwd / (label + f'-attempt-{attempt}.log')
        args = list(map(str, ['nice', '-n', '10', *argv]))
        with log.open('ab', buffering=0) as stream:
            child = subprocess.Popen(args, cwd=cwd, env=env, stdin=subprocess.DEVNULL,
                stdout=stream, stderr=subprocess.STDOUT, start_new_session=True)
            record = dict(hardware_commit=COMMIT, argv=args, log=str(log),
                started_utc=now(), pid=child.pid, start_ticks=proc(child.pid)['start_ticks'], returncode=None)
            with mutex:
                st['stages'][label] = record; st['status'] = 'RUNNING_' + label.upper(); save(S, st)
            started = time.monotonic()
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update(updated_utc=now())
                os.fsync(stream.fileno())
                if child.poll() is None and (time.monotonic() - started > timeout or shutil.disk_usage(O).free < 60 * 2**30):
                    os.killpg(child.pid, signal.SIGTERM)
                    try:
                        child.wait(timeout=30)
                    except subprocess.TimeoutExpired:
                        os.killpg(child.pid, signal.SIGKILL); child.wait()
                    raise RuntimeError(label + ' independent candidate guard; evidence retained')
        accepted = (child.returncode != 0) if expect_failure else (child.returncode == 0)
        record.update(returncode=child.returncode, accepted_result=accepted,
            expected_failure=expect_failure, outputs={str(p): sha(p) for p in outputs}, ended_utc=now())
        save(receipt, record)
        with mutex:
            st['stages'][label] = record; save(S, st)
        assert accepted, (label, child.returncode, str(log))
        return log

    cp = CPFILE.read_text().strip()
    classes = O / 'classes'; classes.mkdir(exist_ok=True)
    compiler = [CACHE / 'org/scala-lang' / n / '2.13.10' / (n + '-2.13.10.jar')
                for n in ['scala-compiler', 'scala-library', 'scala-reflect']]
    plugin = CACHE / 'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    emit = O / 'EmitSort.scala'; emit.write_text(WRAPPER)
    run('compile', [JAVA, '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', ':'.join(map(str, compiler)),
        'scala.tools.nsc.Main', '-classpath', cp, '-Xplugin:' + str(plugin), '-d', classes, *sources, emit], O, [emit], 1800)
    def elaborate(label, mode, directory, extra=(), top='Scatter'):
        directory.mkdir(exist_ok=True)
        run(label, [JAVA, '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4', '-cp', str(classes) + ':' + cp,
            'opt4fit.EmitSort', mode, directory, *extra], directory, [directory / (top + '.v')], 1800)
    def sat(label, directory, script, expected_failure=False):
        log = run(label, ['/usr/local/bin/yosys', '-Q', '-T', '-p', script], directory, [], 300, expected_failure)
        content = log.read_text()
        if expected_failure:
            assert 'proof did fail' in content and 'timed out' not in content
        else:
            assert 'SUCCESS' in content
    for mode, top in [('comparator', 'ComparatorProof'), ('zero-one', 'SortZeroOne')]:
        sub = O / mode
        elaborate('elaborate-' + mode, mode, sub, top=top)
        sat('proof-' + mode, sub, f'read_verilog {sub / (top + ".v")}; prep -top {top} -flatten; sat -verify -prove io_ok 1 -timeout 240')
    for n in [3, 4]:
        sub = O / ('proof' + str(n)); sub.mkdir(exist_ok=True)
        a, b = sub / 'reference', sub / 'candidate'
        elaborate('elaborate-reference' + str(n), 'reference', a, [n, 4])
        elaborate('elaborate-candidate' + str(n), 'candidate', b, [n, 4])
        reference = sub / 'reference.v'
        reference.write_text((a / 'Scatter.v').read_text().replace('module Scatter(', 'module Reference('))
        bounds = []
        for i in range(n):
            for offset, width, maximum in [(0, 4, 8), (4, 2, 3), (6, 2, 2), (8, 1, 1)]:
                bounds.append(f'(terms[{i*9+offset+width-1}:{i*9+offset}] <= {maximum})')
        miter = sub / 'miter.v'
        miter.write_text(f'module Miter(input [{n*2-1}:0] keys,input [{n*9-1}:0] terms,output ok);'
            + 'wire [1023:0] a,b; Reference r(keys,terms,a); Scatter c(keys,terms,b);'
            + 'wire valid=' + ' && '.join(bounds) + '; assign ok=!valid || a==b; endmodule\n')
        prefix = f'read_verilog {reference} {b / "Scatter.v"} {miter}; prep -top Miter -flatten; '
        sat('proof-scatter' + str(n), sub, prefix + 'sat -verify -prove ok 1 -timeout 240')
        if n == 3:
            bad = sub / 'negative.v'
            bad.write_text(miter.read_text().replace('a==b', "a==(b ^ 1024'b1)"))
            sat('proof-negative', sub, f'read_verilog {reference} {b / "Scatter.v"} {bad}; prep -top Miter -flatten; sat -verify -prove ok 1 -timeout 60', True)
    update(status='LOCAL_FORMAL_PASSED_REAL_SIZE_VALIDATION_PENDING', local_formal='PASS', negative_mutation_rejected=True)
    micro = O / 'micro80'
    elaborate('elaborate-micro80', 'candidate', micro, [80, 256])
    cpp = micro / 'oracle.cpp'; cpp.write_text(CPP)
    exe = micro / 'obj/VScatter'
    run('micro80-compile', ['/usr/local/bin/verilator', '--cc', '--exe', '--build', '-j', 4,
        '--top-module', 'Scatter', '--Mdir', micro / 'obj', '-Wno-fatal', '--output-split', 10000,
        '--output-split-cfuncs', 200, '-CFLAGS', '-O1', micro / 'Scatter.v', cpp], micro, [exe], 3600)
    log = run('micro80-oracle', [exe], micro, [], 1800)
    assert 'SCATTER_80_256_PASS' in log.read_text()
    update(real_size_combinational_regression='PASS_8192_VECTORS_1024_OUTPUTS')
    def map_rtl(label, rtl, top, sub):
        sub.mkdir(exist_ok=True)
        tcl = sub / 'map.tcl'; report = sub / 'utilization.rpt'; dcp = sub / 'module.dcp'
        tcl.write_text('set_param general.maxThreads 4\n' + f'read_verilog {{{rtl}}}\n'
            + f'synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
            + f'report_utilization -file {{{report}}}\nreport_utilization -hierarchical -file {{{sub / "hierarchical.rpt"}}}\n'
            + f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
        run(label, ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
            '-log', sub / 'vivado.log', '-source', tcl], sub, [report, dcp], 86400)
        return dict(resources=resources(report), report=str(report), report_sha256=sha(report))
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        future = pool.submit(map_rtl, 'map-micro80', micro / 'Scatter.v', 'Scatter', micro / 'map')
        full = O / 'full-address'
        elaborate('elaborate-full-address', 'address', full, top='PackageAddressStats')
        rtl = full / 'PackageAddressStats.v'
        compare = O / 'compare'; compare.mkdir(exist_ok=True)
        fixtures = D / 'build-logs/Opt4-fit-modules-20261110/verification'
        for src, dst in [('address-original.v', 'original.v'), ('address-tb.v', 'tb.v')]:
            target = compare / dst
            if target.exists():
                assert target.read_bytes() == (fixtures / src).read_bytes()
            else:
                shutil.copy2(fixtures / src, target)
        exe = compare / 'obj/Vtb'
        run('compare-compile', ['/usr/local/bin/verilator', '--binary', '--timing', '--top-module', 'tb',
            '--Mdir', compare / 'obj', '-j', 4, '--output-split', 10000, '--output-split-cfuncs', 200,
            '--x-initial', '0', '--x-assign', '0', '-Wno-fatal', '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT',
            "-DRANDOM=32'h0", '-CFLAGS', '-O0', compare / 'original.v', rtl, compare / 'tb.v'], compare, [exe], 7200)
        log = run('compare', [exe], compare, [], 1800)
        assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in log.read_text()
        update(full_module_regression='PASS_6144_CYCLES_52_OUTPUTS_NOT_FULL_FORMAL', rtl_sha256=sha(rtl))
        micro_map = future.result()
        update(micro_map=micro_map)
    whole_module = map_rtl('map-full-address', rtl, 'PackageAddressStats', full / 'map')
    update(status='VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED', full_module_map=whole_module, ended_utc=now())
    save(O / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            st = json.loads(S.read_text()); st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now()); save(S, st)
        raise
