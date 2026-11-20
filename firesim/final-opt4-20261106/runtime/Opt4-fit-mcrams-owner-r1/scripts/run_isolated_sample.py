import sys
from pathlib import Path as _BundlePath
sys.path.insert(0,str(_BundlePath(__file__).resolve().parent))
sys.path.insert(1,'/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""One device-bound real FPGA sample. Never performs global maintenance."""
import argparse,datetime as dt,fcntl,hashlib,json,os,re,signal,subprocess,sys,time
from pathlib import Path
from board_batch import W,D,BDFS,SERIALS,sha,save,precheck
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from inspect_roi_raw import inspect_bytes
RUNNER_SOURCE=Path(__file__).read_bytes()

def verify(out,identity,exitcode,controlled_stop,timedout):
    uart=(out/'uart.log').read_text(errors='replace').replace('\r','');rid=identity['run_id'];issues=[]
    if uart.count('EC_SAMPLE_GUEST_DONE run_id='+rid+' ')!=1:issues.append('missing unique successful output validation')
    if not re.search(r'^EC_COMMAND_EXIT=0$',uart,re.M):issues.append('missing successful application command exit')
    if 'Kernel panic' in uart or 'EC_OPT4_INVALID' in uart or 'EC_SAMPLE_FAILED' in uart:issues.append('guest failure/scope violation')
    if timedout:issues.append('host timeout')
    if exitcode!=0 and not controlled_stop:issues.append('unexpected driver exit')
    counts=None;raw=None;cycles=None;drain=None;participation=None
    if identity['configuration']=='Native':
        journal=(out/'roi-raw.jsonl').read_bytes() if (out/'roi-raw.jsonl').exists() else None
        prefix=0
        if journal and identity.get('host_bridge_restart'):
            try:
                lines=journal.splitlines(keepends=True);values=[json.loads(line) for line in lines]
                prefix=max(i for i,v in enumerate(values) if v['under_reset']==1)
                origin=values[prefix]['sequence'];segment=[]
                for v in values[prefix:]:
                    v['sequence']-=origin;segment.append((json.dumps(v)+'\n').encode())
                raw=inspect_bytes(b''.join(segment));raw['excluded_pre_reset_records']=prefix
                raw['original_journal_sha256']=sha(out/'roi-raw.jsonl')
            except (ValueError,KeyError):issues.append('missing fresh target reset in restarted bridge journal')
        else:raw=inspect_bytes(journal) if journal else None
        epochs=[e for e in raw['epochs'] if e['source_boundaries_complete']] if raw else []
        if raw is None or raw['protocol_issues'] or raw['partial_tail_bytes'] or len(epochs)!=1:issues.append('incomplete Native ROI boundaries/transport')
        else:cycles=epochs[0]['roi_cycles'];drain=0
    else:
        snapshots=re.findall(r'EC_OPT4_SNAPSHOT ([^\n]*)',uart)
        def fields(s):return dict(re.findall(r'(\w+)=\s*([0-9a-fA-F]+)',s))
        try:
            assert len(snapshots)==2
            f=fields(snapshots[-1]);counts={k:int(f[k]) for k in ['epoch','begin','end','drain','generated','completed','outstanding','faults','passed','failed','cancelled','dropped']}
            assert counts['end']>counts['begin'] and counts['drain']>=counts['end']
            assert counts['generated']>0 and counts['generated']==counts['completed']==counts['passed']
            assert not any(counts[k] for k in ['outstanding','faults','failed','cancelled','dropped'])
            cycles=counts['end']-counts['begin'];drain=counts['drain']-counts['end']
        except (AssertionError,KeyError,ValueError):issues.append('invalid/missing positive checker accounting and drain')
        contexts=re.findall(r'EC_OPT4_CONTEXT .*satp=([0-9a-f]+).*hardware_initialized=1',uart)
        installed=re.findall(r'EC_OPT4_INSTALLED hart=(\d+) satp=([0-9a-f]+)',uart)
        parked=re.findall(r'EC_OPT4_CONTEXT_DRAINED ([^\n]*)',uart)
        try:
            assert len(contexts)==1 and len(installed)==4 and {int(h) for h,s in installed}=={1,2,3,4}
            assert all(int(s,16)==int(contexts[0],16) for h,s in installed)
            assert len(parked)==1 and counts is not None
            p=fields(parked[0]);assert int(p['firmware'],16)==15 and int(p['satp'],16)==int(contexts[0],16)
            assert all(int(p[k])==counts[k] for k in ['epoch','generated','completed','outstanding'])
        except (AssertionError,KeyError,ValueError):issues.append('missing matching installed/parked checker context')
        events=''.join(p.read_text(errors='replace') for p in sorted(out.glob('rtl-events-*')) if p.is_file())
        if re.search(r'Assertion failed|%Error',events):issues.append('RTL assertion')
        begins=re.findall(r'EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)',events)
        results=re.findall(r'EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=\s*([01]) cancelled=\s*([01])',events)
        pending={};pairs=0
        # Each hart has a single package owner; ordering is per source print stream.
        for line in events.splitlines():
            b=re.search(r'EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)',line)
            r=re.search(r'EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=\s*([01]) cancelled=\s*([01])',line)
            if b:
                h,q,s,p=b.groups();key=(int(h),int(q,16))
                if key in pending:issues.append('duplicate task BEGIN')
                pending[key]=1
                if not contexts or int(s,16)!=int(contexts[0],16) or int(p)!=0 or int(h) not in range(1,5):issues.append('task context/hart mismatch')
            if r:
                h,q,s,c,x=r.groups();key=(int(h),int(q,16))
                if key not in pending:issues.append('task RESULT without matching BEGIN')
                else:del pending[key];pairs+=1
                if (int(s),int(c),int(x))!=(0,1,0):issues.append('task failed/cancelled or lacks true full comparison')
        if pending or not pairs or counts is None or pairs!=counts.get('generated') or len(begins)!=pairs or len(results)!=pairs:issues.append('incomplete real task event coverage')
        participation=dict(begins=len(begins),results=len(results),matched_pairs=pairs,unfinished=len(pending),strict_latency=None)
    host=(out/'host.log').read_text(errors='replace')
    efficiency=None
    interval=re.findall(r'EC_HOST_INTERVAL target_start=(\d+) target_end=(\d+) target_delta=(\d+) host_delta=(\d+) wall_seconds=([0-9.]+) throughput_cycles_per_second=([0-9.]+)',host)
    if len(interval)==1:
        start,end,delta,hdelta,seconds,hz=interval[0]
        efficiency=dict(target_start=int(start),target_end=int(end),target_delta=int(delta),host_delta=int(hdelta),host_simulation_wall_seconds=float(seconds),simulation_throughput_cycles_per_second=float(hz),measurement_scope='host simulation efficiency, separate from architecture ROI')
        if int(end)-int(start)!=int(delta) or float(seconds)<=0:issues.append('invalid host efficiency counters')
    rb=re.findall(r'EC_FASED_READBACK key=(\w+) expected=(\d+) actual=(\d+)',host)
    expected=identity['memory_model']['settings'];seen={k:int(a) for k,e,a in rb if e==a}
    if seen!=expected:issues.append('FASED settings not fully read back')
    traffic_records=re.findall(r'EC_OPT4_TRAFFIC index=(\d+) value=(\d+)',uart)
    traffic={int(i):int(v) for i,v in traffic_records}
    if traffic_records and (len(traffic_records)!=128 or set(traffic)!=set(range(128))):issues.append('incomplete/duplicate post-drain traffic counter readback')
    return dict(valid=not issues,issues=sorted(set(issues)),roi_cycles=cycles,drain_cycles=drain,counts=counts,raw=raw,participation=participation,post_drain_traffic_counters=traffic,
                checker_latency=None,guest_power_down_observed='Power down' in uart,fased_readback=seen,host_efficiency=efficiency)

def run(a):
    if a.bdf != BDFS[0]:raise ValueError('Only 0000:21:00.0 is authorized')
    assert os.geteuid()==0
    maintenance=(D/'locks/maintenance-0000_21_00.0.lock').open('a');fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
    lock=(D/'locks'/('card-'+a.bdf.replace(':','_')+'.lock')).open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    from opt4_fit_runtime_guard import priority_guard,sample_binding,add_identity
    fit_receipt=getattr(a,'opt4_fit_receipt',None)
    priority_guard(fit_receipt)
    cfg=a.configuration;native=json.loads((W/'native-reuse.json').read_text());fwpath=a.firmware_receipt or W/'software'/cfg/'firmware-build.json'
    fw=json.loads(fwpath.read_text());driver_path=a.driver_receipt or W/'runtime'/(cfg+'-observed-driver.json');dr=json.loads(driver_path.read_text())
    dtpath=next(Path(p) for p in fw['input_files'] if p.endswith('.json') and 'fdt' in Path(p).name)
    # Old payload receipts referenced a mutable variant pointer. Its original
    # DTB directory retains the immutable build manifest; use exact payload DTB.
    fdt=json.loads(dtpath.read_text())
    actual_fdt=Path(fw['content_checks']['fdt']['path'])
    if fdt['sha256']!=fw['content_checks']['fdt']['sha256']:
        fdt=json.loads((actual_fdt.parent/'manifest.json').read_text())
    assert fdt['sha256']==fw['content_checks']['fdt']['sha256'] and sha(actual_fdt)==fdt['sha256']
    assert not (a.formal and (fw.get('diagnostic_only') or a.diagnostic_trace)), 'diagnostic image/trace cannot be formal'
    exe=Path(dr['output_dir'])/'FireSim-xilinx_alveo_u280';elf=Path(fw['output_dir'])/'platform/generic/firmware/fw_payload.elf'
    assert dr['returncode']==0 and fw['returncode']==0 and sha(exe)==dr['outputs'][str(exe)] and sha(elf)==fw['outputs'][str(elf)]
    apps_path=a.apps_receipt or W/'software/apps-build.json';rootfs_path=a.rootfs_receipt or W/'software/rootfs-build.json'
    apps=json.loads(apps_path.read_text());rootfs=json.loads(rootfs_path.read_text());memory=json.loads((W/'runtime/fased-common/manifest.json').read_text())
    assert a.program=='smoke' or a.program in apps['binaries'], 'program absent from bound software manifest'
    assert not (a.formal and apps.get('formal_eligible') is False), 'this software profile is not eligible for formal performance results'
    assert rootfs['apps_manifest_sha256']==sha(apps_path), 'rootfs/apps receipt mismatch'
    assert sha(rootfs['path'])==rootfs['sha256']
    kernel_path=next(Path(p) for p in fw['input_files'] if p.endswith('.json') and 'kernel' in Path(p).name)
    kernel=json.loads(kernel_path.read_text())
    assert kernel['input_files'].get(rootfs['path'])==rootfs['sha256'], 'firmware kernel embeds different rootfs'
    deployment=json.loads((D/'latest-deployment.json').read_text());assert deployment['status']=='DEPLOYED_NOT_RUN'
    assert deployment.get('host_boot_id')==Path('/proc/sys/kernel/random/boot_id').read_text().strip(), 'deployment receipt predates current host boot; recheck and deploy existing bitstream'
    if fit_receipt:
        assert cfg=='C4'
        fit=sample_binding(fit_receipt,driver_path,fwpath,apps_path,rootfs_path,a.program)
        bitsha=fit['durable_bitstream_sha256']
    else:
        bitsha=next(h for p,h in native['verified_artifacts'].items() if p.endswith('.bit')) if cfg=='Native' else json.loads((W/'bitstream-build.json').read_text())['durable_bitstream_sha256']
    card=next(c for c in deployment['completed_cards'] if c['bdf']==a.bdf);assert card['bitstream_sha256']==bitsha
    assert card['configuration']==cfg and card['source_id']==dr['hardware_source_id'], 'driver/hardware lineage mismatch'
    if fit_receipt:
        assert card['hardware_commit']==fit['hardware_commit'] and card['hardware_profile']==fit['profile']
        assert card['derived_build_receipt_sha256']==sha(fit_receipt)
    generation=deployment['started_utc']+'|'+a.bdf+'|'+bitsha
    consumed_path=D/('consumed-'+a.bdf.replace(':','_')+'.json')
    probe_previous=None
    deployment_reuse_validated=False
    deployment_reuse_receipt=None
    if consumed_path.exists() and not dr.get('supports_target_restart'):
        consumed=json.loads(consumed_path.read_text())
        if consumed['deployment_generation']==generation:
            previous_run=Path(consumed['run_dir'])
            previous_state=json.loads((previous_run/'state.json').read_text())
            previous_result=json.loads((previous_run/'result.json').read_text())
            previous_complete=json.loads((previous_run/'complete.json').read_text())
            assert previous_state['status']=='COMPLETE' and previous_result['valid']
            assert sha(previous_run/'result.json')==previous_complete['result_sha256']
            assert previous_result['identity']['configuration']=='C4'
            assert previous_result['identity']['board_bdf']==a.bdf
            assert previous_result['identity']['bitstream_sha256']==bitsha
            assert previous_result['identity']['driver_sha256']==sha(exe)
            assert previous_result['guest_power_down_observed'], 'previous guest did not prove clean target shutdown'
            reset=previous_result.get('target_reset_validation') or consumed.get('target_reset_validation',{})
            deployment_reuse_validated=(reset.get('status')=='VALIDATED'
                and reset.get('deployment_generation')==generation
                and reset.get('board_bdf')==a.bdf
                and reset.get('bitstream_sha256')==bitsha
                and reset.get('driver_sha256')==sha(exe)
                and reset.get('current_guest_booted')
                and reset.get('current_guest_power_down'))
            if deployment_reuse_validated:
                deployment_reuse_receipt=reset
                proof_path=D/'runs'/reset['run_id']/'result.json'
                proof=json.loads(proof_path.read_text())
                proof_complete=json.loads((proof_path.parent/'complete.json').read_text())
                assert proof['valid'] and sha(proof_path)==proof_complete['result_sha256']
                assert proof['target_reset_validation']==reset, 'reset validation proof mismatch'
            if not deployment_reuse_validated:
                assert a.target_reset_probe and cfg=='C4', 'same deployment reuse requires a guarded C4 target-reset probe'
                probe_previous=previous_run
        else:
            assert not a.target_reset_probe, 'target-reset probe only applies to the current deployment'
    else:
        assert not a.target_reset_probe, 'target-reset probe requires a previous sample on the same deployment'
    check=precheck(target_bdfs=[a.bdf])
    conflicts=[x for x in check['open_devices'] if a.bdf in json.dumps(x)]
    # Device nodes must be resolved to the actual current BDF: XDMA numbering changes after re-enumeration.
    current=Path('/sys/bus/pci/devices')/a.bdf/'xdma'
    xdma_ids={re.match(r'(xdma\d+)_',p.name)[1] for p in current.iterdir() if re.match(r'(xdma\d+)_',p.name)}
    conflicts += [x for x in check['open_devices'] if any('/dev/'+xid+'_' in json.dumps(x) for xid in xdma_ids)]
    assert not conflicts,conflicts
    prefix='opt4-fit-3656aec4-mcrams' if fit_receipt else cfg.lower()
    rid=f'{prefix}-{a.program}-{a.input}-r{a.repetition}-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=D/'runs'/rid;out.mkdir()
    case=next((c for c in apps['cases'] if c['program']==a.program and c['input']==a.input),None)
    assert a.program=='smoke' or case is not None, 'application/input absent from bound rootfs'
    ident=dict(run_id=rid,configuration=cfg,board_bdf=a.bdf,board_serial=SERIALS[BDFS.index(a.bdf)],program=a.program,input=a.input,repetition=a.repetition,
               hardware_commit='8491167d84b6d9521b151a743673c1516926a1f8' if cfg=='C4' else None,hardware_source_id=dr['hardware_source_id'],bitstream_sha256=bitsha,
               driver_sha256=sha(exe),driver_receipt_sha256=sha(driver_path),firmware_sha256=sha(elf),firmware_receipt_sha256=sha(fwpath),apps_manifest_sha256=sha(apps_path),
               rootfs_sha256=rootfs['sha256'],elf_sha256=apps['smoke']['sha256'] if a.program=='smoke' else apps['binaries'][a.program]['sha256'],case=case,
               memory_model={k:memory[k] for k in ['model','settings']},threads=1,warmups=0,target_boom_hz=200000000,target_checker_hz=100000000 if cfg=='C4' else None,
               formal=a.formal,target_reset_probe=a.target_reset_probe,software_profile=apps.get('software_profile','original-parsec-serial'),
               previous_run_id=probe_previous.name if probe_previous else None)
    ident.update(linux_memory_cap_bytes=fdt['linux_mem_cap'],linux_bootargs=fdt['bootargs'],fdt_sha256=fdt['sha256'],software_diagnostic=fw.get('diagnostic_only',False))
    ident['host_bridge_restart']=bool(dr.get('supports_target_restart'))
    if fit_receipt:add_identity(ident,fit_receipt)
    iid=hashlib.sha256(json.dumps(ident,sort_keys=True).encode()).hexdigest();uartin=out/'uart.in';uartin.write_bytes(b'')
    domain,bus,devfn=a.bdf.split(':');device,function=devfn.split('.')
    argv=[str(exe),'+permissive',f'+domain={domain}',f'+bus={bus}',f'+device={device}',f'+function={function}','+bar=0','+pci-vendor=10ee','+pci-device=903f',
          '+uart-in0='+str(uartin),'+uart-out0='+str(out/'uart.log'),'+fesvr-step-size=2004765',*memory['plusargs']]
    argv += ['+ec-dac-roi-log='+str(out/'roi-raw.jsonl'),'+ec-dac-snapshot-seconds=30'] if cfg=='Native' else ['+print-file='+str(out/'rtl-events-')]
    if a.diagnostic_trace:
        assert not a.formal
        argv += ['+tracefile='+str(out/'diagnostic-trace'),'+trace-select=1',
                 '+trace-start='+str(a.trace_start),'+trace-end='+str(a.trace_start+10000),'+trace-output-format=0']
    argv += ['+permissive-off','+prog0='+str(elf)]
    (out/'runner-source.py').write_bytes(RUNNER_SOURCE)
    parser_path=Path(inspect_bytes.__code__.co_filename)
    (out/'roi-parser-source.py').write_bytes(parser_path.read_bytes())
    save(out/'manifest.json',dict(schema='ec-isolated-fpga-sample/1',identity=ident,identity_sha256=iid,argv=argv,runner_sha256=hashlib.sha256(RUNNER_SOURCE).hexdigest(),roi_parser_sha256=sha(out/'roi-parser-source.py'),deployment=deployment,precheck=check,
                                target_reset_probe_previous=str(probe_previous) if probe_previous else None))
    state=dict(schema='ec-isolated-fpga-sample-state/1',status='STARTING',identity_sha256=iid,run_id=rid,sequence=0,
               configuration=cfg,board_bdf=a.bdf,board_serial=ident['board_serial'],program=a.program,
               input=a.input,repetition=a.repetition,host_boot_id=deployment['host_boot_id'],
               started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    start=time.monotonic();sent=False;shutdown=False;done_at=None;controlled=False;timedout=False;last=-30;log_budget_exceeded=False
    with (out/'host.log').open('wb',buffering=0) as f:
        consumed_record=dict(deployment_generation=generation,run_id=rid,run_dir=str(out),
                             requires_unified_redeployment_before_next_guest=True)
        if deployment_reuse_receipt:
            consumed_record['target_reset_validation']=deployment_reuse_receipt
        save(consumed_path,consumed_record)
        child=subprocess.Popen(['nice','-n','10','/usr/bin/stdbuf','-oL','-eL',*argv],cwd=out,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'PATH':'/usr/local/bin:/usr/bin:/bin','LD_LIBRARY_PATH':''})
        state.update(status='RUNNING',pid=child.pid,pgid=child.pid,start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21]);save(out/'state.json',state)
        save(D/('active-'+a.bdf.replace(':','_')+'.json'),dict(run_dir=str(out),**state));print(json.dumps(dict(run_id=rid,pid=child.pid,log=str(out/'uart.log'))),flush=True)
        while child.poll() is None:
            elapsed=time.monotonic()-start;u=(out/'uart.log').read_bytes() if (out/'uart.log').exists() else b''
            if not sent and b'EC_GUEST_READY' in u:
                with uartin.open('ab',buffering=0) as inp:inp.write(f'/opt/ec-fpga/run-one {a.program} {a.input} {a.repetition} {rid}; echo EC_COMMAND_EXIT=$?\n'.encode());os.fsync(inp.fileno())
                sent=True
            if sent and not shutdown and re.search(rb'EC_COMMAND_EXIT=\d+\r?\n',u):
                with uartin.open('ab',buffering=0) as inp:inp.write(b'/bin/busybox sync; /bin/poweroff -f\n');os.fsync(inp.fileno())
                shutdown=True;done_at=elapsed
            if elapsed-last>=30:
                log_bytes=sum(p.stat().st_size for p in out.iterdir() if p.is_file())
                log_budget_exceeded=log_bytes>a.max_log_gib*2**30
                state.update(sequence=state['sequence']+1,elapsed_seconds=elapsed,guest_ready=sent,guest_command_ended=shutdown,uart_bytes=len(u),updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
                state.update(log_bytes=log_bytes,max_log_gib=a.max_log_gib)
                for p in out.iterdir():
                    if p.is_file() and p.suffix not in ['.tmp']:
                        os.chown(p,1008,1008)
                        fd=os.open(p,os.O_RDONLY);os.fsync(fd);os.close(fd)
                save(out/'snapshot.json',state);save(out/'state.json',state);save(D/('active-'+a.bdf.replace(':','_')+'.json'),dict(run_dir=str(out),**state));last=elapsed
            guest_fatal=b'Kernel panic' in u or b'EC_OPT4_INVALID' in u or b'EC_SAMPLE_FAILED' in u
            if elapsed>a.timeout or (not sent and elapsed>a.boot_timeout) or guest_fatal or log_budget_exceeded or (done_at is not None and elapsed-done_at>30):
                timedout=elapsed>a.timeout or (not sent and elapsed>a.boot_timeout);controlled=not timedout and b'Power down' in u
                os.killpg(child.pid,signal.SIGTERM)
                try:child.wait(timeout=15)
                except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
                break
            try:child.wait(timeout=.5)
            except subprocess.TimeoutExpired:pass
    result=verify(out,ident,child.returncode,controlled,timedout)
    if log_budget_exceeded:
        result['valid']=False;result['issues'].append('sample log budget exceeded; raw evidence retained')
    if a.target_reset_probe:
        if not result['guest_power_down_observed']:
            result['issues'].append('target-reset probe missing guest powerdown')
            result['valid']=False
        result['target_reset_validation']=dict(schema='ec-target-reset-validation/1',status='VALIDATED' if result['valid'] else 'FAILED',
            previous_run_id=ident['previous_run_id'],run_id=rid,deployment_generation=generation,board_bdf=a.bdf,
            bitstream_sha256=bitsha,driver_sha256=sha(exe),previous_guest_power_down=previous_result['guest_power_down_observed'],
            current_guest_booted=sent,current_guest_power_down=result['guest_power_down_observed'],
            criterion='new EC_GUEST_READY and valid C4 task/accounting/output chain after prior guest powerdown on unchanged deployment',
            deployment_reuse_authorized=result['valid'])
        save(out/'target-reset-validation.json',result['target_reset_validation'])
    # Finalize state before hashing evidence so committed state hashes remain
    # verifiable. A COMPLETE state alone is never an atomic sample commit.
    state.update(status='COMPLETE' if result['valid'] else 'TIMEOUT' if timedout else 'FAILED',issues=result['issues'],ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state)
    result.update(schema='ec-isolated-fpga-result/1',identity=ident,identity_sha256=iid,driver_returncode=child.returncode,driver_stop_after_guest_powerdown=controlled,
                  timedout=timedout,host_wall_seconds=time.monotonic()-start,fpga_execution=True,formal=a.formal,evidence={str(p):sha(p) for p in out.iterdir() if p.is_file()})
    save(out/'result.json',result)
    if result['valid']:
        save(out/'complete.json',dict(identity_sha256=iid,result_sha256=sha(out/'result.json'),formal=a.formal))
        if a.target_reset_probe:
            deployment_reuse_receipt=result['target_reset_validation']
        if deployment_reuse_receipt:
            save(consumed_path,dict(deployment_generation=generation,run_id=rid,run_dir=str(out),
                                    requires_unified_redeployment_before_next_guest=True,
                                    target_reset_validation=deployment_reuse_receipt))
    save(D/('active-'+a.bdf.replace(':','_')+'.json'),dict(run_dir=str(out),**state))
    for p in out.iterdir():
        if p.is_file():os.chown(p,1008,1008)
    os.chown(out,1008,1008)
    print(json.dumps(dict(run_id=rid,valid=result['valid'],roi_cycles=result['roi_cycles'],issues=result['issues'])),flush=True)
    return 0 if result['valid'] else 2
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('configuration',choices=['Native','C4']);p.add_argument('program');p.add_argument('input',choices=['test','simsmall','simmedium']);p.add_argument('--bdf',choices=BDFS,required=True);p.add_argument('--repetition',type=int,default=1);p.add_argument('--timeout',type=int,default=1800);p.add_argument('--formal',action='store_true');p.add_argument('--firmware-receipt',type=Path)
    p.add_argument('--diagnostic-trace',action='store_true')
    p.add_argument('--trace-start',type=int,default=100000000)
    p.add_argument('--apps-receipt',type=Path)
    p.add_argument('--rootfs-receipt',type=Path)
    p.add_argument('--driver-receipt',type=Path)
    p.add_argument('--target-reset-probe',action='store_true')
    p.add_argument('--opt4-fit-receipt',type=Path)
    p.add_argument('--boot-timeout',type=int,default=600)
    p.add_argument('--max-log-gib',type=float,default=4)
    raise SystemExit(run(p.parse_args()))
