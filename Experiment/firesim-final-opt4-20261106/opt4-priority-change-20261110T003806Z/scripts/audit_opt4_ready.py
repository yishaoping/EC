#!/usr/bin/env python3
"""Read actual software artifacts once; record readiness without FPGA access."""
import datetime as dt
import hashlib
import json
from pathlib import Path
import struct

from board_batch import W, D, save
from coverage_first import catalog, results, matches


def main():
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = D / ('opt4-readiness-' + stamp)
    out.mkdir()
    cache = {}

    def sha(path):
        p = Path(path)
        if str(p) not in cache:
            h = hashlib.sha256()
            with p.open('rb') as f:
                for block in iter(lambda: f.read(4 * 1024 * 1024), b''):
                    h.update(block)
            cache[str(p)] = h.hexdigest()
        return cache[str(p)]

    def bound(path, expected):
        assert sha(path) == expected, str(path)

    rows, valid = catalog(), results()
    checked = []
    for row in rows:
        if row['configuration'] != 'C4' or row['program'].startswith('net'):
            continue
        name = row['program']
        item = dict(program=name, profile=row['profile'], receipts=row['receipts'],
                    software_status='NOT_VERIFIED', fpga_validation='NOT_RUN')
        checked.append(item)
        try:
            assert row['status'] == 'READY' and row['formal_eligible']
            a, root, fw, dr = [json.loads(Path(row['receipts'][k]).read_text())
                               for k in ['apps', 'rootfs', 'firmware', 'driver']]
            assert dr['hardware_source_id'] == row['bound']['hardware_source_id']
            assert fw['returncode'] == dr['returncode'] == 0
            binary = a['binaries'][name]
            bound(binary['path'], binary['sha256'])
            with Path(binary['path']).open('rb') as f:
                elf = f.read(64)
            assert elf[:4] == b'\x7fELF' and struct.unpack_from('<H', elf, 18)[0] == 243
            assert root['apps_manifest_sha256'] == sha(row['receipts']['apps'])
            bound(root['path'], root['sha256'])
            payload = str(Path(fw['output_dir']) / 'platform/generic/firmware/fw_payload.elf')
            bound(payload, fw['outputs'][payload])
            driver = str(Path(dr['output_dir']) / 'FireSim-xilinx_alveo_u280')
            bound(driver, dr['outputs'][driver])
            for content in fw['content_checks'].values():
                if isinstance(content, dict) and 'path' in content and 'sha256' in content:
                    bound(content['path'], content['sha256'])
            kp = next(Path(p) for p in fw['input_files'] if p.endswith('.json') and 'kernel' in Path(p).name)
            kernel = json.loads(kp.read_text())
            assert kernel['input_files'][root['path']] == root['sha256']
            for p, digest in fw['input_files'].items():
                bound(p, digest)
            cases = [c for c in a['cases'] if c['program'] == name]
            assert any(c['input'] == 'simmedium' for c in cases)
            for case in cases:
                assert case['threads'] == 1 and case['warmups'] == 0
                bound(case['runconf'], case['runconf_sha256'])
                for p, digest in case.get('input_archives', {}).items():
                    bound(p, digest)
                for p, digest in case.get('input_files', {}).items():
                    bound(Path(a['output_dir']) / 'inputs' / name / case['input'] / p, digest)
                for p, digest in case.get('reference_outputs', {}).items():
                    ref = Path(p)
                    if not ref.is_absolute():
                        # Stable Fluidanimate records guest output names; its
                        # adoption receipt binds the host reference directory.
                        assert case.get('software_reference') == 'STABLE_PAIR_ORDER_RISCV_REFERENCE'
                        ref = Path(a['host_log_dir']) / ('reference-' + case['input']) / ref
                    bound(ref, digest)
            n = next(r for r in rows if r['configuration'] == 'Native' and r['program'] == name)
            paired = [matches(n, valid, 'simmedium', rep) for rep in (1, 2, 3)]
            assert all(paired), 'Native current-profile formal repetitions missing'
            assert n['bound']['elf_sha256'] == row['bound']['elf_sha256']
            assert n['bound']['rootfs_sha256'] == row['bound']['rootfs_sha256']
            for _, r in [pairs[0] for pairs in paired]:
                assert r['identity']['case'] == next(c for c in cases if c['input'] == 'simmedium')
                assert r['identity']['linux_bootargs'] == row['bound']['linux_bootargs']
                assert r['identity']['linux_memory_cap_bytes'] == row['bound']['linux_memory_cap_bytes']
            item.update(software_status='READY_HASH_VERIFIED_FPGA_PENDING',
                        native_formal_repetitions=[1, 2, 3], elf_sha256=binary['sha256'],
                        firmware_sha256=sha(payload), rootfs_sha256=root['sha256'],
                        bound=row['bound'], inputs=[c['input'] for c in cases],
                        cases=cases, native_results=[str(pairs[0][0]) for pairs in paired])
        except Exception as exc:
            item.update(software_status='BLOCKED_AUDIT', reason=str(exc))
    cad = json.loads((D / 'C4-runtime-cad-state.json').read_text())
    for p, digest in {**cad['inputs'], **cad['effective_cad_inputs']}.items():
        bound(p, digest)
    result = dict(schema='ec-opt4-readiness-audit/1', observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                  hardware_commit=cad['hardware_commit'], source_id=cad['source_id'],
                  fpga_access=False, cad_inputs_verified=True, artifacts_verified=cache,
                  ready=sum(r['software_status'] == 'READY_HASH_VERIFIED_FPGA_PENDING' for r in checked),
                  programs=checked, formal_fpga_results_created=0,
                  remaining_global_gates=['Final bitstream generation and certification',
                      '21-only deployment at a safe sample boundary',
                      'C4 smoke and per-program correctness, true checker matching and drain'])
    save(out / 'result.json', result)
    save(D / 'opt4-readiness-latest.json', result)
    print(json.dumps(dict(ready=result['ready'], total=len(checked), evidence=str(out / 'result.json'),
                          blocked=[dict(program=r['program'], reason=r['reason']) for r in checked if 'reason' in r])))


if __name__ == '__main__':
    main()
