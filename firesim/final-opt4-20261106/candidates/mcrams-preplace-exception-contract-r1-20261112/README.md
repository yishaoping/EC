Prepared preplace assertion for a future independently versioned shell recovery.
It is not installed in the existing r4b observer or any live physical flow.

`render.py` adds the read-only verifier to the existing BD/IP top-opt script,
after saving its checkpoint and reports, before the stage can admit placement.
Removing this addition reproduces the pinned r4b script byte for byte. There
is no CAD launcher, request, service, device control, or constraint change.
A future consumer must retain the original capacity/parity, exact predecessor
exit/cgroup, checkpoint reuse, resource and physical certification gates.

`verify.tcl` checks Vivado's valid exception export, nonempty 100% endpoint
coverage, and representative setup/hold timing-path requirements and EXCEPTION
properties. Both target clocks retain the native master and divide-by-one
period; generated multicycles remain setup/hold 1/0 and 2/1. No period is
assigned by the verifier. The existing physical BUFG identity gate is retained.
Unexpected target exceptions and unsupported report formats fail closed.

Round-130 validation uses a four-register primitive diagnostic netlist. It
links and queries timing only; it performs no synthesis, opt_design, placement,
routing, bitstream or FPGA operations. Its period is copied from the saved
shell inventory solely for the fixture. Passing fixture tests does not prove
actual complete-host exception application, physical timing, or certification.
The actual fullshell verifier has not run; the current r4b automatic path
still needs a separately versioned integration before claiming this assertion.
