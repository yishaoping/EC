#!/usr/bin/env python3
"""Compare exported B/C4 config values, retaining explicit predictor ABI evidence."""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import re

def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()

def differences(a,b,path=''):
    if isinstance(a,dict) and isinstance(b,dict):
        return sum((differences(a.get(k),b.get(k),path+'.'+k) for k in sorted(a.keys()|b.keys())),[])
    if a!=b: return [{'path':path,'B':a,'C4':b}]
    return []

def predictor(root):
    mixin=root/'generators/boom/src/main/scala/common/config-mixins.scala'
    match=re.search(r'(class WithTAGELBPD\b.*?)(?=\nclass |\Z)',mixin.read_text(),re.S)
    if not match: raise ValueError('WithTAGELBPD source not found')
    bpd=root/'generators/boom/src/main/scala/ifu/bpd'
    return {'mixin_source_sha256':hashlib.sha256(match[1].strip().encode()).hexdigest(),
            'predictor_sources':{str(p.relative_to(bpd)):sha(p) for p in bpd.rglob('*.scala')},
            'predictor_namespace_normalized':{str(p.relative_to(bpd)):hashlib.sha256(
                p.read_text().replace('org.chipsalliance.cde.config','freechips.rocketchip.config').encode()).hexdigest()
                for p in bpd.rglob('*.scala')},
            'mixin_file':str(mixin)}

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--b',required=True,type=Path);p.add_argument('--c4',required=True,type=Path)
    p.add_argument('--b-tree',required=True,type=Path);p.add_argument('--c4-tree',required=True,type=Path)
    p.add_argument('--out',required=True,type=Path)
    a=p.parse_args()
    b=json.loads(a.b.read_text());c=json.loads(a.c4.read_text())
    assert len(b['tiles'])==1 and len(c['tiles'])==5
    assert b['tiles'][0]['hartId']==c['tiles'][0]['hartId']==0
    assert {x['hartId'] for x in c['tiles']}==set(range(5))
    bp,cp=predictor(a.b_tree),predictor(a.c4_tree)
    aliases=[a.c4_tree/'generators/rocket-chip/src/main/scala/org/chipsalliance/cde/config/package.scala',
             a.c4_tree/'generators/rocket-chip/src/main/scala/packge.scala']
    alias_proof=all(f.is_file() for f in aliases) and all(
        f'type {name} = chipsalliance.rocketchip.config.{name}' in aliases[0].read_text() and
        f'type {name} = org.chipsalliance.cde.config.{name}' in aliases[1].read_text()
        for name in ['Parameters','Config'])
    # The pinned EC tree also changes SwBranchPredictorBank, which is not
    # instantiated by the byte-identical WithTAGELBPD constructor above.
    unused={'sw_predictor.scala'}
    normalized={label:{k:v for k,v in evidence['predictor_namespace_normalized'].items() if k not in unused}
                for label,evidence in [('B',bp),('C4',cp)]}
    predictor_equal=(bp['mixin_source_sha256']==cp['mixin_source_sha256'] and
                     alias_proof and normalized['B']==normalized['C4']
                     and bool(bp['predictor_sources']))
    bt,ct=copy.deepcopy(b['tiles'][0]),copy.deepcopy(c['tiles'][0])
    raw=differences(bt,ct)
    bo,co=bt['core']['branchPredictor'],ct['core']['branchPredictor']
    # Closure ordinals change when Opt4 adds a preceding config mixin. Only
    # normalize after byte-equal constructor AND implementation source proof.
    if predictor_equal and all('WithTAGELBPD' in v for v in [bo,co]):
        bt['core']['branchPredictor']=ct['core']['branchPredictor']='WithTAGELBPD:source-identical'
    diff=differences(bt,ct)
    common={k:differences(b[k],c[k]) for k in ['inclusive_cache','external_memory','memory_model']}
    result={'parameter_comparison_passed':not diff and not any(common.values()),
            'runtime_comparability':'NOT_VALIDATED: runtime FASED/software/timebase still required',
            'tile_counts':{'B':len(b['tiles']),'C4':len(c['tiles'])},'raw_boom_differences':raw,
            'source_proven_predictor_equivalence':predictor_equal,'predictor_evidence':{'B':bp,'C4':cp},
            'cde_alias_proof':alias_proof,'cde_alias_sources':{str(f):sha(f) for f in aliases if f.is_file()},
            'excluded_unused_predictor':{'files':sorted(unused),
                'reason':'WithTAGELBPD instantiates Loop/Tage/BTB/BIM/FAMicroBTB, not SwBranchPredictorBank; raw hashes retained above'},
            'boom_differences_after_source_proof':diff,'common_parameter_differences':common,
            'exports':{str(f.resolve()):sha(f) for f in [a.b,a.c4]}}
    a.out.parent.mkdir(parents=True,exist_ok=True)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print(a.out, result['parameter_comparison_passed'])
    return 0 if result['parameter_comparison_passed'] else 1

if __name__=='__main__': raise SystemExit(main())
