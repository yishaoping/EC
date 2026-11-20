#!/usr/bin/env python3
"""Bind existing full-ROI network programs to the unchanged Native runtime.

Uses the existing queue; never deploys hardware or changes a running service.
C4 remains explicitly incompatible with the original threaded/trapping ROI.
"""
import concurrent.futures
import copy
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import subprocess
import sys
import tarfile
import time

from board_batch import W, D, save, sha
from job_service import proc
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R = D/'software/network-native-preparation.json'
NAMES = ['netdedup', 'netferret', 'netstreamcluster']
SIZES = ['test', 'simsmall', 'simmedium']
C4_BLOCK = ('Full original network ROI requires syscall, thread scheduling and '
            'context support absent from the frozen C4 monitor/firmware protocol. '
            'No checker/fault masking or ROI subdivision is permitted.')

WRAPPER = '''#!/bin/sh
set -eu
export UPTCPIP_RX_THREADS=1 OMP_NUM_THREADS=1 PARSEC_NUM_THREADS=1
program=$1; input=$2
case_dir=/opt/ec-fpga/cases/$program/$input
server_args=$(/bin/busybox cat "$case_dir/argv")
client_args=$(/bin/busybox cat "$case_dir/client-argv")
server_pid=; client_pid=; watchdog=
cleanup() {
  [ -z "$watchdog" ] || kill "$watchdog" 2>/dev/null || true
  [ -z "$server_pid" ] || kill "$server_pid" 2>/dev/null || true
  [ -z "$client_pid" ] || kill "$client_pid" 2>/dev/null || true
}
trap cleanup EXIT
trap 'exit 124' TERM INT
/opt/ec-fpga/$program $server_args > network-server.log 2>&1 &
server_pid=$!
# The repaired Netferret explicitly publishes listen readiness. The other
# original user-TCP clients retry until their server accepts the connection.
if [ "$program" = netferret ]; then
  tries=0
  while ! /bin/busybox grep -q EC_NET_LISTEN_READY network-server.log; do
    kill -0 "$server_pid" 2>/dev/null || { /bin/busybox cat network-server.log; exit 1; }
    tries=$((tries + 1)); [ "$tries" -le 200 ] || exit 124
    /bin/busybox sleep 0.05
  done
fi
/opt/ec-fpga/${program}client $client_args > network-client.log 2>&1 &
client_pid=$!
echo "EC_NETWORK_PEERS_STARTED program=$program input=$input server=$server_pid client=$client_pid"
case "$input" in test) limit=25 ;; simsmall) limit=300 ;; simmedium) limit=3600 ;; *) exit 2 ;; esac
owner=$$
(trap 'kill "$timer" 2>/dev/null || true; exit' TERM INT
 /bin/busybox sleep "$limit" & timer=$!
 wait "$timer"
 echo "EC_NETWORK_TIMEOUT program=$program input=$input"
 kill -TERM "$owner") </dev/null >network-watchdog.log 2>&1 &
watchdog=$!
set +e
wait "$server_pid"; server_rc=$?; server_pid=
wait "$client_pid"; client_rc=$?; client_pid=
set -e
kill "$watchdog" 2>/dev/null || true; wait "$watchdog" 2>/dev/null || true; watchdog=
echo "EC_NETWORK_SERVER_LOG_BEGIN program=$program"
/bin/busybox cat network-server.log
echo "EC_NETWORK_SERVER_LOG_END program=$program"
echo "EC_NETWORK_CLIENT_LOG_BEGIN program=$program"
/bin/busybox cat network-client.log
echo "EC_NETWORK_CLIENT_LOG_END program=$program"
echo "EC_NETWORK_PEERS_EXIT program=$program server=$server_rc client=$client_rc"
[ "$server_rc" = 0 ] && [ "$client_rc" = 0 ]
if [ "$program" = netdedup ]; then
  /opt/ec-fpga/netdedup -u -o decoded.dat > network-decode.log 2>&1
  /bin/busybox cat network-decode.log
fi
/bin/busybox sha256sum -c "$case_dir/output-sha256sums"
echo "EC_NETWORK_COMPLETE program=$program input=$input peers_exit_zero=1 output_exact=1"
'''


def read(p):
    return json.loads(Path(p).read_text())


def run_logged(argv, log, timeout=1800):
    with Path(log).open('ab', buffering=0) as stream:
        p = subprocess.Popen(list(map(str, argv)), cwd=W, stdin=subprocess.DEVNULL,
                             stdout=stream, stderr=subprocess.STDOUT, start_new_session=True,
                             env={**os.environ, 'PATH':'/usr/bin:/bin', 'LD_LIBRARY_PATH':''})
        try:
            rc = p.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(p.pid, signal.SIGTERM)
            try: p.wait(timeout=15)
            except subprocess.TimeoutExpired:
                os.killpg(p.pid, signal.SIGKILL); p.wait()
            rc = 124
        os.fsync(stream.fileno())
    assert rc == 0, (argv, rc, str(log))


