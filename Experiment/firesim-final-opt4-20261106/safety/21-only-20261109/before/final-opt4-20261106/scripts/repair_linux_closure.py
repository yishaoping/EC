#!/usr/bin/env python3
"""Restore omitted Linux source inputs from the verified same-version archive."""
import hashlib
import json
from pathlib import Path
import sys
import tarfile

WORK = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
DATA = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
CHECKPOINT = Path('/data1/gzh/EC/firesim/dac2026/checkpoints/20261104')
sys.path.insert(0, str(CHECKPOINT))
from restore_sources import assemble


def main():
    archive = Path('/data1/gzh/EC/firesim/dac2026/deps/linux-6.2.tar.xz')
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    assert digest == '74862fa8ab40edae85bb3385c0b71fe103288bce518526d63197800b3cbdecb1'
    manifest = json.loads((CHECKPOINT/'manifests/opt4-linux-v6-linux.json').read_text())
    original = assemble(manifest, {})
    restored = {}
    with tarfile.open(archive, 'r|xz') as tar:
        for member in tar:
            if not (member.isfile() or member.issym()):
                continue
            rel = Path(member.name).relative_to('linux-6.2')
            assert '..' not in rel.parts
            if str(rel) in original:
                continue
            payload = tar.extractfile(member).read() if member.isfile() else member.linkname.encode()
            h = hashlib.sha256(payload).hexdigest()
            for variant in ['C4', 'Native']:
                dest = WORK/'software'/variant/'linux'/rel
                created = not (dest.exists() or dest.is_symlink())
                if created:
                    dest.parent.mkdir(parents=True, exist_ok=True)
                    if member.issym():
                        dest.symlink_to(member.linkname)
                    else:
                        dest.write_bytes(payload)
                        dest.chmod(member.mode)
                actual = dest.read_bytes() if member.isfile() else dest.readlink().as_posix().encode()
                assert actual == payload, str(dest)
                restored.setdefault(variant, {})[str(rel)] = dict(sha256=h, mode=oct(member.mode),
                                                                added_now=created, verified_same_version=True)
    report = dict(schema='ec-linux-source-closure-repair/1', archive=str(archive), archive_sha256=digest,
                  reason='Restore source directories omitted by generic checkpoint target/build/output skip rules. Preserve every checkpoint input.',
                  restored_and_verified=restored)
    path = DATA/'linux-source-closure-repair.json'
    path.write_text(json.dumps(report, indent=2)+'\n')
    profile = WORK/'software/linux-profile.json'
    record = json.loads(profile.read_text())
    record.update(source_closure_repair=str(path), source_closure_repair_sha256=hashlib.sha256(path.read_bytes()).hexdigest())
    profile.write_text(json.dumps(record, indent=2)+'\n')
    print({k:len(v) for k,v in restored.items()}, flush=True)


if __name__ == '__main__':
    main()
