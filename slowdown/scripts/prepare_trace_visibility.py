#!/usr/bin/env python3
"""Static trace-only review. Does not edit source or invoke any build tool.

The original one-time alias insertion has already completed. This filename is
retained as a repeatable checker; it can no longer insert or overwrite aliases.
"""
import hashlib
import json
from pathlib import Path
import re

ROOT = Path("/data1/gzh/EC")
MANIFEST = ROOT / "slowdown/manifests"
BLOCK = re.compile(r"^[ \t]*// SLOWDOWN_TRACE_BEGIN[^\n]*\n(.*?)^[ \t]*// SLOWDOWN_TRACE_END[^\n]*\n", re.M | re.S)


def canonical(text):
    return "\n".join(line for line in text.splitlines() if line.strip())


def inspect():
    aliases = json.loads((MANIFEST / "trace_aliases.json").read_text())
    files = sorted({a["file"] for a in aliases})
    result = {}
    for rel in files:
        before = (MANIFEST / "source_before" / rel).read_text()
        current = (ROOT / rel).read_text()
        blocks = BLOCK.findall(current)
        if not blocks or canonical(BLOCK.sub("", current)) != canonical(before):
            raise RuntimeError("functional text changed outside trace blocks: " + rel)
        actual = []
        for block in blocks:
            for line in block.splitlines():
                line = line.strip()
                if (re.fullmatch(r"val slowdown_\w+ = chisel3\.WireInit\(.+\)", line) or
                    re.fullmatch(r"chisel3\.dontTouch\(slowdown_\w+\)", line) or
                    re.fullmatch(r'slowdown_\w+\.suggestName\(s"slowdown_\w+\$w"\)', line)):
                    actual.append(line)
                elif line and not line.startswith("//"):
                    raise RuntimeError("unapproved observation syntax: " + rel + ": " + line)
        for record in (a for a in aliases if a["file"] == rel):
            name = record["alias"].replace("_<bank>", "")
            declaration = "val " + name + " = chisel3.WireInit(" + record["expression"] + ")"
            if declaration not in actual or "chisel3.dontTouch(" + name + ")" not in actual:
                raise RuntimeError("alias inventory mismatch: " + name)
            if current.splitlines()[record["line"] - 1].strip() != declaration:
                raise RuntimeError("stale source line in inventory: " + name)
            if name in BLOCK.sub("", current):
                raise RuntimeError("alias consumed by functional source: " + name)
        result[rel] = {"trace_blocks": len(blocks), "functional_nonblank_sha256":
                       hashlib.sha256(canonical(before).encode()).hexdigest(),
                       "functional_text_equal": True}
    return {"status": "PASS", "files": result, "observation_aliases": len(aliases),
            "proof_scope": "original functional source text identical after removing trace blocks; blank line additions allowed",
            "elaboration": "NOT_EXECUTED", "compilation": "NOT_EXECUTED", "simulation": "NOT_EXECUTED"}


if __name__ == "__main__":
    print(json.dumps(inspect(), indent=2))
