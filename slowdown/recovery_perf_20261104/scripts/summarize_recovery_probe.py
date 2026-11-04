#!/usr/bin/env python3
"""Summarize genuine injected FAIL observations without claiming restoration."""
import argparse
import json
from pathlib import Path
import re


def summary(run):
    manifest=json.loads((run/'manifest.json').read_text())
    text=(run/'stderr.log').read_text()
    events=[]
    for line in text.splitlines():
        if not line.startswith('RECOVERY_'):continue
        fields=dict(re.findall(r'(\w+)=([^\s]+)',line))
        events.append(dict(kind=line.split()[0],**fields))
    inject=next((e for e in events if e['kind']=='RECOVERY_INJECT'),None)
    error=next((e for e in events if e['kind']=='RECOVERY_REAL_COMPARATOR_ERROR'),None)
    fail=next((e for e in events if e['kind']=='RECOVERY_FAIL_STICKY'),None)
    end=next((e for e in events if e['kind']=='RECOVERY_PROBE_END'),None)
    before=[e for e in events if e.get('event')=='before_FAIL_edge']
    after=[e for e in events if e.get('event')=='after_FAIL_edge']
    return dict(run=str(run),hardware_commit=manifest['hardware_commit'],manifest=str(run/'manifest.json'),
        scope='genuine checker-fault/FAIL-path observation; no main historical-memory/register/PC restoration oracle',
        detection_and_accepted_FAIL=bool(inject and error and fail and end),
        restoration_validated=False,recovery_acceptance='BLOCKED',
        requested_boundary=dict(minimum_watermark=manifest.get('minimum_watermark',0),require_wb=manifest.get('require_wb',False)),
        trigger_status='INJECTED' if inject else 'NOT_EXERCISED',
        injection=inject,comparator_error=error,accepted_fail=fail,end=end,
        before_FAIL_slots=before,after_FAIL_slots=after,
        events=events,exit=json.loads((run/'exit.json').read_text()) if (run/'exit.json').exists() else None)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('run',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    r=summary(a.run)
    a.output.write_text(json.dumps(r,indent=2)+'\n')
    print(json.dumps({k:r[k] for k in ['hardware_commit','detection_and_accepted_FAIL','restoration_validated','injection','accepted_fail','end']}))
