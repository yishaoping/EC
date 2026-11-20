#!/usr/bin/python3
"""Detached initial recovery component validation; no whole synthesis/FPGA."""
from pathlib import Path
import fcntl
import json
import os
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import read, save, sha, identity, live, now

O = D / 'build-logs/Opt4-architectural-recovery-r1-20261111'
S = D / 'Opt4-architectural-recovery-r1-state.json'

def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    previous = read(S)
    assert not live(previous) and not live(previous.get('child', {}))
    cfg = read(C / 'config.json')
    b = cfg['binding']
    assert all(sha(p) == h for p, h in read(C / 'input-hashes.json').items())
    source = Path(cfg['source'])
    assert source.read_bytes() == subprocess.check_output(
        ['git', 'show', b['hardware_commit'] + ':chipyard/generators/boom/src/main/scala/recovery/PackageRecoveryController.scala'], cwd=b['worktree'])
    state = dict(schema='ec-opt4-initial-recovery-component-validation/1',
                 **identity(), hardware_commit=b['hardware_commit'], source_id=b['source_id'],
                 status='STARTING', started_utc=now(), stages=previous.get('stages', {}),
                 architectural_recovery_validated=False, production_selected=False,
                 full_dut_synthesis=False, fpga_access=False,
                 limit='Sequencing component only; real checkpoint storage, architectural and memory restore engines, BOOM/CSR/firmware integration and injected whole-DUT recovery remain unimplemented/unverified.')
    save(S, state)
    def stage(name, args, outputs):
        receipt = O / (name + '-result.json')
        old = read(receipt)
        if old:
            assert old['returncode'] == 0 and old['source_id'] == b['source_id']
            assert all(sha(p) == h for p, h in old['outputs'].items())
            state['stages'][name] = old
            return Path(old['log'])
        log = O / (name + '.log')
        assert not log.exists(), 'failed or partial stage requires versioned recovery'
        with log.open('xb', buffering=0) as stream:
            argv = list(map(str, ['nice', '-n', '10', *args]))
            child = subprocess.Popen(argv, cwd=C, stdin=subprocess.DEVNULL,
                stdout=stream, stderr=subprocess.STDOUT,
                env={**os.environ, 'JAVA_TOOL_OPTIONS':'', 'CCACHE_DISABLE':'1', 'MAKEFLAGS':'-j4'})
            state.update(status='RUNNING_' + name.upper(), active_stage=name,
                         child=identity(child.pid), updated_utc=now())
            save(S, state)
            while child.poll() is None:
                try: child.wait(timeout=30)
                except subprocess.TimeoutExpired: pass
                state['updated_utc'] = now()
                save(S, state)
                os.fsync(stream.fileno())
        result = dict(returncode=child.returncode, source_id=b['source_id'],
                      log=str(log), ended_utc=now(),
                      outputs={str(p):sha(p) for p in outputs if p.is_file()})
        save(receipt, result)
        state.update(child={}, updated_utc=now())
        state['stages'][name] = result
        save(S, state)
        assert child.returncode == 0 and all(p.is_file() for p in outputs), (name, str(log))
        return log
    classes = O / 'classes'
    classes.mkdir(exist_ok=True)
    cp = ':'.join(cfg['classpath'])
    stage('compile', [cfg['java'], '-Xmx8G', '-XX:ActiveProcessorCount=4',
          '-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', cp,
          '-Xplugin:' + cfg['plugin'], '-d', classes, source, C/'Emit.scala'],
          [classes/'opt4recovery/Emit.class'])
    rtl = O/'rtl'
    rtl.mkdir(exist_ok=True)
    verilog = rtl/'PackageRecoveryController.v'
    stage('emit', [cfg['java'], '-Xmx8G', '-XX:ActiveProcessorCount=4', '-cp',
          str(classes)+':'+cp, 'opt4recovery.Emit', rtl], [verilog])
    cpp = O/'test.cpp'
    stage('generate-test', ['/usr/bin/python3', C/'generate_test.py', cpp], [cpp])
    exe = O/'obj/VPackageRecoveryController'
    stage('verilate', ['/usr/local/bin/verilator', '--cc', '--exe', '--build',
          '--assert', '--top-module', 'PackageRecoveryController', '--Mdir', O/'obj',
          '-j', '4', '-Wno-fatal', '-CFLAGS', '-O0',
          '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0', verilog, cpp], [exe])
    log = stage('test', [exe], [])
    assert 'RECOVERY_CONTROL_COMPONENT_PASS positive_transactions=64 negative_cases=10' in log.read_text()
    state.update(status='PASS_INITIAL_CONTROL_COMPONENT_NOT_FULL_ARCHITECTURAL_RECOVERY',
                 component_tests=dict(positive_transactions=64, negative_cases=10),
                 target_rtl_sha256=sha(verilog), completed_utc=now())
    save(S, state)
    save(O/'result.json', state)

if __name__ == '__main__':
    try: main()
    except Exception as exc:
        s = read(S)
        if s.get('pid') == os.getpid():
            s.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
            save(S, s)
        raise
