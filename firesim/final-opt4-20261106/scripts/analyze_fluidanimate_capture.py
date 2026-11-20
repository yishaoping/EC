#!/usr/bin/env python3
"""Recover a complete diagnostic UART file; describe differences, never relax validity."""
import base64
from collections import Counter
import datetime as dt
import hashlib
import json
import math
import re
import struct
import time
from pathlib import Path
from board_batch import W,D,save,sha


OUTPUT=D/'software/fluidanimate-fpga-output-analysis.json'


def read(p):return json.loads(p.read_text()) if p.exists() else {}


def analyze(path):
    manifest=read(path/'manifest.json');identity=manifest['identity'];rid=identity['run_id']
    text=(path/'uart.log').read_text(errors='strict').replace('\r','')
    pattern=(r'^EC_DIAGNOSTIC_FILE_BEGIN run_id='+re.escape(rid)+r' file=out\.fluid bytes=(\d+) encoding=base64\n'
             r'([A-Za-z0-9+/=\n]+)^EC_DIAGNOSTIC_FILE_END run_id='+re.escape(rid)+r' file=out\.fluid$')
    matches=list(re.finditer(pattern,text,re.M))
    assert len(matches)==1, 'capture must contain exactly one complete matching file envelope'
    match=matches[0];n=int(match[1]);assert n<=8388608
    data=base64.b64decode(''.join(match[2].splitlines()),validate=True);assert len(data)==n
    destination=path/'diagnostic-files';destination.mkdir(exist_ok=True)
    target=destination/'out.fluid'
    if target.exists():assert target.read_bytes()==data
    else:
        tmp=target.with_name(target.name+'.tmp');tmp.write_bytes(data);tmp.replace(target)
    apps=read(W/'software/fluidanimate-apps-build.json')
    case=next(c for c in apps['cases'] if c['input']==identity['input'])
    reference=Path(apps['host_log_dir'])/('reference-'+identity['input'])/'out.fluid'
    assert sha(reference)==case['reference_outputs']['out.fluid']
    ref=reference.read_bytes();assert len(data)>=8 and len(ref)>=8
    header=struct.unpack('<fi',data[:8]);refheader=struct.unpack('<fi',ref[:8])
    assert len(data)==8+header[1]*36 and len(ref)==8+refheader[1]*36
    evidence=dict(schema='ec-fluidanimate-output-diagnostic/1',status='OUTPUT_RECOVERED',
        diagnostic_only=True,formal_eligible=False,no_validity_override=True,
        run_dir=str(path),run_id=rid,identity_sha256=manifest.get('identity_sha256'),
        uart_sha256=sha(path/'uart.log'),file=str(target),file_sha256=hashlib.sha256(data).hexdigest(),
        bytes=n,reference=str(reference),reference_sha256=sha(reference),
        header=dict(rest_particles_per_meter=header[0],particles=header[1]),
        reference_header=dict(rest_particles_per_meter=refheader[0],particles=refheader[1]),
        exact_bytes_equal=data==ref,original_sample_valid=read(path/'result.json').get('valid'),
        interpretation='Numerical and record-order differences below are diagnostics only. The exact-byte formal gate remains unchanged.')
    if len(data)==len(ref) and header==refheader:
        floats=struct.iter_unpack('<9f',data[8:]);refs=struct.iter_unpack('<9f',ref[8:])
        names=['px','py','pz','hvx','hvy','hvz','vx','vy','vz']
        rows=[dict(component=name,equal=0,different=0,nonfinite=0,max_absolute_error=0.0,sum_absolute_error=0.0) for name in names]
        for values,expected in zip(floats,refs):
            for row,a,b in zip(rows,values,expected):
                if a==b:row['equal']+=1;continue
                row['different']+=1
                if not (math.isfinite(a) and math.isfinite(b)):row['nonfinite']+=1;continue
                delta=abs(a-b);row['max_absolute_error']=max(row['max_absolute_error'],delta);row['sum_absolute_error']+=delta
        evidence['components']=rows
        evidence['particle_records_equal_as_multiset']=Counter(data[i:i+36] for i in range(8,len(data),36))==Counter(ref[i:i+36] for i in range(8,len(ref),36))
    save(path/'diagnostic-output-analysis.json',evidence)
    return evidence


def main():
    profile=W/'software/fluidanimate-diagnostic-apps-build.json'
    save(OUTPUT,dict(status='WAITING_FOR_FPGA_DIAGNOSTIC_CAPTURE',diagnostic_only=True,formal_eligible=False))
    while True:
        if profile.exists():
            digest=sha(profile)
            candidates=[]
            for manifest in (D/'runs').glob('native-fluidanimate-simsmall-r*/manifest.json'):
                m=read(manifest)
                if m.get('identity',{}).get('apps_manifest_sha256')==digest and (manifest.parent/'result.json').exists():candidates.append(manifest.parent)
            if candidates:
                path=sorted(candidates)[-1]
                try:evidence=analyze(path)
                except Exception as exc:
                    save(OUTPUT,dict(status='FAILED_WITH_EVIDENCE',run_dir=str(path),error=repr(exc),diagnostic_only=True));raise
                evidence['ended_utc']=dt.datetime.now(dt.timezone.utc).isoformat();save(OUTPUT,evidence)
                print(json.dumps({k:evidence[k] for k in ['status','run_id','exact_bytes_equal','file_sha256']}),flush=True);return
        time.sleep(300)


if __name__=='__main__':main()
