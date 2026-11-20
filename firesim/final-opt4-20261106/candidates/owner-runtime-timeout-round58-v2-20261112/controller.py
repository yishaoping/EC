#!/usr/bin/python3
"""Evidence-gated timeout recovery; same binary/target, successful Plain reused."""
import argparse
import fcntl
import hashlib
import importlib.util
import json
import math
import os
from pathlib import Path
import re
import resource
import signal
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
OLD = D/'cycleprecise-owner-pair-runtime-r1-20261111'
OLD_STATE = D/'Opt4-mcrams-owner-pair-runtime-r1-state.json'
OLD_UNIT = 'ec-opt4-auto-owner-pair-runtime-r1-3656aec4.service'
O = D/'build-logs/Opt4-owner-runtime-timeout-round58-v2-20261112'
S = D/'Opt4-owner-runtime-timeout-round58-v2-state.json'
HELPER = W/'candidates/mcrams-owner-pair-metasim-r1-20261111/controller.py'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'owner-runtime-timeout-r58-v2-3656aec4'
V1 = D/'build-logs/Opt4-owner-runtime-timeout-round58-v1-20261112'
V1_STATE = D/'Opt4-owner-runtime-timeout-round58-v1-state.json'
V1_UNIT = 'ec-opt4-auto-owner-runtime-timeout-r58-v1-3656aec4.service'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def write_new(path, obj):
    with Path(path).open('x') as f:
        json.dump(obj, f, indent=2, sort_keys=True); f.write('\n')
        f.flush(); os.fsync(f.fileno())


def empty_unit(unit_name):
    command = ['systemctl','show',unit_name,'-p','ActiveState','-p','SubState','-p','MainPID','-p','ControlGroup']
    output = subprocess.run(command, capture_output=True, text=True, check=True).stdout
    unit = dict(line.split('=', 1) for line in output.splitlines() if '=' in line)
    assert unit['ActiveState'] in ['inactive','failed'] and unit['MainPID'] == '0', unit
    roots = [Path('/sys/fs/cgroup'), Path('/sys/fs/cgroup/systemd')]
    groups = {root/'system.slice'/unit_name for root in roots}
    if unit.get('ControlGroup'):
        assert '..' not in Path(unit['ControlGroup']).parts
        groups.update(root/unit['ControlGroup'].lstrip('/') for root in roots)
    checked = []
    for group in sorted(groups):
        leaves = sorted(group.rglob('cgroup.procs')) if group.exists() else []
        for leaf in leaves:
            assert not leaf.read_text().strip(), ('nonempty predecessor cgroup', str(leaf))
        checked.append(dict(path=str(group), exists=group.exists(), process_files=len(leaves)))
    return dict(unit_name=unit_name, unit=unit, exact_cgroups=checked)


def exited():
    old = read(OLD_STATE)
    assert old['status'] == 'FAILED_FINITE_CAPTURED_PARITY_PRESERVED' and old['stop_cause'] == 'HOST_TIMEOUT'
    prior = read(V1_STATE)
    assert prior['status'] == 'FAILED_WITH_EVIDENCE' and read(V1/'prefix-audit.json')['status']=='FAIL_LOG_PREFIX_MISMATCH_NO_RUNTIME'
    for proc in [old, old.get('child', {}), prior, prior.get('child', {}),
        dict(pid=2086926, start_ticks='22779600', host_boot_id=old['host_boot_id'])]:
        assert not live(proc), ('predecessor still live', proc)
    return dict(original=empty_unit(OLD_UNIT), v1=empty_unit(V1_UNIT))


def cpu_check():
    for name, row in read(U/'snapshot.json')['states'].items():
        if not row.get('identity_live'): continue
        for proc in [row, row.get('child',{}), row.get('stage_process',{}), *row.get('worker_processes',[])]:
            if live(proc) and proc['pid'] != os.getpid():
                affinity = os.sched_getaffinity(proc['pid'])
                assert len(affinity) > 8 or not ({250,251} & affinity), ('CPU conflict', name, proc['pid'])
                if re.search(r'canneal|full-gg-external-observer|full-mcrams-parity|owner-pair-runtime|frozen-full-metasim-sample', name, re.I):
                    raise AssertionError(('another full Canneal live',name,proc['pid']))


def tail_cycle(path):
    with path.open('rb') as f:
        f.seek(max(0, path.stat().st_size-65536))
        values = re.findall(rb'\bcycle=([0-9a-f]{16})\b', f.read())
    assert values
    return max(int(x,16) for x in values)


