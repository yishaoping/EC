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
BASE=m.BASE; PROFILE='OriginalSVB32-component-trace-host40'
SID='b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
PREP=m.D/'cycleprecise-frozen-svb-fpga-r2-20261111'
PROOF=m.D/'cycleprecise-frozen-svb-trace-r4-20261111'
L=m.D/'cycleprecise-original-svb-host40-shell-onboard-r2-20261112'
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
 assert b['profile']=='OriginalSVB32-component-trace' and b['source_id']==SID and b['functional_baseline']==BASE and not b['complete_opt4']
 assert m.sha(PROOF/'result.json')==b['cycle_proof_sha256']
 assert m.sha(PROOF/'binding.json')==b['target_binding_sha256']
 assert r['negative_rejected'] and r['compared_output_values']==42291
 assert r['output_ports']==127 and r['functional_baseline']==BASE and not r['architectural_restart_tested']
 assert d['source_id']==SID and d['profile']=='OriginalSVB32-component-trace' and d['board_allowlist']==['0000:21:00.0']
 assert m.sha(d['binary'])==d['binary_sha256']
 assert m.sha(PROOF/'target-cycles.txt')==d['trace_sha256']
 assert m.sha(PREP/'simif_xilinx_alveo_u280_21_only.cc')==d['guarded_source_sha256']
 r=m.read(PREP/'receipts/adapter-compare.json');assert r['returncode']==0
 assert m.sha(r['log'])==r['log_sha256']
 s=Path(r['log']).read_text();assert 'compared_fields=42291' in s and '[SVBProbe]PASS Test' in s and 'unstable value' not in s
 return cfg,b,d

def certify():
 spec=importlib.util.spec_from_file_location('independent_host40_cert',Path(__file__).parent/'certificate.py')
 cert=importlib.util.module_from_spec(spec);spec.loader.exec_module(cert)
 return cert.certify(sys.modules[__name__])


def existing_component_winner():
 for name in ['cycleprecise-original-svb-onboard-r1-20261111','cycleprecise-original-svb-spread-onboard-r2-20261111','cycleprecise-original-svb-recovered-onboard-r1-20261111','cycleprecise-original-svb-host40-onboard-r1-20261112']:
  p=m.D/name;r=m.read(p/'result.json');done=m.read(p/'complete.json')
  if r.get('status')=='VALID_COMPONENT_FPGA_TRACE' and done:
   assert done['result_sha256']==m.sha(p/'result.json')
   assert r['source_id']==SID and r['board_bdf']==bb.TARGET_BDF
   assert r['certificate_sha256']==m.sha(p/'certified-component.json')
   return p
 return None


