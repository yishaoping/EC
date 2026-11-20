#!/usr/bin/python3
"""Compile a source-bound MSHR optimization and exercise its actual queue."""
from pathlib import Path
import fcntl
import importlib.util
import json
import os
import resource
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-mshr-queue-split-memory-r1-20261112'
spec = importlib.util.spec_from_file_location('stages',W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m = importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.O = O
from opt4_unattended_common import identity, now, read, save, sha
from prepare import prepare


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing attempt'
    os.sched_setaffinity(0,{204,205})
    resource.setrlimit(resource.RLIMIT_AS,(32*2**30,)*2)
    binding=prepare()
    cfg=read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    m.ST.update(schema='ec-mshr-split-queue-validation/1',**identity(),started_utc=now(),
        cpus=[204,205],memory_limit_gib=32,source_binding_sha256=sha(C/'source-binding.json'),
        hardware_parent=binding['hardware_parent'],functional_baseline=binding['functional_baseline'],
        fpga_access=False,production_admission=False,area_saving_unknown=True,
        no_CAD=True,full_system_fit=False,
        scope='Actual full16-entry holdable MSHR request queue finite cycles; not complete MSHR/DCache/system equivalence or measured host area.')
    m.update('SOURCE_CONTRACT_PASS')
    classes=O/'classes';classes.mkdir()
    sources=[C/n for n in ['Reference.scala','Candidate.scala','Emit.scala',
                           'BoomMSHRBranchKillableQueue.scala','mshrs.scala']]
    # Compile both the probe and production-ready MSHR implementation, preserving
    # all six MSHRs and their original descriptors/handshakes.
    m.stage('compile-source',[cfg['java'],'-Xmx16G','-Xss16M','-XX:ActiveProcessorCount=2',
        '-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),
        '-Xplugin:'+cfg['plugin'],'-d',classes,*sources],
        [classes/'mshrsplitprobe/Emit.class',classes/'boom/lsu/BoomMSHRFile.class'])
    target=O/'target';target.mkdir()
    m.stage('emit-actual-queue',[cfg['java'],'-Xmx16G','-Xss16M','-XX:ActiveProcessorCount=2',
        '-Dec.dac.firesim=true','-cp',str(classes)+':'+':'.join(cfg['classpath']),
        'mshrsplitprobe.Emit',target],[target/'QueuePair.v'])
    header=(target/'QueuePair.v').read_text().split('module QueuePair(',1)[1].split(');',1)[0]
    import re
    enq=int(re.search(r'input\s+\[(\d+):0\]\s+io_enqBits',header)[1])+1
    branch=int(re.search(r'input\s+\[(\d+):0\]\s+io_branch',header)[1])+1
    assert enq>512 and branch>8
    stim=(C/'stimulus.cpp').read_text().replace('@ENQ_WORDS@',str((enq+31)//32)).replace(
        '@BRANCH_WORDS@',str((branch+31)//32))
    m.exact(O/'stimulus.cpp',stim)
    exe=O/'obj/VQueuePair'
    m.stage('compile-finite-pair',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2',
        '--compiler','clang','--top-module','QueuePair','--Mdir',O/'obj','-Wno-fatal',
        '--x-initial','0','--x-assign','0','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',
        "-DRANDOM=32'h0",'-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',
        target/'QueuePair.v',O/'stimulus.cpp'],[exe])
    log=m.stage('full-queue-finite-cycles',[exe])
    assert 'MSHR_QUEUE_FINITE_PASS cycles=65536' in log.read_text()
    assert all(sha(p)==h for p,h in binding['files'].items())
    m.update('PASS_ACTUAL_FULL_MSHR_QUEUE_FINITE_CYCLES_NO_AREA_CLAIM',ended_utc=now(),
        finite_cycles=65536,payload_bits=enq,branch_update_bits=branch,
        all_outputs_including_invalid_payload_compared=True,complete_formal_equivalence=False,
        next='Measure complete same-harness MSHR generated host pair only after this private optimization is useful in composition. Complete DCache cycles and actual host validation remain mandatory before integration.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
