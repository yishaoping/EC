#!/usr/bin/python3
"""Read-only composition ledger. Independently validates bounded proof artifacts.

This binds separate lemmas; it never promotes them to end-to-end equivalence.
"""
import fcntl
import hashlib
import json
import os
from pathlib import Path
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-memory-proof-ledger-round53-v1-20261112'
STATE = D/'Opt4-owner-memory-proof-ledger-round53-v1-state.json'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
MODEL = '46428dc8d9868145ee7636f7da186ea61906da0bb3e0fad3dc756ffd95c135a4'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    return p


def bounded_sha(path):
    q = Path(path)
    assert q.stat().st_size < 8*2**20, ('Unexpected large proof artifact', str(q))
    return sha(q)


def audit_lemma(label, directory, count, negatives, status):
    policy()
    o = D/'build-logs'/directory
    r = read(o/'result.json')
    assert r['status'] == status
    plan=read(C/'plan.json')
    assert bounded_sha(o/'result.json') == plan['external_result_sha256'][label]
    job=plan['job_names'][label]
    request=read(U/'requests'/(job+'.json'))
    assert read(U/'request-results'/(job+'.json'))['status'] in ['STARTED','ADOPTED']
    assert all(bounded_sha(q)==h for q,h in request['spec']['inputs'].items())
    assert read(o/'complete.json')['result_sha256'] == bounded_sha(o/'result.json')
    assert r['actual_ram_model_sha256'] == MODEL
    assert r['functional_baseline'] == BASE
    assert r['hardware_commit'] == '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
    assert not live(r), 'A complete result with live producer is not yet adopted'
    assert len(r['proof_receipts']) == count and len(r['mutation_receipts']) == negatives
    assert all(bounded_sha(q) == h for q,h in r['inputs'].items())
    for negative, group in [(False,r['proof_receipts']),(True,r['mutation_receipts'])]:
        for receipt in group:
            n = receipt['label']
            for ext,key in [('.sv','source_sha256'),('.ys','script_sha256'),('.log','log_sha256')]:
                assert bounded_sha(o/(n+ext)) == receipt[key], (label,n,key)
            log = (o/(n+'.log')).read_text()
            if negative:
                assert receipt['returncode'] != 0 and 'proof did fail' in log
                assert 'TIMEOUT' not in log and 'syntax error' not in log
            else:
                assert receipt['returncode'] == 0 and 'SUCCESS!' in log
            command = (o/(n+'.ys')).read_text()
            assert '-verify' in command and '-timeout' in command
    if label == 'controller':
        factors = ['control_relation','pipeline_relation'] + ['payload_relation_'+str(i) for i in range(35)]
        assert r['induction_factors'] == factors
        observations=['command_ready_equal','response_valid_equal','write_ready_equal',
            'advance_equal','read_address_equal','write_enable_equal','write_address_equal','write_payload_equal'] + ['response_payload_equal_'+str(i) for i in range(35)]
        assert r['observation_factors']==observations
        assert r['adopted_successful_v2_stages']==38
        for factor in observations:
            command=(o/('observations-'+factor+'.ys')).read_text()
            assert '-seq 1 -set relation 1 -prove '+factor+' 1 -verify' in command
        for factor in factors:
            command = (o/('step-'+factor+'.ys')).read_text()
            assert '-seq 2 -set-at 1 relation 1 -prove-skip 1 -prove '+factor+' 1 -verify' in command
        assert r['proof_boundary']['exact_reversal_checked']
        assert not r['proof_boundary']['memory_contents_proved']
        assert r['proof_boundary']['read_data_cut_replacement']=='assign data_read_data_async_data = proof_read_word;'
        assert not r['ready_valid_stability_assumption'] and not r['initial_payload_assumption']
        assert not r['invalid_response_payload_compared']
    else:
        assert not r['memory_read_cut'] and r['observer_exact_reversal_checked']
        assert not r['initial_memory_assumption']
        if label == 'storage':
            assert not r['initialization_or_reset_base_proved']
        assert [(q['low_bit'],q['high_bit']) for q in r['proof_receipts']] == [(i,i+8) for i in range(0,81,9)]
        for receipt in r['proof_receipts']:
            command = (o/(receipt['label']+'.ys')).read_text()
            assert '-seq 2 -set stable_address 1' in command
            if label == 'storage':
                assert '-set-at 1 relation 1 -prove-skip 1 -prove relation 1' in command
            else:
                assert '-set-at 1 word_relation 1 -prove-skip 1 -prove read_relation 1' in command
    return dict(label=label, result=str(o/'result.json'), result_sha256=bounded_sha(o/'result.json'),
        complete_sha256=bounded_sha(o/'complete.json'), positive_obligations=count,
        rejected_source_mutations=negatives, actual_model_sha256=MODEL,
        status=r['status'], limitations=r['limitations'])


