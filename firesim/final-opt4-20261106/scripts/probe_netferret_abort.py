#!/usr/bin/env python3
"""Separate bounded software-only probe; retain abort semantics and full ROI."""
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

JOIN = '--join-cancel' in sys.argv
PREFIX = 'netferret-join-probe' if JOIN else 'netferret-abort-probe'
R = D/'software'/(PREFIX+'-state.json')


def main():
    lock = (D/'software'/(PREFIX+'.lock')).open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if R.exists():
        st = json.loads(R.read_text())
        if st['status'] == 'COMPLETE_REVIEW_EVIDENCE':
            return
    else:
        stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        st = dict(status='BUILDING', output_dir=str(W/'software'/(PREFIX+'-'+stamp)),
                  log_dir=str(D/'software'/(PREFIX+'-'+stamp)),
                  formal_eligible=False, fpga_execution=False, commands=[])
    st.update(pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    out, logs = Path(st['output_dir']), Path(st['log_dir'])
    out.mkdir(exist_ok=True); logs.mkdir(exist_ok=True)
    save(R, st)
    prior = json.loads((D/'software/netferret-stable-candidate-state.json').read_text())
    base = Path(prior['output_dir'])
    source = base/'server.c'
    text = source.read_text()
    if JOIN:
        assert text.count('tpool_cancel(p_acceptor);') == 1
        text = text.replace('tpool_cancel(p_acceptor);', 'tpool_cancel(p_acceptor);\n\tfor (int ec_i=0; ec_i<p_acceptor->nthreads; ++ec_i) { int ec_rc=pthread_join(p_acceptor->threads[ec_i], NULL); fprintf(stderr, "EC_CANCEL_JOIN_RC=%d\\n", ec_rc); assert(ec_rc==0); }')
    for call in ['cass_env_close(env, 0)', 'cass_cleanup()', 'image_cleanup()', '__parsec_bench_end()']:
        line = 'ret = '+call+';' if call.startswith('cass_env_close') else call+';'
        assert text.count(line) == 1
        text = text.replace(line, 'fprintf(stderr, "EC_CLEANUP_BEFORE '+call+'\\n");\n\t'+line+
                            '\n\tfprintf(stderr, "EC_CLEANUP_AFTER '+call+'\\n");')
    text += '\nextern void __real_abort(void);\nvoid __wrap_abort(void) { fprintf(stderr, "EC_ABORT_CALLER=%p\\n", __builtin_return_address(0)); fflush(stderr); __real_abort(); __builtin_unreachable(); }\n'
    target = out/'server.c'; target.write_text(text)
    patch = logs/'abort-probe.patch'
    patch.write_text(''.join(difflib.unified_diff(source.read_text().splitlines(True), text.splitlines(True), fromfile=str(source), tofile=str(target))))
    st['patch'] = dict(path=str(patch), sha256=sha(patch)); save(R, st)
    def run(label, argv, timeout=900):
        with (logs/(label+'.log')).open('ab', buffering=0) as log:
            p = subprocess.Popen(['nice', '-n', '15', *argv], stdout=log, stderr=subprocess.STDOUT,
                                 stdin=subprocess.DEVNULL, start_new_session=True,
                                 env={**os.environ, 'PYTHONPATH':str(W/'scripts')})
            st.update(status='RUNNING', stage=label, child_pid=p.pid, child_start_ticks=proc(p.pid)['start_ticks']); save(R, st)
            rc = p.wait(timeout=timeout); os.fsync(log.fileno())
        st.pop('child_pid', None); st.pop('child_start_ticks', None)
        st['commands'].append(dict(label=label, argv=argv, returncode=rc, log=str(logs/(label+'.log')))); save(R, st)
        assert rc == 0
    server = out/'netferret/server/parsec/bin/ferret-pthreads'
    server.parent.mkdir(parents=True, exist_ok=True)
    if not server.exists():
        for command in prior['commands'][:2]:
            argv = [str(target) if a == str(source) else a.replace(str(base), str(out)) if a.startswith(str(base)) else a for a in command['argv']]
            if command['label'] == 'build-link':
                argv.insert(1, '-Wl,--wrap=abort')
            run(command['label'], argv)
    receipt = copy.deepcopy(json.loads((base/'receipt.json').read_text()))
    receipt.update(output_dir=str(out), profile=PREFIX+'/1', formal_eligible=False)
    receipt['programs']['netferret']['binaries']['server/parsec/bin/ferret-pthreads'] = dict(path=str(server), sha256=sha(server))
    bound = out/'receipt.json'; save(bound, receipt)
    st['receipt'] = dict(path=str(bound), sha256=sha(bound)); save(R, st)
    linux = out/'linux.py'
    text = (base/'linux.py').read_text()
    text = text.replace(str(base/'receipt.json'), str(bound)).replace('netferret-stable-linux', PREFIX+'-linux')
    text = text.replace("for size in ['test','simsmall','simmedium']:", "for size in ['test']:")
    linux.write_text(text)
    run('linux-test', [sys.executable, str(linux)], timeout=600)
    st.update(status='COMPLETE_REVIEW_EVIDENCE', ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(R, st)


if __name__ == '__main__':
    main()
