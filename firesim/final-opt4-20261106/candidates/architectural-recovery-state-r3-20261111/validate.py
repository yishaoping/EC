#!/usr/bin/python3
"""Source-bound, checkpointed recovery backend component validation. No FPGA."""
from pathlib import Path
import fcntl
import json
import os
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import read, save, sha, identity, live, now

O = D / 'build-logs/Opt4-architectural-recovery-state-r3-20261111'
S = D / 'Opt4-architectural-recovery-state-r3-state.json'

def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    previous = read(S)
    assert not live(previous) and not live(previous.get('child', {})), 'adopt live validation'
    cfg = read(C/'config.json')
    b = cfg['binding']
    assert all(sha(p) == h for p,h in read(C/'input-hashes.json').items())
    for p,relative in cfg['source_paths'].items():
        assert Path(p).read_bytes() == subprocess.check_output(
            ['git','show',b['hardware_commit']+':'+relative], cwd=b['worktree'])
    st = dict(schema='ec-opt4-recovery-backend-component-validation/1', **identity(),
              hardware_commit=b['hardware_commit'], source_id=b['source_id'],
              started_utc=now(), status='STARTING', stages={},
              fpga_access=False, full_dut_synthesis=False, production_selected=False,
              architectural_recovery_validated=False,
              limitation='Actual generated backend RTL with modeled external state/memory devices. Real BOOM rename/register/CSR, coherent cache/SVB, CDC, checker firmware and fault-injected whole-DUT integration still required.')
    save(S,st)
    def stage(name,args,outputs):
        receipt=O/(name+'-result.json')
        old=read(receipt)
        if old:
            assert old['returncode']==0 and old['source_id']==b['source_id']
            assert all(Path(p).is_file() and sha(p)==h for p,h in old['outputs'].items())
            st['stages'][name]=old
            return Path(old['log'])
        log=O/(name+'.log')
        assert not log.exists(), 'preserve failed stage; create versioned continuation'
        with log.open('xb',buffering=0) as stream:
            child=subprocess.Popen(list(map(str,['nice','-n','15',*args])),cwd=C,
                stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,
                env={**os.environ,'JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1','MAKEFLAGS':'-j2'})
            st.update(status='RUNNING_'+name.upper(),active_stage=name,
                      child=identity(child.pid),updated_utc=now());save(S,st)
            while child.poll() is None:
                try: child.wait(timeout=30)
                except subprocess.TimeoutExpired: pass
                st.update(updated_utc=now());save(S,st);os.fsync(stream.fileno())
        r=dict(returncode=child.returncode,source_id=b['source_id'],log=str(log),
               ended_utc=now(),outputs={str(p):sha(p) for p in outputs if p.is_file()})
        save(receipt,r);st['stages'][name]=r;st.update(child={},updated_utc=now());save(S,st)
        assert child.returncode==0 and all(p.is_file() for p in outputs),(name,str(log))
        return log
    classes=O/'classes';classes.mkdir(exist_ok=True)
    cp=':'.join(cfg['classpath'])
    stage('compile',[cfg['java'],'-Xmx6G','-XX:ActiveProcessorCount=2',
          '-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
          '-Xplugin:'+cfg['plugin'],'-d',classes,*cfg['source_paths'].keys(),C/'Emit.scala'],
          [classes/'opt4recovery/Emit.class'])
    tests={}
    for kind,top,expected in [('state','PackageRecoveryState','RECOVERY_STATE_PASS'),
                              ('memory','PackageRecoveryMemory','RECOVERY_MEMORY_PASS')]:
        rtl=O/kind;rtl.mkdir(exist_ok=True)
        verilog=rtl/(top+'.v')
        stage('emit-'+kind,[cfg['java'],'-Xmx6G','-XX:ActiveProcessorCount=2',
              '-cp',str(classes)+':'+cp,'opt4recovery.Emit',kind,rtl],[verilog])
        cpp=O/(kind+'-test.cpp')
        stage('generate-'+kind,['/usr/bin/python3',C/'generate_test.py',kind,cpp],[cpp])
        exe=O/(kind+'-obj')/('V'+top)
        stage('verilate-'+kind,['/usr/local/bin/verilator','--cc','--exe','--build',
              '--assert','--top-module',top,'--Mdir',exe.parent,'-j','2','-Wno-fatal',
              '-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',verilog,cpp],[exe])
        log=stage('test-'+kind,[exe],[])
        assert expected in log.read_text()
        tests[kind]=dict(summary=log.read_text().strip(),rtl_sha256=sha(verilog),
                         log=str(log),executable_sha256=sha(exe))
    st.update(status='PASS_RECOVERY_BACKEND_COMPONENTS_NOT_DUT_INTEGRATED',
              component_tests=tests,completed_utc=now())
    save(S,st);save(O/'result.json',st)

if __name__=='__main__':
    try: main()
    except Exception as exc:
        st=read(S)
        if st.get('pid')==os.getpid():
            st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
        raise
