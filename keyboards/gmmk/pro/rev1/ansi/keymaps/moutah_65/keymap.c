/**
 * GMMK PRO
 * Moutah 65
 *
 * Based on a 65% layout but for GGMK Pro which is a 75%.
 * Synced with keychron\q2\ansi_encoder\keymaps\moutah_65. Has much brighter RGB values as the leds and keycaps make it dimmer.
 */

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
#define C_SLSH LCTL(KC_SLSH)
#define T_CTLF4 LCTL_T(KC_F4)

#define _WHITE 255, 255, 255
// orange
#define _PRIMARY_COLOR 195, 74, 0
// green
#define _SECONDARY_COLOR 71, 138, 0
// purple
#define _LOCKED_COLOR 153, 16, 212
// dim orangish white
#define _ADVANCED_BACKGROUND_COLOR 51, 50, 45
// deep red
#define _BOOTLOADER_COLOR 255, 12, 12
// deep green
#define _SLEEP_COLOR 12, 255, 12
// pink
#define _RGB_FUNCTION_COLOR 128, 51, 51
// electric blue
#define _FN_KEYS_COLOR 0, 113, 178

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_WINDOWS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           KC_MPLY,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_CALC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        QK_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_WINDOWS_SUP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,           KC_MPLY,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        QK_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        T_CTLF4, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOCKED] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          MO_ADV,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADVANCED] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_SLEP,          _______,
        _______, _______, TO_WIN,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_SAI, _______, _______, _______, RGB_HUI, _______, _______, RGB_VAI, _______, _______,          _______,          _______,
        _______,          _______, RGB_SAD, _______, _______, _______, RGB_HUD, TO_MAC,  _______, RGB_VAD, _______,          _______, RGB_SPI, _______,
        TO_LOK,  _______, _______,                            _______,                            _______, _______, _______, RGB_RMOD,RGB_SPD, RGB_MOD
    ),

};
// clang-format on

// *** Rotary encoder

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    // return true; //set to return false to counteract enabled encoder in pro.c
    return false;
}

// *** Custom keys

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {

        case KC_ESC:
            {
                // Initialize a boolean variable that keeps track
                // of the delete key status: registered or not?
                static bool grvkey_registered;

                if (record->event.pressed) {

                    // SHIFT + Esc
                    if (mod_state & MOD_MASK_SHIFT) {
                        // First temporarily canceling both shifts so that
                        // shift isn't applied to the KC_GRV keycode
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_GRV);
                        // Update the boolean variable to reflect the status of KC_GRV
                        grvkey_registered = true;
                        // Reapplying modifier state so that the held shift key(s)
                        // still work even after having tapped the Backspace/Delete key.
                        set_mods(mod_state);
                        return false;
                    }

                } else { // on release of KC_ESC
                    // In case KC_GRV is still being sent even after the release of KC_ESC
                    if (grvkey_registered) {
                        unregister_code(KC_GRV);
                        grvkey_registered = false;
                        return false;
                    }
                }

                return true;
            }
    }

    // WINDOWS specific macros
    uint8_t current_layer = get_highest_layer(layer_state);
    if (current_layer == _WINDOWS) {
        if (record->event.pressed) {
            switch (keycode) {

                case KC_LEFT:
                    {
                        if (mod_state & MOD_MASK_GUI) {

                            // WIN + ALT + Left -> WIN + Left
                            if (mod_state & MOD_MASK_ALT) {
                                del_mods(MOD_MASK_ALT);
                                tap_code(KC_LEFT);
                                set_mods(mod_state);
                                return false;
                            }

                            // WIN + Left -> WIN + CTRL + LEFT
                            else {
                                add_mods(MOD_MASK_CTRL);
                                tap_code(KC_LEFT);
                                set_mods(mod_state);
                                return false;
                            }

                        }
                    }

                case KC_RIGHT:
                    {
                        if (mod_state & MOD_MASK_GUI) {

                            // WIN + ALT + Right -> WIN + Right
                            if (mod_state & MOD_MASK_ALT) {
                                del_mods(MOD_MASK_ALT);
                                tap_code(KC_RIGHT);
                                set_mods(mod_state);
                                return false;
                            }

                            // WIN + Right -> WIN + CTRL + Right
                            else {
                                add_mods(MOD_MASK_CTRL);
                                tap_code(KC_RIGHT);
                                set_mods(mod_state);
                                return false;
                            }

                        }
                    }

                case KC_UP:
                    {
                        // WIN + Up -> WIN + Tab
                        if (mod_state & MOD_MASK_GUI) {
                            tap_code(KC_TAB);
                            return false;
                        }
                    }

                case KC_ENT:
                    {
                        // WIN + ALT + Enter -> WIN + Up
                        if (mod_state & MOD_MASK_GUI) {
                            if (mod_state & MOD_MASK_ALT) {
                                del_mods(MOD_MASK_ALT);
                                tap_code(KC_UP);
                                set_mods(mod_state);
                                return false;
                            }
                        }
                    }

            }
        }
    }

    // Let QMK process the keycode as usual
    return true;
};

