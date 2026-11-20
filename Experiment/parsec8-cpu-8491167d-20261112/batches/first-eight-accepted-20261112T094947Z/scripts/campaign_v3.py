"""Independent CPU simulation slots, complete pass before bounded retries/repeats."""
from common import *
import sys,subprocess,time,fcntl
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
lock=(ROOT/'campaign.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
children={};reservations={};last_export=0

def path(mf,mode,r,attempt=1):
 base=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-{mode}-r{r}"
 return base if attempt==1 else base.with_name(base.name+f'-attempt{attempt}')
def completed(mf,mode,r):
 out=[p/'result.json' for p in [path(mf,mode,r,a) for a in [1,2]] if (p/'result.json').exists()]
 return [read(p) for p in out]
def passed(mf,mode,r):return next((r for r in completed(mf,mode,r) if r['valid']),None)
def available(mode):
 f=(ROOT/(mode+'-simulator.lock')).open('a')
 try:fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
 except BlockingIOError:f.close();return False
 f.close();return True
def cpu_available(slot):
 cpu={'native':200,'native-aux':201,'native-extra1':202,'native-extra2':204,'ec':201,'ec-aux':200,'ec-extra1':202,'ec-extra2':204}[slot]
 f=(ROOT/f'cpu{cpu}-simulator.lock').open('a')
 try:fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
 except BlockingIOError:f.close();return False
 f.close();return True

def items():return [(read(p),p) for x in read(ROOT/'queue.json')['items'] if (p:=ROOT/x['manifest']).exists()]
def pass_finished(ms):
 return len(ms)==8 and all(completed(m,'native',1) and (not passed(m,'native',1) or completed(m,'ec',1)) for m,_ in ms)
def choose(ms,mode):
 done=pass_finished(ms)
 # Prefetch already-comparable repeats only after every selected first EC run
 # has been dispatched. Every first-round EC task keeps its slot/priority.
 prefetch=len(ms)==8 and all(any((p/'binding.json').exists() for p in run_paths(m,'ec')) for m,_ in ms)
 stages=[(1,[1,2])]+([(2,[1,2]),(3,[1,2])] if done or prefetch else [])
 for repeat,attempts in stages:
  candidates=[]
  for attempt in attempts:
   for order,(m,mp) in enumerate(ms):
    p=path(m,mode,repeat,attempt)
    if (p/'binding.json').exists() or p in reservations.values():continue
    if passed(m,mode,repeat):continue
    if attempt==2:
     old=path(m,mode,repeat)
    # Retry interrupted runs with retained identity/reason. Algorithm failures
    # require an explicitly repaired manifest instead.
     if not (old/'external-stop-reason.json').exists():continue
    first_pair_ready=pair_comparable(m,mp,passed(m,'native',1),passed(m,'ec',1))
    pending_native_prefetch=mode=='native' and prefetch and passed(m,'native',1) and not completed(m,'ec',1)
    if repeat>1 and not (first_pair_ready or pending_native_prefetch):continue
    if mode=='ec':
     nr=passed(m,'native',repeat)
     if not nr:continue
     cost=nr.get('total_fastest_target_cycles',1e12)
    else:cost=order
    candidates.append((cost,order,m,mp,repeat,attempt))
  if candidates:return min(candidates,key=lambda x:x[:2])
 return None
while True:
 ms=items()
 for mode in list(children):
  p,log=children[mode]
  if p.poll() is not None:log.close();del children[mode];reservations.pop(mode,None);last_export=0
 # Physical CPU 201 always serves EC. CPU 200 serves Native until all
 # selected first Native runs pass, then serves pending first-round EC before
 # Native repeats. Two additional pressure-controlled EC slots use otherwise
 # idle cores 202/204. CPU and per-instance locks enforce the four-model cap.
 ec_work=choose(ms,'ec')
 native_work=choose(ms,'native')
 lanes=[('native-aux','native')] if native_work and native_work[4]==1 else ([('ec','ec')] if ec_work else [('native-aux','native')])
 if len(ms)==8:
  native_first_done=all(passed(m,'native',1) for m,_ in ms)
  for suffix in ['extra1','extra2']:
   # Prefetch a missing earlier Native repeat before a later EC repeat on
   # an idle extra CPU; preserve every already-running model and CPU lock.
   ec_choice=choose(ms,'ec');native_choice=choose(ms,'native')
   use_native=native_choice is not None and (native_choice[4]==1 or native_first_done and (ec_choice is None or native_choice[4]<ec_choice[4]))
   if use_native or native_first_done:
    mode='native' if use_native else 'ec';lanes.append((mode+'-'+suffix,mode))
 if not any(k in children for k in ['native','ec-aux']) and available('native') and available('ec-aux'):
  native_first_done=len(ms)==8 and all(passed(m,'native',1) for m,_ in ms)
  aux=choose(ms,'ec') if native_first_done else None
  native_work=choose(ms,'native')
  lanes.append(('ec-aux','ec') if aux and (aux[4]==1 or native_work is None) else ('native','native'))
 for slot_name,mode in lanes:
  if slot_name in children or not available(slot_name) or not cpu_available(slot_name):continue
  c=choose(ms,mode)
  if not c:continue
  _,_,mf,mp,r,a=c;log=(ROOT/'campaign-v3.log').open('ab')
  reservations[slot_name]=path(mf,mode,r,a)
  proc=subprocess.Popen([sys.executable,str(ROOT/'scripts/run_one.py'),str(mp),mode,'--repeat',str(r),'--attempt',str(a),'--slot',slot_name],cwd=ROOT,stdout=log,stderr=subprocess.STDOUT)
  children[slot_name]=(proc,log)
  save(ROOT/f'queue-{slot_name}-state.json',dict(controller=ident(os.getpid()),runner=ident(proc.pid),benchmark=mf['benchmark'],mode=mode,slot=slot_name,repeat=r,attempt=a,manifest=str(mp),updated_utc=now()))
 if time.monotonic()-last_export>60:
  subprocess.run([sys.executable,str(ROOT/'scripts/export.py')],cwd=ROOT,stdout=subprocess.DEVNULL);last_export=time.monotonic()
 busy_slots=[s for s in ['native','native-aux','native-extra1','native-extra2','ec','ec-aux','ec-extra1','ec-extra2'] if not available(s)]
 summary=read(ROOT/'paper/summary.json') if (ROOT/'paper/summary.json').exists() else {}
 if not children and not busy_slots and summary.get('valid_pair_count')==8 and len(summary.get('repeatability',[]))==8 and all(x['paired_n']==3 for x in summary['repeatability']):
  save(ROOT/'campaign-v3-state.json',dict(status='COMPLETE_THREE_ACCEPTED_PAIRED_REPEATS',controller=ident(os.getpid()),updated_utc=now(),summary_sha256=sha(ROOT/'paper/summary.json')))
  break
 save(ROOT/'campaign-v3-state.json',dict(status='RUNNING' if children or busy_slots else 'WAITING_FOR_SLOT_OR_MANIFEST',controller=ident(os.getpid()),first_pass_done=pass_finished(ms),ready_profiles=len(ms),active={m:ident(p.pid) for m,(p,_) in children.items()},busy_slots_including_inherited=busy_slots,updated_utc=now()))
 time.sleep(5)
