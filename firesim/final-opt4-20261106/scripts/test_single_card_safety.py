#!/usr/bin/env python3
"""No FPGA writes: exercise rejection, removed-endpoint rescan, and JTAG scope."""
import ast
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
from types import SimpleNamespace

W = Path(__file__).resolve().parents[1]
TOOLS = [Path('/data1/gzh/EC/firesim/upstream/platforms/xilinx_alveo_u250/scripts'), W/'deployment-tools'] + [W/c/'chipyard/sims/firesim/platforms/xilinx_alveo_u250/scripts'
                                  for c in ['Native', 'C4']]


def reject(argv, text):
    p = subprocess.run(argv, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    assert p.returncode != 0 and text in p.stdout, (argv, p.returncode, p.stdout)


def main():
    checks = []
    for tools in TOOLS:
        for args in [['--extended-bdf','0000:e2:00.0'], ['--bdf','e2:00.0'],
                     ['--extended-bdf','0000:21:00.1'], ['--extended-bdf','1234:21:00.0'],
                     ['--bus_id','e2'], ['--all-bdfs'], ['--all-serials'],
                     ['--serial','Xilinx/21770433G001A'], ['--serial','Xilinx/21770433G02LA']]:
            reject([sys.executable, str(tools/'fpga-util.py'), *args, '--disconnect-bdf'],
                   'ERROR' if args[0] in ['--bus_id','--all-bdfs','--all-serials'] else 'error')
            checks.append([str(tools), args])
        spec = importlib.util.spec_from_file_location('tested_pcielib', tools/'pcielib.py')
        pci = importlib.util.module_from_spec(spec); spec.loader.exec_module(pci)
        for fn in ['get_device_paths','get_bridge_paths','clear_serr_bits',
                   'clear_fatal_error_reporting_bits','remove','rescan','unbind_xdma',
                   'bind_xdma','enable_memmapped_transfers']:
            try:
                getattr(pci, fn)('e2')
            except SystemExit:
                pass
            else:
                raise AssertionError('e2 reached hardware operation: '+fn)
        for path, value in [(Path('/sys/bus/pci/rescan'),'1\n'),
                            (Path('/sys/bus/pci/drivers/xdma/unbind'),'0000:e2:00.0')]:
            try:
                pci.write_to_linux_device_path(path, value)
            except SystemExit:
                pass
            else:
                raise AssertionError('unsafe write accepted')
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp); bridge=root/'devices/pci0000:20/0000:20:03.1'
            bridge.mkdir(parents=True); (bridge/'rescan').write_text('untouched')
            pci.pciDevicesPath=root/'bus/pci/devices';pci.pciDevicesPath.mkdir(parents=True)
            pci.SAFE_BRIDGE_PATH=bridge
            endpoint=bridge/pci.SAFE_BDF;endpoint.mkdir()
            (endpoint/'vendor').write_text('0x10ee');(endpoint/'device').write_text('0x903f')
            (endpoint/'remove').write_text('untouched')
            (pci.pciDevicesPath/pci.SAFE_BDF).symlink_to(endpoint)
            assert pci.get_bridge_paths('21')==[bridge]
            writes=[];pci.write_to_linux_device_path=lambda path, data='1\n':writes.append((path,data))
            pci.remove('21')
            for child in endpoint.iterdir():child.unlink()
            endpoint.rmdir()
            pci.rescan('21')
            assert writes==[(endpoint/'remove','1\n'),(bridge/'rescan','1\n')],writes
            sibling=bridge/'0000:21:01.0';sibling.mkdir()
            try:pci.rescan('21')
            except SystemExit:pass
            else:raise AssertionError('shared bridge accepted')
        reject(['tclsh', str(tools/'program_fpga.tcl'), '-serial', 'Xilinx/21770433G001A'],
               'EC_FATAL_21_ONLY')
        # Exercise the real Tcl with mocked Vivado commands and two JTAG cards.
        stub = '''
set argv [list -serial Xilinx/21770433G02LA -bitstream_path fixture.bit]
set argc [llength $argv]
proc set_param {args} {}
proc open_hw_manager {} {}
proc close_hw_manager {} {}
proc connect_hw_server {args} {}
proc current_hw_target {args} {return ""}
proc close_hw_target {} {}
proc get_hw_targets {args} {
    if {[llength $args]} {return [lindex $args 0]}
    return {localhost:3122/xilinx_tcf/Xilinx/21770433G001A localhost:3122/xilinx_tcf/Xilinx/21770433G02LA}
}
proc open_hw_target {target} {
    if {[file tail $target] ne "21770433G02LA"} {error "protected e2 was opened"}
}
proc get_hw_devices {args} {
    if {[llength $args] != 0} {error "unexpected device selector"}
    return target21device
}
proc current_hw_device {device} {}
proc set_property {key value device} {if {$device ne "target21device"} {error "wrong device"}}
proc program_hw_devices {device} {if {$device ne "target21device"} {error "wrong device"}}
proc refresh_hw_device {device} {if {$device ne "target21device"} {error "wrong device"}}
source [lindex $::env(EC_TEST_TCL_PATH)]
'''
        import os
        p=subprocess.run(['tclsh'],input=stub,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,
                         env={**os.environ,'EC_TEST_TCL_PATH':str(tools/'program_fpga.tcl')})
        assert p.returncode==0 and 'EC_FPGA_PROGRAMMED serial=Xilinx/21770433G02LA' in p.stdout,p.stdout
    for entry,args in [('board_batch.py',['--pair']),('board_batch.py',['--single-native-bdf','0000:e2:00.0']),
                       ('run_isolated_sample.py',['Native','smoke','test','--bdf','0000:e2:00.0']),
                       ('infrasetup.py',['Native','--bdf','0000:e2:00.0'])]:
        reject([sys.executable,str(W/'scripts'/entry),*args],'error')
    manager=Path('/data1/gzh/EC/firesim/upstream/deploy/runtools/run_farm_deploy_managers.py')
    tree=ast.parse(manager.read_text())
    cls=next(n for n in tree.body if isinstance(n,ast.ClassDef) and n.name=='XilinxAlveoInstanceDeployManager')
    for method in cls.body:
        if isinstance(method,ast.FunctionDef) and method.name in ['load_xdma','unload_xdma','flash_fpgas',
                'infrasetup_instance','create_fpga_database','enumerate_fpgas','start_sim_slot']:
            module=ast.Module(body=[ast.ImportFrom(module='__future__',names=[ast.alias(name='annotations')],level=0),method],type_ignores=[])
            ast.fix_missing_locations(module);scope={};exec(compile(module,str(manager),'exec'),scope)
            args=[SimpleNamespace(parent_node=SimpleNamespace(metasimulation_enabled=False))]
            if len(method.args.args)>1:args.append('unused')
            try:scope[method.name](*args)
            except RuntimeError as exc:assert 'disabled' in str(exc)
            else:raise AssertionError('Manager hardware path not blocked: '+method.name)
    print(json.dumps(dict(status='PASS',tool_copies=len(TOOLS),negative_cli_cases=len(checks)+4,
                          removed_endpoint_rescan='PASS',jtag_scope='PASS',manager_guards='PASS',
                          real_hardware_writes=0)))


if __name__=='__main__':main()
