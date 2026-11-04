#!/usr/bin/env python3
"""Build unexecuted Linux prerequisites in isolated sources (not a certified C4 image)."""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time
from build_minimal import BASE, ENV, ROOT, resource_check, sha

WORK=BASE/'software-v3'

def snapshot(src):
    files={}
    for directory,dirs,names in os.walk(src):
        dirs[:]=[d for d in dirs if d not in {'.git','build','output','__pycache__'}]
        for n in names:
            f=Path(directory)/n
            if f.is_symlink(): files[str(f.relative_to(src))]={'link':os.readlink(f)}
            elif f.is_file(): files[str(f.relative_to(src))]=sha(f)
    return files

def main():
    script_content=Path(__file__).read_bytes()
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('phase',choices=['busybox','kernel','firmware'])
    p.add_argument('--wait-lock',action='store_true')
    p.add_argument('--kernel-result',type=Path,help='successful kernel result for generic B firmware payload')
    p.add_argument('--initramfs',type=Path,help='embed this exact cpio archive in a kernel prerequisite')
    p.add_argument('--fdt',type=Path,help='embed this exact DTB in generic OpenSBI firmware')
    a=p.parse_args()
    lock=open(BASE/'.dac-compile.lock','a')
    print('acquiring DAC compile resource lock',flush=True)
    fcntl.flock(lock,fcntl.LOCK_EX|(0 if a.wait_lock else fcntl.LOCK_NB))
    resources=resource_check()
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    label=a.phase+'-'+stamp
    log=ROOT/'Experiment/dac2026/build-logs/opt4-alveo-v3'/label
    out=WORK/'builds'/label
    log.mkdir(parents=True,exist_ok=False);out.mkdir(parents=True,exist_ok=False)
    (log/'build-script.py').write_bytes(script_content)
    src=WORK/({'kernel':'linux','firmware':'opensbi'}.get(a.phase,a.phase))
    before=snapshot(src)
    source_id=hashlib.sha256(json.dumps(before,sort_keys=True).encode()).hexdigest()
    (log/'sources.json').write_text(json.dumps(before,indent=2)+'\n')
    env=os.environ.copy()
    for k in ['CFLAGS','CPPFLAGS','CXXFLAGS','LDFLAGS','LD_LIBRARY_PATH','ARCH','CROSS_COMPILE']:
        env.pop(k,None)
    env.update(PATH=f'{ENV}/bin:{ENV}/riscv-tools/bin:/usr/local/bin:/usr/bin:/bin',CONDA_PREFIX=str(ENV),
               CC='/usr/bin/gcc',HOSTCC='/usr/bin/gcc',HOSTCXX='/usr/bin/g++',MAKEFLAGS='-j2',
               SOURCE_DATE_EPOCH='1793577600',KBUILD_BUILD_TIMESTAMP='Mon Nov 2 00:00:00 UTC 2026',
               KBUILD_BUILD_USER='ec-dac',KBUILD_BUILD_HOST='isolated-build')
    cross=str(ENV/'riscv-tools/bin/riscv64-unknown-linux-gnu-')
    input_files={str(f.resolve()):sha(f) for f in (a.initramfs,a.fdt) if f is not None}
    commands=[];start=time.monotonic();result=1;error=None;content_checks={}
    def run(args):
        nonlocal result
        argv=['nice','-n','15']+list(map(str,args))
        commands.append({'argv':argv,'cwd':str(src)})
        (log/'commands.json').write_text(json.dumps(commands,indent=2)+'\n')
        with open(log/'build.log','ab',buffering=0) as f:
            result=subprocess.run(argv,cwd=src,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT).returncode
        if result: raise RuntimeError('compile failed; see '+str(log/'build.log'))
    print(log,flush=True)
    try:
        if a.phase=='busybox':
            shutil.copy2(WORK/'busybox-config',out/'.config')
            run(['make','-j1','O='+str(out),'CROSS_COMPILE='+cross,'oldconfig'])
            run(['make','-j2','O='+str(out),'CROSS_COMPILE='+cross])
            assert (out/'busybox').is_file()
        elif a.phase=='kernel':
            common=['make','-j2','O='+str(out),'ARCH=riscv','CROSS_COMPILE='+cross]
            run(common+['defconfig'])
            args=[src/'scripts/config','--file',out/'.config']
            for key in ['DRM','SOUND','NET','SCSI','ATA','USB_SUPPORT','PCI','VIRTIO','MODULES','BPF_SYSCALL','DEBUG_KERNEL','DEBUG_INFO','KALLSYMS']:
                args+=['--disable',key]
            for key in ['BLK_DEV_INITRD','DEVTMPFS','DEVTMPFS_MOUNT','PROC_FS','SYSFS','TMPFS','SERIAL_SIFIVE','SERIAL_SIFIVE_CONSOLE','UNIX98_PTYS','FUTEX','MULTIUSER','DEBUG_INFO_NONE']:
                args+=['--enable',key]
            args+=['--disable','SMP']
            if a.initramfs:
                args+=['--set-str','INITRAMFS_SOURCE',str(a.initramfs.resolve())]
            run(args)
            run(common+['olddefconfig'])
            run(common+['Image','vmlinux'])
            assert (out/'arch/riscv/boot/Image').is_file()
        else:
            if not a.kernel_result: raise ValueError('--kernel-result required')
            k=json.loads(a.kernel_result.read_text())
            if k.get('phase')!='kernel' or k.get('returncode')!=0: raise ValueError('kernel build not successful')
            kernel=Path(k['output_dir'])/'arch/riscv/boot/Image'
            if sha(kernel)!=k['outputs'][str(kernel)]: raise ValueError('kernel Image hash changed')
            # Compile a generic boot prerequisite only; no firmware checker
            # service, ROI driver, DT reservation or measurement claim.
            firmware_args=['make','-j2','O='+str(out),'PLATFORM=generic','CROSS_COMPILE='+cross,
                           'FW_PAYLOAD_PATH='+str(kernel)]
            if a.fdt: firmware_args+=['FW_PAYLOAD_FDT_PATH='+str(a.fdt.resolve())]
            run(firmware_args)
            assert (out/'platform/generic/firmware/fw_payload.elf').is_file()
            payload=(out/'platform/generic/firmware/fw_payload.bin').read_bytes()
            for name,path in [('kernel_Image',kernel),('fdt',a.fdt)]:
                if path is None: continue
                data=path.read_bytes()
                offset=payload.find(data)
                content_checks[name]={'path':str(path.resolve()),'sha256':sha(path),
                                      'size':len(data),'payload_offset':offset,
                                      'exact_bytes_present':bool(data) and offset>=0}
                if not content_checks[name]['exact_bytes_present']:
                    raise RuntimeError(name+' exact bytes absent from firmware payload')
        if snapshot(src)!=before: raise RuntimeError('source tree changed during build')
        if any(sha(f)!=expected for f,expected in input_files.items()):
            raise RuntimeError('input archive/DTB changed during build')
        result=0
    except Exception as exc:
        result=1;error=repr(exc);print(error,file=sys.stderr,flush=True)
    selected=['busybox','.config'] if a.phase=='busybox' else (
        ['vmlinux','arch/riscv/boot/Image','.config'] if a.phase=='kernel' else
        ['platform/generic/firmware/fw_payload.elf','platform/generic/firmware/fw_payload.bin'])
    outputs={str(out/f):sha(out/f) for f in selected if (out/f).is_file()}
    record=dict(phase=a.phase,source_tree=str(src),source_id=source_id,output_dir=str(out),outputs=outputs,
                returncode=result,error=error,commands=commands,resources=resources,wall_seconds=time.monotonic()-start,
                target_execution='NOT_RUN',runtime_validation='NOT_RUN',
                status='BASE_PREREQUISITE_ONLY: no ROI/checker runtime or certified experiment image',
                build_script_sha256=hashlib.sha256(script_content).hexdigest(),
                busybox_config_sha256=sha(WORK/'busybox-config'),
                kernel_result=str(a.kernel_result.resolve()) if a.kernel_result else None,
                input_files=input_files,content_checks=content_checks,
                tool_hashes={str(f):sha(f) for f in [Path('/usr/bin/gcc'),Path('/usr/bin/g++'),
                                                    Path(cross+'gcc'),Path(cross+'ld'),Path(cross+'objcopy')]},
                environment_overrides={k:env[k] for k in ['PATH','CONDA_PREFIX','CC','HOSTCC','HOSTCXX','MAKEFLAGS']})
    (log/'result.json').write_text(json.dumps(record,indent=2)+'\n')
    print('returncode='+str(result),flush=True)
    return result

if __name__=='__main__': raise SystemExit(main())
