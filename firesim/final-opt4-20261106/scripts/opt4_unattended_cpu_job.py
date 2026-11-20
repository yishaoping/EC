#!/usr/bin/env python3
"""User-only detached CPU job. Exact input binding and restart checkpoints."""
import subprocess
import sys
from opt4_unattended_common import *

def main():
    spec=read(Path(sys.argv[1]));out=U/'jobs'/spec['name'];out.mkdir(parents=True,exist_ok=True)
    lock=(out/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    path=out/'state.json';old=read(path)
    if live(old) or live(old.get('child',{})):raise RuntimeError('adopt live job')
    # Fresh CPU services read the latest user scope before executing anything.
    # Existing CAD/controller processes retain their already-loaded code.
    from opt4_frozen_scope import enforce
    try:
        scope = enforce(spec)
    except Exception as exc:
        if old:
            save(out/('before-scope-rejection-'+str(os.getpid())+'.json'), old)
        rejection=dict(schema='ec-opt4-cpu-job/1', **identity(),
                       status='CANCELLED_BY_FROZEN_ONLY_SCOPE', kind=spec['kind'],
                       ended_utc=now(), error=repr(exc), argv=spec['argv'],
                       child_started=False, outputs={})
        save(path,rejection)
        event('CPU_JOB_CANCELLED_BY_FROZEN_ONLY_SCOPE',job=spec['name'],error=repr(exc))
        raise
    hashes=bound_inputs(spec)
    if old.get('status')=='COMPLETE' and old.get('returncode')==0 and old.get('input_sha256')==hashes:
        if all(Path(p).is_file() and sha(p)==h for p,h in old.get('outputs',{}).items()):return
    if old:save(out/('before-'+str(os.getpid())+'.json'),old)
    st=dict(schema='ec-opt4-cpu-job/1',**identity(),status='RUNNING',kind=spec['kind'],started_utc=now(),input_sha256=hashes,
            checkpoints=spec.get('checkpoints',[]),argv=spec['argv'],scope=scope)
    save(path,st)
    cache=W/'cache/unattended-opt4/ccache'
    temporary=out/'tmp'
    cache.mkdir(parents=True,exist_ok=True);temporary.mkdir(exist_ok=True)
    with (out/'console.log').open('ab',buffering=0) as log:
        log.write((now()+' START '+json.dumps(spec['argv'])+'\n').encode());os.fsync(log.fileno())
        p=subprocess.Popen(spec['argv'],cwd=spec['cwd'],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,
             env={**os.environ,'PYTHONPATH':str(W/'scripts'),'CCACHE_DIR':str(cache),
                  'CCACHE_TEMPDIR':str(temporary),'TMPDIR':str(temporary)})
        st.update(child=identity(p.pid));save(path,st)
        while p.poll() is None:
            try:p.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            st.update(updated_utc=now());save(path,st);os.fsync(log.fileno())
    missing=[p for p in spec.get('outputs',[]) if not Path(p).is_file()]
    st.update(returncode=p.returncode,status='COMPLETE' if p.returncode==0 and not missing else 'FAILED_WITH_EVIDENCE',ended_utc=now(),missing_outputs=missing,
        outputs={p:sha(p) for p in spec.get('outputs',[]) if Path(p).is_file()})
    save(path,st);event('CPU_JOB_EXITED',job=spec['name'],returncode=p.returncode)

if __name__=='__main__':main()
