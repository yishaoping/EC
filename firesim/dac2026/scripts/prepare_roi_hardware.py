#!/usr/bin/env python3
"""Create a B-only v4 ROI integration; preserve every v3 source and receipt."""
import datetime
import json
from pathlib import Path
import shutil
import subprocess
from build_minimal import BASE, ROOT, inventory, sha


def replace_once(path, old, new):
    text = path.read_text()
    if text.count(old) != 1:
        raise ValueError('expected exactly one insertion anchor: '+str(path))
    path.write_text(text.replace(old, new))


def main():
    source = BASE/'opt4-alveo-v3/B/chipyard'
    destination = BASE/'opt4-roi-v4/B/chipyard'
    if destination.exists():
        raise ValueError('refuse overwrite '+str(destination))
    stamp = datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    log = ROOT/'Experiment/dac2026/build-logs/opt4-roi-v4'/('prepare-B-'+stamp)
    log.mkdir(parents=True, exist_ok=False)
    before = inventory(source)
    destination.parent.mkdir(parents=True, exist_ok=True)
    command = ['cp', '-a', '--reflink=auto', str(source), str(destination)]
    subprocess.run(command, check=True)
    if inventory(source) != before or inventory(destination) != before:
        raise ValueError('copy content mismatch')
    hw = ROOT/'firesim/dac2026/measurement/hardware'
    for src, dest in [(hw/'DacRoi.scala', destination/'generators/rocket-chip/src/main/scala/util/DacRoi.scala'),
                      (hw/'DacRoiPeripheral.scala', destination/'generators/chipyard/src/main/scala/example/DacRoiPeripheral.scala')]:
        if dest.exists():
            raise ValueError('refuse overwrite '+str(dest))
        shutil.copy2(src, dest)
    replace_once(destination/'generators/chipyard/src/main/scala/DigitalTop.scala',
                 '  with chipyard.example.CanHavePeripheryGCD ',
                 '  with chipyard.example.CanHavePeripheryDacRoi\n  with chipyard.example.CanHavePeripheryGCD ')
    replace_once(destination/'generators/firechip/src/main/scala/DacTarget.scala',
                 '  new WithDacMeasurementPolicy ++',
                 '  new chipyard.example.WithDacRoi ++\n  new WithDacMeasurementPolicy ++')
    # The debug instruction memory is synchronous. Use RegNext on all other
    # commit metadata and tick, exactly as the existing BOOM trace path does.
    # No observer output is connected to the functional ready/stall network.
    insertion = '''
  // DAC B ROI observer: original retirement timestamp, not package execution.
  if (p(freechips.rocketchip.util.DacRoiEnabled)) {
    import freechips.rocketchip.util.{DacRoiController, DacRoiRequest, DacRoiReply}
    import chisel3.util.experimental.BoringUtils
    require(xLen == 64)
    val dac = Module(new DacRoiController(coreWidth))
    dac.io.valid := VecInit(rob.io.commit.arch_valids.map(v => RegNext(v, false.B)))
    dac.io.insn := rob.io.commit.debug_insts
    dac.io.originalTick := RegNext(dac.io.tick, 0.U)
    dac.io.satp := RegNext(Cat(csr.io.ptbr.mode, csr.io.ptbr.asid, csr.io.ptbr.ppn), 0.U)
    dac.io.prv := RegNext(csr.io.status.prv, 3.U)
    dac.io.hart := io.hartid
    val requestBits = WireInit(0.U((new DacRoiRequest).getWidth.W))
    val requestValid = WireInit(false.B)
    val replyReady = WireInit(false.B)
    BoringUtils.addSink(requestBits, "ec_dac_roi_request_bits")
    BoringUtils.addSink(requestValid, "ec_dac_roi_request_valid")
    BoringUtils.addSink(replyReady, "ec_dac_roi_reply_ready")
    dac.io.request.bits := requestBits.asTypeOf(new DacRoiRequest)
    dac.io.request.valid := requestValid
    dac.io.reply.ready := replyReady
    BoringUtils.addSource(dac.io.request.ready, "ec_dac_roi_request_ready")
    BoringUtils.addSource(dac.io.reply.bits.asUInt, "ec_dac_roi_reply_bits")
    BoringUtils.addSource(dac.io.reply.valid, "ec_dac_roi_reply_valid")
    BoringUtils.addSource(clock, "ec_dac_roi_clock")
    BoringUtils.addSource(reset.asBool, "ec_dac_roi_reset")
  }

'''
    replace_once(destination/'generators/boom/src/main/scala/exu/core.scala',
                 '  if (trace) {', insertion+'  if (trace) {')
    after = inventory(destination)
    changes = {n: {'before': before.get(n), 'after': after.get(n)}
               for n in sorted(before.keys() | after.keys()) if before.get(n) != after.get(n)}
    if inventory(source) != before:
        raise ValueError('v3 changed')
    record = {'phase': 'prepare-roi-hardware', 'returncode': 0, 'source': str(source),
              'destination': str(destination), 'commands': [command], 'changes': changes,
              'parent_receipts': str(ROOT/'Experiment/dac2026/preparation/opt4-alveo-v3/compile-receipts-verified.json'),
              'configuration': 'B', 'checkers': 0, 'C4': 'NOT_INTEGRATED',
              'host_passive_bridge': 'NOT_IMPLEMENTED', 'target_execution': 'NOT_RUN',
              'runtime_validation': 'NOT_RUN', 'script_sha256': sha(Path(__file__))}
    (log/'result.json').write_text(json.dumps(record, indent=2)+'\n')
    shutil.copy2(__file__, log/'build-script.py')
    (destination.parent/'source-origin.json').write_text(json.dumps(record, indent=2)+'\n')
    print(log/'result.json', flush=True)


if __name__ == '__main__':
    main()
