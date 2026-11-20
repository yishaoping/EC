#!/usr/bin/python3
"""Read-only verification of all exported bytes, bindings and distribution counts."""
from pathlib import Path
import csv,hashlib,json,math,statistics

P=Path(__file__).resolve().parent
def sha(p):
    h=hashlib.sha256()
    with Path(p).open('rb') as f:
        while b:=f.read(8*1024*1024):h.update(b)
    return h.hexdigest()
def rows(name):return list(csv.DictReader((P/name).open()))
def main():
    complete=json.loads((P/'complete.json').read_text());manifest=json.loads((P/'manifest.json').read_text())
    assert sha(P/'manifest.json')==complete['manifest_sha256']
    assert sha(P/'summary.json')==complete['summary_sha256']
    for name,e in manifest['files'].items():
        p=P/name;assert p.stat().st_size==e['bytes'] and sha(p)==e['sha256'],name
    for e in manifest['external_sources']:
        p=Path(e['path']);assert p.stat().st_size==e['bytes'] and sha(p)==e['sha256'],e['path']
    life=rows('lifetimes.csv');assert len(life)==659
    for s in rows('latency-target-cycles.csv'):
        v=sorted(int(x[s['metric']]) for x in life);assert int(s['n'])==len(v)
        assert float(s['mean'])==statistics.mean(v)
        for q,k in [(.5,'p50'),(.95,'p95'),(.99,'p99')]:assert int(s[k])==v[math.ceil(q*len(v))-1]
        assert sum(int(x['count']) for x in rows('latency-histogram-target.csv') if x['metric']==s['metric'])==659
    for l in life:
        assert int(l['capture_to_ack'])==int(l['capture_to_promotion'])+int(l['promotion_to_ack'])
        for k in ['capture_to_ack','capture_to_promotion','promotion_to_ack']:
            for unit in ['fpga_hcycles','host_wall_ns']:
                assert 0<=int(l[k+'_'+unit+'_lower'])<=int(l[k+'_'+unit+'_upper'])
    runs=rows('runs.csv');assert len(runs)==2
    assert all(int(r['trace_edges'])==1759001 and int(r['acks'])==659 for r in runs)
    assert int(runs[1]['driver_completion_cumulative_clock_tokens'])-int(runs[0]['driver_completion_cumulative_clock_tokens'])==1759001
    assert abs(float(runs[1]['replay_edges_per_host_second'])-1759001/float(runs[1]['driver_loop_wall_seconds']))<1e-8
    print(json.dumps(dict(status='PASS_ALL_PUBLICATION_HASHES_AND_STATISTICS',files=len(manifest['files']),external_sources=len(manifest['external_sources']),lifetimes=len(life))))

if __name__=='__main__':main()
