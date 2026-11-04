#!/usr/bin/env python3
"""Artifact-backed experiment cache; absent/incomplete identity never hits."""
import argparse
import datetime
import hashlib
import json
from pathlib import Path
import subprocess
import fcntl
import os

ROOT=Path(__file__).resolve().parents[2]
OUT=Path(__file__).resolve().parent
INDEX=OUT/'experiment_index.json'
WORKTREES=[Path('/data1/gzh')/n for n in ['EC-opt4-perf','EC-opt4-recovery-perf','EC-opt4-recovery-rescue','EC-opt4-aggressive-perf']]


def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda:f.read(1048576),b''):h.update(b)
    return h.hexdigest()


def digest(v):
    return hashlib.sha256(json.dumps(v,sort_keys=True,separators=(',',':')).encode()).hexdigest()


def read(p):return json.loads(Path(p).read_text())


def save(v):
    OUT.mkdir(exist_ok=True)
    p=INDEX.with_suffix('.tmp');p.write_text(json.dumps(v,indent=2)+'\n');p.replace(INDEX)


def locked():
    OUT.mkdir(exist_ok=True)
    f=(OUT/'experiment_index.lock').open('a')
    fcntl.flock(f,fcntl.LOCK_EX)
    return f


def build_identity(source):
    return dict(hardware=source['hardware_sha256'],resources=source['restored_resource_sha256'],
        config=source['config'],svb_entries=source['n_svb_entries'],checker_harts=source['checker_harts'],
        trace=source.get('trace_enabled'),flags=['VERILATOR_THREADS=1','STAGE1_EXIT_PORTS','SAFE_CHAIN_EVENTS'],
        verilator_version=subprocess.check_output(['verilator','--version'],text=True).strip(),
        compiler_version=subprocess.check_output(['clang++','--version'],text=True).splitlines()[0])


def discover():
    records=[]
    for root in WORKTREES:
        area=root/'slowdown/parsec_evaluation_20261103'
        paths=list((area/'runs').glob('*/run_manifest.json'))+list((area/'build').glob('bfs_regression_*/run_manifest.json'))
        for p in paths:
            try:
                m=read(p);source=m.get('build_evidence',{}).get('source') or m.get('source')
                elf=m.get('elf_sha256');sim=m.get('simulator_sha256')
                # BFS manifests use source plus build-evidence revision seal.
                if not sim:sim=m.get('build_evidence',{}).get('revision',{}).get('simulator_sha256')
                software=m.get('software',{})
                software=software if isinstance(software,dict) else {}
                argv=m.get('command',[])
                settings=[a for a in argv[1:] if not a.startswith(('+loadmem=','+dramsim_ini_dir=')) and not a.endswith('.riscv')]
                swfile=p.parent/'test.riscv';lm=p.parent/'test.loadmem_hex'
                benchmark=('gapbs_bfs512_8192_source0' if p.parent.name.startswith('bfs_regression_') else p.parent.name.rsplit('_correction_',1)[0].rsplit('_native_',1)[0].rsplit('_check_',1)[0])
                identity=dict(hardware=source,simulator_sha256=sim,benchmark=benchmark,
                    design=m.get('design','correction'),elf_sha256=elf,loadmem_sha256=sha(lm) if lm.exists() else None,
                    workload_input=software,settings=settings,roi_scope=software.get('roi_scope','BFS_AMOW_plus_BFS_plus_STOP' if p.parent.name.startswith('bfs_regression_') else None),
                    seed=m.get('seed',1),capture_policy=m.get('profiling_capture_policy'))
                analysis=p.parent/'analysis.json';result=p.parent/'result.json'
                a=read(analysis) if analysis.exists() else read(result) if result.exists() else {}
                completed=m.get('exit_status') is not None
                status='COMPLETE' if completed and m['exit_status']==0 else 'FAILED' if completed else 'INCOMPLETE'
                correct=a.get('status')=='PASS' or (m.get('design') in ['native','check'] and m.get('software_correct') is True)
                metadata_complete=bool(source and sim and elf and swfile.exists() and lm.exists() and identity['roi_scope'])
                intact=bool(swfile.exists() and elf and sha(swfile)==elf)
                identity=m.get('experiment_cache_identity',identity)
                records.append(dict(key=digest(identity),identity=identity,run=str(p.parent),manifest_sha256=sha(p),
                    analysis_sha256=sha(analysis if analysis.exists() else result) if a else None,
                    status=status,correctness='PASS' if correct else 'UNKNOWN_OR_FAIL',
                    reusable=status=='COMPLETE' and correct and metadata_complete and intact,
                    roi_cycles=m.get('roi_cycles',a.get('ROI_cycles')),hardware_commit=m.get('canonical_hardware_commit'),
                    simulator_path=argv[0] if argv else None,identity_complete=metadata_complete))
            except (OSError,ValueError,KeyError,TypeError) as e:
                records.append(dict(run=str(p.parent),status='UNINDEXABLE',reason=str(e),reusable=False))
    builds=[]
    for root in WORKTREES:
        for p in (root/'slowdown/optimization_6_overlap/runs').glob('*/run_manifest.json'):
            try:
                m=read(p)
                if m.get('verilator_build')!='PASS':continue
                # Tool identity belongs to the historical build; do not invent it
                # from current PATH. Its logs and model hash remain authoritative.
                binary=root/'slowdown/optimization_6_overlap/build'/p.parent.name/'verilator/simulator-chipyard-v1Config'
                if binary.exists():builds.append(dict(hardware=m['source']['hardware_sha256'],config=m['source']['config'],manifest=str(p),simulator=str(binary),simulator_sha256=sha(binary)))
            except (OSError,ValueError,KeyError):continue
    old=read(INDEX) if INDEX.exists() else {}
    value=dict(schema=1,updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),runs=records,builds=builds,
        local_builds=old.get('local_builds',[]),launches=old.get('launches',[]),directed_tests=old.get('directed_tests',[]),
        policy='Exact identity AND valid complete actual artifacts required. An old revision never substitutes for new hardware. Incomplete entries never hit.')
    save(value);return value


def exact_run(expected):
    """Every behavior-affecting requested field must match, not just the name."""
    cache=discover()
    for r in cache['runs']:
        if r.get('reusable') and r['key']==digest(expected):
            p=Path(r['run'])/'run_manifest.json'
            analysis=p.parent/'analysis.json'
            if not analysis.exists():analysis=p.parent/'result.json'
            if sha(p)==r['manifest_sha256'] and sha(analysis)==r['analysis_sha256']:return r
    return None


if __name__=='__main__':
    argparse.ArgumentParser(description=__doc__).parse_args()
    with locked():
        x=discover();print(json.dumps(dict(index=str(INDEX),runs=len(x['runs']),reusable=sum(r.get('reusable',False)for r in x['runs']),builds=len(x['builds']))))
