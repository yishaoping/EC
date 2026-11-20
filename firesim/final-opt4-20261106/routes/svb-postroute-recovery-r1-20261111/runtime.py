#!/usr/bin/python3
"""Wait for the separately identified original SVB artifact, certify, run on21.

No full-Opt4 admission, Native runs, global driver actions or other-card access.
Live card owners and a certified full Opt4 always take precedence.
"""
import argparse, fcntl, hashlib, importlib.util, json, os
from pathlib import Path
import re, signal, subprocess, sys, time
C=Path('/data1/gzh/EC/firesim/final-opt4-20261106/routes/cycleprecise-r2-20261111')
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
sys.path.insert(0,str(m.W/'scripts'))
import board_batch as bb
from coverage_first import sample_busy
BASE=m.BASE; PROFILE='OriginalSVB32-component-trace'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PREP=m.D/'cycleprecise-frozen-svb-fpga-r2-20261111'
PROOF=m.D/'cycleprecise-frozen-svb-trace-r4-20261111'
L=m.D/'cycleprecise-original-svb-recovered-onboard-r1-20261111'
ROOT=m.D/'cycleprecise-svb-postroute-recovery-r1-20261111'
SPREAD=None
WAITERS=[(m.D/'cycleprecise-original-svb-onboard-r1-20261111','ec-opt4-original-svb-onboard-r1.service'),(m.D/'cycleprecise-original-svb-spread-onboard-r2-20261111','ec-opt4-original-svb-spread-follow-r2.service')]
OLD=m.D/'cycleprecise-original-svb-onboard-r1-20261111'
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
 cfg,b,d=verify_inputs()
 s=m.read(SPREAD/'result.json')
 assert s['status']=='BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION'
 assert s['functional_baseline']==BASE and s['source_id']==SID
 assert not s['target_changed'] and not s['fpga_access'] and not s['complete_opt4']
 assert m.read(SPREAD/'complete.json')['result_sha256']==m.sha(SPREAD/'result.json')
 assert all(m.sha(p)==h for p,h in s['outputs'].items())
 pins=m.read(Path(__file__).parent/'inputs.json')
 assert s['capsule_inputs_sha256']==m.sha(Path(__file__).parent/'inputs.json')
 bound=m.read(SPREAD/'sealed-inputs.json')
 assert bound['eligible'] and bound['functional_baseline']==BASE and bound['source_id']==SID
 assert bound['checkpoint_sha256']==m.sha(bound['sealed_checkpoint'])
 assert bound['producer_state_sha256']==m.sha(bound['producer_state'])
 assert all(m.sha(p)==h for p,h in bound['source_input_hashes'].items())
 routed=SPREAD/'final.dcp'
 bit=Path(s['bitstream'])
 assert m.sha(routed)==s['outputs'][str(routed)] and m.sha(bit)==s['bitstream_sha256']==s['outputs'][str(bit)]
 log=(SPREAD/'recovery.log').read_text(errors='replace')
 assert 'EC_SVB_RECOVERY_BITSTREAM_COMPLETE' in log
 # Independently restore the actual routed design. Existing target clock
 # constraint and original shell settings are retained, never relaxed here.
 audit=L/'clock-audit.complete.json'
 if not audit.exists():
  tcl=L/'clock-audit.tcl'
  code='set_param general.maxThreads 2\nopen_checkpoint {'+str(routed)+'}\n'
  code+='if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved cells"}\n'
  code+='set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]\n'
  code+='if {[llength $pins] != 1} {error "target buffer absent"}\nset clks [get_clocks -of_objects $pins]\n'
  code+='if {[llength $clks] != 1} {error "target clock absent"}\nset period [get_property PERIOD $clks]\n'
  code+='if {$period <= 0 || $period > 20.01 || [llength [all_registers -clock $clks]] < 1000} {error "invalid target clock"}\n'
  code+='report_clocks -file {'+str(L/'physical-clocks.rpt')+'}\ncheck_timing -verbose -file {'+str(L/'check-timing.rpt')+'}\n'
  code+='report_timing_summary -report_unconstrained -file {'+str(L/'timing-summary.rpt')+'}\nreport_route_status -file {'+str(L/'route-status.rpt')+'}\n'
  code+='report_drc -file {'+str(L/'drc.rpt')+'}\n'
  code+='set violations [get_drc_violations -quiet -filter {SEVERITY == Error}]\nif {[llength $violations]} {error "DRC errors $violations"}\n'
  code+='set setup [get_timing_paths -delay_type max -max_paths 1]\nset hold [get_timing_paths -delay_type min -max_paths 1]\n'
  code+='if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}\n'
  code+='set wns [get_property SLACK $setup]\nset whs [get_property SLACK $hold]\nif {$wns < 0 || $whs < 0} {error "timing failed"}\n'
  code+='puts "EC_SVB_CLOCK_AUDIT_PASS WNS=$wns WHS=$whs period=$period"\nexit 0\n'
  if tcl.exists():assert tcl.read_text()==code
  else:tcl.write_text(code)
  log=L/'clock-audit.log';assert not log.exists(),'partial audit requires versioned recovery'
  update(status='AUDITING_SPREAD_ROUTED_COMPONENT_NO_FPGA_IO')
  bb.command(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(L/'clock-audit.vivado.log'),'-source',str(tcl)],L,log,timeout=3600)
  text=log.read_text();assert 'EC_SVB_CLOCK_AUDIT_PASS' in text
  timing=(L/'check-timing.rpt').read_text()
  assert re.search(r'checking no_clock \(0\)',timing)
  assert re.search(r'checking unconstrained_internal_endpoints \(0\)',timing)
  bb.save(audit,dict(routed_checkpoint=str(routed),routed_sha256=m.sha(routed),log_sha256=m.sha(log),target_divide=1))
 else:
  a=m.read(audit);assert m.sha(a['routed_checkpoint'])==a['routed_sha256'] and m.sha(L/'clock-audit.log')==a['log_sha256']
 cert=dict(schema='ec-original-component-certificate/1',status='CERTIFIED_ORIGINAL_SVB_COMPONENT_NOT_FULL_OPT4',
  functional_baseline=BASE,profile=PROFILE,source_id=SID,complete_opt4=False,formal_parsec_admission=False,
  bitstream=str(bit),bitstream_sha256=m.sha(bit),cad_result=str(SPREAD/'result.json'),cad_result_sha256=m.sha(SPREAD/'result.json'),
  driver=d,cycle_proof_sha256=m.sha(PROOF/'result.json'),binding_sha256=m.sha(PREP/'binding.json'),
  target_trace='synthetic directed original component; not application payload replay',board_bdf=bb.TARGET_BDF,
  board_serial=bb.TARGET_SERIAL,clock_audit_sha256=m.sha(audit),physical_only_retry=True,created_utc=m.now())
 bb.save(L/'certified-component.json',cert);return cert

