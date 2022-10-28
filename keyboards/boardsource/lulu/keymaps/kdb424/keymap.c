// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "kdb424.c"
#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _GAMING 1
#define _RAISE1 2
#define _RAISE2 3
#define _GUI 4
#define _SYMBOLS 5
#define REPROGR REPROGRAM_MACRO

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ~   |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |                    |   D  |   H  |   T  |   N  |   S  |  ENT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shft |   ;  |   Q  |   J  |   K  |   X  |-------.    ,-------|   B  |   M  |   W  |   V  |   Z  |   /  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          | LCTL | LGUI | /LT1_SP /       \LT2_SP\  | LCTL | LALT |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
 [_DVORAK] = LAYOUT( \
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,\
  KC_TILD, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                       KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  TAB_SB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                       KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  OS_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX,  XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
                             XXXXXXX, OS_LALT, SUPER_L, LT1_SP,   LT2_SP,  OS_LCTL, KC_NO,   XXXXXXX \
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
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,\
  KC_TILD, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X, _______,  _______,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
                            _______, KC_LALT, KC_SPC,  KC_SPC,   LT2_SP,  KC_LCTL, KC_UP, _______ \
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
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  KC_GRV,  _______, _______, _______, _______, _______,                   XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_DEL,  \
  _______, _______, _______, _______, KC_TAB,  _______,                   XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_BSLS, \
  _______, _______, _______, _______, _______, REPROGR, _______, _______, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS, \
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
 *                          |      | LGUI | /       /       \      \  |Dvorak|Gaming|
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */

[_RAISE2] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                     _______, _______, _______, KC_LBRC, KC_RBRC, LSFT(KC_INS), \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                     KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,  _______, _______,  _______, _______, _______, _______, _______, KC_BSLS, \
                             _______, KC_LCTL, _______,  _______, _______,  DF(0),   DF(1), _______ \
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
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______, \
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
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, RGB_M_SW,                    _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, RGB_M_P, RGB_MOD, RGB_SAI, RGB_SAD, RGB_M_TW, _______, _______,  _______, _______, _______, _______, _______, _______, \
                             _______, RGB_TOG, _______,  _______, _______,  _______, _______, _______ \
)
};
