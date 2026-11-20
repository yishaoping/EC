#!/usr/bin/env python3
"""Actual two-clock Golden Gate token comparison, sequenced after module screening."""
import datetime as dt
import json
import os
from pathlib import Path
import subprocess
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
R=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=R/'performance-only-memory-cdc-r2-20261114'
H=O/'host-r1'
FS=W/'C4/chipyard/sims/firesim/sim'
cfg=json.loads((W/'candidates/address-banked-storage-compose-r1-20261112/config.json').read_text())

def save(status,**kw):
    p=H/'state.tmp';p.write_text(json.dumps(dict(status=status,utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        hardware_baseline='6fada307',fpga_access=False,model_requests=False,full_system_equivalence=False,**kw),indent=2)+'\n')
    os.replace(p,H/'state.json')

def run(name,args,env=None,timeout=3600,negative=False,marker=None):
    save('RUNNING_'+name)
    log=H/(name+'.log')
    with log.open('wb') as f:
        p=subprocess.run([str(a) for a in args],cwd=H,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env,timeout=timeout)
    text=log.read_text(errors='replace')
    if (p.returncode==0)==negative or (marker and marker not in text):raise RuntimeError((name,p.returncode))

def main():
    os.sched_setaffinity(0,{246,247})
    H.mkdir(exist_ok=False)
    save('WAITING_COMPLETE_MODULE_AREA')
    start=time.monotonic()
    while True:
        area=O/'area-r1/state.json'
        if area.is_file():
            a=json.loads(area.read_text())
            if a['status'].startswith('COMPLETE_QUEUE_PAIR_AREA'):break
            if a['status'].startswith('FAILED'):raise RuntimeError('area screening failed; preserve all evidence and do not integrate')
        if time.monotonic()-start>18000:raise RuntimeError('bounded wait for area screening expired')
        time.sleep(15)
    classes=H/'classes';classes.mkdir()
    target=H/'target';target.mkdir()
    cp=':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx16G','-Xss24M','-XX:ActiveProcessorCount=2']
    src=W/'Opt4-performance-only-memory-cdc-r2-20261114/chipyard/generators/rocket-chip/src/main/scala/util/AsyncQueue.scala'
    run('SCALA_COMPILE',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',classes,src,W/'Opt4-performance-only-memory-cdc-r2-20261114/chipyard/generators/rocket-chip/src/main/scala/util/LocalMemAsyncQueue.scala',C/'Emit.scala',C/'Host.scala'])
    fullcp=str(classes)+':'+cp
    run('ELABORATE',java+['-cp',fullcp,'localcdcprobe.EmitHost',target])
    generated=H/'generated';generated.mkdir()
    run('GOLDENGATE',java+['-cp',fullcp,'midas.stage.GoldenGateMain','-i',target/'QueuePairHost.fir',
        '-td',generated,'-faf',target/'QueuePairHost.anno.json','-ggcp','localcdcprobe','-ggcs','PlainConfig',
        '--output-filename-base','FireSim-generated'])
    listing=generated/'firrtl_black_box_resource_files.f'
    simulation=generated/'simulation.sv'
    simulation.write_text((generated/'FireSim-generated.sv').read_text()+
        ''.join(Path(p).read_text() for p in listing.read_text().splitlines() if p.strip()))
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=R/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    run('COMPILE_HOST',['make','-C',FS/'midas/src/main/cc','-j2','verilator','PLATFORM=xilinx_alveo',
        'DRIVER_NAME=QueuePairHost','GEN_DIR='+str(generated),'GEN_FILE_BASENAME=FireSim-generated',
        'DESIGN_V='+str(simulation),'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestQueue.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],env=env,timeout=7200)
    exe=generated/'VQueuePairHost'
    args=[exe,'+seed=8491167','+max-cycles=10000000']
    run('TOKENS',args,env=env,marker='LOCAL_CDC_HOST_TOKEN_PASS tokens=8192')
    run('NEGATIVE_CONTROL',args+['+negative'],env=env,negative=True,marker='LOCAL_CDC_HOST_MISMATCH token=100')
    save('PASS_TWO_CLOCK_GOLDENGATE_FINITE_TOKENS_AND_NEGATIVE_CONTROL',tokens=8192,capacity=256,payload_bits=305,
        scope='Both actual queue implementations in one generated host, exact public output token boundary; whole-system validation and routability remain unproved.')

if __name__=='__main__':
    try:main()
    except Exception as e:
        if H.is_dir():save('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
