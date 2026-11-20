# Actual physical host-clock diagnostic

Only open the immutable fully routed original SVB component checkpoint in an independent process; change actual MMCM CLKOUT0_DIVIDE_F 24 to 30, and verify automatic derived clocks, unchanged other-clock periods, topology counts and target clock register membership. Save full setup/hold/DRC/bus-skew reports. No timing constraint relaxation, target RTL changes, synthesis, router, bitstream or device I/O. This is a diagnostic profile, not a certificate. Any later implementation/admission requires an independently bound actual host-frequency profile and complete timing/DRC validation; never use the original 50 MHz certificate for a different clock. Original 50 MHz tasks remain untouched.

Recovery r2: r1 tool has no redirect command. Preserve exactfailed log; only replace diagnostic property output with native list_property/get_property. No design change in r1 occurred before failure.
