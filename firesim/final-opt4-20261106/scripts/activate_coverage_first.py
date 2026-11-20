#!/usr/bin/env python3
"""One-time future-boundary ownership handoff; no signals or device access."""
import datetime as dt
import json
from pathlib import Path
from board_batch import W,D,save,sha
from job_service import inspect


def main():
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'plan-history'/('coverage-first-handoff-'+stamp);out.mkdir(parents=True)
    names=['suite-execution-plan.json','suite-native-queue-state.json','suite-c4-queue-state.json',
           'active-0000_e2_00.0.json','C4-runtime-cad-state.json','idle-repairs-state.json',
           'fluidanimate-stable-native-state.json','c4-canneal-continuation-state.json']
    audits={n:inspect(D/n) for n in names if n!='suite-execution-plan.json'}
    for n in names:
        if (D/n).exists():(out/n).write_bytes((D/n).read_bytes())
    save(out/'startup-audit.json',audits)
    gate=D/'c4-canneal-continuation-state.json';g=json.loads(gate.read_text())
    assert not any(p['identity_live'] or p['identity_uncertain'] for p in audits[gate.name]['processes']), 'do not alter a live priority controller'
    g.update(status='DELEGATED_TO_COVERAGE_FIRST_SERVICE',future_owner='ec-parsec-coverage-first.service',
             delegation_utc=dt.datetime.now(dt.timezone.utc).isoformat(),prior_state=str(out/gate.name),
             reason='Keeps live legacy C4 suite waiting; its pre-loop recovery must not race the single future owner')
    save(gate,g)
    plan=D/'suite-execution-plan.json';s=json.loads(plan.read_text())
    order=['blackscholes','canneal','swaptions','bodytrack','streamcluster','fluidanimate','dedup',
           'x264','vips','raytrace','ferret','facesim','freqmine','netdedup','netferret','netstreamcluster']
    assert len(s['programs'])==16 and {t['program'] for t in s['programs']}==set(order)
    for t in s['programs']:
        t['prior_managed_by_existing_queue']=t.get('managed_by_existing_queue',[])
        t['managed_by_existing_queue']=['Native','C4']
        t['future_owner']='ec-parsec-coverage-first.service'
        t['coverage_priority']=order.index(t['program'])
        if t['program']=='blackscholes':
            t.pop('driver_receipts',None)
            # Reviewed patches change journal sequence origin / host efficiency
            # reporting only. They leave RTL, ROI tick fields and memory model
            # untouched. Preserve each result's actual driver hashes.
            t['reusable_driver_receipts']={'Native':[str(W/'runtime'/n) for n in
                ['Native-observed-driver.json','Native-restart-driver.json']]}
            t['driver_reuse_scope']='Historical Native Blackscholes only; identical target hardware/ELF/input/firmware/ROI. Restart patch normalizes journal sequence, not ROI ticks. Host efficiency differs and must retain per-driver provenance.'
    s.update(policy='Existing active batches retained; legacy suites delegate future tasks; one coverage-first owner visits formal r1 then r2 then r3, skips exact atomic commits, records blockers without stopping other programs',
             handoff_receipt=str(out/'receipt.json'))
    save(plan,s)
    save(out/'receipt.json',dict(schema='ec-future-boundary-handoff/1',updated_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        plan_sha256=sha(plan),programs=len(s['programs']),signals_sent=False,device_operations=False,
        active_inputs_unchanged=True,legacy_batches_retained=['freqmine repetitions','idle repairs','fluidanimate authorized repair','C4 initial deployment/gates'],
        service='ec-parsec-coverage-first.service',priority_order=order))
    print(out)


if __name__=='__main__':main()
