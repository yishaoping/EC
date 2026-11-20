from common import *
import shutil,subprocess

old=ROOT/'software/swaptions_test-attempt5'
out=ROOT/'software/swaptions_no_main_timer'
assert not out.exists()
out.mkdir()
shutil.copytree(old/'source',out/'source',ignore=shutil.ignore_patterns('Benchmark'))
shutil.copy2(old/'htif.ld',out/'htif.ld')
mf=read(old/'manifest.json');src=out/'source'
ec=(src/'test.c').read_text().replace('    workload_prepare();','    __asm__ volatile("csrci mie, 128" ::: "memory");\n    workload_prepare();')
# csrci has a 5-bit immediate; use a register mask for the MTIE bit.
ec=ec.replace('__asm__ volatile("csrci mie, 128" ::: "memory");','__asm__ volatile("csrc mie, %0" :: "r"((uint64_t)128) : "memory");')
ec=ec.replace('    workload_run();','    uint64_t timer_before=timer_flags[0].value;\n    workload_run();')
ec=ec.replace('    int ok=workload_verify();','    printf("[IRQ] policy=main_timer_disabled before=%lu after=%d mie=%lu\\n",timer_before,timer_flags[0].value,(unsigned long)read_csr(mie));\n    int ok=workload_verify();')
(src/'test.c').write_text(ec)
n=(src/'native-main.c').read_text().replace('#include <stdio.h>','#include <stdio.h>\n#include "hw/interrupt.h"')
n=n.replace(' workload_prepare();',' __asm__ volatile("csrc mie, %0" :: "r"((uint64_t)128) : "memory");\n workload_prepare();')
n=n.replace(' workload_run();',' uint64_t timer_before=timer_flags[0].value;\n workload_run();')
n=n.replace(' int ok=workload_verify();',' printf("[IRQ] policy=main_timer_disabled before=%lu after=%d mie=%lu\\n",timer_before,timer_flags[0].value,(unsigned long)read_csr(mie));\n int ok=workload_verify();')
(src/'native-main.c').write_text(n)
cmds=[]
with (out/'build.log').open('wb') as log:
 for cmd in mf['commands']:
  argv=[a.replace(str(old),str(out)) for a in cmd]
  argv.insert(1,'-I'+str(src))
  subprocess.run(argv,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT);cmds.append(argv)
mf.update(profile='representative-16-trial-no-main-timer',commands=cmds,
 source_sha256={str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()},
 shared_kernel_objects={str(out/Path(p).name):sha(out/Path(p).name) for p in mf['shared_kernel_objects']},
 elf={m:{'path':str(out/(m+'.riscv')),'sha256':sha(out/(m+'.riscv'))} for m in ['native','ec']},
 interrupt_policy={'main_hart_timer':'MTIE cleared before workload_prepare in both modes','check':'[IRQ] before/after timer_flags and mie; no main timer increment inside ROI','checker_harts':'unchanged frozen firmware'},
 timeout_seconds=3600,differences='Separate startup ELF; same application objects/input; main-hart timer disabled before preparation in both modes; checker firmware unchanged')
save(out/'manifest.json',mf)
print(out/'manifest.json')
