#!/usr/bin/env python3
"""Copy Linux and install the B-only ROI driver, preserving the v3 source/builds."""
import datetime
import json
from pathlib import Path
import shutil
import subprocess
from build_base_linux import WORK, snapshot
from build_minimal import ROOT, sha


def main():
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    source = WORK/'linux'
    destination = WORK.parent/('software-roi-v4-'+stamp)/'linux'
    log = ROOT/'Experiment/dac2026/build-logs/opt4-alveo-v3'/('prepare-roi-linux-'+stamp)
    log.mkdir(parents=True, exist_ok=False)
    before = snapshot(source)
    destination.parent.mkdir(parents=True, exist_ok=False)
    command = ['cp', '-a', '--reflink=auto', str(source), str(destination)]
    subprocess.run(command, check=True)
    if snapshot(destination) != before or snapshot(source) != before:
        raise RuntimeError('Linux copy is not an exact preserved source snapshot')
    installed = {}
    for name in ('ec_dac_roi.c', 'ec_dac_roi_regs.h', 'ec_dac_roi_uapi.h'):
        src = ROOT/'firesim/dac2026/measurement/linux'/name
        dest = destination/'drivers/misc'/name
        if dest.exists():
            raise RuntimeError('refuse overwrite: '+str(dest))
        shutil.copy2(src, dest)
        installed[str(dest.relative_to(destination))] = sha(dest)
    makefile = destination/'drivers/misc/Makefile'
    makefile.write_text(makefile.read_text()+'\nobj-$(CONFIG_EC_DAC_ROI) += ec_dac_roi.o\n')
    kconfig = destination/'drivers/misc/Kconfig'
    kconfig.write_text(kconfig.read_text()+'''
config EC_DAC_ROI
    bool "EC DAC hardware ROI control (B only, requires target device)"
    depends on RISCV && 64BIT && OF && MMU && !SMP
    default n
    help
      Implements the version 1 BEGIN/END/DRAIN ABI over a real target
      controller. Does not emulate missing hardware or support checker
      address spaces. No device is added to the device tree by this option.
''')
    after = snapshot(destination)
    changes = {name: {'before': before.get(name), 'after': after.get(name)}
               for name in sorted(before.keys() | after.keys()) if before.get(name) != after.get(name)}
    expected = {'drivers/misc/'+n for n in ('Makefile', 'Kconfig', 'ec_dac_roi.c',
                                             'ec_dac_roi_regs.h', 'ec_dac_roi_uapi.h')}
    if set(changes) != expected or snapshot(source) != before:
        raise RuntimeError('unexpected source changes')
    receipt = {'phase': 'prepare-roi-linux', 'returncode': 0, 'source': str(source),
               'destination': str(destination), 'commands': [command], 'changes': changes,
               'source_files_preserved': len(before), 'driver_supported': ['B'],
               'C4': 'REFUSED: Linux/checker mm/context protocol not implemented',
               'target_controller': 'NOT_IMPLEMENTED', 'target_execution': 'NOT_RUN',
               'runtime_validation': 'NOT_RUN', 'script_sha256': sha(Path(__file__))}
    (log/'result.json').write_text(json.dumps(receipt, indent=2)+'\n')
    shutil.copy2(__file__, log/'build-script.py')
    (destination.parent/'source-origin.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(log/'result.json', flush=True)


if __name__ == '__main__':
    main()
