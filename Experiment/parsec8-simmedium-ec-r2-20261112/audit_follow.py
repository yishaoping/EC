#!/usr/bin/python3
"""Read only completed EC streams; update separate, honest simmedium publication."""
from pathlib import Path
import collections,csv,datetime,gzip,hashlib,json,math,os,re,sqlite3,time,traceback
R=Path(__file__).resolve().parent
BENCH=['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def save(p,x):
 p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 t.replace(p)
def lines(p):
 with gzip.open(p,'rt') as f:
  for l in f:yield l.rstrip('\r\n')
def audit(bench):
 out=R/'runs'/bench;result=read(out/'result.json');binding=read(out/'binding.json')
 assert result['publication_candidate'] and result['binding_sha256']==sha(out/'binding.json')
 integrity=read(out/'stream-integrity.json');assert result['stream_integrity_sha256']==sha(out/'stream-integrity.json')
 for n,x in integrity.items():
  p=out/(n+'.gz');assert sha(p)==x['gzip_sha256'];h=hashlib.sha256();size=0
  with gzip.open(p,'rb') as f:
   for chunk in iter(lambda:f.read(2**20),b''):h.update(chunk);size+=len(chunk)
  assert h.hexdigest()==x['raw_sha256'] and size==x['raw_bytes'],('raw mismatch',n)
 dbpath=R/'audits'/f'{bench}-join.sqlite';dbpath.parent.mkdir(exist_ok=True)
 if dbpath.exists():dbpath.unlink() # Only our incomplete analysis work file; no producer data.
 con=sqlite3.connect(dbpath);con.execute('CREATE TABLE packages(seq INTEGER PRIMARY KEY,alloc_fast INTEGER,alloc_csr INTEGER,hart INTEGER,accepted_fast INTEGER,accepted_csr INTEGER,local_begin INTEGER,local_result INTEGER)')
 con.execute('PRAGMA synchronous=OFF');seq_record=0;nalloc=naccept=0;header=end=None
 for text in lines(out/'external-events.jsonl.gz'):
  e=json.loads(text);kind=e['kind']
  if kind=='HEADER':assert header is None;header=e;continue
  if 'record' in e:seq_record+=1;assert e['record']==seq_record
  assert kind!='SAMPLE_ERROR'
  if kind=='BOOM_ALLOC':
   con.execute('INSERT INTO packages(seq,alloc_fast,alloc_csr) VALUES(?,?,?)',(e['package_seq'],e['fastest_target_cycle'],e['boom_csr_cycle']));nalloc+=1
  elif kind=='BOOM_RESULT_ACCEPTED':
   assert e['status']==0
   row=con.execute('SELECT alloc_fast,alloc_csr,accepted_fast FROM packages WHERE seq=?',(e['package_seq'],)).fetchone();assert row and row[2] is None
   assert e['fastest_target_cycle']>=row[0] and e['boom_csr_cycle']>=row[1]
   con.execute('UPDATE packages SET hart=?,accepted_fast=?,accepted_csr=? WHERE seq=?',(e['checker'],e['fastest_target_cycle'],e['boom_csr_cycle'],e['package_seq']));naccept+=1
  elif kind=='END':assert end is None;end=e
  else:raise AssertionError(('unknown external event',kind))
 assert header and end and header['functional_baseline']==binding['functional_baseline']
 assert end['sample_errors']==0 and end['failed']==end['cancelled']==0
 assert nalloc==naccept==end['allocations']==end['accepted']==end['passed'] and nalloc>0
 assert con.execute('SELECT count(*) FROM packages WHERE accepted_fast IS NULL').fetchone()[0]==0
 begin=re.compile(r'CYCLE:\s+(\d+) EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)')
 done=re.compile(r'CYCLE:\s+(\d+) EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=\s*(\d+) cancelled=\s*(\d+)')
 countb=countr=0;live={};lastcycle=-1;previous=collections.defaultdict(int)
 for i,text in enumerate(lines(out/'rtl-events-1.gz')):
  if i==0:assert text=='# Clock Domain: tileClockGroup_tile_1, Relative Frequency: 1/2 of Base Clock';continue
  if not text.strip():continue
  a,b=begin.fullmatch(text),done.fullmatch(text);assert a or b,('unknown checker print',text[:300]);v=(a or b).groups();cycle,hart,seq=int(v[0]),int(v[1]),int(v[2],16)
  assert cycle>=lastcycle and 1<=hart<=4;lastcycle=cycle
  row=con.execute('SELECT hart,local_begin,local_result FROM packages WHERE seq=?',(seq,)).fetchone();assert row and row[0]==hart
  if a:
   assert hart not in live and seq>previous[hart] and row[1] is None and int(v[4])==0
   live[hart]=seq;previous[hart]=seq;countb+=1;con.execute('UPDATE packages SET local_begin=? WHERE seq=?',(cycle,seq))
  else:
   assert live.get(hart)==seq and row[1] is not None and row[2] is None and cycle>=row[1]
   assert tuple(map(int,v[3:]))==(0,1,0);del live[hart];countr+=1;con.execute('UPDATE packages SET local_result=? WHERE seq=?',(cycle,seq))
 assert not live and countb==countr==naccept
 assert con.execute('SELECT count(*) FROM packages WHERE local_result IS NULL').fetchone()[0]==0
 con.commit();con.close()
 uart=(out/'uart.log').read_text(errors='replace').replace('\r','')
 contexts=re.findall(r'EC_OPT4_CONTEXT .*satp=([0-9a-f]+).*hardware_initialized=1',uart)
 installed=re.findall(r'EC_OPT4_INSTALLED hart=(\d+) satp=([0-9a-f]+)',uart)
 parked=re.findall(r'EC_OPT4_CONTEXT_DRAINED ([^\n]*)',uart)
 assert len(contexts)==1 and len(installed)==4 and {int(h) for h,s in installed}=={1,2,3,4} and all(int(s,16)==int(contexts[0],16) for h,s in installed)
 assert len(parked)==1
 fields=dict(re.findall(r'(\w+)=\s*([0-9a-fA-F]+)',parked[0]));c=result['counts']
 assert int(fields['firmware'],16)==15 and int(fields['satp'],16)==int(contexts[0],16)
 assert all(int(fields[k])==c[k] for k in ['epoch','generated','completed','outstanding'])
 assert naccept==c['generated'] and result['roi_cycles']==c['end']-c['begin']
 return dict(status='PASS_FULL_SIMMEDIUM_EC_STRICT_STREAM_AUDIT',valid_ec_roi=True,benchmark=bench,input='simmedium',repetition=1,method='CPU_GOLDENGATE_FULL_EC_LINUX',roi_target_cycles=result['roi_cycles'],drain_target_cycles=result['drain_cycles'],host_wall_seconds=result['host_wall_seconds'],checker_pass=naccept,pending=0,functional_baseline=binding['functional_baseline'],cross_backend_native_ratio_admitted=False,slowdown=None,source_result=str(out/'result.json'),source_result_sha256=sha(out/'result.json'),binding_sha256=sha(out/'binding.json'),stream_integrity_sha256=sha(out/'stream-integrity.json'),auditor_sha256=sha(__file__),completed_utc=now())
def publish():
 rows=[]
 for b in BENCH:
  ct=read(R/'contracts'/f'{b}.json');out=R/'runs'/b;st=read(out/'state.json') if (out/'state.json').exists() else {};a=read(R/'audits'/f'{b}.json') if (R/'audits'/f'{b}.json').exists() else {};native=ct.get('native_archives',[])
  rows.append(dict(benchmark=b,input='simmedium',ec_repetition=1,native_archived_n=len(native),native_roi_cycles_mean=sum(n['roi_cycles'] for n in native)/len(native) if native else None,native_method='FPGA_ARCHIVE_REUSED_NO_NEW_NATIVE',ec_method='CPU_GOLDENGATE_FULL_EC_LINUX',ec_status=a.get('status',st.get('status','QUEUED')),ec_roi_target_cycles=a.get('roi_target_cycles') if a.get('valid_ec_roi') else None,ec_drain_target_cycles=a.get('drain_target_cycles'),slowdown=None,slowdown_admission='PENDING_SAME_TARGET_CONFIGURATION_RUNTIME_COUNTER_AND_CROSS_BACKEND_REVIEW',host_wall_seconds=a.get('host_wall_seconds',st.get('host_seconds')),guest_command_sent=st.get('guest_command_sent'),result=str(out/'result.json')))
 with (R/'simmedium-performance.csv').open('w') as f:w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
 save(R/'paper-state.json',dict(updated_utc=now(),valid_ec_simmedium=sum(r['ec_roi_target_cycles'] is not None for r in rows),valid_slowdowns=0,native_launch_allowed=False,rows=rows))
 # Explicit missingness: no fabricated zero/ratio bars from scoped runs.
 import matplotlib;matplotlib.use('Agg');import matplotlib.pyplot as plt
 fig,ax=plt.subplots(figsize=(10,4));ax.set_xticks(range(8),[b.capitalize() for b in BENCH],rotation=25,ha='right');ax.set_xlim(-.7,7.7);ax.set_ylim(0,1.4);ax.set_ylabel('EC / Native ROI target cycles');ax.set_title('PARSEC simmedium — one EC run each; existing Native reused')
 for i,row in enumerate(rows):ax.text(i,.65,'pending' if row['ec_roi_target_cycles'] is None else 'EC measured\nratio pending',rotation=90,ha='center',va='center',fontsize=9)
 ax.text(.5,.95,'No valid full simmedium slowdown yet; scoped/reduced runs excluded',transform=ax.transAxes,ha='center',fontsize=9);fig.tight_layout()
 for ext in ['svg','pdf','png']:fig.savefig(R/('Performance.'+ext),dpi=160)
 plt.close(fig)
def main():
 while True:
  for b in BENCH:
   p=R/'runs'/b/'result.json';q=R/'audits'/f'{b}.json'
   if p.exists() and not q.exists():
    r=read(p)
    if r.get('publication_candidate'):
     try:a=audit(b)
     except Exception as e:a=dict(status='FAILED_STRICT_AUDIT',valid_ec_roi=False,error=repr(e),traceback=traceback.format_exc(),completed_utc=now())
    else:a=dict(status=r['status'],valid_ec_roi=False,stop_cause=r.get('stop_cause'),source_result=str(p),source_result_sha256=sha(p),completed_utc=now())
    save(q,a)
  try:publish()
  except Exception as e:save(R/'paper-update-error.json',dict(error=repr(e),utc=now()))
  s=read(R/'campaign-state.json') if (R/'campaign-state.json').exists() else {}
  if s.get('status')=='FIRST_ROUND_FINISHED':break
  time.sleep(30)
if __name__=='__main__':main()
