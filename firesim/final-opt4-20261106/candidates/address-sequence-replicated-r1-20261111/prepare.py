#!/usr/bin/python3
"""Create a successor without editing any live worktree or controller."""
from pathlib import Path
import hashlib, importlib.util, json, shutil, subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
P = W/'candidates/address-async-sequence-r1-20261111'
F = W/'Opt4-fit-address-sequence-replicated-r1-20261111'
O = D/'build-logs/Opt4-fit-address-sequence-replicated-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
BASE = '9ae9a7fcf231a75259e23973b12a93896a443cbb'
PREVIOUS = '94b749cf20b50487d82c7378071250fa9bd5eb3b'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, value): Path(p).write_text(json.dumps(value, indent=2, sort_keys=True)+'\n')

assert not F.exists(), 'never reuse a live candidate path'
subprocess.run(['git','worktree','add','-b','opt4/address-sequence-replicated-r1-20261111',str(F),PREVIOUS],
               cwd=W/'Opt4-fit-address-async-sequence-r1-20261111',check=True)
shutil.copyfile(C/'AddressBucketSequenceMemory.scala', F/REL/'AddressBucketSequenceMemory.scala')
line = json.loads((F/'lineage.json').read_text())
line.update(purpose='Replicate full-width async sequence storage into 45 two-read/one-write memories; unchanged parent module and cycles.',
            branch='opt4/address-sequence-replicated-r1-20261111',source_tree=str(F/'chipyard'))
save(F/'lineage.json',line)
assert (F/REL/'PackageAddressStats.scala').read_bytes() == subprocess.check_output(
    ['git','show',PREVIOUS+':'+REL+'PackageAddressStats.scala'],cwd=F)
subprocess.run(['git','diff','--check'],cwd=F,check=True)
subprocess.run(['git','add',REL+'AddressBucketSequenceMemory.scala','lineage.json'],cwd=F,check=True)
subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost',
                'commit','-m','Replicate bucket sequence memory into two-reader copies'],cwd=F,check=True)
commit = subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
spec = importlib.util.spec_from_file_location('inventory_module',W/'scripts/build_hw.py')
mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod)
inv = mod.inventory(F/'chipyard')
sid = hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
O.mkdir(exist_ok=True); save(O/'source-inventory.json',inv)
patch = subprocess.check_output(['git','diff','--binary',BASE,commit],cwd=F)
(O/'candidate.patch').write_bytes(patch)
b = dict(schema='ec-opt4-replicated-sequence-binding/1',hardware_commit=commit,
         source_id=sid,parent_commit=BASE,direct_git_parent=PREVIOUS,
         frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',
         profile='Opt4-fit-address-sequence-replicated-r1-candidate',
         production_selected=False,full_dut_formal=False,
         candidate_change='Full32 sequence storage, 90 async readers, 45 identical 256x32 memories with two reads each and broadcast single-edge writes. Parent RTL unchanged from 94b749cf. No narrowing, serialization, port/checker/recovery removal.',
         patch_sha256=hashlib.sha256(patch).hexdigest())
save(C/'binding.json',b); save(O/'candidate-binding.json',b)
cfg = json.loads((P/'config.json').read_text()); cfg.update(worktree=str(F),binding=b)
save(C/'config.json',cfg)
for name in ['EmitSequence.scala','boundary.cpp','frozen-original.v','frozen-tb.v']:
    shutil.copyfile(P/name,C/name)
inputs = {str(p):sha(p) for p in [*map(Path,cfg['classpath']),*map(Path,cfg['compiler']),
                                  Path(cfg['plugin']),W/'scripts/build_hw.py']}
for name in ['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressBucketSequenceMemory.scala']:
    p = F/REL/name; inputs[str(p)] = sha(p)
for p in C.iterdir():
    if p.is_file() and p.name != 'input-hashes.json': inputs[str(p)] = sha(p)
save(C/'input-hashes.json',inputs)
print(json.dumps(b,sort_keys=True))
