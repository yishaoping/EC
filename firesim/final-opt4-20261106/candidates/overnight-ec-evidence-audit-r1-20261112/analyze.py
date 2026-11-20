#!/usr/bin/python3
"""Reproducible audit of completed CPU-only EC evidence; never accesses FPGA.

Preserves source receipts. Writes a versioned audit with streamed raw-log hashes,
strict finite package identity joins, exact SVB identity lifetimes, and CSV data.
It does not run a workload, change models, certify bitstreams, or deploy hardware.
"""
from pathlib import Path
import collections
import csv
import datetime
import gzip
import hashlib
import importlib.util
import json
import math
import os
import re
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D/'overnight-ec-evidence-audit-r4-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
CAN = D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
RUN = CAN/'canneal-observer-on'
BS = D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111'
SV = D/'cycleprecise-original-svb-binary-replay-r1-20261111'
GG = D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
CP = W/'candidates/full-gg-external-observer-r5-20261111'
SP = W/'candidates/full-svb-binary-replay-r1-20261111'
GP = W/'candidates/full-svb-gg-stream-replay-r3-20261111'
G2 = W/'candidates/full-svb-gg-stream-replay-r2-20261111'
BP = W/'candidates/full-gg-blackscholes-observed-r1-20261111'
CACHE = {}
VERIFICATIONS = []
RAW = {}

def read(p):
    return json.loads(Path(p).read_text())

def sha(p):
    p = Path(p).resolve()
    if p not in CACHE:
        before = p.stat()
        h = hashlib.sha256()
        with p.open('rb') as f:
            while chunk := f.read(4*2**20):
                h.update(chunk)
        after = p.stat()
        assert (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns), ('CHANGED_DURING_AUDIT', str(p))
        CACHE[p] = dict(sha256=h.hexdigest(), bytes=after.st_size, mtime_ns=after.st_mtime_ns)
    return CACHE[p]['sha256']

def check(p, expected, reason):
    actual = sha(p)
    VERIFICATIONS.append(dict(path=str(p), expected_sha256=expected, actual_sha256=actual,
                              passed=actual == expected, reason=reason))
    assert actual == expected, ('SHA256_MISMATCH', reason, str(p), expected, actual)
    return actual

def save(name, value):
    p = O/name
    assert not p.exists(), ('PRESERVE_EXISTING_AUDIT', str(p))
    temp = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with temp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(temp, p)

def csvwrite(name, rows):
    assert rows
    p = O/name
    with p.open('x', newline='') as f:
        out = csv.DictWriter(f, fieldnames=list(rows[0]))
        out.writeheader(); out.writerows(rows); f.flush(); os.fsync(f.fileno())

def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    sha(path)
    return module

def strict_package_join(run, name):
    # Uses independently hashbound strict analyzer, not a status flag in the run.
    module = load_module('strict_'+name, W/'candidates/full-gg-acceptance-strict-r1-20261111/analyze.py')
    joined = module.analyze(run)
    save(name+'-strict-join.json', joined)
    events = [json.loads(line) for line in (run/'external-events.jsonl').read_text().splitlines()]
    return joined, events

def rawscan(stream):
    # UART/application text is in complete host stdout, while rtl-prints-* are
    # separate synthesized debug streams. Scan original bytes in bounded chunks.
    digest=hashlib.sha256(); count=0; tail=b''; rows=[]; targets=[];faults=[]
    total=re.compile(rb'Target Cycles Emulated:\s*(\d+)')
    def lines(chunk):
        for line in chunk.split(b'\n'):
            if any(marker in line for marker in [b'[ROI]',b'[OUTPUT]',b'[APP]',b'[COMPUTATION]',b'[END]']):
                rows.append(line.decode(errors='replace').rstrip('\r'))
            if b'Target Cycles Emulated:' in line:
                targets.extend(int(m[1]) for m in total.finditer(line))
            if any(marker in line for marker in [b'Assertion failed',b'%Error',b'status=FAIL',b'Simulator deadlock detected']):
                faults.append(line.decode(errors='replace'))
    while chunk:=stream.read(4*2**20):
        digest.update(chunk);count+=len(chunk)
        text=tail+chunk;cut=text.rfind(b'\n')
        if cut>=0:
            lines(text[:cut]);tail=text[cut+1:]
        else:
            tail=text
        assert len(tail)<8*2**20,'UNBOUNDED_RAW_LINE'
    if tail:lines(tail)
    return dict(raw_bytes=count,raw_sha256=digest.hexdigest(),application_rows=rows,
                target_cycles=targets[-1] if targets else None,faults=faults)

