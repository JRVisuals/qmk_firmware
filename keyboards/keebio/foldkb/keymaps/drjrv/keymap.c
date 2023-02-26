/* Copyright 2022 Forrest Cahoon <forrest.cahoon@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


// Milliseconds the backlight is off (or on) when blinking to show
// caps lock is on. In other words, half the time of a full blink cycle.
#define CAPS_LOCK_BLINK_MS 350

#include QMK_KEYBOARD_H
#include "jrvdefs.c"

enum layer {
    _QWERTY,
    _LOWER,      // media keys on left rail |  and classic JRV lower
    _RAISE,      // mouse keys on WASD and classic JRV railse
    _SPACEFN, // "space function" classic JRV progamming layer
};

enum custom_keycodes {
    PG_ARRO = SAFE_RANGE,
    PG_CARRO,
    PG_BANG,
    PG_ENDC,
    PG_EQEQ,
    PG_EQL,
    PG_LBRK,
    PG_LPAR,
    PG_MINS,
    PG_NEEQ,
    PG_RBRK,
    PG_RPAR,
    PG_SLAS,
    PG_VBAR,
    MS_BTN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐ 16
    KC_MUTE,  KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL, KC_BSPC,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┤ 15
    KC_HOME,     KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤ 14
    KC_END ,     DBL_ITERM,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      KC_ENT,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴─────────────┬───┘ 14
    KC_PGUP,     SFT_CAP,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,      SFT_ENT,  SFT_ENT,
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┴────────┤        ├────────┴────────┴──────┬─┴────────┼────────┴─┬─────────┬──────────┤13
    KC_PGDN,       KC_LCTL,   KC_LALT,   KC_LGUI,   LOWER, SPACEFN, SPACEFN,           SPACEFN,   SPACEFN ,      RAISE  ,   KC_RGUI,  KC_RALT,  KC_RCTL
// └────────┴───┴──────────┴─────────┴──────────┴────────┴─────────────────┘        └────────────────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
  [_LOWER] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_MUTE, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F12,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_MPRV,       KC_TILD,     KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,_______,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
    KC_MPLY,     _______,      _______, _______, _______, _______, _______,           KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_PDOT, KC_PIPE,    _______,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴────┬────────┬───┘
    KC_MNXT, _______,          _______, _______, _______,  _______, _______,          _______, RCS(KC_LEFT),RCS(KC_DOWN),RCS(KC_UP),RCS(KC_RGHT), _______,  _______,
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┼────────┤        ├────────┴─┬──────┴──────┬─┴────────┼────────┴─┬─────────┬─┴────────┤
    KC_VOLD,     _______,   _______,  _______,   _______, _______, KC_VOLD,          KC_VOLU,   _______,      _______,   _______,   _______,  _______
// └────────┴───┴──────────┴─────────┴──────────┴────────┴────────┴────────┘        └──────────┴─────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
  [_RAISE] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______, QK_BOOT, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F12,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    _______,     _______,       KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
    _______,     _______,      KC_MS_L,  KC_MS_D, KC_MS_R,  SS_SEL, _______,          KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_PDOT, KC_PIPE,    _______,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴────┬────────┬───┘
    _______, _______,          _______, KC_MS_D, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______,
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┼────────┤        ├────────┴─┬──────┴──────┬─┴────────┼────────┴─┬─────────┬─┴────────┤
    _______,     _______,   _______,  _______,   _______, _______, _______,          _______,   _______,      _______,   _______,   _______,  _______
// └────────┴───┴──────────┴─────────┴──────────┴────────┴────────┴────────┘        └──────────┴─────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
  [_SPACEFN] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    _______,  _______, _______, _______, KC_EQL , KC_LPRN, KC_RPRN, KC_EQL,             KC_GT, KC_LCBR, KC_RCBR, KC_SCLN, _______, _______, _______, _______,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    RGB_MOD,        KC_TAB,     KC_DQUO, KC_QUOT, KC_MINS,PG_CARRO, KC_EQL,           KC_PLUS, KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_LBRC, _______, DBL_ITERM,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
    RGB_TOG,        KC_PIPE,    KC_SLSH,  KC_LT , KC_LBRC, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_RBRC,  KC_GT , KC_BSLS, KC_PIPE,     _______,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴────┬────────┬───┘
    RGB_VAI, _______,           _______, _______, _______, PG_NEEQ, PG_EQEQ,          _______, KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT,      _______,
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┼────────┤        ├────────┴─┬──────┴──────┬─┴────────┼────────┴─┬─────────┬─┴────────┤
    RGB_VAD,     _______,   _______,  _______,   _______, _______,  _______,            _______,   _______,     KC_LEFT ,  KC_DOWN ,  KC_UP  ,  KC_RGHT ,
// └────────┴───┴──────────┴─────────┴──────────┴────────┴────────┴────────┘        └──────────┴─────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
};

// clang-format on

const key_override_t pg_lbrk_none  = ko_make_with_layers_and_negmods(0, PG_LBRK, KC_LEFT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_lbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LBRK, KC_LEFT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_lpar_none  = ko_make_with_layers_and_negmods(0, PG_LPAR, KC_LEFT_PAREN, ~0, ~0);
const key_override_t pg_lpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LPAR, KC_LEFT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rbrk_none  = ko_make_with_layers_and_negmods(0, PG_RBRK, KC_RIGHT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_rbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RBRK, KC_RIGHT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rpar_none  = ko_make_with_layers_and_negmods(0, PG_RPAR, KC_RIGHT_PAREN, ~0, ~0);
const key_override_t pg_rpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RPAR, KC_RIGHT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_slas_none  = ko_make_with_layers_and_negmods(0, PG_SLAS, KC_SLASH, ~0, ~0);
const key_override_t pg_slas_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_SLAS, KC_BACKSLASH, ~0, ~MOD_MASK_SHIFT);

const key_override_t ms_btn_none  = ko_make_with_layers_and_negmods(0, MS_BTN, KC_MS_BTN1, ~0, ~0);
const key_override_t ms_btn_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, MS_BTN, KC_MS_BTN2, ~0, ~MOD_MASK_SHIFT);

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &pg_lbrk_none, &pg_lbrk_shift,
    &pg_lpar_none, &pg_lpar_shift,
    &pg_rbrk_none, &pg_rbrk_shift,
    &pg_rpar_none, &pg_rpar_shift,
    &pg_slas_none, &pg_slas_shift,
    &ms_btn_none, &ms_btn_shift,
    NULL};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t std_mods     = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t all_mods     = std_mods | oneshot_mods;
    bool    shift_on     = all_mods & MOD_MASK_SHIFT;
    bool    ctrl_on      = all_mods & MOD_MASK_CTRL;

    // None of our special keycodes use ALT or GUI mods (so far), so we
    // check once here at the top and let other code handle it if any of
    // these are set.
    if (all_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) return true;

    switch (keycode) {
        case KC_CAPS:
            // On caps lock release, if caps lock just got turned off, ensure that
            // backlight is enabled when it stops blinking.
            if (!record->event.pressed) {
                if (!host_keyboard_led_state().caps_lock) {
                    backlight_enable();
                    // In this case, we want to continue processing
                    return true;
                }
            }
            break;
         case PG_CARRO:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("->");
                    if (ctrl_on) SEND_STRING(" ");
                } else {
                    if (ctrl_on) SEND_STRING(" ");
                     SEND_STRING("=>");
                    if (ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_ARRO:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("=>");
                    if (!ctrl_on) SEND_STRING(" ");
                } else {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("->");
                    if (ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_BANG:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("*");
                    if (!ctrl_on) SEND_STRING(" ");
                } else {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("!");
                    if (!ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_ENDC:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING(SS_TAP(X_END));
                if (!shift_on) SEND_STRING(";");
                if (!ctrl_on) SEND_STRING(SS_TAP(X_ENTER));
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("==") : SEND_STRING("===");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQL:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("+") : SEND_STRING("=");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_MINS:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (shift_on) {
                    if (ctrl_on) SEND_STRING(" ");
                    SEND_STRING("_");
                    if (ctrl_on) SEND_STRING(" ");
                } else {
                    if (!ctrl_on) SEND_STRING(" ");
                    SEND_STRING("-");
                    if (!ctrl_on) SEND_STRING(" ");
                }
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_NEEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("!=") : SEND_STRING("!==");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_VBAR:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("&") : SEND_STRING("|");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
    }
    return true;
}

static uint16_t caps_lock_blink_timer = 0;

// This is called after every matrix scan. We make the backlight blink
// when caps lock is on here. To ensure the backlight is in the on state
// when caps lock is turned off, we also watch for the relase of the caps
// lock key in process_record_user().
void housekeeping_task_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        if (timer_elapsed(caps_lock_blink_timer) >= CAPS_LOCK_BLINK_MS) {
             backlight_toggle();
            caps_lock_blink_timer = timer_read();
        }
    }
}

// The backlight level shows which layer we are in:
// Mouse layer: dim | QWERTY layer: medium | Programming layer: bright
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:
            backlight_level(1);
            break;
        case _LOWER:
            backlight_level(3);
            break;
        default:
            backlight_level(2);
            break;
    }
    return state;
}

void keyboard_post_init(void) {
    backlight_level(2);
}
