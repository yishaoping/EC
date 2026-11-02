# Opt5 SourceC: GO, implementation ready for one user experiment

Current B ROI **1,648,923**. Target **<1,502,513**, saving **≥146,411**.
Static global waitAck→SourceC→victim Release→Acquire serialization is proven.
The two-file fix returns SourceC only during pure waitAck; target set remains locked through terminal ACK.
Runtime opportunity/critical saving and sub1.5 outcome remain UNKNOWN.

- [Quick decision](sourcec_quick_decision.md)
- [Fix and safety](sourcec_fix.md)
- [Validation](validation_result.json)
- [One real command](next_run.md)

Only Scala typing, CPU tests, hashing and static guards executed. Hardware generation,
Verilator build and simulation await the user. Previous B seals/recovered correctness,
raw capture FAIL, claims and reports remain intact. No A-prime or second SourceC run.
Supporting snapshots/logs/minimal delta are under evidence/; the cumulative source seal is under sealed/.