def application_rows(run):
    return RAW[str(run)]['application_rows']

def workload(name, root, run, result, plan, binding, full):
    check(plan['binary'], binding['binary_sha256'], name+' executable binding')
    elf = next(a.split('=', 1)[1] for a in binding['args'] if a.startswith('+prog0='))
    check(elf, result['elf_sha256'], name+' ELF binding')
    assert result['functional_baseline'] == BASE and not result['fpga_access']
    assert binding['functional_baseline'] == BASE and not binding['fpga_access']
    joined, events = strict_package_join(run, name)
    rows = application_rows(run)
    reference_rows = full['application_rows'] if name == 'canneal' else result['application_rows']
    assert rows == reference_rows, ('APPLICATION_RAW_ROWS_DIFFER', name)
    roi = next(re.search(r'start=(\d+) stop=(\d+) cycles=(\d+)', r) for r in rows if '[ROI]' in r)
    app = next(re.search(r'cycles=(\d+) instret=(\d+)', r) for r in rows if '[APP]' in r)
    start, end, cycles = map(int, roi.groups())
    assert end-start == cycles == int(app[1])
    output = next(r for r in rows if '[OUTPUT]' in r)
    assert 'verified=1' in output and any('[END]' in r and 'status=PASS' in r for r in rows)
    allocations = [e for e in events if e['kind'] == 'BOOM_ALLOC']
    accepted = [e for e in events if e['kind'] == 'BOOM_RESULT_ACCEPTED']
    last = max(accepted, key=lambda e:e['boom_csr_cycle'])
    pending_stop = sum(e['boom_csr_cycle'] <= end for e in allocations) - sum(e['boom_csr_cycle'] <= end for e in accepted)
    assert pending_stop >= 0
    wall = full['host_wall_seconds'] if name == 'canneal' else result['host_wall_seconds']
    total = full['target_cycles'] if name == 'canneal' else result['total_fastest_target_cycles']
    faults = full['faults'] if name == 'canneal' else result['faults']
    assert not faults
    record = dict(benchmark=name, data_kind='CPU_FULL_SYSTEM_GOLDENGATE_METASIMULATION',
        status='PASS_INDEPENDENT_HASH_RAW_OUTPUT_AND_STRICT_FINITE_PACKAGE_AUDIT',
        functional_baseline=BASE, source_id=result['source_id'], elf=elf, elf_sha256=sha(elf),
        model_binary=plan['binary'], model_sha256=sha(plan['binary']),
        input_profile='original baremetal project64; one thread; complete protected kernel',
        roi_cycles=cycles, roi_instructions=int(app[2]), roi_start_csr=start, roi_end_csr=end,
        total_fastest_target_cycles=total, host_wall_seconds=wall,
        simulated_target_cycles_per_host_second=total/wall,
        allocated_packages=joined['allocations'], full_compare_results=joined['full_compare_local_results'],
        boom_accepted_pass=joined['boom_pass_accepted'], pending_at_roi_stop=pending_stop,
        pending_at_observation_end=0, last_result_accepted_csr=last['boom_csr_cycle'],
        checker_acceptance_tail_csr_cycles=max(0, last['boom_csr_cycle']-end),
        output=output, faults=0, fpga_access=False, strict_checker_execution_latency_measured=False,
        raw_prints=str(run/'rtl-prints-0'), source_result=str(root/('full-result.json' if name=='canneal' else 'result.json')))
    assert record['checker_acceptance_tail_csr_cycles'] >= 0
    if name == 'blackscholes':
        assert cycles == result['roi_cycles'] and int(app[2]) == result['roi_instructions']
        assert record['checker_acceptance_tail_csr_cycles'] == result['checker_result_acceptance_tail_after_roi_csr_cycles']
    return record

