#!/usr/bin/python3
"""Prove the emitted owner RAM scheduler with an explicit symbolic read cut.

Verification copies only. This is not a proof of memory contents, the FAME
composition, complete DCache/Opt4 equivalence, area, or FPGA admission.
"""
import fcntl
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-ram-controller-round53-v1-20261112'
S = D/'Opt4-owner-ram-controller-round53-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']


def observe(raw):
    """Reversible observer insertion and one overapproximating read-data cut."""
    ports = ',\n  input [80:0] proof_read_word,\n' + ',\n'.join([
        '  output [69:0] proof_states',
        '  output proof_write_complete, output proof_advance',
        '  output [8:0] proof_read_address',
        '  output proof_write_enable, output [8:0] proof_write_address',
        '  output [80:0] proof_write_data, output [80:0] proof_pipeline',
        '  output [2834:0] proof_held_data'])
    aliases = '\n'.join([
        '  assign proof_states = {'+', '.join(f'read_state_{i}' for i in reversed(range(35)))+'};',
        '  assign proof_write_complete = write_complete_0;',
        '  assign proof_advance = advance_cycle;',
        '  assign proof_read_address = data_read_data_async_addr;',
        '  assign proof_write_enable = data_MPORT_en & data_MPORT_mask;',
        '  assign proof_write_address = data_MPORT_addr;',
        '  assign proof_write_data = data_MPORT_data;',
        '  assign proof_pipeline = read_data;',
        '  assign proof_held_data = {'+', '.join(f'read_resp_data_{i}' for i in reversed(range(35)))+'};'])+'\n'
    cut_old = 'assign data_read_data_async_data = data[data_read_data_async_addr];'
    cut_new = 'assign data_read_data_async_data = proof_read_word;'
    assert raw.count(cut_old) == 1 and raw.count('\n);') == 1
    assert raw.count('endmodule') == 1 and raw.startswith('module RamModel(')
    result = raw.replace('\n);', ports+'\n);', 1)
    result = result.replace('endmodule', aliases+'endmodule', 1).replace(cut_old, cut_new, 1)
    assert result.replace(ports, '', 1).replace(aliases, '', 1).replace(cut_new, cut_old, 1) == raw
    return result, dict(read_data_cut_original=cut_old, read_data_cut_replacement=cut_new,
        original_memory_dimensions=[512, 81], read_ports=35, write_ports=1,
        exact_reversal_checked=True, memory_contents_proved=False,
        cut_meaning='Read data is arbitrary independently on every host edge; controller and pipeline only.')