def main():
    lock = (D/'software/network-native-preparation.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    st = read(R) if R.exists() else {'cases':{}, 'commands':[]}
    if st.get('status') == 'BOUND_TO_EXISTING_NATIVE_QUEUE':
        return
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = Path(st.setdefault('output_dir', str(W/'software'/('network-native-'+stamp))))
    logs = Path(st.setdefault('log_dir', str(D/'software'/out.name)))
    out.mkdir(exist_ok=True); logs.mkdir(exist_ok=True)
    st.update(status='PREPARING', pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              started_utc=st.get('started_utc', dt.datetime.now(dt.timezone.utc).isoformat()),
              frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',
              hardware_modified=False, scheduler_modified=False, c4_blocker=C4_BLOCK)
    save(R, st)
    try:
        runtime = read(W/'software/network-runtime-candidates.json')
        probe = read(D/'software/network-complete-roi-probe.json')
        ferret_review = read(D/'software/network-recovery-20261109T043612Z/netferret-stable-joined-candidate-offline-review.json')
        appbase = read(W/'software/formal-apps-build.json')
        # Explicitly audit Native rather than applying C4 admission rules to it.
        native_driver = W/'software/Native/linux/drivers/misc/ec_dac_roi.c'
        native_monitor = W/'Native/chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala'
        assert 'get_nr_threads(current)' not in native_driver.read_text()
        assert 'faults := faults | 8.U' not in native_monitor.read_text()
        st['native_protocol_sources'] = {str(p):sha(p) for p in [native_driver,native_monitor]}
        binaries, cases, diagnostics = {}, [], {}
        source_receipts = {}
        for name in NAMES:
            item = probe['netferret_real_hooks'] if name=='netferret' else runtime['programs'][name]
            bs = item['binaries']
            for b in bs.values(): assert sha(b['path'])==b['sha256'], b['path']
            server = next(b for n,b in bs.items() if n.startswith('server/'))
            client = next(b for n,b in bs.items() if n.startswith('client/'))
            binaries[name] = server; binaries[name+'client'] = client
            source_receipts[name] = item
            diag_receipt = read(probe['cases'][name]['diagnostic_receipt']['path'])
            diagnostics[name] = next(b for n,b in diag_receipt['programs'][name]['binaries'].items() if n.startswith('server/'))
            for size in SIZES:
                inp = out/'inputs'/name/size; inp.mkdir(parents=True, exist_ok=True)
                if name=='netferret':
                    review = ferret_review['cases'][size]
                    assert all(review['gates'].values())
                    evidence = read(review['user_result']['path'])
                    expected = review['candidate_output']
                elif name=='netdedup':
                    linux = read(D/'software/netdedup-framed-linux-validation.json')
                    row = next(c for c in linux['cases'] if c['input']==size)
                    assert row['status']=='LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED'
                    lr = read(row['result']); evidence = read(lr['reference'])
                    expected = evidence['output']
                else:
                    linux = read(D/'software/network-linux-validation.json') if size=='test' else read(D/'software/netstreamcluster-linux-validation.json')
                    row = next(c for c in linux['cases'] if c['input']==size and c['program']==name)
                    assert row['status']=='LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED'
                    lr = read(row['result']); evidence = read(lr['reference'])
                    expected = evidence['output']
                assert sha(expected['path']) == expected['sha256']
                archive = evidence.get('input_archive')
                if archive:
                    assert sha(archive['path'])==archive['sha256']
                    with tarfile.open(archive['path']) as tf:
                        assert all(not Path(m.name).is_absolute() and '..' not in Path(m.name).parts and not m.issym() and not m.islnk() for m in tf.getmembers())
                        tf.extractall(inp)
                input_files = {str(p.relative_to(inp)):sha(p) for p in sorted(inp.rglob('*')) if p.is_file()}
                sums = {'out.ddp' if name=='netdedup' else 'output.txt': expected['sha256']}
                if name=='netdedup': sums['decoded.dat'] = evidence['correctness']['input_sha256']
                runconf = Path('/data1/gzh/EC/Software/PARSEC/pkgs/netapps')/name/'parsec'/(size+'.runconf')
                cases.append(dict(program=name,input=size,argv=evidence['server_argv'][1:],
                    client_argv=evidence['client_argv'][1:],threads=1,warmups=0,
                    thread_definition='One application worker; original user-TCP/pthread service threads remain enabled',
                    roi='Full original server __parsec_roi_begin/end sites; includes original network/compute/thread/syscall work and elapsed target cycles',
                    algorithm_unchanged=name!='netferret',
                    software_repair='Explicit previously reviewed stable joined Netferret profile; no ROI change' if name=='netferret' else 'Existing RISC-V user-TCP/framing integration, original application computation',
                    input_files=input_files,input_archives={archive['path']:archive['sha256']} if archive else {},
                    runconf=str(runconf),runconf_sha256=sha(runconf),
                    input_mapping=evidence.get('mapping_note','Official local runconf preserved'),
                    validation=dict(kind='files_sha256',files=sums),
                    reference_outputs={expected['path']:expected['sha256']},
                    offline_evidence=str(row['result']) if name!='netferret' else str(review['source_result']['path']),
                    fpga_validation='NOT_RUN'))
        apps = dict(schema='ec-fpga-apps/1', status='PREPARED_FPGA_NOT_RUN', output_dir=str(out),
            software_profile='network-original-full-roi-native/1', configurations_allowed=['Native'],
            formal_eligible=True, fpga_validation='NOT_RUN', c4_incompatible_reason=C4_BLOCK,
            binaries=binaries, smoke=appbase['smoke'], cases=cases,
            source_receipts=source_receipts, native_protocol_sources=st['native_protocol_sources'],
            diagnostic_capture_files=['output.txt','network-server.log','network-client.log'])
        apps_path = out/'apps-build.json'
        if apps_path.exists(): assert read(apps_path)==apps, 'immutable apps receipt changed'
        else: save(apps_path, apps)
        fs_path = out/'rootfs-build.json'
        if not fs_path.exists():
            run_logged([sys.executable,W/'scripts/prepare_rootfs.py','--apps-receipt',apps_path,'--output-receipt',fs_path],logs/'rootfs.log')
        fs = read(fs_path)
        if 'network_launcher_sha256' not in fs:
            tree=Path(fs['path']).parent/'tree'; dst=tree/'opt/ec-fpga'
            shell=dst/'run-one'
            old=shell.read_text(); anchor='  /opt/ec-fpga/$program $argv >console.pipe 2>&1'
            replacement='  /opt/ec-fpga/run-network "$program" "$input" >console.pipe 2>&1'
            assert old.count(anchor)==1 or old.count(replacement)==1
            shell.write_text(old.replace(anchor,replacement))
            (dst/'run-network').write_text(WRAPPER);(dst/'run-network').chmod(0o755)
            for c in cases:
                (dst/'cases'/c['program']/c['input']/'client-argv').write_text(' '.join(c['client_argv'])+'\n')
            for p in [shell,dst/'run-network']:subprocess.run(['/bin/sh','-n',str(p)],check=True)
            (dst/'SHA256SUMS').write_text(''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file() and p.name!='SHA256SUMS'))
            packed=Path(fs['path']).parent/'initramfs-network.cpio'
            cpio_newc(tree,packed)
            fs.update(path=str(packed),sha256=sha(packed),bytes=packed.stat().st_size,
                files={str(p.relative_to(tree)):sha(p) for p in tree.rglob('*') if p.is_file()},
                shared_by=['Native'],network_launcher_sha256=sha(dst/'run-network'),
                integration='Dual original processes, full original server ROI; bounded per-pair watchdog, exact peer exits/full outputs; no checker bypass',
                parent_generator_sha256=sha(W/'scripts/prepare_rootfs.py'))
            save(fs_path,fs);save(Path(fs['path']).parent/'manifest.json',fs)
        fs=read(fs_path);assert sha(fs['path'])==fs['sha256'] and fs['apps_manifest_sha256']==sha(apps_path)
        tree=Path(fs['path']).parent/'tree'
        st.update(status='OFFLINE_VALIDATION_AND_NATIVE_BUILD',apps_receipt=str(apps_path),rootfs_receipt=str(fs_path));save(R,st)

        def validate(name):
            result=logs/(name+'-wrapper-test.json')
            if result.exists(): assert read(result)['passed']; return read(result)
            diag=out/('diagnostic-'+name)/'tree'
            if diag.exists():
                diag.rename(diag.parent/('interrupted-tree-'+stamp))
            shutil.copytree(tree,diag,symlinks=True)
            b=diagnostics[name];assert sha(b['path'])==b['sha256']
            shutil.copy2(b['path'],diag/'opt/ec-fpga'/name)
            (diag/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
cd /tmp
/bin/busybox cp -R /opt/ec-fpga/inputs/NAME/test/. .
/bin/sh /opt/ec-fpga/run-network NAME test
echo EC_NETWORK_WRAPPER_EXIT=$?
/bin/busybox poweroff -f
'''.replace('NAME',name));(diag/'init').chmod(0o755)
            image=diag.parent/'initramfs.cpio';cpio_newc(diag,image)
            prior=read(D/'software/fluidanimate-stable-order-candidate.json')['argv']
            kernel=Path(prior[prior.index('-kernel')+1]);qemu=prior[0]
            log=logs/(name+'-wrapper-test.log')
            run_logged([qemu,'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
                        '-kernel',kernel,'-initrd',image,'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G'],log,240)
            text=log.read_text(errors='replace').replace('\r','')
            passed=bool(re.search(r'^EC_NETWORK_WRAPPER_EXIT=0$',text,re.M) and
                'EC_NETWORK_COMPLETE program='+name+' input=test peers_exit_zero=1 output_exact=1' in text and
                text.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==text.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1 and
                not any(x in text for x in ['Kernel panic','EC_NETWORK_TIMEOUT','Assertion','Aborted']))
            record=dict(passed=passed,program=name,input='test',diagnostic_only=True,fpga_execution=False,
                diagnostic_elf_sha256=b['sha256'],runtime_elf_sha256=binaries[name]['sha256'],
                rootfs_sha256=sha(image),launcher_sha256=fs['network_launcher_sha256'],log=str(log),log_sha256=sha(log))
            save(result,record);assert passed,(name,str(log));return record

        def build_native():
            prep=(W/'software/.profile-system-preparation.lock').open('a');fcntl.flock(prep,fcntl.LOCK_EX)
            kr=out/'Native-kernel-build.json'; fw=out/'Native-firmware-build.json'
            parent=W/'software/Native/canneal-formal-kernel-build.json'
            if not kr.exists():
                run_logged([sys.executable,W/'scripts/build_earlyconsole.py','Native','--parent-receipt',parent,
                    '--rootfs-receipt',fs_path,'--output-receipt',kr,'--build-root',
                    '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],logs/'Native-kernel.log')
            before=Path(read(parent)['output_dir']);after=Path(read(kr)['output_dir'])
            strip=lambda p:[l for l in (p/'.config').read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
            assert strip(before)==strip(after) and sha(before/'drivers/misc/ec_dac_roi.o')==sha(after/'drivers/misc/ec_dac_roi.o')
            if not fw.exists():
                run_logged([sys.executable,W/'scripts/build_system.py','Native','firmware','--kernel-result',kr,
                    '--fdt-result',W/'software/Native/fdt-mem2g-build.json','--output-receipt',fw,'--build-root',
                    '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds','--jobs','4','--fdt-load-address','0xbfe00000'],logs/'Native-firmware.log')
            f=read(fw);assert f['returncode']==0
            return dict(kernel_receipt=str(kr),firmware_receipt=str(fw),
                config_unchanged_except_rootfs=True,roi_driver_object_unchanged=True)

        # Each diagnostic owns its own QEMU/IPCs; at most two 2-GiB guests.
        with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
            build=pool.submit(build_native)
            futures={pool.submit(validate,name):name for name in NAMES}
            for future in concurrent.futures.as_completed(futures):
                name=futures[future]
                try:st['cases'][name]=future.result()
                except Exception as exc:st['cases'][name]=dict(passed=False,error=repr(exc))
                save(R,st)
            st['native_build']=build.result();save(R,st)
        ready=[n for n in NAMES if st['cases'][n].get('passed')]
        # Publish complete bindings only. Existing coordinator reads them at its
        # next boundary; it alone owns FPGA starts and first-pass scheduling.
        for name in ready:
            for src,dst in [(apps_path,W/f'software/{name}-apps-build.json'),
                            (fs_path,W/f'software/{name}-rootfs-build.json'),
                            (Path(st['native_build']['firmware_receipt']),W/f'software/Native/{name}-firmware-build.json')]:
                if dst.exists():assert dst.read_bytes()==src.read_bytes(), 'never overwrite software version'
                else:save(dst,read(src))
        if st.get('error'):st.setdefault('resolved_attempt_errors',[]).append(st.pop('error'))
        st.update(status='BOUND_TO_EXISTING_NATIVE_QUEUE' if len(ready)==3 else 'PARTIAL_READY_WITH_EVIDENCE',
            ready_programs=ready,fpga_started_by_this_service=False,
            next_action='Existing coverage-first: Native test -> simsmall -> formal first pass -> repetitions 2/3. Yield to certified C4 at safe boundary.',
            ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(R,st)
    except Exception as exc:
        st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st);raise


if __name__=='__main__':main()
