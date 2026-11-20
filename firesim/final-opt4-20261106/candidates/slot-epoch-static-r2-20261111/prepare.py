#!/usr/bin/python3
from pathlib import Path
import hashlib, importlib.util, json, subprocess

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
policy=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
P=W/'Opt4-fit-update-share-svb-r2-20261111'
F=W/'Opt4-fit-slot-epoch-static-r2-20261111'
BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775'
REL='chipyard/generators/boom/src/main/scala/lsu/'
def save(p,j):Path(p).write_text(json.dumps(j,indent=2,sort_keys=True)+'\n')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
assert not F.exists()
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=P,text=True).strip()==BASE
subprocess.run(['git','worktree','add','-b','opt4/slot-epoch-static-r2-20261111',str(F),BASE],cwd=P,check=True)
src=F/REL/'dcache.scala';original=src.read_text();s=original;pairs=[]
def replace(a,b,count=1):
 global s
 assert s.count(a)==count,(a,s.count(a))
 s=s.replace(a,b);pairs.append([b,a,count])
replace('''  val slotEpoch = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(16.W))))))''','''  val slotEpochBank = new SlotEpochBank(nSets, nWays)''')
replace('slotEpoch(pset)(pway) := slotEpoch(pset)(pway) + 1.U',
        'slotEpochBank.write(0, pset, pway, slotEpochBank.read(pset, pway) + 1.U)')
replace('''slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) :=
      slotEpoch(crossPackagePendingSet)(crossPackagePendingWay) + 1.U''',
        '''slotEpochBank.write(1, crossPackagePendingSet, crossPackagePendingWay,
      slotEpochBank.read(crossPackagePendingSet, crossPackagePendingWay) + 1.U)''')
replace('slotEpoch(set)(way) := reservedEpoch(set)(way)',
        'slotEpochBank.write(2, set, way, reservedEpoch(set)(way))')
replace('slotEpoch(s0_req(w).addr(idxMSB, idxLSB))',
        'slotEpochBank.readSet(s0_req(w).addr(idxMSB, idxLSB))')
replace('''VecInit((0 until nSets).flatMap(s =>
    (0 until nWays).map(w => slotEpoch(s)(w))))''','slotEpochBank.snapshot')
def closing(text,start):
 assert text[start]=='('
 depth=1;i=start+1
 while depth:
  depth += (text[i]=='(')-(text[i]==')');i+=1
 return i
reads=[];pos=0
while True:
 a=s.find('slotEpoch(',pos)
 if a<0:break
 x=a+len('slotEpoch');y=closing(s,x);assert s[y]=='('
 z=closing(s,y);old=s[a:z]
 assert not s[z:].lstrip().startswith(':='),old
 new='slotEpochBank.read('+s[x+1:y-1]+', '+s[y+1:z-1].lstrip()+')'
 s=s[:a]+new+s[z:];pairs.append([new,old,1]);reads.append([old,new]);pos=a+len(new)
back=s
for new,old,count in reversed(pairs):
 assert back.count(new)>=count,(new,back.count(new))
 back=back.replace(new,old,count)
assert back==original
assert 'slotEpoch(' not in s and s.count('slotEpochBank.write(')==3
src.write_text(s);(F/REL/'SlotEpochBank.scala').write_bytes((C/'SlotEpochBank.scala').read_bytes())
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Area-only statically decoded slotEpoch registers, full16bit state, three independent writes, original priority/reset/read/debug cycles; candidate not admitted.',branch='opt4/slot-epoch-static-r2-20261111',source_tree=str(F/'chipyard'));save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL+'dcache.scala',REL+'SlotEpochBank.scala','lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Statically decode slot epoch writes and preserve ordered full-width observations'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inv=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
save(C/'source-inventory.json',inv);save(C/'reverse-substitutions.json',pairs);save(C/'read-accesses.json',reads)
(C/'parent.scala.txt').write_text(original)
b=dict(schema='ec-opt4-slot-epoch-binding/1',hardware_commit=commit,source_id=sid,parent_commit=BASE,frozen_commit=policy['functional_baseline_commit'],worktree=str(F),sets=256,ways=2,bits=16,write_ports=3,write_priority=['probe','crossPackageMetaClear','refill'],scalar_read_occurrences=len(reads),full_snapshot_entries=512,helper_sha256=sha(F/REL/'SlotEpochBank.scala'),dcache_sha256=sha(src),production_selected=False,whole_dut_admission=False,fpga_access=False)
save(C/'binding.json',b);print(json.dumps(b))
