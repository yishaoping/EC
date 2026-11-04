#!/usr/bin/env python3
"""Read-only verification of stage-1 receipts and file hashes; no driver/target execution."""
import argparse
import hashlib
import json
from pathlib import Path
from build_minimal import inventory, sha


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--evidence',type=Path,required=True)
    p.add_argument('--out',type=Path,required=True)
    a=p.parse_args(); evidence=json.loads(a.evidence.read_text()); rows=[]; limitations=[]
    source_cache={}
    for cid,phases in evidence['builds'].items():
        for phase,summary in phases.items():
            result_path=Path(summary['result'])
            if sha(result_path)!=summary['result_sha256']:raise ValueError('receipt changed: '+str(result_path))
            result=json.loads(result_path.read_text())
            if result['returncode']!=0 or result['phase']!=phase or result['runtime_validation']!='NOT_RUN':
                raise ValueError('invalid compile-only receipt: '+str(result_path))
            if result['source_id']!=summary['source_id'] or result['outputs']!=summary['outputs']:
                raise ValueError('summary/receipt identity mismatch')
            tree=result['source_tree']
            if tree not in source_cache:
                files=inventory(Path(tree))
                source_cache[tree]=hashlib.sha256(json.dumps(files,sort_keys=True).encode()).hexdigest()
            if source_cache[tree]!=result['source_id']:raise ValueError('build source changed: '+tree)
            for f,expected in result['outputs'].items():
                if sha(f)!=expected:raise ValueError('compiled artifact changed: '+f)
            if result.get('input_result') and sha(result['input_result'])!=result['input_result_sha256']:
                raise ValueError('parent build receipt changed')
            script=result_path.parent/'build-script.py'
            script_status='HASH_VERIFIED'
            if script.exists():
                if sha(script)!=result['build_script_sha256']:raise ValueError('build script snapshot changed')
            else:
                # Early receipts predate snapshot retention. Do not recreate
                # an old script from today's version or claim it was verified.
                script_status='NOT_RETAINED_IN_EARLY_RECEIPT'
                limitations.append({'receipt':str(result_path),'missing':'build-script.py',
                                    'recorded_script_sha256':result['build_script_sha256']})
            rows.append({'configuration':cid,'phase':phase,'receipt':str(result_path),'outputs_verified':len(result['outputs']),
                         'source_id':result['source_id'],'status':'COMPILE_RECEIPT_SOURCE_AND_OUTPUT_HASHES_VERIFIED',
                         'build_script_snapshot':script_status})
    report={'evidence':str(a.evidence.resolve()),'evidence_sha256':sha(a.evidence),'builds':rows,
            'current_source_ids':source_cache,'target_execution':'NOT_RUN','driver_executed':False,
            'runtime_validation':'NOT_RUN','provenance_limitations':limitations,
            'warning':'This verifies compiler receipts and current source/output bytes only; missing early script snapshots are explicit limitations. It does not prove bitstream or experiment functionality.'}
    a.out.parent.mkdir(parents=True,exist_ok=True)
    with open(a.out,'x') as f:json.dump(report,f,indent=2);f.write('\n')
    print(json.dumps({'report':str(a.out),'verified_build_phases':len(rows),'runtime_validation':'NOT_RUN'}))


if __name__=='__main__':main()
