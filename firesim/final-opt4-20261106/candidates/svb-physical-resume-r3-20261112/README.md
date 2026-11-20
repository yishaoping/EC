Original SVB50MHz sealed-physical1 resume, r3

Reuses the actual completed 3h physical optimization of spread r51 which improved WNS -2.010 to -1.373ns. That attempt failed on Vivado2021.1 runtime rejection of route_design -preserve with -directive Explore. This version removes the incompatible -preserve option and immediately routes physical ECOs without repeating physopt. It retains original 19.998ns target clock, all target RTL, interface, setup/hold/pulse/DRC gates and adds bus-skew checking. It is neither a new target architecture nor a lowered-frequency build.

The original r51 remains active on254-255; this version uses252-253,64GiB and checks at most one existing actual component Vivado process before using the second slot. It has an independent lock to avoid the r51 global physical lock. Whole-Opt4 CAD is unchanged. No FPGA operation occurs.

Source, successful physical checkpoint and failure evidence are immutable and hash-bound. A successful result goes under the original recovery ROOT so existing independent certification and 21-only followers can validate it. It is not certified merely because bitstream generation succeeded.
