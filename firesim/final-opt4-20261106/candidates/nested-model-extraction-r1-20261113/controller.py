#!/usr/bin/python3
"""Bounded nested-model extraction regression, without CAD or FPGA access."""
from pathlib import Path
import fcntl
import hashlib
import json
import os
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-nested-model-extraction-r1-20261113'
T = W / 'Opt4-area-nested-model-extraction-r1-20261113'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST = {}


def members(unit):
    found = []
    for path in Path('/proc').iterdir():
        if not path.name.isdigit():
            continue
        try:
            if any(line.split(':', 2)[-1].endswith('/' + unit) or
                   ('/' + unit + '/') in line.split(':', 2)[-1]
                   for line in (path / 'cgroup').read_text().splitlines()):
                found.append(identity(int(path.name)))
        except OSError:
            pass
    return found


def update(status, **kw):
    ST.update(status=status, updated_utc=now(), **kw)
    save(O / 'state.json', ST)


def stage(name, argv, outputs=(), marker=None, timeout=1800):
    start = time.monotonic()
    with (O / (name + '.log')).open('x') as out:
        child = subprocess.Popen(list(map(str, argv)), cwd=O,
            stdout=out, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
        while child.poll() is None:
            update('RUNNING_' + name.upper(), active_stage=name,
                   child=identity(child.pid), stage_seconds=time.monotonic()-start)
            if time.monotonic()-start > timeout:
                child.terminate()
                try:
                    child.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    child.kill()
                    child.wait()
                break
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
    accepted = child.returncode == 0 and all(Path(p).is_file() for p in outputs)
    if marker:
        accepted = accepted and marker in (O / (name + '.log')).read_text()
    save(O / (name + '-receipt.json'), dict(utc=now(), argv=list(map(str, argv)),
        returncode=child.returncode, accepted=accepted, seconds=time.monotonic()-start,
        log=str(O / (name + '.log')), log_sha256=sha(O / (name + '.log')),
        outputs={str(p):sha(p) for p in outputs if Path(p).is_file()}))
    assert accepted, (name, child.returncode)
    update('COMPLETED_' + name.upper(), child={})


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt original exact owner'
    prior = 'ec-opt4-sprint-composed-validate-r1-20261112.service'
    assert not members(prior), 'Await exact predecessor cgroup release'
    save(O / 'predecessor-release.json', dict(utc=now(), unit=prior, members=[]))
    os.sched_setaffinity(0, {218,219})
    resource.setrlimit(resource.RLIMIT_AS, (32*2**30,)*2)
    binding = read(C / 'source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['hardware_commit']
    for rel,h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git','show',binding['hardware_commit']+':'+rel],cwd=T)).hexdigest()==h
    ST.update(schema='ec-nested-model-extraction-regression/1', **identity(),
        started_utc=now(), functional_baseline=binding['functional_baseline'],
        hardware_commit=binding['hardware_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=[218,219], memory_limit_gib=32, no_CAD=True, fpga_access=False,
        full_system_fit=False, production_admission=False,
        scope='Compiler extraction regression and saved actual production extraction; no host token/area/whole EC equivalence claim.')
    update('ADMITTED_EXACT_COMMITTED_INPUTS')
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    java=[cfg['java'],'-Xmx24G','-Xss32M','-XX:ActiveProcessorCount=2']
    cp=':'.join(cfg['classpath'])
    classes=O/'classes'; classes.mkdir()
    stage('compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',cp,'-d',classes,C/'ExtractModel.scala',C/'StockExtractModel.scala',C/'Regression.scala'],
        [classes/'midas/passes/fame/ExtractModel.class',classes/'nestedmodeltest/Production.class'])
    cp=str(classes)+':'+cp
    stage('nested-scope-regression',java+['-cp',cp,'nestedmodeltest.Regression',O],
        [O/'regression-summary.json',O/'reference.fir',O/'candidate.fir'],
        marker='NESTED_MODEL_EXTRACTION_REGRESSION_PASS')
    for name in ['reference','candidate']:
        stage('emit-'+name,java+['-cp',cp,'nestedmodeltest.EmitVerilog',O/(name+'.fir'),name+'.v',O],
            [O/(name+'.v')])
    ys=O/'sequential-equivalence.ys'
    ys.write_text(f'''read_verilog {O}/reference.v
hierarchy -top FAMETop
proc
flatten
opt_clean
rename FAMETop reference
design -stash reference
read_verilog {O}/candidate.v
hierarchy -top FAMETop
proc
flatten
opt_clean
rename FAMETop candidate
design -stash candidate
design -copy-from reference -as reference reference
design -copy-from candidate -as candidate candidate
equiv_make reference candidate equiv
hierarchy -top equiv
equiv_struct
equiv_simple -seq 2
equiv_induct -seq 4
equiv_status -assert
''')
    stage('sequential-equivalence',['/usr/local/bin/yosys','-Q','-T','-s',ys],
        marker='Equivalence successfully proven!',timeout=600)
    original=D/'build-logs/Opt4-address-banked-production-host-r1-20261112/Threaded'
    stage('actual-production-extraction',java+['-cp',cp,'nestedmodeltest.Production',O,
        original/'post-wrap-sram-models.fir',original/'post-trigger-wiring.json'],
        [O/'production-extracted.fir',O/'production-extracted.anno.json',O/'production-summary.json'],
        marker='ACTUAL_PRODUCTION_NESTED_MODEL_EXTRACTION_PASS',timeout=1800)
    assert all(sha(p)==h for p,h in binding['files'].items())
    update('PASS_NESTED_MODEL_EXTRACTION_SCOPE_AND_SEQUENTIAL_REGRESSION_WITH_ACTUAL_PRODUCTION_EXTRACTION',
        regression=read(O/'regression-summary.json'), actual_production=read(O/'production-summary.json'),
        sequential_equivalence=True, ended_utc=now(),
        next='Adopt compiler regression only. Exact production host tokens/area and material complete caller/DCache/ABI closure remain required before source-bound whole EC build.')
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',ST)
        raise
