// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "jrvdefs.c"
#include "layers.h"
#include "encoder.c"
#include "oled.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CTLESC|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | CTL' |
 * |------+------+------+------+------+------|    RGB|    |TOGGLE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /SpaceFN/       \SpaceFN\  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_GRV  ,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB ,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DBL_ITERM,
  CTRL_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTRL_QUOT,
  SFT_CAP ,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  RGB_TOG,  RGB_TOG,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_ENT,
                            KC_LALT, KC_LGUI,   LOWER,  SPACEFN    ,  SPACEFN,      RAISE,  KC_RGUI, KC_RCTL
),
/* QWERTY WINDOWS (swaps left ctrl and escape gui) */
 [_QWERTYWIN] = LAYOUT(
  KC_GRV  ,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB ,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DBL_ITERM,
  GUI_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, CTRL_QUOT,
  SFT_CAP ,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  RGB_TOG,  RGB_TOG,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  SFT_ENT,
                            KC_LALT, KC_LCTL,   LOWER,  SPACEFN    ,  SPACEFN,      RAISE,  KC_RGUI, KC_RCTL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12  |   F1 |  F2  |   F3 |  F4  |  F5  |                    |   F6 |   F7 |  F8  |  F9 |  F10  | F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|   _  |   -  |   =  |   +  |   .  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |SLeft | SDown| SUp  |SRight|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /       /       \      \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
KC_F12  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_F11,
KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
_______, _______, _______, _______, _______, _______,                   KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_PDOT, KC_PIPE,
_______, _______, _______, _______, _______, _______, _______, _______, _______, RCS(KC_LEFT), RCS(KC_DOWN), RCS(KC_UP)  , RCS(KC_RGHT), _______,\
                           _______, _______, _______, _______, _______, _______,  _______, _______ \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12  |   F1 |  F2  |   F3 |  F4  |  F5  |                    |   F6 |   F7 |  F8  |  F9 |  F10  | F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |     |ScrnFul|ScrnSel|     |-------.    ,-------|   _  |   -  |   =  |   +  |   .  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Home |PgDown| PgUp | End  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /       /       \      \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
KC_F12  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9 , KC_F10 , KC_F11,
_______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                    KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
_______, _______, _______, SS_FUL , SS_SEL , _______,                    KC_UNDS, KC_MINS, KC_EQL , KC_PLUS, KC_PDOT, KC_PIPE,
_______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, _______,\
                      _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* SPACEFN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |   =  |   (  |   )  |  =   |                    |   >  |   {  |   }  |   ;  |      | BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ^  |   "  |   '  |   -  |   _  |  =   |                    |   +  |   _  |   -  |   '  |  "   |   ^  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   |  |   /  |   <  |   [  |   {  |  (   |-------.    ,-------|   )  |   }  |   ]  |   >  |   \  |   |  |
 * |------+------+------+------+------+------| R-MODE|    | R-TOGL|------+------+------+------+------+------|
 * |   :  |   ;  |   ,  |   .  |      |R-HUEI|-------.    ,-------|R-HUED| Left | Down |  Up  |Right |   :  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |R-SATI|R-VALI| /Space  /       \Space \  |R-VALD|R-SATD|      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SPACEFN] = LAYOUT( \
_______, _______, KC_EQL , KC_LPRN, KC_RPRN, KC_EQL ,                           KC_GT  , KC_LCBR, KC_RCBR, KC_SCLN, _______, QK_BOOT,
KC_GRV , KC_DQUO, KC_QUOT, KC_MINS, KC_UNDS, KC_EQL ,                           KC_PLUS, KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_GRV,
KC_PIPE, KC_SLSH, KC_LT  , KC_LBRC, KC_LCBR, KC_LPRN,                           KC_RPRN, KC_RCBR, KC_RBRC, KC_GT  , KC_BSLS, KC_PIPE,
_______, _______, _______, _______, _______, RGB_HUI,    RGB_MOD, RGB_TOG,      RGB_HUD, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,\
                           _______, RGB_SAI, RGB_VAI,    _______, _______,      RGB_VAD,  RGB_SAD, _______ \


),

/* ADJUST (LOWER&RAISE)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | M b2 | M up | M b1 | M b2 |      |                    |      |      |      |      |      |      |
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | BOOT | M a0 | M a1 | M a2 |      |      |                    |    |   |QWERTYwin|QWERTYmac|Gaming|Mac/Win|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | M lf | M dn | M rt |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  BOOT |    | BOOT  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | /       /       \      \  |      |      |
 *                          |      |      |/       /         \      \ |      |      |
 *                          `---------------------'           '------''-------------'
 */
[_ADJUST] = LAYOUT( \
  QK_BOOT, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,                     _______, _______, DF(_QWERTYWIN), DF(_QWERTY), DF(_GAMING), CG_TOGG, \
  _______, KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_BTN2, _______,            _______, _______, _______, _______, _______, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,  QK_BOOT, QK_BOOT,  _______, _______, _______, _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),

/* Gaming
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                          |      |      | /       /       \      \  |      |      |
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
