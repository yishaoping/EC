#!/usr/bin/env python3
"""Extend staged Streamcluster to official simmedium, reusing the exact ELF."""
import datetime as dt
import json
from pathlib import Path
import re
import shutil
import subprocess
from board_batch import W,D,save,sha


def main():
    receipt=W/'software/streamcluster-staged-formal-apps-build.json';assert not receipt.exists()
    parent=W/'software/streamcluster-staged-apps-build.json';apps=json.loads(parent.read_text())
    diagnostic=Path(apps['staging_diagnostic_receipt']);evidence=json.loads(diagnostic.read_text())
    elf=Path(evidence['diagnostic_elf']);assert sha(elf)==evidence['diagnostic_sha256']
    binary=apps['binaries']['streamcluster'];assert sha(binary['path'])==binary['sha256']
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-streamcluster-staged-formal-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    shutil.copytree(Path(apps['output_dir'])/'inputs/streamcluster',out/'inputs/streamcluster')
    (out/'inputs/streamcluster/simmedium').mkdir()
    conf=Path('/data1/gzh/EC/Software/PARSEC/pkgs/kernels/streamcluster/parsec/simmedium.runconf')
    argv=re.search(r'^run_args="(.*)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
    reference=logs/'reference-simmedium';reference.mkdir()
    original=Path(binary['reference_path']);assert sha(original)==binary['reference_sha256']
    with (reference/'stdout.log').open('wb') as log:
        subprocess.run(['/usr/bin/qemu-riscv64',str(original),*argv],cwd=reference,stdout=log,stderr=log,check=True,timeout=1800)
    diag=logs/'diagnostic-simmedium';diag.mkdir()
    with (diag/'trace.log').open('wb') as log:
        subprocess.run(['/usr/bin/qemu-riscv64','-strace',str(elf),*argv],cwd=diag,stdout=log,stderr=log,check=True,timeout=1800)
    expected=sha(reference/'output.txt');assert sha(diag/'output.txt')==expected
    rows=(diag/'trace.log').read_text().splitlines();bi=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));ei=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
    calls=[l for l in rows[bi+1:ei] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)];assert not calls,calls
    case=dict(program='streamcluster',input='simmedium',argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={},input_files={},input_generation='original synthetic input; seed1',threads=1,warmups=0,fpga_validation='NOT_RUN',software_reference='QEMU_RISCV_USER_ONLY',reference_outputs={str(reference/'output.txt'):expected},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),algorithm_unchanged=True)
    apps.update(output_dir=str(out),host_log_dir=str(logs),parent_receipt=str(parent),parent_receipt_sha256=sha(parent),binaries={'streamcluster':binary},cases=apps['cases']+[case],
        formal_eligible=True,reused_elf=True,no_application_recompile=True,status='PREPARED_FPGA_NOT_RUN',software_profile='streamcluster-staged-io-synthetic-serial',
        formal_input_policy='Official simmedium:10 20 64 8192 8192 1000 none output.txt1; original generation/clustering/formatting and original ROI hooks, external OS output staged; both groups identical; require matching FPGA simsmall real-check/drain gate',
        formal_reference=dict(reference=str(reference/'output.txt'),sha256=expected,diagnostic_trace=str(diag/'trace.log'),no_synchronous_roi_syscall=True))
    save(out/'manifest.json',apps);save(logs/'result.json',apps);save(receipt,apps);print(json.dumps(dict(receipt=str(receipt),reused_elf_sha256=binary['sha256'],formal_output_sha256=expected,roi_syscalls=calls)),flush=True)


if __name__=='__main__':main()
