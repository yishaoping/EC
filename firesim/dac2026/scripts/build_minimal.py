#!/usr/bin/env python3
"""Compile only: isolated Chipyard integration, immutable logs, no target/device execution."""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time

ROOT = Path('/data1/gzh/EC')
BASE = ROOT / 'firesim/dac2026/work'
ENV = ROOT / 'firesim/envs/manager-1.17.1'
SKIP = {'.git', 'target', 'generated-src', 'output', 'build', 'builds', '.bloop', '.metals', '__pycache__'}
EXT = {'.scala', '.sbt', '.mk', '.cc', '.cpp', '.c', '.h', '.hpp', '.v', '.sv', '.img', '.json', '.conf', '.properties'}

def sha(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for b in iter(lambda: f.read(1024 * 1024), b''):
            h.update(b)
    return h.hexdigest()

def write(path, data):
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + '\n')

def inventory(cy):
    files = {}
    for root in ['generators', 'tools', 'sims/firesim/sim', 'project']:
        for current, dirs, names in os.walk(cy / root):
            dirs[:] = [d for d in dirs if d not in SKIP]
            for name in names:
                path = Path(current) / name
                if path.suffix in EXT or name in {'Makefile', 'build.sc'}:
                    files[str(path.relative_to(cy))] = (
                        {'symlink': os.readlink(path), 'target_sha256': sha(path) if path.is_file() else None}
                        if path.is_symlink() else sha(path))
    files['build.sbt'] = sha(cy / 'build.sbt')
    return files

