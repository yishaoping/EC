"""Isolated software-only build. Never invokes hardware tools or a workload."""
import argparse
import datetime
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import uuid

ROOT = Path('/data1/gzh/EC/baseline')
SOURCE = ROOT / 'software_common'
TOOLCHAIN = Path('/data1/gzh/EC/chipyard/.conda-env/riscv-tools')
SOURCES = ['hw/interrupt.c', 'test.c', 'Benchmark/gapbs/gapbs_bfs.c',
           'stat/report.c', 'core/secondary.c', 'cfg/init.c', 'core/checker.c',
           'hw/spin_lock.c']


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def dump(path, value):
    with Path(path).open('x') as stream:
        json.dump(value, stream, indent=2)
        stream.write('\n')


def tree(directory):
    result = {}
    for path in sorted(directory.rglob('*')):
        if path.is_symlink():
            raise ValueError('Source symlink is not permitted: ' + str(path))
        if path.is_file():
            result[str(path.relative_to(directory))] = sha(path)
    return result


def finalize(output, symbols_text, disassembly):
    elf = output / 'test.riscv'
    data = elf.read_bytes()
    if data[:7] != b'\x7fELF\x02\x01\x01':
        raise ValueError('Expected ELF64 little-endian software')
    header = struct.unpack_from('<16sHHIQQQIHHHHHH', data)
    if header[1] != 2 or header[2] != 243 or header[4] != 0x80000000:
        raise ValueError('Unexpected executable, architecture, or entry')
    symbols = {}
    for line in symbols_text.splitlines():
        fields = line.split()
        if len(fields) >= 8 and fields[0].endswith(':') and fields[0][:-1].isdigit():
            size = int(fields[2], 16) if fields[2].startswith('0x') else int(fields[2])
            symbols.setdefault(fields[7], []).append((int(fields[1], 16), size))

    def symbol(name):
        values = symbols.get(name, [])
        if len(values) != 1:
            raise ValueError('Missing/ambiguous ELF symbol: ' + name)
        return values[0]

    layout = json.loads((output / 'source/layout_contract.json').read_text())
    for name, expected in layout['symbols'].items():
        if list(symbol(name)) != expected:
            raise ValueError('Workload data layout changed: ' + name)
    for name, expected in layout['absolute_symbols'].items():
        if symbol(name)[0] != expected:
            raise ValueError('Stack/heap layout changed: ' + name)
    starts, stops = symbol('common_roi_start')[0], symbol('common_roi_stop')[0]
    instructions = {}
    for line in disassembly.splitlines():
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f]{8}|[0-9a-f]{4})\s', line)
        if match:
            instructions[int(match[1], 16)] = int(match[2], 16)
    for pc in (starts, stops):
        word = instructions.get(pc, 0)
        if (word >> 20 != 0xc00 or (word & 0x7f) != 0x73 or
                ((word >> 12) & 7) != 2 or ((word >> 15) & 31) != 0):
            raise ValueError('ROI symbol is not rdcycle')
    if starts >= stops:
        raise ValueError('ROI order is invalid')
    forbidden = {0x55, 0x77, 0x78, 0x79, 0x7b}
    custom = []
    for pc, word in instructions.items():
        if (word & 0x7f) == 0x2b:
            funct = word >> 25
            if funct in forbidden:
                raise ValueError('Legacy statistics instruction remains: ' + hex(pc))
            if funct == 0x76 and starts <= pc <= stops:
                raise ValueError('Observer control inside hart-0 ROI')
            custom.append({'pc': hex(pc), 'funct': hex(funct)})
    if not custom:
        raise ValueError('No retained checker protocol instructions')
    base, length = layout['loadmem_base'], layout['loadmem_bytes']
    image = bytearray(length)
    segments = []
    occupied = []
    for i in range(header[10]):
        segment = struct.unpack_from('<IIQQQQQQ', data, header[5] + i * header[9])
        kind, flags, offset, va, pa, filesz, memsz, align = segment
        if kind == 3:
            raise ValueError('A dynamic interpreter is not supported')
        if kind != 1 or not memsz:
            continue
        if va != pa or filesz > memsz or offset + filesz > len(data):
            raise ValueError('Unsupported ELF memory mapping')
        if va < base or va + memsz > base + length:
            raise ValueError('ELF exceeds the verified loadmem window')
        if any(va < end and start < va + memsz for start, end in occupied):
            raise ValueError('Overlapping PT_LOAD segments')
        occupied.append((va, va + memsz))
        image[va - base:va - base + filesz] = data[offset:offset + filesz]
        segments.append({'address': hex(va), 'filesz': filesz, 'memsz': memsz})
    if not segments:
        raise ValueError('No ELF loadable segments')
    with (output / 'test.loadmem_hex').open('x') as stream:
        for i in range(0, length, layout['loadmem_line_bytes']):
            stream.write(image[i:i + layout['loadmem_line_bytes']][::-1].hex() + '\n')
    return {'schema': 1, 'hart': 0, 'counter': 'cycle',
            'start_symbol': 'common_roi_start', 'stop_symbol': 'common_roi_stop',
            'start_pc': hex(starts), 'stop_pc': hex(stops),
            'definition': 'stop_cycle - start_cycle',
            'scope': 'amo_w_plus_bfs512_plus_stop_and_session_completion',
            'instruction_sites': custom, 'loadable_segments': segments,
            'layout_verified': True}


