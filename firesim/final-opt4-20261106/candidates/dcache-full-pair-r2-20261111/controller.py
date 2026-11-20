#!/usr/bin/python3
"""Actual full DCache pair from version-bound GoldenGate RTL.
Preserve every ordinary port and512x32 generation observations; no FPGA access.
This area job does not silently upgrade compositional proof to whole-RTL formal.
"""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,re,shutil,subprocess,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
L=D/'build-logs/Opt4-fit-dcache-full-pair-r2-20261111';S=D/'Opt4-fit-dcache-full-pair-r2-state.json';TOP='BoomNonBlockingDCache';BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775';COMMIT='2210930f510eccf5518c444dadca4a51bcf6f851';SID='548c7b8e1066ba82388ab759127e6d3b5c2a794f2f32ebcdc27b7f653b71d66c'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def ident(pid):
 try:
  s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def main():
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(schema='ec-opt4-full-dcache-pair/1',**ident(os.getpid()),status='WAITING_BOUND_CANDIDATE_GOLDENGATE',hardware_commit=COMMIT,source_id=SID,parent_commit=BASE,functional_baseline_commit='8491167d84b6d9521b151a743673c1516926a1f8',started_utc=now(),stages={},maps={},fpga_access=False,whole_dut_formal=False,production_selected=False)
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 update()
 while True:
  rr=read(D/'Opt4-fit-dcache-owner-rtl-state.json');ctrl=read(D/'Opt4-fit-dcache-owner-system-r4-state.json')
  if rr.get('status')=='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED':break
  if ctrl.get('status')=='FAILED_WITH_EVIDENCE':raise RuntimeError('candidateGG failed; preserve evidence and recover binding before mapping')
  update(dependency_status=ctrl.get('status'));time.sleep(60)
 refs={'reference':read(D/'Opt4-fit-update-share-svb-rtl-state.json'),'candidate':rr}
 assert refs['reference']['hardware_commit']==BASE and rr['hardware_commit']==COMMIT and rr['source_id']==SID
 proof=read(D/'build-logs/Opt4-fit-dcache-owner-system-r4-20261111/combined-equivalence.json');assert proof['hardware_commit']==COMMIT and proof['source_id']==SID and proof['exact_source_reversal']
 update(compositional_receipt=proof,proof_limits='Complete source parent reconstruction plus arbitrary512word state-transition induction and actual Arbiter2 exclusion. Not generated completeDCache SAT or wholeDUT formal.',status='PREPARING_REAL_FULL_DCACHE_PAIR')
 headers={};obs={};rtls={}
 for label,r in refs.items():
  root=Path(r['goldengate_dir']);src=root/'FireSim-generated.sv';assert sha(src)==r['outputs'][str(src)]
  text=src.read_text();match=re.search(r'^module '+TOP+r'\((.*?)\);',text,re.M|re.S);assert match
  end=text.index('\nendmodule',match.end());body=text[match.end():end];headers[label]=re.sub(r'\s+',' ',match.group(1)).strip()
  signals=set(re.findall(r'\bwire\s+\[31:0\]\s+(debug_line_generation_\d+)\s*=',body));expected={'debug_line_generation_'+str(i) for i in range(512)};assert signals==expected,(label,len(signals))
  anno=read(Path(r['elaboration_dir'])/'firesim.firesim.FireSim.anno.json')
  # Retain original don't-touch observation declarations in local area harness.
  names=[]
  for a in anno:
   if a.get('class')=='firrtl.transforms.DontTouchAnnotation' and a.get('target','').startswith('~FireSim|'+TOP+'>'):
    raw=a['target'].split('>',1)[1];name=re.sub(r'[^A-Za-z0-9_$]','_',raw).rstrip('_');names.append(name)
  kept=[]
  for name in sorted(set(names)):
   pat=r'(?m)^(\s*)(wire|reg)(\s+(?:\[[^\]\n]+\]\s+)?)('+re.escape(name)+r'(?:_\d+)*)(\s*(?:=|;))'
   def mark(m):kept.append(m.group(4));return m.group(1)+'(* keep = "true" *) '+m.group(2)+m.group(3)+m.group(4)+m.group(5)
   body=re.sub(pat,mark,body)
  # Full512generation observations are outputs only in the isolated area copy.
  # The authenticated actual GoldenGate RTL is never changed.
  header=match.group(0)[:-2]+',\n  output [16383:0] opt4_complete_generation_observation\n);'
  assign='\n  assign opt4_complete_generation_observation = {'+', '.join('debug_line_generation_'+str(i) for i in reversed(range(512)))+'};\n'
  instrumented=text[:match.start()]+header+body+assign+text[end:]
  sub=L/label;sub.mkdir(exist_ok=True);rtl=sub/'full-dcache-observed.sv';rtl.write_text(instrumented);rtls[label]=rtl
  obs[label]=dict(original=str(src),original_sha256=sha(src),observed_copy=str(rtl),observed_copy_sha256=sha(rtl),generation_ports=512,generation_bits=16384,all_original_ports_preserved=True,annotation_kept_signals=sorted(set(kept)),source_receipt_sha256=sha(D/('Opt4-fit-update-share-svb-rtl-state.json' if label=='reference' else 'Opt4-fit-dcache-owner-rtl-state.json')))
 assert headers['reference']==headers['candidate'],'real full module interface mismatch'
 assert obs['reference']['annotation_kept_signals']==obs['candidate']['annotation_kept_signals'],'debug observation boundary mismatch'
 save(L/'paired-rtl-inputs.json',dict(hardware_commit=COMMIT,source_id=SID,inputs=obs,interface_equal=True,instrumentation_scope='Local module area only. ActualGoldenGate unchanged. All original ports and512x32generation outputs retained. All named originalDontTouch wires/regs kept. This is not postopt wholeDUT area.'))
 update(status='FULL_DCACHE_INPUTS_MATCHED_MAPPING',inputs=obs)
 for label in ['candidate','reference']:
  sub=L/label;report=sub/'utilization.rpt';dcp=sub/'module.dcp';rp=sub/'map-result.json';prev=read(rp)
  if prev.get('returncode')==0 and prev.get('rtl_sha256')==sha(rtls[label]) and report.exists() and dcp.exists():
   assert sha(report)==prev['report_sha256'];st['maps'][label]=prev;continue
  while True:
   mem=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
   if mem>=192*2**20 and shutil.disk_usage(W).free>=180*2**30:break
   update(status='WAITING_FULL_MODULE_MEMORY_DISK_GATE',next_map=label);time.sleep(300)
  tcl=sub/'map.tcl';tcl.write_text(f'set_param general.maxThreads 2\nset_param synth.elaboration.rodinMoreOptions {{rt::set_parameter dissolveMemorySizeLimit 74752}}\nread_verilog -sv {{{rtls[label]}}}\nsynth_design -mode out_of_context -top {TOP} -part xcu280-fsvh2892-2L-e\nset bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]\nif {{[llength $bb]}} {{error "unresolved DCache dependencies: $bb"}}\nreport_utilization -file {{{report}}}\nreport_utilization -hierarchical -hierarchical_depth 25 -file {{{sub/"hierarchical.rpt"}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
  attempt=1+len(list(sub.glob('attempt-*.log')));log=sub/f'attempt-{attempt}.log';env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2','TMPDIR':str(sub)}
  with log.open('xb',buffering=0) as f:
   p=subprocess.Popen(['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(sub/f'vivado-{attempt}.log'),'-source',str(tcl)],cwd=sub,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   update(status='RUNNING_FULL_DCACHE_'+label.upper()+'_SYNTH',active_stage=label,child=ident(p.pid),log=str(log))
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update();os.fsync(f.fileno())
  assert p.returncode==0 and report.is_file() and dcp.is_file(),(label,p.returncode,str(log))
  counts={}
  for line in report.read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)\s*\|',line)
   if m:counts.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  assert len(counts)==5 and counts['CLB LUTs']>0
  row=dict(returncode=0,hardware_commit=r['hardware_commit'] if False else refs[label]['hardware_commit'],rtl_sha256=sha(rtls[label]),resources=counts,report=str(report),report_sha256=sha(report),checkpoint=str(dcp),log=str(log));save(rp,row);st['maps'][label]=row;update(child={})
 saved=st['maps']['reference']['resources']['CLB LUTs']-st['maps']['candidate']['resources']['CLB LUTs']
 update(status='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT',lut_saved=saved,significant_area_gain=saved>=75000,ended_utc=now(),child={});save(L/'result.json',st)
if __name__=='__main__':
 try:main()
 except Exception as exc:
  s=read(S)
  if s.get('pid')==os.getpid():s.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,s)
  raise
