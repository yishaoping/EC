#!/usr/bin/python3
"""Compile and full-state finite-test the independently committed common bank.

No CAD, whole-target generation, FPGA IO, or intelligent supervisor.
"""
from pathlib import Path
import fcntl
import importlib.util
import json
import os
import re
import resource
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-common-stats-bank-r2-20261113'
PREVIOUS=D/'build-logs/Opt4-common-stats-bank-r1-20261113'
TREE=W/'Opt4-area-common-stats-bank-r1-20261113'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
spec=importlib.util.spec_from_file_location('common_bank_stage_tools',W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.O=O
CFG=W/'candidates/address-banked-storage-compose-r1-20261112/config.json'
PARENT='16b2d8945f6e17385a4fe136eadd9597ee1ac4fc'
BOOM='chipyard/generators/boom/src/main/scala/lsu/'
ROCKET='chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/'

def source(rev,rel):
    return subprocess.check_output(['git','show',rev+':'+rel],cwd=TREE,text=True)

def no_owner_members(unit):
    expected='/user.slice/user-1008.slice/user@1008.service/'+unit
    found=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if expected in [l.split(':',2)[-1] for l in (p/'cgroup').read_text().splitlines()]:
                found.append(identity(int(p.name)))
        except OSError:pass
    return found

def proof_sources():
    common=(TREE/ROCKET/'ecstatscommon/StatsBank.scala').read_text()
    addr=source(PARENT,BOOM+'opt4bankedproduction/BucketBank.scala')
    bar=source(PARENT,ROCKET+'BarrierBucketBank.scala')
    adecl='    val observeAddress = Output(Vec(16, UInt(1313.W)))\n'
    bdecl='    val observeBarrier = Output(Vec(16, UInt(161.W)))\n'
    aobs='''
  for (i <- 0 until 16) io.observeAddress(i) := Cat(bucketValid(i), bucketSeq(i),
    bucketStore(i).asUInt, bucketFirstStore(i).asUInt, bucketLoadFirst(i).asUInt,
    bucketStoreFirst(i).asUInt, bucketStrictWriteRead(i).asUInt)
'''
    bobs='''
  for (i <- 0 until 16) io.observeBarrier(i) := Cat(buckets.valid(i), buckets.seq(i),
    buckets.count(i), buckets.requestCycleSum(i))
'''
    def withproof(text,name,newname,decl,obs):
        text=re.sub(r'\bclass '+name+r'\b', 'class '+newname, text, count=1)
        assert 'class '+newname in text
        text=text.replace('  val io = IO(new Bundle {','  val io = IO(new Bundle {\n'+decl,1)
        at=text.rfind('\n}')
        return text[:at]+obs+text[at:]
    common=withproof(common,'StatsBank','StatsBankProof',adecl+bdecl,aobs+bobs)
    addr=withproof(addr,'BucketBank','AddressReference',adecl,aobs)
    bar=withproof(bar,'GHBarrierBucketBank','BarrierReference',bdecl,bobs)
    for n,t in [('StatsBankProof.scala',common),('AddressReference.scala',addr),('BarrierReference.scala',bar)]:
        m.exact(O/n,t)
    # Connect the original two independent banks to exactly the corresponding
    # common-bank inputs. Compare all public outputs and every state word,
    # including payloads while valid=0. Proof ports never enter production.
    afields=re.findall(r'^    val (\w+) = Input',addr,re.M)
    bfields=re.findall(r'^    val (\w+) = Input',bar,re.M)
    aouts=re.findall(r'^    val (\w+) = Output',addr,re.M)
    bouts=re.findall(r'^    val (\w+) = Output',bar,re.M)
    # IO declarations are one line each in the committed common type.
    ci=common[common.index('  val io = IO(new Bundle {'):common.index('\n  })')]
    ins='\n'.join(l for l in ci.splitlines() if '= Input' in l)
    connections=[];checks=[]
    for n in afields:connections += [f'  a.io.{n} := io.{n}',f'  c.io.{n} := io.{n}']
    for n in bfields:
        cn='barrier'+n[0].upper()+n[1:]
        connections += [f'  b.io.{n} := io.{cn}',f'  c.io.{cn} := io.{cn}']
    for n in aouts:checks.append(f'(a.io.{n}.asUInt === c.io.{n}.asUInt)')
    for n in bouts:
        cn=n if n=='observeBarrier' else 'barrier'+n[0].upper()+n[1:]
        checks.append(f'(b.io.{n}.asUInt === c.io.{cn}.asUInt)')
    text='''package commonbanktest
import chisel3._
import chisel3.util._
import ecstatscommon.{Counts, Source}
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
class Pair extends Module {
  val a = Module(new opt4bankedproduction.AddressReference)
  val b = Module(new freechips.rocketchip.guardiancouncil.BarrierReference(256,16))
  val c = Module(new ecstatscommon.StatsBankProof)
  val io = IO(new Bundle {
'''+ins+'''
    val same = Output(Bool())
  })
'''+ '\n'.join(connections)+'\n  io.same := '+ ' &&\n    '.join(checks)+'\n}\n'+'''
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Pair,
    Array("--target-dir",args(0),"--output-file","Pair"))
}
'''
    m.exact(O/'Pair.scala',text)
    return [O/n for n in ['StatsBankProof.scala','AddressReference.scala','BarrierReference.scala','Pair.scala']]

def target_test(rtl):
    head=re.search(r'\bmodule Pair\s*\((.*?)\);',rtl.read_text(),re.S).group(1)
    ps=re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)
    inputs=[(w,n) for d,w,n in ps if d=='input']
    assert [(d,w,n) for d,w,n in ps if d=='output']==[('output','','io_same')]
    lines=['module tb;','integer cycle;',"reg [63:0] rng=64'h4d595df4d0f33173;",'wire io_same;']
    lines += ['reg '+w+' '+n+';' for w,n in inputs]
    lines += ['Pair dut('+','.join('.'+n+'('+n+')' for w,n in inputs)+',.io_same(io_same));',
        'task check; begin if(io_same !== 1\'b1) begin $display("COMMON_BANK_MISMATCH cycle=%0d",cycle); $fatal(1); end end endtask',
        'initial begin','cycle=-1;']
    lines += [n+"='0;" for w,n in inputs]
    lines += ['reset=1; io_resetStats=1; io_barrierResetStats=1;',
        '#1; clock=1; #1; clock=0; #1;',
        'for(cycle=0;cycle<8192;cycle=cycle+1) begin']
    for w,n in inputs:
        if n in ['clock','reset','io_resetStats','io_barrierResetStats']:continue
        lines += ['rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',n+'=rng;']
    lines += [
        'reset=(cycle<3 || cycle==3072);',
        'io_resetStats=(cycle<3 || cycle%1024==0);',
        'io_barrierResetStats=(cycle<3 || cycle%1024==0);',
        '// Walk all sixteen bank bases under production 256-slot geometry.',
        'io_base=(cycle%16)*16; io_barrierBase=io_base;',
        'io_processSeq=(cycle%16)*16+(cycle%16);',
        'io_retiringSeq=io_processSeq;',
        'io_barrierEvent_bits=io_processSeq;',
        'if(cycle%4==0) io_barrierSafeWatermark=0;',
        'if(cycle%4==1) io_barrierSafeWatermark=io_barrierEvent_bits;',
        'if(cycle==4097) begin']
    # Equal arbitrary seed after reset-based runs tests carry and source
    # priority in reachable and arbitrary state, including invalid payloads.
    for prefix in ['dut.a','dut.c']:
        lines += [prefix+'.bucketValid_0=1;',prefix+'.bucketSeq_0=32\'d17;']
        for metric in ['bucketStore','bucketFirstStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']:
            for g in range(4):lines.append(prefix+'.'+metric+'_0_'+str(g)+"=64'hffffffffffffffff;")
    for prefix in ['dut.b','dut.c']:
        for name,val in [('valid',"1'b1"),('seq',"32'd17"),('count',"64'hffffffffffffffff"),('requestCycleSum',"64'hffffffffffffffff")]:
            lines.append(prefix+'.buckets_'+name+'_0='+val+';')
    lines += ['end',
        '#1; check; clock=1; #1; clock=0; #1;',
        'if($test$plusargs("EC_MUTATE") && cycle==1000) begin force dut.c.bucketStore_0_0=64\'hdeadbeef12345678; #1; end',
        'check; end',
        '$display("COMMON_BANK_FULL_STATE_PASS cycles=8192 address_words=336 barrier_words=64 invalid_payload=compared"); $finish;',
        'end endmodule']
    m.exact(O/'tb.v','\n'.join(lines)+'\n')
    binary=O/'target.vvp'
    m.stage('compile-target',['/usr/bin/iverilog','-g2012','-s','tb','-o',binary,rtl,O/'tb.v'],[binary],cwd=O)
    log=m.stage('full-state-target',['/usr/bin/vvp',binary],cwd=O)
    assert 'COMMON_BANK_FULL_STATE_PASS cycles=8192' in log.read_text()
    # Keep the expected negative exit separate from the success-only stage.
    negative=O/'negative.log'
    with negative.open('xb') as out:
        r=subprocess.run(['/usr/bin/vvp',binary,'+EC_MUTATE'],stdout=out,stderr=subprocess.STDOUT)
    assert r.returncode!=0 and 'COMMON_BANK_MISMATCH cycle=1000' in negative.read_text()
    save(O/'target-validation.json',dict(cycles=8192,state_bits_per_lane=1474,
        lanes=16,all_state_including_invalid_payload=True,public_outputs_compared=True,
        directed_arbitrary_overflow_seed_cycle=4097,negative_state_mutation_rejected=True,
        log=str(log),log_sha256=sha(log),negative=str(negative),negative_sha256=sha(negative)))

