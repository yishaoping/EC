#!/usr/bin/env python3
"""Boot built Linux/rootfs on QEMU virt; never validate the frozen DUT/checker."""
import argparse
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import selectors
import signal
import subprocess
import time

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
QEMU=Path('/data1/gzh/EC/chipyard/.conda-env/bin/qemu-system-riscv64')


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('configuration',choices=['Native','C4'])
    a=p.parse_args()
    receipt=W/'software'/a.configuration/'kernel-build.json'
    r=json.loads(receipt.read_text())
    assert r['returncode']==0 and r['configuration']==a.configuration
    kernel=Path(r['output_dir'])/'arch/riscv/boot/Image'
    assert sha(kernel)==r['outputs'][str(kernel)]
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'software'/(a.configuration+'-qemu-kernel-'+stamp)
    out.mkdir()
    argv=[str(QEMU),'-M','virt','-m','512M','-smp','1','-nographic','-bios','default',
          '-kernel',str(kernel),'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1']
    start=time.monotonic()
    child=subprocess.Popen(argv,stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,
                           start_new_session=True)
    state=dict(schema='ec-qemu-kernel-smoke/1',configuration=a.configuration,argv=argv,
               kernel_receipt=str(receipt),kernel_receipt_sha256=sha(receipt),kernel_sha256=sha(kernel),
               qemu_sha256=sha(QEMU),pid=child.pid,pgid=child.pid,
               start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21],
               purpose='QEMU virt Linux/rootfs boot and missing-device rejection only',
               checker_runtime='NOT_TESTED',fpga_validation='NOT_RUN',formal_eligible=False,
               note='QEMU uses its own BIOS/DT, 512M software-only RAM, and ttyS0 console; not the FPGA system profile.')
    (out/'started.json').write_text(json.dumps(state,indent=2)+'\n')
    sel=selectors.DefaultSelector()
    sel.register(child.stdout,selectors.EVENT_READ)
    data=b''
    sent=False
    timeout=False
    with (out/'console.log').open('wb',buffering=0) as f:
        while child.poll() is None:
            if time.monotonic()-start>120:
                timeout=True
                os.killpg(child.pid,signal.SIGTERM)
                break
            for key,_ in sel.select(timeout=1):
                chunk=os.read(key.fd,65536)
                if not chunk:
                    continue
                f.write(chunk)
                os.fsync(f.fileno())
                data+=chunk
                if not sent and b'EC_GUEST_READY' in data:
                    child.stdin.write(b'/opt/ec-fpga/run-one smoke test 1 qemu_only; echo EC_DIAG_COMMAND_EXIT=$?; /bin/poweroff -f\n')
                    child.stdin.flush()
                    sent=True
        try:
            child.wait(timeout=10)
        except subprocess.TimeoutExpired:
            os.killpg(child.pid,signal.SIGKILL)
            child.wait()
        tail=child.stdout.read()
        f.write(tail)
        os.fsync(f.fileno())
        data+=tail
    good=(not timeout and child.returncode==0 and b'EC_GUEST_READY' in data and
          b'reason=missing_real_roi_driver' in data and b'EC_DIAG_COMMAND_EXIT=125' in data)
    state.update(returncode=child.returncode,timeout=timeout,software_boot_and_fail_closed=good,
                 wall_seconds=time.monotonic()-start,console_sha256=sha(out/'console.log'))
    (out/'result.json').write_text(json.dumps(state,indent=2)+'\n')
    print(json.dumps(dict(result_path=str(out/'result.json'),software_boot_and_fail_closed=good,
                          fpga_validation='NOT_RUN')),flush=True)
    return 0 if good else 1


if __name__=='__main__':
    raise SystemExit(main())
