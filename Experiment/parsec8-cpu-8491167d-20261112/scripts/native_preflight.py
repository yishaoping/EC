from common import *
import sys,subprocess
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
for item in read(ROOT/'queue.json')['items']:
 p=ROOT/item['manifest']
 if not p.exists():continue
 mf=read(p);out=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-native-r1"
 if (out/'binding.json').exists() or (out/'result.json').exists():continue
 with (ROOT/'native-preflight.log').open('ab') as log:
  subprocess.run([sys.executable,str(ROOT/'scripts/run_one.py'),str(p),'native'],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
 subprocess.run([sys.executable,str(ROOT/'scripts/summarize.py')],cwd=ROOT,stdout=subprocess.DEVNULL)
