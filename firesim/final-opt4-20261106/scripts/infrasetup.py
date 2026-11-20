#!/usr/bin/env python3
"""Campaign deployment entry point. Reuse certified images on FPGA 21 only."""
import argparse
import subprocess
import sys
from board_batch import W, TARGET_BDF


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('configuration', choices=['Native', 'C4'])
    parser.add_argument('--bdf', choices=[TARGET_BDF], default=TARGET_BDF)
    args = parser.parse_args()
    option = '--single-native-bdf' if args.configuration == 'Native' else '--single-c4-bdf'
    return subprocess.call([sys.executable, str(W/'scripts/board_batch.py'),
                            '--deploy-only', option, args.bdf], cwd=W)


if __name__ == '__main__':
    raise SystemExit(main())
