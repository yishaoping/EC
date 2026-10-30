"""Bounded, priority-reserved observation capture; budgets never stop the workload.

Mandatory evidence loss is explicit and prevents validation PASS. Optional examples
may be omitted, while source counters, protocol records and final results have
separate reservations. Only the user-run launcher invokes a hardware simulator.
"""
import json
import os
import re
import selectors
import subprocess
import time
from collections import Counter, deque

EVENT_LIMIT = 48 * 1024 * 1024
DIAGNOSTIC_LIMIT = 2 * 1024 * 1024  # each of stdout/stderr
OPPORTUNITY_LIMIT = 4 * 1024 * 1024
MAX_RECORD = 65536
POLICY = 'priority_reserved_v2'
RING_EVENT_PREFIXES = (
    b'FASTLINE_', b'WB_', b'PROBE_', b'MSHR_', b'PRESERVATION_', b'PRESERVATION ',
    b'SVB_', b'C_CHANNEL ', b'D_ACK ', b'WATERMARK_ADVANCE ',
    b'CORE_WATCHDOG_SNAPSHOT ', b'DCACHE_WATCHDOG_SNAPSHOT ',
    b'CACHE_HANG_SNAPSHOT ', b'LONG_STALL ',
)


def unsigned(word):
    value = int(word)
    if not 0 <= value < 2**64:
        raise ValueError('integer outside unsigned 64-bit range')
    return value


