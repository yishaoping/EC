#!/usr/bin/env python3
from opt4_unattended_common import *
from summarize_c4_capacity import utilization
records=[]
for state,key in [('Opt4-fit-address-round3-state.json','full_address_map'),('Opt4-fit-address-sort-state.json','full_module_map'),('Opt4-fit-address-heap-candidate-state.json','full_module_map')]:
 x=read(D/state);m=x.get(key)
 if not m:
  records.append(dict(state=state,status=x.get('status'),resources_available=False));continue
 assert sha(m['report'])==m['report_sha256']
 records.append(dict(state=state,status=x['status'],hardware_commit=x.get('hardware_commit') or x.get('fit_commit'),resources=m['resources'],report=m['report'],report_sha256=m['report_sha256'],resources_available=True,scope='MODULE_OOC_NOT_SYSTEM_FIT'))
whole=read(D/'Opt4-fit-cad-state.json')
save(U/'resource-audit-first-job.json',dict(schema='ec-opt4-resource-audit/1',utc=now(),modules=records,whole_system_status=whole.get('status'),whole_system_resources=whole.get('top_postopt_resources'),fit_inferred_from_modules=False,fpga_access=False))
print(json.dumps(dict(modules=records,whole_system_status=whole.get('status')),sort_keys=True))
