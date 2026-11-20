from pathlib import Path
import sys,json,subprocess,datetime
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from board_batch import D,precheck,save
from job_service import inspect,proc
out=D/'safety/21-only-20261109'
value={'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'precheck':precheck(target_bdfs=['0000:21:00.0']),
       'protected_processes':{str(pid):proc(pid) for pid in [13544,13546,5257]},
       'units':{}}
for name in ['coverage-first','native','c4-first','c4-suite','cad']:
 unit='ec-parsec-'+name+'.service'
 value['units'][name]={'state_audit':inspect(D/'jobs'/name/'state.json'),'systemd':subprocess.check_output(['systemctl','show',unit,'-p','MainPID','-p','ControlGroup','-p','ActiveState','-p','SubState'],text=True)}
 cg=next(x.split('=',1)[1] for x in value['units'][name]['systemd'].splitlines() if x.startswith('ControlGroup='))
 group=Path('/sys/fs/cgroup/systemd')/cg.lstrip('/')
 pidfile=group/'cgroup.procs'
 if not pidfile.exists():pidfile=Path('/sys/fs/cgroup')/cg.lstrip('/')/'cgroup.procs'
 value['units'][name]['cgroup_processes']=[proc(int(x)) for x in pidfile.read_text().split()] if pidfile.exists() else []
save(out/'root-preflight.json',value)
print(json.dumps(value,indent=2))
