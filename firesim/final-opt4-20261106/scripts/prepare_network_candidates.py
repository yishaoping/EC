#!/usr/bin/env python3
"""Private, checkpointed RISC-V port of the original PARSEC network apps.

Candidate receipts never authorize FPGA execution. No DUT/scheduler/device ops.
"""
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess

from board_batch import W,D,save,sha
from job_service import proc

P=Path('/data1/gzh/EC/Software/PARSEC')
T=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')
RECEIPT=W/'software/network-candidate-build.json'
STATUS=D/'software/network-candidate-build-state.json'
PORT_VERSION=2


def patch_stack(src):
    original=P/'pkgs/libs/uptcpip/src'
    arch=src/'include/riscv64'
    if not arch.exists():shutil.copytree(original/'include/x86_64',arch)
    # LP64/little-endian scalar types are shared; no x86 instruction is reused.
    for name in ['bsd_param.h']:
        p=arch/name;p.write_text(p.read_text().replace('"amd64"','"riscv64"'))
    p=arch/'bsd__types.h';p.write_text(p.read_text().replace('#define __NO_STRICT_ALIGNMENT','/* RISC-V alignment follows the compiler ABI. */'))
    p=arch/'bsd_endian.h';s=p.read_text()
    s=s.replace('__asm ("bswap %0" : "+r" (__X));','__X = __builtin_bswap32(__X);',1)
    s=s.replace('__asm ("bswap %0" : "+r" (__X));','__X = __builtin_bswap64(__X);',1);p.write_text(s)
    p=arch/'bsd_atomic.h';old=(original/'include/x86_64/bsd_atomic.h').read_text()
    aliases=old[old.index('/*\n * Abbreviated functions'): ] if '/*\n * Abbreviated functions' in old else old[old.index('#define\tatomic_set_acq_char'):]
    # Retain upstream names/aliases below the primitive definitions.
    aliases=old[old.index('#define\tatomic_set_acq_char'):old.rindex('#endif /* !WANT_FUNCTIONS */')]
    prefix='''/* RISC-V LP64 port: GCC atomics preserve lock and ordering semantics. */
#ifndef _BSD_MACHINE_ATOMIC_H_
#define _BSD_MACHINE_ATOMIC_H_
#define mb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
#define rmb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
#define wmb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
'''
    for name,typ in [('char','u_char'),('short','u_short'),('int','u_int'),('long','u_long')]:
        for operation,builtin,value in [('set','or','v'),('clear','and',f'({typ})~v'),('add','add','v'),('subtract','sub','v')]:
            for barr in ['', '_barr']:
                prefix+=f'static __inline void atomic_{operation}{barr}_{name}(volatile {typ} *p, {typ} v) {{ __atomic_fetch_{builtin}(p,{value},__ATOMIC_SEQ_CST); }}\n'
        prefix+=f'''static __inline int atomic_cmpset_{name}(volatile {typ} *p,{typ} e,{typ} v) {{ return __atomic_compare_exchange_n(p,&e,v,0,__ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST); }}
static __inline {typ} atomic_fetchadd_{name}(volatile {typ} *p,{typ} v) {{ return __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }}
static __inline {typ} atomic_readandclear_{name}(volatile {typ} *p) {{ return __atomic_exchange_n(p,0,__ATOMIC_SEQ_CST); }}
static __inline {typ} atomic_load_acq_{name}(volatile {typ} *p) {{ return __atomic_load_n(p,__ATOMIC_ACQUIRE); }}
static __inline void atomic_store_rel_{name}(volatile {typ} *p,{typ} v) {{ __atomic_store_n(p,v,__ATOMIC_RELEASE); }}
'''
    p.write_text(prefix+aliases+'\n#endif\n')
    (arch/'bsd_cpufunc.h').write_text('''/* Only user-stack primitives; privileged x86 operations are not stubbed. */
#ifndef _BSD_MACHINE_CPUFUNC_H_
#define _BSD_MACHINE_CPUFUNC_H_
static __inline void cpu_spinwait(void) { __asm__ __volatile__("nop" ::: "memory"); }
static __inline unsigned long long rdtsc(void) { unsigned long v; __asm__ __volatile__("rdcycle %0" : "=r"(v) :: "memory"); return v; }
#endif
''')
    (arch/'bsd_cpu.h').write_text('''#ifndef _BSD_MACHINE_CPU_H_
#define _BSD_MACHINE_CPU_H_
#include <machine/bsd_cpufunc.h>
static __inline unsigned long long get_cyclecount(void) { return rdtsc(); }
#endif
''')
    (src/'freebsd.netinet/in_cksum_riscv64.c').write_bytes((original/'freebsd.netinet/in_cksum_x86_64.c').read_bytes())
    p=src/'host.support/uptcp_statis.c';s=(original/'host.support/uptcp_statis.c').read_text();s=s[:s.index('unsigned long long my_rdtsc()')]+'''unsigned long long my_rdtsc(void) {
    unsigned long v;
    __asm__ __volatile__("fence rw,rw; rdcycle %0; fence rw,rw" : "=r"(v) :: "memory");
    return v;
}
''';p.write_text(s)
    # Original volatile SPSC indices assume x86 store ordering. On RISC-V,
    # release publishes packet bytes; acquire observes them before consumption.
    p=src/'host.support/shmbuf_ring.h';s=(original/'host.support/shmbuf_ring.h').read_text()
    s=s.replace('br->write_off = (br->write_off + 1) % HIF_MAX_SHMBUF;',
        '__atomic_store_n(&br->write_off, (__atomic_load_n(&br->write_off, __ATOMIC_RELAXED) + 1) % HIF_MAX_SHMBUF, __ATOMIC_RELEASE);')
    s=s.replace('br->read_off = (br->read_off + 1) % HIF_MAX_SHMBUF;',
        '__atomic_store_n(&br->read_off, (__atomic_load_n(&br->read_off, __ATOMIC_RELAXED) + 1) % HIF_MAX_SHMBUF, __ATOMIC_RELEASE);')
    s=s.replace('while(next_off == br->read_off)','while(next_off == __atomic_load_n(&br->read_off, __ATOMIC_ACQUIRE))')
    s=s.replace('while(br->read_off == br->write_off)',
        'while(__atomic_load_n(&br->read_off, __ATOMIC_RELAXED) == __atomic_load_n(&br->write_off, __ATOMIC_ACQUIRE))')
    p.write_text(s)


