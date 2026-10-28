"""Shared, fail-closed sandbox policy for launch and offline FST extraction.

This host rejects mounting a new procfs in an unprivileged user namespace.
Reuse the existing procfs READ ONLY, as the successful Baseline launcher does.
Namespace, network and filesystem isolation are never disabled as a fallback.
"""
from pathlib import Path

POLICY = "readonly-root-existing-proc-private-tmp-v1"


def sandbox_command(argv, cwd, env, temporary, bwrap, writable, mounts=()):
    writable, temporary, cwd = map(lambda p: Path(p).resolve(), (writable, temporary, cwd))
    temporary.relative_to(writable)
    if not all(p.is_dir() for p in (writable, temporary, cwd)):
        raise RuntimeError("sandbox requires existing writable, temporary and working directories")
    args = [str(bwrap), "--die-with-parent", "--new-session", "--unshare-all",
            "--ro-bind", "/", "/", "--bind", str(writable), str(writable),
            "--bind", str(temporary), "/tmp", "--bind", str(temporary), "/var/tmp",
            "--dev", "/dev", "--ro-bind", "/proc", "/proc", "--chdir", str(cwd)]
    for entry in mounts:
        backing, virtual = entry[:2]
        mode = entry[2] if len(entry) == 3 else "rw"
        backing = Path(backing).resolve()
        if mode == "rw":
            backing.relative_to(writable)
            if not backing.is_dir() or not Path(virtual).is_dir():
                raise RuntimeError("sandbox bind mount directory missing: " + str(virtual))
        elif mode != "ro":
            raise RuntimeError("unsupported sandbox mount mode: " + str(mode))
        if not backing.exists() or not Path(virtual).exists():
            raise RuntimeError("sandbox bind mount source/target missing: " + str(virtual))
        args += ["--ro-bind" if mode == "ro" else "--bind", str(backing), str(virtual)]
    for key, value in sorted(env.items()):
        args += ["--setenv", str(key), str(value)]
    return args + ["--", *map(str, argv)]
