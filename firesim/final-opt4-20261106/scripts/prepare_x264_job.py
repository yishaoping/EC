#!/usr/bin/env python3
import subprocess
from board_batch import W
subprocess.run(['python3',str(W/'scripts/prepare_x264.py')],check=True)
subprocess.run(['python3',str(W/'scripts/prepare_profile_system.py'),'x264'],check=True)
