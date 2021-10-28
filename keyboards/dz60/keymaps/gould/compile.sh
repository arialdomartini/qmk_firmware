docker run \
       --rm \
       -e keyboard=dz60 \
       -e keymap=default \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware \
       make dz60:gould:bin
