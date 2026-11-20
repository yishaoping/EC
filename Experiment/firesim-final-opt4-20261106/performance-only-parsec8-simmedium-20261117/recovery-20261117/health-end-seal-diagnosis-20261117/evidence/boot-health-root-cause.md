# FPGA21 boot health timeout root cause

The first new-bitstream health attempt was cut off by a 900-second BOOT deadline before user space. This deadline is demonstrably inadequate: the previous Performance-Only run using the byte-identical software/runtime reached Guest READY and received its command after 2178.422152 seconds. New bitstream boot completion remains unproven until the independent retry.

## Evidence boundary

Frozen hardware commit 8f67d038273d3cdc8ecce45cc4e8c5efb5cbbaa4; bitstream a6a3c73e82222b2ce11f86042be73f518a198f927ee99ba32d774dcde08e8b13. All prior health logs, deployment records, timestamps and per-file SHA256 are preserved in failed-health-evidence/ and failure-evidence-manifest.json. The failed sample remains invalid, PARSEC 0/8, no Slowdown.

OpenSBI, Linux Image/vmlinux, rootfs, DTB, driver, FASED settings, BOOM/checker frequency parameters and boot arguments were matched to the prior booted 4915b82 run. Hardware differs by the CSR/RSU repair and physical implementation; the old benchmark subsequently suffered checker faults, so its boot is a boot-time reference only. Its certification is not accepted.

## Symptom and actual stop

- Driver began at 17:32:34.908 Shanghai time. Runner stopped it at 17:47:40.861, 905.954 wall seconds later. Boot limit was 900 s; its check loop and orderly driver termination account for the remaining time. The separate 1800 s limit did not fire first.
- Last Linux message: `[    0.000000] software IO TLB: mapped [mem 0x00000000f9c00000-0x00000000fdc00000] (64MB)`. Linux printk time is 0.000000 during early memory initialization; this is not a host wall timestamp. The old collector did not record per-line host times, so the exact wall time of that line cannot be recovered. File mtime is not substituted for its print time.
- This is before rootfs unpack/mount, /init, EC_GUEST_READY, checker context installation or smoke invocation. UART input remained empty, so no Guest command or benchmark was issued.
- `arch/riscv/mm/init.c:163-164` calls swiotlb_init followed by memblock_free_all; the last print comes from kernel/dma/swiotlb.c:189-200. This brackets a boot-memory-initialization region, not a precise stuck PC.
- Linux marking harts 1–4 unavailable is expected in this bound DT: Linux runs on hart0, firmware reserves harts1–4 for checkers. These lines are not evidence of checker initialization failure.

## Progress versus health

78 recorded heartbeat samples increased strictly, from 7,323,656 at 18 s to 597,949,238 at 904 s; final driver counter 599,424,737. Effective throughput 661,689.729 target cycles/s is close to the earlier approximately 667,749 cycles/s. FPGA-cycle advancement proves simulator progress only; it does not prove retired Guest instructions or checker health.

The older 600 s attempts stopped at `software IO TLB: area num 1.`; the new 900 s attempt has progressed to `mapped ... (64MB)`. Normalized new UART is an exact prefix of the prior booted UART: True. No recorded sbi_trap_error, sbi_hart_hang, mcause=1, checker mismatch, panic, OOM or watchdog is present. No hart PC/CSR/PTE snapshot exists for this stopped attempt; none is inferred.

Host log confirms card21/XDMA4 and expected FASED readback. The fresh root read-only precheck found no driver/device holders; PCIe Gen3 x16, runtime active and all AER totals zero. There is no current DMA/PCIe error evidence. The driver printed PASSED after the runner terminated it; this is not a passing Guest or certification result.

## Proven cause and limits

Proven immediate cause: complete.py reduced health boot allowance to 900 s and measured its 1800 s total from driver launch. The prior identical software needed 2178.422 s to Guest READY, around 1.445–1.452 billion target cycles. The 900 s limit cannot accommodate that known startup, and even the total smoke budget was shorter than it. This is a runner budgeting defect, not evidence requiring another hardware build.

Supported: slow but normal early kernel memory initialization explains the observed prefix and cycle rate. Unproven: that the repaired bitstream completes Linux and all checker work; a new bounded run must establish this. We do not equate advancing cycles with Guest correctness, nor exclude a separate latent hardware fault without testing.

## Minimal software repair

Independent branch repair/boot-health-timeout-20261117. BOOT: 3600 s and 2.4 billion target cycles, whichever first; PREPARATION: 3600 s from command delivery to EC_SAMPLE_START; EXECUTION: 1800 s for smoke, unchanged 43200/172800 s budgets for PARSEC, measured from sample start. This separates boot and checksum/input preparation from execution without changing any target-cycle ROI arithmetic, application, image, input or output rules.

A 120 s target-cycle/no-heartbeat watchdog terminates simulator stalls even if UART noise continues. Advancing cycles cannot bypass the BOOT, PREPARATION or EXECUTION limits. Fatal-trap detection remains immediate and independent. New progress.jsonl records observed UART/phase changes with wall time and real last FPGA cycle; no independent periodic patrol is installed.

25 offline regressions passed, including actual failed and booted logs, actual fatal checker dumps, normal Native logs, independent phase budgets, cycle stalls, missing heartbeat, cycle-running/Guest-not-ready bounds, incomplete health and invalid later-sample rejection. sample_verify.py and fatal_traps.py remain byte-identical; no measurements or checker gates were relaxed.

## Recovery and continuation

After cert/build/software hash and card-idle verification, execute exactly one fresh health attempt under health/ in this independent tree, using the unchanged bitstream and bound firmware. Audited single-card deployment reprograms the same image for a clean independent Guest; it does not modify the bitstream or any other FPGA.

Require real output validation, all four installed and participating checker harts, positive matched package accounting/drain, no fatal traps and successful command exit. Internal S/U/M/CSR/PTE state is not directly sampled: preserve the full generated offline privilege tests and distinguish those from FPGA runtime evidence. Only a fully valid health result may automatically start blackscholes; only valid blackscholes enables the other seven. Any failure preserves evidence and stops without an unchanged retry.
