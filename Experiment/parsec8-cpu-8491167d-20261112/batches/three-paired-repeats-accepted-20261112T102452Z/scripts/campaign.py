"""Sequential CPU-only queue. Failing workloads never block other ready work."""
from common import *
import sys,time,subprocess,fcntl

def main():
 lock=(ROOT/'campaign.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
 while True:
  plan=read(ROOT/'queue.json');pending=False
  for item in plan['items']:
   mfpath=ROOT/item['manifest']
   if not mfpath.exists():continue
   mf=read(mfpath)
   for mode in ['native','ec']:
    out=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-{mode}-r1"
    if (out/'result.json').exists():continue
    if mode=='ec':
     nr=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-native-r1/result.json"
     if not nr.exists() or not read(nr)['valid']:continue
    # Do not adopt or overwrite an unfinished attempt.
    if (out/'binding.json').exists():continue
    save(ROOT/'campaign-state.json',dict(status='RUNNING',controller=ident(os.getpid()),benchmark=mf['benchmark'],mode=mode,manifest=str(mfpath),updated_utc=now()))
    with (ROOT/'campaign.log').open('ab') as log:
     subprocess.run([sys.executable,str(ROOT/'scripts/run_one.py'),str(mfpath),mode],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
    subprocess.run([sys.executable,str(ROOT/'scripts/summarize.py')],cwd=ROOT,stdout=subprocess.DEVNULL)
  save(ROOT/'campaign-state.json',dict(status='WAITING_FOR_READY_MANIFESTS',controller=ident(os.getpid()),updated_utc=now()))
  time.sleep(20)

if __name__=='__main__':main()
