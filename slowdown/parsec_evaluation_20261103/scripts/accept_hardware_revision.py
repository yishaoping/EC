#!/usr/bin/env python3
"""Require all mandatory regressions before recording an accepted revision."""
import argparse,json
from pathlib import Path
from run_pilot import ROOT,OUT,hardware,dump
def main():
    p=argparse.ArgumentParser();p.add_argument('candidate',type=Path);p.add_argument('--bfs',required=True);p.add_argument('--blackscholes',required=True);p.add_argument('--streamcluster',required=True);p.add_argument('--canneal',required=True);a=p.parse_args()
    sim,evidence,commit=hardware(a.candidate,True);checks={}
    cone=[p for p in (OUT/'logs').glob('epoch_cone_*.json') if json.loads(p.read_text()).get('emitted_source_sha256')==evidence['revision']['emitted_DCache_sha256'] and json.loads(p.read_text()).get('status')=='PASS'];assert cone,'Matching emitted epoch controller test required'
    checks['emitted_epoch_controller']={'evidence':str(cone[-1].relative_to(OUT))}
    bfs=OUT/'build'/a.bfs;result=json.loads((bfs/'result.json').read_text());assert result['status']=='PASS' and result['canonical_hardware_commit']==commit;checks['BFS']=dict(run_id=a.bfs,result=result)
    for app,name in [('blackscholes',a.blackscholes),('streamcluster',a.streamcluster),('canneal',a.canneal)]:
        run=OUT/'runs'/name;m=json.loads((run/'run_manifest.json').read_text());s=json.loads((run/'analysis.json').read_text())
        assert m['canonical_hardware_commit']==commit and m['simulator_sha256']==evidence['revision']['simulator_sha256'] and m['design']=='correction' and m['software']['benchmark']==app and m['software']['input_class']=='simdev' and m.get('evaluation_git_status')==''
        assert s['status']=='PASS' and s['packages']['FAIL']==0 and s['packages']['CANCELLED']==0
        checks[app]=dict(run_id=name,ROI_cycles=m['roi_cycles'],ROI_instret=m['roi_instret'],output=m['output'],accepted_packages=s['packages']['PASS'])
    r=evidence['revision'];r.update(status='ACCEPTED',canonical_tag=r['proposed_tag'],acceptance=checks)
    dest=OUT/'hardware_revision.json';assert not dest.exists(),'Archive an older accepted revision explicitly before replacement'
    dump(dest,r);print(json.dumps(r,indent=2))
if __name__=='__main__':main()
