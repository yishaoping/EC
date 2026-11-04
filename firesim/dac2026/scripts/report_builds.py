#!/usr/bin/env python3
"""Summarize actual build results; never infer runtime success from compilation."""
import argparse
import json
from pathlib import Path
import datetime

ROOT=Path('/data1/gzh/EC')

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--integration',default='opt4-alveo-v3',choices=['opt4-alveo-v3','opt4-minimal-v2','opt4-roi-v4','opt4-roi-v5'])
    p.add_argument('--out',type=Path,required=True)
    a=p.parse_args()
    logs=ROOT/'Experiment/dac2026/build-logs'/a.integration
    results=[];incomplete=[]
    for d in sorted(logs.iterdir()):
        if not d.is_dir(): continue
        f=d/'result.json'
        if f.exists():
            v=json.loads(f.read_text())
            if 'returncode' not in v: continue
            results.append({k:v.get(k) for k in ['config','phase','source_id','source_tree','returncode','error','output_dir','wall_seconds','runtime_validation']})
            results[-1]['result']=str(f)
            results[-1]['status']='COMPILE_PASSED' if v['returncode']==0 else 'COMPILE_FAILED'
        elif any((d/f).exists() for f in ['command.json','commands.json','build-script.py']):
            incomplete.append(str(d))
    configurations={}
    for name,target in [('B','DacBaseline'),('C4','DacOpt4C4')]:
        phases={}
        for phase in ['compile','parameters','elaborate','goldengate','driver']:
            rows=[r for r in results if r['config']==target and r['phase']==phase]
            phases[phase]={'latest_attempt':rows[-1] if rows else None,
                           'last_successful':next((r for r in reversed(rows) if r['returncode']==0),None)}
        configurations[name]={'scripts_generated':True,'build_phases':phases,'user_run_status':'BLOCKED_BY_INCOMPLETE_IMAGE_AND_MEASUREMENT',
                              'real_runtime_passed':False,'bitstream_certified':False}
    report={'created_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'integration':a.integration,
            'configurations':configurations,'all_build_attempts':results,'no_final_result_directories':incomplete,
            'warning':'No final result means incomplete or interrupted; it does not prove the process is alive. Intermediate FIRRTL and CLI help are not completed builds. No runtime success can be inferred here.'}
    a.out.parent.mkdir(parents=True,exist_ok=True)
    a.out.write_text(json.dumps(report,indent=2)+'\n')
    print(a.out)

if __name__=='__main__': main()
