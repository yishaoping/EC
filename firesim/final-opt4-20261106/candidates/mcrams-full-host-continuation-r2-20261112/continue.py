#!/usr/bin/python3
"""Persistent consumer for existing owner MCRams capacity/parity producers.
Never restarts them. Reuses reports/checkpoints; submits unique successors.
"""
import argparse,datetime,fcntl,hashlib,json,os,pathlib,re,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
AREA=D/'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112';MC=D/'cycleprecise-owner-mc-runtime-r2-20261112'
O=D/'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112';S=D/'Opt4-mcrams-full-host-continuation-r2-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8';HW='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ST={}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):
 try:return json.loads(P(p).read_text())
 except FileNotFoundError:return {}
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid=None):
 pid=pid or os.getpid()
 try:a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=a[0])
 except FileNotFoundError:return {}
def live(x):
 if not x.get('pid'):return False
 a=ident(x['pid']);return bool(a and a['process_state'] not in ['Z','X'] and all(str(a[k])==str(x.get(k)) for k in ['pid','start_ticks','host_boot_id']))
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def submit(name,script,outputs,inputs,kind='analysis'):
 q=U/'requests'/(name+'.json');req=dict(action='cpu_job',spec=dict(name=name,kind=kind,cwd=str(C),argv=['/usr/bin/python3',str(script)],inputs={str(p):sha(p) for p in inputs},outputs=list(map(str,outputs)),checkpoints=[str(S)]))
 if q.exists():assert read(q)==req,'immutable successor name changed'
 else:save(q,req)
 return str(q)
def rank_report():
 p=AREA/'postopt-hierarchical.rpt';rows=[]
 if not p.exists():return rows
 header=None
 for l in p.read_text().splitlines():
  if not l.startswith('|'):continue
  a=[x.strip() for x in l.split('|')[1:-1]]
  if 'Instance' in a and 'Total LUTs' in a:header=a;continue
  if header and len(a)==len(header):
   r=dict(zip(header,a))
   if re.fullmatch(r'[0-9,]+',r.get('Total LUTs','')) and r.get('Module')!='(top)':
    r['LUT']=int(r['Total LUTs'].replace(',',''));rows.append(r)
 # Hierarchy includes parent and child, so this is an inclusive ranking, not
 # an area sum. Exact report rows remain in each entry.
 return sorted(rows,key=lambda r:r['LUT'],reverse=True)[:50]
def stable_snapshot(name,j):
 p=O/name
 if p.exists():assert read(p)==j
 else:save(p,j)
