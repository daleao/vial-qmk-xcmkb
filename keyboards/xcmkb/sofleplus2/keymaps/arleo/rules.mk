
############ CAPS WORD ############
# read more here https://docs.qmk.fm/features/caps_word, but it may relates to COMMAND_ENABLE = no, already disabled by default so no conflict here.
AUTOCORRECT_ENABLE = yes
CAPS_WORD_ENABLE = yes
TRI_LAYER_ENABLE = yes
LEADER_ENABLE = yes

########### VIA VIAL ###########
VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_ENCODERS_ENABLE = yes
VIAL_USER_CONFIG_ENABLE = yes

# arleo: keymap.c is the only source of truth. QMK Settings off, so the
# config.h tap-hold defines are authoritative (no EEPROM copy that a new build
# resets). Tap dance is unused. Combos and key overrides stay on, and keymap.c
# writes its own definitions into Vial's slots at boot (vial.h has no switch to
# keep the feature but drop Vial's dynamic part).
QMK_SETTINGS = no
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = no
KEY_OVERRIDE_ENABLE = yes

########### PLUS ###########
# macOS dual-mode: mouse fallback for non-PTP hosts (macOS/Linux)
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = digitizer

# v5.07: IQS5xx RDY (GP13) edge-gated reads + RST (GP14) hard reset/recovery
SRC += trackpad_rdy_rst.c

########### CONSOLE ###########
# Overrides CONSOLE_ENABLE = yes in sofleplus2/rules.mk, for this keymap only.
# The console was only ever read by the phantom probe, which is not in this
# build, and it costs a USB interface (.4 in the six-interface map). On the
# Debian client's dmesg the interfaces that failed to bind were always the
# last-probed ones, so one fewer is strictly less exposure. Set back to yes if
# you ever need hid_listen output from a client's board.
CONSOLE_ENABLE = no

########### OS DETECTION ###########
# OS_DETECTION_ENABLE stays ON -- the keymap depends on it: get_effective_os_detection(),
# the OS_DETECTION_TOGGLE keycode and the EEPROM-persisted toggle at 0x0FB3.
# It is OS_DETECTION_KEYBOARD_RESET (config.h) that is disabled, and that is the
# one that caused the Windows reboots and Linux enumeration failures.
OS_DETECTION_ENABLE = yes

########### DIP SWITCH ###########
DIP_SWITCH_ENABLE = yes

########### VIAL 0.7.4 ###########
REPEAT_KEY_ENABLE = yes
LAYER_LOCK_ENABLE = yes

########### UNICODE ###########
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
UCIS_ENABLE = no
UNICODE_COMMON = yes

########### SQUEEZING AVR ###########
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
