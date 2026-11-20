#!/usr/bin/env python3
"""Build final frozen C4 on a separately budgeted filesystem. Pure CAD, no FPGA IO."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from build_minimal import sha, inventory


def save(p, value):
    temp = p.with_suffix('.tmp')
    with temp.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    temp.replace(p)


def main():
    lock = (D/'.final-runtime-cad.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    # Independent read-only source/RTL inputs and private CAD directory. The
    # baseline job owns the shared legacy lock; neither job mutates its inputs.
    cad_root = (W/'cad-work').resolve()
    assert cad_root.stat().st_uid == os.getuid()
    disk = shutil.disk_usage(cad_root)
    assert disk.free >= 80*2**30, '80 GiB guard applies to actual CAD filesystem'
    assert shutil.disk_usage(D).free >= 20*2**30, 'preserve result filesystem headroom'
    memory = {l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    assert memory['MemAvailable'] >= 32*2**20
    assert os.getloadavg()[0] < os.cpu_count()*.9
    lineage = json.loads((W/'integration.json').read_text())
    assert lineage['hardware_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    cy = Path(lineage['source_tree'])
    inv = inventory(cy)
    sid = hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
    assert sid == 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
    evidence = json.loads((D/'hardware-revalidation-20261106.json').read_text())
    assert evidence['source_id'] == sid
    ggpath = Path(lineage['build_receipts']['goldengate'])
    drpath = Path(lineage['build_receipts']['driver'])
    gg, driver = [json.loads(p.read_text()) for p in [ggpath,drpath]]
    for r in [gg,driver]:
        assert r['returncode']==0 and r['source_id']==sid and r['source_tree']==str(cy)
        assert r['platform_config']=='DacXilinxAlveoConfig'
        for f,h in r['outputs'].items():assert sha(f)==h,f
    assert driver['input_result']==str(ggpath)
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    label = 'C4-runtime-bitstream-'+stamp
    out = cad_root/label
    logs = D/'build-logs'/label
    logs.mkdir()
    platform = cy/'sims/firesim/platforms/xilinx_alveo_u280/cl_firesim'
    shutil.copytree(platform,out,symlinks=False)
    inputs = {str(f):sha(f) for f in [ggpath,drpath,D/'hardware-revalidation-20261106.json',W/'integration.json']}
    for name in ['sv','defines.vh','synthesis.xdc','implementation.xdc']:
        src = Path(gg['output_dir'])/('FireSim-generated.'+name)
        assert sha(src)==gg['outputs'][str(src)]
        shutil.copy2(src,out/'design'/src.name)
        inputs[str(src)]=sha(src)
    (out/'scripts/platform_env.tcl').write_text('set jobs 2\n')
    board = out/'scripts/au280.tcl'
    board.write_text(board.read_text().replace('xilinx.com:au280:part0:1.2','xilinx.com:au280:part0:1.1'))
    boards = Path('/data1/gzh/EC/firesim/dac2026/deps/boards')
    wrapper = out/'scripts/dac_compile.tcl'
    wrapper.write_text('set_param general.maxThreads 2\nset_param board.repoPaths {'+str(boards)+'}\nsource [file join [pwd] scripts main.tcl]\n')
    synthesis = out/'scripts/synthesis.tcl'
    synthesis.write_text(synthesis.read_text().replace('launch_runs ${synth_run}',
        'set_property STEPS.SYNTH_DESIGN.ARGS.DIRECTIVE RuntimeOptimized [get_runs -filter {IS_SYNTHESIS == 1}]\nlaunch_runs ${synth_run}',1))
    effective = {str(f):sha(f) for f in sorted(out.rglob('*')) if f.is_file()}
    env = os.environ.copy()
    env.update(OMP_NUM_THREADS='2',MAKEFLAGS='-j1',TMPDIR=str(out/'tmp'))
    (out/'tmp').mkdir()
    argv = ['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
            '-log',str(logs/'vivado.log'),'-source',str(wrapper),'-tclargs','50','TIMING','au280']
    state = dict(schema='ec-final-opt4-cad/1',status='STARTING',phase='bitstream',configuration='C4',
                 pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],
                 hardware_commit=lineage['hardware_commit'],source_tree=str(cy),source_id=sid,
                 golden_gate_result=str(ggpath),driver_result=str(drpath),output_dir=str(out),log_dir=str(logs),
                 inputs=inputs,effective_cad_inputs=effective,argv=argv,host_fpga_clock_mhz=50,
                 target_boom_clock_mhz=200,target_checker_clock_mhz=100,jobs=2,max_threads=2,
                 synthesis_directive='RuntimeOptimized',alternative_to=str(D/'C4-cad-state.json'),reason='Original synthesis hot spot HOptDfg reconvergent graph merging; retain original while trying supported runtime directive with identical DUT/GG RTL/clock constraints',no_fpga_device_access=True,runtime_validation='NOT_RUN',started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 disk_budget=dict(filesystem_device=cad_root.stat().st_dev,initial_free_gib=disk.free/2**30,
                                  start_minimum_gib=80,stop_free_below_gib=60,max_growth_gib=120),
                 script_sha256=sha(__file__),returncode=None,certified_bitstream=False)
    (logs/'build-script.py').write_bytes(Path(__file__).read_bytes())
    save(logs/'command.json',state)
    (W/'cad-runtime-current.json').write_text(json.dumps(dict(output_dir=str(out),log_dir=str(logs)),indent=2)+'\n')
    start=time.monotonic()
    child=None
    stopped=None
    def stop(sig,frame):
        nonlocal stopped
        stopped='INTERRUPTED'
        if child and child.poll() is None:os.killpg(child.pid,signal.SIGTERM)
    signal.signal(signal.SIGINT,stop)
    signal.signal(signal.SIGTERM,stop)
    with (logs/'build.log').open('wb',buffering=0) as stream:
        child=subprocess.Popen(argv,cwd=out,env=env,stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
        state.update(status='RUNNING',child_pid=child.pid,child_pgid=child.pid,
                     child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21])
        save(D/'C4-runtime-cad-state.json',state)
        print(json.dumps(dict(pid=child.pid,pgid=child.pid,output=str(out),log=str(logs))),flush=True)
        while child.poll() is None:
            try:child.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            free=shutil.disk_usage(cad_root).free
            state.update(elapsed_seconds=time.monotonic()-start,disk_free_gib=free/2**30,
                         updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(D/'C4-runtime-cad-state.json',state)
            if child.poll() is None and (free < 60*2**30 or disk.free-free > 120*2**30 or time.monotonic()-start>24*3600):
                stopped='RESOURCE_LIMIT_OR_TIMEOUT'
                os.killpg(child.pid,signal.SIGTERM)
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
    rc=child.returncode
    bit=out/'vivado_proj/firesim.bit'
    if rc==0 and (not bit.is_file() or not bit.stat().st_size):rc=1
    if rc==0 and inventory(cy)!=inv:rc=1;stopped='SOURCE_CHANGED'
    if rc==0 and any(sha(f)!=h for f,h in effective.items()):rc=1;stopped='CAD_INPUT_CHANGED'
    state.update(returncode=rc,status=stopped or ('BUILT_NOT_RUN' if rc==0 else 'FAILED'),
                 certified_bitstream=rc==0,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 wall_seconds=time.monotonic()-start,outputs={str(bit):sha(bit)} if bit.exists() else {})
    save(logs/'result.json',state)
    save(D/'C4-runtime-cad-state.json',state)
    if rc==0:
        destination=W/'images'/label
        destination.mkdir(parents=True)
        shutil.copy2(bit,destination/'firesim.bit')
        assert sha(destination/'firesim.bit')==state['outputs'][str(bit)]
        state['durable_bitstream']=str(destination/'firesim.bit')
        state['durable_bitstream_sha256']=sha(destination/'firesim.bit')
        save(destination/'result.json',state)
        save(W/'bitstream-runtime-build.json',state)
        save(D/'C4-runtime-cad-state.json',state)
    print(json.dumps(dict(status=state['status'],returncode=rc,result=str(logs/'result.json'))),flush=True)
    return rc or (1 if stopped else 0)


if __name__=='__main__':raise SystemExit(main())
