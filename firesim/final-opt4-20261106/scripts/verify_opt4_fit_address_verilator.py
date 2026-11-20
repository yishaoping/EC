#!/usr/bin/env python3
"""Resume only failed address comparison with full-size pinned module RTL."""
from pathlib import Path
import datetime,fcntl,json,os,shutil,signal,subprocess,time
from board_batch import W,D,save,sha
from job_service import audit,proc

O=D/'build-logs/Opt4-fit-modules-20261110/address-verilator'
S=D/'Opt4-fit-address-verilator-state.json'
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-address-verilator.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    spec=json.loads((W/'scripts/job-specs/opt4-fit-verification.json').read_text())
    previous=audit(spec)
    assert not any(r['identity_live'] or r['identity_uncertain'] for s in previous['states'] for r in s['processes']), 'prior verifier still live; no duplicate'
    old=json.loads((D/'Opt4-fit-verification-state.json').read_text())
    assert old['status']=='FAILED_WITH_EVIDENCE' and 'address-compile offline timeout' in old['error']
    O.mkdir(exist_ok=True);save(O/'previous-verifier-audit.json',previous)
    save(O/'previous-verifier-state.json',old)
    shutil.copy2(D/'jobs/opt4-fit-verification/console.log',O/'previous-verifier-console.log')
    st=dict(schema='ec-opt4-fit-address-verilator/1',status='PREPARING',pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        started_utc=now(),fpga_access=False,formal_admission=False,full_design_proof=False,
        fit_commit='7007c37d35aa9974cfe5a98e64a9b98bd71e0638',
        reason='Icarus compilation reached configured 1800-second timeout without producing a comparison result; not an RTL mismatch. Reuse unchanged 52-output testbench and full-size original/candidate modules.')
    save(S,st)
    build=json.loads((D/'Opt4-fit-modules-state.json').read_text())
    src=O.parent/'verification'
    for name in ['address-original.v','address-fit.v','address-tb.v']:
        shutil.copy2(src/name,O/name)
    assert sha(O/'address-fit.v')==build['modules']['fit-address']['rtl_sha256']
    assert (O/'address-original.v').read_text().replace('module PackageAddressStats_original(', 'module PackageAddressStats(',1)==Path(build['modules']['baseline-address']['rtl']).read_text()
    st['inputs']={name:sha(O/name) for name in ['address-original.v','address-fit.v','address-tb.v']}
    tool=shutil.which('verilator');assert tool
    st['tool_version']=subprocess.check_output([tool,'--version'],text=True).strip();save(S,st)
    def run(label,argv,timeout):
        st.update(status=label.upper());save(S,st)
        with (O/(label+'.log')).open('ab',buffering=0) as f:
            p=subprocess.Popen(argv,cwd=O,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},
                stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            st.update(child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks'],active_argv=list(map(str,argv)));save(S,st)
            start=time.monotonic()
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now());save(S,st);os.fsync(f.fileno())
                if time.monotonic()-start>timeout:
                    os.killpg(p.pid,signal.SIGTERM)
                    try:p.wait(timeout=20)
                    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                    raise RuntimeError(label+' offline group timeout')
            assert p.returncode==0,(label,p.returncode)
    run('compile',['nice','-n','15',tool,'--binary','--timing','--top-module','tb','--Mdir',str(O/'obj'),
        '-j','8','--output-split','10000','--output-split-cfuncs','200','--x-initial','0','--x-assign','0',
        '-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0',
        str(O/'address-original.v'),str(O/'address-fit.v'),str(O/'address-tb.v')],3600)
    run('compare',['nice','-n','15',str(O/'obj/Vtb')],1800)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in (O/'compare.log').read_text()
    st.update(status='PASS_FULL_SIZE_6144_CYCLE_COMPARISON_NOT_FORMAL',ended_utc=now(),vectors=6144,
        outputs_per_cycle=52,log_sha256=sha(O/'compare.log'),executable_sha256=sha(O/'obj/Vtb'))
    save(S,st);print(json.dumps(st),flush=True)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
        raise
