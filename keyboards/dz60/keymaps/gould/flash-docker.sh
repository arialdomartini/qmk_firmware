#!/usr/bin/env bash
set -euo pipefail

docker run --rm  \
	-w /qmk_firmware \
	-v .:/qmk_firmware \
	-e ALT_GET_KEYBOARDS=true \
	qmkfm/qmk_cli \
	qmk flash --keyboard dz60 --keymap gould
