#!/usr/bin/env python3
"""Compile native Opt4 C4 Linux Verilator, using the existing Chipyard make path. Never run."""
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import subprocess
import shutil
import time
from build_minimal import ROOT, BASE, ENV, inventory, resource_check, sha

def main():
    w=BASE/'opt4-linux-v6';cy=w/'C4/chipyard'
    lock=open(BASE/'.dac-c4-linux-compile.lock','a')
    fcntl.flock(lock,fcntl.LOCK_EX)
    resources=resource_check()
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    out=w/'builds'/('C4-native-'+stamp);out.mkdir(parents=True,exist_ok=False)
    log=ROOT/'Experiment/dac2026/build-logs/opt4-linux-v6'/out.name;log.mkdir(parents=True,exist_ok=False)
    source=inventory(cy)
    for n in ['common.mk','variables.mk','sims/verilator/Makefile','sims/common-sim-flags.mk']:
        source[n]=sha(cy/n)
    sourceid=hashlib.sha256(json.dumps(source,sort_keys=True).encode()).hexdigest()
    (log/'sources.json').write_text(json.dumps(source,indent=2)+'\n')
    sim=out/'verilator';sim.mkdir();(sim/'Makefile').symlink_to(cy/'sims/verilator/Makefile')
    shutil.copytree(cy/'tools/DRAMSim2',out/'dramsim',symlinks=True,
        ignore=shutil.ignore_patterns('.git','*.o','*.a','*.so','*.po','*.dep','*.deppo'))
    cache=BASE/'opt4-minimal-v2/cache'
    env=os.environ.copy()
    for k in ['LD_LIBRARY_PATH','LD_PRELOAD','CLASSPATH','JAVA_OPTS','_JAVA_OPTIONS','FIRESIM_STANDALONE']:env.pop(k,None)
    env.update(PATH=f'{ENV}/bin:{ENV}/riscv-tools/bin:/usr/local/bin:/usr/bin:/bin',
        RISCV=str(ENV/'riscv-tools'),CONDA_PREFIX=str(ENV),JAVA_HOME=str(ENV/'lib/jvm'),
        SBT_BIN=f'{ENV}/bin/java -jar {ENV}/bin/sbt-launch.jar',SBT_OPTS='',
        COURSIER_CACHE=str(cache/'coursier/v1'),
        JAVA_TOOL_OPTIONS='-Xmx12G -Xss8M -XX:ActiveProcessorCount=2 -Dsbt.task.cpus=2 '
        '-Dsbt.supershell=false -Dsbt.server.autostart=false -Dsbt.color=false -Dec.dac.firesim=true '
        f'-Duser.home={cache}/java-home -Dsbt.boot.directory={cache}/sbt/boot -Dsbt.global.base={cache}/sbt',
        CC='/usr/bin/gcc',CXX='/usr/bin/g++',MAKEFLAGS='-j2',OMP_NUM_THREADS='2')
    args=['nice','-n','15','make','-j2','-C',str(sim),'-f',str(cy/'sims/verilator/Makefile'),
        'base_dir='+str(cy),'sim_dir='+str(sim),'gen_dir='+str(out/'generated'),
        'build_dir='+str(out/'generated'),'output_dir='+str(out/'output'),
        'dramsim_dir='+str(out/'dramsim'),'CONFIG=DacLinuxC4','VERILATOR_THREADS=1',
        'EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS','default']
    command={'argv':args,'cwd':str(cy),'environment':{k:env[k] for k in ['PATH','RISCV','CONDA_PREFIX','SBT_BIN','JAVA_TOOL_OPTIONS','CC','CXX']}}
    (log/'command.json').write_text(json.dumps(command,indent=2)+'\n')
    (log/'build-script.py').write_bytes(Path(__file__).read_bytes())
    print(log,flush=True);start=time.monotonic()
    with (log/'build.log').open('wb',buffering=0) as f:
        rc=subprocess.run(args,cwd=cy,env=env,stdout=f,stderr=subprocess.STDOUT).returncode
    binary=sim/'simulator-chipyard-DacLinuxC4'
    error=None
    after=inventory(cy)
    for n in ['common.mk','variables.mk','sims/verilator/Makefile','sims/common-sim-flags.mk']:after[n]=sha(cy/n)
    if source!=after:rc=1;error='source changed during compilation'
    if not binary.is_file() and not rc:rc=1;error='simulator artifact missing'
    outputs={str(p):sha(p) for p in [binary,*out.glob('generated/*.dts'),*out.glob('generated/*.dtb')] if p.is_file()}
    receipt={'phase':'native-verilator','configuration':'chipyard.DacLinuxC4','returncode':rc,'error':error,
        'source_tree':str(cy),'source_id':sourceid,'resources':resources,'command':command,
        'output_dir':str(out),'simulator':str(binary),'outputs':outputs,'wall_seconds':time.monotonic()-start,
        'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN',
        'observation':'actual RTL package begin/result plus source-clock ROI and live counters',
        'legacy_input_only_loggers':'disabled using existing ec.dac.firesim guard; functional comparison retained'}
    (log/'result.json').write_text(json.dumps(receipt,indent=2)+'\n')
    if not rc:(w/'native-build.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print('returncode='+str(rc),flush=True);return rc
if __name__=='__main__':raise SystemExit(main())
