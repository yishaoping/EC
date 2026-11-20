#!/usr/bin/python3
"""Create a separate immutable 9ae-parent worktree; no live source mutation."""
from pathlib import Path
import hashlib,importlib.util,json,shutil,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
P=W/'Opt4-fit-address-bucket-tag-r3-20261111'
F=W/'Opt4-fit-dcache-result-memory-r1-20261111'
O=D/'build-logs/Opt4-fit-dcache-result-memory-r1-20261111'
BASE='9ae9a7fcf231a75259e23973b12a93896a443cbb'
REL='chipyard/generators/boom/src/main/scala/lsu/'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,x):Path(p).write_text(json.dumps(x,indent=2,sort_keys=True)+'\n')
assert not F.exists(),'version a new candidate instead'
subprocess.run(['git','worktree','add','-b','opt4/dcache-result-memory-r1-20261111',str(F),BASE],cwd=P,check=True)
p=F/REL/'dcache.scala';source=p.read_text()
old='  val appliedEffectResult = Reg(Vec(nSets, Vec(nWays, UInt(xLen.W))))'
new='''  // One writer, two independent asynchronous readers. Payload is unreset
  // exactly as before; all validity, token, and instrumentation arrays stay.
  val appliedEffectResultMemory = Module(new AppliedEffectResultMemory(nSets, nWays, xLen))
  appliedEffectResultMemory.io.writeEnable := false.B
  appliedEffectResultMemory.io.writeSet := 0.U
  appliedEffectResultMemory.io.writeWay := 0.U
  appliedEffectResultMemory.io.writeData := 0.U'''
assert source.count(old)==1;source=source.replace(old,new,1)
old='    s3_result := Mux(duplicate, appliedEffectResult(set)(way),'
new='''    s3_result := Mux(duplicate, appliedEffectResultMemory.io.readData(0),'''
assert source.count(old)==1;source=source.replace(old,new,1)
needle='  when (s2_write_grant) {'
insert='''  appliedEffectResultMemory.io.readSet(0) := s2_req(0).addr(idxMSB, idxLSB)
  appliedEffectResultMemory.io.readWay(0) := OHToUInt(s2_effective_req(0).way_en)
'''
assert source.count(needle)==1;source=source.replace(needle,insert+needle,1)
old='    s3_result := appliedEffectResult(s3_set)(s3_way_idx)'
assert source.count(old)==1;source=source.replace(old,'    s3_result := appliedEffectResultMemory.io.readData(1)',1)
needle='  when (s3_valid && s3_duplicate_effect) {'
insert='''  appliedEffectResultMemory.io.readSet(1) := s3_set
  appliedEffectResultMemory.io.readWay(1) := s3_way_idx
'''
assert source.count(needle)==1;source=source.replace(needle,insert+needle,1)
old='      appliedEffectResult(set)(way) := s3_result'
new='''      appliedEffectResultMemory.io.writeEnable := true.B
      appliedEffectResultMemory.io.writeSet := set
      appliedEffectResultMemory.io.writeWay := way
      appliedEffectResultMemory.io.writeData := s3_result'''
assert source.count(old)==1;source=source.replace(old,new,1)
assert 'appliedEffectResult(' not in source
p.write_text(source);shutil.copyfile(C/'AppliedEffectResultMemory.scala',F/REL/'AppliedEffectResultMemory.scala')
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Independent full-width DCache applied-effect result 2R1W asynchronous storage. No validity/token/debug/cycle changes.',branch='opt4/dcache-result-memory-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL+'dcache.scala',REL+'AppliedEffectResultMemory.scala','lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Use asynchronous full-width storage for duplicate effect results'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('result_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inventory=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=True);save(O/'source-inventory.json',inventory)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F);(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-dcache-result-memory-binding/1',hardware_commit=commit,parent_commit=BASE,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,profile='Opt4-fit-dcache-result-memory-r1-candidate',production_selected=False,full_dut_formal=False,patch_sha256=hashlib.sha256(patch).hexdigest(),change='Only unreset nSets*nWays*xLen appliedEffectResult storage becomes a full-width async2R1W memory. Original write guards, pre/post-edge behavior, validity/token arrays, debug arrays and all ports retained. Not admitted to whole DUT without complete frozen DCache comparison.')
save(C/'binding.json',b);save(O/'candidate-binding.json',b)
cfg=json.loads((W/'candidates/address-async-current-r1-20261111/config.json').read_text());cfg.update(worktree=str(F),binding=b)
save(C/'config.json',cfg)
parent_data=subprocess.check_output(['git','show',BASE+':'+REL+'dcache.scala'],cwd=P)
frozen_data=(W/'C4'/REL/'dcache.scala').read_bytes()
assert frozen_data==(Path(json.loads((W/'integration.json').read_text())['frozen_source'])/'generators/boom/src/main/scala/lsu/dcache.scala').read_bytes()
(C/'parent-dcache.scala.txt').write_bytes(parent_data)
(C/'frozen-dcache.scala.txt').write_bytes(frozen_data)
save(O/'dcache-source-lineage.json',dict(parent_sha256=hashlib.sha256(parent_data).hexdigest(),frozen_sha256=hashlib.sha256(frozen_data).hexdigest(),parent_equals_frozen=parent_data==frozen_data,frozen_commit=b['frozen_commit'],integration_manifest=str(W/'integration.json'),note='Frozen payload copied from preserved C4 tree and byte-compared to frozen source backup; original commit belongs to original repository, not this derived snapshot repository.'))
inputs={str(p):sha(p) for p in [*map(Path,cfg['classpath']),*map(Path,cfg['compiler']),Path(cfg['plugin']),W/'scripts/build_hw.py']}
for n in ['dcache.scala','AppliedEffectResultMemory.scala']:inputs[str(F/REL/n)]=sha(F/REL/n)
for p in C.iterdir():
 if p.is_file() and p.name!='input-hashes.json':inputs[str(p)]=sha(p)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
