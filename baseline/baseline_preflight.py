"""Infrastructure checks only: no project compilation, elaboration or simulation."""
import os
from pathlib import Path
import re
import shutil
import stat
from urllib.parse import unquote, urlparse
from zipfile import BadZipFile, ZipFile


def metadata_copy(launcher, destination, resources=False):
    """Copy definitions and optionally resource data, never hardware Scala."""
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
    if resources:
        audit = launcher.resource_checks()
        links = []
        for _, resource_dir in audit.source_roots(launcher.CHIPYARD).values():
            if not resource_dir.is_dir():
                continue
            for source in sorted(resource_dir.rglob('*')):
                if source.is_symlink():
                    if not source.resolve().is_relative_to(launcher.CHIPYARD.resolve()):
                        launcher.fail('Source resource link escapes historical tree: ' + str(source))
                    links.append({'source': str(source), 'target': os.readlink(source),
                                  'target_exists': source.exists()})
            # Preserve historical relative links, including optional dangling
            # CVA6 collateral. Dereferencing/correcting those would change b3.
            target = project / resource_dir.relative_to(launcher.CHIPYARD)
            shutil.copytree(resource_dir, target, symlinks=True, copy_function=shutil.copy2)
        launcher.record(destination / 'resource_links.json', links)
        audit.apply_restoration(launcher, project)
    return project


def dependency_probe(launcher, destination, environment, env, manifest):
    project = metadata_copy(launcher, destination, resources=True)
    # These are the external-dependency scopes used by historical chipyard and
    # tapeout. `update` resolves libraries; it does not compile project sources.
    modules = ('hardfloat rocketMacros rocketConfig rocketchip testchipip chipyard '
               'mempress constellation fft_generator tracegen icenet hwacha boom '
               'cva6 ibex sodor sha3 gemmini nvdla iocell tapeout dsptools '
               'api-config-chipsalliance rocket-dsp-utils sifive_blocks sifive_cache').split()
    tasks = [p + '/update' for p in modules]
    tasks.append('{file:' + str(project / 'sims/firesim/sim') + '/}targetutils/update')
    # No resource/source generators are defined in these pinned build files.
    # copyResources copies data only; never call compile/packageBin/runMain.
    resource_tasks = [p + '/Compile/copyResources' for p in modules]
    resource_tasks.append('{file:' + str(project / 'sims/firesim/sim') +
                          '/}targetutils/Compile/copyResources')
    command = [env['tools']['java'], '-jar', env['sbt_launch_jar'],
               'show csrCacheDirectory', 'projects', 'all ' + ' '.join(tasks),
               'all ' + ' '.join(resource_tasks), 'exit']
    log = destination / 'sbt_dependencies.log'
    print('PHASE=DEPENDENCY_PREFLIGHT; metadata and libraries only; no hardware compilation', flush=True)
    rc = launcher.invoke(command, project, log, environment, manifest)
    data = log.read_text(errors='replace')
    errors = list(dict.fromkeys(line for line in data.splitlines()
                               if line.startswith('[error]')))
    launcher.record(destination / 'dependency_errors.json', {'return_code': rc, 'errors': errors})
    artifacts, artifact_errors = resolved_artifacts(launcher, project)
    launcher.record(destination / 'resolved_artifacts.json', artifacts)
    copied, resource_errors = copied_resources(launcher, project)
    launcher.record(destination / 'copied_resource_identity.json', copied)
    launcher.record(destination / 'resource_copy_errors.json', resource_errors)
    cache_path = str(launcher.ROOT / 'cache/coursier/v1')
    cache_verified = '[info] ' + cache_path + '\n' in data
    return {'status': 'PASS' if rc == 0 and cache_verified and artifacts and
            not errors and not artifact_errors and not resource_errors else 'FAIL', 'return_code': rc,
            'effective_coursier_cache_verified': cache_verified,
            'resolved_artifact_count': len(artifacts),
            'resolved_artifacts': str(destination / 'resolved_artifacts.json'),
            'artifact_errors': artifact_errors,
            'copied_resource_count': len(copied), 'resource_errors': resource_errors,
            'copied_resources': str(destination / 'copied_resource_identity.json'),
            'resource_check_scope': 'Actual SBT copyResources output identities; hardware JAR packaging/elaboration not executed',
            'log': str(log), 'scope': modules + ['firesim/targetutils'],
            'definition_identity': str(destination / 'sbt_definition_identity.json'),
            'hardware_sources_copied': False, 'hardware_tasks_executed': False,
            'errors': errors}


def copied_resources(launcher, project):
    audit = launcher.resource_checks()
    refs = audit.checked_inventory(launcher)['literal_references']
    result, errors = {}, []
    for ref in refs:
        for provider in ref['providers']:
            module = provider['module']
            base = project / audit.MODULES[module]
            # Follow b3's project base exactly. iocell and tapeout intentionally
            # copy identical resources into two DIFFERENT project outputs.
            prefix = 'src' if module in ('rocketchip', 'iocell', 'dsptools',
                                         'rocket-dsp-utils', 'api-config-chipsalliance') else ''
            target = base / prefix / 'target/scala-2.13/classes' / ref['resource'].lstrip('/')
            key = module + ':' + ref['resource']
            if not target.is_file() or launcher.sha(target) != provider['sha256']:
                errors.append('SBT did not copy the expected resource: ' + key)
            else:
                result[key] = {'path': str(target), 'sha256': launcher.sha(target)}
    return result, list(dict.fromkeys(errors))


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
