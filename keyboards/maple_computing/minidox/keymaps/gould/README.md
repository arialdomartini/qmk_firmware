# Compile

I was not able to flash using Docker. I made it work installing `qmk` in Arch via `pacman`.

``` sh
git fetch --all --recurse-submodules
```

Then build and flash the firmware with:

``` sh
qmk flash -kb maple_computing/minidox -km gould
```

or


``` sh
make maple_computing/minidox:gould:flash
```


When asked, click the reset button under master keyboard (the left half), keeping the right part connected.

You might need to execute

``` sh
xset r rate 185 35
```

to adjust the keyboard rate.
