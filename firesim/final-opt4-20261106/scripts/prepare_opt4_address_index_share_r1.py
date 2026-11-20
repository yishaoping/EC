#!/usr/bin/python3
"""Record immutable design identity and source hashes for index-share r1."""
from pathlib import Path
import hashlib
import importlib.util
import json
import os
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
F = W / 'Opt4-fit-address-index-share-r1-20261111'
CY = F / 'chipyard'
OUT = D / 'build-logs/Opt4-fit-address-index-share-r1-20261111'
BUILD_HW = W / 'scripts/build_hw.py'
SOURCE_REL = Path('generators/boom/src/main/scala/lsu/PackageAddressStats.scala')


def sha_bytes(data):
    return hashlib.sha256(data).hexdigest()


def sha_file(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def atomic_bytes(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('wb') as stream:
        stream.write(data)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def atomic_json(path, value):
    atomic_bytes(path, (json.dumps(value, indent=2, sort_keys=True) + '\n').encode())


def main():
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    parent = subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip()
    assert commit == '470f1291d01608e80be6cd8d42b29fc5fc28d395'
    assert parent == '8da24a269b98a0d6a8f57b030353a310812c4344'

    spec = importlib.util.spec_from_file_location('opt4_build_hw_inventory', BUILD_HW)
    build_hw = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(CY)
    source_id = sha_bytes(json.dumps(inventory, sort_keys=True).encode())
    patch = subprocess.check_output(['git', 'show', '--format=', '--binary', commit], cwd=F)

    OUT.mkdir(parents=True, exist_ok=True)
    inventory_path = OUT / 'source-inventory.json'
    patch_path = OUT / 'candidate.patch'
    binding_path = OUT / 'candidate-binding.json'
    hashes_path = OUT / 'source-input-hashes.json'
    atomic_json(inventory_path, inventory)
    atomic_bytes(patch_path, patch)
    binding = dict(
        schema='ec-opt4-address-index-share-binding/1',
        hardware_commit=commit,
        parent_commit=parent,
        frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',
        source_id=source_id,
        profile='Opt4-fit-address-index-share-r1-candidate',
        candidate_change='Compute packet-sequence low-index comparisons once per source way and bucket, then share them across all four granules and package load/store reductions.',
        full_dut_formal=False,
        production_selected=False,
        patch_sha256=sha_bytes(patch))
    atomic_json(binding_path, binding)

    source_path = CY / SOURCE_REL
    files = [BUILD_HW, source_path, inventory_path, patch_path, binding_path]
    hashes = {str(path): sha_file(path) for path in files}
    atomic_json(hashes_path, hashes)
    print(json.dumps(dict(status='IDENTITY_READY', hardware_commit=commit,
                          source_id=source_id, source_inputs=len(hashes),
                          evidence_dir=str(OUT)), sort_keys=True))


if __name__ == '__main__':
    main()
