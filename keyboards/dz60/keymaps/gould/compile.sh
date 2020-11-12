#!/usr/bin/env bash
set -euo pipefail

keymap=${1:-gould}

./util/docker_build.sh dz60:${keymap}:flash
