"""Independent original-SVB host40 certificate; never admits full Opt4/PARSEC."""
from pathlib import Path
import re


def certify(r):
    m=r.m;C=Path(__file__).resolve().parent;L=r.L;CAD=r.SPREAD
    cfg,b,d=r.verify_inputs()
    pins=m.read(C/'runtime-inputs.json')
    for path,h in pins['files'].items():assert m.sha(path)==h,('host40 runtime input changed',path)
    s=m.read(CAD/'result.json')
    assert s['status']=='HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION'
    assert s['profile']==r.PROFILE and s['functional_baseline']==m.BASE and s['source_id']==r.SID
    assert not s['target_rtl_changed'] and s['host_clock_changed'] and not s['complete_opt4'] and not s['fpga_access']
    assert s['mmcm_clkout0_divide_f']==30.0 and abs(s['host_clock_period_ns']-24.9975)<0.002
    assert s['input_manifest_sha256']==m.sha(C/'inputs.json')
    assert m.read(CAD/'complete.json')['result_sha256']==m.sha(CAD/'result.json')
    assert all(m.sha(p)==h for p,h in s['outputs'].items())
    bound=m.read(CAD/'sealed-inputs.json')
    assert s['sealed_inputs_sha256']==m.sha(CAD/'sealed-inputs.json')
    assert bound['profile']==r.PROFILE and bound['source_id']==r.SID and not bound['target_rtl_changed']
    assert m.sha(bound['sealed_checkpoint'])==bound['sealed_checkpoint_sha256']
    assert m.sha(bound['probe_result'])==bound['probe_result_sha256']
    assert m.read(bound['probe_result'])['status']=='COMPLETE_DIAGNOSTIC_NOT_CERTIFIED'
    routed=CAD/'final.dcp';bit=Path(s['bitstream'])
    assert m.sha(routed)==s['outputs'][str(routed)]
    assert m.sha(bit)==s['bitstream_sha256']==s['outputs'][str(bit)]
    assert 'EC_SVB_HOST40_BITSTREAM_COMPLETE' in (CAD/'recovery.log').read_text(errors='replace')
    contract=m.read(C/'physical-clock-contract.json')
    audit=L/'clock-audit.complete.json'
    if not audit.exists():
        tcl=L/'clock-audit.tcl'
        code=(C/'audit.tcl.in').read_text().replace('@CHECKPOINT@',str(routed)).replace('@OUT@',str(L))
        clocks=' '.join('{'+name+'} '+str(period) for name,period in contract['periods_ns'].items())
        code=code.replace('@CLOCKS@',clocks)
        if tcl.exists():assert tcl.read_text()==code
        else:tcl.write_text(code)
        log=L/'clock-audit.log';assert not log.exists(),'partial audit requires versioned recovery'
        r.update(status='AUDITING_HOST40_ROUTED_COMPONENT_NO_FPGA_IO')
        r.bb.command(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(L/'clock-audit.vivado.log'),'-source',str(tcl)],L,log,timeout=3600)
        text=log.read_text(errors='replace');assert 'EC_SVB_HOST40_INDEPENDENT_AUDIT_PASS' in text
        timing=(L/'check-timing.rpt').read_text()
        assert re.search(r'checking no_clock \(0\)',timing)
        assert re.search(r'checking unconstrained_internal_endpoints \(0\)',timing)
        r.bb.save(audit,dict(profile=r.PROFILE,routed_checkpoint=str(routed),routed_sha256=m.sha(routed),
           log_sha256=m.sha(log),physical_clock_contract_sha256=m.sha(C/'physical-clock-contract.json'),
           mmcm_clkout0_divide_f=30.0,host_clock_period_ns=24.9975,target_cycle_definition_changed=False,
           bus_skew_sha256=m.sha(L/'bus-skew.rpt'),pulse_width_sha256=m.sha(L/'pulse-width.rpt')))
    else:
        a=m.read(audit)
        assert a['profile']==r.PROFILE and m.sha(a['routed_checkpoint'])==a['routed_sha256'] and m.sha(L/'clock-audit.log')==a['log_sha256']
    cert=dict(schema='ec-original-component-host40-certificate/1',status='CERTIFIED_ORIGINAL_SVB_COMPONENT_HOST40_NOT_FULL_OPT4',
       functional_baseline=m.BASE,profile=r.PROFILE,source_id=r.SID,complete_opt4=False,formal_parsec_admission=False,
       target_rtl_changed=False,target_cycle_definition_changed=False,bridge_ratios_changed=False,
       physical_host_clock_period_ns=24.9975,physical_host_clock_frequency_hz=1e9/24.9975,
       target_frequency_hz=None,target_time_note='Target-cycle events only; physical host period must not be used as architectural target frequency.',
       bitstream=str(bit),bitstream_sha256=m.sha(bit),cad_result=str(CAD/'result.json'),cad_result_sha256=m.sha(CAD/'result.json'),
       reused_driver=d,driver=d,driver_reuse_reason='Identical MMIO/bridge ABI, DONE/token polling, no physical-frequency constant; actual board trace still required.',
       cycle_proof_sha256=m.sha(r.PROOF/'result.json'),binding_sha256=m.sha(r.PREP/'binding.json'),
       target_trace='synthetic directed original component; not application payload replay',board_bdf=r.bb.TARGET_BDF,
       board_serial=r.bb.TARGET_SERIAL,clock_audit_sha256=m.sha(audit),host_clock_adaptation_only=True,created_utc=m.now())
    r.bb.save(L/'certified-component.json',cert);return cert
