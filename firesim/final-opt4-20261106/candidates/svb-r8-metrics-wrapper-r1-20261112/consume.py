#!/usr/bin/python3
"""Read-only metrics continuation only if the conditional r8 replay completes."""
from pathlib import Path
import importlib.util
import sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,sha
C=Path(__file__).resolve().parent
for path,digest in read(C/'inputs.json')['files'].items():
    assert sha(path)==digest, ('sealed wrapper input changed',path)
p=W/'candidates/svb-application-fpga-metrics-r2-20261112/consume.py'
spec=importlib.util.spec_from_file_location('readonly_r8_metrics',p)
m=importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.RUNS=(D/'cycleprecise-original-svb-host40-shell-application-onboard-r8-20261112',)
m.RUN=m.RUNS[0]
m.OUT=D/'svb-application-fpga-metrics-r8-r1-20261112'
m.main()
