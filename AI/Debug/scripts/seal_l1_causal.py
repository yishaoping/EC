#!/usr/bin/env python3
"""Seal reviewed inputs for existing launcher's explicit L1-Causal-1 mode."""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[3]
OPT3='9afd806830ce32e2e8ad317a4530747e852c881f'
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def output(*args):return subprocess.check_output(['git',*args],cwd=ROOT,text=True).strip()

def main():
    ap=argparse.ArgumentParser();ap.add_argument('experiment',type=Path)
    ap.add_argument('--one-shot-contract',type=Path)
    a=ap.parse_args();r=a.experiment.resolve()
    assert r.is_relative_to(ROOT/'AI/TMP')
    assert not (r/'source_seal.json').exists(),'sealed revisions are immutable; use a new experiment if source changes'
    spec=importlib.util.spec_from_file_location('launch',ROOT/'slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py')
    launch=importlib.util.module_from_spec(spec);spec.loader.exec_module(launch)
    changed=set(output('diff','--name-only',OPT3,'--','chipyard').splitlines())
    untracked=set(output('ls-files','--others','--exclude-standard','--','chipyard').splitlines())
    source=sorted(changed|untracked)
    allowed=launch.ALLOWED_HARDWARE | {
      'chipyard/generators/boom/src/main/scala/lsu/lsu.scala',
      'chipyard/generators/boom/src/main/scala/exu/rob.scala',
      'chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala',
      'chipyard/generators/rocket-chip/src/main/scala/r/R_ICSL.scala',
      'chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala',
      'chipyard/generators/rocket-chip/src/main/scala/util/SafeChainObservation.scala',
      'chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala'}
    assert set(source)<=allowed,set(source)-allowed
    patch=subprocess.check_output(['git','diff','--binary',OPT3,'--',*sorted(changed)],cwd=ROOT)
    for rel in sorted(untracked):
      p=subprocess.run(['git','diff','--no-index','--binary','--','/dev/null',rel],cwd=ROOT,capture_output=True)
      assert p.returncode in (0,1);patch+=p.stdout
    (r/'causal_cumulative.patch').write_bytes(patch)
    subprocess.run(['git','apply','--reverse','--check',str(r/'causal_cumulative.patch')],cwd=ROOT,check=True)
    tool_paths=[
     'slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py',
     'slowdown/optimization_4_svb/scripts/compact_capture.py',
     'slowdown/optimization_4_svb/scripts/prepare_failure_diagnostics.py',
     'slowdown/optimization_4_svb/analysis/analyze_svb.py',
     'slowdown/optimization_4_svb/analysis/analyze_hang.py',
     'slowdown/optimization_4_svb/analysis/integrity_ledger.py',
     'AI/Debug/scripts/test_l1_causal.py','AI/Debug/scripts/seal_l1_causal.py',
     'chipyard/sims/verilator/Makefile','chipyard/common.mk','chipyard/variables.mk']
    if a.one_shot_contract:
      tool_paths += ['AI/Debug/scripts/launch_checker_seq67_one_shot.py',
        'AI/Debug/scripts/run_checker_seq67_one_shot.sh',
        'AI/Debug/scripts/analyze_checker_seq67_one_shot.py',
        'AI/Debug/scripts/inspect_checker_seq67_evidence.py',
        'AI/Debug/scripts/test_checker_seq67_one_shot.py',
        'AI/Debug/scripts/audit_seq67_dispatch_dependencies.py',
        'AI/Debug/scripts/collect_l1_causal_provenance.py',
        'AI/Debug/scripts/analyze_l1_causal_pair.py']
    data=dict(experiment='L1-Causal-1',svb_entries=16,opt3_head=OPT3,
      git_head=output('rev-parse','HEAD'),hardware_sha256={p:digest(ROOT/p) for p in source},
      tool_sha256={p:digest(ROOT/p) for p in tool_paths},patch_sha256=digest(r/'causal_cumulative.patch'),
      software={'elf_sha256':digest(launch.ELF),'loadmem_sha256':digest(launch.LOADMEM)},
      seed=1,max_cycles=500000000,verilator_threads=1,
      arms={'A':{'config':'L1Causal32Config','sets':256},'B':{'config':'L1Causal64Config','sets':512}},
      common_l1={'ways':2,'block_bytes':64,'mshrs':6,'banks':1},
      roi={'start_pc':'0x80000340','stop_pc':'0x8000039c','exact_prefix_snapshot_ring':64})
    if a.one_shot_contract:
      c=a.one_shot_contract.resolve()
      assert c.is_relative_to(ROOT/'AI/TMP')
      contract=json.loads(c.read_text())
      assert contract['number_of_full_runs_requested']==1 and contract['run_target']=='B_ONLY_64K_2WAY'
      data['one_shot_contract']={'path':str(c.relative_to(ROOT)),'sha256':digest(c)}
    invariant={k:v for k,v in data.items() if k!='arms'}
    data['paired_source_fingerprint']=hashlib.sha256(json.dumps(invariant,sort_keys=True).encode()).hexdigest()
    (r/'source_seal.json').write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
    print(json.dumps({'status':'SEALED','hardware_files':len(source),'fingerprint':data['paired_source_fingerprint']},indent=2))

if __name__=='__main__':main()