def main():
    parser = argparse.ArgumentParser(description='Build ONE shared performance ELF; never runs it')
    parser.add_argument('--output', required=True, help='New absolute directory under baseline/software_common_builds/')
    args = parser.parse_args()
    output = Path(args.output)
    parent = ROOT / 'software_common_builds'
    if (not output.is_absolute() or not output.resolve().is_relative_to(parent.resolve()) or
            output.resolve() == parent.resolve() or output.exists() or output.is_symlink()):
        raise ValueError('Output must be a new directory below baseline/software_common_builds')
    for path in (ROOT, SOURCE, parent, *output.parents):
        if path.is_symlink():
            raise ValueError('Symlink in build path: ' + str(path))
    contract_file = ROOT / 'common_benchmark_contract.py'
    spec = importlib.util.spec_from_file_location('common_contract', contract_file)
    contract = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(contract)
    before = tree(SOURCE)
    tools = {name: TOOLCHAIN / 'bin' / ('riscv64-unknown-elf-' + name)
             for name in ('gcc', 'objdump', 'readelf')}
    for path in tools.values():
        if not path.is_file() or not os.access(path, os.X_OK):
            raise ValueError('Missing recorded tool: ' + str(path))
    if not Path('/usr/bin/bwrap').is_file():
        raise ValueError('Read-only build isolation is unavailable')
    output.mkdir(parents=True, exist_ok=False)
    shutil.copytree(SOURCE, output / 'source', symlinks=False)
    if tree(output / 'source') != before:
        raise ValueError('Source snapshot identity mismatch')
    shutil.copyfile(contract_file, output / 'common_benchmark_contract.py')
    for name in ('tmp', 'home'):
        (output / name).mkdir()
    record = {'schema': 1, 'kind': 'common_software_build', 'state': 'IN_PROGRESS',
              'source_hashes': before, 'contract_sha256': sha(contract_file),
              'tools': {k: {'path': str(v), 'sha256': sha(v)} for k, v in tools.items()},
              'started': datetime.datetime.now(datetime.timezone.utc).isoformat(),
              'commands': [], 'RUN_PROVENANCE': 'UNRESOLVED'}
    dump(output / 'build.started.json', record)

    def invoke(command):
        environment = {'PATH': str(TOOLCHAIN / 'bin') + ':/usr/bin:/bin',
                       'LANG': 'C', 'LC_ALL': 'C', 'HOME': str(output / 'home'),
                       'TMPDIR': str(output / 'tmp'), 'TMP': str(output / 'tmp'),
                       'TEMP': str(output / 'tmp'), 'PYTHONDONTWRITEBYTECODE': '1'}
        wrapped = ['/usr/bin/bwrap', '--die-with-parent', '--new-session', '--unshare-all',
                   '--ro-bind', '/', '/', '--bind', str(output), str(output),
                   '--ro-bind', str(output / 'source'), str(output / 'source'),
                   '--dev', '/dev', '--chdir', str(output)]
        for key, value in environment.items():
            wrapped += ['--setenv', key, value]
        wrapped += ['--', *map(str, command)]
        record['commands'].append({'argv': list(map(str, command)), 'sandbox_argv': wrapped})
        result = subprocess.run(wrapped, stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE, env={'PATH': '/usr/bin:/bin'})
        with (output / 'build.log').open('ab') as log:
            log.write(result.stdout + result.stderr)
        if result.returncode:
            raise ValueError('Tool failed; inspect ' + str(output / 'build.log'))
        return result.stdout.decode('utf-8', errors='strict')

    try:
        record['compiler_version'] = invoke([tools['gcc'], '--version'])
        record['toolchain_inputs'] = {}
        for library in ('libc_nano.a', 'libgcc.a', 'cc1', 'as', 'ld'):
            option = '-print-prog-name=' if library in ('cc1', 'as', 'ld') else '-print-file-name='
            path = Path(invoke([tools['gcc'], option + library]).strip())
            if not path.is_absolute() or not path.is_file():
                raise ValueError('Cannot identify a required toolchain input: ' + library)
            record['toolchain_inputs'][library] = {'path': str(path), 'sha256': sha(path)}
        support = output / 'source/support'
        # The specs file resolves htif.ld in the current working directory.
        shutil.copyfile(support / 'htif.ld', output / 'htif.ld')
        command = [str(tools['gcc']), '-fno-common', '-fno-builtin-printf', '-fdata-sections',
                   '-specs=' + str(support / 'htif_nano.specs'), '-L' + str(support),
                   '-I' + str(support), '-I' + str(output / 'source'),
                   '-march=rv64imafd', '-O2', '-static',
                   '-Wl,-Map=' + str(output / 'test.map')]
        command += [str(output / 'source' / name) for name in SOURCES]
        command += ['-o', str(output / 'test.riscv')]
        invoke(command)
        disassembly = invoke([tools['objdump'], '-d', '-S', output / 'test.riscv'])
        (output / 'test.dump').write_text(disassembly)
        symbols = invoke([tools['readelf'], '-sW', output / 'test.riscv'])
        (output / 'test.symbols').write_text(symbols)
        roi = finalize(output, symbols, disassembly)
        if tree(SOURCE) != before or tree(output / 'source') != before or sha(contract_file) != record['contract_sha256']:
            raise ValueError('Source changed during build')
        record.update({'state': 'BUILT_STATIC_CHECKS_PASSED_NOT_RUN', 'roi': roi,
                       'elf_sha256': sha(output / 'test.riscv'),
                       'loadmem_sha256': sha(output / 'test.loadmem_hex'),
                       'runtime_correctness': 'UNRESOLVED'})
        dump(output / 'build.manifest.json', record)
        descriptor = {'schema': 2, 'name': 'common_amo_w_gapbs_bfs512',
                      'origin_description': 'One common source snapshot; fixed 64-byte per-hart timer slots; no legacy statistics readback dependency',
                      'baseline_compatibility': 'REVIEWED_FOR_BASELINE',
                      'baseline_compatibility_evidence': 'Static shared protocol review: baseline/manifests/common_benchmark_20261023_fa82d07b; NOT_RUNTIME_VALIDATED',
                      'timing_boundary': 'Hart 0 common_roi_start/stop rdcycle; AMO.W + BFS512 + STOP/session completion; not simulator exit/drain',
                      'exit_drain_evidence': 'Finite HTIF _exit; checker software ready only; cache/package/DRAM drain remains UNRESOLVED; exit drain excluded from ROI',
                      'elf': str(output / 'test.riscv'), 'elf_sha256': record['elf_sha256'],
                      'loadmem': str(output / 'test.loadmem_hex'), 'loadmem_sha256': record['loadmem_sha256'],
                      'loadmem_addr': '80000000', 'inputs': [], 'roi': roi,
                      'interval': 'NOT_USED; no funct 0x79',
                      'workload_parameters': {'algorithm': 'AMO.W self-check then GAPBS BFS',
                                              'nodes': 512, 'source': 0, 'degree': 16,
                                              'alpha': 15, 'beta': 18, 'external_inputs': []},
                      'harts': {'boom': [0], 'checkers': [1, 2, 3, 4], 'timers': [0, 1, 2, 3]},
                      'timer': {'stride_bytes': 64, 'limit': 50, 'delta_clint_ticks': 32},
                      'software_build_manifest': str(output / 'build.manifest.json'),
                      'software_build_manifest_sha256': sha(output / 'build.manifest.json'),
                      'required_pass_patterns': contract.PASS_PATTERNS,
                      'failure_patterns': contract.FAILURE_PATTERNS,
                      'RUN_PROVENANCE': 'UNRESOLVED'}
        contract.validate_roi_descriptor(descriptor)
        dump(output / 'workload.json', descriptor)
        print('COMMON_ELF=' + descriptor['elf'] + '\nSHA256=' + descriptor['elf_sha256'] +
              '\nWORKLOAD=' + str(output / 'workload.json') + '\nNO_SIMULATION_EXECUTED')
    except BaseException as exc:
        record.update({'state': 'FAILED', 'error': str(exc)})
        dump(output / 'build.failed.json', record)
        raise


if __name__ == '__main__':
    main()
