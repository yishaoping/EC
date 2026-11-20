#!/usr/bin/python3
from pathlib import Path
import subprocess,json,hashlib,importlib.util
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
P=W/'Opt4-fit-update-share-svb-r2-20261111';F=W/'Opt4-fit-address-update-sequence-r1-20261111';BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775';SEQ='27f7e7d6d043d2c5e3dff7551fdb0487e5775580';TAG='9ae9a7fcf231a75259e23973b12a93896a443cbb';REL='chipyard/generators/boom/src/main/scala/lsu/'
O=D/'build-logs/Opt4-fit-address-update-sequence-r1-20261111'
assert not F.exists();subprocess.run(['git','worktree','add','-b','opt4/address-update-sequence-r1-20261111',str(F),BASE],cwd=P,check=True)
get=lambda commit,n:subprocess.check_output(['git','show',commit+':'+REL+n],cwd=F).decode()
base=get(TAG,'PackageAddressStats.scala');seq=get(SEQ,'PackageAddressStats.scala');s=get(BASE,'PackageAddressStats.scala');pairs=[]
def change(old,new):
 global s
 assert s.count(old)==1,(old[:80],s.count(old));s=s.replace(old,new,1);pairs.append([new,old])
a=base.index('  val bucketSeq =');b=base.index('  val bucketStore =',a);x=seq.index('  // All sequence bits');y=seq.index('  val bucketStore =',x);change(base[a:b],seq[x:y])
a=base.index('  private def bucketSequenceMatches(');b=base.index('\n\n',a);x=seq.index('  private def bucketSequenceMatches(');y=seq.index('\n\n',x);change(base[a:b],seq[x:y])
x=seq.index('  // resetStats has final assignment priority');y=seq.index('  // Safe-watermark retirement',x);insertion=seq[x:y];change('  // Safe-watermark retirement',insertion+'  // Safe-watermark retirement')
x=seq.index('  require(bucketSequenceReadPort ==');y=seq.index('\n\n',x);insertion=seq[x:y];needle='  val safeError = retiringSlotCollision || retiringUnderflow';change(needle,needle+'\n'+insertion)
change('        bucketSeq(i) := processEvent.packetSeq','        // Sequence update is the unchanged single physical-edge memory write.')
change('      bucketSeq(i) := 0.U','      // Invalid sequence payload remains hidden by the unchanged valid mask.')
back=s
for new,old in reversed(pairs):assert back.count(new)==1;back=back.replace(new,old,1)
assert back==get(BASE,'PackageAddressStats.scala')
(F/REL/'PackageAddressStats.scala').write_text(s);(F/REL/'AddressBucketSequenceMemory.scala').write_text(get(SEQ,'AddressBucketSequenceMemory.scala'))
line=json.loads((F/'lineage.json').read_text());line.update(branch='opt4/address-update-sequence-r1-20261111',purpose='Compose exact replicated90reader sequence storage with validated reset-correct update sharing. Independent complete proof/regression/map required.',source_tree=str(F/'chipyard'));(F/'lineage.json').write_text(json.dumps(line,indent=2)+'\n')
subprocess.run(['git','diff','--check'],cwd=F,check=True);subprocess.run(['git','add',REL+'PackageAddressStats.scala',REL+'AddressBucketSequenceMemory.scala','lineage.json'],cwd=F,check=True);subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Compose full-width replicated sequence storage with reset-correct counter update sharing'],cwd=F,check=True)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip();spec=importlib.util.spec_from_file_location('composed_inventory',W/'scripts/build_hw.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);inv=m.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest();O.mkdir(exist_ok=True)
b=dict(schema='ec-opt4-update-sequence-composition-binding/1',hardware_commit=commit,parent_commit=BASE,sequence_candidate=SEQ,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',source_id=sid,production_selected=False,full_dut_formal=False,fpga_access=False)
(C/'binding.json').write_text(json.dumps(b,indent=2)+'\n');(C/'reverse-substitutions.json').write_text(json.dumps(pairs,indent=2)+'\n');(O/'source-inventory.json').write_text(json.dumps(inv,indent=2)+'\n');(O/'candidate.patch').write_bytes(subprocess.check_output(['git','diff','--binary',BASE,commit],cwd=F))
cfg=json.loads((W/'candidates/address-static-retire-r2-20261111/config.json').read_text());cfg.update(binding=b,worktree=str(F));(C/'config.json').write_text(json.dumps(cfg,indent=2)+'\n');print(json.dumps(b))
