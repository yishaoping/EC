#!/usr/bin/env python3
"""Independent framed-I/O/end-tag repair; original Ferret pipeline/ROI retained."""
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha

HELPERS=r'''
/* Transport framing only: computation, pipeline and original ROI are retained. */
static void ec_send_exact(int fd, const void *buf, size_t bytes) {
    const char *p = buf;
    while (bytes) {
#ifdef ENABLE_PARSEC_UPTCPIP
        ssize_t n = uptcp_send(fd, p, bytes, 0);
#else
        ssize_t n = send(fd, p, bytes, 0);
#endif
        if (n <= 0) { perror("ec_send_exact"); exit(1); }
        p += n; bytes -= n;
    }
}
static void ec_recv_exact(int fd, void *buf, size_t bytes) {
    char *p = buf;
    while (bytes) {
#ifdef ENABLE_PARSEC_UPTCPIP
        ssize_t n = uptcp_recv(fd, p, bytes, 0);
#else
        ssize_t n = recv(fd, p, bytes, 0);
#endif
        if (n <= 0) { perror("ec_recv_exact: incomplete frame"); exit(1); }
        p += n; bytes -= n;
    }
}
static void ec_close_end(int fd) {
    struct linger linger = {1, 30};
#ifdef ENABLE_PARSEC_UPTCPIP
    /* UpTCP forwards BSD option numbers directly; these are BSD constants. */
    if (uptcp_setsockopt(fd, 0xffff, 0x0080, &linger, sizeof(linger)) != 0 || uptcp_close(fd) != 0) {
#else
    if (setsockopt(fd, SOL_SOCKET, SO_LINGER, &linger, sizeof(linger)) != 0 || close(fd) != 0) {
#endif
        perror("ec_close_end"); exit(1);
    }
}
'''

