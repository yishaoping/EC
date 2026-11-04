#!/usr/bin/env python3
"""Run the existing emitted epoch test with outputs in a private build directory."""
import importlib.util
import shutil
import uuid
from seal_candidate import ROOT, OUT

spec = importlib.util.spec_from_file_location("epoch_test", ROOT / "slowdown/parsec_evaluation_20261103/scripts/test_emitted_epoch_cone.py")
test = importlib.util.module_from_spec(spec)
spec.loader.exec_module(test)
test.OUT = OUT / "build" / ("epoch_test_" + uuid.uuid4().hex[:8])
(test.OUT / "build").mkdir(parents=True)
(test.OUT / "logs").mkdir()
(test.OUT / "scripts").mkdir()
shutil.copyfile(ROOT / "slowdown/parsec_evaluation_20261103/scripts/emitted_epoch_cone.cpp",
                test.OUT / "scripts/emitted_epoch_cone.cpp")
test.main()
