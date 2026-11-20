#!/usr/bin/python3
"""Run the hash-verified original full GG model; never an FPGA sample.

Keep raw bridges and stdout. Application output alone cannot admit a checker
result: protocol/ROI analysis remains a separate gate.
"""
import importlib.util, os, pathlib, re, signal, subprocess, time
P=pathlib.Path; C=P(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-full-metasim-sample-r1-20261111';m.S=m.L/'state.json'

def main():
 m.L.mkdir(exist_ok=True)
 lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 assert not (m.L/'binding.json').exists(),'adopt existing run, never duplicate'
 probe=m.D/'cycleprecise-frozen-full-metasim-follow-r3-20261111'
 r=m.read(probe/'result.json');b=m.read(probe/'binding.json')
 assert r['target_progress_observed'] and r['target_cycles']==10001
 assert b['functional_baseline']==m.BASE
 binary=P(b['args'][0]);assert m.sha(binary)==b['binary_sha256']
 elf=m.D/'cycleprecise-frozen-canneal-20261111/test.riscv'
 assert m.sha(elf)==b['elf_sha256']
 args=[s.replace('+max-cycles=10000','+max-cycles=5000000') for s in b['args']]
 # Driver-owned persistent snapshots/print files, without target RTL changes.
 args[args.index('+permissive-off'):args.index('+permissive-off')]=[
  '+heartbeat-polling-interval=1000','+print-file='+str(m.L/'rtl-prints-')]
 m.ST.update(schema='ec-original-full-gg-metasim-workload/1',**m.ident(os.getpid()),
  functional_baseline=m.BASE,fpga_access=False,formal_fpga_sample=False,started_utc=m.now())
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,probe_binding_sha256=m.sha(probe/'binding.json'),
  binary_sha256=m.sha(binary),elf_sha256=m.sha(elf),args=args,software_profile='canneal project400 bare-metal',
  target_platform='original DacOpt4C4 DacXilinxAlveoConfig GG model',scope='CPU metasimulation, no FPGA/Native slowdown or architectural restart admission',
  application_expected_output='benchmark=canneal checksum=40b2b50000000000 verified=1 routing_cost=4789',
  target_cycle_limit=5000000,host_timeout_seconds=10800,owned_log_budget_bytes=4*2**30))
 log=m.L/'host.log';start=time.monotonic();cause=None
 with log.open('xb',buffering=0) as f:
  child=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*args],cwd=m.L,stdin=subprocess.DEVNULL,
   stdout=f,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':''})
  m.update(status='RUNNING_FULL_GOLDENGATE_CANNEAL_NOT_VALIDATED',child=m.ident(child.pid))
  while True:
   try:rc=child.wait(timeout=30)
   except subprocess.TimeoutExpired:rc=None
   files=[p for p in m.L.iterdir() if p.is_file()]
   total=sum(p.stat().st_size for p in files)
   hb=m.L/'heartbeat.csv';tail=hb.read_text().splitlines()[-1] if hb.exists() else None
   m.update(host_wall_seconds=time.monotonic()-start,owned_log_bytes=total,heartbeat_last_row=tail,
    process_exited=rc is not None)
   os.fsync(f.fileno())
   if rc is not None:break
   if total>4*2**30:cause='OWNED_LOG_BUDGET_EXCEEDED'
   if time.monotonic()-start>10800:cause='HOST_TIMEOUT'
   if cause:
    # Only this controller's own bounded child process group.
    os.killpg(child.pid,signal.SIGTERM)
    try:rc=child.wait(timeout=20)
    except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);rc=child.wait()
    break
 logs=log.read_text(errors='replace')
 app=re.findall(r'\[APP\] protected=(\d+) start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+) session_stop=(\d+)',logs)
 output='benchmark=canneal checksum=40b2b50000000000 verified=1 routing_cost=4789'
 correctness=rc==0 and cause is None and output in logs and '[COMPUTATION] status=PASS' in logs and '[END] hart=0 status=PASS' in logs
 fault=bool(re.search(r'Assertion failed|%Error|\*\*\* FAILED|status=FAIL|Simulator deadlock detected',logs))
 x=dict(status='APPLICATION_OUTPUT_MATCH_PROTOCOL_PENDING' if correctness and not fault else 'WORKLOAD_NOT_VALIDATED_WITH_EVIDENCE',
  functional_baseline=m.BASE,kind='FULL_GOLDENGATE_CPU_METASIM_NOT_FPGA',returncode=rc,stop_cause=cause,
  output_correctness=correctness,fault_marker=fault,roi_records=app,host_wall_seconds=time.monotonic()-start,
  checker_validation=False,strict_checker_latency='NOT_MEASURED',architectural_restart_tested=False,
  files={str(p):m.sha(p) for p in m.L.iterdir() if p.is_file() and p.name not in ['state.json','instance.lock']})
 m.save(m.L/'result.json',x);m.update(status=x['status'],child={},result=str(m.L/'result.json'))

if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));raise
