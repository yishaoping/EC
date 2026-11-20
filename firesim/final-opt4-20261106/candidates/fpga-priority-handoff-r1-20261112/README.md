# FPGA priority handoff

This version keeps the canonical composite MCRams bundle immutable. `controller.py`
imports its original runtime and wraps only `next_task` with the requested eight
application order. Original software receipts, physical certification, device
restriction, smoke/reset/output/checker/drain gates and atomic sample completion
remain in the original runtime.

`follower.py` replaces only the exact idle single-Python certification waiter.
After actual full physical certification, it can retire the obsolete NOT FIT
8da runtime only when its exact two Python processes have no child/sample or
commands. It never signals Vivado or a live sample. The shared runtime lock and
21-card locks remain authoritative.

Offline validation uses the real 13-profile software suite, exercises mandatory
smoke and application-failure behavior, and verifies all 39 formal selections
visit repetition 1 before 2/3. It performs no FPGA I/O.

```sh
python3 validate.py
python3 install.py --validate-only
python3 controller.py --offline
```

Installed service: `ec-opt4-fpga-priority-handoff-r1.service`.
Status: `Experiment/firesim-final-opt4-20261106/fpga-priority-handoff-r1-20261112/state.json`.