def broker(name, expected_status='COMPLETE'):
    p = D/'unattended-opt4/jobs'/name/'state.json'
    j = read(p)
    assert j['status'] == expected_status and j['returncode'] == 0
    assert not j.get('missing_outputs')
    for q, h in j['outputs'].items():
        check(q, h, name+' broker completed output')
    # Scope and immutable request inputs must still match, regardless of stale
    # process identity fields left by a completed wrapper.
    assert j['scope']['baseline'] == BASE
    for q, h in j.get('input_sha256', {}).items():
        check(q, h, name+' broker immutable input')
    return dict(path=str(p), sha256=sha(p), status=j['status'], returncode=j['returncode'],
                started_utc=j.get('started_utc'), ended_utc=j.get('ended_utc'),
                output_count=len(j['outputs']), input_count=len(j.get('input_sha256', {})))

def parse_summary(path, prefix):
    # Reads only a small raw component log; full app output is streamed elsewhere.
    text = Path(path).read_text()
    lines = [r for r in text.splitlines() if r.startswith(prefix+' ')]
    assert len(lines) == 1, ('MISSING_OR_DUPLICATE_SUMMARY', str(path))
    fields = {}
    for item in lines[0].split()[1:]:
        k, v = item.split('=', 1)
        fields[k] = float(v) if '.' in v else int(v)
    return fields, text

def admission_audit(proof):
    a = read(GG/'board-admission-ready.json')
    assert a['status'] == 'READY_FOR_CONTROLLED_21_ONLY_BOARD_ADMISSION_NOT_EXECUTED'
    assert a['board_allowlist'] == ['0000:21:00.0'] and not a['fpga_access']
    assert a['functional_baseline'] == BASE and not a['complete_opt4']
    assert a['required_driver_args'] == ['+svb-force-all-inputs', '+domain=0000', '+bus=21',
        '+device=00', '+function=0', '+bar=0', '+svb-trace='+a['trace']]
    assert a['expected_summary'] == proof['positive']['summary']
    check(a['cpu_proof'], a['cpu_proof_sha256'], 'application FPGA follower CPU proof')
    check(a['driver'], a['driver_sha256'], 'application guarded21 driver')
    check(a['trace'], a['trace_sha256'], 'application full trace')
    prep = D/'cycleprecise-frozen-svb-fpga-r2-20261111'
    check(prep/'goldengate/FireSim-generated.sv', a['host_rtl_sha256'], 'component exact host RTL')
    check(prep/'goldengate/FireSim-generated.const.h', a['control_header_sha256'], 'component exact driver header ABI')
    plan = read(G2/'plan.json')
    assert plan['board_allowlist'] == ['0000:21:00.0'] and not plan['target_or_model_modified']
    assert plan['functional_baseline'] == BASE and plan['source_id'] == a['source_id']
    for q,h in plan['inputs'].items():
        check(q,h,'original GG replay immutable model/adapter input')
    followers=[]
    for variant in ['r1','recovered-r1']:
        root = D/('cycleprecise-original-svb-application-onboard-'+variant+'-20261111')
        state = read(root/'state.json')
        route = W/'routes'/('svb-application-onboard-'+variant+'-20261111')
        pins = read(route/'inputs.json')
        assert pins['board_allowlist']==['0000:21:00.0'] and pins['no_deployment_operations']
        for q,h in pins['files'].items():
            check(q,h,'live follower immutable source binding')
        # Pure /proc identity check; no card mapping or driver access.
        pid=state['pid']; proc=Path('/proc')/str(pid)
        live=False
        try:
            stat= (proc/'stat').read_text().split(') ',1)[1].split()
            live=(stat[19]==str(state['start_ticks']) and stat[0] not in ['Z','X'] and
                  Path('/proc/sys/kernel/random/boot_id').read_text().strip()==state['host_boot_id'])
        except FileNotFoundError:
            pass
        followers.append(dict(state=str(root/'state.json'), status=state['status'],
                              updated_utc=state.get('updated_utc'), pid=pid,
                              exact_process_identity_live=live, no_deployment_operations=state['deployment_operations']==[],
                              fpga_access=state['fpga_access']))
    return dict(status='CPU_PROOF_TRACE_MODEL_DRIVER_ADMISSION_SCHEMA_HASH_PASS_NO_DEVICE_ACCESS',
                required_board='0000:21:00.0', trace_records=a['trace_records'],
                driver_args=a['required_driver_args'], followers=followers,
                remaining_gate='Existing certified component deployment + 42291-value directed hardware proof and safe21 lock boundary; parent owns board validation',
                fpga_access=False)

