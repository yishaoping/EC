#!/usr/bin/env python3
"""Prepare a working future diagnostic child without changing any live sample."""
import datetime as dt
import fcntl
import json
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha


def main():
    output=D/'software/fluidanimate-capture-transport-repair.json'
    old=json.loads(output.read_text()) if output.exists() else {}
    if old.get('status')=='COMPLETE_FUTURE_DIAGNOSTIC_BOUND':return
    profile='fluidanimate-diagnostic-v2'
    oldapps=W/'software/fluidanimate-diagnostic-apps-build.json'
    newapps=W/f'software/{profile}-apps-build.json'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    state=dict(status='PREPARING_PRIVATE_DIAGNOSTIC',application_elf_unchanged=True,input_unchanged=True,
               roi_unchanged=True,formal_eligible=False,transport='existing busybox uuencode -m with header/trailer removed')
    save(output,state)
    if not newapps.exists():
        apps=json.loads(oldapps.read_text());apps.update(software_profile='fluidanimate-unchanged-app-failed-output-capture-v2',
            transport_revision='busybox-uuencode-m-v2',reused_diagnostic_receipt=str(oldapps),reused_diagnostic_receipt_sha256=sha(oldapps))
        save(newapps,apps)
    subprocess.run(['python3',W/'scripts/prepare_profile_system.py',profile],check=True)
    # These aliases are resolved only when the waiting repair worker reaches
    # its future diagnostic child. No apps/rootfs/image bytes are overwritten.
    job=json.loads((D/'idle-repairs-state.json').read_text())
    assert job['status']=='WAITING_EXISTING_NATIVE_QUEUE_IDLE',job
    active=json.loads((D/'active-0000_e2_00.0.json').read_text());assert active.get('program')=='freqmine',active
    assert not list((D/'runs').glob('native-fluidanimate-*-*/diagnostic-output-analysis.json'))
    history=D/'software'/('fluidanimate-capture-transport-repair-'+stamp);history.mkdir()
    bindings={}
    for suffix in ['apps','rootfs']:
        target=W/f'software/fluidanimate-diagnostic-{suffix}-build.json'
        source=W/f'software/{profile}-{suffix}-build.json'
        save(history/target.name,json.loads(target.read_text()));save(target,json.loads(source.read_text()))
        bindings[str(target)]=dict(source=str(source),sha256=sha(target))
    for cfg in ['Native','C4']:
        target=W/f'software/{cfg}/fluidanimate-diagnostic-firmware-build.json';source=W/f'software/{cfg}/{profile}-firmware-build.json'
        save(history/(cfg+'-'+target.name),json.loads(target.read_text()));save(target,json.loads(source.read_text()))
        bindings[str(target)]=dict(source=str(source),sha256=sha(target))
    state.update(status='COMPLETE_FUTURE_DIAGNOSTIC_BOUND',bindings=bindings,history=str(history),
                 unchanged_active_run=active['run_dir'],no_live_sample_inputs_modified=True)
    save(output,state);print(json.dumps(state),flush=True)


if __name__=='__main__':main()
