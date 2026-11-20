#!/usr/bin/env python3
"""Snapshot the failed R6 build only; never launch CAD or modify source artifacts."""
from pathlib import Path
import hashlib
import json
import shutil
import subprocess
from datetime import datetime, timezone

OUT = Path(__file__).resolve().parents[1]
EXP = OUT.parent
BUILD = EXP / 'build-logs/Opt4-performance-only-support-r6-20261113'
IMPL = BUILD / 'project/builds/cad-6fada307/vivado_proj/firesim.runs/impl_1'
HARDWARE = '6fada307bb77be90b39720d3f95404fece0e431b'

def digest(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()

def main():
    entries = []
    sources = []
    for p in BUILD.iterdir():
        if p.is_file() and p.suffix in ('.rpt', '.log', '.tcl', '.json'):
            sources.append((p, OUT / 'raw/r6' / p.name))
    sources.append((BUILD / 'capacity.complete', OUT / 'raw/r6/capacity.complete'))
    for p in IMPL.iterdir():
        if p.is_file() and p.suffix in ('.rpt', '.tcl', '.rpx'):
            sources.append((p, OUT / 'raw/r6/impl_1' / p.name))
        if p.is_file() and p.suffix == '.dcp':
            sources.append((p, OUT / 'checkpoints' / p.name))
    synth = IMPL.parent / 'synth_1/design_1_wrapper.dcp'
    sources.append((synth, OUT / 'checkpoints/design_1_wrapper_synth.dcp'))
    dut = BUILD / 'project/builds/cad-6fada307/vivado_proj/firesim.gen/sources_1/bd/design_1/ip/design_1_firesim_wrapper_0_0/design_1_firesim_wrapper_0_0.dcp'
    sources.append((dut, OUT / 'checkpoints/firesim_wrapper_DUT_synth.dcp'))
    for name in ('FireSim-generated.implementation.xdc', 'FireSim-generated.synthesis.xdc', 'FireSim-generated.defines.vh', 'bitstream_config.xdc'):
        p = BUILD / 'project/builds/cad-6fada307/design' / name
        if p.exists():
            sources.append((p, OUT / 'raw/r6/constraints' / name))
    for name in ('retained-safety-contract.json', 'complete-shell-postopt-r1.json', 'checker-lsl-source-continuity.json', 'functional-coverage-r1.json'):
        p = EXP / 'performance-only-20261113' / name
        sources.append((p, OUT / 'raw/profile' / name))
    sources.append((EXP / 'matched-parameters.json', OUT / 'raw/context/matched-parameters.json'))
    for src, dst in sources:
        before = src.stat()
        sha = digest(src)
        dst.parent.mkdir(parents=True, exist_ok=True)
        if not dst.exists():
            subprocess.run(['cp', '--reflink=auto', '--preserve=timestamps', '--', str(src), str(dst)], check=True)
        assert digest(dst) == sha, f'Snapshot mismatch: {dst}'
        after = src.stat()
        assert (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns), f'Live source changed: {src}'
        entries.append({'source': str(src), 'saved': str(dst.relative_to(OUT)), 'sha256': sha, 'bytes': before.st_size, 'mtime_ns': before.st_mtime_ns})
    manifest = {'captured_utc': datetime.now(timezone.utc).isoformat(), 'hardware_commit': HARDWARE, 'build': str(BUILD), 'profile': 'EC Performance-Only: data preservation + cache isolation', 'full_PALIMPSEST': False, 'files': entries}
    (OUT / 'evidence').mkdir(exist_ok=True)
    (OUT / 'evidence/source_manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    print(json.dumps({'files': len(entries), 'bytes': sum(e['bytes'] for e in entries), 'manifest': str(OUT / 'evidence/source_manifest.json')}))

if __name__ == '__main__':
    main()
