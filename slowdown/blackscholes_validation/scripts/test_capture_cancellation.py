#!/usr/bin/env python3
"""Reduced ownership witnesses for snapshot/exception interleavings.
These CPU contracts supplement the actual full-system RTL regression.
"""
import itertools,unittest
class Capture:
    def __init__(self):
        self.pending=False;self.issued=False;self.cancelled=False;self.identity=None
        self.allocations=[];self.discards=[];self.leases=[]
    def step(self, request=None, admit=False, response=None, flush=False, space=True):
        old=(self.pending,self.issued,self.cancelled)
        discard=self.cancelled or flush
        ready=discard or space
        consumed=response is not None and ready
        if consumed:
            assert self.pending and self.issued,'response without owner'
            assert response==self.identity,'response owner changed'
        if request is not None:
            assert not self.pending,'descriptor overwritten'
            self.pending=True;self.issued=False;self.cancelled=False;self.identity=request
        if admit:
            assert old[0] and not old[1] and not flush
            self.issued=True
        if consumed:
            self.pending=False;self.issued=False;self.cancelled=False
            (self.discards if discard else self.allocations).append(response)
            if not discard:self.leases.append(response)
        if flush:
            if old[0] and old[1] and not consumed:self.cancelled=True
            else:self.pending=False;self.issued=False;self.cancelled=False
        return consumed
class CancellationTests(unittest.TestCase):
    def test_exception_at_every_read_or_hold_edge(self):
        for response_cycle,flush_cycle in itertools.product(range(2,14),range(1,14)):
            c=Capture();c.step(request=(0x8002be80,0x851,1));c.step(admit=True)
            for cycle in range(1,20):
                present=cycle>=response_cycle and not (c.allocations or c.discards)
                c.step(response=c.identity if present else None,flush=cycle==flush_cycle,space=cycle>=12)
            self.assertEqual(len(c.allocations)+len(c.discards),1)
            if flush_cycle<=max(response_cycle,12):
                self.assertEqual(c.allocations,[]);self.assertEqual(c.leases,[])
            self.assertFalse(c.pending);self.assertFalse(c.issued);self.assertFalse(c.cancelled)
    def test_flush_before_admission_cancels_without_response(self):
        c=Capture();c.step(request=(1,2,3));c.step(flush=True)
        self.assertFalse(c.pending);self.assertFalse(c.issued)
    def test_late_response_cannot_allocate_in_new_epoch(self):
        c=Capture();c.step(request=(1,2,3));c.step(admit=True);c.step(flush=True)
        self.assertTrue(c.pending);self.assertTrue(c.issued)
        self.assertTrue(c.step(response=(1,2,3),space=False))
        self.assertEqual(c.discards,[(1,2,3)]);self.assertEqual(c.leases,[])
        c.step(request=(4,5,6));c.step(admit=True);c.step(response=(4,5,6))
        self.assertEqual(c.allocations,[(4,5,6)])
    def test_same_edge_response_flush_discards(self):
        c=Capture();c.step(request=(1,2,3));c.step(admit=True);c.step(response=(1,2,3),flush=True)
        self.assertEqual(c.discards,[(1,2,3)]);self.assertEqual(c.leases,[])
    def test_mismatched_response_is_rejected(self):
        c=Capture();c.step(request=(1,2,3));c.step(admit=True);c.step(flush=True)
        with self.assertRaisesRegex(AssertionError,'owner changed'):c.step(response=(1,9,3))
    def test_old_clear_reproduces_observed_failure(self):
        c=Capture();c.step(request=(1,2,3));c.step(admit=True)
        c.pending=False;c.issued=False
        with self.assertRaisesRegex(AssertionError,'without owner'):c.step(response=(1,2,3))
if __name__=='__main__':unittest.main(verbosity=2)
