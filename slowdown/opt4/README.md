# Stable Opt4 identity and small reference records

Functional sources remain at chipyard/generators/; the compatible run/config entry
remains ../optimization_4_svb/ and ../run_optimization_4_svb.sh. This directory stores
[frozen_manifest.json](frozen_manifest.json), the byte-identical versioned cumulative
source guard patch and small reference records, not duplicate hardware or build products.

Start with [OPT4_BASELINE](../OPT4_BASELINE.md). Optimization is PAUSED. Raw manifests,
ROI, checksum, corrected host recertification, original shadow FAIL and generated
config/clock identity are kept under reference/. Generated executables, waveforms,
large logs and native build products remain local at their original paths.
