#!/usr/bin/env python3
"""Idempotent software preparation service; no hardware or active sample inputs."""
import subprocess
from board_batch import W
if not (W/'software/facesim-staged-resident-apps-build.json').exists():
    subprocess.run(['python3',str(W/'scripts/prepare_facesim.py'),'--stage','--preload-controls'],check=True)
subprocess.run(['python3',str(W/'scripts/prepare_profile_system.py'),'facesim-staged-resident'],check=True)
