#!/usr/bin/python3
"""Full256 AddressStats feedback/state closure at 8/16/32 lanes; no CAD or IO."""
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
import time
from prepare import derive, T

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-common-caller-geometry-closure-r1-20261113'
G=D/'build-logs/Opt4-common-bank-geometry-r3-20261113'
P=D/'build-logs/Opt4-common-bank-geometry-r2-20261113'
REF=D/'build-logs/Opt4-address-banked-complete-module-r1-20261112'
CPUS={216,217}
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
s=importlib.util.spec_from_file_location('caller_geometry_stage',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
m.C,m.O,m.CPUS=C,O,CPUS


def members(unit):
    found=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if any(l.split(':',2)[-1].endswith('/'+unit) or '/'+unit+'/' in l.split(':',2)[-1]
                   for l in (p/'cgroup').read_text().splitlines()):found.append(identity(int(p.name)))
        except OSError:pass
    return found


def ports(path,top):
    head=re.search(r'\bmodule '+top+r'\s*\((.*?)\);',path.read_text(),re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)


def testbench(lanes,candidate,out):
    reference=REF/'Reference-Proof/BankedProofReference.v'
    assert ports(reference,'BankedProofReference')==ports(candidate,'BankedProofCandidate')
    assert len([p for p in ports(candidate,'BankedProofCandidate') if p[0]=='output'])==5684
    instances=re.findall(r'\bGeometryBankProof(?:_\d+)?\s+(bucketBanks_\d+)\s*\(',candidate.read_text())
    assert set(instances)=={f'bucketBanks_{i}' for i in range(256//lanes)}
    original=(D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v').read_text()
    text=original.replace('PackedProofReference','BankedProofReference').replace('PackedProofCandidate','BankedProofCandidate')
    seed_re=r'\bb\.(bucket(?:Store|FirstStore|LoadFirst|StoreFirst|StrictWriteRead))_(\d+)_(\d+)'
    def rebind(match):
        metric,slot,g=match.groups();slot=int(slot)
        return f'b.bucketBanks_{slot//lanes}.{metric}_{slot%lanes}_{g}'
    text,count=re.subn(seed_re,rebind,text)
    assert count==5122,count
    # Require inverse identity of the complete stimulus and comparison oracle.
    reverse_re=r'\bb\.bucketBanks_(\d+)\.(bucket(?:Store|FirstStore|LoadFirst|StoreFirst|StrictWriteRead))_(\d+)_(\d+)'
    reverted,n=re.subn(reverse_re,lambda x:f'b.{x[2]}_{int(x[1])*lanes+int(x[3])}_{x[4]}',text)
    assert n==5122 and reverted==original.replace('PackedProofReference','BankedProofReference').replace('PackedProofCandidate','BankedProofCandidate')
    tb=out/'tb.v';m.exact(tb,text)
    save(out/'testbench-binding.json',dict(lanes=lanes,source_testbench_sha256=sha(D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v'),
        testbench_sha256=sha(tb),oracle_inverse_byte_equal=True,candidate_register_rebindings=count,
        full_target_cycles=6144,outputs=5684,invalid_payload_words=5120,
        real_feedback_paths_retained=True,reference_RTL_sha256=sha(reference),candidate_RTL_sha256=sha(candidate)))
    return reference,tb


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing sole owner'
    binding=read(C/'source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['hardware_commit']
    assert all(hashlib.sha256(subprocess.check_output(['git','show',binding['hardware_commit']+':'+p],cwd=T)).hexdigest()==h
               for p,h in binding['committed_files'].items())
    proof,derivation=derive()
    assert proof==(C/'CandidateProof.scala').read_text() and derivation==read(C/'proof-derivation.json')
    m.ST.update(schema='ec-complete-caller-geometry-closure/1',**identity(),started_utc=now(),
        hardware_commit=binding['hardware_commit'],hardware_source_commit=binding['hardware_source_commit'],
        functional_baseline=binding['functional_baseline'],cpus=sorted(CPUS),memory_limit_gib=64,
        fpga_access=False,no_CAD=True,host_validation=False,full_system_fit=False,production_admission=False,
        source_binding_sha256=sha(C/'source-binding.json'),
        scope='Actual full256 AddressStats 8/16/32 bank geometry, every6144target edge and5684output pre/post observation including invalid5120payload words. No complete DCache/host/area/shell or whole formal claim.')
    unit='ec-opt4-common-bank-geometry-r3-20261113.service'
    while not (G/'result.json').is_file() or members(unit):
        if (G/'failure.json').exists():raise RuntimeError(('Diagnose failed geometry prerequisite',str(G/'failure.json')))
        m.update('WAITING_EXACT_GEOMETRY_PROOFS_AND_CGROUP_RELEASE')
        time.sleep(30)
    result=read(G/'result.json')
    assert result['status']=='PASS_PARAMETERIZED_COMMON_BANK_GEOMETRY_PREREQUISITES_NOT_HOST_OR_AREA'
    assert result['hardware_commit']==binding['geometry_prerequisite_commit']
    save(O/'adopted-geometry-prerequisite.json',dict(result=str(G/'result.json'),result_sha256=sha(G/'result.json'),
        source_binding_sha256=sha(W/'candidates/common-bank-geometry-r3-20261113/source-binding.json'),
        exact_predecessor_cgroup_released=True))
    os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    save(O/'admission.json',m.admission())
    cfg=read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java=[cfg['java'],'-Xmx32G','-Xss32M','-XX:ActiveProcessorCount=2']
    base=':'.join(map(str,[P/'classes',D/'build-logs/Opt4-common-stats-bank-r1-20261113/classes',D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes']))+':'+':'.join(cfg['classpath'])
    classes=O/'classes';classes.mkdir()
    m.stage('compile-proof-caller',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',base,
        '-Xplugin:'+cfg['plugin'],'-d',classes,C/'CandidateProof.scala',C/'Emit.scala'],[classes/'geometrycomplete/Emit.class'])
    cp=str(classes)+':'+base
    validated={}
    for lanes in [16,8,32]:
        out=O/f'lanes-{lanes}';out.mkdir()
        for mode in ['Proof','Module']:
            dest=out/mode;dest.mkdir();top='Banked'+mode+'Candidate'
            m.stage(f'emit-{mode}-{lanes}',java+['-cp',cp,'geometrycomplete.Emit',str(lanes),mode,dest],[dest/(top+'.v')])
        public=out/'Module/BankedModuleCandidate.v'
        reference_public=REF/'Reference-Module/BankedModuleReference.v'
        assert ports(public,'BankedModuleCandidate')==ports(reference_public,'BankedModuleReference')
        assert len([p for p in ports(public,'BankedModuleCandidate') if p[0]=='output'])==52
        save(out/'public-abi.json',dict(exact=True,outputs=52,proof_ports_absent=True,
            candidate_RTL_sha256=sha(public),reference_RTL_sha256=sha(reference_public)))
        reference,tb=testbench(lanes,out/'Proof/BankedProofCandidate.v',out)
        exe=out/'obj/Vtb'
        m.stage(f'compile-target-{lanes}',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
            '--Mdir',out/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
            '--x-initial','0','--x-assign','0','-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",
            '-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',reference,out/'Proof/BankedProofCandidate.v',tb],[exe])
        m.stage(f'full-target-{lanes}',[exe],marker='PACKED_COMPLETE_MODULE_PARITY_PASS cycles=6144')
        m.stage(f'invalid-payload-negative-{lanes}',[exe,'+EC_MUTATE'],negative=True,
            marker='PACKED_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000')
        validated[str(lanes)]=dict(cycles=6144,outputs=5684,public_outputs=52,invalid_payload_words=5120,
            before_and_after_edge=True,oracle_inverse_byte_equal=True,negative_invalid_payload_rejected=True,
            testbench_binding_sha256=sha(out/'testbench-binding.json'),public_abi_sha256=sha(out/'public-abi.json'))
        save(O/'completed-geometries.json',validated)
    assert all(sha(p)==h for p,h in binding['files'].items())
    m.update('PASS_COMPLETE_ADDRESS_CALLER_8_16_32_FINITE_ALL_STATE_AND_ABI_NOT_HOST_AREA',
        validated=validated,ended_utc=now(),full_formal=False,
        next='Bind actual8/32 mixed caller host token/throughput and serial same-scope area screens; full frozen DCache/caller/host/ABI and exact shell gates still mandatory. No measured savings or FIT.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now());save(O/'failure.json',m.ST)
        raise
