import sys
from pathlib import Path as _BundlePath
sys.path.insert(0,str(_BundlePath(__file__).resolve().parent))
sys.path.insert(1,'/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""21-only deployment and sample capture. No host-wide driver or PCI actions.

The e2 FPGA is protected, including any task already running on it.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import selectors
import shutil
import signal
import socket
import subprocess
import sys
import time

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
TARGET_BDF='0000:21:00.0'
TARGET_SERIAL='21770433G02LA'
BDFS=[TARGET_BDF]
SERIALS=[TARGET_SERIAL]
UID=1008
GID=1008


def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()


def save(p,value):
    tmp=p.with_suffix('.tmp')
    with tmp.open('w') as f:
        json.dump(value,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.chown(tmp,UID,GID)
    tmp.replace(p)
    fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)


def precheck(cleanup_root=None,target_bdfs=None):
    targets=BDFS if target_bdfs is None else list(target_bdfs)
    assert targets and len(set(targets))==len(targets) and all(b==TARGET_BDF for b in targets), targets
    opened=[];sims=[];other_sims=[];old_users=[];denied=0
    nodes=set()
    for b in targets:
        node_dir=Path('/sys/bus/pci/devices')/b/'xdma'
        if node_dir.is_dir():nodes.update('/dev/'+p.name for p in node_dir.iterdir())
    for p in Path('/proc').glob('[0-9]*'):
        try:
            cmd=(p/'cmdline').read_bytes().replace(b'\0',b' ').decode(errors='replace')
            comm=(p/'comm').read_text().strip()
            if comm.startswith('FireSim-') or comm=='fpga-util.py':
                row=dict(pid=int(p.name),cmd=cmd)
                bus=re.search(r'(?:^|\s)\+bus=(?:0x)?([0-9a-fA-F]+)(?:\s|$)',cmd)
                if bus and bus[1].lower()!='21':other_sims.append(row)
                else:sims.append(row)
            if cleanup_root and str(cleanup_root) in cmd:old_users.append(dict(pid=int(p.name),kind='command',cmd=cmd))
            try:
                cwd=os.readlink(p/'cwd')
                if cleanup_root and cwd.startswith(str(cleanup_root)):old_users.append(dict(pid=int(p.name),kind='cwd',path=cwd))
            except OSError:pass
            for fd in (p/'fd').iterdir():
                try:
                    target=os.readlink(fd)
                    if target.removesuffix(' (deleted)') in nodes or target.startswith('/dev/xclmgmt') or any(b in target and '/resource' in target for b in targets):
                        opened.append(dict(pid=int(p.name),fd=fd.name,target=target,cmd=cmd))
                    if cleanup_root and target.startswith(str(cleanup_root)):old_users.append(dict(pid=int(p.name),kind='fd',path=target))
                except PermissionError:denied+=1
                except OSError:pass
            # MMIO remains mapped after a device FD is closed.
            try:
                maps=(p/'maps').read_text()
                hits=[x for x in maps.splitlines() if any(n in x for n in nodes) or any(b in x and '/resource' in x for b in targets)]
                if hits:opened.append(dict(pid=int(p.name),kind='mapping',paths=hits,cmd=cmd))
            except PermissionError:denied+=1
        except PermissionError:denied+=1
        except (FileNotFoundError,ProcessLookupError):pass
    mapping=[]
    db=json.loads(Path('/opt/firesim-db.json').read_text())
    for b in targets:
        serial=SERIALS[BDFS.index(b)]
        s=Path('/sys/bus/pci/devices')/b
        assert (s/'vendor').read_text().strip()=='0x10ee' and (s/'device').read_text().strip()=='0x903f'
        assert sum(x['bdf']==b[5:] and x['uid']=='Xilinx/'+serial for x in db)==1
        mapping.append(dict(bdf=b,serial=serial,driver=(s/'driver').resolve().name))
    return dict(observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),target_bdfs=targets,mapping=mapping,
                open_devices=opened,simulation_processes=sims,other_card_simulations=other_sims,cleanup_users=old_users,
                permission_denied=denied,user_confirms_boards_available=True)


