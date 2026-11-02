#!/usr/bin/env python3
"""Bounded live status read for the explicitly sealed L1-Causal-1 pair."""
import argparse
import datetime
import json
from pathlib import Path
import time

ROOT=Path(__file__).resolve().parents[3]


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--capture-processes',action='store_true')
    ap.add_argument('--compact',action='store_true')
    args=ap.parse_args()
    report=Path((ROOT/'AI/TMP/.l1_causal_active').read_text().strip())
    revision=Path((ROOT/'AI/TMP/.l1_causal_revision').read_text().strip())
    output={'as_of':datetime.datetime.now().astimezone().isoformat(),'arms':{}}
    for name in ['A','B']:
        paths=list((revision/'arms'/name/'runs').glob('*/run_manifest.json'))
        if len(paths)!=1:
            output['arms'][name]={'manifest_count':len(paths)}
            continue
        p=paths[0];m=json.loads(p.read_text());run=p.parent
        d={key:m.get(key) for key in ['phase','result','hardware_generation','verilator_build','simulation','exit_status','error']}
        stream=run/'safe_chain_events.tsv'
        if stream.exists() and stream.stat().st_size:
            with stream.open('rb') as f:
                f.seek(max(0,stream.stat().st_size-16384));raw=f.read()
            lines=raw.splitlines()
            if not raw.endswith(b'\n'):lines=lines[:-1]
            all_rows=[x.split(b'\t') for x in lines if x.startswith(b'SC1\t') and len(x.split(b'\t'))>=8]
            if all_rows:d['latest_observed_global_cycle']=max(int(x[2]) for x in all_rows)
            rows=[x.split(b'\t') for x in lines if x.startswith(b'SC1\t') and len(x.split(b'\t'))>=8 and x.split(b'\t')[6]==b'0']
            if rows:d['latest_observed_hart0_SC_cycle']=int(rows[-1][2])
            d['captured_event_bytes']=stream.stat().st_size
        if m.get('phase')=='VERILATOR_BUILD':
            build=revision/'arms'/name/'build'/run.name
            units=list((build/'generated').rglob('VTestHarness*.cpp'))
            missing=[p.name for p in units if not p.with_suffix('.o').exists()]
            d['cpp_units']=len(units);d['cpp_pending']=len(missing)
            if len(missing)<4:d['pending_files']=missing
        for file in ['stdout.log','stderr.log','cache_opportunity.jsonl']:
            p=run/file
            if p.exists():d[file+'_bytes']=p.stat().st_size
            if file=='stderr.log' and p.exists() and p.stat().st_size:
                with p.open('rb') as f:
                    f.seek(max(0,p.stat().st_size-8192));tail=f.read().decode(errors='replace')
                markers=[x for x in tail.splitlines() if x.startswith('[CAUSAL_ROI_MARKER]')]
                if markers:d['roi_markers']=markers
        output['arms'][name]=d
    if args.capture_processes:
        for proc in Path('/proc').iterdir():
            if not proc.name.isdigit():continue
            try:
                argv=[x.decode(errors='replace') for x in (proc/'cmdline').read_bytes().split(b'\0') if x]
                if argv and str(revision) in argv[0] and '/simulator-chipyard-L1Causal' in argv[0]:
                    name='A' if '32Config' in argv[0] else 'B'
                    p=report/f'simulation_process_{name}.json'
                    if not p.exists():p.write_text(json.dumps({'pid':int(proc.name),'argv':argv,'captured_unix':time.time()},indent=2)+'\n')
                    output['arms'][name]['pid']=int(proc.name)
            except (FileNotFoundError,PermissionError,ProcessLookupError):pass
    if args.compact:
        print(output['as_of'])
        for name,d in output['arms'].items():
            keys=['phase','result','error','exit_status','latest_observed_global_cycle','latest_observed_hart0_SC_cycle','cpp_pending','roi_markers']
            print(name,json.dumps({k:d[k] for k in keys if k in d and d[k] is not None}))
    else:print(json.dumps(output,indent=2))


if __name__=='__main__':main()
