#!/usr/bin/env python3
"""Low-rate observations of this CAD job's known descendants and phase only."""
import datetime as dt,json,os,re,time,sys
from pathlib import Path
from board_batch import D,save

state=D/(sys.argv[1] if len(sys.argv)>1 else 'C4-cad-state.json');interval=300
prefix='cad-runtime-progress' if len(sys.argv)>1 else 'cad-progress'
while True:
    r=json.loads(state.read_text());root=Path(r['output_dir']);rows=[]
    for begin in (root/'vivado_proj/firesim.runs').glob('*/.vivado.begin.rst'):
        if (begin.parent/'.vivado.end.rst').exists():continue
        pid=int(re.search(r'Pid="(\d+)"',begin.read_text())[1]);todo=[pid]
        while todo:
            q=todo.pop();proc=Path('/proc')/str(q)
            try:
                fields=(proc/'stat').read_text().split();children=(proc/'task'/str(q)/'children').read_text().split();todo.extend(map(int,children))
                rss=next((l.split()[1] for l in (proc/'status').read_text().splitlines() if l.startswith('VmRSS:')),None)
                rows.append(dict(run=begin.parent.name,pid=q,start_ticks=fields[21],state=fields[2],cpu_seconds=(int(fields[13])+int(fields[14]))/os.sysconf('SC_CLK_TCK'),rss_kib=rss,children=children))
            except (FileNotFoundError,ProcessLookupError):pass
    rec=dict(observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),cad_status=r['status'],rows=rows)
    with (D/(prefix+'-observations.jsonl')).open('a') as f:f.write(json.dumps(rec)+'\n');f.flush();os.fsync(f.fileno())
    save(D/(prefix+'-latest.json'),rec)
    if r['status'] not in ['STARTING','RUNNING']:break
    time.sleep(interval)
