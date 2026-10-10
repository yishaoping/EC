---
name: ec-regression-review
description: Compare EC BOOM/Rocket runs and independently validate fix coverage, retirement alignment and statistics without treating program completion as correctness.
---

# ec-regression-review

Use ../regression_alignment.md, ../../prompts/regression_analysis.md and ../../prompts/post_run_audit.md.

Start by determining whether the prior first-bad invariant disappeared in the new run. Independently align BOOM commit with checker PC/instruction/sequence, accounting explicitly for startup and traps. Check final count, DATA/END, LSL consumption, token completions, results/release/safe and benchmark verified/checksum.

State actual exercised boundaries and untested configs. Update ../../state/current_debug_state.md, archive completed bug chain and add demonstrated reusable lessons; leave intermediates in TMP. Do not delete TMP unless this turn's user explicitly authorizes cleanup.
