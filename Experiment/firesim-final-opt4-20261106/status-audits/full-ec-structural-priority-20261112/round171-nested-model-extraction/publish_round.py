#!/usr/bin/python3
"""Publish completed round evidence; leave the existing collector independent."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os
import subprocess
import sys

B=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
A=Path(__file__).resolve().parent
O=B/'area-sprint-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live,now

launch=read(A/'launch-nested-r2.json')
observed=(dt.datetime.now(dt.timezone.utc)-dt.datetime.fromisoformat(launch['utc'])).total_seconds()
assert observed>=300, 'Observe module at least300seconds before next inspection'
N=B/'build-logs/Opt4-nested-model-extraction-r2-20261113'
nr=read(N/'result.json')
assert nr['status'].startswith('PASS_NESTED_MODEL_EXTRACTION')
assert nr['actual_production']['same_reference_resolution_both_sides']
assert nr['actual_production']['raw_vs_resolved_serialized_bank_equal']
assert nr['actual_production']['raw_IR_metadata_differs']
assert nr['proven_equivalence_cells']==1033
save(A/'nested-final-adoption.json',dict(utc=now(),module_observed_seconds=observed,
    result=str(N/'result.json'),result_sha256=sha(N/'result.json'),
    regression=nr['regression'],actual_production=nr['actual_production'],
    proven_equivalence_cells=nr['proven_equivalence_cells'],
    compiler_source_commit=nr['compiler_source_parent_commit'],
    correction_commit=nr['hardware_commit'],scope=nr['scope']))

dr=read(B/'build-logs/Opt4-dcache-storage-compose-report-r4-20261113/result.json')
assert dr['module_lut_saved']==136579 and dr['candidate_resources']['CLB LUTs']==1492945
bindings={}
for name in ['nested-model-extraction-r1-20261113','nested-model-extraction-r2-20261113','dcache-storage-compose-report-r4-20261113']:
    p=W/'candidates'/name/'source-binding.json';b=read(p)
    assert all(sha(path)==h for path,h in b['files'].items())
    commit=b.get('hardware_commit',b.get('recovery_commit'));tree=Path(b['worktree'])
    for rel,h in b['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git','show',commit+':'+rel],cwd=tree)).hexdigest()==h
    bindings[name]=dict(commit=commit,source_binding=str(p),source_binding_sha256=sha(p),
        all_private_pins_match=True,all_committed_files_match=True,
        pin_count=len(b['files']),committed_file_count=len(b['committed_files']))
save(A/'committed-source-closure.json',dict(utc=now(),bindings=bindings))

owner_names=['address-dsp-fullmodule-pair-r1-20261112','address-banked-production-host-r2-20261113',
    'address-banked-production-area-pair-r2-20261113','common-stats-host-r5-20261113',
    'nested-model-extraction-r1-20261113','nested-model-extraction-r2-20261113',
    'dcache-storage-compose-report-r4-20261113']
owners={}
units={'ec-opt4-'+name+'.service':name for name in owner_names}
resources={name:dict(unit=unit,memory_limit_is_not_measured_peak=True,processes=[],current_aggregate_rss_bytes=0)
           for unit,name in units.items()}
for proc in Path('/proc').iterdir():
    if not proc.name.isdigit():continue
    try:
        cgroups=(proc/'cgroup').read_text()
        for unit,name in units.items():
            if any(l.split(':',2)[-1].endswith('/'+unit) or '/'+unit+'/' in l for l in cgroups.splitlines()):
                ident=identity(int(proc.name))
                if ident:
                    ident.update(affinity=sorted(os.sched_getaffinity(int(proc.name))),cgroup=cgroups)
                    resources[name]['processes'].append(ident)
                    resources[name]['current_aggregate_rss_bytes']+=ident['rss_bytes']
    except (OSError,ProcessLookupError):pass
for name in owner_names:
    p=B/'build-logs'/('Opt4-'+name)
    source=p/'state.json'
    if not source.exists():source=p/'queue.json'
    s=read(source)
    owners[name]=dict(state=str(source),status=s.get('status'),active_stage=s.get('active_stage'),
        hardware_commit=s.get('hardware_commit'),identity_live=live(s),controller=identity(s['pid']) if s.get('pid') else {},
        result=str(p/'result.json') if (p/'result.json').exists() else None,
        error=s.get('error'))
    if (p/'result.json').exists():owners[name]['result_sha256']=sha(p/'result.json')
save(A/'final-owner-observation.json',dict(utc=now(),module_observed_seconds=observed,owners=owners,actual_resources=resources))

next_action=('After >=300s module observation consume original productionr2 3003token52output Plain/Threaded and negative results, '
    'its bound serial area waiter, mixedr5 3003token73output/negative and serial area, and original DSP pair. '
    'Use completed DCache r4 report-only adoption1492945vs1629524LUT (gain136579), preserving private variant5542; no remap. '
    'Nested extraction compiler prerequisite now has60cases/24negative/1033equivalencecells and saved production16bank extraction; '
    'full GoldenGate/caller/host/ABI still required. Diagnose/version failures only after exact predecessor cgroup release. '
    'Material compatible same-scope gain gates one exact complete-source host/shell build. No FIT until real complete-shell capacity/physical/cert receipts; '
    'then card21only and eight first-ready PARSEC programs. Keep all healthy CAD and original independent collector/supervisor.')
summary=('Adopted completed DCache map through strict parser-only recovery4fbb98f:1629524->1492945LUT, gain136579, '
    '8192cycles/24575observations retained; no RTL/CAD/reference retry. '
    'Committed nested model parent specialization2d3d0ae and reference-normalization recovery0620ad3: '
    '60nestedcases,24path-strippingnegatives,1033sequentialequivalencecells, actual saved16bank production extraction PASS. '
    'Production/mixed host tokens and material area pending. NoFIT: fullshell2478437LUT, gap1174757; no certified completeEC image.')
round_path=O/'round-00171.json'
assert not round_path.exists(),'Immutable round receipt already published'
receipt=dict(schema='ec-area-sprint-round-evidence/1',round=171,utc=now(),outcome='PROGRESS',
    functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',summary=summary,
    actual_actions=[
        'Read exact current policies and adopted PID/start_ticks/boot_id/cgroup ownership without signalling healthy CAD.',
        'Consumed completed original DCache map. Diagnosed FPGATop hardcoded parser failure after successful Vivado and checkpoint; retained exact failure.',
        'Committed4fbb98f strict expected-design parser recovery, reused exact complete original reports/checkpoints and8192cycle/24575observation proof, eight negative report checks PASS.',
        'Implemented2d3d0ae stock parent-path specialization before unchanged promotion; 60 nested/partial-selection cases and24 path-stripping negatives passed; sequential proof1033cells PASS.',
        'Retained initial parsed-vs-resolved IR metadata mismatch; committed0620ad3 same-stage reference normalization with unchanged hardware/compiler and exact completed proof reuse after r1 cgroup release.',
        'Validated actual saved production16bank extraction, byte-equal serialized bank text, exact resolved bank IR and top ports.',
        'Registered report/extraction result owners with existing independent morning collector; no subagent, intelligent supervisor, FPGA IO or CPU/SVB session control.'
    ],
    experiments=bindings,actual_dcache_module=read(A/'adopted-complete-dcache-area.json'),
    new_nested_extraction=read(A/'nested-final-adoption.json'),
    actual_fullshell=read(A/'fullshell-adoption-revalidation.json'),
    actual_resources=resources,pending=owners,
    failure=dict(dcache_r3='Collector expected FPGATop instead of BoomNonBlockingDCache; successful checkpoint retained and strictly adopted.',
        nested_r1='Exact bank IR comparison used parsed reference against resolved output; recovery uses identical stock reference resolution and retains equal serialized text.'),
    launched_jobs=['ec-opt4-nested-model-extraction-r1-20261113.service','ec-opt4-dcache-storage-compose-report-r4-20261113.service','ec-opt4-nested-model-extraction-r2-20261113.service'],
    module_observed_seconds=observed,next_action=next_action,noFIT=True,
    no_new_complete_EC_certified_bitstream=True,no_board_operations=True,no_CPU_session_control=True,
    no_SVB_control=True,no_new_subagents=True,no_new_intelligent_supervisor=True,
    original_sprint_branch_unchanged=True,healthy_CAD_preserved=True)
save(round_path,receipt)
pointer=dict(round=171,receipt=str(round_path),receipt_sha256=sha(round_path),summary=summary,next_action=next_action)
save(O/'latest-round.json',pointer)
with (B/'unattended-opt4/campaign-policy.lock').open('a') as lock:
    fcntl.flock(lock,fcntl.LOCK_EX)
    policy=read(B/'unattended-opt4/campaign-policy.json')
    key='round171_nested_model_and_completed_dcache_20261113'
    assert key not in policy
    policy[key]=dict(utc=now(),receipt=str(round_path),receipt_sha256=sha(round_path),
        source_bindings=bindings,noFIT=True,actual_complete_DCache_LUT=1492945,
        actual_same_scope_DCache_gain=136579,fullshell_LUT=2478437,fullshell_gap=1174757,
        no_FPGA_IO=True,next_action=next_action)
    save(B/'unattended-opt4/campaign-policy.json',policy)
    save(A/'campaign-policy-new-key.json',policy[key])
save(A/'round-publication.json',dict(utc=now(),**pointer))
print(json.dumps(dict(receipt=str(round_path),receipt_sha256=sha(round_path),summary=summary),indent=2))
