#!/usr/bin/env python3
"""Freeze v4; create B-only v5 with a passive FireSim raw ROI bridge."""
import datetime
import json
from pathlib import Path
import shutil
import subprocess
from build_minimal import BASE, ROOT, inventory, sha
from prepare_roi_hardware import replace_once


def main():
    source = BASE/'opt4-roi-v4/B/chipyard'
    destination = BASE/'opt4-roi-v5/B/chipyard'
    if destination.exists():
        raise ValueError('refuse overwrite '+str(destination))
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    log = ROOT/'Experiment/dac2026/build-logs/opt4-roi-v5'/('prepare-B-'+stamp)
    log.mkdir(parents=True, exist_ok=False)
    before = inventory(source)
    destination.parent.mkdir(parents=True, exist_ok=True)
    command = ['cp', '-a', '--reflink=auto', str(source), str(destination)]
    subprocess.run(command, check=True)
    if inventory(source) != before or inventory(destination) != before:
        raise ValueError('copy content mismatch')
    hw = ROOT/'firesim/dac2026/measurement/hardware'
    sim = destination/'sims/firesim/sim'
    for src, dest in [(hw/'DacRoiBridge.scala', sim/'firesim-lib/src/main/scala/bridges/DacRoiBridge.scala'),
                      (hw/'ec_dac_roi.h', sim/'midas/src/main/cc/bridges/ec_dac_roi.h'),
                      (hw/'ec_dac_roi.cc', sim/'midas/src/main/cc/bridges/ec_dac_roi.cc')]:
        if dest.exists(): raise ValueError('refuse overwrite '+str(dest))
        shutil.copy2(src, dest)
    controller = destination/'generators/rocket-chip/src/main/scala/util/DacRoi.scala'
    replace_once(controller, '    val tick = Output(UInt(64.W))',
                 '    val tick = Output(UInt(64.W))\n    val observe = Output(Vec(6, UInt(64.W)))')
    replace_once(controller, '  val lastSerial = RegInit(0.U(56.W))',
                 '  io.observe := VecInit(Seq(epoch, state, tick, beginTick, endTick, faults))\n'
                 '  val lastSerial = RegInit(0.U(56.W))')
    core = destination/'generators/boom/src/main/scala/exu/core.scala'
    replace_once(core, '    BoringUtils.addSource(dac.io.request.ready, "ec_dac_roi_request_ready")',
                 '    BoringUtils.addSource(dac.io.observe.asUInt, "ec_dac_roi_observation")\n'
                 '    BoringUtils.addSource(dac.io.request.ready, "ec_dac_roi_request_ready")')
    top = destination/'generators/firechip/src/main/scala/FireSim.scala'
    insertion = '''  // Passive B ROI observation; no bridge outputs feed the target.
  if (p(freechips.rocketchip.util.DacRoiEnabled)) {
    import chisel3.util.experimental.BoringUtils
    require(p(NumNodes) == 1)
    val sourceClock = Wire(Clock()); sourceClock := false.B.asClock
    val sourceReset = WireInit(true.B)
    val observation = WireInit(0.U(384.W))
    BoringUtils.addSink(sourceClock, "ec_dac_roi_clock")
    BoringUtils.addSink(sourceReset, "ec_dac_roi_reset")
    BoringUtils.addSink(observation, "ec_dac_roi_observation")
    val roiBridge = Module(new firesim.bridges.DacRoiBridge)
    roiBridge.io.clock := sourceClock
    roiBridge.io.underReset := sourceReset
    roiBridge.io.values := observation.asTypeOf(Vec(6, UInt(64.W)))
  }

'''
    replace_once(top, '  p(ClockBridgeInstantiatorKey).instantiateFireSimClockBridge',
                 insertion+'  p(ClockBridgeInstantiatorKey).instantiateFireSimClockBridge')
    after = inventory(destination)
    changes = {n: {'before': before.get(n), 'after': after.get(n)}
               for n in sorted(before.keys() | after.keys()) if before.get(n) != after.get(n)}
    if inventory(source) != before: raise ValueError('v4 changed')
    record = {'phase': 'prepare-roi-bridge', 'returncode': 0, 'source': str(source),
              'destination': str(destination), 'commands': [command], 'changes': changes,
              'configuration': 'B', 'checkers': 0, 'C4': 'NOT_INTEGRATED',
              'bridge_status': 'SOURCE_WRITTEN_NOT_YET_COMPILED',
              'formal_completion_markers': False, 'target_execution': 'NOT_RUN',
              'runtime_validation': 'NOT_RUN', 'script_sha256': sha(Path(__file__))}
    (log/'result.json').write_text(json.dumps(record, indent=2)+'\n')
    shutil.copy2(__file__, log/'build-script.py')
    (destination.parent/'source-origin.json').write_text(json.dumps(record, indent=2)+'\n')
    print(log/'result.json', flush=True)


if __name__ == '__main__':
    main()
