This consumer reads the completed r5 application replay and writes only its own
`Experiment/firesim-final-opt4-20261106/svb-application-fpga-metrics-r1-20261112/`
output. It performs no CAD, device, deployment, replay, or CPU experiment action.

The manifest pins the already independently audited Canneal target-event
lifetimes, binary integrity receipt, CPU replay proof, board admission, driver
source and layout. Offline validation checks the exact binary and driver hashes,
all 659 complete lifetimes, target-edge arithmetic, percentiles and counts.
The broker request is `svb-application-fpga-metrics-r1-8491167d`; retain that
request if resource admission defers it. Do not launch a second consumer.

Hardware attribution additionally requires the complete r5 application replay,
exact card21/serial, certified bitstream, unchanged admission, raw log hash,
PASS marker, every replay summary count and disabled input cache. The exported
latency is the captured application traffic validated by component replay.
Replay cycles/host second include MMIO overhead; workload ACKs/target cycle
include idle and backpressure. Neither is autonomous peak SVB throughput.
SVB ACK is ownership/writeback completion. Checker and rollback latencies stay
unavailable. This component result cannot admit or represent complete EC.

Validation command:

```
python3 consume.py --offline
```
