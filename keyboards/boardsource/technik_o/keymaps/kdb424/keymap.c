/* Copyright 2020 Boardsource
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

#include QMK_KEYBOARD_H
#include "kdb424.c"

#define _DVORAK 0
#define _GAMING 1
#define _RAISE1 2
#define _RAISE2 3
#define _GUI 4
#define _SYMBOLS 5
#define REPROGR REPROGRAM_MACRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_ortho_4x12(
  KC_GESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  TAB_SB,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  OS_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
  XXXXXXX,  XXXXXXX, XXXXXXX, OS_LALT, SUPER_L, LT1_SP,  LT2_SP,  OS_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  [_GAMING] = LAYOUT_ortho_4x12(
  KC_GESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  TAB_SB,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  OS_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
  XXXXXXX,  XXXXXXX, XXXXXXX, OS_LALT, SUPER_L, LT1_SP,  LT2_SP,  OS_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  ),
  [_RAISE1] = LAYOUT_ortho_4x12(
  KC_GRV,  _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_DEL,  \
  _______, _______, _______, _______, KC_TAB,  _______, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_BSLS, \
  _______, _______, _______, _______, _______, REPROGR, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS, \
  XXXXXXX,  XXXXXXX, XXXXXXX,_______, _______, _______, _______, KC_EQL,  KC_0,    XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  [_RAISE2] = LAYOUT_ortho_4x12(
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_LBRC, KC_RBRC, LSFT(KC_INS), \
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, KC_BSLS, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, _______, _______, _______,  DF(0),  DF(1),   XXXXXXX, XXXXXXX, XXXXXXX \
  ),
  [_GUI] = LAYOUT_ortho_4x12( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, CMB_ON,  CMB_OFF, XXXXXXX, XXXXXXX, XXXXXXX \
  ),
  [_SYMBOLS] = LAYOUT_ortho_4x12( \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, RGB_M_SW, _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
    _______, RGB_M_P, RGB_MOD, RGB_SAI, RGB_SAD, RGB_M_TW, _______, _______, _______, _______, _______, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, _______,  _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  )

};

