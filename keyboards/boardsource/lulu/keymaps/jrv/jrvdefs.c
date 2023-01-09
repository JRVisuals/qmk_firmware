#pragma once

#include QMK_KEYBOARD_H

#define REPROGR REPROGRAM_MACRO
#define LT1_SP LT(_RAISE, KC_SPC)
#define LT2_SP LT(_LOWER, KC_SPC)
#define TAB_SB LT(_SPACEFN, KC_TAB)
#define SUPER_L LM(_ADJUST, MOD_LGUI)


// Key code names
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SPACEFN LT(_SPACEFN, KC_SPC)  // Tap for space, hold for space function layer
#define SFT_ENT MT(MOD_RSFT, KC_ENT)  // Tap for enter, hold for right shift
#define LOCK     TG(_LOCKED)
#define KC_PSTE KC_PASTE
#define ZOOM_IN LGUI(KC_PPLS)
#define ZOOM_OUT LGUI(KC_MINS)
#define ZOOM_NML LGUI(KC_0)
#define ITERM LGUI(S(KC_I))
#define CHROMEDEV LGUI(LALT(KC_I))
#define SS_SEL LGUI(LCTL(S(KC_4)))
#define SS_FUL LGUI(S(KC_3))
#define CTRL_TAB LCTL(KC_TAB)
#define CTRL_ESC LCTL_T(KC_ESC)
#define CTRL_QUOT RCTL_T(KC_QUOT)


// Redundant commands on RAISE
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

#ifdef TAP_DANCE_ENABLE
#    define SFT_CAP TD(0)  // Left shift, double tap for caps
#    define DBL_TAB TD(1)  // Tab, double tap for CTRL TAB
#    define DBL_ITERM TD(2)  // Chrome Dev Tools, double tap for iTerm window
#endif
#ifndef TAP_DANCE_ENABLE
#    define SFT_CAP KC_LSFT  //
#    define DBL_TAB KC_TAB  //
#    define DBL_ITERM CHROMEDEV  // Chrome dev (cmd alt i)
#endif

// Tap Dance Definitions
#ifdef TAP_DANCE_ENABLE
// note, this first tap_dance_action_t was qk_tap_dance_action_t but this was causing errors
tap_dance_action_t tap_dance_actions[] = {[0] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS), [1] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, CTRL_TAB), [2] = ACTION_TAP_DANCE_DOUBLE(CHROMEDEV, ITERM)};
#endif


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
