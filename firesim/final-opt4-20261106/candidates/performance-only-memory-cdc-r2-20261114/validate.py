#!/usr/bin/env python3
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import subprocess

C=Path(__file__).resolve().parent
W=C.parent.parent
T=W/'Opt4-performance-only-memory-cdc-r2-20261114'
O=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-memory-cdc-r2-20261114/run-r1')
cfg=json.loads((W/'candidates/address-banked-storage-compose-r1-20261112/config.json').read_text())

def save(status, **kw):
    p=O/'state.json'; tmp=p.with_suffix('.tmp')
    tmp.write_text(json.dumps(dict(status=status,utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        functional_baseline='6fada307',fpga_access=False,full_system_equivalence=False,**kw),indent=2)+'\n')
    os.replace(tmp,p)

def run(stage,args):
    save('RUNNING_'+stage, pid=os.getpid())
    with (O/(stage+'.log')).open('wb') as log:
        r=subprocess.run([str(a) for a in args],cwd=O,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
    if r.returncode:raise RuntimeError((stage,r.returncode))

def main():
    os.sched_setaffinity(0,{246,247})
    O.mkdir(exist_ok=False)
    src=T/'chipyard/generators/rocket-chip/src/main/scala/util/AsyncQueue.scala'
    base=W/'Opt4-performance-only-fpga-r1-20261113/chipyard/generators/rocket-chip/src/main/scala/util/AsyncQueue.scala'
    assert src.read_bytes()==base.read_bytes()
    classes=O/'classes';classes.mkdir();target=O/'target';target.mkdir()
    cp=':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx12G','-Xss16M','-XX:ActiveProcessorCount=2']
    run('SCALA_COMPILE',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,src,T/'chipyard/generators/rocket-chip/src/main/scala/util/LocalMemAsyncQueue.scala',C/'Emit.scala'])
    run('EMIT_ACTUAL_ASYNC_QUEUE_PAIR',java+['-cp',str(classes)+':'+cp,'localcdcprobe.Emit',target])
    run('VERILATOR_COMPILE',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2',
        '--top-module','QueuePair','--Mdir',O/'obj','-Wno-fatal','--x-initial','0','--x-assign','0',
        '-CFLAGS','-O1',target/'QueuePair.v',C/'compare.cpp'])
    run('TWO_CLOCK_FINITE_CYCLES',[O/'obj/VQueuePair'])
    text=(O/'TWO_CLOCK_FINITE_CYCLES.log').read_text();assert 'LOCAL_CDC_PAIR_PASS' in text
    save('PASS_ACTUAL_QUEUE_FINITE_CYCLES_NOT_FULL_HOST_EQUIVALENCE',
         receipt=text.strip(),source_sha256=hashlib.sha256(src.read_bytes()).hexdigest(),
         capacity=256,payload_bits=305,sync_stages=2,safety_unchanged=True,
         scope='Actual production AsyncQueue class, narrow false versus true; every output including invalid payload, independent clocks/resets. Full Golden Gate host and whole system equivalence pending.')

if __name__=='__main__':
    try:main()
    except Exception as e:
        save('FAILED_WITH_EVIDENCE',error=repr(e));raise