def handoff_idle_host40_predecessor():
 unit='ec-opt4-svb-host40-follow-r1.service'
 root=m.D/'cycleprecise-original-svb-host40-onboard-r1-20261112'
 row=m.read(root/'state.json')
 props=dict(x.split('=',1) for x in subprocess.check_output(['systemctl','show',unit,'-p','MainPID','-p','ActiveState','-p','ControlGroup'],text=True).splitlines() if '=' in x)
 if props.get('MainPID')=='0':return True
 if row.get('status')!='WAITING_INDEPENDENT_HOST40_PHYSICAL_RESULT_NO_FPGA_IO' or row.get('child') or row.get('fpga_access') or (root/'deployment.json').exists():
  update(status='WAITING_EXISTING_HOST40_R1_AUDIT_OR_BOARD_ACTIVITY_NO_PREEMPTION',predecessor=row);return False
 pid=int(props['MainPID'])
 assert pid==row['pid'] and m.ident(pid).get('start_ticks')==row['start_ticks']
 cgname='/system.slice/'+unit
 assert props.get('ControlGroup')==cgname
 cg=Path('/sys/fs/cgroup/systemd')/cgname.lstrip('/')
 assert (cg/'cgroup.procs').is_file()
 tasks=set(int(x) for f in cg.rglob('cgroup.procs') for x in f.read_text().split())
 if tasks!={pid}:
  update(status='WAITING_HOST40_R1_CHILD_OR_UNVERIFIED_CGROUP_NO_PREEMPTION',predecessor_tasks=sorted(tasks));return False
 argv=(Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0')
 assert any(b'svb-host40-physical-r1-20261112/runtime.py' in x for x in argv)
 bb.save(L/'host40-r1-idle-handoff-before.json',dict(predecessor=row,service_properties=props,cgroup_tasks=sorted(tasks),both_shared_21_locks_held=True,certificate_sha256=m.sha(L/'certified-component.json'),utc=m.now(),cad_or_device_signalled=False))
 subprocess.run(['systemctl','stop',unit],check=True)
 assert subprocess.check_output(['systemctl','show',unit,'-p','MainPID','--value'],text=True).strip()=='0'
 bb.save(L/'host40-r1-idle-handoff-complete.json',dict(stopped_idle_waiter_pid=pid,both_shared_21_locks_held=True,cad_or_device_signalled=False,utc=m.now()))
 return True


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
 for path,expected in m.read(Path(__file__).parent/'runtime-inputs.json')['files'].items():assert m.sha(path)==expected,('follower input changed',path)
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 if (L/'complete.json').exists():
  save_metrics(L);return
 assert not (L/'deployment.json').exists(),'adopt existing deployment/run evidence; never redeploy automatically after a partial run'
 m.ST.update(schema='ec-original-svb-onboard/1',**m.ident(os.getpid()),functional_baseline=BASE,
  configuration=PROFILE,board_bdf=bb.TARGET_BDF,board_serial=bb.TARGET_SERIAL,complete_opt4=False,fpga_access=False)
 verify_inputs()
 while True:
  winner=existing_component_winner()
  if winner:
   update(status='EXISTING_VALID_COMPONENT_WINS_NO_HOST40_REDEPLOYMENT',winner=str(winner));return
  choice=m.read(m.D/'cycleprecise-svb-host40-shell-recovery-r2-20261112/chosen-result.json')
  if choice:
   assert choice['profile']==PROFILE and choice['source_id']==SID
   result_path=Path(choice['result']);assert result_path.is_relative_to(m.D/'cycleprecise-svb-host40-shell-recovery-r2-20261112')
   assert m.sha(result_path)==choice['result_sha256']
   SPREAD=result_path.parent
   result=m.read(result_path)
   if result.get('status')=='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION':break
  physical=m.read(m.D/'cycleprecise-svb-host40-shell-recovery-r2-20261112/state.json')
  if physical.get('status') in ['BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED','FAILED_WITH_EVIDENCE']:
   update(status='HOST40_R2_PHYSICAL_FAILURE_PRESERVED_NO_DEPLOYMENT');return
  update(status='WAITING_INDEPENDENT_HOST40_PHYSICAL_RESULT_NO_FPGA_IO')
  time.sleep(300)
 cert=certify();assert cert
 while True:
  winner=existing_component_winner()
  if winner:
   update(status='EXISTING_VALID_COMPONENT_WINS_NO_HOST40_REDEPLOYMENT',winner=str(winner));return
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
  if existing_component_winner():
   for f in locks:f.close()
   update(status='EXISTING_VALID_COMPONENT_WINS_AFTER_21_LOCK_NO_REDEPLOYMENT');return
  if not handoff_idle_host40_predecessor():
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
  active=dict(schema='ec-original-component-run/1',run_id=L.name,run_dir=str(L),status='RUNNING',physical_host_clock_period_ns=24.9975,
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
  kind='FPGA_ORIGINAL_SVB32_HOST40_DIRECTED_COMPONENT_TRACE_NOT_FULL_OPT4',profile=PROFILE,physical_host_clock_period_ns=24.9975,physical_host_clock_frequency_hz=1e9/24.9975,target_frequency_hz=None,target_cycle_definition_changed=False,functional_baseline=BASE,source_id=SID,
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
