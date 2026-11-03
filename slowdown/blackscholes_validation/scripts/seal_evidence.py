#!/usr/bin/env python3
"""Preserve completed validation artifacts, retaining raw compact event streams."""
import argparse, gzip, hashlib, json, shutil
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/blackscholes_validation'

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()

def copy(source, target, compress=False):
    if compress:
        payload = gzip.compress(source.read_bytes(), mtime=0)
        if target.exists(): assert gzip.decompress(target.read_bytes()) == source.read_bytes()
        else: target.write_bytes(payload)
    elif target.exists(): assert sha(source) == sha(target), target
    else: shutil.copy2(source, target)

def main():
    p = argparse.ArgumentParser()
    p.add_argument('runs', type=Path, nargs='+')
    args = p.parse_args()
    evidence = OUT / 'evidence'
    for run in args.runs:
        manifest = json.loads((run / 'run_manifest.json').read_text())
        assert manifest['simulation'] == 'COMPLETED', run
        target = evidence / run.name
        target.mkdir(exist_ok=True)
        for source in run.iterdir():
            if not source.is_file(): continue
            if source.suffix in ['.json', '.log', '.sh', '.patch'] and not source.name.startswith('DRAM'):
                copy(source, target / source.name)
            elif source.name in ['safe_chain_events.tsv', 'cache_opportunity.jsonl', 'hang_ringbuffer.tsv']:
                copy(source, target / (source.name + '.gz'), True)
        print('SEALED=' + str(target))
    software = OUT / 'build/parsec_test4'
    target = evidence / 'software'
    target.mkdir(exist_ok=True)
    for name in ['test.riscv', 'test.loadmem_hex', 'test.dump']:
        copy(software / name, target / (name + '.gz'), True)
    for name in ['core', 'cfg', 'hw', 'stat', 'support']:
        src = software / 'source' / name
        for source in src.rglob('*'):
            if source.is_file():
                dest = target / source.relative_to(software / 'source')
                dest.parent.mkdir(parents=True, exist_ok=True)
                copy(source, dest)
    hashes = {str(x.relative_to(evidence)): sha(x) for x in sorted(evidence.rglob('*'))
              if x.is_file() and x.name != 'SHA256SUMS.json'}
    (evidence / 'SHA256SUMS.json').write_text(json.dumps(hashes, indent=2) + '\n')

if __name__ == '__main__': main()