def main():
    lock=(D/'software/network-candidate-build.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    previous=json.loads(RECEIPT.read_text()) if RECEIPT.exists() else {}
    if previous.get('status') == 'CANDIDATE_ELFS_BUILT' and previous.get('port_version') == PORT_VERSION:
        from network_binding import verify_files
        verify_files(previous)
        print(json.dumps(dict(status='CANDIDATE_ELFS_REUSED',receipt=str(RECEIPT))),flush=True)
        return 0
    if previous and previous.get('port_version')!=PORT_VERSION:
        archive=D/'software'/('network-candidate-build-v'+str(previous.get('port_version',1))+'-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json')
        save(archive,previous);previous={}
    if previous:
        out=Path(previous['output_dir'])
    else:
        stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        out=W/'software'/('network-riscv-candidate-'+stamp);out.mkdir()
        for name in ['uptcpip','netdedup','netferret','netstreamcluster']:
            group='libs' if name=='uptcpip' else 'netapps'
            shutil.copytree(P/f'pkgs/{group}/{name}/src',out/name,
                            ignore=shutil.ignore_patterns('*.o','*.a','*.so','*.o.client','*.o.sim','*.o.client.sim'))
        # Versioned copy retains this checkout's original inputs and runconf mapping.
    logs=D/'software'/out.name;logs.mkdir(exist_ok=True)
    state=dict(schema='ec-network-candidates/1',status='BUILDING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),output_dir=str(out),log_dir=str(logs),
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),commands=previous.get('commands',[]),
        checkpoints=previous.get('checkpoints',{}),programs=previous.get('programs',{}),formal_eligible=False,fpga_execution=False,
        port_version=PORT_VERSION,
        source_parsec_commit=subprocess.check_output((['runuser','-u','guozh','--'] if os.geteuid()==0 else [])+['/usr/bin/git','-C',str(P),'rev-parse','HEAD'],text=True).strip(),
        compiler_sha256=sha(T/'riscv64-unknown-linux-gnu-gcc'),hardware_modified=False)
    def checkpoint():save(RECEIPT,state);save(STATUS,state)
    checkpoint()
    def run(label,argv,cwd,timeout=3600):
        log=logs/(str(len(state['commands'])).zfill(3)+'-'+label+'.log')
        record=dict(label=label,argv=list(map(str,argv)),cwd=str(cwd),log=str(log));state['commands'].append(record)
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=cwd,env={**os.environ,'PATH':str(T)+':/usr/bin:/bin','LD_LIBRARY_PATH':''},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'],active_log=str(log));checkpoint()
            try:rc=child.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                child.terminate();child.wait(timeout=30);raise
            os.fsync(f.fileno())
        state.pop('child_pid',None);state.pop('child_start_ticks',None)
        record.update(returncode=rc,log_sha256=sha(log));checkpoint()
        if rc:raise RuntimeError(f'{label} failed {rc}; {log}')
    try:
        src=out/'uptcpip'
        built=state['checkpoints'].get('stack_libraries',{})
        if not built or not all(Path(p).exists() and sha(p)==h for p,h in built.items()):
            patch_stack(src)
            # clean applies only to this private candidate, never any original job.
            run('stack-clean',['make','clean','ARCH=riscv64'],src)
            run('stack-build',['make','-j4','ARCH=riscv64','CC='+str(T/'riscv64-unknown-linux-gnu-gcc'),'CXX='+str(T/'riscv64-unknown-linux-gnu-g++'),'GCC_OX=-O2 -g -march=rv64gc -mabi=lp64d -fcommon -fno-strict-aliasing'],src)
        libraries=list((src/'lib').glob('libuptcp*.a'));assert len(libraries)==4
        for p in libraries:
            run(p.name+'-object-architecture',[T/'riscv64-unknown-linux-gnu-objdump','-f',p],out)
        state['checkpoints']['stack_libraries']={str(p):sha(p) for p in libraries}
        state['status']='STACK_COMPILED_APPLICATIONS_PENDING';checkpoint()
        parent=json.loads((W/'software/apps-build.json').read_text())
        hooks=Path(parent['output_dir'])/'src/hooks'
        diagnostic=out/'diagnostic-hooks.c'
        diagnostic.write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {static const char m[]="EC_NETWORK_DIAGNOSTIC_ROI_BEGIN\\n";write(2,m,sizeof(m)-1);}
