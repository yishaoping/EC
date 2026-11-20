#!/usr/bin/python3
"""Prepare a one-writer storage alternative and an exact bucket-state lemma."""
from pathlib import Path
import hashlib
import json

C=Path(__file__).resolve().parent
W=C.parent.parent
S=W/'Opt4-fit-dcache-field-read-prune-r1-20261111/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'


def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def put(p,t):
    if p.exists():assert p.read_text()==t,p
    else:p.write_text(t)


def main():
    source=S.read_text()
    old_decl='  val buckets = RegInit(0.U.asTypeOf(new GHBarrierLatencyBucket(window)))'
    new_decl='''  // Private implementation candidate: payload is written only for an accepted event.
  // Resolve/reset changes the masks; the original bucket view still returns exact zeros.
  val bucketValid = RegInit(VecInit(Seq.fill(window)(false.B)))
  val sequenceInitialized = RegInit(VecInit(Seq.fill(window)(false.B)))
  val payload = Mem(window, new GHBarrierStoredWord)
  chisel3.experimental.annotate(midas.targetutils.MemModelAnnotation(payload))
  val buckets = Wire(new GHBarrierLatencyBucket(window))
  buckets.valid := bucketValid
  for (i <- 0 until window) {
    val word = payload.read(i.U)
    buckets.seq(i) := Mux(sequenceInitialized(i), word.seq, 0.U)
    buckets.count(i) := Mux(bucketValid(i), word.count, 0.U)
    buckets.requestCycleSum(i) := Mux(bucketValid(i), word.requestCycleSum, 0.U)
  }'''
    old_reset='''      buckets.valid(i) := false.B
      buckets.seq(i) := 0.U
      buckets.count(i) := 0.U
      buckets.requestCycleSum(i) := 0.U'''
    new_reset='''      bucketValid(i) := false.B
      sequenceInitialized(i) := false.B'''
    old_resolve='''        buckets.valid(i) := false.B
        buckets.count(i) := 0.U
        buckets.requestCycleSum(i) := 0.U'''
    new_resolve='''        bucketValid(i) := false.B'''
    old_event='''    when (eventAccepted) {
      when (!buckets.valid(eventIndex) || bucketResolve(eventIndex)) {
        buckets.valid(eventIndex) := true.B
        buckets.seq(eventIndex) := io.event.bits
        buckets.count(eventIndex) := 1.U
        buckets.requestCycleSum(eventIndex) := io.currentCycle
      }.otherwise {
        buckets.count(eventIndex) := buckets.count(eventIndex) + 1.U
        buckets.requestCycleSum(eventIndex) :=
          buckets.requestCycleSum(eventIndex) + io.currentCycle
      }
    }'''
    new_event='''    when (eventAccepted) {
      val fresh = !buckets.valid(eventIndex) || bucketResolve(eventIndex)
      val next = Wire(new GHBarrierStoredWord)
      next.seq := Mux(fresh, io.event.bits, buckets.seq(eventIndex))
      next.count := Mux(fresh, 1.U, buckets.count(eventIndex) + 1.U)
      next.requestCycleSum := Mux(fresh, io.currentCycle,
        buckets.requestCycleSum(eventIndex) + io.currentCycle)
      payload.write(eventIndex, next)
      bucketValid(eventIndex) := true.B
      sequenceInitialized(eventIndex) := true.B
    }'''
    substitutions=[(old_decl,new_decl),(old_reset,new_reset),(old_resolve,new_resolve),(old_event,new_event)]
    candidate=source
    for old,new in substitutions:
        assert candidate.count(old)==1,old
        candidate=candidate.replace(old,new)
    extra='''class GHBarrierStoredWord extends Bundle {
  val seq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
  val count = UInt(64.W)
  val requestCycleSum = UInt(64.W)
}

'''
    marker='class GHBarrierLatencyStats(val window: Int) extends Module {'
    candidate=candidate.replace(marker,extra+marker)
    projected=candidate.replace(extra,'')
    for old,new in reversed(substitutions):
        assert projected.count(new)==1
        projected=projected.replace(new,old)
    assert projected==source,'Unexpected arithmetic, output or event-policy change'
    put(C/'BarrierLatencyStats.scala',candidate)
    # The pre-state relation is an encoding relation, not equality of hidden RAM bits.
    # Invalid original counts are zero (reset/resolve induction); resolved sequence
    # tags survive, so they use an independent initialized mask, never valid alone.
    proof='''module BarrierStorageProof(
 input valid, initialized, resolve, event_here, reset,
 input [31:0] stored_seq, event_seq,
 input [63:0] stored_count, stored_request, current_cycle,
 output equivalent, output invalid_zero_invariant, output mutant_equivalent);
 wire [31:0] old_seq = initialized ? stored_seq : 32'b0;
 wire [63:0] old_count = valid ? stored_count : 64'b0;
 wire [63:0] old_request = valid ? stored_request : 64'b0;
 wire fresh = !valid || resolve;
 wire next_valid = !reset && (event_here || (valid && !resolve));
 wire next_initialized = !reset && (initialized || event_here);
 wire [31:0] write_seq = fresh ? event_seq : old_seq;
 wire [63:0] write_count = fresh ? 64'd1 : old_count + 64'd1;
 wire [63:0] write_request = fresh ? current_cycle : old_request + current_cycle;
 wire [31:0] physical_seq = event_here ? write_seq : stored_seq;
 wire [63:0] physical_count = event_here ? write_count : stored_count;
 wire [63:0] physical_request = event_here ? write_request : stored_request;
 wire [31:0] candidate_seq = next_initialized ? physical_seq : 32'b0;
 wire [63:0] candidate_count = next_valid ? physical_count : 64'b0;
 wire [63:0] candidate_request = next_valid ? physical_request : 64'b0;
 wire [31:0] reference_seq = reset ? 32'b0 :
     (event_here && fresh ? event_seq : old_seq);
 wire [63:0] reference_count = reset ? 64'b0 :
     (event_here ? write_count : (resolve ? 64'b0 : old_count));
 wire [63:0] reference_request = reset ? 64'b0 :
     (event_here ? write_request : (resolve ? 64'b0 : old_request));
 assign equivalent = candidate_seq == reference_seq &&
     candidate_count == reference_count && candidate_request == reference_request;
 assign invalid_zero_invariant = next_valid || (reference_count == 0 && reference_request == 0);
 // The tempting valid-only sequence mask is incorrect after resolution.
 wire [31:0] mutant_seq = next_valid ? physical_seq : 32'b0;
 assign mutant_equivalent = mutant_seq == reference_seq;
endmodule
'''
    put(C/'storage-proof.v',proof)
    plan=dict(schema='ec-private-barrier-one-writer-storage/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        derived_parent='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        source=str(S),source_sha256=sha(S),candidate_sha256=sha(C/'BarrierLatencyStats.scala'),
        source_projection_sha256=hashlib.sha256(projected.encode()).hexdigest(),
        measured_parent_inclusive_luts=[86896,57262,43538],
        measured_parent_total_luts=187696,parent_resource_scope='Three inclusive hierarchy entries, not a new candidate-area measurement',
        change='Replace per-slot count/request/seq resettable payload with one256x160 Mem, a valid mask and independent sequence-initialized mask. Exactly one dynamic write per accepted event. Keep virtual invalid count/request zero and preserve stale sequence after resolve.',
        no_counter_narrowing=True,target_cycles_unchanged=True,source_outside_storage_byte_equal=True,
        arithmetic_and_overflow_and_outputs_byte_equal=True,physical_target_register_encoding_changed=True,
        intended_memory_ports={'depth':256,'width':160,'dynamic_writers':1,'static_read_words':256},
        area_saving_unknown=True,production_admission=False,full_host_synthesis=False,fpga_access=False,
        proof_scope='Per-arbitrary-bucket next-state encoding relation over160 arbitrary payload bits and arbitrary event/resolve/reset priorities, plus invalid-zero induction. Not complete-module or whole-target formal equivalence.',
        required_next=['Actual Scala compilation and complete-module finite parity, including masked invalid view and sequence after resolve',
                       'Source-bound actual GoldenGate memory port audit and paired complete-module host area',
                       'Exact composition/ABI/target-cycle validation and fresh whole-host post-opt capacity'],
        forbid_naive_high_port_memory_retry=True)
    put(C/'plan.json',json.dumps(plan,indent=2,sort_keys=True)+'\n')
    print('PREPARED_PRIVATE_ONE_WRITER_BARRIER_STORAGE_NO_PRODUCTION_EDITS_OR_AREA_CLAIM')


if __name__=='__main__':main()
