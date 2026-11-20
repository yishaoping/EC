#!/usr/bin/python3
"""Create a separate source candidate; preserve all existing CAD inputs."""
from pathlib import Path
import hashlib, importlib.util, json, subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
P = W/'Opt4-fit-update-share-svb-r2-20261111'
F = W/'Opt4-fit-barrier-update-share-r1-20261111'
O = D/'build-logs/Opt4-fit-barrier-update-share-r1-20261111'
BASE = 'e0c3737f989c563f99a00f3fd26c1cbd27421775'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
REL = 'chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, value): Path(p).write_text(json.dumps(value, indent=2, sort_keys=True)+'\n')

policy = json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert policy['area_equivalence_only'] and policy['functional_baseline_commit'] == FROZEN
assert not F.exists(), 'Use a new version, never replace a partial candidate'
subprocess.run(['git','worktree','add','-b','opt4/barrier-update-share-r1-20261111',str(F),BASE],cwd=P,check=True)
src = F/REL
parent = src.read_text()
helper = '''/** Share only accepted-event arithmetic; all values remain full width. */
object GHBarrierEventUpdate {
  def count(allocate: Bool, old: UInt): UInt =
    Mux(allocate, 1.U(64.W), old + 1.U)
  def cycleSum(allocate: Bool, old: UInt, cycle: UInt): UInt =
    Mux(allocate, cycle, old + cycle)
  def selected(accepted: Bool, index: UInt, slot: Int): Bool =
    accepted && index === slot.U
}

'''
old = '''    for (i <- 0 until window) {
      when (bucketResolve(i)) {
        buckets.valid(i) := false.B
        buckets.count(i) := 0.U
        buckets.requestCycleSum(i) := 0.U
      }
    }

    when (eventAccepted) {
      when (!buckets.valid(eventIndex) || bucketResolve(eventIndex)) {
        buckets.valid(eventIndex) := true.B
        buckets.seq(eventIndex) := io.event.bits
        buckets.count(eventIndex) := 1.U
        buckets.requestCycleSum(eventIndex) := io.currentCycle
      }.otherwise {
        buckets.count(eventIndex) := buckets.count(eventIndex) + 1.U
        buckets.requestCycleSum(eventIndex) :=
          buckets.requestCycleSum(eventIndex) + io.currentCycle
      }
    }
'''
new = '''    val eventAllocates = !buckets.valid(eventIndex) || bucketResolve(eventIndex)
    val nextEventCount = GHBarrierEventUpdate.count(eventAllocates, buckets.count(eventIndex))
    val nextEventCycleSum = GHBarrierEventUpdate.cycleSum(eventAllocates,
      buckets.requestCycleSum(eventIndex), io.currentCycle)
    for (i <- 0 until window) {
      when (bucketResolve(i)) {
        buckets.valid(i) := false.B
        buckets.count(i) := 0.U
        buckets.requestCycleSum(i) := 0.U
      }
      // Preserve the original event-after-resolution priority at every slot.
      when (GHBarrierEventUpdate.selected(eventAccepted, eventIndex, i)) {
        when (eventAllocates) {
          buckets.valid(i) := true.B
          buckets.seq(i) := io.event.bits
        }
        buckets.count(i) := nextEventCount
        buckets.requestCycleSum(i) := nextEventCycleSum
      }
    }
'''
assert parent.count(old) == 1
newsrc = parent.replace('class GHBarrierLatencyBucket', helper+'class GHBarrierLatencyBucket', 1).replace(old,new,1)
assert newsrc.replace(helper,'',1).replace(new,old,1) == parent
src.write_text(newsrc)
lineage=json.loads((F/'lineage.json').read_text())
lineage.update(purpose='Function/cycle-equivalent barrier event write factoring; full reset, overflow and instrumentation retained.',branch='opt4/barrier-update-share-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',lineage)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL,'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Share exact accepted-event updates in barrier latency buckets'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
sp=importlib.util.spec_from_file_location('opt4inventory',W/'scripts/build_hw.py')
module=importlib.util.module_from_spec(sp);sp.loader.exec_module(module)
inventory=module.inventory(F/'chipyard')
sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=False)
save(O/'source-inventory.json',inventory)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F)
(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-barrier-update-share-binding/1',hardware_commit=commit,parent_commit=BASE,frozen_commit=FROZEN,source_id=sid,production_selected=False,full_dut_formal=False,fpga_access=False,patch_sha256=hashlib.sha256(patch).hexdigest(),change='Only barrier bucket event writes and equivalent 64-bit arithmetic factoring. Static resolve/event priority, all state, reset, checks, ports and cycles retained.')
save(C/'binding.json',b)
save(O/'candidate-binding.json',b)
save(C/'reverse-recipe.json',dict(helper=helper,old=old,new=new))
(C/'parent.scala.txt').write_text(parent)
frozen=subprocess.check_output(['git','show',FROZEN+':'+REL],cwd=P)
(C/'frozen.scala.txt').write_bytes(frozen)
# The previous one-hot-read candidate is not inherited.
assert b'GHBarrierEventAccess' not in src.read_bytes()
cfg=json.loads((W/'candidates/barrier-event-read-r1-20261111/config.json').read_text())
cfg.update(worktree=str(F),binding=b,source_relative=REL,max_threads=4)
save(C/'config.json',cfg)
inputs={str(p):sha(p) for p in {*map(Path,cfg['classpath']),*map(Path,cfg['compiler']),Path(cfg['plugin']),W/'scripts/build_hw.py',src}}
for path in C.iterdir():
    if path.is_file() and path.name != 'input-hashes.json': inputs[str(path)]=sha(path)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
