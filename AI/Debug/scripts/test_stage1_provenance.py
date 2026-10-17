#!/usr/bin/env python3
"""Offline identity-gate tests; no compiler, make, or simulator process."""
import contextlib
import importlib.util
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

HERE = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('stage1_provenance', HERE/'stage1_provenance.py')
prov = importlib.util.module_from_spec(spec)
spec.loader.exec_module(prov)


class ProvenanceTest(unittest.TestCase):
    def test_source_and_every_generated_unit_are_bound(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            model = root/'generated/model.debug'
            model.mkdir(parents=True)
            (model/'VTestHarness.h').write_text('top header')
            (model/'VTestHarness___024root__DepSet_1.cpp').write_text('leaf implementation')
            sim = root/'simulator'
            sim.write_text('placeholder, never executed')
            manifest, before = root/'manifest.json', root/'before.json'
            sources = {'generators/boom/lsu.scala':'source hash'}
            before.write_text(json.dumps(sources))
            base = ['stage1_provenance.py','--root',str(root),'--sim',str(sim),
                    '--generated',str(model),'--manifest',str(manifest)]

            def invoke(extra=(), changed_sources=None):
                with patch('sys.argv',base+list(extra)), patch.object(prov,'source_record',return_value=changed_sources or sources), patch.object(prov.subprocess,'check_output',return_value='STAGE1_TX STAGE1_SIM_EXIT EXIT_DRAIN CLEAR_CHECK'), contextlib.redirect_stdout(io.StringIO()):
                    return prov.main()

            self.assertEqual(invoke(), 1)  # Run cannot silently mint provenance.
            self.assertEqual(invoke(['--write','--source-snapshot',str(before)]), 0)
            self.assertEqual(invoke(), 0)
            self.assertEqual(invoke(changed_sources={'generators/boom/lsu.scala':'changed'}), 1)
            (model/'VTestHarness___024root__DepSet_1.cpp').write_text('changed leaf')
            self.assertEqual(invoke(), 1)
            self.assertEqual(invoke(['--write','--source-snapshot',str(before)]), 1)

    def test_build_input_drift_prevents_manifest_write(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            model = root/'generated/model.debug'
            model.mkdir(parents=True)
            (model/'VTestHarness.h').write_text('header')
            sim = root/'sim'; sim.write_text('not executable')
            before = root/'before.json'; before.write_text('{"source":"before"}')
            manifest = root/'provenance.json'
            argv = ['stage1_provenance.py','--root',str(root),'--sim',str(sim),
                    '--generated',str(model),'--manifest',str(manifest),
                    '--write','--source-snapshot',str(before)]
            with patch('sys.argv',argv), patch.object(prov,'source_record',return_value={'source':'after'}), patch.object(prov.subprocess,'check_output',return_value='STAGE1_TX STAGE1_SIM_EXIT EXIT_DRAIN CLEAR_CHECK'), contextlib.redirect_stdout(io.StringIO()):
                self.assertEqual(prov.main(),1)
            self.assertFalse(manifest.exists())


if __name__ == '__main__':
    unittest.main()
