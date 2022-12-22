


// 32X128 / Vertical / plain bytes / must be rotated 270' / 8 lines for each 32 vertical pixels

void render_layer1_logo_key(void){
    static const char PROGMEM layer_logo[] = {
// 'keeb-oled-anims_01', 32x128px
0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x0a, 0x0a, 0x0a, 0x3e, 0x00, 0x3e, 0x2a,
0x2a, 0x2a, 0x1e, 0x00, 0x1c, 0x22, 0x22, 0x22, 0x14, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00,
0x00, 0x00, 0xfe, 0x21, 0x42, 0xf4, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf4, 0x42, 0x21, 0xfe, 0x00, 0x00,
0x00, 0x00, 0x0f, 0x10, 0x20, 0x3f, 0x20, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x40, 0x20, 0x3f, 0x20, 0x10, 0x0f, 0x00, 0x00,
  };
  oled_write_raw_P(layer_logo, sizeof(layer_logo));
}

void render_layer2_logo_key(void){
    static const char PROGMEM layer_logo[] = {
// 'keeb-oled-anims_02', 32x128px
0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xfc,
0xfc, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00,
0x00, 0x00, 0xfc, 0x43, 0x84, 0xe8, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x11, 0x13,
0x13, 0x11, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xe8, 0x84, 0x43, 0xfc, 0x00, 0x00,
0x00, 0x00, 0x0f, 0x10, 0x20, 0x3f, 0x21, 0x41, 0x41, 0x41, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,
0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x41, 0x41, 0x41, 0x21, 0x3f, 0x20, 0x10, 0x0f, 0x00, 0x00,
    };
    oled_write_raw_P(layer_logo, sizeof(layer_logo));
}

void render_layer3_logo_key(void){
    static const char PROGMEM layer_logo[] = {
// 'keeb-oled-anims_03', 32x128px
0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xe0, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1c, 0xfe,
0xfe, 0x1c, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00,
0x00, 0x00, 0xf8, 0x87, 0x08, 0xd0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21,
0x21, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xd0, 0x08, 0x87, 0xf8, 0x00, 0x00,
0x00, 0x00, 0x0f, 0x10, 0x21, 0x3f, 0x22, 0x42, 0x42, 0x42, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82,
0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x42, 0x42, 0x42, 0x22, 0x3f, 0x21, 0x10, 0x0f, 0x00, 0x00,
    };
    oled_write_raw_P(layer_logo, sizeof(layer_logo));
}

void render_layer4_logo_key(void){
    static const char PROGMEM layer_logo[] = {
// 'keeb-oled-anims_04', 32x128px
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x04, 0x00, 0x00, 0x80, 0x78, 0x8e,
0x8e, 0x78, 0x80, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00,
0x00, 0x00, 0xf0, 0x0f, 0x10, 0xa0, 0x40, 0x40, 0x42, 0x40, 0x40, 0x40, 0x4f, 0x47, 0x42, 0x6f,
0x57, 0x42, 0x47, 0x4f, 0x40, 0x40, 0x60, 0x40, 0x40, 0x40, 0xa0, 0x10, 0x0f, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x0f, 0x11, 0x22, 0x3f, 0x24, 0x44, 0x44, 0x44, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84,
0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x44, 0x44, 0x44, 0x24, 0x3f, 0x22, 0x11, 0x0f, 0x00, 0x00,
    };
    oled_write_raw_P(layer_logo, sizeof(layer_logo));
}
