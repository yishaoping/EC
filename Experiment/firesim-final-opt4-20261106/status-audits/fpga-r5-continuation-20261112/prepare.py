#!/usr/bin/env python3
"""Prepare a separately bound continuation; never edit a live capsule."""
from pathlib import Path
import hashlib
import json
import py_compile
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OLD = W/'candidates/svb-host40-shell-recovery-r4-20261112'
C = W/'candidates/svb-host40-shell-recovery-r5-20261112'
HERE = Path(__file__).resolve().parent

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for chunk in iter(lambda: f.read(4*1024*1024), b''):
            h.update(chunk)
    return h.hexdigest()

def save(p, x):
    Path(p).write_text(json.dumps(x, indent=2, sort_keys=True)+'\n')

def main():
    assert not C.exists(), 'adopt existing preparation'
    C.mkdir()
    names = ['application.py', 'runtime.py', 'certificate.py', 'audit.tcl.in',
             'recover.tcl.in', 'shell-nets.tcl', 'physical-clock-contract.json',
             'hostclock-interface-audit.json']
    replacements = {
        'svb-host40-shell-recovery-r4-20261112': 'svb-host40-shell-recovery-r5-20261112',
        'svb-host40-shell-onboard-r4-20261112': 'svb-host40-shell-onboard-r5-20261112',
        'svb-host40-shell-application-onboard-r4-20261112': 'svb-host40-shell-application-onboard-r5-20261112',
        'HOST40_R4_PHYSICAL_FAILURE_PRESERVED_NO_DEPLOYMENT': 'HOST40_R5_PHYSICAL_FAILURE_PRESERVED_NO_DEPLOYMENT',
    }
    for name in names:
        code = (OLD/name).read_text()
        if name in ['application.py', 'runtime.py']:
            for a,b in replacements.items():
                code = code.replace(a,b)
        if name == 'runtime.py':
            marker = "'cycleprecise-original-svb-host40-onboard-r1-20261112']:"
            extra = ','.join(repr('cycleprecise-original-svb-host40-shell-onboard-'+v+'-20261112') for v in ['r2','r3','r4'])
            assert code.count(marker) == 1
            code = code.replace(marker, "'cycleprecise-original-svb-host40-onboard-r1-20261112',"+extra+']:')
        if name == 'application.py':
            marker = "'cycleprecise-original-svb-host40-application-onboard-r1-20261112']:"
            extra = ','.join(repr('cycleprecise-original-svb-host40-shell-application-onboard-'+v+'-20261112') for v in ['r2','r3','r4'])
            assert code.count(marker) == 1
            code = code.replace(marker, "'cycleprecise-original-svb-host40-application-onboard-r1-20261112',"+extra+']:')
        (C/name).write_text(code)
    code = (OLD/'controller.py').read_text()
    code = code.replace('"""Measured same-slot continuation: original sealedA finalDCP then B/C/D, no target edits."""',
                        '"""Private best routed DCP: pre-route shell replication then fanout repair; no RTL edits."""')
    code = code.replace("OUT=D/'cycleprecise-svb-host40-shell-recovery-r4-20261112'",
                        "OUT=D/'cycleprecise-svb-host40-shell-recovery-r5-20261112'\nPREVIOUS=D/'cycleprecise-svb-host40-shell-recovery-r4-20261112'")
    code = code.replace("'ec-original-svb-host40-shell-recovery/4'", "'ec-original-svb-host40-shell-recovery/5'")
    start = code.index('def workers():')
    end = code.index('\n\ndef admitted():',start)
    code = code[:start]+'''def workers():
    rows=[]
    # Count actual Vivado executables in component services, including any
    # already owned recovery. Waiting Python processes consume no CAD slot.
    for cg in Path('/sys/fs/cgroup/systemd/system.slice').glob('*svb*.service'):
        if not (cg/'cgroup.procs').is_file():continue
        for pid in set(int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()):
            try:
                argv=(Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\\0')
                if argv and argv[0].decode().endswith('/unwrapped/lnx64.o/vivado'):
                    rows.append(dict(unit=cg.name,**identity(pid),argv=[x.decode() for x in argv if x]))
            except FileNotFoundError:pass
    return rows
'''+code[end:]
    start = code.index("    if mode=='B-shell-FD-replicate':")
    end = code.index("    periods=",start)
    strategy = '''    if mode=='E-preroute-shell-replication':
        strategy='''+repr('''if {![llength $observed_nets] || [llength $observed_nets]>32} {error "bounded shell Q selection failed"}
route_design -unroute
phys_opt_design -force_replication_on_nets $observed_nets
''')+'''
    elif mode=='F-preroute-fanout-placement-routing':
        strategy='''+repr('''route_design -unroute
phys_opt_design -fanout_opt -placement_opt -routing_opt
''')+'''
    else:raise AssertionError('unapproved physical strategy')
'''
    code = code[:start]+strategy+code[end:]
    start = code.index('def predecessor_failed_exited_empty():')
    end = code.index('\n\ndef best_checkpoint():',start)
    code = code[:start]+'''def predecessor_failed_exited_empty():
    state=read(PREVIOUS/'state.json')
    assert state.get('status')=='BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
    assert not live(state) and not live(state.get('child',{}))
    unit='ec-opt4-svb-host40-shell-physical-r4.service'
    props=dict(x.split('=',1) for x in subprocess.check_output(['systemctl','show',unit,'-p','MainPID','-p','ActiveState','-p','ControlGroup'],text=True).splitlines() if '=' in x)
    if props.get('MainPID')!='0' or props.get('ActiveState') not in ['inactive','failed']:return False
    cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
    return not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))
'''+code[end:]
    code = code.replace("roots=[D/'cycleprecise-svb-host40-shell-recovery-r2-20261112',OUT]",
                        "roots=[D/'cycleprecise-svb-host40-shell-recovery-r2-20261112',PREVIOUS,OUT]")
    code = code.replace("lock=(OUT/'extra-component-slot.lock').open('a')", "lock=(PREVIOUS/'extra-component-slot.lock').open('a')")
    code = code.replace("for mode in ['B-shell-FD-replicate','C-postroute-clock-skew','D-shell-critical-shortest-route']:",
                        "for mode in ['E-preroute-shell-replication','F-preroute-fanout-placement-routing']:")
    (C/'controller.py').write_text(code)
    # Independent validation/install, no predecessor process is signalled.
    install = '''#!/usr/bin/python3
import os,sys,subprocess
from pathlib import Path
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now,live

def validate():
    for name in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        p=read(C/name)
        assert p['board_allowlist']==['0000:21:00.0']
        for path,h in p['files'].items():assert sha(path)==h,('input changed',path)
    for name in ['runtime.py','application.py']:
        subprocess.run(['/usr/bin/python3',str(C/name),'--offline'],check=True,cwd=W)
    s=read(D/'cycleprecise-svb-host40-shell-recovery-r4-20261112/state.json')
    assert s['status']=='BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
    assert not live(s) and not live(s.get('child',{}))
    unit='ec-opt4-svb-host40-shell-physical-r4.service'
    assert subprocess.check_output(['systemctl','show',unit,'-p','MainPID','--value'],text=True).strip()=='0'
    cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
    assert not cg.exists() or not any(p.read_text().strip() for p in cg.rglob('cgroup.procs'))

def main():
    validate()
    if '--validate-only' in sys.argv:return
    assert os.geteuid()==0 and not (C/'installation.json').exists(),'adopt installed r5'
    units={}
    for role,script,user,memory,cpus,output in [
      ('physical','controller.py','guozh','64G','224 225','cycleprecise-svb-host40-shell-recovery-r5-20261112'),
      ('follow','runtime.py','root','32G','236 237','cycleprecise-original-svb-host40-shell-onboard-r5-20261112'),
      ('application-follow','application.py','root','4G','238 239','cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112')]:
        unit='ec-opt4-svb-host40-shell-'+role+'-r5.service'
        out=D/output;out.mkdir(exist_ok=True)
        assert not (out/'state.json').exists(),'adopt existing state'
        if user=='guozh':os.chown(out,1008,1008)
        text=f"""[Unit]
Description=Original SVB host40 private preroute continuation {role} r5
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User={user}
Group={user}
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C/script}
Environment=PYTHONPATH={W/'scripts'}
Nice=10
CPUQuota=200%
AllowedCPUs={cpus}
MemoryMax={memory}
TasksMax=512
Restart=no
KillMode=process
StandardOutput=append:{out/'service.log'}
StandardError=append:{out/'service.log'}
[Install]
WantedBy=multi-user.target
"""
        path=Path('/etc/systemd/system')/unit
        assert not path.exists(),'preserve existing unit'
        path.write_text(text);units[unit]=sha(path)
    save(C/'installation.json',dict(status='INDEPENDENT_R5_INSTALLED_FROM_COMPLETED_R4_NO_SIGNALS',utc=now(),units=units,fpga_io=False,cad_signalled=False))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',*units],check=True)

if __name__=='__main__':main()
'''
    (C/'install.py').write_text(install)
    # The Tcl gate tail and independent audit/certificate are inherited exactly.
    assert (C/'recover.tcl.in').read_bytes()==(OLD/'recover.tcl.in').read_bytes()
    assert (C/'audit.tcl.in').read_bytes()==(OLD/'audit.tcl.in').read_bytes()
    assert (C/'certificate.py').read_bytes()==(OLD/'certificate.py').read_bytes()
    for path in C.glob('*.py'):
        py_compile.compile(str(path), doraise=True)
    files = dict(json.loads((OLD/'inputs.json').read_text())['files'])
    for p in [OLD/'inputs.json',
              D/'status-audits/round122-r4-failure-closure-20261112/repair-plan.json',
              D/'status-audits/round122-r4-failure-closure-20261112/recover-preroute-replication.tcl.in']:
        files[str(p)] = sha(p)
    for n in ['B-shell-FD-replicate','C-postroute-clock-skew','D-shell-critical-shortest-route']:
        p=D/'cycleprecise-svb-host40-shell-recovery-r4-20261112'/n/'result.json'
        files[str(p)]=sha(p)
    p=D/'cycleprecise-svb-host40-shell-recovery-r4-20261112/C-postroute-clock-skew/final.dcp'
    files[str(p)]=sha(p)
    for p in C.iterdir():
        if p.is_file():files[str(p)]=sha(p)
    base={k:v for k,v in json.loads((OLD/'inputs.json').read_text()).items() if k!='files'}
    base['schema']='ec-original-svb-host40-shell-bound-inputs/5'
    for name in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        save(C/name,dict(base,files=dict(files)))
        files[str(C/name)]=sha(C/name)
    subprocess.run(['/usr/bin/python3',str(C/'install.py'),'--validate-only'],check=True,cwd=W)
    save(HERE/'preparation.json',dict(status='BOUND_OFFLINE_VALIDATED_NOT_YET_INSTALLED',
        candidate=str(C),source_sha256={str(p):sha(p) for p in C.iterdir() if p.is_file()},
        strict_tcl_gate_unchanged=True,independent_certificate_unchanged=True,
        actual_tool_support_pending=True,fpga_access=False,process_signals=[]))

if __name__=='__main__':main()
