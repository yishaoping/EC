#!/usr/bin/python3
"""Prepare independent reservation-payload storage; never touch live trees."""
from pathlib import Path
import hashlib,importlib.util,json,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
P=W/'Opt4-fit-update-share-svb-r2-20261111'
F=W/'Opt4-fit-reservation-memory-r1-20261111'
BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775'
REL='chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
def save(p,j):Path(p).write_text(json.dumps(j,indent=2,sort_keys=True)+'\n')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
policy=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed'] and not policy['fpga_access']
assert policy['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
assert not F.exists() and not (C/'binding.json').exists()
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=P,text=True).strip()==BASE
subprocess.run(['git','worktree','add','-b','opt4/reservation-memory-r1-20261111',str(F),BASE],cwd=P,check=True)
f=F/REL;original=f.read_text();s=original
helper="""  // Area-only representation: preserve uninitialized payload and clock edge.
  // The frozen single-issue port has exactly one reservation writer. Wider
  // configurations retain their original nested register/last-connect logic.
  class ReservationStorage[T <: Data](gen: T) {
    private val payload = if (memWidth == 1) Some(Mem(nSets * nWays, gen)) else None
    private val registers = if (memWidth != 1) Some(Reg(Vec(nSets, Vec(nWays, gen)))) else None
    def apply(set: UInt)(way: UInt): T = {
      if (memWidth == 1) payload.get.read(Cat(set, way)) else registers.get(set)(way)
    }
    def write(set: UInt, way: UInt, data: T): Unit = {
      if (memWidth == 1) payload.get.write(Cat(set, way), data)
      else registers.get(set)(way) := data
    }
  }
"""
start=original.index('  val reservedEpoch = Reg(');end=original.index('  val installedImage = ',start)
old=original[start:end]
new=helper+"""  val reservedEpoch = new ReservationStorage(UInt(16.W))
  val reservedTransaction = new ReservationStorage(UInt(32.W))
  val reservedMshr = new ReservationStorage(UInt(8.W))
  val reservedNewOwner = new ReservationStorage(Bool())
  val reservedTag = new ReservationStorage(UInt(tagBits.W))
"""
pairs=[[old,new]]
for name,data in [('reservedEpoch','r.slot_epoch'),('reservedTransaction','r.transaction_token'),('reservedMshr','r.replay_mshr_id'),('reservedNewOwner','r.admission === CacheAdmission.primary'),('reservedTag','r.addr >> untagBits')]:
 pairs.append([f'      {name}(set)(way) := {data}',f'      {name}.write(set, way, {data})'])
for old,new in pairs:
 assert s.count(old)==1,old
 s=s.replace(old,new)
back=s
for old,new in reversed(pairs):
 assert back.count(new)==1,new
 back=back.replace(new,old)
assert back==original
for token in ['assert(', 'printf(', 'dontTouch(']:assert s.count(token)==original.count(token)
f.write_text(s)
j=json.loads((F/'lineage.json').read_text());j.update(purpose='Area-only uninitialized reservation-payload asynchronous memories with original multi-issue fallback. No new behavior, not admitted.',branch='opt4/reservation-memory-r1-20261111',source_tree=str(F/'chipyard'),area_parent=BASE,production_selected=False)
save(F/'lineage.json',j)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL,'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Represent single-port reservation metadata as uninitialized asynchronous memories'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inv=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
save(C/'source-inventory.json',inv);save(C/'replacements.json',pairs);(C/'parent.scala.txt').write_text(original)
cfg=json.loads((W/'candidates/installed-image-memory-r1-20261111/toolchain.json').read_text());save(C/'toolchain.json',cfg)
b=dict(schema='ec-opt4-reservation-storage-binding/1',hardware_commit=commit,source_id=sid,parent_commit=BASE,frozen_commit=policy['functional_baseline_commit'],worktree=str(F),dcache_sha256=sha(f),sets=256,ways=2,fields={'epoch':16,'transaction':32,'mshr':8,'newOwner':1,'tag':26},bits=83,read_ports=5,write_ports=1,uninitialized=True,production_selected=False,whole_dut_admission=False,fpga_access=False)
save(C/'binding.json',b);print(json.dumps(b,indent=2))
