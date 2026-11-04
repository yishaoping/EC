#!/usr/bin/env python3
"""Resource limited compile/elaboration only. Never launches a target or touches PCIe."""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path('/data1/gzh/EC')
WORK = ROOT / 'firesim/dac2026/work/opt4-minimal-v2'
ENV = ROOT / 'firesim/envs/manager-1.17.1'

def sha(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for b in iter(lambda: f.read(1024 * 1024), b''):
            h.update(b)
    return h.hexdigest()

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('config', choices=['B', 'C4'])
    p.add_argument('phase', choices=['compile', 'parameters', 'elaborate', 'goldengate', 'driver'])
    p.add_argument('--classpath', type=Path, help='reuse a previously exported classpath from this same tree')
    p.add_argument('--integration', choices=['opt4-minimal-v2','opt4-alveo-v3'], default='opt4-minimal-v2')
    a = p.parse_args()
    cy = WORK.parent / a.integration / a.config / 'chipyard'
    cache = WORK / 'cache'
    target = 'DacBaseline' if a.config == 'B' else 'DacOpt4C4'
    env = os.environ.copy()
    env.pop('FIRESIM_STANDALONE', None)
    env.update({
        'PATH': str(ENV / 'bin') + ':' + env['PATH'],
        'RISCV': str(ENV / 'riscv-tools'),
        'JAVA_HOME': str(ENV / 'lib/jvm'),
        'SBT_BIN': str(ENV / 'bin/java') + ' -jar ' + str(ENV / 'bin/sbt-launch.jar'),
        'SBT_OPTS': '',
        'COURSIER_CACHE': str(cache / 'coursier/v1'),
        'FIRESIM_ENV_SOURCED': '1',
        'JAVA_TOOL_OPTIONS': '-Xmx8G -Xss8M -XX:ActiveProcessorCount=2 -Dsbt.task.cpus=2 '
            '-Dsbt.supershell=false -Dsbt.server.autostart=false -Dsbt.color=false '
            f'-Duser.home={cache}/java-home -Dsbt.boot.directory={cache}/sbt/boot -Dsbt.global.base={cache}/sbt',
        'MAKEFLAGS': '-j1', 'OMP_NUM_THREADS': '2',
    })
    if a.phase == 'compile':
        cwd = cy
        argv = [str(ENV / 'bin/java'), '-jar', str(ENV / 'bin/sbt-launch.jar'), ';project firechip; compile']
    elif a.phase == 'parameters':
        cwd = cy
        output = ROOT / 'Experiment/dac2026/preparation/opt4-minimal-v2' / (a.config + '-parameters.json')
        argv = [str(ENV / 'bin/java'), '-jar', str(ENV / 'bin/sbt-launch.jar'),
                ';project firechip; runMain firesim.firesim.DacParameterAudit firesim.firesim.' + target + ' ' + str(output)]
    elif a.phase == 'elaborate':
        cwd = cy
        output = cy / 'sims/firesim/sim/generated-src/dac' / target
        output.mkdir(parents=True, exist_ok=True)
        argv = [str(ENV / 'bin/java'), '-jar', str(ENV / 'bin/sbt-launch.jar'),
                ';project firechip; runMain chipyard.Generator --target-dir ' + str(output) +
                ' --name firesim.firesim.FireSim --top-module firesim.firesim.FireSim'
                ' --legacy-configs firesim.firesim:' + target]
    elif a.phase == 'goldengate':
        cwd = cy
        generated = cy / 'sims/firesim/sim/generated-src/dac' / target
        argv = [str(ENV / 'bin/java'), '-jar', str(ENV / 'bin/sbt-launch.jar'),
                ';export {file:' + str(cy / 'sims/firesim/sim') + '}firesim / Runtime / fullClasspath']
    else:
        cwd = cy / 'sims/firesim/sim'
        argv = ['make', '-j1', 'DESIGN=FireSim', 'TARGET_CONFIG=' + target,
                'PLATFORM_CONFIG=BaseF1Config', 'PLATFORM=f1',
                'compile' if a.phase == 'goldengate' else 'f1']
    logdir = ROOT / 'Experiment/dac2026/build-logs/opt4-minimal-v2' / (
        a.config + '-' + a.phase + '-' + datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ'))
    logdir.mkdir(parents=True)
    tracked = {}
    for parent in ['generators', 'tools', 'sims/firesim/sim/src', 'sims/firesim/sim/make']:
        for f in (cy / parent).rglob('*'):
            if f.is_file() and f.suffix in {'.scala', '.sbt', '.mk', '.cc', '.h', '.hpp'} and not any(
                    x in {'target', '.git', 'generated-src', 'output'} for x in f.relative_to(cy).parts):
                tracked[str(f.relative_to(cy))] = sha(f)
    identity = hashlib.sha256(json.dumps(tracked, sort_keys=True).encode()).hexdigest()
    (logdir / 'sources.json').write_text(json.dumps(tracked, indent=2) + '\n')
    metadata = {'argv': ['nice', '-n', '15'] + argv, 'cwd': str(cwd), 'phase': a.phase,
                'source_id': identity, 'config': target, 'no_target_execution': True,
                'environment_overrides': {k: env[k] for k in ['PATH', 'RISCV', 'JAVA_HOME', 'SBT_BIN', 'SBT_OPTS', 'COURSIER_CACHE', 'JAVA_TOOL_OPTIONS', 'MAKEFLAGS']},
                'firesim_standalone': 'UNSET', 'platform': 'f1 compile backend; not deployable Alveo evidence'}
    (logdir / 'command.json').write_text(json.dumps(metadata, indent=2) + '\n')
    print(str(logdir), flush=True)
    start = time.time()
    if a.phase == 'goldengate' and a.classpath:
        cp = a.classpath.read_text().strip()
        assert str(cy) in cp and all(Path(x).exists() for x in cp.split(':'))
        (logdir / 'build.log').write_text(cp + '\n')
        result = subprocess.CompletedProcess(argv, 0)
    else:
        with open(logdir / 'build.log', 'xb', buffering=0) as f:
            result = subprocess.run(metadata['argv'], cwd=cwd, env=env, stdout=f, stderr=subprocess.STDOUT)
    if result.returncode == 0 and a.phase == 'goldengate':
        lines = (logdir / 'build.log').read_text().splitlines()
        classpaths = [line for line in lines if line.startswith('/') and
                      all(Path(x).exists() for x in line.split(':'))]
        if not classpaths:
            raise RuntimeError('sbt exported no valid classpath; see ' + str(logdir))
        cp = classpaths[-1]
        (logdir / 'firesim.classpath').write_text(cp + '\n')
        alveo = a.integration == 'opt4-alveo-v3'
        out = generated / (('goldengate-alveo-' if alveo else 'goldengate-f1-') + logdir.name.split('-')[-1])
        out.mkdir(exist_ok=False)
        env['JAVA_TOOL_OPTIONS'] = env['JAVA_TOOL_OPTIONS'].replace('-Xmx8G', '-Xmx16G')
        gg = [str(ENV / 'bin/java'), '-cp', cp, 'midas.stage.GoldenGateMain',
              '-i', str(generated / 'firesim.firesim.FireSim.fir'), '-td', str(out),
              '-faf', str(generated / 'firesim.firesim.FireSim.anno.json'),
              '-ggcp', 'firesim.configs', '-ggcs', 'BaseXilinxAlveoConfig' if alveo else 'BaseF1Config',
              '--output-filename-base', 'FireSim', '--no-dedup']
        (logdir / 'goldengate-command.json').write_text(json.dumps(gg, indent=2) + '\n')
        with open(logdir / 'build.log', 'ab', buffering=0) as f:
            result = subprocess.run(['nice','-n','15'] + gg, cwd=cy, env=env, stdout=f, stderr=subprocess.STDOUT)
    (logdir / 'result.json').write_text(json.dumps({**metadata, 'returncode': result.returncode,
        'wall_seconds': time.time()-start, 'runtime_validation': 'NOT_RUN'}, indent=2) + '\n')
    print('returncode=' + str(result.returncode), flush=True)
    return result.returncode

if __name__ == '__main__':
    sys.exit(main())
