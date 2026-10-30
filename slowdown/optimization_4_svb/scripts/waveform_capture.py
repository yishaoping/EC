"""Uncapped logs for the one-time waveform run; existing failure ring retained."""
import os
from pathlib import Path
import selectors
import subprocess
import time

from compact_capture import Router


class WaveformRouter(Router):
    def __init__(self, directory):
        # Lift host log budgets for this special run only. Producer sampling
        # stays as in the failing revision; FST is the primary evidence.
        super().__init__(directory, event_limit=2**60, diagnostic_limit=2**60)

    def line(self, line, stream):
        if line.startswith((b'SC1\t', b'SC_END\t', b'SC_LIMIT\t', b'SC_LOG_STATS\t', b'CACHE_OPPORTUNITY ')):
            return super().line(line, stream)
        self.remember_raw_diagnostic(line, stream)
        if any(marker in line.lower() for marker in (b'assertion', b'%error', b'fatal')):
            self.counts['failure_markers_seen'] += 1
        self.write('stdout.log' if stream == 0 else 'stderr.log', line)


def capture(argv, directory):
    directory = Path(directory)
    router = WaveformRouter(directory)
    proc = None
    sel = selectors.DefaultSelector()
    try:
        proc = subprocess.Popen(list(map(str, argv)), stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                stdin=subprocess.DEVNULL, cwd=directory, env={'PATH': '/usr/bin:/bin'})
        sel.register(proc.stdout, selectors.EVENT_READ, 0)
        sel.register(proc.stderr, selectors.EVENT_READ, 1)
        last = time.monotonic()
        while sel.get_map():
            for key, _ in sel.select(timeout=1):
                data = os.read(key.fileobj.fileno(), 65536)
                if data: router.feed(data, key.data)
                else: sel.unregister(key.fileobj)
            if time.monotonic() - last >= 30:
                fst = directory/'hang.fst'
                print(f'SIMULATION_IN_PROGRESS={directory}; fst_bytes={fst.stat().st_size if fst.exists() else 0}; '
                      f'compact_bytes={router.sizes["safe_chain_events.tsv"]}', flush=True)
                last = time.monotonic()
        router.exit_status = proc.wait()
        return router.exit_status, router.close()
    except BaseException as exc:
        if proc:
            proc.terminate()
            try: proc.wait(timeout=10)
            except subprocess.TimeoutExpired: proc.kill(); proc.wait()
            router.exit_status = proc.returncode
        router.force_failure_dump = True
        exc.capture_stats = router.close()
        exc.simulator_return_code = proc.returncode if proc else None
        raise
    finally:
        sel.close()
        if proc:
            proc.stdout.close(); proc.stderr.close()
