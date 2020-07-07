image=${1:-.build/dz60_gould.hex}

echo Flashing ${image}

sudo dfu-programmer atmega32u4 erase --force && \
sudo dfu-programmer atmega32u4 flash ${image} &&
sudo dfu-programmer atmega32u4 reset
