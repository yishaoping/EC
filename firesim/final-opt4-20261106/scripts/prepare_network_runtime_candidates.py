#!/usr/bin/env python3
"""Link actual ROI hooks for ready network candidates, without FPGA access.

These ELFs remain outside the formal queue until original ROI/context support
is proven. Compiling hooks never establishes checker compatibility.
"""
import copy
import datetime as dt
import fcntl
import json
from pathlib import Path
import subprocess

from board_batch import W, D, save, sha
from network_binding import candidate


def main():
    lock=(D/'software/network-runtime-candidates.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    base_sha,base=candidate(W/'software/network-candidate-build.json')
    parent=json.loads((W/'software/apps-build.json').read_text())
    hooks=Path(parent['output_dir'])
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('network-runtime-candidates-'+stamp);out.mkdir()
    logs=D/'software'/out.name;logs.mkdir()
    state=dict(schema='ec-network-runtime-candidates/1',status='LINKING',output_dir=str(out),
               log_dir=str(logs),canonical_base_receipt_sha256=base_sha,
               hardware_commit='8491167d84b6d9521b151a743673c1516926a1f8',
               hardware_modified=False,fpga_execution=False,formal_eligible=False,
               programs={},commands=[])
    roi=[hooks/'hooks.o',hooks/'dac_roi.o']
    state['roi_objects']={str(p):sha(p) for p in roi}
    for name in ['netdedup','netstreamcluster']:
        build=copy.deepcopy(base)
        if name=='netdedup':
            receipt_path=W/'software/netdedup-framed-candidate-build.json'
            build=json.loads(receipt_path.read_text())
            original=Path(base['output_dir'])/'netdedup/server/encoder.c'
            replacement=Path(build['output_dir'])/'encoder.c'
            entry=next(c for c in base['commands'] if c['label']=='netdedup-server')
            argv=[str(replacement) if a==str(original) else a for a in entry['argv']]
            key='server/netdedup'
        else:
            receipt_path=W/'software/network-candidate-build.json'
            entry=next(c for c in base['commands'] if c['label']=='netstreamcluster-server')
            argv=list(entry['argv']);key='server/server'
        output=out/name/key;output.parent.mkdir(parents=True)
        argv=[a for a in argv if not a.endswith('/diagnostic-hooks.o')]
        argv[-1]=str(output);argv+=list(map(str,roi))
        log=logs/(name+'-link.log')
        with log.open('wb') as stream:
            result=subprocess.run(['nice','-n','15',*argv],stdout=stream,stderr=subprocess.STDOUT,timeout=120)
        state['commands'].append(dict(program=name,argv=argv,returncode=result.returncode,log=str(log)))
        assert result.returncode==0,name
        bins=build['programs'][name]['binaries']
        for b in bins.values():assert sha(b['path'])==b['sha256']
        bins[key]=dict(path=str(output),sha256=sha(output))
        info=json.loads((D/'software'/(name+'-preparation-state.json')).read_text())
        state['programs'][name]=dict(binaries=bins,source_receipt=str(receipt_path),source_receipt_sha256=sha(receipt_path),
            hooks='Original application ROI sites linked to real ec_dac_roi begin/end objects',
            original_roi_preserved=True,formal_runconf=info['formal_runconf'],
            input_mapping=info['mapping'],application_thread_argument=1,
            actual_process_threads='Includes user-TCP internal threads; argument 1 does not imply single-thread process',
            runtime_validation='NOT_RUN',checker_compatibility='BLOCKED_ORIGINAL_ROI_CONTEXT_AND_SYSCALLS',
            admission='Do not enroll as formal; need supported complete original ROI, zero faults, real checker comparison/drain and exact output')
        save(logs/'manifest.json',state)
    state.update(status='LINKED_NOT_FPGA_VALIDATED',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(logs/'manifest.json',state);save(W/'software/network-runtime-candidates.json',state)
    print(json.dumps(dict(status=state['status'],manifest=str(logs/'manifest.json'),programs=list(state['programs']))))


if __name__=='__main__':main()
