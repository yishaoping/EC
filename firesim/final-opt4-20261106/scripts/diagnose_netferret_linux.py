#!/usr/bin/env python3
"""Bounded independent evidence run for the Linux/user Ferret divergence."""
import base64
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys

from board_batch import W, D, save, sha
from job_service import proc

JOINED = '--joined-candidate' in sys.argv
STABLE = JOINED or '--stable-candidate' in sys.argv
SENTINEL = STABLE or '--sentinel-candidate' in sys.argv
PREFIX = 'netferret-stable-joined-candidate' if JOINED else ('netferret-stable-candidate' if STABLE else ('netferret-sentinel-candidate' if SENTINEL else 'netferret-linux-diagnostic'))
LINUX_PREFIX = 'netferret-stable-joined-linux' if JOINED else ('netferret-stable-linux' if STABLE else ('netferret-sentinel-linux' if SENTINEL else 'netferret-diagnostic-linux'))
R = D/'software'/(PREFIX+'-state.json')


def main():
    lock = (D/'software'/(PREFIX+'.lock')).open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if R.exists():
        state = json.loads(R.read_text())
        if state['status'] == 'COMPLETE_REVIEW_EVIDENCE':
            return
    else:
        stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        state = dict(status='BUILDING', output_dir=str(W/'software'/(PREFIX+'-'+stamp)),
                     log_dir=str(D/'software'/(PREFIX+'-'+stamp)),
                     formal_eligible=False, fpga_execution=False, commands=[])
    state.update(pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
                 host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    out, logs = Path(state['output_dir']), Path(state['log_dir'])
    out.mkdir(exist_ok=True); logs.mkdir(exist_ok=True); save(R, state)
    original = json.loads((W/'software/netferret-protocol-candidate-build.json').read_text())
    src = Path(original['output_dir'])/'server.c'
    text = src.read_text()
    if SENTINEL:
        assert text.count('if (p.dist == HUGE_VAL) continue;') == 1
        text = text.replace('if (p.dist == HUGE_VAL) continue;',
            'if (p.dist == HUGE_VAL || p.dist == CASS_DIST_MAX) continue;')
    if STABLE:
        text=text.replace('/* 4. accept and enqueue */',
            'fprintf(stderr, "EC_NET_LISTEN_READY\\n");\n\tfflush(stderr);\n\t/* 4. accept and enqueue */')
        if JOINED:
            assert text.count('tpool_cancel(p_acceptor);') == 1
            text=text.replace('tpool_cancel(p_acceptor);',
                'tpool_cancel(p_acceptor);\n\t/* Cancellation is asynchronous; join before freeing pool/application state. */\n\tfor (int ec_i=0; ec_i<p_acceptor->nthreads; ++ec_i) { int ec_rc=pthread_join(p_acceptor->threads[ec_i], NULL); assert(ec_rc==0); }')
    else:
        text = text.replace('assert(obj != NULL);',
        'fprintf(stderr, "EC_FERRET_RANK id=%u dist=%a max=%a obj=%p\\n", p.id, (double)p.dist, (double)CASS_DIST_MAX, (void *)obj);\n\t\t\tassert(obj != NULL);')
        text = text.replace('ec_recv_exact(fd, pkt_ptr->buf, pkt_ptr->len);',
        'ec_recv_exact(fd, pkt_ptr->buf, pkt_ptr->len);\n'
        '        unsigned long long ec_hash = 1469598103934665603ULL;\n'
        '        for (int ec_i=0; ec_i<pkt_ptr->len; ++ec_i) ec_hash = (ec_hash ^ (unsigned char)pkt_ptr->buf[ec_i]) * 1099511628211ULL;\n'
        '        fprintf(stderr, "EC_FERRET_FRAME bytes=%d fnv=%016llx\\n", pkt_ptr->len, ec_hash);')
    target = out/'server.c'; target.write_text(text)
    patch = logs/'diagnostic.patch'; patch.write_text(''.join(difflib.unified_diff(src.read_text().splitlines(True), text.splitlines(True), fromfile=str(src), tofile=str(target))))
    state['patch'] = dict(path=str(patch), sha256=sha(patch)); save(R, state)
    prep = json.loads((D/'software/netferret-protocol-preparation.json').read_text())
    commands = prep['commands'][:2]
    server = out/'netferret/server/parsec/bin/ferret-pthreads'; server.parent.mkdir(parents=True, exist_ok=True)
    obj = out/'server.o'
    def run(label, argv, timeout=600):
        log = logs/(label+'.log')
        with log.open('ab', buffering=0) as stream:
            child = subprocess.Popen(['nice', '-n', '15', *map(str, argv)], stdout=stream,
                stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True,
                env={**os.environ, 'PYTHONPATH':str(W/'scripts'), 'EC_NETWORK_NO_TRACE':'1'})
            state.update(status='RUNNING', stage=label, child_pid=child.pid, child_start_ticks=proc(child.pid)['start_ticks']); save(R, state)
            rc=child.wait(timeout=timeout)
            os.fsync(stream.fileno())
        state.pop('child_pid', None); state.pop('child_start_ticks', None)
        state['commands'].append(dict(label=label, argv=list(map(str, argv)), returncode=rc, log=str(log))); save(R,state)
        return rc
    if not server.exists():
        argv=commands[0]['argv']; argv=[str(target) if a==str(src) else str(obj) if a==str(src.parent/'server.o') else a for a in argv]
        assert run('build-object',argv)==0
        argv=commands[1]['argv']; old_server=original['programs']['netferret']['binaries']['server/parsec/bin/ferret-pthreads']['path']
        argv=[str(obj) if a==str(src.parent/'server.o') else str(server) if a==old_server else a for a in argv]
        assert run('build-link',argv)==0
    client=out/'netferret/client/client'; client.parent.mkdir(parents=True,exist_ok=True)
    if STABLE:
        original_client=Path(original['output_dir'])/'client.c'
        source=original_client.read_text();start=source.index('int dir_helper (');end=source.index('/* the whole path',start)
        source=source[:start]+'''int dir_helper (char *dir, char *head)
{
    struct dirent **entries = NULL;
    int count = scandir(dir, &entries, NULL, alphasort);
    if (count < 0) { perror("scandir"); return -1; }
    int rc = 0;
    for (int i = 0; i < count; ++i) {
        if (!rc && scan_dir(entries[i]->d_name, head) != 0) rc = -1;
        free(entries[i]);
    }
    free(entries);
    return rc;
}

'''+source[end:]
        client_source=out/'client.c';client_source.write_text(source)
        client_patch=logs/'client-stable-order.patch';client_patch.write_text(''.join(difflib.unified_diff(original_client.read_text().splitlines(True),source.splitlines(True),fromfile=str(original_client),tofile=str(client_source))))
        argv=prep['commands'][2]['argv'];original_binary=original['programs']['netferret']['binaries']['client/client']['path']
        argv=[str(client_source) if a==str(original_client) else str(client) if a==original_binary else a for a in argv]
        if not client.exists():assert run('build-client',argv)==0
        state['client_patch']=dict(path=str(client_patch),sha256=sha(client_patch));save(R,state)
    elif not client.exists(): client.symlink_to(original['programs']['netferret']['binaries']['client/client']['path'])
    receipt=copy.deepcopy(original);receipt.update(output_dir=str(out),profile=PREFIX+'/1',formal_eligible=False,
        software_delta={k:state[k] for k in ['patch','client_patch'] if k in state})
    receipt['programs']['netferret']['binaries']={k:dict(path=str(p),sha256=sha(p)) for k,p in [('server/parsec/bin/ferret-pthreads',server),('client/client',client)]}
    receipt_path=out/'receipt.json';save(receipt_path,receipt);state['receipt']=str(receipt_path);save(R,state)
    if SENTINEL:
        user=out/'user.py'
        user_text=(W/'scripts/validate_network_candidates.py').read_text().replace("W/'software/network-candidate-build.json'",repr(str(receipt_path)))
        if STABLE:
            user_text=user_text.replace("peers=[('server',server),('client',client)] if arch=='riscv64-kernel' else [('client',client),('server',server)]", "peers=[('server',server),('client',client)]")
            user_text=user_text.replace("            if arch=='riscv64-kernel' and label=='server':", """            if arch=='riscv64' and label=='server':
                deadline=time.monotonic()+30
                while 'EC_NET_LISTEN_READY' not in (out/'server.log').read_text(errors='replace'):
                    assert p.poll() is None, 'server exited before readiness'
                    if time.monotonic()>deadline: raise TimeoutError('private user TCP listen readiness')
                    time.sleep(.05)
            if arch=='riscv64-kernel' and label=='server':""")
        user.write_text(user_text)
        for size in ['test','simsmall','simmedium']:
            dst=logs/('user-'+size)
            if (dst/'result.json').exists(): continue
            dst.mkdir(exist_ok=True)
            run('user-'+size,['unshare','--ipc','--mount','--net','--fork',sys.executable,str(user),'--case','netferret','--size',size,'--out',str(dst)],timeout=1900)
    linux=out/'linux.py';text=(W/'scripts/validate_network_linux.py').read_text()
    for a,b in [("W/'software/network-candidate-build.json'",repr(str(receipt_path))),
                ("R=D/'software/network-linux-validation.json'", "R=D/'software/"+LINUX_PREFIX+"-validation.json'"),
                ("'software/network-linux-validation.lock'","'software/"+LINUX_PREFIX+"-validation.lock'"),
                ("'network-linux-'+stamp","'"+LINUX_PREFIX+"-'+stamp"),
                ("for size in ['test','simsmall','simmedium']:","for size in ['test','simsmall','simmedium']:" if SENTINEL else "for size in ['test','simsmall']:"),
                ("for name in ['netdedup','netferret','netstreamcluster']:","for name in ['netferret']:"),
                ('wait "$server_pid"; server_rc=$?', 'wait "$server_pid"; server_rc=$?\nif [ "$server_rc" -ne 0 ]; then kill "$client_pid"; fi'),
                ('/bin/busybox sha256sum OUTPUT', '/bin/busybox sha256sum OUTPUT\necho EC_NET_DUMP_BEGIN\n/bin/busybox cat OUTPUT\necho EC_NET_DUMP_END')]:
        text=text.replace(a,b)
    if STABLE:
        old='''CLIENT > /run/client.log 2>&1 &
client_pid=$!
SERVER > /run/server.log 2>&1 &
server_pid=$!'''
        new='''SERVER > /run/server.log 2>&1 &
server_pid=$!
ready=0
while ! /bin/busybox grep -q EC_NET_LISTEN_READY /run/server.log; do
    ready=$((ready+1))
    if [ "$ready" -gt 600 ] || ! kill -0 "$server_pid"; then
        /bin/busybox cat /run/server.log
        echo EC_NET_LISTEN_FAILED
        /bin/busybox poweroff -f
    fi
    /bin/busybox sleep 0.05
done
CLIENT > /run/client.log 2>&1 &
client_pid=$!'''
        assert old in text
        text=text.replace(old,new)
    linux.write_text(text)
    linux_path=D/'software'/(LINUX_PREFIX+'-validation.json')
    if not linux_path.exists() or json.loads(linux_path.read_text())['status']!='COMPLETE_REVIEW_EVIDENCE':
        assert run('linux', [sys.executable, str(linux)],timeout=5400)==0
    linux_state=json.loads(linux_path.read_text())
    for case in linux_state['cases']:
        result=Path(case['result']);console=(result.parent/'console.log').read_text(errors='replace')
        output=result.parent/'captured-output.txt'
        if 'EC_NET_DUMP_BEGIN' in console and 'EC_NET_DUMP_END' in console:
            body=console.split('EC_NET_DUMP_BEGIN',1)[1].split('EC_NET_DUMP_END',1)[0].strip('\r\n')+'\n'
            output.write_text(body)
        ranks=[l for l in console.splitlines() if 'EC_FERRET_RANK' in l]
        frames=[l for l in console.splitlines() if 'EC_FERRET_FRAME' in l]
        state.setdefault('cases',{})[case['input']]=dict(result=str(result),ranks=ranks,frames=frames)
        if SENTINEL and output.exists():
            user_result=logs/('user-'+case['input'])/'result.json'
            ur=json.loads(user_result.read_text())
            if 'output' in ur:
                expected=Path(ur['output']['path']).read_text().splitlines()
                actual=output.read_text().splitlines()
                assert len(actual)==len(set(l.split('\t')[0] for l in actual)), 'duplicate query output'
                state['cases'][case['input']].update(
                    captured_output=str(output),exact_repaired_user_output=actual==expected,
                    same_query_results=sorted(actual)==sorted(expected),queries=len(actual),
                    user_result=str(user_result))
    state.update(status='COMPLETE_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,state)


if __name__ == '__main__':
    main()
