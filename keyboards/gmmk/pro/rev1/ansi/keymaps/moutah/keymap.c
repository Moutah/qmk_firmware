/**
 * GMMK PRO
 * Moutah
 *
 * Synced with keychron\q11\ansi_encoder\keymaps\moutah. Has much brighter RGB values as the leds and keycaps make it dimmer.
 */

#include QMK_KEYBOARD_H
#include "moutah.h"

// blue
#define _COLOR_WINDOWS 72, 72, 255
// teal
#define _COLOR_MAC 0, 172, 42
// dim blueish black
#define _COLOR_ADVANCED 32, 32, 255
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

    // windows
    [_LAYER_MAIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HYPR_F13,         KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_CMD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // mac
    [_LAYER_SECONDARY] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HYPR_F13,         KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_CMD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        T_CTLF4, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_WINDOWS_SUP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, W_L,     _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_LAYER_COMMANDS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, TO_LOK,           RGB_TOG,
        XXXXXXX, HYPR_1,  HYPR_2,  HYPR_3,  HYPR_4,  HYPR_5,  HYPR_6,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, TO_MAIN, XXXXXXX, _K_RGB,  _K_MDTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          _K_MX_C,
        XXXXXXX, _K_MDA,  XXXXXXX, XXXXXXX, _K_AFN,  XXXXXXX, XXXXXXX, XXXXXXX, _K_MX_O, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        KC_CAPS,          XXXXXXX, XXXXXXX, _K_MDC,  XXXXXXX, _K_MDC2, XXXXXXX, TO_SEC,  XXXXXXX, XXXXXXX, XXXXXXX,          KC_CAPS, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            KC_SLEP,                            XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, XXXXXXX, KC_MNXT
    ),

    [_LAYER_LOCK] = LAYOUT(
        TO_MAIN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        OS_CMD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_RSFT, XXXXXXX, XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL,                            XXXXXXX,                            MO_WSP,  KC_RCTL, KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
    ),

};
// clang-format on

// *** Rotary encoder

// set to return false to counteract enabled encoder in pro.c
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mod_state = get_mods();

    int hsvDeltaValue = 4 * (clockwise ? 1 : -1);

    if (mod_state & MOD_MASK_SHIFT) {
        updateHSVBy(hsvDeltaValue, 0, 0);
        return false;
    }

    if (mod_state & MOD_MASK_ALT) {
        updateHSVBy(0, hsvDeltaValue, 0);
        return false;
    }

    if (mod_state & MOD_MASK_CTRL) {
        updateHSVBy(0, 0, hsvDeltaValue);
        return false;
    }

    if (mod_state & MOD_MASK_GUI) {
        updateRGBSpeed(clockwise);
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

    return handle_custom_keys(keycode, record, mod_state, current_layer, _FOR_WINDOWS);
};

// *** RGB

bool rgb_matrix_indicators_user(void) {
    //  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
    //  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
    //  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
    //  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
    //  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
    //  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
    //  87, led 07                                                                                                                                                                      88, led 18
    //  91, led 08                                                                                                                                                                      92, led 19

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
            rgb_matrix_set_color(69, _COLOR_ADVANCED);

            // f9 : rgb
            rgb_matrix_set_color(50, _COLOR_WHITE);

            // \ : bootloader
            rgb_matrix_set_color(93, _COLOR_BOOTLOADER);

            // 1, 2, 3, 4, 5, 6 : quick launch
            rgb_matrix_set_color(7, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(13, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(19, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(24, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(29, _COLOR_QUICK_LAUNCH);
            rgb_matrix_set_color(35, _COLOR_QUICK_LAUNCH);

            // w, m : layers
            rgb_matrix_set_color(14, _COLOR_WINDOWS);
            rgb_matrix_set_color(43, _COLOR_MAC);

            // r : output rgb value
            rgb_matrix_set_color(25, _COLOR_WHITE);

            // t : | ---
            rgb_matrix_set_color(30, _COLOR_WHITE);

            // a : []()
            rgb_matrix_set_color(9, _COLOR_WHITE);

            // f : () => {}
            rgb_matrix_set_color(26, _COLOR_WHITE);

            // l & r shift : caps lock
            rgb_matrix_set_color(4, _COLOR_WHITE);
            rgb_matrix_set_color(90, _COLOR_WHITE);

            // c : ```\n\n ```
            rgb_matrix_set_color(2, _COLOR_WHITE);

            // b : ```\n\n
            rgb_matrix_set_color(32, _COLOR_WHITE);

            // space : sleep
            rgb_matrix_set_color(33, _COLOR_SLEEP);

            // left & right : next / prev media
            rgb_matrix_set_color(95, _COLOR_MEDIA);
            rgb_matrix_set_color(79, _COLOR_MEDIA);
            break;

        case _LAYER_MAIN:
            // layer indicator
            rgb_matrix_set_color(69, _COLOR_WINDOWS);
            break;

        case _LAYER_SECONDARY:
            // layer indicator
            rgb_matrix_set_color(69, _COLOR_MAC);
            break;

        case _LAYER_LOCK:
            // layer indicator
            rgb_matrix_set_color(69, _COLOR_OFF);
            break;

        default:
            break;
    }

    // caps lock
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(69, _COLOR_WHITE);

        rgb_matrix_set_color(67, _COLOR_WHITE); // Left side LED 1
        rgb_matrix_set_color(68, _COLOR_WHITE); // Right side LED 1
        rgb_matrix_set_color(70, _COLOR_WHITE); // Left side LED 2
        rgb_matrix_set_color(71, _COLOR_WHITE); // Right side LED 2
        rgb_matrix_set_color(73, _COLOR_WHITE); // Left side LED 3
        rgb_matrix_set_color(74, _COLOR_WHITE); // Right side LED 3
        rgb_matrix_set_color(76, _COLOR_WHITE); // Left side LED 4
        rgb_matrix_set_color(77, _COLOR_WHITE); // Right side LED 4
        rgb_matrix_set_color(80, _COLOR_WHITE); // Left side LED 5
        rgb_matrix_set_color(81, _COLOR_WHITE); // Right side LED 5
        rgb_matrix_set_color(83, _COLOR_WHITE); // Left side LED 6
        rgb_matrix_set_color(84, _COLOR_WHITE); // Right side LED 6
        rgb_matrix_set_color(87, _COLOR_WHITE); // Left side LED 7
        rgb_matrix_set_color(88, _COLOR_WHITE); // Right side LED 7
        rgb_matrix_set_color(91, _COLOR_WHITE); // Left side LED 8
        rgb_matrix_set_color(92, _COLOR_WHITE); // Right side LED 8
    }

    return false;
}
