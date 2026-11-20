#!/usr/bin/python3
"""Adopt the live full-host compilation, repair link only after it exits.

Then perform one bounded CPU boot probe. No FPGA, CAD, Native runs or benchmark
admission. A maximum-cycle stop is diagnostic, never a passed experiment.
"""
import importlib.util, os, pathlib, re, subprocess, time
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-full-metasim-follow-r1-20261111';m.S=m.L/'state.json'
def alive(s):
 for key in ['pid','start_ticks','host_boot_id']:
  if key not in s:return False
 return m.ident(s['pid'])=={k:s[k] for k in ['pid','start_ticks','host_boot_id']}
def main():
 m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 parent=m.D/'cycleprecise-frozen-full-metasim-r1-20261111'
 m.ST.update(schema='ec-frozen-full-metasim-postcompile/1',**m.ident(os.getpid()),functional_baseline=m.BASE,
  fpga_access=False,formal_performance_sample=False,parent=str(parent/'state.json'))
 while True:
  s=m.read(parent/'state.json')
  if alive(s):
   m.update(status='WAITING_FOR_EXISTING_LIVE_COMPILATION_NO_INTERFERENCE',parent_stage=s.get('stage'));time.sleep(300);continue
  if s.get('status','').startswith('BUILT_') or s.get('status')=='FAILED_WITH_EVIDENCE':break
  raise RuntimeError('Parent exited without reviewed terminal receipt; preserve partial compilation')
 bind=m.read(parent/'binding.json');assert bind['functional_baseline']==m.BASE
 out=parent/'host';binary=out/'VFrozenOpt4';model=out/'VFrozenOpt4.csrc'
 # Parent has exited. Add exact SONAME aliases for its private dependency
 # symlinks, so runtime uses the same library versions as the repaired link.
 for lib in list((parent/'external-libs').glob('*.so')):
  info=subprocess.check_output(['/usr/bin/readelf','-d',str(lib)],text=True)
  hit=re.search(r'\(SONAME\).*?\[(.*?)\]',info)
  if hit:
   alias=lib.with_name(hit[1])
   if not alias.exists():alias.symlink_to(lib.resolve())
 if not s.get('status','').startswith('BUILT_'):
  log=(parent/'compile.log').read_text(errors='replace')
  assert 'undefined reference' in log or 'undefined symbol' in log,'non-link failure requires separate reviewed recovery'
  assert (model/'Vemul.mk').is_file()
  # Override link flags only, reusing valid generated C++ and object files.
  # The original failed compile log and receipt are never rewritten.
  env={**os.environ,**bind['environment'],'LD_LIBRARY_PATH':''}
  flags=bind['environment']['LDFLAGS']+' -lstdc++ -lpthread -lgmp -l:libdwarf.so -l:libelf.so -lz'
  m.save(m.L/'link-repair-binding.json',dict(parent_binding_sha256=m.sha(parent/'binding.json'),
   original_makefile_sha256=m.sha(model/'Vemul.mk'),original_failure_sha256=m.sha(parent/'compile.log'),
   repair='Link-only library flags; no RTL or generated C++ edits',flags=flags))
  m.stage('link-repair',['/usr/bin/make','-C',str(model),'-f','Vemul.mk','-j2','VM_USER_LDLIBS='+flags],m.L,[binary],env=env,timeout=3600)
 assert binary.is_file()
 replay=m.D/'cycleprecise-frozen-canneal-20261111'
 rb=m.read(replay/'binding.json');elf=replay/'test.riscv'
 assert rb['functional_baseline']==m.BASE and m.sha(elf)==rb['elf_sha256']
 mf=m.W/'runtime/fased-common/manifest.json';argsfile=mf.with_name('fased-common.args');memory=m.read(mf)
 assert m.sha(argsfile)==memory['arguments_sha256'] and memory['settings']['relaxFunctionalModel']==0
 argv=[str(binary),'+permissive','+max-cycles=10000','+fesvr-step-size=1000',*memory['plusargs'],
  '+prog0='+str(elf),'+permissive-off']
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,binary_sha256=m.sha(binary),elf_sha256=m.sha(elf),
  parent_binding_sha256=m.sha(parent/'binding.json'),memory_manifest_sha256=m.sha(mf),args=argv,
  scope='Bounded original full FireSim host-model boot probe, 10000 target cycles maximum; not ROI, checker acceptance or formal PARSEC.'))
 start=time.monotonic();log=m.L/'boot-probe.log';assert not log.exists()
 with log.open('xb',buffering=0) as f:
  child=subprocess.Popen(argv,cwd=m.L,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
   env={**os.environ,'LD_LIBRARY_PATH':''})
  m.update(status='RUNNING_BOUNDED_FULL_HOST_BOOT_PROBE',child=m.ident(child.pid))
  try:rc=child.wait(timeout=1800)
  except subprocess.TimeoutExpired:
   child.terminate()
   try:rc=child.wait(timeout=20)
   except subprocess.TimeoutExpired:child.kill();rc=child.wait()
   rc='HOST_TIMEOUT'
 text=log.read_text(errors='replace');hit=re.search(r'Target Cycles Emulated:\s*([\d,]+)',text)
 cycles=int(hit[1].replace(',','')) if hit else None
 m.update(status='BOOT_PROBE_FINISHED_NOT_A_FORMAL_SAMPLE',child={},returncode=rc,
  target_cycles=cycles,host_wall_seconds=time.monotonic()-start,log_sha256=m.sha(log),
  target_progress_observed=cycles is not None and cycles>=10000,
  checker_pass=False,application_output_validated=False,maximum_cycle_stop_is_not_benchmark_pass=True)
 m.save(m.L/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
