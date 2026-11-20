# Actual host40 shell WNS diagnosis and short recovery path

Actual after-setup report proves WNS-0.424ns is in250MHz XDMA shell. Worst asyncFIFO pointer FDCE→RAMD32→outputFDRE has3.935ns datapath,95.476%route,1logic level; Qnet522loads contributes3.463ns. Next reset FDCE→XDMA output-resetFDRE has4.184ns datapath,98.112%route,0logic levels;979loadnet contributes4.105ns. No target functionality is implicated by these top20setup paths. Exact source/destination/clock/delay entries and original report SHA are in parsed-top20-setup.json.

Vivado2021.1 real tool help states fully-routed `-tns_cleanup` fixes TNS but not WNS. Therefore the first attempt explicitly runs only postroute routing/placement optimizations, saves physical DCP, then legal Explore/tns_cleanup. It does not repeat broad3h physopt or any RTL synthesis. Failure automatically tries bounded safe shellFDQphysical replication from actual negative setup paths, reusing the successful final routedDCP. ASYNC_REG/DONT_TOUCH/target/nonFD/lowfanout nets are excluded. All clock/setup/hold/route/DRC/pulse/bus-skew gates stay required.

Root-admitted one extra small component slot224-225/64GiB has live checks MemAvailable>=256GiB,disk>=150GiB,load<48,max3actualcomponentVivados. This is distinct from fullOpt4 CAD; existing jobs are untouched. Independent r2 certificates and21-onlyrootfollowers preserve profile/bit/source/tracebinding. No successful timing, bitstream or FPGA result is inferred from preparation.

## Actual launch

2026-11-12 02:09:06 UTC: root installed and started all3r2 services. Physical controllerPID2429073 (boot/start recorded in r2-actual-started.json) launched strategyAchild2429130 on224-225 and is opening sealed host40 DCP. Rootcertification and applicationfollowers remain idle waiting, no FPGA I/O. All62bound inputfiles match their manifest after startup; no liveinputs changed. A candidate query robustness concern was caught before any attempted write by the MainPIDguard, so no mutating operation executed; it is not an observed toolfailure. Existing r3/r51/r4/host40r1remain unchanged.

## Actual query/command validation and conditional C/D continuation

At02:12UTC the real r2A design query successfully selected14 safe negative shellFDQnets; the earlier name-resolution concern did not reproduce, and no input was modified. Vivado accepted `phys_opt_design -routing_opt -placement_opt` on100%fullyrouteddesign and entered physical synthesis.

Independent r3 successor was prepared with77hashedinputs and both runtime/applicationofflinebindingchecks passed. Actual guard testing rejected the still-live r2predecessor (False), while3componentworkers were observed. Rootinstaller entry is candidates/svb-host40-shell-recovery-r3-20261112/install.py. It initially starts only persistentwaiting while r2isactive. After recordedfailure+exactservice/cgroupexit, it reuses224-225slot and bestactualfinalWNScheckpoint for C(clockskewopt), then D(bounded shortest-delayreroute) if needed. Both options are supported by saved real Vivado2021.1help, preserve targetRTL/clockperiods and fullgates, and never resynthesize. Existingr2success wins. This continuation is not a physicalpass or a newFPGAresult.

C/D actual systemd installation confirmed: 2455877=WAITING_R2_ACTUAL_FAILURE_AND_EXACT_CGROUP_EXIT_NO_CAD, 2455878=WAITING_INDEPENDENT_HOST40_PHYSICAL_RESULT_NO_FPGA_IO, 2455879=WAITING_CERTIFIED_COMPONENT_AND_REAL_APPLICATION_CPU_REPLAY. No extraCAD/FPGAwork launched; installation receipt SHA 2c36552df4afd2dce153d352e7bbf06ec6f75d1de90dfff61e07b41546458f36.
