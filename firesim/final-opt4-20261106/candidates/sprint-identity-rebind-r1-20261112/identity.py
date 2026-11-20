#!/usr/bin/python3
"""Offline ABI/runtime rebinding for the committed sprint host.

This tool never creates a certificate or changes the running root handoff.
The new bundle is offered to that owner only after exact ABI comparison.
"""
from pathlib import Path
import copy
import hashlib
import json
import os
import shutil
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
VALID=D/'build-logs/Opt4-sprint-composed-validate-r1-20261112'
ROOT=W/'Opt4-area-sprint-20261112'
PARENT=W/'runtime/Opt4-fit-mcrams-owner-r1'
R=W/'runtime/Opt4-fit-sprint-fd5de2ba-r1'
OUT=D/'build-logs/Opt4-sprint-identity-rebind-r1-20261112'
COMMIT='fd5de2bafb8f5d236dfe240fbecf3436f8c3468a'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
PROFILE='Opt4-fit-C4-SVB32-sprint-fd5de2ba-r1'
OLD_COMMIT='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
OLD_SOURCE='c8e5bfa5f0926ba127b39187dc86f3062ad5fe035173eeff36f94db9341d0c0e'
OLD_PROFILE='Opt4-fit-C4-SVB32-MCRams-owner-r1'
PHYSICAL=D/'Opt4-sprint-shell-physical-r1-state.json'


def read(p):return json.loads(Path(p).read_text())


def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()


def exact(p,text):
    p=Path(p);p.parent.mkdir(parents=True,exist_ok=True)
    if p.exists():assert p.read_text()==text,('immutable artifact changed',str(p))
    else:p.write_text(text)


def write(p,j):exact(p,json.dumps(j,indent=2,sort_keys=True)+'\n')


