#!/usr/bin/env python3
"""Check deterministic architectural repeatability, independently of host cost."""
import json
from pathlib import Path
OUT=Path(__file__).resolve().parents[1]
def main():
    pairs=json.loads((OUT/'repeat_selection.json').read_text());reports=[]
    for label,ids in pairs.items():
        manifests=[json.loads((OUT/'runs'/rid/'run_manifest.json').read_text())for rid in ids]
        analyses=[json.loads((OUT/'runs'/rid/'analysis.json').read_text())for rid in ids]
        assert len(ids)>=2
        keys=['design','elf_sha256','simulator_sha256','canonical_hardware_commit','seed','roi_instret','output']
        same=all(len({json.dumps(m.get(k),sort_keys=True)for m in manifests})==1 for k in keys)
        valid=same and all(a['status']=='PASS'for a in analyses) and all(m.get('evaluation_git_status')==''for m in manifests)
        cycles=[m['roi_cycles']for m in manifests];reports.append({'case':label,'runs':ids,'work_and_model_identical':same,'validated':valid,'ROI_cycles':cycles,'deterministic_cycles':len(set(cycles))==1,'host_wall_seconds_simulation_cost':[m['host_wall_seconds']for m in manifests]})
    status='PASS'if reports and all(r['validated']and r['deterministic_cycles']for r in reports)else'FAIL'
    (OUT/'counters/repeatability.json').write_text(json.dumps({'status':status,'cases':reports,'scope':'Seed 1 deterministic target cycles; host time is operational cost, not hardware variation'},indent=2)+'\n');print(status);return status!='PASS'
if __name__=='__main__':raise SystemExit(main())
