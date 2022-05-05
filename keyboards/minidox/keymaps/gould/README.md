# Compile

I was not able to flash using Docker. I made it work installing `qmk` in Arch via `pacman`.

``` sh
git fetch --all --recurse-submodules
```

Then build and flash the firmware with:

``` sh
qmk flash -kb minidox -km gould
```

When asked, click the reset button under master keyboard (the left half), keeping the right part connected.

