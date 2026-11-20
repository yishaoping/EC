#!/usr/bin/python3
"""Run the immutable hierarchy analysis over locally bound evidence copies."""
from pathlib import Path
import runpy

ROOT = Path("/data1/gzh/EC")
CANDIDATE = ROOT / "firesim/final-opt4-20261106/candidates/hierarchy-area-rank-r4-20261111"
NAMESPACE = runpy.run_path(
    str(ROOT / "firesim/final-opt4-20261106/candidates/hierarchy-area-rank-r1-20261111/controller.py"),
    run_name="ec_opt4_hierarchy_rank_template",
)
NAMESPACE["REPORT"] = CANDIDATE / "evidence/top-postopt-hierarchical.rpt"
NAMESPACE["PRIOR_STATE"] = CANDIDATE / "evidence/cad-state.json"
NAMESPACE["OUT"] = ROOT / "Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-hierarchy-analysis-r4-20261111"
NAMESPACE["STATE"] = ROOT / "Experiment/firesim-final-opt4-20261106/Opt4-fit-hierarchy-analysis-r4-state.json"
NAMESPACE["main"]()
