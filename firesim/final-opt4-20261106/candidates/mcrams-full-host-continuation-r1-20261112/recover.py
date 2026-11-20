#!/usr/bin/python3
"""Read-only report recovery first; reuse completed DCP, never rerun DUT synth."""
import importlib.util,json,pathlib,sys
C=pathlib.Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('continuation',C/'continue.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
A=m.AREA;out=m.O/'recovered-capacity.json'
assert not m.live(m.read(m.D/'Opt4-mcrams-full-host-capacity-r1-state.json'))
assert not m.live(m.read(m.D/'Opt4-mcrams-full-host-capacity-r1-state.json').get('child',{}))
s=importlib.util.spec_from_file_location('reports',m.W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py');p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
if (A/'postopt-utilization.rpt').exists() and (A/'postopt.dcp').exists():
 totals=p.parse_total((A/'postopt-utilization.rpt').read_text());p.parse_hier((A/'postopt-hierarchical.rpt').read_text(),totals);p.crosschecks((A/'postopt-utilization.rpt').read_text(),totals)
 r=dict(status='RECOVERED_ACTUAL_POSTOPT_REPORTS_NO_RESYNTHESIS',resources={k:v['used'] for k,v in totals.items()},capacities={k:v['available'] for k,v in totals.items()},checkpoint=str(A/'postopt.dcp'),evidence_sha256={str(x):m.sha(x) for x in [A/'postopt-utilization.rpt',A/'postopt-hierarchical.rpt']},full_physical_fit=False,fpga_access=False)
elif (A/'synth.dcp').exists():
 r=dict(status='SYNTH_CHECKPOINT_PRESERVED_OPT_RECOVERY_REQUIRED',checkpoint=str(A/'synth.dcp'),fpga_access=False,automatic_resynthesis=False)
else:
 r=dict(status='NO_COMPLETED_CHECKPOINT_PRESERVED_REAL_TOOL_FAILURE_REQUIRES_AUTONOMOUS_DIAGNOSIS',failure=m.read(A/'failure.json'),log=str(A/'run.log'),fpga_access=False,automatic_resynthesis=False)
if out.exists():assert m.read(out)==r
else:m.save(out,r)
print(r['status'])
