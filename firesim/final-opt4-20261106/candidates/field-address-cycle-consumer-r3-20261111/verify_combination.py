from pathlib import Path
import json
from component_admission import C, D, check

decision, receipt = check(json.loads((C / 'config.json').read_text()))
assert decision == 'READY', (decision, receipt)
path = D / 'build-logs/Opt4-fit-field-address-cycle-consumer-r3-20261111/combined-equivalence.json'
with path.open('x') as f:
    json.dump(receipt, f, indent=2, sort_keys=True)
    f.write('\n')
