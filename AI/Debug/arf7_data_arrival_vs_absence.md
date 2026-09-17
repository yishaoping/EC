# ARF7: data not arrived vs. no data

## Conclusion from the saved waveform

The evidence supports **no sequence-7 data was produced**, rather than a
sequence-7 data packet merely arriving late:

| FST time | Observation |
|---:|---|
| 105577 | GH_BUF/GHM still expose data, but the tag is sequence 6. |
| 105579 | `GH_BUF.buf_all_empty=1`, `ght_filters_empty=1`, destination is zero, and data enqueue valid is zero. |
| 105583 | R_IC allocates the next package. |
| 105585 | The checker segment watermark becomes sequence 7 while data valid remains zero. |
| 105595 onward | ARF/CPS sequence 7 entries enter the ARF CDC path; no sequence-7 data enqueue is visible. |

This proves that a sequence-7 ARF stream exists without a matching observed
data anchor. It does not, by itself, prove at the first `valid=0` cycle that a
future data beat is impossible. That distinction must be made in RTL.

## Required ordering

```text
segment sequence N observed
        |
        +-- real data N enq.fire --> data anchor N --> consume ARF/CPS N
        |
        +-- producer-empty stable + no data/in-flight --> empty anchor N
```

An ARF/CPS head for N remains in the ARF CDC FIFO while neither branch has
completed. Older data consumption (for example sequence 6) cannot authorize
sequence 7.

## Current hardware guard

`GHM.scala` maintains a per-checker wait state keyed by the live segment
sequence. It only enables the zero-payload anchor after:

1. the segment sequence is non-zero and stable;
2. the empty level of the big core that owns this checker is high;
3. that level remains high for three GHM source-clock cycles; and
4. no real data is currently selected.

A real data beat has priority and resets the empty observation window. The
empty transaction is still sent through the normal AsyncQueue and is marked
as sent only on `enq.fire`, so a full CDC queue cannot lose it or duplicate it.

## Protocol boundary

The existing interface exposes a live segment watermark and a producer-empty
level, not an explicit per-package `data_done` or `zero_data` message. The
three-cycle settling guard prevents the observed allocation-edge race and is
conservative for CDC latency, but the strongest future protocol should add an
explicit allocation/data-done handshake carrying the package sequence (or an
epoch for wraparound). That is the only way to distinguish producer completion
from a producer that is temporarily empty and may create data later.

## Static verification

`sbt -batch 'project chipyard' compile` passed. No simulation, Verilator run,
VCD/FST replay, RTL generation, or hardware generation was run.
