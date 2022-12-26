#include QMK_KEYBOARD_H

enum layers {
    _WINDOWS,
    _WINDOWS_SUP,
    _MAC,
    _LOCKED,
    _ADVANCED,
};

#define TO_WIN TO(_WINDOWS)
#define TO_MAC TO(_MAC)
#define TO_LOK TO(_LOCKED)
#define MO_WSP MO(_WINDOWS_SUP)
#define MO_ADV MO(_ADVANCED)
#define C_HOME LCTL(KC_HOME)
#define C_END LCTL(KC_END)

#define _WINDOWS_COLOR_RGB 195, 74, 0
#define _MAC_COLOR_RGB 71, 138, 0
#define _LOCKED_COLOR_RGB 123, 31, 162

#define _WHITE 255, 255, 255
#define _RED 250, 12, 12
#define _BLUE 12, 12, 250
#define _BLACK 0, 0, 0
#define _PINK 255, 153, 153

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WINDOWS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_WINDOWS_SUP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, C_HOME,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           KC_MPLY,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOCKED] = LAYOUT(
        RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          MO_ADV,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADVANCED] = LAYOUT(
        QK_BOOT, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_SLEP,          _______,
        _______, TO_WIN,  TO_MAC,  TO_LOK,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_VAD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};
// clang-format on

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    // return true; //set to return false to counteract enabled encoder in pro.c
    return false;
}

//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08                                                                                                                                                                      92, led 19

bool rgb_matrix_indicators_user(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case _WINDOWS:
        case _WINDOWS_SUP:
            rgb_matrix_set_color_all(_WINDOWS_COLOR_RGB);
            break;

        case _MAC:
            rgb_matrix_set_color_all(_MAC_COLOR_RGB);
            break;

        case _ADVANCED:
            rgb_matrix_set_color_all(_BLACK);

            // 1 key = WINDOWS layer
            rgb_matrix_set_color(7, _WINDOWS_COLOR_RGB);

            // 2 key = MAC layer
            rgb_matrix_set_color(13, _MAC_COLOR_RGB);

            // 3 key = LOCKED layer
            rgb_matrix_set_color(19, _LOCKED_COLOR_RGB);

            // fn key
            rgb_matrix_set_color(86, _BLUE);

            // esc key
            rgb_matrix_set_color(0, _RED);

            // printscreen key
            rgb_matrix_set_color(69, _PINK);

            // left side
            rgb_matrix_set_color(67, _BLUE);
            rgb_matrix_set_color(70, _BLUE);
            rgb_matrix_set_color(73, _BLUE);
            rgb_matrix_set_color(76, _BLUE);
            rgb_matrix_set_color(80, _BLUE);
            rgb_matrix_set_color(83, _BLUE);
            rgb_matrix_set_color(87, _BLUE);
            rgb_matrix_set_color(91, _BLUE);

            // right side
            rgb_matrix_set_color(68, _BLUE);
            rgb_matrix_set_color(71, _BLUE);
            rgb_matrix_set_color(74, _BLUE);
            rgb_matrix_set_color(77, _BLUE);
            rgb_matrix_set_color(81, _BLUE);
            rgb_matrix_set_color(84, _BLUE);
            rgb_matrix_set_color(88, _BLUE);
            rgb_matrix_set_color(92, _BLUE);
            break;

        default:
            break;
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, _WHITE);  // ESC
        rgb_matrix_set_color(6, _WHITE);  // F1
        rgb_matrix_set_color(12, _WHITE); // F2
        rgb_matrix_set_color(18, _WHITE); // F3
        rgb_matrix_set_color(23, _WHITE); // F4
        rgb_matrix_set_color(28, _WHITE); // F5
        rgb_matrix_set_color(34, _WHITE); // F6
        rgb_matrix_set_color(39, _WHITE); // F7
        rgb_matrix_set_color(44, _WHITE); // F8
        rgb_matrix_set_color(50, _WHITE); // F9
        rgb_matrix_set_color(56, _WHITE); // F10
        rgb_matrix_set_color(61, _WHITE); // F11
        rgb_matrix_set_color(66, _WHITE); // F12
        rgb_matrix_set_color(69, _WHITE); // Prt
        rgb_matrix_set_color(67, _WHITE); // Left side LED 1
        rgb_matrix_set_color(68, _WHITE); // Right side LED 1
        rgb_matrix_set_color(70, _WHITE); // Left side LED 2
        rgb_matrix_set_color(71, _WHITE); // Right side LED 2
        rgb_matrix_set_color(73, _WHITE); // Left side LED 3
        rgb_matrix_set_color(74, _WHITE); // Right side LED 3
        rgb_matrix_set_color(76, _WHITE); // Left side LED 4
        rgb_matrix_set_color(77, _WHITE); // Right side LED 4
        rgb_matrix_set_color(80, _WHITE); // Left side LED 5
        rgb_matrix_set_color(81, _WHITE); // Right side LED 5
        rgb_matrix_set_color(83, _WHITE); // Left side LED 6
        rgb_matrix_set_color(84, _WHITE); // Right side LED 6
        rgb_matrix_set_color(87, _WHITE); // Left side LED 7
        rgb_matrix_set_color(88, _WHITE); // Right side LED 7
        rgb_matrix_set_color(91, _WHITE); // Left side LED 8
        rgb_matrix_set_color(92, _WHITE); // Right side LED 8
        rgb_matrix_set_color(3, _WHITE);  // CAPS LED
    }

    return false;
}
