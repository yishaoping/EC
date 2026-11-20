#!/usr/bin/env python3
"""Isolated client lifetime candidate; original coordinator owns all FPGA work.

The client keeps its userspace TCP threads alive until the server closes. No
application data, server work, original ROI hooks, or ACK drain is removed.
QEMU diagnostic hooks establish software correctness only, never checker gates.
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
from prepare_network_native import run_logged
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R = D/'software/netstreamcluster-graceful-close.json'
PREFIX = 'netstreamcluster-graceful-close-v3'


def read(p):
    return json.loads(Path(p).read_text())


def main():
    lock = (D/'software/netstreamcluster-graceful-close.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    st = read(R) if R.exists() else {}
    if st.get('status') == 'OFFLINE_PASSED_NATIVE_PROFILE_ADMITTED':
        return
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = Path(st.setdefault('output_dir', str(W/'software'/('netstreamcluster-graceful-close-'+stamp))))
    logs = Path(st.setdefault('log_dir', str(D/'software'/out.name)))
    out.mkdir(exist_ok=True); logs.mkdir(exist_ok=True)
    st.update(status='BUILDING_CLIENT', pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              hardware_modified=False, cad_modified=False, scheduler_modified=False,
              fpga_execution=False, cases=st.get('cases', {}))
    save(R, st)
    base = read(W/'software/network-candidate-build.json')
    wait = read(D/'software/network-native-wait-diagnosis.json')
    prior_profile = read(D/'software/network-native-wait-profile.json')
    parent_apps_path = Path(prior_profile['apps_receipt'])
    parent_apps = read(parent_apps_path)
    parent_fs = read(prior_profile['rootfs_receipt'])
    parent_tree = Path(parent_fs['path']).parent/'tree'
    entry = next(c for c in base['commands'] if c['label'] == 'netstreamcluster-client')
    source = Path(base['output_dir'])/'netstreamcluster/client/client.cpp'
    original = source.read_text()
    anchor = '  pthread_barrier_wait(&thread_barrier);\n\nout:'
    assert original.count(anchor) == 1
    text = original.replace(anchor, '''#ifdef ENABLE_PARSEC_UPTCPIP
  /* Unlike a kernel TCP socket, this TCP stack dies with the process.
   * Keep its ACK/FIN workers alive until the server has closed the stream.
   * No further application payload is expected after its original ACK. */
  {
    char unexpected;
    int ec_eof = uptcp_recv(sd, &unexpected, sizeof(unexpected), 0);
    if (ec_eof != 0) {
      fprintf(stderr, "EC_NETSTREAM_CLOSE_FAILED recv=%d errno=%d\\n", ec_eof, errno);
      exit(1);
    }
    fprintf(stderr, "EC_NETSTREAM_SERVER_EOF tid=%d\\n", tid);
  }
#endif
  pthread_barrier_wait(&thread_barrier);

out:''')
    target = out/'client-graceful-close.cpp'; target.write_text(text)
    patch = logs/'client-graceful-close.patch'
    patch.write_text(''.join(difflib.unified_diff(original.splitlines(True), text.splitlines(True),
                                              fromfile=str(source), tofile=str(target))))
    st['patch'] = dict(path=str(patch), sha256=sha(patch), source=str(source),
                       source_sha256=sha(source), candidate_source_sha256=sha(target))
    client = out/'netstreamclusterclient'
    if 'client' not in st:
        argv = list(entry['argv']); argv[argv.index(str(source))] = str(target)
        argv[argv.index('-o')+1] = str(client)
        run_logged(['nice', '-n', '15', *argv], logs/'client-build.log')
        st['client'] = dict(path=str(client), sha256=sha(client), argv=argv)
        save(R, st)
    assert sha(client) == st['client']['sha256']
    for kind in ['diagnostic', 'real-hooks']:
        assert sha(wait['builds'][kind]['path']) == wait['builds'][kind]['sha256']
    prior = read(D/'software/fluidanimate-stable-order-candidate.json')['argv']
    qemu, kernel = prior[0], prior[prior.index('-kernel')+1]

    def case(size, icount):
        label = size+'-icount'+str(icount); dst = logs/label
        if (dst/'result.json').exists():
            result = read(dst/'result.json')
            assert result['client_sha256'] == st['client']['sha256']
            return label, result
        dst.mkdir(exist_ok=True); work = out/label
        if work.exists():
            work.rename(work.with_name(work.name+'-interrupted-'+stamp))
        tree = work/'tree'; shutil.copytree(parent_tree, tree, symlinks=True)
        shutil.copy2(wait['builds']['diagnostic']['path'], tree/'opt/ec-fpga/netstreamcluster')
        shutil.copy2(client, tree/'opt/ec-fpga/netstreamclusterclient')
        init = '''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
cd /tmp
/bin/busybox cp -R /opt/ec-fpga/inputs/netstreamcluster/SIZE/. .
/bin/sh /opt/ec-fpga/run-network netstreamcluster SIZE
echo EC_NETWORK_WRAPPER_EXIT=$?
/bin/busybox poweroff -f
'''.replace('SIZE', size)
        (tree/'init').write_text(init); (tree/'init').chmod(0o755)
        image = work/'initramfs.cpio'; cpio_newc(tree, image)
        argv = [qemu, '-machine', 'virt', '-cpu', 'rv64', '-m', '2G', '-smp', '1',
                '-nographic', '-no-reboot', '-bios', 'default', '-kernel', kernel,
                '-initrd', str(image), '-append', 'console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
        if icount is not None:
            argv += ['-icount', f'shift={icount},align=off,sleep=off']
        result = dict(program='netstreamcluster', input=size, argv=argv,
                      client_sha256=st['client']['sha256'], rootfs_sha256=sha(image),
                      status='RUNNING', fpga_execution=False, formal_eligible=False,
                      diagnostic_hooks=True, host_boot_id=st['host_boot_id'])
        started = time.monotonic()
        with (dst/'console.log').open('wb', buffering=0) as stream:
            child = subprocess.Popen(['nice', '-n', '15', *argv], stdout=stream,
                stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, start_new_session=True,
                env={**os.environ, 'LD_LIBRARY_PATH': ''})
            result.update(pid=child.pid, start_ticks=proc(child.pid)['start_ticks'])
            save(dst/'state.json', result)
            try:
                rc = child.wait(timeout=1800)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid, signal.SIGTERM)
                try: child.wait(timeout=15)
                except subprocess.TimeoutExpired: os.killpg(child.pid, signal.SIGKILL); child.wait()
                rc = 124
            os.fsync(stream.fileno())
        console = (dst/'console.log').read_text(errors='replace').replace('\r', '')
        gates = dict(wrapper_zero=bool(re.search(r'^EC_NETWORK_WRAPPER_EXIT=0$', console, re.M)),
            peers_zero='EC_NETWORK_PEERS_EXIT program=netstreamcluster server=0 client=0' in console,
            exact_output=f'EC_NETWORK_COMPLETE program=netstreamcluster input={size} peers_exit_zero=1 output_exact=1' in console,
            server_eof='EC_NETSTREAM_SERVER_EOF tid=0' in console,
            complete_original_roi=console.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==console.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1,
            no_failure=not any(s in console for s in ['Kernel panic', 'EC_NETWORK_FAILURE program=', 'EC_NETSTREAM_CLOSE_FAILED', 'Assertion', 'Aborted']))
        result.update(status='OFFLINE_PASSED' if rc==0 and all(gates.values()) else 'FAILED_WITH_EVIDENCE',
                      returncode=rc, gates=gates, host_wall_seconds=time.monotonic()-started,
                      log=str(dst/'console.log'), log_sha256=sha(dst/'console.log'))
        save(dst/'state.json', result); save(dst/'result.json', result)
        return label, result

    st['status'] = 'RUNNING_OFFLINE'; save(R, st)
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        futures = [pool.submit(case, size, icount) for size, icount in
                   [('test', 5), ('simsmall', None), ('simmedium', None)]]
        for future in concurrent.futures.as_completed(futures):
            label, result = future.result(); st['cases'][label] = result; save(R, st)
    if not all(r['status']=='OFFLINE_PASSED' for r in st['cases'].values()):
        st.update(status='FAILED_OFFLINE_PRESERVED_NOT_ADMITTED'); save(R, st); return
    apps = copy.deepcopy(parent_apps)
    apps.update(output_dir=str(out), software_profile='netstreamcluster-full-roi-graceful-client-close/3',
        parent_receipt=str(parent_apps_path), parent_receipt_sha256=sha(parent_apps_path),
        software_patch=st['patch'], offline_evidence=str(R),
        version_delta='Server joined-v2 ELF unchanged; client awaits server EOF before destroying userspace TCP; all original computation, input and outer server ROI sites retained',
        fpga_validation='NOT_RUN', status='OFFLINE_VALIDATED_FPGA_PENDING')
    apps['binaries'] = {n: b for n, b in apps['binaries'].items() if n in ['netstreamcluster', 'netstreamclusterclient']}
    apps['binaries']['netstreamclusterclient'] = {k: st['client'][k] for k in ['path', 'sha256']}
    apps['cases'] = [c for c in apps['cases'] if c['program']=='netstreamcluster']
    for c in apps['cases']:
        c.update(fpga_validation='NOT_RUN', software_patch=st['patch'])
        src = Path(parent_apps['output_dir'])/'inputs/netstreamcluster'/c['input']
        dst = out/'inputs/netstreamcluster'/c['input']
        if not dst.exists(): shutil.copytree(src, dst)
        assert {str(p.relative_to(dst)):sha(p) for p in dst.rglob('*') if p.is_file()} == c['input_files']
    ap = out/'apps-build.json'; save(ap, apps)
    fs_path = out/'rootfs-build.json'
    if not fs_path.exists():
        run_logged([sys.executable, W/'scripts/prepare_rootfs.py', '--apps-receipt', ap,
                    '--output-receipt', fs_path], logs/'rootfs.log')
    fs = read(fs_path)
    if 'network_launcher_sha256' not in fs:
        tree = Path(fs['path']).parent/'tree'; dst = tree/'opt/ec-fpga'; shell = dst/'run-one'
        text = shell.read_text(); anchor = '  /opt/ec-fpga/$program $argv >console.pipe 2>&1'
        assert text.count(anchor)==1
        shell.write_text(text.replace(anchor, '  /opt/ec-fpga/run-network "$program" "$input" >console.pipe 2>&1'))
        shutil.copy2(parent_tree/'opt/ec-fpga/run-network', dst/'run-network')
        for c in apps['cases']:
            (dst/'cases/netstreamcluster'/c['input']/'client-argv').write_text(' '.join(c['client_argv'])+'\n')
        for p in [shell, dst/'run-network']: subprocess.run(['/bin/sh', '-n', str(p)], check=True)
        (dst/'SHA256SUMS').write_text(''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file() and p.name!='SHA256SUMS'))
        image = tree.parent/'initramfs-network.cpio'; cpio_newc(tree, image)
        fs.update(path=str(image), sha256=sha(image), bytes=image.stat().st_size, shared_by=['Native'],
                  files={str(p.relative_to(tree)):sha(p) for p in tree.rglob('*') if p.is_file()},
                  network_launcher_sha256=sha(dst/'run-network'))
        save(fs_path, fs); save(image.parent/'manifest.json', fs)
    assert sha(fs['path'])==fs['sha256'] and fs['apps_manifest_sha256']==sha(ap)
    st.update(status='BUILDING_NATIVE_PAYLOAD', apps_receipt=str(ap), rootfs_receipt=str(fs_path)); save(R, st)
    prep = (W/'software/.profile-system-preparation.lock').open('a'); fcntl.flock(prep, fcntl.LOCK_EX)
    kr = out/'Native-kernel-build.json'; fw = out/'Native-firmware-build.json'
    previous = read(D/'software/network-native-preparation.json')
    parent_kr = Path(previous['native_build']['kernel_receipt'])
    if not kr.exists():
        run_logged([sys.executable, W/'scripts/build_earlyconsole.py', 'Native', '--parent-receipt', parent_kr,
            '--rootfs-receipt', fs_path, '--output-receipt', kr, '--build-root',
            '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'], logs/'Native-kernel.log')
    before, after = (Path(read(p)['output_dir']) for p in [parent_kr, kr])
    strip = lambda p:[l for l in (p/'.config').read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
    assert strip(before)==strip(after) and sha(before/'drivers/misc/ec_dac_roi.o')==sha(after/'drivers/misc/ec_dac_roi.o')
    if not fw.exists():
        run_logged([sys.executable, W/'scripts/build_system.py', 'Native', 'firmware', '--kernel-result', kr,
            '--fdt-result', W/'software/Native/fdt-mem2g-build.json', '--output-receipt', fw, '--build-root',
            '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds', '--jobs', '2',
            '--fdt-load-address', '0xbfe00000'], logs/'Native-firmware.log')
    assert read(fw)['returncode']==0
    for src, dst in [(ap, W/f'software/{PREFIX}-apps-build.json'),
                     (fs_path, W/f'software/{PREFIX}-rootfs-build.json'),
                     (fw, W/f'software/Native/{PREFIX}-firmware-build.json')]:
        if dst.exists(): assert dst.read_bytes()==src.read_bytes()
        else: save(dst, read(src))
    gate = (D/'locks/future-software-plan-update.lock').open('a'); fcntl.flock(gate, fcntl.LOCK_EX)
    active = read(D/'active-0000_21_00.0.json')
    # This service never stops a task. Wait if our own program is still active.
    while active.get('program')=='netstreamcluster' and active.get('status') in ['RUNNING', 'STARTING']:
        time.sleep(60); active = read(D/'active-0000_21_00.0.json')
    planpath = D/'suite-execution-plan.json'; plan = read(planpath)
    row = next(r for r in plan['programs'] if r['program']=='netstreamcluster')
    assert row['software_profile_prefix'] in ['netstreamcluster-receivers-joined-v2', PREFIX]
    old = sha(planpath); archive = D/'plan-history'/('before-netstreamcluster-graceful-close-'+stamp+'.json')
    save(archive, plan); row['software_profile_prefix']=PREFIX; save(planpath, plan)
    st.update(status='OFFLINE_PASSED_NATIVE_PROFILE_ADMITTED', firmware_receipt=str(fw),
        old_plan_sha256=old, new_plan_sha256=sha(planpath), plan_archive=str(archive),
        kernel_config_unchanged_except_initramfs=True, roi_driver_object_unchanged=True,
        fpga_started_by_this_service=False, c4_protocol_resolved=False,
        next_action='Original coverage-first alone runs test, simsmall, then formal only if real FPGA gates pass; C4 retains priority',
        ended_utc=dt.datetime.now(dt.timezone.utc).isoformat()); save(R, st)


if __name__=='__main__':
    main()
