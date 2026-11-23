# SoflePLUS2 firmware changelog

Firmware for SoflePLUS2 Batch 3 & 4: TPS43, TPS65 and TPS65 Horizontal.

v5.11b / v5.11hb (Horizontal) (2026-11-13)

* Fixed: plugging in the USB cable sometimes put the keyboard into firmware-update mode (the RPI-RP2 drive appeared instead of the keyboard). This could happen on either half.
* Double-tap reset still opens firmware-update mode. Leave about half a second between the two taps; a very fast double tap now just restarts the keyboard.
* Bootmagic now uses three keys, so a key resting on the corner can no longer send the keyboard to firmware-update mode. To open firmware-update mode, hold the three outer keys of the top row on the half you plug the cable into, for about a second while plugging in: Esc, 1, 2 on the left half; Backspace, 0, 9 on the right half. These are the three corner keys whatever is mapped to them, so Backspace may be "-" on your layout. Your keymap and settings are not erased.
* The keyboard takes about half a second longer to appear after plugging in.

v5.11 / v5.11h (Horizontal) (2026-10-11)

* Lighting: while Caps Lock is on, or a layer with indicator LEDs is active, all other LEDs turn off so the indicator colours stand out. With Caps Lock off on the base layer, the effect runs as before.
* Lighting: each indicator LED can have its own colour.
* Wake-up animation when the keyboard is plugged in or the PC starts up.
* Bootmagic jumps to the bootloader without erasing your keymap or settings.
* Disc click: a short tap is now reliable when only one half is plugged in, and a glitch on the cable between the halves no longer causes a false click on the other half.
* Repeat Key: repeats a tap-dance result instead of restarting the dance, and keeps the Shift that Auto Shift adds.
* Matrix tester: the disc click and knob turns now show up in Vial's matrix tester.
* Trackpad: phantom-touch protection (idle re-calibration and a contact confidence check).

Older versions: https://xcmkb-docs.gitbook.io/doc/firmware-changelog
