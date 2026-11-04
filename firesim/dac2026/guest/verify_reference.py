#!/usr/bin/env python3
"""Output-only checker, never executes a benchmark. Golden files must be trusted inputs."""
import argparse
import hashlib
import json
import math
from pathlib import Path
import sys

def verify(args):
    output=Path(args.output).read_bytes()
    reference=Path(args.reference).read_bytes()
    if args.mode=="bytes":
        correct=output==reference
    elif args.mode=="floats":
        x=[float(s) for s in output.decode().split()]
        y=[float(s) for s in reference.decode().split()]
        correct=len(x)==len(y) and all(math.isfinite(a) and math.isfinite(b) and
                   abs(a-b)<=args.atol+args.rtol*abs(b) for a,b in zip(x,y))
    else:
        # blackscholes.c: input column 9 is DGrefval; pthreads/serial ERR_CHK
        # tests fabs(delta) >=1e-4. TBB uses 1e-5; caller must choose explicitly.
        rows=[line.split() for line in reference.decode().splitlines() if line.strip()]
        count=int(rows[0][0]);prices=output.decode().split()
        correct=(len(rows)==count+1 and len(prices)==count+1 and int(prices[0])==count and
                 all(len(row)==9 and math.isfinite(float(price)) and
                     abs(float(price)-float(row[8]))<args.atol for price,row in zip(prices[1:],rows[1:])))
    print(json.dumps({"correct":correct,"sha256":hashlib.sha256(output).hexdigest(),
                      "reference_sha256":hashlib.sha256(reference).hexdigest(),"mode":args.mode,
                      "absolute_tolerance":args.atol,"relative_tolerance":args.rtol}))
    return 0 if correct else 1

if __name__=="__main__":
    p=argparse.ArgumentParser();p.add_argument("--output",required=True);p.add_argument("--reference",required=True)
    p.add_argument("--mode",choices=["bytes","floats","blackscholes"],default="bytes")
    p.add_argument("--atol",type=float,default=0);p.add_argument("--rtol",type=float,default=0)
    a=p.parse_args()
    if a.atol<0 or a.rtol<0:p.error("negative tolerance")
    try:sys.exit(verify(a))
    except (OSError,ValueError,UnicodeError) as e:
        print(json.dumps({"correct":False,"error":str(e)}));sys.exit(2)
