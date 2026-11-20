#!/usr/bin/python3
"""Finalize already completed SAT stages after v2's result-packing exception.

No proof, simulation, synthesis, source generation or hardware operation reruns.
All original SAT input/log/exit receipts are sealed and checked independently.
"""
import fcntl
import importlib.util
import os
from pathlib import Path
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-queue-induction-round52-v3-20261112'
S = D/'Opt4-owner-queue-induction-round52-v3-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def main():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    plan = read(C/'plan.json')
    assert all(sha(q) == h for q, h in plan['inputs'].items())
    if (O/'complete.json').exists():
        assert sha(O/'result.json') == read(O/'complete.json')['result_sha256']
        print('IMMUTABLE_COMPLETE_REVALIDATED')
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'Preserve partial stage, use a new recovery version'
    assert plan['cpu'] in os.sched_getaffinity(0)
    os.sched_setaffinity(0, {plan['cpu']})
    state = dict(schema='ec-owner-queue-induction-finalization/1', **identity(),
                 functional_baseline=BASE, fpga_access=False, target_changed=False)
    save(S, {**state, 'status': 'VERIFYING_SEALED_SUCCESSFUL_SAT_STAGES', 'updated_utc': now()})
    try:
        evidence = C/'evidence'
        prior = read(evidence/'proof-plan.json')
        composition = read(evidence/'composition-result.json')
        assert sha(evidence/'composition-result.json') == prior['composition_result_sha256']
        assert composition['status'] == 'PASS_EXACT_OWNER_FAME_AND_SIMWRAPPER_CHANNEL_WIRING_NOT_FULL_EQUIVALENCE'
        assert composition['channel_instances'] == 109
        assert len(composition['mutations_rejected']) == 9
        # Load only the pure observer/harness definitions. Module main is not
        # called, and no import creates a child process or modifies old output.
        spec = importlib.util.spec_from_file_location('sealed_queue_proof', evidence/'proof-controller.py')
        definition = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(definition)
        stages = evidence/'stages'
        proofs, negatives = [], []
        for row in prior['queues']:
            name, width = row['name'], row['width']
            original = (evidence/(name+'.sv')).read_text()
            assert sha(evidence/(name+'.sv')) == composition['queue_module_hashes'][name]
            actual = definition.observer(original, name, width)
            good = actual+'\n'+definition.harness(name, width)
            variants = {name+'-'+kind: good for kind in ['reset', 'step', 'outputs']}
            for kind, old, new in [
                ('ready', 'assign io_enq_ready = ~valid_1;', 'assign io_enq_ready = ~valid_0;'),
                ('payload', 'assign io_deq_bits = elts_0;', 'assign io_deq_bits = elts_1;'),
                ('reset', "valid_0 <= 1'h0;", "valid_0 <= 1'h1;")]:
                assert actual.count(old) == 1
                variants[name+'-negative-'+kind] = actual.replace(old, new, 1)+'\n'+definition.harness(name, width)
            for label, expected_source in variants.items():
                v, y, log = [stages/(label+ext) for ext in ['.sv', '.ys', '.log']]
                r = read(stages/(label+'-receipt.json'))
                assert v.read_text() == expected_source, ('proof source mismatch', label)
                assert r['label'] == label
                assert r['source_sha256'] == sha(v) and r['script_sha256'] == sha(y)
                assert r['log_sha256'] == sha(log)
                # Exact command text is independently reconstructed, including
                # arbitrary related state versus reset base and output claims.
                if label.endswith('-step'):
                    command = 'sat -seq 2 -set-at 1 relation 1 -prove-skip 1 -prove relation 1 -verify -timeout 90'
                elif label.endswith(('-outputs', '-negative-ready', '-negative-payload')):
                    command = 'sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 90'
                else:
                    command = 'sat -seq 2 -set-at 1 reset 1 -prove-skip 1 -prove relation 1 -prove reset_empty 1 -verify -timeout 90'
                original_source = Path(plan['original_output'])/(label+'.sv')
                expected_script = f'read_verilog -sv -DSYNTHESIS {original_source}\nprep -top QueueRelation -flatten\nopt_clean\n'+command+'\n'
                assert y.read_text() == expected_script, ('proof command changed', label)
                text = log.read_text()
                assert 'TIMEOUT' not in text and 'timed out' not in text
                if '-negative-' in label:
                    assert r['returncode'] != 0
                    assert 'SAT proof finished - model found: FAIL!' in text and 'proof did fail' in text
                    negatives.append(r)
                else:
                    assert r['returncode'] == 0
                    assert 'SAT proof finished - no model found: SUCCESS!' in text
                    proofs.append(r)
        assert len(proofs) == len(negatives) == 9
        failure = read(evidence/'proof-finalization-failure.json')
        assert failure['error'] == 'TypeError("dict() got multiple values for keyword argument \'status\'")'
        result = {**state,
            'status': 'PASS_ACTUAL_OWNER_CHANNEL_FIFO_RELATIONAL_INDUCTION_NOT_FULL_RAM_OR_SYSTEM',
            'hardware_commit': prior['hardware_commit'], 'source_id': prior['source_id'],
            'completed_utc': now(), 'queue_types': 3, 'channel_instances': 109,
            'widths': [1, 81, 9], 'fifo_depth': 2, 'proof_receipts': proofs,
            'mutation_receipts': negatives, 'mutations_rejected': len(negatives),
            'arbitrary_related_state_induction': True, 'reset_from_arbitrary_state': True,
            'producer_stability_assumption': False, 'payload_initialization_assumption': False,
            'invalid_output_payload_compared': False, 'full_equivalence': False, 'whole_fit': False,
            'original_sat_stages_reused': True, 'sat_rerun': False,
            'composition_result_sha256': prior['composition_result_sha256'],
            'plan_sha256': sha(C/'plan.json'), 'input_sha256': plan['inputs'],
            'limitations': ['Actual queue transitions plus previous wiring audit only.',
                'RAM semantics, full target equivalence and resource savings remain separate.',
                'No FPGA sample, whole Opt4 FIT or production admission.']}
        save(O/'result.json', result)
        save(O/'complete.json', dict(result_sha256=sha(O/'result.json'), completed_utc=now()))
        save(S, {**state, 'status': result['status'], 'updated_utc': now(), 'result_sha256': sha(O/'result.json')})
        print(result['status'])
    except Exception as exc:
        save(O/'failure.json', {**state, 'status': 'FAILED_WITH_EVIDENCE', 'error': repr(exc)})
        save(S, {**state, 'status': 'FAILED_WITH_EVIDENCE', 'error': repr(exc), 'updated_utc': now()})
        raise


if __name__ == '__main__':
    main()
