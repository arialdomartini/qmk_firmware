docker run \
       --rm \
       -e keyboard=ergodox_ez \
       -e keymap=gould \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware
