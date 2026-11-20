#!/usr/bin/env python3
"""Run bounded evaluation stages; abort on first failure; no original edits."""
from pathlib import Path
import subprocess,json,datetime
root=Path(__file__).resolve().parents[1]
commands=[['python3','scripts/'+s] for s in ['audit_baseline.py','run_tests.py','synthesize_baseline.py','synthesize.py','estimate_area.py']]
log=[]
for cmd in commands:
 print('+ '+' '.join(cmd),flush=True)
 r=subprocess.run(cmd,cwd=root)
 log.append({'command':cmd,'returncode':r.returncode})
 if r.returncode:raise SystemExit(r.returncode)
(root/'results/reproduction.json').write_text(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'commands':log},indent=2)+'\n')
