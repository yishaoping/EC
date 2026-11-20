#!/usr/bin/python3
"""Exact existing area continuation, bound to the recovered validator only."""
from pathlib import Path
import importlib.util

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
spec=importlib.util.spec_from_file_location('immutable_area_continuation',W/'candidates/address-banked-production-area-pair-r1-20261112/controller.py')
p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
p.P=D/'build-logs/Opt4-sprint-production-stack-recovery-r1-20261112'
p.O=D/'build-logs/Opt4-sprint-production-recovered-area-r1-20261112'
p.m.O=p.O
p.UNIT='ec-opt4-sprint-production-stack-recovery-r1-20261112.service'
original_abi=p.production_abi


def abi():
    # The recovered validator reuses exactly the original target RTL and
    # proof receipts; supply that authenticated file without regeneration.
    src=D/'build-logs/Opt4-address-banked-production-host-r1-20261112/Module-target'
    dst=p.P/'Module-target'
    if not dst.exists():dst.symlink_to(src,target_is_directory=True)
    return original_abi()


p.production_abi=abi
if __name__=='__main__':
    try:p.main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=p.now())
            p.save(p.O/'failure.json',p.m.ST)
        raise
