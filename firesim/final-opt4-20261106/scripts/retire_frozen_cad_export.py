#!/usr/bin/env python3
"""Retire only the proven non-fitting frozen export cgroup, preserving evidence."""
from pathlib import Path
import datetime,json,os,shutil,subprocess
from board_batch import W,D,save,sha
from job_service import proc,boot

def main():
    assert os.geteuid()==0
    cad=json.loads((D/'C4-runtime-cad-state.json').read_text())
    summary=json.loads((D/'build-logs/C4-capacity-20261110/capacity-summary.json').read_text())
    assert cad['host_boot_id']==boot()
    assert cad['source_id']=='c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
    assert summary['optimized_dut_verdict']=='NOT_FIT'
    resources=summary['resources']['optimized_dut']
    assert resources['CLB LUTs']['used']>resources['CLB LUTs']['available']
    assert resources['CARRY8']['used']>resources['CARRY8']['available']
    for k,t in [('pid','start_ticks'),('child_pid','child_start_ticks')]:
        r=proc(cad[k]);assert r and r['start_ticks']==str(cad[t]),(k,r)
    assert '/scripts/resume_bitstream.py' in proc(cad['pid'])['cmdline']
    group='/system.slice/ec-parsec-cad.service'
    cgroup=Path('/sys/fs/cgroup/systemd')/group.lstrip('/')/'cgroup.procs'
    ids=sorted(set(map(int,cgroup.read_text().split())))
    assert cad['pid'] in ids and cad['child_pid'] in ids and 11088 in ids
    active=json.loads((D/'active-0000_21_00.0.json').read_text())
    assert active['pid'] not in ids
    processes=[]
    for pid in ids:
        r=proc(pid)
        if not r:continue
        assert group in (Path('/proc')/str(pid)/'cgroup').read_text()
        assert 'FireSim-xilinx_' not in r['cmdline']
        processes.append(r)
    stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'build-logs'/('frozen-cad-retired-not-fit-'+stamp);out.mkdir()
    for n in ['C4-runtime-cad-state.json','cad-wall-limit-guard-state.json']:
        shutil.copy2(D/n,out/n)
    for p in [D/'jobs/cad/state.json',D/'jobs/cad-wall-limit-guard/state.json',
              D/'jobs/cad/console.log',D/'build-logs/C4-capacity-20261110/capacity-summary.json',
              D/'build-logs/C4-capacity-20261110/vivado-postopt.rpt',
              D/'build-logs/C4-capacity-20261110/vivado-postopt-drc.rpt']:
        shutil.copy2(p,out/(p.parent.name+'-'+p.name))
    original=Path(cad['output_dir'])
    checkpoints=[dict(path=str(p),bytes=p.stat().st_size,mtime_ns=p.stat().st_mtime_ns)
                 for p in original.rglob('*.dcp') if p.is_file()]
    optimized=D/'build-logs/C4-capacity-20261110/DUT-optimized-capacity.dcp'
    assert optimized.exists() and checkpoints
    receipt=dict(schema='ec-retired-frozen-cad/1',utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        status='STOP_REQUESTED',reason='Frozen DUT independently optimized and DRC-confirmed NOT FIT; stop unnecessary VHDL function-simulation export and prevent its later implementation. Preserve independent full-top opt_design diagnostic.',
        authorization='User requested safe retirement of proven NOT FIT frozen C4 work to prioritize Opt4-fit',
        source_id=cad['source_id'],hardware_commit=cad['hardware_commit'],processes=processes,
        service='ec-parsec-cad.service',guard_service='ec-parsec-cad-wall-limit-guard.service',
        preserved_checkpoints=checkpoints,preserved_optimized_dcp=str(optimized),
        postopt_resources=resources,capacity_summary_sha256=sha(D/'build-logs/C4-capacity-20261110/capacity-summary.json'),
        native_identity=active,fpga_actions=False,deleted_files=[],full_top_diagnostic_untouched=True)
    save(out/'receipt.json',receipt);save(D/'frozen-cad-retirement.json',receipt)
    subprocess.run(['systemctl','disable','ec-parsec-cad.service','ec-parsec-cad-wall-limit-guard.service'],check=True)
    subprocess.run(['systemctl','stop','ec-parsec-cad-wall-limit-guard.service'],check=True)
    subprocess.run(['systemctl','stop','--no-block','ec-parsec-cad.service'],check=True)
    print(json.dumps(dict(receipt=str(out/'receipt.json'),stop_requested=True,fpga_actions=False)),flush=True)

if __name__=='__main__':main()
