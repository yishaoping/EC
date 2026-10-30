# Opt4 hang diagnostics suppressed by printf enable

Latest user run `optimization_4_svb_20261029_120415_a83514b4` built fresh and exited1 at simulator time2099000. Its exact generated `BoomCore.sv:6915` is `assert(~ecWatchdogImminent)`, proving the pipeline watchdog. GAPBS512 did not produce verified/checksum/complete ROI. Hardware hang root cause remains unresolved.

The diagnostic source/patch/tool hashes match the run. However Makefile defines PRINTF_COND as verbose&&done_reset; all new Chisel printf diagnostics inherit it. emulator.cc zero-initializes verbose, and the pinned launcher supplies no -V/--verbose/+verbose. Generated SV and compiled C++ confirm the gate. As a result ring8192/1MiB retains only2 fatal lines, no snapshot or owner events. This is suppression at producer, not ring eviction. The previous READY declaration checked build/marker presence and missed the runtime enable condition.

The offline hang analyzer originally interpreted0 named events as NO_WATCHDOG_OBSERVED. It now resolves a native assertion against only this run's exact generated file/line or explicit watchdog text; missing state produces HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT. Tests reject unrelated assertion labels and cross-run source association. The SVB protocol analyzer now uses manifest n_svb_entries when STOP capacity is absent, eliminating59 false slot8..15 invalid selections while preserving missing-footer failure.

Corrected prefix: all Release/ACK6999/6999, SVB promotion/ACK/completion325/325/325, source conflict0, invalid ACK0, observed C generation regression0. Last SVB completion1,837,183; watermark181->182 at1,845,013; last accepted checker result is CANCEL183 at1,969,461 (clear1,969,462); blocked seq183 samples continue to2,088,049. Exact final architectural progress/fast-line owner/WB/probe/MSHR state cannot be recovered. The compact event multiset equals the previous failure run, aside from same-edge output order.

No functional RTL, thresholds, launcher arguments, source/ACK allocator, same-line order gate,16-entry capacity, geometry or cache observer changed.70 offline tests, BOOM compile, Scala parser, native host fixture, SV lint, launcher static-check and patch/diff checks PASS. Raw run evidence is preserved. No new pure diagnostic simulation is prepared or run. Final status HANG_DIAGNOSTIC_EVIDENCE_INSUFFICIENT; no safe functional root-cause fix or official rerun readiness is claimed.

Full evidence,21 answers, requested reports and tool-only patch: [analysis report](../../TMP/opt4_svb_hang_rootcause_fix_20261030_a83514b4_7c92e1d0/README.md).