def event_budgets(event_limit=EVENT_LIMIT):
    summary = min(1024*1024, event_limit//8)
    examples = min(8*1024*1024, event_limit//4)
    return dict(summary=summary, diagnostic=examples, protocol=event_limit-summary-examples)


def budget_contract():
    budgets = event_budgets()
    total = EVENT_LIMIT + 2*DIAGNOSTIC_LIMIT + OPPORTUNITY_LIMIT
    if min(budgets.values()) <= 0 or sum(budgets.values()) != EVENT_LIMIT or total >= 100*1024*1024:
        raise ValueError('invalid observation budget reservations')
    return dict(policy=POLICY, event_budgets=budgets, total_stream_limit_bytes=total,
                mandatory_loss_policy='continue_workload_reject_validation',
                optional_loss_policy='count_and_continue')


def optional_event(kind, hart):
    return kind == 1 or (4 <= kind <= 15 and kind != 10) or (kind == 16 and hart != 0)


class Router:
    def __init__(self, directory, event_limit=EVENT_LIMIT, diagnostic_limit=DIAGNOSTIC_LIMIT,
                 ring_byte_limit=1024*1024, ring_line_limit=8192):
        if event_limit < 8 or diagnostic_limit < 8:
            raise ValueError('capture budgets must be at least eight bytes')
        if ring_byte_limit < 8 or ring_line_limit < 1:
            raise ValueError('diagnostic ring limits must be positive')
        self.directory = directory
        self.files = {name: (directory/name).open('xb') for name in
                      ('safe_chain_events.tsv', 'stdout.log', 'stderr.log', 'cache_opportunity.jsonl')}
        self.event_limit, self.diagnostic_limit = event_limit, diagnostic_limit
        # 48 MiB = 39 MiB protocol + 8 MiB optional + 1 MiB final snapshots/footers.
        self.budgets = event_budgets(event_limit)
        self.used = Counter()
        self.counts, self.sizes = Counter(), Counter()
        self.observers, self.producers = {}, {}
        self.incomplete_reasons = set()
        self.warned = set()
        self.optional_omitted = 0
        self.buffers = {0: b'', 1: b''}
        self.discarding = {0: False, 1: False}
        self.ring_byte_limit, self.ring_line_limit = ring_byte_limit, ring_line_limit
        self.raw_ring = deque()
        self.raw_ring_bytes = 0
        self.raw_ring_index = {}
        self.raw_ring_duplicates = 0
        self.exit_status = None
        self.force_failure_dump = False
        self.failure_diagnostics_dumped = False
        self.closed = False

    def incomplete(self, reason):
        self.incomplete_reasons.add(reason)

    def observer(self, kind, hart):
        key = f'{kind}:{hart}'
        if key not in self.observers:
            if len(self.observers) >= 128:
                self.incomplete('too_many_observer_identities')
                key = 'other'
            self.observers.setdefault(key, dict(seen=0, kept=0, omitted=0, events_seen=0, footers_seen=0))
        return self.observers[key]

    def warn_limit(self, category):
        if category not in self.warned:
            self.warned.add(category)
            print('OBSERVATION_LIMIT scope='+category+'; simulation continues; mandatory_evidence_complete='+
                  str(not self.incomplete_reasons).lower(), flush=True)

    def write(self, dest, line):
        self.files[dest].write(line)
        self.sizes[dest] += len(line)
        self.counts[dest+'_lines'] += 1

    def remember_raw_diagnostic(self, line, stream):
        if line.startswith((b'SC1\t', b'SC_END\t', b'SC_LIMIT\t', b'SC_LOG_STATS\t',
                            b'CACHE_OPPORTUNITY ')):
            return
        event_line = line.rstrip(b'\r\n')
        failure = bool(re.search(rb'\b(assert|assertion|fatal|failed|abort)\b|%error',
                                 event_line.lower()))
        if not failure and not event_line.startswith(RING_EVENT_PREFIXES):
            return
        record = (b'stdout\t' if stream == 0 else b'stderr\t') + event_line.replace(b'\t', b'\\t') + b'\n'
        record_budget = max(0, self.ring_byte_limit - 21)
        if len(record) > record_budget:
            record = record[-record_budget:] if record_budget else b''
        if not record:
            return
        key = self.ring_key(event_line)
        if key in self.raw_ring_index:
            self.raw_ring_index[key]['repeats'] += 1
            self.raw_ring_duplicates += 1
            return
        stored_size = len(record) + 21
        while self.raw_ring and (len(self.raw_ring) >= self.ring_line_limit or
                                 self.raw_ring_bytes + stored_size > self.ring_byte_limit):
            removed = self.raw_ring.popleft()
            self.raw_ring_bytes -= removed['stored_size']
            self.raw_ring_index.pop(removed['key'], None)
        if len(record) <= self.ring_byte_limit:
            item = dict(key=key, record=record, repeats=1, stored_size=stored_size)
            self.raw_ring.append(item)
            self.raw_ring_index[key] = item
            self.raw_ring_bytes += stored_size

    @staticmethod
    def ring_key(event_line):
        text = event_line.decode('utf-8', errors='replace')
        name = text.split(None, 1)[0]
        repeated_waits = {'FASTLINE_BLOCK_OTHER_LINE', 'PRESERVATION_WAIT',
                          'PRESERVATION_BLOCKED', 'WB_BLOCK', 'PROBE_BLOCKED'}
        if name in repeated_waits:
            # Preserve every dependency/identity bit; only timestamp/age can
            # differ for a repeated wait. Lifecycle and C/D events retain time.
            text = re.sub(r'\b(?:cycle|age)=[^\s]+\s*', '', text)
        return (name, text)

    def event(self, line):
        p = line.rstrip(b'\n').split(b'\t')
        try:
            if p[0] == b'SC1' and len(p) == 23:
                _, _, _, _, kind, hart = map(unsigned, p[1:7])
                for word in p[7:]:
                    if len(word) != 16:raise ValueError('invalid word length')
                    if not 0 <= int(word, 16) < 2**64:raise ValueError('invalid word value')
                category = ('diagnostic' if optional_event(kind, hart) else
                            'summary' if kind in (16, 17, 18, 25, 30, 31) else 'protocol')
            elif p[0] == b'SC_END' and len(p) == 8:
                _, _, _, _, kind, hart, _ = map(unsigned, p[1:])
                category = 'summary'
            else:raise ValueError('invalid compact event')
            if not 0 <= kind < 256 or not 0 <= hart < 65536:raise ValueError('invalid observer identity')
        except ValueError:
            self.incomplete('malformed_compact_record')
            self.counts['malformed_compact_records'] += 1
            return
        obs = self.observer(kind, hart); obs['seen'] += 1
        if p[0] == b'SC1':obs['events_seen'] += 1
        else:
            obs['footers_seen'] += 1
            obs['footer_emitted_count'] = int(p[7])
        self.counts['event_records_seen'] += 1
        if self.used[category]+len(line) > self.budgets[category]:
            obs['omitted'] += 1
            self.counts[category+'_records_omitted'] += 1
            if category == 'diagnostic':self.optional_omitted += 1
            else:self.incomplete(category+'_budget_exhausted')
            self.warn_limit(category)
            return
        self.used[category] += len(line); obs['kept'] += 1
        self.write('safe_chain_events.tsv', line)

    def producer(self, line):
        p = line.rstrip(b'\n').split(b'\t')
        try:
            kind, hart = int(p[1]), int(p[2]); key=f'{kind}:{hart}'
            if not 0 <= kind < 256 or not 0 <= hart < 65536:raise ValueError('invalid producer identity')
            if len(self.producers) >= 128 and key not in self.producers:
                raise ValueError('too many producers')
            if p[0] == b'SC_LIMIT' and len(p) == 6:
                emitted, limit, critical = map(unsigned, p[3:])
                if emitted < 0 or limit < 1 or critical not in (0, 1):raise ValueError('invalid limit')
                if not optional_event(kind, hart):self.incomplete('mandatory_producer_limit')
                self.producers.setdefault(key, {})['limit_seen'] = True
            elif p[0] == b'SC_LOG_STATS' and len(p) == 7:
                produced, emitted, omitted, limit = map(unsigned, p[3:])
                if min(produced, emitted, omitted) < 0 or limit < 1 or produced != emitted+omitted or emitted > limit:
                    raise ValueError('invalid producer conservation')
                if 'produced' in self.producers.get(key, {}):
                    raise ValueError('duplicate producer final statistics')
                self.producers.setdefault(key, {}).update(produced=produced, emitted=emitted, omitted=omitted, limit=limit)
                if omitted and not optional_event(kind, hart):self.incomplete('mandatory_producer_limit')
            else:raise ValueError('malformed producer statistics')
        except (ValueError, IndexError):
            self.incomplete('malformed_producer_statistics')

    def line(self, line, stream):
        if len(line) > MAX_RECORD:
            self.incomplete('oversized_output_record'); self.counts['oversized_records'] += 1
            return
        self.remember_raw_diagnostic(line, stream)
        if line.startswith((b'SC1\t', b'SC_END\t')):
            self.event(line); return
        if line.startswith((b'SC_LIMIT\t', b'SC_LOG_STATS\t')):
            self.producer(line); return
        if line.startswith(b'CACHE_OPPORTUNITY '):
            line=line[len(b'CACHE_OPPORTUNITY '):]; dest='cache_opportunity.jsonl'
            if self.sizes[dest]+len(line) > OPPORTUNITY_LIMIT:
                self.incomplete('cache_summary_budget_exhausted')
                self.counts['cache_summaries_omitted'] += 1; self.warn_limit('cache_summary'); return
            self.write(dest,line); return
        if line.startswith(b'SC_OVERFLOW'):
            self.incomplete('legacy_producer_overflow')
            self.counts['observer_overflows'] += 1
        lower=line.lower()
        failure=bool(re.search(rb'\b(assert|assertion|fatal|failed|abort)\b|%error',lower))
        if failure:self.counts['failure_markers_seen'] += 1
        essential=(failure or line.startswith((b'[ROI]', b'[RUN] benchmark=', b'[COMPUTATION]', b'[END]',
                    b'STAGE1_HOST_SUCCESS', b'STAGE1_SIM_EXIT', b'STAGE1_TX EXIT_', b'SC_OVERFLOW', b'***')))
        retained=(essential or line.startswith((b'[',b'%')) or any(t in lower for t in (b'error',b'fail',b'timeout')))
        if not retained:
            self.counts['discarded_diagnostic_lines'] += 1; self.counts['discarded_diagnostic_bytes'] += len(line)
            return
        dest='stdout.log' if stream==0 else 'stderr.log'
        category=dest+('_essential' if essential else '_general')
        reserved=self.diagnostic_limit//4
        budget=reserved if essential else self.diagnostic_limit-reserved
        if self.used[category]+len(line)>budget:
            self.counts[category+'_omitted'] += 1
            if essential:self.incomplete('essential_diagnostic_budget_exhausted')
            self.warn_limit(category);return
        self.used[category] += len(line); self.write(dest,line)

    def feed(self, data, stream):
        if self.discarding[stream]:
            pos=data.find(b'\n')
            if pos<0:return
            data=data[pos+1:];self.discarding[stream]=False
        parts=(self.buffers[stream]+data).split(b'\n');self.buffers[stream]=parts.pop()
        if len(self.buffers[stream])>MAX_RECORD:
            self.incomplete('oversized_output_record');self.counts['oversized_records'] += 1
            self.buffers[stream]=b'';self.discarding[stream]=True
        for part in parts:self.line(part+b'\n',stream)

    def close(self):
        if not self.closed:
            self.closed=True
            try:
                for stream,tail in self.buffers.items():
                    if tail:
                        self.incomplete('unterminated_output_record')
                        self.counts['truncated_event_records'] += 1
                        # Never invent a complete final event or benchmark marker.
                for key in self.observers.keys() | self.producers.keys():
                    if key == 'other' or optional_event(*map(int, key.split(':'))):continue
                    observer, producer = self.observers.get(key, {}), self.producers.get(key, {})
                    if (observer.get('footers_seen') != 1 or
                            producer.get('emitted') is None or
                            producer.get('emitted') != observer.get('events_seen') or
                            producer.get('emitted') != observer.get('footer_emitted_count')):
                        self.incomplete('mandatory_producer_footer_mismatch')
            finally:
                for file in self.files.values():file.close()
            failed = (self.force_failure_dump or self.exit_status not in (None, 0) or
                      self.counts['failure_markers_seen'] > 0 or self.counts['observer_overflows'] > 0)
            if failed:
                with (self.directory/'hang_ringbuffer.tsv').open('xb') as output:
                    output.write(b'stream\tevent\trepeats\n')
                    for item in self.raw_ring:
                        output.write(item['record'].rstrip(b'\n') + b'\t' +
                                     str(item['repeats']).encode() + b'\n')
                self.failure_diagnostics_dumped = True
            (self.directory/'capture_summary.json').write_text(json.dumps(self.stats(),indent=2,sort_keys=True)+'\n')
        return self.stats()

    def stats(self):
        return dict(schema=2, policy=POLICY, closed=self.closed,
            mandatory_evidence_complete=not self.incomplete_reasons,
            optional_evidence_complete=not self.optional_omitted and not any(
                p.get('omitted',0) or p.get('limit_seen') for k,p in self.producers.items()
                if k!='other' and optional_event(*map(int,k.split(':')))),
            incomplete_reasons=sorted(self.incomplete_reasons),
            optional_records_omitted=self.optional_omitted, observers=self.observers, producers=self.producers,
            event_budgets=dict(self.budgets), event_bytes_by_class=dict(self.used),
            sizes=dict(self.sizes), counts=dict(self.counts), event_limit_bytes=self.event_limit,
            diagnostic_limit_bytes=self.diagnostic_limit, cache_opportunity_limit_bytes=OPPORTUNITY_LIMIT,
            diagnostic_ringbuffer=dict(limit_bytes=self.ring_byte_limit,
                limit_lines=self.ring_line_limit, retained_bytes=self.raw_ring_bytes,
                retained_lines=len(self.raw_ring), duplicate_events=self.raw_ring_duplicates,
                dumped=self.failure_diagnostics_dumped,
                file='hang_ringbuffer.tsv' if self.failure_diagnostics_dumped else None,
                policy='named_diagnostic_events_and_failure_lines_only'),
            total_stream_limit_bytes=self.event_limit+2*self.diagnostic_limit+OPPORTUNITY_LIMIT,
            event_storage='priority reserved TSV; explicit loss accounting; bounded final JSON')


def capture(argv, directory):
    router=Router(directory)
    try:
        proc=subprocess.Popen(argv,stdout=subprocess.PIPE,stderr=subprocess.PIPE,
                              stdin=subprocess.DEVNULL,env={'PATH':'/usr/bin:/bin'})
    except BaseException as exc:
        exc.capture_stats=router.close();exc.simulator_return_code=None;raise
    sel=selectors.DefaultSelector()
    last=time.monotonic()
    try:
        sel.register(proc.stdout,selectors.EVENT_READ,0);sel.register(proc.stderr,selectors.EVENT_READ,1)
        while sel.get_map():
            for key,_ in sel.select(timeout=1):
                data=os.read(key.fileobj.fileno(),65536)
                if data:router.feed(data,key.data)
                else:sel.unregister(key.fileobj)
            if time.monotonic()-last>30:
                print('SIMULATION_IN_PROGRESS='+str(directory)+'; event_bytes='+str(router.sizes['safe_chain_events.tsv'])+
                      '; optional_records_omitted='+str(router.optional_omitted)+
                      '; mandatory_evidence_complete='+str(not router.incomplete_reasons).lower(),flush=True)
                last=time.monotonic()
        return_code = proc.wait()
        router.exit_status = return_code
        return return_code,router.close()
    except BaseException as exc:
        proc.terminate()
        try:proc.wait(timeout=10)
        except subprocess.TimeoutExpired:proc.kill();proc.wait()
        router.exit_status = proc.returncode
        router.force_failure_dump = True
        try:exc.capture_stats=router.close()
        except Exception as close_exc:
            exc.capture_stats=router.stats();exc.capture_stats['close_error']=str(close_exc)
        exc.simulator_return_code=proc.returncode;raise
    finally:
        sel.close()
        proc.stdout.close();proc.stderr.close()
