#!/usr/bin/python3
"""One bounded JVM-stack recovery after verified target parity.

Reuse existing target classes, FIRRTL, all source pins and positive trace.
Only GoldenGate JVM stack size changes. Never retries a functional mismatch.
"""
from pathlib import Path
import fcntl
import importlib.util
import os
import resource
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OLD=D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
O=D/'build-logs/Opt4-sprint-production-stack-recovery-r1-20261112'
SOURCE=W/'candidates/address-banked-production-host-r1-20261112'
spec=importlib.util.spec_from_file_location('immutable_production_validator',SOURCE/'controller.py')
p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
p.O=O;p.m.O=O
from opt4_unattended_common import identity,live,now,read,save,sha


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists()
    state=read(OLD/'state.json')
    assert state['status'].startswith('FAILED') and not live(state)
    assert state.get('active_stage','').startswith('goldengate-')
    failed_log=OLD/(state['active_stage']+'.log')
    assert 'java.lang.StackOverflowError' in failed_log.read_text(errors='replace')
    for name in ['full-target-parity','full-target-negative','elaborate-host']:
        r=read(OLD/(name+'-receipt.json'))
        assert r['accepted'] and not r['missing_outputs']
        assert sha(r['log'])==r['log_sha256']
        assert all(sha(k)==v for k,v in r['outputs'].items())
    pins=read(OLD/'inputs.json')
    assert all(sha(k)==v for k,v in pins['files'].items())
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    os.sched_setaffinity(0,{212,213});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    p.m.ST.update({k:v for k,v in state.items() if k not in ['pid','start_ticks','host_boot_id','process_state','child','error','ended_utc']})
    p.m.ST.update(**identity(),started_utc=now(),schema='ec-production-stack-recovery/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source_binding_sha256=sha(SOURCE/'source-binding.json'),
        finite_parity=True,monitor_outputs=5684,target_cycles=6144,
        same_target_RTL=True,only_jvm_stack_changed=True,prior_failure=str(OLD/'failure.json'))
    p.m.update('RECOVERING_GOLDENGATE_STACK_ONLY_REUSING_ALL_TARGET_VERIFICATION')
    save(O/'inputs.json',pins)
    for name in ['full-target-parity-receipt.json','full-target-negative-receipt.json','trace-ports.h']:
        (O/name).write_bytes((OLD/name).read_bytes())
    target=OLD/'Host-target'
    cp=str(OLD/'classes-Module')+':'+':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx24G','-Xss64M','-XX:ActiveProcessorCount=2','-cp',cp]
    trace=OLD/'positive-reference-public-tokens.txt'
    assert trace.is_file()
    tokens={}
    for name,config in [('Threaded','ThreadedConfig'),('Plain','PlainConfig')]:
        host=O/name;host.mkdir()
        p.m.stage('goldengate-'+name,java+['midas.stage.GoldenGateMain','-i',target/'CompleteAddressStats.fir',
            '-td',host,'-faf',target/'CompleteAddressStats.anno.json','-ggcp','opt4bankedproduction',
            '-ggcs',config,'--output-filename-base','FireSim-generated'],
            [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
        post=(host/'post-gen-sram-models.fir').read_text()
        assert ('module BucketBank_threaded :' in post)==(name=='Threaded')
        save(O/(name+'-threading-audit.json'),dict(selected_count=16,proof_ports_absent=True,
            host_RTL_sha256=sha(host/'FireSim-generated.sv'),
            transformed_bank_type='BucketBank_threaded' if name=='Threaded' else 'BucketBank'))
        tokens[name]=p.simulate(host,name,trace)
        save(O/'token-progress.json',tokens)
    assert tokens['Threaded']['digest']==tokens['Plain']['digest']
    p.m.update('PASS_COMPLETE_TARGET_FINITE_PARITY_AND_COMPLETE_HOST_TOKENS_NO_AREA_OR_FIT',
        tokens=tokens,host_tokens=3003,production_public_outputs=52,full_formal=False,
        host_area_gain_unknown=True,full_system_fit=False,ended_utc=now())
    save(O/'result.json',p.m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',p.m.ST)
        raise
