"""Infrastructure checks only: no project compilation, elaboration or simulation."""
import os
from pathlib import Path
import re
import shutil
import stat
from urllib.parse import unquote, urlparse
from zipfile import BadZipFile, ZipFile


def metadata_copy(launcher, destination):
    """Copy build definitions, never hardware Scala or generated products."""
    project = destination / 'sbt_metadata'
    project.mkdir()
    identities = {}
    for directory, dirs, files in os.walk(launcher.CHIPYARD):
        dirs[:] = [d for d in dirs if d not in ('.git', 'target', '.bloop', '.metals')]
        for name in files:
            source = Path(directory) / name
            relative = source.relative_to(launcher.CHIPYARD)
            if not (source.suffix == '.sbt' or
                    ('project' in relative.parts and source.suffix in ('.scala', '.properties'))):
                continue
            if source.is_symlink():
                launcher.fail('Unexpected linked SBT definition: ' + str(source))
            target = project / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(source, target)
            identities[str(relative)] = launcher.sha(source)
    launcher.record(destination / 'sbt_definition_identity.json', identities)
    return project


def dependency_probe(launcher, destination, environment, env, manifest):
    project = metadata_copy(launcher, destination)
    # These are the external-dependency scopes used by historical chipyard and
    # tapeout. `update` resolves libraries; it does not compile project sources.
    modules = ('hardfloat rocketMacros rocketConfig rocketchip testchipip chipyard '
               'mempress constellation fft_generator tracegen icenet hwacha boom '
               'cva6 ibex sodor sha3 gemmini nvdla iocell tapeout dsptools '
               'api-config-chipsalliance rocket-dsp-utils sifive_blocks sifive_cache').split()
    tasks = [p + '/update' for p in modules]
    tasks.append('{file:' + str(project / 'sims/firesim/sim') + '/}targetutils/update')
    command = [env['tools']['java'], '-jar', env['sbt_launch_jar'],
               'show csrCacheDirectory', 'projects', 'all ' + ' '.join(tasks), 'exit']
    log = destination / 'sbt_dependencies.log'
    print('PHASE=DEPENDENCY_PREFLIGHT; metadata and libraries only; no hardware compilation', flush=True)
    rc = launcher.invoke(command, project, log, environment, manifest)
    data = log.read_text(errors='replace')
    errors = list(dict.fromkeys(line for line in data.splitlines()
                               if line.startswith('[error]')))
    launcher.record(destination / 'dependency_errors.json', {'return_code': rc, 'errors': errors})
    artifacts, artifact_errors = resolved_artifacts(launcher, project)
    launcher.record(destination / 'resolved_artifacts.json', artifacts)
    cache_path = str(launcher.ROOT / 'cache/coursier/v1')
    cache_verified = '[info] ' + cache_path + '\n' in data
    return {'status': 'PASS' if rc == 0 and cache_verified and artifacts and
            not errors and not artifact_errors else 'FAIL', 'return_code': rc,
            'effective_coursier_cache_verified': cache_verified,
            'resolved_artifact_count': len(artifacts),
            'resolved_artifacts': str(destination / 'resolved_artifacts.json'),
            'artifact_errors': artifact_errors,
            'log': str(log), 'scope': modules + ['firesim/targetutils'],
            'definition_identity': str(destination / 'sbt_definition_identity.json'),
            'hardware_sources_copied': False, 'hardware_tasks_executed': False,
            'errors': errors}


def resolved_artifacts(launcher, project):
    artifacts, errors = {}, []
    for report in project.rglob('output'):
        if '/update/update_cache_' not in str(report):
            continue
        try:
            data = launcher.read_json(report)
            for configuration in data['configurations']:
                for module in configuration['modules']:
                    if module.get('evicted'):
                        continue
                    identity = module['module']
                    label = ':'.join(identity[k] for k in ('organization', 'name', 'revision'))
                    for _, uri in module['artifacts']:
                        parsed = urlparse(uri)
                        if parsed.scheme != 'file' or parsed.netloc:
                            raise ValueError('Nonlocal resolved artifact: ' + uri)
                        path = launcher.inside(Path(unquote(parsed.path)))
                        key = str(path)
                        if key not in artifacts:
                            with ZipFile(path) as archive:
                                corrupt = archive.testzip()
                                if corrupt:
                                    raise ValueError('Corrupt JAR entry: ' + key + ': ' + corrupt)
                            artifacts[key] = {'sha256': launcher.sha(path), 'modules': []}
                        if label not in artifacts[key]['modules']:
                            artifacts[key]['modules'].append(label)
        except (OSError, ValueError, KeyError, RuntimeError, BadZipFile) as error:
            errors.append(str(report) + ': ' + str(error))
    return artifacts, errors


