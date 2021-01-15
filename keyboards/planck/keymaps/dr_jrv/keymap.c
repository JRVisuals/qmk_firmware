// Layout picture at http://www.keyboard-layout-editor.com/#/gists/b1849c3de3e27b7ff62f4ed1df172baf
// make planck/rev6:dr_jrv:dfu-util
#include QMK_KEYBOARD_H

#include "eeconfig.h"
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers { _QWERTY, _NUMPAD, _RAISE, _LOWER, _ADJUST, _MEDIA, _ONESHOT, _SPACEFN };

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    NUMPAD,
    RAISE,
    LOWER,
    ADJUST,
    MEDIA,
    ONESHOT,
    SPACEFN,
    DYNAMIC_MACRO_RANGE,
    // Custom Code Macros
    CODE_ARROWFN,
    GIT_ADD,
    GIT_COMMIT,
    GIT_STATUS,
    GIT_RESET,
};

#include "dynamic_macro.h"

// Key code names
#define SPACEFN LT(_SPACEFN, KC_SPC)  // Tap for space, hold for space function layer
#define SFT_ENT MT(MOD_RSFT, KC_ENT)  // Tap for enter, hold for right shift
//#define LOCK     TG(_LOCKED)
#define KC_PSTE KC_PASTE
#define ZOOM_IN LGUI(KC_PPLS)
#define ZOOM_OUT LGUI(KC_MINS)
#define ZOOM_NML LGUI(KC_0)
#define ITERM LGUI(S(KC_I))
#define SS_SEL LGUI(LCTL(S(KC_4)))
#define SS_FUL LGUI(S(KC_3))

#ifdef TAP_DANCE_ENABLE
#    define SFT_CAP TD(0)  // Left shift, double tap for caps
#endif
#ifndef TAP_DANCE_ENABLE
#    define SFT_CAP KC_LSFT  // Regular left shift
#endif

// Tap Dance Definitions
#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {[0] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)};
#endif

// Layout definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |*Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |  FN  | Ctrl |  Alt |  CMD | Lower|    Space    | Raise| Left | Down |  Up  | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        SFT_CAP, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SFT_ENT,
        MEDIA, KC_LCTL, KC_LALT, KC_LCMD, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
        ),

    /* NUMPAD
     * ,-----------------------------------------------------------------------------------.
     * |QWERTY| NULL |  Up  | NULL | NULL | NULL | NULL |   /  |   7  |   8  |   9  |   -  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Left | Down | Right| NULL | NULL | NULL |   *  |   4  |   5  |   6  |   +  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |NumLck| NULL | NULL | NULL | NULL | NULL |BckSp |   1  |   2  |   3  |  Ent |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |   0  |   .  |   ,  |   =  |
     * `-----------------------------------------------------------------------------------'
     */
    [_NUMPAD] = LAYOUT_planck_grid(
        QWERTY, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS,
        _______, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, KC_P1, KC_P2, KC_P3, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PDOT, KC_PCMM, KC_PEQL),

    /* RAISE
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | F11  | F12  |SS_FUL|SS_SEL|      |      |   -  |   =  |   [  |   ]  |  \   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |      |ISO # |ISO / | NULL |      | Enter|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    _______, KC_F11, KC_F12, SS_FUL, SS_SEL, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_LSFT,
    _______, _______, _______, _______, _______, _______, KC_NUHS, KC_NUBS, XXXXXXX, _______, KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* LOWER
     * ,-----------------------------------------------------------------------------------.
     * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |DelWrd|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   _  |   +  |   {  |   }  |  |   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |LShift|  F6  |  F7  |  F8  |  F9  |  F10 |      |ISO ~ |ISO | | NULL | PgUp | Enter|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      | Home | PgDn |  End |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LALT(KC_BSPC),
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LSFT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, S(KC_NUHS), S(KC_NUBS), XXXXXXX, XXXXXXX, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
        ),

    /* ADJUST (Raise and Lower)
     * ,-----------------------------------------------------------------------------------.
     * | SLEEP| RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-| CTog | CUp  | POWER|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | WAKE | NULL | NULL | NULL | NULL | NULL | NULL | MMod | NULL | CRes | CDn  | NULL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | NULL | NULL | NULL |AudOff|MusOff|QWERTY|NUMPAD|Mus On|Aud On| NULL |Voice+|SysReq|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | NULL | NULL | NULL | Reset|      |     NULL    |      | NULL |AGNorm|Voice-|AGSwap|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_SLEP, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, CK_TOGG, CK_UP, KC_PWR,
        KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_MOD, XXXXXXX, CK_RST, CK_DOWN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, AU_OFF, MU_OFF, QWERTY, NUMPAD, MU_ON, AU_ON, XXXXXXX, MUV_IN, KC_SYSREQ,
        XXXXXXX, XXXXXXX, XXXXXXX, RESET, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, AG_NORM, MUV_DE, AG_SWAP
        ),

    /* MEDIA, COMMANDS, AND CODE MACROS
     * ,-----------------------------------------------------------------------------------.
     * | NULL | NULL | NULL | NULL | gRes | iTrm | NULL | NULL |Insert| NULL |PrntSc| NULL |›
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | NULL | gAdd | gStat| NULL | ()=> | NULL | NULL | NULL | NULL | NULL |PlyMc1|PlyMc2|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |ONESHT| NULL | NULL |gComit| NULL | NULL | NULL | NULL |ZoomOu|ZoomIn| Prev |RecStp|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | NULL | NULL |      | Vol- |     Mute    | Vol+ |Zoom 0| Stop | Next | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_MEDIA] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GIT_RESET, ITERM, XXXXXXX, XXXXXXX, KC_INS, XXXXXXX, KC_PSCR, XXXXXXX,
        XXXXXXX, GIT_ADD, GIT_STATUS, XXXXXXX, CODE_ARROWFN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,
        ONESHOT, XXXXXXX, XXXXXXX, GIT_COMMIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ZOOM_OUT, ZOOM_IN, KC_MPRV, DYN_REC_STOP,
        _______, XXXXXXX, XXXXXXX, _______, KC_VOLD, KC_MUTE, KC_MUTE, KC_VOLU, ZOOM_NML, KC_MSTP, KC_MNXT, KC_MPLY
        ),

    /* ONESHOT
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |RecMc1|RecMc2|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ONESHOT] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, DYN_REC_START1, DYN_REC_START2,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* SPACE FN
     * ,-----------------------------------------------------------------------------------.
     * |PRNT SC|      |  UP  |      |      |      |      |      |  UP  |      |      |SLEEP |
     * |-------+------+------+------+------+-------------+------+------+------+------+------|
     * |       | LEFT | DOWN | RIGHT|      |      |      | LEFT | DOWN | RIGHT|      |      |
     * |-------+------+------+------+------+------|------+------+------+------+------+------|
     * |       |   ~  |   #  |   /  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  |  |   |
     * |-------+------+------+------+------+------+------+------+------+------+------+------|
     * |       |      |      |      |      |             |      | MUTE |VOLDWN|VOL UP|      |
     * `-----------------------------------------------------------------------------------'
     */
    [_SPACEFN] = LAYOUT_planck_grid(
        KC_PSCR, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, KC_SLEP,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_TILD, KC_NUHS, KC_SLSH, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS, KC_EQL, KC_PIPE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC__MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX
    ),

};

