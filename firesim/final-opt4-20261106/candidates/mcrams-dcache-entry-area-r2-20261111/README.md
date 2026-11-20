# Measured area: real DCache owner-image entry

Uses the exact r5 PlainConfig/MCConfig FPGATop RTL, with all35 read ports,512x81 memory,512-bit ownerWritten reset mask and35 observation capture outputs. Same Vivado2021.1 U280 OOC synthesis settings. No target RTL, live CAD, FPGA or full system changes.

Admission requires r5 finite trace proof and immutable host RTL hashes. Both model builds must report zero black boxes; MCConfig must contain a connected RamModel before synthesis. Detailed hierarchical reports are preserved to distinguish controller/PeekPoke overhead from RAM. The top OOC report is this storage-entry host harness, not complete DCache or Opt4 FIT.

Persistent broker job has2 CPUs,64GiB address-space cap, per-stage immutable receipts and atomically updated state. Failed or partial stages are preserved. No FPGA or production admission.

Area v2 pins CPU250,251, avoiding P0 SVB physical recovery CPU254,255. v1 was queued/deferred and withdrawn before start; its request and broker evidence remain archived.
