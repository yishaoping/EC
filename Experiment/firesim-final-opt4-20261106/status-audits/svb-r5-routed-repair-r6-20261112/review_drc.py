#!/usr/bin/python3
"""Read saved DRC and checkpoint constraints; emit a separate review receipt."""
import collections
import datetime
import hashlib
import json
from pathlib import Path
import re
import zipfile

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = Path(__file__).resolve().parent
E = D/'cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication'
R4 = D/'cycleprecise-svb-host40-shell-recovery-r4-20261112/D-shell-critical-shortest-route'


def sha(p):
    with p.open('rb') as f:
        return hashlib.file_digest(f, 'sha256').hexdigest() if hasattr(hashlib, 'file_digest') else hashlib.sha256(f.read()).hexdigest()


def parse(p):
    text = p.read_text()
    rows = []
    for m in re.finditer(r'^([A-Z]+-\d+)#(\d+) (Warning|Critical Warning|Error)\n(.*?)(?=\n[A-Z]+-\d+#\d+ (?:Warning|Critical Warning|Error)|\Z)', text, re.M | re.S):
        rows.append(dict(rule=m[1], number=int(m[2]), severity=m[3], detail=m[4].strip()))
    declared = int(re.search(r'Violations found:\s*(\d+)', text)[1])
    assert len(rows) == declared, (len(rows), declared)
    return rows


def main():
    rows, old = parse(E/'drc-final.rpt'), parse(R4/'drc-final.rpt')
    counts = collections.Counter(x['rule'] for x in rows)
    assert counts == {'NTCN-8': 16, 'PDCN-1569': 10, 'REQP-1858': 22, 'RTSTAT-10': 1}
    pins = []
    for x in rows:
        if x['rule'] != 'PDCN-1569':
            continue
        m = re.search(r"physical LUT pin '([^']+)'.*?cell (.*?) \(pin (.*?)\).*?equation: '([^']+)'", x['detail'])
        assert m and m[1] not in re.findall(r'\bA[1-6]\b', m[4])
        pins.append(dict(cell=m[2], logical_pin=m[3], unused_physical_pin=m[1], equation=m[4], unused_input_absent_from_equation=True))
    logical_pins = {x['logical_pin'] for x in pins}
    prior_pins = {re.search(r'\(pin (.*?)\)', x['detail'])[1] for x in old if x['rule'] == 'PDCN-1569'}
    assert logical_pins == prior_pins
    for rule in ['NTCN-8', 'REQP-1858']:
        assert {x['detail'] for x in rows if x['rule'] == rule} == {x['detail'] for x in old if x['rule'] == rule}
    assert all('design_1_i/xdma_0/' in x['detail'] for x in rows if x['rule'] in ['NTCN-8', 'REQP-1858'])
    assert all(x['cell'].startswith(('dbg_hub/', 'design_1_i/axi_dwidth_converter_0/')) for x in pins)
    with zipfile.ZipFile(E/'final.dcp') as z:
        xdc = z.read('design_1_wrapper_early.xdc').decode()
    assignments = [dict(line=i + 1, text=line) for i, line in enumerate(xdc.splitlines()) if line.startswith('set_property CLOCK_DELAY_GROUP')]
    assert len(assignments) == 18
    assert sum('/phy_clk_i/CLK_CORECLK]' in x['text'] or '/phy_clk_i/CLK_USERCLK]' in x['text'] for x in assignments) == 2
    result = dict(
        schema='ec-svb-r5-E-saved-warning-review/1',
        utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source='Saved r5 E fully routed checkpoint and reports; no live design mutation or FPGA access',
        errors=sum(x['severity'] == 'Error' for x in rows),
        critical_warnings=sum(x['severity'] == 'Critical Warning' for x in rows),
        warnings=sum(x['severity'] == 'Warning' for x in rows),
        counts=dict(counts),
        drc_rows=rows,
        pdcn_input_audit=pins,
        same_pdcn_logical_pin_set_as_r4=True,
        ntcn_and_reqp_details_identical_to_r4=True,
        checkpoint_early_xdc_clock_delay_group_assignments=assignments,
        review={
            'NTCN-8': 'All 16 GT leaf assignments are present in the sealed scoped input XDC, alongside the two CORECLK/USERCLK group assignments. The warning refers to the upstream GT segments. Preserve all assignments and require complete clock coverage and actual setup/hold STA; no constraint removal or waiver.',
            'PDCN-1569': 'All 10 warnings concern the same logical input set as r4, in debug hub or vendor AXI FIFO IP. Every warned physical input is absent from the printed Boolean equation. Physical pin/equation ordering differs after implementation. No INIT or connectivity edit.',
            'REQP-1858': 'The 22 advisory details exactly match r4 and refer only to vendor PCIe BRAM. Collision freedom inside vendor PCIe IP is not proven by this report. Preserve WRITE_FIRST mode; retain end-to-end PCIe/MMIO and replay checks after certified deployment.',
            'RTSTAT-10': 'Both reports declare 246 nets without routable loads. Each prints only the first 15 of 204 entries, so equality of all omitted objects cannot be inferred. This differs from an unrouted sink; final report_route_status and zero routing-error gate remain required.',
        },
        final_r6_drc_required=True,
        timing_certification_granted=False,
        warning_severity_or_constraints_changed=False,
        complete_opt4=False,
        fpga_access=False,
        inputs={str(p): sha(p) for p in [E/'drc-final.rpt', R4/'drc-final.rpt', E/'final.dcp', E/'final-timing.rpt', E/'route-final.rpt']},
    )
    (O/'drc-review.json').write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
    print(json.dumps({k: result[k] for k in ['errors', 'critical_warnings', 'warnings', 'counts', 'final_r6_drc_required']}))


if __name__ == '__main__':
    main()
