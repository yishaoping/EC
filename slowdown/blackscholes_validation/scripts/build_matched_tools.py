#!/usr/bin/env python3
"""Re-Verilate the verified detection RTL with the correction build's tools.

No Scala/RTL regeneration and no writes to the previous build. The existing
Chipyard-generated Verilator command is reused with fresh model/output paths.
"""
import datetime, hashlib, json, os, shlex, shutil, subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/blackscholes_validation'
OLD = OUT / 'build/matched_check'
TARGET = OUT / 'build/matched_check_v5048'
FROZEN = ROOT / 'slowdown/optimization_6_overlap/build/overlap_retained_copy_20261103_040650_0a6ef6bc'
VERILATOR = '/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
CLANG = '/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin'

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p, x): p.write_text(json.dumps(x, indent=2) + '\n')

def main():
    previous = json.loads((OLD / 'build.manifest.json').read_text())
    assert previous['state'] == 'BUILT'
    assert json.loads((OLD / 'configuration_check.json').read_text())['status'] == 'PASS'
    TARGET.mkdir(exist_ok=False)
    for name in ['model', 'verilator', 'tmp']: (TARGET / name).mkdir()
    # Exactly the same memory timing library as frozen correction; archive only.
    shutil.copy2(FROZEN / 'dramsim/libdramsim.a', TARGET / 'libdramsim.a')
    logs = sorted(OLD.glob('default_resume_*.log'))
    original = next(line for line in (logs[-1] if logs else OLD / 'default.log').read_text().splitlines()
                    if line.startswith('verilator --cc --exe'))
    argv = shlex.split(original)
    argv[0] = VERILATOR
    sim = TARGET / 'verilator/simulator-chipyard-v1Config'
    argv[argv.index('-o') + 1] = str(sim)
    argv[argv.index('-Mdir') + 1] = str(TARGET / 'model')
    for i, arg in enumerate(argv):
        if i and argv[i - 1] == '-CFLAGS':
            argv[i] = arg.replace(str(OLD / 'generated/chipyard.TestHarness.v1Config/VTestHarness.h'),
                                  str(TARGET / 'model/VTestHarness.h'))
        if i and argv[i - 1] == '-LDFLAGS':
            argv[i] = arg.replace('-L' + str(OLD / 'source/chipyard/tools/DRAMSim2'), '-L' + str(TARGET))
    argv += ['--no-timing']
    env = dict(previous['environment'])
    env['PATH'] = str(Path(VERILATOR).parent) + ':' + CLANG + ':' + env['PATH']
    env.update(CC=CLANG + '/clang', CXX=CLANG + '/clang++', CCACHE_DISABLE='1',
               TMPDIR='/tmp', TMP='/tmp', TEMP='/tmp')
    commands = [argv, ['/usr/bin/make', '-C', str(TARGET / 'model'), '-f', 'VTestHarness.mk',
                        'VM_PARALLEL_BUILDS=1', 'CXX=' + env['CXX'], 'CC=' + env['CC'],
                        'LINK=' + env['CXX'], '-j16']]
    inputs = {}
    for p in (OLD / 'generated/gen-collateral').iterdir():
        if p.is_file(): inputs[str(p)] = sha(p)
    for p in (OLD / 'generated').glob('*.f'): inputs[str(p)] = sha(p)
    record = dict(state='BUILDING', base_commit=previous['base_commit'],
                  configuration_patch_sha256=previous['configuration_patch_sha256'],
                  parent_manifest_sha256=sha(OLD / 'build.manifest.json'),
                  parent_build=str(OLD), input_sha256=inputs, environment=env,
                  verilator_version=subprocess.check_output([VERILATOR, '--version'], text=True).strip(),
                  compiler_version=subprocess.check_output([env['CXX'], '--version'], text=True).strip(),
                  dramsim_sha256=sha(TARGET / 'libdramsim.a'), commands=[],
                  started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    manifest = TARGET / 'build.manifest.json'
    for phase, command in zip(['verilate', 'compile'], commands):
        wrapped = ['/usr/bin/bwrap', '--die-with-parent', '--new-session', '--unshare-all',
                   '--ro-bind', '/', '/', '--bind', str(TARGET), str(TARGET),
                   '--bind', str(TARGET / 'tmp'), '/tmp', '--dev', '/dev', '--chdir', str(TARGET)]
        for k, v in env.items(): wrapped += ['--setenv', k, v]
        wrapped += ['--', *command]
        record['commands'].append(dict(argv=command, sandbox_argv=wrapped))
        dump(manifest, record)
        print('PHASE=' + phase + ' LOG=' + str(TARGET / (phase + '.log')), flush=True)
        with (TARGET / (phase + '.log')).open('xb') as log:
            rc = subprocess.run(wrapped, env={'PATH': '/usr/bin:/bin'}, stdin=subprocess.DEVNULL,
                                stdout=log, stderr=subprocess.STDOUT).returncode
        if rc:
            record.update(state='FAILED', failed_phase=phase, returncode=rc)
            dump(manifest, record)
            raise RuntimeError('Build failed: ' + phase)
    for p, h in inputs.items(): assert sha(Path(p)) == h, p
    record.update(state='BUILT', simulator=str(sim), simulator_sha256=sha(sim),
                  ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    dump(manifest, record)
    print('BUILT=' + str(sim), flush=True)

if __name__ == '__main__': main()
