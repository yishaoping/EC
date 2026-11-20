from common import *
import shutil,subprocess
out=ROOT/'software/streamcluster_project64'
assert not out.exists()
out.mkdir()
ref=read(SOURCE/'build.manifest.json')
shutil.copytree(SOURCE/'source',out/'source',ignore=shutil.ignore_patterns('Benchmark'))
shutil.copy2(SOURCE/'htif.ld',out/'htif.ld')
sourcehash={str(p.relative_to(out/'source')):sha(p) for p in (out/'source').rglob('*') if p.is_file()}
for n,h in ref['source_sha256'].items():
 if n in sourcehash:assert sourcehash[n]==h,n
native=module(W/'candidates/matched-single-boom-gg-r1-20261112/controller.py','native_adapter').NATIVE_MAIN
(out/'native-main.c').write_text(native)
commands=[]
with (out/'build.log').open('wb') as log:
 for cmd in ref['commands']:
  argv=[a.replace(str(SOURCE),str(out)) for a in cmd]
  subprocess.run(argv,cwd=out,stdout=log,stderr=subprocess.STDOUT,check=True);commands.append(argv)
 shutil.copy2(out/'protected.riscv',out/'ec.riscv')
 cmd=[a.replace(str(SOURCE),str(out)) for a in ref['commands'][1]]
 cmd[cmd.index('-c')+1]=str(out/'native-main.c');cmd[-1]=str(out/'native-main.o')
 subprocess.run(cmd,cwd=out,stdout=log,stderr=subprocess.STDOUT,check=True);commands.append(cmd)
 cmd=[a.replace(str(SOURCE),str(out)) for a in ref['commands'][-1]]
 cmd=[str(out/'native-main.o') if a==str(out/'1.o') else a for a in cmd];cmd[-1]=str(out/'native.riscv')
 subprocess.run(cmd,cwd=out,stdout=log,stderr=subprocess.STDOUT,check=True);commands.append(cmd)
save(out/'manifest.json',dict(benchmark='streamcluster',profile='project64',method='CPU_GG_COMPLETE_PROJECT_INPUT',functional_baseline=BASE,threads=1,commands=commands,source_sha256=sourcehash,shared_kernel_objects={str(p):sha(p) for p in out.glob('*.o') if p.name not in ['1.o','native-main.o']},expected_output=['benchmark=streamcluster checksum=38343be6f0bf622b verified=1 centers=3 weight=64'],elf={mode:dict(path=str(out/(mode+'.riscv')),sha256=sha(out/(mode+'.riscv'))) for mode in ['native','ec']},roi_scope=ref['roi_scope'],input=ref['parameters'],seed=ref['seed'],same_elf=False,layout_caveat='Different startup and linked addresses; kernel objects and input identical',max_target_cycles=6000000,timeout_seconds=10800))
print(out/'manifest.json')
