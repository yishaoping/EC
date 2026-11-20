#!/usr/bin/python3
"""Prepare an independent latency candidate without editing any live tree."""
from pathlib import Path
import hashlib, importlib.util, json, subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
P = W/'Opt4-fit-address-bucket-tag-r3-20261111'
F = W/'Opt4-fit-barrier-event-read-r1-20261111'
O = D/'build-logs/Opt4-fit-barrier-event-read-r1-20261111'
BASE = '9ae9a7fcf231a75259e23973b12a93896a443cbb'
REL = 'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, x): Path(p).write_text(json.dumps(x, indent=2, sort_keys=True)+'\n')

assert not F.exists(), 'version a new candidate instead'
subprocess.run(['git','worktree','add','-b','opt4/barrier-event-read-r1-20261111',str(F),BASE],cwd=P,check=True)
p=F/REL; old=p.read_text(); source=old
needle='/** Per-package storage'
helper='''/** Exact read of a power-of-two slot array using a shared full decoder.
  * The selector is unqualified: invalid slots and overflow observations retain
  * exactly the same payload as the dynamic Vec access.
  */
object GHBarrierEventAccess {
  def read(select: Seq[Bool], data: Seq[UInt]): UInt = {
    require(select.nonEmpty && select.size == data.size)
    Mux1H(select, data)
  }
}

'''
assert source.count(needle)==1; source=source.replace(needle,helper+needle,1)
needle='  val eventBucketAvailable = !buckets.valid(eventIndex) ||\n    bucketResolve(eventIndex) || buckets.seq(eventIndex) === io.event.bits'
replacement='''  // Decode once for the five complete, unqualified asynchronous reads.
  // All bucket registers, writes, resets and reduction logic are unchanged.
  val eventSelect = (0 until window).map(i => eventIndex === i.U)
  val eventValid = GHBarrierEventAccess.read(eventSelect, buckets.valid.map(_.asUInt)).asBool
  val eventResolve = GHBarrierEventAccess.read(eventSelect, bucketResolve.map(_.asUInt)).asBool
  val eventSeq = GHBarrierEventAccess.read(eventSelect, buckets.seq.toSeq)
  val eventCount = GHBarrierEventAccess.read(eventSelect, buckets.count.toSeq)
  val eventRequestCycleSum = GHBarrierEventAccess.read(eventSelect, buckets.requestCycleSum.toSeq)
  val eventBucketAvailable = !eventValid || eventResolve || eventSeq === io.event.bits'''
assert source.count(needle)==1; source=source.replace(needle,replacement,1)
for before,after,count in [
 ('eventAccepted && buckets.valid(eventIndex) &&','eventAccepted && eventValid &&',2),
 ('!bucketResolve(eventIndex) &&','!eventResolve &&',2),
 ('buckets.count(eventIndex) === ~0.U(64.W)','eventCount === ~0.U(64.W)',1),
 ('buckets.requestCycleSum(eventIndex) >','eventRequestCycleSum >',1),
 ('when (!buckets.valid(eventIndex) || bucketResolve(eventIndex))','when (!eventValid || eventResolve)',1),
 ('buckets.count(eventIndex) + 1.U','eventCount + 1.U',1),
 ('buckets.requestCycleSum(eventIndex) + io.currentCycle','eventRequestCycleSum + io.currentCycle',1)]:
 assert source.count(before)==count,(before,source.count(before));source=source.replace(before,after)
p.write_text(source)
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Independent latency event read decoder; no state, update, overflow, cycle or instrumentation changes.',branch='opt4/barrier-event-read-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL,'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Share exact one-hot event reads in latency statistics'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('inventory_module',W/'scripts/build_hw.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
inv=m.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=True);save(O/'source-inventory.json',inv)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F);(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-barrier-event-read-binding/1',hardware_commit=commit,parent_commit=BASE,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,profile='Opt4-fit-barrier-event-read-r1-candidate',production_selected=False,full_dut_formal=False,patch_sha256=hashlib.sha256(patch).hexdigest(),change='Only five dynamic event-bucket reads become full one-hot reads. Unchanged registers/write guards/overflow/reductions/cycles/ports; complete frozen-module comparison and actual paired maps required.')
save(C/'binding.json',b);save(O/'candidate-binding.json',b)
(C/'parent.scala.txt').write_text(old)
frozen=(W/'C4'/REL).read_bytes()
(C/'frozen.scala.txt').write_bytes(frozen)
cfg=json.loads((W/'candidates/address-async-current-r1-20261111/config.json').read_text())
cfg.update(worktree=str(F),binding=b,source_relative=REL);save(C/'config.json',cfg)
inputs={str(p):sha(p) for p in {*map(Path,cfg['classpath']),*map(Path,cfg['compiler']),Path(cfg['plugin']),W/'scripts/build_hw.py',F/REL,W/'C4'/REL}}
for p in C.iterdir():
 if p.is_file() and p.name!='input-hashes.json':inputs[str(p)]=sha(p)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
