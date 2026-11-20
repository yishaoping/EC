from pathlib import Path
import json,hashlib,fcntl,os,datetime
from canonical import Cone,strip_comments,ASSIGN,WIRE,BARE
from diagnostic_metadata import source_locations
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'build-logs/Opt4-fit-field-read-residual-round31-v1-20261111'
S=D/'Opt4-fit-field-read-residual-round31-v1-state.json'
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def policy():
 p=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
 assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
policy()
L.mkdir(exist_ok=False)
lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
manifest=json.loads((C/'input-hashes.json').read_text());assert all(sha(p)==h for p,h in manifest.items())
prior=json.loads((C/'prior-result.json').read_text())
st=dict(schema='ec-opt4-residual-diagnosis/1',hardware_commit=prior['hardware_commit'],source_id=prior['source_id'],pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().rsplit(')',1)[1].split()[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),status='DIAGNOSING_RESIDUAL_MISMATCH',production_admission=False,fpga_access=False)
S.write_text(json.dumps(st,indent=2)+'\n')
cones={}
for label,row in prior['inputs'].items():
 policy();assert sha(row['path'])==row['sha256']
 text=Path(row['path']).read_text();start=text.index('\nmodule BoomNonBlockingDCache(')+1;end=text.index('\nendmodule',start)+len('\nendmodule')
 text=strip_comments(text[start:end])
 if label=='candidate':text,metadata=source_locations(text)
 cones[label]=Cone(text)
a=cones['parent'].residual();b=cones['candidate'].residual()
i=next((i for i,(x,y) in enumerate(zip(a,b)) if x!=y),min(len(a),len(b)))
j=0
while j<min(len(a)-i,len(b)-i) and a[-1-j]==b[-1-j]:j+=1
record=dict(first_difference=i,parent_length=len(a),candidate_length=len(b),common_suffix=j,parent=a[max(0,i-1000):i+2000],candidate=b[max(0,i-1000):i+2000],metadata_locations=len(metadata['changed_diagnostic_locations']))
# Look up expanded root digests around the first changed functional statement.
digest_roots={}
for label,cone in cones.items():
 near=(a if label=='parent' else b)[max(0,i-1000):i+2000]
 digest_roots[label]=[dict(name=n,expr=cone.defs[n],type=cone.types[n]) for n,h in cone.cache.items() if h in near and n in cone.defs][:60]
record['digest_roots']=digest_roots
(L/'first-difference.json').write_text(json.dumps(record,indent=2,sort_keys=True)+'\n')
st.update(status='COMPLETE_RESIDUAL_DIAGNOSIS_NO_ADMISSION',result=record,input_hashes=manifest,ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
S.write_text(json.dumps(st,indent=2,sort_keys=True)+'\n');(L/'result.json').write_text(json.dumps(st,indent=2,sort_keys=True)+'\n')
