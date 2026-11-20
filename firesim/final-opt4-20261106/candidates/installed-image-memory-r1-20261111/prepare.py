#!/usr/bin/python3
"""Prepare one isolated uninitialized 1R1W storage substitution."""
from pathlib import Path
import hashlib, importlib.util, json, subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
P=W/'Opt4-fit-update-share-svb-r2-20261111'
F=W/'Opt4-fit-installed-image-memory-r1-20261111'
BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775'
REL='chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,j):Path(p).write_text(json.dumps(j,indent=2,sort_keys=True)+'\n')
policy=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed'] and not policy['fpga_access']
assert not F.exists() and not (C/'binding.json').exists()
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=P,text=True).strip()==BASE
subprocess.run(['git','worktree','add','-b','opt4/installed-image-memory-r1-20261111',str(F),BASE],cwd=P,check=True)
f=F/REL;original=f.read_text();s=original
pairs=[
 ['  val installedImage = Reg(Vec(nSets, Vec(nWays, new CacheImageKey)))',
  '  val installedImage = Mem(nSets * nWays, new CacheImageKey)'],
 ['    installedImage(installSet)(installWay) := mshrs.io.install.bits.image',
  '    installedImage.write(Cat(installSet, installWay), mshrs.io.install.bits.image)'],
 ['installedImage(refillReqSet)(refillReqWay).asUInt',
  'installedImage.read(Cat(refillReqSet, refillReqWay)).asUInt']]
for old,new in pairs:
 assert s.count(old)==1,old
 s=s.replace(old,new)
back=s
for old,new in reversed(pairs):
 assert back.count(new)==1,new
 back=back.replace(new,old)
assert back==original and original.count('installedImage')==s.count('installedImage')==3
f.write_text(s)
j=json.loads((F/'lineage.json').read_text());j.update(purpose='Area-only flat asynchronous installedImage memory. All81 key bits,512 entries, no initialization or reset added, same write and read edge semantics. Not admitted.',branch='opt4/installed-image-memory-r1-20261111',source_tree=str(F/'chipyard'),area_parent=BASE,production_selected=False)
save(F/'lineage.json',j)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL,'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Represent installed image keys as flat uninitialized asynchronous memory'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inv=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
save(C/'source-inventory.json',inv);save(C/'replacements.json',pairs);(C/'parent.scala.txt').write_text(original)
cfg=json.loads((W/'candidates/slot-epoch-static-r2-20261111/toolchain.json').read_text());save(C/'toolchain.json',cfg)
key=F/'chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala'
b=dict(schema='ec-opt4-installed-image-binding/1',hardware_commit=commit,source_id=sid,parent_commit=BASE,frozen_commit=policy['functional_baseline_commit'],worktree=str(F),dcache_sha256=sha(f),key_definition=str(key),key_definition_sha256=sha(key),sets=256,ways=2,bits=81,write_ports=1,read_ports=1,uninitialized=True,production_selected=False,whole_dut_admission=False,fpga_access=False)
save(C/'binding.json',b);print(json.dumps(b,indent=2))
