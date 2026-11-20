#!/usr/bin/python3
"""Recover the completed Native CPU build, then automatically measure two ROIs.
Only matching original Native host collector sources are supplied. Reuses
generated C++/objects; no re-elaboration, target RTL edits or FPGA operations.
"""
from pathlib import Path
import argparse,fcntl,gzip,hashlib,importlib.util,json,os,re,resource,shutil,subprocess,time,traceback
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent;P=W/'candidates/matched-single-boom-gg-r1-20261112'
U=D/'unattended-opt4';OLD=D/'cycleprecise-matched-single-boom-gg-r1-20261112'
O=D/'cycleprecise-matched-single-boom-gg-r3-20261112';S=D/'Opt4-matched-single-boom-gg-r3-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8';NAME='matched-single-boom-gg-r3-8491167d'
spec=importlib.util.spec_from_file_location('bound_native_helpers',P/'controller.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.O=O;m.S=S
def assignments(path,name):
 text=Path(path).read_text();match=re.search(r'^'+name+r'\s*=\s*(.*?)(?=\n\n|\Z)',text,re.M|re.S);assert match,name
 return [word for word in match[1].replace('\\\n',' ').split() if word != chr(92)]
def prepare():
 m.policy();assert not O.exists() and not (C/'plan.json').exists()
 oldstate=m.read(U/'jobs/matched-single-boom-gg-r2-8491167d/state.json')
 assert oldstate['status']=='FAILED_WITH_EVIDENCE' and oldstate['returncode']==1
 for row in [oldstate,oldstate.get('child',{})]:assert not row or m.ident(row.get('pid',0))!= {k:row[k] for k in ['pid','start_ticks','host_boot_id'] if k in row},'PRESERVE_LIVE_OLD_TASK'
 assert "No rule to make target" in (D/'cycleprecise-matched-single-boom-gg-r2-20261112/model-recovery.log').read_text()
 p=m.read(P/'plan.json');O.mkdir();overlay=C/'native-driver';(overlay/'bridges').mkdir(parents=True)
 source=W/'Native/chipyard/sims/firesim/sim/midas/src/main/cc/bridges'
 pins={str(W/'candidates/matched-single-boom-gg-r2-20261112/controller.py'):m.sha(W/'candidates/matched-single-boom-gg-r2-20261112/controller.py'),str(C/'controller.py'):m.sha(C/'controller.py'),str(P/'controller.py'):m.sha(P/'controller.py'),str(P/'plan.json'):m.sha(P/'plan.json')}
 for name in ['ec_dac_roi.h','ec_dac_roi.cc']:
  q=overlay/'bridges'/name;shutil.copy2(source/name,q);pins[str(q)]=m.sha(q);pins[str(source/name)]=m.sha(source/name)
 model=OLD/'host/VMatchingNative.csrc';mk=model/'Vemul.mk';assert mk.exists()
 classes=assignments(mk,'VM_USER_CLASSES')+['ec_dac_roi'];assert all(chr(92) not in x for x in classes)
 dirs=assignments(mk,'VM_USER_DIR')+[str(overlay/'bridges')]
 flags=assignments(mk,'VM_USER_CFLAGS')+['-I'+str(overlay)]
 argv=['/usr/bin/make','-C',str(model),'-f','Vemul.mk','-j8',
       'VM_USER_CLASSES='+' '.join(classes),'VM_USER_DIR='+' '.join(dirs),'VM_USER_CFLAGS='+' '.join(flags)]
 ec_audit=D/'overnight-ec-evidence-audit-r4-20261112'
 summary=m.read(ec_audit/'summary.json');complete=m.read(ec_audit/'complete.json')
 assert m.sha(ec_audit/'summary.json')==complete['summary_sha256']
 capsule=C/'evidence';capsule.mkdir()
 for src in [D/'cycleprecise-matched-single-boom-gg-r2-20261112/model-recovery.log',OLD/'software-build.json',OLD/'model-compile.log',ec_audit/'summary.json',ec_audit/'complete.json']:
  q=capsule/(m.sha(src)[:16]+'-'+src.name);shutil.copy2(src,q);pins[str(q)]=m.sha(q)
 budget={r['benchmark']:min(6*3600,int(r['host_wall_seconds']*2+600)) for r in summary['workloads']}
 plan=dict(schema='ec-clean-native-gg-recovery-and-roi/1',functional_baseline=BASE,
      native_source_id=p['native_source_id'],parent_plan_sha256=m.sha(P/'plan.json'),
      original_missing_collector_failure_sha256=m.sha(OLD/'model-compile.log'),previous_make_continuation_failure_sha256=m.sha(D/'cycleprecise-matched-single-boom-gg-r2-20261112/model-recovery.log'),
      original_makefile_sha256=m.sha(mk),native_driver_overlay_sha256=pins,
      command=argv,environment=p['environment'],binary=p['binary'],software=p['software'],memory_plusargs=p['memory_plusargs'],
      target_frequency_hz=200000000,cpu_affinity=list(range(208,216)),max_cpus=8,max_address_space_gib=64,
      compile_timeout_seconds=10800,workload_host_timeouts=budget,ec_audit=str(ec_audit/'summary.json'),
      stages=['REUSE_CXX_OBJECTS_ADD_ORIGINAL_NATIVE_DACROIBRIDGE','BOUNDED_BOOT','COMPLETE_CANNEAL_PROJECT400','COMPLETE_BLACKSCHOLES_PROJECT64'],
      fpga_access=False,native_fpga_paused=True,rtl_modified=False,output_correctness_required=True,
      limitations=['Native boot adapter uses independent ELF; complete kernel/input sources match EC',
      'Layout and initial cache state may differ; no perfect sameELF claim','No current formalLinuxPARSEC-FPGA matching comparison'])
 m.save(C/'plan.json',plan);pins[str(C/'plan.json')]=m.sha(C/'plan.json')
 req=dict(action='cpu_job',spec=dict(name=NAME,kind='analysis',cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],inputs=pins,
      outputs=[str(O/'compile-result.json'),str(O/'boot-probe.json'),str(O/'result.json')],checkpoints=[str(S)]))
 m.save(C/'request.json',req);dest=U/'requests'/(NAME+'.json');assert not dest.exists();m.save(dest,req)
 print(json.dumps(dict(status='SUBMITTED_NATIVE_COLLECTOR_RECOVERY_AND_AUTOMATIC_COMPLETE_WORKLOADS',request=str(dest),cpu_affinity=plan['cpu_affinity'],fpga_access=False),indent=2))

