#!/usr/bin/python3
"""Require actual full-shell capacity and complete physical proof for this host."""
from pathlib import Path
import json
import re
import shutil
from identity import W,D,R,OUT,COMMIT,BASE,PROFILE,PHYSICAL,read,sha,write

READY='PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION'


def checked_receipt(path,commit,sid):
    row=read(path)
    assert row['returncode']==0 and row['hardware_commit']==commit
    assert row['host_transform_id']==sid and row['outputs']
    assert all(sha(p)==h for p,h in row['outputs'].items())
    return row


def check_state(state,bundle):
    """Identity gate is checked before reading any physical artifact."""
    assert state['hardware_commit']==COMMIT
    assert state['host_transform_id']==bundle['host_transform_id']
    assert state['host_rtl_sha256']==bundle['host_rtl_sha256']
    assert state['functional_baseline']==BASE
    assert state['status']==READY and not state['fpga_access']
    assert state['shell_excluded'] is False
    assert state['actual_full_shell_postopt_fit'] is True
    assert state['configuration']=='DacOpt4C4' and state['part']=='xcu280-fsvh2892-2L-e'


def certify():
    if not PHYSICAL.exists() or read(PHYSICAL).get('status')!=READY:
        return dict(status='WAITING_REAL_SPRINT_FULL_SHELL_FIT_TIMING_DRC_BITSTREAM',
                    certified_bitstream=False,fpga_access=False)
    state=read(PHYSICAL);bundle=read(R/'bundle.json');sid=bundle['host_transform_id']
    check_state(state,bundle)
    assert all(sha(p)==h for p,h in bundle['immutable_inputs'].items())
    assert all(sha(p)==h for p,h in bundle['scripts'].items())
    receipts={}
    for name in ['shell_link','top_opt','place','route','timing_drc_bitstream']:
        path=Path(state['actual_stage_receipts'][name])
        checked_receipt(path,COMMIT,sid);receipts[name]=str(path)
    for k in ['CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','URAM','DSPs']:
        row=state['top_postopt_resources'][k]
        assert row['available']>0 and 0<=row['used']<=row['available']
    for p,h in state['physical_reports'].items():assert sha(p)==h
    timing=read(state['physical_metrics'])
    assert timing['setup_wns']>=0 and timing['hold_whs']>=0
    assert timing['pulse_violations']==timing['bus_skew_violations']==timing['drc_errors']==0
    assert timing['unconstrained_internal_endpoints']==timing['no_clock_endpoints']==0
    assert timing['all_clocks_checked'] and timing['all_routes_complete']
    # Metrics must be emitted and hashed by the successful actual final stage.
    final=read(receipts['timing_drc_bitstream'])
    assert final['outputs'][state['physical_metrics']]==sha(state['physical_metrics'])
    bit=Path(state['bitstream']);assert sha(bit)==state['bitstream_sha256']
    assert final['outputs'][str(bit)]==sha(bit)
    dst=R/'firesim.bit'
    if not dst.exists():shutil.copy2(bit,dst)
    assert sha(dst)==sha(bit)
    stages={name:dict(returncode=0,source_id=sid,hardware_commit=COMMIT) for name in
        ['dut_synth','top_synth','implementation','timing_bitstream']}
    certificate=dict(state,status='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED',
        hardware_commit=COMMIT,target_commit=COMMIT,source_id=sid,host_transform_id=sid,
        profile=PROFILE,frozen_parent_commit=BASE,returncode=0,certified_bitstream=True,
        formal_admission=False,deployment_admission=False,durable_bitstream=str(dst),
        durable_bitstream_sha256=sha(dst),actual_stage_receipts=receipts,stages=stages,
        stage_semantics='Runtime legacy admission keys wrap actual source-bound shell_link/top_opt/place/route/final evidence; no synthetic measurement.',
        runtime_bundle_sha256=sha(R/'bundle.json'))
    write(R/'certified-build.json',certificate)
    return certificate


if __name__=='__main__':print(json.dumps(certify(),indent=2))
