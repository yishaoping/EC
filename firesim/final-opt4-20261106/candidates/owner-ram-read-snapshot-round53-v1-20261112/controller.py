#!/usr/bin/python3
"""Actual emitted RAM read snapshot and same-edge old-word semantics.

The arbitrary watched address and nine projections cover all 512x81 bits.
No read-data cut: the actual memory, async read and read_data register remain.
The one-edge proof starts with the selected memory word related and checks
that a selected-address read captures that pre-write word even on a collision.
"""
import fcntl
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
O = D/'build-logs/Opt4-owner-ram-read-snapshot-round53-v1-20261112'
S = D/'Opt4-owner-ram-read-snapshot-round53-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']


def observer(raw, low):
    # The full original module and its actual write process remain intact.
    # Yosys may remove unobserved response logic and unused payload bits.
    ports = (',\n input [8:0] proof_watch, output [8:0] proof_word,\n'
             ' output proof_write_enable, output [8:0] proof_write_address,\n'
             ' output [80:0] proof_write_data, output [8:0] proof_pipeline, output [8:0] proof_read_address')
    aliases = (f' assign proof_word = data[proof_watch][{low+8}:{low}];\n'
               ' assign proof_write_enable = data_MPORT_en & data_MPORT_mask;\n'
               ' assign proof_write_address = data_MPORT_addr;\n'
               ' assign proof_write_data = data_MPORT_data;\n'
               f' assign proof_pipeline = read_data[{low+8}:{low}];\n'
               ' assign proof_read_address = data_read_data_async_addr;\n')
    assert raw.count('\n);') == 1 and raw.count('endmodule') == 1
    result = raw.replace('\n);', ports+'\n);', 1).replace('endmodule', aliases+'endmodule', 1)
    assert result.replace(ports, '', 1).replace(aliases, '', 1) == raw
    return result


def harness(low):
    ports = ['input clock', 'input reset', 'input [34:0] command_valid',
        'input [314:0] command_address', 'input [34:0] response_ready',
        'input write_valid', 'input write_en', 'input write_mask',
        'input [8:0] write_address', 'input [80:0] write_payload',
        'input [8:0] watch', 'output stable_address', 'output word_relation', 'output read_relation']
    bindings = ['.clock(clock)', '.reset(reset)', '.proof_watch(watch)',
        '.proof_word(actual_word)', '.proof_write_enable(actual_write)',
        '.proof_write_address(actual_address)', '.proof_write_data(actual_data)',
        '.proof_pipeline(actual_pipeline)', '.proof_read_address(actual_read_address)',
        '.channels_write_cmds_0_ready()', '.channels_write_cmds_0_valid(write_valid)',
        '.channels_write_cmds_0_bits_en(write_en)', '.channels_write_cmds_0_bits_mask(write_mask)',
        '.channels_write_cmds_0_bits_addr(write_address)', '.channels_write_cmds_0_bits_data(write_payload)']
    for i in range(35):
        bindings += [f'.channels_read_cmds_{i}_ready()',
            f'.channels_read_cmds_{i}_valid(command_valid[{i}])',
            f'.channels_read_cmds_{i}_bits_addr(command_address[{9*i} +: 9])',
            f'.channels_read_resps_{i}_ready(response_ready[{i}])',
            f'.channels_read_resps_{i}_valid()', f'.channels_read_resps_{i}_bits()']
    return ('module OwnerReadSnapshotRelation('+',\n'.join(ports)+');\n'+f'''
 wire [8:0] actual_word, actual_address, actual_pipeline, actual_read_address;
 wire [80:0] actual_data;
 wire actual_write;
 reg [8:0] previous_watch, expected_word, expected_pipeline;
 reg captured_watch;
 always @(posedge clock) begin
   previous_watch <= watch;
   captured_watch <= actual_read_address == watch;
   expected_pipeline <= expected_word;
   if (actual_write && actual_address == watch)
     expected_word <= actual_data[{low+8}:{low}];
 end
 assign stable_address = watch == previous_watch;
 assign word_relation = actual_word == expected_word;
 assign read_relation = !captured_watch || actual_pipeline == expected_pipeline;
 RamModel dut('''+',\n'.join(bindings)+');\nendmodule\n')


