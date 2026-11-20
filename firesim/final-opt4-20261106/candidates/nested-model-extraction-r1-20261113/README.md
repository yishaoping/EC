The production bank caller is nested in complete EC. Stock ExtractModel passes
the nonlocal model target to PromoteSubmodule, which rejects it. This isolated
compiler candidate resolves each selected model's parent path using FIRRTL's
stock EliminateTargetPaths pass, preserving unselected sibling instances and the
shared bank model type. The existing promotion and rename implementation runs
unchanged after specialization.

Regression covers local compatibility, nested and partial instance selection,
repeated callers, sequential equivalence for a repeated-parent 128-bank example,
and extraction from the saved actual complete production module. It does not
validate GoldenGate host tokens, area, full EC equivalence, shell FIT, or FPGA.
