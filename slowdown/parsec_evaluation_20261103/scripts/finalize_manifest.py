#!/usr/bin/env python3
"""Revise the current manifest while preserving the original historical freeze."""
import copy,hashlib,json,subprocess
from pathlib import Path
from run_pilot import ROOT,OUT,hardware,sha,dump
def main():
    path=OUT/'reproducibility_manifest.json';historical=OUT/'revisions/153292380/reproducibility_manifest.json'
    if not historical.exists():
        historical.parent.mkdir(parents=True,exist_ok=True);historical.write_bytes(path.read_bytes())
    old=json.loads(historical.read_text());sim,evidence,commit=hardware(OUT/'hardware_revision.json')
    status=subprocess.check_output(['git','status','--porcelain=v1'],cwd=ROOT,text=True);assert not status,'Commit the accepted revision and tag before capturing the clean evaluation manifest'
    def git(*args):return subprocess.check_output(['git',*args],cwd=ROOT,text=True).strip()
    r=copy.deepcopy(old);revision=evidence['revision'];assert git('rev-parse',revision['canonical_tag']+'^{}')==commit
    r.update(canonical_final_commit=commit,last_hardware_fix_commit=commit,tag=revision['canonical_tag'],branch=git('branch','--show-current'),evaluation_head=git('rev-parse','HEAD'),git_status=status,parent_history=git('log','-12','--format=%H %P %s',commit).splitlines(),hardware_tree=git('rev-parse',commit+':chipyard'),hardware_source_sha256=evidence['source']['hardware_sha256'],restored_resource_sha256=evidence['source']['restored_resource_sha256'],reused_builds={'correction':revision['build_id'],'check':'blackscholes_validation/build/matched_check_v5048','native':'blackscholes_validation/build/matched_check_v5048; protected session disabled'},accepted_revision_file=str((OUT/'hardware_revision.json').relative_to(ROOT)),accepted_revision_sha256=sha(OUT/'hardware_revision.json'),simulator_sha256=revision['simulator_sha256'],native_baseline_scope='Matched detection model without SVB/recovery datapath; same ELF text/input/addresses, one mode word differs; physically present checkers wait in idle firmware',historical_manifest=str(historical.relative_to(ROOT)),superseded_hardware='153292380: confirmed Streamcluster S2 grant / epoch flush ownership race')
    dump(path,r);print(path)
if __name__=='__main__':main()
