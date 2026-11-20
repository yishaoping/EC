#!/usr/bin/env python3
"""Bind the diagnosed staged-I/O source to real ROI hooks in a private profile."""
import datetime as dt
import hashlib
import json
import shutil
import subprocess
from pathlib import Path

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    parent=W/'software/formal-apps-build.json';apps=json.loads(parent.read_text())
    diagnostic=D/'software/streamcluster-staged-diagnostic-20261106T115645Z/result.json'
    evidence=json.loads(diagnostic.read_text());source=Path(evidence['candidate_source'])
    assert sha(source)==evidence['candidate_sha256']
    assert all(c['output_matches'] and not c['syscalls_in_original_roi'] for c in evidence['cases'])
    label='apps-streamcluster-staged-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/label;log=D/'software'/label
    out.mkdir();log.mkdir()
    shutil.copy2(source,out/'streamcluster.cpp')
    shutil.copytree(Path(apps['output_dir'])/'inputs',out/'inputs')
    command=next(c['argv'][:] for c in apps['commands']
                 if c.get('argv') and any(x.endswith('/streamcluster.cpp') for x in c['argv'])
                 and '-DENABLE_PARSEC_HOOKS' in c['argv'])
    original=next(x for x in command if x.endswith('/streamcluster.cpp'))
    command=[str(out/'streamcluster.cpp') if x==original else x for x in command]
    command[-1]=str(out/'streamcluster')
    with (log/'build.log').open('wb') as stream:
        subprocess.run(command,stdout=stream,stderr=subprocess.STDOUT,check=True,timeout=180)
    apps.update(output_dir=str(out),parent_receipt=str(parent),parent_receipt_sha256=sha(parent),
        software_profile='streamcluster-staged-io-synthetic-serial',formal_eligible=False,
        profile_limitation='External I/O scheduling and allocator residency changed; unchanged clustering, generated input, original ROI hooks and formatting. Must be used in both groups and measured separately.',
        status='BUILT_WITH_REAL_ROI_HOOKS_FPGA_NOT_RUN',fpga_validation='NOT_RUN',
        staging_diagnostic_receipt=str(diagnostic),staging_diagnostic_sha256=sha(diagnostic),
        original_roi_hooks_preserved=True,clustering_algorithm_modified=False,
        build_command=command,source_sha256=sha(out/'streamcluster.cpp'))
    apps['binaries']['streamcluster'].update(path=str(out/'streamcluster'),sha256=sha(out/'streamcluster'),
        algorithm_sources_modified=False,software_integration_modified=True,
        integration='staged external I/O and prefaulted allocation; original ROI hooks and all math retained')
    # Only synthetic test/simsmall are diagnosed for this profile.
    apps['cases']=[c for c in apps['cases'] if c['program']=='streamcluster' and c['input'] in ['test','simsmall']]
    for c in apps['cases']:
        c['software_profile']=apps['software_profile'];c['fpga_validation']='NOT_RUN'
    receipt=W/'software/streamcluster-staged-apps-build.json'
    value=json.dumps(apps,indent=2)+'\n'
    (log/'result.json').write_text(value);(out/'manifest.json').write_text(value);receipt.write_text(value)
    print(receipt)

if __name__=='__main__':main()
