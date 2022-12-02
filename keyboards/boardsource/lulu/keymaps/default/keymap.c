// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "kdbjrv.c"
#include QMK_KEYBOARD_H
#include "oled.c"

#define _QWERTY 0
#define _RAISE1 1
#define _RAISE2 2
#define _GUI 3
#define _SYMBOLS 4
#define _GAMING 5

// Key code names
// #define SPACEFN LT(_SPACEFN, KC_SPC)  // Tap for space, hold for space function layer
#define SFT_ENT MT(MOD_RSFT, KC_ENT)  // Tap for enter, hold for right shift
//#define LOCK     TG(_LOCKED)
#define KC_PSTE KC_PASTE
#define ZOOM_IN LGUI(KC_PPLS)
#define ZOOM_OUT LGUI(KC_MINS)
#define ZOOM_NML LGUI(KC_0)
#define ITERM LGUI(S(KC_I))
#define CHROMEDEV LGUI(LALT(KC_I))
#define SS_SEL LGUI(LCTL(S(KC_4)))
#define SS_FUL LGUI(S(KC_3))
#define CTRL_TAB LCTL(KC_TAB)

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
#    define SFT_CAP KC_LSFT  // Regular left shift
#    define DBL_TAB KC_TAB  // Regular left shift
#    define DBL_ITERM CHROMEDEV  // Chrome dev (cmd alt i)
#endif

// Tap Dance Definitions
#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {[0] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS), [1] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, CTRL_TAB), [2] = ACTION_TAP_DANCE_DOUBLE(CHROMEDEV, ITERM)};
#endif

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  DBL_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DBL_ITERM,
  LT(KC_LCTL, KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(KC_LCTL, KC_QUOT),
  SFT_CAP,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, QK_BOOT,  QK_BOOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_ENT,
                   KC_LALT,    KC_LGUI, MO(1), LT(MO(_SYMBOLS), KC_SPC),  LT(MO(_SYMBOLS), KC_SPC),   MO(2),   KC_RGUI, KC_RCTL
),

/* RAISE1
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |      |      |      |      |      |                    |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Reprog|      |      |      |      |      |                    |      |      |   7  |  8   |  9   |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |   4  |  5   |  6   |   \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |   1  |  2   |  3   |   -  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | /       /       \      \  |   =  |  0   |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[_RAISE1] = LAYOUT( \
   KC_F12, KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LALT(KC_BSPC),
        _______, _______, _______, _______, _______, _______, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_PDOT, KC_PIPE,

  _______, _______, _______, _______, _______, _______, QK_BOOT, QK_BOOT, XXXXXXX, XXXXXXX,KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, \
                             _______, _______, _______, _______, _______, KC_EQL,  KC_0, _______ \
),
/* RAISE2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F9  |  F10 |  F11 |  F12 |      |                    |      |      |      |  [   |  ]   | SIns |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |                    | Home | Left | Down |  Up  |Right | End  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |-------.    ,-------|      |      |      |      |      |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      | LGUI | /       /       \      \  |Qwerty|Gaming|
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */

[_RAISE2] = LAYOUT( \
 KC_F12, KC_F1, KC_F2,   KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        _______, _______, _______, SS_FUL, SS_SEL, _______, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_PDOT, KC_PIPE,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,  QK_BOOT, QK_BOOT,  _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, \
                             _______, _______, _______,  _______, _______,  DF(0),   DF(1), _______ \
),
/* GUI
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  1   |   2  |   3  |   4  |  5   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  6   |   7  |   8  |   9  |  0   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | /       /       \      \  |      |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[_GUI] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        _______, _______, _______, _______, _______, _______, \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                        _______, _______, _______, _______, _______, _______, \
  QK_BOOT, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  CMB_ON,  CMB_OFF, _______ \
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  !   |   @  |   #  |   $  |  %   |                    |   ^  |   &  |   *  |   (  |  )   | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |   [  |  ]   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | /       /       \      \  |      |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[_SYMBOLS] = LAYOUT( \
XXXXXXX, XXXXXXX, KC_EQL, KC_LPRN, KC_RPRN, KC_EQL, KC_GT, KC_LCBR, KC_RCBR, KC_SCLN, XXXXXXX, XXXXXXX,
        KC_GRV, KC_DQUO, KC_QUOT, KC_MINS, KC_UNDS, KC_EQL , KC_PLUS, KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_GRV,
        KC_PIPE, KC_SLSH, KC_LT  , KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT  , KC_BSLS, KC_QUOT,
        XXXXXXX, KC_SCLN, KC_COMM, KC_PDOT, XXXXXXX, RGB_HUI,RGB_MOD,RGB_TOG, RGB_HUD, KC_PDOT, KC_COMM, KC_COMM, KC_SCLN, KC_PIPE,
                 _______, _______, RGB_VAI,     _______, _______,     RGB_VAD,  _______, _______ \


),

/* Gaming
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ctl  |   A  |   O  |   E  |   U  |   I  |                    |   D  |   H  |   T  |   N  |   S  |  ENT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shft |   ;  |   Q  |   J  |   K  |   X  |-------.    ,-------|   B  |   M  |   W  |   V  |   Z  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LALT | Space| / Space /       \LT2_SP\  |  Ctl |  Up  |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
 [_GAMING] = LAYOUT( \
  KC_ESC, _______,    _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,    _______,\
  KC_TAB, _______, _______, _______,  _______,    _______,                     _______,    _______,    _______,    _______,    _______,    _______, \
  KC_LSFT, _______,    _______,    _______,    _______,    _______,                     _______,    _______,    _______,    _______,    _______,    _______, \
  KC_LCTL, _______, _______,    _______,    _______,    _______, _______,  _______,  _______,    _______,    _______,    _______,    _______,    _______, \
                            KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,   KC_SPC,  KC_SPC, KC_LALT, KC_RCTL \
)
};


/*

  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, RGB_M_SW,                    _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, RGB_M_P, RGB_MOD, RGB_SAI, RGB_SAD, RGB_M_TW, _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, RGB_TOG, _______,  _______, _______,  _______, _______, _______ \

*/