def main():
    start=time.monotonic()
    O.mkdir(exist_ok=True)
    assert not (O/'summary.json').exists(), 'ADOPT_COMPLETE_AUDIT_NO_REWRITE'
    can=read(CAN/'full-result.json'); bs=read(BS/'result.json')
    sv=read(SV/'full-result.json'); gg=read(GG/'full-result.json')
    # Explicitly distinguish broker completion from per-sample completion marker.
    brokers=[]
    for name in ['full-gg-external-observer-r5-full-8491167d',
                 'full-svb-binary-replay-r1-full-8491167d',
                 'full-svb-gg-stream-replay-r3-full-8491167d',
                 'full-gg-blackscholes-observed-r1-8491167d']:
        brokers.append(broker(name))
    complete=read(BS/'complete.json')
    for key,name in [('result_sha256','result.json'),('binding_sha256','binding.json'),
                     ('stdout_integrity_sha256','stdout-integrity.json'),('strict_acceptance_sha256','strict-acceptance.json')]:
        check(BS/name,complete[key],'Blackscholes atomic complete marker')
    check(BP/'plan.json',complete['plan_sha256'],'Blackscholes atomic plan binding')
    check(read(BP/'plan.json')['elf'],complete['elf_sha256'],'Blackscholes atomic ELF binding')
    check(CP/'plan.json',can['plan_sha256'],'Canneal full-result plan binding')
    for q,h in can['full']['files'].items():
        check(q,h,'Canneal completed full run raw artifact')
    for candidate in [CP,BP,SP,GP]:
        plan=read(candidate/'plan.json')
        for q,h in plan.get('external_inputs',plan.get('inputs',{})).items():
            check(q,h,'completed plan immutable input')
    # Recompute lossless entire Blackscholes raw stdout+stderr, bounded memory.
    integrity=read(BS/'stdout-integrity.json')
    check(BS/'host-complete.log.gz',integrity['gzip_sha256'],'Blackscholes compressed raw stream')
    with gzip.open(BS/'host-complete.log.gz','rb') as f:
        scanned=rawscan(f)
    RAW[str(BS)]=scanned
    assert scanned['raw_bytes']==integrity['raw_bytes'] and scanned['raw_sha256']==integrity['raw_sha256'] and integrity['complete_stream_eof']
    assert scanned['target_cycles']==bs['total_fastest_target_cycles'] and not scanned['faults']
    save('blackscholes-lossless-stdout-verification.json',dict(status='PASS_COMPLETE_GZIP_EOF_RAW_BYTES_AND_SHA256',
         **scanned,gzip_bytes=(BS/'host-complete.log.gz').stat().st_size,
         gzip_sha256=sha(BS/'host-complete.log.gz'),fpga_access=False))
    with (RUN/'host.log').open('rb') as f:
        RAW[str(RUN)]=rawscan(f)
    assert RAW[str(RUN)]['raw_sha256']==sha(RUN/'host.log') and not RAW[str(RUN)]['faults']
    assert RAW[str(RUN)]['target_cycles']==can['full']['target_cycles']
    workloads=[workload('canneal',CAN,RUN,can,read(CP/'plan.json'),read(RUN/'binding.json'),can['full']),
               workload('blackscholes',BS,BS,bs,read(BP/'plan.json'),read(BS/'binding.json'),bs)]
    # Current exact GG capture must equal the original model run, including prints.
    original=D/'cycleprecise-frozen-full-metasim-sample-r1-20261111'
    for name in ['rtl-prints-0','rtl-prints-1']:
        check(original/name,sha(RUN/name),'Canneal original model vs observer identical print stream')
    ref=read(original/'result.json')
    with (original/'host.log').open('rb') as f:
        original_raw=rawscan(f)
    assert original_raw['application_rows']==RAW[str(RUN)]['application_rows']
    assert original_raw['target_cycles']==can['full']['target_cycles'] and not original_raw['faults']
    assert can['original_prints_and_application_and_target_count_match']
    assert ref['returncode']==0 and ref['output_correctness'] and ref['stop_cause'] is None
    save('canneal-observer-original-raw-parity.json',dict(status='PASS_SAME_ELF_COMPLETE_RAW_APPLICATION_PRINT_STREAMS_AND_TARGET_CYCLES',
         original_raw=original_raw,observer_raw=RAW[str(RUN)],fpga_access=False))
    # Independently revalidate complete binary structure and all event lifetimes.
    validator=load_module('binary_structure_audit',CP/'validate_binary.py')
    binary=validator.validate(CP/'binary-layout.json',RUN/'external-events.jsonl.svb-full.bin')
    assert binary==read(CAN/'binary-integrity.json')
    save('binary-integrity-recomputed.json',binary)
    analyzer=load_module('svb_lifetimes_audit',CP/'analyze_svb_latency.py')
    lifetimes=analyzer.analyze(RUN,CP/'binary-layout.json')
    # JSON normalizes integer histogram keys and tuple identities; compare that
    # serialization rather than Python tuple-vs-list implementation details.
    assert json.loads(json.dumps(lifetimes))==read(CAN/'svb-lifetimes.json')
    save('svb-lifetimes-recomputed.json',lifetimes)
    latencies=[];histrows=[];liferows=[]
    for name,m in lifetimes['metrics'].items():
        latencies.append(dict(metric=name,**{k:v for k,v in m.items() if k!='histogram'}))
        histrows.extend(dict(metric=name,cycles=k,count=v) for k,v in m['histogram'].items())
    for row in lifetimes['sample_lifetimes']:
        ident=json.dumps(row['identity'],separators=(',',':')).encode()
        liferows.append({**{k:v for k,v in row.items() if k!='identity'},'identity_sha256':hashlib.sha256(ident).hexdigest()})
    csvwrite('svb-latency.csv',latencies);csvwrite('svb-latency-histogram.csv',histrows)
    csvwrite('svb-lifetimes.csv',liferows)
    occ={int(k):v for k,v in lifetimes['occupancy_histogram_target_cycles'].items()}
    assert sum(occ.values())==binary['records']-binary['counts']['reset_cycles']
    first=min(r['capture_target_cycle'] for r in lifetimes['sample_lifetimes'])
    last=max(r['ack_target_cycle'] for r in lifetimes['sample_lifetimes'])
    n=lifetimes['complete_ack_lifetimes']
    rates=dict(data_kind='CPU_FULL_GG_CAPTURE_IDENTICALLY_REPLAYED_IN_ORIGINAL_SVB',
        completed_transactions=n, nonreset_observation_cycles=sum(occ.values()),
        observed_completed_per_nonreset_target_cycle=n/sum(occ.values()),
        first_capture_tick=first,last_ack_tick=last,inclusive_activity_window_cycles=last-first+1,
        completed_per_active_window_target_cycle=n/(last-first+1),
        nonzero_occupancy_cycles=sum(v for k,v in occ.items() if k),
        mean_occupancy_all_nonreset_cycles=sum(k*v for k,v in occ.items())/sum(occ.values()),
        maximum_occupancy=max(occ),full_occupancy_cycles=occ.get(32,0),
        scope='Offered workload observed rate including original target idle/backpressure; not saturated SVB capacity or FPGA throughput',fpga_access=False)
    save('svb-observed-rates.json',rates)
    # Replay receipt chain and actual positive/negative output, independent of status.
    check(CAN/'full-result.json',sv['original_full_metasim_result_sha256'],'standalone predecessor result')
    check(SP/'replay',sv['binary_sha256'],'standalone target executable')
    check(SP/'plan.json',sv['plan_sha256'],'standalone target plan')
    check(CAN/'full-result.json',gg['observer_result_sha256'],'GG observer predecessor')
    check(SV/'full-result.json',gg['standalone_result_sha256'],'GG standalone predecessor')
    check(GG/'strict-checker-join.json',gg['strict_checker_join_sha256'],'GG strict package admission')
    check(D/'cycleprecise-original-svb-gg-stream-replay-r2-20261111/build-receipt.json',gg['build_receipt_sha256'],'GG adapter build receipt')
    replayrows=[]
    for label,result,kind in [('standalone',sv,'CPU_ORIGINAL_TARGET_SVB_RTL'),('goldengate',gg,'CPU_GOLDENGATE_SVB_COMPONENT')]:
        assert result['passed'] and not result['fpga_access']
        for polarity in ['positive','negative']:
            r=result[polarity];check(r['log'],r['log_sha256'],label+' '+polarity+' raw replay log')
        if label=='standalone':
            positive,pt=parse_summary(result['positive']['log'],'REPLAY_SUMMARY')
            negative,nt=parse_summary(result['negative']['log'],'REPLAY_SUMMARY')
            assert positive['cycles']==binary['records'] and positive['mismatches']==0 and positive['mutation_applied']==0
            assert positive['defined_output_word_checks']==19698670 and negative['mismatches']==1 and negative['mutation_applied']==1
            assert 'MISMATCH tick=1092660 port=io_promote_bits_data_0[0]' in nt
            assert 'expected=d7700b1e actual=d7700b1f' in nt and result['actual_payload_mutation_rejected']
            total=positive['cycles'];checks=positive['defined_output_word_checks']
        else:
            positive,pt=parse_summary(result['positive']['log'],'SVB_GG_STREAM_SUMMARY')
            assert positive==result['positive']['summary']
            nt=Path(result['negative']['log']).read_text()
            assert '[SVBProbe]PASS Test' in pt and '[SVBProbe]FAIL Test' in nt
            assert result['negative']['returncode']==1 and result['real_application_payload_mutation_rejected']
            assert 'SVB_GG_STREAM_MISMATCH' in nt and 'io_promote_bits_data_0' in nt
            assert positive['records']==binary['records'] and positive['mismatches']==0 and positive['input_cache_enabled']==0
            total=positive['records'];checks=positive['defined_output_word_checks']
        replayrows.append(dict(replay=label,data_kind=kind,records=total,defined_output_word_checks=checks,
            positive_mismatches=0,positive_returncode=result['positive']['returncode'],
            negative_payload_rejected=True,negative_returncode=result['negative']['returncode'],
            host_wall_seconds=result['positive']['host_wall_seconds'],
            replayed_target_edges_per_host_second=total/result['positive']['host_wall_seconds'],
            fpga_access=False,scope='Finite original complete target-edge input/output replay; host harness rate, not SVB autonomous throughput'))
    csvwrite('workloads.csv',workloads);csvwrite('replays.csv',replayrows)
    admission=admission_audit(gg);save('application-follower-admission-audit.json',admission)
    save('evidence-verification.json',dict(status='PASS_ALL_RECORDED_HASH_AND_IDENTITY_CHECKS',
         verifications=VERIFICATIONS,files={str(p):v for p,v in CACHE.items()},
         brokers=brokers,fpga_access=False))
    summary=dict(schema='ec-completed-evidence-audit/1',status='PASS_COMPLETED_CPU_EVIDENCE_INDEPENDENT_AUDIT',
        functional_baseline=BASE,workloads=workloads,replays=replayrows,
        svb_latencies=latencies,svb_observed_rates=rates,application_admission=admission,
        broker_completed_jobs=len(brokers),hash_checks=len(VERIFICATIONS),distinct_files_hashed=len(CACHE),
        existing_complete_markers={str(root): (root/'complete.json').exists() for root in [CAN,BS,SV,GG]},
        fpga_access=False,formal_fpga_samples=0,
        limitations=['All evidence in this audit is CPU RTL/metasimulation, not FPGA measurement',
          'No strict checkerDone-minus-same-package BOOMexecutionDone measurement',
          'No architectural rollback/restart verification',
          'Plain target +dramsim differs from GG FASED timing; no cross-model cycle equivalence or slowdown claim',
          'Finite exact replay is not universal whole-system formal equivalence',
          'SVB ACK is ownership/writeback completion, not checker completion'],
        host_wall_seconds=time.monotonic()-start,completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    save('summary.json',summary)
    save('complete.json',dict(summary_sha256=sha(O/'summary.json'),
        evidence_verification_sha256=sha(O/'evidence-verification.json'),
        audit_source_sha256=sha(__file__),fpga_access=False))
    print(json.dumps(dict(status=summary['status'],output=str(O),workloads=[dict(benchmark=r['benchmark'],roi_cycles=r['roi_cycles'],
        instructions=r['roi_instructions'],accepted=r['boom_accepted_pass'],tail=r['checker_acceptance_tail_csr_cycles']) for r in workloads],
        hash_checks=len(VERIFICATIONS),svb_complete_lifetimes=n,fpga_access=False),indent=2))

if __name__=='__main__':
    try:
        main()
    except BaseException as e:
        O.mkdir(exist_ok=True)
        p=O/('failed-'+str(os.getpid())+'.json')
        p.write_text(json.dumps(dict(status='AUDIT_FAILED_WITH_EVIDENCE',error=repr(e),
            verifications=VERIFICATIONS,fpga_access=False),indent=2)+'\n')
        raise
