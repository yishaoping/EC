#!/usr/bin/env python3
"""Read-only streaming EDIF instance census; no Vivado/RTL/FPGA mutation."""
from pathlib import Path
import collections
import datetime as dt
import functools
import json
import re
import time
import zipfile
from board_batch import W,D,save,sha

STATE=D/'C4-capacity-edif-state.json'
OUT=D/'build-logs/C4-capacity-20261110'
OUT.mkdir(exist_ok=True)
stamp=lambda:dt.datetime.now(dt.timezone.utc).isoformat()
s=json.loads((D/'C4-dcp-cad-state.json').read_text())
dcp=next(Path(d['stable_snapshot']) for d in s['reused_checkpoints'] if Path(d['snapshot']).stem=='design_1_firesim_wrapper_0_0')
pattern=re.compile(rb'(?m)^[ \t]*\((cell|instance) ([^\n]+)')
refs=re.compile(rb'\(cellref ([^ ]+) \(libraryref ([^)]+)\)\)')
definitions={};hier={};samples={};current=None;total=0;start=time.monotonic();last=start
st=dict(schema='ec-c4-edif-capacity/1',status='READING_IMMUTABLE_EDIF',pid=__import__('os').getpid(),
       start_ticks=Path('/proc/self/stat').read_text().split()[21],
       host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
       started_utc=stamp(),input_dcp=str(dcp),input_dcp_sha256=s['dut_dcp_sha256'],
       hardware_commit=s['hardware_commit'],source_id=s['source_id'],fpga_access=False)
save(STATE,st)
with zipfile.ZipFile(dcp) as z:
 member=next(n for n in z.namelist() if n.endswith('.edf'));st['edif_uncompressed_bytes']=z.getinfo(member).file_size
 with z.open(member) as stream:
  tail=b''
  while True:
   raw=stream.read(32*2**20)
   if not raw:break
   total+=len(raw);data=tail+raw;idx=data.rfind(b'\n');tail=data[idx+1:];data=data[:idx+1]
   for m in pattern.finditer(data):
    kind,body=m.groups()
    if kind==b'cell':
     current=body.split(None,1)[0].decode();assert current not in definitions,current
     definitions[current]=collections.Counter();hier[current]=[];continue
    ref=refs.search(body);assert ref and current,(current,body[:200])
    name,lib=[x.decode() for x in ref.groups()];definitions[current][(lib,name)]+=1
    ident=body[:body.index(b' (viewref')].decode()
    if ident.startswith('(rename '):ident=ident.split('"',2)[1]
    if lib!='hdi_primitives':hier[current].append((ident,name))
    elif name in ['LUT6','CARRY8','DSP48E2']:
     key=current+'|'+name;bucket=samples.setdefault(key,[])
     if len(bucket)<6:bucket.append(ident)
   if time.monotonic()-last>=30:
    st.update(updated_utc=stamp(),bytes_read=total,cell_definitions=len(definitions),wall_seconds=time.monotonic()-start)
    save(STATE,st);last=time.monotonic()
 assert not tail.strip(),tail[:100]

@functools.lru_cache(None)
def expanded(name):
 c=collections.Counter()
 for (lib,ref),n in definitions[name].items():
  if lib=='hdi_primitives':c[ref]+=n
  else:
   assert ref in definitions,ref
   for p,v in expanded(ref).items():c[p]+=n*v
 return c

top='design_1_firesim_wrapper_0_0';counts=expanded(top)
def metrics(c):
 return dict(lut_primitives=sum(v for k,v in c.items() if re.fullmatch('LUT[1-6](_2)?',k)),
             lut6=c['LUT6'],carry8=c['CARRY8'],dsp48e2=c['DSP48E2'],registers=sum(v for k,v in c.items() if k.startswith('FD')))
occurrences=collections.Counter({top:1});order=[];seen=set()
def visit(name):
 if name in seen:return
 seen.add(name)
 for (_,ref),n in definitions[name].items():
  if ref in definitions:visit(ref)
 order.append(name)
visit(top)
for name in reversed(order):
 for (lib,ref),n in definitions[name].items():
  if lib!='hdi_primitives':occurrences[ref]+=occurrences[name]*n
rows=[]
for name in definitions:
 if not occurrences[name]:continue
 direct=collections.Counter({ref:n for (lib,ref),n in definitions[name].items() if lib=='hdi_primitives'})
 row=dict(module=name,instances=occurrences[name],direct=metrics(direct),inclusive=metrics(expanded(name)),children=hier[name])
 row['total_direct_lut_primitives']=row['direct']['lut_primitives']*row['instances'];rows.append(row)
rows.sort(key=lambda r:r['total_direct_lut_primitives'],reverse=True)
receipt=dict(st,status='COMPLETE_READ_ONLY_CENSUS',ended_utc=stamp(),wall_seconds=time.monotonic()-start,
             bytes_read=total,primitive_instances=dict(counts),metrics=metrics(counts),
             hierarchy=rows,primitive_samples=samples,duplicate_definition_check='PASSED',
             physical_utilization_caveat='Raw LUT primitives can pack together; use Vivado utilization for physical LUT count. No ancestor/descendant totals are summed together.',
             post_opt_status='NOT_COLLECTED_BY_EDIF_CENSUS')
save(OUT/'edif-capacity-census.json',receipt);save(STATE,receipt)
print(json.dumps(dict(status=receipt['status'],metrics=receipt['metrics'],top_direct_modules=[{k:r[k] for k in ['module','instances','direct','total_direct_lut_primitives']} for r in rows[:15]])),flush=True)
