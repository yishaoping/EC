#!/usr/bin/env python3
"""Bind repaired network ELFs and probe complete original ROI offline only."""
import copy
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import subprocess
import sys
from board_batch import W, D, save, sha
from job_service import proc
from network_binding import candidate

R=D/'software/network-complete-roi-probe.json'


def main():
    lock=(D/'software/network-complete-roi-probe.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    st=json.loads(R.read_text()) if R.exists() else dict(status='PREPARING',cases={},commands=[])
    if st['status']=='COMPLETE_OFFLINE_WITH_PROTOCOL_BLOCKERS':return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=Path(st.setdefault('work_dir',str(W/'software'/('network-complete-roi-'+stamp))))
    logs=Path(st.setdefault('log_dir',str(D/'software'/('network-complete-roi-'+stamp))))
    out.mkdir(exist_ok=True);logs.mkdir(exist_ok=True)
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        hardware_commit='8491167d84b6d9521b151a743673c1516926a1f8',hardware_modified=False,
        fpga_execution=False,formal_eligible=False,scheduler_modified=False)
    save(R,st)
    def run(label,argv,timeout=300):
        log=logs/(label+'.log')
        with log.open('ab',buffering=0) as stream:
            child=subprocess.Popen(list(map(str,argv)),stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,start_new_session=True,
                env={**os.environ,'PYTHONPATH':str(W/'scripts'),'EC_NETWORK_NO_TRACE':'0'})
            st.update(status='RUNNING',stage=label,child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(R,st)
            try:rc=child.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                import signal
                os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);rc=124
            os.fsync(stream.fileno())
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        st['commands'].append(dict(label=label,argv=list(map(str,argv)),returncode=rc,log=str(log)));save(R,st)
        return rc
    try:
        _,base=candidate(W/'software/network-candidate-build.json')
        joined=json.loads((D/'software/netferret-stable-joined-candidate-state.json').read_text())
        repaired=json.loads(Path(joined['receipt']).read_text())
        review=D/'software/network-recovery-20261109T043612Z/netferret-stable-joined-candidate-offline-review.json'
        checked=json.loads(review.read_text());assert checked['receipt']['sha256']==sha(joined['receipt'])
        assert all(all(v for v in c['gates'].values()) for c in checked['cases'].values())
        hooks=Path(json.loads((W/'software/apps-build.json').read_text())['output_dir'])
        server=out/'netferret-runtime/server/parsec/bin/ferret-pthreads';server.parent.mkdir(parents=True,exist_ok=True)
        link=next(c['argv'] for c in joined['commands'] if c['label']=='build-link')
        diagnostic=repaired['programs']['netferret']['binaries']['server/parsec/bin/ferret-pthreads']['path']
        argv=[str(server) if x==diagnostic else x for x in link if not x.endswith('/diagnostic-hooks.o')]
        argv += [str(hooks/'hooks.o'),str(hooks/'dac_roi.o')]
        if not server.exists():assert run('netferret-real-hooks-link',argv,120)==0
        real_bins=copy.deepcopy(repaired['programs']['netferret']['binaries']);real_bins['server/parsec/bin/ferret-pthreads']=dict(path=str(server),sha256=sha(server))
        st['netferret_real_hooks']=dict(profile='netferret-stable-joined-real-hooks/1',binaries=real_bins,
            source_receipt=dict(path=joined['receipt'],sha256=sha(joined['receipt'])),
            offline_reference=dict(path=str(review),sha256=sha(review)),roi_objects={str(hooks/n):sha(hooks/n) for n in ['hooks.o','dac_roi.o']},
            original_roi_preserved=True,algorithm_objects_unchanged=True,runtime_validation='NOT_RUN',real_checker_validated=False,formal_eligible=False)
        save(logs/'netferret-real-hooks.json',st['netferret_real_hooks']);save(R,st)
        template=(W/'scripts/validate_network_candidates.py').read_text()
        for name in ['netdedup','netferret','netstreamcluster']:
            if name in st['cases']:continue
            receipt=(json.loads((W/'software/netdedup-framed-candidate-build.json').read_text()) if name=='netdedup' else repaired if name=='netferret' else base)
            tree=out/('diagnostic-'+name);tree.mkdir(exist_ok=True)
            # Present immutable exact ELFs in the path layout the existing
            # validator expects; never modify the original software tree.
            for rel,b in receipt['programs'][name]['binaries'].items():
                assert sha(b['path'])==b['sha256']
                p=tree/name/rel;p.parent.mkdir(parents=True,exist_ok=True)
                if not p.exists():p.symlink_to(b['path'])
            pinned=copy.deepcopy(receipt);pinned['output_dir']=str(tree)
            pin=tree/'receipt.json';save(pin,pinned)
            text=template.replace("W/'software/network-candidate-build.json'",repr(str(pin)))
            if name=='netferret':
                text=text.replace("peers=[('server',server),('client',client)] if arch=='riscv64-kernel' else [('client',client),('server',server)]", "peers=[('server',server),('client',client)]")
                anchor="            if arch=='riscv64-kernel' and label=='server':"
                text=text.replace(anchor,"""            if arch=='riscv64' and label=='server':
                deadline=time.monotonic()+30
                while 'EC_NET_LISTEN_READY' not in (out/'server.log').read_text(errors='replace'):
                    assert p.poll() is None, 'server exited before readiness'
                    if time.monotonic()>deadline: raise TimeoutError('private user TCP listen readiness')
                    time.sleep(.05)
"""+anchor)
            script=tree/'probe.py';script.write_text(text)
            case_dir=logs/name;case_dir.mkdir(exist_ok=True)
            if (case_dir/'result.json').exists():
                prior_result=json.loads((case_dir/'result.json').read_text())
                assert prior_result['source_receipt_sha256']==sha(pin), 'resume receipt changed'
                rc=0 if prior_result['status']!='FAILED_WITH_EVIDENCE' else 2
            else:
                rc=run(name+'-full-original-roi-test',['unshare','--ipc','--mount','--net','--fork',sys.executable,script,
                    '--case',name,'--size','test','--out',case_dir],timeout=240)
            result=json.loads((case_dir/'result.json').read_text())
            text=(case_dir/'server.log').read_text(errors='replace')
            # Marker writes delimit the same original application ROI. Their
            # write syscall is diagnostic-only; do not count it as workload.
            start=text.index('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN');end=text.index('EC_NETWORK_DIAGNOSTIC_ROI_END',start)
            region=text[start:end]
            calls=re.findall(r'(?m)^(\d+)\s+([A-Za-z_]\w*)\((.*?)$',region)
            first={}
            for tid,op,args in calls:
                if op=='write' and 'EC_NETWORK_DIAGNOSTIC' in args:continue
                first.setdefault(op,dict(tid=tid,example=op+'('+args[:250]))
            counts={n:sum(op==n for _,op,_ in calls) for n in sorted(first)}
            complete=rc==0 and result['status']!='FAILED_WITH_EVIDENCE'
            if name=='netdedup':exact=complete and result['correctness']['passed']
            elif name=='netferret':exact=complete and result['output']['sha256']==checked['cases']['test']['candidate_output']['sha256']
            else:
                linux=json.loads((D/'software/network-linux-validation.json').read_text())
                prior=next(c for c in linux['cases'] if c['program']=='netstreamcluster' and c['input']=='test')
                prior_result=json.loads(Path(prior['result']).read_text())
                exact=complete and prior_result['exact_qemu_user_output'] and result['output']['sha256'] in prior_result['observed_output_hashes']
            st['cases'][name]=dict(status='OFFLINE_PROTOCOL_OUTPUT_AND_TRACE_PASSED' if exact else 'FAILED_WITH_EVIDENCE',
                result=str(case_dir/'result.json'),result_sha256=sha(case_dir/'result.json'),original_roi_complete=complete,
                exact_output_or_full_decode=exact,diagnostic_only=True,formal_eligible=False,
                roi_syscall_counts=counts,first_syscall_examples=first,qemu_trace_prefix_ids=sorted(set(t for t,_,_ in calls)),
                trace_precision='Observed calls matched between full original ROI markers; QEMU multithread text can interleave, so counts are not exhaustive and prefix IDs are not guest TIDs.',
                diagnostic_receipt=dict(path=str(pin),sha256=sha(pin)),validator_sha256=sha(script))
            save(R,st)
        sources=[W/'software/C4/linux/drivers/misc/ec_dac_roi.c',W/'software/C4/opensbi/lib/sbi/ec_opt4.c',
            W/'software/C4/opensbi/lib/sbi/ec_opt4_entry.S',W/'C4/chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala']
        st['protocol_source_bindings']={str(p):sha(p) for p in sources}
        if st.get('error'):st.setdefault('resolved_attempt_errors',[]).append(st.pop('error'))
        st.update(status='COMPLETE_OFFLINE_WITH_PROTOCOL_BLOCKERS',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
            source_proven_limits=['dac_begin rejects multithread process and any second context per boot',
                'DacRoiController records fault8 on traps/non-U privilege/satp changes across complete ROI',
                'OpenSBI accepts only first context; unknown op is ENOTSUPP, no pause/resume epoch operation',
                'Checker service unexpected trap is fault+park, not Linux syscall dispatch'],
            software_only_auxiliary_options=['preallocate resident buffers before ROI','replace auxiliary time queries with a defined common clock outside ROI'],
            unresolved_essential_operations='User TCP receive workers, pthread synchronization/scheduling and original network computation remain in ROI; moving them out or excluding syscall gaps would change required workload/measurement.',
            resolution='No existing software-only pause/re-arm path can preserve full original ROI under this monitor. A complete supported context/trap protocol requires a separately versioned integration/observer design and bitstream validation, or a proven entirely user-mode cooperative implementation retaining all network semantics. Neither is claimed implemented.',
            fpga_admission='BLOCKED_COMPLETE_ORIGINAL_ROI_CONTEXT_PROTOCOL')
        save(R,st);save(logs/'result.json',st)
    except Exception as exc:
        st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st);raise


if __name__=='__main__':main()
