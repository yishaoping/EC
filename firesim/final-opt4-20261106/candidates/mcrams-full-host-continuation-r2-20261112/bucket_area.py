#!/usr/bin/python3
"""Bounded paired actual address bank GG host area after real target parity.
Two cores,24GiB, one isolated bank only. No third large host/DUT synthesis.
"""
import fcntl,hashlib,importlib.util,json,os,pathlib,re,resource,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
REF=D/'build-logs/Opt4-mcrams-address-bucket-r5-20261112';O=D/'build-logs/Opt4-mcrams-address-bucket-area-r1-20261112';S=D/'Opt4-mcrams-address-bucket-area-r1-state.json'
def read(p):return json.loads(P(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()));t.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(t,p)
def total(p):
 text=P(p).read_text();head=text.split('2. BLOCKRAM')[0];out={}
 for n in ['CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','DSPs','URAM']:
  a=re.search(r'^\|\s*'+re.escape(n)+r'\*?\s*\|\s*([\d.,]+)\s*\|',text,re.M);assert a,(n,str(p));out[n]=float(a[1].replace(',',''))
 assert out['CLB LUTs']>0;return out
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);assert not S.exists()
 os.sched_setaffinity(0,{246,247});resource.setrlimit(resource.RLIMIT_AS,(24*2**30,24*2**30))
 proof=read(REF/'result.json');assert proof['status']=='PASS_WORD_TRANSITION_LEMMA_AND_FINITE_FULL_WIDTH_ALL_WORD_TARGET_PARITY_AREA_PENDING'
 assert proof['results']['Reg']['metrics']['event_digest']==proof['results']['MemMC']['metrics']['event_digest']
 st=dict(status='STARTED_PAIRED_ACTUAL_ADDRESS_BANK_AREA',functional_baseline=proof['functional_baseline'],fpga_access=False,full_address_module=False,whole_fit=False,no_large_CAD=True,proof_sha256=sha(REF/'result.json'),models={});save(S,st)
 for label in ['MemMC','Reg']:
  sv=REF/label/'FireSim-generated.sv';assert sha(sv)==proof['results'][label]['host_rtl_sha256'];out=O/label;out.mkdir(exist_ok=True)
  code=f'''set_param general.maxThreads 2
read_verilog -sv {{{sv}}}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
if {{[llength [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]]}} {{error "unresolved address bank model"}}
report_utilization -file {{{out/'utilization.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 15 -file {{{out/'hierarchical.rpt'}}}
write_checkpoint -force {{{out/'mapped.dcp'}}}
puts "ACTUAL_ADDRESS_BANK_AREA_ZERO_BLACKBOX"
exit 0
'''
  script=out/'map.tcl';script.write_text(code);start=time.monotonic()
  with (out/'run.log').open('xb',buffering=0) as f:
   p=subprocess.Popen(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-source',str(script)],cwd=out,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
   while p.poll() is None:
    try:p.wait(timeout=60)
    except subprocess.TimeoutExpired:pass
    st.update(status='RUNNING_LOCAL_'+label,child_pid=p.pid,host_wall_seconds=time.monotonic()-start);save(S,st);os.fsync(f.fileno())
  assert p.returncode==0,(label,p.returncode)
  st['models'][label]=dict(resources=total(out/'utilization.rpt'),host_rtl_sha256=sha(sv),report=str(out/'utilization.rpt'),report_sha256=sha(out/'utilization.rpt'),zero_blackboxes=True);save(S,st)
 before=st['models']['Reg']['resources'];after=st['models']['MemMC']['resources'];st.update(status='MEASURED_ACTUAL_REGVEC_VS_MCRAMS_ADDRESS_BANK_NO_FULL_MODULE_FIT_CLAIM',resource_savings={k:before[k]-after[k] for k in before},area_scope='Original256x64 address storage interface with all258read and256write ports; one bank only, not full arithmetic/AddressStats');save(S,st);save(O/'result.json',st)
if __name__=='__main__':main()
