#!/usr/bin/python3
"""Rerun only timed-out MC host from reset; retain completed Plain evidence."""
import argparse,datetime,fcntl,hashlib,importlib.util,json,os,pathlib,resource
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OLD=D/'cycleprecise-owner-pair-runtime-r1-20261111';O=D/'cycleprecise-owner-mc-runtime-r2-20261112';S=D/'Opt4-mcrams-owner-mc-runtime-r2-state.json'
HELPER=W/'candidates/mcrams-owner-pair-metasim-r1-20261111/controller.py'
def read(p):return json.loads(P(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()));q.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(q,p)
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--run',action='store_true');ap.parse_args();plan=read(C/'plan.json')
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);assert not S.exists()
 assert all(sha(p)==h for p,h in plan['inputs'].items())
 os.sched_setaffinity(0,{250,251});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 sp=importlib.util.spec_from_file_location('helpers',HELPER);m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);m.O=O;m.S=S
 m.ST.update(schema='ec-owner-MC-rerun-from-reset-existing-Plain/2',**m.ident(),started_utc=m.now(),functional_baseline=plan['functional_baseline'],derived_hardware=plan['derived_hardware'],fpga_access=False,whole_fit=False,production_admission=False,reused_Plain=True,rerun_from_reset=True,instruction_checkpoint_restored=False)
 m.update(status='STARTED_RERUN_MC_ONLY');m.guard();run_dir=O/'MCRams/run';run_dir.mkdir(parents=True)
 env={**os.environ,**plan['environment']};args=[plan['binary']]+['+print-file='+str(run_dir/'rtl-prints-') if a.startswith('+print-file=') else a for a in plan['reference_args'][1:]]
 assert '+max-cycles=5000000' in args
 r=m.stage('run-MCRams',args,run_dir,env,timeout=57600,budget=16*2**30)
 b=O/'MCRams/host/VOwnerPairMCRams';b.parent.mkdir();b.symlink_to(plan['binary']);actual=m.parse_run('MCRams',r,plan['application_expected_output']);old=read(OLD/'result.json');plain=old['results']['Plain'];assert plain['output_correctness']
 # Host stdout interleaving is not a target-cycle parity criterion. Compare
 # original captured target print streams and CSR ROI/output records only.
 rows=actual['target_rows']==plain['target_rows'];prints=actual['captured_print_streams']==plain['captured_print_streams'] and len(actual['captured_print_streams'])>=2
 ok=actual['output_correctness'] and rows and prints
 m.update(status='PASS_FINITE_SAME_TARGET_CAPTURED_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE' if ok else 'MC_FAILED_OR_CAPTURED_PARITY_MISMATCH_PRESERVED',
   results=dict(Plain=plain,MCRams=actual),captured_finite_parity_passed=ok,exact_target_rows=rows,exact_captured_print_streams=prints,
   host_stdout_byte_compare_used=False,completed_utc=m.now(),strict_latency_or_full_state_equivalence=False)
 save(O/'result.json',m.ST)
if __name__=='__main__':main()
