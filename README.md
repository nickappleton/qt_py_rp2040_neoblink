# qt_py_rp2040_neoblink

A minimal example to get the NeoPixel on the Adafruit QT Py RP2040 to blink. 

## OS X instructions

1. Download and install ARM GCC from ARM https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain
2. Download and install CMake https://cmake.org
3. Clone the Pico SDK with submodules:

```sh
git clone git@github.com:raspberrypi/pico-sdk.git --recurse-submodules
```

4. Clone the Pico examples somewhere. We use the WS2812 support included here.
```sh
git clone git@github.com:raspberrypi/pico-examples.git
```
5. Generate makefiles:

```sh
PICO_SDK_PATH=(path where Pico SDK was cloned) PICO_EXAMPLES_PATH=(path where Pico Examples was cloned) cmake ../pico-examples -DPICO_BOARD=adafruit_qtpy_rp2040 -DPICO_TOOLCHAIN_PATH=/Applications/ARM
```

`/Applications/ARM` is probably where the ARM tools were installed to. If not, change the path.

6. Build the example.

```sh
make -j
```

7. Plug in the QT Py while holding the "boot" button. Then copy the generated `blink.uf2` file to the QT Py.

