"""Sandbox filesystem/libc checks only; never load or execute a simulator."""
import ctypes
import json
import mmap
import os
from pathlib import Path
import sys
import tempfile


ROOT = Path('/data1/gzh/EC/baseline')


def probe():
    results = {}

    def check(name, action):
        try:
            detail = action()
            results[name] = {'status': 'PASS', 'detail': detail}
        except (KeyError, OSError, ValueError, RuntimeError) as exc:
            results[name] = {'status': 'FAIL', 'error': str(exc)}

    def mounts():
        temporary = Path(os.environ['TMPDIR'])
        if not temporary.resolve().is_relative_to(ROOT) or not temporary.is_dir():
            raise RuntimeError('TMPDIR must be an existing baseline directory')
        for name in ('/tmp', '/var/tmp'):
            if not os.path.samefile(name, temporary):
                raise RuntimeError(name + ' is not backed by the private baseline directory')
            if os.statvfs(name).f_flag & os.ST_RDONLY:
                raise RuntimeError(name + ' is read-only')
        for name in ('/data1/gzh/EC/chipyard', str(ROOT / 'source')):
            if not os.statvfs(name).f_flag & os.ST_RDONLY:
                raise RuntimeError(name + ' must remain read-only')
        return {'TMPDIR': str(temporary), 'private_mounts': ['/tmp', '/var/tmp'],
                'current_and_canonical_source': 'READ_ONLY'}

    def native_temporary_files():
        # FST uses four simultaneously open libc tmpfile() streams, then mmap.
        # Python tempfile alone would miss the hardcoded libc /tmp dependency.
        libc = ctypes.CDLL(None, use_errno=True)
        libc.tmpfile.restype = ctypes.c_void_p
        libc.fileno.argtypes = [ctypes.c_void_p]
        libc.fileno.restype = ctypes.c_int
        libc.fclose.argtypes = [ctypes.c_void_p]
        streams = []
        try:
            for _ in range(4):
                ctypes.set_errno(0)
                stream = libc.tmpfile()
                if not stream:
                    error = ctypes.get_errno()
                    raise OSError(error, 'libc tmpfile(): ' + os.strerror(error))
                streams.append(stream)
                fd = libc.fileno(stream)
                payload = b'FST native temporary I/O probe'
                if os.write(fd, payload) != len(payload):
                    raise RuntimeError('Short temporary-file write')
                with mmap.mmap(fd, len(payload), access=mmap.ACCESS_WRITE) as mapping:
                    mapping[0:3] = b'fst'
                    mapping.flush()
                os.lseek(fd, 0, os.SEEK_SET)
                if os.read(fd, len(payload)) != b'fst native temporary I/O probe':
                    raise RuntimeError('Temporary-file readback mismatch')
            return {'simultaneous_libc_tmpfiles': len(streams), 'read_write_mmap': 'PASS'}
        finally:
            for stream in streams:
                libc.fclose(stream)

    def adjacent_waveform_files():
        # Writer opens both the output and an adjacent .hier file. Use unique
        # probe files, never the real test.fst or any saved waveform.
        with tempfile.TemporaryDirectory(prefix='waveform_io_', dir=Path.cwd()) as directory:
            for name in ('probe.fst', 'probe.fst.hier'):
                with (Path(directory) / name).open('xb') as stream:
                    stream.write(b'filesystem probe only; not an FST waveform\n')
                    stream.flush()
                    os.fsync(stream.fileno())
        with tempfile.TemporaryFile(dir=os.environ['TMPDIR']) as stream:
            stream.write(b'TMPDIR probe')
            stream.seek(0)
            if stream.read() != b'TMPDIR probe':
                raise RuntimeError('TMPDIR readback mismatch')
        return 'output, adjacent hierarchy and TMPDIR I/O passed; no FST decoding performed'

    check('mount_isolation', mounts)
    if results['mount_isolation']['status'] != 'PASS':
        # Never touch native /tmp or create probe files if called directly
        # outside the expected sandbox or with an invalid mount policy.
        for name in ('libc_tmpfile_and_mmap', 'waveform_directory_io'):
            results[name] = {'status': 'SKIPPED_ISOLATION_FAILED'}
        return {'status': 'FAIL', 'checks': results,
                'scope': 'FILESYSTEM_AND_LIBC_ONLY_NO_SIMULATION'}
    check('libc_tmpfile_and_mmap', native_temporary_files)
    check('waveform_directory_io', adjacent_waveform_files)
    return {'status': 'PASS' if all(x['status'] == 'PASS' for x in results.values()) else 'FAIL',
            'checks': results, 'scope': 'FILESYSTEM_AND_LIBC_ONLY_NO_SIMULATION'}


if __name__ == '__main__':
    report = probe()
    print(json.dumps(report, indent=2))
    sys.exit(0 if report['status'] == 'PASS' else 1)
