#!/usr/bin/env python3
"""Offline-only reconstruction from immutable r2 A and B (never launches HW)."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]


def digest(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


def records(path):
    with path.open() as f:
        for i, line in enumerate(f, 1):
            p = line.rstrip().split('\t')
            if len(p) == 23 and p[0] == 'SC1':
                yield dict(line=i, cycle=int(p[2]), local=int(p[3]), kind=int(p[5]),
                    hart=int(p[6]), n=[int(w,16) for w in p[7:]])


def inspect(revision):
    result = dict(revision=str(revision), clock_unit='SC column2 BOOM cycles; column3 checker-local cycle')
    for name in ['A', 'B']:
        paths = list((revision/'arms'/name/'runs').glob('*/run_manifest.json'))
        if len(paths) != 1:
            raise ValueError('expected one immutable old run for '+name)
        run = paths[0].parent
        capture = json.loads((run/'capture_summary.json').read_text())
        summary = json.loads((run/'analysis/summary.json').read_text())
        rows = list(records(run/'safe_chain_events.tsv'))
        sc6 = [x for x in rows if x['kind'] == 6]
        starts = [x for x in sc6 if x['n'][2] >> 21 & 1]
        observers = {k:v for k,v in capture['observers'].items() if k.startswith('6:')}
        omitted = sum(x['omitted'] for x in observers.values())
        result[name] = dict(run=str(run), sc6_retained=len(sc6), sc6_capture=observers,
            sc6_host_records_omitted=omitted, retained_starts=len(starts),
            retained_start_excpt_mode=[x for x in starts if x['n'][3]&4],
            correctness=summary['correctness'],
            seq63_67_checker3=[x for x in sc6 if x['hart']==3 and x['n'][0] in [63,67]],
            files_sha256={str(p.relative_to(ROOT)):digest(p) for p in
                [paths[0],run/'capture_summary.json',run/'analysis/summary.json',
                 run/'safe_chain_events.tsv',run/'stdout.log',run/'stderr.log',run/'cache_opportunity.jsonl']})
    b=result['B']
    bad = [x for x in b['retained_start_excpt_mode'] if x['hart']==3 and x['n'][0]==67]
    if len(bad) != 1 or b['sc6_host_records_omitted']:
        raise ValueError('saved B does not establish the required complete prefix')
    x=bad[0]
    # normal_start needs context_idle; fallback running needs cleanup_done=0.
    # n15==1 establishes nonchecking, so only registered privrun can start.
    privrun_inferred = x['n'][15]==1 and not x['n'][3]&1
    result['first_divergence'] = dict(row=x, privileged_start_pulse_inferred=privrun_inferred,
        explanation='start_accepted=1, context_idle=0, excpt_mode=1, ICSL status=nonchecking; normal/fallback start paths are false',
        upstream_collision='registered privrun and registered excpt_mode both become set on this edge; prior checker edge is the likely synthetic redirect / architectural trap collision',
        inferred_predecessor_boom_cycle=x['cycle']-2,
        caveat='No direct CSR cause/vector or check_exception event was logged; predecessor inference uses sealed source and complete B SC6 change detection, not a waveform.')
    # A SC6 is optional and host-dropped records exist. PASS/cancel=0 does not
    # prove a safe-but-timing-changing deferral never happens.
    result['a_non_interference_proven'] = False
    result['a_proof_blocker'] = 'A optional SC6 host loss; no complete dispatch/trap coincidence counter in r2. Zero retained bad starts and zero CANCELs are insufficient for strict timing equivalence.'
    result['classification'] = 'TYPE_1_PROTOCOL_BUG; not a justified watchdog-bound increase'
    return result


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--revision',type=Path,required=True)
    ap.add_argument('--report',type=Path,required=True);a=ap.parse_args()
    result=inspect(a.revision.resolve())
    (a.report/'offline_evidence.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
    print(json.dumps({k:result[k] for k in ['classification','a_non_interference_proven','a_proof_blocker']}))


if __name__=='__main__':main()
