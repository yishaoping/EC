#!/usr/bin/env python3

import argparse
import os
import subprocess
import sys
import shutil
import json
from pathlib import Path
import pcielib
import util
import firesim

from typing import Dict, Any, List

scriptPath = Path(__file__).resolve().parent
SAFE_BUS_ID = '21'
SAFE_BDF = '0000:21:00.0'
SAFE_SERIAL = 'Xilinx/21770433G02LA'

def program_fpga(vivado: Path, serial: str, bitstream: str) -> None:
    if serial != SAFE_SERIAL:
        sys.exit(f':ERROR: Refusing JTAG target {serial}')
    progTcl = scriptPath / 'program_fpga.tcl'
    assert progTcl.exists(), f"Unable to find {progTcl}"
    rc, stdout, stderr = util.call_vivado(
        vivado,
        [
            '-source', str(progTcl),
            '-tclargs',
                '-serial', serial,
                '-bitstream_path', bitstream,
        ]
    )
    log_name = Path.cwd() / ('program-' + serial.replace('/', '_') + '.log')
    log_name.write_text(stdout + '\n' + stderr)
    if rc != 0 or f'EC_FPGA_PROGRAMMED serial={serial} file={bitstream}' not in stdout:
        sys.exit(f":ERROR: Unable to flash FPGA {serial} with {bitstream}.\nstdout:\n{stdout}\nstderr:\n{stderr}")
    print(f":INFO: Verified Vivado program completion; transcript: {log_name}")

# mapping functions

def get_fpga_db() -> Dict[Any, Any]:
    if firesim.dbPath.exists():
        with open(firesim.dbPath, 'r') as f:
            return json.load(f)
    else:
        print(f":ERROR: Unable to open {firesim.dbPath}. Does it exist? Did you run 'firesim enumeratefpgas'?", file=sys.stderr)
    sys.exit(f":ERROR: Unable to create FPGA database from {firesim.dbPath}")

def get_serial_from_bus_id(id: str) -> str:
    if id != SAFE_BUS_ID:
        sys.exit(f":ERROR: Refusing FPGA access on PCI bus {id}; allowed target is {SAFE_BDF}")
    deviceBDF = pcielib.get_bdf_from_extended_bdf(pcielib.get_singular_device_extended_bdf(id))
    for e in get_fpga_db():
        if deviceBDF == e['bdf'] and e['uid'] == SAFE_SERIAL:
            return e['uid']
    sys.exit(":ERROR: Unable to get serial number from bus id")

def get_serials() -> List[str]:
    return [SAFE_SERIAL]

def get_extended_bdfs() -> List[str]:
    return [SAFE_BDF]

# main

