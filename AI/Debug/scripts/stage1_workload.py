#!/usr/bin/env python3
"""Prepare/verify Stage 1 software evidence. Never builds or runs hardware."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

REPO = Path(__file__).resolve().parents[3]


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def sources():
    paths = [p for p in (REPO / 'Software/Test').rglob('*')
             if p.suffix in ('.c', '.h', '.S', '.ld') or p.name == 'compile.sh']
    for rel in ('chipyard/toolchains/libgloss/build/libgloss_htif.a',
                'chipyard/toolchains/libgloss/util/htif_nano.specs',
                'chipyard/toolchains/libgloss/util/htif.ld',
                'chipyard/toolchains/riscv-tools/riscv-pk/machine/encoding.h'):
        paths.append(REPO / rel)
    return {str(p.relative_to(REPO)): sha(p) for p in sorted(paths) if p.is_file()}


def verify(path):
    record = json.loads(Path(path).read_text())
    if record['sources'] != sources():
        raise ValueError('software sources changed; run stage1_prepare_workload.sh first')
    for key in ('benchmark', 'loadmem', 'dump'):
        if sha(record[key]) != record[key + '_sha256']:
            raise ValueError(key + ' changed')
    if record.get('amo_lanes') != [0, 4]:
        raise ValueError('directed AMO.W lanes missing')
    return record


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', required=True)
    parser.add_argument('--capture-source')
    parser.add_argument('--prepare', help='directory containing independently compiled test.riscv/test.dump')
    parser.add_argument('--source-snapshot')
    args = parser.parse_args()
    if args.capture_source:
        Path(args.capture_source).write_text(json.dumps(sources(), indent=2, sort_keys=True) + '\n')
        return
    if not args.prepare:
        verify(args.manifest)
        print('WORKLOAD_IDENTITY=PASS')
        return
    if not args.source_snapshot or json.loads(Path(args.source_snapshot).read_text()) != sources():
        raise ValueError('software changed during compilation')
    directory = Path(args.prepare).resolve()
    elf, dump = directory / 'test.riscv', directory / 'test.dump'
    tool = REPO / 'chipyard/.conda-env/riscv-tools/bin/riscv64-unknown-elf-objdump'
    symbols = subprocess.check_output([str(tool), '-t', str(elf)], text=True)
    names = {}
    exit_range = None
    for line in symbols.splitlines():
        parts = line.split()
        if len(parts) >= 6 and re.fullmatch('[0-9a-fA-F]+', parts[0]):
            name = parts[-1]
            names[name] = int(parts[0], 16)
            if name == '_exit':
                exit_range = [int(parts[0], 16), int(parts[0], 16) + int(parts[-2], 16)]
    addr = names['stage1_amo_words']
    if addr % 64 or addr < 0x80000000:
        raise ValueError('AMO array not aligned/in ordinary DRAM')
    disasm = dump.read_text()
    match = re.search(r'<stage1_amo_w_test>:\n(.*?)(?=\n[0-9a-f]+ <)', disasm, re.S)
    if not match:
        raise ValueError('directed test absent from ELF')
    body = match.group(1)
    # Four volatile asm operations must survive compilation; source fixes offsets 0/4.
    if body.count('amoswap.w.aqrl') != 2 or body.count('amoadd.w.aqrl') != 2:
        raise ValueError('directed AMO instructions absent')
    segments = subprocess.check_output(['readelf', '-lW', str(elf)], text=True)
    ends = []
    for line in segments.splitlines():
        parts = line.split()
        if parts and parts[0] == 'LOAD':
            ends.append(int(parts[3], 16) + int(parts[5], 16))
    length = max(ends) - 0x80000000
    depth = 1 << max(0, ((length + 63) // 64 - 1).bit_length())
    loadmem = directory / 'test.loadmem_hex'
    with loadmem.open('w') as out:
        subprocess.run(['elf2hex', '64', str(depth), str(elf), str(0x80000000)], stdout=out, check=True)
    record = dict(schema=1, sources=sources(), amo_lanes=[0, 4], amo_addresses=[addr, addr+4],
                  exit_pc_range=exit_range, exit_addresses=[names['tohost'], names['fromhost']],
                  loadmem_base=0x80000000, loadmem_width=64, loadmem_depth=depth)
    for key, path in (('benchmark', elf), ('dump', dump), ('loadmem', loadmem)):
        record[key], record[key+'_sha256'] = str(path), sha(path)
    Path(args.manifest).write_text(json.dumps(record, indent=2, sort_keys=True)+'\n')
    print('WORKLOAD_IDENTITY=PASS')
    print('AMO_LOW_ADDRESS=0x%x\nAMO_HIGH_ADDRESS=0x%x' % (addr, addr+4))
    print('WORKLOAD_MANIFEST=' + str(Path(args.manifest).resolve()))


if __name__ == '__main__':
    main()
