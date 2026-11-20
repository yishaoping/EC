#!/usr/bin/env python3
"""Pinned independent heap candidate: compile, generate, full-cycle comparison.

No current whole-system or other module build is modified. A full-module map
is allowed only after these tests. No automatic whole-DUT promotion.
"""
from pathlib import Path
import datetime as dt
import fcntl
import json
import os
import shutil
import signal
import subprocess
import time

from board_batch import W,D,save,sha
from job_service import proc,boot
from prepare_opt4_fit_modules import JAVA,CACHE,CPFILE
from summarize_opt4_fit import resources

F=W/'Opt4-fit-address-heap-20261110'
COMMIT='06b873106478683661e2d33dbf1c5b7ff73f45b8'
REL='chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
O=D/'build-logs/Opt4-fit-address-heap-candidate-20261110'
S=D/'Opt4-fit-address-heap-candidate-state.json'
now=lambda:dt.datetime.now(dt.timezone.utc).isoformat()


def main():
    lock=(D/'.opt4-fit-address-heap-candidate.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True);b=json.loads((F/'candidate-binding.json').read_text())
    assert b['hardware_commit']==COMMIT
    source=O/'PackageAddressStats.scala'
    content=subprocess.check_output(['git','show',COMMIT+':'+REL],cwd=F)
    if source.exists():assert source.read_bytes()==content
    else:source.write_bytes(content)
    prior=json.loads((D/'Opt4-fit-address-heap-proof-state.json').read_text())
    assert prior['status']=='COMPOSITIONALLY_PROVED_MICRO_MAP_COMPLETE_NOT_INSTALLED'
    assert prior['negative_mutation_rejected']
    bounds=json.loads((D/'Opt4-fit-address-round3-state.json').read_text())['tests']['touch_bounds']
    assert bounds['status']=='PASS_UNIVERSAL_96_INPUT_BITS' and bounds['bounds']==[8,3,2,1]
    assert 'SUCCESS' in Path(bounds['log']).read_text()
    # The current revision changes only the combinational exactHitSum helper.
    parent=subprocess.check_output(['git','show',b['parent_commit']+':'+REL],cwd=F,text=True)
    def outside(s):
        start=s.index('  private def exactHitSum(');end=s.index('  private def touchedMask(',start)
        return s[:start].replace('bounded and balanced. No intermediate can overflow this exact width.','bounded. No architectural state or cycle boundary changes.')+s[end:]
    assert outside(parent)==outside(content.decode()),'state/event/cycle logic changed'
    st=dict(schema='ec-opt4-fit-address-heap-candidate/1',status='STARTING',pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=boot(),hardware_commit=COMMIT,
        source_id=b['source_id'],source_sha256=sha(source),started_utc=now(),stages={},
        fpga_access=False,formal_admission=False,full_dut_synthesis=False,production_selected=False,
        proof_scope='Compositional parsed micro RTL + proven leaf bounds; full module regression, not full-design formal equivalence',
        invariant_outside_exactHitSum_unchanged=True)
    save(S,st)
    env={**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':''}
    def run(label,argv,cwd,outputs,timeout):
        receipt=cwd/(label+'-result.json')
        if receipt.exists():
            r=json.loads(receipt.read_text());assert r['hardware_commit']==COMMIT and r['returncode']==0
            assert all(sha(p)==h for p,h in r['outputs'].items())
            st['stages'][label]=r;save(S,st);return
        n=len(list(cwd.glob(label+'-attempt-*.log')))+1;log=cwd/(label+f'-attempt-{n}.log')
        with log.open('ab',buffering=0) as stream:
            p=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=cwd,env=env,stdin=subprocess.DEVNULL,
                stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
            start=time.monotonic();st.update(status='RUNNING_'+label.upper(),child_pid=p.pid,
                child_start_ticks=proc(p.pid)['start_ticks'],log=str(log));save(S,st)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now());save(S,st);os.fsync(stream.fileno())
                if p.poll() is None and (time.monotonic()-start>timeout or shutil.disk_usage(O).free<60*2**30):
                    os.killpg(p.pid,signal.SIGTERM)
                    try:p.wait(timeout=30)
                    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
                    raise RuntimeError(label+' independent candidate guard')
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        assert p.returncode==0,(label,p.returncode,str(log))
        r=dict(hardware_commit=COMMIT,returncode=0,outputs={str(p):sha(p) for p in outputs},log=str(log),ended_utc=now())
        save(receipt,r);st['stages'][label]=r;save(S,st)
    cp=CPFILE.read_text().strip();classes=O/'classes';classes.mkdir(exist_ok=True)
    compiler=[CACHE/'org/scala-lang'/n/'2.13.10'/(n+'-2.13.10.jar') for n in ['scala-compiler','scala-library','scala-reflect']]
    plugin=CACHE/'edu/berkeley/cs/chisel3-plugin_2.13.10/3.5.5/chisel3-plugin_2.13.10-3.5.5.jar'
    emit=O/'EmitHeap.scala';emit.write_text('package opt4fit\nobject EmitHeap extends App {(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(0)))}\n')
    run('compile',[JAVA,'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',':'.join(map(str,compiler)),
        'scala.tools.nsc.Main','-classpath',cp,'-Xplugin:'+str(plugin),'-d',classes,source,emit],O,[emit],1800)
    rtl=O/'PackageAddressStats.v'
    run('elaborate',[JAVA,'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=4','-cp',str(classes)+':'+cp,'opt4fit.EmitHeap',O],O,[rtl],1800)
    compare=O/'compare';compare.mkdir(exist_ok=True)
    for old,new in [(D/'build-logs/Opt4-fit-modules-20261110/verification/address-original.v',compare/'original.v'),
                    (D/'build-logs/Opt4-fit-modules-20261110/verification/address-tb.v',compare/'tb.v')]:
        if new.exists():assert new.read_bytes()==old.read_bytes()
        else:shutil.copy2(old,new)
    exe=compare/'obj/Vtb'
    run('compare-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb','--Mdir',compare/'obj','-j','4',
        '--output-split','10000','--output-split-cfuncs','200','--x-initial','0','--x-assign','0','-Wno-fatal',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0',compare/'original.v',rtl,compare/'tb.v'],compare,[exe],7200)
    run('compare',[exe],compare,[],1800)
    assert 'ADDRESS_SEQUENTIAL_COMPARISON_PASS' in Path(st['stages']['compare']['log']).read_text()
    st.update(full_module_regression='PASS_6144_CYCLES_ALL_52_OUTPUTS_NOT_FULL_FORMAL',rtl_sha256=sha(rtl));save(S,st)
    sub=O/'map';sub.mkdir(exist_ok=True);tcl=sub/'map.tcl';report=sub/'utilization.rpt';dcp=sub/'module.dcp'
    tcl.write_text('set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\n'
        +'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        +f'report_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    run('full-module-map',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',sub/'vivado.log','-source',tcl],sub,[report,dcp],86400)
    st.update(status='VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED',resources=resources(report),ended_utc=now())
    save(S,st);save(O/'result.json',st)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
        raise
