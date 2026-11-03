#!/usr/bin/env python3
"""Independent retained-copy protocol contracts; not RTL runtime evidence."""
from dataclasses import dataclass
from pathlib import Path
import importlib.util
import itertools
import random
import unittest


@dataclass(frozen=True)
class Image:
    seq: int
    generation: int
    value: int


class CopyContract:
    """One frozen local incarnation and one lower historical-image owner.

    The oracle tracks bytes and recovery images independently of cache tags.
    A receipt is only legal after the lower copy is committed. Probe or eviction
    may retire local residency, but cannot retire the outstanding source owner.
    """
    def __init__(self, old=Image(5, 10, 0x1234), watermark=5):
        self.local = old
        self.watermark = watermark
        self.epoch = 7
        self.effect_token = 41
        self.permission = 'T'
        self.owner = None
        self.receipt = None
        self.lower = None
        self.history = {}

    def begin(self, older_retained=False):
        if self.owner or older_retained or self.local.seq > self.watermark:
            return False
        self.owner = (self.local, self.epoch)
        return True

    def copy(self):
        image, _ = self.owner
        if self.lower and self.lower != image:
            # The lower-level protection rule is independent of L1 residency.
            if self.lower.seq > self.watermark:
                return False
            self.history[self.lower.seq] = self.lower
        self.lower = image
        return True

    def ack(self, image, epoch):
        assert self.owner == (image, epoch), 'wrong source/identity receipt'
        assert self.lower == image, 'ACK preceded lower data commit'
        if self.local == image and self.epoch == epoch:
            self.receipt = image
        self.owner = None

    def probe(self, invalidate=False):
        self.permission = 'N' if invalidate else 'B'
        if invalidate:
            self.local = None
            self.receipt = None
            self.epoch += 1

    def write(self, image, effect_token):
        if self.owner or self.local is None or self.permission != 'T':
            return False
        if self.receipt != self.local:
            return False
        assert self.local.seq <= self.watermark
        self.local = image
        self.effect_token = effect_token
        self.receipt = None
        return True


class RetainedCopyTests(unittest.TestCase):
    def test_never_overwrite_before_matching_committed_receipt(self):
        for copy_at, ack_at, write_at in itertools.product(range(5), repeat=3):
            c = CopyContract()
            c.begin()
            for cycle in range(5):
                if cycle == copy_at:
                    c.copy()
                if cycle == ack_at and c.lower == c.owner[0]:
                    c.ack(*c.owner)
                if cycle == write_at:
                    old_lower = c.lower
                    if c.write(Image(6, 11, 0x5678), 42):
                        self.assertEqual(old_lower, Image(5, 10, 0x1234))
                        self.assertIsNone(c.owner)

    def test_retained_ack_preserves_resident_epoch_data_and_effect_identity(self):
        c = CopyContract()
        before = (c.local, c.epoch, c.effect_token, c.permission)
        c.begin(); c.copy(); c.ack(*c.owner)
        self.assertEqual((c.local, c.epoch, c.effect_token, c.permission), before)
        self.assertTrue(c.write(Image(6, 11, 0x5678), 42))
        self.assertEqual(c.lower.value, 0x1234)
        self.assertIsNone(c.receipt)

    def test_same_line_older_retained_image_blocks_publication(self):
        c = CopyContract()
        self.assertFalse(c.begin(older_retained=True))
        self.assertTrue(c.begin(older_retained=False))

    def test_probe_races_never_resurrect_or_restore_write_permission(self):
        for invalid, probe_before_copy in itertools.product((False, True), repeat=2):
            c = CopyContract()
            c.begin(); image, epoch = c.owner
            if probe_before_copy:
                c.probe(invalid)
            self.assertTrue(c.copy())
            if not probe_before_copy:
                c.probe(invalid)
            self.assertEqual(c.owner, (image, epoch))
            c.ack(image, epoch)
            self.assertFalse(c.write(Image(6, 11, 0x5678), 42))
            if invalid:
                self.assertIsNone(c.local)
                self.assertIsNone(c.receipt)

    def test_wrong_and_early_receipts_are_rejected(self):
        c = CopyContract(); c.begin()
        image, epoch = c.owner
        with self.assertRaises(AssertionError):
            c.ack(image, epoch)
        c.copy()
        with self.assertRaises(AssertionError):
            c.ack(Image(image.seq, image.generation + 1, image.value), epoch)
        with self.assertRaises(AssertionError):
            c.ack(image, epoch + 1)
        c.ack(image, epoch)

    def test_lower_recovery_history_survives_repeated_local_retention(self):
        c = CopyContract()
        rng = random.Random(20261103)
        expected = {}
        for seq in range(5, 105):
            c.watermark = seq
            self.assertTrue(c.begin())
            old = c.local
            # Arbitrary local backpressure never grants write permission.
            for _ in range(rng.randrange(30)):
                self.assertFalse(c.write(Image(seq+1, old.generation+1, seq), seq))
            self.assertTrue(c.copy())
            c.ack(*c.owner)
            expected[old.seq] = old
            self.assertTrue(c.write(Image(seq+1, old.generation+1, seq), seq))
            for s, image in expected.items():
                self.assertEqual(c.lower if c.lower.seq == s else c.history[s], image)

    def test_sc51_requires_complete_window_and_rejects_corruption(self):
        script = Path(__file__).with_name('analyze_overlap.py')
        spec = importlib.util.spec_from_file_location('analysis', script)
        m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
        row = dict(kind=51, hart=0, cycle=100,
                   nums=[1, 100, 10, 9, 10, 7, 1, 1, 1] + [0]*7)
        capture = dict(observers={'51:0':dict(events_seen=1, footers_seen=1,
            footer_emitted_count=1, omitted=0)}, producers={'51:0':dict(
            produced=1, emitted=1, omitted=0)})
        self.assertEqual(m.retained_copy([row], capture, 100)['status'], 'PASS')
        self.assertEqual(m.retained_copy([row], capture, 99)['status'], 'FAIL')
        self.assertEqual(m.retained_copy([], capture, 100, True)['status'], 'FAIL')
        for i in range(16):
            corrupt = dict(row, nums=row['nums'].copy())
            corrupt['nums'][i] += 101
            self.assertEqual(m.retained_copy([corrupt], capture, 100)['status'], 'FAIL')


if __name__ == '__main__':
    unittest.main(verbosity=2)
