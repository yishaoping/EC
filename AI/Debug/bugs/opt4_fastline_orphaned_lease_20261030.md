# Opt4: FST-confirmed orphaned fast-line lease

The final waveform run `optimization_4_svb_waveform_20261030_014511_32d45e01` failed with the pipeline watchdog (capture complete, benchmark not complete). The FST and all twelve starting hardware files are tied to the saved manifest. This investigation did not launch a simulator.

First bad transition: FST3,656,087 / pre-edge core1,827,940 changed the saved set143/way1 slot from epoch0x16/key179:0x158a8 to epoch0x17/key3:0xb92e. `svbCaptureResidentMatch` fell but `svbFastLineValid` remained set for line0x800123c0/package183. The original store subsequently completed at way0/epoch0x11 (functional token0x1cc33, core1,836,859); the old way-specific release did not recognize it.

At the watchdog, line0x80008040/token0x1cc34 could not establish preservation solely because the global fast-valid gate was false. All WB, probe, six MSHRs and sixteen SVB entries were idle/free. The ROB was empty, not holding a valid stuck memory head; the committed STQ0 byte store at PC0x80000a94 retried every three cycles, filled STQ and stopped dispatch. Last commit was core1,837,022. This is an orphaned ownership deadlock with retry livelock, not a proven WB/probe/MSHR ABBA cycle. Do not manufacture a closed cycle from stale payloads.

Implemented fix in DCache: revoke the bypass lease on complete resident identity loss; bind S2/S3 bypass to saved way/epoch/key/incoming package; scope legacy preservation conflict by physical line; serialize capture against legacy handoff on the single freeze descriptor. Retained SVB ordering/source/ACK/watermark semantics and SVB16 capacity remain intact. DEADLOCK-1/OWNER-1/WB-1 assertions complement existing ORDER protection. Independent publication-oracle tests preserve same-line ordering through ACK.

Static validation and next formal fresh-run readiness are tracked in [the report](../../TMP/opt4_svb_fst_rootcause_fix_20261030_114113_773ea77d/README.md) and its `validation_result.json`. Hardware correctness and ROI remain pending the next user-run, non-trace Opt4 validation. No additional pure observation run is authorized or prepared.