def harness():
    # A separate per-reader transaction model with an integer priority scan.
    # No assumptions on command stability, response readiness, reset, data,
    # or arbitrary related initial controller states are imposed.
    lines = ['''module OwnerRamRelation(
 input clock, input reset,
 input [34:0] command_valid, input [314:0] command_address,
 input [34:0] response_ready,
 input write_valid, input write_en, input write_mask,
 input [8:0] write_address, input [80:0] write_payload,
 input [80:0] read_word,
 output relation, output observations, output reset_empty,
 output read_before_write
);
 wire [34:0] command_ready, response_valid;
 wire [2834:0] response_payload, held;
 wire [69:0] phases;
 wire actual_write_ready, actual_complete, actual_advance, actual_write_en;
 wire [8:0] actual_read_address, actual_write_address;
 wire [80:0] actual_write_data, actual_pipeline;
 reg [1:0] phase [0:34];
 reg [80:0] saved [0:34];
 reg [80:0] pipeline;
 reg completed;
 reg [34:0] expected_ready, expected_valid, requests;
 reg [8:0] selected_address;
 reg found, all_acquired, all_answered;
 integer i;
 always @* begin
   found = 0;
   selected_address = command_address[8:0];
   all_acquired = 1;
   all_answered = 1;
   for (i=0; i<35; i=i+1) begin
     requests[i] = phase[i] == 0 && command_valid[i];
     expected_ready[i] = phase[i] == 0 && !found;
     expected_valid[i] = phase[i] == 1 || phase[i] == 2;
     if (!found && requests[i]) selected_address = command_address[9*i +: 9];
     found = found || requests[i];
     all_acquired = all_acquired && phase[i] != 0;
     all_answered = all_answered && (phase[i] == 3 || (expected_valid[i] && response_ready[i]));
   end
 end
 wire expected_write_ready = all_acquired && !completed;
 wire write_fire = expected_write_ready && write_valid;
 wire finish = all_answered && (completed || write_fire);
 wire enabled_write = write_fire && write_en && write_mask && !reset;
 integer j;
 always @(posedge clock) begin
   pipeline <= read_word;
   if (reset || finish) completed <= 0;
   else if (write_fire) completed <= 1;
   for (j=0; j<35; j=j+1) begin
     if (reset || finish) phase[j] <= 0;
     else if (expected_ready[j] && command_valid[j]) phase[j] <= 1;
     else if (expected_valid[j]) phase[j] <= response_ready[j] ? 3 : 2;
     if (!reset && !finish && phase[j] == 1) saved[j] <= pipeline;
   end
 end
 wire [34:0] state_equal, payload_equal, output_equal;
 genvar g;
 generate for (g=0; g<35; g=g+1) begin: compare
   assign state_equal[g] = phases[2*g +: 2] == phase[g];
   assign payload_equal[g] = phase[g] != 2 || held[81*g +: 81] == saved[g];
   assign output_equal[g] = !expected_valid[g] || response_payload[81*g +: 81] ==
     (phase[g] == 1 ? pipeline : saved[g]);
 end endgenerate
 assign relation = (&state_equal) && completed == actual_complete &&
   pipeline == actual_pipeline && (&payload_equal);
 assign observations = command_ready == expected_ready && response_valid == expected_valid &&
   (&output_equal) && actual_write_ready == expected_write_ready &&
   actual_advance == finish && (!found || actual_read_address == selected_address) &&
   actual_write_en == enabled_write && actual_write_address == write_address &&
   actual_write_data == write_payload;
 assign reset_empty = phases == 0 && !actual_complete;
 assign read_before_write = !actual_write_en ||
   ((&{'''+', '.join(f'(phases[{2*i} +: 2] != 0)' for i in range(35))+'''}) &&
    !reset && write_valid && write_en && write_mask && !actual_complete);
 RamModel dut(''']
    bindings = ['.clock(clock)', '.reset(reset)',
        '.channels_write_cmds_0_ready(actual_write_ready)',
        '.channels_write_cmds_0_valid(write_valid)', '.channels_write_cmds_0_bits_en(write_en)',
        '.channels_write_cmds_0_bits_mask(write_mask)', '.channels_write_cmds_0_bits_addr(write_address)',
        '.channels_write_cmds_0_bits_data(write_payload)', '.proof_read_word(read_word)',
        '.proof_states(phases)', '.proof_write_complete(actual_complete)',
        '.proof_advance(actual_advance)', '.proof_read_address(actual_read_address)',
        '.proof_write_enable(actual_write_en)', '.proof_write_address(actual_write_address)',
        '.proof_write_data(actual_write_data)', '.proof_pipeline(actual_pipeline)', '.proof_held_data(held)']
    for i in range(35):
        bindings.extend([
            f'.channels_read_cmds_{i}_ready(command_ready[{i}])',
            f'.channels_read_cmds_{i}_valid(command_valid[{i}])',
            f'.channels_read_cmds_{i}_bits_addr(command_address[{9*i} +: 9])',
            f'.channels_read_resps_{i}_ready(response_ready[{i}])',
            f'.channels_read_resps_{i}_valid(response_valid[{i}])',
            f'.channels_read_resps_{i}_bits(response_payload[{81*i} +: 81])'])
    return '\n'.join(lines)+',\n'.join(bindings)+');\nendmodule\n'


