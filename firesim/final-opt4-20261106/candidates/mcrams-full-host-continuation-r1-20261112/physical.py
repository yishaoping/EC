#!/usr/bin/python3
"""Reuse the exact FPGATop DCP inside unchanged pinned U280 shell.
Only small shell-facing wrappers are synthesized. Never re-synthesizes DUT.
Actual top-opt gate precedes place/route; all checkpoints/logs remain private.
"""
import datetime,fcntl,hashlib,importlib.util,json,os,pathlib,re,resource,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-mcrams-shell-physical-r1-20261112';S=D/'Opt4-mcrams-shell-physical-r1-state.json';ST={}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid=None):
 pid=pid or os.getpid()
 try:a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=a[0])
 except FileNotFoundError:return {}
def live(s):
 i=ident(s.get('pid',0));return bool(i and i['process_state'] not in ['Z','X'] and all(str(i[k])==str(s.get(k)) for k in ['pid','start_ticks','host_boot_id']))
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def stage(name,body,outputs):
 receipt=O/(name+'-receipt.json')
 if receipt.exists():
  r=read(receipt);assert r['returncode']==0 and all(sha(p)==h for p,h in r['outputs'].items());return
 script=O/(name+'.tcl');log=O/(name+'.log');assert not script.exists() and not log.exists(),'partial stage preserved; reviewed independent resume required'
 script.write_text(body+'\n');start=time.monotonic()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/(name+'.vivado.log')),'-source',str(script)],cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8','TMPDIR':str(O)})
  update(status='RUNNING_'+name.upper(),stage=name,child=ident(p.pid),log=str(log))
  while p.poll() is None:
   try:p.wait(timeout=60)
   except subprocess.TimeoutExpired:pass
   os.fsync(f.fileno());update(host_wall_seconds=time.monotonic()-start)
 r=dict(returncode=p.returncode,script_sha256=sha(script),outputs={str(p):sha(p) for p in outputs if P(p).is_file()},log=str(log),completed_utc=now(),host_wall_seconds=time.monotonic()-start)
 save(receipt,r);update(child={});assert p.returncode==0 and all(P(p).is_file() for p in outputs),(name,p.returncode)
