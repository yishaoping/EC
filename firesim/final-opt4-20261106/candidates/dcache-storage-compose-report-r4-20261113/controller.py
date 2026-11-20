#!/usr/bin/python3
"""Read-only adoption of completed DCache CAD, correcting expected design only."""
from pathlib import Path
import fcntl
import hashlib
import json
import os
import resource
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-dcache-storage-compose-report-r4-20261113'
P=D/'build-logs/Opt4-dcache-storage-compose-r3-20261112'
R2=D/'build-logs/Opt4-dcache-storage-compose-r2-20261112'
T=W/'Opt4-area-dcache-storage-compose-report-r4-20261113'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
import resource_parser as parser
ST={}
TOP='BoomNonBlockingDCache'


def members(unit):
    found=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if any(l.split(':',2)[-1].endswith('/'+unit) or '/'+unit+'/' in l
                   for l in (p/'cgroup').read_text().splitlines()):found.append(identity(int(p.name)))
        except OSError:pass
    return found


def update(status,**kw):
    ST.update(status=status,updated_utc=now(),**kw);save(O/'state.json',ST)


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt exact original owner'
    prior='ec-opt4-dcache-storage-compose-r3-20261112.service'
    assert not members(prior),'Wait for predecessor cgroup release'
    save(O/'predecessor-release.json',dict(utc=now(),unit=prior,members=[]))
    os.sched_setaffinity(0,{216,217});resource.setrlimit(resource.RLIMIT_AS,(8*2**30,)*2)
    binding=read(C/'source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['recovery_commit']
    for rel,h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git','show',binding['recovery_commit']+':'+rel],cwd=T)).hexdigest()==h
    failed=read(P/'failure.json');assert failed['active_stage']=='map-complete-dcache'
    traceback=(P/'service.log').read_text()
    assert "resource_parser.py" in traceback and 'Design' in traceback and 'FPGATop' in traceback
    ST.update(schema='ec-dcache-completed-map-report-recovery/1',**identity(),started_utc=now(),
        functional_baseline=failed['functional_baseline'],parent_commit=failed['parent_commit'],
        recovery_commit=binding['recovery_commit'],artifact_source_variant=failed['source_variant'],
        source_variant=failed['source_variant'],source_variant_is_private=True,
        cpus=[216,217],memory_limit_gib=8,FPGA_IO=False,no_CAD=True,no_RTL_regeneration=True,
        full_system_fit=False,production_admission=False,source_binding_sha256=sha(C/'source-binding.json'),
        scope='Full frozen DCache finite regression and completed same-harness OOC synthesis pair; parser-only recovery. No generated host or shell FIT claim.')
    update('VERIFYING_COMPLETED_CAD_AND_REPORT_IDENTITY')
    receipt=read(P/'map-complete-dcache-receipt.json')
    assert receipt['returncode']==0 and not receipt['missing_outputs']
    assert all(sha(p)==h for p,h in receipt['outputs'].items())
    assert sha(receipt['log'])==receipt['log_sha256']
    log=Path(receipt['log']).read_text();assert 'synth_design completed successfully' in log and 'error "blackbox"' in log
    cycle=read(P/'full-dcache-cycle-receipt.json')
    assert cycle['returncode']==0 and not cycle['missing_outputs']
    assert sha(cycle['log'])==cycle['log_sha256']
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192 all_outputs_and_donttouch=1 assertions_enabled=1' in Path(cycle['log']).read_text()
    assert 'FULL_DCACHE_CYCLE_COUNTS cycles=8192 observations=24575 ' in Path(cycle['log']).read_text()
    contract=read(R2/'source-contract.json');assert all(sha(p)==h for p,h in contract['files'].items())
    harness=read(P/'area-harness.json');assert harness['identical_harness_to_reference'] and harness['all_original_observations'] and harness['all_original_ports']
    assert sha(harness['observed'])==harness['observed_sha256'] and sha(harness['original'])==harness['original_sha256']
    reference=harness['reference'];assert reference['hardware_commit']=='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
    assert reference['returncode']==0
    for k in ['report','checkpoint','log']:assert sha(reference[k])==reference[k+'_sha256']
    util=P/'area/utilization.rpt';hier=P/'area/hierarchical.rpt'
    text=util.read_text();ht=hier.read_text()
    totals=parser.parse_total(text,TOP);hc=parser.parse_hier(ht,totals,TOP);pc=parser.crosschecks(text,totals)
    original=parser.parse_total(Path(reference['report']).read_text(),TOP)
    parser.crosschecks(Path(reference['report']).read_text(),original)
    candidate_resources={k:v['used'] for k,v in totals.items()}
    reference_resources={k:v['used'] for k,v in original.items()}
    for k,v in reference['resources'].items():assert v==reference_resources[k]
    # These negative reports must fail all the same identity/capacity/total checks.
    line=next(l for l in text.splitlines() if '| CLB LUTs*' in l)
    negative={
        'wrong_expected_design':lambda:parser.parse_total(text,'FPGATop'),
        'missing_LUT_total':lambda:parser.parse_total(text.replace(line,line.replace('CLB LUTs*','CLB LUTx*')),TOP),
        'duplicate_LUT_total':lambda:parser.parse_total(text.replace(line,line+'\n'+line),TOP),
        'wrong_capacity':lambda:parser.parse_total(text.replace(line,line.replace('1303680','1303679')),TOP),
        'wrong_hierarchy_design':lambda:parser.parse_hier(ht,totals,'FPGATop'),
        'wrong_device':lambda:parser.parse_total(text.replace('xcu280fsvh2892-2L','xcu250fsvh2104-2L'),TOP),
    }
    regression={k:parser.rejected(fn) for k,fn in negative.items()}
    old=dict(totals);old['CARRY8']={**totals['CARRY8'],'used':totals['CARRY8']['used']+1}
    regression['wrong_primitive_total']=parser.rejected(lambda:parser.crosschecks(text,old))
    bad=dict(totals);bad['CLB LUTs']={**totals['CLB LUTs'],'used':totals['CLB LUTs']['used']+1}
    regression['wrong_hierarchy_total']=parser.rejected(lambda:parser.parse_hier(ht,bad,TOP))
    save(O/'parser-validation.json',dict(PASS=True,negative_rejected=regression,
        expected_design=TOP,hierarchy=hc,primitives=pc,capacities_unchanged=True,
        report_unmodified=True,reference_not_remapped=True))
    saved=reference_resources['CLB LUTs']-candidate_resources['CLB LUTs']
    save(O/'adoption.json',dict(original_failure=str(P/'failure.json'),original_failure_sha256=sha(P/'failure.json'),
        source_contract=str(R2/'source-contract.json'),source_contract_sha256=sha(R2/'source-contract.json'),
        map_receipt=str(P/'map-complete-dcache-receipt.json'),map_receipt_sha256=sha(P/'map-complete-dcache-receipt.json'),
        cycle_receipt=str(P/'full-dcache-cycle-receipt.json'),cycle_receipt_sha256=sha(P/'full-dcache-cycle-receipt.json'),
        candidate_files=receipt['outputs'],reference=reference,source_unchanged=True,
        correction='Expected design parameter only; totals, device, capacity, primitives and hierarchy checks preserved.'))
    assert all(sha(p)==h for p,h in binding['files'].items())
    update('COMPLETE_FULL_DCACHE_CYCLE_AND_PAIRED_MODULE_AREA_REPORT_RECOVERY_NOT_WHOLE_FIT',
        candidate_resources=candidate_resources,reference_resources=reference_resources,
        module_lut_saved=saved,complete_dcache_cycles_verified=True,target_cycles=8192,
        observations=24575,full_host_saving_unknown=True,blackboxes=0,ended_utc=now(),
        next='Consume material actual production AddressStats or mixed-host area and full caller/host/ABI closure before one source-bound complete build. Never subtract this module gain from a whole host result.')
    save(O/'result.json',ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now());save(O/'failure.json',ST)
        raise
