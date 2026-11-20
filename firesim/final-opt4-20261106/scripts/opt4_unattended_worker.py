#!/usr/bin/env python3
"""One noninteractive optimization round, outside any SSH/VS Code process."""
import os
from pathlib import Path
import subprocess
import sys
from opt4_unattended_common import *

def environment(direct=False):
    env={k:v for k,v in os.environ.items() if not k.startswith(('VSCODE_','CODEX_')) and 'proxy' not in k.lower()}
    env.update(PATH='/usr/local/bin:/usr/bin:/bin',CODEX_HOME='/home/guozh/.codex')
    if not direct:
        cfg=read('/home/guozh/.config/ec-opt4-unattended/environment.json')
        env.update(cfg)
    auth=read('/home/guozh/.codex/auth.json')
    if not env.get('BEEAPI_API_KEY') and auth.get('OPENAI_API_KEY'):
        env['BEEAPI_API_KEY']=auth['OPENAI_API_KEY']
    return env

def main():
    # User stop applies only to autonomous model calls; existing CAD is independent.
    if (U/'MODEL_REQUESTS_DISABLED.json').exists():
        raise SystemExit(75)
    r=Path(sys.argv[1]).resolve();assert r.parent==U/'rounds'
    state=r/'worker.json'
    lock=(r/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    if live(read(state)):raise RuntimeError('live round must be adopted')
    st=dict(schema='ec-opt4-headless-round/1',**identity(),started_utc=now(),status='STARTING',round_dir=str(r))
    save(state,st)
    args=['/usr/local/bin/codex','exec','--json','--color','never','--sandbox','danger-full-access',
          '-c','approval_policy="never"','-C','/data1/gzh/EC','--output-schema',str(U/'round-schema.json'),
          '--output-last-message',str(r/'final.json'),'-']
    # Network failure is retried by the supervisor. Never print environment/auth.
    with (r/'events.jsonl').open('ab',buffering=0) as out,(r/'stderr.log').open('ab',buffering=0) as err:
        p=subprocess.Popen(args,stdin=subprocess.PIPE,stdout=out,stderr=err,env=environment(read(U/'network.json').get('mode')=='DIRECT'))
        st.update(status='RUNNING',child=identity(p.pid));save(state,st)
        p.stdin.write((r/'prompt.md').read_bytes());p.stdin.close()
        while p.poll() is None:
            try:p.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            st.update(updated_utc=now());save(state,st)
            os.fsync(out.fileno());os.fsync(err.fileno())
    st.update(status='EXITED',returncode=p.returncode,ended_utc=now());save(state,st)
    event('ROUND_EXITED',round_dir=str(r),returncode=p.returncode)

if __name__=='__main__':main()
