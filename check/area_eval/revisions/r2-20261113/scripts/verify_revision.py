#!/usr/bin/env python3
"""Read-only verification of old inputs and the new analytical deliverables."""
from pathlib import Path
import ast,csv,hashlib,json,re,datetime

R=Path(__file__).resolve().parents[1]
B=R.parents[3]
def digest(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for chunk in iter(lambda:f.read(1024*1024),b''): h.update(chunk)
    return h.hexdigest()

old=json.loads((R/'evidence/previous-artifacts-before.json').read_text())
old_bad=[p for p,h in old.items() if not (B/p).is_file() or digest(B/p)!=h]
inputs=json.loads((R/'evidence/input-manifest.json').read_text())
input_bad=[p for p,h in inputs.items() if not (B/p).is_file() or digest(B/p)!=h['sha256']]
assert not old_bad and not input_bad, (old_bad,input_bad)
preservation={'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
 'old_area_eval_files_checked':len(old),'old_area_eval_changed_or_missing':old_bad,
 'additional_input_files_checked':len(inputs),'additional_input_changed_or_missing':input_bad,
 'original_source_and_generated_checks':'See provenance-checks.json (870 + 746 files)',
 'status':'PASS'}
(R/'evidence/preservation-check.json').write_text(json.dumps(preservation,indent=2)+'\n')

for p in (R/'scripts').glob('*.py'): ast.parse(p.read_text(),filename=str(p))
profiles=json.loads((R/'config/matched_profiles.json').read_text())
assert len(profiles)==3 and all(p['geometry']==profiles[0]['geometry'] for p in profiles)
assert all(p['area_boundary']==profiles[0]['area_boundary'] for p in profiles)
assert all(p['area_mm2'] is None for p in profiles)
assert [p['LSL_payload_bits_per_checker'] for p in profiles]==[0,66300,66300]
summary=json.loads((R/'results/area_summary.json').read_text())
module_rows=list(csv.DictReader((R/'results/module_area.csv').open()))
for seq in (16,32):
    rows=[row for row in module_rows if int(row['sequence_bits'])==seq]
    case=summary['cases'][f'seq{seq}']
    assert sum(int(row['RAM_bits']) for row in rows)==case['RAM_bits']
    assert sum(int(row['DFF_bits']) for row in rows)==case['DFF_bits']
    assert sum(float(row['GE_excluding_RAM']) for row in rows)==case['GE_excluding_RAM']
    for label in ('low','typical','high'):
        assert abs(sum(float(row[label+'_mm2_model']) for row in rows)-case['primitive_subtotal_mm2_model'][label])<1e-12
    syn=json.loads((R/f'results/synthesis/seq{seq}/summary.json').read_text())
    assert len(syn)==13
    for name,info in syn.items():
        assert info['rtl_sha256']==digest(R.parents[1]/'rtl/palimpsest.sv')
        assert info['area_mm2'] is None and info['critical_path_ns'] is None
        log=(R/f'results/synthesis/seq{seq}/{name}/gates.log').read_text()
        assert 'Found and reported 0 problems.' in log
ports=json.loads((R/'results/memory_port_audit.json').read_text())
assert [p['after']['WR_PORTS'] for p in ports]==[1,1]
assert json.loads((R/'results/limits-test.json').read_text())['status'].startswith('PASS_')

bad_links=[]; checked=0
for p in [R/'README.md',*(R/'reports').glob('*.md')]:
    for target in re.findall(r'\]\((/[^)]+)\)',p.read_text()):
        path,_,line=target.rpartition(':')
        q=Path(path if line.isdigit() else target)
        if not q.is_file(): bad_links.append((str(p),target,'missing'))
        elif line.isdigit() and int(line)>len(q.read_text().splitlines()):
            bad_links.append((str(p),target,'line out of bounds'))
        checked+=1
assert not bad_links,bad_links
result={'status':'PASS','preservation':preservation,
 'checks':['Python syntax','old arithmetic reproduction','three matched declarative geometries and boundaries',
 'module counts and area column sums','26 generic synthesis check logs','RAM write-port sharing',
 'finite identity characterization','Markdown evidence target existence and line bounds'],
 'markdown_links_checked':checked,'whole_system_verification':False,'PDK_mapping':False}
(R/'results/verification.json').write_text(json.dumps(result,indent=2)+'\n')
manifest={str(p.relative_to(R)):digest(p) for p in sorted(R.rglob('*'))
          if p.is_file() and p.name!='deliverable-sha256.json'}
(R/'results/deliverable-sha256.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps({'status':'PASS','preserved_old_files':len(old),'checked_inputs':len(inputs),
                  'generic_shapes':26,'evidence_links_checked':checked,
                  'deliverable_files':len(manifest)},indent=2))
