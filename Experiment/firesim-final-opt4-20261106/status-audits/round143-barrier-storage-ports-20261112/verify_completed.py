#!/usr/bin/python3
"""Seal completed port audit without modifying any live/pinned inputs."""
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess

A = Path(__file__).resolve().parent
D = A.parent.parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
C = W/'candidates/barrier-storage-port-audit-r143-v1-20261112'
O = D/'build-logs/Opt4-barrier-storage-port-audit-r143-v1-20261112'
U = D/'unattended-opt4'
NAME = 'barrier-storage-ports-r143-v1-8491167d'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def put(name, value):
    text = json.dumps(value, indent=2, sort_keys=True)+'\n'
    with (A/name).open('x') as f:
        f.write(text)
        f.flush()
        os.fsync(f.fileno())


def main():
    result = read(O/'result.json')
    assert result['status']=='PASS_ACTUAL_GOLDENGATE_STORAGE_PORT_INVENTORY_NOT_PARITY_OR_AREA'
    assert result['data_widths']==[160] and result['logical_payload_bits']==40960
    assert result['extracted_ports']==dict(ModelReadPort=256,ModelWritePort=1,ModelReadWritePort=0)
    assert not result['full_module_parity'] and result['area_saving_unknown']
    assert not any(result[k] for k in ['fpga_access','full_host_synthesis','production_admission'])
    assert sha(C/'inputs.json')==result['inputs_sha256']
    assert all(sha(p)==h for p,h in read(C/'inputs.json')['files'].items())
    assert all(sha(p)==h for p,h in result['outputs'].items())
    stages = {}
    for path in sorted(O.glob('*-receipt.json')):
        receipt = read(path)
        assert receipt['returncode']==0 and not receipt['missing_outputs']
        assert sha(receipt['log'])==receipt['log_sha256']
        assert all(sha(p)==h for p,h in receipt['outputs'].items())
        stages[path.name] = dict(path=str(path), sha256=sha(path),
            log_sha256=receipt['log_sha256'], wall_seconds=receipt['wall_seconds'])
    assert len(stages)==3
    job = read(U/'jobs'/NAME/'state.json')
    assert job['status']=='COMPLETE' and job['returncode']==0 and not job['missing_outputs']
    assert job['outputs'][str(O/'result.json')]==sha(O/'result.json')
    unit = 'ec-opt4-auto-'+NAME+'.service'
    show = subprocess.check_output(['systemctl','show',unit,'--no-pager',
        '-p','ActiveState','-p','SubState','-p','MainPID','-p','ControlGroup','-p','Result',
        '-p','ExecMainStatus'],text=True)
    service = dict(line.split('=',1) for line in show.splitlines())
    assert service['MainPID']=='0' and service['ActiveState']=='inactive'
    assert service['Result']=='success' and service['ExecMainStatus']=='0'
    expected = '/system.slice/'+unit
    cgroups = {}
    for root in ['/sys/fs/cgroup/systemd','/sys/fs/cgroup/unified','/sys/fs/cgroup']:
        path = Path(root+expected+'/cgroup.procs')
        members = path.read_text().split() if path.exists() else []
        assert not members, ('Unexpected surviving exact cgroup',path,members)
        cgroups[str(path)] = dict(exists=path.exists(), members=members)
    put('barrier-port-acceptance.json', dict(
        utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        status='PASS_COMPLETE_SOURCE_BOUND_GOLDENGATE_PORT_INVENTORY',
        source_sha256=result['source_sha256'], result=str(O/'result.json'),
        result_sha256=sha(O/'result.json'), inputs_sha256=result['inputs_sha256'],
        actual_memory=dict(name='payload_flattened',depth=256,width=160,
            read_ports=256,write_ports=1,readwrite_ports=0,read_latency=0,write_latency=1),
        stages=stages, generated_artifacts=result['outputs'],
        service=service, expected_cgroup=expected, exact_cgroup_closure=cgroups,
        historical_controller_identity={k:result[k] for k in ['pid','start_ticks','host_boot_id']},
        controller_proc_present=Path('/proc') .joinpath(str(result['pid'])).exists(),
        broker_state_sha256=sha(U/'jobs'/NAME/'state.json'),
        request_sha256=sha(U/'requests'/(NAME+'.json')),
        full_module_parity=False, area_saving_unknown=True,
        production_admission=False, full_host_synthesis=False, fpga_access=False,
        limitation='Exact private256-slot target and generated GoldenGate memory ports only. No full-module equivalence, mapped area, FIT, physical timing, or FPGA sample claim.'))
    print('SEALED_PASS',sha(A/'barrier-port-acceptance.json'),'result',sha(O/'result.json'))


if __name__=='__main__':
    main()
