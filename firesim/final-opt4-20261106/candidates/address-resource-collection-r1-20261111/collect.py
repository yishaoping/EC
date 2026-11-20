#!/usr/bin/python3
"""Collect actual completed module reports without altering any live pipeline.

Also independently correct the r1 controller's summary parser: Vivado's starred
CLB LUTs header and later SLR rows must not yield an apparent zero-LUT design.
No synthesis, process signals, DCP reopening, promotion, or hardware access.
"""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os
import re
import sys
import time

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-address-resource-collection-r1-20261111'
TABLE=[
 ('round3','aca893e0aa3f7e23e16067ab40713afea41558e8','d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28','Opt4-fit-address-round3-state.json','Opt4-fit-address-round3-20261110/full-address-map/utilization.rpt'),
 ('heap','c41d42f61aa79d8249125c9e911438b797d007ce','6fcb790b0d19e832582166c1940f485a00940f95437b38d297d9533f446721d2','Opt4-fit-address-heap-candidate-state.json','Opt4-fit-address-heap-candidate-c41d42f-20261110/map/utilization.rpt'),
 ('sort','11edd71981aa30ff3a26aab1f2f7327ac0266ee1','f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec','Opt4-fit-address-sort-state.json','Opt4-fit-address-sort-11edd719-20261110/full-address/map/utilization.rpt'),
 ('decode-r1','aeabe5abe9f0ece2e024b5c8aa91a2c24fdfa4cb','c1d8e0c2da48e82aba099638e2a910d8c358341c44aba59229098cf83cc29404','Opt4-fit-address-decode-r1-state.json','Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/utilization.rpt')]

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text()) if Path(p).is_file() else {}
def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p,x):
    p=Path(p);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)

def parse(p):
    result={}
    for line in Path(p).read_text().splitlines():
        m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs)\s*\|\s*([\d,.]+)\s*\|',line)
        if m:result.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    assert set(result)=={'CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','DSPs'},str(p)
    assert result['CLB LUTs']>0, 'do not accept a misleading zero-LUT summary'
    return result

def identity(pid):
    try:
        v=(Path('/proc')/str(pid)/'stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=pid,start_ticks=v[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=v[0])
    except FileNotFoundError:return {}

def live(x):
    y=identity(x.get('pid',0))
    return bool(y and y.get('start_ticks')==str(x.get('start_ticks')) and y.get('host_boot_id')==x.get('host_boot_id') and y.get('process_state') not in ['Z','X'])

def selftest():
    known={TABLE[0][4]:1153226,TABLE[1][4]:1183979,
      'Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-read-old/utilization.rpt':4352,
      'Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-read-new/utilization.rpt':9136}
    rows=[]
    for rel,lut in known.items():
        p=D/'build-logs'/rel;r=parse(p);assert r['CLB LUTs']==lut
        rows.append(dict(report=str(p),sha256=sha(p),expected_lut=lut,parsed=r))
    save(O/'parser-selftest.json',dict(status='PASS_REAL_VIVADO_STARRED_AND_REPEATED_SLR_ROWS',rows=rows,fpga_access=False))

def collect():
    result=[];pending=[]
    for name,commit,source,state,report in TABLE:
        p=D/state;s=read(p);r=dict(name=name,hardware_commit=commit,source_id=source,state=str(p),status=s.get('status'))
        if not s:
            pending.append(name);result.append(r);continue
        assert s['source_id']==source,(name,'source mismatch')
        got=s.get('hardware_commit') or s.get('fit_commit')
        if got:assert got==commit,(name,'commit mismatch')
        completed=s.get('status') in ['VERIFIED_AND_MAPPED_MODULE_ONLY','VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED']
        if not completed:
            if s.get('status')!='FAILED_WITH_EVIDENCE':pending.append(name)
            result.append(r);continue
        path=D/'build-logs'/report;resource=parse(path);r.update(resources=resource,report=str(path),report_sha256=sha(path),scope='ACTUAL_COMPLETE_MODULE_OOC_NOT_SYSTEM_FIT')
        bound=s.get('full_module_map') or s.get('full_address_map') or {}
        if bound.get('report_sha256'):assert bound['report_sha256']==r['report_sha256']
        if name=='decode-r1':
            assert s['local_formal']=='PASS_GENERATED_256X64_ACCESS_CLEAR_AND_64BIT_OVERFLOW'
            assert s['full_module_regression']=='PASS_6144_CYCLES_52_OUTPUTS_NOT_FORMAL'
            r['controller_resource_parser_defect']='Original summary omitted starred LUT row and accepted later zero SLR row; this separate report uses the first actual summary row. Original evidence unchanged.'
        r['lut_reduction_from_8da_percent']=100*(1500571-resource['CLB LUTs'])/1500571
        result.append(r)
    ranked=sorted([x for x in result if x.get('resources')],key=lambda x:(x['resources']['CLB LUTs'],x['resources']['CARRY8']))
    probes={}
    for name in ['old','new']:
        p=D/'build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111'/('map-read-'+name)/'utilization.rpt'
        probes[name]=dict(report=str(p),report_sha256=sha(p),resources=parse(p),scope='256x64 combinational read only; cannot subtract from full-module totals')
    return dict(schema='ec-opt4-real-module-ranking/1',utc=now(),status='PENDING_MODULE_MAPS' if pending else 'COMPLETE_MODULE_RANKING_ONLY',
      modules=result,ranked_names=[x['name'] for x in ranked],pending=pending,read_probes=probes,
      best_measured_candidate=ranked[0]['hardware_commit'] if ranked else None,
      one_hot_read_probe_decision='Reject this read topology for LUT area: 9136 vs4352. Preserve the already-live complete-module experiment and its first results.',
      whole_system_fit=None,full_dut_formal=False,production_selected=False,fpga_access=False,
      next_gate='Real 8da postopt capacity result; measured local-verified candidates only; no module report establishes whole-DUT FIT.')

def main():
    O.mkdir(exist_ok=True)
    if sys.argv[1:]==['--self-test']:selftest();print(O/'parser-selftest.json');return
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(O/'state.json');assert not live(old),'adopt live collector'
    st=dict(schema='ec-opt4-real-module-collector/1',**identity(os.getpid()),status='RUNNING',started_utc=now(),fpga_access=False)
    selftest()
    while True:
        r=collect();save(O/'latest.json',r);st.update(status=r['status'],updated_utc=now(),pending=r['pending']);save(O/'state.json',st)
        if not r['pending']:
            save(O/'result.json',r);print(O/'result.json');return
        time.sleep(300)

if __name__=='__main__':main()
