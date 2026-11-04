#!/usr/bin/env python3
"""Compile identical B/C4 serial blackscholes test and smoke. Never execute."""
import datetime
import json
from pathlib import Path
import shutil
import subprocess
import tarfile
from build_minimal import ROOT, ENV, sha

KIT=ROOT/'firesim/dac2026';WORK=KIT/'work/opt4-linux-v6'
def main():
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out=KIT/'images/opt4-linux-v6'/('apps-'+stamp);out.mkdir(parents=True,exist_ok=False)
    log=ROOT/'Experiment/dac2026/build-logs/opt4-linux-v6'/('apps-'+stamp);log.mkdir(parents=True,exist_ok=False)
    original=KIT/'work/parsec-20261102'
    src=out/'src';src.mkdir()
    shutil.copytree(original/'pkgs/libs/hooks/src',src/'hooks')
    for name in ['dac_roi.c','dac_roi.h','opt4_hw.h']:
        shutil.copy2(KIT/'checker-v6'/name,src/'hooks'/name)
    app=original/'pkgs/apps/blackscholes/src'
    shutil.copytree(app,src/'blackscholes')
    shutil.copy2(KIT/'guest/roi-smoke.c',src/'roi-smoke.c')
    tools=ENV/'riscv-tools/bin';commands=[]
    with (log/'build.log').open('wb',buffering=0) as stream:
        def run(args,stdout=None):
            args=list(map(str,args));commands.append(args)
            subprocess.run(args,cwd=out,stdout=stdout or stream,stderr=stream,check=True)
        flags=['-O3','-march=rv64gc','-mabi=lp64d','-D_GNU_SOURCE','-static']
        run([tools/'riscv64-unknown-linux-gnu-gcc',*flags,'-I'+str(src/'hooks'),
             src/'roi-smoke.c',src/'hooks/dac_roi.c','-o',out/'roi-smoke'])
        run([tools/'riscv64-unknown-linux-gnu-gcc',*flags,'-c',src/'hooks/hooks.c','-o',out/'hooks.o'])
        # Compile the original SERIAL branch. pthread creation within the ROI
        # would violate the supported one-mm/one-thread execution scope.
        run([tools/'riscv64-unknown-linux-gnu-g++',*flags,'-x','c++','-std=gnu++17',
             '-DENABLE_PARSEC_HOOKS','-I'+str(src/'hooks/include'),'-I'+str(src/'blackscholes'),
             src/'blackscholes/blackscholes.c','-x','none',out/'hooks.o','-lm','-o',out/'blackscholes'])
        for name in ['roi-smoke','blackscholes']:
            with (out/(name+'.dump')).open('wb') as dis:
                run([tools/'riscv64-unknown-linux-gnu-objdump','-d',out/name],dis)
            data=(out/(name+'.dump')).read_text()
            if '6b100013' not in data or '6b200013' not in data: raise RuntimeError('missing source ROI marker')
    inputs={}
    for size in ['test','simsmall']:
        archive=original/f'pkgs/apps/blackscholes/inputs/input_{size}.tar'
        dest=out/'inputs'/size;dest.mkdir(parents=True)
        with tarfile.open(archive) as tar:
            for m in tar.getmembers():
                if not m.isfile():continue
                n=Path(m.name)
                if n.is_absolute() or '..' in n.parts:raise ValueError('unsafe input archive')
                target=dest/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(tar.extractfile(m).read())
        inputs[size]={'archive_sha256':sha(archive),'files':{str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()}}
    record={'phase':'apps','returncode':0,'output':str(out),'output_dir':str(out),'commands':commands,
            'program':'blackscholes','primary_input':'test/in_4.txt','options':4,'runs':100,
            'application_threads':1,'build_variant':'upstream serial branch; ENABLE_THREADS undefined',
            'shared_binary_for':['B-v5','C4-v6'],'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN',
            'binaries':{n:sha(out/n) for n in ['roi-smoke','blackscholes']},'inputs':inputs,
            'sources':{str(p.relative_to(src)):sha(p) for p in src.rglob('*') if p.is_file()}}
    (out/'manifest.json').write_text(json.dumps(record,indent=2)+'\n')
    (log/'result.json').write_text(json.dumps(record,indent=2)+'\n')
    (WORK/'apps-build.json').write_text(json.dumps(record,indent=2)+'\n')
    print(log/'result.json')
if __name__=='__main__':main()
