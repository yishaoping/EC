#!/usr/bin/env python3
"""Select only the completed CDC Mem attempt's own physical checkpoint."""
import hashlib
import json
from pathlib import Path
import sys
import zipfile
import argparse

O = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114')
NAME = 'mem-15mhz-altspreadlogic_high'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('output', type=Path)
    parser.add_argument('--check-only', action='store_true')
    args = parser.parse_args()
    out = args.output.resolve()
    assert out.parent == O/'physical/candidates'
    assert out.name in ['mem-10mhz-ssi_spreadslls', 'mem-10mhz-recovery-r2']
    admission = json.loads((O/'admission.json').read_text())
    assert admission['hardware_commit'] == '6e1e9b966d599c442b3bdf2f3a838aae2ee5c6da'
    prior = O/'physical/candidates'/NAME
    result = json.loads((prior/'result.json').read_text())
    assert result['candidate'] == NAME and not result['bitstream_generated']
    assert hashlib.sha256((prior/'run.tcl').read_bytes()).hexdigest() == result['tcl_sha256']
    # The receipt exists only after the owned Vivado has exited. Retain partial
    # routing as well as placement; never restart from synthesis or post-opt.
    for name in ['routed-final.dcp', 'routed.dcp', 'physopt.dcp', 'placed.dcp']:
        cp = prior/name
        if cp.is_file() and zipfile.is_zipfile(cp):
            row = dict(checkpoint=str(cp), sha256=hashlib.sha256(cp.read_bytes()).hexdigest(),
                       prior_result=str(prior/'result.json'),
                       prior_result_sha256=hashlib.sha256((prior/'result.json').read_bytes()).hexdigest(),
                       hardware_commit=admission['hardware_commit'], placement_reused=True,
                       rtl_changed=False, synthesis_repeated=False,
                       reason='Measured 15 MHz failure; preserve its physical state for 10 MHz recovery.')
            if not args.check_only:
                (out/'physical-checkpoint-reuse.json').write_text(json.dumps(row, indent=2)+'\n')
            print(cp)
            return
    raise RuntimeError('No complete owned physical checkpoint; refuse ungrounded replacement placement')


if __name__ == '__main__':
    main()
