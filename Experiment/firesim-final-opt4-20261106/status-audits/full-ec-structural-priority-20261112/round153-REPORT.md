Round153: complete bucket-state bank sharing prepared; actual recovery r3 adopted

The new structure keeps256slots as16identical BucketBank models with16parallel
lanes each. It moves five4x64bit state vectors, valid/sequence, histogram,
65bit add/carry, allocation, retirement and reset into the selected model.
It adds no target pipeline stages or state beyond original bucket registers.
External processCommit/safeError and upstream queue/event/global-error logic
remain outside this private projection. Complete address/EC equivalence and
area are unproved. No production change or FPGA I/O occurred.

R1 was actually started on released218/219 after exact barrier r2 completion,
oldPID absence and empty systemd cgroup. It failed at Scala dependency lookup:
the cached BOOM JAR lacks AddressBucketUpdate. A pre-existing r2 recovery
compiled the unchanged helper but rejected Chisel's prededup BucketBank_1
name. Existing r3 corrects that audit and was adopted with every input pin
verified. No duplicate bank, packed, DSP, histogram area map or parity was
started. R3 was generating the2bank actualhost at14:29UTC. Its2/4bank token
checks, full16x16 plain/threaded token checks and serialized paired maps are
pending. All failed versions and inputs remain intact.

Actual completed evidence:
- Barrier r2: finite parityPASS; actual generatedhost83888->158516LUT and
  44457->131077FF; REJECT +74628LUT/+86620FF. Preserve rejection receipt.
- Pinned histogram r6:2/4thread smokesPASS; Plain256 has8192checked outputs
  over32targettokensPASS (digest dad95fe8a040f1e6). Actual paired area pending.
  This is the strict80source histogram only, not full address/EC equivalence.
- New DCache composition: exact3656aec4 source, nine reversible replacements
  combining prior reservation/image memory candidates, complete DCache
  typecheckPASS. No fullDCache parity or generatedhost area yet.
- Packed fullmodule r1 and fulladdress DSP r1 remain actual live Candidate
  maps; identity matches. No paired gain exists yet.
-8d50489a controller3137848/start28528564 and child3138391/start28529262
  match bootd6c6e410-10ad-4326-86ba-79b657eabd96 and remain liveDUTsynth.

Actual hierarchy was parsed with parent paths, avoiding inclusive double
counting. Boom DCache1501447LUT includes address881587 and barrier children.
Its own row71920LUT means isolated reservation103743/image21460 local gains
cannot simply be subtracted from the fullhost. GHM maximal CDC queues total
115938LUT outside DCache; the four data queues total89537LUT. Actual data CDC
is256deep, sync2, separate enq/deq clocks/resets with Gray indices and safe
reset handshake. Its source RegVec fans all256payload entries to sink selection.
A naive RegVec->Mem retaining256reads is not selected. A future token memory
must preserve old read/write edge ordering, both resets, invalid payload and
all valid/ready bits; installed LabelSRAMModels wraps one clock, so multievent
CDC correctness cannot be assumed. No CDC implementation or saving claimed.

Capacity and schedule: complete generatedhost2420482LUT, capacity1303680,
gap1116802 before shell. Owner-memory saving is already included. Ideal zero
address+barriers still leaves47519LUT above capacity before shell. No new gain
has been booked. The current validated NOTFIT route cannot deliver byNov18;
a viable structural replacement, physical certification and eight complete
real FPGA workloads are unproved.16bank selection is no measuredFMR/MHz/EC
cycle/runtime claim. Preserve SVB artifacts and separate CPU session.

Next: adopt r3, diagnose natural failures only after exact cgroup exit; consume
packed/DSP paired totals when complete; preserve live r6 and CAD. Material
measured savings need source composition, complete-module/alltargetcycle/ABI
checks and fresh completehostpostopt before shell physical work. Existing
certificate->software->runtime owner remains sole card21 handoff.
