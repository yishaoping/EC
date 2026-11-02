# seq67 runtime confirmation

Clock convention: raw SC column2 is global BOOM cycle; column3 is checker-local cycle. Checker3 runs at half BOOM frequency; comparisons below use the global column, not wall time or FST units. SC46 `n2` is diagnostics flags; `n4` context flags; `n6` architectural depth; `n12` ICSL/local depth. Context bits0=idle,1=return_pending,2=excpt_mode, bits11+=local depth. Diagnostics bits1=request,2=ready,3=dispatch,4=registered entry,5=trap,6=eret,8=deferral,15=special return.

| BOOM cycle | checker-local | raw TSV line | diag flags | context | arch/local depth | Meaning |
|---:|---:|---:|---|---|---|---|
| 939331 | 469439 | 63074 | `0x4` | `0x71` | 0/0 | admit seq67; clean context |
| 939411 | 469479 | 63102 | `0x5` | `0x61` | 0/0 | privileged CPS completed; request becomes pending |
| 939413 | 469480 | 63104 | `0x122` | `0x61` | 0/0 | timer interrupt cause0x8000000000000007; request1/ready0/dispatch0; deferral-rise1 |
| 939415 | 469481 | 63108 | `0x82` | `0x64` | 1/0 | architectural exception1/depth1; CPS remains pending; start is prevented |
| 939857 | 469702 | 63162 | `0xc2` | `0x64` | 1/0 | CSR eret1 while architectural exception/depth still1 |
| 939859 | 469703 | 63163 | `0xe` | `0x61` | 0/0 | exception0/architectural depth0; dispatch1 |
| 939861 | 469704 | 63165 | `0x14` | `0x61` | 0/0 | registered privileged entry1/start_accepted1; clean context |
| 940821 | 470184 | 63288 | `0x4004` | `0xa0` | 0/0 | execution done |
| 940889 | 470218 | 63307 | `0x4804` | `0x82` | 0/0 | full_compare_complete1/local result_fire1; return_pending1 |
| 940905 | 470226 | 63325 | `0xc004` | `0x70` | 0/0 | special-address return valid1; return_pending0 |
| 940907 | 470227 | 63331 | `0x5004` | `0x71` | 0/0 | cleanup complete/context_idle1; result handoff1 |

SC46 line63104 is the decisive trap/dispatch overlap: trap1/request1/ready0/dispatch0, interrupt cause0x8000000000000007 (machine timer interrupt). Previous source dispatched this same pending CPS on that edge; the old first bad start at939415 matches the new deferred edge with exception1. New source holds priv_status1, processes the architectural trap, waits for matching return, and only then generates privileged entry. `ROOT_CAUSE_CONFIRMED` rests on the collision and its delayed dispatch, rather than just a later PASS.

Local trap depth stays0 during this pre-start trap because the checker has not entered package execution; architectural depth goes0→1→0. This is the expected prevention of the old ICSL/architectural-context divergence, not a fabricated local1→0 transition. The independent registered-entry trap-capture branch has counter0 (unexercised).

At940889 result is formed but handoff is still blocked while return_pending1. At940905 special-PC return is observed and return_pending clears. At940907 context_idle1/return_pending0/excpt_mode0/local depth0, cleanup complete and handoff fire. In raw SC4 line63329: flags7=valid/ready/fire. At940911 raw SC3 line63340: seq67 flags3=valid+accepted with no failure/cancel; SC5 line63343 has flags0x37=dequeue valid/ready/fire + release + owner busy. At940912 line63346: flags0x18=release_pending/release with owner bit5 already0; ownership has cleared. At940913 line63348: flags2, release deasserted and owner remains0.

No CANCEL is needed; successful PASS is the terminal result. SC47 last checker3 counters: deferral1, entry-trap0, stale-start0, CANCEL0, seq67 start1/exec1/full-result1/handoff1. Target lifecycle uses35 records and covers handoff at index23, below cap64. All4 SC47 streams remain below128 handoff snapshots. Later periodic traps while stale package_seq still67 occur after ownership release and return normally; they are not new owned/stuck seq67 episodes.

Symptom: old checker3 ownership assert24 (proven). Immediate blocker: old cleanup context not idle (proven). Trigger: trap collision during privileged CPS dispatch, now directly observed and deferred (confirmed with archived source and matched old/new divergence). Amplifier: held context prevents result handoff despite Frontend acknowledgement (old proven). A watchdog increase is not justified.
