#pragma once

#define MASTER_RIGHT // MASTER_LEFT Left side is the main (temp switch to troubleshoot LULU)
#define SPLIT_LAYER_STATE_ENABLE // Allows both sides to react to LAYER info
#define SPLIT_WPM_ENABLE // Allows both sides to react to WPM info (used to wake up oled)

/* Set Polling rate to 1000Hz */
#define USB_POLLING_INTERVAL_MS 1
//#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

/*
#ifdef SPLIT_KEYBOARD
#define EE_HANDS
endif // SPLIT_KEYBOARD
*/


#ifdef COMBO_ENABLE
#    define COMBO_COUNT 8
#    define COMBO_TERM 13
#endif

#ifdef UNICODE_KEY_LNX
#    define UNICODE_SELECTED_MODES UC_LNX
#    undef UNICODE_KEY_LNX
#    define UNICODE_KEY_LNX LCTL(LSFT(LALT(KC_U)))
#endif

#ifdef QMK_KEYS_PER_SCAN
#    undef QMK_KEYS_PER_SCAN
#    define QMK_KEYS_PER_SCAN 1
#endif // !QMK_KEYS_PER_SCAN

#ifndef LEADER_PER_KEY_TIMING
#    define LEADER_PER_KEY_TIMING
#    define LEADER_TIMEOUT 500
#endif

#ifndef NO_ACTION_ONESHOT
#    define ONESHOT_TAP_TOGGLE 3 /* Tapping this number of times holds the key until tapped once again. */
#    define ONESHOT_TIMEOUT 250  /* Time (in ms) before the one shot key is released */
#endif                           // NO ACTION_ONESHOT

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

#ifdef MOUSEKEY_ENABLE
#    undef MOUSEKEY_WHEEL_DELAY
#    define MOUSEKEY_WHEEL_DELAY 50
#    undef MOUSEKEY_WHEEL_INTERVAL
#    define MOUSEKEY_WHEEL_INTERVAL 30
#    undef MOUSEKEY_WHEEL_TIME_TO_MAX
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 4
#endif

#ifdef OLED_DRIVER_ENABLE
#    undef OLED_TIMEOUT
#    define OLED_TIMEOUT 30000
#    define SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef LEADER_ENABLE
#    undef LEADER_TIMEOUT
#    define LEADER_TIMEOUT 400
#    define LEADER_PER_KEY_TIMING
#endif

#ifdef RGB_MATRIX_ENABLE
// Configure RGB Matrix
#    define RGB_MATRIX_KEYPRESSES // enable keypress effects
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_DEFAULT_MODE ENABLE_RGB_MATRIX_RAINDROPS
#    define RGB_MATRIX_DEFAULT_HUE 14
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS*0.5
// Disable RGB Matrix effects (from lulu/config.h)
#   undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#   undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#   undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
//#   undef ENABLE_RGB_MATRIX_BREATHING
#   undef ENABLE_RGB_MATRIX_BAND_SAT
#   undef ENABLE_RGB_MATRIX_BAND_VAL
// Disable All The Things
#    define DISABLE_RGB_MATRIX_SOLID_COLOR
//#    define DISABLE_RGB_MATRIX_ALPHAS_MODS
#    define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#    define DISABLE_RGB_MATRIX_BREATHING
#    define DISABLE_RGB_MATRIX_BAND_SAT
#    define DISABLE_RGB_MATRIX_BAND_VAL
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#    define DISABLE_RGB_MATRIX_CYCLE_ALL
#    define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#    define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define DISABLE_RGB_MATRIX_DUAL_BEACON
#    define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#    define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#    define DISABLE_RGB_MATRIX_RAINDROPS
#    define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    define DISABLE_RGB_MATRIX_TYPING_HEATMAP
//#    define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#    define DISABLE_RGB_MATRIX_SPLASH
#    define DISABLE_RGB_MATRIX_MULTISPLASH
#    define DISABLE_RGB_MATRIX_SOLID_SPLASH
#    define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
// Enable RGB Matrix effects
#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define ENABLE_RGB_MATRIX_RAINDROPS
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_ALPHAS_MODS


#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 150
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
 // RGBLIGHT_ENABLE

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
//#define NO_USB_STARTUP_CHECK
