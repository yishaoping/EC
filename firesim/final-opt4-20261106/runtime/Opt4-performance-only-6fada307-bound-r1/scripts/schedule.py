"""Host scheduling adapter; the original artifact and sample gates stay intact."""
PRIORITY = (
    'blackscholes', 'fluidanimate', 'bodytrack', 'freqmine',
    'swaptions', 'ferret', 'dedup', 'streamcluster',
)


def ordered_suite(suite):
    rows = suite['programs']
    names = [row['program'] for row in rows]
    assert len(names) == len(set(names)) and set(PRIORITY) <= set(names)
    rank = {name: i for i, name in enumerate(PRIORITY)}
    ordered = sorted(enumerate(rows), key=lambda pair: (
        rank.get(pair[1]['program'], len(rank)), pair[0]))
    # Keep the canonical suite and every original per-program binding intact.
    return dict(suite, programs=[row for _, row in ordered])


def adapt(original):
    def next_task(suite, records, failures, bitsha):
        return original(ordered_suite(suite), records, failures, bitsha)
    return next_task