def prepare():
    OUT.mkdir(exist_ok=True)
    binding=VALID/'host-binding.json'
    if not binding.exists():
        return dict(status='WAITING_ACTUAL_COMMITTED_THREADED_HOST_BINDING',fpga_access=False,
                    hardware_commit=COMMIT,old_runtime_identity_reusable=False)
    b=read(binding)
    assert b['hardware_commit']==COMMIT and b['complete_composed_cycles']
    assert b['source_variant']=='4ebc1788592384ac09a135e608809130181327c91c67476540368a2258229594'
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()==COMMIT
    subprocess.run(['git','diff','--exit-code',COMMIT,'--','chipyard'],cwd=ROOT,check=True)
    cfg=W/'candidates/sprint-composed-validate-r1-20261112/ThreadedConfig.scala'
    paths=[VALID/'host'/n for n in ['FireSim-generated.sv','FireSim-generated.const.h',
        'FireSim-generated.const.vh','FireSim-generated.defines.vh',
        'FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']]
    paths += [VALID/'elaborate'/n for n in ['firesim.firesim.FireSim.dts',
                                          'firesim.firesim.FireSim.dromajo_params.h']]
    assert sha(paths[0])==b['host_RTL_sha256']
    component=D/'build-logs/Opt4-address-banked-production-host-r1-20261112/result.json'
    assert sha(component)==b['component_complete_host_validation']
    srcbinding=W/'candidates/address-banked-storage-compose-r1-20261112/source-binding.json'
    assert sha(srcbinding)==b['compiled_source_binding_sha256']
    for p,h in read(srcbinding)['files'].items():assert sha(p)==h
    identity=dict(hardware_commit=COMMIT,functional_baseline=BASE,
        source_variant=b['source_variant'],host_rtl_sha256=sha(paths[0]),
        threaded_config_sha256=sha(cfg),generated={str(p):sha(p) for p in paths},
        host_binding_sha256=sha(binding),source_binding_sha256=sha(srcbinding))
    sid=hashlib.sha256(json.dumps(identity,sort_keys=True).encode()).hexdigest()
    assert sid!=OLD_SOURCE
    write(OUT/'new-identity.json',dict(identity,host_transform_id=sid,
        schema='ec-sprint-actual-host-identity/1',profile=PROFILE,
        old_runtime_identity_reusable=False,fpga_access=False))
    old=read(PARENT/'driver-compatibility.json')
    rows=[]
    for role in ['FireSim-generated.const.h','FireSim-generated.const.vh',
                 'FireSim-generated.defines.vh','firesim.firesim.FireSim.dts',
                 'firesim.firesim.FireSim.dromajo_params.h']:
        parent=next(r for r in old['generated_inputs'] if r['role']==role)
        a=Path(parent['derived']);new=next(p for p in paths if p.name==role)
        assert sha(a)==parent['derived_sha256']
        rows.append(dict(role=role,original=str(a),original_sha256=sha(a),derived=str(new),
                         derived_sha256=sha(new),byte_equal=a.read_bytes()==new.read_bytes()))
    audit=dict(schema='ec-sprint-driver-ABI-comparison/1',hardware_commit=COMMIT,
        host_transform_id=sid,host_rtl_sha256=identity['host_rtl_sha256'],generated_inputs=rows,
        constraints={str(p):sha(p) for p in paths if p.suffix=='.xdc'},
        constraints_require_new_shell_link_and_physical_validation=True,
        fpga_access=False,formal_admission=False)
    write(OUT/'abi-audit.json',audit)
    if not all(r['byte_equal'] for r in rows):
        # Changed generated software ABI cannot reuse a previously built driver.
        # No guessed compatibility or synthetic successful driver receipt.
        return dict(status='GENERATED_ABI_CHANGED_PRIVATE_DRIVER_REBUILD_REQUIRED',
            hardware_commit=COMMIT,host_transform_id=sid,abi_audit=str(OUT/'abi-audit.json'),
            automatic_driver_reuse_refused=True,fpga_access=False)
    R.mkdir(exist_ok=True);scripts=R/'scripts';scripts.mkdir(exist_ok=True)
    parentbundle=read(PARENT/'bundle.json')
    assert all(sha(p)==h for p,h in parentbundle['scripts'].items())
    oldhost=old['host_rtl_sha256']
    for name in ['board_batch.py','run_isolated_sample.py','continue_opt4_fit.py','opt4_fit_runtime_guard.py']:
        p=PARENT/'scripts'/name
        text=p.read_text()
        replacements=[(OLD_COMMIT,COMMIT),(OLD_SOURCE,sid),(OLD_PROFILE,PROFILE),
            (oldhost,identity['host_rtl_sha256']),
            ('Opt4-fit-mcrams-owner-r1',R.name),
            ('Opt4-mcrams-owner-runtime','Opt4-sprint-runtime'),
            ('Opt4-mcrams-shell-physical-r2-state.json',PHYSICAL.name),
            ('opt4-fit-3656aec4-mcrams','opt4-fit-fd5de2ba-sprint')]
        for a,z in replacements:text=text.replace(a,z)
        compile(text,str(scripts/name),'exec')
        assert OLD_COMMIT not in text and OLD_SOURCE not in text and oldhost not in text
        exact(scripts/name,text)
    # The guarded certifier remains separate from the runtime bundle; it refuses
    # a certificate for an old commit, host or shell checkpoint.
    exact(scripts/'prepare_opt4_fit_runtime.py',
        'import sys\nsys.path.insert(0,'+repr(str(C))+')\nfrom certify import certify\n')
    exact(scripts/'continue_priority.py',
        'import sys\nfrom pathlib import Path\nsys.path.insert(0,str(Path(__file__).resolve().parent))\n'
        'sys.path.insert(1,'+repr(str(W/'candidates/fpga-priority-handoff-r1-20261112'))+')\n'
        'from schedule import adapt\nimport continue_opt4_fit as m\n'
        'm.next_task=adapt(m.next_task)\nif __name__=="__main__":m.main()\n')
    parentdriver=read(PARENT/'driver-receipt.json')
    exe=R/'FireSim-xilinx_alveo_u280';original=PARENT/exe.name
    assert sha(original)==parentdriver['outputs'][str(original)]
    if not exe.exists():shutil.copy2(original,exe)
    assert sha(exe)==sha(original)
    comp=dict(audit,status='PASS_REAL_ACTUAL_SPRINT_DRIVER_ABI_INPUTS_BYTE_EQUAL',
        target_commit=COMMIT,outputs={str(exe):sha(exe)},parent_receipt=str(PARENT/'driver-receipt.json'),
        parent_receipt_sha256=sha(PARENT/'driver-receipt.json'))
    write(R/'driver-compatibility.json',comp)
    driver=dict(parentdriver,hardware_commit=COMMIT,target_commit=COMMIT,hardware_source_id=sid,
        source_id=sid,host_transform_id=sid,profile=PROFILE,output_dir=str(R),outputs={str(exe):sha(exe)},
        compatibility_receipt=str(R/'driver-compatibility.json'),
        compatibility_receipt_sha256=sha(R/'driver-compatibility.json'),
        host_code_reused=True,recompiled=False,fpga_runtime_validated=False,
        status='ABI_COMPATIBLE_REBOUND_NOT_FPGA_VALIDATED')
    write(R/'driver-receipt.json',driver)
    suite=copy.deepcopy(read(PARENT/'software-suite.json'))
    suite.update(profile=PROFILE,hardware_commit=COMMIT,target_commit=COMMIT,source_id=sid,
        host_transform_id=sid,host_rtl_sha256=identity['host_rtl_sha256'],
        automatic_runtime_handoff_installed=False)
    for row in suite['programs']:
        for key,path in row['receipts'].items():assert sha(path)==row['receipt_sha256'][key]
        row['receipts']['driver']=str(R/'driver-receipt.json')
        row['receipt_sha256']['driver']=sha(R/'driver-receipt.json')
    assert suite['program_count']==13
    write(R/'software-suite.json',suite)
    pins=[C/'identity.py',C/'certify.py',OUT/'new-identity.json',OUT/'abi-audit.json',
          binding,srcbinding,component,R/'driver-compatibility.json',R/'driver-receipt.json',R/'software-suite.json']
    bundle=dict(schema='ec-sprint-rebound-runtime-bundle/1',hardware_commit=COMMIT,target_commit=COMMIT,
        host_transform_id=sid,host_rtl_sha256=identity['host_rtl_sha256'],functional_baseline=BASE,
        profile=PROFILE,board_bdf='0000:21:00.0',board_serial='21770433G02LA',fpga_access=False,
        scripts={str(p):sha(p) for p in scripts.glob('*.py')},immutable_inputs={str(p):sha(p) for p in pins},
        software_suite=str(R/'software-suite.json'),software_suite_sha256=sha(R/'software-suite.json'),
        physical_state=str(PHYSICAL),certified_bitstream=False,production_admission=False,
        status='OFFLINE_ACTUAL_HOST_ABI_REBOUND_REQUIRES_FULL_SHELL_PHYSICAL_AND_OWNER_HANDOFF')
    write(R/'bundle.json',bundle)
    request=dict(status='PREPARED_NOT_INSTALLED_EXISTING_HANDOFF_OWNER_REQUIRED',
        target_commit=COMMIT,host_transform_id=sid,bundle=str(R/'bundle.json'),bundle_sha256=sha(R/'bundle.json'),
        runtime_entry=str(scripts/'continue_priority.py'),physical_state=str(PHYSICAL),
        existing_root_handoff='ec-opt4-fpga-priority-handoff-r1.service',
        no_new_root_runtime_service=True,no_live_runtime_or_CAD_modified=True,
        certified_bitstream=False,fpga_access=False)
    write(OUT/'handoff-request.json',request)
    return request


if __name__=='__main__':print(json.dumps(prepare(),indent=2))