def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing exact owner'
    prior='ec-opt4-common-stats-bank-r1-20261113.service'
    assert not no_owner_members(prior),'Preserve exact predecessor cgroup until release'
    save(O/'predecessor-release.json',dict(unit=prior,utc=now(),members=[]))
    os.sched_setaffinity(0,{206,207});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    binding=read(C/'source-binding.json')
    assert all(sha(p)==h for p,h in binding['source_files'].items())
    commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=TREE,text=True).strip()
    assert commit==binding['hardware_commit']
    for p,h in binding['source_files'].items():
        import hashlib
        assert hashlib.sha256(subprocess.check_output(['git','show',commit+':'+str(Path(p).relative_to(TREE))],cwd=TREE)).hexdigest()==h
    m.ST.update(schema='ec-common-stats-bank-validation/1',**identity(),started_utc=now(),
        hardware_commit=commit,functional_baseline=binding['functional_baseline'],
        cpus=[206,207],memory_limit_gib=64,fpga_access=False,no_CAD=True,
        production_admission=False,full_system_fit=False,source_binding_sha256=sha(C/'source-binding.json'),
        scope='Common production16-lane bank compile and all-state finite miter. Not complete target/host equivalence or area/FIT.')
    save(O/'inputs.json',dict(files={str(p):sha(p) for p in C.glob('*') if p.is_file()}))
    m.update('COMPILING_COMMITTED_COMMON_BANK_AND_CALLERS')
    cfg=read(CFG);java=[cfg['java'],'-Xmx24G','-Xss32M','-XX:ActiveProcessorCount=2']
    composed=D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    classes=PREVIOUS/'classes'
    receipt=read(PREVIOUS/'compile-source-receipt.json')
    assert receipt['returncode']==0 and all(sha(p)==h for p,h in receipt['outputs'].items())
    assert read(PREVIOUS/'state.json')['hardware_commit']==commit
    save(O/'reused-production-classes.json',dict(receipt_sha256=sha(PREVIOUS/'compile-source-receipt.json'),files={str(p):sha(p) for p in classes.rglob('*.class')}))
    prod=[Path(p) for p in binding['source_files']]
    required=[classes/'ecstatscommon/StatsBank.class',classes/'boom/lsu/PackageAddressStats.class',
        classes/'freechips/rocketchip/guardiancouncil/GHBarrierLatencyStats.class']
    compiler=java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',str(composed)+':'+':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin']]
    assert all(p.is_file() for p in required)
    proofs=proof_sources();proofclasses=O/'proof-classes';proofclasses.mkdir()
    m.stage('compile-proof',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',str(classes)+':'+str(composed)+':'+':'.join(cfg['classpath']),
        '-Xplugin:'+cfg['plugin'],'-d',proofclasses,*proofs],
        [proofclasses/'commonbanktest/Emit.class'],cwd=TREE/'chipyard')
    cp=':'.join(map(str,[proofclasses,classes,composed]))+':'+':'.join(cfg['classpath'])
    target=O/'target';target.mkdir()
    m.stage('emit-full-bank-miter',java+['-cp',cp,'commonbanktest.Emit',target],
        [target/'Pair.v'],cwd=TREE/'chipyard')
    target_test(target/'Pair.v')
    assert all(sha(p)==h for p,h in binding['source_files'].items())
    m.update('PASS_COMMON_BANK_COMPILE_AND_FULL_STATE_FINITE_MITER_NO_HOST_AREA',
        ended_utc=now(),target_validation=str(O/'target-validation.json'),
        target_validation_sha256=sha(O/'target-validation.json'),
        compiled_classes={str(p):sha(p) for p in required},
        next='Validate actual mixed-role64-instance one-type GoldenGate topology/token feedback and production caller/full-DCache parity. Measure one compatible common-bank completehost pair before any wholeEC CAD.',
        full_target_equivalence=False,host_validation=False,area_gain_unknown=True)
    save(O/'result.json',m.ST)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
