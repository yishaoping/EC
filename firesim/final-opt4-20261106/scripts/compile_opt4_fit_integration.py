#!/usr/bin/env python3
"""Compile all five pinned modified sources together; no DUT elaboration/CAD."""
from pathlib import Path
import datetime,fcntl,json,os,signal,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc
from prepare_opt4_fit_modules import JAVA,CACHE,CPFILE

F=W/'Opt4-fit-20261110';O=D/'build-logs/Opt4-fit-modules-20261110/integration-compile'
S=D/'Opt4-fit-integration-compile-state.json'
COMMIT='8da24a269b98a0d6a8f57b030353a310812c4344'
now=lambda:datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-integration-compile.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True);classes=O/'classes';classes.mkdir(exist_ok=True)
    binding=json.loads((F/'bindings'/f'{COMMIT}.json').read_text())
    st=dict(status='COMPILING_PINNED_MODIFIED_SOURCES',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),fit_commit=COMMIT,
        source_id=binding['source_id'],started_utc=now(),fpga_access=False,full_dut_synthesis=False,
        full_dut_elaboration=False,formal_admission=False,source_snapshots={})
    paths=[]
    for rel in binding['changed_files']:
        p=O/'sources'/rel;p.parent.mkdir(parents=True,exist_ok=True)
        p.write_bytes(subprocess.check_output(['git','show',COMMIT+':'+rel],cwd=F))
        st['source_snapshots'][rel]=dict(snapshot=str(p),sha256=sha(p));paths.append(str(p))
    save(S,st)
    compiler=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar') for n in ['scala-compiler','scala-library','scala-reflect']]
    plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    cp=CPFILE.read_text().strip()
    argv=list(map(str,['nice','-n','15',JAVA,'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4',
        '-cp',':'.join(map(str,compiler)),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+str(plugin),'-d',classes]+paths))
    save(O/'command.json',dict(argv=argv,original_classpath_sha256=sha(CPFILE)))
    with (O/'compile.log').open('ab',buffering=0) as f:
        p=subprocess.Popen(argv,cwd=O,env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''},
            stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
        st.update(child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(S,st);start=time.monotonic()
        while p.poll() is None:
            try:p.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            st.update(updated_utc=now());save(S,st);os.fsync(f.fileno())
            if time.monotonic()-start>1800:
                os.killpg(p.pid,signal.SIGTERM);p.wait();raise RuntimeError('isolated Scala compile timeout')
        assert p.returncode==0,('compile',p.returncode)
    assert any(classes.rglob('InclusiveCache*.class')) and any(classes.rglob('SafePrefixScanner*.class'))
    st.update(status='PASS_FIVE_MODIFIED_SOURCES_COMPILE_ONLY',returncode=0,ended_utc=now(),
        wall_seconds=time.monotonic()-start,compile_log_sha256=sha(O/'compile.log'))
    save(S,st);print(json.dumps(st),flush=True)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(S,st)
        raise
