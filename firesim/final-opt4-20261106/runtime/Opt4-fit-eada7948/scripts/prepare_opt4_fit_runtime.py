import sys
from pathlib import Path as _BundlePath
sys.path.insert(0, str(_BundlePath(__file__).resolve().parent))
sys.path.insert(1, '/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""Prepare separate derived software identities; certify artifacts without FPGA IO.

Never rewrites frozen C4 admission, deployment, scheduler or running samples.
"""
import argparse
import datetime as dt
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

from board_batch import W,D,save,sha
import coverage_first as coverage

COMMIT='eada7948b15146fd33bbc91aad7bac4ab9ec44b7'
F=W/'Opt4-fit-address-update-share-r1-20261111'
PROFILE='Opt4-fit-C4-SVB32-update-share-20261111'
O=W/'runtime'/('Opt4-fit-'+COMMIT[:8])
REPORT=D/'build-logs'/('Opt4-fit-runtime-'+COMMIT[:8])
now=lambda:dt.datetime.now(dt.timezone.utc).isoformat()
read=lambda p:json.loads(Path(p).read_text())


def prepare():
    O.mkdir(exist_ok=True);REPORT.mkdir(exist_ok=True)
    b=read(F/'bindings'/f'{COMMIT}.json')
    compat_path=W/'runtime/Opt4-fit-eada7948/driver-compatibility.json'
    compat=read(compat_path)
    assert compat['hardware_commit']==COMMIT and compat['hardware_source_id']==b['source_id']
    assert len(compat['generated_abi_and_target_description'])==7
    for c in compat['generated_abi_and_target_description']:
        assert c['byte_equal'] and sha(c['original'])==sha(c['derived'])==c['sha256']
    parent_path=Path(compat['parent_receipt']);parent=read(parent_path)
    assert sha(parent_path)==compat['parent_receipt_sha256']
    assert parent['returncode']==0
    exe=O/'FireSim-xilinx_alveo_u280'
    assert sha(exe)==compat['outputs'][str(exe)]
    driver=dict(parent,schema='ec-derived-compatible-driver/1',configuration='C4',
        profile=PROFILE,hardware_commit=COMMIT,hardware_source_id=b['source_id'],
        source_id=b['source_id'],output_dir=str(O),outputs={str(exe):sha(exe)},
        parent_receipt=str(parent_path),parent_receipt_sha256=sha(parent_path),
        compatibility_receipt=str(compat_path),compatibility_receipt_sha256=sha(compat_path),
        frozen_parent_commit=b['frozen_commit'],hardware_rtl_unchanged=False,
        host_code_reused=True,recompiled=False,fpga_runtime_validated=False,
        status='COMPATIBLE_REUSED_NOT_FPGA_VALIDATED')
    driver_path=O/'driver-receipt.json';save(driver_path,driver)
    rows=coverage.catalog();valid=coverage.results();suite=[]
    for row in rows:
        if row['configuration']!='C4' or row['program'].startswith('net'):continue
        assert row['status']=='READY' and row['formal_eligible'],row['program']
        native=next(r for r in rows if r['configuration']=='Native' and r['program']==row['program'])
        paths={k:Path(v) for k,v in row['receipts'].items()}
        apps,rootfs,fw=(read(paths[k]) for k in ['apps','rootfs','firmware'])
        assert apps['binaries'][row['program']]['sha256']==native['bound']['elf_sha256']
        assert sha(apps['binaries'][row['program']]['path'])==native['bound']['elf_sha256']
        assert rootfs['sha256']==native['bound']['rootfs_sha256']
        for k in ['linux_memory_cap_bytes','linux_bootargs']:
            assert row['bound'][k]==native['bound'][k],(row['program'],k)
        assert sha(rootfs['path'])==rootfs['sha256']
        assert rootfs['apps_manifest_sha256']==sha(paths['apps'])
        assert fw['returncode']==0 and not fw.get('diagnostic_only')
        fwelf=Path(fw['output_dir'])/'platform/generic/firmware/fw_payload.elf'
        assert sha(fwelf)==fw['outputs'][str(fwelf)]
        kernel_path=next(Path(p) for p in fw['input_files'] if p.endswith('.json') and 'kernel' in Path(p).name)
        assert read(kernel_path)['input_files'][rootfs['path']]==rootfs['sha256']
        nrefs=[]
        for rep in [1,2,3]:
            matched=coverage.matches(native,valid,'simmedium',rep)
            assert matched,(row['program'],'missing exact valid Native repetition',rep)
            p,r=matched[0]
            nrefs.append(dict(repetition=rep,result=str(p),result_sha256=sha(p),
                identity_sha256=r['identity_sha256'],roi_cycles=r['roi_cycles']))
        suite.append(dict(program=row['program'],software_profile=row['profile'],
            input_sizes=row['inputs'],threads=1,warmups=0,formal_input='simmedium',
            receipts={**row['receipts'],'driver':str(driver_path)},
            receipt_sha256={k:sha(p) for k,p in {**paths,'driver':driver_path}.items()},
            elf_sha256=native['bound']['elf_sha256'],rootfs_sha256=rootfs['sha256'],
            native_references=nrefs,status='SOFTWARE_PREPARED_REQUIRES_DERIVED_FPGA_VALIDATION'))
    assert len(suite)==13
    result=dict(schema='ec-opt4-fit-runtime-preparation/1',utc=now(),profile=PROFILE,
        hardware_commit=COMMIT,source_id=b['source_id'],frozen_parent_commit=b['frozen_commit'],
        driver_receipt=str(driver_path),programs=suite,program_count=len(suite),
        board_bdf='0000:21:00.0',board_serial='21770433G02LA',
        order='smoke; per-program test/simsmall as present; formal r1 coverage before r2/r3',
        fpga_access=False,formal_admission=False,automatic_runtime_handoff_installed=False,
        canonical_frozen_receipts_changed=False,live_services_changed=False,
        status='13_PROGRAMS_SOFTWARE_PREPARED_NOT_RUNTIME_ADMITTED')
    save(O/'software-suite.json',result);save(REPORT/'software-preparation.json',result)
    return result


def certify():
    s=read(D/'Opt4-fit-update-share-cad-state.json')
    if s.get('status')!='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED':
        return dict(status='WAITING_FOR_REAL_TIMING_DRC_BITSTREAM',cad_status=s.get('status'),fpga_access=False)
    b=read(F/'bindings'/f'{COMMIT}.json')
    assert s['hardware_commit']==COMMIT and s['source_id']==b['source_id']
    assert s['profile']==PROFILE and s['configuration']=='DacOpt4C4' and s['part']=='xcu280-fsvh2892-2L-e'
    assert s['certified_bitstream'] and not s['fpga_access'] and not s['formal_admission']
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==COMMIT
    subprocess.run(['git','diff','--exit-code',COMMIT,'--','chipyard'],cwd=F,check=True)
    for name in ['dut_synth','top_synth','implementation','timing_bitstream']:
        item=s['stages'][name];assert item['returncode']==0 and item['source_id']==b['source_id']
        assert all(sha(p)==h for p,h in item['outputs'].items()),name
    assert all(sha(p)==h for p,h in s['inputs']['generated'].items())
    assert len(s['inputs']['shell_checkpoints'])==11 and not s['inputs']['frozen_dut_imported']
    assert all(sha(d['path'])==d['sha256'] for d in s['inputs']['shell_checkpoints'])
    from opt4_fit_runtime_guard import SOURCE
    assert b['source_id']==SOURCE
    for kind in ['CLB LUTs','CARRY8','DSPs','CLB Registers','Block RAM Tile','URAM']:
        r=s['top_postopt_resources'][kind]
        assert 0<=r['used']<=r['available'] and r['available']>0,kind
    logs=Path(s['log_dir'])
    assert (logs/'capacity.complete').read_text().startswith('CAPACITY_FITS_POSTOPT_TIMING_PENDING')
    implementation=Path(s['stages']['implementation']['log']).read_text(errors='replace')
    assert 'EC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX' in implementation
    timing=Path(s['stages']['timing_bitstream']['log']).read_text(errors='replace')
    m=re.search(r'EC_FIT_TIMING WNS=([-+0-9.eE]+) WHS=([-+0-9.eE]+)',timing)
    assert m and all(float(v)>=0 for v in m.groups()) and 'EC_FIT_BITSTREAM_COMPLETE' in timing
    bit=Path(s['bitstream']);assert sha(bit)==s['bitstream_sha256']
    dest=O/'firesim.bit'
    if not dest.exists():
        tmp=dest.with_suffix('.copying');shutil.copy2(bit,tmp)
        assert sha(tmp)==s['bitstream_sha256']
        with tmp.open('rb') as f:os.fsync(f.fileno())
        tmp.replace(dest)
        fd=os.open(dest.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
    assert sha(dest)==s['bitstream_sha256']
    receipt=dict(s,returncode=0,durable_bitstream=str(dest),durable_bitstream_sha256=s['bitstream_sha256'],
        status='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED',certified_utc=now(),
        deployment_admission=False,formal_admission=False,canonical_frozen_receipts_changed=False)
    if (O/'certified-build.json').exists():
        previous=read(O/'certified-build.json')
        assert previous['durable_bitstream_sha256']==receipt['durable_bitstream_sha256']
        assert previous['hardware_commit']==COMMIT and previous['source_id']==b['source_id']
        return previous
    save(O/'certified-build.json',receipt)
    return receipt


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--certify',action='store_true');args=ap.parse_args()
    r=certify() if args.certify else prepare()
    print(json.dumps({k:r.get(k) for k in ['status','profile','hardware_commit','program_count','cad_status','fpga_access','formal_admission']}))
