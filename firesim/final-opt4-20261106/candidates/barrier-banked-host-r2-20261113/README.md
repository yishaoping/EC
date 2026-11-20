Complete barrier host-sharing experiment, derived from fd5de2b and functional baseline 8491167d.

The two exact full-size configurations have 256 entries: 16 banks x 16 lanes and 32 banks x 8 lanes. Every entry retains valid, sequence, count and request-cycle sum (161 bits), including invalid payload. Global counters, multiplication, overflow tests, reset/error priority and target edges remain unchanged outside the bank projection. The source edit ledger is reversible to the exact parent bytes.

Each configuration first compares all 263 observed outputs for 8704 target cycles, including a separate arbitrary internal overflow seed, and rejects a deliberate seen-register mutation. The first 8192 publicly reproducible tokens then drive actual complete-module Plain and Threaded GoldenGate hosts; all seven public outputs are compared and a negative token mutation must be detected. Proof ports are excluded from those hosts and from the serial OOC maps. Results have module scope, never full EC or full-shell scope.

This isolated experiment selects one identical bank type with a power-of-two instance count. Complete EC currently also has AddressStats sharing and three barrier instances. Their eventual combination needs an explicit single-type/power-of-two composition before a whole-host build. No module savings may be added to a prior whole-host receipt.

The deterministic service uses CPUs 206/207 with a 64 GiB cap and the existing resource guard. It has no board I/O, restarts, new model supervisor, or modifications to any pinned predecessor inputs. Failures are retained and require immutable diagnosed recovery after exact predecessor cgroup release.
