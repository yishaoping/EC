#!/usr/bin/env python3
"""Native host-only observer restart adapter; exact bridge sequence retained."""
import datetime as dt,difflib,json,shlex,shutil,subprocess,time
from pathlib import Path
from board_batch import W,D,sha

parent=W/'runtime/Native-observed-driver.json';r=json.loads(parent.read_text());old=Path(r['output_dir'])
assert r['returncode']==0
for p,h in r['outputs'].items():assert sha(p)==h
stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=W/'builds'/('Native-restart-driver-'+stamp);logs=D/'build-logs'/out.name
shutil.copytree(old,out);logs.mkdir();src=out/'restart-host-sources';src.mkdir()
original=Path(r['parent_receipt']);buildlog=(original.parent/'build.log').read_text().splitlines()
compile_line=next(x for x in buildlog if x.startswith('/usr/bin/g++ ') and x.endswith('/ec_dac_roi.cc') and ' -c ' in x)
argv=shlex.split(compile_line);source=Path(argv[-1]);header=source.with_suffix('.h');patch=[]
(src/header.name).write_bytes(header.read_bytes())  # Preserve C++ object ABI.
before=source.read_text();after=before.replace('char ec_dac_roi_t::KIND;', 'static uint64_t sequence_origin = 0;\nstatic bool first_record = true;\nchar ec_dac_roi_t::KIND;').replace('<< v[0]\n', '<< (v[0] - sequence_origin)\n       << ",\\\"bridge_sequence\\\":" << v[0] << ",\\\"sequence_origin\\\":" << sequence_origin\n')
anchor='    if (values[0] != expected_sequence)'
addition='''    if (first_record) {
      sequence_origin = values[0];
      expected_sequence = values[0];
      first_record = false;
    }
'''
assert anchor in after and 'bridge_sequence' in after;after=after.replace(anchor,addition+anchor)
(src/source.name).write_text(after);patch.extend(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(source),tofile=str(src/source.name)))
argv=[a.replace(str(Path(json.loads(original.read_text())['output_dir'])),str(out)) for a in argv];argv[-1]=str(src/source.name);argv[1:1]=['-I'+str(source.parent)]
link=[a.replace(str(old),str(out)) for a in r['commands'][-1]];commands=[argv,link]
start=time.monotonic()
with (logs/'build.log').open('wb',buffering=0) as f:
 for command in commands:subprocess.run(['nice','-n','15',*command],stdout=f,stderr=subprocess.STDOUT,check=True,timeout=180)
(logs/'host-only.patch').write_text(''.join(patch));exe=out/'FireSim-xilinx_alveo_u280'
rr={**r,'output_dir':str(out),'outputs':{str(exe):sha(exe)},'parent_receipt':str(parent),'parent_receipt_sha256':sha(parent),'commands':commands,'patch':str(logs/'host-only.patch'),'patch_sha256':sha(logs/'host-only.patch'),'supports_target_restart':True,'restart_runtime_validation':'NOT_RUN','restart_protocol':'Retain absolute bridge sequence, normalize per driver stream, require a fresh target reset before any valid ROI; no DUT edits','wall_seconds':time.monotonic()-start}
(logs/'result.json').write_text(json.dumps(rr,indent=2)+'\n');(W/'runtime/Native-restart-driver.json').write_text(json.dumps(rr,indent=2)+'\n');print(logs/'result.json')
