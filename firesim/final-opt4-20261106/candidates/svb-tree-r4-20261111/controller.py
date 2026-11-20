#!/usr/bin/python3
"""Exact-cycle SVB selection substitution: SAT, real-size test, full SVB maps.
Does not admit a whole system or access a board. Never alters live builds.
"""
import datetime as dt,fcntl,json,os,re,subprocess,sys,time
from pathlib import Path
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import save,sha,identity,live,now
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-fit-svb-tree-r4-20261111';S=D/'Opt4-fit-svb-tree-r4-state.json'

def read(p):return json.loads(Path(p).read_text()) if Path(p).exists() else {}
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 old=read(S);assert not live(old) and not live(old.get('child',{}))
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);inputs=read(C/'input-hashes.json');assert all(sha(p)==h for p,h in inputs.items())
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
 st=dict(schema='ec-opt4-svb-selection-candidate/1',**identity(),hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='STARTING',started_utc=now(),formal_admission=False,fpga_access=False,stages={})
 save(S,st);env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8','CCACHE_DISABLE':'1','TMPDIR':str(O/'tmp')};(O/'tmp').mkdir(exist_ok=True)
 def update(**v):st.update(**v,updated_utc=now());save(S,st)
 def stage(name,argv,cwd,outputs=(),timeout=None,expect=0):
  rp=O/(name+'-result.json');r=read(rp)
  if r:
   assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id'] and r['returncode']==expect
   assert all(sha(p)==h for p,h in r['outputs'].items());st['stages'][name]=r;save(S,st);return r
  log=O/(name+'-attempt-1.log');assert not log.exists(),'review failed stage before new controller version'
  start=time.monotonic()
  with log.open('xb',buffering=0) as stream:
   p=subprocess.Popen(list(map(str,argv)),cwd=cwd,env=env,stdout=stream,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,start_new_session=True)
   r=dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],argv=list(map(str,argv)),log=str(log),started_utc=now(),child=identity(p.pid));update(status='RUNNING_'+name.upper(),child=r['child'],active_stage=name)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(stream.fileno())
    if timeout and time.monotonic()-start>timeout and p.poll() is None:
     os.killpg(p.pid,15)
     try:p.wait(timeout=10)
     except subprocess.TimeoutExpired:os.killpg(p.pid,9);p.wait()
     r['timeout']=True
  r.update(returncode=p.returncode,ended_utc=now(),wall_seconds=time.monotonic()-start,outputs={str(p):sha(p) for p in outputs if p.is_file()});save(rp,r);st['stages'][name]=r;update(child={})
  assert p.returncode==expect and not r.get('timeout') and all(p.is_file() for p in outputs),(name,p.returncode,log)
  return r
 rel='chipyard/generators/boom/src/main/scala/lsu/';original=subprocess.check_output(['git','show',b['parent_commit']+':'+rel+'speculative-version-buffer.scala'],cwd=F).decode();candidate=(F/rel/'speculative-version-buffer.scala').read_text()
 a=original.index('  val chooseValid = WireDefault(false.B)');z=original.index('\n  val occupancyValue',a)
 expected=original[:a]+'''  // Same total order (package, generation, slot), balanced combinational max.
  // All comparisons and selection remain in this cycle; no state is added.
  val (chooseValid, chooseIdx) = NewestSafeEntry(
    entrySafe.toSeq, key.map(_.contentSeq).toSeq, key.map(_.generation).toSeq)
'''+original[z:]
 assert candidate==expected,'non-selection SVB state, ports or control changed'
 assert (C/'reference-selection.scala.txt').read_text()==original[a:z]
 emitter=(C/'Emit.scala').read_text();assert original[a:z].strip() in emitter
 save(O/'substitution-audit.json',dict(hardware_commit=b['hardware_commit'],source_id=b['source_id'],status='PASS_EXACT_SELECTION_ONLY_SUBSTITUTION',original_source_sha256=__import__('hashlib').sha256(original.encode()).hexdigest(),candidate_source_sha256=sha(F/rel/'speculative-version-buffer.scala'),limits='Combinational substitution proof, unchanged full SVB registers/control. Not whole-DUT formal. Full implementation resource/timing still required.'))
 compiler=[cfg['java'],'-Xmx16G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin']]
 java=[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=8']
 classes=O/'classes';classes.mkdir(exist_ok=True)
 stage('compile',compiler+['-d',classes,F/rel/'NewestSafeEntry.scala',F/rel/'speculative-version-buffer.scala',C/'Emit.scala'],F,[classes/'opt4svbtree/Emit.class',classes/'boom/lsu/SpeculativeVersionBuffer.class'])
 cp=str(classes)+':'+':'.join(cfg['classpath'])
 for mode,top in [('proof','SelectionProbe'),('candidate','CandidateSelection'),('reference','ReferenceSelection'),('svb','SVBModuleHarness')]:
  out=O/mode;out.mkdir(exist_ok=True);stage('emit-'+mode,java+['-cp',cp,'opt4svbtree.Emit',mode,out],out,[out/(top+'.v')])
 yosys='/usr/local/bin/yosys';v=O/'proof/SelectionProbe.v'
 ys=O/'proof.ys';ys.write_text('read_verilog '+str(v)+'\nprep -top SelectionProbe\nflatten\nopt\nsat -timeout 900 -verify -prove io_equivalent 1 -show-inputs\n')
 stage('sat32',[yosys,'-s',ys],O,timeout=960)
 assert 'SUCCESS!' in (O/'sat32-attempt-1.log').read_text()
 mutant=O/'mutant.ys';mutant.write_text('read_verilog '+str(v)+'\nprep -top SelectionProbe\nflatten\nopt\nsat -timeout 120 -verify -prove io_mutantEquivalent 1 -show-inputs\n')
 stage('negative-mutation',[yosys,'-s',mutant],O,timeout=180,expect=1)
 assert 'proof did fail' in (O/'negative-mutation-attempt-1.log').read_text()
 cpp=O/'vectors.cpp';setters='\n'.join('dut.io_valid_%d=valid[%d];dut.io_seq_%d=seq[%d];dut.io_generation_%d=gen[%d];'%(i,i,i,i,i,i) for i in range(32))
 cpp.write_text('''#include "VSelectionProbe.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
static uint64_t rng=0xf2d2ca3e21c4b320ULL;
static uint32_t random32(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);VSelectionProbe dut;
for(unsigned t=0;t<8192;t++){unsigned valid[32],seq[32],gen[32];unsigned best=0;bool found=false;
for(unsigned i=0;i<32;i++) {valid[i]=t%8==0?0:t%8==1?1:random32()&1;seq[i]=t%8==2?0:t%8==3?0xffffffffu:random32();gen[i]=t%8==4?0:t%8==5?0xffffffffu:random32();if(t%8==6){seq[i]=t;gen[i]=t;}
if(valid[i]&&(!found||seq[i]>seq[best]||(seq[i]==seq[best]&&(gen[i]>gen[best]||(gen[i]==gen[best]&&i>best)))) {best=i;found=true;}}
'''+setters+'''
dut.eval();if(!dut.io_equivalent||dut.io_chosenValid!=found||dut.io_chosenIdx!=(found?best:0)) {fprintf(stderr,"FAIL vector=%u\\n",t);return 1;}}
puts("SVB_SELECTION_PASS vectors=8192 slots=32 seq=32 generation=32 ties=1 invalid=1 extrema=1");return 0;}
''')
 obj=O/'obj';stage('compile-vectors',['verilator','--cc','--exe','--build','-j','8','-Wno-fatal','--top-module','SelectionProbe','--Mdir',obj,v,cpp],O,[obj/'VSelectionProbe'])
 stage('vectors',[obj/'VSelectionProbe'],O)
 def mapping(name,rtl,top):
  out=O/('map-'+name);out.mkdir(exist_ok=True);tcl=out/'run.tcl';tcl.write_text('set_param general.maxThreads 8\nread_verilog {'+str(rtl)+'}\nsynth_design -top '+top+' -part xcu280-fsvh2892-2L-e -mode out_of_context\nreport_utilization -file {'+str(out/'utilization.rpt')+'}\nwrite_checkpoint -force {'+str(out/'module.dcp')+'}\nexit 0\n')
  stage('map-'+name,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-source',tcl,'-log',out/'vivado.log'],out,[out/'utilization.rpt',out/'module.dcp'])
  resources={}
  for l in (out/'utilization.rpt').read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)\s*\|',l)
   if m:resources.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  return dict(resources=resources,report=str(out/'utilization.rpt'),report_sha256=sha(out/'utilization.rpt'))
 reports={}
 for mode,top in [('reference','ReferenceSelection'),('candidate','CandidateSelection'),('svb','SVBModuleHarness')]:
  reports[mode]=mapping(mode,O/mode/(top+'.v'),top);update(measured_module_maps=reports)
 assert all(sha(p)==h for p,h in inputs.items())
 update(status='VERIFIED_SELECTION_SUBSTITUTION_AND_MAPPED_NOT_WHOLE_DUT_ADMITTED',local_formal='PASS_ALL_32_SLOTS_ALL_INPUT_BITS_SAT_WITH_NEGATIVE_MUTATION',actual_size_boundary='PASS_8192_VECTORS_32_SLOTS',measured_module_maps=reports,ended_utc=now());save(O/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  s=read(S)
  if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,s)
  raise