def native_probe(launcher, destination, environment, env, manifest):
    # Header preprocessing and tool inspection do not compile or link anything.
    source = destination / 'native_headers.cc'
    source.write_text('#include <cstdint>\n#include <iostream>\n#include <pthread.h>\n'
                      '#include <zlib.h>\n#include <fesvr/htif.h>\n')
    results = {}
    compilers = {'configured_CXX': environment['CXX'],
                 'DRAMSim_hardcoded_gpp': shutil.which('g++', path=environment['PATH']),
                 'Verilator_Makefile_clangpp': shutil.which('clang++', path=environment['PATH'])}
    for name, executable in compilers.items():
        command = [executable, '-std=c++17', '-E', '-x', 'c++',
                   '-I' + environment['RISCV'] + '/include', str(source), '-o', '/dev/null']
        log = destination / ('native.' + name + '.txt')
        rc = launcher.invoke(command, destination, log, environment, manifest)
        results[name] = {'status': 'PASS' if rc == 0 else 'FAIL', 'log': str(log)}
    commands = {'firtool_help': [env['tools']['firtool'], '--help'],
                'verilator_help': [env['tools']['verilator'], '--help'],
                'fesvr_archive': ['/usr/bin/ar', 't', environment['RISCV'] + '/lib/libfesvr.a'],
                'verilator_historical_options': [env['tools']['verilator'],
                    '--trace-fst', '--trace-threads', '1', '--threads', '1', '--threads-dpi', 'all',
                    '-O3', '--assert', '--x-assign', 'fast', '--x-initial', 'fast',
                    '--output-split', '10000', '--output-split-cfuncs', '100',
                    '--timescale', '1ns/1ps', '--max-num-width', '1048576', '--vpi',
                    '-Wno-fatal', '--version'],
                'zlib_runtime_identity': ['/usr/bin/python3', '-I', '-B', '-c',
                    'import ctypes; z=ctypes.CDLL("' + str(launcher.ROOT / 'cache/native-zlib/lib/libz.so.1') +
                    '"); z.zlibVersion.restype=ctypes.c_char_p; v=z.zlibVersion(); '
                    'print("ZLIB_RUNTIME_VERSION="+v.decode()); assert v==b"1.2.13"']}
    for name, command in commands.items():
        log = destination / ('native.' + name + '.txt')
        rc = launcher.invoke(command, destination, log, environment, manifest)
        results[name] = {'status': 'PASS' if rc == 0 else 'FAIL', 'log': str(log)}
    firtool = (destination / 'native.firtool_help.txt').read_text(errors='replace')
    required = ('--format', '--dedup', '--export-module-hierarchy', '--emit-metadata',
                '--verify-each', '--warn-on-unprocessed-annotations',
                '--disable-annotation-classless', '--disable-annotation-unknown',
                '--mlir-timing', '--lowering-options', '--repl-seq-mem',
                '--repl-seq-mem-file', '--repl-seq-mem-circuit', '--annotation-file',
                '--split-verilog')
    missing = [flag for flag in required if not re.search(re.escape(flag) + r'(?=[=\s<]|$)', firtool)]
    results['firtool_historical_options'] = {'status': 'FAIL' if missing else 'PASS',
                                             'missing': missing}
    modes = {}
    for name in ('split-module-files.py', 'split-bb-files.py', 'split-mems-conf.py'):
        original = launcher.CHIPYARD / 'scripts' / name
        copy = destination / name
        shutil.copy2(original, copy)
        expected = stat.S_IMODE(original.stat().st_mode)
        modes[name] = {'original': expected, 'copy': stat.S_IMODE(copy.stat().st_mode),
                       'sha256_match': launcher.sha(copy) == launcher.sha(original)}
    results['source_copy_executable_modes'] = {
        'status': 'PASS' if all(x['original'] == x['copy'] and x['copy'] & 0o111 and
                                x['sha256_match'] for x in modes.values()) else 'FAIL', 'files': modes}
    launcher.record(destination / 'native_checks.json', results)
    return results
