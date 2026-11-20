#!/usr/bin/env python3
"""Primitive-name attribution, separate from inclusive hierarchy totals."""
from pathlib import Path
import collections,datetime,json,re,zipfile,os,time
from board_batch import D,save
O=D/'build-logs/C4-capacity-20261110';base=json.loads((O/'edif-capacity-census.json').read_text());occ={r['module']:r['instances'] for r in base['hierarchy']}
s=json.loads((D/'C4-dcp-cad-state.json').read_text());dcp=next(d['stable_snapshot'] for d in s['reused_checkpoints'] if Path(d['snapshot']).stem=='design_1_firesim_wrapper_0_0')
pattern=re.compile(rb'(?m)^[ \t]*\((cell|instance) ([^\n]+)');refs=re.compile(rb'\(cellref ([^ ]+) \(libraryref ([^)]+)\)\)')
counters=collections.defaultdict(collections.Counter);examples={};current=None;tail=b'';start=time.monotonic();total=0
state=D/'C4-capacity-attribution-state.json';st=dict(status='RUNNING_READONLY_EDIF',pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),fpga_access=False);save(state,st)
with zipfile.ZipFile(dcp) as z:
 with z.open(next(n for n in z.namelist() if n.endswith('.edf'))) as f:
  while True:
   raw=f.read(32*2**20)
   if not raw:break
   total+=len(raw);data=tail+raw;i=data.rfind(b'\n');tail=data[i+1:];data=data[:i+1]
   for m in pattern.finditer(data):
    kind,body=m.groups()
    if kind==b'cell':current=body.split(None,1)[0].decode();continue
    ref=refs.search(body)
    if not ref or ref[2]!=b'hdi_primitives' or not occ.get(current):continue
    prim=ref[1].decode();ident=body[:body.index(b' (viewref')].decode()
    if ident.startswith('(rename '):ident=ident.split('"',2)[1]
    if '_safeBucketsWide' in ident:category='barrier-latency-multiply-reduction-names'
    elif '_l2VerifyCycleThisCycleWide' in ident:category='L2-writeback-multiply-reduction-names'
    elif current=='PackageAddressStats':category='PackageAddressStats-direct'
    elif current.startswith('GHBarrierLatencyStats'):category='barrier-latency-other-direct'
    elif 'safeCycle' in ident or 'safeCyclesResolved' in ident:category='other-safe-cycle-stat-names'
    else:category='remaining'
    counters[category][prim]+=occ[current]
    if len(examples.setdefault(category,[]))<6:examples[category].append(dict(module=current,primitive=prim,instance=ident))
   if int(time.monotonic()-start)%30==0:
    st.update(bytes_read=total,elapsed_seconds=time.monotonic()-start);save(state,st)
rows=[]
for category,c in counters.items():rows.append(dict(category=category,lut_primitives=sum(v for k,v in c.items() if re.fullmatch('LUT[1-6](_2)?',k)),lut6=c['LUT6'],carry8=c['CARRY8'],dsp48e2=c['DSP48E2'],registers=sum(v for k,v in c.items() if k.startswith('FD')),counts=dict(c),examples=examples[category]))
rows.sort(key=lambda r:r['lut_primitives'],reverse=True)
assert sum(r['lut_primitives'] for r in rows)==base['metrics']['lut_primitives']
r=dict(status='COMPLETE_READ_ONLY_NAME_ATTRIBUTION',utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),elapsed_seconds=time.monotonic()-start,input_dcp_sha256=base['input_dcp_sha256'],rows=rows,caveat='Name attribution is evidence of origin, not complete cone analysis. Physically moved logic retains generated names. Categories partition primitive instances and do not double count ancestors.')
save(O/'edif-name-attribution.json',r);save(state,dict(st,status=r['status'],elapsed_seconds=r['elapsed_seconds']));print(json.dumps(rows),flush=True)
