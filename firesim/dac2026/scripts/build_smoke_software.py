#!/usr/bin/env python3
"""Compile fixed RV64 Linux smoke/PARSEC payloads; never execute target code."""
from pathlib import Path
import hashlib
import json
import subprocess
import datetime
import tarfile

ROOT=Path('/data1/gzh/EC')
KIT=ROOT/'firesim/dac2026'
PARSEC=KIT/'work/parsec-20261102'
TOOLS=ROOT/'firesim/envs/manager-1.17.1/riscv-tools/bin'

def digest(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=KIT/'images/opt4-minimal-v2'/stamp
    out.mkdir(parents=True,exist_ok=False)
    log=ROOT/'Experiment/dac2026/build-logs/opt4-minimal-v2'/('software-'+stamp)
    log.mkdir(parents=True)
    commands=[]
    with open(log/'build.log','wb',buffering=0) as f:
        def run(argv,cwd=out,stdout=None):
            commands.append({'argv':list(map(str,argv)),'cwd':str(cwd)})
            subprocess.run(list(map(str,argv)),cwd=cwd,stdout=stdout or f,stderr=f,check=True)
        gcc=TOOLS/'riscv64-unknown-linux-gnu-gcc'
        gxx=TOOLS/'riscv64-unknown-linux-gnu-g++'
        flags=['-O3','-march=rv64gc','-mabi=lp64d','-D_GNU_SOURCE']
        run([gcc,*flags,'-static','-I'+str(KIT/'measurement'),KIT/'guest/roi-smoke.c',
             KIT/'measurement/dac_roi.c','-o',out/'roi-smoke'])
        hooks=PARSEC/'pkgs/libs/hooks/src'
        run([gcc,*flags,'-c',hooks/'hooks.c','-o',out/'hooks.o'])
        app=PARSEC/'pkgs/apps/blackscholes/src'
        with open(out/'blackscholes.m4.cpp','wb') as m4:
            run(['m4',app/'c.m4.pthreads',app/'blackscholes.c'],stdout=m4)
        run([gxx,*flags,'-std=gnu++17','-DENABLE_THREADS','-DENABLE_PARSEC_HOOKS',
             '-DNCO=4','-I'+str(hooks/'include'),'-I'+str(app),'-static','-pthread',
             out/'blackscholes.m4.cpp',out/'hooks.o','-lm','-latomic','-o',out/'blackscholes'])
        for binary in ['roi-smoke','blackscholes']:
            run([TOOLS/'riscv64-unknown-linux-gnu-readelf','-h',out/binary])
            with open(out/(binary+'.disassembly'),'wb') as asm:
                run([TOOLS/'riscv64-unknown-linux-gnu-objdump','-d',out/binary],stdout=asm)
            text=(out/(binary+'.disassembly')).read_text()
            assert '6b100013' in text and '6b200013' in text,'ROI marker missing'
            assert 'ec_dac_roi_begin' in text and 'ec_dac_roi_end' in text,'ROI hooks missing'
    inputs={}
    for size in ['test','simsmall']:
        archive=PARSEC/f'pkgs/apps/blackscholes/inputs/input_{size}.tar'
        dest=out/'inputs'/size
        dest.mkdir(parents=True)
        with tarfile.open(archive) as t:
            for member in t.getmembers():
                if not member.isfile():
                    continue
                if Path(member.name).is_absolute() or '..' in Path(member.name).parts:
                    raise ValueError('unsafe input member')
                target=dest/member.name
                target.parent.mkdir(parents=True,exist_ok=True)
                target.write_bytes(t.extractfile(member).read())
        inputs[size]={'archive_sha256':digest(archive),'files':{str(p.relative_to(dest)):digest(p) for p in dest.rglob('*') if p.is_file()}}
    manifest={'status':'COMPILED; NOT_EXECUTED; requires real ROI device and checker Linux integration',
        'output':str(out),'compiler':str(gcc),'compiler_version':subprocess.check_output([str(gcc),'--version'],text=True).splitlines()[0],
        'commands':commands,'binaries':{n:digest(out/n) for n in ['roi-smoke','blackscholes']},'inputs':inputs,
        'shared_binary_for':['B','C2','C4','C8'],'application_threads':1,
        'target_execution':'NOT_RUN','linux_image':'NOT_BUILT',
        'source_hashes':{str(p):digest(p) for p in [KIT/'guest/roi-smoke.c',KIT/'measurement/dac_roi.c',KIT/'measurement/dac_roi.h',
            hooks/'hooks.c',hooks/'config.h',hooks/'dac_roi.c',hooks/'dac_roi.h',app/'blackscholes.c',app/'c.m4.pthreads',app/'spin_lock.h']}}
    (out/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    (log/'result.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(out)

if __name__=='__main__':
    main()
