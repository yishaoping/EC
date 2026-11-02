# Unclassified legacy DRAMSim logs

No unique run attribution was inferred from timestamps alone. See [relocation manifest](../analysis_archive/cleanup_evidence/log_relocation.json). All22 other repository dramsim.log files already under run/evidence contexts remain unchanged.

- `slowdown/unclassified_logs/root_20261015/dramsim.log`: Tracked legacy root log, mtime2026-10-15 14:19:11+08:00, introduced by1ed07c280; no run/config/benchmark identifier or adjacent manifest. Multiple same-day debug traces prevent unique attribution. SHA256 `3eeb4391f066fafee50345403618575fcd6bb0dfc440f91160e8ffd63cc7d6bc`.
- `slowdown/unclassified_logs/chipyard_verilator_legacy/dramsim.log`: Ignored legacy simulator-CWD log, mtime2026-08-06; no matching manifest/benchmark/config. Not assignable to an Opt4/Opt5 run. SHA256 `032649b7bd03947da445f807a13e43d2e522484d2ea1542a80c6af101c9a210e`.

The small root log was already versioned; its rename preserves history. The simulator-CWD log was ignored and remains ignored; no force-add. These logs are not Opt4 performance evidence.

## Numbered root logs restored on 2026-11-02

Twelve numbered logs were placed in their strongly supported run directories. The first log has no unique run identity and is retained at `root_20261015/dramsim.1.log`. All thirteen files retain their original bytes and local mtimes.

See the [complete relocation manifest](../manifests/workspace_relocation_20261102.json) for SHA256 values, terminal-output timing and available harness/DRAM epoch cross-checks. Neither timestamps nor identical deterministic statistics alone establish run provenance.
