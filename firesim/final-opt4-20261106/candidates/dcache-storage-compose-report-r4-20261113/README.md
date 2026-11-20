Adopt the completed r3 full-DCache map and existing 3656 reference. The collector
failed after successful checkpoint generation because a shared parser hardcodes
the design FPGATop. Parameterize the expected design and require the exact
BoomNonBlockingDCache top in both utilization and hierarchy reports. All device,
capacity, total, primitive, hierarchy and black-box checks remain active.

No CAD, RTL generation, reference remap, simulation, or FPGA operations. Preserve
the original failure and bind completed artifacts and their private source
variant separately from this report-recovery code commit.
