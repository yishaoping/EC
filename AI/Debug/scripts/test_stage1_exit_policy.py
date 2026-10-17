#!/usr/bin/env python3
"""Standalone host C++ predicate test. No RTL, Verilator, make or simulator."""
from pathlib import Path
import subprocess
import tempfile
import unittest

REPO = Path(__file__).resolve().parents[3]
HEADER = REPO / 'chipyard/generators/chipyard/src/main/resources/csrc/stage1_exit.h'


class ExitPolicyTest(unittest.TestCase):
    def test_every_live_blocker_and_parked_prefetch(self):
        # Retain the tiny fixture under AI/TMP for review; never touch run evidence.
        directory = Path(tempfile.mkdtemp(prefix='stage1_exit_unit_', dir=REPO/'AI/TMP'))
        cache = [f'io_stage1_cache_{i}' for i in range(28)]
        lsu = [f'io_stage1_lsu_{i}' for i in range(9)]
        fields = ['io_stage1_schema'] + cache + lsu
        checks = ['t.io_stage1_schema=1; t.io_stage1_cache_4=1;',
                  'assert(stage1_l1_drained(t));']
        for name in cache[1:4] + cache[5:24] + lsu:
            checks += [f't.{name}=1; assert(!stage1_l1_drained(t)); t.{name}=0;']
        checks += ['t.io_stage1_schema=0; assert(!stage1_l1_drained(t)); t.io_stage1_schema=1;',
                   't.io_stage1_cache_4=0; assert(!stage1_l1_drained(t)); t.io_stage1_cache_4=1;']
        for name in [cache[0]] + cache[24:]:
            checks += [f't.{name}=123; assert(stage1_l1_drained(t));']
        source = '#include <cassert>\n#include "' + str(HEADER) + '"\n'
        source += 'struct FakeHarness {\n' + '\n'.join('unsigned long long '+n+'=0;' for n in fields) + '\n};\n'
        source += 'int main(){ FakeHarness t;\n' + '\n'.join(checks) + '\n}\n'
        (directory/'test.cc').write_text(source)
        subprocess.run(['g++', '-std=c++11', '-Wall', '-Wextra', '-Werror',
                        str(directory/'test.cc'), '-o', str(directory/'test')], check=True)
        subprocess.run([str(directory/'test')], check=True)


if __name__ == '__main__':
    unittest.main()
