#!/usr/bin/env python3
"""Validate one corrected B and show a gated comparison to the old valid A.

Normal strict-pair analyzer gates are unchanged. This entry point never treats a
different-source comparison as causal without a sealed noninterference proof.
"""
import argparse
import importlib.util
import json
from pathlib import Path
import sys

SCRIPTS=Path(__file__).resolve().parent
ROOT=SCRIPTS.parents[2]


def module(name,file):
    spec=importlib.util.spec_from_file_location(name,SCRIPTS/file)
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);return m


pair=module('seq67_pair','analyze_l1_causal_pair.py')
evidence=module('seq67_evidence','inspect_checker_seq67_evidence.py')


def diagnostic_validation(run):
    rows=list(evidence.records(run/'safe_chain_events.tsv'))
    life=[r for r in rows if r['kind']==46 and r['n'][0]==67]
    totals=[r for r in rows if r['kind']==47]
    capture=pair.read(run/'capture_summary.json')
    errors=[]
    for hart in range(1,5):
        for kind in [46,47]:
            key=f'{kind}:{hart}';obs=capture.get('observers',{}).get(key,{})
            prod=capture.get('producers',{}).get(key,{})
            # Conflict examples may legitimately be absent on non-target harts.
            expected=bool([r for r in rows if r['kind']==kind and r['hart']==hart])
            if kind==46 and not expected and key not in capture.get('observers',{}):
                continue
            if (obs.get('omitted',0) or prod.get('omitted',0) or
                obs.get('footers_seen')!=1 or obs.get('events_seen')!=prod.get('emitted') or
                prod.get('produced')!=prod.get('emitted') or
                obs.get('footer_emitted_count')!=prod.get('emitted')):
                errors.append(key+': missing/lost/inconsistent mandatory diagnostic records')
    if not life or any(r['n'][1]!=1 for r in life+totals):
        errors.append('seq67 lifecycle absent or unsupported diagnostic schema')
    flags=lambda bit:[r for r in life if r['n'][3]>>bit&1]
    gates=dict(admitted=bool(flags(20)),start_accepted=bool(flags(21)),
        exec_done=bool(flags(8)),full_compare_complete=bool(flags(9)),
        local_result_fire=bool(flags(16)),local_handoff=bool(flags(17)),
        no_cancel=not bool(flags(18)))
    handoffs=flags(17)
    gates['handoff_context_clean']=bool(handoffs) and all(r['n'][4]&1 and not r['n'][4]&14 for r in handoffs)
    accepted=[r for r in rows if r['kind']==3 and r['n'][0]&0xffffffff==67 and r['n'][1]&2]
    gates['boom_result_accepted_pass']=len(accepted)==1 and not accepted[0]['n'][1]&48
    target_harts={r['hart'] for r in life}
    gates['single_target_hart']=len(target_harts)==1 and bool(accepted) and accepted[0]['hart'] in target_harts
    gates['ordered_lifecycle']=bool(handoffs and accepted) and (
        min(r['cycle'] for r in flags(21)) <= min(r['cycle'] for r in flags(8)) <=
        min(r['cycle'] for r in flags(16)) < min(r['cycle'] for r in handoffs) <= accepted[0]['cycle']) if all(flags(i) for i in [21,8,16,17]) and accepted else False
    # Kind47 words3..12: CPS, dispatch, deferral, entry-trap, bad-start,
    # CANCEL, seq67 start, exec, full-result, handoff cumulative counters.
    gates['no_stale_trap_start']=bool(totals) and all(r['n'][7]==0 for r in totals)
    gates['no_global_cancel']=bool(totals) and all(r['n'][8]==0 for r in totals)
    gates['bounded_target_covers_handoff']=bool(handoffs) and all(r['n'][14]<64 for r in handoffs)
    gates['bounded_summaries_not_exhausted']=bool(totals) and all(r['n'][14]>>5<127 for r in totals)
    gates['mandatory_capture']=not errors
    return dict(status='PASS' if all(gates.values()) else 'FAIL',gates=gates,errors=errors,
        target_harts=sorted(target_harts),lifecycle=life,totals=totals,
        interpretation='Deferral/entry-trap events confirm the exercised protocol repair when present. Zero events means prevention was not dynamically exercised; lifecycle PASS alone is not experimental root-cause proof.')


