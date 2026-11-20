#!/usr/bin/python3
"""Validate the private histogram candidate without CAD or device access."""
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-packed-group-reduction-r2-20261112'
S = O/'state.json'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}


def update(status=None, **values):
    ST.update(values, updated_utc=now())
    if status:
        ST['status'] = status
    save(S, ST)


def prepare():
    O.mkdir(exist_ok=True)
    source = W/'candidates/address-group4-r1-20261111/EmitGroup.scala'
    text = source.read_text()
    text = text[:text.index('class GroupProof')] + text[text.index('/** Full 80-source'):]
    text = text.replace('package opt4group', 'package opt4packed').replace('object EmitGroup', 'object EmitPacked')
    text = text.replace('    case "proof" => stage.emitVerilog(new GroupProof, Array("--target-dir", args(1)))\n', '')
    begin = text.index('    case "address" =>')
    text = text[:begin] + '  }\n}\n'
    emitter = C/'EmitPacked.scala'
    if emitter.exists():
        assert emitter.read_text() == text
    else:
        emitter.write_text(text)
    helper = W/'candidates/address-group4-r1-20261111/controller.py'
    spec = importlib.util.spec_from_file_location('packed_boundary_reference', helper)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    cpp = C/'boundary.cpp'
    text = m.boundary_cpp()
    if cpp.exists():
        assert cpp.read_text() == text
    else:
        cpp.write_text(text)
    cfgfile = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgfile)
    plan = read(C/'plan.json')
    assert sha(plan['source']) == plan['source_sha256']
    assert sha(C/'AddressBucketGrouped.scala') == plan['candidate_sha256']
    paths = [C/'validate.py', C/'AddressBucketGrouped.scala', C/'plan.json', emitter, cpp, source, helper, cfgfile]
    paths += [Path(p) for p in cfg['classpath'] + cfg['compiler'] + [cfg['plugin']]]
    pins = dict(schema='ec-private-packed-histogram-local-validation/1',
        functional_baseline=plan['functional_baseline'], files={str(p): sha(p) for p in paths},
        actual_bounds=[8, 3, 2, 1], actual_scatter_widths=[6, 4, 4, 3],
        actual_packed_lane_widths=[11, 9, 9, 8], actual_packed_width=37,
        actual_inputs=80, actual_groups=20, buckets=256, granules=4,
        earlier_500bit_proof='Wider synthetic reduction only; not the actual instantiated histogram',
        fpga_access=False, full_host_synthesis=False, production_admission=False,
        full_module_parity=False, no_area_saving_claim=True,
        remaining_gates=['Complete target parity including invalid/debug state',
            'Paired complete-module area and unchanged latency', 'Whole-host post-opt FIT'])
    pinfile = C/'validation-inputs.json'
    if pinfile.exists():
        assert read(pinfile) == pins
    else:
        save(pinfile, pins)
    return cfg, pins


def stage(name, argv, outputs=(), require=None):
    receipt = O/(name+'-receipt.json')
    if receipt.exists():
        r = read(receipt)
        assert r['returncode'] == 0 and all(sha(p) == h for p, h in r['outputs'].items())
        assert sha(r['log']) == r['log_sha256']
        return Path(r['log'])
    log = O/(name+'.log')
    assert not log.exists(), 'Partial owned attempt retained; versioned recovery required'
    start = time.monotonic()
    with log.open('xb', buffering=0) as stream:
        child = subprocess.Popen(list(map(str, argv)), cwd=O, stdin=subprocess.DEVNULL,
            stdout=stream, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '2'})
        update('RUNNING_'+name.upper(), child=identity(child.pid), active_stage=name)
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(stream.fileno())
            update(child=identity(child.pid), stage_wall_seconds=time.monotonic()-start)
    result = dict(argv=list(map(str, argv)), returncode=child.returncode,
        log=str(log), log_sha256=sha(log), host_wall_seconds=time.monotonic()-start,
        outputs={str(p): sha(p) for p in outputs if Path(p).is_file()},
        missing_outputs=[str(p) for p in outputs if not Path(p).is_file()])
    save(receipt, result)
    update(child={})
    assert child.returncode == 0 and not result['missing_outputs'], (name, result)
    if require:
        assert require in log.read_text(), (name, 'missing required success marker')
    return log


def main():
    cfg, pins = prepare()
    if '--prepare-only' in sys.argv:
        return
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    old = read(S)
    assert not live(old) and not live(old.get('child', {})), 'adopt existing local validation'
    assert all(sha(p) == digest for p, digest in pins['files'].items())
    os.sched_setaffinity(0, {214, 215})
    resource.setrlimit(resource.RLIMIT_AS, (24*2**30,)*2)
    ST.update(schema=pins['schema'], **identity(), started_utc=now(),
        functional_baseline=pins['functional_baseline'], cpus=[214, 215],
        memory_limit_gib=24, fpga_access=False, full_host_synthesis=False,
        production_admission=False, full_module_parity=False,
        inputs_sha256=sha(C/'validation-inputs.json'))
    update('STARTING_PRIVATE_LOCAL_VALIDATION')
    classes = O/'classes'
    classes.mkdir(exist_ok=True)
    cp = ':'.join(cfg['classpath'])
    java = [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=2']
    stage('scala-compile', java+['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
        '-classpath', cp, '-Xplugin:'+cfg['plugin'], '-d', classes,
        C/'AddressBucketGrouped.scala', C/'EmitPacked.scala'],
        [classes/'boom/lsu/AddressBucketGrouped$.class', classes/'opt4packed/EmitPacked$.class'])
    hist = O/'histogram'
    hist.mkdir(exist_ok=True)
    rtl = hist/'HistogramProbe.v'
    stage('elaborate-histogram', java+['-cp', str(classes)+':'+cp,
        'opt4packed.EmitPacked', 'histogram', hist], [rtl])
    exe = hist/'obj/VHistogramProbe'
    stage('boundary-compile', ['/usr/local/bin/verilator', '--cc', '--exe', '--build',
        '--top-module', 'HistogramProbe', '--Mdir', hist/'obj', '-j', '2',
        '--output-split', '10000', '--output-split-cfuncs', '200', '-Wno-fatal',
        '-CFLAGS', '-O0', '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', rtl, C/'boundary.cpp'], [exe])
    stage('boundary-run', [exe], require='HISTOGRAM_ACTUAL_SIZE_PASS vectors=8192 inputs=80 outputs=1024 slots=256 width=64 overflow=1 reset=1')
    update('PASS_LOCAL_ACTUAL_HISTOGRAM_NOT_COMPLETE_MODULE_OR_AREA', child={},
        actual_vectors=8192, actual_output_checks=8192*1024, target_registers_added=0,
        area_saving_unknown=True, complete_module_parity=False, completed_utc=now())
    save(O/'result.json', ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE', error=repr(exc))
        raise
