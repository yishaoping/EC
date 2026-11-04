#!/usr/bin/env python3
"""Reserve one source/config/tool combination; never rebuild it implicitly."""
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import traceback
import uuid
import experiment_cache as cache


def main():
    spec=importlib.util.spec_from_file_location('overlap',cache.ROOT/'slowdown/optimization_6_overlap/scripts/run_experiment.py')
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    source=mod.identity();identity=cache.build_identity(source);key=cache.digest(identity)
    with cache.locked():
        index=cache.discover()
        for old in index['local_builds']:
            if old['key']==key:
                print(json.dumps(dict(decision='DO_NOT_REBUILD',existing=old)),flush=True)
                return 0 if old['status']=='PASS' else 2
        # Historical seals have no recorded complete tool identity. Hardware
        # equality is still a stop, requiring explicit artifact review.
        for old in index['builds']:
            if old['hardware']==identity['hardware'] and old['config']==identity['config']:
                print(json.dumps(dict(decision='HISTORICAL_BUILD_EXISTS_REVIEW_FIRST',existing=old)),flush=True)
                return 2
        log=cache.OUT/'build'/('candidate_a_'+uuid.uuid4().hex[:8]+'.log')
        log.parent.mkdir(exist_ok=True)
        entry=dict(key=key,identity=identity,status='RUNNING',pid=os.getpid(),log=str(log))
        index['local_builds'].append(entry);cache.save(index)
    try:
        argv=[sys.executable,str(cache.ROOT/'slowdown/optimization_6_overlap/scripts/run_experiment.py'),
              '--label','safe_snapshot_a','--build-only','--jobs','8']
        with log.open('x') as stream:
            rc=subprocess.call(argv,cwd=cache.ROOT,stdout=stream,stderr=subprocess.STDOUT)
        entry['exit_status']=rc;entry['status']='PASS' if rc==0 else 'FAIL'
        lines=log.read_text().splitlines()
        run=next((Path(x.split('=',1)[1]) for x in lines if x.startswith('RUN_DIRECTORY=')),None)
        if run:
            entry['run']=str(run);entry['build_id']=run.name
        if rc==0:
            sim=cache.ROOT/'slowdown/optimization_6_overlap/build'/run.name/'verilator/simulator-chipyard-v1Config'
            entry.update(simulator=str(sim),simulator_sha256=cache.sha(sim))
    except BaseException:
        entry['status']='EXCEPTION';entry['error']=traceback.format_exc();rc=1
    with cache.locked():
        index=cache.read(cache.INDEX)
        index['local_builds']=[entry if b['key']==key else b for b in index['local_builds']]
        cache.save(index)
    print(json.dumps(entry),flush=True)
    return rc


if __name__=='__main__':raise SystemExit(main())
