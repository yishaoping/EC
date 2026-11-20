#!/usr/bin/env python3
"""Read-only result review; writes new evidence, never updates campaign inputs."""
import csv
import datetime as dt
import hashlib
import io
import json
from pathlib import Path
import re
import sys
import tarfile

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = Path(__file__).parent
sys.path.insert(0, str(W/'scripts'))
from board_batch import save
import coverage_first as cf


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def binding(p):
    return dict(path=str(p), sha256=sha(p))


def review_ferret(prefix, linuxprefix):
    statepath = D/'software'/(prefix+'-state.json')
    st = read(statepath)
    receiptpath = Path(st['receipt'])
    receipt = read(receiptpath)
    sameisa = read(D/'software/netferret-sameisa-state.json')
    refs = {c['input']:Path(c['result']) for c in sameisa['cases']}
    review = dict(schema='ec-independent-profile-offline-review/1',
                  profile=receipt['profile'], receipt=binding(receiptpath), state=binding(statepath),
                  formal_eligible=False, fpga_execution=False, real_checker_validated=False,
                  original_evidence_modified=False, cases={},
                  rationale='Review repaired profile against its own full-byte user output AND independent original socket per-query numerical results; old-profile SHA failures remain untouched.')
    linuxst = read(D/'software'/(linuxprefix+'-validation.json'))
    for case in linuxst['cases']:
        size = case['input']; resultpath = Path(case['result']); result = read(resultpath)
        consolepath = resultpath.parent/'console.log'; console = consolepath.read_text()
        userpath = Path(st['log_dir'])/('user-'+size)/'result.json'; user = read(userpath)
        useroutput = Path(user['output']['path']); expected = useroutput.read_bytes()
        output = resultpath.parent/'captured-output.txt'
        assert output.is_file()
        actual = output.read_bytes()
        guesthashes = re.findall(r'(?m)^([0-9a-f]{64})  output.txt\s*$', console)
        assert sha(useroutput) == user['output']['sha256']
        for key, b in receipt['programs']['netferret']['binaries'].items():
            assert sha(b['path']) == b['sha256'] == user['binaries'][key]['sha256']
        assert result['candidate_receipt_sha256'] == sha(receiptpath)
        archive = Path(user['input_archive']['path'])
        assert sha(archive) == user['input_archive']['sha256']
        with tarfile.open(archive) as tar:
            querynames = {m.name.lstrip('./') for m in tar.getmembers() if m.isfile() and m.name.lstrip('./').startswith('queries/') and m.name.lower().endswith(('.jpg','.jpeg'))}
        lines = actual.decode().splitlines()
        actualnames = [l.split('\t')[0] for l in lines]
        reference = read(refs[size]); refoutput = Path(reference['output']['path'])
        assert reference['input_archive'] == user['input_archive']
        assert reference['server_argv'][1:] == user['server_argv'][1:]
        assert reference['client_argv'][1:] == user['client_argv'][1:]
        assert all(v == 0 for v in reference['exit_codes'].values())
        assert sha(refoutput) == reference['output']['sha256']
        # The original test prints CASS_DIST_MAX empty slots with uninitialized
        # IDs. They are the documented repair, not legitimate ranked neighbors.
        def ranked_rows(text, discard_original_empty=False):
            rows = {}
            for line in text.splitlines():
                fields = line.split('\t')
                assert fields[0] not in rows
                rows[fields[0]] = [f for f in fields[1:] if not (discard_original_empty and f.endswith(':3.40282e+38'))]
            return rows
        numerical_same = ranked_rows(actual.decode()) == ranked_rows(refoutput.read_text(), discard_original_empty=(size=='test'))
        gates = dict(both_peers_exit_zero=result['both_peers_exit_zero'],
                     user_peers_exit_zero=all(v==0 for v in user['exit_codes'].values()),
                     qemu_exit_zero=result['returncode']==0,
                     original_roi_markers_complete=result['original_roi_markers_complete'],
                     unique_complete_query_set=len(actualnames)==len(set(actualnames)) and set(actualnames)==querynames,
                     full_bytes_equal_to_same_profile_user=actual==expected,
                     guest_output_hash_matches_full_bytes=guesthashes==[sha(output)],
                     independent_original_socket_numerical_results=numerical_same,
                     completion_marker=('EC_NETWORK_LINUX_DONE=netferret-'+size) in console,
                     no_abort_panic_or_assertion=not re.search(r'Aborted|Kernel panic|Assertion .*failed|EC_NET_LISTEN_FAILED',console))
        review['cases'][size] = dict(status='LINUX_PROTOCOL_AND_PROFILE_OUTPUT_PASSED' if all(gates.values()) else 'FAILED_WITH_EVIDENCE',
            gates=gates, queries=len(actualnames), source_result=binding(resultpath), console=binding(consolepath),
            candidate_output=binding(output), user_result=binding(userpath), user_output=binding(useroutput),
            independent_socket_reference=binding(refs[size]), independent_socket_output=binding(refoutput),
            input_archive=user['input_archive'], binaries=receipt['programs']['netferret']['binaries'],
            prior_gate_status=result['status'], prior_gate_reference=result['reference'],
            reference_boundary='test excludes original MAXFLOAT empty-slot bug explicitly; small/formal retain every original per-query rank/value; deterministic query order is part of repaired software profile',
            wall_seconds=result['wall_seconds'])
    review['status'] = 'OFFLINE_PROFILE_VALIDATED_NOT_ADOPTED' if all(c['status'].endswith('_PASSED') for c in review['cases'].values()) else 'PARTIAL_WITH_FAILURES'
    save(OUT/(prefix+'-offline-review.json'), review)
    return review


