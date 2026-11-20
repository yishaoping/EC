#!/usr/bin/env python3
"""Compile/elaborate only selected statistics modules in a versioned fit branch."""
from pathlib import Path
import datetime,fcntl,hashlib,json,os,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc

F=W/'Opt4-fit-20261110'
O=D/'build-logs/Opt4-fit-modules-20261110'
STATE=D/'Opt4-fit-modules-state.json'
JAVA=W.parent/'envs/manager-1.17.1/bin/java'
CACHE=W.parent/'dac2026/work/opt4-minimal-v2/cache/coursier/v1/https/repo1.maven.org/maven2'
CPFILE=D/'build-logs/C4-goldengate-20261106T100436.256198Z/firesim.classpath'

def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-modules.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    cp=CPFILE.read_text().strip()
    compiler=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar') for n in ['scala-compiler','scala-library','scala-reflect']]
    plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    assert all(p.is_file() for p in compiler+[plugin])
    commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
    st=dict(schema='ec-opt4-fit-modules/1',status='RUNNING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),fit_commit=commit,frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',fpga_access=False,full_dut_synthesis=False,formal_admission=False,modules={})
    save(STATE,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''}
    def command(name,argv,cwd,log):
        with log.open('ab',buffering=0) as f:
            p=subprocess.Popen(['nice','-n','10']+list(map(str,argv)),cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            st.update(active_step=name,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(STATE,st)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now());save(STATE,st);os.fsync(f.fileno())
        assert p.returncode==0,(name,p.returncode,str(log))
    for variant,root in [('baseline',W/'C4/chipyard'),('fit',F/'chipyard')]:
        for name,rel,ctor in [
          ('address','generators/boom/src/main/scala/lsu/PackageAddressStats.scala','new boom.lsu.PackageAddressStats(3,40,64,256)'),
          ('barrier','generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala','new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256)')]:
            key=variant+'-'+name;out=O/key;out.mkdir(exist_ok=True);classes=out/'classes';classes.mkdir(exist_ok=True)
            source=root/rel;copy=out/source.name
            copy.write_bytes(source.read_bytes())
            wrapper=out/'EmitStats.scala'
            wrapper.write_text('package opt4fit\nobject EmitStats extends App {\n(new chisel3.stage.ChiselStage).emitVerilog('+ctor+', Array("--target-dir", args(0)))\n}\n')
            record=dict(variant=variant,module=name,source=str(source),source_sha256=sha(source),source_snapshot=str(copy),out=str(out),fit_commit=commit if variant=='fit' else None,status='COMPILING',configuration=dict(commit_width=3,addr_bits=40,line_bytes=64,packet_window=256))
            st['modules'][key]=record;save(STATE,st)
            compile_argv=[JAVA,'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(map(str,compiler)),'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+str(plugin),'-d',classes,copy,wrapper]
            save(out/'command.json',dict(compile_argv=list(map(str,compile_argv)),runtime_classpath=str(classes)+':'+cp))
            command(key+'-compile',compile_argv,out,out/'compile.log')
            record['status']='ELABORATING';save(STATE,st)
            command(key+'-elaborate',[JAVA,'-Xmx20G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',str(classes)+':'+cp,'opt4fit.EmitStats',out],out,out/'elaborate.log')
            rtl=out/('PackageAddressStats.v' if name=='address' else 'GHBarrierLatencyStats.v')
            assert rtl.is_file()
            record.update(status='ELABORATED_MODULE_ONLY',rtl=str(rtl),rtl_sha256=sha(rtl),ended_utc=now())
            save(out/'receipt.json',record);save(STATE,st)
    st.update(status='ELABORATED_MODULES_ONLY',ended_utc=now());st.pop('child_pid',None);st.pop('child_start_ticks',None);save(STATE,st)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if STATE.exists():
            s=json.loads(STATE.read_text());s.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(STATE,s)
        raise
