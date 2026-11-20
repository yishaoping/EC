#!/usr/bin/python3
"""Exact3656 source composition and typecheck, no GG/CAD/FPGA access."""
import hashlib
import json
import os
from pathlib import Path
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-dcache-reservation-image-compose-r1-20261112'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

cfgpath = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
cfg = read(cfgpath)
F = Path(cfg['worktree'])
commit = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
relative = 'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
original = subprocess.check_output(['git','show',commit+':'+relative],cwd=F)
assert original == (F/relative).read_bytes()
patches = [W/'candidates'/n/'replacements.json' for n in
    ['reservation-memory-r1-20261111','installed-image-memory-r1-20261111']]
text = original.decode()
reversals = []
for path in patches:
    for old,new in read(path):
        assert text.count(old) == 1, (str(path), old, text.count(old))
        text = text.replace(old,new,1)
        reversals.append((old,new))
reverse = text
for old,new in reversed(reversals):
    assert reverse.count(new) == 1
    reverse = reverse.replace(new,old,1)
assert reverse.encode() == original
assert 'if (memWidth == 1)' in text
assert 'Reg(Vec(nSets, Vec(nWays, gen)))' in text
assert text.count('reservedEpoch.write(') == 1
assert text.count('installedImage.write(') == 1
C.mkdir(exist_ok=True)
source = C/'dcache.scala'
if source.exists(): assert source.read_text() == text
else: source.write_text(text)
proofs = [D/'build-logs/Opt4-fit-reservation-proof-r3-20261111/result.json',
    W/'candidates/installed-image-memory-r1-20261111/proof-evidence-r1/result.json']
classes_base = F/'builds/system-3656aec4-r4/source-classes'
pins = dict(schema='ec-dcache-reservation-image-source-composition/1',
    utc=now(), functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
    derived_hardware=commit, parent_source_sha256=hashlib.sha256(original).hexdigest(),
    candidate_source_sha256=sha(source), source_reversal_pass=True,
    replacements=len(reversals), files={str(p):sha(p) for p in patches+proofs+[cfgpath,C/'prepare.py',source]},
    base_private_class_hashes={str(p):sha(p) for p in sorted(classes_base.rglob('*.class'))},
    scope='Complete3656DCache source with only two prior source-bound storage replacements; compile-only prerequisite.',
    original_writers_clocks_resets_observations_preserved=True,
    wider_memWidth_retains_original_registers=True,
    full_dcache_equivalence=False, full_host_area_saving_unknown=True,
    production_admission=False, no_GoldenGate=True, no_CAD=True, no_board_io=True,
    next='Source projection -> full generatedDCache topology+same-target-cycle/allobservations parity -> paired generated-host module area. No subtraction of local gains.')
pinpath = C/'source-composition.json'
if pinpath.exists():
    prior=read(pinpath); pins['utc']=prior['utc']; assert prior == pins
else: save(pinpath,pins)
print(json.dumps({k:pins[k] for k in ['source_reversal_pass','replacements','parent_source_sha256','candidate_source_sha256']}))
if '--compile' not in sys.argv: sys.exit(0)

O.mkdir(exist_ok=True)
assert not (O/'result.json').exists() and not (O/'compile.log').exists(), 'Preserve existing attempt'
cpus = {234,235}
overlap = []
for proc in Path('/proc').iterdir():
    if not proc.name.isdigit(): continue
    try:
        affinity = os.sched_getaffinity(int(proc.name))
        if proc.stat().st_uid == os.getuid() and len(affinity)<=8 and affinity & cpus:
            overlap.append(int(proc.name))
    except OSError: pass
assert not overlap, ('Do not overlap pinned producers', overlap)
mem = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
assert mem >= 256*2**20
os.sched_setaffinity(0,cpus)
resource.setrlimit(resource.RLIMIT_AS,(16*2**30,16*2**30))
out = O/'classes'; out.mkdir()
classpath = str(classes_base)+':'+':'.join(cfg['classpath'])
argv=[cfg['java'],'-Xmx8G','-Xss8M','-XX:ActiveProcessorCount=2',
    '-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',classpath,
    '-Xplugin:'+cfg['plugin'],'-d',str(out),str(source)]
with (O/'compile.log').open('xb') as log:
    child=subprocess.Popen(argv,cwd=O,stdout=log,stderr=subprocess.STDOUT,
        env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
    save(O/'launch.json',dict(utc=now(),controller=identity(),child=identity(child.pid),argv=argv,
        source_pin=sha(pinpath),cpus=sorted(cpus),memory_limit_gib=16,no_CAD=True,no_FPGA=True))
    rc=child.wait()
assert rc == 0, ('Compile failed; retain evidence',rc)
assert (out/'boom/lsu/BoomNonBlockingDCache.class').exists()
assert all(sha(p)==h for p,h in pins['files'].items())
save(O/'result.json',dict(utc=now(),status='PASS_EXACT3656_SOURCE_REVERSAL_AND_COMPLETE_DCACHE_TYPECHECK_ONLY',
    source_pin=sha(pinpath),log_sha256=sha(O/'compile.log'),
    outputs={str(p):sha(p) for p in sorted(out.rglob('*.class'))},
    full_dcache_equivalence=False,area_saving_unknown=True,production_admission=False,
    no_CAD=True,no_board_io=True))
print('PASS_EXACT3656_SOURCE_REVERSAL_AND_COMPLETE_DCACHE_TYPECHECK_ONLY')
