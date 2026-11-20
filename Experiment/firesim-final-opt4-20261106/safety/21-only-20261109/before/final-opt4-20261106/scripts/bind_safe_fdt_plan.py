#!/usr/bin/env python3
"""Bind already prepared software at future program boundaries only."""
import datetime as dt
import json
from board_batch import W,D,save,sha


def main():
    path=D/'suite-execution-plan.json'
    plan=json.loads(path.read_text())
    queue=json.loads((D/'suite-native-queue-state.json').read_text())
    active=json.loads((D/'active-0000_e2_00.0.json').read_text())
    updates={'dedup':'dedup-staged-safe-fdt','facesim':'facesim-staged-resident-safe-fdt',
             'ferret':'ferret-safe-fdt','raytrace':'raytrace-headless-safe-fdt'}
    assert queue['stage']=='freqmine-formal3',queue['stage']
    assert all(queue['tasks'].get(name,{}).get('status')!='RUNNING' for name in updates)
    assert 'freqmine' in active['run_dir']
    before_active=sha(D/'active-0000_e2_00.0.json')
    before_plan=sha(path)
    for name,profile in updates.items():
        diagnostic=json.loads((D/f'software/{profile}-boot-diagnostic.json').read_text())
        assert diagnostic['qemu_integrity_passed'] and not diagnostic['kernel_panic']
        for cfg in ['Native','C4']:
            fw=json.loads((W/f'software/{cfg}/{profile}-firmware-build.json').read_text())
            assert fw['returncode']==0 and fw['content_checks']['runtime_memory_layout']['no_overlap']
        for task in plan['programs']:
            if task['program']==name:task['software_profile_prefix']=profile
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    history=D/'plan-history';history.mkdir(exist_ok=True)
    save(history/f'before-safe-fdt-{stamp}.json',json.loads(path.read_text()))
    save(path,plan)
    receipt=dict(schema='ec-future-plan-update/1',updated_utc=stamp,
        old_sha256=before_plan,new_sha256=sha(path),profiles=updates,
        observed_active_run=active['run_dir'],observed_active_state_sha256=before_active,
        queue_stage=queue['stage'],active_sample_inputs_modified=False,
        application_kernel_rootfs_rebuilt=False,firmware_only=True,fpga_validation='NOT_RUN',
        dedup_retry='FAILED remains retained; supplement only at idle boundary, no active queue restart')
    output=history/f'safe-fdt-{stamp}-receipt.json';save(output,receipt)
    print(json.dumps(dict(updated_future_profiles=updates,unchanged_active_run=active['run_dir'],receipt=str(output))))


if __name__=='__main__':main()