def command(argv,cwd,log,timeout=900):
    with log.open('ab',buffering=0) as f:
        f.write((json.dumps(dict(argv=list(map(str,argv)),cwd=str(cwd)))+'\n').encode())
        child=subprocess.Popen(list(map(str,argv)),cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
                               start_new_session=True,env={**os.environ,'PATH':'/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin'})
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(child.pid,signal.SIGTERM)
            try:child.wait(timeout=20)
            except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
            raise RuntimeError('command timeout: '+str(argv[0]))
        if rc:raise RuntimeError(f'command failed {rc}: {argv[0]}; see {log}')


def clean_abandoned(out):
    root=Path('/data1/gzh/EC/firesim/dac2026/work/opt4-linux-v6/builds/C4-bitstream-20261103T105502.826002Z')
    check=precheck(root)
    save(out/'cleanup-precheck.json',check)
    assert not check['cleanup_users'], 'abandoned build still referenced by running process'
    files=[]
    for p in root.rglob('*.rtd'):
        assert '.Xil' in p.parts and not p.is_symlink() and p.stat().st_uid==UID
        files.append(dict(path=str(p),bytes=p.stat().st_size,mtime_ns=p.stat().st_mtime_ns,
                          role='regenerable Vivado internal synthesis database; old version abandoned CAD'))
    assert not list(root.rglob('*.bit')), 'unexpected bitstream; inspect before cleanup'
    before=shutil.disk_usage(D)
    report=dict(schema='ec-authorized-cleanup/1',root=str(root),before_free_bytes=before.free,
                deletion_scope='only *.rtd below .Xil in one abandoned old C4 CAD build',files=files,
                preserved='all source, generated RTL, scripts, logs, reports, manifests, dcp, and any bitstream elsewhere',
                deleted_bytes=0,status='DELETING')
    save(out/'cleanup.json',report)
    for row in files:
        p=Path(row['path']);assert p.stat().st_size==row['bytes'] and p.stat().st_mtime_ns==row['mtime_ns'];p.unlink()
        report['deleted_bytes']+=row['bytes']
    report.update(status='COMPLETE',after_free_bytes=shutil.disk_usage(D).free)
    save(out/'cleanup.json',report)
    print(json.dumps(dict(cleanup_deleted_gib=report['deleted_bytes']/2**30,data1_free_gib=report['after_free_bytes']/2**30)),flush=True)


def ensure_jtag_server(out,serials):
    try:
        with socket.create_connection(('127.0.0.1',3122),timeout=2):pass
    except OSError:
        log=D/'owned-hw-server-3122-20261107.log'
        with log.open('ab',buffering=0) as stream:
            child=subprocess.Popen(['/tools/Xilinx/Vivado/2021.1/bin/hw_server','-s','tcp::3122'],
                                   stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,
                                   start_new_session=True)
        save(D/'owned-hw-server-3122.json',dict(pid=child.pid,pgid=child.pid,port=3122,
            start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21],
            host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
            log=str(log),owned_by_this_campaign=True,other_servers_stopped=False,
            started_utc=dt.datetime.now(dt.timezone.utc).isoformat()))
        deadline=time.monotonic()+30
        while True:
            try:
                with socket.create_connection(('127.0.0.1',3122),timeout=2):break
            except OSError:
                assert child.poll() is None and time.monotonic()<deadline, 'owned hw_server failed to start'
                time.sleep(.5)
    script=out/'readonly-jtag-targets.tcl'
    script.write_text('set_param labtools.enable_cs_server false\nopen_hw_manager\nconnect_hw_server -url localhost:3122 -allow_non_jtag\nforeach target [get_hw_targets] { puts "EC_JTAG_TARGET $target" }\nclose_hw_manager\nexit\n')
    log=out/'readonly-jtag-targets.log'
    command(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
             '-log',str(out/'readonly-jtag-vivado.log'),'-source',script],out,log,timeout=90)
    observed=log.read_text(errors='replace')
    assert all(any(s in line and line.startswith('EC_JTAG_TARGET ') for line in observed.splitlines())
               for s in serials), 'requested JTAG serial absent; no PCIe or driver maintenance performed'