def execute_workload(s,plan,probe=False):
 name=s['workload'];short=name.split('_')[0];out=O/(name+('-boot' if probe else '-full'));out.mkdir()
 binary=Path(plan['binary']);limit=10000 if probe else (5000000 if short=='canneal' else 16000000)
 argv=[str(binary),'+permissive','+max-cycles='+str(limit),'+fesvr-step-size=1000',*plan['memory_plusargs'],
       '+ec-dac-roi-log='+str(out/'roi-raw.jsonl'),'+ec-dac-snapshot-seconds=20',
       '+print-file='+str(out/'rtl-prints-'),'+permissive-off','+prog0='+s['elf']]
 m.save(out/'binding.json',dict(argv=argv,plan_sha256=m.sha(C/'plan.json'),binary_sha256=m.sha(binary),elf_sha256=m.sha(s['elf']),
      native_source_id=plan['native_source_id'],functional_baseline=BASE,native_main_sha256=s['native_main_sha256'],
      kernel_input_source_sha256=s['kernel_and_input_source_sha256'],same_ec_elf=False,fpga_access=False))
 start=time.monotonic();rows=[];target=None;faults=[];rawhash=hashlib.sha256();rawbytes=0
 budget=1200 if probe else plan['workload_host_timeouts'][short]
 log=out/'host-complete.log.gz'
 with log.open('xb') as backing,(out/'host-summary.log').open('x') as compact:
  zipped=gzip.GzipFile(fileobj=backing,mode='wb',compresslevel=1)
  child=subprocess.Popen(argv,cwd=out,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,
       env={**os.environ,**plan['environment'],'LD_LIBRARY_PATH':''},start_new_session=True)
  m.update('RUNNING_MATCHED_NATIVE_'+name.upper()+('_PROBE' if probe else '_FULL'),child=m.ident(child.pid),run_dir=str(out),fpga_access=False)
  # Incremental output stays compressed; bounded pipe timeout is handled by a
  # process-owned watchdog. It never signals any other process or FPGA task.
  import threading
  timed=[]
  def timeout():
   if child.poll() is None:
    timed.append(True);os.killpg(child.pid,15)
  timer=threading.Timer(budget,timeout);timer.daemon=True;timer.start()
  for line in child.stdout:
   rawhash.update(line);rawbytes+=len(line);zipped.write(line)
   text=line.decode(errors='replace').rstrip('\r\n')
   if any(k in text for k in ['[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]']):rows.append(text);compact.write(text+'\n');compact.flush()
   hit=re.search(r'Target Cycles Emulated:\s*(\d+)',text)
   if hit:target=int(hit[1])
   if re.search(r'Assertion failed|%Error|status=FAIL|Simulator deadlock detected|EC_DAC_ROI_OBSERVER_FAILED',text):faults.append(text)
   if rawbytes>8*2**30 and child.poll() is None:timed.append('LOG_BUDGET');os.killpg(child.pid,15)
  rc=child.wait();timer.cancel();zipped.close();backing.flush();os.fsync(backing.fileno());compact.flush();os.fsync(compact.fileno())
 wall=time.monotonic()-start
 if probe:
  good=target is not None and target>=10000 and not faults and not timed
  result=dict(status='BOUNDED_NATIVE_TARGET_PROGRESS_NOT_BENCHMARK_PASS' if good else 'BOOT_FAILED',target_cycles=target,returncode=rc,host_wall_seconds=wall,
      binary_sha256=m.sha(binary),elf_sha256=m.sha(s['elf']),faults=faults,fpga_access=False,valid_performance_sample=False)
 else:
  roi=next((re.search(r'start=(\d+) stop=(\d+) cycles=(\d+)',row) for row in rows if '[ROI]' in row),None)
  app=next((re.search(r'cycles=(\d+) instret=(\d+)',row) for row in rows if '[APP]' in row),None)
  outputs=[row.split('[OUTPUT] ',1)[1] for row in rows if '[OUTPUT] ' in row]
  good=rc==0 and not timed and not faults and roi is not None and app is not None and outputs==s['expected_output'] and '[END] hart=0 status=PASS' in rows
  result=dict(status='PASS_TRUE_SINGLE_BOOM_COMPLETE_MATCHED_KERNEL_ROI' if good else 'FAILED_OR_UNVALIDATED_NATIVE_WORKLOAD',valid=good,
      benchmark=short,input_profile=name,native_source_id=plan['native_source_id'],functional_baseline=BASE,binary_sha256=m.sha(binary),
      elf_sha256=m.sha(s['elf']),protected_reference_elf_sha256=s['protected_reference_elf_sha256'],same_ec_elf=False,
      source_kernel_and_input_identical=True,native_adapter_difference='Original EC startup replaced with clean Native main; no EC instruction ignoring',
      roi_scope=s['roi_scope'],threads=s['threads'],target_boom_hz=200000000,memory_plusargs=plan['memory_plusargs'],
      total_fastest_target_cycles=target,returncode=rc,host_wall_seconds=wall,faults=faults,timeout=bool(timed),
      output=outputs,application_rows=rows,fpga_access=False,kind='CPU_GOLDENGATE_TRUE_SINGLE_BOOM_MATCHED_SOURCE_PROFILE')
  if roi and app:
   begin,end,cycles=map(int,roi.groups());assert end-begin==cycles==int(app[1])
   result.update(roi_start_csr=begin,roi_end_csr=end,roi_cycles=cycles,roi_instructions=int(app[2]))
 result.update(raw_stdout_bytes=rawbytes,raw_stdout_sha256=rawhash.hexdigest(),compressed_log_sha256=m.sha(log),completed_utc=m.now())
 m.save(out/'result.json',result)
 if good:m.save(out/'complete.json',dict(result_sha256=m.sha(out/'result.json'),binding_sha256=m.sha(out/'binding.json')))
 return result

