# tenleeless

![tenleeless](imgur.com)

*A Teensy-powered, hot-swappable, tenkeyless board*

* Keyboard Maintainer: [Michael Lee](https://github.com/MichaelRLee)
* Hardware Supported: [PCB](https://github.com/MichaelRLee/Custom-Keyboard-PCB/tree/Rev1/Numpad), Teensy 3.2
* Hardware Availability: Get it printed for yourself (open source, JLC gerber files included in PCB link)

Teensy LC and other microcontrollers with the same footprint should also work with a bit of modification.

Make example for this keyboard (after setting up your build environment):

    make finz/tenleeless:default

Flashing example for this keyboard:

    make finz/tenleeless:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

The bootloader can be entered in 2 ways:

* **Key combo**: Press both `shift` keys and `pause`
* **Bootmagic reset**: Hold down the `Esc` key and plug in the keyboard