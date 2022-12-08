#include <stdio.h>
#include "layers.h"
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
#include "oledart-jrv-key-layers.c" // WIP JRV keycap layer logos

//#include "oledart-jrv-zninit1-anim.c" // WIP JRV zninit animation 1

void render_layer_logo(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            render_layer1_logo();
            break;
        case 1:
            render_layer2_logo();
            break;
        case 2:
            render_layer3_logo();
            break;
        case 3:
            render_layer4_logo();
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



// OLED screen update
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_bongocat_anim();
        //oled_set_cursor(0, 0);
        //render_layer_name();
    } else {

        oled_set_cursor(0,0);
        render_layer_name();
        render_layer_logo();
      //  render_zninit1_anim();
    }
    return false;
}
