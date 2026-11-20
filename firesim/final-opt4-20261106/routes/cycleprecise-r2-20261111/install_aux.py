#!/usr/bin/python3
import os, pathlib, subprocess, json, hashlib, sys
P=pathlib.Path;W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=P(__file__).resolve().parent
assert os.geteuid()==0
mem=int(next(s.split()[1] for s in P('/proc/meminfo').read_text().splitlines() if s.startswith('MemAvailable:')))
assert mem>256*2**20 and os.getloadavg()[0]<96
unit='ec-opt4-cycleprecise-metasim-r3.service';L=D/'cycleprecise-metasim-r3-20261111';L.mkdir(exist_ok=True);os.chown(L,1008,1008)
s=f'''[Unit]
Description=Opt4 Golden Gate same-target multi-cycle metasim (no FPGA)
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/metasim_recovery.py
Nice=15
CPUQuota=200%
MemoryMax=32G
TasksMax=512
Restart=no
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
p=P('/etc/systemd/system')/unit
if p.exists():assert p.read_text()==s
else:p.write_text(s)
subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',unit],check=True)

# One explicitly reviewed module-only exception: two counted campaign slots
# are pure waiting controllers. Never relabel module work as a proof or start
# a third whole. Keep the existing broker's exact immutable unit/spec format.
sys.path.insert(0,str(W/'scripts'))
import opt4_unattended_common as co
from opt4_frozen_scope import enforce
req=co.read(co.U/'requests/dcache-field-read-full-map-r2-3656aec4.json')['spec']
co.bound_inputs(req);enforce(req)
out=co.U/'jobs'/req['name'];out.mkdir(exist_ok=True);os.chown(out,1008,1008)
old=co.read(out/'state.json')
if co.live(old) or co.live(old.get('child',{})):
    print('ADOPT existing field-read map');sys.exit(0)
assert not old,'do not rerun a partial/failed/completed module'
spec=out/'spec.json'
if spec.exists():assert co.read(spec)==req
else:co.save(spec,req)
unit='ec-opt4-auto-'+req['name']+'.service';cwd=req['cwd']
s=f'''[Unit]
Description=Opt4 autonomous CPU job {req['name']}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={cwd}
ExecStart=/usr/bin/python3 {W}/scripts/opt4_unattended_cpu_job.py {spec}
Nice=10
TasksMax=1024
CPUQuota=3200%
Restart=no
KillMode=process
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
[Install]
WantedBy=multi-user.target
'''
p=P('/etc/systemd/system')/unit
if p.exists():assert p.read_text()==s
else:p.write_text(s)
drop=P('/etc/systemd/system')/(unit+'.d');drop.mkdir(exist_ok=True)
(drop/'reviewed-module-limit.conf').write_text('[Service]\nCPUQuota=200%\nMemoryMax=64G\nNice=15\n')
co.save(out/'resource-exception.json',dict(utc=co.now(),available_memory_gib=mem/2**20,load=os.getloadavg(),whole_cad_added=False,
   scope='Single already-proven full DCache module; waiting controllers consumed normal broker slots. Explicit resource-reviewed bounded module only; preserve all original jobs and proof/area gates.',cpu_limit=2,memory_max_gib=64))
subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',unit],check=True)
print('Started bounded metasim and authenticated field-read full-module area; no whole CAD/FPGA actions')
