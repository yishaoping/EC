#!/usr/bin/env python3
"""Package manual-only C4 Linux short/PARSEC entries. Does not boot or run."""
import datetime
import argparse
import json
from pathlib import Path
import shutil
from build_minimal import ROOT, sha
from prepare_boot_prerequisite import cpio_newc

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--native-htif',action='store_true',help='native console profile with mandatory host verification of every application file in the immutable cpio')
    a=p.parse_args()
    kit=ROOT/'firesim/dac2026';w=kit/'work/opt4-linux-v6'
    apps=json.loads((w/'apps-build.json').read_text());appdir=Path(apps['output'])
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    image_base=kit/'images/opt4-linux-v6'
    if a.native_htif:image_base=image_base/'native-htif'
    out=image_base/('rootfs-'+stamp);out.mkdir(parents=True,exist_ok=False)
    base=kit/'images/software-v3/B-boot-20261102T083720.765499Z/rootfs'
    tree=out/'rootfs';shutil.copytree(base,tree,symlinks=True)
    dst=tree/'opt/ec-dac'
    shutil.rmtree(dst);dst.mkdir()
    for name,h in apps['binaries'].items():
        if sha(appdir/name)!=h:raise ValueError('binary changed')
        shutil.copy2(appdir/name,dst/name)
    shutil.copytree(appdir/'inputs',dst/'inputs')
    shutil.copy2(kit/'checker-v6/manual-linux.sh',dst/'manual-link.sh')
    if a.native_htif:
        script=dst/'manual-link.sh'
        text=script.read_text().replace('/bin/busybox sha256sum -c SHA256SUMS',
            '# All application files are SHA256-verified in the exact cpio by the host runner.\n'
            '# The input and BUILD hashes below are still checked in the guest.\n'
            'echo "8 4 1 7" > /proc/sys/kernel/printk\n'
            'echo "EC_OPT4_INTEGRITY transport=immutable_initramfs host_verification=REQUIRED"')
        script.write_text(text)
    (dst/'manual-link.sh').chmod(0o755)
    checks=''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file())
    (dst/'SHA256SUMS').write_text(checks)
    (dst/'BUILD.json').write_text(json.dumps(apps,indent=2)+'\n')
    (tree/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
echo "EC_OPT4_C4_V6_BOOT: no program runs automatically; one ROI per boot"
echo "Manual stage B: /opt/ec-dac/manual-link.sh smoke"
echo "Manual stage C: /opt/ec-dac/manual-link.sh test"
while true; do /bin/sh; sleep 1; done
''')
    (tree/'init').chmod(0o755)
    if a.native_htif:
        (tree/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
# PID 1 is this small init, so it implements the normal poweroff request.
trap '/bin/busybox sync; /bin/busybox poweroff -f' USR2
echo "EC_OPT4_C4_V6_BOOT: native HTIF actual guest init"
mode=
for option in $(/bin/busybox cat /proc/cmdline); do
  case "$option" in ec_dac_mode=smoke) mode=smoke ;; ec_dac_mode=test) mode=test ;; esac
done
case "$mode" in smoke|test) ;; *) echo 'EC_OPT4_INVALID reason=missing_bound_boot_mode'; /bin/busybox poweroff -f ;; esac
echo "EC_OPT4_COMMAND command=/opt/ec-dac/manual-link.sh $mode"
/opt/ec-dac/manual-link.sh "$mode"
rc=$?
echo "EC_OPT4_CONSOLE_EXIT code=$rc"
echo 'EC_OPT4_COMMAND command=/bin/busybox sync; /bin/busybox poweroff'
/bin/busybox sync
/bin/busybox poweroff
while true; do /bin/busybox sleep 1; done
''')
    (tree/'etc/PREPARATION_STATUS').write_text('C4_USER_ONLY_V6_BUILT_CANDIDATE_NOT_RUN\n')
    cpio_newc(tree,out/'initramfs.cpio')
    record={'phase':'rootfs','returncode':0,'initramfs':str(out/'initramfs.cpio'),
            'sha256':sha(out/'initramfs.cpio'),'output_dir':str(out),
            'apps_manifest':str(appdir/'manifest.json'),'apps_manifest_sha256':sha(appdir/'manifest.json'),
            'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN','automatic_benchmark':False}
    if a.native_htif:
        record.update(configuration='C4-v6-native-HTIF',
            integrity='mandatory SHA256 of all application files extracted from this exact cpio before native execution; guest still hashes BUILD and actual input',
            image_application_files={str(p.relative_to(tree)):sha(p) for p in sorted(dst.rglob('*')) if p.is_file()})
    (out/'result.json').write_text(json.dumps(record,indent=2)+'\n')
    receipt_dir=w/'native-htif' if a.native_htif else w
    receipt_dir.mkdir(parents=True,exist_ok=True)
    (receipt_dir/'rootfs-build.json').write_text(json.dumps(record,indent=2)+'\n');print(out/'result.json')
if __name__=='__main__':main()
