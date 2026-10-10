#!/usr/bin/env python3
"""Summarize ec_fst_trace/fst_signal_trace output without decoding values."""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections import OrderedDict
from pathlib import Path

LINE = re.compile(r"^(?P<time>\d+)\s+(?P<signal>.+?)\s+=\s+(?P<value>.*)$")


def read_lines(source: str):
    if source == "-":
        yield from sys.stdin
    else:
        with Path(source).open(encoding="utf-8") as handle:
            yield from handle


def parse(source: str, keep_events: bool = False):
    signals: OrderedDict[str, dict] = OrderedDict()
    ignored = 0
    for raw in read_lines(source):
        match = LINE.match(raw.rstrip("\n"))
        if not match:
            ignored += 1
            continue
        time = int(match.group("time"))
        name = match.group("signal")
        value = match.group("value")
        entry = signals.setdefault(
            name,
            {"changes": 0, "first_time": time, "first_value": value,
             "last_time": time, "last_value": value, "events": []},
        )
        entry["changes"] += 1
        entry["last_time"] = time
        entry["last_value"] = value
        if keep_events:
            entry["events"].append({"time": time, "value": value})
    return signals, ignored


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("trace_file", nargs="?", default="-",
                        help="trace output file, or - for stdin")
    parser.add_argument("--json", action="store_true",
                        help="emit machine-readable JSON")
    parser.add_argument("--events", action="store_true",
                        help="include every transition in JSON output")
    args = parser.parse_args()
    signals, ignored = parse(args.trace_file, keep_events=args.events)
    if args.json:
        output = OrderedDict()
        for name, entry in signals.items():
            item = dict(entry)
            if not args.events:
                item.pop("events", None)
            output[name] = item
        print(json.dumps({"signals": output, "ignored_lines": ignored},
                         ensure_ascii=True, indent=2))
        return 0
    for name, entry in signals.items():
        print(f"{entry['last_time']:>12}  {name}  changes={entry['changes']}  final={entry['last_value']}")
    if ignored:
        print(f"ignored_lines={ignored}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
