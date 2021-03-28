/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MEDIA,
  _SPACEFN };

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  MEDIA,
    // Custom Code Macros
    CODE_ARROWFN,
    CODE_ARROW,
    GIT_ADD,
    GIT_COMMIT,
    GIT_STATUS,
    GIT_RESET,
};


#include "dynamic_macro.h"

// Key code names
// #define SPACEFN LT(_SPACEFN, KC_SPC)  // Tap for space, hold for space function layer
#define SFT_ENT MT(MOD_RSFT, KC_ENT)  // Tap for enter, hold for right shift
//#define LOCK     TG(_LOCKED)
#define KC_PSTE KC_PASTE
#define ZOOM_IN LGUI(KC_PPLS)
#define ZOOM_OUT LGUI(KC_MINS)
#define ZOOM_NML LGUI(KC_0)
#define ITERM LGUI(S(KC_I))
#define SS_SEL LGUI(LCTL(S(KC_4)))
#define SS_FUL LGUI(S(KC_3))

// Redundant commands on RAISE
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
* | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BKSP |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |*Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  FN  | Ctrl |  Alt |  CMD | Lower|   SpaceFN   | Raise| Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_CAP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
  MEDIA,   KC_LCTL, KC_LALT, KC_LCMD, LOWER, LT(_SPACEFN, KC_SPC), LT(_SPACEFN, KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
* |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |DelWrd|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |LShift|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |  =>  |   [  |   ]  | Enter|
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LALT(KC_BSPC),
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, CODE_ARROW, KC_LBRC, KC_RBRC, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |SS_FUL|SS_SEL|      |   _  |   -  |   =  |   [  |   ]  |  \   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |LShift| undo | cut  | copy | paste|      |      |ISO # |ISO / | NULL |   |  | Enter|
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
    _______, _______, _______, SS_FUL, SS_SEL, _______, KC_UNDS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LSFT, UNDO, CUT, COPY, PASTE, _______, _______, KC_NUHS, KC_NUBS, XXXXXXX, KC_PIPE, KC_ENT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
* |      | M b2 | M up | M b1 | M b2 | SAT+ | SAT- |BRGTH+|BRGTH-| CTog | CUp  | POWER|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      | M lf | M dn | M rt |RGBMOD| HUE+ | HUE- | MMod | NULL | CRes | CDn  | NULL |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | NULL | NULL | NULL |AudOff|MusOff|QWERTY| NULL |Mus On|Aud On| NULL |Voice+|SysReq|
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | NULL | NULL | NULL | Reset|      |     NULL    |      | NULL |AGNorm|Voice-|AGSwap|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX, KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_BTN2, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, CK_TOGG, CK_UP, KC_PWR,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, RGB_MOD, RGB_HUI, RGB_HUD, MU_MOD, XXXXXXX, CK_RST, CK_DOWN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, AU_OFF, MU_OFF, QWERTY, XXXXXXX, MU_ON, AU_ON, XXXXXXX, MUV_IN, KC_SYSREQ,
        XXXXXXX, XXXXXXX, XXXXXXX, RESET, _______, ITERM, ITERM, _______, XXXXXXX, AG_NORM, MUV_DE, AG_SWAP
),

/* SPACE FN
     * ,------------------------------------------------------------------------------------.
     * |       |      |      |      |      |             |      |      |      |      |      |
     * |-------+------+------+------+------+------+------+------+------+------+------+------|
     * |  NULL | NULL |   |  |   -  |   _  |  =   |   =  |   _  |   -  |   |  | NULL | NULL |
     * |-------+------+------+------+------+-------------+------+------+------+------+------|
     * |   '   |   /  |   <  |   {  |   [  |   (  |   )  |   ]  |   }  |   >  |   \  |  '   |
     * |-------+------+------+------+------+------|------+------+------+------+------+------|
     * |  NULL |   ;  |   .  |   ,  | NULL | NULL | NULL | NULL |   ,  |   .  |   ;  | NULL |
     * |-------+------+------+------+------+------+------+------+------+------+------+------|
     * |  NULL | NULL | NULL | NULL | NULL |             | NULL | NULL | NULL | NULL | NULL |
     * `-----------------------------------------------------------------------------------'
     */
    [_SPACEFN] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, KC_PIPE, KC_MINS, KC_UNDS, KC_EQL , KC_EQL , KC_UNDS, KC_MINS, KC_PIPE, XXXXXXX, XXXXXXX,
        KC_QUOT, KC_SLSH, KC_LT  , KC_LCBR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT  , KC_BSLS, KC_QUOT,
        XXXXXXX, KC_SCLN, KC_PDOT, KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_PDOT, KC_SCLN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;

        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