def prepare():
    policy()
    assert not (C/'plan.json').exists() and not O.exists()
    old, result = read(OLD/'plan.json'), read(OLD/'result.json')
    assert old['functional_baseline'] == result['functional_baseline'] == BASE
    assert result['results']['Plain']['output_correctness'] and not result['results']['Plain']['faults']
    assert result['results']['MCRams']['stop_cause'] == 'HOST_TIMEOUT' and not result['results']['MCRams']['faults']
    old_guard = exited(); cpu_check()
    elapsed = result['results']['MCRams']['host_wall_seconds']
    progress = tail_cycle(OLD/'run-MCRams.log')
    completed = [int(x.split(':',1)[1]) for x in result['results']['Plain']['host_metrics'] if x.startswith('Target Cycles Emulated:')]
    assert len(completed) == 1 and 0 < progress < completed[0]
    projected = elapsed*completed[0]/progress
    budget = math.ceil(projected*1.6/60)*60
    assert old['host_timeout_seconds'] < budget <= 9*3600, ('budget requires another review', budget)
    originals = dict(old['inputs'])
    for leaf in ['plan.json','result.json','receipts/run-Plain.json','receipts/run-MCRams.json','Plain/run-result.json','MCRams/run-result.json']:
        path = OLD/leaf; originals[str(path)] = sha(path)
    for leaf, digest in result['results']['Plain']['captured_print_streams'].items():
        path = OLD/'Plain/run'/leaf
        assert sha(path) == digest
        originals[str(path)] = digest
    for leaf in ['prefix-audit.json','failure.json']:
        path=V1/leaf; originals[str(path)]=sha(path)
    inputs = {str(p):sha(p) for p in [C/'controller.py', C/'README.md', HELPER, W/'scripts/opt4_unattended_common.py']}
    plan = dict(schema='ec-owner-timeout-measured-recovery/1',functional_baseline=BASE,
        hardware_commit=old['derived_hardware'],inputs=inputs,originals=originals,
        prior_guard=old_guard,prior_progress_cycle=progress,prior_host_seconds=elapsed,
        expected_complete_cycles=completed[0],measured_projected_seconds=projected,
        host_timeout_seconds=budget,prior_host_timeout_seconds=old['host_timeout_seconds'],
        reference_plan=str(OLD/'plan.json'),target_changed=False,no_compile=True,
        cpus=[250,251],fpga_access=False,whole_fit=False,production_admission=False)
    write_new(C/'plan.json',plan)
    request = dict(action='cpu_job',spec=dict(name=NAME,kind='module',cwd=str(C),
        argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],
        inputs={**inputs,str(C/'plan.json'):sha(C/'plan.json')},
        outputs=[str(O/'complete.json')],checkpoints=[str(S)]))
    write_new(C/'request.json',request)
    print(json.dumps(dict(status='PREPARED_NOT_SUBMITTED',progress=progress,projected_seconds=projected,host_timeout_seconds=budget)))


def prefix_audit():
    """Keep exact bytes within each independently drained observation stream."""
    mc, plain = OLD/'run-MCRams.log', OLD/'run-Plain.log'
    length = mc.stat().st_size
    with mc.open('rb') as f:
        f.seek(max(0,length-65536)); tail = f.read()
    complete = length-(len(tail)-tail.rfind(b'\n')-1)
    assert complete > 0
    hm, hp = hashlib.sha256(), hashlib.sha256()
    first = None
    uart_mc,uart_plain=[],[]
    uart_pattern=re.compile(rb'^\[(?:INIT|ROI|OUTPUT|APP|COMPUTATION|END)\]')
    counts=dict(mc_raw_lines=0,plain_raw_lines=0,compared_non_uart_lines=0)
    def lines(stream, digest, uart, label):
        for line in stream:
            digest.update(line); counts[label+'_raw_lines']+=1
            # A killed process may leave a final partial line; preserve/hash it
            # but compare only complete lines, with its byte count explicit.
            if label=='mc' and not line.endswith(b'\n'): continue
            if uart_pattern.match(line): uart.append(line)
            else: yield line
    with mc.open('rb') as f, plain.open('rb') as g:
        plain_lines=lines(g,hp,uart_plain,'plain')
        for a in lines(f,hm,uart_mc,'mc'):
            b=next(plain_lines,None)
            counts['compared_non_uart_lines']+=1
            if first is None and a != b:
                first=dict(channel='all_non_uart_lines',line=counts['compared_non_uart_lines'],
                    mc=a.decode(errors='replace'),plain=None if b is None else b.decode(errors='replace'))
        for line in plain_lines: pass
    if first is None and uart_mc != uart_plain[:len(uart_mc)]:
        first=dict(channel='application_uart',mc=[x.decode(errors='replace') for x in uart_mc],
            plain=[x.decode(errors='replace') for x in uart_plain[:len(uart_mc)]])
    expected_mc = read(OLD/'receipts/run-MCRams.json')['log_sha256']
    expected_plain = read(OLD/'receipts/run-Plain.json')['log_sha256']
    assert hm.hexdigest() == expected_mc and hp.hexdigest() == expected_plain, 'original log binding changed'
    result = dict(status='PASS_EXACT_TIMED_OUT_LOG_PREFIX_PER_TRANSPORT' if first is None else 'FAIL_LOG_PREFIX_MISMATCH_NO_RUNTIME',
        mc_log=str(mc),plain_log=str(plain),mc_sha256=hm.hexdigest(),plain_sha256=hp.hexdigest(),
        complete_prefix_bytes=complete,discarded_partial_tail_bytes=length-complete,first_mismatch=first,
        counts=counts,mc_uart_lines=[x.decode(errors='replace') for x in uart_mc],
        uart_prefix_match=uart_mc==uart_plain[:len(uart_mc)],all_other_lines_prefix_match=first is None,
        partition='Only exact bracketed INIT/ROI/OUTPUT/APP/COMPUTATION/END application lines are separate; all remaining bytes retained in other stream.',
        prior_combined_order_failure_sha256=sha(V1/'prefix-audit.json'),
        full_target_equivalence=False,roi_complete=False)
    write_new(O/'prefix-audit.json',result)
    assert first is None, result
    return result


