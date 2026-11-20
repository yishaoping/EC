#!/usr/bin/env python3
"""Build an unbound software candidate; adoption requires the user's experiment decision."""
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
from board_batch import W,D,save,sha

OUTPUT=D/'software/fluidanimate-stable-candidate-preparation.json'
PROFILE='fluidanimate-stable-candidate'
TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    lock=(D/'locks/fluidanimate-stable-candidate-preparation.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    prior=json.loads(OUTPUT.read_text()) if OUTPUT.exists() else {}
    if prior.get('status')=='READY_UNBOUND_PENDING_DECISION':return
    parent=W/'software/fluidanimate-apps-build.json';apps=json.loads(parent.read_text());base=Path(apps['output_dir'])
    proof=json.loads((D/'software/fluidanimate-stable-order-candidate.json').read_text())
    assert proof.get('cross_environment_output_exact') and proof.get('user_in_radius_omissions')==proof.get('linux_in_radius_omissions')==0
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=Path(prior['output_dir']) if prior.get('output_dir') else W/'software'/('apps-fluidanimate-stable-candidate-'+stamp)
    logs=Path(prior['host_log_dir']) if prior.get('host_log_dir') else D/'software'/out.name
    out.mkdir(exist_ok=True);logs.mkdir(exist_ok=True)
    state=dict(status='PREPARING_UNBOUND_CANDIDATE',output_dir=str(out),host_log_dir=str(logs),diagnostic_only=True,
        formal_eligible=False,awaiting_explicit_software_semantics_decision=True,no_plan_changes=True,fpga_operations=False,
        parent_receipt=str(parent),parent_receipt_sha256=sha(parent),completed_cases=prior.get('completed_cases',[]))
    save(OUTPUT,state);shutil.copy2(__file__,logs/'preparation-script.py')
    src=out/'src';expected='if(&neigh->p[iparNeigh % PARTICLES_PER_CELL] < &cell->p[ipar % PARTICLES_PER_CELL])'
    replacement='if(cindexNeigh < cindex || (cindexNeigh == cindex && iparNeigh < ipar))'
    original=(base/'src/fluidanimate/serial.cpp').read_text();assert original.count(expected)==2
    patched=original.replace(expected,replacement)
    if not src.exists():shutil.copytree(base/'src',src)
    (src/'fluidanimate/serial.cpp').write_text(patched)
    patch=logs/'stable-pair-order.patch';patch.write_text(''.join(difflib.unified_diff(original.splitlines(True),patched.splitlines(True),fromfile=str(base/'src/fluidanimate/serial.cpp'),tofile=str(src/'fluidanimate/serial.cpp'))))
    for name in ['hooks.o','dac_roi.o','diagnostic-hooks.o','roi-smoke']:shutil.copy2(base/name,out/name)
    if not (out/'inputs').exists():shutil.copytree(base/'inputs',out/'inputs')
    env={**os.environ,'LD_LIBRARY_PATH':''}
    def run(argv,label,cwd=out,timeout=900):
        log=logs/(label+'.log');state.update(stage=label,active_log=str(log));save(OUTPUT,state)
        with log.open('wb',buffering=0) as f:
            subprocess.run(list(map(str,argv)),cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=timeout,check=True)
            os.fsync(f.fileno())
        return log
    flags=['-O3','-march=rv64gc','-mabi=lp64d','-static','-D_GNU_SOURCE','-D_XOPEN_SOURCE=600','-Wno-invalid offsetof'.replace(' ','-'),'-I'+str(src/'hooks'),'-I'+str(src/'fluidanimate'),'-std=gnu++17','-DENABLE_PARSEC_HOOKS']
    for name,objects in [('fluidanimate',['hooks.o','dac_roi.o']),('fluidanimate-reference',['diagnostic-hooks.o'])]:
        if not (out/name).exists():
            run([TOOLS/'riscv64-unknown-linux-gnu-g++',*flags,src/'fluidanimate/serial.cpp',src/'fluidanimate/cellpool.cpp',*[out/o for o in objects],'-lm','-pthread','-o',out/name],'build-'+name)
    cases=[]
    for oldcase in apps['cases']:
        size=oldcase['input'];ref=logs/('reference-'+size)
        if not ref.exists():shutil.copytree(out/'inputs/fluidanimate'/size,ref)
        done=ref/'reference-complete.json'
        if not done.exists():
            run(['/usr/bin/qemu-riscv64',out/'fluidanimate-reference',*oldcase['argv']],'reference-'+size,cwd=ref)
            save(done,dict(output_sha256=sha(ref/'out.fluid'),elf_sha256=sha(out/'fluidanimate-reference')))
        else:
            d=json.loads(done.read_text());assert d['output_sha256']==sha(ref/'out.fluid') and d['elf_sha256']==sha(out/'fluidanimate-reference')
        diag=logs/('trace-'+size)
        if not diag.exists():shutil.copytree(out/'inputs/fluidanimate'/size,diag)
        trace=run(['/usr/bin/qemu-riscv64','-strace',out/'fluidanimate-reference',*oldcase['argv']],'trace-'+size,cwd=diag)
        lines=trace.read_text().splitlines();begin=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
        syscalls=[l for l in lines[begin+1:end] if re.match(r'^\d+ [A-Za-z_]\w*\(',l)]
        assert sha(diag/'out.fluid')==sha(ref/'out.fluid') and not syscalls,(size,syscalls)
        if size=='simsmall':assert sha(ref/'out.fluid')==proof['user_diagnostic_output_sha256']
        case=dict(oldcase);case.update(reference_outputs={'out.fluid':sha(ref/'out.fluid')},validation=dict(kind='files_sha256',files={'out.fluid':sha(ref/'out.fluid')}),
            software_reference='QEMU_RISCV_USER_CANDIDATE_ONLY',fpga_validation='NOT_RUN',algorithm_unchanged=False,
            software_bugfix='Stable cell/particle index pair ordering instead of cross-allocation pointer ordering',diagnostic_roi_syscalls=syscalls,diagnostic_trace=str(trace))
        cases.append(case);state['completed_cases']=sorted(set(state['completed_cases']+[size]));save(OUTPUT,state)
    prepared=dict(apps);prepared.update(output_dir=str(out),host_log_dir=str(logs),software_profile='fluidanimate-stable-index-pairing-candidate',
        formal_eligible=False,awaiting_explicit_software_semantics_decision=True,algorithm_sources_modified=True,
        original_apps_receipt=str(parent),original_apps_receipt_sha256=sha(parent),cases=cases,
        integration_patch=str(patch),integration_patch_sha256=sha(patch),smoke=dict(path=str(out/'roi-smoke'),sha256=sha(out/'roi-smoke')),
        binaries=dict(fluidanimate=dict(path=str(out/'fluidanimate'),sha256=sha(out/'fluidanimate'),application_threads=1,algorithm_sources_modified=True)),
        sources={str(p.relative_to(src/'fluidanimate')):sha(p) for p in (src/'fluidanimate').rglob('*') if p.is_file()},
        fpga_validation='NOT_RUN',status='CANDIDATE_PREPARED_NOT_ADOPTED')
    receipt=W/f'software/{PROFILE}-apps-build.json'
    if receipt.exists():assert json.loads(receipt.read_text())==prepared
    else:save(receipt,prepared)
    save(out/'manifest.json',prepared)
    run(['python3',W/'scripts/prepare_profile_system.py',PROFILE],'prepare-both-payloads',timeout=900)
    state.update(status='READY_UNBOUND_PENDING_DECISION',apps_receipt=str(receipt),apps_receipt_sha256=sha(receipt),
        candidate_elf=str(out/'fluidanimate'),candidate_elf_sha256=sha(out/'fluidanimate'),
        candidate_patch=str(patch),candidate_patch_sha256=sha(patch),completed_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(OUTPUT,state);print(json.dumps(state),flush=True)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=json.loads(OUTPUT.read_text()) if OUTPUT.exists() else {}
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),no_plan_changes=True)
        save(OUTPUT,state);raise
