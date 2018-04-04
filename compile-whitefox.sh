docker run \
       --rm \
       -e keyboard=whitefox \
       -e keymap=default \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware \
       make whitefox:default:bin
