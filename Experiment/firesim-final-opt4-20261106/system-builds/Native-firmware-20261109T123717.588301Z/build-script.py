#!/usr/bin/env python3
"""Build matched Linux/OpenSBI in independent outputs; never touch FPGA devices."""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import signal
import shutil
import subprocess
import sys
import time

WORK = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
DATA = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
ENV = Path('/data1/gzh/EC/firesim/envs/manager-1.17.1')
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from build_minimal import sha


def atomic(path, obj):
    tmp = path.with_suffix('.tmp')
    with tmp.open('w') as f:
        json.dump(obj, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    tmp.replace(path)


def snapshot(src):
    files = {}
    for directory, dirs, names in os.walk(src):
        dirs[:] = sorted(d for d in dirs if d not in {'.git', '__pycache__'})
        for name in sorted(names):
            f = Path(directory)/name
            files[str(f.relative_to(src))] = {'link': os.readlink(f)} if f.is_symlink() else sha(f)
    return files


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('configuration', choices=['Native', 'C4'])
    p.add_argument('phase', choices=['kernel', 'firmware'])
    p.add_argument('--kernel-result', type=Path)
    p.add_argument('--fdt-result', type=Path)
    p.add_argument('--rootfs-receipt', type=Path,
                   help='Exact rootfs for kernel builds; defaults to the shared rootfs receipt')
    p.add_argument('--build-root', type=Path, help='Actual output filesystem; receipts/logs remain in Experiment')
    p.add_argument('--output-receipt', type=Path, help='Independent software variant receipt')
    p.add_argument('--jobs', type=int, default=2, help='Parallel build jobs (default: 2)')
    p.add_argument('--fdt-load-address',type=lambda s:int(s,0),
                   help='OpenSBI runtime DTB copy address; must not overlap the embedded kernel')
    a = p.parse_args()
    if a.jobs < 1:
        p.error('--jobs must be positive')
    if a.phase == 'firmware' and not (a.kernel_result and a.fdt_result):
        p.error('firmware requires exact --kernel-result and --fdt-result')
    lock = (DATA/'.system-build.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    build_root = (a.build_root or WORK/'software'/a.configuration/'builds').resolve()
    build_root.mkdir(parents=True, exist_ok=True)
    memory = {l.split(':')[0]: int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    resources = dict(available_memory_gib=memory['MemAvailable']/1024**2,
                     free_disk_gib=shutil.disk_usage(build_root).free/2**30,
                     log_free_disk_gib=shutil.disk_usage(DATA).free/2**30,
                     actual_build_root=str(build_root),load_1min=os.getloadavg()[0],host_cpus=os.cpu_count(),jobs=a.jobs)
    # Keep the original 40 GiB output guard, but check the filesystem actually
    # used by this build, independently of the small persistent log volume.
    assert resources['available_memory_gib']>=32 and resources['free_disk_gib']>=40
    assert resources['log_free_disk_gib']>=10 and resources['load_1min']<os.cpu_count()*.9, resources
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    label = a.configuration+'-'+a.phase+'-'+stamp
    log = DATA/'system-builds'/label
    out = build_root/label
    log.mkdir(parents=True)
    out.mkdir(parents=True)
    src = WORK/'software'/a.configuration/('linux' if a.phase == 'kernel' else 'opensbi')
    before = snapshot(src)
    atomic(log/'sources.json', before)
    source_id = hashlib.sha256(json.dumps(before, sort_keys=True).encode()).hexdigest()
    script = Path(__file__).read_bytes()
    (log/'build-script.py').write_bytes(script)
    inputs = {str(WORK/'software/linux-profile.json'): sha(WORK/'software/linux-profile.json')}
    env = os.environ.copy()
    for k in ['CFLAGS', 'CPPFLAGS', 'CXXFLAGS', 'LDFLAGS', 'LD_LIBRARY_PATH', 'ARCH', 'CROSS_COMPILE']:
        env.pop(k, None)
    env.update(PATH=f'{ENV}/bin:{ENV}/riscv-tools/bin:/usr/local/bin:/usr/bin:/bin',
               CONDA_PREFIX=str(ENV), CC='/usr/bin/gcc', HOSTCC='/usr/bin/gcc', HOSTCXX='/usr/bin/g++',
               MAKEFLAGS='-j2', SOURCE_DATE_EPOCH='1793577600',
               KBUILD_BUILD_TIMESTAMP='Mon Nov 2 00:00:00 UTC 2026',
               KBUILD_BUILD_USER='ec-fpga', KBUILD_BUILD_HOST='isolated-build')
    cross = str(ENV/'riscv-tools/bin/riscv64-unknown-linux-gnu-')
    state_path = DATA/'system-build-state.json'
    state = dict(schema='ec-firesim-system-build-state/1', configuration=a.configuration,
                 phase=a.phase, status='RUNNING', pid=os.getpid(),
                 start_ticks=Path('/proc/self/stat').read_text().split()[21],
                 started_utc=dt.datetime.now(dt.timezone.utc).isoformat(), log=str(log), output_dir=str(out),
                 no_fpga_access=True)
    atomic(state_path, state)
    commands = []
    child = None
    interrupted = False

    def stop(sig, frame):
        nonlocal interrupted
        interrupted = True
        if child is not None and child.poll() is None:
            os.killpg(child.pid, signal.SIGTERM)
    signal.signal(signal.SIGTERM, stop)
    signal.signal(signal.SIGINT, stop)

    def run(args):
        nonlocal child
        argv = ['nice', '-n', '15'] + list(map(str, args))
        commands.append(dict(argv=argv, cwd=str(src)))
        atomic(log/'commands.json', commands)
        with (log/'build.log').open('ab', buffering=0) as stream:
            child = subprocess.Popen(argv, cwd=src, env=env, stdin=subprocess.DEVNULL,
                                     stdout=stream, stderr=subprocess.STDOUT, start_new_session=True)
            state.update(child_pid=child.pid, child_pgid=child.pid,
                         child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21])
            atomic(state_path, state)
            try:
                rc = child.wait(timeout=5400)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid, signal.SIGTERM)
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    os.killpg(child.pid, signal.SIGKILL)
                    child.wait()
                raise RuntimeError('build timeout')
            if rc:
                raise RuntimeError(f'command failed {rc}: see {log}/build.log')
        if interrupted:
            raise RuntimeError('build interrupted')

    print(log, flush=True)
    start = time.monotonic()
    error = None
    checks = {}
    try:
        if a.phase == 'kernel':
            rootfs_receipt = a.rootfs_receipt or WORK/'software/rootfs-build.json'
            rootfs = json.loads(rootfs_receipt.read_text())
            archive = Path(rootfs['path'])
            if sha(archive) != rootfs['sha256']:
                raise ValueError('rootfs mismatch')
            inputs.update({str(rootfs_receipt): sha(rootfs_receipt), str(archive): sha(archive)})
            common = ['make', f'-j{a.jobs}', 'O='+str(out), 'ARCH=riscv', 'CROSS_COMPILE='+cross]
            run(common+['defconfig'])
            args = [src/'scripts/config', '--file', out/'.config']
            for k in ['DRM', 'SOUND', 'NET', 'SCSI', 'ATA', 'USB_SUPPORT', 'PCI', 'VIRTIO',
                      'MODULES', 'BPF_SYSCALL', 'DEBUG_KERNEL', 'DEBUG_INFO', 'KALLSYMS', 'SMP']:
                args += ['--disable', k]
            for k in ['BLK_DEV_INITRD', 'DEVTMPFS', 'DEVTMPFS_MOUNT', 'PROC_FS', 'SYSFS', 'TMPFS',
                      'SERIAL_SIFIVE', 'SERIAL_SIFIVE_CONSOLE', 'UNIX98_PTYS', 'FUTEX', 'MULTIUSER',
                      'DEBUG_INFO_NONE', 'EC_DAC_ROI']:
                args += ['--enable', k]
            args += ['--set-str', 'INITRAMFS_SOURCE', str(archive)]
            run(args)
            run(common+['olddefconfig'])
            run(common+['Image', 'vmlinux'])
            assert 'CONFIG_EC_DAC_ROI=y\n' in (out/'.config').read_text()
            assert (out/'drivers/misc/ec_dac_roi.o').is_file()
            checks['roi_driver_object'] = sha(out/'drivers/misc/ec_dac_roi.o')
            checks['same_rootfs'] = rootfs['sha256']
            checks['memory_profile'] = json.loads((WORK/'software/linux-profile.json').read_text())['profile']
            selected = ['vmlinux', 'arch/riscv/boot/Image', '.config', 'drivers/misc/ec_dac_roi.o']
        else:
            k = json.loads(a.kernel_result.read_text())
            d = json.loads(a.fdt_result.read_text())
            # Variant pointers can later change. Bind immutable receipt copies
            # as well as exact kernel/DTB bytes into each payload build.
            kernel_receipt = log/'bound-kernel-receipt.json'
            fdt_receipt = log/'bound-fdt-receipt.json'
            kernel_receipt.write_bytes(a.kernel_result.read_bytes())
            fdt_receipt.write_bytes(a.fdt_result.read_bytes())
            assert k['returncode'] == 0 and k['phase'] == 'kernel' and k['configuration'] == a.configuration
            assert d['returncode'] == 0 and d['configuration'] == a.configuration
            kernel = Path(k['output_dir'])/'arch/riscv/boot/Image'
            fdt = Path(d['fdt'])
            assert sha(kernel) == k['outputs'][str(kernel)] and sha(fdt) == d['sha256']
            fdt_address=a.fdt_load_address if a.fdt_load_address is not None else 0x82200000
            kernel_start=0x80200000;kernel_end=kernel_start+kernel.stat().st_size
            assert 0x80000000<=fdt_address and fdt_address+fdt.stat().st_size<=0x100000000, 'DTB must fit matched mem=2G guest RAM'
            assert fdt_address%4096==0
            assert fdt_address+fdt.stat().st_size<=kernel_start or fdt_address>=kernel_end, 'OpenSBI DTB relocation overlaps kernel/initramfs; select an explicit safe address'
            assert fdt_address>=0x80200000, 'do not overlap the resident firmware/checker service'
            checks['runtime_memory_layout']=dict(kernel_start=kernel_start,kernel_end=kernel_end,
                fdt_copy_start=fdt_address,fdt_copy_end=fdt_address+fdt.stat().st_size,
                no_overlap=True,linux_memory_cap_bytes=2*1024**3)
            inputs.update({str(kernel_receipt): sha(kernel_receipt), str(fdt_receipt): sha(fdt_receipt),
                           str(kernel): sha(kernel), str(fdt): sha(fdt)})
            run(['make', f'-j{a.jobs}', 'O='+str(out), 'PLATFORM=generic', 'CROSS_COMPILE='+cross,
                 'FW_PAYLOAD_PATH='+str(kernel), 'FW_PAYLOAD_FDT_PATH='+str(fdt),
                 'FW_PAYLOAD_FDT_ADDR='+hex(fdt_address),'FW_JUMP_FDT_ADDR='+hex(fdt_address)])
            payload = (out/'platform/generic/firmware/fw_payload.bin').read_bytes()
            for label, f in [('kernel', kernel), ('fdt', fdt)]:
                content = f.read_bytes()
                offset = payload.find(content)
                assert content and offset >= 0
                checks[label] = dict(path=str(f), sha256=sha(f), bytes=len(content), payload_offset=offset,
                                     exact_bytes_present=True)
            selected = ['platform/generic/firmware/fw_payload.elf', 'platform/generic/firmware/fw_payload.bin']
        assert all(sha(f) == digest for f, digest in inputs.items())
        assert snapshot(src) == before, 'source changed during build'
    except Exception as exc:
        error = repr(exc)
    result = dict(schema='ec-firesim-system-build/1', configuration=a.configuration, phase=a.phase,
                  source_tree=str(src), source_id=source_id, output_dir=str(out),
                  outputs={str(out/f): sha(out/f) for f in selected if (out/f).is_file()} if error is None else {},
                  input_files=inputs, commands=commands, resources=resources, content_checks=checks,
                  returncode=1 if error else 0, error=error, wall_seconds=time.monotonic()-start,
                  build_script_sha256=hashlib.sha256(script).hexdigest(),
                  tool_hashes={str(Path(cross+t)): sha(cross+t) for t in ['gcc', 'ld', 'objcopy']},
                  runtime_validation='NOT_RUN', fpga_execution='NOT_RUN')
    atomic(log/'result.json', result)
    if not error:
        atomic(a.output_receipt or WORK/'software'/a.configuration/(a.phase+'-build.json'), result)
    state.update(status='INTERRUPTED' if interrupted else 'FAILED' if error else 'BUILT_NOT_RUN',
                 result_path=str(log/'result.json'), ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(), error=error)
    atomic(state_path, state)
    print(json.dumps(dict(result_path=str(log/'result.json'), returncode=result['returncode'], error=error)), flush=True)
    return result['returncode']


if __name__ == '__main__':
    raise SystemExit(main())
