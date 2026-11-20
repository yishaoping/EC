#!/usr/bin/python3
"""Prove actual RAM transaction snapshots, with the emitted memory intact.

No target edits, no synthesis, no device access, and no target/FAME admission.
"""
import fcntl
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
O = D/'build-logs/Opt4-owner-ram-transaction-round55-v1-20261112'
S = D/'Opt4-owner-ram-transaction-round55-v1-state.json'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
MODEL = '46428dc8d9868145ee7636f7da186ea61906da0bb3e0fad3dc756ffd95c135a4'


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']


def observe(raw):
    """Only add observation ports; retain every original memory/RTL byte."""
    ports = '''
 ,input [8:0] proof_watch_address
 ,output [80:0] proof_word
 ,output [69:0] proof_phases
 ,output proof_advance
 ,output proof_write_complete
 ,output proof_write_enable
 ,output [8:0] proof_read_address
'''
    aliases = '\n'.join([
        'assign proof_word = data[proof_watch_address];',
        'assign proof_phases = {'+', '.join('read_state_'+str(i) for i in reversed(range(35)))+'};',
        'assign proof_advance = advance_cycle;',
        'assign proof_write_complete = write_complete_0;',
        'assign proof_write_enable = data_MPORT_en;',
        'assign proof_read_address = data_read_data_async_addr;'])+'\n'
    assert raw.startswith('module RamModel(') and raw.count('endmodule') == 1
    assert raw.count('\n);') == 1
    assert 'reg [80:0] data [0:511];' in raw
    assert raw.count('assign data_read_data_async_data = data[data_read_data_async_addr];') == 1
    result = raw.replace('\n);', ports+'\n);', 1).replace('endmodule', aliases+'endmodule', 1)
    assert result.replace(ports, '', 1).replace(aliases, '', 1) == raw
    return result


def harness(low):
    """A watched-address transaction monitor, independent of RAM read data.

    A command handshake saves the pre-edge abstract word. That saved value
    must be returned while valid, including arbitrary response stalls. The
    abstract word changes only on an enabled, masked, accepted write after
    all 35 read commands have been acquired. It has no reset initialization.
    """
    source = '''module OwnerRamTransaction(
 input clock, input reset,
 input [34:0] command_valid, input [314:0] command_address,
 input [34:0] response_ready,
 input write_valid, input write_en, input write_mask,
 input [8:0] write_address, input [80:0] write_payload,
 input [8:0] watched_address, input [5:0] watched_reader,
 output relation, output word_relation, output selectors_stable,
 output reader_legal, output snapshot_property, output arbitration_property,
 output write_order_property
);
 wire [34:0] command_ready, response_valid;
 wire [2834:0] response_payload;
 wire [69:0] phases;
 wire [80:0] actual_word;
 wire advance, write_complete, actual_write_enable;
 wire [8:0] actual_read_address;
 wire [1:0] selected_phase = phases[2*watched_reader +: 2];
 wire selected_ready = command_ready[watched_reader];
 wire selected_valid = command_valid[watched_reader];
 wire [8:0] selected_address = command_address[9*watched_reader +: 9];
 wire selected_accept = selected_ready && selected_valid;
 wire selected_response_valid = response_valid[watched_reader];
 wire [80:0] selected_response = response_payload[81*watched_reader +: 81];
 wire [34:0] acquired;
 genvar g;
 generate for (g=0; g<35; g=g+1) begin: acq
   assign acquired[g] = phases[2*g +: 2] != 0;
 end endgenerate
 wire reference_write_enable = (&acquired) && !write_complete &&
   write_valid && write_en && write_mask && !reset;
 reg [8:0] abstract_word;
 reg [8:0] expected_snapshot;
 reg tracked;
 reg [8:0] previous_address;
 reg [5:0] previous_reader;
 always @(posedge clock) begin
   previous_address <= watched_address;
   previous_reader <= watched_reader;
   if (reference_write_enable && write_address == watched_address)
     abstract_word <= write_payload[LOW +: 9];
   if (reset || advance) tracked <= 0;
   else if (selected_accept) begin
     tracked <= selected_address == watched_address;
     expected_snapshot <= abstract_word;
   end
 end
 assign word_relation = actual_word[LOW +: 9] == abstract_word;
 assign snapshot_property = !tracked || !selected_response_valid ||
   selected_response[LOW +: 9] == expected_snapshot;
 assign relation = word_relation && (!tracked || selected_phase != 0) && snapshot_property;
 assign reader_legal = watched_reader < 35;
 assign selectors_stable = watched_address == previous_address && watched_reader == previous_reader;
 assign arbitration_property = !selected_accept || actual_read_address == selected_address;
 assign write_order_property = actual_write_enable == reference_write_enable &&
   !(actual_write_enable && (|(command_ready & command_valid)));
 RamModel dut(
'''.replace('LOW', str(low))
    bindings = ['.clock(clock)', '.reset(reset)',
        '.channels_write_cmds_0_ready()', '.channels_write_cmds_0_valid(write_valid)',
        '.channels_write_cmds_0_bits_en(write_en)', '.channels_write_cmds_0_bits_mask(write_mask)',
        '.channels_write_cmds_0_bits_addr(write_address)', '.channels_write_cmds_0_bits_data(write_payload)',
        '.proof_watch_address(watched_address)', '.proof_word(actual_word)',
        '.proof_phases(phases)', '.proof_advance(advance)',
        '.proof_write_complete(write_complete)', '.proof_write_enable(actual_write_enable)',
        '.proof_read_address(actual_read_address)']
    for i in range(35):
        bindings.extend([
            f'.channels_read_cmds_{i}_ready(command_ready[{i}])',
            f'.channels_read_cmds_{i}_valid(command_valid[{i}])',
            f'.channels_read_cmds_{i}_bits_addr(command_address[{9*i} +: 9])',
            f'.channels_read_resps_{i}_ready(response_ready[{i}])',
            f'.channels_read_resps_{i}_valid(response_valid[{i}])',
            f'.channels_read_resps_{i}_bits(response_payload[{81*i} +: 81])'])
    return source+',\n'.join(bindings)+');\nendmodule\n'


