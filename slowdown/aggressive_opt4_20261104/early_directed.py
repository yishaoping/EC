#!/usr/bin/env python3
"""Validate emitted ownership RTL as soon as available, before full C++ build."""
import json
from pathlib import Path
import sys
import time
import traceback
import screen_candidate as screen


def main():
    screen.OUT.mkdir(parents=True,exist_ok=False)
    screen.STATE['state']='WAIT_EMITTED_RTL';screen.save()
    print('EARLY_TEST_STATUS='+str(screen.OUT/'status.json'),flush=True)
    generated=Path(sys.argv[1]).resolve();svb=generated/'gen-collateral/SpeculativeVersionBuffer.sv'
    while not svb.exists() or not svb.read_text().rstrip().endswith('endmodule'):
        time.sleep(15)
    screen.directed('svb_retention',screen.REC/'scripts/test_svb_retention.py',generated,
        [svb,screen.REC/'scripts/svb_retention_driver.cpp'])
    screen.STATE['state']='EARLY_SVB_PASS';screen.save()


if __name__=='__main__':
    try:main()
    except BaseException:
        screen.STATE['state']='EARLY_DIRECTED_FAIL';screen.STATE['error']=traceback.format_exc();screen.save();raise
