#!/usr/bin/python3
"""One source-bound GoldenGate port inventory; no parity, mapping or device IO."""
import fcntl
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-barrier-storage-port-audit-r143-v1-20261112'
PARENT = W/'candidates/barrier-valid-masked-storage-r1-20261112'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST = {}


def update(**kw):
    ST.update(kw, updated_utc=now())
    save(O/'state.json', ST)


def stage(name, argv, outputs):
    log = O/(name+'.log')
    assert not log.exists(), 'Preserve partial attempt; use a new recovery version'
    started = time.monotonic()
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str, argv)), cwd=O, stdin=subprocess.DEVNULL,
            stdout=f, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2'})
        update(status='RUNNING_'+name.upper(), child=identity(child.pid), active_stage=name)
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(f.fileno())
            update(stage_wall_seconds=time.monotonic()-started)
    receipt = dict(argv=list(map(str, argv)), returncode=child.returncode,
        log=str(log), log_sha256=sha(log), wall_seconds=time.monotonic()-started,
        outputs={str(p):sha(p) for p in outputs if p.is_file()},
        missing_outputs=[str(p) for p in outputs if not p.is_file()])
    save(O/(name+'-receipt.json'), receipt)
    update(child={})
    assert child.returncode == 0 and not receipt['missing_outputs'], (name, receipt)


def memory_inventory(text):
    """Read memory declarations rather than infer ports from Scala call counts."""
    memories = []
    module = None
    lines = text.splitlines()
    for i, line in enumerate(lines):
        mod = re.match(r'  module (\w+)\s*:', line)
        if mod:
            module = mod[1]
        match = re.match(r'(\s*)mem (\w+)\s*:', line)
        if not match:
            continue
        indent = len(match[1])
        fields = {}
        for following in lines[i+1:]:
            if following.strip() and len(following)-len(following.lstrip()) <= indent:
                break
            field = re.match(r'\s*([\w-]+) => (.+)', following)
            if field:
                fields.setdefault(field[1], []).append(field[2])
        memories.append(dict(module=module, name=match[2], fields=fields))
    return memories


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Never restart an existing attempt'
    pins = read(C/'inputs.json')
    assert all(sha(p)==h for p,h in pins['files'].items()), 'Bound input changed'
    # Admission is through the existing CPU broker; these only bound this task.
    os.sched_setaffinity(0, {216,217})
    resource.setrlimit(resource.RLIMIT_AS, (24*2**30,24*2**30))
    ST.update(schema='ec-private-barrier-storage-port-audit/1', **identity(),
        started_utc=now(), inputs_sha256=sha(C/'inputs.json'),
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source_sha256=sha(PARENT/'BarrierLatencyStats.scala'),
        full_module_parity=False, area_saving_unknown=True, full_host_synthesis=False,
        fpga_access=False, production_admission=False, cpus=[216,217], memory_limit_gib=24)
    update(status='STARTING')
    cfg = read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    classes = O/'classes'
    classes.mkdir()
    java = [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=2']
    compiler = java+['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
        '-classpath', ':'.join(cfg['classpath']), '-Xplugin:'+cfg['plugin'], '-d', classes]
    stage('compile', compiler+[PARENT/'BarrierLatencyStats.scala', C/'Emit.scala'],
        [classes/'opt4barrierports143/Harness.class', classes/'opt4barrierports143/MCConfig.class'])
    cp = str(classes)+':'+':'.join(cfg['classpath'])
    target = O/'target'
    target.mkdir()
    stage('elaborate', java+['-cp', cp, 'freechips.rocketchip.system.Generator',
        '--target-dir', target, '--name', 'Barrier', '--top-module', 'opt4barrierports143.Harness',
        '--configs', 'firesim.midasexamples.NoConfig'], [target/'Barrier.fir',target/'Barrier.anno.json'])
    raw = (target/'Barrier.fir').read_text()
    assert 'cmem payload' in raw, 'Actual candidate memory missing'
    host = O/'gg'
    host.mkdir()
    stage('goldengate', java+['-cp',cp,'midas.stage.GoldenGateMain',
        '-i',target/'Barrier.fir','-td',host,'-faf',target/'Barrier.anno.json',
        '-ggcp','opt4barrierports143','-ggcs','MCConfig',
        '--output-filename-base','FireSim-generated','--no-dedup'],
        [host/'FireSim-generated.sv',host/'post-wrap-sram-models.fir',host/'post-infer-model-ports.json'])
    memories = memory_inventory((host/'post-wrap-sram-models.fir').read_text())
    payloads = [m for m in memories if m['name'].startswith('payload')]
    assert payloads, 'No extracted payload memory'
    widths = []
    for m in payloads:
        f = m['fields']
        assert f['depth'] == ['256'] and f['read-latency'] == ['0'] and f['write-latency'] == ['1'], m
        widths.append(sum(map(int,re.findall(r'UInt<(\d+)>', f['data-type'][0]))))
        assert len(f.get('writer',[]))==1 and not f.get('readwriter'), m
        assert len(f.get('reader',[]))==256, m
    assert sum(widths)==160, (widths,payloads)
    annotations = read(host/'post-infer-model-ports.json')
    port_counts = {kind:sum(a.get('class')=='midas.passes.fame.'+kind for a in annotations)
        for kind in ['ModelReadPort','ModelWritePort','ModelReadWritePort']}
    assert port_counts['ModelWritePort']==len(payloads), port_counts
    assert port_counts['ModelReadPort']==256*len(payloads), port_counts
    assert port_counts['ModelReadWritePort']==0, port_counts
    update(status='PASS_ACTUAL_GOLDENGATE_STORAGE_PORT_INVENTORY_NOT_PARITY_OR_AREA',
        completed_utc=now(), memories=payloads, data_widths=widths,
        logical_payload_bits=256*sum(widths), extracted_ports=port_counts,
        outputs={str(p):sha(p) for p in [target/'Barrier.fir',target/'Barrier.anno.json',
            host/'FireSim-generated.sv',host/'post-wrap-sram-models.fir',host/'post-infer-model-ports.json']},
        next='Complete-module finite parity including masked invalid state and stale sequence; paired host area only after existing module resource admission. No integration or whole synthesis from this audit.')
    save(O/'result.json', ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
            save(O/'failure.json', ST)
        raise
