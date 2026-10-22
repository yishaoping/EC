# Stage 3 workload preparation: GNU symbol visibility parsing

User run `AI/TMP/stage3_runs/run_jp4_qkjb/` stopped during software manifest
preparation. The precise exception is `ValueError: invalid literal for int()
with base 16: '.hidden'` in stage1_workload.py's newly added symbol-size parser.
BUILD=FAIL labels the runner's preparation/build phase; hardware build, DIRECTED
and SYSTEM had not begun. SOURCE_PROVENANCE=FAIL here is incomplete input
capture after that exception, not an observed hardware source mismatch.

The user's already compiled software is retained at
`AI/TMP/stage1_workload_2Raas2GM/`. Its ELF SHA256 is
`f5f84a1727e1c5466bd69e5e89c96410f1622297c1e62bf31408f176a2b65610`.
Its source.before.json matches the current software sources. Actual objdump
output contains, for example:

```text
00000000800079f8 g     O .rodata 0000000000000100 .hidden __clz_tab
0000000080007e40 g     O .bss    0000000000000100 timer_flags
```

GNU's optional visibility token is between size and name. Thus parts[-2] is
not always the size. The new all-symbol size conversion hit __clz_tab, although
the padded timer symbol itself has the correct 256-byte size and 64B alignment.
The older inline _exit size extraction had the same structural assumption and
could also fail if that function had non-default visibility.

Fix: stage1_workload.py now uses one parse_symbols helper for address and size.
It handles default/.hidden/.protected/.internal visibility consistently, ignores
headers, supports differing flag counts and zero-sized/absolute/undefined
symbol rows, and fails with symbol/row context for a malformed size. The _exit
range uses the parsed size rather than another positional assumption. Timer
layout/source/ELF/dump/loadmem checks remain strict; no fallback value is added.

Added offline `test_stage1_workload.py`: 3 test methods cover all four visibility
forms on both _exit/timer_flags, header/flag variants and rejection of malformed
size data. All pass. Read-only inspection of the real failed run's ELF parses
261 symbols, including 5 hidden symbols; confirms timer base0x80007e40/size256,
_exit range0x800007b0..0x800007d8, AMO pair counts2/2, required HTIF symbols,
source snapshot match and LOAD header parsing. Python AST, shell syntax and
git diff --check pass. No workload preparation/conversion/build or simulation
was executed by the agent, and no old manifest/run artifact was rewritten.

Evidence, exact task preimages and task patch:
`AI/TMP/stage3_symbol_parser_c0denskc/`;
pointer `AI/TMP/stage3_symbol_parser.latest`.
Only the workload parser and its offline test changed functionally; no C,
Scala, directed harness or preservation/coherence logic changed this task.
The user still uses the same no-argument Stage3 runner; the existing source
mismatch handling automatically prepares the updated software on that run.
Old failed status is retained, not retroactively marked PASS.

```ini
STATIC_REVIEW=PASS
ELF_SYMBOL_PARSER=PASS
READY_FOR_DYNAMIC_VALIDATION=YES
STAGE3_STATUS=PATCHED_PENDING_REBUILD
STAGE3_CLOSURE=NO
```

These flags describe static/parser readiness only. No new BUILD/DIRECTED/SYSTEM
PASS or hardware closure is claimed.
