"""Durable campaign-local state; contains no credentials or device operations."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
UID = 1008
GID = 1008
def now(): return dt.datetime.now(dt.timezone.utc).isoformat()
def boot(): return Path('/proc/sys/kernel/random/boot_id').read_text().strip()
def read(p):
    try: return json.loads(Path(p).read_text())
    except FileNotFoundError: return {}
def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda:f.read(2**20),b''):h.update(block)
    return h.hexdigest()
def bound_inputs(spec):
    """Executable/source inputs stay in W; immutable evidence is explicit."""
    inputs=spec['inputs']; evidence=spec.get('evidence_inputs',{})
    assert inputs and not set(inputs).intersection(evidence),'input classes overlap'
    for rows,root in [(inputs,W),(evidence,D/'build-logs')]:
        for name,expected in rows.items():
            p=Path(name).resolve()
            assert p.is_relative_to(root) and p.is_file(),('input root/file',name)
            assert len(expected)==64 and sha(p)==expected,('input hash changed',name)
    return {**inputs,**evidence}
def save(p,value):
    p=Path(p);p.parent.mkdir(parents=True,exist_ok=True)
    tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with tmp.open('w') as f:
        json.dump(value,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
    if os.geteuid()==0:os.chown(tmp,UID,GID)
    os.replace(tmp,p)
    fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def identity(pid=None):
    pid=pid or os.getpid()
    try:
        s=(Path('/proc')/str(pid)/'stat').read_text();v=s[s.rindex(')')+2:].split()
        return dict(pid=pid,start_ticks=v[19],process_state=v[0],host_boot_id=boot(),cpu_ticks=int(v[11])+int(v[12]),rss_bytes=int(v[21])*os.sysconf('SC_PAGE_SIZE'))
    except (FileNotFoundError,ProcessLookupError):return {}
def live(row):
    if not row.get('pid') or row.get('host_boot_id')!=boot():return False
    x=identity(row['pid'])
    return bool(x and x['start_ticks']==str(row.get('start_ticks')) and x['process_state'] not in ['Z','X'])
def event(kind,**values):
    U.mkdir(exist_ok=True)
    with (U/'ledger.jsonl').open('a') as f:
        fcntl.flock(f,fcntl.LOCK_EX)
        if os.geteuid()==0:
            os.fchown(f.fileno(),UID,GID)
            os.fchmod(f.fileno(),0o664)
        f.write(json.dumps({**values,'utc':now(),'event':kind},sort_keys=True)+'\n');f.flush();os.fsync(f.fileno())
