# A noninterference audit

A_NON_INTERFERENCE_PROVEN = NO

This is an evidence-coverage limitation, not a rule that any RTL change requires A.

- A remains a valid reference: ROI1707863, exit0, verified1, checksum43439728,
  all24 arm gates PASS, cancelled_results0.
- Retained SC6 rows6518; producer emitted7219. Host capture omitted **701** SC6 rows.
  Kind6 is optional under priority_reserved_v2, despite mandatory capture being PASS.
- All283 retained start rows have excpt_mode0, including checker3 seq67. This supports
  noninterference on the visible starts, but cannot establish the condition globally.
- r2 has no complete counter for `pending privileged CPS && current trap/return`.
  Correct final software output and zero CANCELs do not rule out a safe deferral that
  changes timing. New reset initialization also lacks a complete old boot trace.
- All17 old hardware source hashes are unchanged, and the patch is limited to the
  two privileged dispatch/entry sources plus observation. Scope equality is not
  dynamic timing equivalence.

Do not run A now. Request only B. If B correctness/observer/ROI/diagnostics PASS,
write `CORRECTNESS_CLOSED_BUT_STRICT_PAIRING_REQUIRES_BASELINE_REFRESH` and report old-A
versus new-B numeric differences as **unpaired references**, not geometry-only effects.
Only after that B shows worthwhile benefit may an additional A be discussed. None is
scheduled by the launcher. `a_non_interference_proof.json` is hash-bound into the seal.
