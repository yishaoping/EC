#!/usr/bin/env python3
"""Compile untouched host algorithms/user TCP for cross-architecture outputs."""
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha
from job_service import proc

P=Path('/data1/gzh/EC/Software/PARSEC')
RECEIPT=D/'software/network-host-reference.json'


def main():
    prior={}
    if RECEIPT.exists():
        prior=json.loads(RECEIPT.read_text())
        if prior.get('status')=='COMPILED' and all(Path(p).exists() and sha(p)==h for p,h in prior['binaries'].items()):return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=Path(prior['output_dir']) if prior else W/'software'/('network-host-reference-'+stamp);out.mkdir(exist_ok=True)
    logs=D/'software'/out.name;logs.mkdir(exist_ok=True)
    for name in ['uptcpip','netdedup','netferret','netstreamcluster']:
        if not (out/name).exists():shutil.copytree(P/f'pkgs/{"libs" if name=="uptcpip" else "netapps"}/{name}/src',out/name,
            ignore=shutil.ignore_patterns('*.o','*.a','*.so','*.o.client','*.o.sim','*.o.client.sim'))
    hostbin=out/'hostbin';hostbin.mkdir(exist_ok=True)
    if not (hostbin/'ls').exists():(hostbin/'ls').symlink_to('/data1/gzh/EC/firesim/envs/manager-1.17.1/bin/ls')
    state=dict(status='BUILDING',output_dir=str(out),log_dir=str(logs),commands=prior.get('commands',[]),binaries={},
        pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        software_scope='Original x86_64 user TCP and unmodified application computations; diagnostic hooks at original ROI',fpga_eligible=False)
    def run(label,argv,cwd):
        p=logs/(str(len(state['commands'])).zfill(3)+'-'+label+'.log')
        entry=dict(argv=list(map(str,argv)),cwd=str(cwd),log=str(p));state['commands'].append(entry);save(RECEIPT,state)
        with p.open('wb') as f:
            rc=subprocess.run(['nice','-n','15',*map(str,argv)],cwd=cwd,env={**os.environ,'PATH':str(hostbin)+':/usr/bin:/bin','LD_LIBRARY_PATH':'','CC':'gcc','CXX':'g++','CFLAGS':'-O2 -fcommon','LDFLAGS':''},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=1800).returncode
        entry.update(returncode=rc,log_sha256=sha(p));save(RECEIPT,state)
        if rc:raise RuntimeError(f'{label} failed {rc}; {p}')
    try:
        src=out/'uptcpip'
        run('stack-clean',['make','clean','ARCH=x86_64'],src)
        run('stack',['make','-j4','ARCH=x86_64','CC=gcc','CXX=g++','GCC_OX=-O2 -g -fcommon -fno-strict-aliasing'],src)
        assert len(list((src/'lib').glob('libuptcp*.a')))==4
        candidate=json.loads((W/'software/network-candidate-build.json').read_text())
        diag=Path(candidate['output_dir'])/'diagnostic-hooks.c'
        parent=json.loads((W/'software/apps-build.json').read_text());hooks=Path(parent['output_dir'])/'src/hooks'
        run('hooks',['gcc','-O2','-I'+str(hooks),'-c',diag,'-o',out/'diagnostic-hooks.o'],out)
        common=['-O2','-g','-fcommon','-fno-strict-aliasing','-D_GNU_SOURCE','-DENABLE_PARSEC_HOOKS','-DENABLE_PARSEC_UPTCPIP','-I'+str(src/'lib'),'-I'+str(hooks)]
        for part in ['server','client']:
            d=out/'netstreamcluster'/part
            run('netstreamcluster-'+part,['g++',*common,d/('streamcluster.cpp' if part=='server' else 'client.cpp'),out/'diagnostic-hooks.o','-static','-L'+str(src/'lib'),'-l'+('uptcp' if part=='server' else 'uptcp.client'),'-pthread','-lm','-o',d/part],out)
        server=out/'netdedup/server'
        ssl=P/'pkgs/libs/ssl/inst/amd64-linux.gcc-serial/include/openssl'
        for n in ['e_os2.h','opensslconf.h']:shutil.copy2(ssl/n,server/'openssl'/n)
        flags=common+['-I'+str(server),'-DENABLE_GZIP_COMPRESSION','-DENABLE_STATISTICS','-D_XOPEN_SOURCE=600']
        run('netdedup-server',['gcc',*flags,*[server/n for n in ['hashtable.c','util.c','dedup.c','rabin.c','encoder.c','decoder.c','mbuffer.c','sha.c']],out/'diagnostic-hooks.o','-static','-L'+str(src/'lib'),'-luptcp','-lz','-pthread','-lm','-o',server/'netdedup'],out)
        run('netdedup-client',['gcc',*flags,out/'netdedup/client/dedup_client.c','-static','-L'+str(src/'lib'),'-luptcp.client','-pthread','-lm','-o',out/'netdedup/client/netdedup_client'],out)
        server=out/'netferret/server'
        gsl=jpeg=out/'host-dependencies'
        for name,library in [('gsl','libgsl.a'),('libjpeg','libjpeg.a')]:
            if not (gsl/'lib'/library).exists():
                source=out/('host-'+name)
                if not source.exists():shutil.copytree(P/f'pkgs/libs/{name}/src',source,ignore=shutil.ignore_patterns('*.o','*.lo','*.a','*.so*','.libs'))
                run(name+'-configure',['bash','configure','--host=x86_64-pc-linux-gnu','--build=x86_64-pc-linux-gnu','--prefix='+str(gsl),'--disable-shared','--enable-static'],source)
                run(name+'-build',['make','-j4'],source)
                run(name+'-install',['make','install'],source)
        flags=' '.join(common+['-I'+str(server/'include'),'-I'+str(gsl/'include'),'-I'+str(jpeg/'include'),'-pthread'])
        args=['version=pthreads','CC=gcc','CXX=g++','AR=ar','CFLAGS='+flags,'LDFLAGS=-static -L'+str(gsl/'lib')+' -L'+str(jpeg/'lib')+' -L'+str(src/'lib')+' -L'+str(server/'parsec/lib'),'LIBS='+str(out/'diagnostic-hooks.o')+' -pthread']
        run('netferret-dirs',['make','dirs',*args],server)
        run('netferret-libs',['make','-j4','lib',*args],server)
        run('netferret-server',['make','-j4','benchmark',*args],server)
        run('netferret-client',['make','-j4','CC=gcc','CFLAGS='+flags,'LDFLAGS=-static -L'+str(src/'lib'),'LIBS=-pthread'],out/'netferret/client')
        rel=['netstreamcluster/server/server','netstreamcluster/client/client','netdedup/server/netdedup','netdedup/client/netdedup_client','netferret/server/parsec/bin/ferret-pthreads','netferret/client/client']
        state['binaries']={str(out/n):sha(out/n) for n in rel}
        state.update(status='COMPILED',dependencies={str(p):sha(p) for p in [gsl/'lib/libgsl.a',gsl/'lib/libgslcblas.a',jpeg/'lib/libjpeg.a']})
    except Exception as e:state.update(status='FAILED_WITH_EVIDENCE',error=repr(e))
    state.update(ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(RECEIPT,state);save(logs/'result.json',state)
    print(json.dumps(dict(status=state['status'],error=state.get('error'))),flush=True)
    return 0 if state['status']=='COMPILED' else 2


if __name__=='__main__':raise SystemExit(main())
