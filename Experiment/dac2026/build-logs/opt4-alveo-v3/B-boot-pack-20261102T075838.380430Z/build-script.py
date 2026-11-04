#!/usr/bin/env python3
"""Pack an unexecuted B initramfs/DTB prerequisite, with an interactive init and no auto benchmark."""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import stat
import subprocess

ROOT=Path('/data1/gzh/EC')


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def output_from_result(path, phase, relative):
    result=json.loads(path.read_text())
    if result.get('returncode')!=0 or result.get('phase')!=phase:raise ValueError('need successful '+phase+' result')
    f=Path(result['output_dir'])/relative
    if sha(f)!=result['outputs'][str(f)]:raise ValueError('input artifact changed: '+str(f))
    return f


def cpio_newc(root, dest):
    # Deterministic newc writer: root ownership, fixed times, no host device access.
    entries=[('.',stat.S_IFDIR|0o755,b'')]
    for path in sorted(root.rglob('*')):
        mode=path.lstat().st_mode
        if path.is_symlink():data=os.readlink(path).encode()
        elif path.is_file():data=path.read_bytes()
        elif path.is_dir():data=b''
        else:raise ValueError('unexpected archive entry '+str(path))
        entries.append((str(path.relative_to(root)),mode,data))
    entries.append(('TRAILER!!!',0,b''))
    with open(dest,'xb') as f:
        for ino,(name,mode,data) in enumerate(entries,1):
            encoded=name.encode()+b'\0'
            fields=[ino,mode,0,0,2 if stat.S_ISDIR(mode) else 1,1793577600,len(data),0,0,0,0,len(encoded),0]
            header=b'070701'+b''.join(f'{v:08x}'.encode() for v in fields)
            f.write(header+encoded);f.write(b'\0'*((-(len(header)+len(encoded)))%4))
            f.write(data);f.write(b'\0'*((-len(data))%4))
        f.write(b'\0'*((-f.tell())%512))


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--busybox-result',type=Path,required=True)
    p.add_argument('--baseline-elaboration-result',type=Path,required=True)
    a=p.parse_args()
    busybox=output_from_result(a.busybox_result,'busybox','busybox')
    elab=json.loads(a.baseline_elaboration_result.read_text())
    if elab.get('config')!='DacBaseline':raise ValueError('this boot prerequisite is only for true single-BOOM B')
    dts=output_from_result(a.baseline_elaboration_result,'elaborate','firesim.firesim.FireSim.dts')
    text=dts.read_text()
    if len(re.findall(r'cpu@[0-9a-f]+\s*\{',text))!=1:raise ValueError('not a single-hart baseline DT')
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out=ROOT/'firesim/dac2026/images/software-v3'/('B-boot-'+stamp)
    log=ROOT/'Experiment/dac2026/build-logs/opt4-alveo-v3'/('B-boot-pack-'+stamp)
    out.mkdir(parents=True,exist_ok=False);log.mkdir(parents=True,exist_ok=False)
    tree=out/'rootfs'
    for part in ('bin','sbin','dev','proc','sys','tmp','run','etc','root','opt/ec-dac'):(tree/part).mkdir(parents=True,exist_ok=True)
    shutil.copy2(busybox,tree/'bin/busybox')
    for applet in ('sh','mount','umount','mkdir','mknod','cat','ls','echo','dmesg','sleep','uname','poweroff','reboot'):
        (tree/'bin'/applet).symlink_to('busybox')
    (tree/'init').write_text('#!/bin/sh\n'
        'export PATH=/bin:/sbin\n'
        'mount -t devtmpfs devtmpfs /dev || { mknod /dev/console c 5 1; mknod /dev/null c 1 3; }\n'
        'mount -t proc proc /proc\nmount -t sysfs sysfs /sys\n'
        'exec </dev/console >/dev/console 2>&1\n'
        'echo "EC_DAC_BASE_BOOT_ONLY: no ROI device, checker service or certified observer"\n'
        'echo "No benchmark runs automatically. Interactive shell is a prerequisite check only."\n'
        'while true; do /bin/sh; sleep 1; done\n')
    (tree/'init').chmod(0o755)
    (tree/'etc/PREPARATION_STATUS').write_text('B_BASE_BOOT_PREREQUISITE_ONLY\nROI/checker/observer not implemented; target execution NOT_RUN\n')
    cpio=out/'initramfs.cpio';cpio_newc(tree,cpio)
    # Keep generated hardware DT unchanged. All software-only edits are explicit.
    text=text.replace('\n/ {\n','\n/ {\n\tchosen {\n\t\tbootargs = "console=ttySIF0,115200n8 earlycon=sbi rdinit=/init";\n\t\tstdout-path = "serial0:115200n8";\n\t};\n',1)
    text=re.sub(r'(riscv,isa = ")([^"]+)(";)',lambda m:m[1]+m[2].lower()+m[3],text)
    text=text.replace('clock-frequency = <0>;','clock-frequency = <200000000>;')
    software_dts=out/'B-boot.dts';software_dts.write_text(text)
    command=['/usr/bin/dtc','-I','dts','-O','dtb','-o',str(out/'B-boot.dtb'),str(software_dts)]
    with open(log/'build.log','wb') as f:r=subprocess.run(command,stdout=f,stderr=subprocess.STDOUT)
    if r.returncode:raise RuntimeError('DT compile failed: '+str(log))
    inputs={str(f.resolve()):sha(f) for f in (a.busybox_result,a.baseline_elaboration_result,busybox,dts,Path(__file__))}
    files={str(f.relative_to(out)):{'link':os.readlink(f)} if f.is_symlink() else {'sha256':sha(f)} for f in sorted(out.rglob('*')) if f.is_file() or f.is_symlink()}
    record={'phase':'B-boot-pack','returncode':0,'output_dir':str(out),'inputs':inputs,'files':files,
            'commands':[command],'dtc_sha256':sha('/usr/bin/dtc'),'status':'B_BASE_BOOT_PREREQUISITE_ONLY',
            'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN',
            'software_dt_edits':['chosen console/interactive rdinit','lowercase existing ISA extension names','CPU0 200 MHz from audited generated clock schedule'],
            'not_included':['ROI control driver','passive measurement bridge','Linux/checker service','PARSEC job/backend/Python3','certified experiment image']}
    for f in (out/'manifest.json',log/'result.json'):f.write_text(json.dumps(record,indent=2)+'\n')
    print(log/'result.json')


if __name__=='__main__':main()
