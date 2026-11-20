#!/usr/bin/python3
"""Actual saved report parser crosschecks; no synthesis or FPGA IO."""
import copy,importlib.util,json,pathlib,re
C=pathlib.Path(__file__).resolve().parent
s=importlib.util.spec_from_file_location('area_parser',C/'resource_parser.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
D=pathlib.Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');out={}
for label,path in [('nonzero',D/'build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/PlainConfig'),('zero',D/'build-logs/Opt4-mcrams-owner-generated-area-r1-20261111')]:
 u=(path/'utilization.rpt').read_text();h=(path/'hierarchical.rpt').read_text()
 if label=='zero':
  h=h.replace('ownerImageMemory_flattened','FPGATop');u=re.sub(r'(^\| Design\s+:) ownerImageMemory_flattened',r'\1 FPGATop',u,flags=re.M)
 t=m.parse_total(u)
 m.parse_hier(h,t);m.crosschecks(u,t)
 assert t['CLB LUTs']['used']>0
 bad=copy.deepcopy(t);bad['CARRY8']['used']+=1;assert m.rejected(lambda:m.crosschecks(u,bad))
 bad=copy.deepcopy(t);bad['CLB LUTs']['used']+=1;assert m.rejected(lambda:m.parse_hier(h,bad))
 line=next(x for x in u.splitlines() if re.match(r'^\|\s*CLB LUTs\*?\s*\|',x));assert m.rejected(lambda:m.parse_total(u.replace(line,line+'\n'+line)))
 assert m.rejected(lambda:m.parse_total(u.replace(line,line.replace('1303680','1303679'))))
 if label=='zero':assert t['CARRY8']['used']==0
 out[label]=dict(actual_LUT=t['CLB LUTs']['used'],actual_CARRY8=t['CARRY8']['used'],zero_primitive_omission_supported=label=='zero',missing_nonzero_or_primitive_disagreement_rejected=True,hierarchy_disagreement_rejected=True,duplicate_total_rejected=True,wrong_capacity_rejected=True)
print(json.dumps(dict(status='PASS_ACTUAL_ZERO_NONZERO_REPORT_AND_MUTATION_PREFLIGHT',results=out,fpga_access=False),indent=2))
