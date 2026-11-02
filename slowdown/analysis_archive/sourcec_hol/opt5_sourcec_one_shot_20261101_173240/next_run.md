# One user-run Opt5 SourceC experiment

From `/data1/gzh/EC`:

```bash
bash AI/Debug/scripts/run_opt5_sourcec.sh --report AI/TMP/opt5_sourcec_one_shot_20261101_173240 --jobs 4
```

This runs fresh L1Causal64Config elaboration/RTL, Verilator build, the same current-B
ELF/loadmem/ROI/seed1/500M limit/one simulator thread, then correctness, SC48 and ROI
validation. Build jobs4 only controls compilation. Persistent exclusive launch claim
rejects a second invocation; no retry/resume/sweep/A-prime/new baseline.

Current B comparison is1,648,923 cycles. All functional/integrity/protocol/ordering,
benchmark checksum43439728, observer/native ROI, config/clock/resource, package ownership
and mandatory capture gates must pass before any performance verdict. Original B raw
capture FAIL is preserved; its prior lossless offline recovery remains the reference.
Historical A/newB strict pairing is still pending and is not asserted here.

|Validated outcome|Decision|
|---|---|
|ROI<1,502,513|OPT5_SUCCESS_SUB1P5=YES|
|saving≥100,000|retain strong Opt5|
|50,000≤saving<100,000|retain for combination|
|saving<50,000|stop SourceC direction immediately|
|any validation failure|INVALID; no performance claim or automatic retry|

Results update validation_result.json; raw manifest/logs remain under sealed/arms/B/.
No second SourceC micro-tuning experiment. A later offline-only reanalysis can use the
same Python entry with --analyze-only; it never launches hardware. Static preflight
can use --static-check and does not consume the launch claim.
