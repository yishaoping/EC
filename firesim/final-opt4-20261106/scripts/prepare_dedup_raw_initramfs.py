#!/usr/bin/env python3
"""Reuse every Dedup byte while bypassing the failing gzip unpacking path."""
import datetime as dt
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

def main():
    profile='dedup-staged-raw'
    apps=W/f'software/{profile}-apps-build.json'
    root=W/f'software/{profile}-rootfs-build.json'
    original_apps=W/'software/dedup-staged-apps-build.json'
    original_root=W/'software/dedup-staged-rootfs-build.json'
    if not apps.exists():shutil.copy2(original_apps,apps)
    assert sha(apps)==sha(original_apps)
    if not root.exists():
        state=json.loads(original_root.read_text())
        out=W/'software'/('rootfs-dedup-raw-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ'));out.mkdir()
        # Linux usr/Makefile uses an already packed .cpio.* file directly,
        # without another gzip stage. This file contains the original newc
        # archive, not gzip bytes; Linux detects the newc magic normally.
        target=out/'initramfs.cpio.raw';os.link(state['path'],target)
        assert sha(target)==state['sha256']
        state.update(path=str(target),parent_receipt=str(original_root),parent_receipt_sha256=sha(original_root),
                     transport='uncompressed newc; exact original archive bytes; bypass kernel gzip flush/unpack path')
        save(root,state);save(out/'manifest.json',state)
        # prepare_profile_system validates the shell in <rootfs-dir>/tree.
        (out/'tree').symlink_to(Path(json.loads(original_root.read_text())['path']).parent/'tree',target_is_directory=True)
    subprocess.run(['python3',W/'scripts/prepare_profile_system.py',profile],check=True)

if __name__=='__main__':main()