def main():
 argparse.ArgumentParser().parse_args();O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 ST.update(schema='ec-owner-mcrams-persistent-continuation/1',**ident(),started_utc=now(),functional_baseline=BASE,derived_target_commit=HW,fpga_access=False,no_target_resynthesis=True,whole_physical_fit=False)
 while True:
  a=read(AREA/'result.json') or read(O/'recovered-capacity.json');as_=read(D/'Opt4-mcrams-full-host-capacity-r1-state.json');ms=read(D/'Opt4-mcrams-owner-mc-runtime-r2-state.json');m=read(MC/'result.json')
  # Process identity, not stale status or service survival, controls adoption.
  al=live(as_) or live(as_.get('child',{}));ml=live(ms) or live(ms.get('child',{}))
  update(status='ADOPTING_EXISTING_CAPACITY_AND_PARITY_NO_DUPLICATES',area_status=as_.get('status'),area_live=al,MC_status=ms.get('status'),MC_live=ml,area_result=str(AREA/'result.json'),MC_result=str(MC/'result.json'))
  if a:
   assert a.get('derived_hardware')==HW and a.get('functional_baseline')==BASE
   assert a.get('host_rtl_sha256')=='9d5380252ec779da8844b1ff632af84330fd2d0dff63912dd4c08180ae2ff3e1'
   resources=a['reports']['postopt']['resources'];caps=a['reports']['postopt']['capacities']
   ranking=dict(schema='ec-owner-full-host-inclusive-resource-ranking/1',capacity_result_sha256=sha(AREA/'result.json') if (AREA/'result.json').exists() else sha(O/'recovered-capacity.json'),resources=resources,capacities=caps,resource_excess={k:max(0,v-caps[k]) for k,v in resources.items()},ranked_inclusive_instances=rank_report(),not_additive=True,full_host_OOC_only=True,full_physical_system_FIT=False)
   stable_snapshot('actual-capacity-ranking.json',ranking)
   if not a.get('full_host_fit'):
    # This persistent monitor still follows the independent address RAM
    # prototype. The regular autonomous worker consumes the ranked evidence
    # to select a *proved* next target; no blind re-synthesis or P&R.
    b=read(D/'Opt4-mcrams-address-bucket-r5-state.json')
    update(status='NOT_FIT_NO_PHYSICAL_IMPLEMENTATION_ADDRESS_PROTOTYPE_CONTINUES',actual_resources=resources,resource_excess=ranking['resource_excess'],ranking=str(O/'actual-capacity-ranking.json'),address_prototype_status=b.get('status'),next='Use actual hierarchy plus passed address prototype; no speculative full-system saving claim')
   elif m and m.get('captured_finite_parity_passed'):
    assert m['derived_hardware']==HW and m['functional_baseline']==BASE
    stable_snapshot('capacity-parity-admission.json',dict(functional_baseline=BASE,derived_hardware=HW,host_rtl_sha256=a['host_rtl_sha256'],capacity_result=str(AREA/'result.json') if (AREA/'result.json').exists() else str(O/'recovered-capacity.json'),capacity_result_sha256=sha(AREA/'result.json') if (AREA/'result.json').exists() else sha(O/'recovered-capacity.json'),target_parity_result=str(MC/'result.json'),target_parity_result_sha256=sha(MC/'result.json'),no_full_state_equivalence_claim=True,fpga_access=False,whole_physical_fit=False))
    req=submit('mcrams-shell-physical-r2-3656aec4',C/'physical.py',[D/'build-logs/Opt4-mcrams-shell-physical-r2-20261112/result.json'],[C/'physical.py',C/'physical-plan.json'],kind='module')
    update(status='SUBMITTED_CHECKPOINT_REUSE_SHELL_TOP_OPT_PHYSICAL_SUCCESSOR',request=req,admission=str(O/'capacity-parity-admission.json'))
   else:update(status='HOST_OOC_FIT_REQUIRES_ACTUAL_TARGET_PARITY_BEFORE_SHELL',actual_resources=resources)
  if not al and not a:
   # Parser-only failures or interrupted opt can be recovered from the exact
   # synth/postopt DCP, by a separate unique analysis/recovery request.
   req=submit('mcrams-host-report-recovery-r2-3656aec4',C/'recover.py',[O/'recovered-capacity.json'],[C/'recover.py',C/'physical-plan.json'],kind='module')
   update(status='CAPACITY_PRODUCER_EXITED_SUBMITTED_VERSIONED_REPORT_CHECKPOINT_RECOVERY',request=req,producer_error=as_.get('error'))
  b=read(D/'build-logs/Opt4-mcrams-address-bucket-r5-20261112/result.json')
  if b.get('status')=='PASS_WORD_TRANSITION_LEMMA_AND_FINITE_FULL_WIDTH_ALL_WORD_TARGET_PARITY_AREA_PENDING':
   req=submit('address-bucket-mcrams-area-r1-8491167d',C/'bucket_area.py',[D/'build-logs/Opt4-mcrams-address-bucket-area-r1-20261112/result.json'],[C/'bucket_area.py'],kind='module')
   update(address_area_request=req)
  if not ml and not m:
   update(status='MC_PRODUCER_EXITED_PRESERVE_RECEIPTS_REQUIRE_REPARSE_OR_REVIEW',MC_error=ms.get('error'),MC_receipt=str(MC/'receipts/run-MCRams.json'))
  time.sleep(300)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if ST:update(status='CONTINUATION_FAILED_WITH_EVIDENCE',error=repr(e));save(O/'failure.json',ST)
  raise
