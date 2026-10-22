# Stage3 configured assertion matrix

Static source expansion: `(p,c,m,r,f)=(false,true,true,false,true)`, `b=false`.

N = ordinary table allows; F = ordinary table forbids; · = implicit self (not checked by the original table).
Flush commits use the separate strict terminal proof. Matrix includes unreachable BRANCH states.

| before / after | INVALID | BRANCH | BRANCH_C | TIP | TIP_C | TIP_CD | TIP_D | TRUNK_C | TRUNK_CD |
|---|---|---|---|---|---|---|---|---|---|
| INVALID | · | F | F | N | F | F | N | N | F |
| BRANCH | F | · | F | F | F | F | F | F | F |
| BRANCH_C | F | F | · | F | F | F | F | F | F |
| TIP | F | F | F | · | F | F | N | N | F |
| TIP_C | F | F | F | N | · | F | N | N | F |
| TIP_CD | F | F | F | F | F | · | N | F | N |
| TIP_D | F | F | F | F | F | F | · | F | N |
| TRUNK_C | F | F | F | N | N | N | N | · | N |
| TRUNK_CD | F | F | F | F | F | N | N | F | · |

Ordinary: 18 allowed, 54 forbidden, 9 implicit self pairs.

Strict FLUSH_COMMIT allowed edges (each requires issued+sent+matching ACK, cleared metadata/provenance):

- `S_TIP -> S_INVALID`
- `S_TIP_C -> S_INVALID`
- `S_TIP_CD -> S_INVALID`
- `S_TIP_D -> S_INVALID`
- `S_TRUNK_C -> S_INVALID`
- `S_TRUNK_CD -> S_INVALID`

BRANCH/BRANCH_C cannot originate in this configuration. Replacement has a separate EVICT event; a tag miss remains INVALID in the ordinary matrix.

This artifact is not RTL generation, simulation or a proof that all table-allowed paths are reachable.
