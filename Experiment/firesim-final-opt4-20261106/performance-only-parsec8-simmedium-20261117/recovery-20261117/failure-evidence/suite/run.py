#!/usr/bin/env python3
"""Eight simmedium runs on certified Performance-Only FPGA, card 21 only."""
import argparse
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import signal
import statistics
import subprocess
import sys
import time

HERE = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
CERT = W/'runtime/Opt4-performance-only-4915b82-physical-r3/certified-build.json'
HANDOFF = W/'Opt4-performance-only-rtl-timing-r2-20261115/candidates/rtl-timing-physical-r3-20261116/after-physical.py'
PHYSICAL = Path('/var/tmp/guozh-ec-rtl-timing-r2-20261115/physical-r3-20261116')
BDF, SERIAL = '0000:21:00.0', '21770433G02LA'
NAMES = ['blackscholes', 'fluidanimate', 'bodytrack', 'swaptions',
         'ferret', 'dedup', 'streamcluster', 'freqmine']
HW = '4915b82c138d63cfb7b74f2fe5249ab96c765d34'
sys.path.insert(0, str(W/'scripts'))
from board_batch import precheck


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(8*1024*1024), b''):
            h.update(b)
    return h.hexdigest()


def read(p):
    return json.loads(Path(p).read_text())


def save(p, value):
    p = Path(p)
    t = p.with_suffix(p.suffix+'.tmp')
    with t.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    if os.geteuid() == 0:
        os.chown(t, 1008, 1008)
    t.replace(p)


def load(name, path):
    s = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(s); s.loader.exec_module(m)
    return m


