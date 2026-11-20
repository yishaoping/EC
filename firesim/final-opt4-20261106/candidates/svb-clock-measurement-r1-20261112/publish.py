#!/usr/bin/python3
"""Read-only publication of bound real card21 component observations."""
from pathlib import Path
import bisect,csv,hashlib,importlib.util,json,math,os,re,shutil,statistics,sys
import numpy as np

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT=D/'paper-svb-real-fpga-r1-20261112'
RUN=D/'svb-clock-measurement-fpga-r1-20261112'
OLD=D/'cycleprecise-original-svb-host40-shell-application-onboard-r7-20261112'
AUDIT=D/'overnight-ec-evidence-audit-r4-20261112'
CPU=D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import now,read,save,sha

def write_csv(name,rows):
    assert rows,name
    keys=list(dict.fromkeys(k for r in rows for k in r))
    with (OUT/name).open('x') as f:
        w=csv.DictWriter(f,fieldnames=keys);w.writeheader();w.writerows(rows)

def stats(values):
    v=sorted(values);n=len(v);assert n
    return dict(n=n,mean=statistics.mean(v),minimum=v[0],p50=v[math.ceil(.5*n)-1],
                p95=v[math.ceil(.95*n)-1],p99=v[math.ceil(.99*n)-1],maximum=v[-1])

def parsed(txt,marker):
    m=re.findall('^'+marker+' (.*)$',txt,re.M);assert len(m)==1,marker
    return {k:float(v) if '.' in v or 'e' in v.lower() else int(v)
            for k,v in (x.split('=',1) for x in m[0].split())}

