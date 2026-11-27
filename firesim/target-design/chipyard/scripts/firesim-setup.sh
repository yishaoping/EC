#!/usr/bin/env bash

# Sets up FireSim for use as a library within Chipyard

set -e
set -o pipefail

RDIR=$(cd -- "$(dirname -- "$(readlink -f -- "${BASH_SOURCE[0]}")")/.." && pwd)

if [ ! -f "$RDIR/.gitmodules" ]; then
    echo "These dependency sources are tracked by EC; no nested submodule setup is needed."
    exit 0
fi

cd "$RDIR"

# Reenable the FireSim submodule
git config --unset submodule.sims/firesim.update || true
pushd sims/firesim
./build-setup.sh "$@" --library --skip-validate
popd
