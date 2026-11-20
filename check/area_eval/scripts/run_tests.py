#!/usr/bin/env python3
from pathlib import Path
import subprocess,json,hashlib,datetime
ROOT=Path(__file__).resolve().parents[1]
commands=[['verilator','--lint-only','-Wno-MULTITOP','rtl/palimpsest.sv']]
for test in ['stateful','store']:
 commands += [['iverilog','-g2012','-s','tb_'+test,'-o',f'results/tb_{test}.vvp','rtl/palimpsest.sv',f'tests/tb_{test}.sv'],['vvp',f'results/tb_{test}.vvp']]
commands += [['python3','tests/test_combinational.py']]
commands += [['python3','tests/test_protocol_random.py']]
results=[]
for n,cmd in enumerate(commands):
 r=subprocess.run(cmd,cwd=ROOT,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,timeout=60)
 (ROOT/f'results/test-{n}.log').write_text(r.stdout)
 results.append({'command':cmd,'returncode':r.returncode,'log':f'results/test-{n}.log'})
 if r.returncode: print(r.stdout); raise SystemExit(r.returncode)
 if r.stdout:print(r.stdout.strip())
(ROOT/'results/tests.json').write_text(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'rtl_sha256':hashlib.sha256((ROOT/'rtl/palimpsest.sv').read_bytes()).hexdigest(),'status':'PASS','runs':results},indent=2)+'\n')
