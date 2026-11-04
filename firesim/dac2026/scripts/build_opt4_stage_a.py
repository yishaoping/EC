#!/usr/bin/env python3
"""Compile a short payload and stage the already built frozen Opt4 RTL simulator. Never run it."""
import datetime
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
from build_minimal import ROOT, sha

KIT = ROOT/'firesim/dac2026'
WORK = KIT/'work/opt4-linux-v6'

def main():
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    log = ROOT/'Experiment/dac2026/build-logs/opt4-linux-v6'/('stage-A-'+stamp)
    out = WORK/'builds'/('stage-A-'+stamp)
    log.mkdir(parents=True, exist_ok=False)
    out.mkdir(parents=True, exist_ok=False)
    sw = WORK/'stage-a-software'
    shutil.copy2(KIT/'checker-v6/stage_a.c', sw/'test.c')
    cy = ROOT/'chipyard'
    tools = cy/'.conda-env/riscv-tools/bin'
    gloss = cy/'toolchains/libgloss'
    (out/'riscv-pk').mkdir()
    shutil.copy2(cy/'toolchains/riscv-tools/riscv-pk/machine/encoding.h',out/'riscv-pk/encoding.h')
    shutil.copy2(gloss/'util/htif.ld',out/'htif.ld')
    commands=[]
    with (log/'build.log').open('wb',buffering=0) as stream:
        def run(argv):
            argv=list(map(str,argv)); commands.append(argv)
            subprocess.run(argv,cwd=out,stdout=stream,stderr=subprocess.STDOUT,check=True)
        sources=[sw/p for p in ['test.c','hw/interrupt.c','core/checker.c','core/secondary.c',
                                'cfg/init.c','hw/spin_lock.c','stat/report.c']]
        run([tools/'riscv64-unknown-elf-gcc','-O2','-march=rv64imafd','-mabi=lp64d','-static',
             '-fno-common','-fno-builtin-printf','-specs='+str(gloss/'util/htif_nano.specs'),
             '-L'+str(gloss/'build'),'-I'+str(out),'-I'+str(sw),*sources,'-o',out/'short.riscv'])
        with (out/'short.dump').open('wb') as dis:
            subprocess.run([str(tools/'riscv64-unknown-elf-objdump'),'-d',str(out/'short.riscv')],
                           stdout=dis,stderr=stream,check=True)
    # This executable is the actual frozen Opt4 build, not another same-name config.
    ref=ROOT/'slowdown/optimization_4_svb'
    manifest=ref/'runs/optimization_4_svb_20261030_072604_18475a92/run_manifest.json'
    history=json.loads(manifest.read_text())
    expected=history['source']['hardware_sha256']
    mismatches=[n for n,h in expected.items() if not (ROOT/n).is_file() or sha(ROOT/n)!=h]
    if mismatches: raise RuntimeError('frozen source mismatch: '+repr(mismatches))
    binary=ref/'build/optimization_4_svb_20261030_072604_18475a92/verilator/simulator-chipyard-v1Config'
    simulator=out/'simulator-chipyard-v1Config'
    shutil.copy2(binary,simulator)
    shutil.copy2(cy/'.conda-env/riscv-tools/lib/libdramsim.so',out/'libdramsim.so')
    subprocess.run(['patchelf','--set-rpath','$ORIGIN:/usr/lib/x86_64-linux-gnu:/lib/x86_64-linux-gnu',str(simulator)],check=True)
    shutil.copytree(cy/'generators/testchipip/src/main/resources/dramsim2_ini',out/'dramsim2_ini')
    artifacts={str(p):sha(p) for p in out.rglob('*') if p.is_file()}
    identity={'phase':'stage-A-build','returncode':0,'target_execution':'NOT_RUN',
       'runtime_validation':'NOT_RUN','configuration':'original chipyard.v1Config frozen slowdown/opt4',
       'commands':commands,'software_sources':{str(p):sha(p) for p in sw.rglob('*') if p.is_file() and p.suffix in {'.c','.h'}},
       'hardware_manifest':str(manifest),'hardware_manifest_sha256':sha(manifest),
       'hardware_source_hashes':expected,'simulator_origin':str(binary),
       'simulator_sha256':sha(simulator),'simulator_origin_sha256':sha(binary),
       'elf_code_unchanged_by_rpath_adaptation':True,'reused_existing_simulator':True,
       'elf':str(out/'short.riscv'),'simulator':str(simulator),'output_dir':str(out),
       'outputs':artifacts,'minimum_packages':2,
       'coverage':'bare-metal real task/CPS/ECP/LSL/final comparison/result CDC; no Linux claim',
       'cache_shadow_validation':'separate, not asserted by this package smoke'}
    identity['identity']=hashlib.sha256(json.dumps(identity,sort_keys=True).encode()).hexdigest()
    (log/'result.json').write_text(json.dumps(identity,indent=2)+'\n')
    (WORK/'stage-a-build.json').write_text(json.dumps(identity,indent=2)+'\n')
    print(log/'result.json')

if __name__=='__main__': main()