def gate():
 return '''
set bad {}
set unresolved [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
foreach c $unresolved {
 if {$c eq "dbg_hub" && [get_property REF_NAME $c] eq "dbg_hub_CV" && [get_property IS_DEBUG_CORE $c]} {continue}
 lappend bad $c
}
if {[llength $bad]} {error "unresolved functional blackboxes: $bad"}
'''
def main():
 plan=read(C/'physical-plan.json');O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not S.exists();ad=read(D/'build-logs/Opt4-mcrams-full-host-continuation-r1-20261112/capacity-parity-admission.json')
 assert all(sha(p)==h for p,h in plan['immutable_inputs'].items())
 for key in ['capacity_result','target_parity_result']:assert sha(ad[key])==ad[key+'_sha256']
 a=read(ad['capacity_result']);m=read(ad['target_parity_result']);assert a['full_host_fit'] and m['captured_finite_parity_passed']
 assert ad['host_rtl_sha256']==plan['host_rtl_sha256']
 os.sched_setaffinity(0,set(range(240,248)));resource.setrlimit(resource.RLIMIT_AS,(128*2**30,128*2**30))
 ST.update(schema='ec-mcrams-reused-DUT-DCP-shell-physical/1',**ident(),started_utc=now(),functional_baseline=plan['functional_baseline'],hardware_commit=plan['derived_hardware'],host_transform_id=plan['host_transform_id'],fpga_access=False,certified_bitstream=False,formal_admission=False,no_DUT_resynthesis=True)
 # No third large job and no overlap with another full physical implementation.
 while True:
  p=read(D/'Opt4-fit-update-share-svb-cad-state.json')
  if not live(p) or p.get('current_stage')=='dut_synth':break
  update(status='WAITING_LIVE_E0_PHYSICAL_SAFE_BOUNDARY');time.sleep(300)
 lock2=(D/'.mcrams-shell-physical.lock').open('a');fcntl.flock(lock2,fcntl.LOCK_EX|fcntl.LOCK_NB)
 host=P(a['checkpoint']);assert sha(host)==a['checkpoint_sha256']
 # F1Shim is part of generated host RTL but was not the FPGATop synthesis
 # root. Recover only that adapter around the exact immutable DCP.
 sv=P(plan['host_rtl']).read_text();shim=re.search(r'^module F1Shim\b.*?^endmodule',sv,re.M|re.S)[0]
 wrapper=O/'shell-adapters.sv';wrapper.write_text(P(plan['physical_wrapper']).read_text()+'\n'+P(plan['bd_wrapper']).read_text()+'\n'+shim+'\n')
 stage('stub',f'open_checkpoint {{{host}}}\nwrite_verilog -force -mode synth_stub {{{O/"FPGATop_stub.v"}}}\nexit 0',[O/'FPGATop_stub.v'])
 stage('wrapper_only',f'''set_param general.maxThreads 8
read_verilog {{{O/'FPGATop_stub.v'}}}
read_verilog {{{plan['defines']}}}
read_verilog -sv {{{wrapper}}}
synth_design -mode out_of_context -top design_1_firesim_wrapper_0_0 -part xcu280-fsvh2892-2L-e
set target [get_cells -hier -quiet -filter {{REF_NAME == FPGATop}}]
if {{[llength $target] != 1}} {{error "exact FPGATop boundary missing: $target"}}
read_checkpoint -cell $target {{{host}}}
if {{[llength [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]]}} {{error "wrapper DCP unresolved"}}
write_checkpoint -force {{{O/'wrapper-host-linked.dcp'}}}
puts "EXACT_FPGATOP_DCP_REUSED_NO_DUT_SYNTHESIS"
exit 0''',[O/'wrapper-host-linked.dcp'])
 # Top DCP contains the original shell interconnect only; every functional
 # blackbox is filled from exact bound snapshots, and the old DUT is excluded.
 lines=[f'open_checkpoint {{{plan["shell_top_dcp"]}}}']
 for row in plan['shell_checkpoints']+[dict(path=str(O/'wrapper-host-linked.dcp'),ref='design_1_firesim_wrapper_0_0')]:
  lines += [f'set target [get_cells -hier -quiet -filter {{REF_NAME == {row["ref"]}}}]',f'if {{[llength $target] != 1}} {{error "shell cell {row["ref"]}: $target"}}',f'read_checkpoint -cell $target {{{row["path"]}}}']
 lines += [gate(),f'read_xdc {{{plan["implementation_xdc"]}}}',f'read_xdc {{{plan["bitstream_xdc"]}}}','opt_design -directive Explore',f'write_checkpoint -force {{{O/"top-opt.dcp"}}}',f'report_utilization -file {{{O/"top-postopt-utilization.rpt"}}}',f'report_utilization -hierarchical -hierarchical_depth 30 -file {{{O/"top-postopt-hierarchical.rpt"}}}','exit 0']
 stage('top_opt','\n'.join(lines),[O/'top-opt.dcp',O/'top-postopt-utilization.rpt'])
 # Existing capacity parser accepts complete top and compares actual counts;
 # only capacity FIT admits physical implementation.
 sysroot=W/'scripts';import sys;sys.path.insert(0,str(sysroot));from summarize_c4_capacity import utilization
 res=utilization(O/'top-postopt-utilization.rpt');needed=['CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','URAM','DSPs'];assert all(k in res for k in needed)
 update(top_postopt_resources=res)
 if any(res[k]['used']>res[k]['available'] for k in needed):
  update(status='NOT_FIT_COMPLETE_TOP_NO_PLACE',checkpoint=str(O/'top-opt.dcp'),completed_utc=now());save(O/'result.json',ST);return
 stage('place',f'''open_checkpoint {{{O/'top-opt.dcp'}}}
if {{[llength [get_debug_cores -quiet]]}} {{implement_debug_core}}
if {{[llength [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]]}} {{error "unresolved after debug implementation"}}
place_design -directive Explore
phys_opt_design -directive Explore
write_checkpoint -force {{{O/'placed.dcp'}}}
exit 0''',[O/'placed.dcp'])
 stage('route',f'''open_checkpoint {{{O/'placed.dcp'}}}
route_design -directive Explore
write_checkpoint -force {{{O/'routed.dcp'}}}
exit 0''',[O/'routed.dcp'])
 stage('timing_drc_bitstream',f'''open_checkpoint {{{O/'routed.dcp'}}}
report_timing_summary -report_unconstrained -file {{{O/'timing-summary.rpt'}}}
report_drc -file {{{O/'final-drc.rpt'}}}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {{![llength $setup] || ![llength $hold]}} {{error "missing timing paths"}}
set wns [get_property SLACK $setup];set whs [get_property SLACK $hold]
if {{$wns<0 || $whs<0}} {{error "setup/hold not closed: $wns $whs"}}
set bad [get_drc_violations -quiet -filter {{SEVERITY == Error}}]
if {{[llength $bad]}} {{error "DRC errors: $bad"}}
puts "MCRAMS_PHYSICAL_TIMING WNS=$wns WHS=$whs"
write_bitstream -force {{{O/'firesim.bit'}}}
exit 0''',[O/'firesim.bit',O/'timing-summary.rpt',O/'final-drc.rpt'])
 update(status='PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION',completed_utc=now(),bitstream=str(O/'firesim.bit'),bitstream_sha256=sha(O/'firesim.bit'),certified_bitstream=False,runtime_admission=False,board_bdf='0000:21:00.0',runtime_descriptor=plan['runtime_descriptor'])
 save(O/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(O/'failure.json',ST)
  raise
