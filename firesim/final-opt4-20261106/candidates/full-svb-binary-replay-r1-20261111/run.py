#!/usr/bin/python3
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,sys,time,traceback
C=Path(__file__).resolve().parent
W=C.parents[1]
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=D/'cycleprecise-frozen-svb-r3-20261111'
O=D/'cycleprecise-original-svb-binary-replay-r1-20261111'
STATE=D/'Opt4-original-svb-binary-replay-r1-state.json'
OBS=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
INC=Path('/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/share/verilator/include')
sys.path.insert(0,str(C.with_name('full-gg-external-observer-r5-20261111')))
from validate_binary import validate
from controller import save,read,sha,now,ident
def state(status,**v):save(STATE,dict(status=status,**ident(os.getpid()),updated_utc=now(),fpga_access=False,**v))
def run_cmd(args,name):
 started=time.monotonic()
 with (O/name).open('xb') as log:
  p=subprocess.Popen(args,cwd=O,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
  state('RUNNING_'+name.replace('.','_'),child=ident(p.pid),argv=args)
  try:rc=p.wait(timeout=1800)
  except subprocess.TimeoutExpired:p.kill();p.wait();raise
 return dict(argv=args,returncode=rc,host_wall_seconds=time.monotonic()-started,log=str(O/name),log_sha256=sha(O/name))
def check_inputs():
 plan=read(C/'plan.json')
 assert sha(plan['archive'])==plan['archive_sha256']
 assert sha(plan['frozen_rtl'])==plan['frozen_rtl_sha256']
 for p,h in plan['model_object_inputs'].items():assert sha(p)==h
 assert sha(C/'replay.cpp')==plan['replay_source_sha256']
 policy=read(D/'unattended-opt4/campaign-policy.json')
 assert policy['functional_baseline_commit']==plan['functional_baseline'] and policy['area_equivalence_only'] and policy['native_paused'] and not policy['fpga_access']
 assert policy['board_allowlist']==['0000:21:00.0']
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:2]);resource.setrlimit(resource.RLIMIT_AS,(24*2**30,)*2)
 return plan
def prepare_run():
 assert not O.exists(),'adopt existing replay'
 O.mkdir();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 plan=check_inputs()
 assert read(OBS/'probe-result.json')['passed']
 trace=OBS/'probe-observer-on/external-events.jsonl.svb-full.bin'
 integrity=validate(C/'binary-layout.json',trace)
 compile_args=[CLANG,'-std=c++20','-O1','-DVL_TIME_CONTEXT','-I'+str(INC),'-I'+str(INC/'vltstd'),'-I'+str(R/'obj'),'-c',str(C/'replay.cpp'),'-o',str(C/'replay.o')]
 link_args=[CLANG,str(C/'replay.o'),str(R/'obj/verilated.o'),str(R/'obj/verilated_threads.o'),str(R/'obj/VSpeculativeVersionBuffer__ALL.a'),'-lpthread','-latomic','-o',str(C/'replay')]
 compiled=run_cmd(compile_args,'compile.log');assert compiled['returncode']==0
 linked=run_cmd(link_args,'link.log');assert linked['returncode']==0
 save(O/'build-receipt.json',dict(binary_sha256=sha(C/'replay'),compile=compiled,link=linked,archive_sha256=plan['archive_sha256'],model_objects_rebuilt=False))
 probe=run_cmd([str(C/'replay'),str(trace)],'probe-replay.log')
 negative=run_cmd([str(C/'replay'),'--self-test-data'],'data-mutation.log')
 passed=probe['returncode']==0 and negative['returncode']==0 and 'REPLAY_DATA_MUTATION_REJECTED' in (O/'data-mutation.log').read_text()
 result=dict(status='PASS_RESET_STARTED_STARTUP_TRACE_AND_DIRECTED_DATA_MUTATION' if passed else 'FAILED_WITH_EVIDENCE',passed=passed,
  trace_integrity=integrity,probe=probe,directed_data_mutation=negative,binary_sha256=sha(C/'replay'),plan_sha256=sha(C/'plan.json'),
  scope='10k real original GoldenGate SVB target-edge startup trace versus standalone frozen target module; zero real SVB events in startup; directed mutation is synthetic',fpga_access=False,completed_utc=now())
 save(O/'result.json',result);state(result['status'],child={},result=str(O/'result.json'))
def full_run():
 plan=check_inputs();assert read(O/'result.json')['passed']
 assert not (O/'full-result.json').exists(),'adopt complete full replay'
 assert read(OBS/'full-result.json')['valid_finite_observation']
 lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 trace=OBS/'canneal-observer-on/external-events.jsonl.svb-full.bin'
 integrity=validate(C/'binary-layout.json',trace)
 receipt=read(O/'build-receipt.json');assert sha(C/'replay')==receipt['binary_sha256']
 actual=run_cmd([str(C/'replay'),str(trace)],'full-replay.log')
 negative=run_cmd([str(C/'replay'),str(trace),'--mutate-data'],'full-data-mutation.log')
 # Zero real promotions cannot satisfy the application payload mutation gate.
 mutation_admitted=negative['returncode']==0 and integrity['counts']['promote_accepted']>0
 passed=actual['returncode']==0 and mutation_admitted
 result=dict(status='PASS_FULL_REAL_APPLICATION_ORIGINAL_SVB_TARGET_REPLAY_AND_DATA_MUTATION' if passed else 'FULL_REPLAY_FAILED_OR_NO_REAL_PROMOTION',passed=passed,
  trace_integrity=integrity,positive=actual,actual_payload_mutation_rejected=mutation_admitted,negative=negative,
  original_full_metasim_result_sha256=sha(OBS/'full-result.json'),binary_sha256=sha(C/'replay'),plan_sha256=sha(C/'plan.json'),
  scope='CPU standalone original target SVB replay, all defined outputs of62 original host ports; not an FPGA sample or whole-system equivalence',fpga_access=False,completed_utc=now())
 save(O/'full-result.json',result);state(result['status'],child={},result=str(O/'full-result.json'))
if __name__=='__main__':
 try:{'--prepare':prepare_run,'--full':full_run}[sys.argv[1]]()
 except BaseException as error:
  if O.exists():save(O/'failure-'+str(os.getpid())+'.json',dict(error=repr(error),traceback=traceback.format_exc(),utc=now()))
  state('FAILED_WITH_EVIDENCE',error=repr(error));raise
