#!/usr/bin/env python3
"""Read existing evidence only; never launch or control a producer."""
import datetime
import hashlib
import json
import os
from pathlib import Path
import time

EC = Path('/data1/gzh/EC')
D = EC / 'Experiment/firesim-final-opt4-20261106'
W = EC / 'firesim/final-opt4-20261106'
R = EC / 'Experiment/parsec8-simmedium-ec-r2-20261112'
OUT = Path(__file__).resolve().parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
CGROUP = '/user.slice/user-1008.slice/user@1008.service/ec-parsec8-simmedium-ec-r2-20261112.service'
BOUND = {}


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for chunk in iter(lambda: f.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def read(p, bind=True):
    p = Path(p)
    raw = p.read_bytes()
    if bind:
        BOUND[str(p)] = hashlib.sha256(raw).hexdigest()
    return json.loads(raw)


def process(identity):
    p = Path('/proc') / str(identity['pid'])
    stat = p.joinpath('stat').read_text().rsplit(')', 1)[1].split()
    assert stat[19] == str(identity['start_ticks'])
    assert identity.get('boot_id', identity.get('host_boot_id')) == BOOT
    assert '1:name=systemd:' + CGROUP in p.joinpath('cgroup').read_text().splitlines()
    assert stat[0] != 'Z'
    return dict(pid=identity['pid'], start_ticks=stat[19], boot_id=BOOT,
                ppid=int(stat[1]), state=stat[0], cgroup=CGROUP,
                cpu_ticks=int(stat[11]) + int(stat[12]),
                affinity=sorted(os.sched_getaffinity(identity['pid'])))


def sample(benchmark, worker, controller):
    out = R / 'runs' / benchmark
    state = read(out / 'state.json', False)
    wp, child = process(worker), process(state['child'])
    assert wp['ppid'] == controller['pid'] and child['ppid'] == wp['pid']
    heartbeat = (out / 'heartbeat.csv').read_bytes()
    rows = [list(map(int, line.split(b','))) for line in heartbeat.splitlines()[1:]
            if line.count(b',') == 1]
    assert rows and all(b[0] > a[0] and b[1] >= a[1] for a, b in zip(rows, rows[1:]))
    return dict(observed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                producer_state=state, worker=wp, child=child,
                heartbeat_sha256=hashlib.sha256(heartbeat).hexdigest(),
                heartbeat_rows=len(rows), last_target_cycle=rows[-1][0],
                last_heartbeat_host_seconds=rows[-1][1],
                uart_bytes=(out / 'uart.log').stat().st_size,
                uart_input_bytes=(out / 'uart.in').stat().st_size)


def main():
    assert not (OUT / 'result.json').exists(), 'preserve previous receipt'
    old147 = D / 'status-audits/round147-parsec-existing-pairs-acceptance-20261112'
    prior = read(old147 / 'result.json')
    assert read(old147 / 'complete.json')['files_sha256']['result.json'] == BOUND[str(old147 / 'result.json')]
    old148 = D / 'status-audits/round148-simmedium-existing-owner-adoption-20261112'
    adoption = read(old148 / 'receipt.json')
    assert (old148 / 'receipt.sha256').read_text().split()[0] == BOUND[str(old148 / 'receipt.json')]
    inputs = read(R / 'inputs.json')
    assert adoption['immutable_source_sha256'][str(R / 'inputs.json')] == BOUND[str(R / 'inputs.json')]

    # Reuse the 21 passing archival audits; investigate only their three exceptions.
    exceptions = [n for n in prior['historical_fpga'] if not n['saved_evidence_valid']]
    assert len(exceptions) == 3 and {n['benchmark'] for n in exceptions} == {'blackscholes'}
    ct = read(R / 'contracts/blackscholes.json')
    reconciled = []
    for archive in ct['native_archives']:
        p = Path(archive['result'])
        result = read(p)
        assert BOUND[str(p)] == archive['result_sha256']
        complete = read(p.parent / 'complete.json')
        assert complete['result_sha256'] == BOUND[str(p)]
        assert complete['identity_sha256'] == result['identity_sha256']
        assert result['valid'] and result['formal'] and result['fpga_execution']
        assert not result['timedout'] and result['issues'] == []
        mismatches = []
        for name, expected in result['evidence'].items():
            actual = sha(name)
            BOUND[name] = actual
            if actual != expected:
                mismatches.append(dict(path=name, expected_sha256=expected, actual_sha256=actual))
        statepath, snappath = p.parent / 'state.json', p.parent / 'snapshot.json'
        assert [n['path'] for n in mismatches] == [str(statepath)]
        snapshot, state = read(snappath), read(statepath)
        assert result['evidence'][str(snappath)] == result['evidence'][str(statepath)] == BOUND[str(snappath)]
        assert snapshot['run_id'] == state['run_id'] == result['identity']['run_id']
        assert snapshot['identity_sha256'] == state['identity_sha256'] == result['identity_sha256']
        assert snapshot['status'] == 'RUNNING' and state['status'] == 'COMPLETE'
        assert state['issues'] == [] and datetime.datetime.fromisoformat(state['ended_utc'])
        expected_state = dict(snapshot, status='COMPLETE', issues=[], ended_utc=state['ended_utc'])
        assert state == expected_state, 'unexpected archival state change'
        epoch, = result['raw']['epochs']
        assert epoch['source_boundaries_complete'] and not any(epoch[k] for k in ['aborted', 'reset_seen', 'faults'])
        assert epoch['end_tick'] - epoch['begin_tick'] == result['roi_cycles'] == archive['roi_cycles']
        reconciled.append(dict(repetition=archive['repeat'], result=str(p),
                               result_sha256=BOUND[str(p)], mismatches_retained=mismatches,
                               immutable_snapshot_matches_both_original_hashes=True,
                               all_other_recorded_evidence_hashes_match=True,
                               state_delta=dict(status=['RUNNING', 'COMPLETE'],
                                                added_issues=[], added_ended_utc=state['ended_utc']),
                               roi_target_cycles=result['roi_cycles'],
                               strict_original_evidence_manifest_pass=False,
                               finding='Terminal bookkeeping delta only; immutable measurement evidence intact. Original mismatch is retained, not rewritten.'))

    # New static comparison uses saved parameter data; no elaboration or simulation.
    np = EC / 'firesim/dac2026/work/opt4-roi-v5/builds/B-parameters-20261102T092950.874012Z/parameters.json'
    ep = W / 'builds/C4-parameters-20261106T100204.040607Z/parameters.json'
    native, ec = read(np), read(ep)
    ec_receipt = read(D / 'build-logs/C4-parameters-20261106T100204.040607Z/result.json')
    assert ec_receipt['outputs'][str(ep)] == BOUND[str(ep)]
    assert ec_receipt['source_id'] == read(D / 'cycleprecise-frozen-full-metasim-r1-20261111/binding.json')['source_id']
    nt, et = native['tiles'][0], ec['tiles'][0]
    nc, ec_core = dict(nt['core']), dict(et['core'])
    predictor_labels = [nc.pop('branchPredictor'), ec_core.pop('branchPredictor')]
    assert nc == ec_core
    assert {k:v for k,v in nt.items() if k != 'core'} == {k:v for k,v in et.items() if k != 'core'}
    shared = ['inclusive_cache', 'external_memory', 'memory_model']
    assert all(native[k] == ec[k] for k in shared)
    static = dict(saved_boom_parameters_equal_except_predictor_label=True,
                  unclassified_predictor_closure_labels=predictor_labels,
                  other_boom_core_field_count=len(nc), shared_equal_fields=shared,
                  native_tile_count=len(native['tiles']), ec_tile_count=len(ec['tiles']),
                  admission=False,
                  limitations=['Predictor closure strings are neither functional equivalence proof nor proof of mismatch.',
                               'Historical Native bitstream-to-parameter/source chain and cross-backend timebase equivalence still require admission.'])
    source_lines = {}
    for cfg in ['Native', 'C4']:
        root = W / cfg / 'chipyard/generators'
        selected = []
        for rel in ['rocket-chip/src/main/scala/util/DacRoi.scala', 'boom/src/main/scala/exu/core.scala']:
            p = root / rel
            BOUND[str(p)] = sha(p)
            for line, text in enumerate(p.read_text().splitlines(), 1):
                if any(s in text for s in ['tick := tick + 1.U', 'beginTick := io.originalTick;',
                                           'endTick := io.originalTick;', 'val starts = VecInit',
                                           'val ends = VecInit', 'dac.io.originalTick := RegNext(dac.io.tick',
                                           'dac.io.valid := VecInit(rob.io.commit.arch_valids']):
                    selected.append(dict(path=str(p), line=line, source=text.strip()))
        assert len(selected) == 7
        source_lines[cfg] = selected

    campaign = read(R / 'campaign-state.json', False)
    controller = process(campaign['controller'])
    active = {v['benchmark']: v['worker'] for v in campaign['active'].values()}
    first = {b: sample(b, w, controller) for b, w in active.items()}
    time.sleep(12)
    progress = []
    for b, worker in active.items():
        second = sample(b, worker, controller)
        assert second['child']['start_ticks'] == first[b]['child']['start_ticks']
        assert second['last_target_cycle'] > first[b]['last_target_cycle']
        assert second['child']['cpu_ticks'] > first[b]['child']['cpu_ticks']
        progress.append(dict(benchmark=b, first=first[b], second=second,
                             target_cycle_delta=second['last_target_cycle']-first[b]['last_target_cycle'],
                             interpretation='Target heartbeat advances before ROI; no guest command or application completion inferred.'))
    paper = read(R / 'paper-state.json', False)
    assert paper['valid_slowdowns'] == 0 and all(row['slowdown'] is None for row in paper['rows'])
    assert all(sha(p) == h for p, h in BOUND.items())
    result = dict(schema='ec-round149-simmedium-admission/1',
                  status='PASS_READONLY_RECONCILIATION_SLOWDOWN_NOT_ADMITTED',
                  observed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                  functional_baseline=inputs['functional_baseline'],
                  archival_checks_reused=21, archival_terminal_deltas=reconciled,
                  original_historical_status_preserved=prior['historical_fpga_status'],
                  static_configuration=static, counter_source_observations=source_lines,
                  counter_boundary='Both source snapshots latch original BOOM retirement-marker ticks. This is source evidence, not cross-backend runtime validation.',
                  active_progress=progress, pending=campaign['pending'],
                  valid_ec_simmedium=paper['valid_ec_simmedium'], valid_slowdowns=0,
                  slowdown_admitted=False,
                  pending_gates=['Full simmedium software output and strict EC checker/drain/event audit.',
                                 'Full target configuration and historical Native source/bitstream contract.',
                                 'Runtime ROI timebase/counter equivalence across FPGA Native and CPU EC.'],
                  immutable_sources_sha256=BOUND,
                  launched_jobs=[], producer_changes=[], process_signals=[], fpga_operations=[],
                  next_automatic_action='Existing simmedium-only owner dispatches each application once after guest-ready; records failures/timeouts and advances remaining order. No rerun or ratio publication.')
    with (OUT / 'result.json').open('x') as f:
        json.dump(result, f, indent=2, sort_keys=True)
        f.write('\n')
    with (OUT / 'result.sha256').open('x') as f:
        f.write(sha(OUT / 'result.json') + '  result.json\n')
    print(json.dumps(dict(status=result['status'], result_sha256=sha(OUT / 'result.json'),
                          reconciled_native_terminal_deltas=len(reconciled),
                          active=[dict(benchmark=r['benchmark'], target_cycle_delta=r['target_cycle_delta'],
                                       last_target_cycle=r['second']['last_target_cycle']) for r in progress],
                          pending=result['pending'], valid_ec_simmedium=result['valid_ec_simmedium'], valid_slowdowns=0)))


if __name__ == '__main__':
    main()
