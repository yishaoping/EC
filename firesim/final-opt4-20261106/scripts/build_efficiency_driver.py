#!/usr/bin/env python3
"""Host-only per-invocation emulation counters; preserves C++ object layout."""
import datetime as dt,difflib,json,shlex,shutil,subprocess,sys,time
from pathlib import Path
from board_batch import W,D,sha

cfg=sys.argv[1];assert cfg in ['Native','C4']
parent=W/'runtime'/(cfg+('-restart-driver.json' if cfg=='Native' else '-observed-driver.json'));r=json.loads(parent.read_text());old=Path(r['output_dir'])
assert r['returncode']==0
for p,h in r['outputs'].items():assert sha(p)==h
original=Path(json.loads((W/'native-reuse.json').read_text())['driver_receipt']) if cfg=='Native' else D/'build-logs/C4-driver-20261106T104028.658367Z/result.json'
base=json.loads(original.read_text());lines=(original.parent/'build.log').read_text().splitlines()
argv=shlex.split(next(l for l in lines if l.startswith('/usr/bin/g++ ') and l.endswith('/simulation.cc') and ' -c ' in l));source=Path(argv[-1]);before=source.read_text()
after=before.replace('simulation_t::simulation_t(', 'static uint64_t ec_invocation_tcycle_start = 0;\n\nsimulation_t::simulation_t(',1)
after=after.replace('  start_hcycle = clock.hcycle();','  ec_invocation_tcycle_start = clock.tcycle();\n  start_hcycle = clock.hcycle();',1)
anchor='  const double sim_time = diff_secs(end_time, start_time);'
addition='''
  fprintf(stderr, "EC_HOST_INTERVAL target_start=%" PRIu64 " target_end=%" PRIu64 " target_delta=%" PRIu64 " host_delta=%" PRIu64 " wall_seconds=%.9f throughput_cycles_per_second=%.3f\\n",
          ec_invocation_tcycle_start, end_tcycle, end_tcycle-ec_invocation_tcycle_start,
          hcycles, sim_time, (end_tcycle-ec_invocation_tcycle_start)/sim_time);
'''
assert anchor in after;after=after.replace(anchor,anchor+addition)
stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'builds'/(cfg+'-efficiency-driver-'+stamp);logs=D/'build-logs'/out.name
shutil.copytree(old,out);logs.mkdir();src=out/'efficiency-host-sources';src.mkdir();dest=src/'simulation.cc';dest.write_text(after)
argv=[a.replace(base['output_dir'],str(out)) for a in argv];argv[-1]=str(dest);argv[1:1]=['-I'+str(source.parent)]
commands=[argv,[a.replace(str(old),str(out)) for a in r['commands'][-1]]];start=time.monotonic()
with (logs/'build.log').open('wb',buffering=0) as f:
 for command in commands:subprocess.run(['nice','-n','15',*command],stdout=f,stderr=subprocess.STDOUT,check=True,timeout=180)
(logs/'host-only.patch').write_text(''.join(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(source),tofile=str(dest))));exe=out/'FireSim-xilinx_alveo_u280'
rr={**r,'output_dir':str(out),'outputs':{str(exe):sha(exe)},'parent_receipt':str(logs/'parent-receipt.json'),'parent_receipt_sha256':sha(parent),'commands':commands,'patch':str(logs/'host-only.patch'),'patch_sha256':sha(logs/'host-only.patch'),'efficiency_counter_scope':'per driver invocation; target_delta excludes earlier invocations; host-only metrics never architecture slowdown','wall_seconds':time.monotonic()-start}
(logs/'parent-receipt.json').write_bytes(parent.read_bytes());(logs/'result.json').write_text(json.dumps(rr,indent=2)+'\n');(W/'runtime'/(cfg+'-efficiency-driver.json')).write_text(json.dumps(rr,indent=2)+'\n');print(logs/'result.json')