def main():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_RAM_CONTROLLER_PROOF_REVALIDATED')
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve failed/partial evidence; use a new version'
    assert plan['cpu'] in os.sched_getaffinity(0)
    # The proof uses one nonconflicting CPU and at most 8 GiB; the broker
    # remains authoritative for ordinary/auxiliary job admission.
    for row in read(U/'snapshot.json')['states'].values():
        if row.get('identity_live'):
            for proc in row.get('worker_processes', []):
                if live(proc):
                    affinity = os.sched_getaffinity(proc['pid'])
                    assert len(affinity) > 8 or plan['cpu'] not in affinity, ('CPU conflict', proc['pid'])
    os.sched_setaffinity(0, {plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS, (8*2**30, 8*2**30))
    state = dict(schema='ec-owner-ram-controller-proof/1', **identity(),
        functional_baseline=BASE, hardware_commit=plan['hardware_commit'], source_id=plan['source_id'],
        fpga_access=False, target_changed=False, full_equivalence=False, whole_fit=False,
        started_utc=now(), cpu=plan['cpu'])

    def status(value, **extra):
        state.update(status=value, updated_utc=now(), **extra)
        save(O/'state.json', state)
        save(S, state)

    def run(label, source, command, expected_pass):
        policy()
        v, y, log = (O/(label+suffix) for suffix in ['.sv', '.ys', '.log'])
        assert not any(p.exists() for p in [v, y, log])
        v.write_text(source)
        y.write_text(f'read_verilog -sv -DSYNTHESIS {v}\nprep -top OwnerRamRelation -flatten\n'
            'memory_map\nopt_clean\n'+command+'\n')
        start = time.monotonic()
        with log.open('xb') as stream:
            child = subprocess.Popen([plan['yosys'], '-s', str(y)], cwd=C,
                stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
            status('RUNNING_'+label, child=identity(child.pid), stage_log=str(log))
            try:
                code = child.wait(timeout=180)
            except subprocess.TimeoutExpired:
                child.kill()
                code = child.wait()
                raise RuntimeError(('owned proof child timed out; not PASS', label, code))
        receipt = dict(label=label, returncode=code, seconds=time.monotonic()-start,
            source_sha256=sha(v), script_sha256=sha(y), log_sha256=sha(log))
        save(O/(label+'-receipt.json'), receipt)
        text = log.read_text()
        if expected_pass:
            assert code == 0 and 'SUCCESS!' in text, receipt
        else:
            assert code != 0 and 'proof did fail' in text, receipt
            assert 'TIMEOUT' not in text and 'syntax error' not in text, receipt
        return receipt

    try:
        raw = (C/'evidence/actual-RamModel.sv').read_text()
        actual, boundary = observe(raw)
        save(O/'verification-boundary.json', boundary)
        source = actual+'\n'+harness()
        reset = ('sat -seq 2 -set-at 1 reset 1 -prove-skip 1 -prove relation 1 '
                 '-prove reset_empty 1 -verify -timeout 120')
        step = ('sat -seq 2 -set-at 1 relation 1 -prove-skip 1 -prove relation 1 '
                '-verify -timeout 120')
        obs = 'sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 120'
        guards = 'sat -seq 1 -prove read_before_write 1 -verify -timeout 120'
        proofs = [run(label, source, command, True) for label, command in
            [('reset', reset), ('step', step), ('observations', obs), ('read-before-write', guards)]]
        mutants = [
            ('priority', 'assign channels_read_cmds_1_ready = _read_access_req_T_1 & read_access_available_1;',
                'assign channels_read_cmds_1_ready = _read_access_req_T_1;', obs),
            ('address', 'assign data_read_data_async_addr = read_access_granted_34 ? channels_read_cmds_34_bits_addr : _GEN_273;',
                'assign data_read_data_async_addr = channels_read_cmds_0_bits_addr;', obs),
            ('mask', 'wire  _active_write_en_T = channels_write_cmds_0_bits_en & channels_write_cmds_0_bits_mask;',
                'wire  _active_write_en_T = channels_write_cmds_0_bits_en;', obs),
            ('payload', "assign channels_read_resps_34_bits = read_state_34 == 2'h1 ? read_data : read_resp_data_34;",
                'assign channels_read_resps_34_bits = read_data;', obs),
            ('reset', "read_state_34 <= 2'h0;", "read_state_34 <= 2'h1;", reset),
            ('advance', 'wire  advance_cycle = outputs_responded_or_firing & writes_done_or_finishing;',
                'wire  advance_cycle = outputs_responded_or_firing;', obs),
            ('pipeline', 'read_data <= data_read_data_async_data;',
                "read_data <= data_read_data_async_data ^ 81'h100000000000000000000;", step)]
        negatives = []
        for label, old, new, command in mutants:
            assert actual.count(old) == 1, (label, actual.count(old))
            negatives.append(run('negative-'+label, actual.replace(old, new, 1)+'\n'+harness(), command, False))
        result = {**state, 'status':'PASS_ACTUAL_35R1W_RAM_CONTROLLER_AND_PAYLOAD_RELATIONAL_INDUCTION_WITH_SYMBOLIC_READ_CUT',
            'completed_utc':now(), 'child':{}, 'readers':35, 'data_bits':81, 'address_bits':9,
            'proof_receipts':proofs, 'mutation_receipts':negatives, 'mutations_rejected':len(negatives),
            'proof_boundary':boundary, 'universal_related_state_induction':True,
            'reset_from_arbitrary_controller_state':True, 'initial_payload_assumption':False,
            'ready_valid_stability_assumption':False, 'invalid_response_payload_compared':False,
            'actual_ram_model_sha256':sha(C/'evidence/actual-RamModel.sv'),
            'plan_sha256':sha(C/'plan.json'), 'inputs':plan['inputs'],
            'limitations':['Symbolic memory-read cut; memory contents and read/write collision semantics remain separate.',
                'Payload comparison is guarded by valid; inactive Decoupled payload is unconstrained.',
                'No end-to-end target-cycle/FAME proof, full DCache/Opt4 equivalence, area, FIT, FPGA or production admission.']}
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
