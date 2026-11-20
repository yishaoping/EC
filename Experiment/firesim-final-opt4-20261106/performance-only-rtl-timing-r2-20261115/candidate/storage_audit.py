#!/usr/bin/env python3
"""Identify actual queue storage after Golden Gate SRAM labeling, no CAD."""
import hashlib
import json
from pathlib import Path
import re
import sys


def main():
    build = Path(sys.argv[1]).resolve()
    p = build/'host/post-wrap-sram-models.fir'
    text = p.read_text()
    chunks = re.split(r'(?m)^  (?:ext)?module ', text)
    modules = {b.split(':', 1)[0].strip(): b for b in chunks[1:]}
    root = re.search(r'(?m)^circuit (\w+)\s*:', text)[1]
    rows = []

    def memory(name):
        block = modules[name]
        m = re.search(r'(?m)^    mem mem :[^\n]*\n\s+data-type => UInt<(\d+)>\n\s+depth => (\d+)', block)
        assert m, ('queue storage is no longer a direct memory', name)
        assert not re.search(r'\binst mem of ', block)
        return dict(module=name, width=int(m[1]), depth=int(m[2]),
                    separately_extracted_MCRAM=False, storage='unannotated asynchronous target memory')

    def walk(name, path):
        for instance, child in re.findall(r'\binst (\w+) of (\w+)\b', modules[name]):
            where = path+'/'+instance
            if re.fullmatch(r'GH_FIFO_SC(?:_\d+)?', child):
                item = memory(child)
                assert (item['width'], item['depth']) == (82, 256)
                rows.append(dict(instance=where, kind='BJL', **item))
            elif name == 'GHM' and re.fullmatch(r'u_result_cdc_\d+', instance):
                source = re.search(r'\binst source of (\w+)\b', modules[child])[1]
                item = memory(source)
                assert (item['width'], item['depth']) == (34, 256)
                rows.append(dict(instance=where, kind='result_CDC', **item))
            else:
                walk(child, where)

    walk(root, root)
    assert sum(x['kind'] == 'BJL' for x in rows) == 8
    assert sum(x['kind'] == 'result_CDC' for x in rows) == 4
    log = (build/'GOLDENGATE.log').read_text()
    models = re.search(r'RAM Models To Extract: (\d+)', log)
    result = dict(status='PASS_ACTUAL_QUEUE_STORAGE_IDENTIFIED', instances=rows,
        complete_system_annotated_SRAM_models=int(models[1]),
        new_queue_independent_MCRAM_extractions=0,
        conclusion='Do not use total SRAM model count as evidence of BJL/result host time multiplexing.',
        wrapped_firrtl_sha256=hashlib.sha256(p.read_bytes()).hexdigest(),
        whole_shell_area_measured=False)
    (build/'queue-storage-audit.json').write_text(json.dumps(result, indent=2)+'\n')
    print(result['status'], 'BJL=8 result_CDC=4 separate_queue_MCRAM=0')


if __name__ == '__main__':
    main()
