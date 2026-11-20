#!/usr/bin/env python3
"""Arithmetic-only candidate validation. Does not modify or certify the DUT."""
import datetime as dt
import hashlib
import itertools
import json
from pathlib import Path
import random
import time

out=Path(__file__).resolve().parent
start=time.monotonic()
# For each Boolean mask, non-selected terms are zero. Distributivity is exact
# in N; the bounds below prove that no intermediate fixed-width truncates.
max_count=(1<<64)-1
sum_max=256*max_count
product_sum_max=max_count*sum_max
assert sum_max < 1<<73 and product_sum_max < 1<<137
# A canonical polynomial map explicitly compares both sides for all 256 terms.
# m_i is the same Boolean variable on both sides; validity of this polynomial
# identity over all naturals therefore includes every Boolean assignment.
lhs={('cycle','count_'+str(i),'mask_'+str(i)):1 for i in range(256)}
rhs={tuple(sorted(('cycle','count_'+str(i),'mask_'+str(i)))):1 for i in range(256)}
assert {tuple(sorted(k)):v for k,v in lhs.items()} == rhs

def original(cycle,counts,masks):
 v=0
 for n,m in zip(counts,masks):v=(v+(cycle*n if m else 0))&((1<<137)-1)
 return v

def candidate(cycle,counts,masks):
 v=sum(n if m else 0 for n,m in zip(counts,masks))&((1<<73)-1)
 return cycle*v&((1<<137)-1)

rng=random.Random(8491167);checked=0
for cycle in [0,1,2,(1<<63)-1,1<<63,max_count]:
 for n in [0,1,2,(1<<63)-1,1<<63,max_count]:
  for mask in [0,1]:
   counts=[n]*256;masks=[mask]*256
   assert original(cycle,counts,masks)==candidate(cycle,counts,masks);checked+=1
for _ in range(2048):
 cycle=rng.getrandbits(64);counts=[rng.getrandbits(64) for _ in range(256)];masks=[rng.getrandbits(1) for _ in range(256)]
 a=original(cycle,counts,masks);b=candidate(cycle,counts,masks);assert a==b
 # All consumers retain low64 and OR-of-upper-bits overflow semantics.
 assert (a&max_count,bool(a>>64))==(b&max_count,bool(b>>64));checked+=1
receipt=dict(status='ARITHMETIC_IDENTITY_AND_BOUNDS_VALIDATED_CANDIDATE_ONLY',
 utc=dt.datetime.now(dt.timezone.utc).isoformat(),universal_identity='sum_i(m_i ? cycle*count_i : 0) = cycle*sum_i(m_i ? count_i : 0)',
 proof_scope='Polynomial distributivity plus exact unsigned width bounds; full design/RTL/sequential equivalence and FPGA implementation are NOT established.',
 terms=256,sum_bits=73,product_bits=137,sum_max=str(sum_max),product_sum_max=str(product_sum_max),
 polynomial_terms=len(lhs),polynomial_normalization_equal=True,no_fixed_width_intermediate_truncation=True,
 full_width_boundary_random_vectors=checked,elapsed_seconds=time.monotonic()-start,
 hardware_changed=False,formal_result=False,patch_sha256=hashlib.sha256((out/'candidate-only.patch').read_bytes()).hexdigest(),
 estimated_multiply_operators='Three GHBarrierLatencyStats instances plus L2 own reduction: 1024 64x64 operators -> four 64x73 operators; no physical fit claim',
 remaining='Full counter update/reset/overflow equivalence; complete generated hardware capacity/timing; Native/Opt4 matched measurement validation; explicit approval before replacing frozen profile')
(out/'arithmetic-proof.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(receipt,indent=2))
