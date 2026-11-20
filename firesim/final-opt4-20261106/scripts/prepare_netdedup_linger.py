#!/usr/bin/env python3
"""Netdedup candidate: keep user TCP alive for graceful FIN drain on exit."""
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

def main():
    lock=(D/'software/netdedup-linger.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    R=D/'software/netdedup-linger-preparation.json'
    if R.exists():
        st=json.loads(R.read_text())
        if st.get('status')=='COMPLETE_REVIEW_EVIDENCE' and st.get('linux_returncode')==0:return
    else:
        stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        st=dict(schema='ec-netdedup-linger-candidate/1',status='BUILDING',output_dir=str(W/'software'/('netdedup-linger-'+stamp)),
            log_dir=str(D/'software'/('netdedup-linger-'+stamp)),formal_eligible=False,fpga_execution=False,
            algorithm_unchanged=True,original_server_roi_unchanged=True)
    out=Path(st['output_dir']);out.mkdir(exist_ok=True);logs=Path(st['log_dir']);logs.mkdir(exist_ok=True);save(R,st)
    base=json.loads((W/'software/network-candidate-build.json').read_text());src=Path(base['output_dir'])
    original=src/'netdedup/client/dedup_client.c';text=original.read_text()
    before='\tuptcp_close(sd);'
    after='''	/* UpTCP owns the TX/FIN worker threads in this process. BSD socket
	 * option numbers are used by uptcp_setsockopt without Linux translation.
	 * Keep the process alive until graceful close finishes, rather than
	 * terminating its workers with outstanding data/FIN on a single CPU. */
	struct linger ec_linger = { 1, 30 };
	if (uptcp_setsockopt(sd, 0xffff /* BSD SOL_SOCKET */,
	                    0x0080 /* BSD SO_LINGER */,
	                    &ec_linger, sizeof(ec_linger)) != 0)
		EXIT_TRACE("Socket error: graceful linger option failed\\n");
	if (uptcp_close(sd) != 0)
		EXIT_TRACE("Socket error: graceful close failed\\n");'''
    assert text.count(before)==1
    target=out/'dedup_client.c';target.write_text(text.replace(before,after))
    patch=logs/'candidate.patch';patch.write_text(''.join(difflib.unified_diff(text.splitlines(True),target.read_text().splitlines(True),fromfile='a/client/dedup_client.c',tofile='b/client/dedup_client.c')))
    # Reuse validated dependencies and the unchanged v2 server.
    T=W.parent/'envs/manager-1.17.1/riscv-tools/bin'
    parent=json.loads((W/'software/apps-build.json').read_text());hooks=Path(parent['output_dir'])/'src/hooks'
    argv=[str(T/'riscv64-unknown-linux-gnu-gcc'),'-O2','-g','-march=rv64gc','-mabi=lp64d','-fcommon','-fno-strict-aliasing',
        '-D_GNU_SOURCE','-I'+str(src/'uptcpip/lib'),'-I'+str(hooks),'-I'+str(original.parent),'-DENABLE_PARSEC_UPTCPIP','-D_XOPEN_SOURCE=600',
        str(target),'-static','-L'+str(src/'uptcpip/lib'),'-luptcp.client','-pthread','-lm','-o',str(out/'netdedup_client')]
    for existing in ['build.log','linux-launch.log']:
        p=logs/existing
        if p.exists():shutil.copy2(p,p.with_name(existing+'.before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')))
    with (logs/'build.log').open('wb') as f:rc=subprocess.run(['nice','-n','15',*argv],stdout=f,stderr=subprocess.STDOUT,timeout=300).returncode
    assert rc==0
    manifest=copy.deepcopy(base);manifest.update(profile='netdedup-graceful-close-candidate/1',parent_receipt_sha256=sha(W/'software/network-candidate-build.json'),
        integration_patch=dict(path=str(patch),sha256=sha(patch)),formal_eligible=False)
    # App lookup still uses original server paths; client binary path is below.
    appout=out/'netdedup';(appout/'server').mkdir(parents=True,exist_ok=True);(appout/'client').mkdir(exist_ok=True)
    for name,binary in [('server/netdedup',src/'netdedup/server/netdedup'),('client/netdedup_client',out/'netdedup_client')]:
        dst=appout/name
        if not dst.exists():dst.symlink_to(binary)
    # The validator uses this output directory only for netdedup cases.
    manifest['output_dir']=str(out)
    manifest['programs']['netdedup']['binaries']['client/netdedup_client']=dict(path=str(out/'netdedup_client'),sha256=sha(out/'netdedup_client'))
    receipt=W/'software/netdedup-linger-candidate-build.json';save(receipt,manifest)
    st.update(status='VALIDATING',elf_sha256=sha(out/'netdedup_client'),patch=str(patch),patch_sha256=sha(patch),receipt=str(receipt),commands=[argv]);save(R,st)
    # Copy the already reviewed harness, binding only this candidate receipt.
    user=out/'validate-user.py';user.write_text((W/'scripts/validate_network_candidates.py').read_text().replace("W/'software/network-candidate-build.json'","W/'software/netdedup-linger-candidate-build.json'"))
    for size in ['test','simsmall','simmedium']:
        dst=logs/('user-'+size)
        if (dst/'result.json').exists():continue
        if dst.exists():dst.rename(dst.with_name(dst.name+'-interrupted-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')))
        dst.mkdir()
        argv=['unshare','--ipc','--mount','--net','--fork','python3',str(user),'--case','netdedup','--size',size,'--out',str(dst)]
        with (dst/'launch.log').open('wb') as f:
            rc=subprocess.run(argv,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts'),'EC_NETWORK_NO_TRACE':'1'},timeout=1900).returncode
        st.setdefault('user_cases',[]).append(dict(input=size,result=str(dst/'result.json'),returncode=rc));save(R,st)
    linux=out/'validate-linux.py';s=(W/'scripts/validate_network_linux.py').read_text()
    s=s.replace("W/'software/network-candidate-build.json'","W/'software/netdedup-linger-candidate-build.json'")
    s=s.replace("R=D/'software/network-linux-validation.json'","R=D/'software/netdedup-linger-linux-validation.json'")
    s=s.replace("'software/network-linux-validation.lock'","'software/netdedup-linger-linux-validation.lock'")
    s=s.replace("for name in ['netdedup','netferret','netstreamcluster']:","for name in ['netdedup']:")
    s=s.replace("'network-linux-'+stamp","'netdedup-linger-linux-'+stamp")
    # Expose peer logs continuously to host UART in the new diagnostic rootfs.
    s=s.replace('/bin/busybox mount -t sysfs sysfs /sys','/bin/busybox mount -t sysfs sysfs /sys\n/bin/busybox mount -t tmpfs tmpfs /tmp')
    s=s.replace('CLIENT > /run/client.log 2>&1 &','CLIENT &').replace('SERVER > /run/server.log 2>&1 &','SERVER &')
    s=s.replace('/bin/busybox cat /run/server.log','true').replace('/bin/busybox cat /run/client.log','true')
    linux.write_text(s)
    with (logs/'linux-launch.log').open('wb') as f:
        rc=subprocess.run(['python3',str(linux)],stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'PYTHONPATH':str(W/'scripts')},timeout=5400).returncode
    st.update(status='COMPLETE_REVIEW_EVIDENCE' if rc==0 else 'LINUX_LAUNCH_FAILED_WITH_EVIDENCE',linux_returncode=rc,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
