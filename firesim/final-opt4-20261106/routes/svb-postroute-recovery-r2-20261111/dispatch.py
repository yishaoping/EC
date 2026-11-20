#!/usr/bin/python3
"""Run immutable r1 dispatcher with strict-cgroup workers and guard."""
import importlib.util
from guard import C,R1,verify,strict_empty


def main():
    verify()
    s=importlib.util.spec_from_file_location('strict_dispatch_r1',R1/'dispatch.py')
    m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
    m.m.unit_empty=strict_empty
    m.UNITS={(p,mode):f'ec-opt4-svb-recovery-{p}-{mode}-r2.service'
             for p in ['original','spread'] for mode in ['postroute','replicate']}
    return m.main()


if __name__=='__main__':main()
