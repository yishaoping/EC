#!/usr/bin/python3
"""Versioned broker recovery with broker-accepted source and report inputs."""
from pathlib import Path
import runpy

ROOT = Path("/data1/gzh/EC")
BASE = ROOT / "firesim/final-opt4-20261106/candidates/hierarchy-area-rank-r1-20261111/controller.py"
NAMESPACE = runpy.run_path(str(BASE), run_name="ec_opt4_hierarchy_rank_template")
NAMESPACE["OUT"] = ROOT / "Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-hierarchy-analysis-r3-20261111"
NAMESPACE["STATE"] = ROOT / "Experiment/firesim-final-opt4-20261106/Opt4-fit-hierarchy-analysis-r3-state.json"
NAMESPACE["main"]()
