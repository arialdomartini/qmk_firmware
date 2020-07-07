#!/usr/bin/env bash
set -euo pipefail

keymap=${1:-gould}

./util/docker_build.sh dztech/dz60rgb/v2:${keymap}:flash
