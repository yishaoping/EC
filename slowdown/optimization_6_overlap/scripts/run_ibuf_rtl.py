#!/usr/bin/env python3
"""Emit and test the actual checker IBuf at both supported fetch widths.

Run when no other SBT job is using this private worktree's compiler targets.
"""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import uuid

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/optimization_6_overlap'


def main():
    run = OUT / 'build' / ('ibuf_' + dt.datetime.now().strftime('%Y%m%d_%H%M%S_') + uuid.uuid4().hex[:8])
    run.mkdir(parents=True)
    chip, conda = ROOT / 'chipyard', ROOT / 'chipyard/.conda-env'
    env = os.environ.copy()
    env.update(PATH=str(Path(shutil.which('verilator')).parent) + ':' + str(conda / 'bin') + ':' + env['PATH'],
        JAVA_HOME=str(conda / 'lib/jvm'), RISCV=str(conda / 'riscv-tools'),
        JAVA_TOOL_OPTIONS='-Xmx12G -Xss8M -XX:ActiveProcessorCount=8 -Dsbt.supershell=false',
        SBT_OPTS=f'-Dsbt.ivy.home={chip}/.ivy2 -Dsbt.global.base={chip}/.sbt -Dsbt.boot.directory={chip}/.sbt/boot -Dsbt.color=false')
    emitter, driver = OUT / 'scripts/EmitCheckerIBuf.scala', OUT / 'scripts/ibuf_driver.cpp'
    sbt = [str(conda / 'bin/sbt'), '-java-home', str(conda / 'lib/jvm'),
           f'set chipyard / Compile / unmanagedSources += file("{emitter}")', 'project chipyard']
    sbt += [f'runMain opt4perf.EmitCheckerIBuf {words} {run}/words{words}' for words in (1, 2)]
    with (run / 'emit.log').open('x') as log:
        subprocess.run(sbt, cwd=chip, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
    report = dict(scope='actual emitted IBuf RTL; independent stream scoreboard', tests=[])
    for words in (1, 2):
        obj, verilog = run / f'obj{words}', run / f'words{words}/CheckerIBufWrapper.v'
        obj.mkdir()
        argv = ['verilator', '--cc', '--exe', '--build', '--assert', '-Wno-fatal',
            '--top-module', 'CheckerIBufWrapper', '-Mdir', str(obj), '-CFLAGS',
            f'-DFETCH_HALVES={words * 2} -O2 -std=c++17', str(verilog), str(driver), '-o', 'ibuf_test']
        with (run / f'verilator{words}.log').open('x') as log:
            subprocess.run(argv, cwd=ROOT, env=env, stdout=log, stderr=subprocess.STDOUT, check=True)
        result = subprocess.run([str(obj / 'ibuf_test')], capture_output=True, text=True, check=True)
        report['tests'].append(dict(fetch_words=words, output=result.stdout.strip(),
            verilog_sha256=hashlib.sha256(verilog.read_bytes()).hexdigest(),
            driver_sha256=hashlib.sha256(driver.read_bytes()).hexdigest(),
            emitter_sha256=hashlib.sha256(emitter.read_bytes()).hexdigest()))
        print(result.stdout.strip(), flush=True)
    (run / 'result.json').write_text(json.dumps(report, indent=2, sort_keys=True) + '\n')
    print('RESULT=' + str(run / 'result.json'))


if __name__ == '__main__':
    main()
