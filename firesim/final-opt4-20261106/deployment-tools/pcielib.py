import subprocess
import sys
import re
from pathlib import Path

from typing import Dict, List

pciDevicesPath = Path('/sys/bus/pci/devices')
SAFE_BUS_ID = '21'
SAFE_BDF = '0000:21:00.0'
SAFE_BRIDGE = '0000:20:03.1'
SAFE_BRIDGE_PATH = Path('/sys/devices/pci0000:20') / SAFE_BRIDGE

def require_safe_bus_id(bus_id: str) -> None:
    if bus_id != SAFE_BUS_ID:
        sys.exit(f":ERROR: Hardware operation blocked for PCI bus {bus_id}; this campaign is pinned to 0000:21:00.0")

def get_device_paths(bus_id: str) -> List[Path]:
    require_safe_bus_id(bus_id)
    endpoint = pciDevicesPath / SAFE_BDF
    if not endpoint.exists():
        return []
    if endpoint.resolve().parent != SAFE_BRIDGE_PATH:
        sys.exit(':ERROR: Target FPGA upstream bridge changed; no hardware operation allowed')
    if (endpoint / 'vendor').read_text().strip() != '0x10ee' or (endpoint / 'device').read_text().strip() != '0x903f':
        sys.exit(':ERROR: Target FPGA PCI identity changed')
    return [endpoint]

def get_device_extended_bdfs(bus_id: str) -> List[str]:
    return [e.name for e in get_device_paths(bus_id)]

def get_singular_device_path(bus_id: str) -> Path:
    devicePaths = get_device_paths(bus_id)
    if len(devicePaths) == 0:
        sys.exit(f":ERROR: Unable to obtain Extended Device BDF path for {bus_id}")
    if len(devicePaths) != 1:
        sys.exit(f":ERROR: Unable to obtain Extended Device BDF path for {bus_id} since too many Extended Device BDFs match: {devicePaths}")
    return devicePaths[0]

def get_singular_device_extended_bdf(bus_id: str) -> str:
    deviceBDFs = get_device_extended_bdfs(bus_id)
    if len(deviceBDFs) == 0:
        sys.exit(f":ERROR: Unable to obtain Extended Device BDF for {bus_id}")
    if len(deviceBDFs) != 1:
        sys.exit(f":ERROR: Unable to obtain Extended Device BDF for {bus_id} since too many Extended Device BDFs match: {deviceBDFs}")
    return deviceBDFs[0]

# obtain bridge paths/bdfs

def get_bridge_paths(bus_id: str) -> List[Path]:
    require_safe_bus_id(bus_id)
    # The endpoint disappears during reprogramming; the known upstream bridge
    # remains. Never fall back to a host-wide PCI rescan.
    if not SAFE_BRIDGE_PATH.is_dir():
        sys.exit(':ERROR: Expected isolated 21 upstream bridge is absent')
    children = [p.name for p in SAFE_BRIDGE_PATH.iterdir()
                if re.fullmatch(r'[0-9a-f]{4}:[0-9a-f]{2}:[0-9a-f]{2}\.[0-7]', p.name)]
    if any(name != SAFE_BDF for name in children):
        sys.exit(f':ERROR: Unexpected device shares target bridge: {children}')
    get_device_paths(bus_id)
    return [SAFE_BRIDGE_PATH]

def get_bridge_extended_bdfs(bus_id: str) -> List[str]:
    return [e.name for e in get_bridge_paths(bus_id)]

def get_singular_bridge_path(bus_id: str) -> Path:
    bridgePaths = get_bridge_paths(bus_id)
    if len(bridgePaths) == 0:
        sys.exit(f":ERROR: Unable to obtain Extended Bridge BDF path for {bus_id}")
    if len(bridgePaths) != 1:
        sys.exit(f":ERROR: Unable to obtain Extended Bridge BDF path for {bus_id} since too many Extended Bridge BDFs match: {bridgePaths}")
    return bridgePaths[0]

def get_singular_bridge_extended_bdf(bus_id: str) -> str:
    bridgeBDFs = get_bridge_extended_bdfs(bus_id)
    if len(bridgeBDFs) == 0:
        sys.exit(f":ERROR: Unable to obtain Extended Bridge BDF for {bus_id}")
    if len(bridgeBDFs) != 1:
        sys.exit(f":ERROR: Unable to obtain Extended Bridge BDF for {bus_id} since too many Extended Bridge BDFs match: {bridgeBDFs}")
    return bridgeBDFs[0]

# misc

def get_fpga_devs(bus_id) -> List[Path]:
    def readUevent(path: Path) -> Dict[str, str]:
        if not (path / 'uevent').exists():
            return {}
        return { entry[0]: entry[1] for entry in [line.strip('\n\r ').split('=') for line in open(f'{path}/uevent', 'r').readlines()] if len(entry) >= 2 }

    def xdmaResolver(path: Path) -> List[Path]:
        xdmaDevs = []
        for f in ['resource', 'resource0', 'resource1']:
            rsrcPath = (path / f)
            if rsrcPath.exists():
                xdmaDevs.append(rsrcPath)
        xdmaPath = (path / 'xdma')
        if xdmaPath.is_dir():
            ueventEntries = [readUevent(xdmaPath / entry.name) for entry in xdmaPath.iterdir() if (xdmaPath / entry.name).is_dir()]
            xdmaDevs.extend([Path('/dev') / uevent['DEVNAME'] for uevent in ueventEntries if 'DEVNAME' in uevent and (Path('/dev') / uevent['DEVNAME']).exists()])
        return xdmaDevs

    resolvers = {
        'xdma' : xdmaResolver
    }

    returnDevs = []
    fpgaDevices = get_device_extended_bdfs(bus_id)
    for fpgaDev in fpgaDevices:
        path = pciDevicesPath / fpgaDev
        fpgaDevUevent = readUevent(path)
        if 'DRIVER' not in fpgaDevUevent:
            print(":WARNING: Verify that 'xdma' driver is loaded")
            continue
        if fpgaDevUevent['DRIVER'] not in resolvers:
            continue
        returnDevs.extend(resolvers[fpgaDevUevent['DRIVER']](path.resolve()))

    return returnDevs

