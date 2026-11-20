#!/usr/bin/python3
"""Versioned reference-resolution correction; reuse exact completed proofs."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import resource
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-nested-model-extraction-r2-20261113'
P=D/'build-logs/Opt4-nested-model-extraction-r1-20261113'
T=W/'Opt4-area-nested-model-extraction-r2-20261113'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
spec=importlib.util.spec_from_file_location('nested_resolution_predecessor',W/'candidates/nested-model-extraction-r1-20261113/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.C,m.O,m.T=C,O,T


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt exact owner'
    unit='ec-opt4-nested-model-extraction-r1-20261113.service'
    assert not m.members(unit),'Wait for exact predecessor cgroup release'
    save(O/'predecessor-release.json',dict(unit=unit,members=[],utc=now()))
    failed=read(P/'failure.json');assert failed['active_stage']=='actual-production-extraction'
    os.sched_setaffinity(0,{218,219});resource.setrlimit(resource.RLIMIT_AS,(32*2**30,)*2)
    binding=read(C/'source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['hardware_commit']
    for rel,h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git','show',binding['hardware_commit']+':'+rel],cwd=T)).hexdigest()==h
    receipts={}
    for name in ['compile','nested-scope-regression','emit-reference','emit-candidate','sequential-equivalence']:
        p=P/(name+'-receipt.json');r=read(p)
        assert r['accepted'] and r['returncode']==0 and sha(r['log'])==r['log_sha256']
        assert all(sha(f)==h for f,h in r['outputs'].items())
        receipts[name]=dict(path=str(p),sha256=sha(p))
    assert 'Of those cells 1033 are proven and 0 are unproven.' in (P/'sequential-equivalence.log').read_text()
    m.ST.update(schema='ec-nested-model-resolved-reference-recovery/1',**identity(),started_utc=now(),
        functional_baseline=binding['functional_baseline'],hardware_commit=binding['hardware_commit'],
        compiler_source_parent_commit=binding['parent_commit'],cpus=[218,219],memory_limit_gib=32,
        fpga_access=False,no_CAD=True,full_system_fit=False,production_admission=False,
        source_binding_sha256=sha(C/'source-binding.json'),
        scope='Same compiler source, reused completed60-case/sequential proof; actual saved production reference normalized at same stock analysis stage. No host token/area/whole EC equivalence claim.')
    m.update('VERIFYING_COMPLETED_PROOFS_AND_EQUIVALENT_REFERENCE_ANALYSIS')
    save(O/'adopted-proof-receipts.json',dict(receipts=receipts,rerun=False,hardware_or_compiler_changed=False))
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    java=[cfg['java'],'-Xmx24G','-Xss32M','-XX:ActiveProcessorCount=2']
    base=str(P/'classes')+':'+':'.join(cfg['classpath'])
    classes=O/'classes';classes.mkdir()
    m.stage('compile-reference-normalization',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',base,'-d',classes,C/'Regression.scala'],[classes/'nestedmodeltest/Production.class'])
    source=D/'build-logs/Opt4-address-banked-production-host-r1-20261112/Threaded'
    m.stage('actual-production-extraction',java+['-cp',str(classes)+':'+base,'nestedmodeltest.Production',O,
        source/'post-wrap-sram-models.fir',source/'post-trigger-wiring.json'],
        [O/'production-extracted.fir',O/'production-extracted.anno.json',O/'production-summary.json'],
        marker='ACTUAL_PRODUCTION_NESTED_MODEL_EXTRACTION_PASS',timeout=1800)
    summary=read(O/'production-summary.json')
    assert summary['same_reference_resolution_both_sides'] and summary['raw_IR_metadata_differs'] and summary['raw_vs_resolved_serialized_bank_equal']
    assert all(sha(p)==h for p,h in binding['files'].items())
    m.update('PASS_NESTED_MODEL_EXTRACTION_SCOPE_AND_SEQUENTIAL_REGRESSION_WITH_ACTUAL_PRODUCTION_EXTRACTION',
        regression=read(P/'regression-summary.json'),actual_production=summary,
        sequential_equivalence=True,proven_equivalence_cells=1033,ended_utc=now(),
        next='Compiler prerequisite only: consume actual production/mixed-host token and material compatible area results, then full caller/frozenDCache/host/ABI validation before exact complete-shell postopt.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now());save(O/'failure.json',m.ST)
        raise