def run():
 m.policy();plan=m.read(C/'plan.json');p=m.read(P/'plan.json')
 lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 m.ST.update(**m.ident(os.getpid()),functional_baseline=BASE,native_source_id=plan['native_source_id'],fpga_access=False)
 os.nice(5);os.sched_setaffinity(0,set(plan['cpu_affinity']));resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 assert m.sha(P/'plan.json')==plan['parent_plan_sha256']
 for q,h in plan['native_driver_overlay_sha256'].items():assert m.sha(q)==h,q
 env={**os.environ,**plan['environment']};built=m.command(plan['command'],O/'model-recovery.log',O,env,10800)
 binary=Path(plan['binary']);assert binary.is_file()
 m.save(O/'compile-result.json',dict(status='BUILT_ORIGINAL_SINGLE_BOOM_GG_WITH_MATCHING_NATIVE_HOST_COLLECTOR',binary=str(binary),binary_sha256=m.sha(binary),compile=built,fpga_access=False))
 boot=execute_workload(plan['software'][0],plan,probe=True);m.save(O/'boot-probe.json',boot)
 assert boot['status']=='BOUNDED_NATIVE_TARGET_PROGRESS_NOT_BENCHMARK_PASS','NATIVE_BOOT_GATE_FAILED'
 rows=[]
 for sw in plan['software']:
  # A failed application keeps its evidence and does not suppress the other one.
  try:rows.append(execute_workload(sw,plan))
  except Exception as e:rows.append(dict(benchmark=sw['workload'],status='FAILED_WITH_EVIDENCE',valid=False,error=repr(e),fpga_access=False))
 result=dict(status='COMPLETE_NATIVE_SOURCE_MATCHED_MEASUREMENTS' if all(r.get('valid') for r in rows) else 'PARTIAL_NATIVE_MEASUREMENTS_WITH_EVIDENCE',
      workloads=rows,plan_sha256=m.sha(C/'plan.json'),fpga_access=False,formal_linux_fpga=False,completed_utc=m.now())
 m.save(O/'result.json',result);m.update(result['status'],child={},result=str(O/'result.json'))

if __name__=='__main__':
 try:
  ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true');a=ap.parse_args()
  if a.prepare:prepare()
  elif a.run:run()
  else:raise ValueError('actionrequired')
 except BaseException as e:
  O.mkdir(exist_ok=True);m.save(O/('failure-'+str(os.getpid())+'.json'),dict(error=repr(e),traceback=traceback.format_exc(),fpga_access=False));raise
