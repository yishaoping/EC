#!/usr/bin/python3
"""Universal FIFO transition proof of the actual 109 owner token channels.

Only verification copies gain observation ports. Original queue statements,
producer RTL, annotations, running jobs and FPGA services are never changed.
"""
import fcntl
import hashlib
import json
import os
from pathlib import Path
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-queue-induction-round52-v2-20261112'
S = D/'Opt4-owner-queue-induction-round52-v2-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']


def observer(original, name, width):
    """Insert outputs and aliases, leaving every functional byte intact."""
    a, sep, b = original.partition('\n);')
    assert sep and original.count('endmodule') == 1
    ports = (',\n  output proof_v0, output proof_v1,\n'
             f'  output [{width-1}:0] proof_d0, output [{width-1}:0] proof_d1')
    aliases = ('  assign proof_v0 = valid_0;\n  assign proof_v1 = valid_1;\n'
               '  assign proof_d0 = elts_0;\n  assign proof_d1 = elts_1;\n')
    result = a + ports + sep + b.replace('endmodule', aliases+'endmodule')
    restored = result.replace(ports, '', 1).replace(aliases, '', 1)
    assert restored == original, 'Functional queue changed by observer insertion'
    assert result.startswith('module '+name+'(')
    return result


def harness(name, width):
    # An independent count-based, two-entry FIFO. No same-cycle bypass or
    # full replacement is assumed: the emitted queue deliberately reports
    # !valid_1 even when its consumer is ready.
    return f'''module QueueRelation(
 input clock, input reset, input push_valid, input pop_ready,
 input [{width-1}:0] payload,
 output relation, output observations, output reset_empty
);
 wire ready, valid, v0, v1;
 wire [{width-1}:0] data, d0, d1;
 {name} dut(.clock(clock), .reset(reset), .io_enq_ready(ready),
   .io_enq_valid(push_valid), .io_enq_bits(payload),
   .io_deq_ready(pop_ready), .io_deq_valid(valid), .io_deq_bits(data),
   .proof_v0(v0), .proof_v1(v1), .proof_d0(d0), .proof_d1(d1));
 reg [1:0] count;
 reg [{width-1}:0] head, tail;
 wire push = push_valid && count < 2;
 wire pop = pop_ready && count != 0;
 always @(posedge clock) begin
   if (reset) count <= 0;
   else begin
     case ({{push, pop}})
       2'b10: count <= count + 1;
       2'b01: count <= count - 1;
       default: count <= count;
     endcase
     if (pop) begin
       if (count == 2) head <= tail;
       else if (push) head <= payload;
       if (push && count == 2) tail <= payload;
     end else if (push) begin
       if (count == 0) head <= payload;
       else tail <= payload;
     end
   end
 end
 assign relation = count <= 2 && v0 == (count != 0) && v1 == (count == 2)
   && (count == 0 || d0 == head) && (count != 2 || d1 == tail);
 assign observations = ready == (count < 2) && valid == (count != 0)
   && (!valid || data == head);
 assign reset_empty = count == 0 && !v0 && !v1;
endmodule
'''


