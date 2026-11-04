from __future__ import annotations
import hashlib
import json
import os
from pathlib import Path
import tempfile

KIT = Path(__file__).resolve().parents[1]
ROOT = KIT.parents[1]
DATA = ROOT / "Experiment" / "dac2026"
FIRESIM = KIT / "work/opt4-alveo-v3/C4/chipyard/sims/firesim"
MANAGER_ENV = ROOT / "firesim/envs/manager-1.17.1"

def canonical(obj):
    return json.dumps(obj, sort_keys=True, separators=(",", ":"), ensure_ascii=False)

def digest(obj):
    return hashlib.sha256(canonical(obj).encode()).hexdigest()

def filehash(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()

def read_json(path):
    return json.loads(Path(path).read_text())

def kit_identity():
    inputs={}
    for base in (KIT/"ec_dac",KIT/"measurement",KIT/"guest",KIT/"scripts",KIT/"area"):
        for p in base.rglob("*"):
            if p.is_file() and p.suffix in {".py",".h",".hpp",".c",".cc",".sh",".tcl"}:
                inputs[str(p.relative_to(KIT))]=filehash(p)
    return {"id":digest(inputs),"files":inputs}

def atomic_json(path, obj, replace=True):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix="." + path.name + ".", dir=path.parent)
    try:
        with os.fdopen(fd, "w") as f:
            f.write(canonical(obj) + "\n")
            f.flush()
            os.fsync(f.fileno())
        if not replace and path.exists():
            raise FileExistsError(path)
        if replace:
            os.replace(tmp, path)
        else:
            os.link(tmp, path)  # no-clobber, including a concurrent creator
            os.unlink(tmp)
        d = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
        try:
            os.fsync(d)
        finally:
            os.close(d)
    finally:
        if os.path.exists(tmp):
            os.unlink(tmp)

def require(condition, message):
    if not condition:
        raise ValueError(message)

def name(value):
    require(bool(value) and all(c.isalnum() or c in "_.-" for c in value),
            "identifier must contain only letters, numbers, _, . or -")
    require(value not in (".", ".."), "invalid identifier")
    return value
