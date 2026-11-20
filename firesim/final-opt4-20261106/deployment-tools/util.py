from pathlib import Path
import subprocess

from typing import List, Tuple

def call_vivado(vivado: Path, args: List[str]) -> Tuple[int, str, str]:
    pVivado = subprocess.Popen(
        [
            str(vivado),
            '-mode', 'batch',
        ] + args,
        stdin=subprocess.DEVNULL,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    sout, serr = pVivado.communicate()

    eSout = sout.decode('utf-8') if sout is not None else ""
    eSerr = serr.decode('utf-8') if serr is not None else ""

    # Vivado interactive Tcl can return 0 after a sourced script error.
    # Batch mode plus an explicit success witness prevents false deployment.
    if 'ERROR:' in eSout or 'ERROR:' in eSerr:
        return (pVivado.returncode or 1, eSout, eSerr)
    return (pVivado.returncode, eSout, eSerr)
