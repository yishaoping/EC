#!/usr/bin/env python3
"""Measure the isolated native event build with the existing real Opt4 short ELF."""
import datetime as dt
import json
import os
from pathlib import Path
import re
import selectors
import subprocess
import time
from build_minimal import ROOT, sha
from opt4_linux_run import preload_image

WORK=ROOT/'firesim/dac2026/work/opt4-linux-v6'
RESULTS=ROOT/'Experiment/dac2026/opt4-linux-v6/native-short'

def save(path,value):
    with path.open('x') as f:
        json.dump(value,f,indent=2);f.write('\n');f.flush();os.fsync(f.fileno())

def main():
    native=json.loads((WORK/'diagnostic36/native-build.json').read_text())
    short=json.loads((WORK/'stage-a-build.json').read_text())
    for record in [native,short]:
        assert record['returncode']==0
        for path,digest in record['outputs'].items():assert sha(path)==digest,path
    assert native['required_events_without_verbose']
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    attempt=RESULTS/'partial'/stamp;raw=RESULTS/'raw'/stamp
    attempt.mkdir(parents=True);raw.mkdir(parents=True)
    preload=preload_image(Path(short['elf']))
    command=['/usr/bin/stdbuf','-oL','-eL',native['simulator'],'-s','1','+cycle-count',
        '+permissive','+dramsim','+dramsim_ini_dir='+str(Path(native['source_tree'])/'generators/testchipip/src/main/resources/dramsim2_ini'),
        '+loadmem='+preload['path'],'+loadmem_addr=0','+max-cycles=4000000',
        '+uart-pty','+permissive-off',short['elf']]
    save(attempt/'manifest.json',{'native':native,'software':short,'preload':preload,'argv':command,
        'script_sha256':sha(__file__),'scope':'native C4 real package protocol and measured speed; not Linux or slowdown'})
    print(attempt,flush=True)
    start=time.monotonic();last_sync=start;tail=b'';cycle=0
    with (raw/'console.log').open('xb',buffering=0) as console,(raw/'rtl.log').open('xb',buffering=0) as log,(raw/'progress.jsonl').open('x',buffering=1) as progress:
        child=subprocess.Popen(command,cwd=attempt,stdin=subprocess.DEVNULL,stdout=console,stderr=subprocess.PIPE)
        save(attempt/'STARTED.json',{'pid':child.pid,'runner_pid':os.getpid(),'argv':command,
            'started_at':dt.datetime.now(dt.timezone.utc).isoformat(),'raw_dir':str(raw)})
        sel=selectors.DefaultSelector();sel.register(child.stderr,selectors.EVENT_READ)
        opened=True
        while opened:
            for key,event in sel.select(timeout=1):
                chunk=os.read(child.stderr.fileno(),1<<20)
                if not chunk:opened=False;break
                log.write(chunk)
                lines=(tail+chunk).split(b'\n');tail=lines.pop()
                observed=re.findall(rb'(?<![\w_])cycle=([0-9a-f]+)',b'\n'.join(lines))
                if observed:cycle=max(cycle,int(observed[-1],16))
            if time.monotonic()-last_sync>=5:
                elapsed=time.monotonic()-start
                progress.write(json.dumps({'elapsed_seconds':elapsed,'boom_cycle':cycle,
                    'completion':'UNCOMMITTED','console_bytes':os.fstat(console.fileno()).st_size,
                    'rtl_bytes':os.fstat(log.fileno()).st_size})+'\n')
                for f in [progress,console,log]:f.flush();os.fsync(f.fileno())
                last_sync=time.monotonic()
        rc=child.wait();elapsed=time.monotonic()-start
        for f in [progress,console,log]:f.flush();os.fsync(f.fileno())
    save(attempt/'exit.json',{'returncode':rc,'wall_seconds':elapsed})
    text=(raw/'rtl.log').read_text(errors='replace')
    output=(raw/'console.log').read_text(errors='replace')
    begins=re.findall(r'EC_OPT4_PACKAGE_BEGIN hart=(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)',text)
    ends=re.findall(r'EC_OPT4_PACKAGE_RESULT hart=(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=([01]) cancelled=([01])',text)
    rows=re.findall(r'EC_OPT4_A_RESULT ([^\r\n]*)',output)
    fields=dict(re.findall(r'(\w+)=(\w+)',rows[0])) if len(rows)==1 else {}
    reasons=[]
    if rc:reasons.append('nonzero simulator exit')
    if len(rows)!=1 or fields.get('status')!='PASS':reasons.append('missing unique successful software result')
    for k in ['generated','completed','passed']:
        if not fields.get(k,'').isdigit() or int(fields[k])!=len(begins):reasons.append('software/RTL '+k+' mismatch')
    if len(begins)<2 or len(begins)!=len(ends):reasons.append('incomplete real packages')
    bs=[(int(h),int(q,16)) for h,q,s,p in begins];es=[(int(h),int(q,16)) for h,q,s,c,x in ends]
    if len(set(bs))!=len(bs) or set(bs)!=set(es) or len(set(es))!=len(es):reasons.append('sequence mismatch')
    if any(int(s,16)!=0 or int(p)!=3 for h,q,s,p in begins):reasons.append('unexpected baremetal context')
    if any(int(s)!=0 or c!='1' or x!='0' for h,q,s,c,x in ends):reasons.append('comparison not complete/PASS')
    if any(fields.get(k)!='0' for k in ['failed','cancelled','dropped','outstanding','timeout']):reasons.append('fault/backlog')
    if fields.get('checksum')!='32704':reasons.append('wrong checksum')
    if re.search(r'Assertion failed|%Error|Aborted',text):reasons.append('RTL fatal')
    final=re.findall(r'EXIT_DRAIN .*source=DCACHE .*?cycle=([0-9a-f]+)',text)
    final_cycle=int(final[-1],16) if final else cycle
    record={'valid':not reasons,'reasons':reasons,'fields':fields,'real_package_begins':len(begins),
        'real_package_results':len(ends),'final_boom_cycle':final_cycle,'wall_seconds':elapsed,
        'boom_cycles_per_host_second':final_cycle/elapsed,'verbose':False,
        'raw_files':{str(p):sha(p) for p in raw.iterdir()},'manifest_sha256':sha(attempt/'manifest.json'),
        'runtime_validation':'PASS' if not reasons else 'INVALID','slowdown_eligible':False}
    save(attempt/'verification.json',record)
    if not reasons:
        complete=RESULTS/'complete';complete.mkdir(exist_ok=True)
        os.link(attempt/'verification.json',complete/(stamp+'.json'))
        fd=os.open(complete,os.O_DIRECTORY);os.fsync(fd);os.close(fd)
    print(json.dumps(record,indent=2),flush=True)
    return int(bool(reasons))

if __name__=='__main__':raise SystemExit(main())