# clear SERR bit in command register
# https://support.xilinx.com/s/question/0D52E00006hpjPHSAY/dell-r720-poweredge-server-reboots-on-fpga-reprogramming?language=en_US
def clear_serr_bits(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    for bridgeBDF in get_bridge_extended_bdfs(bus_id):
        run = subprocess.run(['setpci', '-s', bridgeBDF, 'COMMAND=0000:0100'])
        if run.returncode != 0:
            sys.exit(f":ERROR: Unable to clear SERR bit for {bridgeBDF}")

# clear fatal error reporting enable bit in the device control register
# https://support.xilinx.com/s/question/0D52E00006hpjPHSAY/dell-r720-poweredge-server-reboots-on-fpga-reprogramming?language=en_US
def clear_fatal_error_reporting_bits(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    for bridgeBDF in get_bridge_extended_bdfs(bus_id):
        run = subprocess.run(['setpci', '-s', bridgeBDF, 'CAP_EXP+8.w=0000:0004'])
        if run.returncode != 0:
            sys.exit(f":ERROR: Unable to clear error reporting bit for {bridgeBDF}")

def write_to_linux_device_path(path: Path, data: str = '1\n') -> None:
    allowed = {
        str(SAFE_BRIDGE_PATH / 'rescan'): {'1\n'},
        str(SAFE_BRIDGE_PATH / SAFE_BDF / 'remove'): {'1\n'},
        '/sys/bus/pci/drivers/xdma/unbind': {SAFE_BDF},
        '/sys/bus/pci/drivers/xdma/bind': {SAFE_BDF},
    }
    if str(path) not in allowed or data not in allowed[str(path)]:
        sys.exit(f':ERROR: Refusing non-target sysfs write: {path}')
    try:
        print(f":INFO: Writing to {path}: {data.strip()}")
        open(path, 'w').write(data)
    except:
        sys.exit(f":ERROR: Cannot write to {path} value: {data}")

def remove(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    for devicePaths in get_device_paths(bus_id):
        removePath = devicePaths.resolve().absolute() / 'remove'
        if removePath.exists():
            write_to_linux_device_path(removePath)

def rescan(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    bridgePaths = get_bridge_paths(bus_id)
    if not bridgePaths:
        sys.exit(f":ERROR: Unable to find upstream bridge for PCI bus {bus_id}")
    for bridgePath in bridgePaths:
        rescanPath = bridgePath / 'rescan'
        if not rescanPath.exists():
            sys.exit(f":ERROR: No targeted upstream-bridge rescan interface at {rescanPath}")
        write_to_linux_device_path(rescanPath)

def unbind_xdma(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    unbindPath = Path('/sys/bus/pci/drivers/xdma/unbind')
    for devicePath in get_device_paths(bus_id):
        driverPath = devicePath / 'driver'
        if driverPath.exists() and driverPath.resolve().name == 'xdma':
            write_to_linux_device_path(unbindPath, devicePath.name)

def bind_xdma(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    bindPath = Path('/sys/bus/pci/drivers/xdma/bind')
    devices = get_device_paths(bus_id)
    if not devices:
        sys.exit(f":ERROR: FPGA endpoint for PCI bus {bus_id} did not return after targeted rescan")
    for devicePath in devices:
        driverPath = devicePath / 'driver'
        if not driverPath.exists():
            write_to_linux_device_path(bindPath, devicePath.name)
        if not driverPath.exists() or driverPath.resolve().name != 'xdma':
            sys.exit(f":ERROR: XDMA did not bind to target {devicePath.name}")

# enable memory mapped transfers for the fpga
# https://support.xilinx.com/s/question/0D52E00006iHlNoSAK/lspci-reports-bar-0-disabled?language=en_US
def enable_memmapped_transfers(bus_id: str) -> None:
    require_safe_bus_id(bus_id)
    for deviceBDF in get_device_extended_bdfs(bus_id):
        run = subprocess.run(['setpci', '-s', deviceBDF, 'COMMAND=0x02'])
        if run.returncode != 0:
            sys.exit(f":ERROR: Unable to enable memmapped transfers on {deviceBDF}")

def any_device_exists(bus_id: str) -> bool:
    return len(get_device_paths(bus_id)) > 0

# converter funcs

def get_extended_bdf_from_bdf(bdf: str) -> str:
    return '0000:' + bdf

def get_bus_id_from_extended_bdf(extended_bdf: str) -> str:
    return extended_bdf[5:7]

def get_bdf_from_extended_bdf(extended_bdf: str) -> str:
    return extended_bdf[5:]
