from pathlib import Path
import difflib, json, hashlib, subprocess
root=Path(__file__).resolve().parents[2]; d=Path(__file__).resolve().parent
out=[]; info=[]; preserved=[]
for b in sorted((d/'before').rglob('*.scala')):
 rel=b.relative_to(d/'before'); p=root/'chipyard/generators'/rel
 before=b.read_text(); after=p.read_text()
 if before!=after:
  delta=list(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile='before/'+str(rel),tofile='after/'+str(rel)))
  out+=delta
  info.append({'file':str(rel),'added':sum(x.startswith('+') and not x.startswith('+++') for x in delta),'removed':sum(x.startswith('-') and not x.startswith('---') for x in delta),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()})
 else: preserved.append(str(rel))
(d/'task-only.diff').write_text(''.join(out));(d/'source-manifest.json').write_text(json.dumps(info,indent=2)+'\n')
prior=(d/'before.diff').read_text(); cur=subprocess.check_output(['git','diff'],cwd=root,text=True)
def chunks(s):return {part.split('\n',1)[0]:part for part in s.split('diff --git ')[1:]}
pc=chunks(prior);cc=chunks(cur)
saved={'a/chipyard/generators/'+str(b.relative_to(d/'before'))+' b/chipyard/generators/'+str(b.relative_to(d/'before')) for b in (d/'before').rglob('*.scala')}
for name,part in pc.items():
 if name not in saved:
  assert cc.get(name)==part,'unexpected diff changed: '+name
  preserved.append(name)
subprocess.run(['git','diff','--check','--','chipyard/generators'],cwd=root,check=True)
print('PASS: task-only diff, source hashes, existing edits and whitespace checked')
print('Task changed files:',len(info));print('Task added/deleted:',sum(x['added'] for x in info),sum(x['removed'] for x in info))
for x in preserved:print('PRESERVED',x)
