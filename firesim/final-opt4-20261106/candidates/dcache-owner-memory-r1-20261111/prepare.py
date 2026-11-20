#!/usr/bin/python3
"""Prepare independent source representation; never modify active CAD."""
from pathlib import Path
import hashlib,importlib.util,json,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
P=W/'Opt4-fit-update-share-svb-r2-20261111';F=W/'Opt4-fit-dcache-owner-memory-r1-20261111'
BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775'
REL='chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
O=D/'build-logs/Opt4-fit-dcache-owner-memory-r1-20261111'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,j):Path(p).write_text(json.dumps(j,indent=2,sort_keys=True)+'\n')
assert not F.exists();assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=P,text=True).strip()==BASE
subprocess.run(['git','worktree','add','-b','opt4/dcache-owner-memory-r1-20261111',str(F),BASE],cwd=P,check=True)
p=F/REL;original=p.read_text();source=original;pairs=[]
def replace(old,new,count=1):
 global source
 assert source.count(old)==count,(old,source.count(old));source=source.replace(old,new);pairs.append([new,old,count])
# One146-bit entry represents exactly the four reset-to-zero original arrays.
# Reset mask preserves every unqualified read, including invalid cache slots.
replace('''  val dirtyPacketSeq = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))))))
  val dirtyPacketTracked = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(false.B)))))''','''  // Function/cycle-equivalent full-width metadata storage; no validity filter
  // on readers. Independent reset mask represents the original zeroed payload.
  class OwnerPayload extends Bundle {
    val image = new CacheImageKey
    val generation = UInt(32.W)
    val packetSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
    val tracked = Bool()
  }
  require(isPow2(nSets) && isPow2(nWays))
  private val ownerWayBits = log2Ceil(nWays)
  private def ownerIndex(set: UInt, way: UInt): UInt =
    if (nWays == 1) set else Cat(set, way(ownerWayBits - 1, 0))
  val ownerMemory = Mem(nSets * nWays, new OwnerPayload)
  val ownerWritten = RegInit(VecInit(Seq.fill(nSets * nWays)(false.B)))
  val ownerWriteEnable = WireDefault(false.B)
  val ownerWriteIndex = WireDefault(0.U(log2Ceil(nSets * nWays).W))
  val ownerWriteData = WireDefault(0.U.asTypeOf(new OwnerPayload))
  private def readOwner(set: UInt, way: UInt): OwnerPayload = {
    val index = ownerIndex(set, way)
    Mux(ownerWritten(index), ownerMemory.read(index), 0.U.asTypeOf(new OwnerPayload))
  }
  when (ownerWriteEnable && !reset.asBool) {
    ownerMemory.write(ownerWriteIndex, ownerWriteData)
    ownerWritten(ownerWriteIndex) := true.B
  }''')
replace('''  val lineGeneration = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U(32.W))))))''','')
replace('''  val imageKey = RegInit(VecInit(Seq.fill(nSets)(VecInit(
    Seq.fill(nWays)(0.U.asTypeOf(new CacheImageKey))))))''','')
replace('''      dirtyPacketSeq(set)(way) := mshrs.io.refill.bits.image.contentSeq
      dirtyPacketTracked(set)(way) := mshrs.io.refill.bits.image.valid &&
        mshrs.io.refill.bits.image.contentSeq =/= 0.U
      lineGeneration(set)(way) := mshrs.io.refill.bits.image.generation
      imageKey(set)(way) := mshrs.io.refill.bits.image''','''      ownerWriteEnable := true.B
      ownerWriteIndex := ownerIndex(set, way)
      ownerWriteData.packetSeq := mshrs.io.refill.bits.image.contentSeq
      ownerWriteData.tracked := mshrs.io.refill.bits.image.valid &&
        mshrs.io.refill.bits.image.contentSeq =/= 0.U
      ownerWriteData.generation := mshrs.io.refill.bits.image.generation
      ownerWriteData.image := mshrs.io.refill.bits.image''')
