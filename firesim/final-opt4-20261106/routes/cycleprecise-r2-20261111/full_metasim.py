#!/usr/bin/python3
"""Compile the existing final-target Golden Gate model, without CAD or FPGA.

Separate from the proven RAM probes. Compilation does not admit a performance
sample, and no unavailable architectural recovery behavior is added.
"""
import importlib.util, os, pathlib, shlex, shutil
P=pathlib.Path; C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-full-metasim-r1-20261111';m.S=m.L/'state.json'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'

def main():
 m.L.mkdir(exist_ok=True)
 lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
 m.ST.update(schema='ec-opt4-frozen-full-host-metasim/1',**m.ident(os.getpid()),
  functional_baseline=m.BASE,started_utc=m.now(),fpga_access=False,
  runtime_validation=False,formal_performance_sample=False)
 receipt=m.D/'build-logs/C4-driver-20261106T104028.658367Z/result.json'
 r=m.read(receipt)
 assert r['frozen_hardware_commit']==m.BASE and r['returncode']==0
 gg_receipt=P(r['input_result']);g=m.read(gg_receipt)
 assert m.sha(gg_receipt)==r['input_result_sha256'] and g['returncode']==0
 src=m.W/'builds/C4-goldengate-20261106T100436.256198Z'
 out=m.L/'host';out.mkdir(exist_ok=True)
 inputs={str(receipt):m.sha(receipt),str(gg_receipt):m.sha(gg_receipt)}
 for name in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
  p=src/name;h=m.sha(p)
  assert g['outputs'].get(str(p))==h,('GG binding mismatch',p)
  dst=out/name
  if not dst.exists():shutil.copy2(p,dst)
  assert m.sha(dst)==h
  inputs[str(p)]=h
 # External RTL resources already belong to the same GG receipt. Append only
 # absent definitions, to a private host copy; never touch existing collateral.
 sv=out/'FireSim-generated.sv';stamp=out/'blackbox-binding.json'
 if not stamp.exists():
  text=sv.read_text();added=[]
  for line in (src/'firrtl_black_box_resource_files.f').read_text().splitlines():
   p=P(line.strip())
   if not line.strip():continue
   inputs[str(p)]=m.sha(p)
   import re
   modules=re.findall(r'^\s*module\s+(\w+)',p.read_text(),re.M)
   if not all(re.search(r'\bmodule\s+'+re.escape(n)+r'\b',text) for n in modules):
    text+='\n'+p.read_text();added.append(str(p))
  if added:sv.write_text(text)
  m.save(stamp,dict(appended=added,sha256=m.sha(sv),inputs=inputs))
 else:assert m.sha(sv)==m.read(stamp)['sha256']
 log=(receipt.parent/'build.log').read_text().splitlines()
 line=next(s for s in reversed(log) if s.startswith('/usr/bin/g++ ') and 'firesim_top.cc' in s)
 argv=shlex.split(line)
 drivers=[p for p in argv if p.endswith('.cc') or p.endswith('.a')]
 assert drivers and all(P(p).is_file() for p in drivers)
 for p in drivers:inputs[p]=m.sha(p)
 # Keep compiler libc and C++ headers coherent. Expose only the nonstandard
 # dependency headers/libraries, rather than entire system directories.
 inc=m.L/'external-headers';inc.mkdir(exist_ok=True)
 conda=P(r['environment_overrides']['CONDA_PREFIX'])
 riscv=P(r['environment_overrides']['RISCV'])
 for name in ['gmp.h','dromajo_cosim.h','libdwarf.h','dwarf.h','libelf.h','gelf.h','zlib.h','zconf.h']:
  p=conda/'include'/name
  if name=='gmp.h':p=P('/usr/include/x86_64-linux-gnu/gmp.h')
  shutil.copy2(p,inc/name);inputs[str(p)]=m.sha(p)
 libs=m.L/'external-libs';libs.mkdir(exist_ok=True)
 for name in ['libgmp.so','libdwarf.so','libelf.so','libz.so','libzstd.so']:
  p=(P('/usr/lib/x86_64-linux-gnu') if name=='libgmp.so' else conda/'lib')/name
  if p.exists() and not (libs/name).exists():(libs/name).symlink_to(p)
 # Dromajo definitions are fixed to the original elaboration, even if its
 # bridge is absent from this particular configuration.
 old=P(r['output_dir'])
 for name in ['dromajo_params.h']:
  if (old/name).is_file():shutil.copy2(old/name,out/name)
 testchip=m.W/'C4/chipyard/generators/testchipip/src/main/resources/testchipip/csrc'
 flags=' '.join(['-O1','-I'+str(inc),'-I'+str(riscv/'include'),'-I'+str(testchip),
  '-I'+str(m.FS/'src/main/cc/firesim'),'-I'+str(m.FS/'firesim-lib/src/main/cc'),'-Wno-inconsistent-missing-override'])
 env={**os.environ,'PATH':str(P(CLANG).parent)+':'+str(P(m.V).parent)+':/usr/bin:/bin',
  'CXX':CLANG,'CXXFLAGS':flags,'LDFLAGS':'-L'+str(libs)+' -Wl,-rpath,'+str(libs),
  'LD_LIBRARY_PATH':'','MAKEFLAGS':'-j2'}
 cmd=['/usr/bin/make','-C',str(m.FS/'midas/src/main/cc'),'-j2','verilator',
  'PLATFORM=xilinx_alveo','DRIVER_NAME=FrozenOpt4','GEN_DIR='+str(out),
  'GEN_FILE_BASENAME=FireSim-generated','DRIVER='+' '.join(drivers),
  'VERILATOR_FLAGS=--compiler clang -Wno-fatal -Wno-MULTIDRIVEN','CXX='+CLANG]
 m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,source_id=r['source_id'],
  target_platform_config=r['platform_config'],input_sha256=inputs,
  host_rtl_sha256=m.sha(sv),command=cmd,environment={k:env[k] for k in ['PATH','CXX','CXXFLAGS','LDFLAGS','MAKEFLAGS']},
  scope='Actual original full FireSim host RTL. Compile first; runtime and parity acceptance are independent required gates. No FPGA access.'))
 m.stage('compile',cmd,m.L,[out/'VFrozenOpt4'],timeout=86400,env=env)
 m.update(status='BUILT_FULL_FROZEN_HOST_METASIM_RUNTIME_NOT_VALIDATED',binary=str(out/'VFrozenOpt4'),
  binary_sha256=m.sha(out/'VFrozenOpt4'),next='Bounded boot/target-cycle smoke with frozen software and FASED parameters, then compare full observations. Do not count build as a run.')
 m.save(m.L/'result.json',m.ST)

if __name__=='__main__':
 try:main()
 except Exception as e:
  m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