def main():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(q) == h for q, h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_TRANSACTION_PROOF_REVALIDATED')
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve failed/partial evidence; recover in a new version'
    assert plan['cpu'] in os.sched_getaffinity(0)
    for row in read(U/'snapshot.json')['states'].values():
        if row.get('identity_live'):
            for proc in row.get('worker_processes', []):
                if live(proc):
                    affinity = os.sched_getaffinity(proc['pid'])
                    assert len(affinity) > 8 or plan['cpu'] not in affinity, ('CPU conflict', proc['pid'])
    os.sched_setaffinity(0, {plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS, (8*2**30, 8*2**30))
    state = dict(schema='ec-owner-ram-transaction-induction/1', **identity(),
        functional_baseline=BASE, hardware_commit=plan['hardware_commit'], source_id=plan['source_id'],
        fpga_access=False, target_changed=False, memory_read_cut=False, whole_fit=False,
        complete_fame_equivalence=False, full_equivalence=False, started_utc=now(), cpu=plan['cpu'])

    def status(value, **extra):
        state.update(status=value, updated_utc=now(), **extra)
        save(O/'state.json', state)
        save(S, state)

    def run(label, actual, low, command, positive):
        policy()
        v, y, log = (O/(label+suffix) for suffix in ['.sv', '.ys', '.log'])
        assert not any(q.exists() for q in [v, y, log])
        v.write_text(actual+'\n'+harness(low))
        y.write_text(f'read_verilog -sv -DSYNTHESIS {v}\nprep -top OwnerRamTransaction -flatten\n'
            'memory_map\nopt -full\nopt_clean\n'+command+'\n')
        started = time.monotonic()
        with log.open('xb') as stream:
            child = subprocess.Popen([plan['yosys'], '-s', str(y)], cwd=C,
                stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
            status('RUNNING_'+label, child=identity(child.pid), stage_log=str(log))
            try:
                code = child.wait(timeout=240)
            except subprocess.TimeoutExpired:
                child.kill()
                code = child.wait()
                raise RuntimeError(('Owned proof child timed out; not PASS', label, code))
        receipt = dict(label=label, returncode=code, seconds=time.monotonic()-started,
            low_bit=low, high_bit=low+8, source_sha256=sha(v), script_sha256=sha(y), log_sha256=sha(log))
        save(O/(label+'-receipt.json'), receipt)
        text = log.read_text()
        if positive:
            assert code == 0 and 'SUCCESS!' in text, receipt
        else:
            assert code != 0 and 'proof did fail' in text and 'TIMEOUT' not in text, receipt
            assert 'syntax error' not in text, receipt
        return receipt

    try:
        raw = (C/'evidence/actual-RamModel.sv').read_text()
        assert sha(C/'evidence/actual-RamModel.sv') == MODEL
        actual = observe(raw)
        common = '-set reader_legal 1 -set selectors_stable 1 '
        reset = 'sat -seq 2 '+common+'-set-at 1 reset 1 -set-at 1 word_relation 1 -prove-skip 1 -prove relation 1 -verify -timeout 120'
        step = 'sat -seq 2 '+common+'-set-at 1 relation 1 -prove-skip 1 -prove relation 1 -verify -timeout 120'
        proofs = []
        for low in range(0, 81, 9):
            proofs.append(run(f'bits-{low}-{low+8}-reset', actual, low, reset, True))
            proofs.append(run(f'bits-{low}-{low+8}-step', actual, low, step, True))
        guards = 'sat -seq 1 -set reader_legal 1 -prove arbitration_property 1 -prove write_order_property 1 -verify -timeout 120'
        proofs.append(run('arbitration-and-write-order', actual, 0, guards, True))
        mutants = [
            ('read-address', 'assign data_read_data_async_data = data[data_read_data_async_addr];',
             "assign data_read_data_async_data = data[data_read_data_async_addr ^ 9'h001];", 0),
            ('write-high-bit', 'assign data_MPORT_data = channels_write_cmds_0_bits_data;',
             "assign data_MPORT_data = channels_write_cmds_0_bits_data ^ 81'h100000000000000000000;", 72),
            ('write-mask', 'wire  _active_write_en_T = channels_write_cmds_0_bits_en & channels_write_cmds_0_bits_mask;',
             'wire  _active_write_en_T = channels_write_cmds_0_bits_en;', 0),
            ('held-response', "assign channels_read_resps_34_bits = read_state_34 == 2'h1 ? read_data : read_resp_data_34;",
             'assign channels_read_resps_34_bits = read_data;', 0)]
        negatives = []
        for label, old, new, low in mutants:
            assert actual.count(old) == 1, (label, actual.count(old))
            negatives.append(run('negative-'+label, actual.replace(old, new, 1), low, step, False))
        result = {**state, 'status':'PASS_ACTUAL_35R1W_RAM_TRANSACTION_SNAPSHOTS_NO_READ_CUT',
            'completed_utc':now(), 'child':{}, 'readers':35, 'words':512, 'data_bits':81,
            'arbitrary_watched_reader':True, 'arbitrary_watched_address':True,
            'all_41472_stored_bits_covered':True, 'observer_exact_reversal_checked':True,
            'ready_valid_stability_assumption':False, 'initial_memory_assumption':'related arbitrary watched word; no initialized contents or reset base',
            'conditional_reset_base':True, 'proof_receipts':proofs,
            'mutation_receipts':negatives, 'mutations_rejected':len(negatives),
            'reference_snapshot':'Save the pre-edge abstract word on the selected accepted read and hold it independently until reset/advance.',
            'reference_write':'All 35 reads acquired, write not completed, write_valid/en/mask and not reset; update watched abstract word from original write input.',
            'selector_assumptions':'Only proof reader/address stay constant over induction edge; command/address/data/response readiness/reset remain arbitrary.',
            'actual_ram_model_sha256':MODEL, 'plan_sha256':sha(C/'plan.json'), 'inputs':plan['inputs'],
            'limitations':['RAM handshake transaction property only; no complete adapter, queue, reset-mask or FAME target-cycle composition.',
                'Conditional arbitrary related storage base; this does not establish initialized or reset-visible target memory.',
                'Inactive response payload is unconstrained. No liveness assumption or completion-time claim.',
                'No full DCache/Opt4 equivalence, area, timing/DRC/bitstream, FPGA or production admission.']}
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