replace('''    lineGeneration(set)(way) := imageSerial''','''    ownerWriteEnable := true.B
    ownerWriteIndex := ownerIndex(set, way)
    ownerWriteData.generation := imageSerial''')
replace('''    imageKey(set)(way).valid := true.B
    imageKey(set)(way).writer := outer.staticImageWriter.U
    imageKey(set)(way).generation := imageSerial
    imageKey(set)(way).contentSeq := s3_req.packet_seq''','''    ownerWriteData.image.valid := true.B
    ownerWriteData.image.writer := outer.staticImageWriter.U
    ownerWriteData.image.generation := imageSerial
    ownerWriteData.image.contentSeq := s3_req.packet_seq''')
replace('''    dirtyPacketSeq(set)(way) := s3_req.packet_seq
    dirtyPacketTracked(set)(way) := s3_req.packet_seq =/= 0.U''','''    ownerWriteData.packetSeq := s3_req.packet_seq
    ownerWriteData.tracked := s3_req.packet_seq =/= 0.U''')
def closing(text,start):
 assert text[start]=='(';depth=1;i=start+1
 while depth:
  if text[i]=='(':depth+=1
  elif text[i]==')':depth-=1
  i+=1
 return i
# All remaining occurrences are reads. Preserve exact set/way expressions,
# including invalid/debug/overflow observations; no newly qualified readers.
reads=[]
for name,field in [('dirtyPacketSeq','packetSeq'),('dirtyPacketTracked','tracked'),('lineGeneration','generation'),('imageKey','image')]:
 pos=0
 while True:
  a=source.find(name+'(',pos)
  if a<0:break
  x=a+len(name);y=closing(source,x);assert source[y]=='('
  z=closing(source,y)
  old=source[a:z];new='readOwner('+source[x+1:y-1]+', '+source[y+1:z-1]+').'+field
  assert not source[z:].lstrip().startswith(':='),'unhandled write'
  source=source[:a]+new+source[z:];pairs.append([new,old,1]);reads.append({'source':old,'replacement':new});pos=a+len(new)
# Reverse substitutions in reverse order must reproduce every byte of parent.
back=source
for new,old,count in reversed(pairs):
 assert back.count(new)>=count,(new,back.count(new));back=back.replace(new,old,count)
assert back==original
assert len(reads)>40
p.write_text(source)
line=json.loads((F/'lineage.json').read_text());line.update(purpose='Full-width reset-masked async DCache owner metadata storage only; original C4/SVB32 behavior and exact read/write cycles retained. Independent candidate, not admitted.',branch='opt4/dcache-owner-memory-r1-20261111',source_tree=str(F/'chipyard'));save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL,'lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Represent full-width DCache owner arrays by reset-masked async storage'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec=importlib.util.spec_from_file_location('owner_inventory',W/'scripts/build_hw.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
inv=m.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest();O.mkdir(exist_ok=True)
save(O/'source-inventory.json',inv)
patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F);(O/'candidate.patch').write_bytes(patch)
b=dict(schema='ec-opt4-owner-memory-binding/1',hardware_commit=commit,parent_commit=BASE,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,production_selected=False,fpga_access=False,full_dut_formal=False,change='Only four full-width resettable DCache arrays represented by146bit512entry reset-masked async memory, original physical-effect/refill write guards and all unqualified read expressions retained.',read_accesses=len(reads),patch_sha256=hashlib.sha256(patch).hexdigest())
save(C/'binding.json',b);save(O/'candidate-binding.json',b)
(C/'parent.scala.txt').write_text(original);save(C/'reverse-substitutions.json',pairs);save(C/'read-accesses.json',reads)
cfg=json.loads((W/'candidates/dcache-owner-memory-screen-r3-20261111/config.json').read_text());cfg.update(worktree=str(F),binding=b,source_relative=REL);save(C/'config.json',cfg)
print(json.dumps(b))
