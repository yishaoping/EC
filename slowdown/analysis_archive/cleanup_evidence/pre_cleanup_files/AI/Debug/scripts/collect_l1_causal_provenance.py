#!/usr/bin/env python3
"""Record generated/config/native/binary identities for the active sealed pair."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]


def read(p):return json.loads(p.read_text())
def dump(p,v):p.write_text(json.dumps(v,indent=2,sort_keys=True)+'\n')
def digest(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda:f.read(1024*1024),b''):h.update(chunk)
    return h.hexdigest()


def differences(a,b,path=''):
    if type(a)!=type(b):return [(path,a,b)]
    if isinstance(a,dict):
        return [x for k in sorted(a.keys()|b.keys()) for x in differences(a.get(k),b.get(k),path+'/'+k)]
    if isinstance(a,list):
        if len(a)!=len(b):return [(path,a,b)]
        return [x for i,(v,w) in enumerate(zip(a,b)) for x in differences(v,w,path+'/'+str(i))]
    return [] if a==b else [(path,a,b)]


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--execution',action='store_true');args=ap.parse_args()
    report=Path((ROOT/'AI/TMP/.l1_causal_active').read_text().strip())
    revision=Path((ROOT/'AI/TMP/.l1_causal_revision').read_text().strip())
    seal=read(revision/'source_seal.json')
    builds={}
    for arm in ['A','B']:
        paths=list((revision/'arms'/arm/'runs').glob('*/run_manifest.json'))
        if len(paths)!=1:raise ValueError(f'{arm}: expected one run, got {len(paths)}')
        m=read(paths[0])
        builds[arm]=revision/'arms'/arm/'build'/paths[0].parent.name
        if m.get('hardware_generation')!='PASS':raise ValueError(f'{arm}: RTL generation not complete')
    generated={n:b/'generated' for n,b in builds.items()}
    configs={n:next(g.glob('*Config.json')) for n,g in generated.items()}
    delta=differences(read(configs['A']),read(configs['B']))
    extra={}
    for suffix in ['l2.json','buildTopClockGenerator.freq-summary','harnessDividerOnlyClockGenerator.freq-summary']:
        paths=[next(generated[n].glob('*Config.'+suffix)) for n in ['A','B']]
        hashes=[digest(p) for p in paths]
        extra[suffix]={'equal':hashes[0]==hashes[1],'paths':[str(p) for p in paths],'sha256':hashes}
    expected=[('/cpus/cpu@0/d-cache-sets/0',256,512),('/cpus/cpu@0/d-cache-size/0',32768,65536)]
    config_status='PASS' if delta==expected and all(x['equal'] for x in extra.values()) else 'FAIL'
    dump(report/'generated_configuration_audit.json',dict(status=config_status,revision=str(revision),
        scope='Generated device tree, clock and L2 config; dynamic geometry is separately validated',
        config_json={n:str(p) for n,p in configs.items()},differences=delta,same_collateral=extra))
    source=ROOT/'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc';source_hash=digest(source)
    resources={n:[{'path':str(p),'sha256':digest(p),'matches_source':digest(p)==source_hash}
        for p in g.rglob('cache_opportunity.cc')] for n,g in generated.items()}
    resource_status='PASS' if all(v and all(p['matches_source'] for p in v) for v in resources.values()) else 'FAIL'
    dump(report/'native_resource_copy_validation.json',dict(status=resource_status,revision=str(revision),source_sha256=source_hash,arms=resources))
    changed=[rel for rel,h in {**seal['hardware_sha256'],**seal['tool_sha256']}.items() if digest(ROOT/rel)!=h]
    dump(report/'sealed_inputs_inflight_check.json',dict(status='PASS' if not changed else 'FAIL',revision=str(revision),
        changed=changed,source_fingerprint=seal['paired_source_fingerprint']))
    output={'generated_configuration':config_status,'native_resource_copy':resource_status,'changed_sealed_inputs':changed}
    if args.execution:
        processes={n:read(report/f'simulation_process_{n}.json') for n in ['A','B']}
        execution={'argv_A':processes['A']['argv'],'argv_B':processes['B']['argv'],
            'actual_simulation_parameters_equal':processes['A']['argv'][1:]==processes['B']['argv'][1:],'executables':{}}
        for n in ['A','B']:
            p=Path(processes[n]['argv'][0]);p.relative_to(builds[n])
            execution['executables'][n]={'path':str(p),'size':p.stat().st_size,'sha256':digest(p)}
        execution['status']='PASS' if execution['actual_simulation_parameters_equal'] else 'FAIL'
        dump(report/'simulation_execution_provenance.json',execution);output['actual_execution']=execution['status']
    print(json.dumps(output,indent=2))
    if config_status!='PASS' or resource_status!='PASS' or changed:raise SystemExit(1)


if __name__=='__main__':main()
