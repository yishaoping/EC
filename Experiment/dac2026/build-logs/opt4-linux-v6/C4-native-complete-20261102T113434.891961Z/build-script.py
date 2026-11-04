#!/usr/bin/env python3
"""Resume only generated C++ compilation for an exact C4 native source receipt. Never run."""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time
from build_minimal import ROOT,BASE,ENV,sha,inventory,resource_check

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--input-result',required=True,type=Path)
    p.add_argument('--jobs',type=int,choices=range(1,9),default=8)
    a=p.parse_args();w=BASE/'opt4-linux-v6'
    lock=open(BASE/'.dac-c4-linux-compile.lock','a');fcntl.flock(lock,fcntl.LOCK_EX)
    resources=resource_check();old=json.loads(a.input_result.read_text())
    cy=Path(old['source_tree']);out=Path(old['output_dir'])
    if cy!=w/'C4/chipyard' or not out.is_relative_to(w/'builds'):raise ValueError('not this isolated C4')
    files=inventory(cy)
    for n in ['common.mk','variables.mk','sims/verilator/Makefile','sims/common-sim-flags.mk']:files[n]=sha(cy/n)
    sourceid=hashlib.sha256(json.dumps(files,sort_keys=True).encode()).hexdigest()
    if sourceid!=old['source_id']:raise ValueError('source changed: regenerate hardware first')
    for f,h in old['outputs'].items():
        if sha(f)!=h:raise ValueError('prior artifact changed: '+f)
    model=out/'generated/chipyard.TestHarness.DacLinuxC4'
    if not (model/'VTestHarness.mk').exists():raise ValueError('Verilator generation did not finish')
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    log=ROOT/'Experiment/dac2026/build-logs/opt4-linux-v6'/('C4-native-complete-'+stamp)
    log.mkdir(exist_ok=False,parents=True)
    inputs={str(f):sha(f) for f in model.iterdir() if f.is_file() and f.suffix in {'.cpp','.h','.mk'}}
    inputs.update({str(f):sha(f) for f in (out/'generated/gen-collateral').iterdir() if f.is_file()})
    (log/'inputs.json').write_text(json.dumps(inputs,indent=2)+'\n')
    (log/'sources.json').write_text(json.dumps(files,indent=2)+'\n')
    (log/'build-script.py').write_bytes(Path(__file__).read_bytes())
    env=os.environ.copy()
    for key in ['LD_LIBRARY_PATH','LD_PRELOAD','CFLAGS','CXXFLAGS','CPPFLAGS','MAKEFLAGS']:env.pop(key,None)
    env.update(PATH=f'{ENV}/bin:{ENV}/riscv-tools/bin:/usr/local/bin:/usr/bin:/bin',CONDA_PREFIX=str(ENV))
    args=['nice','-n','15','make','-j'+str(a.jobs),'-C',str(model),'-f','VTestHarness.mk','VM_PARALLEL_BUILDS=1']
    (log/'command.json').write_text(json.dumps({'argv':args,'resources':resources},indent=2)+'\n')
    print(log,flush=True);start=time.monotonic()
    with (log/'build.log').open('wb',buffering=0) as stream:
        rc=subprocess.run(args,env=env,stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT).returncode
    if inventory(cy)!={k:v for k,v in files.items() if k not in ['common.mk','variables.mk','sims/verilator/Makefile','sims/common-sim-flags.mk']}:
        rc=1
    if any(sha(f)!=h for f,h in inputs.items()):rc=1
    binary=Path(old['simulator'])
    if not binary.exists():rc=1
    outputs={str(f):sha(f) for f in [binary,*out.glob('generated/*.dts'),*out.glob('generated/*.dtb')] if f.is_file()}
    record={**old,'returncode':rc,'error':None if rc==0 else 'C++ compile or source/input verification failed',
        'resume_input_result':str(a.input_result.resolve()),'resume_input_result_sha256':sha(a.input_result),
        'compiled_input_inventory':str(log/'inputs.json'),'compiled_input_inventory_sha256':sha(log/'inputs.json'),
        'completion_command':args,'completion_log':str(log),'outputs':outputs,
        'completion_wall_seconds':time.monotonic()-start,'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN'}
    (log/'result.json').write_text(json.dumps(record,indent=2)+'\n')
    if not rc:(w/'native-build.json').write_text(json.dumps(record,indent=2)+'\n')
    print('returncode='+str(rc),flush=True);return rc
if __name__=='__main__':raise SystemExit(main())
