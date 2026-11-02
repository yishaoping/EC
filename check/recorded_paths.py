"""Resolve pre-rename evidence paths without changing sealed files or hashes."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent
LEGACY_ROOT = ROOT.parent / 'baseline'


def current_path(value):
    path = Path(value)
    if path.is_absolute() and path.is_relative_to(LEGACY_ROOT):
        return ROOT / path.relative_to(LEGACY_ROOT)
    if not path.is_absolute() and path.parts[:1] == ('baseline',):
        return Path('check') / path.relative_to('baseline')
    return path


def relocate_recorded_paths(value):
    """Translate path values/keys in memory; preserve protocol labels and hashes."""
    if isinstance(value, str):
        if value == str(LEGACY_ROOT):
            return str(ROOT)
        for old, new in ((str(LEGACY_ROOT) + '/', str(ROOT) + '/'),
                         ('baseline/', 'check/')):
            if value.startswith(old):
                return new + value[len(old):]
        return value
    if isinstance(value, list):
        return [relocate_recorded_paths(item) for item in value]
    if isinstance(value, dict):
        return {relocate_recorded_paths(key): relocate_recorded_paths(item)
                for key, item in value.items()}
    return value


def read_record(path):
    with current_path(path).open() as stream:
        return relocate_recorded_paths(json.load(stream))
