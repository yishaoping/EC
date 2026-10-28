"""Bounded streaming capture. Events have one copy; stable/noisy output is counted.

Only the user-run launcher invokes a simulator. Unit tests feed bytes directly.
"""
import os
import selectors
import subprocess
import time
from collections import Counter

# Leave room below the 100 MiB analysis target for derived JSON/intervals.
EVENT_LIMIT = 48 * 1024 * 1024
DIAGNOSTIC_LIMIT = 2 * 1024 * 1024


class Router:
    def __init__(self, directory, event_limit=EVENT_LIMIT, diagnostic_limit=DIAGNOSTIC_LIMIT):
        self.files = {name: (directory/name).open('xb') for name in
                      ('safe_chain_events.tsv', 'stdout.log', 'stderr.log')}
        self.event_limit, self.diagnostic_limit = event_limit, diagnostic_limit
        self.counts, self.sizes = Counter(), Counter()
        self.buffers = {0: b'', 1: b''}
        self.closed = False

    def line(self, line, stream):
        if line.startswith((b'SC1\t', b'SC_END\t')):
            dest = 'safe_chain_events.tsv'
            if self.sizes[dest]+len(line)>self.event_limit:
                raise RuntimeError('SAFE_CHAIN_EVENT_BUDGET_EXCEEDED; evidence incomplete; no automatic retry')
        elif line.startswith(b'SC_OVERFLOW'):
            # Keep the first failure's observer identity; previously raising
            # here lost the only SC_OVERFLOW kind/hart record from the pipe.
            dest = 'stdout.log' if stream == 0 else 'stderr.log'
            if self.sizes[dest]+len(line)>self.diagnostic_limit:
                raise RuntimeError('SAFE_CHAIN_OBSERVER_OVERFLOW; '+line.decode(errors='replace').strip()+
                                   '; diagnostic budget exhausted; evidence incomplete')
            self.files[dest].write(line)
            self.sizes[dest] += len(line)
            self.counts['observer_overflows'] += 1
            raise RuntimeError('SAFE_CHAIN_OBSERVER_OVERFLOW; '+line.decode(errors='replace').strip()+
                               '; evidence incomplete')
        elif line.startswith((b'[', b'STAGE1_HOST_SUCCESS', b'STAGE1_TX EXIT_',
                              b'STAGE1_SIM_EXIT', b'***', b'%')) or any(
                token in line.lower() for token in (b'assert', b'error', b'failed', b'fail', b'fatal', b'abort', b'timeout')):
            dest = 'stdout.log' if stream == 0 else 'stderr.log'
            if self.sizes[dest]+len(line)>self.diagnostic_limit:
                raise RuntimeError('SAFE_CHAIN_DIAGNOSTIC_BUDGET_EXCEEDED')
        else:
            self.counts['discarded_diagnostic_lines'] += 1
            self.counts['discarded_diagnostic_bytes'] += len(line)
            return
        self.files[dest].write(line)
        self.sizes[dest] += len(line)
        self.counts[dest+'_lines'] += 1

    def feed(self, data, stream):
        pending = self.buffers[stream]+data
        parts = pending.split(b'\n')
        self.buffers[stream] = parts.pop()
        if len(self.buffers[stream]) > 65536:
            raise RuntimeError('unexpected unterminated long output record')
        for part in parts:
            self.line(part+b'\n', stream)

    def close(self):
        if not self.closed:
            self.closed = True
            try:
                for stream, tail in self.buffers.items():
                    if tail:
                        # Preserve truncation; never invent an event newline.
                        if tail.startswith((b'SC1\t', b'SC_END\t')):
                            if self.sizes['safe_chain_events.tsv']+len(tail)>self.event_limit:
                                raise RuntimeError('SAFE_CHAIN_EVENT_BUDGET_EXCEEDED')
                            self.files['safe_chain_events.tsv'].write(tail)
                            self.sizes['safe_chain_events.tsv'] += len(tail)
                            self.counts['truncated_event_records'] += 1
                        else:
                            self.line(tail+b'\n', stream)
            finally:
                for file in self.files.values():
                    file.close()
        return self.stats()

    def stats(self):
        return {'sizes': dict(self.sizes), 'counts': dict(self.counts),
                'event_limit_bytes': self.event_limit, 'diagnostic_limit_bytes': self.diagnostic_limit,
                'event_storage': 'single compact TSV; no duplicate combined/raw event log'}


def capture(argv, directory):
    router = Router(directory)
    try:
        proc = subprocess.Popen(argv, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                stdin=subprocess.DEVNULL, env={'PATH':'/usr/bin:/bin'})
    except BaseException as exc:
        exc.capture_stats = router.close()
        exc.simulator_return_code = None
        raise
    sel=selectors.DefaultSelector()
    sel.register(proc.stdout,selectors.EVENT_READ,0)
    sel.register(proc.stderr,selectors.EVENT_READ,1)
    last=time.monotonic()
    try:
        while sel.get_map():
            for key,_ in sel.select(timeout=1):
                data=os.read(key.fileobj.fileno(),65536)
                if data:router.feed(data,key.data)
                else:sel.unregister(key.fileobj)
            if time.monotonic()-last>30:
                print('SIMULATION_IN_PROGRESS='+str(directory)+'; event_bytes='+
                      str(router.sizes['safe_chain_events.tsv']),flush=True)
                last=time.monotonic()
        return proc.wait(), router.close()
    except BaseException as exc:
        proc.terminate()
        try:proc.wait(timeout=10)
        except subprocess.TimeoutExpired:
            proc.kill();proc.wait()
        # The launcher records these even when capture cannot return normally.
        try:
            exc.capture_stats = router.close()
        except Exception as close_exc:
            # A buffered tail can also fail validation/budget checks. Keep
            # the first error as the cause and retain the cleanup diagnostic.
            exc.capture_stats = router.stats()
            exc.capture_stats['close_error'] = str(close_exc)
        exc.simulator_return_code = proc.returncode
        raise
    finally:
        sel.close()
