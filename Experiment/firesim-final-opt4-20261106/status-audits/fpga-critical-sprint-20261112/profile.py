#!/usr/bin/python3
"""Bounded sampling of exact existing FPGA CAD processes; no CAD signals."""
from pathlib import Path
import json,os,subprocess,sys,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,save

def main():
    assert os.geteuid()==0
    # These are the unchanged capacity parent and its actual mapping child.
    rows={2379656:'25825451',2442537:None}
    before={}
    for pid,start in rows.items():
        i=identity(pid);assert i and i['host_boot_id']=='d6c6e410-10ad-4326-86ba-79b657eabd96'
        if start:assert i['start_ticks']==start
        cg=(Path('/proc')/str(pid)/'cgroup').read_text()
        assert '/ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service' in cg
        argv=(Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0')
        assert argv[0].decode().endswith('/unwrapped/lnx64.o/vivado')
        before[pid]=dict(identity=i,cgroup=cg)
    data=OUT/'capacity.perf.data';assert not data.exists(),'preserve profile'
    command=['/usr/bin/perf','record','-e','cpu-clock','-F','49','--call-graph','fp','-p',','.join(map(str,rows)),'-o',str(data),'--','/usr/bin/sleep','12']
    r=subprocess.run(command,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True,timeout=30)
    (OUT/'perf-record.log').write_text(r.stdout)
    if r.returncode==0:
        with (OUT/'capacity-profile.txt').open('w') as f:
            subprocess.run(['/usr/bin/perf','report','--stdio','--no-children','--sort','comm,dso,symbol','--percent-limit','1','-i',str(data)],stdout=f,stderr=subprocess.STDOUT,timeout=30,check=True)
    after={pid:identity(pid) for pid in rows}
    for pid in rows:assert after[pid]['start_ticks']==before[pid]['identity']['start_ticks']
    save(OUT/'profile-receipt.json',dict(updated_utc=now(),returncode=r.returncode,argv=command,before=before,after=after,signals_sent_to_cad=[],cad_inputs_modified=False,fpga_access=False))
    print('BOUNDED_CAD_PROFILE_COMPLETE',r.returncode)

if __name__=='__main__':main()