def main():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_QUEUE_PROOF_REVALIDATED')
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve partial stage; new recovery version required'
    cpus = set(os.sched_getaffinity(0))
    assert plan['cpu'] in cpus
    os.sched_setaffinity(0, {plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS, (8*2**30, 8*2**30))
    state = dict(schema='ec-owner-queue-induction/1', **identity(),
        functional_baseline=BASE, hardware_commit=plan['hardware_commit'],
        source_id=plan['source_id'], started_utc=now(), fpga_access=False,
        target_changed=False, full_equivalence=False, whole_fit=False,
        cpu=plan['cpu'])

    def status(value, **extra):
        state.update(status=value, updated_utc=now(), **extra)
        save(S, state)
        save(O/'state.json', state)

    def run(label, source, command, should_pass=True):
        policy()
        v = O/(label+'.sv')
        y = O/(label+'.ys')
        log = O/(label+'.log')
        assert not v.exists() and not log.exists()
        v.write_text(source)
        y.write_text(f'read_verilog -sv -DSYNTHESIS {v}\n'
                     'prep -top QueueRelation -flatten\n'
                     'opt_clean\n'+command+'\n')
        start = time.monotonic()
        with log.open('xb') as f:
            child = subprocess.Popen([plan['yosys'], '-s', str(y)], cwd=C,
                stdout=f, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
            status('RUNNING_'+label, child=identity(child.pid), stage_log=str(log))
            try:
                code = child.wait(timeout=120)
            except subprocess.TimeoutExpired:
                # This child is owned by this bounded proof controller only.
                child.kill()
                code = child.wait()
                raise RuntimeError(('proof timeout; never a PASS', label, code))
        receipt = dict(label=label, returncode=code, source_sha256=sha(v),
            script_sha256=sha(y), log_sha256=sha(log), seconds=time.monotonic()-start)
        save(O/(label+'-receipt.json'), receipt)
        if should_pass:
            assert code == 0 and 'SUCCESS!' in log.read_text(), receipt
        else:
            assert code != 0 and 'proof did fail' in log.read_text(), receipt
        return receipt

    try:
        previous = read(plan['composition_result'])
        assert previous['status'] == 'PASS_EXACT_OWNER_FAME_AND_SIMWRAPPER_CHANNEL_WIRING_NOT_FULL_EQUIVALENCE'
        assert previous['channel_instances'] == 109 and previous['all_owner_token_ports_accounted']
        assert sha(plan['composition_result']) == plan['composition_result_sha256']
        assert len(previous['mutations_rejected']) == 9
        proofs, mutations = [], []
        for row in plan['queues']:
            name, width = row['name'], row['width']
            raw = Path(row['file']).read_text()
            assert sha(row['file']) == previous['queue_module_hashes'][name]
            actual = observer(raw, name, width)
            source = actual + '\n' + harness(name, width)
            # Induction base: reset takes arbitrary physical/reference states
            # to the empty relation. Payload remains unconstrained when empty.
            proofs.append(run(name+'-reset', source,
                'sat -seq 2 -set-at 1 reset 1 -prove-skip 1 -prove relation 1 '
                '-prove reset_empty 1 -verify -timeout 90'))
            # Universal one-step preservation from arbitrary related states.
            # All payload bits, ready/valid and reset inputs are unconstrained.
            proofs.append(run(name+'-step', source,
                'sat -seq 2 -set-at 1 relation 1 -prove-skip 1 '
                '-prove relation 1 -verify -timeout 90'))
            proofs.append(run(name+'-outputs', source,
                'sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 90'))
            substitutions = [
                ('ready', 'assign io_enq_ready = ~valid_1;', 'assign io_enq_ready = ~valid_0;'),
                ('payload', 'assign io_deq_bits = elts_0;', 'assign io_deq_bits = elts_1;'),
                ('reset', "valid_0 <= 1'h0;", "valid_0 <= 1'h1;")]
            for kind, old, new in substitutions:
                assert actual.count(old) == 1, (name, old)
                mutant = actual.replace(old, new, 1)+'\n'+harness(name, width)
                command = ('sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 90'
                    if kind in ['ready', 'payload'] else
                    'sat -seq 2 -set-at 1 reset 1 -prove-skip 1 -prove relation 1 '
                    '-prove reset_empty 1 -verify -timeout 90')
                mutations.append(run(name+'-negative-'+kind, mutant, command, False))
        result = dict(**state, status='PASS_ACTUAL_OWNER_CHANNEL_FIFO_RELATIONAL_INDUCTION_NOT_FULL_RAM_OR_SYSTEM',
            completed_utc=now(), queue_types=3, channel_instances=109,
            widths=[1, 81, 9], fifo_depth=2, proof_receipts=proofs,
            mutation_receipts=mutations, mutations_rejected=len(mutations),
            arbitrary_related_state_induction=True, reset_from_arbitrary_state=True,
            producer_stability_assumption=False, payload_initialization_assumption=False,
            composition_result_sha256=plan['composition_result_sha256'],
            plan_sha256=sha(C/'plan.json'), input_sha256=plan['inputs'],
            limitations=['Queue transitions and source-bound wire composition only.',
                'RAM scheduling/data semantics, target equivalence and full area remain separate.',
                'No FPGA result, full Opt4 FIT or production admission.'])
        save(O/'result.json', result)
        save(O/'complete.json', dict(result_sha256=sha(O/'result.json'), completed_utc=now()))
        status(result['status'], child={}, result_sha256=sha(O/'result.json'))
        print(result['status'])
    except Exception as exc:
        status('FAILED_WITH_EVIDENCE', child={}, error=repr(exc))
        save(O/'failure.json', state)
        raise


if __name__ == '__main__':
    main()
