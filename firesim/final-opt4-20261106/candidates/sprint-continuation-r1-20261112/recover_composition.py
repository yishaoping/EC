#!/usr/bin/python3
"""Use the same composition gate with the authenticated recovered module pair."""
from pathlib import Path
import importlib.util

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
spec=importlib.util.spec_from_file_location('immutable_composed_validator',W/'candidates/sprint-composed-validate-r1-20261112/controller.py')
p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
p.HOST=D/'build-logs/Opt4-sprint-production-stack-recovery-r1-20261112'
p.AREA=D/'build-logs/Opt4-sprint-production-recovered-area-r1-20261112'
p.O=D/'build-logs/Opt4-sprint-composed-recovered-validate-r1-20261112'
p.m.O=p.O
if __name__=='__main__':
    try:p.main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=p.now())
            p.save(p.O/'failure.json',p.m.ST)
        raise
