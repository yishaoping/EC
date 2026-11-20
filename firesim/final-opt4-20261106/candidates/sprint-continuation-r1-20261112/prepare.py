"""Import compatibility for the immutable production validator's sibling API."""
from pathlib import Path
import importlib.util

_source=Path(__file__).resolve().parent.parent/'address-banked-production-host-r1-20261112/prepare.py'
_spec=importlib.util.spec_from_file_location('ec_original_production_prepare',_source)
_module=importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(_module)
prepare=_module.prepare