def prepare():
    cert = read(CERT)
    assert cert['hardware_commit'] == HW and cert['board_bdf'] == BDF
    assert cert['board_serial'] == SERIAL and cert['full_PALIMPSEST'] is False
    assert cert['routing']['legal']
    assert all(cert['timing'][k] == 0 for k in ['tns','ths','setup_endpoints','hold_endpoints'])
    assert sha(cert['bitstream']) == cert['bitstream_sha256']
    driver = cert['driver_audit']['compatible_driver']
    assert sha(driver) == cert['driver_audit']['compatible_driver_sha256']
    plan = read(D/'suite-execution-plan.json')
    memory = read(W/'runtime/fased-common/manifest.json')
    native = []
    for path in (D/'runs').glob('native-*-simmedium-*/result.json'):
        try:
            r, c = read(path), read(path.parent/'complete.json')
            if (r.get('valid') and r.get('formal') and r.get('fpga_execution')
                    and r['identity'].get('program') in NAMES
                    and c['result_sha256'] == sha(path)
                    and c['identity_sha256'] == r['identity_sha256']):
                assert hashlib.sha256(json.dumps(r['identity'],sort_keys=True).encode()).hexdigest() == r['identity_sha256']
                native.append((path,r))
        except (OSError,ValueError,KeyError,AssertionError):
            continue
    rows = []
    for name in NAMES:
        row = dict(program=name,input='simmedium',repetition=1,status='READY')
        try:
            task = next(t for t in plan['programs'] if t['program'] == name)
            profile = task['software_profile_prefix']
            receipts = {k: str(p) for k,p in dict(
                apps=W/'software'/f'{profile}-apps-build.json',
                rootfs=W/'software'/f'{profile}-rootfs-build.json',
                firmware=W/'software/C4'/f'{profile}-firmware-build.json').items()}
            a,r,f = (read(receipts[k]) for k in ['apps','rootfs','firmware'])
            case = next(c for c in a['cases'] if c['program']==name and c['input']=='simmedium')
            assert case['threads']==1 and case['warmups']==0
            assert not a.get('c4_incompatible_reason') and a.get('formal_eligible',True)
            assert f['returncode']==0 and not f.get('diagnostic_only',False)
            assert r['apps_manifest_sha256']==sha(receipts['apps']) and sha(r['path'])==r['sha256']
            binary = a['binaries'][name]
            assert sha(binary['path'])==binary['sha256']
            elf = Path(f['output_dir'])/'platform/generic/firmware/fw_payload.elf'
            assert sha(elf)==f['outputs'][str(elf)]
            kernel_path = next(Path(p) for p in f['input_files'] if p.endswith('.json') and 'kernel' in Path(p).name)
            kernel = read(kernel_path)
            assert kernel['input_files'].get(r['path'])==r['sha256']
            fdt_path = Path(f['content_checks']['fdt']['path'])
            fdt = read(fdt_path.parent/'manifest.json')
            assert sha(fdt_path)==fdt['sha256']==f['content_checks']['fdt']['sha256']
            assert f['content_checks']['fdt']['exact_bytes_present']
            assert fdt['linux_harts']==[0] and fdt['firmware_checker_harts']==[1,2,3,4]
            matches = []
            for path,n in native:
                i = n['identity']
                if not (i.get('configuration')=='Native' and i.get('program')==name
                        and i.get('input')=='simmedium' and i.get('threads')==1 and i.get('warmups')==0
                        and i.get('apps_manifest_sha256')==sha(receipts['apps'])
                        and i.get('rootfs_sha256')==r['sha256']
                        and i.get('elf_sha256')==binary['sha256']
                        and i.get('case')==case and i.get('memory_model')=={k:memory[k] for k in ['model','settings']}
                        and i.get('linux_memory_cap_bytes')==fdt['linux_mem_cap']
                        and i.get('target_boom_hz')==fdt['target_boom_hz']):
                    continue
                matches.append(dict(result=str(path),sha256=sha(path),roi_cycles=n['roi_cycles'],
                                    host_wall_seconds=n['host_wall_seconds']))
            row.update(profile=profile,software_semantics_label=case.get('software_semantics_label',
                       a.get('software_profile',profile)),receipts=receipts,
                       receipt_sha256={k:sha(p) for k,p in receipts.items()},case=case,
                       firmware=str(elf),firmware_sha256=sha(elf),rootfs_sha256=r['sha256'],
                       elf_sha256=binary['sha256'],apps_manifest_sha256=sha(receipts['apps']),
                       fdt=str(fdt_path),fdt_sha256=fdt['sha256'],bootargs=fdt['bootargs'],
                       linux_memory_cap_bytes=fdt['linux_mem_cap'],target_boom_hz=fdt['target_boom_hz'],
                       target_checker_hz=fdt['target_checker_hz'],native_samples=matches,
                       native_median_roi_cycles=statistics.median(x['roi_cycles'] for x in matches) if matches else None,
                       boot_timeout_seconds=3600,timeout_seconds=172800 if name=='freqmine' else 43200)
        except Exception as e:
            row.update(status='SKIP_PREPARATION_FAILED',reason=repr(e))
        rows.append(row)
    manifest = dict(schema='ec-performance-only-parsec8-simmedium/1',prepared_utc=now(),
        configuration='ECPerformanceOnly',profile=cert['profile'],full_PALIMPSEST=False,
        hardware_commit=HW,source_id=cert['source_id'],board_bdf=BDF,board_serial=SERIAL,
        certificate=str(CERT),certificate_sha256=sha(CERT),bitstream=cert['bitstream'],
        bitstream_sha256=cert['bitstream_sha256'],driver=driver,
        driver_sha256=cert['driver_audit']['compatible_driver_sha256'],memory_model=memory,
        input='simmedium',threads=1,warmups=0,repetitions=1,programs=rows,
        failure_policy='Preserve evidence, skip application, continue next medium input; no substitute inputs',
        deployment_policy='Reprogram certified card21 before each independent guest; no unverified reset reuse',
        slowdown_policy='Performance-Only ROI target cycles / median of exactly matched valid Native FPGA ROI cycles',
        runner_sha256=sha(__file__),verification_sha256=sha(HERE/'sample_verify.py'),
        handoff_sha256=sha(HANDOFF),periodic_patrol=False)
    save(HERE/'plan.json',manifest)
    print(json.dumps(dict(status='PREPARED_NOT_RUN',ready=[r['program'] for r in rows if r['status']=='READY'],
                         skipped=[r for r in rows if r['status']!='READY'],native_counts={r['program']:len(r.get('native_samples',[])) for r in rows}),ensure_ascii=False),flush=True)
    return manifest


