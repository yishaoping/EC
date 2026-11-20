#!/usr/bin/python3
"""Short independent scalar/source review; not RTL formal or an FPGA sample."""
from pathlib import Path
import hashlib,itertools,json,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');F=W/'Opt4-fit-address-update-share-r2-20261111';R='chipyard/generators/boom/src/main/scala/lsu/';COMMIT='00847dc2b8f6be3f1e1ff0639c1104d33334ddc9';BASE='9ae9a7fcf231a75259e23973b12a93896a443cbb'
mask=(1<<64)-1;values=[0,1,2,7,8,639,640,(1<<63)-1,1<<63,mask-640,mask-1,mask];cases=0
for value,delta,valid,current,event,retire,reset in itertools.product(values,values,[False,True],[False,True],[False,True],[False,True],[False,True]):
 oldsum=value+delta;oldcurrent=((value if valid else 0)+delta)&mask
 oldupdated=oldcurrent if current else ((oldsum&mask) if delta else value)
 newdata=delta if current and not valid else oldsum&mask
 newupdated=newdata if current or delta else value
 oldnext=0 if reset or not event and retire else (oldupdated if event else value)
 newnext=0 if reset or not event and retire else (newupdated if event else value)
 assert oldnext==newnext
 cases+=1
source=(F/R/'PackageAddressStats.scala').read_text();base=subprocess.check_output(['git','show',BASE+':'+R+'PackageAddressStats.scala'],cwd=F,text=True)
start='    for (i <- 0 until packetWindow) {\n      val isCurrent = currentBucketIdx === i.U'
end='\n    for (g <- 0 until 4) {\n      val storeDelta = newStoreCounts(g).pad(64)'
a=base.index(start);b=base.index(end,a);c=source.index(start);d=source.index(end,c)
assert base[:a]==source[:c] and base[b:]==source[d:],'source change escaped exact bucket write block'
for name in ['bucketStore','bucketFirstStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']:
 assert f'val {name} = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))' in source
changed=subprocess.check_output(['git','diff','--name-only',BASE,COMMIT],cwd=F,text=True).splitlines()
assert changed==[R+'AddressBucketUpdate.scala',R+'PackageAddressStats.scala','lineage.json']
report=dict(schema='ec-opt4-update-share-unconditional-review/1',hardware_commit=COMMIT,reference_commit=BASE,status='PASS_STATIC_WRITE_BLOCK_CONFINEMENT_AND_SCALAR_BOUNDARIES',source_id=json.loads((F/'candidate-binding.json').read_text())['source_id'],scalar_cases=cases,scalar_domain='12 full-width values/deltas including 2^64-1 and overflow x all valid/current/event/retire/reset boolean combinations; stale invalid payloads included',source_scope='All PackageAddressStats text outside the counter-write block is exactly equal to verified 9ae9a7fc; all five banks remain 256x4x64. Current addend selection, all overflow flags, reset, retirement, error handling, and instrumentation are unchanged.',changed_files=changed,controller=str(W/'candidates/address-update-share-r2-20261111/controller.py'),full_dut_formal=False,fpga_access=False,limits='Scalar arithmetic review supplements the detached generated-RTL SAT, 8192 actual-size vectors, and global-reset complete-module comparison. Their receipts must be collected before admission.')
p=D/'build-logs/Opt4-fit-address-update-share-r2-20261111/unconditional-source-review.json';p.parent.mkdir(exist_ok=True);p.write_text(json.dumps(report,indent=2,sort_keys=True)+'\n');print(json.dumps(report))
