set -e

docker run \
       --rm \
       -e keyboard=whitefox \
       -e keymap=default \
       -e subproject="" \
       -v $('pwd'):/qmk:rw \
       -w /qmk \
       edasque/qmk_firmware \
       make whitefox:gould:bin

echo "Flash your keyboard with:"
echo "sudo dfu-util -D .build/whitefox-gould.bin"
