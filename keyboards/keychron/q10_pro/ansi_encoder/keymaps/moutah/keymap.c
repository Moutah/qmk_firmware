/**
 * Keychron Q10 Pro
 * Moutah
 *
 * Synced with keychron\q11\ansi_encoder\keymaps\moutah.
 */

#include QMK_KEYBOARD_H
#include "moutah.h"

// blue
#define _COLOR_WINDOWS 18, 38, 33
// apple green
#define _COLOR_MAC 12, 24, 9
// dim blueish black
#define _COLOR_ADVANCED_BACKGROUND 2, 2, 3
// deep red
#define _COLOR_BOOTLOADER 255, 12, 12
// deep green
#define _COLOR_SLEEP 12, 255, 12
// pink
#define _COLOR_QUICK_LAUNCH 235, 50, 96
// yellow
#define _COLOR_MEDIA 220, 200, 4

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // mac
    [_LAYER_MAIN] = LAYOUT_90_ansi(
        KC_MPLY,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   HYPR_F13,           TO_LOCK,
        HYPR_F1,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        HYPR_F2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,
        HYPR_F3,    OS_CMD,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        HYPR_F4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        HYPR_F5,    T_CTLF4,  KC_LALT,            KC_LGUI,  KC_SPC,   _______,             KC_SPC,             KC_RALT,            KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    // windows
    [_LAYER_SECONDARY] = LAYOUT_90_ansi(
        KC_MPLY,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   HYPR_F13,           TO_LOCK,
        HYPR_F1,    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_HOME,
        HYPR_F2,    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_DEL,
        HYPR_F3,    OS_CMD,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        HYPR_F4,    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        HYPR_F5,    KC_LGUI,  KC_LALT,            KC_LCTL,  KC_SPC,   _______,             KC_SPC,             KC_RCTL,            KC_RGUI,            KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

//    [_LAYER_WINDOWS_SUP] = LAYOUT_90_ansi(
//        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
//        _______,    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  W_L,      _______,  _______,            _______,            _______,
//        _______,    _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  C_SLSH,   _______,  C_HOME,
//        _______,    _______,  _______,            _______,  _______,  _______   ,          _______,            _______,            _______,            KC_HOME,  C_END,    KC_END
//    ),

    [_LAYER_COMMANDS] = LAYOUT_90_ansi(
        RGB_TOG,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  RGB_MOD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   QK_BOOT,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  HYPR_1,   HYPR_2,   HYPR_3,   HYPR_4,   HYPR_5,    HYPR_6,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  TO_SEC,   XXXXXXX,  _K_RGB,   _K_MDTB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  _K_MDA,   XXXXXXX,  XXXXXXX,  _K_AFN,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,            XXXXXXX,
        XXXXXXX,    KC_CAPS,            XXXXXXX,  XXXXXXX,  _K_MDC,   XXXXXXX,   _K_MDC2,  XXXXXXX,  XXXXXXX,  TO_MAIN,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_CAPS,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  KC_SLEP,  XXXXXXX,             KC_SLEP,            XXXXXXX,            XXXXXXX,             KC_MPRV,  XXXXXXX,  KC_MNXT
    ),

    [_LAYER_LOCKED] = LAYOUT_90_ansi(
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  RGB_MOD,            TO_MAIN,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,            XXXXXXX,
        XXXXXXX,    XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,             XXXXXXX,            XXXXXXX,            XXXXXXX,             XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
};
// clang-format on

// *** Rotary encoder

// set to return false to counteract enabled encoder in pro.c
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mod_state = get_mods();
    int hsvDeltaValue = 4 * (clockwise ? 1 : -1);

    if (mod_state & MOD_MASK_ALT) {
        updateHSVBy(0, hsvDeltaValue, 0);
        return false;
    }

    if (mod_state & MOD_MASK_CTRL) {
        updateHSVBy(0, 0, hsvDeltaValue);
        return false;
    }

    if (mod_state & MOD_MASK_SHIFT) {
        updateHSVBy(hsvDeltaValue, 0, 0);
        return false;
    }

    turnVolume(clockwise);
    return false;
}

// *** Metrics

void keyboard_post_init_user(void) {
    load_user_data();
}

// *** Custom keys

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        record_key_pressed();
    }

    uint8_t mod_state     = get_mods();
    uint8_t current_layer = get_highest_layer(layer_state);

    return handle_custom_keys(keycode, record, mod_state, current_layer, _FOR_MAC);
};

// *** RGB

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {

    // no rgb
    if (rgb_state == _RGB_STATE_OFF) {
        rgb_matrix_set_color_all(_COLOR_OFF);
        return false;
    }

    // custom layer rgb
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _LAYER_COMMANDS:
            rgb_matrix_set_color_all(_COLOR_ADVANCED_BACKGROUND);

            // f7 : rgb
            rgb_matrix_set_color(7, _COLOR_WHITE);

            // f12 : bootloader
            rgb_matrix_set_color(12, _COLOR_BOOTLOADER);

            // 1, 2, 3, 4, 5, 6 : quick launch
            rgb_matrix_set_color(17, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(18, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(19, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(20, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(21, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(22, _COLOR_QUICK_LAUNCH);

            // w, m : layers
            rgb_matrix_set_color(34, _COLOR_WINDOWS);
            rgb_matrix_set_color(71, _COLOR_MAC);

            // r : output rgb value
            rgb_matrix_set_color(36, _COLOR_WHITE);

            // t : | ---
            rgb_matrix_set_color(37, _COLOR_WHITE);

            // a : []()
            rgb_matrix_set_color(49, _COLOR_WHITE);

            // f : () => {}
            rgb_matrix_set_color(52, _COLOR_WHITE);

            // l & r shift : caps lock
            rgb_matrix_set_color(63, _COLOR_WHITE);
            rgb_matrix_set_color(75, _COLOR_WHITE);

            // c : ```\n\n ```
            rgb_matrix_set_color(66, _COLOR_WHITE);

            // b : ```\n\n
            rgb_matrix_set_color(68, _COLOR_WHITE);
            rgb_matrix_set_color(69, _COLOR_WHITE);

            // r & l space : sleep
            rgb_matrix_set_color(81, _COLOR_SLEEP);
            rgb_matrix_set_color(83, _COLOR_SLEEP);

            // left & right : next / prev media
            rgb_matrix_set_color(86, _COLOR_MEDIA);
            rgb_matrix_set_color(88, _COLOR_MEDIA);
            break;

        case _LAYER_MAIN:
            // layer indicator
            rgb_matrix_set_color(14, _COLOR_MAC);
            break;

        case _LAYER_SECONDARY:
            // layer indicator
            rgb_matrix_set_color(14, _COLOR_WINDOWS);
            break;

        case _LAYER_LOCKED:
            // layer indicator
            rgb_matrix_set_color(14, _COLOR_OFF);
            break;

        default:
            break;
    }


    // caps lock
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(14, _COLOR_WHITE);
    }

    return true;
}
#endif

