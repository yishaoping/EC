#!/usr/bin/python3
"""Prepare a new worktree; never modify an existing candidate or live inputs."""
from pathlib import Path
import hashlib,importlib.util,json,shutil,subprocess

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
F=W/'Opt4-fit-address-async-sequence-r1-20261111'
P=W/'Opt4-fit-address-bucket-tag-r3-20261111'
O=D/'build-logs/Opt4-fit-address-async-sequence-r1-20261111'
BASE='9ae9a7fcf231a75259e23973b12a93896a443cbb'
REL='chipyard/generators/boom/src/main/scala/lsu/'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,x):Path(p).write_text(json.dumps(x,indent=2,sort_keys=True)+'\n')

assert not F.exists(),'new candidate name required'
subprocess.run(['git','worktree','add','-b','opt4/address-async-sequence-r1-20261111',str(F),BASE],cwd=P,check=True)
p=F/REL/'PackageAddressStats.scala';s=p.read_text()
old='''  val bucketSeq = Reg(Vec(packetWindow,
    UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))'''
new='''  // All sequence bits are retained. The single write port and every
  // combinational reader preserve the original edge and access semantics.
  private val bucketSequenceReaders = packageWays + strictWays + strictOverflowEntries + 2
  val bucketSequenceMemory = Module(new AddressBucketSequenceMemory(
    packetWindow, bucketSequenceReaders, GH_GlobalParams.GH_PACKET_SEQ_BITS))
  private var bucketSequenceReadPort = 0'''
assert s.count(old)==1;s=s.replace(old,new,1)
old='''  private def bucketSequenceMatches(index: UInt, sequence: UInt): Bool =
    bucketSeq(index)(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, packetIndexBits) ===
      sequence(GH_GlobalParams.GH_PACKET_SEQ_BITS - 1, packetIndexBits)'''
new='''  private def bucketSequenceMatches(index: UInt, sequence: UInt): Bool = {
    val port = bucketSequenceReadPort
    bucketSequenceReadPort += 1
    bucketSequenceMemory.io.readIndex(port) := index
    AddressBucketSequenceMemory.matches(
      bucketSequenceMemory.io.readData(port), sequence, packetIndexBits)
  }'''
assert s.count(old)==1;s=s.replace(old,new,1)
old='''        bucketSeq(i) := processEvent.packetSeq
''';assert s.count(old)==1;s=s.replace(old,'',1)
old='''      bucketSeq(i) := 0.U
''';assert s.count(old)==1;s=s.replace(old,'',1)
needle='''  // Safe-watermark retirement is serialized before the next event whose'''
insert='''  // resetStats has final assignment priority in the original register
  // table. Invalid payload is hidden by bucketValid; suppress its write edge.
  bucketSequenceMemory.io.writeEnable := processCommit && !io.resetStats
  bucketSequenceMemory.io.writeIndex := currentBucketIdx
  bucketSequenceMemory.io.writeData := processEvent.packetSeq

'''
assert needle in s;s=s.replace(needle,insert+needle,1)
needle='''  val safeError = retiringSlotCollision || retiringUnderflow'''
assert needle in s;s=s.replace(needle,needle+'''
  require(bucketSequenceReadPort == bucketSequenceReaders,
    "every original sequence reader must have one combinational memory port")''',1)
assert 'bucketSeq(' not in s
p.write_text(s);shutil.copyfile(C/'AddressBucketSequenceMemory.scala',F/REL/'AddressBucketSequenceMemory.scala')
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Full-width single-writer asynchronous bucket-sequence storage; all validity/state/cycle contracts retained.',branch='opt4/address-async-sequence-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL+'PackageAddressStats.scala',REL+'AddressBucketSequenceMemory.scala','lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Use full-width async memory for single-writer bucket sequences'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('sequence_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
inventory=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=True);save(O/'source-inventory.json',inventory)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F);(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-async-sequence-binding/1',hardware_commit=commit,parent_commit=BASE,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,profile='Opt4-fit-address-async-sequence-r1-candidate',production_selected=False,full_dut_formal=False,candidate_change='Only bucketSeq register-vector storage becomes 256x32 asynchronous 90R1W memory; no sequence width, state validity, bucket count, cycle, error or instrumentation change.',patch_sha256=hashlib.sha256(patch).hexdigest())
save(C/'binding.json',b);save(O/'candidate-binding.json',b)
cfg=json.loads((W/'candidates/address-async-current-r1-20261111/config.json').read_text());cfg.update(worktree=str(F),binding=b)
save(C/'config.json',cfg)
for n in ['frozen-original.v','frozen-tb.v']:shutil.copyfile(W/'candidates/address-update-share-r2-20261111'/n,C/n)
inputs={str(p):sha(p) for p in [*map(Path,cfg['classpath']),*map(Path,cfg['compiler']),Path(cfg['plugin']),W/'scripts/build_hw.py']}
for n in ['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressBucketSequenceMemory.scala']:inputs[str(F/REL/n)]=sha(F/REL/n)
for p in C.iterdir():
 if p.is_file() and p.name!='input-hashes.json':inputs[str(p)]=sha(p)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
