#!/usr/bin/env python3
"""Compile the RX service blob and install the exact v6 kernel/firmware sources. No execution."""
from pathlib import Path
import datetime
import json
import shutil
import subprocess
from build_minimal import ROOT, ENV, sha

def main():
    kit=ROOT/'firesim/dac2026';w=kit/'work/opt4-linux-v6';src=kit/'checker-v6'
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out=w/'service-build'/stamp;out.mkdir(parents=True,exist_ok=False);tools=ENV/'riscv-tools/bin'
    commands=[
        [tools/'riscv64-unknown-linux-gnu-gcc','-c','-march=rv64gc','-mabi=lp64d',src/'service.S','-o',out/'service.o'],
        [tools/'riscv64-unknown-linux-gnu-ld','-Ttext=0','-e','ec_opt4_service',out/'service.o','-o',out/'service.elf'],
        [tools/'riscv64-unknown-linux-gnu-objcopy','-O','binary','-j','.text',out/'service.elf',out/'service.bin']]
    for a in commands: subprocess.run(list(map(str,a)),check=True)
    nm=subprocess.check_output([str(tools/'riscv64-unknown-linux-gnu-nm'),str(out/'service.elf')],text=True)
    syms={line.split()[2]:int(line.split()[0],16) for line in nm.splitlines() if len(line.split())==3}
    assert syms['ec_opt4_service']==0
    size=syms['ec_opt4_service_end'];assert 0<size<4096
    blob=(out/'service.bin').read_bytes()[:size]
    (out/'service.code').write_bytes(blob)
    (src/'ec_opt4_service_blob.h').write_text('static const unsigned char ec_opt4_service_blob[] = {'+','.join(map(str,blob))+'};\n')
    for name in ['ec_dac_roi.c','ec_dac_roi_regs.h','ec_dac_roi_uapi.h','ec_opt4_service_blob.h','opt4_hw.h']:
        shutil.copy2(src/name,w/'linux/drivers/misc'/name)
    for a,b in [('firmware.c','ec_opt4.c'),('firmware_entry.S','ec_opt4_entry.S')]:shutil.copy2(src/a,w/'opensbi/lib/sbi'/b)
    with (out/'service.dump').open('wb') as f:
        subprocess.run([str(tools/'riscv64-unknown-linux-gnu-objdump'),'-d',str(out/'service.elf')],stdout=f,check=True)
    receipt={'phase':'service-blob','returncode':0,'commands':[list(map(str,a)) for a in commands],
             'code_bytes':size,'code_sha256':sha(out/'service.code'),'source_sha256':sha(src/'service.S'),
             'teardown_witness_csr':'0xcc0, U read-only custom CSR, C4 v6 only',
             'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN'}
    (out/'result.json').write_text(json.dumps(receipt,indent=2)+'\n');print(out/'result.json')
if __name__=='__main__':main()
