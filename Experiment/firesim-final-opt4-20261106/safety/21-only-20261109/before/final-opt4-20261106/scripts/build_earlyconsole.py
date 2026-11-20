#!/usr/bin/env python3
"""Incremental matched boot-observability kernel build; original outputs preserved."""
import argparse,datetime as dt,hashlib,json,os,shutil,subprocess,sys,time
from pathlib import Path
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');E=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,s):p.write_text(json.dumps(s,indent=2)+'\n')
def main(a):
    config=a.configuration
    parent_path=a.parent_receipt or W/'software'/config/'kernel-build.json';r=json.loads(parent_path.read_text());old=Path(r['output_dir']);src=Path(r['source_tree'])
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=(a.build_root or W/'software'/config/'builds')/(config+'-earlyconsole-'+stamp);logs=D/'system-builds'/out.name;logs.mkdir()
    out.parent.mkdir(parents=True,exist_ok=True)
    assert shutil.disk_usage(out.parent).free>10*2**30
    shutil.copytree(old,out,symlinks=True)
    commands=[];env=os.environ.copy();env.update(PATH=str(E/'bin')+':'+str(E/'riscv-tools/bin')+':/usr/bin:/bin',MAKEFLAGS='-j2',KBUILD_BUILD_TIMESTAMP='Mon Nov 2 00:00:00 UTC 2026',KBUILD_BUILD_USER='ec-fpga',KBUILD_BUILD_HOST='isolated-build',SOURCE_DATE_EPOCH='1793577600')
    env.pop('LD_LIBRARY_PATH',None)
    cross=str(E/'riscv-tools/bin/riscv64-unknown-linux-gnu-');start=time.monotonic()
    state=dict(configuration=config,phase='earlyconsole-kernel',status='RUNNING',pid=os.getpid(),output_dir=str(out),log_dir=str(logs),parent_receipt=str(parent_path),parent_receipt_sha256=sha(parent_path))
    save(D/(config+'-earlyconsole-state.json'),state)
    with (logs/'build.log').open('wb',buffering=0) as f:
        def run(argv):
            commands.append(list(map(str,argv)));p=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=src,env=env,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=p.pid,child_pgid=p.pid);save(D/(config+'-earlyconsole-state.json'),state)
            rc=p.wait(timeout=1800);assert rc==0,(rc,str(logs))
        run([src/'scripts/config','--file',out/'.config','--enable','RISCV_SBI_V01','--enable','SERIAL_EARLYCON_RISCV_SBI','--enable','HVC_RISCV_SBI','--enable','PRINTK_TIME'])
        if a.rootfs_receipt:
            rootfs=json.loads(a.rootfs_receipt.read_text());assert sha(rootfs['path'])==rootfs['sha256']
            run([src/'scripts/config','--file',out/'.config','--set-str','INITRAMFS_SOURCE',rootfs['path']])
            r['input_files']={p:h for p,h in r['input_files'].items() if 'rootfs' not in p and not p.endswith('.cpio')}
            r['input_files'].update({str(a.rootfs_receipt):sha(a.rootfs_receipt),rootfs['path']:rootfs['sha256']})
            r['content_checks']['same_rootfs']=rootfs['sha256']
        common=['make','-j2','O='+str(out),'ARCH=riscv','CROSS_COMPILE='+cross,'HOSTCC=/usr/bin/gcc','HOSTCXX=/usr/bin/g++']
        run([*common,'olddefconfig']);run([*common,'Image','vmlinux'])
    rr={**r,'output_dir':str(out),'outputs':{str(out/p):sha(out/p) for p in ['vmlinux','arch/riscv/boot/Image','.config','drivers/misc/ec_dac_roi.o']},'commands':commands,'parent_receipt':str(parent_path),'parent_receipt_sha256':sha(parent_path),'integration_change':'Enable the earlycon=sbi backend already requested by DT; no DUT/app/input/ROI edits','wall_seconds':time.monotonic()-start,'runtime_validation':'NOT_RUN'}
    if config=='C4' and (D/'software/traffic-readback-integration/manifest.json').exists():
        integration=D/'software/traffic-readback-integration/manifest.json';patch=json.loads(integration.read_text())
        assert sha(patch['source'])==patch['sha256']
        rr['software_integration']=dict(manifest=str(integration),sha256=sha(integration),source_parent_id=r['source_id'])
        # A cloned kernel that already includes this integration keeps its
        # source identity; changing only its initramfs is not a source edit.
        if r.get('software_integration',{}).get('sha256') != sha(integration):
            rr['source_id']=hashlib.sha256((r['source_id']+patch['sha256']).encode()).hexdigest()
        rr['input_files'][str(integration)]=sha(integration)
        rr['input_files'][patch['source']]=patch['sha256']
    save(logs/'result.json',rr);save(a.output_receipt or W/'software'/config/'earlyconsole-kernel-build.json',rr)
    state.update(status='BUILT_NOT_RUN',result_path=str(logs/'result.json'));save(D/(config+'-earlyconsole-state.json'),state);print(json.dumps(state),flush=True)
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('configuration',choices=['Native','C4']);p.add_argument('--parent-receipt',type=Path);p.add_argument('--rootfs-receipt',type=Path);p.add_argument('--output-receipt',type=Path);p.add_argument('--build-root',type=Path)
    main(p.parse_args())