def main():
    policy()
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_OWNER_MEMORY_LEMMA_LEDGER_REVALIDATED')
        return
    O.mkdir(parents=True,exist_ok=True)
    lock=(O/'instance.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Recover with new version after partial failure'
    state=dict(schema='ec-owner-memory-lemma-ledger/1', **identity(),
        started_utc=now(), functional_baseline=BASE, fpga_access=False,
        target_changed=False, complete_dcache_equivalence=False,
        complete_fame_equivalence=False, whole_fit=False, production_admission=False)
    save(O/'state.json',dict(state,status='AUDITING_BOUND_LEMMAS'))
    try:
        plan=read(C/'plan.json')
        assert all(bounded_sha(q)==h for q,h in plan['inputs'].items())
        lemmas=[audit_lemma(*args) for args in [
            ('controller','Opt4-owner-ram-controller-round53-v3-20261112',82,7,
             'PASS_ACTUAL_35R1W_RAM_CONTROLLER_AND_PAYLOAD_RELATIONAL_INDUCTION_WITH_SYMBOLIC_READ_CUT'),
            ('storage','Opt4-owner-ram-storage-round53-v1-20261112',9,2,
             'PASS_ACTUAL_512X81_HOST_RAM_ARBITRARY_ADDRESS_STORAGE_STEP_INDUCTION'),
            ('read_snapshot','Opt4-owner-ram-read-snapshot-round53-v1-20261112',9,3,
             'PASS_ACTUAL_512X81_HOST_RAM_READ_SNAPSHOT_AND_SAME_EDGE_OLD_WORD_RELATION')]]
        queue=read(plan['queue_result']); wiring=read(plan['wiring_result']); reuse=read(plan['reuse_result'])
        assert queue['status']=='PASS_ACTUAL_OWNER_CHANNEL_FIFO_RELATIONAL_INDUCTION_NOT_FULL_RAM_OR_SYSTEM'
        assert queue['channel_instances']==109 and queue['mutations_rejected']==9
        assert wiring['channel_instances']==109 and wiring['all_owner_token_ports_accounted']
        assert reuse['read_channels']==35 and reuse['write_channels']==1
        assert bounded_sha(plan['actual_model'])==MODEL
        result={**state,'status':'PASS_SEPARATE_SOURCE_BOUND_OWNER_MEMORY_LEMMAS_NOT_END_TO_END_EQUIVALENCE',
            'completed_utc':now(),'lemmas':lemmas,'new_positive_obligations':100,
            'new_rejected_source_mutations':12,'queue_and_wiring_prior_receipts':plan['inputs'],
            'scope':'Same actual emitted 35R1W 512x81 model; independent controller/storage/read-snapshot lemmas, plus prior queue and wiring evidence.',
            'unclosed_obligations':[
              'Formal composition across complete adapter/FAME target-advance/clock/reset token boundaries.',
              'Complete frozen DCache/system observations over all legal histories; finite workload parity remains separately measured.',
              'Complete DCache and whole-system area, actual clock coverage, timing/DRC/bitstream certification and real FPGA samples.'],
            'target_rtl_modified':False,'whole_area_saving_inferred':False,
            'predecessor_timeout':plan['v1_failure'],'plan_sha256':bounded_sha(C/'plan.json')}
        save(O/'result.json',result)
        save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),completed_utc=now()))
        save(STATE,dict(state,status=result['status'],updated_utc=now(),result_sha256=sha(O/'result.json')))
        print(result['status'])
    except Exception as exc:
        fail=dict(state,status='FAILED_WITH_EVIDENCE',error=repr(exc),updated_utc=now())
        save(O/'failure.json',fail);save(STATE,fail)
        raise


if __name__=='__main__':
    main()
