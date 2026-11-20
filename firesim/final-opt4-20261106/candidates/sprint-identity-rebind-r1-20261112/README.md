Offline preparation for committed sprint fd5de2bafb8f5d236dfe240fbecf3436f8c3468a.

The preparer waits for sprint-composed-validate-r1's actual host binding. It
does not regenerate a target or host, map, touch a board, or start a runtime.
It derives a new host identity from the actual RTL, generated collateral,
source binding and threaded configuration. Real generated software ABI
inputs must compare byte-for-byte before the existing driver can be reused.
Changed constraints are bound to the new host and require new shell work.
A changed software ABI refuses driver reuse and records the rebuild need.

The output is a distinct software/runtime bundle plus a handoff request for
the existing root priority owner. The old 3656 runtime, services and pinned
inputs remain intact. No new root runtime service is installed. The prepared
priority entry retains the original artifact, checker, drain, correctness,
atomic completion and card-lock gates and applies the existing eight-program
first scheduling adapter.

The separate certifier requires this exact commit, host ID and RTL, actual
full-shell postopt FIT, successful source-bound shell/link/place/route/final
receipts, and setup/hold/pulse/skew/DRC/unconstrained/routes/bitstream evidence.
It rejects shell-excluded host capacity as physical admission. Neither a
queued service nor the offline admission unit test is physical evidence.
