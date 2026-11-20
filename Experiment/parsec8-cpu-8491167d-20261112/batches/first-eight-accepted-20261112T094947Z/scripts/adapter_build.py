"""Build serial PARSEC adapters with a shared HTIF/timer measurement contract."""
from common import *
import shutil,subprocess

def setup(name):
 out=ROOT/'software'/name
 out.mkdir(exist_ok=True)
 if not (out/'source').exists():
  base=ROOT/'software/swaptions_no_main_timer'
  shutil.copytree(base/'source',out/'source',ignore=shutil.ignore_patterns('Benchmark'))
  shutil.copy2(base/'htif.ld',out/'htif.ld')
 return out,out/'source'

def build(out,files,metadata,host_files=None):
 src=out/'source';base=read(ROOT/'software/swaptions_no_main_timer/manifest.json')
 flags=base['commands'][0][1:base['commands'][0].index('-c')]
 flags=['-I'+str(src),*flags,'-fno-exceptions','-fno-rtti',*metadata.get('extra_flags',[]),*metadata.get('target_extra_flags',[])]
 gcc=str(TOOLS/'riscv64-unknown-elf-gcc');gxx=str(TOOLS/'riscv64-unknown-elf-g++')
 common=['hw/interrupt.c','stat/report.c','core/secondary.c','cfg/init.c','core/checker.c','hw/spin_lock.c','cxx_runtime.c']
 cmds=[];objs=[]
 with (out/'build.log').open('wb') as log:
  for i,name in enumerate(common+files):
   tool=gxx if name.endswith('.cpp') else gcc
   obj=out/f'app-{i}.o';cmd=[tool,*flags,'-c',str(src/name),'-o',str(obj)]
   subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(cmd);objs.append(str(obj))
  for mode,main in [('native','native-main.c'),('ec','test.c')]:
   obj=out/(mode+'-main.o');cmd=[gcc,*flags,'-c',str(src/main),'-o',str(obj)]
   subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(cmd)
   cmd=[gxx,*flags,*objs,str(obj),'-Wl,--gc-sections','-Wl,-Map='+str(out/(mode+'.map')),'-lm','-o',str(out/(mode+'.riscv'))]
   subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(cmd)
  hfiles=host_files or files
  hostobjs=[]
  for i,name in enumerate(hfiles+['host-reference.cpp']):
   tool='/usr/bin/g++' if name.endswith('.cpp') else '/usr/bin/gcc'
   obj=out/f'host-{i}.o';cmd=[tool,'-O2','-fno-exceptions','-I'+str(src),*metadata.get('extra_flags',[]),'-c',str(src/name),'-o',str(obj)]
   subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(cmd);hostobjs.append(str(obj))
  cmd=['/usr/bin/g++',*hostobjs,'-lm','-o',str(out/'host-reference')]
  subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(cmd)
  proc=subprocess.run([str(out/'host-reference')],cwd=out,check=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,timeout=60)
 (out/'host-reference.log').write_text(proc.stdout+proc.stderr)
 outputs=[s.split('[OUTPUT] ',1)[1] for s in proc.stdout.splitlines() if s.startswith('[OUTPUT] ')]
 assert len(outputs)==1 and 'verified=1' in outputs[0],proc.stdout
 metadata.update(functional_baseline=BASE,threads=1,commands=cmds,source_sha256={str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()},
  shared_kernel_objects={p:sha(p) for p in objs},expected_output=outputs,
  host_reference={'path':str(out/'host-reference'),'sha256':sha(out/'host-reference'),'log':str(out/'host-reference.log'),'log_sha256':sha(out/'host-reference.log')},
  elf={m:{'path':str(out/(m+'.riscv')),'sha256':sha(out/(m+'.riscv'))} for m in ['native','ec']},same_elf=False,
  interrupt_policy=base['interrupt_policy'],max_target_cycles=metadata.get('max_target_cycles',2000000),timeout_seconds=metadata.get('timeout_seconds',3600))
 save(out/'manifest.json',metadata)
 return metadata
