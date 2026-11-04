#!/usr/bin/env python3
"""Verify explicit B ROI compile/pack receipts; never execute a driver or target."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import stat
from build_minimal import inventory, sha
from build_base_linux import snapshot


def require(value, message):
    if not value:
        raise ValueError(message)


def verify_archive(path, files):
    """Parse, never extract/execute, the actual Linux newc payload."""
    raw = path.read_bytes()
    offset = 0
    seen = set()
    leaves = set()
    expected = {n[len('rootfs/'):]: item for n, item in files.items() if n.startswith('rootfs/')}
    while True:
        h = raw[offset:offset+110]
        require(h[:6] == b'070701' and len(h) == 110, 'invalid newc header')
        fields = [int(h[i:i+8], 16) for i in range(6, 110, 8)]
        mode, size, namesize = fields[1], fields[6], fields[11]
        offset += 110
        namebytes = raw[offset:offset+namesize]
        require(namesize > 0 and len(namebytes) == namesize and namebytes[-1] == 0, 'invalid archive name')
        name = namebytes[:-1].decode()
        offset = (offset+namesize+3) & ~3
        data = raw[offset:offset+size]
        require(len(data) == size, 'truncated archive entry')
        offset = (offset+size+3) & ~3
        if name == 'TRAILER!!!':
            require(not any(raw[offset:]), 'unexpected bytes after archive trailer')
            break
        require(name not in seen and not Path(name).is_absolute() and '..' not in Path(name).parts, 'unsafe/duplicate archive entry')
        seen.add(name)
        if stat.S_ISDIR(mode):
            require(not data, 'directory has archive data')
            continue
        require(name in expected, 'unexpected archive leaf '+name)
        item = expected[name]
        if 'link' in item:
            require(stat.S_ISLNK(mode) and data.decode() == item['link'], 'archive symlink mismatch '+name)
        else:
            require(stat.S_ISREG(mode) and hashlib.sha256(data).hexdigest() == item['sha256'], 'archive file mismatch '+name)
        leaves.add(name)
    require(leaves == set(expected), 'missing archive files')
    return len(leaves)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('elaborate', 'goldengate', 'driver', 'boot-pack', 'kernel', 'firmware', 'out'):
        p.add_argument('--'+name, type=Path, required=True)
    a = p.parse_args()
    receipts = {}
    for name in ('elaborate', 'goldengate', 'driver', 'boot_pack', 'kernel', 'firmware'):
        path = getattr(a, name).resolve()
        data = json.loads(path.read_text())
        phase = 'B-boot-pack' if name == 'boot_pack' else name
        require(data.get('phase') == phase and data.get('returncode') == 0, 'not successful '+phase)
        require(data.get('runtime_validation') == 'NOT_RUN', 'this verifier only accepts unexecuted build receipts')
        for f, digest in data.get('outputs', {}).items():
            require(sha(Path(f)) == digest, 'artifact changed '+f)
        for f, digest in data.get('input_files', data.get('inputs', {})).items():
            require(sha(Path(f)) == digest, 'input changed '+f)
        receipts[name] = {'path': str(path), 'sha256': sha(path), 'data': data}
    e, g, d, b, k, f = [receipts[n]['data'] for n in ('elaborate', 'goldengate', 'driver', 'boot_pack', 'kernel', 'firmware')]
    for child, parent in [('goldengate', 'elaborate'), ('driver', 'goldengate')]:
        c, q = receipts[child]['data'], receipts[parent]
        require(Path(c['input_result']).resolve() == Path(q['path']) and
                c['input_result_sha256'] == q['sha256'], 'hardware parent receipt mismatch '+child)
    require(e['source_tree'] == g['source_tree'] == d['source_tree'], 'hardware tree mismatch')
    require(e['source_id'] == g['source_id'] == d['source_id'], 'hardware source identity mismatch')
    require(all(v['config'] == 'DacBaseline' and v['integration'] == 'opt4-roi-v4' and
                v['platform'] == 'xilinx_alveo_u280' for v in (e, g, d)), 'wrong B integration/platform')
    current = hashlib.sha256(json.dumps(inventory(Path(e['source_tree'])), sort_keys=True).encode()).hexdigest()
    require(current == e['source_id'], 'current hardware sources differ')
    current = hashlib.sha256(json.dumps(snapshot(Path(k['source_tree'])), sort_keys=True).encode()).hexdigest()
    require(current == k['source_id'], 'current Linux sources differ')
    for name, receipt in receipts.items():
        script = Path(receipt['path']).parent/'build-script.py'
        expected = receipt['data'].get('build_script_sha256')
        if expected:
            require(sha(script) == expected, 'build script snapshot changed '+name)
    tree = Path(b['output_dir'])
    for relative, item in b['files'].items():
        path = tree/relative
        if 'link' in item:
            require(path.is_symlink() and path.readlink().as_posix() == item['link'], 'archive symlink changed')
        else:
            require(sha(path) == item['sha256'], 'boot pack changed '+relative)
    require(b['inputs'][receipts['elaborate']['path']] == receipts['elaborate']['sha256'], 'boot pack uses another hardware DT')
    require(b.get('roi_candidate') and b.get('static_smoke_software'), 'not the ROI/manual-software pack')
    cpio = tree/'initramfs.cpio'
    dtb = tree/'B-boot.dtb'
    archive_leaves = verify_archive(cpio, b['files'])
    require(k['input_files'][str(cpio)] == sha(cpio), 'kernel embeds another initramfs')
    require(Path(f['kernel_result']).resolve() == Path(receipts['kernel']['path']), 'firmware uses another kernel')
    require(f['input_files'][receipts['kernel']['path']] == receipts['kernel']['sha256'], 'firmware kernel receipt not bound')
    require(f['input_files'][str(dtb)] == sha(dtb), 'firmware embeds another DTB')
    payload = (Path(f['output_dir'])/'platform/generic/firmware/fw_payload.bin').read_bytes()
    image = Path(k['output_dir'])/'arch/riscv/boot/Image'
    require(image.read_bytes() in payload and dtb.read_bytes() in payload, 'Image/DTB bytes absent')
    config = (Path(k['output_dir'])/'.config').read_text()
    require('CONFIG_EC_DAC_ROI=y\n' in config and '# CONFIG_SMP is not set\n' in config, 'kernel driver/CPU configuration mismatch')
    kernel_object = Path(k['output_dir'])/'drivers/misc/ec_dac_roi.o'
    require(sha(kernel_object) == k['content_checks']['roi_driver']['object_sha256'], 'ROI object changed')
    dts = (tree/'B-boot.dts').read_text()
    require(len(re.findall(r'cpu@[0-9a-f]+\s*\{', dts)) == 1 and '"ec,dac-roi-v1"' in dts, 'wrong hardware/device DT')
    fir = (Path(e['output_dir'])/'firesim.firesim.FireSim.fir').read_text()
    require(re.search(r'inst \S+ of DacRoiController\b', fir), 'ROI source controller missing')
    require(not re.search(r'inst \S+ of (RocketTile|Rocket|GHM|GHE|GuardianCouncil)\b', fir), 'unexpected checker hardware in B')
    sv = (Path(g['output_dir'])/'FireSim-generated.sv').read_text()
    require('DacRoiController' in sv, 'controller absent after GoldenGate')
    report = {'configuration': 'B', 'integration': 'opt4-roi-v4', 'compile_and_content_checks_passed': True,
              'receipts': {n: {key: v[key] for key in ('path', 'sha256')} for n, v in receipts.items()},
              'hardware_source_id': e['source_id'], 'linux_source_id': k['source_id'],
              'archive_leaves_verified': archive_leaves,
              'checks': ['same-source target/GoldenGate/native driver', 'no Rocket/checker in B',
                         'ROI platform device from this elaboration', 'builtin B driver linked in UP kernel',
                         'exact archive, static apps and inputs', 'exact Image/DTB embedded in OpenSBI'],
              'target_execution': 'NOT_RUN', 'driver_executed': False, 'runtime_validation': 'NOT_RUN',
              'real_runtime_passed_samples': 0, 'certified_experiment_image': False,
              'host_passive_measurement_bridge': False, 'C4_linux_context_protocol': False,
              'warning': 'Compile/content evidence only. No bitstream, deployment, target event timing or experiment validity is proved.'}
    a.out.parent.mkdir(parents=True, exist_ok=True)
    with a.out.open('x') as output:
        json.dump(report, output, indent=2); output.write('\n')
    print(a.out)


if __name__ == '__main__':
    main()
