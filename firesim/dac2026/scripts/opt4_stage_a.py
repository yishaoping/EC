#!/usr/bin/env python3
"""Manual-only frozen Opt4 RTL short test. prepare/verify never start a target."""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import signal
import subprocess
import threading
from build_minimal import ROOT, sha

WORK=ROOT/'firesim/dac2026/work/opt4-linux-v6'
RESULTS=ROOT/'Experiment/dac2026/opt4-linux-v6/stage-A'

def write(p,obj): p.write_text(json.dumps(obj,indent=2)+'\n')
def build():
    b=json.loads((WORK/'stage-a-build.json').read_text())
    for p,h in b['outputs'].items():
        if not Path(p).is_file() or sha(p)!=h: raise ValueError('artifact changed: '+p)
    if b['returncode']!=0: raise ValueError('build failed')
    return b

def host_runtime(simulator):
    report=subprocess.run(['/usr/bin/readelf','-lW',str(simulator)],capture_output=True,
                          text=True,check=True).stdout
    match=re.search(r'Requesting program interpreter: ([^]]+)',report)
    if not match: raise ValueError('simulator ELF has no readable interpreter')
    loader=Path(match.group(1))
    if not loader.is_file(): raise ValueError('simulator ELF interpreter is missing: '+str(loader))
    libraries=[str(Path(simulator).resolve().parent),str(loader.resolve().parent),
               '/usr/lib/x86_64-linux-gnu','/lib/x86_64-linux-gnu']
    return {'loader':str(loader.resolve()),'loader_sha256':sha(loader),
            'library_path':libraries}

def current_host_runtime(runtime):
    loader=Path(runtime['loader'])
    if not loader.is_file() or sha(loader)!=runtime['loader_sha256']:
        raise ValueError('host dynamic loader changed: '+str(loader))
def prepare():
    b=build()
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    attempt=RESULTS/'partial'/stamp
    attempt.mkdir(parents=True,exist_ok=False)
    rawdir=RESULTS/'raw'/stamp
    rawdir.mkdir(parents=True,exist_ok=False)
    host=host_runtime(b['simulator'])
    target_argv=[b['simulator'],'-s','1','+cycle-count','+permissive',
          '+safe-chain-events','+safe-chain-budgeted','+dramsim',
          '+dramsim_ini_dir='+str(Path(b['output_dir'])/'dramsim2_ini'),
          '+max-cycles=20000000','+permissive-off',b['elf']]
    argv=[host['loader'],'--library-path',':'.join(host['library_path']),*target_argv]
    write(attempt/'manifest.json',{'build':b,'host_runtime':host,'target_argv':target_argv,
        'argv':argv,'cwd':str(attempt),'raw_log':str(rawdir/'raw.log'),
        'runner_sha256':sha(Path(__file__).resolve()),
        'status':'PREPARED_NOT_RUN','scope':'bare-metal real Opt4; not Linux/PARSEC/slowdown',
        'run_command':['python3',str(Path(__file__).resolve()),'run','--attempt',str(attempt)]})
    print(attempt)
