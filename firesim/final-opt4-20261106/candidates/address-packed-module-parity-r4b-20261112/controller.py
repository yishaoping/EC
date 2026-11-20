#!/usr/bin/python3
"""Complete private address target finite parity, including every debug word.

No Vivado, Golden Gate, whole-host build, source integration or device access.
Failed attempts remain immutable and require an independent recovery version.
"""
from pathlib import Path
import fcntl
import os
import resource
import shutil
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-address-packed-module-parity-r4b-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,live,now,read,save,sha

ST={}


def update(status=None,**values):
    ST.update(values,updated_utc=now())
    if status: ST['status']=status
    save(O/'state.json',ST)


def gate():
    while True:
        mem=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk=shutil.disk_usage(W).free
        load=float(Path('/proc/loadavg').read_text().split()[0])
        if mem>=96*2**20 and disk>=40*2**30 and load<64:
            return
        update('WAITING_RESOURCES_NO_SIGNALS',available_kib=mem,disk_bytes=disk,load1=load)
        time.sleep(30)


def stage(name,argv,outputs=(),negative=False,marker=None):
    receipt=O/(name+'-receipt.json')
    if receipt.exists():
        r=read(receipt)
        assert r['accepted'] and sha(r['log'])==r['log_sha256']
        assert all(sha(p)==h for p,h in r['outputs'].items())
        return r
    log=O/(name+'.log')
    assert not log.exists(),'Partial stage preserved; independently version recovery'
    gate()
    start=time.monotonic()
    with log.open('xb',buffering=0) as stream:
        child=subprocess.Popen(list(map(str,argv)),cwd=O,stdin=subprocess.DEVNULL,
            stdout=stream,stderr=subprocess.STDOUT,
            env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2','MAKEFLAGS':'-j2'})
        update('RUNNING_'+name.upper(),child=identity(child.pid),active_stage=name,log=str(log))
        while child.poll() is None:
            try: child.wait(timeout=30)
            except subprocess.TimeoutExpired: pass
            os.fsync(stream.fileno())
            update(child=identity(child.pid),stage_wall_seconds=time.monotonic()-start)
    accepted=(child.returncode!=0 if negative else child.returncode==0)
    # A signal, compiler failure or generic crash is never a successful
    # negative test: require the actual unmasked debug mismatch marker.
    accepted=accepted and (marker is None or marker in log.read_text(errors='replace'))
    observed={str(p):sha(p) for p in outputs if Path(p).is_file()}
    accepted=accepted and len(observed)==len(outputs)
    r=dict(argv=list(map(str,argv)),returncode=child.returncode,accepted=accepted,
        negative=negative,required_marker=marker,log=str(log),log_sha256=sha(log),
        outputs=observed,wall_seconds=time.monotonic()-start,completed_utc=now())
    save(receipt,r)
    update(child={})
    assert accepted,(name,r)
    return r


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(O/'state.json')
    assert not live(old) and not live(old.get('child',{})),'Adopt existing pair'
    pins=read(C/'inputs.json')
    assert pins and all(sha(p)==h for p,h in pins['files'].items()),'Input hash mismatch'
    local=D/'build-logs/Opt4-address-packed-group-reduction-r2-20261112/result.json'
    r=read(local)
    assert r['status']=='PASS_LOCAL_ACTUAL_HISTOGRAM_NOT_COMPLETE_MODULE_OR_AREA'
    assert r['actual_output_checks']==8388608
    assert r['inputs_sha256']==sha(W/'candidates/address-packed-group-reduction-r2-20261112/validation-inputs.json')
    os.sched_setaffinity(0,set(pins['cpus']))
    resource.setrlimit(resource.RLIMIT_AS,(pins['memory_limit_gib']*2**30,)*2)
    resource.setrlimit(resource.RLIMIT_CORE,(0,0))
    ST.update(**identity(),schema=pins['schema'],started_utc=now(),inputs_sha256=sha(C/'inputs.json'),
        functional_baseline=pins['functional_baseline'],cpus=pins['cpus'],memory_limit_gib=pins['memory_limit_gib'],
        fpga_access=False,full_host_synthesis=False,production_admission=False,formal_equivalence=False,
        common_initial_payload='zero; no arbitrary-state equivalence claim',
        actual_histogram_receipt_sha256=sha(local),area_result_available=False)
    update('STARTING_PRIVATE_FULL_MODULE_DEBUG_COMPARISON')
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    classes=O/'classes';classes.mkdir(exist_ok=True)
    java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2']
    cp=':'.join(cfg['classpath'])
    sources=[C/(label+kind+'.scala') for label in ['Reference','Candidate']
        for kind in ['PackageAddressStats','AddressBucketGrouped']]+[C/'AddressBucketUpdate.scala',C/'EmitPair.scala']
    stage('compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',classes,*sources],[classes/'opt4packedpair/EmitPair$.class'])
    rtlout=O/'pair';rtlout.mkdir(exist_ok=True)
    rtl=rtlout/'PackedAddressPair.v'
    stage('elaborate',java+['-cp',str(classes)+':'+cp,'opt4packedpair.EmitPair',rtlout],[rtl])
    text=rtl.read_text()
    assert sum(1 for line in text.splitlines() if 'output' in line and 'io_reference_debugBuckets_' in line)==5120
    assert sum(1 for line in text.splitlines() if 'output' in line and 'io_candidate_debugBuckets_' in line)==5120
    exe=O/'obj/Vtb'
    stage('verilate',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
        '--Mdir',O/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
        '--x-initial','0','--x-assign','0','-Wno-fatal','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',
        "-DRANDOM=32'h0",'-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',rtl,C/'pair-tb.v'],[exe])
    positive=stage('compare',[exe],marker='PACKED_FULL_MODULE_DEBUG_PASS cycles=6144 outputs=5172 debug_checks=31457280')
    negative=stage('compare-invalid-debug-negative',[exe,'+mutate-debug'],negative=True,
        marker='PACKED_DEBUG_MISMATCH word=0 cycle=1900 valid=0')
    update('PASS_FINITE_COMPLETE_MODULE_ALL_DEBUG_OUTPUTS_NOT_FORMAL_OR_AREA',
        completed_utc=now(),child={},checks=pins['checks'],rtl_sha256=sha(rtl),
        positive_receipt_sha256=sha(O/'compare-receipt.json'),
        observer_negative_receipt_sha256=sha(O/'compare-invalid-debug-negative-receipt.json'),
        next=pins['next'],new_cad_jobs=0,new_fpga_samples=0)
    save(O/'result.json',ST)


if __name__=='__main__':
    try: main()
    except Exception as exc:
        if ST: update('FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now())
        raise
