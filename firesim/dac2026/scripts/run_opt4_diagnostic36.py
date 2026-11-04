#!/usr/bin/env python3
"""Sequential software-only short -> Linux smoke -> Blackscholes test.

Wait for the existing short run via filesystem notification, never PID polling.
Every simulator is started by its version-bound existing runner. No FPGA path.
"""
import argparse
import ctypes
import datetime as dt
import json
import os
from pathlib import Path
import select
import subprocess
import sys
from build_minimal import ROOT, sha

SCRIPTS=Path(__file__).resolve().parent
WORK=ROOT/'firesim/dac2026/work/opt4-linux-v6'

def save(path,value):
    tmp=path.with_suffix('.tmp')
    with tmp.open('w') as f:
        json.dump(value,f,indent=2);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(tmp,path)
    fd=os.open(path.parent,os.O_DIRECTORY);os.fsync(fd);os.close(fd)

def wait_verification(attempt):
    lib=ctypes.CDLL(None,use_errno=True)
    fd=lib.inotify_init1(os.O_CLOEXEC|os.O_NONBLOCK)
    if fd<0:raise OSError(ctypes.get_errno(),'inotify_init1')
    try:
        if lib.inotify_add_watch(fd,os.fsencode(attempt),0x8|0x80|0x100)<0:
            raise OSError(ctypes.get_errno(),'inotify_add_watch')
        while True:
            path=attempt/'verification.json'
            if path.exists():
                try:return json.loads(path.read_text())
                except json.JSONDecodeError:pass
            select.select([fd],[],[])
            while True:
                try:os.read(fd,65536)
                except BlockingIOError:break
    finally:os.close(fd)

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--short-attempt',type=Path,required=True)
    p.add_argument('--smoke-attempt',type=Path,required=True)
    a=p.parse_args();short=a.short_attempt.resolve();smoke=a.smoke_attempt.resolve()
    assert short.parent==ROOT/'Experiment/dac2026/opt4-linux-v6/native-short/partial'
    assert smoke.parent==ROOT/'Experiment/dac2026/opt4-linux-v6/linux/partial'
    sm=json.loads((smoke/'manifest.json').read_text())
    sh=json.loads((short/'manifest.json').read_text())
    assert sm['profile'] in ['diagnostic36','diagnostic36-small'] and sm['mode']=='smoke'
    small=sm['profile']=='diagnostic36-small'
    profile=sm['profile']
    assert sh['native']==sm['receipts']['native']['value']
    assert not (smoke/'STARTED.json').exists()
    state={'pid':os.getpid(),'started_at':dt.datetime.now(dt.timezone.utc).isoformat(),
        'short_attempt':str(short),'smoke_attempt':str(smoke),'commands':[],
        'script_sha256':sha(__file__),'runner_sha256':sm['runner_sha256'],
        'smoke_manifest_sha256':sha(smoke/'manifest.json'),
        'short_manifest_sha256':sha(short/'manifest.json'),'software_only':True,
        'slowdown_eligible':False,'status':'WAITING_FOR_NATIVE_SHORT'}
    with (smoke/'diagnostic-chain-owner.json').open('x') as f:
        json.dump(state,f,indent=2);f.flush();os.fsync(f.fileno())
    status=smoke/'diagnostic-chain-state.json'
    save(status,state);print(status,flush=True)
    def run(name,args):
        command=[sys.executable,*map(str,args)]
        state.update(status=name,updated_at=dt.datetime.now(dt.timezone.utc).isoformat())
        state['commands'].append(command);save(status,state)
        logfile=smoke/(name.lower()+'.log')
        with logfile.open('xb',buffering=0) as f:
            rc=subprocess.run(command,cwd=ROOT,stdout=f,stderr=subprocess.STDOUT).returncode
            os.fsync(f.fileno())
        state.update(last_returncode=rc);save(status,state)
        if rc:raise RuntimeError(name+' failed; '+str(logfile))
        return logfile.read_text()
    try:
        verdict=wait_verification(short)
        if not verdict.get('valid'):raise RuntimeError('native short invalid; Linux not started')
        assert sha(short/'manifest.json')==state['short_manifest_sha256']
        assert sha(smoke/'manifest.json')==state['smoke_manifest_sha256']
        if (smoke/'CONTINUATION_DISABLED.json').exists():raise RuntimeError('chain disabled')
        run('RUNNING_SMOKE',[SCRIPTS/'opt4_linux_run.py','run','--attempt',smoke])
        b=json.loads((smoke/'verification.json').read_text())
        committed=smoke.parent.parent/'complete'/(smoke.name+'.json')
        assert b['valid'] and committed.exists()
        state['smoke_verification_sha256']=sha(smoke/'verification.json')
        print('Linux smoke valid; preparing Blackscholes test',flush=True)
        dts=Path(sm['receipts']['native']['value']['output_dir'])/'generated/chipyard.TestHarness.DacLinuxC4.dts'
        extra=['--diagnostic-small'] if small else []
        run('PREPARING_TEST_FDT',[SCRIPTS/'prepare_opt4_fdt.py','--native-htif','--diagnostic36',*extra,'--guest-mode','test','--dts',dts])
        fdt=json.loads((WORK/profile/'fdt-build.json').read_text())
        kernel=sm['receipts']['firmware']['value']['kernel_result']
        run('BUILDING_TEST_FIRMWARE',[SCRIPTS/'build_opt4_linux_software.py','firmware','--native-htif','--diagnostic36',*extra,'--kernel-result',kernel,'--fdt',fdt['fdt']])
        prepared=run('PREPARING_TEST_ATTEMPT',[SCRIPTS/'opt4_linux_run.py','prepare','--profile',profile,'--console','htif','--mode','test','--max-cycles','100000000'])
        test=Path(prepared.strip())
        assert test.parent==smoke.parent
        state['test_attempt']=str(test);save(status,state)
        run('RUNNING_BLACKSCHOLES_TEST',[SCRIPTS/'opt4_linux_run.py','run','--attempt',test])
        result=json.loads((test/'verification.json').read_text())
        assert result['valid'] and (test.parent.parent/'complete'/(test.name+'.json')).exists()
        state.update(status='SMOKE_AND_BLACKSCHOLES_VALID',test_verification_sha256=sha(test/'verification.json'))
    except Exception as exc:
        state.update(status='STOPPED_ON_FAILURE',error=repr(exc))
        save(status,state);print(json.dumps(state,indent=2),flush=True);return 1
    state['ended_at']=dt.datetime.now(dt.timezone.utc).isoformat();save(status,state)
    print(json.dumps(state,indent=2),flush=True)
    return 0

if __name__=='__main__':raise SystemExit(main())
