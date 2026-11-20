from pathlib import Path
import sys,json,fcntl
import resource_parser as m
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');A=D/'status-audits/full-ec-structural-priority-20261112/round164-mixed-stats-host'
S=read(D/'Opt4-fit-field-address-cad-state.json');BASE='8491167d84b6d9521b151a743673c1516926a1f8'
assert S['status']=='NOT_FIT_POSTOPT' and S['hardware_commit']=='8d50489af3af9e4c766509284ba3d9d7c99cfec9' and S['frozen_parent_commit']==BASE
P=Path(S['log_dir']);U=P/'top-postopt-utilization.rpt';H=P/'top-postopt-hierarchical.rpt';L=P/'implementation-attempt-1.log';T=P/'implementation-bound.tcl'
assert 'EC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX' in L.read_text() and 'NOT FIT; saved optimized checkpoint' in L.read_text()
assert 'Design State : Optimized' in U.read_text()
TOTAL=m.parse_total(U.read_text());m.parse_hier(H.read_text(),TOTAL);CROSS=m.crosschecks(U.read_text(),TOTAL)
TESTS=m.test_parser(U.read_text(),H.read_text());save(A/'fullshell-parser-validation.json',TESTS)
assert CROSS['blackboxes']==0 and TOTAL['CLB LUTs']['used']==2478437
assert all(TOTAL[k]['used']==S['top_postopt_resources'][k]['used'] for k in TOTAL)
BIND=W/'Opt4-fit-field-address-compose-r1-20261111/bindings/8d50489af3af9e4c766509284ba3d9d7c99cfec9.json';B=read(BIND)
assert B['hardware_commit']==S['hardware_commit'] and B['source_id']==S['source_id'] and B['frozen_commit']==BASE
for path,h in S['inputs']['generated'].items():assert sha(path)==h,(path,'generated')
for r in S['inputs']['shell_checkpoints']:assert sha(r['path'])==r['sha256'],(r['path'],'shell_checkpoint')
RTL=Path(S['inputs']['rtl_receipt']);RS=read(RTL)
assert RS['hardware_commit']==S['hardware_commit'] and RS['source_id']==S['source_id']
SNAP=A/'fullshell-8d50489a-cad-state.json';save(SNAP,S)
SB=A/'fullshell-8d50489a-source-binding.json'
save(SB,dict(schema='ec-complete-shell-postopt-source-binding/1',functional_baseline=BASE,hardware_commit=S['hardware_commit'],source_id=S['source_id'],shell_included=True,
 original_source_binding=str(BIND),original_source_binding_sha256=sha(BIND),original_rtl_receipt=str(RTL),original_rtl_receipt_sha256=sha(RTL),
 exact_cad_snapshot=str(SNAP),exact_cad_snapshot_sha256=sha(SNAP),generated_files=S['inputs']['generated'],shell_checkpoints=S['inputs']['shell_checkpoints'],source_dut_imported=False,
 top='design_1_wrapper',part=S['part'],functional_baseline_source=B,implementation_tcl=str(T),implementation_tcl_sha256=sha(T),implementation_log=str(L),implementation_log_sha256=sha(L),
 parser=str(Path(m.__file__)),parser_sha256=sha(m.__file__),parser_change='Exact original strict parser; only required top identity changed from FPGATop to design_1_wrapper. Actual parser positive/negative tests retained.',
 validation_limits='Original component/generated storage/cycle validation only. No monolithic fullDUT equivalence, timing, bitstream, board deployment or3656 source composition inferred.'))
R=A/'fullshell-8d50489a-result.json'
save(R,dict(schema='ec-complete-u280-shell-postopt-adoption/1',scope='complete_u280_shell_postopt',functional_baseline=BASE,hardware_commit=S['hardware_commit'],source_id=S['source_id'],shell_included=True,blackboxes=0,
 resources={k:v['used'] for k,v in TOTAL.items()},capacity=1303680,lut_gap=2478437-1303680,status='NOT_FIT_POSTOPT',measurement_completed_utc=S['ended_utc'],adopted_utc=now(),
 utilization=str(U),utilization_sha256=sha(U),hierarchical=str(H),hierarchical_sha256=sha(H),source_binding=str(SB),source_binding_sha256=sha(SB),full_system_fit=False,certified_bitstream=False,placed_routed=False,
 no_FPGA_IO=True,formal_admission=False,full_dut_formal=False,
 provenance='Original root CAD finished before round164. Outer result.json absent because capacity veto exits before placement. Complete optimized shell utilization/hierarchy/zero-blackbox outputs are complete.',
 source_scope_rule='8d50489a complete shell only; never subtract this gain again from3656 or combine independent module measurements.'))
LEDGER=D/'area-sprint-20261112/fullshell-adoptions.json';lock=LEDGER.with_suffix('.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX)
X=read(LEDGER);X.setdefault('schema','ec-complete-shell-adoptions/1');entries=X.setdefault('results',[])
E=dict(scope='complete_u280_shell_postopt',result=str(R),result_sha256=sha(R),utilization=str(U),utilization_sha256=sha(U),source_binding=str(SB),source_binding_sha256=sha(SB),hardware_commit=S['hardware_commit'])
assert not any(y.get('hardware_commit')==E['hardware_commit'] for y in entries);entries.append(E);save(LEDGER,X)
print(json.dumps(dict(registered=str(R),LUT=2478437,gap=1174757,blackboxes=CROSS['blackboxes'],FIT=False)))