def main():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_RAM_READ_SNAPSHOT_PROOF_REVALIDATED')
        return
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve partial evidence; recover with new version'
    for row in read(U/'snapshot.json')['states'].values():
        if row.get('identity_live'):
            for proc in row.get('worker_processes', []):
                if live(proc):
                    affinity = os.sched_getaffinity(proc['pid'])
                    assert len(affinity) > 8 or plan['cpu'] not in affinity, ('CPU conflict', proc['pid'])
    assert plan['cpu'] in os.sched_getaffinity(0)
    os.sched_setaffinity(0, {plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS, (16*2**30, 16*2**30))
    state = dict(schema='ec-owner-ram-read-snapshot-proof/1', **identity(),
        functional_baseline=BASE, hardware_commit=plan['hardware_commit'], source_id=plan['source_id'],
        fpga_access=False, target_changed=False, full_equivalence=False, whole_fit=False,
        cpu=plan['cpu'], started_utc=now())

    def status(value, **extra):
        state.update(status=value, updated_utc=now(), **extra)
        save(O/'state.json', state)
        save(S, state)

    def run(label, raw, low, negative=False):
        policy()
        source = observer(raw, low)+'\n'+harness(low)
        v, y, log = (O/(label+ext) for ext in ['.sv', '.ys', '.log'])
        assert not any(q.exists() for q in [v, y, log])
        v.write_text(source)
        y.write_text(f'read_verilog -sv -DSYNTHESIS {v}\n'
            'prep -top OwnerReadSnapshotRelation -flatten\n'
            'memory_map\nopt -full\nopt_clean\n'
            'sat -seq 2 -set stable_address 1 -set-at 1 word_relation 1 '
            '-prove-skip 1 -prove read_relation 1 -verify -timeout 180\n')
        start = time.monotonic()
        with log.open('xb') as stream:
            child = subprocess.Popen([plan['yosys'], '-s', str(y)], cwd=C,
                stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
            status('RUNNING_'+label, child=identity(child.pid), stage_log=str(log))
            try:
                code = child.wait(timeout=240)
            except subprocess.TimeoutExpired:
                child.kill()
                code = child.wait()
                raise RuntimeError(('owned proof child timeout; not PASS', label, code))
        text = log.read_text()
        receipt = dict(label=label, low_bit=low, high_bit=low+8, returncode=code,
            seconds=time.monotonic()-start, source_sha256=sha(v), script_sha256=sha(y), log_sha256=sha(log))
        save(O/(label+'-receipt.json'), receipt)
        if negative:
            assert code != 0 and 'proof did fail' in text and 'TIMEOUT' not in text, receipt
        else:
            assert code == 0 and 'SUCCESS!' in text, receipt
        return receipt

    try:
        raw = (C/'evidence/actual-RamModel.sv').read_text()
        # Require the actual dimensions and writer, rather than a hand-written
        # generic RAM. No initial memory, reset value, or zero assumption.
        assert 'reg [80:0] data [0:511];' in raw
        old = 'data[data_MPORT_addr] <= data_MPORT_data;'
        assert raw.count(old) == 1
        proofs = [run(f'bits-{low}-{low+8}', raw, low) for low in range(0, 81, 9)]
        read_old = 'read_data <= data_read_data_async_data;'
        async_old = 'assign data_read_data_async_data = data[data_read_data_async_addr];'
        assert raw.count(read_old) == 1 and raw.count(async_old) == 1
        mutations = [
            ('pipeline-high-bit', read_old,
                "read_data <= data_read_data_async_data ^ 81'h100000000000000000000;", 72),
            ('async-read-address', async_old,
                "assign data_read_data_async_data = data[data_read_data_async_addr ^ 9'h1];", 0),
            ('same-edge-write-forwarding', read_old,
                'read_data <= (data_MPORT_en && data_MPORT_mask && '
                'data_MPORT_addr == data_read_data_async_addr) ? '
                'data_MPORT_data : data_read_data_async_data;', 0)]
        negatives = [run('negative-'+label, raw.replace(old, new, 1), low, True)
            for label, old, new, low in mutations]
        result = {**state,
            'status':'PASS_ACTUAL_512X81_HOST_RAM_READ_SNAPSHOT_AND_SAME_EDGE_OLD_WORD_RELATION',
            'completed_utc':now(), 'child':{}, 'words':512, 'bits_per_word':81,
            'all_41472_stored_bits_covered':True, 'arbitrary_watched_address':True,
            'watched_address_stable_across_induction_edge':True,
            'memory_read_cut':False, 'initial_memory_assumption':False,
            'observer_exact_reversal_checked':True, 'read_capture_reset_gating':'actual ungated pipeline',
            'induction_hypothesis':'Only actual selected word equals reference word before edge; no pipeline assumption.',
            'collision_semantics':'When observed read address equals arbitrary watched address, the actual pipeline captures the pre-edge word, including simultaneous write to that address.',
            'proof_receipts':proofs, 'mutation_receipts':negatives, 'mutations_rejected':len(negatives),
            'actual_ram_model_sha256':sha(C/'evidence/actual-RamModel.sv'),
            'plan_sha256':sha(C/'plan.json'), 'inputs':plan['inputs'],
            'limitations':['Reference memory write uses actual observed control/address/data; controller equivalence is separate.',
                'Watched-word storage invariant is a separately bound prerequisite, not reproved here.',
                'No complete multi-cycle FAME/target-cycle composition, DCache/Opt4 equivalence, area, FIT, FPGA or production admission.']}
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
