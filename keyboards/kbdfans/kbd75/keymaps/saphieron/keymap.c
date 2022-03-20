#include QMK_KEYBOARD_H

#define _______ KC_TRNS

#define RGBMODE_SOLID 1

#define KC_LEQ KC_NONUS_BSLASH
#define FUNC_GRAVE_ESC 0

enum custom_keycodes {
    STRM_START = SAFE_RANGE,
    STRM_STOP,
    RCRD_START,
    RCRD_STOP,
    MIC_MUTE,
    DESK_MUTE,
    CAPTURE_WIN,
    SCENE_START,
    SCENE_GAME,
    SCENE_LOBBY,
    SCENE_END,
};

static inline void handleSTRM_START(uint16_t keycode, keyrecord_t *record);
static inline void handleSTRM_STOP(uint16_t keycode, keyrecord_t *record);
static inline void handleRCRD_START(uint16_t keycode, keyrecord_t *record);
static inline void handleRCRD_STOP(uint16_t keycode, keyrecord_t *record);
static inline void handleMIC_MUTE(uint16_t keycode, keyrecord_t *record);
static inline void handleDESK_MUTE(uint16_t keycode, keyrecord_t *record);
static inline void handleCAPTURE_WIN(uint16_t keycode, keyrecord_t *record);
static inline void handleSCENE_START(uint16_t keycode, keyrecord_t *record);
static inline void handleSCENE_GAME(uint16_t keycode, keyrecord_t *record);
static inline void handleSCENE_LOBBY(uint16_t keycode, keyrecord_t *record);
static inline void handleSCENE_END(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case STRM_START:
        handleSTRM_START(keycode, record);
        break;
    case STRM_STOP:
        handleSTRM_STOP(keycode, record);
        break;
    case RCRD_START:
        handleRCRD_START(keycode, record);
        break;
    case RCRD_STOP:
        handleRCRD_STOP(keycode, record);
        break;
    case MIC_MUTE:
        handleMIC_MUTE(keycode, record);
        break;
    case DESK_MUTE:
        handleDESK_MUTE(keycode, record);
        break;
    case CAPTURE_WIN:
        handleCAPTURE_WIN(keycode, record);
        break;
    case SCENE_START:
        handleSCENE_START(keycode, record);
        break;
    case SCENE_GAME:
        handleSCENE_GAME(keycode, record);
        break;
    case SCENE_LOBBY:
        handleSCENE_LOBBY(keycode, record);
        break;
    case SCENE_END:
        handleSCENE_END(keycode, record);
        break;
    }
    return true;
};

static inline void handleSTRM_START(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F10))));
    } else {
    }
}

static inline void handleSTRM_STOP(uint16_t keycode, keyrecord_t *record){
    //
}

static inline void handleRCRD_START(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F11))));
    } else {
    }
}

static inline void handleRCRD_STOP(uint16_t keycode, keyrecord_t *record){
//
}

static inline void handleMIC_MUTE(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_KP_SLASH))));
    } else {
    }
}

static inline void handleDESK_MUTE(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_KP_ASTERISK))));
    } else {
    }
}

static inline void handleCAPTURE_WIN(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_TAP(X_EQUAL)));
    } else {
    }
}

static inline void handleSCENE_START(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F6))));
    } else {
    }
}

static inline void handleSCENE_GAME(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F7))));
    } else {
    }
}

static inline void handleSCENE_LOBBY(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F8))));
    } else {
    }
}

static inline void handleSCENE_END(uint16_t keycode, keyrecord_t *record){
    if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_F9))));
    } else {
    }
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_VOLD,   KC_VOLU,
    KC_GESC  ,KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_NO,   KC_BSPC,   KC_MUTE,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_NO,
    MO(1),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_NO,
    KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_NO,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  KC_RGUI,  MO(2),    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_INS,
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_DEL,   KC_PSCR,
    KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_HOME,  KC_UP,    KC_END,   KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,    KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_NO,    KC_PGUP,  KC_PGDN,  KC_NO,              KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(5),    KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(3),
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT
  ),

  [3] = LAYOUT(
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, CAPTURE_WIN, SCENE_START,SCENE_GAME,SCENE_LOBBY,SCENE_END, KC_NO, KC_NO, KC_NO,    KC_VOLD,  KC_VOLU,
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  MIC_MUTE,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            DESK_MUTE,
    MO(4),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_NO,
    KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_NO,
    KC_LCTL,  KC_LGUI,  KC_LALT,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RALT,  KC_RGUI,  MO(4),    KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [4] = LAYOUT(
    STRM_STOP,STRM_START,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    TO(0),
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_DEL,   KC_NO,
    KC_CAPS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_HOME,  KC_UP,    KC_END,   KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_NO,    KC_TRNS,                      KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,    KC_PGUP,  KC_PGDN,  KC_NO,    KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT
  ),


  [5] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  TO(0),
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,    _______,
    _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    KC_LSFT,  _______,  _______,  _______,  BL_DEC,   BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
};

// enum function_id {
//     SHIFT_ESC, SHIFT_RSHIFT, SHIFT_DEL
// };

// const uint16_t PROGMEM fn_actions[] = {
// 	[0] = ACTION_FUNCTION(SHIFT_ESC), //[1] = ACTION_FUNCTION(SHIFT_RSHIFT), [2] = ACTION_FUNCTION(SHIFT_DEL),
// };


const rgblight_segment_t PROGMEM my_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_caps_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_TEAL}
);
const rgblight_segment_t PROGMEM my_selector_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_stream_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_RED}
);
const rgblight_segment_t PROGMEM my_stream_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_CORAL}
);
const rgblight_segment_t PROGMEM my_reset_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_WHITE}
);
const rgblight_segment_t PROGMEM my_other_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_default_layer,
    my_caps_default_layer,
    my_selector_layer,
    my_stream_layer,
    my_stream_caps_layer,
    my_reset_layer,
    my_other_layer
);

extern rgblight_config_t rgblight_config;
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_config.hue    = 191;
    rgblight_config.sat    = 255;
    rgblight_config.val    = 255;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    return state;
}
