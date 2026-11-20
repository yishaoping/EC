"""CPU-only two-slot scheduler; first pass across all ready profiles before repeats."""
from common import *
import sys,subprocess,time,fcntl
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
lock=(ROOT/'campaign.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
children={};last_export=0

def path(mf,mode,r):return ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-{mode}-r{r}"
def available(mode):
 f=(ROOT/(mode+'-simulator.lock')).open('a')
 try:fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
 except BlockingIOError:f.close();return False
 f.close();return True

def load_items():
 items=[]
 for item in read(ROOT/'queue.json')['items']:
  p=ROOT/item['manifest']
  if p.exists():items.append((read(p),p))
 return items

def candidate(items,mode,r):
 choices=[]
 for order,(mf,p) in enumerate(items):
  out=path(mf,mode,r)
  if (out/'binding.json').exists() or (out/'result.json').exists():continue
  if mode=='ec':
   nr=path(mf,'native',r)/'result.json'
   if not nr.exists() or not read(nr)['valid']:continue
   cost=read(nr).get('total_fastest_target_cycles',1e12)
  else:cost=order
  choices.append((cost,order,mf,p))
 return min(choices,key=lambda x:x[:2]) if choices else None

def first_pass_done(items):
 if len(items)!=8:return False
 for mf,_ in items:
  nr=path(mf,'native',1)/'result.json';er=path(mf,'ec',1)/'result.json'
  if not nr.exists():return False
  if read(nr)['valid'] and not er.exists():return False
 return True

while True:
 items=load_items()
 for mode in list(children):
  p,log=children[mode]
  if p.poll() is not None:log.close();del children[mode];last_export=0
 done=first_pass_done(items)
 for mode in ['native','ec']:
  if mode in children or not available(mode):continue
  picked=None;repeat=1
  for r in ([1,2,3] if done else [1]):
   picked=candidate(items,mode,r)
   if picked:repeat=r;break
  if picked:
   _,_,mf,mp=picked
   log=(ROOT/'campaign-v2.log').open('ab')
   proc=subprocess.Popen([sys.executable,str(ROOT/'scripts/run_one.py'),str(mp),mode,'--repeat',str(repeat)],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
   children[mode]=(proc,log)
   save(ROOT/f'queue-{mode}-state.json',dict(controller=ident(os.getpid()),runner=ident(proc.pid),benchmark=mf['benchmark'],mode=mode,repeat=repeat,manifest=str(mp),updated_utc=now()))
 if time.monotonic()-last_export>60:
  subprocess.run([sys.executable,str(ROOT/'scripts/summarize.py')],cwd=ROOT,stdout=subprocess.DEVNULL)
  last_export=time.monotonic()
 save(ROOT/'campaign-v2-state.json',dict(status='RUNNING' if children else 'WAITING_FOR_RESULTS_OR_READY_MANIFESTS',controller=ident(os.getpid()),first_pass_done=done,ready_profiles=len(items),active={m:ident(p.pid) for m,(p,_) in children.items()},updated_utc=now()))
 time.sleep(5)