def main():
    lock=(D/'software/netferret-protocol.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    R=D/'software/netferret-protocol-preparation.json'
    if R.exists():
        st=json.loads(R.read_text())
        if st.get('status')=='COMPLETE_REVIEW_EVIDENCE':return
    else:
        stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        st=dict(schema='ec-netferret-protocol-candidate/1',status='BUILDING',output_dir=str(W/'software'/('netferret-protocol-'+stamp)),
            log_dir=str(D/'software'/('netferret-protocol-'+stamp)),formal_eligible=False,fpga_execution=False,
            original_algorithm_pipeline_and_roi_preserved=True)
    out=Path(st['output_dir']);out.mkdir(exist_ok=True);logs=Path(st['log_dir']);logs.mkdir(exist_ok=True);save(R,st)
    base=json.loads((W/'software/network-candidate-build.json').read_text());src=Path(base['output_dir'])
    client=src/'netferret/client/client.c';server=src/'netferret/server/benchmark/ferret-pthreads.c'
    sources={}
    for name,p in [('client',client),('server',server)]:
        s=p.read_text();s=s.replace('void send_end_tag()',HELPERS+'\nvoid send_end_tag()',1) if name=='client' else s.replace('void *t_acceptor (void *dummy)',HELPERS+'\nvoid *t_acceptor (void *dummy)',1)
        if name=='client':
            start=s.index('#ifdef ENABLE_PARSEC_UPTCPIP\n        if (uptcp_send(fd, &end_tag')
            end=s.index('\n}',start)
            s=s[:start]+'        ec_send_exact(fd, &end_tag, sizeof(end_tag));\n        ec_close_end(fd);\n'+s[end:]
            start=s.index('\t        int bytes_left = pkt_ptr->len + sizeof(int);')
            end=s.index('\n\t\t/* 5. write results */',start)
            s=s[:start]+'''        ec_send_exact(fd, pkt_ptr, pkt_ptr->len + sizeof(int));
        ec_recv_exact(fd, &pkt_ptr->len, sizeof(pkt_ptr->len));
        if (pkt_ptr->len < 0 || pkt_ptr->len > MAX_SOCKET_BUF - sizeof(int)) {
            fprintf(stderr, "Invalid result frame length\\n"); exit(1);
        }
        ec_recv_exact(fd, pkt_ptr->buf, pkt_ptr->len);
'''+s[end:]
            block='''		if(cnt_enqueue == cnt_dequeue){ /* last item */
			send_end_tag();
		}'''
            assert block in s;s=s.replace(block,'\t\t/* End tag follows both joined producer/consumer pools. */')
            token='\ttpool_join(p_load, NULL);';assert s.count(token)==1;s=s.replace(token,token+'\n\tsend_end_tag();')
        else:
            s=s.replace('socklen_t \t\taddrlen;','socklen_t \t\taddrlen = sizeof(pin);')
            start=s.index('\t\twhile(bytes_recv < bytes_input)')
            end=s.index('\n\n\t\t/* 3. enqueue */',start)
            s=s[:start]+'''        ec_recv_exact(fd, &pkt_ptr->len, sizeof(pkt_ptr->len));
        if (pkt_ptr->len == -1) {
#ifdef ENABLE_PARSEC_UPTCPIP
            parsec_exit_tcpip_roi();
#endif
            ec_close_end(fd);
            goto exit;
        }
        if (pkt_ptr->len < 0 || pkt_ptr->len > MAX_SOCKET_BUF - sizeof(int)) {
            fprintf(stderr, "Invalid query frame length\\n"); exit(1);
        }
        ec_recv_exact(fd, pkt_ptr->buf, pkt_ptr->len);
'''+s[end:]
            start=s.index('#ifdef ENABLE_PARSEC_UPTCPIP\n\t\tif (uptcp_send(rank->fd')
            end=s.index('\n\n\t\tcass_result_free',start)
            s=s[:start]+'        ec_send_exact(rank->fd, sendbuf, bufsize);'+s[end:]
        target=out/(name+'.c');target.write_text(s);sources[name]=target
    patch=logs/'candidate.patch';patch.write_text(''.join(''.join(difflib.unified_diff(p.read_text().splitlines(True),sources[n].read_text().splitlines(True),fromfile='a/'+n+'.c',tofile='b/'+n+'.c')) for n,p in [('client',client),('server',server)]))
    T=W.parent/'envs/manager-1.17.1/riscv-tools/bin'
    deps=json.loads((W/'software/ferret-candidate-build.json').read_text());prefix=Path(deps['output_dir'])/'dependencies'
    parent=json.loads((W/'software/apps-build.json').read_text());hooks=Path(parent['output_dir'])/'src/hooks'
    sbase=src/'netferret/server';libs=sbase/'parsec/lib'
    flags=['-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing','-D_GNU_SOURCE','-DENABLE_PARSEC_HOOKS','-DENABLE_PARSEC_UPTCPIP',
        '-I'+str(src/'uptcpip/lib'),'-I'+str(hooks),'-I'+str(sbase/'include'),'-I'+str(prefix/'include')]
    def run(label,argv):
        log=logs/(label+'.log')
        if log.exists():log.rename(log.with_name(label+'-before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.log'))
        with log.open('wb') as f:rc=subprocess.run(['nice','-n','15',*map(str,argv)],stdout=f,stderr=subprocess.STDOUT,timeout=300).returncode
        st.setdefault('commands',[]).append(dict(argv=list(map(str,argv)),log=str(log),returncode=rc));save(R,st);assert rc==0,label
    obj=out/'server.o';run('server-object',[T/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',sources['server'],'-o',obj])
    sb=out/'netferret/server/parsec/bin/ferret-pthreads';sb.parent.mkdir(parents=True,exist_ok=True)
    cb=out/'netferret/client/client';cb.parent.mkdir(parents=True,exist_ok=True)
    run('server-link',[T/'riscv64-unknown-linux-gnu-g++','-static',obj,src/'diagnostic-hooks.o','-L'+str(libs),'-L'+str(prefix/'lib'),'-L'+str(src/'uptcpip/lib'),
        '-Wl,--start-group','-lcass','-lcassimage','-lgsl','-lgslcblas','-ljpeg','-luptcp','-Wl,--end-group','-pthread','-lrt','-lm','-o',sb])
    run('client',[T/'riscv64-unknown-linux-gnu-gcc',*flags,'-I'+str(client.parent),sources['client'],client.parent/'tpool.c',sbase/'src/queue.c','-static','-L'+str(src/'uptcpip/lib'),'-luptcp.client','-pthread','-lm','-o',cb])
    manifest=copy.deepcopy(base);manifest.update(profile='netferret-framed-close-candidate/1',parent_receipt_sha256=sha(W/'software/network-candidate-build.json'),
        output_dir=str(out),integration_patch=dict(path=str(patch),sha256=sha(patch)),formal_eligible=False)
    manifest['programs']['netferret']['binaries']={n:dict(path=str(p),sha256=sha(p)) for n,p in [('server/parsec/bin/ferret-pthreads',sb),('client/client',cb)]}
    receipt=W/'software/netferret-protocol-candidate-build.json';save(receipt,manifest)
    st.update(status='VALIDATING',receipt=str(receipt),patch=str(patch),patch_sha256=sha(patch),binaries=manifest['programs']['netferret']['binaries']);save(R,st)
    user=out/'validate-user.py';user.write_text((W/'scripts/validate_network_candidates.py').read_text().replace("W/'software/network-candidate-build.json'","W/'software/netferret-protocol-candidate-build.json'"))
    for size in ['test','simsmall','simmedium']:
        dst=logs/('user-'+size)
        if (dst/'result.json').exists():continue
        dst.mkdir(exist_ok=True)
        with (dst/'launch.log').open('wb') as f:
            rc=subprocess.run(['unshare','--ipc','--mount','--net','--fork','python3',str(user),'--case','netferret','--size',size,'--out',str(dst)],
                stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts'),'EC_NETWORK_NO_TRACE':'1'},timeout=1900).returncode
        st.setdefault('user_cases',[]).append(dict(input=size,result=str(dst/'result.json'),returncode=rc));save(R,st)
    linux=out/'validate-linux.py';s=(W/'scripts/validate_network_linux.py').read_text()
    for old,new in [("W/'software/network-candidate-build.json'","W/'software/netferret-protocol-candidate-build.json'"),
                    ("'software/network-linux-validation.lock'","'software/netferret-protocol-linux-validation.lock'"),
                    ("R=D/'software/network-linux-validation.json'","R=D/'software/netferret-protocol-linux-validation.json'"),
                    ("'network-linux-'+stamp","'netferret-protocol-linux-'+stamp"),
                    ("for name in ['netdedup','netferret','netstreamcluster']:","for name in ['netferret']:"),
                    ('CLIENT > /run/client.log 2>&1 &','CLIENT &'),('SERVER > /run/server.log 2>&1 &','SERVER &'),
                    ('/bin/busybox cat /run/server.log','true'),('/bin/busybox cat /run/client.log','true')]:s=s.replace(old,new)
    linux.write_text(s)
    with (logs/'linux-launch.log').open('wb') as f:
        rc=subprocess.run(['python3',str(linux)],stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts')},timeout=5400).returncode
    st.update(status='COMPLETE_REVIEW_EVIDENCE' if rc==0 else 'LINUX_LAUNCH_FAILED_WITH_EVIDENCE',linux_returncode=rc,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
