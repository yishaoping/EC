#!/usr/bin/env python3
"""Optional common blackscholes payload on frozen B v5. Existing first boot remains unchanged."""
import argparse
import json
from pathlib import Path
import sys
import b_v5_first_run as b

WORK=b.KIT/'work/opt4-linux-v6'

def prepare(a):
    # Reuse every existing device/deployment guard. Only this optional plan's
    # firmware is selected here; no frozen B source or first-run file is edited.
    receipt=WORK/'B-software/firmware-build.json'
    fw=b.read(receipt);b.require(fw['returncode']==0 and fw['configuration']=='B-v5','B common-app firmware build absent')
    root=b.read(WORK/'B-software/rootfs-build.json');apps=b.read(WORK/'apps-build.json')
    b.require(root['apps_manifest_sha256']==b.sha(WORK/'apps-build.json'),'B/C4 app identity mismatch')
    b.require(b.sha(root['initramfs'])==root['sha256'],'B rootfs changed')
    kernel=b.read(fw['kernel_result'])
    b.require(kernel['input_files'].get(root['initramfs'])==root['sha256'],'B kernel/rootfs mismatch')
    expected_dtb=b.KIT/'images/software-v3/B-boot-20261102T083720.765499Z/B-boot.dtb'
    b.require(fw['input_files'].get(str(expected_dtb))==b.sha(expected_dtb),'B v5 software-visible DT changed')
    b.check_artifacts(fw['outputs'])
    b.FIRMWARE_RECEIPT=receipt
    b.prepare(a)
    p=a.out/'plan.json';plan=b.read(p)
    for f in [WORK/'apps-build.json',WORK/'B-software/rootfs-build.json',Path(root['initramfs']),Path(fw['kernel_result'])]:
        plan['artifacts'][str(f.resolve())]=b.sha(f)
    plan.update(optional_common_apps=True,common_apps_sha256=b.sha(WORK/'apps-build.json'),
        guest_mode=a.mode,guest_command='/opt/ec-dac/manual-link.sh '+a.mode,
        first_run_payload_unchanged=True,formal_sample=False,slowdown_pairing='requires valid C4 FireSim with same software/input/memory/frequency')
    p.write_text(json.dumps(plan,indent=2)+'\n')
    print('This optional payload guest command: '+plan['guest_command'])
    print('Shutdown: /bin/busybox sync; /bin/busybox poweroff -f')

def verify(a):
    d=a.run_dir;plan=b.read(d/'plan.json');b.check_artifacts(plan['artifacts'])
    b.require(plan.get('optional_common_apps') is True,'not the common app plan')
    console=(d/'console.log').read_text(errors='replace');raw=b.inspect_bytes((d/'roi-raw.jsonl').read_bytes())
    epochs=[e for e in raw['epochs'] if e['source_boundaries_complete']];issues=[]
    if raw['protocol_issues'] or raw['partial_tail_bytes'] or len(raw['epochs'])!=1 or len(epochs)!=1:issues.append('incomplete/invalid real ROI capture')
    if not (d/'started.json').exists() or b.read(d/'started.json')['plan_sha256']!=b.sha(d/'plan.json'):issues.append('unbound start')
    if plan['blockers'] or not plan['bitstream']:issues.append('bitstream not bound')
    if b.read(d/'exit.json')['returncode']!=0:issues.append('driver exit nonzero')
    success='EC_OPT4_LINUX_END mode='+plan['guest_mode']+' correctness=PASS application_exit=0'
    if console.count(success)!=1:issues.append('missing unique output/exit validation')
    if plan['common_apps_sha256']+'  BUILD.json' not in console:issues.append('software mismatch')
    if 'EC_DAC_ROI_OBSERVER_FAILED' in console or 'EC_OPT4_INVALID' in console:issues.append('invalid hardware capture')
    result={'valid':not issues,'issues':issues,'configuration':'B-v5','roi_cycles':epochs[0]['roi_cycles'] if len(epochs)==1 else None,
        'generated':0,'completed':0,'checker_latency':None,'runtime_validation':'PASS' if not issues else 'INVALID',
        'formal_sample':False,'scope':'B common app capture only; C4 FireSim pairing still required',
        'plan_sha256':b.sha(d/'plan.json'),'raw_sha256':b.sha(d/'roi-raw.jsonl'),'console_sha256':b.sha(d/'console.log')}
    b.save(a.out,result);print(json.dumps(result,indent=2));return 0 if not issues else 1

def main():
    p=argparse.ArgumentParser(description=__doc__);s=p.add_subparsers(dest='action',required=True)
    a=s.add_parser('prepare');a.add_argument('--bdf',required=True);a.add_argument('--out',required=True,type=Path)
    a.add_argument('--bitstream-result',type=Path);a.add_argument('--mode',choices=['smoke','test','simsmall'],default='test')
    a=s.add_parser('run');a.add_argument('--plan',required=True,type=Path);a.add_argument('--deployment-record',required=True,type=Path)
    a=s.add_parser('verify');a.add_argument('--run-dir',required=True,type=Path);a.add_argument('--out',required=True,type=Path)
    args=p.parse_args()
    return {'prepare':prepare,'run':b.run,'verify':verify}[args.action](args) or 0
if __name__=='__main__':sys.exit(main())
