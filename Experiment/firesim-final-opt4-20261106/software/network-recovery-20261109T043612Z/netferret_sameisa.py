#!/usr/bin/env python3
"""Independent original RISC-V socket reference, never a replacement workload."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha
from job_service import proc
P=Path('/data1/gzh/EC/Software/PARSEC')
T=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')
R=D/'software/netferret-sameisa-state.json'

def main():
    lock=(D/'software/netferret-sameisa.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    bound=sha(W/'software/network-candidate-build.json')
    if R.exists():
        st=json.loads(R.read_text());assert st['candidate_receipt_sha256']==bound
        if st['status']=='COMPLETE_REVIEW_EVIDENCE':return
    else:
        st=dict(schema='ec-netferret-sameisa/1',status='BUILDING',candidate_receipt_sha256=bound,
            output_dir=str(W/'software'/('netferret-kernel-reference-'+stamp)),log_dir=str(D/'software'/('netferret-sameisa-'+stamp)),
            started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),commands=[],cases=[],formal_eligible=False,fpga_execution=False)
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    ref=Path(st['output_dir']);ref.mkdir(exist_ok=True)
    logs=Path(st['log_dir']);logs.mkdir(exist_ok=True);save(R,st)
    b=json.loads((W/'software/network-candidate-build.json').read_text());base=Path(b['output_dir'])
    deps=json.loads((W/'software/ferret-candidate-build.json').read_text());prefix=Path(deps['output_dir'])/'dependencies'
    parent=json.loads((W/'software/apps-build.json').read_text());hooks=Path(parent['output_dir'])/'src/hooks'
    original=P/'pkgs/netapps/netferret/src';server=original/'server'
    libs=base/'netferret/server/parsec/lib'
    reused=[base/'diagnostic-hooks.o',libs/'libcass.a',libs/'libcassimage.a']+[prefix/'lib'/s for s in ['libgsl.a','libgslcblas.a','libjpeg.a']]
    st['reused_dependencies']={str(p):sha(p) for p in reused}
    flags=['-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing','-D_GNU_SOURCE','-DENABLE_PARSEC_HOOKS',
        '-I'+str(hooks),'-I'+str(server/'include'),'-I'+str(prefix/'include')]
    def run(label,argv):
        log=logs/(label+'.log')
        with log.open('wb') as f:rc=subprocess.run(['nice','-n','15',*map(str,argv)],stdout=f,stderr=subprocess.STDOUT,timeout=300).returncode
        st['commands'].append(dict(argv=list(map(str,argv)),log=str(log),returncode=rc));save(R,st);assert rc==0,label
    gcc=T/'riscv64-unknown-linux-gnu-gcc'
    # tpool is recompiled without ENABLE_PARSEC_UPTCPIP; library compute/image
    # objects are byte-identical to the candidate. Only transport is selected.
    objs=[]
    for label,source in [('tpool',server/'src/tpool.c'),('benchmark',server/'benchmark/ferret-pthreads.c')]:
        obj=ref/(label+'.o');run(label,[gcc,*flags,'-c',source,'-o',obj]);objs.append(obj)
    sb=ref/'netferret/server/parsec/bin/ferret-pthreads';sb.parent.mkdir(parents=True,exist_ok=True)
    cb=ref/'netferret/client/client';cb.parent.mkdir(parents=True,exist_ok=True)
    run('server',[T/'riscv64-unknown-linux-gnu-g++','-static',*objs,base/'diagnostic-hooks.o','-L'+str(libs),'-L'+str(prefix/'lib'),
        '-Wl,--start-group','-lcass','-lcassimage','-lgsl','-lgslcblas','-ljpeg','-Wl,--end-group','-pthread','-lrt','-lm','-o',sb])
    run('client',[gcc,*flags,original/'client/client.c',original/'client/tpool.c',server/'src/queue.c','-static','-pthread','-lm','-o',cb])
    save(D/'software/netferret-kernel-reference.json',dict(schema='ec-netferret-kernel-reference/1',status='COMPILED',output_dir=str(ref),
        binaries={n:dict(path=str(p),sha256=sha(p)) for n,p in [('server/parsec/bin/ferret-pthreads',sb),('client/client',cb)]},
        compiler_sha256=sha(gcc),algorithm_sources_modified=False,original_sources={str(p):sha(p) for p in [server/'benchmark/ferret-pthreads.c',original/'client/client.c']},
        reused_dependencies=st['reused_dependencies'],formal_eligible=False))
    st['status']='VALIDATING';save(R,st)
    for size in ['test','simsmall','simmedium']:
        out=logs/size
        if (out/'result.json').exists():continue
        if out.exists():out.rename(out.with_name(size+'-interrupted-'+stamp))
        out.mkdir()
        argv=['unshare','--ipc','--mount','--net','--fork','python3',str(W/'scripts/validate_netferret_sameisa.py'),
            '--case','netferret','--arch','riscv64-kernel','--size',size,'--out',str(out)]
        with (out/'launch.log').open('wb') as f:
            child=subprocess.Popen(argv,stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,env={**os.environ,'EC_NETWORK_NO_TRACE':'1'})
            st.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'],active_case=size);save(R,st);rc=child.wait()
        st['cases'].append(dict(input=size,result=str(out/'result.json'),returncode=rc))
        st.pop('child_pid',None);st.pop('child_start_ticks',None);save(R,st)
    st.update(status='COMPLETE_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