def resource_check():
    memory = {l.split(':')[0]: int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    free_mem = memory['MemAvailable'] / 1024**2
    free_disk = shutil.disk_usage(BASE).free / 1024**3
    load = os.getloadavg()[0]
    cpus = os.cpu_count()
    state = dict(available_memory_gib=free_mem, free_disk_gib=free_disk, load_1min=load, host_cpus=cpus,
                 jobs=2, make_jobs=1, niceness=15)
    if free_mem < 32 or free_disk < 40 or load > cpus * .9:
        raise RuntimeError('compile resource guard refused: ' + json.dumps(state))
    return state

def run(argv, cwd, env, log, commands):
    command = dict(argv=['nice', '-n', '15'] + argv, cwd=str(cwd),
                   java_tool_options=env['JAVA_TOOL_OPTIONS'])
    commands.append(command)
    write(log.parent / 'commands.json', commands)
    with open(log, 'ab', buffering=0) as stream:
        return subprocess.run(command['argv'], cwd=cwd, env=env, stdout=stream, stderr=subprocess.STDOUT).returncode

def main():
    script_content = Path(__file__).read_bytes()
    script_hash = hashlib.sha256(script_content).hexdigest()
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('config', choices=['B', 'C4'])
    p.add_argument('phase', choices=['compile', 'parameters', 'elaborate', 'goldengate', 'driver'])
    p.add_argument('--integration', choices=['opt4-minimal-v2', 'opt4-alveo-v3', 'opt4-roi-v4', 'opt4-roi-v5'], default='opt4-alveo-v3')
    p.add_argument('--input-result', type=Path, help='successful elaboration result for GoldenGate; successful GoldenGate result for driver')
    p.add_argument('--wait-lock', action='store_true', help='queue behind an existing DAC compile; does not execute a target')
    a = p.parse_args()
    cy = BASE / a.integration / a.config / 'chipyard'
    if not (cy / 'build.sbt').is_file():
        p.error('missing isolated tree: ' + str(cy))
    cache = BASE / 'opt4-minimal-v2/cache'
    # One compile at a time across both configurations/integrations.
    lock = open(BASE / '.dac-compile.lock', 'a')
    try:
        if a.wait_lock:
            print('waiting for DAC compile resource lock', flush=True)
        fcntl.flock(lock, fcntl.LOCK_EX | (0 if a.wait_lock else fcntl.LOCK_NB))
    except BlockingIOError:
        p.error('another DAC compilation holds the shared resource lock')
    resources = resource_check()
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    name = a.config + '-' + a.phase + '-' + stamp
    logdir = ROOT / 'Experiment/dac2026/build-logs' / a.integration / name
    logdir.mkdir(parents=True, exist_ok=False)
    (logdir / 'build-script.py').write_bytes(script_content)
    out = BASE / a.integration / 'builds' / name
    out.mkdir(parents=True, exist_ok=False)
    files = inventory(cy)
    source_id = hashlib.sha256(json.dumps(files, sort_keys=True).encode()).hexdigest()
    write(logdir / 'sources.json', files)
    target = 'DacBaseline' if a.config == 'B' else 'DacOpt4C4'
    alveo = a.integration in {'opt4-alveo-v3', 'opt4-roi-v4', 'opt4-roi-v5'}
    platform = 'xilinx_alveo_u280' if alveo else 'f1'
    platform_config = 'BaseXilinxAlveoConfig' if alveo else 'BaseF1Config'
    git_id = subprocess.check_output(['git', '-C', str(cy / 'sims/firesim'), 'rev-parse', 'HEAD'], text=True).strip()
    env = os.environ.copy()
    for key in ['FIRESIM_STANDALONE', 'CLASSPATH', 'LD_LIBRARY_PATH', 'CHIPYARD_DIR', 'FIRESIM_DIR', 'JAVA_OPTS', '_JAVA_OPTIONS']:
        env.pop(key, None)
    env.update({
        'PATH': ':'.join(map(str, [ENV / 'bin', ENV / 'riscv-tools/bin'])) + ':/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin',
        'CONDA_PREFIX': str(ENV), 'RISCV': str(ENV / 'riscv-tools'), 'JAVA_HOME': str(ENV / 'lib/jvm'),
        'SBT_BIN': str(ENV / 'bin/java') + ' -jar ' + str(ENV / 'bin/sbt-launch.jar'), 'SBT_OPTS': '',
        'COURSIER_CACHE': str(cache / 'coursier/v1'), 'FIRESIM_ENV_SOURCED': '1',
        'JAVA_TOOL_OPTIONS': '-Xmx8G -Xss8M -XX:ActiveProcessorCount=2 -Dsbt.task.cpus=2 '
            '-Dsbt.supershell=false -Dsbt.server.autostart=false -Dsbt.color=false '
            '-Dec.dac.firesim=true '
            f'-Duser.home={cache}/java-home -Dsbt.boot.directory={cache}/sbt/boot -Dsbt.global.base={cache}/sbt',
        'MAKEFLAGS': '-j1', 'OMP_NUM_THREADS': '2',
        # Native Alveo links the host's /usr/lib libraries. Use matching host
        # crt/libc, not Conda's older sysroot (which needs __libc_csu_init).
        'CC': '/usr/bin/gcc', 'CXX': '/usr/bin/g++',
    })
    metadata = dict(integration=a.integration, source_tree=str(cy), source_id=source_id, config=target,
                    phase=a.phase, platform=platform, platform_config=platform_config, firesim_commit=git_id,
                    no_target_execution=True, runtime_validation='NOT_RUN', build_script_sha256=script_hash,
                    output_dir=str(out), resources=resources,
                    environment_overrides={k: env[k] for k in ['PATH', 'RISCV', 'CONDA_PREFIX', 'JAVA_HOME', 'SBT_BIN', 'COURSIER_CACHE', 'JAVA_TOOL_OPTIONS', 'MAKEFLAGS', 'CC', 'CXX']},
                    tool_hashes={str(f): sha(f) for f in [ENV / 'bin/java', ENV / 'bin/sbt-launch.jar',
                        Path(env['CC']), Path(env['CXX'])]},
                    firesim_standalone='UNSET', legacy_input_only_loggers='disabled by ec.dac.firesim=true in v3 C4')
    write(logdir / 'command.json', metadata)
    print(str(logdir), flush=True)
    commands = []
    start = time.monotonic()
    result = 1
    error = None
    java = [str(ENV / 'bin/java')]
    sbt = java + ['-jar', str(ENV / 'bin/sbt-launch.jar')]
    try:
        previous = None
        if a.phase in {'goldengate', 'driver'}:
            if not a.input_result:
                raise RuntimeError('--input-result is required; no implicit reuse of stale build artifacts')
            previous = json.loads(a.input_result.read_text())
            expected_phase = 'elaborate' if a.phase == 'goldengate' else 'goldengate'
            for key, value in dict(source_id=source_id, source_tree=str(cy), config=target,
                                   integration=a.integration, phase=expected_phase, returncode=0).items():
                if previous.get(key) != value:
                    raise RuntimeError('input result mismatch in ' + key)
            for file, digest in previous['outputs'].items():
                if not Path(file).is_file() or sha(file) != digest:
                    raise RuntimeError('input artifact modified or missing: ' + file)
            metadata['input_result'] = str(a.input_result.resolve())
            metadata['input_result_sha256'] = sha(a.input_result)
        log = logdir / 'build.log'
        if a.phase == 'compile':
            result = run(sbt + [';project firechip; compile'], cy, env, log, commands)
        elif a.phase == 'parameters':
            result = run(sbt + [';project firechip; runMain firesim.firesim.DacParameterAudit firesim.firesim.' + target + ' ' + str(out / 'parameters.json')], cy, env, log, commands)
        elif a.phase == 'elaborate':
            result = run(sbt + [';project firechip; runMain chipyard.Generator --target-dir ' + str(out) +
                ' --name firesim.firesim.FireSim --top-module firesim.firesim.FireSim --legacy-configs firesim.firesim:' + target], cy, env, log, commands)
        elif a.phase == 'goldengate':
            result = run(sbt + [';export {file:' + str(cy / 'sims/firesim/sim') + '}firesim / Runtime / fullClasspath'], cy, env, log, commands)
            if result == 0:
                cps = [l for l in log.read_text().splitlines() if l.startswith('/') and all(Path(x).exists() for x in l.split(':'))]
                if not cps:
                    raise RuntimeError('sbt exported no valid classpath')
                cp = cps[-1]
                (logdir / 'firesim.classpath').write_text(cp + '\n')
                src = Path(previous['output_dir'])
                env['JAVA_TOOL_OPTIONS'] = env['JAVA_TOOL_OPTIONS'].replace('-Xmx8G', '-Xmx16G')
                result = run(java + ['-cp', cp, 'midas.stage.GoldenGateMain',
                    '-i', str(src / 'firesim.firesim.FireSim.fir'), '-td', str(out),
                    '-faf', str(src / 'firesim.firesim.FireSim.anno.json'),
                    '-ggcp', 'firesim.configs', '-ggcs', platform_config,
                    '--output-filename-base', 'FireSim-generated', '--no-dedup'], cy, env, log, commands)
                # Match FireSim make/goldengate.mk: append supplied blackboxes.
                if result == 0:
                    listing = out / 'firrtl_black_box_resource_files.f'
                    if listing.exists():
                        with open(out / 'FireSim-generated.sv', 'ab') as sv:
                            for f in listing.read_text().splitlines():
                                if f.strip():
                                    sv.write(Path(f.strip()).read_bytes())
                                    sv.write(b'\n')
        else:
            src = Path(previous['output_dir'])
            elab_result = json.loads(Path(previous['input_result']).read_text())
            elab = Path(elab_result['output_dir'])
            env['CXXFLAGS'] = '-I' + str(out)
            metadata['driver_cxxflags_environment'] = env['CXXFLAGS']
            # Compile just the native driver against this exact generated header.
            # Skip Scala/RTL make dependencies; those were verified above.
            result = run(['make', '-j1', 'driver', 'DESIGN=FireSim', 'TARGET_CONFIG=' + target,
                'PLATFORM=' + platform, 'PLATFORM_CONFIG_PACKAGE=firesim.configs', 'PLATFORM_CONFIG=' + platform_config,
                'GENERATED_DIR=' + str(src), 'OUTPUT_DIR=' + str(out),
                'DROMAJO_LONG_H=' + str(elab / 'firesim.firesim.FireSim.dromajo_params.h'),
                'DTS_FILE=' + str(elab / 'firesim.firesim.FireSim.dts'),
                'DROMAJO_DTB=' + str(out / 'target.dtb'), 'DROMAJO_ROM=' + str(out / 'target.rom'),
                'DROMAJO_H=' + str(out / 'dromajo_params.h'),
                'FIRESIM_MAIN_CP=/dev/null', 'TARGET_CP=/dev/null',
                '-o', str(src / 'FireSim-generated.const.h'), '-o', str(src / 'FireSim-generated.sv'),
                '-o', str(elab / 'firesim.firesim.FireSim.dromajo_params.h'),
                '-o', str(elab / 'firesim.firesim.FireSim.dts')], cy / 'sims/firesim/sim', env, log, commands)
        if result == 0 and inventory(cy) != files:
            raise RuntimeError('sources changed during compilation; artifacts not accepted')
    except Exception as exc:
        result, error = 1, repr(exc)
        print(error, file=sys.stderr, flush=True)
    outputs = {str(f): sha(f) for f in sorted(out.rglob('*')) if f.is_file()}
    if result == 0:
        expected = {'parameters': [out / 'parameters.json'], 'elaborate': [out / 'firesim.firesim.FireSim.fir', out / 'firesim.firesim.FireSim.anno.json'],
                    'goldengate': [out / 'FireSim-generated.sv', out / 'FireSim-generated.const.h'], 'driver': [out / ('FireSim-' + platform)]}.get(a.phase, [])
        if any(not f.is_file() or f.stat().st_size == 0 for f in expected):
            result, error = 1, 'compiler returned zero but expected output absent or empty'
    write(logdir / 'result.json', dict(metadata, commands=commands, returncode=result, error=error,
                                       wall_seconds=time.monotonic()-start, outputs=outputs))
    print('returncode=' + str(result), flush=True)
    return result

if __name__ == '__main__':
    sys.exit(main())
