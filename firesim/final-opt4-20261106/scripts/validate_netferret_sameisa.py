#!/usr/bin/env python3
"""Bounded QEMU user tests of original user-TCP server/client pairs.

Each case gets private IPC, network and mount namespaces, including /tmp.
No host IPC keys, FPGA devices, existing guests or queue inputs are touched.
"""
import argparse
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import signal
import subprocess
import tarfile
import time

from board_batch import W,D,save,sha
from job_service import proc

P=Path('/data1/gzh/EC/Software/PARSEC')
S=W/'scripts/validate_network_candidates.py'
RECEIPT=D/'software/network-offline-validation.json'


def read(p,default=None):return json.loads(Path(p).read_text()) if Path(p).exists() else default


def case(program,size,out,arch='riscv64'):
    assert os.geteuid()==0
    # mount propagation is private before mounting a temporary test /tmp.
    subprocess.run(['mount','--make-rprivate','/'],check=True)
    subprocess.run(['mount','-t','tmpfs','-o','size=128m','tmpfs','/tmp'],check=True)
    build=read(W/'software/network-candidate-build.json');src=Path(build['output_dir'])/program
    compiled=build['programs'][program]
    assert compiled['status']=='ELF_COMPILED_DIAGNOSTIC_NOT_FORMAL'
    for b in compiled['binaries'].values():assert sha(b['path'])==b['sha256']
    if arch=='x86_64':
        host=read(D/'software/network-host-reference.json');assert host['status']=='COMPILED'
        src=Path(host['output_dir'])/program
        compiled=dict(binaries={str(p):dict(path=str(p),sha256=h) for p,h in host['binaries'].items() if Path(p).is_relative_to(src)})
        for b in compiled['binaries'].values():assert sha(b['path'])==b['sha256']
    if arch=='riscv64-kernel':
        assert program=='netferret'
        ref=read(D/'software/netferret-kernel-reference.json');assert ref['status']=='COMPILED'
        src=Path(ref['output_dir'])/program
        compiled=dict(binaries=ref['binaries'])
        for b in compiled['binaries'].values():assert sha(b['path'])==b['sha256']
        # Only the newly created private network namespace is configured.
        subprocess.run(['/usr/sbin/ip','link','set','lo','up'],check=True)
        subprocess.run(['/usr/sbin/ip','addr','add','10.10.10.12/32','dev','lo'],check=True)
    trace_enabled=arch=='riscv64' and size=='test' and os.environ.get('EC_NETWORK_NO_TRACE')!='1'
    prefix=['/usr/bin/qemu-riscv64']+(['-strace'] if trace_enabled else []) if arch.startswith('riscv64') else []
    work=out/'work';work.mkdir()
    input_receipt=None
    if program!='netstreamcluster':
        package='kernels/dedup' if program=='netdedup' else 'apps/ferret'
        archive=P/'pkgs'/package/'inputs'/('input_'+size+'.tar')
        with tarfile.open(archive) as tar:
            members=tar.getmembers()
            assert all(not Path(x.name).is_absolute() and '..' not in Path(x.name).parts and not x.issym() and not x.islnk() for x in members)
            tar.extractall(work)
        input_receipt=dict(path=str(archive),sha256=sha(archive))
    if program=='netstreamcluster':
        # Preserve the actual local simmedium.runconf -> simlarge mapping.
        dim,chunk,n,kmin,kmax,center=(1,10,10,2,5,5) if size=='test' else ((32,4096,4096,10,20,1000) if size=='simsmall' else (128,16384,16384,10,20,1000))
        server=[src/'server/server',str(kmin),str(kmax),str(dim),str(n),str(chunk),str(center),'none','output.txt','1']
        client=[src/'client/client',str(dim),str(n),str(chunk),'1']
        expected=work/'output.txt'
    elif program=='netdedup':
        # The broken formal runconf mixes client options into the server.
        # Diagnostic repair separates them, retaining the archive's media.dat.
        infile='test.dat' if size=='test' else 'media.dat'
        server=[src/'server/netdedup','-c','-v','-t','1','-o','out.ddp']
        client=[src/'client/netdedup_client','-i',infile]
        expected=work/'out.ddp'
    else:
        server=[src/'server/parsec/bin/ferret-pthreads','corel','lsh','5' if size=='test' else '10','5' if size=='test' else '20','1']
        client=[src/'client/client','queries','1','output.txt']
        expected=work/'output.txt'
    state=dict(schema='ec-network-qemu-case/1',program=program,input=size,status='RUNNING',
        pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        server_argv=list(map(str,server)),client_argv=list(map(str,client)),binaries=compiled['binaries'],
        input_archive=input_receipt,private_ipc_namespace=True,private_mount_namespace=True,private_network_namespace=True,
        namespaces={n:os.readlink('/proc/self/ns/'+n) for n in ['ipc','mnt','net']},formal_eligible=False,fpga_run=False,
        roi='Original application hook sites; diagnostic writes only, no checker claim',source_receipt_sha256=sha(W/'software/network-candidate-build.json'),
        architecture=arch,trace_enabled=trace_enabled,
        mapping_note='simmedium invokes original simlarge for netstreamcluster; netdedup candidate separates server/client flags and uses unchanged formal archive')
    save(out/'state.json',state)
    streams=[];children=[];start=time.monotonic();timeout=180 if size=='test' else 1800
    try:
        # Client-first order follows upstream wrappers. User TCP initialization
        # and retransmission perform the handshake when the server starts.
        peers=[('server',server),('client',client)] if arch=='riscv64-kernel' else [('client',client),('server',server)]
        for label,argv in peers:
            f=(out/(label+'.log')).open('wb',buffering=0);streams.append(f)
            p=subprocess.Popen(['nice','-n','15',*prefix,*map(str,argv)],cwd=work,
                stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,start_new_session=True,
                env={**os.environ,'LD_LIBRARY_PATH':'','UPTCPIP_RX_THREADS':'1'})
            children.append((label,p));state.setdefault('children',{})[label]=proc(p.pid)
            if arch=='riscv64-kernel' and label=='server':
                # Wait for this process's listener, avoiding a connect race.
                deadline=time.monotonic()+15
                while not any(line.split()[1].endswith(':A52D') and line.split()[3]=='0A' for line in Path('/proc/net/tcp').read_text().splitlines()[1:]):
                    assert p.poll() is None,'kernel reference server exited before listen'
                    if time.monotonic()>deadline:raise TimeoutError('private kernel reference listen')
                    time.sleep(.05)
        save(out/'state.json',state)
        while any(p.poll() is None for _,p in children):
            if time.monotonic()-start>timeout:raise TimeoutError('bounded original-protocol QEMU case timeout')
            if any((out/(label+'.log')).stat().st_size>64*2**20 for label,_ in children):raise RuntimeError('64 MiB diagnostic log budget')
            # A concrete error in either peer must not leave its mate running.
            if any(p.poll() not in [None,0] for _,p in children):raise RuntimeError('nonzero server/client exit')
            try:children[0][1].wait(timeout=2)
            except subprocess.TimeoutExpired:pass
            time.sleep(.2)
        exits={label:p.returncode for label,p in children};state['exit_codes']=exits
        assert all(v==0 for v in exits.values()),exits
        assert expected.exists() and expected.stat().st_size>0,'missing complete output'
        state['output']=dict(path=str(expected),sha256=sha(expected),bytes=expected.stat().st_size)
        server_text=(out/'server.log').read_text(errors='replace')
        assert server_text.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==1 and server_text.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1,'incomplete original ROI markers'
        if program=='netdedup':
            with (out/'decode.log').open('wb') as f:
                rc=subprocess.run((['/usr/bin/qemu-riscv64'] if arch=='riscv64' else [])+[str(src/'server/netdedup'),'-u','-o','decoded.dat'],cwd=work,stdout=f,stderr=subprocess.STDOUT,timeout=180).returncode
            assert rc==0 and sha(work/'decoded.dat')==sha(work/infile),'full dedup decode comparison failed'
            state['correctness']=dict(method='decode entire compressed stream and byte SHA256 versus original input',passed=True,input_sha256=sha(work/infile),decoded_sha256=sha(work/'decoded.dat'))
        elif program=='netferret':
            queries=sorted(p.name for p in (work/'queries').rglob('*') if p.is_file())
            lines=expected.read_text().splitlines()
            assert len(lines)==len(queries),'not all query results returned'
            assert all(any(q in line for line in lines) for q in queries),'query/result name mismatch'
            state['correctness']=dict(method='all input query names returned; numerical reference comparison remains pending',queries=len(queries),results=len(lines),passed=False)
        else:
            state['correctness']=dict(method='complete clustering output produced; cross-reference comparison remains pending',passed=False)
        state['status']='PROTOCOL_AND_DECODE_PASSED' if program=='netdedup' else 'PROTOCOL_COMPLETED_REFERENCE_PENDING'
    except Exception as e:state.update(status='FAILED_WITH_EVIDENCE',error=repr(e))
    finally:
        for _,p in children:
            if p.poll() is None:
                os.killpg(p.pid,signal.SIGTERM)
                try:p.wait(timeout=10)
                except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
        for f in streams:f.flush();os.fsync(f.fileno());f.close()
        state['exit_codes']={label:p.returncode for label,p in children}
        text=(out/'server.log').read_text(errors='replace') if (out/'server.log').exists() else ''
        begin=text.find('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN');end=text.find('EC_NETWORK_DIAGNOSTIC_ROI_END',begin)
        region=text[begin:end if end>=0 else None] if begin>=0 else ''
        calls=re.findall(r'\b\d+\s+([A-Za-z_][A-Za-z_0-9]*)\(',region)
        state['roi_diagnostic']=dict(begin_seen=begin>=0,end_seen=end>=0,syscall_counts={n:calls.count(n) for n in sorted(set(calls))},time_base='host QEMU trace order only; no target cycles or checker latency',source='server.log; diagnostic marker writes remain visible')
        state.update(wall_seconds=time.monotonic()-start,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(out/'state.json',state);save(out/'result.json',state)
    return 0 if state['status']!='FAILED_WITH_EVIDENCE' else 2


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--case');ap.add_argument('--size',default='test');ap.add_argument('--out',type=Path);ap.add_argument('--arch',default='riscv64');a=ap.parse_args()
    if a.case:return case(a.case,a.size,a.out,a.arch)
    assert os.geteuid()==0
    lock=(D/'software/network-offline-validation.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    build=read(W/'software/network-candidate-build.json');assert build['status']=='CANDIDATE_ELFS_BUILT'
    if RECEIPT.exists():
        old=read(RECEIPT);archive=D/'software'/('network-offline-before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json');save(archive,old)
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    root=D/'software'/('network-qemu-'+stamp);root.mkdir()
    state=dict(schema='ec-network-offline-validation/1',status='RUNNING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),output_dir=str(root),
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),cases=[],formal_eligible=False,fpga_execution=False,
        no_host_ipc_cleanup=True,no_hardware_or_scheduler_modifications=True)
    save(RECEIPT,state)
    def launch(argv,log,stage):
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(argv,cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'],active_program=stage);save(RECEIPT,state)
            rc=child.wait()
        state.pop('child_pid',None);state.pop('child_start_ticks',None);save(RECEIPT,state)
        return rc
    rc=launch(['/usr/bin/python3',str(W/'scripts/build_network_host_reference.py')],root/'reference-build.log','host-reference-build')
    if rc:
        state.update(status='REFERENCE_BUILD_FAILED_WITH_EVIDENCE');save(RECEIPT,state);return 2
    # First visit each tiny case, then larger original archives; retain failures.
    failed=set()
    for size in ['test','simsmall','simmedium']:
        for name in ['netdedup','netstreamcluster','netferret']:
            if name in failed:continue
            pair={}
            for arch in ['x86_64','riscv64']:
                out=root/(name+'-'+size+'-'+arch);out.mkdir()
                argv=['unshare','--ipc','--mount','--net','--fork','/usr/bin/python3',str(S),'--case',name,'--size',size,'--arch',arch,'--out',str(out)]
                rc=launch(argv,out/'launch.log',name+'-'+size+'-'+arch)
                result=read(out/'result.json',dict(status='NAMESPACE_OR_LAUNCH_FAILED',returncode=rc))
                entry=dict(program=name,input=size,architecture=arch,result=str(out/'result.json'),status=result['status'],returncode=rc)
                state['cases'].append(entry);pair[arch]=result;save(RECEIPT,state)
                if rc:failed.add(name)
            if all('output' in pair.get(arch,{}) for arch in ['x86_64','riscv64']):
                exact=pair['x86_64']['output']['sha256']==pair['riscv64']['output']['sha256']
                comparison=dict(program=name,input=size,exact_bytes=exact,host_output=pair['x86_64']['output'],riscv_output=pair['riscv64']['output'],
                    interpretation='Full output SHA256 comparison to separately compiled original x86 user-TCP algorithm; QEMU only, not FPGA/checker proof')
                state.setdefault('comparisons',[]).append(comparison)
                if not exact:failed.add(name)
                save(RECEIPT,state)
    state.update(status='COMPLETE_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(RECEIPT,state)
    print(json.dumps(state['cases']),flush=True)


if __name__=='__main__':raise SystemExit(main())