def collect_provenance(report,contract,b):
    # Source identity and reviewed exceptions are checked by wrapper preflight.
    m=pair.read(Path(b['manifest']));a_manifest=pair.read(Path(contract['a_manifest']))
    oldrev=Path(contract['a_revision']);rev=report/'sealed'
    oldseal=pair.read(oldrev/'source_seal.json');newseal=pair.read(rev/'source_seal.json')
    oldexec=pair.read(Path(contract['old_execution_provenance']))
    a_argv=oldexec['argv_A'];b_argv=m.get('simulation_argv',[])
    digest=module('seq67_launcher_hash','launch_checker_seq67_one_shot.py').digest
    checks=dict(
        same_actual_execution_arguments=bool(b_argv) and a_argv[1:]==b_argv[1:],
        expected_B_executable=bool(b_argv) and Path(b_argv[0]).name=='simulator-chipyard-L1Causal64Config',
        same_software=a_manifest['software']==m['software'],
        B_source_sealed=m['source']['hardware_sha256']==newseal['hardware_sha256'] and m['source']['tool_sha256']==newseal['tool_sha256'] and m['source']['paired_source_fingerprint']==newseal['paired_source_fingerprint'])
    builds={
        'A':oldrev/'arms/A/build'/Path(contract['a_manifest']).parent.name,
        'B':rev/'arms/B/build'/Path(b['manifest']).parent.name}
    generated={};resources={};errors=[]
    try:
        configs={n:next((p/'generated').glob('*Config.json')) for n,p in builds.items()}
        # Independently compare actual generated geometry/clocks/L2.
        prov=module('seq67_generated','collect_l1_causal_provenance.py')
        delta=prov.differences(pair.read(configs['A']),pair.read(configs['B']))
        checks['generated_geometry_only']=delta==[('/cpus/cpu@0/d-cache-sets/0',256,512),('/cpus/cpu@0/d-cache-size/0',32768,65536)]
        generated['differences']=delta
        for suffix in ['l2.json','buildTopClockGenerator.freq-summary','harnessDividerOnlyClockGenerator.freq-summary']:
            paths=[next((builds[n]/'generated').glob('*Config.'+suffix)) for n in ['A','B']]
            generated[suffix]=[dict(path=str(p),sha256=digest(p)) for p in paths]
            checks['unchanged_'+suffix]=digest(paths[0])==digest(paths[1])
        native='chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'
        checks['unchanged_native_source']=oldseal['hardware_sha256'][native]==newseal['hardware_sha256'][native]
        for name,build in builds.items():
            paths=list((build/'generated').rglob('cache_opportunity.cc'))
            resources[name]=[dict(path=str(p),sha256=digest(p)) for p in paths]
            checks[name+'_native_copies']=bool(paths) and all(digest(p)==newseal['hardware_sha256'][native] for p in paths)
    except (OSError,StopIteration,KeyError,ValueError) as exc:
        errors.append(str(exc));checks['generated_and_native_audit']=False
    return dict(status='PASS' if all(checks.values()) else 'FAIL',checks=checks,errors=errors,
        actual_argv_A=a_argv,actual_argv_B=b_argv,generated=generated,native_resources=resources)