def main(args: List[str]) -> int:
    parser = argparse.ArgumentParser(description="Program/manipulate a Xilinx XDMA-enabled FPGA device")
    megroup = parser.add_mutually_exclusive_group(required=True)
    megroup.add_argument("--bus_id", help="Bus number of FPGA (i.e. ****:<THIS>:**.*)")
    megroup.add_argument("--bdf", help="BDF of FPGA (i.e. ****:<THIS>)")
    megroup.add_argument("--extended-bdf", help="Extended BDF of FPGA (i.e. all of this - ****:**:**.*)")
    megroup.add_argument("--serial", help="Serial number of FPGA (i.e. what 'get_hw_target' shows in Vivado)")
    megroup.add_argument("--all-serials", help="Use all serial numbers (no PCI-E manipulation)", action="store_true")
    megroup.add_argument("--all-bdfs", help="Use all BDFs (PCI-E manipulation)", action="store_true")
    parser.add_argument("--vivado-bin", help="Explicit path to 'vivado'", type=Path)
    parser.add_argument("--hw-server-bin", help="Explicit path to 'hw_server'", type=Path)
    megroup2 = parser.add_mutually_exclusive_group(required=True)
    megroup2.add_argument("--bitstream", help="The bitstream to flash onto FPGA(s)", type=Path)
    megroup2.add_argument("--disconnect-bdf", help="Disconnect BDF(s)", action="store_true")
    megroup2.add_argument("--reconnect-bdf", help="Reconnect BDF(s)", action="store_true")
    parsed_args = parser.parse_args(args)

    if parsed_args.bdf and parsed_args.bdf != '21:00.0':
        parser.error('only exact BDF 21:00.0 is allowed')
    if parsed_args.extended_bdf and parsed_args.extended_bdf != SAFE_BDF:
        parser.error('only exact BDF 0000:21:00.0 is allowed')
    if parsed_args.serial:
        parser.error('serial-only programming is disabled; use --extended-bdf 0000:21:00.0 for checked PCI/JTAG mapping')
    requested_bus_ids = []
    if parsed_args.bus_id:
        requested_bus_ids.append(parsed_args.bus_id)
    if parsed_args.bdf:
        requested_bus_ids.append(pcielib.get_bus_id_from_extended_bdf(
            pcielib.get_extended_bdf_from_bdf(parsed_args.bdf)))
    if parsed_args.extended_bdf:
        requested_bus_ids.append(pcielib.get_bus_id_from_extended_bdf(parsed_args.extended_bdf))
    if any(bus_id != SAFE_BUS_ID for bus_id in requested_bus_ids):
        sys.exit(f":ERROR: Refusing PCI targets {requested_bus_ids}; only {SAFE_BDF} is allowed")
    if parsed_args.all_bdfs or parsed_args.all_serials:
        sys.exit(":ERROR: --all-bdfs and --all-serials are disabled for this single-card campaign")
    if parsed_args.serial and parsed_args.serial != SAFE_SERIAL:
        sys.exit(f":ERROR: Refusing JTAG serial {parsed_args.serial}; only {SAFE_SERIAL} is allowed")

    if parsed_args.hw_server_bin is None:
        parsed_args.hw_server_bin = shutil.which('hw_server')
    if parsed_args.vivado_bin is None:
        parsed_args.vivado_bin = shutil.which('vivado')
    if parsed_args.vivado_bin is None:
        parsed_args.vivado_bin = shutil.which('vivado_lab')

    if parsed_args.hw_server_bin is None:
        print(':ERROR: Could not find Xilinx Hardware Server!', file=sys.stderr)
        exit(1)
    if parsed_args.vivado_bin is None:
        print(':ERROR: Could not find Xilinx Vivado (or Vivado Lab)!', file=sys.stderr)
        exit(1)

    parsed_args.vivado_bin = Path(parsed_args.vivado_bin).absolute()
    parsed_args.hw_server_bin = Path(parsed_args.hw_server_bin).absolute()

    eUserId = os.geteuid()
    sudoUserId = os.getenv('SUDO_UID')
    isAdmin = (eUserId == 0) and (sudoUserId is None)
    userId = eUserId if sudoUserId is None else int(sudoUserId)

    # if not sudoer, spawn w/ sudo
    if eUserId != 0:
        execvArgs  = ['/usr/bin/sudo', str(Path(__file__).absolute())] + sys.argv[1:]
        execvArgs += ['--vivado-bin', str(parsed_args.vivado_bin), '--hw-server-bin', str(parsed_args.hw_server_bin)]
        print(f":INFO: Running: {execvArgs}")
        os.execv(execvArgs[0], execvArgs)

    def is_bdf_arg(parsed_args) -> bool:
        return parsed_args.bus_id or parsed_args.bdf or parsed_args.extended_bdf or parsed_args.all_bdfs

    def get_bus_ids_from_args(parsed_args) -> List[str]:
        bus_ids = []
        if parsed_args.bus_id:
            bus_ids.append(parsed_args.bus_id)
        if parsed_args.bdf:
            bus_ids.append(pcielib.get_bus_id_from_extended_bdf(pcielib.get_extended_bdf_from_bdf(parsed_args.bdf)))
        if parsed_args.extended_bdf:
            bus_ids.append(pcielib.get_bus_id_from_extended_bdf(parsed_args.extended_bdf))
        if parsed_args.all_bdfs:
            bus_ids.extend([pcielib.get_bus_id_from_extended_bdf(bdf) for bdf in get_extended_bdfs()])
        return bus_ids

    def disconnect_bus_id(bus_id: str) -> None:
        pcielib.require_safe_bus_id(bus_id)
        pcielib.clear_serr_bits(bus_id)
        pcielib.clear_fatal_error_reporting_bits(bus_id)
        pcielib.unbind_xdma(bus_id)
        pcielib.remove(bus_id)
        assert not pcielib.any_device_exists(bus_id), f"{bus_id} still visible. Check for proper removal."

    def reconnect_bus_id(bus_id: str) -> None:
        pcielib.rescan(bus_id)
        pcielib.bind_xdma(bus_id)
        pcielib.enable_memmapped_transfers(bus_id)
        assert pcielib.any_device_exists(bus_id), f"{bus_id} not visible. Check for proper rescan."

    # program based on bitstream
    if parsed_args.bitstream is not None:
        if not parsed_args.bitstream.is_file() or not parsed_args.bitstream.exists():
            sys.exit(f":ERROR: Invalid bitstream: {parsed_args.bitstream}")
        else:
            parsed_args.bitstream = parsed_args.bitstream.absolute()

        if is_bdf_arg(parsed_args):
            bus_ids = get_bus_ids_from_args(parsed_args)

            # must be called before the remove otherwise it will not find a serial number
            serialNums = []
            for bus_id in bus_ids:
                serialNums.append(get_serial_from_bus_id(bus_id))

            for bus_id in bus_ids:
                disconnect_bus_id(bus_id)

            # program fpga(s) separately if doing multiple bdfs
            try:
                for i, bus_id in enumerate(bus_ids):
                    serialNumber = serialNums[i]
                    program_fpga(parsed_args.vivado_bin, serialNumber, parsed_args.bitstream)
                    print(f":INFO: Successfully programmed FPGA {bus_id} with {parsed_args.bitstream}")
            finally:
                # Restore visibility even when Vivado cannot find/program JTAG.
                for bus_id in bus_ids:
                    reconnect_bus_id(bus_id)

        if parsed_args.serial or parsed_args.all_serials:
            serials = []
            if parsed_args.serial:
                serials.append(parsed_args.serial)
            if parsed_args.all_serials:
                serials.extend(get_serials())

            for serial in serials:
                program_fpga(parsed_args.vivado_bin, serial, parsed_args.bitstream)
                print(f":INFO: Successfully programmed FPGA {serial} with {parsed_args.bitstream}")
            print(":WARNING: Please warm reboot the machine")

    # disconnect bdfs
    if parsed_args.disconnect_bdf:
        if is_bdf_arg(parsed_args):
            bus_ids = get_bus_ids_from_args(parsed_args)
            for bus_id in bus_ids:
                disconnect_bus_id(bus_id)
        else:
            sys.exit("Must provide a BDF-like argument to disconnect")

    # reconnect bdfs
    if parsed_args.reconnect_bdf:
        if is_bdf_arg(parsed_args):
            bus_ids = get_bus_ids_from_args(parsed_args)
            for bus_id in bus_ids:
                reconnect_bus_id(bus_id)
        else:
            sys.exit("Must provide a BDF-like argument to disconnect")

    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