def main():
    now = dt.datetime.now(dt.timezone.utc).isoformat()
    reviews = [review_ferret('netferret-stable-candidate', 'netferret-stable-linux'),
               review_ferret('netferret-stable-joined-candidate', 'netferret-stable-joined-linux')]
    live = read(D/'coverage-status-live.json')
    save(OUT/'coverage-status-snapshot.json', live)
    rows, valid = cf.catalog(), cf.results()
    accepted = []
    for row in rows:
        if row['status'] != 'READY':
            continue
        for repetition in [1,2,3]:
            for path, r in cf.matches(row, valid, 'simmedium', repetition):
                assert r['formal'] and r['fpga_execution'] and r['valid']
                ident = r['identity']
                accepted.append(dict(configuration=row['configuration'], program=row['program'], repetition=repetition,
                    input=ident['input'], software_profile=ident.get('software_profile'),
                    matched_profile_prefix=row['profile'], roi_cycles=r.get('roi_cycles'),
                    roi_instructions=r.get('roi_instructions'), host_wall_seconds=r.get('host_wall_seconds'),
                    host_simulation_wall_seconds=(r.get('host_efficiency') or {}).get('host_simulation_wall_seconds'),
                    host_throughput_cycles_per_second=(r.get('host_efficiency') or {}).get('simulation_throughput_cycles_per_second'),
                    driver_returncode=r.get('driver_returncode'), valid=r['valid'], issues=r.get('issues'),
                    result=binding(path), complete=binding(path.parent/'complete.json'), identity_sha256=r['identity_sha256'],
                    identity=ident, output_and_roi_evidence=r.get('evidence'), result_fields_collected=list(r)))
    save(OUT/'accepted-formal-samples.json', dict(observed_utc=now, samples=accepted,
        note='Only exact current profile matching and atomic completion accepted. None/blank means not collected; host time is not architecture slowdown.'))
    flatfields=['configuration','program','repetition','input','software_profile','roi_cycles','roi_instructions','host_wall_seconds','host_simulation_wall_seconds','host_throughput_cycles_per_second','driver_returncode','valid','identity_sha256','result_path','result_sha256','complete_sha256']
    stream=io.StringIO(); writer=csv.DictWriter(stream, fieldnames=flatfields); writer.writeheader()
    for r in accepted:
        flat={k:r.get(k) for k in flatfields}; flat.update(result_path=r['result']['path'],result_sha256=r['result']['sha256'],complete_sha256=r['complete']['sha256']);writer.writerow(flat)
    (OUT/'accepted-formal-samples.csv').write_text(stream.getvalue())
    failures=read(D/'coverage-first-state.json').get('failures',{})
    priorities={t['program']:t.get('coverage_priority',100) for t in read(D/'suite-execution-plan.json')['programs']}
    rows.sort(key=lambda r:priorities[r['program']])
    nexts={str(rep):[dict(program=r['program'],input=size,repetition=n) for r,size,n,key in cf.next_jobs(rows,valid,failures,'Native',rep)] for rep in [1,2,3]}
    counts={cfg:len([r for r in accepted if r['configuration']==cfg]) for cfg in ['Native','C4']}
    save(OUT/'experiment-snapshot.json', dict(observed_utc=now, published_utc=live['updated_utc'],
        formal_samples=counts, coverage=live['coverage'], active_state=read(D/'active-0000_21_00.0.json'),
        future_native_tasks_by_round=nexts, c4_state=read(D/'C4-runtime-cad-state.json'),
        continuation_state=read(D/'fpga-continuation-state.json'), reviews=[r['status'] for r in reviews],
        hardware_modified=False, fpga_scheduler_modified=False, fpga_or_cad_restarted=False))
    labels={'PASSED':'通过','RUNNING':'运行中','PENDING':'待执行','NOT_DEFINED':'未定义',
            'BLOCKED_SOFTWARE':'软件阻塞','FAILED_WITH_EVIDENCE':'失败'}
    table=['|程序|Native test|small|正式 r1 / r2 / r3|Opt4 test / small / r1 / r2 / r3|阻碍/下一步|',
           '|---|---|---|---|---|---|']
    for p in live['programs']:
        n=p['configurations']['Native']; c=p['configurations']['C4'];ns=n['slots'];cs=c['slots']
        note='等待认证最终 bitstream 和 C4 首验'
        if p['program'].startswith('net'): note='独立软件候选；原 ROI checker/context 协议尚未支持，未正式入队'
        if p['program']=='ferret': note='Native simsmall 输出 SHA 不符；其他项继续'
        if p['program']=='vips': note='Native test Kernel stack overflow；其他项继续'
        table.append('|'+ '|'.join([p['program'],labels.get(ns['test']['status'],ns['test']['status']),
            labels.get(ns['simsmall']['status'],ns['simsmall']['status']),
            ' / '.join(labels.get(ns['r'+str(i)]['status'],ns['r'+str(i)]['status']) for i in [1,2,3]),
            ' / '.join('等待bitstream' if cs[k]['status']=='PENDING' else labels.get(cs[k]['status'],cs[k]['status']) for k in ['test','simsmall','r1','r2','r3']),note])+'|')
    (OUT/'16-program-round-status.md').write_text('\n'.join([f'快照 {now}；发布来源 {live["updated_utc"]}。正式轮次不含 test/simsmall。Native/C4 样本数 {counts}。', '',*table,'',
        '待执行只表示未来任务；失败功能门之后的正式轮次不会越过功能门。Blackscholes/Canneal 的当前 profile 小输入缺项不以其他历史 profile 冒记通过。',
        '完整逐样本目标周期、宿主时间、有效性、身份与原始证据见 accepted-formal-samples.json / .csv；原样本未修改。']))
    print(json.dumps(dict(formal_samples=counts,reviews=[r['status'] for r in reviews], report=str(OUT/'16-program-round-status.md'))))


if __name__=='__main__':
    main()