def deploy_native(out,pair=False,single_c4_bdf=None,single_native_bdf=None,opt4_fit_receipt=None):
    if pair:
        raise ValueError('two-card deployment is disabled; only 0000:21:00.0 is allowed')
    if single_c4_bdf not in [None,TARGET_BDF] or single_native_bdf not in [None,TARGET_BDF]:
        raise ValueError('only 0000:21:00.0 is allowed')
    from opt4_fit_runtime_guard import priority_guard,artifact
    priority_guard(opt4_fit_receipt)
    n=json.loads((W/'native-reuse.json').read_text())
    if opt4_fit_receipt:
        assert single_c4_bdf==TARGET_BDF and single_native_bdf is None
        c=artifact(opt4_fit_receipt)
        cards=[dict(bdf=TARGET_BDF,serial=TARGET_SERIAL,configuration='C4',
            hardware_profile=c['profile'],hardware_commit=c['hardware_commit'],source_id=c['source_id'],
            derived_build_receipt=str(opt4_fit_receipt),derived_build_receipt_sha256=sha(opt4_fit_receipt),
            bitstream=c['durable_bitstream'],bitstream_sha256=c['durable_bitstream_sha256'])]
    elif single_c4_bdf:
        c=json.loads((W/'bitstream-runtime-build.json').read_text())
        assert c['hardware_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
        assert c['certified_bitstream'] and c['returncode']==0
        cbit=c['durable_bitstream'];cdigest=c['durable_bitstream_sha256'];assert sha(cbit)==cdigest
        assert c['source_id']=='c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
        save(W/'bitstream-build.json',c)
        cards=[dict(bdf=single_c4_bdf,serial=SERIALS[BDFS.index(single_c4_bdf)],configuration='C4',source_id=c['source_id'],bitstream=cbit,bitstream_sha256=cdigest)]
    else:
        bit,digest=next((p,h) for p,h in n['verified_artifacts'].items() if p.endswith('.bit'))
        assert sha(bit)==digest
        targets=[single_native_bdf] if single_native_bdf else [TARGET_BDF]
        cards=[dict(bdf=b,serial=SERIALS[BDFS.index(b)],configuration='Native',source_id=n['source_id'],bitstream=bit,bitstream_sha256=digest) for b in targets]
    assert len(cards)==1 and cards[0]['bdf']==TARGET_BDF
    scripts=W/'deployment-tools'
    assert (scripts/'fpga-util.py').exists()
    check=precheck(target_bdfs=[card['bdf'] for card in cards])
    save(out/'pre-deployment.json',check)
    assert not check['open_devices'] and not check['simulation_processes'], 'concrete device/simulation conflict'
    ensure_jtag_server(out,[card['serial'] for card in cards])
    check=precheck(target_bdfs=[card['bdf'] for card in cards])
    save(out/'pre-maintenance.json',check)
    assert not check['open_devices'] and not check['simulation_processes'], 'concrete conflict before target-card operation'
    log=out/'deployment.log'
    state=dict(schema='ec-single-fpga-deployment/2',status='MAINTENANCE_RUNNING',
               configuration='Native+C4' if pair else ('C4' if single_c4_bdf else 'Native'),
               source_id=cards[0]['source_id'],bitstream=cards[0]['bitstream'],bitstream_sha256=cards[0]['bitstream_sha256'],
               bdfs=[card['bdf'] for card in cards],serials=[card['serial'] for card in cards],cards=cards,
               user_authorization='2026-11-09 explicit 21-only experiments; never disturb e2',
               global_operations=[],
               targeted_operations=[
                   'unbind XDMA for 0000:21:00.0 only',
                   'remove and rescan through the 0000:21:00.0 upstream bridge only',
                   'program JTAG serial Xilinx/21770433G02LA only',
                   'rebind XDMA for 0000:21:00.0 only'],
               system_driver_updated=False,board_flash_firmware_updated=False,host_reboot=False,
               pid=os.getpid(),host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
               started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),completed_cards=[])
    state['deployment_tools']={str(p):sha(p) for p in scripts.glob('*') if p.is_file()}
    save(out/'deployment.json',state)
    for card in cards:
        b,serial=card['bdf'],card['serial']
        command(['/usr/bin/python3',scripts/'fpga-util.py','--extended-bdf',b,'--bitstream',card['bitstream'],
                 '--vivado-bin','/tools/Xilinx/Vivado/2021.1/bin/vivado',
                 '--hw-server-bin','/tools/Xilinx/Vivado/2021.1/bin/hw_server'],out,log,timeout=900)
        state['completed_cards'].append(card)
        save(out/'deployment.json',state)
    state.update(status='DEPLOYED_NOT_RUN',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 postcheck=precheck(target_bdfs=[card['bdf'] for card in cards]))
    save(out/'deployment.json',state)
    save(D/'latest-deployment.json',state)
    print(json.dumps(dict(deployment=state['status'],bdfs=state['bdfs'],receipt=str(out/'deployment.json'))),flush=True)


