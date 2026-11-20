#!/usr/bin/python3
"""Record this round's scope, actual outputs, and adopted jobs without changing them."""
from pathlib import Path
import datetime, hashlib, json, os

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
O=D/'build-logs/Opt4-round40-two-route-evidence-v1-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'

def read(p):return json.loads(Path(p).read_text())
def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
    return h.hexdigest()
def save(name,j):
    with (O/name).open('x') as f:
        json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
def live(j):
    try:
        if j['host_boot_id']!=Path('/proc/sys/kernel/random/boot_id').read_text().strip():return False
        f=Path(f"/proc/{j['pid']}/stat").read_text().rsplit(')',1)[1].split()
        return f[19]==str(j['start_ticks']) and f[0]!='Z'
    except (KeyError,FileNotFoundError):return False

def main():
    p=read(U/'campaign-policy.json')
    assert p['functional_baseline_commit']==BASE and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist']==['0000:21:00.0']
    O.mkdir(exist_ok=False)
    now=datetime.datetime.now(datetime.timezone.utc)
    save('policy-observed.json',dict(utc=now.isoformat(),sha256=sha(U/'campaign-policy.json'),
        capacity=p['latest_postopt_capacity'],scope=p['scope_reminder']))
    jobs={}
    for v in ['v1','v2','v3','v4']:
        state_path=D/f'Opt4-mt-host-continue-round40-{v}-state.json'
        if not state_path.exists():continue
        state=read(state_path);b=state_path.parent/f'build-logs/Opt4-mt-host-continue-round40-{v}-20261111'
        broker=U/f'request-results/mt-host-continue-r40-{v}-8491167d.json'
        j=dict(state=state,state_path=str(state_path),controller_live=live(state),
               child_live=live(state.get('child',{})),broker=read(broker))
        for n in ['result.json','failure.json','compile-receipt.json','continue-receipt.json']:
            f=b/n
            if f.exists():j[n]=dict(path=str(f),sha256=sha(f),value=read(f))
        jobs[v]=j
    assert jobs and all(j['broker']['status'] in ['STARTED','ADOPTED'] for j in jobs.values())
    save('host-continuation-jobs.json',jobs)
    last_version=list(jobs)[-1];last=jobs[last_version];last_state=last['state']
    latest_output=D/f'build-logs/Opt4-mt-host-continue-round40-{last_version}-20261111'
    inventory=latest_output/'goldengate/mt-singleton-inventory.txt'
    milestone={}
    if inventory.exists():
        inventory_text=inventory.read_text()
        assert inventory_text.count(' instances=1')==5
        assert 'existing_top_statements_and_module_definitions_identical=true' in inventory_text
        assert 'added_definitions_unreachable=true' in inventory_text
        milestone=dict(path=str(inventory),sha256=sha(inventory),
            exact_singletons=5,existing_module_and_top_statement_identity_pass=True,
            added_definitions_unreachable=True,full_host_runtime_equivalence=False)
        save('singleton-mt-reachability-proof.json',milestone)
    entry=D/'build-logs/Opt4-mcrams-dcache-entry-r5-20261111/result.json'
    e=read(entry);a=e['results']['PlainConfig'];b=e['results']['MCConfig']
    assert e['status']=='PASS_REAL_DCACHE_MEMORY_INTERFACE_SAME_TARGET_GG_PLAIN_AND_MCRAMS_NOT_FULL_DCACHE'
    assert e['functional_baseline_commit']==BASE and e['hardware_commit'].startswith('3656aec4')
    assert a['metrics']['checked_values']==b['metrics']['checked_values']==178857
    assert a['metrics']['event_digest']==b['metrics']['event_digest']
    assert a['negative_rejected'] and b['negative_rejected']
    assert a['target_sha256']==b['target_sha256']
    save('adopted-dcache-entry-boundary.json',dict(path=str(entry),sha256=sha(entry),
        results=e['results'],scope='Reset-masked 512x81 memory with 35 asynchronous readers and 35 edge-captured observations; 2,569 finite test cycles. Not complete DCache or universal equivalence.',
        repeated=False,new_module_map=False,whole_area_gain_claimed=False))
    snap=read(U/'snapshot.json')
    names=['Opt4-fit-update-share-svb-cad-state.json','Opt4-fit-dcache-field-read-full-map-r2-state.json',
           'Opt4-fit-dcache-fieldbank-full-map-r4-state.json','Opt4-fit-dcache-full-pair-r2-state.json',
           'Opt4-fit-field-address-cycle-consumer-r3-state.json','Opt4-fit-owner-update-sequence-system-r3-state.json',
           'Opt4-fit-address-group8-cec-r1-state.json','Opt4-fit-address-update-sequence-r1-state.json']
    save('route-b-adoption.json',dict(snapshot_utc=snap['utc'],states={n:snap['states'][n] for n in names if n in snap['states']},
        new_whole_synthesis=False,live_inputs_changed=False,signals_sent=False))
    route_a={}
    routes=p['parallel_evidence_routes']['route_a']
    paths={k:Path(routes[k]) for k in ['original_svb_component_fpga_preparation','original_svb_component_21_follower']}
    paths.update(component_cad=D/'cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json',
        mcrams_full_parity=D/'Opt4-route-a-full-mcrams-parity-round38-v1-state.json',
        full_payload_capture=D/'Opt4-full-gg-external-observer-r3-state.json')
    for key,f in paths.items():
        j=read(f);route_a[key]=dict(path=str(f),state=j,controller_live=live(j))
        child=j.get('child',{})
        if j.get('child_pid'):child=dict(pid=j['child_pid'],start_ticks=j['child_start_ticks'],host_boot_id=j['host_boot_id'])
        route_a[key]['child_live']=live(child)
    save('route-a-adoption.json',route_a)
    sprint=read(D/'opt4-sprint-24h-20261111/latest.json')
    hours=(datetime.datetime.fromisoformat(sprint['deadline_utc'])-now).total_seconds()/3600
    save('resource-and-deadline.json',dict(utc=now.isoformat(),snapshot_utc=snap['utc'],deadline_utc=sprint['deadline_utc'],
        remaining_hours=hours,resources={k:snap[k] for k in ['available_memory_gib','free_disk_gib','loadavg']},
        full_opt4_risk='HIGH: latest completed whole postopt exceeds U280 by 1,543,702 LUT.',
        component_risk='Independent component routing/certification still pending; capacity does not establish clock coverage/timing/DRC.',
        formal_opt4_fpga_sample=False,worker_fpga_io=False))
    report=f'''Round 40 continued the frozen MTModels+MCRams host compiler from the hash-bound round-39 v5 checkpoint. Latest version {last_version}: {last_state['status']}.

Each version uses an independent broker request, controller, immutable capsule and output directory. Version v1 stopped during standalone Scala compilation because of an unqualified FIRRTL class and protected emission API. Version v2 compiled, then correctly refused the overly strict unchanged-circuit serialization guard: the original MT pass creates unused one-thread definitions even for singleton classes. Version v3 proved each of the five exact classes occurs once, every existing non-top module remains AST-identical, and every existing top statement remains AST-identical modulo transparent Block/EmptyStmt wrappers, but stopped at an unnecessary name-pattern guard on added unused helper classes. Version v4 replaces that guard with complete module reachability from the original top, rejecting any added reachable definition while retaining all old-definition and top-statement identity checks. Actual singleton/reachability proof available: {bool(milestone)}. No specialized Rocket sharing is enabled or inferred. Original compiler libraries, target source, live inputs and previous failures are preserved.

The continuation runs the original remaining FAME fanout, MT, RAM wrapper, SimulationMapping, host specialization and backend/emission passes. Host RTL output, if produced, still requires complete ABI/blackbox validation and same-target runtime parity before any area or deployment admission. No whole-DUT FIT or universal equivalence claim follows from a compiler pass.

Adopted the newly completed 3656aec4-derived DCache-entry memory test: the same target FIR/annotations under Plain and MCRams matched 178,857 defined 81-bit values in 2,569 test cycles, both rejected a negative mutation. This isolates one reset-masked 512x81/35-read memory interface with edge-captured observations. It is not complete-DCache equivalence; 973 undefined values were explicitly skipped. Peek/poke-inclusive FMR172.016 and CPU throughput336.76/260.328 cycles/s are boundary measurements, not full application or FPGA performance. The test was not rerun and no module/whole savings are inferred.

Existing full MCRams Canneal parity, full application payload observer, original SVB component routing and its 21-only certified follower were adopted by PID/start/boot identity. Observer logs are still in progress and are not promoted to complete application trace replay. Component capacity200,342 LUT remains component-only; physical target-clock coverage/timing/DRC and independent certification are mandatory. No worker FPGA I/O occurred.

Route B remains active without duplicate jobs or live input changes. 9ae completed NOT FIT:2,847,382 LUT/90,740 CARRY8/195 DSP, excess1,543,702 LUT. e0 and full-DCache maps/consumers continue; e211 complete-address761,398 LUT is module-only and cannot be subtracted as an additive whole gain. Latest source-bound resources and process identities are saved in route-b-adoption.json.

Sprint deadline{sprint['deadline_utc']}; {hours:.2f} hours remain at seal. Full Opt4 FIT deadline risk is HIGH. Native remains paused. Only a certified valid formal Opt4 FPGA sample satisfies the objective; none is claimed. Next: adopt the exact successful continuation checkpoint or preserve the failed stage and recover independently, then validate complete host ABI and same-target parity; retain all live CAD/module/route-A jobs.
'''
    (O/'REPORT.md').write_text(report)
    changed=[]
    for v in jobs:
        c=W/f'candidates/mt-host-continue-round40-{v}-20261111'
        changed += [str(f) for f in c.rglob('*') if f.is_file()]
    changed += [str(Path(__file__).resolve())]
    changed += [str(U/f'requests/mt-host-continue-r40-{v}-8491167d.json') for v in jobs]
    changed += [str(f) for f in O.iterdir() if f.is_file()]
    save('changed-files.json',sorted(changed))
    launched=[j['broker']['unit']+': '+j['state']['status'] for j in jobs.values()]
    outcome='WAITING_ACTIVE_JOB' if last['controller_live'] else 'PROGRESS'
    result=dict(outcome=outcome,summary='Round 40 advanced isolated frozen host compiler continuation; full Opt4 remains NOT FIT and no formal FPGA sample is claimed.',
        changed_files=sorted(changed)+[str(O/'changed-files.json'),str(O/'round40-result.json')],
        evidence=[str(O/'REPORT.md'),str(O/'host-continuation-jobs.json'),str(O/'adopted-dcache-entry-boundary.json'),str(O/'route-a-adoption.json'),str(O/'route-b-adoption.json')],
        launched_jobs=launched,next_action='Adopt the continuation output or recover its exact failed stage; authenticate host ABI/blackbox closure and same-target parity. Preserve all live route A/B jobs. FIT advances through actual clock coverage/timing/DRC/certification to the existing 21-only runtime.',retry_after_seconds=600)
    save('round40-result.json',result)
    print(json.dumps(dict(report=str(O/'REPORT.md'),result=str(O/'round40-result.json'),latest_status=last_state['status'])))

if __name__=='__main__':main()