#ifdef AUDIO_ENABLE
float tone_startup[][2]        = SONG(STARTUP_SOUND);
float tone_qwerty[][2]         = SONG(QWERTY_SOUND);
float tone_numpad[][2]         = SONG(NUM_LOCK_ON_SOUND);
float tone_oneshot[][2]        = SONG(TERMINAL_SOUND);
float tone_dyn_macro_rec[][2]  = SONG(SONIC_RING);
float tone_dyn_macro_stop[][2] = SONG(SONIC_RING);
float music_scale[][2]         = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]        = SONG(GOODBYE_SOUND);
#endif

void press_key(uint16_t key) {
    register_code(key);
    unregister_code(key);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // uint16_t macro_kc = (keycode == ONESHOT ? DYN_REC_STOP : keycode);
    if (!process_record_dynamic_macro(keycode, record)) {
        switch (keycode) {
            case DYN_REC_START1:
            case DYN_REC_START2:
#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_dyn_macro_rec);
#endif
                break;
            case DYN_REC_STOP:
#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_dyn_macro_stop);
#endif
                break;
        }
        return false;
    }

    switch (keycode) {
        case ONESHOT:
            if (record->event.pressed) {
                layer_on(_ONESHOT);
                set_oneshot_layer(_ONESHOT, ONESHOT_START);
                clear_oneshot_layer_state(ONESHOT_PRESSED);
#ifdef AUDIO_ENABLE
                PLAY_SONG(tone_oneshot);
#endif
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_NUMPAD)) {
#ifdef AUDIO_ENABLE
                    PLAY_SONG(tone_qwerty);
#endif
                    layer_off(_NUMPAD);
                }
            }
            return false;
            break;
        case NUMPAD:
            if (record->event.pressed) {
                if (!IS_LAYER_ON(_NUMPAD)) {
#ifdef AUDIO_ENABLE
                    PLAY_SONG(tone_numpad);
#endif
                    layer_on(_NUMPAD);
                }
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                rgblight_sethsv(rgblight_get_hue() - 50, rgblight_get_sat(), 255);
                layer_on(_RAISE);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            } else {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 128);
                layer_off(_RAISE);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                rgblight_sethsv(rgblight_get_hue() + 50, rgblight_get_sat(), 255);
                layer_on(_LOWER);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            } else {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 128);
                layer_off(_LOWER);
                update_tri_layer(_RAISE, _LOWER, _ADJUST);
            }
            return false;
            break;
        case MEDIA:
            if (record->event.pressed) {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 255);
                layer_on(_MEDIA);
            } else {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 128);
                layer_off(_MEDIA);
            }
            return false;
            break;
        case SPACEFN:
            if (record->event.pressed) {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 255);

            } else {
                rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 128);
            }
            return false;
            break;
        case CODE_ARROWFN:
            if (record->event.pressed) {
                SEND_STRING("()=>{};" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
            }
            return false;
            break;

        case GIT_ADD:
            if (record->event.pressed) {
                SEND_STRING("git add -A \n");
            }
            return false;
            break;

        case GIT_STATUS:
            if (record->event.pressed) {
                SEND_STRING("git status \n");
            }
            return false;
            break;

        case GIT_COMMIT:
            if (record->event.pressed) {
                SEND_STRING("git commit -m ''" SS_TAP(X_LEFT));
            }
            return false;
            break;
        case GIT_RESET:
            if (record->event.pressed) {
                SEND_STRING("git reset HEAD");
            }
            return false;
            break;
    }
    return true;
}
