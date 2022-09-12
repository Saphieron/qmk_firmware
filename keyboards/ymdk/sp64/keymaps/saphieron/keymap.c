// Copyright 2022 saphieron
// SPDX-License-Identifier: GPL-3.0-only
#include QMK_KEYBOARD_H

/* Layer transitions diagram
 *
 * BASE <-> _FN     [MO]
 * BASE <-> _NUM    [TG]
 * _NUM <-> _MIRROR [MO]
 *
 * Direct transitions between layers not listed here are considered bugs.
 */

enum layer_names {
    BASE,     // default layer
    _FN,      // function layer
    _NUM,     // numpad
    _MIRROR,  // mirrorboard layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,        KC_9,     KC_0,      KC_MINUS,    KC_EQUAL,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,     KC_P,      KC_LBRACKET, KC_RBRACKET, KC_BSLS,
    MO(1),   KC_A,    KC_S,    KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,     KC_SCOLON, KC_QUOTE,                 KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,   KC_SLSH,   KC_RSFT,     KC_UP,       KC_DEL,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,           MO(1),    KC_SPACE,           KC_RALT,     MO(2),               KC_LEFT,     KC_DOWN,  KC_RIGHT
),


[1] = LAYOUT(
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,
    KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_HOME, KC_UP,   KC_END,   KC_NO,    KC_NO,    KC_NO,   KC_NO,  
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,    KC_NO,             KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_PGUP,  KC_PGUP,  KC_NO,   KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,   KC_NO,            KC_NO,   KC_NO,              KC_NO,    KC_NO,   KC_NO
),

[2] = LAYOUT(
    TO(3),   _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,
    _______, _______, _______, _______,          _______, _______,           _______, _______,          KC_VOLD, KC_MUTE, KC_VOLU
  ),

[3] = LAYOUT(
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, TO(0),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    KC_LSFT, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______, _______, _______,
    TO(0),   _______, _______, _______,          _______, _______,          _______, _______,          _______, RESET,   _______
    ),
};

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
const rgblight_segment_t PROGMEM BASE_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_OFF});
const rgblight_segment_t PROGMEM _FN_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_RED});
const rgblight_segment_t PROGMEM _NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_YELLOW});
const rgblight_segment_t PROGMEM _MIRROR_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 12, HSV_ORANGE});

const rgblight_segment_t* const PROGMEM user_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    BASE_layer,
    _FN_layer,
    _NUM_layer,
    _MIRROR_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = user_rgb_layers;
}
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {

/* Add some indication for current function layer.
 *
 * N.B.: rgblight_set_layer_state calls rgblight_mode_noeeprom.
 */
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MIRROR));

    return state;
}
#endif
