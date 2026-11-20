#!/usr/bin/python3
import hashlib
import json
from pathlib import Path

C=Path(__file__).resolve().parent
OLD='/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-host40-shell-recovery-r5-20261112/'
NEW=str(C)+'/'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def rebind(name):
    path=C/name
    data=json.loads(path.read_text())
    rebound={}
    for source,digest in data['files'].items():
        if source.startswith(OLD) or source.startswith(NEW):
            target=str(C/Path(source).name)
            assert Path(target).is_file(),target
            digest=sha(target)
            source=target
        rebound[source]=digest
    data['files']=dict(sorted(rebound.items()))
    path.write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')


rebind('runtime-inputs.json')
rebind('application-inputs.json')
