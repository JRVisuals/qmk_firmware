#pragma once

#define _DVORAK 0
#define _GAMING 1
#define _RAISE1 2

#define REPROGR REPROGRAM_MACRO
#define LT1_SP LT(_RAISE1, KC_SPC)
#define LT2_SP LT(_RAISE2, KC_SPC)
#define TAB_SB LT(_SYMBOLS, KC_TAB)
#define SUPER_L LM(_GUI, MOD_LGUI)

enum custom_keycodes {
    DVORAK,
    PLOVER,
    RAISE1,
    RAISE2,
    GUI,
    SYMBOLS,
    GAMING,
    REPROGRAM_MACRO,
};

#ifdef COMBO_ENABLE
#    include "combos.c"
#endif // COMBOS_ENABLE

#ifdef REFLASH_MACRO
#    include <stdbool.h>
#    include QMK_KEYBOARD_H // Needed for macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    }
    switch (keycode) {
        case REPROGRAM_MACRO:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)));
                wait_ms(900);
                SEND_STRING("cd ~/src/qmk-firmware" SS_TAP(X_ENTER));
                wait_ms(100);
                SEND_STRING("sleep 1 && make " QMK_KEYBOARD ":" QMK_KEYMAP ":dfu && exit" SS_TAP(X_ENTER));
                reset_keyboard();
                return false;
                break;
            }
    }
    return true;
}
#endif

#ifndef NO_ACTION_ONESHOT
#    define OS_LSFT OSM(MOD_LSFT)
#    define OS_LALT OSM(MOD_LALT)
#    define OS_LCTL OSM(MOD_LCTL)
#else // NO_ACTION_ONESHOT
#    define OS_LSFT KC_LSFT
#    define OS_LALT KC_LALT
#    define OS_LCTL KC_LCTL
#endif // NO_ACTION_ONESHOT
