#!/usr/bin/python3
import importlib.util,os,sys,subprocess
from pathlib import Path
C=Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-host40-shell-recovery-r6-20261112')
DRIVER=Path(__file__).resolve()
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
AUDIT=D/'status-audits/round133-r6-minimal-api-recovery-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now,live

def validate():
    pins=read(DRIVER.parent/'inputs.json')
    assert pins['candidate']==str(C)
    for path,h in pins['files'].items():assert sha(path)==h,('installer dependency changed',path)
    for name in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        p=read(C/name)
        assert p['board_allowlist']==['0000:21:00.0']
        for path,h in p['files'].items():assert sha(path)==h,('input changed',path)
    for name in ['runtime.py','application.py']:
        subprocess.run(['/usr/bin/python3',str(C/name),'--offline'],check=True,cwd=W)
    spec=importlib.util.spec_from_file_location('r6_controller',C/'controller.py')
    controller=importlib.util.module_from_spec(spec);spec.loader.exec_module(controller)
    controller.verify()
    assert controller.predecessor_failed_exited_empty()
    assert not (AUDIT/'repair-plan.json').exists(),'preserve existing round evidence'
    out=controller.OUT
    assert not (out/'state.json').exists() and not (out/'result.json').exists()
    for unit in ['ec-opt4-svb-host40-shell-physical-r6.service',
                 'ec-opt4-svb-host40-shell-follow-r6.service',
                 'ec-opt4-svb-host40-shell-application-follow-r6.service']:
        path=Path('/etc/systemd/system')/unit
        assert not path.exists(),('preserve pre-existing unit',unit)
    return controller

def main():
    controller=validate()
    if '--validate-only' in sys.argv:return
    assert os.geteuid()==0 and not (C/'installation.json').exists(),'adopt installed r6'
    units={}
    for role,script,user,memory,cpus,output in [
      ('physical','controller.py','guozh','64G','224 225','cycleprecise-svb-host40-shell-recovery-r6-20261112'),
      ('follow','runtime.py','root','32G','236 237','cycleprecise-original-svb-host40-shell-onboard-r6-20261112'),
      ('application-follow','application.py','root','4G','238 239','cycleprecise-original-svb-host40-shell-application-onboard-r6-20261112')]:
        unit='ec-opt4-svb-host40-shell-'+role+'-r6.service'
        out=D/output;out.mkdir(exist_ok=True)
        assert not (out/'state.json').exists(),'adopt existing state'
        if user=='guozh':os.chown(out,1008,1008)
        text=f"""[Unit]
Description=Original SVB host40 private preroute continuation {role} r6
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
    sources={n:sha(C/n) for n in ['controller.py','install.py','runtime.py','application.py','certificate.py','recover.tcl.in','physical-clock-contract.json','inputs.json','runtime-inputs.json','application-inputs.json','rebind_inputs.py']}
    save(C/'installation.json',dict(status='INDEPENDENT_R6_MINIMAL_VIVADO_API_REPAIR_INSTALLED_FROM_R5_F_CHECKPOINT',utc=now(),units_sha256=units,fpga_io=False,target_rtl_changed=False,physical_gates_changed=False,inputs_sha256=sha(C/'inputs.json'),candidate_sources=sources,installer_driver=dict(path=str(DRIVER),sha256=sha(DRIVER),revision='r2-explicit-controller-return')))
    AUDIT.mkdir(exist_ok=True)
    good,admission=controller.admitted()
    save(AUDIT/'repair-plan.json',dict(
        schema='ec-opt4-svb-r6-minimal-api-recovery/1',
        status='R6_INSTALLED_CONDITIONAL_ON_PINNED_RESOURCE_GUARD',utc=now(),
        source_id=controller.SID,functional_baseline=controller.BASE,profile=controller.PROFILE,
        predecessor_result=str(controller.FRESULT),predecessor_result_sha256=sha(controller.FRESULT),
        source_checkpoint=str(controller.FCHECKPOINT),source_checkpoint_sha256=sha(controller.FCHECKPOINT),
        repair='phys_opt_design -fanout_opt -placement_opt; standard route_design follows',
        rejected_option='-routing_opt in pre-route phys_opt_design (unsupported by Vivado 2021.1)',
        target_rtl_changed=False,physical_gates_changed=False,clock_constraints_changed=False,
        complete_opt4=False,fpga_access=False,board_allowlist=['0000:21:00.0'],
        resource_guard_met=good,resource_snapshot=admission,
        resource_limits=read(read(C/'inputs.json')['resource_admission'])['limits'],
        shared_slot_lock=str(controller.SLOTLOCK),unit_sha256=units,
        candidate_sources_sha256=sources,inputs_sha256=sha(C/'inputs.json')))
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',*units],check=True)

if __name__=='__main__':main()
