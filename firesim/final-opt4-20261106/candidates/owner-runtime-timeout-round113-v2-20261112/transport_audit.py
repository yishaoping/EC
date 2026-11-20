"""Compare preserved stdout prefixes without imposing UART/RTL drain order."""
import hashlib
import io
import re

# These exact startup rows originate in the same bound application ELF. A
# changed payload is not classified away: it remains in the other stream.
UART_ROWS = (
    b'[INIT] checker_mask=0xf status=ready\n',
    b'[INIT] software_interrupt=pass\n',
    b'[RUN] hart=0 status=started\n',
    b'[CONFIG] common_abi=1 harts=5 timer_stride=64 legacy_readback=off\n',
)
ELF_FORMATS = (
    b'[INIT] checker_mask=0x%lx status=ready',
    b'[INIT] software_interrupt=pass',
    b'[RUN] hart=%lx status=started',
    b'[CONFIG] common_abi=1 harts=5 timer_stride=64 legacy_readback=off',
)


def compare(mc_stream, plain_stream):
    """Hash every raw byte; compare each complete MC line in its transport."""
    stats = {}
    for label in ('mc', 'plain'):
        stats[label] = dict(raw_sha=hashlib.sha256(), uart_sha=hashlib.sha256(),
            other_sha=hashlib.sha256(), raw_bytes=0, raw_lines=0, uart_bytes=0,
            other_bytes=0, other_lines=0, partial_bytes=0, uart_rows=[])

    def lines(stream, label):
        s = stats[label]
        for line in stream:
            offset = s['raw_bytes']
            s['raw_sha'].update(line)
            s['raw_bytes'] += len(line)
            s['raw_lines'] += 1
            if not line.endswith(b'\n'):
                s['partial_bytes'] += len(line)
                assert not stream.read(1), 'partial line must be final'
                continue
            if line in UART_ROWS:
                s['uart_rows'].append(line)
                s['uart_sha'].update(line)
                s['uart_bytes'] += len(line)
            else:
                s['other_sha'].update(line)
                s['other_bytes'] += len(line)
                s['other_lines'] += 1
                yield offset, line

    expected = lines(plain_stream, 'plain')
    first = None
    count = 0
    prefix_sha = hashlib.sha256()
    for mc_offset, actual in lines(mc_stream, 'mc'):
        item = next(expected, None)
        count += 1
        if item is not None:
            prefix_sha.update(item[1])
        if first is None and (item is None or item[1] != actual):
            first = dict(channel='all_other_complete_lines', index=count,
                mc_offset=mc_offset, plain_offset=None if item is None else item[0],
                mc=actual.decode(errors='replace'),
                plain=None if item is None else item[1].decode(errors='replace'))
    for _ in expected:
        pass
    a, b = stats['mc']['uart_rows'], stats['plain']['uart_rows']
    # Four rows, in exact program order, must really be present on both sides.
    uart_ok = a == list(UART_ROWS) and b == list(UART_ROWS)
    if first is None and not uart_ok:
        first = dict(channel='startup_uart', mc=[x.decode() for x in a],
            plain=[x.decode() for x in b])
    for s in stats.values():
        assert s['raw_bytes'] == s['uart_bytes'] + s['other_bytes'] + s['partial_bytes']
        for key in ('raw_sha', 'uart_sha', 'other_sha'):
            s[key + '256'] = s.pop(key).hexdigest()
        s['uart_rows'] = [x.decode() for x in s['uart_rows']]
    return dict(passed=first is None, first_mismatch=first, counts=stats,
        compared_other_lines=count, plain_other_prefix_sha256=prefix_sha.hexdigest(),
        uart_match=uart_ok, normalized_bytes=0, dropped_complete_lines=0,
        complete_target_cycle_equivalence=False, roi_complete=False,
        scope='Exact finite stdout prefix within UART and all-other transports; no UART/RTL interleaving equivalence claim.')


def mutation_checks():
    # Model independent host drain order while retaining cycle/payload bytes.
    target = [b'STAGE1_TX S1 source=DCACHE cycle=0000000000000010 data=01\n',
              b'C1: cycle=0000000000000011 data=02\n']
    mc = UART_ROWS[0] + target[0] + UART_ROWS[1] + UART_ROWS[2] + target[1] + UART_ROWS[3]
    plain = b''.join(UART_ROWS) + b''.join(target)
    def accepted(a, b):
        return compare(io.BytesIO(a), io.BytesIO(b))['passed']
    assert accepted(mc, plain)
    mutations = {
        'uart_payload': mc.replace(b'hart=0 status=started', b'hart=1 status=started'),
        'target_payload': mc.replace(b'data=01', b'data=ff'),
        'target_cycle': mc.replace(b'cycle=0000000000000010', b'cycle=0000000000000012'),
        'missing_target_row': mc.replace(target[0], b''),
        'duplicate_target_row': mc + target[0],
        'missing_uart_row': mc.replace(UART_ROWS[2], b''),
        'uart_reorder': mc.replace(UART_ROWS[1] + UART_ROWS[2], UART_ROWS[2] + UART_ROWS[1]),
        'unknown_bracketed_row': mc + b'[UNKNOWN] data=01\n',
    }
    rejected = {name: not accepted(data, plain) for name, data in mutations.items()}
    assert all(rejected.values()), rejected
    return dict(status='PASS_EXACT_TRANSPORT_PARTITION_AND_EIGHT_REJECTED_MUTATIONS',
        independent_drain_order_accepted=True, rejected=rejected)
