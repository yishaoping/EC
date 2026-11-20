#!/usr/bin/python3
"""Prepare an independent, immutable asynchronous single-writer candidate."""
from pathlib import Path
import hashlib, importlib.util, json, os, shutil, subprocess

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
F=W/'Opt4-fit-address-async-current-r1-20261111'
P=W/'Opt4-fit-address-bucket-tag-r3-20261111'
O=D/'build-logs/Opt4-fit-address-async-current-r1-20261111'
BASE='9ae9a7fcf231a75259e23973b12a93896a443cbb'
REL='chipyard/generators/boom/src/main/scala/lsu/'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True)
 p.write_text(json.dumps(x,indent=2,sort_keys=True)+'\n')

assert not F.exists(), 'use a new candidate; never edit live inputs'
subprocess.run(['git','worktree','add','-b','opt4/address-async-current-r1-20261111',str(F),BASE],cwd=P,check=True)
p=F/REL/'PackageAddressStats.scala';s=p.read_text()
for name in ['bucketStore','bucketFirstStore']:
 s=s.replace(f'  val {name} = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))\n','')
s=s.replace('  val bucketValid = RegInit',
 '''  // These two categories have exactly one writer per cycle. Async reads
  // preserve current/retiring combinational timing. Invalid payload is hidden
  // by the original validity guards; allocation always starts from zero.
  val currentBucketMemory = Module(new AddressCurrentBucketMemory(packetWindow))
  val bucketValid = RegInit''',1)
s=s.replace('  val currentBucketCollision =',
 '  currentBucketMemory.io.currentIndex := currentBucketIdx\n  val currentBucketCollision =',1)
for name,category,delta in [('bucketStore',0,'newStoreCounts'),('bucketFirstStore',1,'newFirstStoreCounts')]:
 prefix='currentStoreNextWide' if category==0 else 'currentFirstStoreNextWide'
 old=f'''    {prefix}(g) := Mux(bucketValid(currentBucketIdx),
      {name}(currentBucketIdx)(g), 0.U(64.W)) +& {delta}(g).pad(64)'''
 new=f'''    {prefix}(g) := AddressCurrentBucketMemory.sum(
      bucketValid(currentBucketIdx), currentBucketMemory.io.current({category})(g), {delta}(g))'''
 assert old in s;s=s.replace(old,new,1)
 old=f'          {name}(i)(g) := {prefix}(g)(63, 0)\n'
 assert old in s;s=s.replace(old,'',1)
 for index in ['retiringIdx','i']:
  import re
  pattern=rf'^\s*{name}\({index}\)\(g\) := 0\.U\n'
  s,n=re.subn(pattern,'',s,flags=re.M);assert n==1,(name,index,n)
 s=s.replace(f'{name}(retiringIdx)(g)',f'currentBucketMemory.io.retiring({category})(g)')
 assert name+'(' not in s
s=s.replace('''        when (isCurrent) {
        }
''','')
needle='''  // Safe-watermark retirement is serialized before the next event whose'''
insert='''  // ResetStats used to clear payload with final assignment priority. Only
  // validity needs clearing now; suppress that edge's memory write as well.
  currentBucketMemory.io.writeEnable := processCommit && !io.resetStats
  for (g <- 0 until 4) {
    currentBucketMemory.io.writeData(0)(g) := currentStoreNextWide(g)(63, 0)
    currentBucketMemory.io.writeData(1)(g) := currentFirstStoreNextWide(g)(63, 0)
  }

'''
assert needle in s;s=s.replace(needle,insert+needle,1)
s=s.replace('  val retiringSlotCollision =',
 '  currentBucketMemory.io.retiringIndex := retiringIdx\n  val retiringSlotCollision =',1)
p.write_text(s)
shutil.copyfile(C/'AddressCurrentBucketMemory.scala',F/REL/'AddressCurrentBucketMemory.scala')
line=json.loads((F/'lineage.json').read_text());line.update(
 purpose='Async single-writer storage for current-only store/first-store counters; exact zero-based allocation and unchanged cycle semantics.',
 branch='opt4/address-async-current-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL+'PackageAddressStats.scala',REL+'AddressCurrentBucketMemory.scala','lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Use async single-writer storage for current-only bucket counters'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('async_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inventory=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=True);save(O/'source-inventory.json',inventory)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F);(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-async-current-binding/1',hardware_commit=commit,parent_commit=BASE,
 frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,
 profile='Opt4-fit-address-async-current-r1-candidate',production_selected=False,full_dut_formal=False,
 candidate_change='Only two single-writer 256x4x64 banks become a 256x512 asynchronous 2R1W memory. Validity, full count widths, zero-based allocation, overflow, reset, retirement and all other state/cycles remain architecturally equivalent.',patch_sha256=hashlib.sha256(patch).hexdigest())
save(C/'binding.json',b);save(O/'candidate-binding.json',b)
cfg=json.loads((W/'candidates/address-update-share-r2-20261111/config.json').read_text())
cfg.update(worktree=str(F),binding=b,parent_local_receipt=str(D/'build-logs/Opt4-fit-address-bucket-tag-r3-20261111/verified-local.json'))
save(C/'config.json',cfg)
for n in ['frozen-original.v','frozen-tb.v']:
 shutil.copyfile(W/'candidates/address-update-share-r2-20261111'/n,C/n)
inputs=json.loads((W/'candidates/address-update-share-r2-20261111/input-hashes.json').read_text())
inputs={p:h for p,h in inputs.items() if '/candidates/address-update-share-r2-' not in p and '/Opt4-fit-address-update-share-r2-' not in p}
for n in ['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressCurrentBucketMemory.scala']:
 path=F/REL/n;inputs[str(path)]=sha(path)
for path in C.iterdir():
 if path.is_file() and path.name!='input-hashes.json':inputs[str(path)]=sha(path)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
