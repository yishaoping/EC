#!/usr/bin/python3
from pathlib import Path
import hashlib,json,runpy,sys
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
p=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert p['area_equivalence_only'] and not p['fpga_access']
def sha(f):return hashlib.sha256(Path(f).read_bytes()).hexdigest()
assert sha(D/'build-logs/Opt4-fit-installed-image-proof-r1-20261111/result.json')==sha(C/'proof-evidence-r1/result.json')
for source,x in json.loads((C/'proof-evidence-r1/snapshot-manifest.json').read_text()).items():
 assert sha(source)==sha(x['copy'])==x['sha256']
sys.argv=[str(C/'controller.py'),'map']
runpy.run_path(str(C/'controller.py'),run_name='__main__')
