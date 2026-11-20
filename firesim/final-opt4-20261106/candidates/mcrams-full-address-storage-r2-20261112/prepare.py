#!/usr/bin/python3
"""Private complete source-bound address module, no active source edits."""
import difflib,hashlib,json,pathlib,re
P=pathlib.Path;C=P(__file__).resolve().parent;W=C.parent.parent
ROOT=W/'Opt4-fit-dcache-field-read-prune-r1-20261111'
SRC=ROOT/'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
BASE='8491167d84b6d9521b151a743673c1516926a1f8';TARGET='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def exact(p,s):
 if p.exists():assert p.read_text()==s,p
 else:p.write_text(s)
def main():
 original=SRC.read_text();assert original.startswith('package boom.lsu\n')
 names=['bucketStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead','bucketFirstStore']
 plain=original.replace('package boom.lsu','package opt4addressplain\nimport boom.lsu.{AddressBucketGrouped, AddressBucketUpdate}',1)
 candidate=original.replace('package boom.lsu','package opt4addressmcrams\nimport boom.lsu.{AddressBucketGrouped, AddressBucketUpdate}\nimport chisel3.experimental.annotate\nimport midas.targetutils.MemModelAnnotation',1)
 # Preserve both private targets' full observable state, including invalid
 # payload after reset, for the future miter. This debug output is proof-only.
 marker='    val idle = Output(Bool())'
 debug='\n    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))'
 assert original.count(marker)==1
 plain=plain.replace(marker,marker+debug);candidate=candidate.replace(marker,marker+debug)
 counts={}
 for name in names:
  declaration=f'  val {name} = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))'
  assert candidate.count(declaration)==1
  replacement=f'''  val {name}Memory = Seq.fill(4)(Mem(packetWindow, UInt(64.W)))
  {name}Memory.foreach(m => annotate(MemModelAnnotation(m)))
  val {name} = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val {name}WriteData = WireDefault({name})
  val {name}WriteEnable = WireDefault(VecInit(Seq.fill(packetWindow)(VecInit(Seq.fill(4)(false.B)))))
  for (i <- 0 until packetWindow; g <- 0 until 4) {{
    {name}(i)(g) := {name}Memory(g).read(i.U)
  }}'''
  candidate=candidate.replace(declaration,replacement)
  # The same last-connect scopes implement process, then retiring clear,
  # then resetStats. Never mask old/invalid state, narrow arithmetic or move
  # the 80-term reduction. All original RHS expressions remain byte-identical.
  pat=re.compile(r'^(\s*)'+name+r'\((i|retiringIdx)\)\(g\) := (.+)$',re.M)
  hits=list(pat.finditer(candidate));assert len(hits)==4,(name,len(hits))
  def sub(m):
   indent,idx,rhs=m.groups()
   # Ignore the just-added constant read assignment; it must not be counted
   # as a write to target state.
   return f'{indent}{name}WriteEnable({idx})(g) := true.B\n{indent}{name}WriteData({idx})(g) := {rhs}'
  # Remove the read-wire assignment from the match set by matching only writes
  # whose RHS is not the Memory(g).read expression.
  effective=[h for h in hits if 'Memory(g).read' not in h[3]]
  assert len(effective)==3,(name,'expected process + retirement + reset',len(effective))
  candidate=pat.sub(lambda m:m[0] if 'Memory(g).read' in m[3] else sub(m),candidate)
  counts[name]=len(effective)
 tail='\n'.join(f'''  for (i <- 0 until packetWindow; g <- 0 until 4) {{
    when ({n}WriteEnable(i)(g)) {{ {n}Memory(g).write(i.U, {n}WriteData(i)(g)) }}
  }}''' for n in names)
 observe='\n'.join(f'  io.debugBuckets({k}) := {n}' for k,n in enumerate(names))
 # Insert after all original procedural assignments so that each constant
 # memory port sees the exact final last-connect data and enable.
 pos=candidate.rfind('\n}');candidate=candidate[:pos]+'\n'+tail+'\n'+observe+candidate[pos:]
 pos=plain.rfind('\n}');plain=plain[:pos]+'\n'+observe+plain[pos:]
 projected=candidate.replace('\n'+tail+'\n'+observe,'')
 for name in names:
  generated=f'''  val {name}Memory = Seq.fill(4)(Mem(packetWindow, UInt(64.W)))
  {name}Memory.foreach(m => annotate(MemModelAnnotation(m)))
  val {name} = Wire(Vec(packetWindow, Vec(4, UInt(64.W))))
  val {name}WriteData = WireDefault({name})
  val {name}WriteEnable = WireDefault(VecInit(Seq.fill(packetWindow)(VecInit(Seq.fill(4)(false.B)))))
  for (i <- 0 until packetWindow; g <- 0 until 4) {{
    {name}(i)(g) := {name}Memory(g).read(i.U)
  }}'''
  assert projected.count(generated)==1
  projected=projected.replace(generated,f'  val {name} = Reg(Vec(packetWindow, Vec(4, UInt(64.W))))')
  projected=re.sub(r'^[ \t]*'+name+r'WriteEnable\((?:i|retiringIdx)\)\(g\) := true.B\n','',projected,flags=re.M)
  projected=projected.replace(name+'WriteData(',name+'(')
 projected=projected.replace(debug,'')
 projected=projected.replace('package opt4addressmcrams\nimport boom.lsu.{AddressBucketGrouped, AddressBucketUpdate}\nimport chisel3.experimental.annotate\nimport midas.targetutils.MemModelAnnotation','package boom.lsu',1)
 assert projected==original,'non-storage source or update order altered\n'+''.join(difflib.unified_diff(original.splitlines(True),projected.splitlines(True)))[:3000]
 exact(C/'source-projection-audit.json',json.dumps(dict(status='PASS_EXACT_ORIGINAL_SOURCE_RECONSTRUCTED_FROM_STORAGE_ONLY_REWRITE',source_sha256=sha(SRC),reconstructed_sha256=hashlib.sha256(projected.encode()).hexdigest(),frozen_functional_baseline=BASE,complete_target_equivalence=False,process_retire_reset_assignment_order_unchanged=True,all_original_rhs_and80term_reductions_unchanged=True),indent=2,sort_keys=True)+'\n')
 exact(C/'PlainPackageAddressStats.scala',plain);exact(C/'MemPackageAddressStats.scala',candidate)
 exact(C/'target-only.patch',''.join(difflib.unified_diff(original.splitlines(True),candidate.splitlines(True),fromfile=str(SRC),tofile='private/MemPackageAddressStats.scala')))
 manifest=dict(schema='ec-source-bound-full-address-MCRams-candidate/1',functional_baseline=BASE,derived_target=TARGET,source=str(SRC),source_sha256=sha(SRC),candidate_sha256=sha(C/'MemPackageAddressStats.scala'),plain_proof_target_sha256=sha(C/'PlainPackageAddressStats.scala'),scope='Private complete PackageAddressStats target; twenty256x64bucket memories replacing fiveRegVec groups/fourgranularities. No active/full-host input changed.',packet_window=256,counter_width=64,counter_groups=5,granularities=4,observed_payload_words=5120,write_priority=['processCommit','safeAdvance&&!safeError&&bucketValid(retiringIdx)','resetStats'],global_reset='Payload unreset exactly as original; RegInit valid/control state retained',arithmetic='Complete original80-term bucketHistogram/exactHitSum, all65bit overflow, allcurrent/retiringreads unchanged',debug='Full5120payload words exported in both private proof targets, including invalidpayload',validation_status='PREPARED_REQUIRES_COMPILE_FULL_TARGET_PARITY_AND_MODULE_AREA',production_admission=False,fpga_access=False,changed_write_sites=counts)
 exact(C/'manifest.json',json.dumps(manifest,indent=2,sort_keys=True)+'\n');print(json.dumps(manifest,indent=2))
if __name__=='__main__':main()
