#include "encoder.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            if(layer_state_is(_SPACEFN)){
                rgblight_step();
            } else if(layer_state_is(_RAISE)){
                rgblight_increase_hue();
             } else if(layer_state_is(_LOWER)){
                rgblight_decrease_val();
            } else {
                tap_code(KC_VOLU);
            }

        } else {
             if(layer_state_is(_SPACEFN)){
                 rgblight_step_reverse();
              } else if(layer_state_is(_RAISE)){
                rgblight_decrease_hue();
            } else if(layer_state_is(_LOWER)){
                rgblight_increase_val();
            } else {
                 tap_code(KC_VOLD);
             }
        }
    } else if (index == 1) {

         if (clockwise) {
            if(layer_state_is(_SPACEFN)){
                rgblight_increase_hue();
            } else {
                tap_code(KC_WH_D);
            }

        } else {
             if(layer_state_is(_SPACEFN)){
                 rgblight_decrease_hue();
             } else {
                 tap_code(KC_WH_U);
             }
        }

    }
    return true;
}
#endif
