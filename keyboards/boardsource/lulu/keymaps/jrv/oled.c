#include <stdio.h>
#include "oled.h"

// Set Rotations
#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_270;
  return rotation;
}
#endif

// Reactive Layer Display
//#include "oledart-default-layers.c" // default gearshift layer logos
#include "oledart-jrv-zninit1-anim.c" // WIP JRV zninit animation 1
#include "oledart-jrv-key-layers.c" // WIP JRV keycap layer logos
void render_layer_logo(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            render_layer1_logo_key();
            break;
        case 1:
            render_layer2_logo_key();
            break;
        case 2:
            render_layer3_logo_key();
            break;
        case 3:
            render_layer4_logo_key();
            break;
        case 4:
            render_layer5_logo_key();
            break;
    }
}

// Layer Printing
// Check layer state and print (refactor to switch)
void render_layer_name(void) {
    bool lower = layer_state_is(_LOWER) & !layer_state_is(_ADJUST);
    bool raise = layer_state_is(_RAISE) & !layer_state_is(_ADJUST);
    bool adjust = layer_state_is(_ADJUST);
    bool space = layer_state_is(_SPACEFN);
    if(lower){
        oled_write("LOWER\n", false);
    } else if(raise){
        oled_write("RAISE\n", false);
    } else if(adjust){
        oled_write(" ADJ \n", false);
    } else if(space){
        oled_write("SPACE\n", false);
    } else {
        oled_write("     \n", false);
    }
}

// BongoCat Animation
#include "oledart-bongocat-anim.c"

char rgb_str[10];
void oled_render_rgb_mode(void) {
    oled_write_P(PSTR("-----"), false);
    sprintf(rgb_str, "RGB %s", get_u8_str(rgb_matrix_get_mode(), ' '));
    oled_write_ln(rgb_str, false);
    oled_write_P(PSTR("-----\n"), false);
}

char lay_str[10];
void oled_render_layer(void) {
    oled_write_P(PSTR("-----"), false);
    sprintf(lay_str, "LAY %s", get_u8_str(get_highest_layer(layer_state), ' '));
    oled_write_ln(lay_str, false);
    oled_write_P(PSTR("-----\n"), false);
}

// OLED screen update
bool oled_task_user(void) {
    if (is_keyboard_master()) {

        // Everyone loves Bongo Cat
        render_bongocat_anim();

    } else {

        // Text Readouts
        render_layer_name();
        // oled_render_rgb_mode();
        oled_render_layer();

        // Layer Logo
        render_layer_logo();
        // Move cursor below the logo render
        oled_set_cursor(0,12);
        // Gratuitous Animation
        render_zninit1_anim();
    }
    return false;
}
