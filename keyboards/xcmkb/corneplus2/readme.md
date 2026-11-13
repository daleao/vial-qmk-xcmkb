# CornePLUS2 firmware changelog

v5.11b (2026-11-13)

* Fixed: plugging in the USB cable sometimes put the keyboard into firmware-update mode (the RPI-RP2 drive appeared instead of the keyboard). This could happen on either half.
* Double-tap reset still opens firmware-update mode. Leave about half a second between the two taps; a very fast double tap now just restarts the keyboard.
* Bootmagic: hold T (left half) or Y (right half) for about a second while plugging in.
* The keyboard takes about half a second longer to appear after plugging in.
* Applies to both the current board (with disc) and the 2025 batch.

v5.11a (2026-10-19)

* Corrected the key layout shown in Vial: a stray extra knob entry was removed and the key positions were tidied. This only changes how the keyboard looks in Vial, not how it types.
* Firmware behaviour is identical to v5.11.
* New: firmware for the 2025 batch.

v5.11 (2026-10-11)

* Lighting: while Caps Lock is on, or a layer with indicator LEDs is active, all other LEDs turn off so the indicator colours stand out. With Caps Lock off on the base layer, the effect runs as before.
* Bootmagic: hold T (left half) or Y (right half) while plugging in to jump straight to the bootloader, without erasing your keymap or settings.
* Disc click: a short tap is now reliable when only one half is plugged in, and a glitch on the cable between the halves no longer causes a false click on the other half.
* Repeat Key: repeats a tap-dance result instead of restarting the dance, and keeps the Shift that Auto Shift adds.
* Matrix tester: the disc click and knob turns now show up in Vial's matrix tester.
* Trackpad: phantom-touch protection (idle re-calibration and a contact confidence check).
* Reset layout: on CornePLUS2, Reset layout in the web app restores the full factory layout (layers, macros, lighting, OLED names and trackpad settings). Because it applies your "no right disc" setup, the 2025 board gets that layout too.
