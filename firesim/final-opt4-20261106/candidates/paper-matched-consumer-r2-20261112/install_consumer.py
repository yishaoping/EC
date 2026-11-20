#!/usr/bin/python3
from pathlib import Path
import fcntl,hashlib,json,os,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent
sys.path.insert(0,str(W/'scripts'));from opt4_unattended_common import read,save,sha
UNIT='ec-paper-matched-source-cpu-consumer-r2-20261112.service';O=D/'paper-matched-source-cpu-comparison-r2-20261112'
def main():
 assert os.geteuid()==0
 lock=(C/'consumer-install.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (C/'consumer-launch-receipt.json').exists() and not (O/'complete.json').exists()
 assert read(O/'canneal_project400/complete.json')['result_sha256']==sha(O/'canneal_project400/result.json')
 assert (O/'canneal_project400/roi-cycles.pdf').is_file() and (O/'canneal_project400/roi-cycles.svg').is_file()
 expected=read(C/'consumer-preflight.json');assert sha(C/'matched_consumer.py')==expected['consumer_sha256'] and expected['status']=='PASS_CONSUMER_STATIC_AUDIT_NO_NEW_MODEL'
 for p,h in expected['bound_inputs'].items():assert sha(p)==h,p
 policy=read(D/'unattended-opt4/campaign-policy.json');assert policy['native_paused'] and policy['board_allowlist']==['0000:21:00.0']
 text=f'''[Unit]
Description=Read-only audit and export of completed matched CPU GoldenGate samples
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/data1/gzh/EC/chipyard/.conda-env/bin/python3 {C}/matched_consumer.py
Nice=15
CPUQuota=100%
TasksMax=32
Restart=on-failure
RestartSec=60
KillMode=process
StandardOutput=append:{C}/consumer-service.log
StandardError=append:{C}/consumer-service.log
[Install]
WantedBy=multi-user.target
'''
 target=Path('/etc/systemd/system')/UNIT
 if target.exists():assert target.read_text()==text
 else:target.write_text(text)
 subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',UNIT],check=True,capture_output=True)
 save(C/'consumer-launch-receipt.json',dict(status='STARTED_READ_ONLY_PERSISTENT_CONSUMER',unit=UNIT,consumer_sha256=sha(C/'matched_consumer.py'),preflight_sha256=sha(C/'consumer-preflight.json'),fpga_access=False,new_model_or_cad=False));print((C/'consumer-launch-receipt.json').read_text())
if __name__=='__main__':main()
