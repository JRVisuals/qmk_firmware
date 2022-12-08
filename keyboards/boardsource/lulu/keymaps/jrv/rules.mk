# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
#BOOTLOADER=atmel-dfu

AUDIO_ENABLE = no           # Audio output on port C6
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
COMMAND_ENABLE = no         # Commands for debug and configuration
CONSOLE_ENABLE = no         # Console for debug
COMBO_ENABLE = no
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = no        # Audio control and System control
LEADER_ENABLE = no
LTO_ENABLE = yes
KEY_LOCK_ENABLE = no
MIDI_ENABLE = no            # MIDI controls
MOUSEKEY_ENABLE = yes
#NKRO_ENABLE = no           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
OLED_ENABLE = yes
RGB_MATRIX_ENABLE = yes
SPACE_CADET_ENABLE = no
SPLIT_KEYBOARD = yes
STENO_ENABLE = no
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
TAP_DANCE_ENABLE = yes
TERMINAL_ENABLE = no
UNICODE_ENABLE = no         # Unicode
VELOCIKEY_ENABLE = no
WPM_ENABLE = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
