#!/usr/bin/env python3
"""Exact template-derived runtime bundles for separately identified Opt4-fit RTL.

Only the existing 21-only deployment/strict verifier is reused. Changed driver
ABI fails closed and is returned to the optimization worker for an actual build.
"""
import importlib.util
import re
import shutil
import subprocess
import sys
from opt4_unattended_common import *

BASE_COMMIT='8da24a269b98a0d6a8f57b030353a310812c4344'
BASE_SOURCE='7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1'
BASE_PROFILE='Opt4-fit-C4-SVB32-20261110'
FILES=['board_batch.py','run_isolated_sample.py','continue_opt4_fit.py',
       'prepare_opt4_fit_runtime.py','opt4_fit_runtime_guard.py']

def descriptor(p):
    p=Path(p).resolve();assert p.is_relative_to(W/'runtime-candidates')
    x=read(p)
    assert re.fullmatch('[0-9a-f]{40}',x['commit']) and re.fullmatch('[0-9a-f]{64}',x['source_id'])
    assert re.fullmatch(r'Opt4-fit-[A-Za-z0-9-]+',x['profile'])
    assert re.fullmatch(r'Opt4-fit-[A-Za-z0-9-]+',x['state_prefix'])
    assert x['board_bdf']=='0000:21:00.0' and x['board_serial']=='21770433G02LA'
    f=Path(x['worktree']).resolve();assert f.is_relative_to(W)
    b=read(f/'bindings'/(x['commit']+'.json'))
    assert b['source_id']==x['source_id'] and b['frozen_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
    for k in ['cad_state','rtl_state']:assert Path(x[k]).resolve().is_relative_to(D)
    x['descriptor_path']=str(p);return x

def generate(x):
    c=x['commit'];out=W/'runtime'/('Opt4-fit-'+c[:8]);bundle=out/'scripts';bundle.mkdir(parents=True,exist_ok=True)
    baseline=read(U/'runtime-template-baseline.json')
    assert baseline['status']=='PINNED_21_ONLY_STRICT_RUNTIME_TEMPLATES'
    for n in FILES:assert sha(W/'scripts'/n)==baseline['templates'][n]
    replacements=[(BASE_COMMIT,c),(BASE_SOURCE,x['source_id']),(BASE_PROFILE,x['profile']),
      ('Opt4-fit-20261110',Path(x['worktree']).name),
      ('Opt4-fit-cad-state.json',Path(x['cad_state']).name),
      ('Opt4-fit-runtime-state.json',x['state_prefix']+'-runtime-state.json'),
      ('Opt4-fit-runtime-logs',x['state_prefix']+'-runtime-logs'),
      ('opt4-fit-8da24a26','opt4-fit-'+c[:8]),
      ('Opt4-fit-C4-driver-compatibility.json','Opt4-fit-'+c[:8]+'/driver-compatibility.json')]
    records={}
    prefix='import sys\nfrom pathlib import Path as _BundlePath\nsys.path.insert(0, str(_BundlePath(__file__).resolve().parent))\nsys.path.insert(1, '+repr(str(W/'scripts'))+')\n'
    for n in FILES:
        text=(W/'scripts'/n).read_text()
        for a,b in replacements:text=text.replace(a,b)
        text=prefix+text
        if n=='continue_opt4_fit.py':
            text=text.replace("str(W/'scripts/run_isolated_sample.py')","str(Path(__file__).resolve().parent/'run_isolated_sample.py')")
            text=text.replace("str(W/'scripts/board_batch.py')","str(Path(__file__).resolve().parent/'board_batch.py')")
        if n=='opt4_fit_runtime_guard.py':
            # Deployment/sample locks remain shared with all 21 users. This
            # version's waiter is only entered after the previous waiter yields.
            assert "BDF='0000:21:00.0'" in text and "SERIAL='21770433G02LA'" in text
        p=bundle/n
        if p.exists():assert p.read_text()==text,'immutable runtime bundle changed'
        else:p.write_text(text)
        compile(text,str(p),'exec');records[n]=sha(p)
    receipt=dict(schema='ec-opt4-candidate-runtime-templates/1',status='PREPARED_TEMPLATES_REQUIRES_BOUND_RTL_ABI_AND_REAL_CAD',
      hardware_commit=c,source_id=x['source_id'],profile=x['profile'],descriptor=x['descriptor_path'],
      descriptor_sha256=sha(x['descriptor_path']),scripts=records,baseline_sha256=sha(U/'runtime-template-baseline.json'),
      board_bdf='0000:21:00.0',fpga_access=False)
    p=out/'bundle.json'
    if p.exists():assert read(p)==receipt
    else:save(p,receipt)
    return out,bundle

def compatibility(x,out):
    r=read(x['rtl_state'])
    assert r.get('status')=='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED','WAITING_BOUND_GOLDENGATE'
    assert r['hardware_commit']==x['commit'] and r['source_id']==x['source_id']
    assert r['modified_class_origins_verified'] and r['configuration_matches_frozen_parameters']
    base=read(W/'runtime/Opt4-fit-C4-driver-compatibility.json');rows=[]
    for row in base['generated_abi_and_target_description']:
        role=row['role'];folder='goldengate_dir' if role.startswith('FireSim-generated.') else 'elaboration_dir'
        derived=Path(r[folder])/role
        assert sha(row['original'])==sha(derived),'ABI_CHANGED_REQUIRES_REAL_DRIVER_REBUILD: '+role
        rows.append(dict(row,derived=str(derived),byte_equal=True,sha256=sha(derived)))
    parent=read(base['parent_receipt']);assert sha(base['parent_receipt'])==base['parent_receipt_sha256']
    src=Path(next(iter(base['outputs'])))
    assert sha(src)==base['outputs'][str(src)]
    dst=out/src.name
    if not dst.exists():shutil.copy2(src,dst)
    assert sha(dst)==sha(src)
    p=out/'driver-compatibility.json'
    result=dict(base,hardware_commit=x['commit'],hardware_source_id=x['source_id'],profile=x['profile'],
      generated_abi_and_target_description=rows,outputs={str(dst):sha(dst)},host_code_reused=True,recompiled=False)
    if p.exists():assert read(p)==result
    else:save(p,result)

def request(r):
    x=descriptor(r['descriptor']);out,bundle=generate(x)
    if r['action']=='prepare_runtime':
        return dict(status='TEMPLATES_PREPARED_NO_FPGA_ACCESS',bundle=str(out/'bundle.json'),
                    next='actual seven-file ABI comparison after candidate GoldenGate; CAD certification before deployment')
    assert r['action']=='start_runtime'
    cad=read(x['cad_state'])
    assert cad.get('status')=='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED','WAITING_CERTIFIABLE_BITSTREAM'
    assert cad['hardware_commit']==x['commit'] and cad['source_id']==x['source_id']
    compatibility(x,out)
    # Preserve a still usable older design; no waiter or child is stopped until
    # the predecessor has a real NOT FIT verdict and has no active FPGA sample.
    old=read(D/'Opt4-fit-runtime-state.json')
    if live(old):
        assert read(D/'Opt4-fit-cad-state.json').get('status')=='NOT_FIT_POSTOPT','WAITING_CURRENT_DESIGN_PRIORITY'
        assert old.get('status')=='WAITING_FOR_DERIVED_BITSTREAM' and not old.get('child_pid'),'WAITING_ACTIVE_PREDECESSOR_RUNTIME'
        active=read(D/'active-0000_21_00.0.json')
        assert not live(active),'WAITING_21_SAFE_BOUNDARY'
        event('OBSOLETE_NOT_FIT_RUNTIME_WAITER_HANDOFF',old=old,candidate=x['commit'])
        subprocess.run(['systemctl','stop','ec-parsec-opt4-fit-runtime.service'],check=True)
    unit='ec-opt4-derived-runtime-'+x['commit'][:8]+'.service'
    path=Path('/etc/systemd/system')/unit
    text=f'''[Unit]
Description=Certified derived Opt4 21-only runtime {x['commit'][:8]}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStartPre=/usr/bin/python3 {bundle}/prepare_opt4_fit_runtime.py
ExecStart=/usr/bin/python3 {bundle}/continue_opt4_fit.py
Restart=on-failure
RestartSec=300
KillMode=process
StandardOutput=append:{out}/runtime-service.log
StandardError=append:{out}/runtime-service.log
[Install]
WantedBy=multi-user.target
'''
    if path.exists():assert path.read_text()==text
    else:path.write_text(text)
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
    return dict(status='CERTIFIED_RUNTIME_SERVICE_STARTED',unit=unit,bundle=str(out/'bundle.json'))

if __name__=='__main__':
    print(json.dumps(request(read(sys.argv[1])),indent=2))