void __parsec_roi_end(void) {static const char m[]="EC_NETWORK_DIAGNOSTIC_ROI_END\\n";write(2,m,sizeof(m)-1);}
''')
        run('diagnostic-hooks',[T/'riscv64-unknown-linux-gnu-gcc','-O2','-march=rv64gc','-mabi=lp64d','-I'+str(hooks),'-c',diagnostic,'-o',out/'diagnostic-hooks.o'],out)
        common=['-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing','-D_GNU_SOURCE','-I'+str(src/'lib'),'-I'+str(hooks),'-DENABLE_PARSEC_HOOKS']
        deps=json.loads((W/'software/ferret-candidate-build.json').read_text())
        prefix=Path(deps['output_dir'])/'dependencies'
        zmanifest=json.loads((W/'software/dedup-staged-apps-build.json').read_text())
        z=Path(zmanifest['output_dir'])/'libz.a'
        depfiles=[z]+[prefix/'lib'/n for n in ['libgsl.a','libgslcblas.a','libjpeg.a']]
        state['reused_dependencies']={str(p):sha(p) for p in depfiles};checkpoint()
        for name in ['netstreamcluster','netdedup','netferret']:
            app=out/name
            prior=state['programs'].get(name,{})
            if prior.get('status')=='ELF_COMPILED_DIAGNOSTIC_NOT_FORMAL' and all(Path(b['path']).exists() and sha(b['path'])==b['sha256'] for b in prior['binaries'].values()):
                continue
            try:
                if name=='netstreamcluster':
                    for part in ['server','client']:
                        flags=common+['-DENABLE_PARSEC_UPTCPIP','-pthread']
                        binary=app/part/part
                        run(name+'-'+part,[T/'riscv64-unknown-linux-gnu-g++',*flags,app/part/('streamcluster.cpp' if part=='server' else 'client.cpp'),out/'diagnostic-hooks.o','-static','-L'+str(src/'lib'),'-l'+('uptcp' if part=='server' else 'uptcp.client'),'-pthread','-lm','-o',binary],app)
                elif name=='netdedup':
                    server=app/'server'
                    for n in ['e_os2.h','opensslconf.h']:
                        shutil.copy2(P/'pkgs/libs/ssl/inst/amd64-linux.gcc-serial/include/openssl'/n,server/'openssl'/n)
                    flags=common+['-I'+str(server),'-I'+str(P/'pkgs/libs/zlib/src'),'-DENABLE_PARSEC_UPTCPIP','-DENABLE_GZIP_COMPRESSION','-DENABLE_STATISTICS','-D_XOPEN_SOURCE=600']
                    units=['hashtable.c','util.c','dedup.c','rabin.c','encoder.c','decoder.c','mbuffer.c','sha.c']
                    run(name+'-server',[T/'riscv64-unknown-linux-gnu-gcc',*flags,*[server/n for n in units],out/'diagnostic-hooks.o',z,'-static','-L'+str(src/'lib'),'-luptcp','-pthread','-lm','-o',server/'netdedup'],app)
                    run(name+'-client',[T/'riscv64-unknown-linux-gnu-gcc',*flags,app/'client/dedup_client.c','-static','-L'+str(src/'lib'),'-luptcp.client','-pthread','-lm','-o',app/'client/netdedup_client'],app)
                else:
                    server=app/'server'
                    flags=' '.join(common+['-I'+str(prefix/'include'),'-I'+str(server/'include'),'-DENABLE_PARSEC_UPTCPIP','-pthread'])
                    args=['version=pthreads','CC='+str(T/'riscv64-unknown-linux-gnu-gcc'),'CXX='+str(T/'riscv64-unknown-linux-gnu-g++'),'AR='+str(T/'riscv64-unknown-linux-gnu-ar'),'CFLAGS='+flags,'LDFLAGS=-static -L'+str(prefix/'lib')+' -L'+str(src/'lib')+' -L'+str(server/'parsec/lib'),'LIBS='+str(out/'diagnostic-hooks.o')+' -pthread']
                    run(name+'-dirs',['make','dirs',*args],server)
                    run(name+'-libs',['make','-j4','lib',*args],server)
                    run(name+'-server',['make','-j4','benchmark',*args],server)
                    run(name+'-client',['make','-j4','CC='+str(T/'riscv64-unknown-linux-gnu-gcc'),'CFLAGS='+flags,'LDFLAGS=-static -L'+str(src/'lib'),'LIBS=-pthread'],app/'client')
                expected=({'netstreamcluster':['server/server','client/client'],
                           'netdedup':['server/netdedup','client/netdedup_client'],
                           'netferret':['server/parsec/bin/ferret-pthreads','client/client']})[name]
                bins={}
                for relative in expected:
                    p=app/relative
                    run(name+'-'+p.name+'-elf',[T/'riscv64-unknown-linux-gnu-readelf','-h','-l',p],out)
                    bins[relative]=dict(path=str(p),sha256=sha(p))
                state['programs'][name]=dict(status='ELF_COMPILED_DIAGNOSTIC_NOT_FORMAL',binaries=bins,
                    original_roi_preserved=True,offline_protocol_validation='NOT_RUN',fpga_validation='NOT_RUN')
            except Exception as e:
                state['programs'][name]=dict(status='BUILD_FAILED_WITH_EVIDENCE',error=repr(e))
            checkpoint()
        state['status']='CANDIDATE_ELFS_BUILT' if all(p['status']=='ELF_COMPILED_DIAGNOSTIC_NOT_FORMAL' for p in state['programs'].values()) else 'APPLICATION_BUILD_FAILURES_RETAINED'
    except Exception as e:
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(e))
    finally:
        # Diff only candidate source/header/build files; no binary or object noise.
        patches=[]
        for name in ['uptcpip','netdedup','netferret','netstreamcluster']:
            original=P/f'pkgs/{"libs" if name=="uptcpip" else "netapps"}/{name}/src'
            for f in sorted((out/name).rglob('*')):
                if not f.is_file() or not (f.suffix in ['.c','.h','.cpp'] or f.name.startswith('Makefile')):continue
                if name=='uptcpip' and 'machine' in f.relative_to(out/name).parts:continue
                relative=f.relative_to(out/name);base=original/relative
                before=base.read_text(errors='replace') if base.exists() else ''
                after=f.read_text(errors='replace')
                if before!=after:patches+=difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=f'a/{name}/{relative}',tofile=f'b/{name}/{relative}')
        patch=logs/'candidate.patch';patch.write_text(''.join(patches))
        state.update(patch=str(patch),patch_sha256=sha(patch),updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());checkpoint()
        save(logs/('build-result-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json'),state)
        print(json.dumps(dict(status=state['status'],receipt=str(RECEIPT),error=state.get('error'))),flush=True)
    return 0 if state['status']!='FAILED_WITH_EVIDENCE' else 2


if __name__=='__main__':raise SystemExit(main())
