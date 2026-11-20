"""Fast CPU functional checks only. Spike cycles are never performance samples."""
from common import *
import subprocess,sys
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
rows=[]
for item in read(ROOT/'queue.json')['items']:
 if sys.argv[1:] and item['benchmark'] not in sys.argv[1:]:continue
 p=ROOT/item['manifest']
 if not p.exists():continue
 mf=read(p);cmd=['/usr/bin/spike','-p1','-m1024','--isa=rv64gc_zicntr_zihpm',mf['elf']['native']['path']]
 try:
  r=subprocess.run(cmd,cwd=ROOT,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,timeout=15)
  text=r.stdout;rc=r.returncode;timeout=False
 except subprocess.TimeoutExpired as e:
  text=(e.stdout or b'').decode(errors='replace') if isinstance(e.stdout,bytes) else e.stdout or '';rc=None;timeout=True
 log=ROOT/'audit'/f"{item['benchmark']}-{mf['profile']}-spike-native-zicntr.log";log.write_text(text)
 actual=[s.split('[OUTPUT] ',1)[1] for s in text.splitlines() if s.startswith('[OUTPUT] ')]
 expected=mf['expected_output']
 if mf.get('output_acceptance')=='verified_fields_checksum_may_differ_from_host':
  import re
  norm=lambda rows:[re.sub(r'checksum=[0-9a-f]+','checksum=ARCH_FLOAT',s) for s in rows]
  actual=norm(actual);expected=norm(expected)
 passed=not timeout and rc==0 and actual==expected
 rows.append(dict(benchmark=item['benchmark'],profile=mf['profile'],command=cmd,returncode=rc,timeout=timeout,functional_only=True,performance_sample=False,output_pass=passed,log=str(log),log_sha256=sha(log),elf_sha256=sha(mf['elf']['native']['path'])))
 save(ROOT/'audit/isa-functional-preflight-zicntr.json',dict(created_utc=now(),method='Spike ISA functional smoke only, never a timing model',rows=rows))
 print(item['benchmark'],passed,'timeout',timeout,flush=True)
