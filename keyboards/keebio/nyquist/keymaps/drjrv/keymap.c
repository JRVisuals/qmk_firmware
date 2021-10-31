#include QMK_KEYBOARD_H


// Bringing in my PREONIC mappings
enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNK,
  _SPACEFN };

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  FUNK,
};


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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |ChromeDevTools/iTerm|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |*Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |  Ctrl|  FN  |  Alt |  CMD | Lower|   SpaceFN   | Raise| Left | Down |  Up  | Right|
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT
    (
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        DBL_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DBL_ITERM,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_CAP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
        KC_LCTL, FUNK,   KC_LALT, KC_LCMD, LOWER, LT(_SPACEFN, KC_SPC), LT(_SPACEFN, KC_SPC), RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),
    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | F7  |  F8  |  F9  |  F10 |  F11 |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |DelWrd|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |   _  |   -  |   =  |   +  |   .  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LShift|      |      |      |      |      |      |      |      |      |      | Enter|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT
    (
        KC_F12, KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, LALT(KC_BSPC),
        _______, _______, _______, _______, _______, _______, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_PDOT, KC_PIPE,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |  F12 |   F1  |  F2  |  F3  |  F4  |  F5  |  F6  | F7  |  F8  |  F9  |  F10 |  F11 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |SS_FUL|SS_SEL|      |   _  |   -  |   =  |   +  |   .  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LShift| undo | cut  | copy | paste|      |      |ISO # |ISO / | NULL |   |  | Enter|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT
    (
        KC_F12, KC_F1, KC_F2,   KC_F3, KC_F4,  KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL,
        _______, _______, _______, SS_FUL, SS_SEL, _______, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_PDOT, KC_PIPE,
        KC_LSFT, UNDO, CUT, COPY, PASTE, _______, _______, KC_NUHS, KC_NUBS, XXXXXXX, KC_PIPE, KC_ENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |QWERTY| M a0 | M a1 | M a2 | NULL | NULL | NULL | NULL | NULL | NULL | NULL | NULL |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | M b2 | M up | M b1 | M b2 | SAT+ | SAT- |BRGTH+|BRGTH-| CTog | CUp  | POWER|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | M lf | M dn | M rt |RGBMOD| HUE+ | HUE- | MMod | NULL | CRes | CDn  | NULL |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | NULL | NULL | NULL |AudOff|AGnorm|QWERTY| NULL |AGswap|Aud On| NULL |      |SysReq|
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | NULL | NULL | NULL | Reset|      |     NULL    |      | NULL | NULL |      | NULL |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT(
        QWERTY,   KC_ACL0,   KC_ACL1,   KC_ACL2,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX, KC_MS_BTN2, KC_MS_U, KC_MS_BTN1, KC_MS_BTN2, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, CK_TOGG, CK_UP, KC_PWR,
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, RGB_MOD, RGB_HUI, RGB_HUD, MU_MOD, XXXXXXX, CK_RST, CK_DOWN, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, AU_OFF, AG_NORM, QWERTY, XXXXXXX, AG_SWAP, AU_ON, XXXXXXX, XXXXXXX, KC_SYSREQ,
        XXXXXXX, XXXXXXX, XXXXXXX, RESET, _______, ITERM, ITERM, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /* FUNK
        * ,-----------------------------------------------------------------------------------.
        * |      |      |      |      |      |             |      |      |      |      |Insert|
        * |------+------+------+------+------+------+------+------+------+------+------+------|
        * |      | NULL | NULL | NULL | NULL |      |      |      |Insert| NULL |PrntSc| iTrm |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
        * |      | NULL | NULL | NULL |      |      |      |      | NULL | NULL |PlyMc1|PlyMc2|
        * |------+------+------+------+------+------+------+------+------+------+------+------|
        * |ONESHT| NULL | NULL | NULL |      |      |      |      |ZoomOu|ZoomIn|Zoom0 |RecStp|
        * |------+------+------+------+------+-------------+------+------+------+------+------|
        * |      | NULL | NULL |      | Vol- |     Mute    | Vol+ | Prev | Stop | Next | Play |
        * `-----------------------------------------------------------------------------------'
        */
    [_FUNK] = LAYOUT
    (
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, ITERM,
        LCTL(KC_TAB), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, _______, _______, ZOOM_OUT, ZOOM_IN, ZOOM_NML, DYN_REC_STOP,
        _______, XXXXXXX, XXXXXXX, _______, KC_VOLD, KC_MUTE, KC_MUTE, KC_VOLU, KC_MPRV, KC_MSTP, KC_MNXT, KC_MPLY
    ),


    /* SPACE FN
    * ,------------------------------------------------------------------------------------.
    * |       |      |   =  |   (  |   )  |  =   |   >  |   {   |   } |   ;  |      |      |
    * |-------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `   |   "  |   '  |   -  |   _  |  =   |   +  |   _  |   -  |   '  |   "  |  `   |
    * |-------+------+------+------+------+-------------+------+------+------+------+------|
    * |   |   |   /  |   <  |   [  |   {  |   (  |   )  |   }  |   ]  |   >  |   \  |  |   |
    * |-------+------+------+------+------+------|------+------+------+------+------+------|
    * |  NULL |   ;  |   ,  |   .  | NULL | NULL | NULL | NULL |   .  |   ,  |   ;  | NULL |
    * |-------+------+------+------+------+------+------+------+------+------+------+------|
    * |  NULL | NULL | NULL | NULL | NULL |             | NULL | NULL | NULL | NULL | NULL |
    * `-----------------------------------------------------------------------------------'
    */
    [_SPACEFN] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_EQL, KC_LPRN, KC_RPRN, KC_EQL, KC_GT, KC_LCBR, KC_RCBR, KC_SCLN, XXXXXXX, XXXXXXX,
        KC_GRV, KC_DQUO, KC_QUOT, KC_MINS, KC_UNDS, KC_EQL , KC_PLUS, KC_UNDS, KC_MINS, KC_QUOT, KC_DQUO, KC_GRV,
        KC_PIPE, KC_SLSH, KC_LT  , KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_GT  , KC_BSLS, KC_QUOT,
        XXXXXXX, KC_SCLN, KC_COMM, KC_PDOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PDOT, KC_COMM, KC_COMM, KC_SCLN, KC_PIPE,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

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

          case FUNK:
            if (record->event.pressed) {
                layer_on(_FUNK);
            } else {
                layer_off(_FUNK);
            }
            return false;
            break;

        case KC_CAPS:
		if (record->event.pressed) {

		}
		return true;
          break;
  }
  return true;
}
