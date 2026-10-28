#!/usr/bin/env python3
"""User-run SBT adapter: keep all loaded projects' target trees external.

Make's run_scala_main supplies the original project/runMain command unchanged.
Explicit per-project settings precede it, affecting build products only. Meta-build
load products are separately redirected by private bind mounts in the launcher.
"""
import os
import json
from pathlib import Path
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sbt_inputs import (build_plan, target_settings, checked_resource_inventory,
                        target_probe_commands, verify_target_probe, verify_classpath)

CURRENT = Path('/data1/gzh/EC/chipyard')
RESOURCE_INPUTS = Path('/data1/gzh/EC/slowdown/optimization_3_checker/manifests/sbt_resource_inputs.json')


def command(arguments, plan=None):
    target = Path(os.environ["SLOWDOWN_SBT_TARGET"]).resolve()
    target.relative_to(Path("/data1/gzh/EC/slowdown/optimization_3_checker/build").resolve())
    # `set every ... thisProject.value.id` is evaluated in the current
    # session scope: the failed run sent every project to chipyardRoot and
    # copyResources deleted other projects' resources from that shared tree.
    # Both the project reference and destination must be literal per project.
    setting = target_settings(plan or build_plan(CURRENT, target))
    return [str(Path(os.environ["JAVA_HOME"]) / "bin/java"), "-jar",
            os.environ["SLOWDOWN_SBT_JAR"], setting, *arguments]


def main():
    target = Path(os.environ['SLOWDOWN_SBT_TARGET']).resolve()
    plan = build_plan(CURRENT, target)
    inventory = checked_resource_inventory(plan, RESOURCE_INPUTS)
    probes, expected = target_probe_commands(plan)
    if sys.argv[1:] == ["--print-command"]:
        print(json.dumps({'argv': command([], plan), 'java_or_sbt_executed': False,
                          'unique_project_targets': len(plan['projects']),
                          'target_probe_commands': probes,
                          'resource_references': len(inventory['references']),
                          'user_run_stages': ['SBT evaluated target/classes isolation',
                                              'Scala packaging and actual JAR resource audit',
                                              'original Make runMain arguments']}))
        return
    # Only the real user-run build enters this branch. --static-check and
    # --preflight-only never load a project or run any of these SBT commands.
    report_dir = Path(tempfile.mkdtemp(prefix='sbt_input_guard_', dir=target.parent))
    (report_dir / 'project_plan.json').write_text(json.dumps(plan, indent=2) + '\n')

    def run_stage(name, arguments):
        logfile = report_dir / (name + '.log')
        print('SBT_INPUT_PHASE=' + name + '\nSBT_INPUT_LOG=' + str(logfile), flush=True)
        with logfile.open('xb') as log:
            proc = subprocess.Popen(command(arguments, plan), stdout=subprocess.PIPE,
                                    stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
            try:
                for line in proc.stdout:
                    log.write(line); log.flush()
                    sys.stdout.buffer.write(line); sys.stdout.buffer.flush()
                rc = proc.wait()
            except BaseException:
                proc.terminate()
                try:
                    proc.wait(timeout=10)
                except subprocess.TimeoutExpired:
                    proc.kill(); proc.wait()
                raise
        if rc:
            raise RuntimeError('SBT input phase failed: ' + name + '; see ' + str(logfile))
        return logfile

    target_log = run_stage('evaluated_targets', probes)
    target_report = verify_target_probe(target_log.read_text(), expected)
    (report_dir / 'target_check.json').write_text(json.dumps(target_report, indent=2) + '\n')
    run_stage('compiled_classpath', ['show chipyard / Runtime / fullClasspathAsJars'])
    chipyard = next(p for p in plan['projects'] if (p['build'], p['id']) == ('chipyard', 'chipyard'))
    exported = Path(chipyard['target']) / 'streams/runtime/fullClasspathAsJars/_global/streams/export'
    if not exported.is_file():
        raise RuntimeError('SBT did not record the expected actual run classpath: ' + str(exported))
    classpath = exported.read_text().strip().split(os.pathsep)
    report = verify_classpath(plan, inventory, classpath)
    report['export_file'] = str(exported)
    (report_dir / 'classpath_resource_check.json').write_text(json.dumps(report, indent=2) + '\n')
    if report['errors']:
        raise RuntimeError('Packaged BlackBox resource failures (all checked):\n- ' + '\n- '.join(report['errors']))
    checked_resource_inventory(plan, RESOURCE_INPUTS)
    print('SBT_TARGET_ISOLATION=PASS\nSBT_PACKAGED_RESOURCES=PASS', flush=True)
    argv = command(sys.argv[1:], plan)
    os.execv(argv[0], argv)


if __name__ == "__main__":
    main()
