#!/usr/bin/env python3
"""Independent, bounded network shutdown diagnosis; no FPGA/CAD operations.

Keep original evidence and software immutable. Candidate joins receive workers
before their stack-owned queue disappears; original ROI hook sites stay intact.
QEMU diagnostic hooks do not establish real ROI/checker validity.
"""
import concurrent.futures
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import time

from board_batch import W, D, save, sha
from job_service import proc
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R = D/'software/network-native-wait-diagnosis.json'


def read(p):
    return json.loads(Path(p).read_text())


def main():
    lock = (D/'software/network-native-wait-diagnosis.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    st = read(R) if R.exists() else {}
    if st.get('status') == 'COMPLETE_OFFLINE_REVIEW_REQUIRED':
        return
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = Path(st.setdefault('output_dir', str(W/'software'/('network-native-wait-'+stamp))))
    logs = Path(st.setdefault('log_dir', str(D/'software'/out.name)))
    out.mkdir(exist_ok=True); logs.mkdir(exist_ok=True)
    st.update(status='PREPARING', pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              hardware_modified=False, cad_modified=False, scheduler_modified=False,
              fpga_execution=False, formal_eligible=False, cases=st.get('cases', {}))
    save(R, st)
    base = read(W/'software/network-candidate-build.json')
    source = Path(base['output_dir'])/'netstreamcluster/server/streamcluster.cpp'
    original = source.read_text()
    text = original.replace('static pthread_mutex_t    queue_lock = PTHREAD_MUTEX_INITIALIZER;',
        'static pthread_mutex_t    queue_lock = PTHREAD_MUTEX_INITIALIZER;\n'
        'static pthread_t ec_receive_threads[MAX_THREAD];\nstatic int ec_receive_count;')
    assert text.count('  pthread_t       thread_id[MAX_THREAD];') == 1
    text = text.replace('  pthread_t       thread_id[MAX_THREAD];', '')
    text = text.replace('&thread_id[thread_count]', '&ec_receive_threads[thread_count]')
    assert text.count('  return thread_count;') == 1
    text = text.replace('  return thread_count;', '  ec_receive_count = thread_count;\n  return thread_count;')
    anchor = '  outcenterIDs( &centers, centerIDs, outfile);\n}'
    assert text.count(anchor) == 1
    text = text.replace(anchor, '''  outcenterIDs( &centers, centerIDs, outfile);
  /* The receive workers still own arguments pointing at this stack queue.
   * Finish their original ACK/close/statistics work before leaving its scope. */
  for (int ec_i = 0; ec_i < ec_receive_count; ++ec_i) {
    int ec_rc = pthread_join(ec_receive_threads[ec_i], NULL);
    if (ec_rc) { fprintf(stderr, "receive pthread_join failed: %d\\n", ec_rc); exit(1); }
  }
}''')
    # Explicitly preserve both original outer ROI sites and all computation.
    assert text.count('__parsec_roi_begin();') == original.count('__parsec_roi_begin();') == 1
    assert text.count('__parsec_roi_end();') == original.count('__parsec_roi_end();') == 1
    target = out/'streamcluster-receivers-joined.cpp'; target.write_text(text)
    patch = logs/'netstreamcluster-receive-lifetime.patch'
    patch.write_text(''.join(difflib.unified_diff(original.splitlines(True), text.splitlines(True),
                                              fromfile=str(source), tofile=str(target))))
    st['candidate_patch'] = dict(path=str(patch), sha256=sha(patch),
        source_sha256=sha(source), candidate_source_sha256=sha(target),
        hypothesis='Server can return before unjoined receiver finishes ACK/close; FPGA root cause not yet proved',
        roi='Original outer hook sites; full receive/compute work retained; added required receive join inside them')
    st['builds'] = st.get('builds', {})
    runtime = read(W/'software/network-runtime-candidates.json')
    for kind in ['diagnostic', 'real-hooks']:
        dst = out/('netstreamcluster-'+kind)
        if kind not in st['builds']:
            entry = (next(c for c in base['commands'] if c['label']=='netstreamcluster-server') if kind=='diagnostic'
                     else next(c for c in runtime['commands'] if c['program']=='netstreamcluster'))
            argv = list(entry['argv'])
            argv[argv.index(str(source))] = str(target)
            argv[argv.index('-o')+1] = str(dst)
            log = logs/('build-'+kind+'.log')
            with log.open('wb', buffering=0) as stream:
                rc = subprocess.run(['nice','-n','15', *argv], stdout=stream,
                    stderr=subprocess.STDOUT, timeout=180,
                    env={**os.environ,'LD_LIBRARY_PATH':''}).returncode
                os.fsync(stream.fileno())
            assert rc == 0, (kind, str(log))
            st['builds'][kind] = dict(path=str(dst), sha256=sha(dst), argv=argv,
                                    log=str(log), log_sha256=sha(log))
            save(R, st)
        assert sha(dst) == st['builds'][kind]['sha256']
    # Improve failure evidence without changing application/ROI/timeout policy.
    fs = read(W/'software/netferret-rootfs-build.json')
    parent_tree = Path(fs['path']).parent/'tree'
    old_wrapper = (parent_tree/'opt/ec-fpga/run-network').read_text()
    anchor = 'trap cleanup EXIT\ntrap \'exit 124\' TERM INT'
    assert old_wrapper.count(anchor) == 1
    wrapper = old_wrapper.replace(anchor, '''finish() {
  rc=$?
  trap - EXIT TERM INT
  if [ "$rc" -ne 0 ]; then
    echo "EC_NETWORK_FAILURE program=$program input=$input exit=$rc"
    for role in server client; do
      case "$role" in server) peer=$server_pid ;; client) peer=$client_pid ;; esac
      echo "EC_NETWORK_FAILURE_LOG_BEGIN role=$role pid=$peer"
      /bin/busybox tail -c 262144 "network-$role.log" 2>/dev/null || true
      echo "EC_NETWORK_FAILURE_LOG_END role=$role"
      if [ -n "$peer" ]; then
        for task in /proc/$peer/task/*; do
          [ -d "$task" ] || continue
          echo "EC_NETWORK_FAILURE_TASK role=$role task=$task"
          /bin/busybox cat "$task/stat" "$task/wchan" "$task/syscall" 2>/dev/null || true
          echo
        done
      fi
    done
    /bin/busybox sha256sum output.txt 2>/dev/null || true
    /bin/busybox cat network-watchdog.log 2>/dev/null || true
  fi
  cleanup
  exit "$rc"
}
trap finish EXIT
trap 'exit 124' TERM INT''')
    wrapper_path = out/'run-network'; wrapper_path.write_text(wrapper); wrapper_path.chmod(0o755)
    subprocess.run(['/bin/sh','-n',str(wrapper_path)], check=True)
    st['failure_capture'] = dict(path=str(wrapper_path), sha256=sha(wrapper_path),
        parent_sha256=sha(parent_tree/'opt/ec-fpga/run-network'), unchanged_timeouts=True)
    save(R, st)
    prior = read(D/'software/fluidanimate-stable-order-candidate.json')['argv']
    qemu, kernel = prior[0], prior[prior.index('-kernel')+1]
    probe = read(D/'software/network-complete-roi-probe.json')
    ferret = read(probe['cases']['netferret']['diagnostic_receipt']['path'])
    ferret_diag = next(b for n,b in ferret['programs']['netferret']['binaries'].items() if n.startswith('server/'))
    cases = [('netstreamcluster','test','baseline',5),
             ('netstreamcluster','test','joined',5),
             ('netstreamcluster','simsmall','joined',None),
             ('netstreamcluster','simmedium','joined',None),
             ('netferret','simsmall','baseline',None),
             ('netferret','simmedium','baseline',None)]

    def case(row):
        name, size, variant, icount = row
        label = '-'.join([name,size,variant,'icount'+str(icount)])
        dst = logs/label
        if (dst/'result.json').exists():
            return label, read(dst/'result.json')
        dst.mkdir(exist_ok=True)
        work = out/label
        if work.exists():
            work.rename(work.with_name(work.name+'-interrupted-'+stamp))
        tree = work/'tree'; shutil.copytree(parent_tree, tree, symlinks=True)
        server = (ferret_diag if name=='netferret' else
                  st['builds']['diagnostic'] if variant=='joined' else
                  base['programs'][name]['binaries']['server/server'])
        assert sha(server['path']) == server['sha256']
        shutil.copy2(server['path'], tree/'opt/ec-fpga'/name)
        shutil.copy2(wrapper_path, tree/'opt/ec-fpga/run-network')
        init = '''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
cd /tmp
/bin/busybox cp -R /opt/ec-fpga/inputs/NAME/SIZE/. .
/bin/sh /opt/ec-fpga/run-network NAME SIZE
echo EC_NETWORK_WRAPPER_EXIT=$?
/bin/busybox poweroff -f
'''.replace('NAME',name).replace('SIZE',size)
        (tree/'init').write_text(init); (tree/'init').chmod(0o755)
        image = work/'initramfs.cpio'; cpio_newc(tree,image)
        argv = [qemu,'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot',
                '-bios','default','-kernel',kernel,'-initrd',str(image),'-append',
                'console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
        if icount is not None: argv += ['-icount',f'shift={icount},align=off,sleep=off']
        result = dict(program=name,input=size,variant=variant,argv=argv,status='RUNNING',
            server_elf=server, wrapper_sha256=sha(wrapper_path), rootfs_sha256=sha(image),
            fpga_execution=False, formal_eligible=False, diagnostic_hooks=True)
        started = time.monotonic()
        with (dst/'console.log').open('wb',buffering=0) as stream:
            child = subprocess.Popen(['nice','-n','15',*argv],stdout=stream,stderr=subprocess.STDOUT,
                                     stdin=subprocess.DEVNULL,start_new_session=True,
                                     env={**os.environ,'LD_LIBRARY_PATH':''})
            result.update(pid=child.pid,start_ticks=proc(child.pid)['start_ticks'],host_boot_id=st['host_boot_id'])
            save(dst/'state.json',result)
            try: rc=child.wait(timeout=1800)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid,signal.SIGTERM)
                try: child.wait(timeout=15)
                except subprocess.TimeoutExpired: os.killpg(child.pid,signal.SIGKILL);child.wait()
                rc=124
            os.fsync(stream.fileno())
        console=(dst/'console.log').read_text(errors='replace').replace('\r','')
        gates=dict(wrapper_zero=bool(re.search(r'^EC_NETWORK_WRAPPER_EXIT=0$',console,re.M)),
            peers_zero=f'EC_NETWORK_PEERS_EXIT program={name} server=0 client=0' in console,
            exact_output=f'EC_NETWORK_COMPLETE program={name} input={size} peers_exit_zero=1 output_exact=1' in console,
            original_roi=console.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==console.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1,
            no_failure=not any(s in console for s in ['Kernel panic','EC_NETWORK_FAILURE program=','Assertion','Aborted']))
        result.update(status='OFFLINE_PASSED' if rc==0 and all(gates.values()) else 'FAILED_WITH_EVIDENCE',
            returncode=rc,gates=gates,host_wall_seconds=time.monotonic()-started,
            log=str(dst/'console.log'),log_sha256=sha(dst/'console.log'),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(dst/'state.json',result);save(dst/'result.json',result)
        return label,result

    st['status']='RUNNING_OFFLINE';save(R,st)
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        futures=[pool.submit(case,row) for row in cases]
        for future in concurrent.futures.as_completed(futures):
            label,result=future.result();st['cases'][label]=dict(status=result['status'],gates=result['gates'],log=result['log'])
            save(R,st)
    st.update(status='COMPLETE_OFFLINE_REVIEW_REQUIRED',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        next_action='Review immutable candidate evidence, then real-hook 21-only FPGA validation at safe boundary; never count diagnostic runs as formal')
    save(R,st)


if __name__=='__main__':
    main()
