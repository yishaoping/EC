#!/usr/bin/python3
from pathlib import Path
import sys,fcntl,subprocess,os,re
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import *
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-fit-svb-reference-map-r1-20261111';S=D/'Opt4-fit-svb-reference-map-r1-state.json'
def main():
 O.mkdir(exist_ok=True);lk=(O/'instance.lock').open('a');fcntl.flock(lk,fcntl.LOCK_EX|fcntl.LOCK_NB);old=read(S);assert not live(old) and not live(old.get('child',{}))
 cfg=read(C/'config.json');b=cfg['binding'];F=Path(cfg['worktree']);parent=b['parent_commit'];rel='chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala';assert (C/'reference.scala').read_bytes()==subprocess.check_output(['git','show',parent+':'+rel],cwd=F)
 st=dict(**identity(),status='STARTING_IDENTICAL_HARNESS_REFERENCE_MAP',hardware_commit=parent,candidate_commit=b['hardware_commit'],started_utc=now(),fpga_access=False,formal_admission=False,stages={});save(S,st)
 def run(label,argv,cwd):
  log=O/(label+'.log');assert not log.exists()
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(list(map(str,argv)),cwd=cwd,stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,env={**os.environ,'JAVA_TOOL_OPTIONS':'','LD_LIBRARY_PATH':''});st.update(status='RUNNING_'+label.upper(),child=identity(p.pid));save(S,st)
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    st.update(updated_utc=now());save(S,st);os.fsync(f.fileno())
  st['stages'][label]=dict(returncode=p.returncode,log=str(log),sha256=sha(log));st.update(child={});save(S,st);assert p.returncode==0,(label,p.returncode,str(log));return log
 base=D/'build-logs/Opt4-fit-svb-tree-r7-20261111';classes=O/'classes';classes.mkdir(exist_ok=True);cp0=str(base/'classes')+':'+':'.join(cfg['classpath'])
 run('compile-reference',[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp0,'-Xplugin:'+cfg['plugin'],'-d',classes,C/'reference.scala'],O)
 rtl=O/'SVBModuleHarness.v';cp=str(classes)+':'+cp0
 log=run('elaborate-reference',[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-verbose:class','-cp',cp,'opt4svbtree.Emit','svb',O],O)
 origins=[l for l in log.read_text(errors='replace').splitlines() if 'boom.lsu.SpeculativeVersionBuffer source:' in l];assert origins and all(str(classes) in l for l in origins)
 logger=F/'chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v';tcl=O/'map.tcl';tcl.write_text('set_param general.maxThreads 8\nread_verilog {'+str(logger)+'}\nread_verilog {'+str(rtl)+'}\nsynth_design -top SVBModuleHarness -part xcu280-fsvh2892-2L-e -mode out_of_context\nreport_utilization -file {'+str(O/'utilization.rpt')+'}\nwrite_checkpoint -force {'+str(O/'module.dcp')+'}\nexit 0\n')
 run('map-reference',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',O/'vivado.log','-source',tcl],O)
 def resource(p):
  r={}
  for l in p.read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)',l)
   if m:r.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  return r
 ref=resource(O/'utilization.rpt');cand=resource(base/'map-svb/utilization.rpt');st.update(status='COMPLETE_IDENTICAL_HARNESS_FULL_SVB_AREA_COMPARISON_NOT_WHOLE_DUT',reference=ref,candidate=cand,lut_saved=ref['CLB LUTs']-cand['CLB LUTs'],carry8_saved=ref['CARRY8']-cand['CARRY8'],class_origins=origins,completed_utc=now(),reference_report_sha256=sha(O/'utilization.rpt'),candidate_report_sha256=sha(base/'map-svb/utilization.rpt'));save(O/'result.json',st);save(S,st)
if __name__=='__main__':
 try:main()
 except Exception as e:
  st=read(S)
  if st.get('pid')==os.getpid():st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
  raise
