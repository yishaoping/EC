"""Canonical RISC-V ISA metadata for Linux; no change to DUT extensions."""
import re


def normalize_dts(text):
    changes = []

    def replace(match):
        original = match[1]
        # Generated Rocket/BOOM strings concatenate the first Z extension to
        # single-letter extensions. Linux 6.2 only skips lowercase z... tokens.
        canonical = re.sub(r'(?<!_)([ZSX][A-Za-z0-9]+)', r'_\1', original).lower()
        assert re.fullmatch(r'rv64[a-z]+(?:_[zsx][a-z0-9]+)*', canonical), canonical
        changes.append(dict(original=original, canonical=canonical))
        return 'riscv,isa = "' + canonical + '";'

    result = re.sub(r'riscv,isa\s*=\s*"([^"]+)";', replace, text)
    assert changes, 'missing ISA metadata'
    return result, changes
