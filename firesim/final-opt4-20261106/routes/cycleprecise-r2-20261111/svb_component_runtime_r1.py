#!/usr/bin/python3
"""Wait for the separately identified original SVB artifact, certify, run on21.

No full-Opt4 admission, Native runs, global driver actions or other-card access.
Live card owners and a certified full Opt4 always take precedence.
"""
import argparse, fcntl, hashlib, importlib.util, json, os
from pathlib import Path
import re, signal, subprocess, sys, time
C=Path(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
sys.path.insert(0,str(m.W/'scripts'))
import board_batch as bb
from coverage_first import sample_busy
BASE=m.BASE; PROFILE='OriginalSVB32-component-trace'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PREP=m.D/'cycleprecise-frozen-svb-fpga-r2-20261111'
PROOF=m.D/'cycleprecise-frozen-svb-trace-r4-20261111'
L=m.D/'cycleprecise-original-svb-onboard-r1-20261111'
CONFIG=C/'svb-component-runtime-r1-inputs.json'

def update(**kw):
 m.ST.update(kw,updated_utc=m.now());bb.save(L/'state.json',m.ST)

def whole_priority():
 p=m.D/'Opt4-fit-runtime-priority.json'
 if p.exists() and m.read(p).get('status') in ['REQUESTED_AT_SAFE_BOUNDARY','ACTIVE']:return True
 for p in (m.W/'runtime').glob('Opt4-fit-*/certified-build.json'):
  if m.read(p).get('certified_bitstream'):return True
 return False

def verify_inputs():
 cfg=m.read(CONFIG);assert cfg['board_allowlist']==['0000:21:00.0']
 assert cfg['functional_baseline']==BASE and cfg['source_id']==SID
 assert cfg['complete_opt4'] is False
 for p,h in cfg['pinned_files'].items():assert m.sha(p)==h,('input changed',p)
 b=m.read(PREP/'binding.json');r=m.read(PROOF/'result.json');d=m.read(PREP/'hardware-driver.json')
 assert b['profile']==PROFILE and b['source_id']==SID and b['functional_baseline']==BASE and not b['complete_opt4']
 assert m.sha(PROOF/'result.json')==b['cycle_proof_sha256']
 assert m.sha(PROOF/'binding.json')==b['target_binding_sha256']
 assert r['negative_rejected'] and r['compared_output_values']==42291
 assert r['output_ports']==127 and r['functional_baseline']==BASE and not r['architectural_restart_tested']
 assert d['source_id']==SID and d['profile']==PROFILE and d['board_allowlist']==['0000:21:00.0']
 assert m.sha(d['binary'])==d['binary_sha256']
 assert m.sha(PROOF/'target-cycles.txt')==d['trace_sha256']
 assert m.sha(PREP/'simif_xilinx_alveo_u280_21_only.cc')==d['guarded_source_sha256']
 r=m.read(PREP/'receipts/adapter-compare.json');assert r['returncode']==0
 assert m.sha(r['log'])==r['log_sha256']
 s=Path(r['log']).read_text();assert 'compared_fields=42291' in s and '[SVBProbe]PASS Test' in s and 'unstable value' not in s
 return cfg,b,d

def certify():
 cfg,b,d=verify_inputs();p=PREP/'cad-logs/result.json'
 if not p.exists():return None
 s=m.read(p)
 assert s['status']=='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED'
 assert s['profile']==PROFILE and s['configuration']=='OriginalSVB32-component'
 assert s['source_id']==SID and s['hardware_commit']==BASE and s['frozen_parent_commit']==BASE
 assert s['part']=='xcu280-fsvh2892-2L-e' and s['certified_bitstream'] and not s['formal_admission']
 for name in ['dut_synth','top_synth','implementation','timing_bitstream']:
  r=s['stages'][name];assert r['source_id']==SID and r['returncode']==0 and r['outputs']
  assert all(m.sha(p)==h for p,h in r['outputs'].items()),name
 assert m.sha(s['bitstream'])==s['bitstream_sha256']
 assert s['inputs']['shell_interface_equal'] and len(s['inputs']['shell_checkpoints'])==11
 assert all(m.sha(p)==h for p,h in s['inputs']['generated'].items())
 assert all(m.sha(r['path'])==r['sha256'] for r in s['inputs']['shell_checkpoints'])
 for kind in ['CLB LUTs','CLB Registers','CARRY8','DSPs','Block RAM Tile','URAM']:
  x=s['top_postopt_resources'][kind];assert 0<=x['used']<=x['available'] and x['available']>0
 # Earlier shell scripts have incorrectly scoped generated-clock commands.
 # Do not trust a WNS alone: audit the clock that reaches the real target
 # BUFGCE after routing. For this original component the target divide is1.
 audit=L/'clock-audit.complete.json'
 if not audit.exists():
  routed=next(p for p in s['stages']['implementation']['outputs'] if p.endswith('_routed.dcp'))
  tcl=L/'clock-audit.tcl'
  tcl.write_text('set_param general.maxThreads 2\nopen_checkpoint {'+routed+'''}
set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
if {[llength $pins] != 1} {error "target clock buffer is absent or ambiguous"}
set clks [get_clocks -of_objects $pins]
if {[llength $clks] != 1} {error "target buffer does not have one timing clock"}
set period [get_property PERIOD $clks]
if {$period <= 0 || $period > 20.01} {error "invalid or relaxed target timing clock"}
set regs [all_registers -clock $clks]
if {[llength $regs] < 1000} {error "target sequential clock coverage is implausible"}
puts "EC_SVB_PHYSICAL_CLOCK period=$period clock=$clks registers=[llength $regs] pin=$pins"
report_clocks -file {'''+str(L/'physical-clocks.rpt')+'''}
check_timing -verbose -file {'''+str(L/'check-timing.rpt')+'''}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "timing paths absent"}
set wns [get_property SLACK $setup];set whs [get_property SLACK $hold]
if {$wns < 0 || $whs < 0} {error "setup or hold failed"}
puts "EC_SVB_CLOCK_AUDIT_PASS WNS=$wns WHS=$whs"
exit 0
''')
  update(status='AUDITING_ROUTED_COMPONENT_TARGET_CLOCK_NO_FPGA_IO')
  log=L/'clock-audit.log'
  assert not log.exists(),'partial/failed audit needs versioned recovery'
  bb.command(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(L/'clock-audit.vivado.log'),'-source',str(tcl)],L,log,timeout=3600)
  text=log.read_text();assert 'EC_SVB_CLOCK_AUDIT_PASS' in text and 'EC_SVB_PHYSICAL_CLOCK' in text
  bb.save(audit,dict(routed_checkpoint=routed,routed_sha256=m.sha(routed),log_sha256=m.sha(log),target_divide=1))
 else:
  x=m.read(audit);assert m.sha(x['routed_checkpoint'])==x['routed_sha256'] and m.sha(L/'clock-audit.log')==x['log_sha256']
 cert=dict(schema='ec-original-component-certificate/1',status='CERTIFIED_ORIGINAL_SVB_COMPONENT_NOT_FULL_OPT4',
  functional_baseline=BASE,profile=PROFILE,source_id=SID,complete_opt4=False,formal_parsec_admission=False,
  bitstream=s['bitstream'],bitstream_sha256=s['bitstream_sha256'],cad_result=str(p),cad_result_sha256=m.sha(p),
  driver=d,cycle_proof_sha256=m.sha(PROOF/'result.json'),binding_sha256=m.sha(PREP/'binding.json'),
  target_trace='synthetic directed original component; not application payload replay',board_bdf=bb.TARGET_BDF,
  board_serial=bb.TARGET_SERIAL,clock_audit_sha256=m.sha(audit),created_utc=m.now())
 bb.save(L/'certified-component.json',cert);return cert

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--offline',action='store_true');a=ap.parse_args()
 if a.offline:
  cfg,b,d=verify_inputs();print(json.dumps(dict(status='INPUT_BINDING_PASS_NOT_CAD_CERTIFICATION',source_id=b['source_id'],fpga_access=False)));return
 assert os.geteuid()==0
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 if (L/'complete.json').exists():return
 assert not (L/'deployment.json').exists(),'adopt existing deployment/run evidence; never redeploy automatically after a partial run'
 m.ST.update(schema='ec-original-svb-onboard/1',**m.ident(os.getpid()),functional_baseline=BASE,
  configuration=PROFILE,board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,complete_opt4=False,fpga_access=False)
 verify_inputs()
 while True:
  c=m.read(PREP/'cad-state.json');update(status='WAITING_COMPONENT_CAD',cad_status=c.get('status'),cad_stage=c.get('current_stage'))
  if c.get('status') in ['NOT_FIT_POSTOPT','FAILED_WITH_EVIDENCE']:raise RuntimeError('component CAD failed; preserve evidence and repair separately')
  if (PREP/'cad-logs/result.json').exists():break
  time.sleep(300)
 cert=certify();assert cert
 while True:
  if whole_priority() or sample_busy():update(status='WAITING_SAFE_21_BOUNDARY_OR_FULL_OPT4_PRIORITY');time.sleep(300);continue
  locks=[]
  try:
   for name in ['maintenance-0000_21_00.0.lock','card-0000_21_00.0.lock']:
    f=(m.D/'locks'/name).open('a');locks.append(f);fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
  except BlockingIOError:
   for f in locks:f.close()
   update(status='WAITING_EXISTING_21_LOCK_OWNER');time.sleep(300);continue
  if whole_priority() or sample_busy():
   for f in locks:f.close()
   time.sleep(300);continue
  check=bb.precheck(target_bdfs=[bb.TARGET_BDF]);bb.save(L/'pre-deployment.json',check)
  if check['open_devices'] or check['simulation_processes']:
   for f in locks:f.close()
   update(status='WAITING_CONCRETE_21_DEVICE_CONFLICT',conflict=check);time.sleep(300);continue
  break
 # Both shared21 locks remain held through deployment and the short trace.
 verify_inputs();assert not whole_priority()
 bb.ensure_jtag_server(L,[bb.TARGET_SERIAL])
 check=bb.precheck(target_bdfs=[bb.TARGET_BDF]);bb.save(L/'pre-maintenance.json',check)
 assert not check['open_devices'] and not check['simulation_processes'] and not whole_priority()
 dep=dict(schema='ec-original-component-deployment/1',status='MAINTENANCE_RUNNING',configuration=PROFILE,
  complete_opt4=False,source_id=SID,bdfs=[bb.TARGET_BDF],serials=[bb.TARGET_SERIAL],bitstream=cert['bitstream'],
  bitstream_sha256=cert['bitstream_sha256'],global_operations=[],host_boot_id=m.ident(os.getpid())['host_boot_id'],
  pid=os.getpid(),started_utc=m.now(),completed_cards=[])
 bb.save(L/'deployment.json',dep);update(status='DEPLOYING_ORIGINAL_SVB_COMPONENT_21_ONLY',fpga_access=True)
 bb.command(['/usr/bin/python3',m.W/'deployment-tools/fpga-util.py','--extended-bdf',bb.TARGET_BDF,
  '--bitstream',cert['bitstream'],'--vivado-bin','/tools/Xilinx/Vivado/2021.1/bin/vivado',
  '--hw-server-bin','/tools/Xilinx/Vivado/2021.1/bin/hw_server'],L,L/'deployment.log',timeout=900)
 dep.update(status='DEPLOYED_NOT_RUN',completed_cards=[dict(bdf=bb.TARGET_BDF,serial=bb.TARGET_SERIAL,
  hardware_profile=PROFILE,hardware_commit=BASE,source_id=SID,bitstream_sha256=cert['bitstream_sha256'])])
 bb.save(L/'deployment.json',dep);bb.save(m.D/'latest-deployment.json',dep)
 argv=[cert['driver']['binary'],'+permissive','+domain=0000','+bus=21','+device=00','+function=0','+bar=0',
  '+pci-vendor=10ee','+pci-device=903f','+seed=8491167','+permissive-off']
 start=time.monotonic();log=L/'hardware-trace.log'
 with log.open('xb',buffering=0) as f:
  child=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*argv],cwd=L,stdin=subprocess.DEVNULL,stdout=f,
   stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':''})
  active=dict(schema='ec-original-component-run/1',run_id=L.name,run_dir=str(L),status='RUNNING',
   configuration=PROFILE,board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,**m.ident(child.pid))
  bb.save(m.D/'active-0000_21_00.0.json',active)
  update(status='RUNNING_ORIGINAL_SVB_FPGA_TRACE_21_ONLY',child=m.ident(child.pid))
  try:rc=child.wait(timeout=600)
  except subprocess.TimeoutExpired:
   os.killpg(child.pid,signal.SIGTERM)
   try:child.wait(timeout=20)
   except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
   rc='HOST_TIMEOUT'
  os.fsync(f.fileno())
 text=log.read_text(errors='replace')
 good=rc==0 and 'PASS_SVB_TRACE target_cycles=372 compared_fields=42291' in text and '[SVBProbe]PASS Test' in text
 good=good and not any(s in text for s in ['TARGET_HOST_MISMATCH','unstable value','*** FAILED','Assertion failed'])
 result=dict(schema='ec-original-component-measurement/1',status='VALID_COMPONENT_FPGA_TRACE' if good else 'FAILED_WITH_EVIDENCE',
  kind='FPGA_ORIGINAL_SVB32_DIRECTED_COMPONENT_TRACE_NOT_FULL_OPT4',functional_baseline=BASE,source_id=SID,
  board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,returncode=rc,host_wall_seconds=time.monotonic()-start,
  certificate_sha256=m.sha(L/'certified-component.json'),raw_log_sha256=m.sha(log),raw_log=str(log),
  target_cycles_replayed=372,defined_cycles_compared=333,compared_output_values=42291 if good else None,
  architectural_restart_tested=False,formal_parsec_sample=False,application_trace=False,completed_utc=m.now())
 bb.save(L/'result.json',result)
 if good:bb.save(L/'complete.json',dict(result_sha256=m.sha(L/'result.json'),certificate_sha256=result['certificate_sha256']))
 active.update(status=result['status'],ended_utc=m.now());bb.save(m.D/'active-0000_21_00.0.json',active)
 update(status=result['status'],child={},result=str(L/'result.json'))

if __name__=='__main__':
 try:main()
 except Exception as e:
  if L.exists():update(status='FAILED_WITH_EVIDENCE',error=repr(e))
  raise
