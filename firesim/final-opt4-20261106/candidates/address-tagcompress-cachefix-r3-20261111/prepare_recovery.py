#!/usr/bin/python3
"""Freeze isolated ccache recovery; retain prior failure without modifying it."""
from pathlib import Path
import ast,hashlib,json,os,shutil,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106'); D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106'); U=D/'unattended-opt4'
C=Path(__file__).resolve().parent; OLD=W/'candidates/address-tagcompress-r1-20261111'; O=D/'build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def write(p,v):
 p=Path(p); p.parent.mkdir(parents=True,exist_ok=True); data=(json.dumps(v,indent=2,sort_keys=True)+'\n').encode()
 if p.exists():assert p.read_bytes()==data; return
 q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def main():
 ast.parse((C/'controller.py').read_text());ast.parse(Path(__file__).read_text())
 inputs=json.loads((OLD/'input-hashes.json').read_text());assert all(sha(p)==h for p,h in inputs.items())
 failure=D/'build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/boundary-compile-attempt-1.log'
 assert 'ccache: error: Failed to write to' in failure.read_text()
 paths=[OLD/'input-hashes.json',failure,D/'Opt4-fit-address-tagcompress-r1-state.json',U/'jobs/address-tagcompress-r1-bind2-3fb8a7f7/state.json']
 paths += [U/'jobs/address-tagcompress-cachefix-r2-3fb8a7f7/state.json',U/'jobs/address-tagcompress-cachefix-r2-3fb8a7f7/console.log']
 paths += [p for p in C.iterdir() if p.is_file() and p.name!='input-hashes.json']
 inputs.update({str(p):sha(p) for p in paths}); write(C/'input-hashes.json',inputs)
 cfg=json.loads((C/'config.json').read_text()); b=cfg['binding']; F=Path(cfg['worktree'])
 direct={p:h for p,h in inputs.items() if Path(p).resolve().is_relative_to(W)};direct[str(C/'input-hashes.json')]=sha(C/'input-hashes.json')
 memory=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))/2**20; disk=shutil.disk_usage(W).free/2**30
 assert memory>=48 and disk>=40
 name='address-tagcompress-cachefix-r3-'+b['hardware_commit'][:8]
 req=dict(action='cpu_job',spec=dict(name=name,kind='module',cwd=str(F/'chipyard'),argv=['/usr/bin/python3',str(C/'controller.py')],inputs=direct,outputs=[str(O/'result.json'),str(O/'verified-local.json')],checkpoints=[str(D/'Opt4-fit-address-tagcompress-cachefix-r3-state.json'),str(O/'verified-local.json')]))
 report=dict(schema='ec-opt4-tagcompress-cache-recovery/1',hardware_commit=b['hardware_commit'],source_id=b['source_id'],reason='First failure is ccache statistics write failure. No RTL or proof failure is inferred.',fix='Separate versioned controller disables ccache and binds private cache/temp under D. Fresh isolated outputs preserve original failure.',controller_sha256=sha(C/'controller.py'),manifest_sha256=sha(C/'input-hashes.json'),available_memory_gib=memory,free_disk_gib=disk,fpga_access=False)
 write(O/'recovery-preflight.json',report)
 if '--submit' in sys.argv:write(U/'requests'/(name+'.json'),req)
 print(json.dumps(report))
if __name__=='__main__':main()