def handoff_waiting_predecessor():
 held=[]
 try:
  for name in ['maintenance-0000_21_00.0.lock','card-0000_21_00.0.lock']:
   f=(m.D/'locks'/name).open('a');held.append(f);fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
 except BlockingIOError:
  for f in held:f.close()
  update(status='WAITING_EXISTING_21_LOCK_OWNER_BEFORE_HANDOFF')
  return None
 try:
  for root,unit in WAITERS:
   if (root/'complete.json').exists():
    save_metrics(root);update(status='ORIGINAL_SVB_ALREADY_MEASURED_NO_DUPLICATE_DEPLOYMENT');return False
   row=m.read(root/'state.json')
   if (root/'deployment.json').exists() or row.get('status','').startswith(('RUNNING_','DEPLOYING_','AUDITING_')):
    update(status='WAITING_EXISTING_COMPONENT_CERTIFICATION_OR_RUN');return None
   pid=subprocess.check_output(['systemctl','show',unit,'-p','MainPID','--value'],text=True).strip()
   if pid!='0':
    if row.get('status')!='WAITING_COMPONENT_CAD' or row.get('child') or row.get('fpga_access'):
     update(status='WAITING_UNVERIFIED_OTHER_FOLLOWER');return None
    assert int(pid)==row['pid'] and m.ident(row['pid']).get('start_ticks')==row['start_ticks']
    bb.save(L/(unit+'.handoff-before.json'),dict(old=row,certificate_sha256=m.sha(L/'certified-component.json'),cad_signalled=False,both_21_locks_held=True))
    subprocess.run(['systemctl','stop',unit],check=True)
    bb.save(L/(unit+'.handoff-complete.json'),dict(utc=m.now(),stopped_idle_waiter_pid=int(pid),cad_signalled=False,fpga_operation_performed=False,both_21_locks_held=True))
  return True
 finally:
  for f in held:f.close()

def save_metrics(run):
 out=run/'trace-event-metrics-r1'
 if (out/'complete.json').exists():return
 subprocess.run(['/usr/bin/python3',str(m.W/'routes/svb-trace-metrics-r1-20261111/analyze.py'),'--hardware-run',str(run),'--out',str(out)],check=True)

def main():
 global SPREAD
 ap=argparse.ArgumentParser();ap.add_argument('--offline',action='store_true');a=ap.parse_args()
 if a.offline:
  cfg,b,d=verify_inputs();print(json.dumps(dict(status='INPUT_BINDING_PASS_NOT_CAD_CERTIFICATION',source_id=b['source_id'],fpga_access=False)));return
 assert os.geteuid()==0
 for path,expected in m.read(Path(__file__).parent/'inputs.json')['files'].items():assert m.sha(path)==expected,('follower input changed',path)
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 if (L/'complete.json').exists():
  save_metrics(L);return
 assert not (L/'deployment.json').exists(),'adopt existing deployment/run evidence; never redeploy automatically after a partial run'
 m.ST.update(schema='ec-original-svb-onboard/1',**m.ident(os.getpid()),functional_baseline=BASE,
  configuration=PROFILE,board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,complete_opt4=False,fpga_access=False)
 verify_inputs()
 while True:
  for root,unit in WAITERS:
   if (root/'complete.json').exists():
    save_metrics(root);update(status='ORIGINAL_SVB_ALREADY_MEASURED_NO_DUPLICATE_DEPLOYMENT');return
  choice=m.read(ROOT/'chosen-physical-result.json')
  if choice:
   assert choice['source_id']==SID and choice['functional_baseline']==BASE
   result=Path(choice['result']);assert result.is_relative_to(ROOT)
   assert m.sha(result)==choice['result_sha256']
   SPREAD=result.parent
   break
  update(status='WAITING_RECOVERY_RESULT_NO_FPGA_IO')
  time.sleep(300)
 cert=certify();assert cert
 while True:
  handoff=handoff_waiting_predecessor()
  if handoff is True:break
  if handoff is False:
   
   for root,unit in WAITERS:
    if (root/'complete.json').exists():save_metrics(root)
   return
  time.sleep(300)
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
 if good:
  bb.save(L/'complete.json',dict(result_sha256=m.sha(L/'result.json'),certificate_sha256=result['certificate_sha256']))
  save_metrics(L)
 active.update(status=result['status'],ended_utc=m.now());bb.save(m.D/'active-0000_21_00.0.json',active)
 update(status=result['status'],child={},result=str(L/'result.json'))

if __name__=='__main__':
 try:main()
 except Exception as e:
  if L.exists():update(status='FAILED_WITH_EVIDENCE',error=repr(e))
  raise
