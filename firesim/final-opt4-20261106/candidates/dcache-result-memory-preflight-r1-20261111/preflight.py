#!/usr/bin/python3
"""Short source-bound combinational checks, not generated-RTL equivalence."""
from pathlib import Path
import datetime,hashlib,json,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=W/'candidates/dcache-result-memory-r1-20261111'
O=D/'build-logs/Opt4-fit-dcache-result-memory-preflight-r1-20261111'
O.mkdir(exist_ok=False)
b=json.loads((C/'binding.json').read_text())
F=W/'Opt4-fit-dcache-result-memory-r1-20261111'
source=F/'chipyard/generators/boom/src/main/scala/lsu/AppliedEffectResultMemory.scala'
s=source.read_text()
for needle in ['val payload = Mem(sets * ways, UInt(bits.W))',
 'def index(set: UInt, way: UInt): UInt = Cat(set, way)',
 'when (io.writeEnable) {',
 'payload.write(AppliedEffectResultMemory.index(io.writeSet, io.writeWay), io.writeData)']:
 assert needle in s,needle
assert '!reset' not in s and 'reset.asBool' not in s
indices=[(set<<3)|way for set in range(64) for way in range(8)]
assert sorted(indices)==list(range(512))
rtl=O/'IndexWord.v'
rtl.write_text('''module IndexWord(input [5:0] set,writeSet,input [2:0] way,writeWay,
 input [63:0] oldWord,newWord,data,input enable,reset,
 output indexEquivalent,nextEquivalent,mutantEquivalent);
 wire refHit=(set==writeSet)&&(way==writeWay);
 wire newHit=({set,way}=={writeSet,writeWay});
 wire [63:0] oldNext=(enable&&refHit)?data:oldWord;
 wire [63:0] newNext=(enable&&newHit)?data:newWord;
 wire [63:0] mutant=(enable&&newHit)?(data^64'h8000000000000000):newWord;
 assign indexEquivalent=(refHit==newHit);
 assign nextEquivalent=(oldWord!=newWord)||(oldNext==newNext);
 assign mutantEquivalent=(oldWord!=newWord)||(oldNext==mutant);
 endmodule
''')
checks=[]
for prop,negative in [('indexEquivalent',False),('nextEquivalent',False),('mutantEquivalent',True)]:
 log=O/(prop+'.log')
 argv=['/usr/local/bin/yosys','-Q','-T','-p',f'read_verilog {rtl}; prep -top IndexWord -flatten; sat -verify -prove {prop} 1 -timeout 10']
 with log.open('xb') as f:p=subprocess.run(argv,cwd=O,stdout=f,stderr=subprocess.STDOUT)
 text=log.read_text()
 assert ('proof did fail' in text and p.returncode!=0) if negative else ('SUCCESS' in text and p.returncode==0)
 assert 'timed out' not in text
 checks.append(dict(property=prop,negative=negative,returncode=p.returncode,argv=argv,log=str(log)))
r=dict(schema='ec-opt4-dcache-result-source-cut-preflight/1',utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
 hardware_commit=b['hardware_commit'],source_id=b['source_id'],
 source=str(source),source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
 index_bijection='PASS_ALL_64_SETS_8_WAYS_512_ENTRIES',
 checks=checks,proof='PASS_ARBITRARY_64BIT_WORD_UPDATE_AND_INDEX_NEGATIVE_MUTATION_REJECTED',
 proof_scope='Handwritten local SAT cut checked against literal source expressions; generated Chisel RTL proof and topology are separate pending broker stages. Equality is a relation on uninitialized payload; no independent initial-state equality claim.',
 complete_frozen_dcache_comparison=False,whole_dut_admitted=False,fpga_access=False)
(O/'result.json').write_text(json.dumps(r,indent=2,sort_keys=True)+'\n')
print(json.dumps({k:r[k] for k in ['hardware_commit','index_bijection','proof','whole_dut_admitted']}))