// *** Lead key

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // c -> markdown code block
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING("``````" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) "\n\n" SS_TAP(X_LEFT));
        }

        // 5 -> start phpstorm process
        SEQ_ONE_KEY(KC_5) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_F5) SS_UP(X_LCTL));
        }

        // 5, 5 -> stops phpstorm process
        SEQ_TWO_KEYS(KC_5, KC_5) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_F5) SS_UP(X_LSFT));
        }

        // n -> ~
        SEQ_ONE_KEY(KC_N) {
            SEND_STRING("~ ");
        }

        // caps lock
        SEQ_ONE_KEY(KC_LEAD) {
            tap_code(KC_CAPS);
        }
    }
}

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

    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case _WINDOWS:
        case _WINDOWS_SUP:
            rgb_matrix_set_color_all(_PRIMARY_COLOR);
            break;

        case _MAC:
            rgb_matrix_set_color_all(_SECONDARY_COLOR);
            break;

        case _ADVANCED:
            rgb_matrix_set_color_all(_ADVANCED_BACKGROUND_COLOR);

            // layers
            rgb_matrix_set_color(14, _PRIMARY_COLOR);
            rgb_matrix_set_color(43, _SECONDARY_COLOR);
            rgb_matrix_set_color(5, _LOCKED_COLOR);

            // fn keys
            rgb_matrix_set_color(7, _FN_KEYS_COLOR);
            rgb_matrix_set_color(13, _FN_KEYS_COLOR);
            rgb_matrix_set_color(19, _FN_KEYS_COLOR);
            rgb_matrix_set_color(24, _FN_KEYS_COLOR);
            rgb_matrix_set_color(29, _FN_KEYS_COLOR);
            rgb_matrix_set_color(35, _FN_KEYS_COLOR);
            rgb_matrix_set_color(40, _FN_KEYS_COLOR);
            rgb_matrix_set_color(45, _FN_KEYS_COLOR);
            rgb_matrix_set_color(51, _FN_KEYS_COLOR);
            rgb_matrix_set_color(57, _FN_KEYS_COLOR);
            rgb_matrix_set_color(62, _FN_KEYS_COLOR);
            rgb_matrix_set_color(78, _FN_KEYS_COLOR);

            // rgb functions
            rgb_matrix_set_color(15, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(37, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(53, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(94, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(95, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(97, _RGB_FUNCTION_COLOR);
            rgb_matrix_set_color(79, _RGB_FUNCTION_COLOR);

            // bootloader
            rgb_matrix_set_color(1, _BOOTLOADER_COLOR);

            // sleep
            rgb_matrix_set_color(85, _SLEEP_COLOR);
            break;

        default:
            break;
    }

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(72, _WHITE); // Home
        rgb_matrix_set_color(75, _WHITE); // PgUp
        rgb_matrix_set_color(86, _WHITE); // PgDn
        rgb_matrix_set_color(82, _WHITE); // End

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
