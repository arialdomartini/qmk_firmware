sudo dfu-programmer atmega32u4 erase --force && \
sudo dfu-programmer atmega32u4 flash dz60_gould.hex &&
sudo dfu-programmer atmega32u4 reset
