#!/usr/bin/env python3
"""Require equivalent validated pilot triplets before expanding inputs."""
import argparse,json
from pathlib import Path
from run_pilot import OUT,dump
def main():
    p=argparse.ArgumentParser();p.add_argument('selection',type=Path);a=p.parse_args();selection=json.loads(a.selection.read_text());revision=json.loads((OUT/'hardware_revision.json').read_text());assert revision['status']=='ACCEPTED'
    assert set(selection)=={'blackscholes','streamcluster','canneal'};cases={}
    for app,ids in selection.items():
        runs={k:json.loads((OUT/'runs'/rid/'run_manifest.json').read_text())for k,rid in ids.items()}
        analyses={k:json.loads((OUT/'runs'/rid/'analysis.json').read_text())for k,rid in ids.items()}
        assert set(runs)=={'native','check','correction'} and all(v['status']=='PASS'for v in analyses.values())
        assert all(v['software']['benchmark']==app and v['software']['input_class']=='simdev' and v.get('evaluation_git_status')==''for v in runs.values())
        assert runs['native'].get('native_model')=='detection' and runs['native']['simulator_sha256']==runs['check']['simulator_sha256']
        assert runs['correction']['canonical_hardware_commit']==revision['canonical_hardware_commit'] and runs['correction']['simulator_sha256']==revision['simulator_sha256']
        assert len({r['roi_instret']for r in runs.values()})==1 and len({tuple(r['output'])for r in runs.values()})==1
        assert runs['check']['elf_sha256']==runs['correction']['elf_sha256']
        cases[app]={'runs':ids,'roi_cycles':{k:v['roi_cycles']for k,v in runs.items()},'ROI_instructions':runs['correction']['roi_instret'],'output':runs['correction']['output'],'PASS':analyses['correction']['packages']['PASS'],'FAIL':analyses['correction']['packages']['FAIL'],'CANCELLED':analyses['correction']['packages']['CANCELLED']}
    result={'status':'PASS','canonical_hardware_commit':revision['canonical_hardware_commit'],'cases':cases,'scope':'Initial simdev pilots only. Primary input comparisons are separately selected.'};dump(OUT/'pilot_acceptance.json',result);print(json.dumps(result,indent=2))
if __name__=='__main__':main()
