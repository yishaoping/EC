#!/usr/bin/python3
"""Validate/render or idempotently install one independent five-minute timer."""
import argparse,hashlib,json,os,pathlib,subprocess
C=pathlib.Path(__file__).resolve().parent
D=pathlib.Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
UNIT='ec-opt4-owner-runtime-r1-dispatch'
def sha(p):return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()
def units(binding_sha):
 service=f'''[Unit]
Description=Submit unique owner-only same-target runtime after existing compile
After=local-fs.target
RequiresMountsFor={C} {D}
[Service]
Type=oneshot
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/dispatch.py --binding-sha {binding_sha}
TimeoutStartSec=120
CPUQuota=100%
MemoryMax=1G
Nice=15
NoNewPrivileges=true
PrivateDevices=true
DevicePolicy=closed
CapabilityBoundingSet=
ProtectKernelTunables=true
ProtectKernelModules=true
ProtectControlGroups=true
RestrictSUIDSGID=true
LockPersonality=true
StandardOutput=append:{D}/owner-runtime-r1-dispatch.log
StandardError=append:{D}/owner-runtime-r1-dispatch.log
'''
 timer=f'''[Unit]
Description=Check version-bound owner paired runtime prerequisites every five minutes
[Timer]
OnBootSec=60s
OnUnitInactiveSec=300s
Persistent=true
AccuracySec=20s
Unit={UNIT}.service
[Install]
WantedBy=timers.target
'''
 return service,timer
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--validate-only',action='store_true');a=ap.parse_args()
 manifest=C/'timer-input-binding.json';binding=json.loads(manifest.read_text());digest=sha(manifest)
 for name,h in binding['immutable_inputs'].items():assert sha(name)==h,'immutable input mismatch: '+name
 assert binding['immutable_inputs'][str(C/'install_timer.py')]==sha(__file__)
 service,timer=units(digest);render=C/'rendered-units';render.mkdir(exist_ok=True)
 for suffix,text in [('service',service),('timer',timer)]:
  p=render/(UNIT+'.'+suffix)
  if p.exists():assert p.read_text()==text,'preserve different rendered version'
  else:p.write_text(text)
 subprocess.run(['systemd-analyze','verify',str(render/(UNIT+'.service')),str(render/(UNIT+'.timer'))],check=True)
 subprocess.run(['/usr/bin/python3',str(C/'dispatch.py'),'--binding-sha',digest,'--verify-only'],check=True)
 if a.validate_only:print('VALIDATED '+UNIT+'.timer');return
 assert os.geteuid()==0,'root installs the system service; validation needs no privilege'
 for suffix,text in [('service',service),('timer',timer)]:
  p=pathlib.Path('/etc/systemd/system')/(UNIT+'.'+suffix)
  if p.exists():assert p.read_text()==text,'independent existing unit differs; preserve it'
  else:
   with p.open('x') as f:f.write(text);f.flush();os.fsync(f.fileno())
   os.chmod(p,0o644)
 subprocess.run(['systemctl','daemon-reload'],check=True)
 subprocess.run(['systemctl','enable','--now',UNIT+'.timer'],check=True)
 subprocess.run(['systemctl','start',UNIT+'.service'],check=True)
 print(UNIT+'.timer')
if __name__=='__main__':main()
