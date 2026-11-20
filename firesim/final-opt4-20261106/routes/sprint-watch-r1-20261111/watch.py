#!/usr/bin/python3
"""Low-cost 24h evidence checkpoint. Read-only toward all CAD/runtime tasks."""
import datetime as dt, fcntl, hashlib, json, os, pathlib, re, shutil, time
P=pathlib.Path
W=P('/data1/gzh/EC/firesim/final-opt4-20261106')
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'opt4-sprint-24h-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
CAP={'CLB LUTs':1303680,'CARRY8':162960,'DSPs':9024}
WATCH=['Opt4-fit-bucket-tag-cad-state.json','Opt4-fit-update-share-svb-cad-state.json',
 'Opt4-fit-dcache-fieldbank-full-map-r4-state.json','Opt4-fit-dcache-full-pair-r2-state.json',
 'Opt4-fit-address-update-sequence-r1-state.json','Opt4-fit-dcache-field-read-full-map-r2-state.json',
 'Opt4-fit-field-address-cycle-consumer-r3-state.json','unattended-opt4/state.json',
 'cycleprecise-route-a-r2-20261111/state.json']
def read(p):
    try:return json.loads(P(p).read_text())
    except FileNotFoundError:return {}
def now():return dt.datetime.now(dt.timezone.utc)
def save(p,x):
    q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    os.replace(q,p)
def proc(pid,depth=0):
    p=P('/proc')/str(pid)
    try:
        a=(p/'stat').read_text().rsplit(')',1)[1].split()
        out=dict(pid=pid,start_ticks=a[19],state=a[0],cpu_ticks=int(a[11])+int(a[12]),rss_bytes=int(a[21])*os.sysconf('SC_PAGE_SIZE'))
        try:out['io']=(p/'io').read_text()
        except PermissionError:out['io']='permission denied; no idle inference'
        children=(p/'task'/str(pid)/'children').read_text().split()
        out['children']=[proc(int(c),depth+1) for c in children[:12]] if depth<5 else []
        return out
    except (OSError,ValueError):return {'pid':pid,'unavailable':True}
def area(p):
    resources={}
    for s in p.read_text().splitlines():
        m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|DSPs|Block RAM Tile)\s*\|\s*([\d,.]+)\s*\|',s)
        if m:resources.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    return resources
def stat(p):
    p=P(p)
    if not p.is_file():return {'path':str(p),'exists':False}
    s=p.stat();return {'path':str(p),'bytes':s.st_size,'mtime_ns':s.st_mtime_ns}
def snapshot(start,deadline):
    rows={}
    for n in WATCH:
        x=read(D/n)
        if not x:continue
        row={k:v for k,v in x.items() if k in ['status','hardware_commit','current_stage','pid','start_ticks','host_boot_id','updated_utc','error','top_postopt_resources','dut_resources','results','metasimulation','stage']}
        if x.get('pid'):row['controller']=proc(x['pid'])
        stages=x.get('stages',{});stage=stages.get(x.get('current_stage'),{})
        log=stage.get('log') or x.get('log')
        if log:row['log']=stat(log)
        rows[n]=row
    reports=[]
    for name in ['Opt4-fit-cad-8da24a26','Opt4-fit-bucket-tag-cad-9ae9a7fc','Opt4-fit-update-share-svb-cad-e0c3737f']:
        for n in ['dut-utilization.rpt','top-postopt-utilization.rpt']:
            p=D/'build-logs'/name/n
            if p.is_file():
                r=area(p);reports.append(dict(**stat(p),resources=r,measurement_scope='whole_postopt' if n.startswith('top-') else 'DUT_only',lut_gap_over_u280=r.get('CLB LUTs',0)-CAP['CLB LUTs']))
    t=now();return dict(schema='ec-opt4-sprint-checkpoint/1',utc=t.isoformat(),started_utc=start,deadline_utc=deadline,
       deadline_reached=t>=dt.datetime.fromisoformat(deadline),functional_baseline=BASE,fpga_access=False,
       resource_capacity=CAP,reports=reports,states=rows,
       resources=dict(available_memory_gib=int(next(s.split()[1] for s in P('/proc/meminfo').read_text().splitlines() if s.startswith('MemAvailable:')))/2**20,free_disk_gib=shutil.disk_usage(W).free/2**30,load=os.getloadavg()),
       warning='CPU progress is not synthesis-stage progress; DUT area is not post-opt FIT. Local RAM results are not whole-EC results. No architectural rollback claim without original RTL and real completion evidence.')
def main():
    L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    policy=read(L/'policy.json')
    assert policy['functional_baseline']==BASE
    start=policy['started_utc'];deadline=policy['deadline_utc']
    state=dict(pid=os.getpid(),start_ticks=P('/proc/self/stat').read_text().rsplit(')',1)[1].split()[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
    while True:
        snap=snapshot(start,deadline);save(L/'latest.json',snap)
        if snap['deadline_reached'] and not (L/'24h-assessment.json').exists():
            snap['assessment']='Report latest measured post-opt and verified full-module gains. If still greatly over capacity, high deadline risk; continue route B, use separately labeled cycle-precise route A and verified Native FPGA evidence. No invented paired result.'
            save(L/'24h-assessment.json',snap)
        state.update(status='MONITORING',updated_utc=snap['utc'],deadline_utc=deadline);save(L/'state.json',state)
        with (L/'history.jsonl').open('a') as f:
            f.write(json.dumps(snap,sort_keys=True)+'\n');f.flush();os.fsync(f.fileno())
        time.sleep(600)
if __name__=='__main__':main()
