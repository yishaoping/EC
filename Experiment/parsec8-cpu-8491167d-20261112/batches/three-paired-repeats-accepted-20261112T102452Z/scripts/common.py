from pathlib import Path
import datetime,hashlib,json,os,importlib.util
ROOT=Path(__file__).resolve().parents[1]
EC=Path('/data1/gzh/EC')
W=EC/'firesim/final-opt4-20261106'
D=EC/'Experiment/firesim-final-opt4-20261106'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
TOOLS=EC/'chipyard/.conda-env/riscv-tools/bin'
SOURCE=Path('/data1/gzh/EC-opt4-perf/slowdown/parsec_evaluation_20261103/build/streamcluster_project64')
NATIVE=D/'cycleprecise-matched-single-boom-gg-r1-20261112/host/VMatchingNative'
PROTECTED=W/'candidates/full-gg-external-observer-r2-20261111/VFrozenOpt4Observed'
MEM=['+mm_readLatency_0=30','+mm_readMaxReqs_0=4','+mm_relaxFunctionalModel_0=0','+mm_writeLatency_0=30','+mm_writeMaxReqs_0=4']
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def ident(pid):
 try:return dict(pid=pid,start_ticks=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()[19],boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def run_paths(mf,mode,repeat=1):
 """Stable attempt order, never select on measured performance."""
 base=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-{mode}-r{repeat}"
 paths=[base]+sorted(base.parent.glob(base.name+'-attempt*'),key=lambda p:int(p.name.rsplit('attempt',1)[1]))
 return paths
def selected_result(mf,mode,repeat=1):
 if not mf:return None,None
 paths=run_paths(mf,mode,repeat)
 results=[(read(p/'result.json'),p/'result.json') for p in paths if (p/'result.json').exists()]
 # Earliest completed successful attempt is predeclared. Keep failed attempts
 # in the evidence ledger; never cherry-pick a faster successful attempt.
 return next(((r,p) for r,p in results if r.get('valid') and (p.parent/'complete.json').exists()),results[-1] if results else (None,paths[0]/'result.json'))
def pair_comparable(mf,mp,n,e):
 return bool(n and e and n.get('valid') and e.get('valid') and
  n.get('roi_cycles') and e.get('roi_cycles') and n.get('output')==e.get('output') and
  n.get('roi_instructions') is not None and n['roi_instructions']==e.get('roi_instructions') and
  n.get('interrupt_policy_verified') and e.get('interrupt_policy_verified') and
  n.get('manifest_sha256')==e.get('manifest_sha256')==sha(mp))
def module(path,name):
 spec=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m
