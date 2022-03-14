# leepad

![leepad](imgur.com)

*A hot-swappable Pro Micro based numpad with macro keys.*

* Keyboard Maintainer: [Michael Lee](https://github.com/MichaelRLee)
* Hardware Supported: [PCB](https://github.com/MichaelRLee/Custom-Keyboard-PCB/tree/main/Numpad), Pro Micro/alternatives
* Hardware Availability: Get it printed for yourself (open source, JLC gerber files included in PCB link)

Make example for this keyboard (after setting up your build environment):

    make finz/leepad:default

Flashing example for this keyboard:

    make finz/leepad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

To flash for the first time, you will need to short the reset and ground pins on the pro micro twice in quick succession.  
Once flashed, the bootlaoder can be entered by holding `Enter`+`left macro key`, then pressing `numlock`.