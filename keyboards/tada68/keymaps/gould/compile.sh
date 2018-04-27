docker run \
       --rm \
       -e keyboard=tada68 \
       -e keymap=default \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware \
       make tada68:gould:bin
