#!/usr/bin/python3
"""Bounded full-width SAT and paired Vivado maps; no DUT/CAD/device changes."""
from pathlib import Path
import fcntl, hashlib, json, os, re, subprocess, time, datetime

C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111'
S=D/'Opt4-fit-address-dsp-counter-bank-r1-state.json'
RTL=C/'counter_bank.v'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def identity(pid):
 try:
  f=Path('/proc')/str(pid)/'stat';s=f.read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=s[19],process_state=s[0],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def main():
 O.mkdir(parents=True,exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(schema='ec-opt4-dsp-arithmetic-screen/1',**identity(os.getpid()),started_utc=now(),status='STARTING',functional_baseline_commit='8491167d84b6d9521b151a743673c1516926a1f8',rtl_sha256=sha(RTL),fpga_access=False,full_dut_synthesis=False,hardware_integrated=False,stages={})
 def update(**kw):st.update(kw);st['updated_utc']=now();save(S,st)
 def run(name,cmd,negative=False,timeout=900):
  log=O/(name+'.log');assert not log.exists(),('immutable attempt exists',str(log))
  with log.open('xb',buffering=0) as f:
   env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2','TMPDIR':str(O/'tmp')}
   p=subprocess.Popen(list(map(str,cmd)),cwd=O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
   update(status='RUNNING_'+name.upper(),child=identity(p.pid),active_stage=name)
   start=time.monotonic()
   while p.poll() is None:
    try:p.wait(timeout=30)
    except subprocess.TimeoutExpired:pass
    update(child=identity(p.pid));os.fsync(f.fileno())
    if time.monotonic()-start>timeout:
     # Only this owned local probe child is eligible for bounded timeout.
     p.terminate();p.wait(timeout=60);raise TimeoutError(name)
  accepted=p.returncode!=0 if negative else p.returncode==0
  st['stages'][name]=dict(returncode=p.returncode,accepted=accepted,log=str(log),log_sha256=sha(log));update(child={})
  assert accepted,(name,p.returncode,str(log));return log
 update();(O/'tmp').mkdir(exist_ok=True)
 log=run('sat',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {RTL}; prep -top CounterAdderProof -flatten; sat -verify -prove equivalent 1 -timeout 180'])
 assert 'SUCCESS' in log.read_text()
 log=run('sat-negative',['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {RTL}; prep -top CounterAdderProof -flatten; sat -verify -prove mutation_equivalent 1 -timeout 60'],negative=True)
 assert 'proof did fail' in log.read_text() and 'timed out' not in log.read_text()
 maps={}
 for label,top in [('reference','CounterBankReference'),('candidate','CounterBankCandidate')]:
  sub=O/label;sub.mkdir(exist_ok=True);tcl=sub/'map.tcl';report=sub/'utilization.rpt';dcp=sub/'module.dcp'
  tcl.write_text(f'set_param general.maxThreads 2\nread_verilog {{{RTL}}}\nsynth_design -mode out_of_context -top {top} -part xcu280-fsvh2892-2L-e\nreport_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nwrite_verilog -force -mode funcsim {{{sub/"mapped.v"}}}\nexit 0\n')
  run('map-'+label,['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],timeout=1800)
  counts={}
  for line in report.read_text().splitlines():
   m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
   if m:counts.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
  assert len(counts)==5 and dcp.is_file()
  maps[label]=dict(resources=counts,report=str(report),report_sha256=sha(report),checkpoint=str(dcp),netlist=str(sub/'mapped.v'))
 # No sequential primitives or latch may be introduced by arithmetic mapping.
 text=(O/'candidate/mapped.v').read_text();assert not re.search(r'\b(FDRE|FDSE|FDCE|FDPE|LDCE|LDPE)\b',text)
 for reg in ['AREG','BREG','CREG','PREG','MREG','ALUMODEREG','OPMODEREG','CARRYINREG']:
  vals=re.findall(r'\.'+reg+r'\((\d+)\)',text)
  assert all(int(v)==0 for v in vals),(reg,vals)
 saving=maps['reference']['resources']['CLB LUTs']-maps['candidate']['resources']['CLB LUTs']
 update(status='PROVEN_AND_PAIRED_MAPPED_LOCAL_ARITHMETIC_NOT_INTEGRATED',maps=maps,lut_saved_per_64_cells=saving,lut_saved_per_cell=saving/64,scope='Arbitrary64+64 bit SAT and actual64 arithmetic cells OOC; mapped DSP/register zero-cycle audit. No full address-module gain, complete-DUT FIT or timing claim.',ended_utc=now(),child={})
 save(O/'result.json',st);print(json.dumps(dict(status=st['status'],maps=maps,lut_saved_per_64_cells=saving)))
if __name__=='__main__':
 try:main()
 except Exception as e:
  if S.exists():
   j=json.loads(S.read_text())
   if j.get('pid')==os.getpid():j.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,j)
  raise
