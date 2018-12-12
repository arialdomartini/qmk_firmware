docker run \
       --rm \
       -e keyboard=hhkb \
       -e keymap=gould \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware \
       make hhkb:gould:bin