def verify(attempt):
    m=json.loads((attempt/'manifest.json').read_text())
    b=build()
    if b['identity']!=m['build']['identity']: raise ValueError('build identity changed')
    current_host_runtime(m['host_runtime'])
    status=json.loads((attempt/'exit.json').read_text())
    rawpath=Path(m['raw_log'])
    raw=rawpath.read_text(errors='replace')
    rows=re.findall(r'^EC_OPT4_A_RESULT (.*)$',raw,re.M)
    reasons=[]
    if status.get('returncode')!=0: reasons.append('nonzero/interrupted simulator exit')
    if len(rows)!=1: reasons.append('expected exactly one guest result')
    fields=dict(re.findall(r'(\w+)=(\S+)',rows[0])) if len(rows)==1 else {}
    try:
        for k in ['cycles','drain_cycles','generated','completed','passed','failed','cancelled',
                  'dropped','outstanding','checksum','expected','timeout']: fields[k]=int(fields[k])
        if not (fields['cycles']>0 and fields['generated']>=2 and
                fields['generated']==fields['completed']==fields['passed']): reasons.append('task accounting incomplete')
        if any(fields[k] for k in ['failed','cancelled','dropped','outstanding','timeout']): reasons.append('checker error or backlog')
        if fields['checksum']!=32704 or fields['expected']!=32704 or fields.get('status')!='PASS': reasons.append('wrong output/status')
    except (KeyError,ValueError): reasons.append('missing or malformed statistics')
    # An assertion or observation overflow invalidates the run even with a final PASS line.
    if re.search(r'Assertion failed|%Error|SC_OVERFLOW|OBSERVATION.*(?:LOSS|OVERFLOW)|Aborted',raw,re.I): reasons.append('RTL assertion or observation failure')
    record={'valid':not reasons,'reasons':reasons,'fields':fields,'build_identity':b['identity'],
            'raw_log':str(rawpath),'raw_sha256':sha(rawpath),'exit_sha256':sha(attempt/'exit.json'),
            'scope':'Opt4 package protocol smoke; cache-shadow correctness not certified',
            'runtime_validation':'PASS' if not reasons else 'INVALID'}
    write(attempt/'verification.json',record)
    if not reasons:
        dest=RESULTS/'complete'/(attempt.name+'.json')
        dest.parent.mkdir(parents=True,exist_ok=True)
        # Retain raw files at their original path. Commit binds exact artifacts/logs.
        temporary=attempt/'completion.tmp'
        with temporary.open('x') as f:
            json.dump({**record,'attempt':str(attempt)},f,indent=2);f.flush();os.fsync(f.fileno())
        os.link(temporary,dest);temporary.unlink()
        dirfd=os.open(dest.parent,os.O_RDONLY|os.O_DIRECTORY)
        try:os.fsync(dirfd)
        finally:os.close(dirfd)
    print(json.dumps(record,indent=2)); return 0 if not reasons else 1
def run(attempt):
    m=json.loads((attempt/'manifest.json').read_text());b=build()
    if m.get('runner_sha256') and m['runner_sha256']!=sha(Path(__file__).resolve()):
        raise ValueError('Stage A runner changed after preparation')
    if b['identity']!=m['build']['identity']: raise ValueError('stale preparation')
    current_host_runtime(m['host_runtime'])
    child=None
    def stop(signum,frame):
        if child and child.poll() is None: child.send_signal(signal.SIGINT)
    signal.signal(signal.SIGINT,stop);signal.signal(signal.SIGTERM,stop)
    env=os.environ.copy();env.pop('LD_PRELOAD',None)
    # The user's explicit `run` is the sole target-starting entry. Direct file
    # capture persists while the target runs; no shutdown-dependent guest copy.
    with Path(m['raw_log']).open('xb',buffering=0) as raw:
        child=subprocess.Popen(m['argv'],cwd=attempt,env=env,stdout=raw,stderr=subprocess.STDOUT)
        started=datetime.datetime.now(datetime.timezone.utc).isoformat()
        write(attempt/'STARTED.json',{'started_at':started,'pid':child.pid,
            'build_identity':b['identity'],'argv':m['argv'],'raw_log':m['raw_log']})
        sync_stop=threading.Event()
        with (attempt/'progress.jsonl').open('x',buffering=1) as progress:
            def sync_logs():
                while not sync_stop.wait(15):
                    os.fsync(raw.fileno())
                    progress.write(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
                        'pid':child.pid,'raw_bytes':os.fstat(raw.fileno()).st_size,
                        'completion':'RUNNING','formal_sample':False})+'\n')
                    progress.flush();os.fsync(progress.fileno())
            sync_thread=threading.Thread(target=sync_logs,name='opt4-stage-a-log-sync',daemon=True)
            sync_thread.start()
            try:
                rc=child.wait()
            finally:
                sync_stop.set();sync_thread.join();os.fsync(raw.fileno())
            progress.write(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
                'pid':child.pid,'raw_bytes':os.fstat(raw.fileno()).st_size,
                'completion':'EXITED','returncode':rc,'formal_sample':False})+'\n')
            progress.flush();os.fsync(progress.fileno())
    write(attempt/'exit.json',{'returncode':rc,'build_identity':b['identity']})
    return verify(attempt)
def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('action',choices=['prepare','run','verify']);p.add_argument('--attempt',type=Path)
    a=p.parse_args()
    if a.action=='prepare': prepare();return 0
    if a.attempt is None:p.error('--attempt required')
    attempt=a.attempt.resolve()
    if attempt.parent!=RESULTS/'partial':p.error('attempt must be a prepared Stage A directory')
    return run(attempt) if a.action=='run' else verify(attempt)
if __name__=='__main__':raise SystemExit(main())
