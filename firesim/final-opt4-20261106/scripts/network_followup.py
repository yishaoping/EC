#!/usr/bin/env python3
"""Targeted, software-only pending network checks; existing FPGA jobs untouched."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha
from job_service import proc
from network_binding import candidate

R=D/'software/network-followup-state.json'
P=Path('/data1/gzh/EC/Software/PARSEC')
T=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')

def main():
    lock=(D/'software/network-followup.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    bound,build=candidate(W/'software/network-candidate-build.json')
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'software'/('network-followup-'+stamp);out.mkdir()
    state=dict(schema='ec-network-followup/1',status='RUNNING',output_dir=str(out),pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),candidate_receipt_sha256=bound,
        formal_eligible=False,fpga_execution=False,cases=[])
    if R.exists():
        prior=json.loads(R.read_text())
        assert prior['candidate_receipt_sha256']==state['candidate_receipt_sha256'],'candidate version changed; review before resume'
        if prior['status']=='COMPLETE_REVIEW_EVIDENCE':
            print('Existing complete evidence retained; no duplicate test');return
        out.rmdir();out=Path(prior['output_dir']);state.update(prior)
        state.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
            host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),resumed_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(R,state)
    # Same-ISA original kernel-socket implementation isolates cross-ISA numeric
    # differences from the RISC-V user-TCP port. No algorithm/source edits.
    ref=Path(state.get('reference_dir',str(W/'software'/('network-kernel-reference-'+stamp))));ref.mkdir(exist_ok=True)
    state['reference_dir']=str(ref);save(R,state)
    parent=json.loads((W/'software/apps-build.json').read_text())
    hooks=Path(parent['output_dir'])/'src/hooks'
    src=Path(build['output_dir'])
    commands=[];bins={}
    for side,source in [('server','streamcluster.cpp'),('client','client.cpp')]:
        dst=ref/'netstreamcluster'/side/side;dst.parent.mkdir(parents=True,exist_ok=True)
        original=P/'pkgs/netapps/netstreamcluster/src'/side/source
        argv=[str(T/'riscv64-unknown-linux-gnu-g++'),'-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing',
            '-D_GNU_SOURCE','-I'+str(hooks),'-DENABLE_PARSEC_HOOKS',str(original),str(src/'diagnostic-hooks.o'),'-static','-pthread','-lm','-o',str(dst)]
        with (out/(side+'-kernel-build.log')).open('wb') as f:
            rc=subprocess.run(['nice','-n','15',*argv],stdout=f,stderr=subprocess.STDOUT,timeout=300).returncode
        assert rc==0,side
        commands.append(dict(argv=argv,source=str(original),source_sha256=sha(original),returncode=rc))
        bins[side+'/'+side]=dict(path=str(dst),sha256=sha(dst))
    save(D/'software/network-kernel-reference.json',dict(schema='ec-network-kernel-reference/1',status='COMPILED',output_dir=str(ref),
        binaries=bins,commands=commands,algorithm_sources_modified=False,formal_eligible=False,
        compiler_sha256=sha(T/'riscv64-unknown-linux-gnu-g++'),user_stack_candidate_receipt_sha256=state['candidate_receipt_sha256']))
    def launch(name,size,arch):
        work=out/(name+'-'+size+'-'+arch)
        if (work/'result.json').exists():
            data=json.loads((work/'result.json').read_text())
            assert data['source_receipt_sha256']==state['candidate_receipt_sha256']
            return 2 if data['status']=='FAILED_WITH_EVIDENCE' else 0
        if work.exists():
            work.rename(work.with_name(work.name+'-interrupted-'+stamp))
        work.mkdir()
        argv=['unshare','--ipc','--mount','--net','--fork','/usr/bin/python3',str(W/'scripts/validate_network_candidates.py'),
            '--case',name,'--size',size,'--arch',arch,'--out',str(work)]
        with (work/'launch.log').open('wb') as f:
            child=subprocess.Popen(argv,stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,env={**os.environ,'EC_NETWORK_NO_TRACE':'1'})
            state.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'],active_case=work.name);save(R,state)
            rc=child.wait()
        result=work/'result.json'
        data=json.loads(result.read_text()) if result.exists() else dict(status='LAUNCH_FAILED')
        state['cases'].append(dict(program=name,input=size,architecture=arch,returncode=rc,status=data['status'],result=str(result)))
        state.pop('child_pid',None);state.pop('child_start_ticks',None);save(R,state)
        return rc
    # Only missing v2 evidence is tested; completed dedup cases are reused.
    if launch('netferret','test','riscv64')==0:
        for size in ['simsmall','simmedium']:
            for arch in ['x86_64','riscv64']:launch('netferret',size,arch)
    for size in ['test','simsmall','simmedium']:
        launch('netstreamcluster',size,'riscv64-kernel')
    launch('netstreamcluster','simmedium','riscv64')
    state.update(status='COMPLETE_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,state)
    print(json.dumps(dict(status=state['status'],output_dir=str(out))),flush=True)

if __name__=='__main__':main()
