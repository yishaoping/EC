import sys
from pathlib import Path as _BundlePath
sys.path.insert(0, str(_BundlePath(__file__).resolve().parent))
sys.path.insert(1, '/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""Exact derived-artifact identity and safe-boundary priority; no device IO."""
import hashlib
import json
from pathlib import Path

from board_batch import W,D,sha

COMMIT='8d50489af3af9e4c766509284ba3d9d7c99cfec9'
SOURCE='9bfb0710adc7650940c3edd5005f578cc1295038b34282ece46b87f2ec55ac6a'
PROFILE='Opt4-fit-C4-SVB32-field-address-r1'
FROZEN='8491167d84b6d9521b151a743673c1516926a1f8'
BDF='0000:21:00.0'
SERIAL='21770433G02LA'
RUNTIME=W/'runtime'/('Opt4-fit-'+COMMIT[:8])
CERT=RUNTIME/'certified-build.json'
SUITE=RUNTIME/'software-suite.json'
PRIORITY=D/'Opt4-fit-runtime-priority.json'


def read(p):return json.loads(Path(p).read_text())


def artifact(receipt):
    p=Path(receipt)
    # No arbitrary manifest can authorize another source, card or tool path.
    if p.resolve()!=CERT.resolve():raise ValueError('derived receipt path is not pinned')
    s=read(p)
    assert s['status']=='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED'
    assert s['hardware_commit']==COMMIT and s['source_id']==SOURCE and s['profile']==PROFILE
    assert s['frozen_parent_commit']==FROZEN and s['part']=='xcu280-fsvh2892-2L-e'
    assert s['configuration']=='DacOpt4C4'
    assert s['returncode']==0 and s['certified_bitstream'] and not s['formal_admission']
    assert Path(s['durable_bitstream']).resolve()==(RUNTIME/'firesim.bit').resolve()
    assert sha(s['durable_bitstream'])==s['durable_bitstream_sha256']
    for name in ['dut_synth','top_synth','implementation','timing_bitstream']:
        r=s['stages'][name]
        assert r['returncode']==0 and r['source_id']==SOURCE and r['hardware_commit']==COMMIT
    for kind in ['CLB LUTs','CARRY8','DSPs','CLB Registers','Block RAM Tile','URAM']:
        r=s['top_postopt_resources'][kind]
        assert 0<=r['used']<=r['available'] and r['available']>0,kind
    return s


def priority_guard(receipt=None):
    if not PRIORITY.exists():return
    p=read(PRIORITY)
    if p.get('status') not in ['REQUESTED_AT_SAFE_BOUNDARY','ACTIVE']:return
    assert p['board_bdf']==BDF and p['board_serial']==SERIAL
    assert p['hardware_commit']==COMMIT and p['source_id']==SOURCE
    # Fail closed on malformed priority, but never signal any existing task.
    if receipt is None:raise RuntimeError('certified Opt4-fit has priority at the next 21-only task boundary')
    assert Path(receipt).resolve()==CERT.resolve() and sha(CERT)==p['certificate_sha256']


def software_paths(row):
    for key,path in row['receipts'].items():
        assert sha(path)==row['receipt_sha256'][key],(row['program'],key)
    driver=read(row['receipts']['driver'])
    assert driver['hardware_commit']==COMMIT and driver['hardware_source_id']==SOURCE
    assert driver['profile']==PROFILE and driver['returncode']==0
    exe=Path(driver['output_dir'])/'FireSim-xilinx_alveo_u280'
    assert sha(exe)==driver['outputs'][str(exe)]
    return row['receipts']


def sample_binding(receipt,driver_path,fwpath,apps_path,rootfs_path,program):
    cert=artifact(receipt);suite=read(SUITE)
    assert suite['hardware_commit']==COMMIT and suite['source_id']==SOURCE
    candidates=suite['programs'] if program=='smoke' else [r for r in suite['programs'] if r['program']==program]
    paths={'driver':driver_path,'firmware':fwpath,'apps':apps_path,'rootfs':rootfs_path}
    row=next(r for r in candidates if all(Path(r['receipts'][k]).resolve()==Path(v).resolve() for k,v in paths.items()))
    software_paths(row)
    return cert


def add_identity(ident,receipt):
    cert=artifact(receipt)
    assert ident['configuration']=='C4' and ident['board_bdf']==BDF and ident['board_serial']==SERIAL
    assert ident['hardware_source_id']==SOURCE and ident['bitstream_sha256']==cert['durable_bitstream_sha256']
    ident.update(hardware_commit=COMMIT,hardware_profile=PROFILE,frozen_parent_commit=FROZEN,
        derived_build_receipt=str(CERT),derived_build_receipt_sha256=sha(CERT))
    return ident


def complete(path):
    """Only a fully committed, hash-bound result is reusable."""
    path=Path(path)
    if not path.exists() or not (path.parent/'complete.json').exists():return None
    r=read(path);c=read(path.parent/'complete.json');i=r.get('identity',{})
    if not(r.get('valid') and r.get('fpga_execution') and c.get('result_sha256')==sha(path)
           and c.get('identity_sha256')==r.get('identity_sha256')):return None
    assert hashlib.sha256(json.dumps(i,sort_keys=True).encode()).hexdigest()==r['identity_sha256']
    return r