def deployment(out):
    env = {k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD']}
    with (out/'deployment-command.log').open('ab',buffering=0) as f:
        r = subprocess.run(['/usr/bin/python3','-I',str(HANDOFF)],cwd=out,env=env,
                           stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=2400)
    state = read(PHYSICAL/'handoff-state.json')
    save(out/'deployment-handoff.json',state)
    assert r.returncode==0 and state['status']=='CARD21_DEPLOYED_RUNTIME_VALIDATION_PENDING',state
    receipt = read(PHYSICAL/'deployment21/deployment.json')
    assert receipt['board_bdf']==BDF and receipt['board_serial']==SERIAL and not receipt['other_boards_touched']
    save(out/'deployment.json',receipt)
    return receipt


def sample(plan, row, out):
    v = load('perfonly_sample_verify',HERE/'sample_verify.py')
    maintenance = (D/'locks/maintenance-0000_21_00.0.lock').open('a')
    card = (D/'locks/card-0000_21_00.0.lock').open('a')
    with maintenance,card:
        fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
        fcntl.flock(card,fcntl.LOCK_EX|fcntl.LOCK_NB)
        check = precheck(target_bdfs=[BDF]);save(out/'pre-run.json',check)
        assert not check['open_devices'] and not check['simulation_processes'],'card21 busy; no task interrupted'
        for k,p in row['receipts'].items():assert sha(p)==row['receipt_sha256'][k]
        assert sha(plan['driver'])==plan['driver_sha256']
        assert sha(row['firmware'])==row['firmware_sha256']
        ident = dict(configuration='ECPerformanceOnly',hardware_profile=plan['profile'],
            hardware_commit=HW,hardware_source_id=plan['source_id'],full_PALIMPSEST=False,
            board_bdf=BDF,board_serial=SERIAL,run_id=out.name,program=row['program'],input='simmedium',
            repetition=1,threads=1,warmups=0,formal=True,performance_only=True,
            bitstream_sha256=plan['bitstream_sha256'],driver_sha256=plan['driver_sha256'],
            firmware_sha256=row['firmware_sha256'],apps_manifest_sha256=row['apps_manifest_sha256'],
            rootfs_sha256=row['rootfs_sha256'],elf_sha256=row['elf_sha256'],case=row['case'],
            linux_memory_cap_bytes=row['linux_memory_cap_bytes'],linux_bootargs=row['bootargs'],
            fdt_sha256=row['fdt_sha256'],software_profile=row['software_semantics_label'],
            target_boom_hz=row['target_boom_hz'],target_checker_hz=row['target_checker_hz'],
            memory_model={k:plan['memory_model'][k] for k in ['model','settings']})
        iid=hashlib.sha256(json.dumps(ident,sort_keys=True).encode()).hexdigest()
        uartin=out/'uart.in';uartin.write_bytes(b'')
        argv=[plan['driver'],'+permissive','+domain=0000','+bus=21','+device=00','+function=0',
              '+bar=0','+pci-vendor=10ee','+pci-device=903f','+uart-in0='+str(uartin),
              '+uart-out0='+str(out/'uart.log'),'+fesvr-step-size=2004765',
              *plan['memory_model']['plusargs'],'+print-file='+str(out/'rtl-events-'),
              '+permissive-off','+prog0='+row['firmware']]
        save(out/'manifest.json',dict(identity=ident,identity_sha256=iid,argv=argv,
             plan_sha256=sha(HERE/'plan.json'),runner_sha256=sha(__file__),verification_sha256=sha(HERE/'sample_verify.py')))
        state=dict(status='STARTING',program=row['program'],input='simmedium',configuration='ECPerformanceOnly',
                   run_id=out.name,run_dir=str(out),identity_sha256=iid,board_bdf=BDF,board_serial=SERIAL,
                   host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now())
        start=time.monotonic();sent=False;shutdown=False;done=None;controlled=False;timedout=False;budget=False;last=0
        env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD']}
        with (out/'host.log').open('wb',buffering=0) as log:
            child=subprocess.Popen(['/usr/bin/nice','-n','10','/usr/bin/stdbuf','-oL','-eL',*argv],cwd=out,
                  env=env,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(status='RUNNING',pid=child.pid,pgid=child.pid,
                         start_ticks=Path(f'/proc/{child.pid}/stat').read_text().rsplit(') ',1)[1].split()[19])
            save(out/'state.json',state);save(D/'active-0000_21_00.0.json',state)
            print(json.dumps(dict(status='RUNNING',program=row['program'],pid=child.pid,uart=str(out/'uart.log'))),flush=True)
            while child.poll() is None:
                elapsed=time.monotonic()-start
                u=(out/'uart.log').read_bytes() if (out/'uart.log').exists() else b''
                if not sent and b'EC_GUEST_READY' in u:
                    with uartin.open('ab',buffering=0) as f:
                        f.write(f'/opt/ec-fpga/run-one {row["program"]} simmedium 1 {out.name}; echo EC_COMMAND_EXIT=$?\n'.encode());os.fsync(f.fileno())
                    sent=True
                if sent and not shutdown and re.search(rb'(?:^|\n)EC_COMMAND_EXIT=\d+\r?\n',u):
                    with uartin.open('ab',buffering=0) as f:
                        f.write(b'/bin/busybox sync; /bin/poweroff -f\n');os.fsync(f.fileno())
                    shutdown=True;done=elapsed
                fatal=any(t in u for t in [b'Kernel panic',b'EC_OPT4_INVALID',b'EC_SAMPLE_FAILED'])
                timedout=elapsed>row['timeout_seconds'] or (not sent and elapsed>row['boot_timeout_seconds'])
                budget=sum(p.stat().st_size for p in out.iterdir() if p.is_file())>32*2**30
                if fatal or timedout or budget or (done is not None and elapsed-done>30):
                    controlled=not timedout and b'Power down' in u
                    os.killpg(child.pid,signal.SIGTERM)
                    try:child.wait(timeout=15)
                    except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
                    break
                if elapsed-last>=30:
                    state.update(elapsed_seconds=elapsed,guest_ready=sent,guest_command_ended=shutdown,uart_bytes=len(u),updated_utc=now())
                    save(out/'state.json',state);save(D/'active-0000_21_00.0.json',state);last=elapsed
                try:child.wait(timeout=.5)
                except subprocess.TimeoutExpired:pass
        result=v.verify(out,ident,child.returncode,controlled,timedout)
        if budget:result['valid']=False;result['issues'].append('log budget exceeded; raw evidence preserved')
        state.update(status='COMPLETE' if result['valid'] else 'TIMEOUT' if timedout else 'FAILED',
                     issues=result['issues'],ended_utc=now());save(out/'state.json',state);save(D/'active-0000_21_00.0.json',state)
        baseline=row.get('native_median_roi_cycles')
        result.update(schema='ec-performance-only-fpga-result/1',identity=ident,identity_sha256=iid,
            driver_returncode=child.returncode,driver_stop_after_guest_powerdown=controlled,timedout=timedout,
            host_wall_seconds=time.monotonic()-start,fpga_execution=True,formal=True,full_PALIMPSEST=False,
            native_samples=row['native_samples'],native_median_roi_cycles=baseline,
            slowdown=result['roi_cycles']/baseline if result['valid'] and baseline else None,
            evidence={str(p):sha(p) for p in out.iterdir() if p.is_file()})
        save(out/'result.json',result)
        if result['valid']:
            save(out/'complete.json',dict(identity_sha256=iid,result_sha256=sha(out/'result.json'),formal=True,full_PALIMPSEST=False))
            save(HERE/'runtime-validation.json',dict(status='VALID_PERFORMANCE_ONLY_SIMMEDIUM',
                 program=row['program'],result=str(out/'result.json'),sha256=sha(out/'result.json'),fpga_runtime_validated=True,full_PALIMPSEST=False))
        print(json.dumps(dict(status=state['status'],program=row['program'],roi_cycles=result['roi_cycles'],
                             slowdown=result['slowdown'],issues=result['issues'])),flush=True)
        return result


def run():
    assert os.geteuid()==0,'Administrator execution required for audited card21 deployment and MMIO'
    with (HERE/'instance.lock').open('a') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
        plan=read(HERE/'plan.json')
        assert plan['runner_sha256']==sha(__file__) and plan['verification_sha256']==sha(HERE/'sample_verify.py')
        assert sha(CERT)==plan['certificate_sha256'] and sha(HANDOFF)==plan['handoff_sha256']
        state=dict(status='RUNNING',started_utc=now(),pid=os.getpid(),input='simmedium',
                   configuration='ECPerformanceOnly',full_PALIMPSEST=False,results=[])
        save(HERE/'state.json',state)
        for row in plan['programs']:
            destination=HERE/'runs'/row['program'];destination.mkdir(parents=True,exist_ok=True)
            if (destination/'attempt.json').exists():
                state['results'].append(read(destination/'attempt.json'));continue
            attempt=dict(program=row['program'],input='simmedium',started_utc=now(),out=str(destination))
            try:
                if row['status']!='READY':raise RuntimeError(row.get('reason',row['status']))
                state.update(current_program=row['program'],phase='CARD21_DEPLOYMENT');save(HERE/'state.json',state)
                deployment(destination)
                state['phase']='FPGA_SAMPLE';save(HERE/'state.json',state)
                result=sample(plan,row,destination)
                attempt.update(status='PASS' if result['valid'] else 'SKIP_FAILED_SAMPLE',
                               roi_cycles=result['roi_cycles'],slowdown=result['slowdown'],issues=result['issues'])
            except Exception as e:
                attempt.update(status='SKIP_FAILED_ATTEMPT',reason=repr(e))
                print(json.dumps(attempt),flush=True)
            attempt['ended_utc']=now();save(destination/'attempt.json',attempt)
            state['results'].append(attempt);save(HERE/'state.json',state)
            lines=['# EC Performance-Only PARSEC simmedium — one round','',
                   '| Benchmark | Status | ROI cycles | Slowdown vs matched Native |',
                   '|---|---|---:|---:|']
            for a in state['results']:
                slowdown=a.get('slowdown')
                lines.append(f'| {a["program"]} | {a["status"]} | {a.get("roi_cycles") or "—"} | {f"{slowdown:.4f}×" if slowdown is not None else "—"} |')
            lines+=['','Only simmedium. Failed attempts are skipped and retained. These are Performance-Only results, not full PALIMPSEST.','']
            (HERE/'results.md').write_text('\n'.join(lines))
        state.update(status='ROUND_FINISHED',ended_utc=now(),current_program=None,phase=None)
        save(HERE/'state.json',state)


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true')
    ap.add_argument('--start',action='store_true');a=ap.parse_args()
    assert sum([a.prepare,a.run,a.start])==1
    if a.prepare:prepare();return
    if a.run:run();return
    assert os.geteuid()==0,'Run this launcher with sudo; credentials are never stored'
    with (HERE/'launcher.log').open('ab',buffering=0) as f:
        child=subprocess.Popen(['/usr/bin/python3','-I',str(Path(__file__).resolve()),'--run'],
              cwd=HERE,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,
              env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD']})
    save(HERE/'launcher.json',dict(pid=child.pid,started_utc=now(),input='simmedium',configuration='ECPerformanceOnly',
         command=['/usr/bin/python3','-I',str(Path(__file__).resolve()),'--run'],periodic_patrol=False))
    print(json.dumps(dict(status='LAUNCHED',pid=child.pid,log=str(HERE/'launcher.log'))),flush=True)


if __name__=='__main__':
    main()
