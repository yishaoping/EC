#!/usr/bin/env python3
"""Append-only raw evidence export; identical reexports are checked, not replaced."""
import gzip,hashlib,io,json,shutil,tarfile
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def copyonce(src,dst,compress=False):
    dst.parent.mkdir(parents=True,exist_ok=True);b=src.read_bytes()
    if dst.exists():
        old=gzip.decompress(dst.read_bytes())if compress else dst.read_bytes()
        assert old==b,'Attempt to overwrite sealed evidence: '+str(dst);return
    if compress:b=gzip.compress(b,compresslevel=9,mtime=0)
    with dst.open('xb')as f:f.write(b)
def main():
    entries=[]
    for run in sorted((OUT/'runs').iterdir()):
        p=run/'run_manifest.json'
        if not p.exists():continue
        m=json.loads(p.read_text())
        if m['state']!='COMPLETED':continue
        dest=OUT/'raw'/run.name;dest.mkdir(parents=True,exist_ok=True)
        for src in sorted(run.iterdir()):
            if not src.is_file()or src.name in ['test.riscv','test.loadmem_hex']:continue
            compress=src.suffix in ['.tsv','.jsonl','.log'];q=dest/(src.name+('.gz'if compress else''));copyonce(src,q,compress)
            entries.append({'source':str(src.relative_to(OUT)),'raw_file':str(q.relative_to(OUT)),'source_sha256':sha(src),'raw_sha256':sha(q),'source_bytes':src.stat().st_size})
        # A single sealed ELF per actual hash; modes do not share a hash.
        elf=run/'test.riscv';copyonce(elf,OUT/'raw/elf'/(sha(elf)+'.riscv.gz'),True)
    for d in sorted((OUT/'build').iterdir()):
        p=d/'build.manifest.json'
        if not p.exists():continue
        dest=OUT/'raw/software'/d.name;dest.mkdir(parents=True,exist_ok=True)
        for name in ['build.manifest.json','build.log','htif.ld','symbols.txt','host_reference.json','host_build.log']:
            src=d/name
            if src.exists():copyonce(src,dest/name)
        source=d/'source';archive=dest/'source.tar.gz'
        if source.exists()and not archive.exists():
            with archive.open('xb')as f:
                with gzip.GzipFile(fileobj=f,mode='wb',mtime=0)as gz:
                    with tarfile.open(fileobj=gz,mode='w')as t:
                        for src in sorted(source.rglob('*')):
                            if not src.is_file():continue
                            info=tarfile.TarInfo(str(src.relative_to(source)));b=src.read_bytes();info.size=len(b);info.mode=0o644;t.addfile(info,io.BytesIO(b))
    # This generated index may grow; individual raw files are immutable.
    (OUT/'raw/INDEX.json').write_text(json.dumps(entries,indent=2)+'\n')
    print('Sealed completed runs:',len({e['source'].split('/')[1]for e in entries}))
if __name__=='__main__':main()
