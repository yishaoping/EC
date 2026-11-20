#!/usr/bin/env python3
"""Summarize only atomically committed valid FPGA samples, retaining failures."""
import collections,datetime as dt,fcntl,hashlib,json,math,statistics
from pathlib import Path
from board_batch import W,D,sha,save


def matched_key(i):
    return {k:i.get(k) for k in ['program','input','apps_manifest_sha256','rootfs_sha256','elf_sha256','case','memory_model','threads','warmups','target_boom_hz','linux_memory_cap_bytes','linux_bootargs']}


def configuration_key(i):
    # Mechanism stays C4 in the strict runtime checker protocol, but a derived
    # hardware version must never share repetitions/statistics with frozen C4.
    if i.get('hardware_profile'):
        return i['hardware_profile']+'@'+i['hardware_commit']
    return i['configuration']


def main():
    lock=(D/'locks/result-summary.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX)
    groups=collections.defaultdict(list);failures=[];functional=[];running=[];duplicates=[];selected={}
    for p in sorted((D/'runs').glob('*/manifest.json')):
        result=p.parent/'result.json';state=p.parent/'state.json';m=json.loads(p.read_text())
        if not result.exists():
            running.append(dict(run_dir=str(p.parent),state=json.loads(state.read_text()) if state.exists() else None));continue
        r=json.loads(result.read_text());i=r['identity'];complete=p.parent/'complete.json'
        committed=False
        if r.get('valid') and complete.exists():
            c=json.loads(complete.read_text());committed=c['result_sha256']==sha(result) and c['identity_sha256']==r['identity_sha256']
        if not committed:
            failures.append(dict(result=str(result),configuration=i['configuration'],program=i['program'],input=i['input'],formal=r.get('formal'),issues=r['issues'] or ['invalid atomic commit']));continue
        if not r.get('formal'):
            functional.append(dict(result=str(result),configuration=i['configuration'],program=i['program'],input=i['input'],roi_cycles=r['roi_cycles']));continue
        key=matched_key(i);kid=hashlib.sha256(json.dumps(key,sort_keys=True).encode()).hexdigest()
        sample_key=(kid,configuration_key(i),i['repetition'])
        if sample_key in selected:
            duplicates.append(dict(result=str(result),retained_result=selected[sample_key],configuration=i['configuration'],program=i['program'],input=i['input'],repetition=i['repetition'],reason='same matched sample and repetition already committed; no additional statistical weight'))
            continue
        selected[sample_key]=str(result)
        groups[kid].append((result,r,key))
    rows=[];ratios=[];program_sets=collections.defaultdict(set)
    for kid,samples in groups.items():
        bycfg=collections.defaultdict(list)
        for p,r,key in samples:bycfg[configuration_key(r['identity'])].append((p,r))
        # Application/rootfs identities must match within each workload. They
        # may differ across workloads in the common-set geometric mean; the
        # system, memory, frequency and measurement policy must still match.
        profile={k:v for k,v in key.items() if k not in ['program','input','elf_sha256','case','apps_manifest_sha256','rootfs_sha256']}
        profile_id=hashlib.sha256(json.dumps(profile,sort_keys=True).encode()).hexdigest()
        row=dict(matched_identity=key,matched_identity_sha256=kid,comparison_profile=profile,comparison_profile_sha256=profile_id,configurations={})
        for cfg,rr in bycfg.items():
            cycles=[r['roi_cycles'] for p,r in rr];assert all(c>0 for c in cycles)
            row['configurations'][cfg]=dict(n=len(cycles),median_cycles=statistics.median(cycles),mean_cycles=statistics.mean(cycles),minimum_cycles=min(cycles),maximum_cycles=max(cycles),relative_range=(max(cycles)-min(cycles))/statistics.mean(cycles),coefficient_of_variation=statistics.stdev(cycles)/statistics.mean(cycles) if len(cycles)>1 else None,samples=[dict(result=str(p),cycles=r['roi_cycles'],repetition=r['identity']['repetition'],board_bdf=r['identity']['board_bdf'],host_wall_seconds=r['host_wall_seconds'],drain_cycles=r['drain_cycles']) for p,r in rr])
            program_sets[cfg].add((key['program'],key['input']))
        pairs=[('C4','Native','Correction/Native'),('Check','Native','Check/Native'),('C4','Check','Correction/Check')]
        pairs += [(cfg,'Native',cfg+'/Native') for cfg in bycfg if cfg.startswith('Opt4-fit-')]
        for numerator,denominator,label in pairs:
            if numerator in bycfg and denominator in bycfg:
                value=row['configurations'][numerator]['median_cycles']/row['configurations'][denominator]['median_cycles']
                ratios.append(dict(program=key['program'],input=key['input'],comparison=label,comparison_profile_sha256=profile_id,median_cycle_ratio=value,matched_identity_sha256=kid,replication_target_met=min(len(bycfg[numerator]),len(bycfg[denominator]))>=3))
        rows.append(row)
    geomeans=[]
    for label,profile_id in sorted({(r['comparison'],r['comparison_profile_sha256']) for r in ratios}):
        rr=[r for r in ratios if r['comparison']==label and r['comparison_profile_sha256']==profile_id]
        workloads=[r['program']+' '+r['input'] for r in rr]
        assert len(set(workloads))==len(workloads), 'ambiguous duplicate workload identities; refuse double weighting'
        geomeans.append(dict(comparison=label,comparison_profile_sha256=profile_id,programs=workloads,n_programs=len(rr),geometric_mean=math.exp(statistics.mean(math.log(r['median_cycle_ratio']) for r in rr)),replication_target_met=all(r['replication_target_met'] for r in rr)))
    report=dict(schema='ec-fpga-summary/1',updated_utc=dt.datetime.now(dt.timezone.utc).isoformat(),formal_groups=rows,ratios=ratios,geometric_means=geomeans,valid_functional=functional,failures=failures,duplicate_samples_excluded=duplicates,running_or_incomplete=running,program_sets={k:sorted([p+' '+i for p,i in v]) for k,v in program_sets.items()},strict_checker_latency=None,latency_limitation='No proven same-unit BOOM completion / Rocket true-comparison completion pair in common timebase; PACKAGE_BEGIN is not a completion event',board_limitation='Board/configuration swap not yet measured; retain per-sample BDF and serial',historical_verilator_slowdown_excluded=True)
    save(D/'results-summary.json',report);print(json.dumps(dict(valid_functional=len(functional),formal_samples=sum(len(v) for v in groups.values()),paired_programs=len(ratios),failures=len(failures))))


if __name__=='__main__':main()
