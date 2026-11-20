#!/usr/bin/env python3
"""Length-framed Netdedup transport candidate, preserving full declared input."""
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha

def main():
    lock=(D/'software/netdedup-framed.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    R=D/'software/netdedup-framed-preparation.json'
    if R.exists():
        st=json.loads(R.read_text())
        if st.get('status')=='COMPLETE_REVIEW_EVIDENCE':return
    else:
        stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        st=dict(schema='ec-netdedup-framed-candidate/1',status='BUILDING',output_dir=str(W/'software'/('netdedup-framed-'+stamp)),
            log_dir=str(D/'software'/('netdedup-framed-'+stamp)),formal_eligible=False,fpga_execution=False,
            scope='Read exact original declared payload length, require every input byte, retain original compression/ROI, never use early EOF as success')
    out=Path(st['output_dir']);out.mkdir(exist_ok=True);logs=Path(st['log_dir']);logs.mkdir(exist_ok=True);save(R,st)
    base=json.loads((W/'software/network-candidate-build.json').read_text());src=Path(base['output_dir'])
    server=src/'netdedup/server';original=server/'encoder.c';s=original.read_text()
    start=s.index('void *SerialIntegratedPipeline(');end=s.index('#endif //ENABLE_PTHREADS',start)
    # The serial routine has nested preprocessor branches; isolate through its
    # following Fragment function comment, not by editing the parallel path.
    end=s.index('void *Fragment(',start)
    region=s[start:end]
    assert region.count('while(bytes_read < MAXBUF)')==1
    region=region.replace('  int r;','  int r;\n  size_t ec_remaining = stats.total_input;',1)
    region=region.replace('while(bytes_read < MAXBUF) {','while(bytes_read < MAXBUF) {\n      if (ec_remaining == 0) break;\n      size_t ec_want = MAXBUF-bytes_read < ec_remaining ? MAXBUF-bytes_read : ec_remaining;',1)
    region=region.replace('MAXBUF-bytes_read, 0);','ec_want, 0);')
    assert region.count('if(r==0) break;')==1
    region=region.replace('if(r==0) break;','if(r==0) { EXIT_TRACE("Truncated declared network payload\\n"); }\n        ec_remaining -= r;',1)
    s=s[:start]+region+s[end:]
    before='''#ifdef ENABLE_PARSEC_UPTCPIP
  if (uptcp_recv(fd, &bytes_input, sizeof(size_t), 0) < 0) {
#else
  if (recv(fd, &bytes_input, sizeof(size_t), 0) < 0) {
#endif
       EXIT_TRACE("recv() size failed: %s\\n", strerror(errno));
  }'''
    assert before in s
    after='''  size_t ec_header_bytes = 0;
  while (ec_header_bytes < sizeof(bytes_input)) {
#ifdef ENABLE_PARSEC_UPTCPIP
    ssize_t ec_n = uptcp_recv(fd, (char *)&bytes_input + ec_header_bytes, sizeof(bytes_input) - ec_header_bytes, 0);
#else
    ssize_t ec_n = recv(fd, (char *)&bytes_input + ec_header_bytes, sizeof(bytes_input) - ec_header_bytes, 0);
#endif
    if (ec_n <= 0) EXIT_TRACE("Incomplete network length header\\n");
    ec_header_bytes += ec_n;
  }'''
    s=s.replace(before,after,1)
    encoder=out/'encoder.c';encoder.write_text(s)
    patch=logs/'candidate.patch';patch.write_text(''.join(difflib.unified_diff(original.read_text().splitlines(True),s.splitlines(True),fromfile='a/server/encoder.c',tofile='b/server/encoder.c')))
    T=W.parent/'envs/manager-1.17.1/riscv-tools/bin';parent=json.loads((W/'software/apps-build.json').read_text());hooks=Path(parent['output_dir'])/'src/hooks'
    z=json.loads((W/'software/dedup-staged-apps-build.json').read_text());zlib=Path(z['output_dir'])/'libz.a'
    flags=['-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing','-D_GNU_SOURCE','-I'+str(src/'uptcpip/lib'),
        '-I'+str(hooks),'-I'+str(server),'-I/data1/gzh/EC/Software/PARSEC/pkgs/libs/zlib/src','-DENABLE_PARSEC_HOOKS','-DENABLE_PARSEC_UPTCPIP',
        '-DENABLE_GZIP_COMPRESSION','-DENABLE_STATISTICS','-D_XOPEN_SOURCE=600']
    sb=out/'netdedup/server/netdedup';sb.parent.mkdir(parents=True,exist_ok=True)
    units=[server/n for n in ['hashtable.c','util.c','dedup.c','rabin.c']]+[encoder]+[server/n for n in ['decoder.c','mbuffer.c','sha.c']]
    argv=[T/'riscv64-unknown-linux-gnu-gcc',*flags,*units,src/'diagnostic-hooks.o',zlib,'-static','-L'+str(src/'uptcpip/lib'),'-luptcp','-pthread','-lm','-o',sb]
    with (logs/'build.log').open('wb') as f:rc=subprocess.run(['nice','-n','15',*map(str,argv)],stdout=f,stderr=subprocess.STDOUT,timeout=300).returncode
    assert rc==0
    client=json.loads((W/'software/netdedup-linger-candidate-build.json').read_text())['programs']['netdedup']['binaries']['client/netdedup_client']
    cb=out/'netdedup/client/netdedup_client';cb.parent.mkdir(exist_ok=True)
    if not cb.exists():cb.symlink_to(client['path'])
    manifest=copy.deepcopy(base);manifest.update(profile='netdedup-length-framed-candidate/1',output_dir=str(out),formal_eligible=False,
        parent_receipt_sha256=sha(W/'software/network-candidate-build.json'),integration_patch=dict(path=str(patch),sha256=sha(patch)),
        client_receipt=str(W/'software/netdedup-linger-candidate-build.json'),client_receipt_sha256=sha(W/'software/netdedup-linger-candidate-build.json'))
    manifest['programs']['netdedup']['binaries']={'server/netdedup':dict(path=str(sb),sha256=sha(sb)),'client/netdedup_client':client}
    receipt=W/'software/netdedup-framed-candidate-build.json';save(receipt,manifest)
    st.update(status='VALIDATING',receipt=str(receipt),patch=str(patch),patch_sha256=sha(patch),binaries=manifest['programs']['netdedup']['binaries']);save(R,st)
    user=out/'validate-user.py';user.write_text((W/'scripts/validate_network_candidates.py').read_text().replace("W/'software/network-candidate-build.json'","W/'software/netdedup-framed-candidate-build.json'"))
    for size in ['test','simsmall','simmedium']:
        dst=logs/('user-'+size)
        if (dst/'result.json').exists():continue
        dst.mkdir(exist_ok=True)
        with (dst/'launch.log').open('wb') as f:
            rc=subprocess.run(['unshare','--ipc','--mount','--net','--fork','python3',str(user),'--case','netdedup','--size',size,'--out',str(dst)],
                stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts'),'EC_NETWORK_NO_TRACE':'1'},timeout=1900).returncode
        st.setdefault('user_cases',[]).append(dict(input=size,result=str(dst/'result.json'),returncode=rc));save(R,st)
    linux=out/'validate-linux.py';s=(W/'scripts/validate_network_linux.py').read_text()
    for old,new in [("W/'software/network-candidate-build.json'","W/'software/netdedup-framed-candidate-build.json'"),
                    ("'software/network-linux-validation.lock'","'software/netdedup-framed-linux-validation.lock'"),
                    ("R=D/'software/network-linux-validation.json'","R=D/'software/netdedup-framed-linux-validation.json'"),
                    ("'network-linux-'+stamp","'netdedup-framed-linux-'+stamp"),
                    ("for name in ['netdedup','netferret','netstreamcluster']:","for name in ['netdedup']:"),
                    ('CLIENT > /run/client.log 2>&1 &','CLIENT &'),('SERVER > /run/server.log 2>&1 &','SERVER &'),
                    ('/bin/busybox cat /run/server.log','true'),('/bin/busybox cat /run/client.log','true')]:s=s.replace(old,new)
    linux.write_text(s)
    with (logs/'linux-launch.log').open('wb') as f:
        rc=subprocess.run(['python3',str(linux)],stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts')},timeout=5400).returncode
    st.update(status='COMPLETE_REVIEW_EVIDENCE' if rc==0 else 'LINUX_LAUNCH_FAILED_WITH_EVIDENCE',linux_returncode=rc,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
