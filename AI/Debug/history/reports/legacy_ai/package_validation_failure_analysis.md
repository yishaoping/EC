# Package validation failure analysis

This note uses the saved `test.vcd` FST and the Scala/Chisel sources.  No
simulation or RTL generation was run during the analysis.

## Failure chain

The log reports 39 allocated packages, 36 completed packages, 3 PASS results
and 33 FAIL results.  The three packages that never completed are seq 4, 14
and 26.  Seq 4 and 26 contain one `store_uncache` each, so their checker tail
timestamps are missing even though the checker traffic count is 16.  This is
why the old log reports a negative average latency.

The FAIL results are primarily false failures caused by comparing after the
checker has left the isolated execution context:

```text
instruction-count boundary
  -> R_ICSL enters postchecking
  -> check_done starts ARF/CSR comparison
  -> old postchecking stall drops when the pipeline becomes empty
  -> old privileged-return request uses a later commit, not package completion
  -> checker redirects to pc_special and R_ICSL enters reset
  -> checker management code resumes and writes the integer register file
  -> RSUSL is still comparing that changing register file against BOOM ECP
  -> package_error latches a false ARF mismatch
```

Seq 2 on hart 2 demonstrates the ordering.  At the postchecking boundary the
checker values already equal ECP:

| Register | Checker before return | BOOM ECP | Changed after return |
| --- | ---: | ---: | ---: |
| x8  | `0x80004d20` | `0x80004d20` | `0x0`, then `0x1` |
| x10 | `0x02004000` | `0x02004000` | `0x0` |
| x18 | `0x80004d68` | `0x80004d68` | `0x0`, then `0x1` |

The saved waveform enters privileged postchecking at time 42217, reaches the
special address at 42241, enters reset at 42245, and only starts the RSUSL
comparison at 42253.  Mismatches are then reported for x8, x10 and x18 at
42289, 42297 and 42329.

CSR comparison has a second semantic issue.  While `checker_priv_mode` is
active, the old exception path updates the real `reg_mstatus/reg_mepc` but not
the shadow CSR state used by the checker.  In seq 3 this leaves shadow
`mstatus=0x8000000a0001e088` and `mepc=0x800003d8`, while ECP contains the
architecturally correct trap state `mstatus=0x8000000a0001f880` and
`mepc=0x80000434`.  Treating the CSR ECP tail as an early shadow return further
destroys the state that must be compared.

## Source fix

`R_ICSL.scala` now holds both postchecking states stalled until the common
package-completion predicate is observed.  A privileged return is a one-shot
request generated only after that predicate.

`CSR.scala` now preserves a completed CSR-pair state until local package clear,
mirrors checker M/S exception effects into the corresponding shadow CSRs, and
does not apply a shadow return merely because the ECP tail arrived.  The
synthetic privileged return occurs only after the complete package result.

The resulting ordering is:

```text
instruction-count boundary
  -> freeze checker architectural execution
  -> drain packet ingress and LSL
  -> complete ARF comparison
  -> complete required CSR comparison
  -> form PASS/FAIL package result and timestamp the package
  -> issue normal/privileged return
  -> observe pc_special
  -> local reset/clear
  -> hand the sequenced result to BOOM
```

## Reusable waveform commands

Summarize error sources by package from an extracted trace:

```sh
perl -ne '
if (/tile_prci_domain_(\d+).*package_seq_reg.*= ([01]+)/) {
  $seq{$1}=oct("0b$2")
} elsif (/tile_prci_domain_(\d+).*\.(rsu_slave\.io_check_error|elu\.io_error_st|elu\.io_error_ld|csr\.io_shadow_check_error) = 1/) {
  $err{"$seq{$1},$1,$2"}++
} elsif (/tile_prci_domain_(\d+).*\.full_check_complete = 1/) {
  $done{"$seq{$1},$1"}=1
}
END {
  for $h (1..4) { for $s (1..100) {
    next unless exists $done{"$s,$h"} || grep(/^$s,$h,/, keys %err);
    printf "%d %d %d %d %d\n", $s, $h, ($done{"$s,$h"}//0),
      ($err{"$s,$h,rsu_slave.io_check_error"}//0),
      ($err{"$s,$h,csr.io_shadow_check_error"}//0);
  }}
}' /tmp/package_error_trace.txt | sort -n -k1,1
```

Inspect the seq 2 ARF ordering directly from the FST:

```sh
Debug/fst_signal_trace \
  chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd \
  0 42335 \
  'tile_prci_domain_2\.tile_reset_domain_tile\.core\.(rsu_slave\.(io_core_arfs_in_(8|10|18)|arfs_ss_ECP_ext\.R0_data|checking_counter_memdelay|arf_mismatch)|icsl\.fsm_state)'
```

Static source compilation was checked with Java 17:

```sh
env JAVA_HOME=/usr/lib/jvm/java-17-openjdk-amd64 \
  PATH=/usr/lib/jvm/java-17-openjdk-amd64/bin:$PATH \
  sbt -batch 'project chipyard' compile
```
