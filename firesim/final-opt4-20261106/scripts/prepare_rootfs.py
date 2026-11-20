#!/usr/bin/env python3
"""Pack a shared immutable initramfs with real ROI hooks and per-sample validation."""
import hashlib
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import sys
import argparse
import re

ROOT = Path('/data1/gzh/EC')
WORK = ROOT/'firesim/final-opt4-20261106'
DATA = ROOT/'Experiment/firesim-final-opt4-20261106'
sys.path.insert(0,str(ROOT/'firesim/dac2026/scripts'))
from prepare_boot_prerequisite import cpio_newc


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--apps-receipt',type=Path,default=WORK/'software/apps-build.json');parser.add_argument('--output-receipt',type=Path,default=WORK/'software/rootfs-build.json');a=parser.parse_args()
    receipt=a.apps_receipt
    apps=json.loads(receipt.read_text())
    captures=apps.get('diagnostic_capture_files',[])
    assert all(re.fullmatch('[A-Za-z0-9_./-]+',n) and '..' not in Path(n).parts and not Path(n).is_absolute() for n in captures)
    assert all(re.fullmatch('[a-z][a-z0-9]*',n) for n in apps['binaries'])
    out=WORK/'software'/('rootfs-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ'))
    out.mkdir(exist_ok=False)
    tree=out/'tree'
    for d in ['bin','sbin','dev','proc','sys','tmp','run','etc','root','opt/ec-fpga']:
        (tree/d).mkdir(parents=True,exist_ok=True)
    old=ROOT/'firesim/dac2026/images/software-v3/B-boot-20261102T083720.765499Z/rootfs/bin/busybox'
    shutil.copy2(old,tree/'bin/busybox')
    for n in ['sh','mount','umount','mkdir','mknod','cat','ls','echo','dmesg','sleep','uname','poweroff','reboot']:
        (tree/'bin'/n).symlink_to('busybox')
    dst=tree/'opt/ec-fpga'
    shutil.copy2(receipt,dst/'BUILD.json')
    for name,b in apps['binaries'].items():
        if sha(b['path'])!=b['sha256']:
            raise ValueError('changed ELF '+name)
        shutil.copy2(b['path'],dst/name)
    if sha(apps['smoke']['path'])!=apps['smoke']['sha256']:
        raise ValueError('changed smoke ELF')
    shutil.copy2(apps['smoke']['path'],dst/'roi-smoke')
    shutil.copytree(Path(apps['output_dir'])/'inputs',dst/'inputs')
    for c in apps['cases']:
        case=dst/'cases'/c['program']/c['input']
        case.mkdir(parents=True)
        (case/'argv').write_text(' '.join(c['argv'])+'\n')
        validation=c.get('validation')
        if validation:
            assert validation['kind'] in ['stdout_prefix_hash','stdout_integer_hash','files_sha256']
            (case/'validation-kind').write_text(validation['kind']+'\n')
            if validation['kind'] in ['stdout_prefix_hash','stdout_integer_hash']:
                if validation['kind']=='stdout_prefix_hash':
                    prefix=validation['prefix'];assert re.fullmatch('[A-Za-z0-9 :_-]+',prefix)
                    (case/'validation-prefix').write_text(prefix+'\n')
                source=Path(validation['reference']);assert sha(source)==validation['reference_sha256']
                shutil.copy2(source,case/'reference-output')
            else:
                assert all(re.fullmatch('[A-Za-z0-9_./-]+',n) and '..' not in Path(n).parts for n in validation['files'])
                (case/'output-sha256sums').write_text(''.join(h+'  '+n+'\n' for n,h in validation['files'].items()))
            continue
        if c['program']=='canneal':
            (case/'expected-routing').write_text(c['expected_final_routing']+'\n')
        else:
            [(path,digest)]=c['reference_outputs'].items()
            if sha(path)!=digest:
                raise ValueError('changed software reference')
            shutil.copy2(path,case/'reference-output')
    (dst/'run-one').write_text('''#!/bin/sh
set -eu
export OMP_NUM_THREADS=1 PARSEC_NUM_THREADS=1
cd /opt/ec-fpga
program=${1:-}; input=${2:-}; repetition=${3:-}; run_id=${4:-}
case "$program" in smoke|__BOUND_PROGRAMS__) ;; *) exit 2 ;; esac
case "$input" in test|simsmall|simmedium) ;; *) exit 2 ;; esac
case "$repetition" in 1|2|3|4|5|6|7|8|9) ;; *) exit 2 ;; esac
case "$run_id" in ''|*[!a-zA-Z0-9_.-]*) exit 2 ;; esac
test -c /dev/ec_dac_roi || { echo "EC_SAMPLE_INVALID run_id=$run_id reason=missing_real_roi_driver"; exit 125; }
/bin/busybox sha256sum -c SHA256SUMS >/tmp/ec-integrity-$$.log || { /bin/busybox cat /tmp/ec-integrity-$$.log; exit 125; }
work=/tmp/ec-$run_id-$program-$input-$repetition
/bin/busybox mkdir "$work"
if [ "$program" != smoke ]; then /bin/busybox cp -R "inputs/$program/$input/." "$work/"; fi
echo "EC_SAMPLE_START run_id=$run_id program=$program input=$input repetition=$repetition seq=1 threads=1 warmups=0 fresh_process=1 one_roi_per_boot=1"
/bin/busybox sha256sum BUILD.json
cd "$work"
/bin/busybox mkfifo console.pipe
/bin/busybox tee stdout.log <console.pipe &
capture=$!
set +e
if [ "$program" = smoke ]; then
  /opt/ec-fpga/roi-smoke >console.pipe 2>&1
else
  argv=$(/bin/busybox cat /opt/ec-fpga/cases/$program/$input/argv)
  /opt/ec-fpga/$program $argv >console.pipe 2>&1
fi
rc=$?
wait "$capture"
capture_rc=$?
set -e
echo "EC_SAMPLE_EXIT run_id=$run_id program=$program input=$input repetition=$repetition seq=2 application_exit=$rc capture_exit=$capture_rc"
if [ "$rc" != 0 ] || [ "$capture_rc" != 0 ]; then
  echo "EC_SAMPLE_FAILED run_id=$run_id program=$program input=$input repetition=$repetition seq=3 reason=application_or_capture_exit"; exit 1
fi
valid=0
case_dir=/opt/ec-fpga/cases/$program/$input
if [ -f "$case_dir/validation-kind" ]; then
 kind=$(/bin/busybox cat "$case_dir/validation-kind")
 if [ "$kind" = stdout_prefix_hash ] || [ "$kind" = stdout_integer_hash ]; then
   if [ "$kind" = stdout_prefix_hash ]; then
     prefix=$(/bin/busybox cat "$case_dir/validation-prefix")
     /bin/busybox grep "^$prefix" stdout.log > validation.txt || true
   else
     /bin/busybox grep -E '^[0-9]+$' stdout.log > validation.txt || true
   fi
   expected=$(/bin/busybox sha256sum "$case_dir/reference-output"); expected=${expected%% *}
   actual=$(/bin/busybox sha256sum validation.txt); actual=${actual%% *}
   [ "$actual" = "$expected" ] && valid=1
   echo "EC_OUTPUT_SHA256 run_id=$run_id program=$program input=$input repetition=$repetition seq=3 actual=$actual expected=$expected"
 elif [ "$kind" = files_sha256 ]; then
   /bin/busybox sha256sum -c "$case_dir/output-sha256sums" && valid=1
 fi
else
case "$program" in
 smoke) /bin/busybox grep -qx 'DAC_SMOKE checksum=500500 expected=500500' stdout.log && valid=1 ;;
 canneal)
   expected=$(/bin/busybox cat /opt/ec-fpga/cases/$program/$input/expected-routing)
   /bin/busybox grep -Fqx "Final routing is: $expected" stdout.log && valid=1 ;;
 streamcluster|blackscholes)
   if [ "$program" = streamcluster ]; then output=output.txt; else output=prices.txt; fi
   expected=$(/bin/busybox sha256sum /opt/ec-fpga/cases/$program/$input/reference-output)
   expected=${expected%% *}
   actual=$(/bin/busybox sha256sum "$output")
   actual=${actual%% *}
   [ "$actual" = "$expected" ] && valid=1
   echo "EC_OUTPUT_SHA256 run_id=$run_id program=$program input=$input repetition=$repetition seq=3 actual=$actual expected=$expected"
   echo "EC_OUTPUT_TEXT_BEGIN run_id=$run_id file=$output"
   /bin/busybox cat "$output"
   echo "EC_OUTPUT_TEXT_END run_id=$run_id file=$output"
   ;;
esac
fi
if [ "$valid" != 1 ]; then
__DIAGNOSTIC_CAPTURE__
  echo "EC_SAMPLE_FAILED run_id=$run_id program=$program input=$input repetition=$repetition seq=4 reason=output_mismatch"; exit 1
fi
echo "EC_SAMPLE_GUEST_DONE run_id=$run_id program=$program input=$input repetition=$repetition seq=4 output_valid=1 application_exit=0 hardware_validation=HOST_REQUIRED"
# This is deliberately a guest observation, never a host completion marker.
/bin/busybox sync
'''.replace('__BOUND_PROGRAMS__','|'.join(apps['binaries'])).replace('__DIAGNOSTIC_CAPTURE__','\n'.join('''  if [ -f '%s' ]; then
    size=$(/bin/busybox wc -c < '%s')
    if [ "$size" -le 8388608 ]; then
      echo "EC_DIAGNOSTIC_FILE_BEGIN run_id=$run_id file=%s bytes=$size encoding=base64"
      /bin/busybox uuencode -m '%s' ec-diagnostic | /bin/busybox sed '1d;$d'
      echo "EC_DIAGNOSTIC_FILE_END run_id=$run_id file=%s"
    fi
  fi''' % ((n,)*5) for n in captures)))
    (dst/'run-one').chmod(0o755)
    sums=''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file())
    (dst/'SHA256SUMS').write_text(sums)
    (tree/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
echo 'EC_GUEST_READY protocol=ec-fpga-sample/1 real_roi_device_required=1 one_roi_per_boot=1'
/bin/busybox sha256sum /opt/ec-fpga/BUILD.json
while true; do /bin/sh; sleep 1; done
''')
    (tree/'init').chmod(0o755)
    cpio_newc(tree,out/'initramfs.cpio')
    record={'schema':'ec-fpga-rootfs/1','phase':'rootfs','returncode':0,'path':str(out/'initramfs.cpio'),
            'sha256':sha(out/'initramfs.cpio'),'bytes':(out/'initramfs.cpio').stat().st_size,
            'shared_by':['Native','Correction'],'apps_manifest_sha256':sha(receipt),
            'files':{str(p.relative_to(tree)):sha(p) for p in tree.rglob('*') if p.is_file()},
            'busybox_parent':str(old),'busybox_sha256':sha(old),'one_roi_per_boot':True,
            'guest_execution':'NOT_RUN','fpga_validation':'NOT_RUN','formal_sample':False}
    (out/'manifest.json').write_text(json.dumps(record,indent=2)+'\n')
    a.output_receipt.write_text(json.dumps(record,indent=2)+'\n')
    print(out/'manifest.json')


if __name__=='__main__':
    main()
