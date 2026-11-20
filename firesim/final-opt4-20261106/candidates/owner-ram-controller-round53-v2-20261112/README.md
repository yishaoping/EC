# Actual owner RAM controller proof, round 53 v2

Versioned recovery after the v1 conjunction timed out. The frozen target and
actual emitted RamModel are unchanged. The exact original relation is factored
into control, pipeline, and all 35 held-payload relations. Each factor is proved
from the full preceding-edge relation, covering the same induction conjunction.
No induction hypotheses are weakened and no extra data/control cut is introduced.
Yosys opt -full performs ordinary logic simplification before SAT.

The sole cut remains the explicitly documented symbolic memory-read word.
Separate storage induction uses the original uncut memory writer. Reset,
observations, writer gates and seven actual-source mutations remain required.
This is host controller evidence, not complete target/FAME/DCache/Opt4 equivalence,
area/FIT or FPGA admission. The failed v1 source/logs are immutable.
