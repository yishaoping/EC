#!/usr/bin/python3
"""Recover production host token sampling with the common precise-edge gate."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import resource
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
FS=W/'C4/chipyard/sims/firesim/sim'
O=D/'build-logs/Opt4-address-banked-production-host-r4-20261113'
P=D/'build-logs/Opt4-address-banked-production-host-r2-20261113'
BASE=D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
TREE=W/'Opt4-area-address-production-host-r4-20261113'
CPUS={212,213}
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
spec=importlib.util.spec_from_file_location('token_recovery_stages',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.C,m.O,m.CPUS=C,O,CPUS


def members(unit):
    result=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if any(l.split(':',2)[-1].endswith('/'+unit) or '/'+unit+'/' in l.split(':',2)[-1]
                   for l in (p/'cgroup').read_text().splitlines()):result.append(identity(int(p.name)))
        except OSError:pass
    return result


def link_inputs(src,dst):
    dst.mkdir()
    for name in ['AbstractClockGate.v','FireSim-generated.sv','FireSim-generated.const.h',
                 'FireSim-generated.const.vh','FireSim-generated.defines.vh',
                 'FireSim-generated.implementation.xdc','FireSim-generated.synthesis.xdc',
                 'firrtl_black_box_resource_files.f']:
        (dst/name).symlink_to(src/name)


def simulate(host,name,trace):
    listing=host/'firrtl_black_box_resource_files.f'
    sim=host/'simulation.sv'
    m.exact(sim,(host/'FireSim-generated.sv').read_text()+
        ''.join(Path(p).read_text() for p in listing.read_text().splitlines() if p.strip()))
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(O)+' -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    exe=host/'VCompleteAddressStats'
    m.stage('compile-host-'+name,['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2','verilator',
        'PLATFORM=xilinx_alveo','DRIVER_NAME=CompleteAddressStats','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(sim),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestComplete.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],[exe],env=env)
    args=[exe,'+trace='+str(trace),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name,args,marker='COMPLETE_ADDRESS_HOST_TOKEN_PASS',env=env,timeout=3600)
    m.stage('token-negative-'+name,args+['+negative'],negative=True,
        marker='COMPLETE_ADDRESS_HOST_MISMATCH cycle=100 port=io_statsValid',env=env,timeout=600)
    line=next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines()
              if l.startswith('COMPLETE_ADDRESS_HOST_TOKEN_PASS '))
    result=json.loads(line.split(' ',1)[1]);assert result['checked_outputs']==3000*52
    return result


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt exact recovery owner'
    predecessor='ec-opt4-address-banked-production-host-r2-20261113.service'
    assert not members(predecessor),'Preserve predecessor until complete cgroup release'
    save(O/'predecessor-release.json',dict(unit=predecessor,members=[],utc=now(),
        predecessor_failure_sha256=sha(P/'failure.json')))
    failure=read(P/'failure.json')
    assert failure['status']=='FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED'
    assert failure['active_stage']=='token-oracle-Threaded'
    log=(P/'token-oracle-Threaded.log').read_text()
    assert 'cycle=12 port=io_counters_0 expected=0 got=2' in log
    parent=read(W/'candidates/address-banked-production-host-r2-20261113/source-binding.json')
    tree=W/'Opt4-area-address-production-host-r2-20261113'
    assert parent['hardware_commit']=='4b0ca01ee8704fe1db70e35c08ab3bd4c00e9ec0'
    assert all(sha(path)==h for path,h in parent['files'].items())
    old_test=next(Path(path) for path in parent['files'] if path.endswith('/TestComplete.cc'))
    assert 'peek_poke.peek(output_ports[0], true)' not in old_test.read_text()
    for rel,h in parent['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git','show',parent['hardware_commit']+':'+rel],cwd=tree)).hexdigest()==h
    recovery_binding=read(C/'source-binding.json')
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=TREE,text=True).strip()==recovery_binding['experiment_parent_commit']
    os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    cp_receipt=read(P/'goldengate-Threaded-receipt.json')
    assert cp_receipt['accepted'] and sha(cp_receipt['log'])==cp_receipt['log_sha256']
    argv=cp_receipt['argv'];cp=argv[argv.index('-cp')+1]
    target=P/'Host-target'
    target_receipt=read(P/'elaborate-host-receipt.json')
    assert target_receipt['accepted'] and all(sha(p)==h for p,h in target_receipt['outputs'].items())
    annotation=target/'CompleteAddressStats.anno.json'
    assert sha(annotation)==target_receipt['outputs'][str(annotation)]
    selected=[a for a in read(annotation) if a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected)==16 and all(a['target'].startswith('~CompleteHost|CompleteHost/bucketBanks_') for a in selected)
    trace=BASE/'positive-reference-public-tokens.txt'
    assert len(trace.read_text().splitlines())==3003
    old_inputs=read(P/'inputs.json')['files'];assert all(sha(p)==h for p,h in old_inputs.items())
    m.ST.update(schema='ec-production-host-precise-token-boundary-recovery/1',**identity(),
        started_utc=now(),hardware_commit=parent['hardware_commit'],functional_baseline=parent['functional_baseline'],
        source_parent_commit=parent['hardware_commit'],cpus=sorted(CPUS),memory_limit_gib=64,
        fpga_access=False,no_CAD=True,full_system_fit=False,production_admission=False,
        reused_exact_target_and_threaded_host=True,host_area_gain_unknown=True,
        scope='Repeat exact3003target-token/52-output host oracle using shared precise public output boundary after step; no target/hardware change, area or shell claim.')
    m.update('ADMITTING_PRECISE_PUBLIC_TOKEN_BOUNDARY_RECOVERY')
    save(O/'admission.json',m.admission())
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    save(O/'diagnosis.json',dict(predecessor=str(P/'failure.json'),predecessor_log_sha256=sha(P/'token-oracle-Threaded.log'),
        symptom='At token12 expected io_counters_0=0, immediate MMIO peek observed2.',
        proven='The r2 TestComplete C++ source read outputs immediately after step(1), without PeekPokeBridge precise/unstable/timeout synchronization.',
        evidence='Other live actual host validators use peek_poke.peek(output_ports[0], true) and reject timeout/unstable before reading public outputs.',
        hardware_inequivalence_proven=False,correction='Add exact shared precise-output boundary and fail on timeout or unstable channel; keep all3003 tokens and52 outputs.',
        target_oracle_or_stimulus_changed=False,hardware_changed=False))
    files={str(p):sha(p) for p in [C/'controller.py',C/'TestComplete.cc',C/'source-binding.json',C/'recovery.json'] if p.exists()}
    files.update(old_inputs)
    files[str(trace)]=sha(trace)
    files[str(FS/'midas/src/main/cc/bridges/peek_poke.cc')]=sha(FS/'midas/src/main/cc/bridges/peek_poke.cc')
    files[str(FS/'midas/src/main/cc/bridges/peek_poke.h')]=sha(FS/'midas/src/main/cc/bridges/peek_poke.h')
    save(O/'inputs.json',dict(files=files))
    link_inputs(P/'Threaded',O/'Threaded')
    (O/'trace-ports.h').symlink_to(P/'trace-ports.h')
    tokens={'Threaded':simulate(O/'Threaded','Threaded',trace)}
    save(O/'token-progress.json',tokens)
    plain=O/'Plain'
    m.stage('goldengate-Plain',[cfg['java'],'-Xmx48G','-Xss32M','-XX:ActiveProcessorCount=2',
        '-cp',cp,'midas.stage.GoldenGateMain','-i',target/'CompleteAddressStats.fir','-td',plain,
        '-faf',annotation,'-ggcp','opt4bankedproduction','-ggcs','PlainConfig','--output-filename-base','FireSim-generated'],
        [plain/'FireSim-generated.sv',plain/'FireSim-generated.synthesis.xdc'])
    fame=(plain/'post-fame-transform.fir').read_text()
    banktypes=re.findall(r'(?m)^\s*inst \w+ of (BucketBank(?:_\d+)?)\b',fame)
    assert len(banktypes)==16 and len(set(banktypes))==1
    assert 'Skipping Combinational Loop Detection' not in (O/'goldengate-Plain.log').read_text()
    link_inputs(plain,O/'Plain-linked')
    tokens['Plain']=simulate(O/'Plain-linked','Plain',trace)
    assert tokens['Plain']['digest']==tokens['Threaded']['digest']
    assert all(sha(p)==h for p,h in files.items())
    m.update('PASS_PRODUCTION_HOST_PRECISE_3003_TOKEN_ORACLE_AND_PLAIN_THREADED_PARITY_NO_AREA',
        tokens=tokens,target_tokens=3003,public_outputs=52,host_area_gain_unknown=True,
        finite_target_parity_reused=True,full_formal=False,ended_utc=now(),
        next='Only after exact validator cgroup release may a diagnosed area-pair successor bind these corrected tokens and measure same-scope Plain/Threaded production host. No area or FIT claim.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now());save(O/'failure.json',m.ST)
        raise
