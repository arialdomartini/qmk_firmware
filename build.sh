docker run \
    --rm \
    -e keyboard=ergodox_ez \
    -e keymap=default_osx \
    -e subproject="" \
    -v $('pwd'):/qmk:rw \
    -w /qmk \
    edasque/qmk_firmware
