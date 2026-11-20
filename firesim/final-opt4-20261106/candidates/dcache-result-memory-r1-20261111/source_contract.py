#!/usr/bin/python3
"""Exact source reversal for the isolated payload-storage substitution."""
from pathlib import Path
import hashlib,json
C=Path(__file__).resolve().parent
def verify():
 cfg=json.loads((C/'config.json').read_text());F=Path(cfg['worktree'])
 p=F/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala';s=p.read_text()
 pairs=[('''  // One writer, two independent asynchronous readers. Payload is unreset
  // exactly as before; all validity, token, and instrumentation arrays stay.
  val appliedEffectResultMemory = Module(new AppliedEffectResultMemory(nSets, nWays, xLen))
  appliedEffectResultMemory.io.writeEnable := false.B
  appliedEffectResultMemory.io.writeSet := 0.U
  appliedEffectResultMemory.io.writeWay := 0.U
  appliedEffectResultMemory.io.writeData := 0.U''',
 '  val appliedEffectResult = Reg(Vec(nSets, Vec(nWays, UInt(xLen.W))))'),
 ('''  appliedEffectResultMemory.io.readSet(0) := s2_req(0).addr(idxMSB, idxLSB)
  appliedEffectResultMemory.io.readWay(0) := OHToUInt(s2_effective_req(0).way_en)
''',''),
 ('    s3_result := Mux(duplicate, appliedEffectResultMemory.io.readData(0),',
  '    s3_result := Mux(duplicate, appliedEffectResult(set)(way),'),
 ('''  appliedEffectResultMemory.io.readSet(1) := s3_set
  appliedEffectResultMemory.io.readWay(1) := s3_way_idx
''',''),
 ('    s3_result := appliedEffectResultMemory.io.readData(1)',
  '    s3_result := appliedEffectResult(s3_set)(s3_way_idx)'),
 ('''      appliedEffectResultMemory.io.writeEnable := true.B
      appliedEffectResultMemory.io.writeSet := set
      appliedEffectResultMemory.io.writeWay := way
      appliedEffectResultMemory.io.writeData := s3_result''',
  '      appliedEffectResult(set)(way) := s3_result')]
 for new,old in pairs:
  assert s.count(new)==1,new
  s=s.replace(new,old,1)
 parent=(C/'parent-dcache.scala.txt').read_text();frozen=(C/'frozen-dcache.scala.txt').read_text()
 assert s==parent,'unexpected change outside exact payload substitution'
 return dict(schema='ec-opt4-result-storage-source-contract/1',status='PASS_EXACT_PARENT_REVERSAL',
  hardware_commit=cfg['binding']['hardware_commit'],source_id=cfg['binding']['source_id'],
  source=str(p),source_sha256=hashlib.sha256(p.read_bytes()).hexdigest(),
  parent_sha256=hashlib.sha256(parent.encode()).hexdigest(),
  frozen_sha256=hashlib.sha256(frozen.encode()).hexdigest(),parent_equals_frozen=parent==frozen,
  substitution_count=6,write_guards_unchanged=True,all_other_source_byte_equal=True,
  no_debug_or_checker_reduction=True,complete_frozen_dcache_comparison='PENDING',
  scope='Exact source structural substitution; does not prove full-DCache generated-RTL output equivalence.',fpga_access=False)
if __name__=='__main__':print(json.dumps(verify(),indent=2,sort_keys=True))
