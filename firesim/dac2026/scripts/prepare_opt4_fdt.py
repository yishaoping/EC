#!/usr/bin/env python3
"""Reserve checker harts in a generated C4 DT; preserve memory/MMIO ranges."""
import argparse
import datetime
import json
from pathlib import Path
import re
import subprocess
from build_minimal import ROOT, ENV, sha

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--dts',type=Path,required=True)
    p.add_argument('--firesim',action='store_true',help='write a separate FireSim FDT receipt; never replace native FDT')
    p.add_argument('--native-htif',action='store_true',help='native-only existing HTIF/SBI console; keep UART and FireSim receipts intact')
    p.add_argument('--diagnostic36',action='store_true',help='isolated 36-bit software diagnosis; never a formal slowdown sample')
    p.add_argument('--diagnostic-small',action='store_true',help='32 MiB Linux memory cap, explicit boot messages, separate artifacts')
    p.add_argument('--guest-mode',choices=['smoke','test'],default='smoke',help='version-bound native init command; ignored by interactive UART profiles')
    a=p.parse_args()
    if a.firesim and a.native_htif:p.error('native HTIF is not a FireSim console')
    if a.diagnostic36 and not a.native_htif:p.error('--diagnostic36 requires --native-htif')
    if a.diagnostic_small and not (a.diagnostic36 and a.native_htif):p.error('--diagnostic-small requires diagnostic native HTIF')
    text=a.dts.read_text()
    if '"ec,dac-roi-v1"' not in text:raise ValueError('no actual ROI peripheral')
    matches=list(re.finditer(r'cpu@([0-4])\s*\{',text))
    if len(matches)!=5:raise ValueError('exactly harts 0..4 required')
    for match in reversed(matches):
        start=match.start();pos=match.end();depth=1
        while depth:
            if text[pos]=='{':depth+=1
            if text[pos]=='}':depth-=1
            pos+=1
        block=text[start:pos];hart=int(match[1])
        block,n=re.subn(r'status = "okay";',f'status = "{"okay" if hart==0 else "disabled"}";',block)
        if n!=1:raise ValueError('CPU status missing')
        block=block.replace('clock-frequency = <0>;',f'clock-frequency = <{200000000 if hart==0 else 100000000}>;')
        text=text[:start]+block+text[pos:]
    if 'chosen {' in text:raise ValueError('unexpected existing chosen node')
    if a.native_htif and '"ucb,htif0"' not in text:raise ValueError('native RTL has no HTIF device')
    console='console=hvc0 earlycon=sbi quiet loglevel=3' if a.native_htif else 'console=ttySIF0,115200 earlycon=sbi loglevel=7'
    if a.native_htif:console+=' ec_dac_mode='+a.guest_mode
    if a.diagnostic_small:console=console.replace('quiet loglevel=3','loglevel=7')+' mem=32M'
    stdout='/htif' if a.native_htif else 'serial0:115200n8'
    last=text.rfind('};');text=text[:last]+f'''  chosen {{
    bootargs = "{console} rdinit=/init panic=-1 maxcpus=1";
    stdout-path = "{stdout}";
  }};
'''+text[last:]
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    w=ROOT/'firesim/dac2026/work/opt4-linux-v6'
    if a.diagnostic36:
        profile='diagnostic36-small' if a.diagnostic_small else 'diagnostic36'
        receipt_dir=w/profile
        image_dir=ROOT/'firesim/dac2026/images/opt4-linux-v6'/profile
        configuration='C4-v6-diagnostic36'
        memory_model='unchanged native DRAMSim2 256 MiB; diagnostic kernel MAX_PHYSMEM_BITS=36'
    elif a.firesim:
        receipt_dir=w/'firesim-software'
        image_dir=ROOT/'firesim/dac2026/images/opt4-linux-v6/firesim'
        configuration='C4-v6-FireSim'
        memory_model='generated FireSim target DTS; preserve FASED memory base and size'
    elif a.native_htif:
        receipt_dir=w/'native-htif'
        image_dir=ROOT/'firesim/dac2026/images/opt4-linux-v6/native-htif'
        configuration='C4-v6-native-HTIF'
        memory_model='original native DRAMSim2; exact same native RTL, existing HTIF console'
    else:
        receipt_dir=w
        image_dir=ROOT/'firesim/dac2026/images/opt4-linux-v6'
        configuration='C4-v6-native'
        memory_model='original v1Config native DRAMSim2; not comparable with B FireSim FASED'
    receipt_dir.mkdir(parents=True,exist_ok=True)
    out=image_dir/('fdt-'+stamp)
    out.mkdir(parents=True,exist_ok=False);(out/'C4.dts').write_text(text)
    subprocess.run([str(ENV/'bin/dtc'),'-I','dts','-O','dtb','-p','4096','-o',str(out/'C4.dtb'),str(out/'C4.dts')],check=True,
                   stdout=subprocess.DEVNULL,stderr=(out/'dtc.log').open('wb'))
    result={'phase':'fdt','configuration':configuration,'returncode':0,
            'source_dts':str(a.dts.resolve()),'source_dts_sha256':sha(a.dts),
            'dts':str(out/'C4.dts'),'dts_sha256':sha(out/'C4.dts'),'fdt':str(out/'C4.dtb'),'sha256':sha(out/'C4.dtb'),
            'linux_harts':[0],'firmware_checker_harts':[1,2,3,4],
            'console':'HTIF/SBI hvc0' if a.native_htif else 'SiFive UART 115200',
            'guest_mode':a.guest_mode if a.native_htif else 'interactive',
            'memory_model':memory_model,
            'linux_memory_limit_mib':32 if a.diagnostic_small else None,
            'slowdown_eligible':False,
            'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN'}
    (out/'result.json').write_text(json.dumps(result,indent=2)+'\n')
    (receipt_dir/'fdt-build.json').write_text(json.dumps(result,indent=2)+'\n')
    print(out/'result.json')
if __name__=='__main__':main()
