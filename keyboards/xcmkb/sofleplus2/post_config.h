#pragma once

/* Plug-in RPI-RP2 fix (2026-11-13), ported from corneplus2 where mode 2 is hardware-tested.
 * The stock RP2040 double-tap reset (config.h + the GENERIC_PROMICRO_RP2040 board config)
 * arms its 200 ms window the moment the chip comes out of reset, so USB contact bounce on
 * plug-in lands in RPI-RP2 about half the time. A keymap config.h may override XCMKB_DTR_MODE:
 *   0          stock double-tap reset
 *   1          double-tap reset OFF (Bootmagic and QK_BOOT still work)
 *   2          default: double-tap kept, but armed only after XCMKB_DTR_SETTLE_MS of stable
 *              power (sofleplus2.c), so plug-in contact bounce cannot trigger it
 * The #undef must live here: the board config.h is included after every keyboard/keymap
 * config.h and defines RP2040_BOOTLOADER_DOUBLE_TAP_RESET unconditionally. post_config.h
 * comes after all config.h files. */
#ifndef XCMKB_DTR_MODE
#    define XCMKB_DTR_MODE 2
#endif
#if XCMKB_DTR_MODE != 0
#    undef RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#endif
#if XCMKB_DTR_MODE == 2
#    ifndef XCMKB_DTR_SETTLE_MS
#        define XCMKB_DTR_SETTLE_MS 300 /* unarmed: a reset in here is a plain reboot */
#    endif
#    ifndef XCMKB_DTR_WINDOW_MS
#        define XCMKB_DTR_WINDOW_MS 500 /* armed: second reset in here -> bootloader */
#    endif
#endif
