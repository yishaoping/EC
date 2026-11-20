#!/usr/bin/env python3
"""Verify evidence snapshots, arithmetic and references; no hardware execution."""
from pathlib import Path
from datetime import datetime, timezone
import csv
import hashlib
import json
import re

ROOT = Path(__file__).resolve().parents[1]

def sha(p):
    h = hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda:f.read(8*1024*1024),b''):
            h.update(chunk)
    return h.hexdigest()

def main():
    checked=[]
    for manifest in ['source_manifest.json','context_manifest.json']:
        j=json.loads((ROOT/'evidence'/manifest).read_text())
        for row in j['files']:
            p=ROOT/row['saved']
            assert sha(p)==row['sha256'],p
            checked.append(row['saved'])
    data=json.loads((ROOT/'results/extracted.json').read_text())
    post=data['area_breakdown_postopt']
    expected={'LUT':1023687,'register':1019173,'RAMB36':658,'RAMB18':41,'URAM':0,'DSP':115}
    for k,v in expected.items():
        assert sum(r[k] for r in post)==v,(k,v)
    assert sum(r['BRAM36_equivalent'] for r in post)==678.5
    byname={r['group']:r for r in post}
    assert byname['svb']['LUT']==64699 and byname['lsl']['LUT']==15172
    assert abs(sum(r['LUT_percent_of_total'] for r in post)-100)<1e-9
    with (ROOT/'results/hierarchy_exclusive_postopt.csv').open() as f:
        residuals=list(csv.DictReader(f))
    negative=sum(r['negative_LUT_sharing_residual']=='True' for r in residuals)
    primary=json.loads((ROOT/'raw/r6/postopt-result.json').read_text())
    assert sha(ROOT/'raw/r6/top-postopt-utilization.rpt')==primary['utilization_sha256']
    assert sha(ROOT/'raw/r6/top-postopt-hierarchical.rpt')==primary['hierarchy_sha256']
    assert primary['postopt_capacity_fit'] and not primary['physical_fit'] and not primary['full_PALIMPSEST']
    revision=json.loads((ROOT/'evidence/revision_verification.json').read_text())
    assert revision['r6_generated_rtl_matches_cad_receipt'] and revision['all_bound_scala_sources_match']
    assert not revision['hardware_diff_6fada307_to_checkout_HEAD'] and not revision['hardware_worktree_status']
    links=re.findall(r'\]\(([^)]+)\)',(ROOT/'README.md').read_text())
    for link in links:
        m=re.match(r'^(.*?):(\d+)$',link)
        path=ROOT/(m[1] if m else link)
        assert path.exists(),link
        if m:
            assert int(m[2])<=len(path.read_text().splitlines()),link
    for p in data['powers']:
        total=float(p['total_W']['value']);dynamic=float(p['dynamic_W']['value']);static=float(p['static_W']['value'])
        assert abs(total-dynamic-static)<0.003,(p['stage'],total,dynamic,static)
        assert p['activity_file']['value']=='---'
    table=(ROOT/'latex/hardware_overhead_table.tex').read_text()
    assert table.count(r'\begin{')==table.count(r'\end{')
    complete=(ROOT/'generated/placed/reporting.complete').exists()
    primary_power=(ROOT/'generated/placed/power_vectorless.rpt').exists() and 'report_power completed successfully' in (ROOT/'generated/placed/console.log').read_text()
    if primary_power:
        invocation=json.loads((ROOT/'generated/placed/invocation.json').read_text())
        assert invocation.get('ended_utc'), 'Wait for private report process to exit before sealing logs'
        if not complete:
            stopped=json.loads((ROOT/'generated/placed/optional_advisory_stop.json').read_text())
            assert stopped['primary_report_power_completed'] and not stopped['preexisting_CAD_processes_signalled']
        original=data['utilization']['full_shell_placed']['rows']
        generated=__import__('extract_results').utilization(ROOT/'generated/placed/utilization.rpt')['rows']
        for k in ['CLB LUTs','CLB Registers','Block RAM Tile','CARRY8','DSPs','URAM']:
            assert original[k]['used']==generated[k]['used'],k
        assert data['area_breakdown_placed'] is not None
        with (ROOT/'results/power_hierarchy_placed_vectorless.csv').open() as f:
            prows=list(csv.DictReader(f))
        assert prows[0]['path']=='design_1_wrapper' and prows[0]['dynamic_W_as_reported']=='11.918'
    tcl=(ROOT/'scripts/report_preroute_power.tcl').read_text()
    assert not re.search(r'^\s*(synth_design|opt_design|place_design|phys_opt_design|route_design|write_checkpoint|open_project)\b',tcl,re.M)
    verification={'verified_utc':datetime.now(timezone.utc).isoformat(),'snapshots_SHA256_verified':len(checked),'postopt_group_sums_exact':True,'BRAM_half_tile_accounting_verified':True,'negative_LUT_sharing_residuals_preserved':negative,'source_revision_and_generated_RTL_verified':True,'markdown_links_verified':len(links),'power_values_reconcile_at_report_precision':True,'placed_primary_report_power_complete':primary_power,'all_optional_reports_complete':complete,'optional_advisory_note':'Task-owned supplementary advisory stopped after primary report success; wrapper 143 preserved; preexisting CAD untouched.','new_synthesis_place_or_route_launched':False,'RTL_modified':False,'strict_PEEK_or_ParaMedic_incremental_overhead_claimed':False,'LaTeX_compiled':False,'LaTeX_note':'No TeX compiler present; environments and generated resource values checked.'}
    (ROOT/'results/verification.json').write_text(json.dumps(verification,indent=2)+'\n')
    artifacts=[]
    for p in sorted(ROOT.rglob('*')):
        if not p.is_file() or p.name=='artifact_manifest.json' or any(s in p.parts for s in ['.Xil','tmp','__pycache__']):
            continue
        artifacts.append({'path':str(p.relative_to(ROOT)),'bytes':p.stat().st_size,'sha256':sha(p)})
    (ROOT/'evidence/artifact_manifest.json').write_text(json.dumps({'verified_utc':verification['verified_utc'],'files':artifacts},indent=2)+'\n')
    print(json.dumps(verification,indent=2))

if __name__=='__main__':
    main()
