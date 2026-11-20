# Four owner memories: independent host generation

This controller requires successful exact-target annotation resolution, the
corrected actual 405,706/24,192-LUT Plain/MCRams entry maps, and both finite
178,857-value entry parity/mutation receipts. It uses the same `3656aec4`
target FIRRTL unchanged and appends four host memory annotations while keeping
the existing ten core RF memory annotations and all original observation
annotations. Its independent output directory cannot overwrite other jobs.

Execution is restricted to two CPU affinity IDs and 64 GiB address space. It
runs GoldenGate only, using the installed MCRams configuration. It does not
run synthesis, full-application simulation, or FPGA deployment. Source and
output hashes, logs, PID/start/boot identity and stage receipts are preserved.

The target-side image35R, generation518R, packet4R and tracked4R memory
interfaces must remain present with their actual512-entry widths and original
read/write latency/collision settings. Later full-module comparison must keep
all512 generation observations, reset/written masking, inputs and target clocks.
Compiler completion does not prove host/target cycle equivalence, full-DCache
area saving, full Opt4 FIT, or runtime certification.

Run `python3 submit.py` once after the round41-v3 preparation completes. It
checks current campaign policy, copies and binds the actual prerequisite
receipts, then publishes one unique atomic broker request. With no completed
preparation receipt it exits without a request or a waiting CPU process. A
later worker may invoke the same helper safely; an existing request is adopted.