def main():
    assert not (OUT/'complete.json').exists(),'immutable publication already exists'
    # Reuse independently checked source/CPU/application and hardware bindings.
    spec=importlib.util.spec_from_file_location('prior_metrics',C.parent/'svb-application-fpga-metrics-r2-20261112/consume.py')
    prior=importlib.util.module_from_spec(spec);spec.loader.exec_module(prior)
    admission,lifetimes,rates=prior.reference()
    old=prior.hardware(admission,OLD)
    r=read(RUN/'result.json');cert=read(RUN/'certified-component.json')
    assert read(RUN/'complete.json')['result_sha256']==sha(RUN/'result.json')
    assert r['status']=='PASS_REAL_SVB_FPGA_HOST_COUNTER_REPLAY' and r['returncode']==0
    assert r['board_bdf']=='0000:21:00.0' and r['board_serial']=='21770433G02LA'
    assert r['functional_baseline']==cert['functional_baseline']==BASE
    assert r['source_id']==cert['source_id']==admission['source_id']
    assert r['trace_sha256']==admission['trace_sha256']
    assert r['bitstream_sha256']==cert['bitstream_sha256']==old['bitstream_sha256']
    assert r['no_reflash'] and not r['deployment_operations'] and not r['full_opt4']
    assert sha(r['raw_log'])==r['raw_log_sha256']
    assert sha(RUN/'fpga-event-intervals.csv')==r['event_csv_sha256']
    assert sha(RUN/'run-started.json')==r['run_started_sha256']
    txt=Path(r['raw_log']).read_text();s=parsed(txt,'SVB_GG_STREAM_SUMMARY');clock=parsed(txt,'SVB_CLOCK_SUMMARY')
    assert s==r['summary'] and clock==r['clock_summary']
    prior.summary_gate(s,admission['expected_summary'])
    assert '[SVBProbe]PASS Test' in txt
    events=[{k:int(v) for k,v in e.items()} for e in csv.DictReader((RUN/'fpga-event-intervals.csv').open())]
    assert len(events)==clock['event_rows']
    by_tick={e['source_tick']:e for e in events};assert len(by_tick)==len(events)
    assert all(events[i]['fpga_hcycle_after']<=events[i+1]['fpga_hcycle_before'] for i in range(len(events)-1))
    assert all(e['fpga_hcycle_before']<=e['fpga_hcycle_after'] and e['steady_ns_before']<=e['steady_ns_after'] for e in events)
    trace=Path(admission['trace'])
    assert trace.stat().st_size==16+s['records']*404
    with trace.open('rb') as f:assert f.read(16)==b'ECSVBFULLBINv1\0\0'
    raw=np.memmap(trace,dtype='<u4',mode='r',offset=16,shape=(s['records'],101))
    def row(tick):
        v=[int(x) for x in raw[tick-s['first_source_tick']]]
        assert v[0]+(v[1]<<32)==tick
        return v
    # Cross-check hardware-stamped expected events against their immutable full payload trace.
    for e in events:
        v=row(e['source_tick']);assert e['boom_csr_cycle']==v[2]+(v[3]<<32)
        assert e['occupancy']==v[99]
        if e['source_tick']!=s['first_source_tick']:
            assert e['capture']==int(bool(v[9] and v[8]))
            assert e['promotion']==int(bool(v[42] and v[41]))
            assert e['ack']==v[100]
        for key,offset in [('capture_key_valid',12),('capture_writer',13),('capture_generation',14),('capture_sequence',15),
                           ('promotion_entry',67),('promotion_key_valid',45),('promotion_writer',46),('promotion_generation',47),('promotion_sequence',48),
                           ('ack_entry',94),('ack_key_valid',95),('ack_writer',96),('ack_generation',97),('ack_sequence',98)]:assert e[key]==v[offset]
    for flag,key in [('capture','capture_accepted'),('promotion','promote_accepted'),('ack','acked')]:assert sum(e[flag] for e in events)==s[key]==659
    OUT.mkdir(exist_ok=True);evidence=OUT/'evidence';evidence.mkdir(exist_ok=True)
    all_lifetimes=[]
    for l in lifetimes['sample_lifetimes']:
        cap,pro,ack=[by_tick[l[k+'_target_cycle']] for k in ['capture','promotion','ack']]
        assert cap['capture'] and pro['promotion'] and ack['ack']
        a,p,z=[row(e['source_tick']) for e in [cap,pro,ack]]
        identity=[p[67],p[43]+(p[44]<<32),*p[45:51],p[51:67]]
        assert identity==l['identity']
        assert [a[10]+(a[11]<<32),*a[12:18],a[18:34]]==identity[1:]
        assert [z[94],*z[95:99]]==[identity[0],*identity[2:6]]
        v={k:x for k,x in l.items() if k!='identity'}
        v['identity_sha256']=hashlib.sha256(json.dumps(identity,separators=(',',':')).encode()).hexdigest()
        for prefix,u,w in [('capture_to_ack',cap,ack),('capture_to_promotion',cap,pro),('promotion_to_ack',pro,ack)]:
            assert v[prefix]==w['source_tick']-u['source_tick']
            v[prefix+'_fpga_hcycles_lower']=w['fpga_hcycle_before']-u['fpga_hcycle_after']
            v[prefix+'_fpga_hcycles_upper']=w['fpga_hcycle_after']-u['fpga_hcycle_before']
            v[prefix+'_host_wall_ns_lower']=w['steady_ns_before']-u['steady_ns_after']
            v[prefix+'_host_wall_ns_upper']=w['steady_ns_after']-u['steady_ns_before']
            assert 0<=v[prefix+'_fpga_hcycles_lower']<=v[prefix+'_fpga_hcycles_upper']
        all_lifetimes.append(v)
    write_csv('lifetimes.csv',all_lifetimes)
    targets=[];host=[];hist=[];ecdf=[]
    for metric in ['capture_to_ack','capture_to_promotion','promotion_to_ack']:
        v=[l[metric] for l in all_lifetimes];st=stats(v)
        reference=lifetimes['metrics'][metric]
        assert all(st[k]==reference[k] for k in ['n','mean','p95','p99'])
        targets.append(dict(metric=metric,unit='target_cycles',**st,scope='real Canneal trace validated on certified SVB FPGA; includes recorded backpressure'))
        for suffix,unit in [('fpga_hcycles','FPGA_host_cycles'),('host_wall_ns','host_wall_ns')]:
            lo=stats([l[metric+'_'+suffix+'_lower'] for l in all_lifetimes]);hi=stats([l[metric+'_'+suffix+'_upper'] for l in all_lifetimes])
            host.append(dict(metric=metric,unit=unit,n=lo['n'],**{k+'_lower':v for k,v in lo.items() if k!='n'},
                             **{k+'_upper':v for k,v in hi.items() if k!='n'},scope='run-specific handshake latency bounds including MMIO and host stalls'))
        from collections import Counter
        counts=Counter(v);running=0
        for value,count in sorted(counts.items()):
            running+=count;hist.append(dict(metric=metric,target_cycles=value,count=count))
            ecdf.append(dict(metric=metric,target_cycles=value,cumulative_count=running,n=len(v),ecdf=running/len(v)))
    write_csv('latency-target-cycles.csv',targets);write_csv('latency-replay-host-bounds.csv',host)
    write_csv('latency-histogram-target.csv',hist);write_csv('latency-ecdf-target.csv',ecdf)
    cad=read(cert['cad_result']);assert sha(cert['cad_result'])==cert['cad_result_sha256']
    K=Path(cert['cad_result']).parent
    for name in ['utilization-final.rpt','final-timing.rpt','drc-final.rpt','route-final.rpt','physical-clocks.rpt']:
        p=K/name;assert sha(p)==cad['outputs'][str(p)]
        shutil.copy2(p,evidence/name)
    resources=[];util=(K/'utilization-final.rpt').read_text()
    for name in ['CLB LUTs','CLB Registers','CARRY8','DSPs','Block RAM Tile','URAM']:
        match=re.search(r'^\| '+re.escape(name)+r'\s+\|\s*([\d.]+)\s*\|[^|]*\|[^|]*\|\s*([\d.]+)',util,re.M);assert match,name
        used,capacity=map(float,match.groups())
        resources.append(dict(resource=name,used=used,available=capacity,utilization_percent=100*used/capacity,
                              scope='post-route complete U280 shell plus SVB replay simulator; not bare SVB',source_sha256=sha(K/'utilization-final.rpt')))
    write_csv('resources.csv',resources)
    timing=[dict(metric=k,value=v,unit='endpoints' if k.endswith('failing') else 'ns',scope='certified complete shell plus SVB replay') for k,v in cad['timing'].items()]
    timing += [dict(metric='DRC_errors',value=0,unit='findings',scope='certification review'),dict(metric='DRC_warnings_retained',value=49,unit='findings',scope='reviewed; not zero warnings'),dict(metric='routed_nets',value=255876,unit='nets',scope='all routable nets; zero routing errors')]
    write_csv('timing-drc.csv',timing)
    h=clock['fpga_hcycle_elapsed'];assert h==clock['fpga_hcycle_end']-clock['fpga_hcycle_begin']
    wall_lo=clock['steady_end_before_ns']-clock['steady_begin_after_ns']
    wall_hi=clock['steady_end_after_ns']-clock['steady_begin_before_ns']
    hzlo=h*1e9/wall_hi;hzhi=h*1e9/wall_lo
    freq=[dict(kind='MMCM/STA nominal FPGA host clock',frequency_hz=cert['physical_host_clock_frequency_hz'],period_ns=cert['physical_host_clock_period_ns'],frequency_hz_lower='',frequency_hz_upper='',scope='nominal physical host clock from certified CAD; not target clock'),
          dict(kind='measured FPGA hcycle / host CLOCK_MONOTONIC',frequency_hz=(hzlo+hzhi)/2,period_ns=1e9/((hzlo+hzhi)/2),frequency_hz_lower=hzlo,frequency_hz_upper=hzhi,scope='64s interval; timestamp-bracket bounds only, not an absolute calibrated oscillator accuracy interval'),
          dict(kind='FireSim driver rounded Host Frequency',frequency_hz=39999000,period_ns='',frequency_hz_lower='',frequency_hz_upper='',scope='39.999 MHz rounded raw log'),
          dict(kind='target frequency',frequency_hz='',period_ns='',frequency_hz_lower='',frequency_hz_upper='',scope='not defined; target cycles must not be divided by physical host frequency')]
    write_csv('frequency.csv',freq)
    runrows=[]
    for name,result,path in [('original_application_replay',old,OLD),('clock_instrumented_application_replay',r,RUN)]:
        ss=result['summary'];t=(path/'hardware-replay.log').read_text()
        completion=int(re.search(r'PASSED \*\*\* after (\d+) cycles',t)[1])
        runrows.append(dict(run=name,workload='canneal_project400',independent_workload_sample=False,
                            trace_edges=ss['records'],defined_output_word_checks=ss['defined_output_word_checks'],
                            captures=ss['capture_accepted'],promotions=ss['promote_accepted'],acks=ss['acked'],
                            driver_loop_wall_seconds=ss['host_wall_seconds'],inclusive_host_wall_seconds=result['host_wall_seconds'],
                            replay_edges_per_host_second=ss['records']/ss['host_wall_seconds'],
                            ack_per_host_second=ss['acked']/ss['host_wall_seconds'],
                            fpga_host_cycles=h if path==RUN else '',
                            fpga_host_cycles_per_replayed_target_edge=h/ss['records'] if path==RUN else '',
                            replay_edges_per_fpga_host_cycle=ss['records']/h if path==RUN else '',
                            driver_completion_cumulative_clock_tokens=completion,
                            bitstream_sha256=result['bitstream_sha256'],trace_sha256=result['trace_sha256'],
                            result_path=str(path/'result.json'),result_sha256=sha(path/'result.json')))
    assert runrows[1]['driver_completion_cumulative_clock_tokens']-runrows[0]['driver_completion_cumulative_clock_tokens']==s['records']
    write_csv('runs.csv',runrows)
    write_csv('workload-event-rates.csv',[dict(metric=k,value=v,unit=u,scope=scope) for k,v,u,scope in [
        ('completed_transactions',659,'transactions','659 complete correlated lifetimes from one Canneal trace'),
        ('ACK_per_active_target_cycle',rates['completed_per_active_target_cycle'] if 'completed_per_active_target_cycle' in rates else 659/(rates['last_ack_tick']-rates['first_capture_tick']+1),'ACK/target_cycle','first capture through last ACK inclusive'),
        ('ACK_per_nonreset_target_cycle',659/(s['records']-s['reset_edges']),'ACK/target_cycle','includes application boot/idle tail'),
        ('maximum_occupancy',32,'entries','workload observed'),
        ('full_occupancy_cycles',3956,'target_cycles','workload observed')]])
    # Source ROI/session timestamps are CSR values from this exact capture.
    full=read(D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111/full-result.json')
    app='\n'.join(full['full']['application_rows'])
    roi=int(re.search(r'\[ROI\].*?stop=(\d+)',app)[1]);stop=int(re.search(r'session_stop=(\d+)',app)[1])
    csr=raw[:,2].astype('uint64')+(raw[:,3].astype('uint64')<<32)
    def csr_tick(value):
        ix=np.where((csr==value)&(raw[:,7]==0))[0];assert len(ix)==1
        return int(raw[ix[0],0])+(int(raw[ix[0],1])<<32)
    lastcap=max(l['capture_target_cycle'] for l in all_lifetimes)
    lastack=max(l['ack_target_cycle'] for l in all_lifetimes)
    tail=raw[lastcap-s['first_source_tick']:,99];j=int(np.where(tail==0)[0][0]);empty=lastcap+j
    assert all(int(x)==0 for x in raw[empty-s['first_source_tick']:,99])
    drain=[]
    for marker,tick in [('last_capture',lastcap),('reported_ROI_stop_CSR_marker',csr_tick(roi)),('reported_application_session_stop_CSR_marker',csr_tick(stop))]:
        for end,etick in [('last_ACK_handshake',lastack),('first_zero_occupancy_preedge_observation',empty)]:
            drain.append(dict(start_marker=marker,start_source_tick=tick,end_marker=end,end_source_tick=etick,
                              interval_target_cycles=etick-tick,unit='target_cycles',
                              scope='SVB component observed tail on replayed traffic; not complete EC/checker/rollback drain'))
    write_csv('drain-observations.csv',drain)
    whole_path=D/'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/result.json'
    whole=read(whole_path);post=whole['reports']['postopt']
    for p,digest in post['evidence'].items():assert sha(p)==digest
    write_csv('opt4-fit.csv',[dict(resource=k,used=v,available=post['capacities'][k],excess=whole['resource_excess'][k],
                                 fit=whole['full_host_fit'],scope=whole['area_scope'],result_sha256=sha(whole_path)) for k,v in post['resources'].items()])
    write_csv('workload-coverage.csv',[dict(workload='canneal_project400',full_payload_trace=True,real_SVB_FPGA_replay=True,full_EC_FPGA=False,notes='only available complete application payload trace; same trace instrumented once'),
        *[dict(workload=name,full_payload_trace=False,real_SVB_FPGA_replay=False,full_EC_FPGA=False,
               notes='No complete SVB payload trace discovered in FPGA evidence; do not invent payload from BOOM_ALLOC/RESULT' if name=='blackscholes' else 'Pending complete trace or runnable full EC; independent CPU session not controlled')
          for name in ['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']]])
    for name in ['result.json','complete.json','run-started.json','pre-run.json','certified-component.json','driver-validation.json','hardware-replay.log','fpga-event-intervals.csv']:
        shutil.copy2(RUN/name,evidence/('instrumented-'+name))
    shutil.copy2(OLD/'hardware-replay.log',evidence/'original-application-hardware-replay.log')
    shutil.copy2(OLD/'result.json',evidence/'original-application-result.json')
    shutil.copy2(whole_path,evidence/'opt4-postopt-result.json')
    (evidence/'raw-application-svb-full.bin').symlink_to(trace)
    # Plots are generated with standard plotting tools, from exported numeric CSVs.
    import matplotlib
    matplotlib.use('Agg')
    import matplotlib.pyplot as plt
    with plt.rc_context({'font.family':'DejaVu Sans','font.size':10,'pdf.fonttype':42,'svg.fonttype':'none'}):
        fig,axs=plt.subplots(1,2,figsize=(8,3.0),layout='constrained')
        for axis,metric,label in [(axs[0],'capture_to_ack','Capture to ACK'),(axs[1],'promotion_to_ack','Promotion to ACK')]:
            rr=[v for v in ecdf if v['metric']==metric]
            axis.step([x['target_cycles'] for x in rr],[x['ecdf'] for x in rr],where='post')
            axis.set(xlabel=label+' (target cycles)',ylabel='Empirical CDF',ylim=(0,1.02));axis.grid(alpha=.25)
        fig.suptitle('Canneal traffic replay on certified SVB FPGA (659 lifetimes)')
        for ext in ['pdf','svg']:fig.savefig(OUT/('latency-cdf.'+ext))
        plt.close(fig)
    summary=dict(schema='ec-publication-real-svb-fpga/1',status='PASS_BOUND_REAL_SVB_FPGA_DATA',created_utc=now(),
                 functional_baseline=BASE,board_bdf=r['board_bdf'],bitstream_sha256=r['bitstream_sha256'],
                 trace_sha256=r['trace_sha256'],full_ec=False,formal_parsec_performance_sample=False,
                 latency_target=targets,latency_host_replay_bounds=host,frequency_hz_measured=(hzlo+hzhi)/2,
                 replay_edges_per_host_second=runrows[1]['replay_edges_per_host_second'],
                 resources=resources,drain_observations=drain,opt4_LUT=post['resources']['CLB LUTs'],
                 opt4_LUT_excess=whole['resource_excess']['CLB LUTs'],
                 strict_checker_latency=None,rollback_latency=None,autonomous_peak_throughput=None,
                 independent_trace_count=1,lifetimes=659)
    save(OUT/'summary.json',summary)
    ca=next(x for x in targets if x['metric']=='capture_to_ack')
    pa=next(x for x in targets if x['metric']=='promotion_to_ack')
    (OUT/'README.md').write_text(f'''# 真实 SVB 组件 FPGA 数据

认证 bitstream 在 `0000:21:00.0` 实测，通过完整 Canneal project400 事件流重放。功能基线 `{BASE}`；仅 SVB 组件，不是完整 EC/8项 PARSEC FPGA 性能。

| 指标 | 实测值 |
|---|---:|
| Capture→ACK，均值/P95/P99 | {ca['mean']:.6f} / {ca['p95']} / {ca['p99']} target cycles |
| Promotion→ACK，均值/P95/P99 | {pa['mean']:.6f} / {pa['p95']} / {pa['p99']} target cycles |
| 本轮重放速率，含MMIO/驱动 | {runrows[1]['replay_edges_per_host_second']:.6f} target edges/host s |
| 本轮 ACK/主机秒，含整条trace闲置区间 | {runrows[1]['ack_per_host_second']:.6f} |
| 本轮 FPGA host counter 增量 | {h} FPGA host cycles |
| 本轮驱动循环/外层主机耗时 | {s['host_wall_seconds']:.9f} / {r['host_wall_seconds']:.9f} s |
| 实测 FPGA host 频率 | {(hzlo+hzhi)/2/1e6:.9f} MHz |
| 认证物理时钟名义值 | {cert['physical_host_clock_frequency_hz']/1e6:.9f} MHz |
| 布线后完整 shell+SVB host 资源 | 197902 LUT / 141885 registers / 12790 CARRY8 / 3 DSP / 125.5 BRAM |
| WNS/TNS/WHS/THS | 0 / 0 / +0.001 / 0 ns |
| DRC | 0 Error / 49 reviewed Warning |
| 最后capture→最后ACK/首次空occupancy观测 | {lastack-lastcap} / {empty-lastcap} target cycles |
| 整机 MCRams post-opt | 2420482 LUT，NOT FIT，缺1116802 LUT（shell未计入） |

本轮 1759001 target edges、19698670 输出wordchecks，659 capture/promotion/ACK，零mismatch。659是同一真实负载内的事件样本，不是659次独立程序运行。原始72.2107秒重放与本轮64.2329秒重放使用同一trace，分开保存在runs.csv；差异不能解释为硬件加速。

CSV：`latency-target-cycles.csv`、`lifetimes.csv`、`latency-replay-host-bounds.csv`、`runs.csv`、`resources.csv`、`frequency.csv`、`timing-drc.csv`、`drain-observations.csv`、`opt4-fit.csv`、`workload-coverage.csv`。CDF供论文直接引用，见PDF/SVG。逐事件原始计数器CSV和真实FPGA日志位于evidence/，大体积完整原始输入trace通过符号链接保留，manifest记录其绝对路径/字节数/SHA256。

必须按METHODS.md解释：target cycles不能用40MHz物理host频率换算；FPGA host-cycle握手区间包含MMIO/主机停顿；应用session_stop后SVB尾部与完整EC/checker排空不是同一指标。ACK不是checker完成或rollback。现阶段无完整EC FPGA bitstream/8项PARSEC性能结论。
''')
    (OUT/'METHODS.md').write_text('''# Measurement method and scope

## Device, design and workload provenance

Only U280 BDF 0000:21:00.0, serial 21770433G02LA, was accessed. The existing independently certified bitstream was reused without programming, XDMA module changes, PCIe reset, JTAG, or other-card operations. The certificate binds the unchanged functional baseline 8491167d, generated target/host, guarded 21-only driver ABI, CAD results and bitstream digest. Resource counts describe the post-route U280 shell plus complete SVB replay host, not bare SVB.

The binary trace was captured from frozen full EC Golden Gate CPU metasim running Canneal project400, ELF SHA256 d0d0e9ae99bd963aeed84a8b395e7096f54985d117d11542d553a38680b8397b. Its 16-byte ECSVBFULLBINv1 header is followed by 101 little-endian uint32 words per sampled pre-edge record. All original 512-bit payloads, reset, idle, backpressure, release and ACK fields are retained. There is one record per actual sampled BOOM target edge; source ticks are 2 through 1759002. The two host_time words in that captured binary come from CPU metasim and are NEVER treated as FPGA host cycles.

The existing full application CPU replay and actual payload-error rejection remain binding prerequisites. The software-only timestamp driver reused the exact target/model, input/output mapping, output definedness rules, reset, force-all input writes and blocking step(1). It adds existing ClockBridge counter reads and a CSV around selected steps. A 372-edge directed replay and actual payload-error rejection validated the new adapter. The FPGA run checked every defined original output word on all 1759001 replayed target edges: 19698670 word checks, all 659 capture/promotion/ACK events, zero mismatches. Original correctness receipts and raw logs remain immutable.

## Three time domains

1. Target cycles: source sampled BOOM edges, and the software TestHarness count of blocking step(1), exactly 1759001 edges. Capture means capture.valid && capture.ready; promotion means promote.valid && promote.ready; ACK means the validated io_acked output. All are sampled pre-edge and commit on that edge. Lifecycle identity includes entry, address, ownership key, epoch/parameter and all data words, with complete matching and no censored sample. Capture to ACK includes recorded watermark eligibility/backpressure and writeback ownership completion; it is not an intrinsic minimum pipeline latency.
2. FPGA host cycles: the bitstream's existing free-running ClockBridge hcycle counter, latched through MMIO. Before/after samples bracket the blocking step that commits an event. For endpoints A and B, true replay event latency lies within [B.before - A.after, B.after - A.before] host cycles. These intervals include all MMIO, file I/O, logging, OS scheduling and host stalls between events. Aggregate mean/quantile bounds are calculated separately from the per-event lower and upper endpoints; monotonic order statistics preserve these bounds. They are not autonomous SVB peak throughput, nor checker or rollback latency.
3. Host wall-clock time: CLOCK_MONOTONIC/steady_clock nanoseconds bracket the same operations; host-wall bounds use the same subtraction. Driver-loop seconds cover trace open/read, replay and instrumentation; inclusive controller seconds also cover process startup/teardown. These quantities are reported independently, without interpreting host scheduling as target behavior.

The long interval hcycle delta divided by the corresponding host monotonic interval estimates actual FPGA host frequency. Timestamp bracketing supplies bounds for call placement only, not calibrated clock accuracy or oscillator uncertainty. The nominal MMCM/STA clock is reported separately. No target frequency in Hz is defined. Dividing target-cycle latencies by approximately40MHz is invalid because host cycles per target edge vary with host stalls.

ClockBridge target tokens are cumulative across replay processes on the same programmed FPGA. The original log completion count is1759374 and the instrumented log reports3518375; their difference is exactly1759001. Consequently the second raw driver's Effective Target Frequency/FMR, whose denominator is cumulative tokens, is not a valid per-run throughput. Paper throughput is recomputed using this run's1759001 replayed edges and measured wall/host-counter deltas. The original pre-instrumentation run and this instrumented run are separate host-timing observations of the same workload, not independent workload samples or evidence of a speedup.

## Statistics, throughput and tail observations

There are659 complete, correlated lifetimes within one Canneal trace. Mean is arithmetic mean; P50/P95/P99 use nearest rank: sorted[ceil(q*n)-1]. Histograms retain unit target-cycle resolution. The exported CDFs use the exact CSV distributions. No independent-run confidence interval is inferred from the659 events.

Replay throughput in target edges per host second includes force-all MMIO writes, correctness peeks and idle/boot trace segments. ACK/host second is the completed-event rate for that same interval. Workload ACK/target-cycle rates use explicit whole-nonreset and first-capture-through-last-ACK inclusive denominators. These describe observed load service, not maximum sustainable hardware throughput.

drain-observations.csv reports exact source-tick differences from last capture, the application's reported ROI-stop CSR timestamp, and its reported session_stop CSR timestamp to last ACK and first subsequent pre-edge zero-occupancy observation. CSR markers are mapped to unique nonreset trace rows. Empty occupancy becomes visible at the following sampled pre-edge, so the observation interval includes this one-cycle sampling distinction. No new drain request was injected. These SVB tail observations do not establish complete EC checker drain, detection/recovery or architectural rollback. The separate source full-EC CPU run is provenance only and is not relabeled as FPGA data.

## Area, correctness and reproducibility

The final utilization report is bound to the certified CAD result:197902LUT,141885CLBregisters,12790CARRY8,3DSP,125.5BRAM,0URAM. Final WNS/TNS are0/0ns, WHS/THS+0.001/0ns, zero failing setup/hold endpoints; all255876networks routed without routing errors. DRC has0Errors and49retained reviewedWarnings, not zero warnings. CDC findings are retained in the original certificate evidence; no claim of zero critical CDC findings is made.

Opt4 resource data is a separate, complete generated MCRams FPGATop post-opt report excluding the shell, with2420482LUT/80990CARRY8/192DSP, excess1116802LUT. It is NOT FIT and does not supply a full EC bitstream or PARSEC FPGA performance sample. Local address optimization is admitted only after actual full-module equivalence evidence and paired resource measurement; local savings are never multiplied into a whole-host FIT claim.

manifest.json binds every publication artifact and external original source by path, byte size and SHA256. The large raw trace is retained as an existing-file link, not recopied or truncated. Run python3 verify.py from this directory to recheck all digests and numeric consistency. Regeneration uses the versioned publish.py source recorded in the manifest; completed publication directories are immutable and require a new version for changes.
''')
    shutil.copy2(C/'verify.py',OUT/'verify.py')
    external=[trace,Path(cert['bitstream']),Path(cert['cad_result']),CPU/'board-admission-ready.json',Path(admission['cpu_proof']),
              D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111/full-result.json',
              AUDIT/'svb-lifetimes-recomputed.json',AUDIT/'svb-observed-rates.json',
              RUN/'result.json',RUN/'complete.json',OLD/'result.json',OLD/'complete.json',
              C/'publish.py',C/'verify.py',C/'StreamingReplay.cc',C/'instrumentation.diff',C/'run.py',C/'plan.json',C/'run-inputs.json',
              C/'SVBStreamingReplay-xilinx_alveo_u280',whole_path,*map(Path,post['evidence'])]
    def entry(p):return dict(path=str(p.resolve()),bytes=p.stat().st_size,sha256=sha(p))
    manifest=dict(schema='ec-publication-evidence-manifest/1',created_utc=now(),
                  files={str(p.relative_to(OUT)):entry(p) for p in sorted(OUT.rglob('*')) if p.is_file()},
                  external_sources=[entry(p) for p in external])
    save(OUT/'manifest.json',manifest)
    save(OUT/'complete.json',dict(manifest_sha256=sha(OUT/'manifest.json'),summary_sha256=sha(OUT/'summary.json')))
    print(json.dumps({k:summary[k] for k in ['status','frequency_hz_measured','replay_edges_per_host_second','opt4_LUT_excess']},indent=2))

if __name__=='__main__':main()
