#!/usr/bin/env python3
"""Seal a successful candidate build without changing any existing revision."""
import argparse,gzip,json,subprocess
from pathlib import Path
from run_pilot import ROOT,OUT,sha,dump
def main():
    p=argparse.ArgumentParser();p.add_argument('build_id');p.add_argument('--tag',required=True);a=p.parse_args()
    base=ROOT/'slowdown/optimization_6_overlap';manifest=base/'runs'/a.build_id/'run_manifest.json';m=json.loads(manifest.read_text())
    assert m['hardware_generation']=='PASS' and m['verilator_build']=='PASS'
    for group in ['hardware_sha256','restored_resource_sha256']:
        for rel,h in m['source'][group].items():assert sha(ROOT/rel)==h,rel
    build=base/'build'/a.build_id;sim=build/'verilator/simulator-chipyard-v1Config'
    commit=m['source']['git_head'];assert subprocess.check_output(['git','show',commit+':chipyard/generators/boom/src/main/scala/lsu/dcache.scala'],cwd=ROOT)==(ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala').read_bytes()
    dest=OUT/'revisions'/commit[:9];dest.mkdir(parents=True,exist_ok=False)
    for src in [manifest,base/'runs'/a.build_id/'source.patch',build/'rtl_generation.log',build/'verilator_build.log']:
        compressed=src.suffix=='.log';data=gzip.compress(src.read_bytes(),mtime=0)if compressed else src.read_bytes();(dest/(src.name+('.gz'if compressed else''))).write_bytes(data)
    sealed=dest/'run_manifest.json'
    r={'status':'CANDIDATE','canonical_hardware_commit':commit,'proposed_tag':a.tag,'parent_hardware_revision':'1532923803d7451b0c7843e9abad1c90ef9eb9ed','build_id':a.build_id,'build_manifest':str(sealed.relative_to(ROOT)),'build_manifest_sha256':sha(sealed),'simulator':str(sim.relative_to(ROOT)),'simulator_sha256':sha(sim),'emitted_DCache_sha256':sha(build/'generated/gen-collateral/BoomNonBlockingDCache.sv'),'acceptance_required':['GAPBS BFS','Blackscholes simdev','Streamcluster simdev'],'scope':'Correctness repair only; no performance optimization'}
    dump(dest/'revision.json',r);print(dest/'revision.json')
if __name__=='__main__':main()
