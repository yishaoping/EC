Round 148 adopts the existing full-application simmedium EC owner. This audit
only reads producer files and process identities; its output stays in this
directory. Run `python3 audit.py` once; an existing receipt is never overwritten.

The receipt binds all eight contracts and 24 archived Native result JSON files,
the frozen model binary, runner, auditor, and active attempt bindings by SHA256.
It checks the user service, boot ID, PID/start ticks, exact service cgroup,
parent relationships, CPU affinity and actual model arguments. Two process
samples establish CPU activity, independently of guest/target progress.

Current EC runs use full frozen8491167d GoldenGate CPU simulation. Archived
Native runs use FPGA. Passing software/input/memory/frequency checks does not
admit cross-backend slowdown. Runtime output, checker accounting, drain, event
audit and target configuration/counter comparability remain required.

The existing runner owns guest command dispatch, its 6-hour boot, 24-hour run
and 30-minute observed-stall limits, and failure-to-next scheduling. Do not
launch another queue, repeat applications, edit pinned sources, control the
completed independent CPU campaign, or disturb live CAD. Earlier startup-only
host-plumbing failures remain separate preserved evidence, as described in the
producer's host-plumbing-repair.json; this audit does not reopen those runs.

No prior phase/reduced ROI results or SVB component results enter current
simmedium Performance. No plots or performance ratios are generated here.
