#!/usr/bin/env python3
"""Pinned module-only optimization experiments; no FPGA or full-DUT actions."""
from pathlib import Path
import datetime, fcntl, json, os, random, signal, subprocess, time
from board_batch import W, D, save, sha
from job_service import proc
from prepare_opt4_fit_modules import JAVA, CACHE, CPFILE
from summarize_opt4_fit import resources

F = W/'Opt4-fit-20261110'
O = D/'build-logs/Opt4-fit-modules-20261110/round2'
STATE = D/'Opt4-fit-round2-state.json'
COMMIT = '8da24a2'

def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()

def main():
    lock=(D/'.opt4-fit-round2.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    commit=subprocess.check_output(['git','rev-parse',COMMIT],cwd=F,text=True).strip()
    st=dict(schema='ec-opt4-fit-round2/1',status='RUNNING',pid=os.getpid(),
            start_ticks=proc(os.getpid())['start_ticks'],
            host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
            started_utc=now(),fit_commit=commit,fpga_access=False,
            full_dut_synthesis=False,formal_admission=False,modules={})
    save(STATE,st)
    cp=CPFILE.read_text().strip()
    compiler=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar')
              for n in ['scala-compiler','scala-library','scala-reflect']]
    plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','OMP_NUM_THREADS':'8'}
    def run(label,argv,out,timeout=1800):
        log=out/(label+'.log')
        with log.open('ab',buffering=0) as f:
            p=subprocess.Popen(list(map(str,['nice','-n','15']+argv)),cwd=out,env=env,
                 stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            st.update(active_step=label,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks'])
            save(STATE,st);start=time.monotonic()
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now());save(STATE,st);os.fsync(f.fileno())
                if time.monotonic()-start>timeout:
                    os.killpg(p.pid,signal.SIGTERM)
                    try:p.wait(timeout=20)
                    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                    raise RuntimeError((label,'module-only timeout',timeout))
            assert p.returncode==0,(label,p.returncode,str(log))
        return log

    # Mathematical bound: all partial sums of 256 unsigned 64-bit inputs fit
    # in 72 bits. The original 73-bit chain never wraps on this domain, so
    # unsigned associativity and +& at every tree node preserve every bit.
    rng=random.Random(20261110)
    for n in [1,2,4,8,16,32,64,128,256]:
        for t in range(256):
            xs=[(1<<64)-1 if t==0 else rng.getrandbits(64) for _ in range(n)]
            level=xs[:]
            while len(level)>1:
                level=[sum(level[i:i+2]) for i in range(0,len(level),2)]
            assert level[0]==sum(xs) and level[0]<(1<<(64+(n-1).bit_length()))
    st['reduction_proof']=dict(argument='All partial sums bounded by 256*(2^64-1)<2^72; +& is exact at each balanced node; original 73-bit reduction never wraps.',
                               boundary_random_checks=2304,full_design_proof=False)
    save(STATE,st)
    specs=[
        ('scanner','chipyard/generators/boom/src/main/scala/lsu/SafePrefixScanner.scala',
         'SafePrefixScanner','new boom.lsu.SafePrefixScanner(256,32)'),
        ('barrier','chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala',
         'GHBarrierLatencyStats','new freechips.rocketchip.guardiancouncil.GHBarrierLatencyStats(256)')]
    jobs=[]
    for kind,rel,top,ctor in specs:
        out=O/kind;out.mkdir(exist_ok=True);classes=out/'classes';classes.mkdir(exist_ok=True)
        source=out/Path(rel).name
        source.write_bytes(subprocess.check_output(['git','show',commit+':'+rel],cwd=F))
        emit=out/'EmitRound2.scala'
        emit.write_text('package opt4fit\nobject EmitRound2 extends App {(new chisel3.stage.ChiselStage).emitVerilog('+ctor+',Array("--target-dir",args(0)))}\n')
        r=dict(status='COMPILING',source_snapshot=str(source),source_sha256=sha(source),fit_commit=commit,top=top)
        st['modules'][kind]=r;save(STATE,st)
        run(kind+'-compile',[JAVA,'-Xmx8G','-XX:ActiveProcessorCount=4','-cp',':'.join(map(str,compiler)),
              'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+str(plugin),'-d',classes,source,emit],out)
        run(kind+'-elaborate',[JAVA,'-Xmx12G','-XX:ActiveProcessorCount=4','-cp',str(classes)+':'+cp,
              'opt4fit.EmitRound2',out],out)
        rtl=out/(top+'.v');r.update(rtl=str(rtl),rtl_sha256=sha(rtl),status='VERIFYING');save(STATE,st)
        if kind=='scanner':
            original=O.parent/'scanner/baseline/SafePrefixScannerBaseline.v'
            test=out/'tb.v';test.write_bytes((O.parent/'scanner/scanner-tb.v').read_bytes())
        else:
            base=O.parent/'baseline-barrier/GHBarrierLatencyStats.v'
            original=out/'original.v'
            original.write_text(base.read_text().replace('module '+top+'(','module '+top+'_original(',1))
            test=out/'tb.v';test.write_bytes((W/'candidates/capacity-exact-factor-20261110/leaf_compare_tb.v').read_bytes())
        exe=out/'compare.vvp'
        run(kind+'-compare-compile',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,original,rtl,test],out)
        log=run(kind+'-compare',['/usr/bin/vvp',exe],out)
        assert 'COMPARISON_PASS' in log.read_text()
        r.update(verification='PASS_GENERATED_RTL_SAMPLED_NOT_FULL_PROOF',
                 original_rtl_sha256=sha(original),testbench_sha256=sha(test),comparison_log=str(log),
                 comparison_log_sha256=sha(log),vectors=4096 if kind=='scanner' else 2048)
        tcl=out/'map.tcl'
        tcl.write_text(f'''set_param general.maxThreads 8
read_verilog {{{rtl}}}
synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {{{out/'utilization.rpt'}}}
write_checkpoint -force {{{out/'module.dcp'}}}
puts "EC_OPT4_FIT_ROUND2_MAP_OK {kind}"
exit 0
''')
        f=(out/'mapping.log').open('ab',buffering=0)
        p=subprocess.Popen(['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
              '-log',str(out/'vivado.log'),'-source',str(tcl)],cwd=out,env=env,
              stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
        r.update(status='MAPPING',pid=p.pid,start_ticks=proc(p.pid)['start_ticks'],tcl_sha256=sha(tcl))
        jobs.append((kind,p,f,out));save(STATE,st)
    while jobs:
        for kind,p,f,out in jobs[:]:
            if p.poll() is None:continue
            os.fsync(f.fileno());f.close();r=st['modules'][kind]
            r.update(returncode=p.returncode,ended_utc=now(),status='MAPPED_MODULE_ONLY' if p.returncode==0 else 'FAILED_WITH_EVIDENCE')
            if p.returncode==0:r.update(utilization=resources(out/'utilization.rpt'),report_sha256=sha(out/'utilization.rpt'))
            save(out/'receipt.json',r);jobs.remove((kind,p,f,out));save(STATE,st)
        st.update(updated_utc=now(),status='MAPPING_MODULES');save(STATE,st)
        if jobs:time.sleep(30)
    st.update(status='MODULES_VALIDATED_AND_MAPPED' if all(r.get('returncode')==0 for r in st['modules'].values()) else 'PARTIAL_FAILURE_WITH_EVIDENCE',ended_utc=now())
    save(STATE,st)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if STATE.exists():
            st=json.loads(STATE.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(STATE,st)
        raise
