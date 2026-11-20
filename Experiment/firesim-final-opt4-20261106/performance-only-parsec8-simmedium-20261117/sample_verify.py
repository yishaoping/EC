#!/usr/bin/env python3
"""Existing sample verifier, with only package-event IO changed to streaming.

All UART, checker accounting, context, FASED, output, drain and failure gates
are copied from the existing runner. Package event matching uses the same
patterns and acceptance rules, without loading multi-gigabyte logs in RAM.
"""
import re
from pathlib import Path
import sys
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from inspect_roi_raw import inspect_bytes

BASELINE_RUNNER_SHA256='c6ecfce4e206e1e9f2cdaee7decfd24d4322c8366f47b3d96fa1f574e393e2ce'

def verify_events(out, contexts, counts):
    issues=[];pending={};pairs=0;begins=0;results=0
    bp=re.compile(r'EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)')
    rp=re.compile(r'EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=\s*([01]) cancelled=\s*([01])')
    for path in sorted(out.glob('rtl-events-*')):
        if not path.is_file():continue
        with path.open(errors='replace') as f:
            for line in f:
                if 'Assertion failed' in line or '%Error' in line:issues.append('RTL assertion')
                b=bp.search(line);r=rp.search(line)
                if b:
                    h,q,s,p=b.groups();key=(int(h),int(q,16));begins+=1
                    if key in pending:issues.append('duplicate task BEGIN')
                    pending[key]=1
                    if not contexts or int(s,16)!=int(contexts[0],16) or int(p)!=0 or int(h) not in range(1,5):issues.append('task context/hart mismatch')
                if r:
                    h,q,s,c,x=r.groups();key=(int(h),int(q,16));results+=1
                    if key not in pending:issues.append('task RESULT without matching BEGIN')
                    else:del pending[key];pairs+=1
                    if (int(s),int(c),int(x))!=(0,1,0):issues.append('task failed/cancelled or lacks true full comparison')
    if pending or not pairs or counts is None or pairs!=counts.get('generated') or begins!=pairs or results!=pairs:issues.append('incomplete real task event coverage')
    return issues,dict(begins=begins,results=results,matched_pairs=pairs,unfinished=len(pending),strict_latency=None)