def native_sample(batch,program,inp,rep=1,timeout=1800):
    sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
    from inspect_roi_raw import inspect_bytes
    n=json.loads((W/'native-reuse.json').read_text())
    dr=json.loads(Path(n['driver_receipt']).read_text())
    fw=json.loads((W/'software/Native/firmware-build.json').read_text())
    apps=json.loads((W/'software/apps-build.json').read_text())
    rootfs=json.loads((W/'software/rootfs-build.json').read_text())
    exe=Path(dr['output_dir'])/'FireSim-xilinx_alveo_u280'
    elf=Path(fw['output_dir'])/'platform/generic/firmware/fw_payload.elf'
    assert sha(exe)==dr['outputs'][str(exe)] and sha(elf)==fw['outputs'][str(elf)]
    rid=f'native-{program}-{inp}-r{rep}-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'runs'/rid
    out.mkdir(parents=True)
    bdf=BDFS[0]
    lock=(D/'locks'/('card-'+bdf.replace(':','_')+'.lock')).open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    case=next((c for c in apps['cases'] if c['program']==program and c['input']==inp),None)
    identity=dict(run_id=rid,configuration='Native',board_bdf=bdf,board_serial=SERIALS[0],program=program,input=inp,repetition=rep,
                  hardware_source_id=n['source_id'],bitstream_sha256=next(h for p,h in n['verified_artifacts'].items() if p.endswith('.bit')),
                  driver_sha256=sha(exe),firmware_sha256=sha(elf),apps_manifest_sha256=sha(W/'software/apps-build.json'),
                  rootfs_sha256=rootfs['sha256'],elf_sha256=apps['smoke']['sha256'] if program=='smoke' else apps['binaries'][program]['sha256'],
                  case=case,threads=1,warmups=0,target_boom_hz=200000000,formal=False)
    identity_id=hashlib.sha256(json.dumps(identity,sort_keys=True).encode()).hexdigest()
    memory=json.loads((W/'runtime/fased-common/manifest.json').read_text())
    uartin=out/'uart.in';uartin.write_bytes(b'')
    argv=[str(exe),'+permissive','+domain=0000','+bus='+BDFS[0][5:7],'+device=00','+function=0','+bar=0',
          '+pci-vendor=10ee','+pci-device=903f','+ec-dac-roi-log='+str(out/'roi-raw.jsonl'),
          '+ec-dac-snapshot-seconds=30','+uart-in0='+str(uartin),'+uart-out0='+str(out/'uart.log'),
          '+fesvr-step-size=2004765',*memory['plusargs'],'+permissive-off','+prog0='+str(elf)]
    save(out/'manifest.json',dict(schema='ec-fpga-first-sample/1',identity=identity,identity_sha256=identity_id,
                                argv=argv,deployment=str(batch/'deployment.json'),status='STARTING'))
    check=precheck()
    save(out/'pre-run.json',check)
    assert not check['open_devices'] and not check['simulation_processes'], 'concrete conflict before first run'
    state=dict(schema='ec-fpga-sample-state/1',run_id=rid,identity_sha256=identity_id,status='RUNNING',sequence=0,
               started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),program=program,input=inp,repetition=rep,board_bdf=bdf)
    start=time.monotonic();sent=False;poweroff=False;hoststop=False;timedout=False
    with (out/'host.log').open('wb',buffering=0) as log:
        child=subprocess.Popen(['nice','-n','10','/usr/bin/stdbuf','-oL','-eL',*argv],cwd=out,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,
                               start_new_session=True,env={**os.environ,'PATH':'/usr/local/bin:/usr/bin:/bin','LD_LIBRARY_PATH':''})
        state.update(pid=child.pid,pgid=child.pid,start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21])
        save(out/'state.json',state);save(D/'active-board-run.json',dict(run_dir=str(out),**state))
        print(json.dumps(dict(run=rid,pid=child.pid,log=str(out/'uart.log'))),flush=True)
        last_snapshot=0;done_at=None
        while child.poll() is None:
            elapsed=time.monotonic()-start
            uart=(out/'uart.log').read_bytes() if (out/'uart.log').exists() else b''
            if not sent and b'EC_GUEST_READY' in uart:
                with uartin.open('ab',buffering=0) as f:
                    f.write(f'/opt/ec-fpga/run-one {program} {inp} {rep} {rid}; echo EC_COMMAND_EXIT=$?\n'.encode());os.fsync(f.fileno())
                sent=True
            if sent and not poweroff and re.search(rb'EC_COMMAND_EXIT=\d+\r?\n',uart):
                with uartin.open('ab',buffering=0) as f:f.write(b'/bin/busybox sync; /bin/poweroff -f\n');os.fsync(f.fileno())
                poweroff=True;done_at=elapsed
            if elapsed-last_snapshot>=30:
                state.update(sequence=state['sequence']+1,elapsed_seconds=elapsed,guest_ready=sent,guest_command_ended=poweroff,
                             uart_bytes=len(uart),updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
                for f in [out/'uart.log',out/'host.log',out/'roi-raw.jsonl']:
                    if f.exists():
                        fd=os.open(f,os.O_RDONLY);os.fsync(fd);os.close(fd)
                save(out/'snapshot.json',state);save(out/'state.json',state);last_snapshot=elapsed
            if elapsed>timeout or (done_at is not None and elapsed-done_at>60):
                timedout=elapsed>timeout;hoststop=not timedout
                os.killpg(child.pid,signal.SIGTERM)
                try:child.wait(timeout=15)
                except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
                break
            try:child.wait(timeout=.5)
            except subprocess.TimeoutExpired:pass
    uart=(out/'uart.log').read_bytes() if (out/'uart.log').exists() else b''
    raw=inspect_bytes((out/'roi-raw.jsonl').read_bytes()) if (out/'roi-raw.jsonl').exists() else None
    epochs=[e for e in raw['epochs'] if e['source_boundaries_complete']] if raw else []
    done=(b'EC_SAMPLE_GUEST_DONE run_id='+rid.encode()) in uart
    exitok=re.search(rb'\nEC_COMMAND_EXIT=0\r?\n',uart) is not None
    issues=[]
    if not done or not exitok:issues.append('missing successful guest output/exit chain')
    if raw is None or raw['protocol_issues'] or raw['partial_tail_bytes'] or len(epochs)!=1:issues.append('ROI transport/boundaries incomplete')
    if timedout:issues.append('host timeout')
    if child.returncode!=0:issues.append('driver did not exit normally')
    result=dict(schema='ec-fpga-first-sample-result/1',identity=identity,identity_sha256=identity_id,
                valid=not issues,status='VALID_FUNCTIONAL_SAMPLE' if not issues else 'FAILED_OR_INCOMPLETE',issues=issues,
                guest_output_valid=done,guest_exit_valid=exitok,driver_returncode=child.returncode,timeout=timedout,
                host_stop_after_guest_shutdown=hoststop,raw=raw,roi_cycles=epochs[0]['roi_cycles'] if len(epochs)==1 else None,
                generated=0,completed=0,passed=0,checker_latency=None,drain_cycles=0,
                host_wall_seconds=time.monotonic()-start,fpga_execution=True,formal=False,
                evidence={str(p):sha(p) for p in out.iterdir() if p.is_file() and p.name not in ['result.json','complete.json']})
    save(out/'result.json',result)
    if not issues:save(out/'complete.json',dict(identity_sha256=identity_id,result_sha256=sha(out/'result.json'),formal=False))
    state.update(status='COMPLETE' if not issues else 'TIMEOUT' if timedout else 'FAILED',driver_returncode=child.returncode,issues=issues,
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(out/'state.json',state);save(D/'active-board-run.json',dict(run_dir=str(out),**state))
    print(json.dumps(dict(run=rid,status=state['status'],roi_cycles=result['roi_cycles'],issues=issues)),flush=True)
    return not issues


def main():
    p=argparse.ArgumentParser()
    p.add_argument('--deploy-only',action='store_true')
    p.add_argument('--run-only',action='store_true')
    p.add_argument('--pair',action='store_true',help=argparse.SUPPRESS)
    p.add_argument('--single-c4-bdf',choices=BDFS,help='Deploy final C4 to one currently enumerated FPGA')
    p.add_argument('--single-native-bdf',choices=BDFS,help='Reuse certified Native bitstream on one currently enumerated FPGA')
    p.add_argument('--opt4-fit-receipt',type=Path,help='Pinned separately certified derived build; never relabel frozen C4')
    a=p.parse_args()
    if a.pair:p.error('two-card --pair is disabled; only 0000:21:00.0 may be used')
    if os.geteuid()!=0:p.error('administrator execution required')
    assert sum(bool(v) for v in [a.pair,a.single_c4_bdf,a.single_native_bdf])<=1, 'choose one deployment mode'
    assert not a.single_c4_bdf or a.deploy_only, 'C4 deployment uses isolated runner for samples'
    assert not a.opt4_fit_receipt or (a.deploy_only and a.single_c4_bdf==TARGET_BDF and not a.run_only)
    (D/'locks').mkdir(exist_ok=True)
    maintenance=(D/'locks/maintenance-0000_21_00.0.lock').open('a');fcntl.flock(maintenance,fcntl.LOCK_EX|fcntl.LOCK_NB)
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    label='C4-single-' if a.single_c4_bdf else ('Native-C4-' if a.pair else ('Native-single-' if a.single_native_bdf else 'Native-'))
    batch=D/'batches'/(label+stamp);batch.mkdir(parents=True)
    try:
        if not a.run_only:
            deploy_native(batch,pair=a.pair,single_c4_bdf=a.single_c4_bdf,single_native_bdf=a.single_native_bdf,opt4_fit_receipt=a.opt4_fit_receipt)
        else:
            latest=json.loads((D/'latest-deployment.json').read_text());assert latest['configuration']=='Native' and latest['status']=='DEPLOYED_NOT_RUN'
            save(batch/'deployment.json',latest)
        if a.deploy_only:return 0
        if not native_sample(batch,'smoke','test'):return 2
        if not native_sample(batch,'blackscholes','test'):return 2
        return 0
    except Exception as exc:
        save(batch/'FAILED.json',dict(error=repr(exc),utc=dt.datetime.now(dt.timezone.utc).isoformat()))
        print(repr(exc),flush=True)
        raise
    finally:
        for root,dirs,files in os.walk(batch):
            os.chown(root,UID,GID)
            for name in files:os.chown(Path(root)/name,UID,GID)


if __name__=='__main__':raise SystemExit(main())
