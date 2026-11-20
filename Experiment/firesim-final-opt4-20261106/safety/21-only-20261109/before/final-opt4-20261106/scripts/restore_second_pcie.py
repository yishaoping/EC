#!/usr/bin/env python3
"""Disabled legacy recovery path that performed host-wide PCI operations."""

import sys


def main():
    raise SystemExit(
        'DISABLED: this legacy recovery path unloads global XDMA and rescans the '
        'entire PCI bus. Use the target-only board_batch.py path pinned to '
        '0000:21:00.0 after the active e2 sample ends.'
    )


if __name__ == '__main__':
    main()