def verify(out,identity,exitcode,controlled_stop,timedout):
    uart=(out/'uart.log').read_text(errors='replace').replace('\r','');rid=identity['run_id'];issues=[]
    if uart.count('EC_SAMPLE_GUEST_DONE run_id='+rid+' ')!=1:issues.append('missing unique successful output validation')
    if not re.search(r'^EC_COMMAND_EXIT=0$',uart,re.M):issues.append('missing successful application command exit')
    if 'Kernel panic' in uart or 'EC_OPT4_INVALID' in uart or 'EC_SAMPLE_FAILED' in uart:issues.append('guest failure/scope violation')
    if timedout:issues.append('host timeout')
    if exitcode!=0 and not controlled_stop:issues.append('unexpected driver exit')
    counts=None;raw=None;cycles=None;drain=None;participation=None
    if identity['configuration']=='Native':
        journal=(out/'roi-raw.jsonl').read_bytes() if (out/'roi-raw.jsonl').exists() else None
        prefix=0
        if journal and identity.get('host_bridge_restart'):
            try:
                lines=journal.splitlines(keepends=True);values=[json.loads(line) for line in lines]
                prefix=max(i for i,v in enumerate(values) if v['under_reset']==1)
                origin=values[prefix]['sequence'];segment=[]
                for v in values[prefix:]:
                    v['sequence']-=origin;segment.append((json.dumps(v)+'\n').encode())
                raw=inspect_bytes(b''.join(segment));raw['excluded_pre_reset_records']=prefix
                raw['original_journal_sha256']=sha(out/'roi-raw.jsonl')
            except (ValueError,KeyError):issues.append('missing fresh target reset in restarted bridge journal')
        else:raw=inspect_bytes(journal) if journal else None
        epochs=[e for e in raw['epochs'] if e['source_boundaries_complete']] if raw else []
        if raw is None or raw['protocol_issues'] or raw['partial_tail_bytes'] or len(epochs)!=1:issues.append('incomplete Native ROI boundaries/transport')
        else:cycles=epochs[0]['roi_cycles'];drain=0
    else:
        snapshots=re.findall(r'EC_OPT4_SNAPSHOT ([^\n]*)',uart)
        def fields(s):return dict(re.findall(r'(\w+)=\s*([0-9a-fA-F]+)',s))
        try:
            assert len(snapshots)==2
            f=fields(snapshots[-1]);counts={k:int(f[k]) for k in ['epoch','begin','end','drain','generated','completed','outstanding','faults','passed','failed','cancelled','dropped']}
            assert counts['end']>counts['begin'] and counts['drain']>=counts['end']
            assert counts['generated']>0 and counts['generated']==counts['completed']==counts['passed']
            assert not any(counts[k] for k in ['outstanding','faults','failed','cancelled','dropped'])
            cycles=counts['end']-counts['begin'];drain=counts['drain']-counts['end']
        except (AssertionError,KeyError,ValueError):issues.append('invalid/missing positive checker accounting and drain')
        contexts=re.findall(r'EC_OPT4_CONTEXT .*satp=([0-9a-f]+).*hardware_initialized=1',uart)
        installed=re.findall(r'EC_OPT4_INSTALLED hart=(\d+) satp=([0-9a-f]+)',uart)
        parked=re.findall(r'EC_OPT4_CONTEXT_DRAINED ([^\n]*)',uart)
        try:
            assert len(contexts)==1 and len(installed)==4 and {int(h) for h,s in installed}=={1,2,3,4}
            assert all(int(s,16)==int(contexts[0],16) for h,s in installed)
            assert len(parked)==1 and counts is not None
            p=fields(parked[0]);assert int(p['firmware'],16)==15 and int(p['satp'],16)==int(contexts[0],16)
            assert all(int(p[k])==counts[k] for k in ['epoch','generated','completed','outstanding'])
        except (AssertionError,KeyError,ValueError):issues.append('missing matching installed/parked checker context')
        event_issues, participation = verify_events(out, contexts, counts)
        issues.extend(event_issues)
    host=(out/'host.log').read_text(errors='replace')
    efficiency=None
    interval=re.findall(r'EC_HOST_INTERVAL target_start=(\d+) target_end=(\d+) target_delta=(\d+) host_delta=(\d+) wall_seconds=([0-9.]+) throughput_cycles_per_second=([0-9.]+)',host)
    if len(interval)==1:
        start,end,delta,hdelta,seconds,hz=interval[0]
        efficiency=dict(target_start=int(start),target_end=int(end),target_delta=int(delta),host_delta=int(hdelta),host_simulation_wall_seconds=float(seconds),simulation_throughput_cycles_per_second=float(hz),measurement_scope='host simulation efficiency, separate from architecture ROI')
        if int(end)-int(start)!=int(delta) or float(seconds)<=0:issues.append('invalid host efficiency counters')
    rb=re.findall(r'EC_FASED_READBACK key=(\w+) expected=(\d+) actual=(\d+)',host)
    expected=identity['memory_model']['settings'];seen={k:int(a) for k,e,a in rb if e==a}
    if seen!=expected:issues.append('FASED settings not fully read back')
    traffic_records=re.findall(r'EC_OPT4_TRAFFIC index=(\d+) value=(\d+)',uart)
    traffic={int(i):int(v) for i,v in traffic_records}
    if traffic_records and (len(traffic_records)!=128 or set(traffic)!=set(range(128))):issues.append('incomplete/duplicate post-drain traffic counter readback')
    return dict(valid=not issues,issues=sorted(set(issues)),roi_cycles=cycles,drain_cycles=drain,counts=counts,raw=raw,participation=participation,post_drain_traffic_counters=traffic,
                checker_latency=None,guest_power_down_observed='Power down' in uart,fased_readback=seen,host_efficiency=efficiency)
