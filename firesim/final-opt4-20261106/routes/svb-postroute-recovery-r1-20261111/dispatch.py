#!/usr/bin/python3
"""Five-minute deterministic failed-physical-stage dispatcher; no board I/O."""
import fcntl
import importlib.util
import os
from pathlib import Path
import subprocess
import sys

C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('physical_recovery',C/'run.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
ROOT=m.OUTPUT
UNITS={(p,mode):f'ec-opt4-svb-recovery-{p}-{mode}-r1.service'
       for p in ['original','spread'] for mode in ['postroute','replicate']}


def main():
    assert os.geteuid()==0
    ROOT.mkdir(exist_ok=True)
    lock=(ROOT/'dispatcher.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    pins=m.read(C/'inputs.json')
    for p,h in pins['files'].items():assert m.sha(p)==h,('changed dispatcher input',p)
    policy=m.read(m.D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit']==m.BASE and policy['area_equivalence_only']
    assert policy['native_paused'] and policy['board_allowlist']==['0000:21:00.0']
    status=dict(schema='ec-original-svb-recovery-dispatch/1',**m.identity(),updated_utc=m.now(),
                fpga_access=False,source_id=m.SID,functional_baseline=m.BASE)
    # All recovery outputs are independent and immutable. Never rerun a failed
    # stage, and never let separate timer invocations start concurrent repairs.
    for (producer,mode),unit in UNITS.items():
        root=ROOT/(producer+'-'+mode)
        row=m.read(root/'state.json')
        if m.live(row) or m.live(row.get('child',{})) or m.unit_active(unit) in ['active','activating']:
            status.update(status='ADOPT_LIVE_RECOVERY',unit=unit,run_directory=str(root))
            m.save(ROOT/'dispatch-state.json',status);return
        result=m.read(root/'result.json')
        if result.get('status')=='BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION':
            assert m.read(root/'complete.json')['result_sha256']==m.sha(root/'result.json')
            assert result['functional_baseline']==m.BASE and result['source_id']==m.SID
            assert all(m.sha(p)==h for p,h in result['outputs'].items())
            choice=dict(result=str(root/'result.json'),result_sha256=m.sha(root/'result.json'),
                        source_id=m.SID,functional_baseline=m.BASE,chosen_utc=m.now(),fpga_access=False)
            old=m.read(ROOT/'chosen-physical-result.json')
            if old:assert old['result_sha256']==choice['result_sha256']
            else:m.save(ROOT/'chosen-physical-result.json',choice)
            status.update(status='RECOVERED_RESULT_HANDED_TO_INDEPENDENT_CERTIFICATION',result=choice['result'])
            m.save(ROOT/'dispatch-state.json',status);return
    if any((m.D/n/'complete.json').exists() for n in [
           'cycleprecise-original-svb-onboard-r1-20261111',
           'cycleprecise-original-svb-spread-onboard-r2-20261111']):
        status.update(status='EXISTING_COMPONENT_MEASUREMENT_WINS_NO_NEW_RECOVERY')
        m.save(ROOT/'dispatch-state.json',status);return
    priority=m.read(m.D/'Opt4-fit-runtime-priority.json')
    if priority.get('status') in ['ACTIVE','REQUESTED_AT_SAFE_BOUNDARY']:
        status.update(status='WAIT_FULL_OPT4_PRIORITY');m.save(ROOT/'dispatch-state.json',status);return
    checks=[]
    seen=set()
    for producer in ['spread','original']:
        for mode in ['postroute','replicate']:
            root=ROOT/(producer+'-'+mode)
            if (root/'state.json').exists():continue
            row=m.eligibility(producer,mode);checks.append(row)
            if not row['eligible']:continue
            checkpoint=m.Path(row['checkpoint']);fingerprint=m.sha(checkpoint)
            # Identical sealed DCP/mode evidence is only attempted once.
            for p in ROOT.glob('*/sealed-inputs.json'):
                previous=m.read(p)
                if previous.get('checkpoint_sha256')==fingerprint and previous.get('mode')==mode:
                    seen.add((mode,fingerprint))
            if (mode,fingerprint) in seen:continue
            unit=UNITS[producer,mode]
            subprocess.run(['systemctl','start',unit],check=True)
            status.update(status='SUBMITTED_REPLACEMENT_AFTER_PRODUCER_FAILURE',unit=unit,
                          producer=producer,mode=mode,checkpoint_sha256=fingerprint,checks=checks)
            m.save(ROOT/'dispatch-state.json',status);return
    status.update(status='WAITING_LIVE_PHYSICAL_PRODUCERS_OR_NO_NEW_SAFE_CANDIDATE',checks=checks)
    m.save(ROOT/'dispatch-state.json',status)


if __name__=='__main__':main()
