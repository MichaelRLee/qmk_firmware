# tenleeless

![tenleeless](imgur.com)

*A Teensy-powered, hot-swappable, tenkeyless board*

* Keyboard Maintainer: [Michael Lee](https://github.com/MichaelRLee)
* Hardware Supported: [PCB](https://github.com/MichaelRLee/Custom-Keyboard-PCB/tree/Rev1/Numpad), Teensy 3.2/Teensy LC
* Hardware Availability: Printed it yourself (open source, JLC gerber files included in PCB link)

Make example for this keyboard (after setting up your build environment):

    make finz/tenleeless/<teensy_32/teensy_lc>:default

Flashing example for this keyboard:

    make finz/tenleeless/<teensy_32/teensy_lc>:default:flash

## Bootloader

The bootloader can be entered in 2 ways:

* **Key combo**: Press both `shift` keys and `pause`
* **Bootmagic reset**: Hold down the `Esc` key and plug in the keyboard