def parse_run(receipt, expected):
    rows,metrics,faults = [],[],[]
    with Path(receipt['log']).open(errors='replace') as f:
        for line in f:
            if any(x in line for x in ['[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]']): rows.append(line.rstrip())
            if any(x in line for x in ['Target Cycles Emulated:','FMR:','Wallclock Time Elapsed:','Effective Target Frequency:']): metrics.append(line.rstrip())
            if re.search(r'Assertion failed|%Error|\*\*\* FAILED|status=FAIL|Simulator deadlock detected',line): faults.append(line.rstrip())
    correct = (receipt['returncode']==0 and receipt['stop_cause'] is None and not faults
        and any(expected in r for r in rows) and '[COMPUTATION] status=PASS scope=official_serial_kernel' in rows
        and '[END] hart=0 status=PASS' in rows)
    return dict(output_correctness=correct,target_rows=rows,host_metrics=metrics,faults=faults,
        returncode=receipt['returncode'],stop_cause=receipt['stop_cause'],host_wall_seconds=receipt['host_wall_seconds'],
        captured_print_streams={p.name:sha(p) for p in sorted((O/'MCRams/run').glob('rtl-prints-*')) if p.is_file()})


def runtime_stage(module, args, run_dir, environment, timeout, budget):
    policy()
    log=O/'run-MCRams.log'; assert not log.exists()
    started=time.monotonic(); cause=None
    with log.open('xb',buffering=0) as stream:
        child=subprocess.Popen(args,cwd=run_dir,env=environment,stdin=subprocess.DEVNULL,
            stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
        module.update(status='RUNNING_MC_RECOVERY_SAME_BINARY_TARGET',stage='run-MCRams',
            child=identity(child.pid),log=str(log),host_timeout_seconds=timeout)
        while child.poll() is None:
            try: child.wait(timeout=30)
            except subprocess.TimeoutExpired: pass
            elapsed=time.monotonic()-started
            owned_bytes=log.stat().st_size+sum(p.stat().st_size for p in run_dir.iterdir() if p.is_file())
            if elapsed>timeout: cause='HOST_TIMEOUT'
            if owned_bytes>budget: cause='OWNED_LOG_BUDGET'
            if cause and child.poll() is None:
                # Only this controller's newly created CPU process group.
                os.killpg(child.pid,signal.SIGTERM)
                try: child.wait(timeout=20)
                except subprocess.TimeoutExpired: os.killpg(child.pid,signal.SIGKILL);child.wait()
            os.fsync(stream.fileno());module.update(host_wall_seconds=elapsed,owned_log_bytes=owned_bytes,stop_cause=cause)
    receipt=dict(stage='run-MCRams',argv=args,returncode=child.returncode,stop_cause=cause,
        host_wall_seconds=time.monotonic()-started,ended_utc=now(),log=str(log),log_sha256=sha(log),outputs={})
    (O/'receipts').mkdir();write_new(O/'receipts/run-MCRams.json',receipt)
    module.update(child={},last_receipt=str(O/'receipts/run-MCRams.json'))
    return receipt


def run():
    policy(); plan=read(C/'plan.json')
    assert all(sha(p)==h for p,h in {**plan['inputs'],**plan['originals']}.items())
    assert not O.exists(), 'Preserve partial recovery; use a reviewed new version'
    O.mkdir(); lock=(O/'instance.lock').open('a'); fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old_lock=(OLD/'instance.lock').open('r'); fcntl.flock(old_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    v1_lock=(V1/'instance.lock').open('r'); fcntl.flock(v1_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    cpu_check(); guard=exited()
    os.sched_setaffinity(0,set(plan['cpus'])); resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    sp=importlib.util.spec_from_file_location('owner_timeout_helper',HELPER);m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
    m.O=O; m.S=S
    m.ST.update(schema='ec-owner-timeout-recovery/1',**identity(),started_utc=now(),
        functional_baseline=BASE,hardware_commit=plan['hardware_commit'],no_compile=True,
        cpus=plan['cpus'],target_changed=False,fpga_access=False,whole_fit=False,production_admission=False)
    try:
        m.update(status='AUDITING_IMMUTABLE_TIMED_OUT_PREFIX',predecessor_exit_guard=guard)
        audit=prefix_audit(); m.update(prefix_audit_sha256=sha(O/'prefix-audit.json'))
        policy(); exited(); cpu_check(); m.guard()
        old=read(OLD/'plan.json'); ref=read(OLD/'result.json')['results']['Plain']; item=old['models']['MCRams']
        for path,digest in plan['originals'].items():
            if path.endswith('/VOwnerMCRams3656') or path.endswith('/test.riscv'): assert sha(path)==digest
        run_dir=O/'MCRams/run'; run_dir.mkdir(parents=True)
        args=[item['binary']]+['+print-file='+str(run_dir/'rtl-prints-') if a.startswith('+print-file=') else a for a in old['reference_args'][1:]]
        assert [a for a in args[1:] if not a.startswith('+print-file=')] == [a for a in old['reference_args'][1:] if not a.startswith('+print-file=')]
        write_new(O/'runtime-binding.json',dict(plan_sha256=sha(C/'plan.json'),binary_sha256=sha(item['binary']),
            elf_sha256=old['elf_sha256'],argv=args,environment=item['environment'],host_timeout_seconds=plan['host_timeout_seconds'],
            target_cycle_limit=old['target_cycle_limit'],owned_log_budget_bytes=old['owned_log_budget_bytes'],
            reused_plain_result_sha256=sha(OLD/'Plain/run-result.json'),prefix_audit_sha256=sha(O/'prefix-audit.json')))
        receipt=runtime_stage(m,args,run_dir,{**os.environ,**item['environment']},
            timeout=plan['host_timeout_seconds'],budget=old['owned_log_budget_bytes'])
        metric=parse_run(receipt,old['application_expected_output']); write_new(O/'MCRams/run-result.json',metric)
        rows=bool(ref['target_rows']) and ref['target_rows']==metric['target_rows']
        streams=len(ref['captured_print_streams'])>=2 and ref['captured_print_streams']==metric['captured_print_streams']
        ok=bool(ref['output_correctness'] and metric['output_correctness'] and rows and streams)
        result={**m.ST,'status':'PASS_RECOVERED_FINITE_OWNER_PLAIN_MC_TARGET_ROWS_AND_PRINT_STREAMS' if ok else 'FAILED_RECOVERY_WITH_PRESERVED_RAW_EVIDENCE',
            'completed_utc':now(),'captured_finite_parity_passed':ok,'exact_target_rows':rows,'exact_print_streams':streams,
            'results':dict(Plain=ref,MCRams=metric),'plan_sha256':sha(C/'plan.json'),
            'limitations':['Finite captured observations only; universal target reset/state/FAME equivalence remains unproved.',
                'Prior MC timeout is preserved; no checkpoint existed, so only MC restarted after exact prefix and exit checks.',
                'No full Opt4 area/FIT, bitstream, FPGA, formal PARSEC, or strict BOOM-done latency claim.']}
        write_new(O/'result.json',result); write_new(O/'complete.json',dict(result_sha256=sha(O/'result.json'),completed_utc=now()))
        m.update(status=result['status'],result_sha256=sha(O/'result.json'),child={})
    except Exception as exc:
        m.update(status='FAILED_WITH_EVIDENCE',error=repr(exc)); write_new(O/'failure.json',m.ST); raise


if __name__=='__main__':
    ap=argparse.ArgumentParser();g=ap.add_mutually_exclusive_group(required=True)
    g.add_argument('--prepare',action='store_true');g.add_argument('--run',action='store_true')
    args=ap.parse_args();prepare() if args.prepare else run()
