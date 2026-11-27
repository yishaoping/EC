#!/bin/bash
# Initialize all marshal-specific submodules. Skip submodules in
# example-workloads (if any). Users should always manually initialize workloads
# if they need them.
#
# You do not need to call this script if you only intend to build bare-metal workloads.
MARSHAL_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
if [ ! -f "$MARSHAL_DIR/.gitmodules" ]; then
    echo "FireMarshal sources are tracked by EC; optional software pins are in firesim/UPSTREAM_SOURCES.json."
    echo "Missing Linux/Buildroot sources must be imported at those pins before building a new image."
    exit 1
fi
set -x

git submodule update --progress --filter=tree:0 --init \
  boards/default/linux \
  boards/default/firmware/opensbi \
  wlutil/busybox \
  boards/default/distros/br/buildroot \
  boards/firechip/drivers/*
