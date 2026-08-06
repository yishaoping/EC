#!/usr/bin/env bash

# Sets up FireSim for use as a library within Chipyard

set -e
set -o pipefail

RDIR=$(cd "$(dirname "$0")/.." && pwd)

cd "$RDIR"

# Reenable the FireSim submodule
git config --unset submodule.sims/firesim.update || true
pushd sims/firesim
./build-setup.sh "$@" --library --skip-validate
popd
