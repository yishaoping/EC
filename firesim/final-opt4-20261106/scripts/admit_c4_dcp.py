#!/usr/bin/env python3
"""Certify completed private DCP artifacts and feed the existing 21-only runner.

No FPGA access and no CAD signals. Never admit a partial or failed build.
Original CAD metadata is archived before canonical admission. The first
selected receipt is pinned; later CAD receipts are retained as alternatives.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys
import time

from board_batch import W, D, save, sha
from job_service import proc
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from build_minimal import inventory

COMMIT = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
STATE = D/'C4-dcp-admission-state.json'
SELECTED = D/'C4-selected-certified-build.json'
CAD = D/'C4-runtime-cad-state.json'
RUNTIME = W/'bitstream-runtime-build.json'


def read(p):
    return json.loads(p.read_text()) if p.exists() else {}


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def check_ready(s):
    assert s['status'] == 'BUILT_NOT_RUN' and s['certified_bitstream']
    assert s['hardware_commit'] == COMMIT and s['source_id'] == SID
    assert s['configuration'] == 'C4' and not s['fpga_access']
    assert all(s['stages'][n]['returncode'] == 0 for n in
               ['dcp_read', 'prepare_impl', 'top_synth', 'implementation', 'timing_bitstream'])
    logs=Path(s['log_dir']);out=Path(s['output_dir'])
    assert out.is_relative_to(W/'dcp-work')
    assert 'EC_DCP_LINK_OK unresolved=0' in (logs/'implementation.log').read_text()
    text=(logs/'timing_bitstream.log').read_text()
    assert 'EC_DCP_ROUTE_TIMING WNS=' in text and 'EC_DCP_BITSTREAM_OK' in text
    assert (logs/'timing-summary.rpt').stat().st_size > 0
    assert (logs/'drc.rpt').stat().st_size > 0
    for p,h in s['input_hashes'].items():
        assert sha(p) == h, p
    inv=inventory(Path(s['source_tree']))
    assert hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest() == SID
    assert len(s['reused_checkpoints']) == 12
    for d in s['reused_checkpoints']:
        assert sha(d.get('stable_snapshot', d['snapshot'])) == d['sha256']
    bit=out/'vivado_proj/firesim.bit'
    assert sha(bit) == s['outputs'][str(bit)]
    return bit


def select_receipt(s):
    bit=check_ready(s)
    destination=W/'images'/Path(s['output_dir']).name
    destination.mkdir(parents=True,exist_ok=True)
    durable=destination/'firesim.bit'
    if not durable.exists():
        tmp=destination/'firesim.bit.copying';shutil.copy2(bit,tmp)
        with tmp.open('rb') as f:os.fsync(f.fileno())
        assert sha(tmp)==s['outputs'][str(bit)]
        os.replace(tmp,durable)
    assert sha(durable)==s['outputs'][str(bit)]
    receipt=dict(s,returncode=0,durable_bitstream=str(durable),
        durable_bitstream_sha256=s['outputs'][str(bit)],
        selected_from='C4-dcp-cad-state.json',admitted_utc=now(),
        deployment_admission='EXISTING_21_ONLY_CONTINUATION_AT_SAFE_TASK_BOUNDARY',
        inputs=s['input_hashes'],effective_cad_inputs={},
        no_fpga_device_access=True)
    save(destination/'result.json',receipt)
    save(SELECTED,receipt)
    return receipt


def publish(receipt):
    # Receipt first, ready signal last: an observer can only advance after the
    # durable bitstream and matching runtime receipt have been published.
    for p in [RUNTIME,CAD]:
        prior=read(p)
        if prior.get('durable_bitstream_sha256')==receipt['durable_bitstream_sha256'] and prior.get('status')=='BUILT_NOT_RUN':
            continue
        if prior:
            archive=D/'build-logs'/'c4-admission-alternatives';archive.mkdir(exist_ok=True)
            h=hashlib.sha256(p.read_bytes()).hexdigest()
            target=archive/(p.stem+'-'+h+'.json')
            if not target.exists():save(target,prior)
        save(p,receipt)


def main():
    a=argparse.ArgumentParser();a.add_argument('--check-only',action='store_true');args=a.parse_args()
    if args.check_only:
        s=read(D/'C4-dcp-cad-state.json')
        if s.get('status')!='BUILT_NOT_RUN':
            print(json.dumps(dict(status='WAITING_FOR_REAL_BUILD_COMPLETION',fpga_access=False)))
        else:
            print(json.dumps(dict(status='ARTIFACTS_VERIFIED_NOT_PUBLISHED',bitstream=str(check_ready(s)),fpga_access=False)))
        return
    assert os.geteuid()==0
    lock=(D/'locks/c4-dcp-admission.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    state=dict(schema='ec-c4-dcp-admission/1',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        started_utc=now(),status='WAITING_CERTIFIED_DCP_BUILD',fpga_access=False,
        target_bdf='0000:21:00.0',cad_signals=False)
    while True:
        selected=read(SELECTED)
        if selected:
            assert selected['hardware_commit']==COMMIT and selected['source_id']==SID
            if not state.get('selected_sha256'):
                assert sha(selected['durable_bitstream'])==selected['durable_bitstream_sha256']
        else:
            candidate=read(D/'C4-dcp-cad-state.json')
            if candidate.get('status')=='BUILT_NOT_RUN':
                existing=read(CAD)
                if existing.get('status')=='BUILT_NOT_RUN' and existing.get('certified_bitstream'):
                    # An already admitted exact build is a usable winner too.
                    assert existing['hardware_commit']==COMMIT and existing['source_id']==SID
                    assert existing['returncode']==0
                    assert sha(existing['durable_bitstream'])==existing['durable_bitstream_sha256']
                    save(SELECTED,existing);selected=existing
                else:
                    selected=select_receipt(candidate)
        if selected:
            publish(selected)
            state.update(status='CERTIFIED_RECEIPT_PUBLISHED_EXISTING_RUNNER_OWNS_FPGA',
                selected_sha256=selected['durable_bitstream_sha256'],selected_receipt=str(SELECTED))
        else:
            state.update(candidate_status=read(D/'C4-dcp-cad-state.json').get('status'))
        state.update(updated_utc=now());save(STATE,state)
        time.sleep(300)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        s=read(STATE);s.update(status='ADMISSION_FAILED_NO_FPGA_ACTION',error=repr(exc),ended_utc=now());save(STATE,s)
        raise
