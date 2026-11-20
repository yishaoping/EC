#!/usr/bin/python3
"""Private source projection of the actual MSHR queue; no shared edits."""
from pathlib import Path
import hashlib
import json
import subprocess

C = Path(__file__).resolve().parent
W = C.parent.parent
ROOT = W/'Opt4-area-sprint-20261112'
REL = 'chipyard/generators/boom/src/main/scala/util/util.scala'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def exact(p, text):
    if p.exists():
        assert p.read_text() == text, ('Immutable input changed', str(p))
    else:
        p.write_text(text)


def prepare():
    commit = subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip()
    assert commit == 'fd5de2bafb8f5d236dfe240fbecf3436f8c3468a'
    parent = (ROOT/REL).read_text()
    assert subprocess.check_output(['git','show',commit+':'+REL],cwd=ROOT).decode() == parent
    begin = parent.index('class BranchKillableQueue[')
    end = parent.index('\n// ------------------------------------------\n// Printf helper', begin)
    original = parent[begin:end]
    header = '''import chisel3._
import chisel3.util._
import boom.common._
import boom.exu.BrUpdateInfo
import boom.util.{IsKilledByBranch, GetNewBrMask}
import org.chipsalliance.cde.config.Parameters
'''
    edits = [
        ('  val uops    = Reg(Vec(entries, new MicroOp))',
         '  val uops    = Mem(entries, new MicroOp)\n'
         '  val brMasks = Reg(Vec(entries, UInt(maxBrCount.W)))'),
        ('    val mask = uops(i).br_mask', '    val mask = brMasks(i)'),
        ('    val uop  = uops(i)',
         '    val uop  = WireInit(uops(i))\n    uop.br_mask := brMasks(i)'),
        ('      uops(i).br_mask := GetNewBrMask(io.brupdate, mask)',
         '      brMasks(i) := GetNewBrMask(io.brupdate, mask)'),
        ('    uops(enq_ptr.value).br_mask := GetNewBrMask(io.brupdate, io.enq.bits.uop)',
         '    brMasks(enq_ptr.value) := GetNewBrMask(io.brupdate, io.enq.bits.uop)'),
        ('  out.uop         := uops(deq_ptr.value)',
         '  out.uop         := uops(deq_ptr.value)\n'
         '  out.uop.br_mask := brMasks(deq_ptr.value)'),
    ]
    candidate = original
    for old,new in edits:
        assert candidate.count(old) == 1, old
        candidate = candidate.replace(old,new,1)
    inverse = candidate
    for old,new in reversed(edits):
        assert inverse.count(new) == 1
        inverse = inverse.replace(new,old,1)
    assert inverse == original
    for label,text in [('Reference',original),('Candidate',candidate)]:
        exact(C/(label+'.scala'),'package mshrsplit'+label.lower()+'\n'+header+text)
    # Source-ready implementation affects only the MSHR RPQ and response queue.
    # No installed source or selected implementation is modified.
    production = 'package boom.lsu\n'+header+candidate.replace(
        'class BranchKillableQueue[','class BoomMSHRBranchKillableQueue[',1)
    exact(C/'BoomMSHRBranchKillableQueue.scala',production)
    mshrsrel = 'chipyard/generators/boom/src/main/scala/lsu/mshrs.scala'
    mshrs = (ROOT/mshrsrel).read_text()
    assert mshrs.count('new BranchKillableQueue(') == 2
    revised = mshrs.replace('new BranchKillableQueue(', 'new BoomMSHRBranchKillableQueue(')
    assert revised.replace('new BoomMSHRBranchKillableQueue(', 'new BranchKillableQueue(') == mshrs
    exact(C/'mshrs.scala',revised)
    binding = dict(schema='ec-mshr-split-queue-source/1',hardware_parent=commit,
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        parent_util_sha256=sha(ROOT/REL),parent_mshrs_sha256=sha(ROOT/mshrsrel),
        queue_projection_inverse_byte_equal=True,mshr_callsite_inverse_byte_equal=True,
        queue_edits=edits,entries=16,flow=False,holdable=True,
        mutable_branch_masks_retained=True,all_payload_fields_retained=True,
        target_cycle_changes=0,shared_inputs_modified=False,
        area_saving_unknown=True,production_admission=False,fpga_access=False,
        files={str(C/n):sha(C/n) for n in ['Reference.scala','Candidate.scala',
            'BoomMSHRBranchKillableQueue.scala','mshrs.scala','Emit.scala','controller.py']})
    exact(C/'source-binding.json',json.dumps(binding,indent=2,sort_keys=True)+'\n')
    return binding


if __name__ == '__main__':
    print(json.dumps(prepare(),indent=2))
