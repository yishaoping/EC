#!/usr/bin/env python3
"""Inject one ARF snapshot bit in a private harness linked to sealed C1 objects.

Never recompiles or changes the hardware model. This is a fault-path probe, not
an architectural restoration oracle. A FAIL or ACK alone cannot pass recovery.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import shlex
import subprocess

ROOT = Path(__file__).resolve().parents[3]
BASE = Path('/data1/gzh/EC-opt4-recovery-perf')
BUILD = BASE / 'slowdown/optimization_6_overlap/build/overlap_checker_icache4k_20261104_021411_630679e4'
MODEL = BUILD / 'generated/chipyard.TestHarness.v1Config'
D = 'TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__'


def sha(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda: f.read(1048576), b''):
            h.update(b)
    return h.hexdigest()


def harness():
    # Explicit field references preserve the exact identity of the sealed model.
    lines = ['#include "VTestHarness___024root.h"', '#include <array>',
             '#include <cstdint>', '#include <cstdlib>', '''
struct RecoverySlot { unsigned valid, state, seq, generation; uint64_t line; std::array<uint32_t,16> data; };
static std::array<RecoverySlot,16> slots(VTestHarness___024root* r) {
  std::array<RecoverySlot,16> s{};''']
    for i in range(16):
        p = 'r->' + D + f'svb__DOT__'
        lines += [f's[{i}].valid={p}valid_{i}; s[{i}].state={p}state_{i};',
                  f's[{i}].seq={p}key_{i}_contentSeq; s[{i}].generation={p}key_{i}_generation;',
                  f's[{i}].line={p}line_{i};']
        for j in range(4):
            for k in range(4):
                lines += [f's[{i}].data[{j*4+k}]={p}data_{i}_{j}[{k}];']
    lines += ['return s; }', '''
static void dump_slots(const char* event, uint64_t cycle, VTestHarness___024root* r) {
  const auto s=slots(r);
  for (unsigned i=0;i<16;i++) if(s[i].valid) {
    fprintf(stderr,"RECOVERY_SLOT event=%s tick=%llu entry=%u state=%u seq=%u generation=%u line=%llx data=",
      event,(unsigned long long)cycle,i,s[i].state,s[i].seq,s[i].generation,(unsigned long long)s[i].line);
    for(auto x:s[i].data) fprintf(stderr,"%08x",x);
    fputc('\n',stderr);
  }
  fflush(stderr);
}
static void recovery_probe(VTestHarness* tile, uint64_t cycle, bool before_edge) {
  static bool enabled=std::getenv("EC_REAL_FAULT_PROBE");
  if(!enabled || tile->reset) return;
  auto* r=tile->rootp;
  static std::array<RecoverySlot,16> prev{};
  static std::array<uint64_t,16> since{};
  static bool injected=false, mismatch=false, accepted=false;
  static unsigned minimum_watermark=std::getenv("EC_FAULT_MIN_WATERMARK") ? std::strtoul(std::getenv("EC_FAULT_MIN_WATERMARK"),nullptr,0) : 0;
  static bool require_wb=std::getenv("EC_FAULT_REQUIRE_WB");
  static uint64_t inject_tick=0, fail_tick=0;
  static unsigned fault_hart=0, fault_seq=0;
  auto s=slots(r);
''', f'const unsigned watermark=r->{D}debug_safe_packet_watermark;',
              f'const unsigned fail_seq=r->{D}barrierFailureSeq;',
              f'const unsigned fail_now=r->{D}barrierFailureAny;',
              f'const unsigned flush=r->{D}svbFlush;']
    lines += ['''
  if(before_edge) {
    bool persistent=false, wb_wait=false;
    for(unsigned i=0;i<16;i++) {
      persistent |= s[i].valid && s[i].state==1 && s[i].seq>watermark && cycle-since[i]>=1024;
      wb_wait |= s[i].valid && s[i].state==2;
    }
    if(!injected && persistent && watermark>=minimum_watermark && (!require_wb || wb_wait)) {
''']
    for h in range(1,5):
        p = 'r->' + f'TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_{h}__DOT__tile_reset_domain_tile__DOT__core__DOT__'
        lines += [f'''if(!injected && {p}package_check_active && {p}rsu_slave__DOT__do_check &&
          {p}rsu_slave__DOT__compare_read_valid && {p}rsu_slave__DOT__checking_counter_memdelay>=1 &&
          {p}rsu_slave__DOT__checking_counter_memdelay<=8) {{
        dump_slots("before_injection",cycle,r);
        uint64_t old={p}rsu_slave__DOT__checker_arfs_snapshot_31;
        {p}rsu_slave__DOT__checker_arfs_snapshot_31 ^= 1ULL;
        injected=true; inject_tick=cycle; fault_hart={h}; fault_seq={p}package_seq_reg;
        fprintf(stderr,"RECOVERY_INJECT tick=%llu hart=%u seq=%u register=31 old=%llx new=%llx watermark=%u retention_min_ticks=1024\\n",
          (unsigned long long)cycle,fault_hart,fault_seq,(unsigned long long)old,(unsigned long long)(old^1ULL),watermark);
        fflush(stderr);
      }}''']
    lines += ['}']
    for h in range(1,5):
        p = 'r->' + f'TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_{h}__DOT__tile_reset_domain_tile__DOT__core__DOT__'
        lines += [f'''if(injected && fault_hart=={h} && !mismatch && {p}rsu_slave__DOT__compare_error_accum) {{
          mismatch=true; fprintf(stderr,"RECOVERY_REAL_COMPARATOR_ERROR tick=%llu hart=%u seq=%u\\n",(unsigned long long)cycle,fault_hart,fault_seq); fflush(stderr);
        }}''']
    lines += ['''
    if(injected && fail_now && !accepted) {
      fprintf(stderr,"RECOVERY_FAIL_ACCEPT_EDGE tick=%llu fault_seq=%u watermark=%u flush=%u\n",(unsigned long long)cycle,fault_seq,watermark,flush);
      dump_slots("before_FAIL_edge",cycle,r);
    }
  } else {
    if(injected && fail_seq && !accepted) {
      accepted=true; fail_tick=cycle;
      fprintf(stderr,"RECOVERY_FAIL_STICKY tick=%llu failed_seq=%u watermark=%u\n",(unsigned long long)cycle,fail_seq,watermark);
      dump_slots("after_FAIL_edge",cycle,r);
    }
    for(unsigned i=0;i<16;i++) {
      bool same=prev[i].valid && s[i].valid && prev[i].seq==s[i].seq && prev[i].generation==s[i].generation && prev[i].line==s[i].line;
      if(injected && prev[i].valid && !same)
        fprintf(stderr,"RECOVERY_SLOT_REMOVED tick=%llu entry=%u old_seq=%u old_generation=%u old_state=%u failed_seq=%u watermark=%u flush=%u\n",
          (unsigned long long)cycle,i,prev[i].seq,prev[i].generation,prev[i].state,fail_seq,watermark,flush);
      if(!same) since[i]=cycle;
      prev[i]=s[i];
    }
    if(injected && ((accepted && cycle-fail_tick>=4096) || cycle-inject_tick>=20000)) {
      dump_slots("probe_end",cycle,r);
      fprintf(stderr,"RECOVERY_PROBE_END injected=1 comparator_error=%u accepted_FAIL=%u restoration=UNPROVEN no_architectural_restore_oracle=1\n",mismatch,accepted);
      fflush(stderr); std::exit(86);
    }
  }
}
''']
    # Escape C newlines in the two non-f-string snippets above.
    return '\n'.join(lines).replace("fputc('\n',stderr)", "fputc('\\n',stderr)").replace('\n",', '\\n",')


def main():
    global BUILD, MODEL
    parser=argparse.ArgumentParser()
    parser.add_argument('--candidate',choices=['1','2'],default='1')
    parser.add_argument('--min-watermark',type=int,default=0)
    parser.add_argument('--require-wb',action='store_true')
    args=parser.parse_args()
    hardware_commit='2b0ea7ff07be09447a1f540c8682b85d15b4a82f'
    if args.candidate=='2':
        BUILD=Path('/data1/gzh/EC-opt4-recovery-rescue/slowdown/optimization_6_overlap/build/overlap_svb_rescue_r2_20261104_042210_dc665532')
        MODEL=BUILD/'generated/chipyard.TestHarness.v1Config'
        hardware_commit='ae0d80a65a5d890b59e4c67575c0cb6af59730ae'
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S')
    out=ROOT/'slowdown/recovery_perf_20261104/build'/('real_checker_fault_'+stamp)
    out.mkdir(parents=True)
    src=(BUILD/'generated/gen-collateral/emulator.cc').read_text()
    # Insert after all headers, before the original entry point.
    pos=src.index('int main(')
    src=src[:pos]+harness()+'\n'+src[pos:]
    needle='  do {\n    tile->clock = 0;\n    tile->eval();'
    assert src.count(needle)==1
    src=src.replace(needle,needle+'\n    recovery_probe(tile, trace_count, true);')
    needle='    tile->clock = 1;\n    tile->eval();'
    pos=src.index(needle,src.index('  do {'))
    src=src[:pos]+src[pos:].replace(needle,needle+'\n    recovery_probe(tile, trace_count, false);',1)
    source=out/'emulator_fault.cc'; source.write_text(src)
    log=(BUILD/'verilator_build.log').read_text().splitlines()
    compile=shlex.split(next(l for l in log if '-o emulator.o ' in l and 'emulator.cc' in l))
    if Path(compile[0]).name=='ccache': compile=compile[1:]
    compile[compile.index('-o')+1]=str(out/'emulator_fault.o')
    compile[-1]=str(source)
    compile.extend(['-I'+str(MODEL)])
    link=shlex.split(next(l for l in log if l.startswith('clang++ ') and 'VTestHarness__ALL.a' in l))
    for i,a in enumerate(link):
        if a.endswith(('.o','.a')): link[i]=str(out/'emulator_fault.o') if a=='emulator.o' else str(MODEL/a)
    link[link.index('-o')+1]=str(out/'simulator_fault')
    env=dict(os.environ,PATH='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin:/usr/bin:/bin')
    meta=dict(scope='Private harness: genuine checker ARF mismatch while unsafe SPEC snapshot persists >=1024 harness ticks. Never a rollback pass without restored data.',
              hardware_commit=hardware_commit, candidate=args.candidate,minimum_watermark=args.min_watermark,require_wb=args.require_wb,compile=compile,link=link,
              source_sha256=sha(source),model_archive_sha256=sha(MODEL/'VTestHarness__ALL.a'))
    (out/'manifest.json').write_text(json.dumps(meta,indent=2)+'\n')
    with (out/'build.log').open('xb') as f:
        for cmd in [compile,link]: subprocess.run(cmd,cwd=out,env=env,stdout=f,stderr=subprocess.STDOUT,check=True)
    sw=BASE/'slowdown/parsec_evaluation_20261103/build/streamcluster_simdev'
    cmd=[str(out/'simulator_fault'),'-s','1','+cycle-count','+permissive','+safe-chain-events','+safe-chain-budgeted','+cache-opportunity','+dramsim',
         '+dramsim_ini_dir='+str(BASE/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'),'+max-cycles=2500000',
         '+loadmem='+str(sw/'protected.loadmem_hex'),'+loadmem_addr=80000000','+permissive-off',str(sw/'protected.riscv')]
    env['EC_REAL_FAULT_PROBE']='1'
    env['EC_FAULT_MIN_WATERMARK']=str(args.min_watermark)
    if args.require_wb:env['EC_FAULT_REQUIRE_WB']='1'
    # A private supervisor records actual process exit after this launcher exits.
    supervisor=out/'supervise.py'
    supervisor.write_text('''import json,subprocess,sys,datetime
from pathlib import Path
out=Path(__file__).resolve().parent
cmd=json.loads((out/'command.json').read_text())
p=subprocess.Popen(cmd,stdout=sys.stdout,stderr=sys.stderr)
rc=p.wait()
(out/'exit.json').write_text(json.dumps(dict(exit_status=rc,end_utc=datetime.datetime.now(datetime.timezone.utc).isoformat()))+'\\n')
''')
    (out/'command.json').write_text(json.dumps(cmd)+'\n')
    with (out/'stdout.log').open('xb') as stdout, (out/'stderr.log').open('xb') as stderr:
        p=subprocess.Popen([os.sys.executable,str(supervisor)],cwd=out,env=env,stdout=stdout,stderr=stderr,start_new_session=True)
    meta.update(command=cmd,pid=p.pid,pgid=p.pid,software_sha256=sha(sw/'protected.riscv'),state='RUNNING',
                restoration_status='NOT_VALIDATED',out=str(out))
    (out/'manifest.json').write_text(json.dumps(meta,indent=2)+'\n')
    print(json.dumps(dict(out=str(out),pid=p.pid)),flush=True)


if __name__=='__main__': main()
