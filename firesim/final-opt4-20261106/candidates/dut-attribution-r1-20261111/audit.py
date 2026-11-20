#!/usr/bin/env python3
"""Read a completed address OOC DCP; rank disjoint mapped name groups.

Names are hints, not source-cone proofs. Raw LUT primitives may share physical
sites; the Vivado utilization report remains authoritative for capacity.
No Vivado, generated input mutation or FPGA access.
"""
import collections
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import time
import zipfile
import zlib

from board_batch import D, save, sha
from job_service import boot, proc

O = D/'build-logs/Opt4-fit-dut-attribution-8da24a26-20261111'
S = D/'Opt4-fit-dut-attribution-state.json'
now = lambda: dt.datetime.now(dt.timezone.utc).isoformat()


def main():
    lock=(D/'.opt4-fit-dut-attribution.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    cad=json.loads((D/'Opt4-fit-cad-state.json').read_text())
    assert cad['hardware_commit']=='8da24a269b98a0d6a8f57b030353a310812c4344'
    stage=cad['stages']['dut_synth'];assert stage['returncode']==0
    path=next(Path(p) for p in stage['outputs'] if p.endswith('.dcp'))
    assert sha(path)==stage['outputs'][str(path)]
    mapping=dict(source_sha256=cad['source_id'],rtl_sha256=cad['inputs']['generated'][str(Path(cad['output_dir'])/'design/FireSim-generated.sv')],fit_commit=cad['hardware_commit'],out=cad['log_dir'])
    stat=path.stat()
    st=dict(schema='ec-address-mapped-name-attribution/1',status='READING_COMPLETED_DCP',
        pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=boot(),
        started_utc=now(),dcp=str(path),dcp_bytes=stat.st_size,
        source_sha256=mapping['source_sha256'],rtl_sha256=mapping['rtl_sha256'],
        module_mapping_commit=mapping.get('fit_commit'),fpga_access=False,source_changed=False)
    save(S,st)
    declarations=re.compile(rb'(?m)^[ \t]*\((cell|instance) ([^\n]+)')
    reference=re.compile(rb'\(cellref ([^\s)]+) \(libraryref ([^\s)]+)\)\)')
    direct=collections.defaultdict(collections.Counter)
    named=collections.defaultdict(lambda:collections.defaultdict(collections.Counter))
    children=collections.defaultdict(collections.Counter)
    current=None
    samples=collections.defaultdict(list)
    totals=collections.Counter()
    start=last=time.monotonic();read_bytes=0;tail=b'';record_count=0;primitive_definitions=0
    def consume(data):
        nonlocal current, tail, primitive_definitions
        data=tail+data
        split=data.rfind(b'\n')
        tail=data[split+1:]
        for match in declarations.finditer(data[:split+1]):
            declaration,body=match.groups()
            if declaration==b'cell':
                current=body.split(None,1)[0].decode()
                assert current not in direct, 'Duplicate cell definition'
                direct[current]=collections.Counter()
                primitive_definitions+=1
                continue
            ref=reference.search(body);assert ref and current
            kind,library=ref.groups()
            if library!=b'hdi_primitives':
                children[current][kind.decode()]+=1
                continue
            ident=body[:body.index(b' (viewref')]
            name=ident.decode()
            if name.startswith('(rename '):name=name.split('"')[1]
            group=re.sub(r'(?:_i(?:_\d+)?|_n_\d+|_reg)?(?:\[.*)?$', '',name.lstrip('_')); group=re.sub(r'_\d+.*$', '',group) or 'anonymous'
            kind=kind.decode();direct[current][kind]+=1;named[current][group][kind]+=1
            if len(samples[current+'.'+group])<3:samples[current+'.'+group].append(name)
    with zipfile.ZipFile(path) as archive:
        member=next(n for n in archive.namelist() if n.endswith('.edf'))
        encoded=archive.read(member)
    pos=0
    while pos<len(encoded):
        header=encoded[pos:pos+24]
        assert len(header)==24 and header[:8]==b'XlxV37EB', ('Unexpected Vivado EDIF record',pos,header)
        advertised=int(header[12:16],16);assert advertised>0
        decoder=zlib.decompressobj();record_bytes=0;cursor=pos+24
        while not decoder.eof:
            chunk=encoded[cursor:cursor+4096];assert chunk,'Truncated EDIF compressed record'
            cursor+=len(chunk)
            decoded=decoder.decompress(chunk,advertised+1-record_bytes)
            record_bytes+=len(decoded);read_bytes+=len(decoded);consume(decoded)
            assert not decoder.unconsumed_tail,'EDIF record exceeds advertised output bound'
        assert not decoder.flush() and record_bytes==advertised,(record_count,record_bytes,advertised)
        pos=cursor-len(decoder.unused_data)
        record_count+=1
        if time.monotonic()-last>=30:
            st.update(decompressed_bytes=read_bytes,record_count=record_count,
                primitive_definitions=primitive_definitions,updated_utc=now())
            save(S,st);last=time.monotonic()
    consume(tail+b'\n')
    assert record_count>1,'Expected chunked Vivado EDIF; single-record parse is suspicious'
    assert path.stat().st_size==stat.st_size and path.stat().st_mtime_ns==stat.st_mtime_ns
    top='design_1_firesim_wrapper_0_0';assert top in direct
    order=[];seen=set();visiting=set()
    def visit(name):
        assert name not in visiting, 'Recursive EDIF hierarchy'
        if name in seen:return
        assert name in direct, ('Unresolved hierarchy',name)
        visiting.add(name)
        for child in children[name]:visit(child)
        visiting.remove(name);seen.add(name);order.append(name)
    visit(top)
    multiplicity=collections.Counter({top:1})
    for name in reversed(order):
        for child,count in children[name].items():multiplicity[child]+=multiplicity[name]*count
    groups=collections.defaultdict(collections.Counter)
    for name,mult in multiplicity.items():
        for kind,count in direct[name].items():totals[kind]+=mult*count
        for group,counter in named[name].items():
            key=group if name==top else name+'.'+group
            for kind,count in counter.items():groups[key][kind]+=mult*count
    metrics=lambda c:dict(lut_primitives=sum(v for k,v in c.items() if re.fullmatch(r'LUT[1-6](_2)?',k)),
        carry8=c['CARRY8'],ff=sum(v for k,v in c.items() if k.startswith('FD')),dsp=c['DSP48E2'])
    rows=[dict(name_group=k,**metrics(v),primitive_counts=dict(v),example_names=samples.get(top+'.'+k,samples.get(k,[]))) for k,v in groups.items()]
    rows.sort(key=lambda r:r['lut_primitives'],reverse=True)
    from summarize_opt4_fit import resources
    physical=resources(Path(mapping['out'])/'dut-utilization.rpt')
    actual=metrics(totals)
    assert actual['carry8']==physical['CARRY8'] and actual['ff']==physical['CLB Registers']
    assert actual['dsp']==physical['DSPs'] and actual['lut_primitives']>=physical['CLB LUTs']>0
    assert totals['RAMB36E2']+totals['RAMB18E2']/2==physical['Block RAM Tile']
    st.update(status='COMPLETE_READ_ONLY_ATTRIBUTION',valid_result=True,ended_utc=now(),wall_seconds=time.monotonic()-start,
        decompressed_bytes=read_bytes,record_count=record_count,primitive_definitions=primitive_definitions,
        primitive_counts=dict(totals),metrics=metrics(totals),groups=rows,
        physical_utilization=physical,primitive_crosscheck='CARRY8_FF_DSP_BRAM_exact_LUT_raw_at_least_packed_PASS',
        hierarchy_multiplicity=dict(multiplicity),
        caveat='Disjoint primitive groups by mapped name only, not physical LUT count or proven source cones. Cross-name optimization may move logic.')
    assert sum(v['lut_primitives'] for v in rows)==st['metrics']['lut_primitives']
    module_rows=[]
    for name,mult in multiplicity.items():
        d=metrics(direct[name]); local=[]
        for group,counts in named[name].items():
            local.append(dict(name_group=group,**metrics(counts),examples=samples.get(name+'.'+group,[])))
        local.sort(key=lambda r:r['lut_primitives'],reverse=True)
        module_rows.append(dict(module=name,instances=mult,direct=d,total_direct_lut_primitives=d['lut_primitives']*mult,groups=local[:50]))
    module_rows.sort(key=lambda r:r['total_direct_lut_primitives'],reverse=True)
    st['direct_module_ranking']=module_rows
    save(O/'result.json',st);save(S,st)
    lines=['# Completed 8da24a26 DUT DCP: mapped-name attribution','',st['ended_utc'],'',st['caveat'],'',
        '| Mapped name group | LUT primitives | CARRY8 | FF | DSP |','|---|---:|---:|---:|---:|']
    lines += ['| '+r['name_group']+' | '+' | '.join(f"{r[k]:,}" for k in ['lut_primitives','carry8','ff','dsp'])+' |' for r in rows[:40]]
    (O/'ATTRIBUTION.md').write_text('\n'.join(lines)+'\n')
    print(json.dumps(dict(status=st['status'],metrics=st['metrics'],largest=rows[:12])),flush=True)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
        raise
