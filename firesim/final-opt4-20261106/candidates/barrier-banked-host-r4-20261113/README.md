Complete barrier host-sharing experiment, derived from fd5de2b and functional baseline 8491167d.

The two exact full-size configurations have 256 entries: 16 banks x 16 lanes and 32 banks x 8 lanes. Every entry retains valid, sequence, count and request-cycle sum (161 bits), including invalid payload. Global counters, multiplication, overflow tests, reset/error priority and target edges remain unchanged outside the bank projection. The source edit ledger is reversible to the exact parent bytes.

Each configuration first compares all 263 observed outputs for 8704 target cycles, including a separate arbitrary internal overflow seed, and rejects a deliberate seen-register mutation. The first 8192 publicly reproducible tokens then drive actual complete-module Plain and Threaded GoldenGate hosts; all seven public outputs are compared and a negative token mutation must be detected. Proof ports are excluded from those hosts and from the serial OOC maps. Results have module scope, never full EC or full-shell scope.

This isolated experiment selects one identical bank type with a power-of-two instance count. Complete EC currently also has AddressStats sharing and three barrier instances. Their eventual combination needs an explicit single-type/power-of-two composition before a whole-host build. No module savings may be added to a prior whole-host receipt.

The deterministic service uses CPUs 206/207 with a 64 GiB cap and the existing resource guard. It has no board I/O, restarts, new model supervisor, or modifications to any pinned predecessor inputs. Failures are retained and require immutable diagnosed recovery after exact predecessor cgroup release.

R3 corrects only the public trace sampling edge. The full target pre/post-edge miter and negative mutation remain. All 8192 input tokens must match r1 bytes and all 8191 adjacent registered-output states must match the prior trace. Reuses completed r2 Threaded16 hardware and binary; no predecessor input changes.

R4 retains r3 exact target/trace PASS and adds an explicit PRECISE_PEEKABLE synchronization using the installed bridge blocking scalar peek before any multiword read. DONE alone permits output channel skew; mpz peek does not wait. All seven output comparisons and the cycle100 negative mutation remain. Hardware/host generation is reused.
