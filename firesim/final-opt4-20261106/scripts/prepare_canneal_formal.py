#!/usr/bin/env python3
"""Add official Canneal simmedium in a separate profile; reuse the exact ELF."""
import datetime as dt
import json
from pathlib import Path
import re
import shutil
import subprocess
import tarfile

from board_batch import W, D, save, sha


def main():
    receipt = W/'software/canneal-formal-apps-build.json'
    assert not receipt.exists(), 'reuse the existing profile instead of rebuilding it'
    parent = W/'software/formal-apps-build.json'
    apps = json.loads(parent.read_text())
    binary = apps['binaries']['canneal']
    assert sha(binary['path']) == binary['sha256']
    reference = Path(binary['reference_path'])
    assert sha(reference) == binary['reference_sha256']
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = W/'software'/('apps-canneal-formal-'+stamp)
    logs = D/'software'/out.name
    out.mkdir()
    logs.mkdir()
    shutil.copytree(Path(apps['output_dir'])/'inputs/canneal', out/'inputs/canneal')
    dest = out/'inputs/canneal/simmedium'
    dest.mkdir()
    parsec = Path('/data1/gzh/EC/Software/PARSEC')
    archive = parsec/'pkgs/kernels/canneal/inputs/input_simmedium.tar'
    with tarfile.open(archive) as tf:
        for item in tf.getmembers():
            if not item.isfile():
                continue
            p = Path(item.name)
            assert not p.is_absolute() and '..' not in p.parts
            target = dest/p
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(tf.extractfile(item).read())
    conf = parsec/'pkgs/kernels/canneal/parsec/simmedium.runconf'
    argv = re.search(r'^run_args="(.*)"$', conf.read_text(), re.M)[1].replace('${NTHREADS}', '1').split()
    refdir = logs/'reference'
    shutil.copytree(dest, refdir)
    command = ['/usr/bin/time', '-v', '/usr/bin/qemu-riscv64', str(reference), *argv]
    with (refdir/'stdout.log').open('wb') as stdout, (refdir/'resource.log').open('wb') as stderr:
        subprocess.run(command, cwd=refdir, stdout=stdout, stderr=stderr, check=True, timeout=300)
    routing = re.findall(r'^Final routing is: (.+)$', (refdir/'stdout.log').read_text(), re.M)
    assert len(routing) == 1
    cases = [c for c in apps['cases'] if c['program'] == 'canneal']
    cases.append(dict(program='canneal', input='simmedium', argv=argv, runconf=str(conf),
        runconf_sha256=sha(conf), input_archives={str(archive): sha(archive)},
        input_files={str(p.relative_to(dest)): sha(p) for p in dest.rglob('*') if p.is_file()},
        threads=1, warmups=0, fpga_validation='NOT_RUN', software_reference='QEMU_RISCV_USER_ONLY',
        expected_final_routing=routing[0], reference_outputs={str(refdir/'stdout.log'): sha(refdir/'stdout.log')},
        algorithm_unchanged=True))
    apps.update(output_dir=str(out), host_log_dir=str(logs), parent_receipt=str(parent),
        parent_receipt_sha256=sha(parent), binaries={'canneal': binary}, cases=cases,
        status='PREPARED_FPGA_NOT_RUN', software_profile='original-canneal-serial',
        formal_eligible=True, reused_elf=True, no_application_recompile=True,
        formal_input_policy='Official Canneal simmedium: 200000.nets, 15000 swaps, 2000 start temperature, 64 steps; one thread, no warmup, original ROI; FPGA small-input gate required',
        formal_reference_command=command, runtime_memory_reference=str(refdir/'resource.log'))
    save(logs/'result.json', apps)
    save(out/'manifest.json', apps)
    save(receipt, apps)
    print(json.dumps(dict(receipt=str(receipt),reused_elf_sha256=binary['sha256'],expected_final_routing=routing[0])), flush=True)


if __name__ == '__main__':
    main()
