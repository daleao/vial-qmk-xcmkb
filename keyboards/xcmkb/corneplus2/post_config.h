/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Plug-in RPI-RP2 fix (2026-11-13, mode 2 hardware-tested). Board default is 2; a keymap
 * config.h may override XCMKB_DTR_MODE:
 *   0          stock: GENERIC_PROMICRO_RP2040's 200 ms double-tap window, armed at power-on
 *              (plug-in contact bounce lands in RPI-RP2 ~50% of the time)
 *   1          double-tap reset OFF (Bootmagic T/Y and QK_BOOT still work)
 *   2          default: double-tap kept, but armed only after XCMKB_DTR_SETTLE_MS of stable
 *              power (corneplus2.c), so plug-in contact bounce cannot trigger it
 * This must live here, not in the keymap config.h: the board config.h
 * (platforms/chibios/boards/GENERIC_PROMICRO_RP2040/configs/config.h:86) is included
 * AFTER the keymap config.h and defines RP2040_BOOTLOADER_DOUBLE_TAP_RESET unconditionally,
 * so an #undef there is overridden. post_config.h comes after all config.h files. */
#ifndef XCMKB_DTR_MODE
#    define XCMKB_DTR_MODE 2
#endif
#if defined(XCMKB_DTR_MODE) && XCMKB_DTR_MODE != 0
#    undef RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#endif
#if defined(XCMKB_DTR_MODE) && XCMKB_DTR_MODE == 2
#    ifndef XCMKB_DTR_SETTLE_MS
#        define XCMKB_DTR_SETTLE_MS 300 /* unarmed: a reset in here is a plain reboot */
#    endif
#    ifndef XCMKB_DTR_WINDOW_MS
#        define XCMKB_DTR_WINDOW_MS 500 /* armed: second reset in here -> bootloader */
#    endif
#endif

#ifndef BOOTMAGIC_LITE_ROW
#    define BOOTMAGIC_LITE_ROW 0
#endif
#ifndef BOOTMAGIC_LITE_COLUMN
#    define BOOTMAGIC_LITE_COLUMN 1
#endif

#ifndef BOOTMAGIC_LITE_ROW_RIGHT
#    define BOOTMAGIC_LITE_ROW_RIGHT 4
#endif
#ifndef BOOTMAGIC_LITE_COLUMN_RIGHT
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 1
#endif

#ifdef RGBLIGHT_ENABLE
#    ifndef RGBLIGHT_LIMIT_VAL
#        define RGBLIGHT_LIMIT_VAL 120
#    endif
#endif

#ifdef RGB_MATRIX_ENABLE
#    ifndef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#        define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#    endif
#endif

#ifdef OLED_ENABLE
    #ifndef OLED_FONT_H
        #define OLED_FONT_H "keyboards/xcmkb/corneplus2/lib/glcdfont.c"
    #endif
#endif