def analyze(report):
    # Recheck the sealed source, proof and immutable old evidence offline.
    module('seq67_postflight','launch_checker_seq67_one_shot.py').preflight(report)
    contract=pair.read(report/'one_shot_contract.json')
    a=pair.arm(Path(contract['a_revision']),'A')
    runs=list((report/'sealed/arms/B/runs').glob('*/run_manifest.json'))
    if len(runs)!=1:
        result=dict(status='B_BUILD_OR_LAUNCH_FAILED',runs_found=len(runs),performance_decision='UNAVAILABLE',additional_runs_scheduled=0)
        pair.dump(report/'one_shot_result.json',result);return result
    run=runs[0].parent
    try:
        b=pair.arm(report/'sealed','B')
        diagnostics=diagnostic_validation(run)
        provenance=collect_provenance(report,contract,b)
    except (OSError,KeyError,ValueError,TypeError) as exc:
        result=dict(status='INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT',error=str(exc),performance_decision='UNAVAILABLE',additional_runs_scheduled=0)
        pair.dump(report/'one_shot_result.json',result);return result
    pair.dump(report/'runtime_baseline_A.json',a);pair.dump(report/'runtime_B.json',b)
    pair.dump(run/'analysis/seq67_diagnostics.json',diagnostics)
    pair.dump(report/'runtime_provenance.json',provenance)
    valid=a['valid'] and b['valid'] and diagnostics['status']=='PASS' and provenance['status']=='PASS'
    proof=pair.read(report/'a_non_interference_proof.json')
    # This report's proof is explicitly NO. No flag can override it at CLI.
    noninterference=proof.get('proven') is True and proof.get('complete_dynamic_coverage') is True
    status=('CORRECTNESS_CLOSED_BUT_STRICT_PAIRING_REQUIRES_BASELINE_REFRESH' if valid and not noninterference else
        'CORRECTNESS_CLOSED_NONINTERFERING_REFERENCE' if valid else 'INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT')
    comparison=None
    if valid:
        ac,bc=a['causal']['counts'],b['causal']['counts']
        comparison=dict(label='UNPAIRED_REFERENCE_DIFFERENCE_NOT_GEOMETRY_CAUSAL_EFFECT' if not noninterference else 'NONINTERFERING_REFERENCE_COMPARISON',
            strict_causal_interpretation_allowed=noninterference,
            roi_A=a['roi_cycles'],roi_B=b['roi_cycles'],roi_difference_A_minus_B=a['roi_cycles']-b['roi_cycles'],
            actual_l1_A=a['actual_l1'],actual_l1_B=b['actual_l1'],
            counter_difference_A_minus_B={k:ac[k]-bc[k] for k in ac},
            latency_histograms_A=a['causal']['latency_histograms'],latency_histograms_B=b['causal']['latency_histograms'])
        pair.dump(report/'reference_comparison.json',comparison)
    result=dict(status=status,B_run=str(run),A_valid=a['valid'],B_valid=b['valid'],
        diagnostics=diagnostics['status'],provenance=provenance['status'],a_non_interference_proven=noninterference,
        strict_performance_decision='PENDING_MANUAL_REVIEW' if valid and noninterference else 'NOT_ESTABLISHED',
        comparison=comparison,additional_runs_scheduled=0,
        after_this_run='Review B benefit first; discuss A only if worthwhile and noninterference remains unproven. Never auto-launch A.')
    pair.dump(report/'runtime_validation.json',dict(A=a['gates'],B=b['gates'],diagnostics=diagnostics['gates'],provenance=provenance['checks']))
    pair.dump(report/'one_shot_result.json',result)
    pair.md(report/'runtime_result.md',f'# One-shot B result\n\n{status}\n\nB: {run}\n\nChecker/observer gates: {b["valid"]}; seq67: {diagnostics["status"]}; provenance: {provenance["status"]}.\n\nOld A noninterference: {noninterference}. See reference_comparison.json for explicitly gated numeric differences; no additional run is scheduled.')
    return result


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--report',type=Path,required=True);a=ap.parse_args()
    result=analyze(a.report.resolve());print(json.dumps(result,indent=2))
    return 0 if result['status'].startswith('CORRECTNESS_CLOSED') else 3


if __name__=='__main__':raise SystemExit(main())
