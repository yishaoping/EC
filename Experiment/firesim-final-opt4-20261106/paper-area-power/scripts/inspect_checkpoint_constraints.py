#!/usr/bin/env python3
"""Inspect XDC members in archived DCP ZIPs without running Vivado."""
from pathlib import Path
import hashlib
import json
import re
import zipfile

ROOT = Path(__file__).resolve().parents[1]

def main():
    stages=[]
    for stage in ['placed','routed']:
        p=ROOT/'checkpoints'/f'design_1_wrapper_{stage}.dcp'
        findings=[];members=[]
        with zipfile.ZipFile(p) as z:
            for item in z.infolist():
                if not item.filename.endswith('.xdc'):
                    continue
                data=z.read(item)
                dst=ROOT/'raw/r6/checkpoint_constraints'/stage/Path(item.filename).name
                dst.parent.mkdir(parents=True,exist_ok=True)
                dst.write_bytes(data)
                members.append({'entry':item.filename,'saved':str(dst.relative_to(ROOT)),'sha256':hashlib.sha256(data).hexdigest()})
                scope=''
                for n,s in enumerate(data.decode(errors='replace').splitlines(),1):
                    if s.startswith('current_instance '):
                        scope=s
                    if re.search(r'set_switching_activity|read_saif|read_vcd|default_toggle|static_probability',s,re.I):
                        findings.append({'saved':str(dst.relative_to(ROOT)),'line':n,'instance_scope':scope,'text':s})
        stages.append({'checkpoint':str(p.relative_to(ROOT)),'members':members,'activity_commands_found':findings})
    result={'stages':stages,'interpretation':'Checkpoint XDCs include IP-scoped reset activity constraints. No workload SAIF/VCD is recorded in report_power. These constraints do not establish built-in numeric defaults for unannotated target nets.'}
    (ROOT/'evidence/checkpoint_activity_constraints.json').write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps({'xdc_members':sum(len(s['members']) for s in stages),'activity_commands':sum(len(s['activity_commands_found']) for s in stages)}))

if __name__=='__main__':
    main()
