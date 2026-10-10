# Package completion evidence from `test.vcd`

This is a read-only waveform analysis. No simulation or RTL/hardware
generation was run. The saved file is an FST container despite its `.vcd`
suffix.

## Completion criterion

For a package to count as normally consumed, the evidence must include all of:

1. Rocket checker `full_check_complete = 1`. In the current RTL this means the
   ingress has drained twice, LSL is empty, ARF checking is complete, and any
   required CSR check is complete.
2. `package_result_fire = 1` with PASS status.
3. The result CDC dequeue fires in GHM (`ghm_result_deq_fire_n = 1`), proving
   the result reached the BOOM-side release path.

`dataConsumedSeq` alone is only a data-anchor indication; it is not package
completion.

## Packages that completed normally

| package sequence | checker | checker-domain evidence | GHM result payload | GHM dequeue/release | conclusion |
|---:|---:|---|---|---|---|
| 2 | checker 1 (`tile_prci_domain_2`, `ghm_*_1`) | `full_check_complete=1` and `arf_check_complete=1` at FST `105417`; `package_seq_reg=2` | FST `105421`: `000...0010`, status `00` (PASS), seq `2` | `ghm_u_result_cdc_1` dequeue at `105455`; `ghm_result_deq_fire_1=1` | **normally complete** |
| 3 | checker 2 (`tile_prci_domain_3`, `ghm_*_2`) | `full_check_complete=1` and `arf_check_complete=1` at FST `107829`; `package_seq_reg=3` | FST `107833`: `000...0011`, status `00` (PASS), seq `3` | `ghm_u_result_cdc_2` dequeue at `107947`; `ghm_result_deq_fire_2=1` | **normally complete** |
| 4 | checker 3 (`tile_prci_domain_4`, `ghm_*_3`) | `full_check_complete=1` and `arf_check_complete=1` at FST `101257`; `package_seq_reg=4` | FST `101261`: `000...0100`, status `00` (PASS), seq `4` | `ghm_u_result_cdc_3` dequeue at `101295`; `ghm_result_deq_fire_3=1` | **normally complete** |

The corresponding data anchors are also visible: `ghm_dataConsumedSeq_1=2`
at FST `83097`, `ghm_dataConsumedSeq_2=3` at `87041`, and
`ghm_dataConsumedSeq_3=4` at `90349`.

## Non-normal and incomplete packages

| package sequence | evidence | conclusion |
|---:|---|---|
| 1 | checker 0 emits payload `0x200000001` at FST `121977`; status `10` is CANCELLED, not PASS. No `full_check_complete` event is present. | cancelled |
| 5 | checker 3 emits payload `0x200000005` at FST `102381`; status `10` is CANCELLED. The checker result event is not a normal completion. | cancelled |
| 6 | `ghm_dataConsumedSeq_3` reaches `6` at FST `102381`, but no matching PASS result/release is observed before the later stall. | data anchor only; incomplete |
| 7 | R_IC allocates sequence 7 around FST `105583`; no data CDC enqueue occurs, while sequence-7 ARF/CPS traffic starts. | no data anchor; blocked |

## Why sequences 1 and 5 were cancelled

The RTL defines cancellation as:

```text
package_cancelled = package_check_active && !full_check_complete &&
                    (new_package || arf_wait_timeout)
```

### Sequence 1: ARF-check timeout

Sequence 1 is checker 0. Its data anchor is consumed at FST `80469`, and its
CPS/ECP ARF streams arrive (`rsu_status` reaches `1` at `80601` and `3` at
`83233`). However, the checker never produces `icsl.if_completion`,
`icsl.io_if_check_done`, or `rsu_slave.io_do_cp_check`; consequently
`rsu_slave.io_if_cp_check_completed` never asserts and
`arf_check_complete` remains false.

After the data/LSL side drains, `arf_waiting_after_data_drain` becomes stable
at FST `105593`. The 12-bit `arf_wait_timeout_counter` then counts to `4095`
at `121973`; `package_cancelled` asserts in the same cycle and emits result
payload `0x200000001` (status `10`, CANCELLED, sequence 1).

The checker FSM repeatedly enters `self_xcpt` at FST `87033`, `100633`, and
`114245`, returning at `88333`, `101825`, and `115405`. Thus the immediate
cause is timeout, while the upstream reason is that the instruction/check-done
handshake never reaches the RSU ARF compare. This is distinct from the later
sequence-7 missing-anchor deadlock. The current source adds an ECP-tail/data-
drained retry request for `do_cp_check`; the saved waveform predates that retry
and remains evidence of the old lost-pulse path.

### Sequence 5: superseded by sequence 6

Sequence 5 is checker 3. It is installed at FST `101353` and becomes active at
`101517`, but no `full_check_complete` or ARF completion event is observed
before the next allocation. At FST `102377`, `io_packet_seq=6`,
`io_packet_seq_valid=1`, and `new_package=1` while sequence 5 is still active.
The `new_package` branch therefore cancels sequence 5 immediately and advances
the registered sequence to 6. Its result payload is `0x200000005` (status `10`,
CANCELLED, sequence 5).

This is an overlap/ownership policy issue: `new_package` only excludes an
outstanding result, not an active unfinished package. It is not an ARF timeout
for sequence 5.

## Answer

Yes. The saved waveform proves at least packages **2, 3, and 4** were
normally consumed to checker completion and released through GHM. It does not
prove that all allocated packages completed: sequence 1 and 5 were cancelled,
sequence 6 has only a consumed data anchor, and sequence 7 has no data anchor
and is the package that leads to the later BOOM idle watchdog hang.
