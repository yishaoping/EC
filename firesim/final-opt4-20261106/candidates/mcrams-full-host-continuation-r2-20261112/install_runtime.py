#!/usr/bin/python3
"""Immutable independent root follower. Starts runtime only after real gates."""
import argparse,fcntl,hashlib,json,os,pathlib,subprocess,time
C=pathlib.Path(__file__).resolve().parent;W=C.parent.parent
D=pathlib.Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');R=W/'runtime/Opt4-fit-mcrams-owner-r1'
UNIT='ec-opt4-mcrams-owner-runtime-follow-r1'
def read(p):return json.loads(pathlib.Path(p).read_text())
def sha(p):return hashlib.sha256(pathlib.Path(p).read_bytes()).hexdigest()
def units():
 return f'''[Unit]
Description=Composite MCRams strict21-only runtime after actual physical certification
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/install_runtime.py --follow
Restart=on-failure
RestartSec=300
KillMode=process
StandardOutput=append:{D}/mcrams-owner-runtime-follow.log
StandardError=append:{D}/mcrams-owner-runtime-follow.log
[Install]
WantedBy=multi-user.target
'''
def verify():
 b=read(C/'runtime-installer-binding.json');assert b['board_bdf']=='0000:21:00.0'
 for p,h in b['immutable_inputs'].items():assert sha(p)==h,'immutable runtime entry changed: '+p
 bundle=read(R/'bundle.json');assert all(sha(p)==h for p,h in bundle['scripts'].items())
 assert sha(R/'software-suite.json')==bundle['software_suite_sha256']
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--validate-only',action='store_true');ap.add_argument('--follow',action='store_true');a=ap.parse_args();verify()
 if a.validate_only:print('PASS_IMMUTABLE_COMPOSITE21_ONLY_RUNTIME_FOLLOWER');return
 assert os.geteuid()==0
 if not a.follow:
  p=pathlib.Path('/etc/systemd/system')/(UNIT+'.service');text=units()
  if p.exists():assert p.read_text()==text
  else:p.write_text(text)
  subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',UNIT+'.service'],check=True);return
 lock=(D/'locks/mcrams-owner-runtime-follow-r1.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 sysdir=R/'scripts';import sys;sys.path.insert(0,str(sysdir));sys.path.insert(1,str(W/'scripts'))
 from prepare_opt4_fit_runtime import certify
 while True:
  verify();p=D/'Opt4-mcrams-shell-physical-r2-state.json';s=read(p) if p.exists() else {}
  if s.get('status')=='PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION':
   certify()
   # Existing common runtime lock and card/maintenance locks prevent duplicate
   # occupancy. Native remains paused and no live process is terminated.
   while True:
    g=(D/'locks/opt4-fit-runtime.lock').open('a')
    try:fcntl.flock(g,fcntl.LOCK_EX|fcntl.LOCK_NB);fcntl.flock(g,fcntl.LOCK_UN);g.close();break
    except BlockingIOError:g.close();time.sleep(300)
   os.execv('/usr/bin/python3',['/usr/bin/python3',str(sysdir/'continue_opt4_fit.py')])
  time.sleep(300)
if __name__=='__main__':main()
