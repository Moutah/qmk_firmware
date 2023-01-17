/**
 * Keychron Q2
 * Moutah 65
 *
 * Synced with gmmk\pro\rev1\ansi\keymaps\moutah_65. Has much darker RGB values as the leds and keycaps make it brighter.
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
#define W_L LGUI(KC_L)

#define _WHITE 255, 255, 255
#define _OFF 0, 0, 0
// light blue
#define _PRIMARY_COLOR 31, 77, 65
// deep blue
#define _SECONDARY_COLOR 31, 77, 15
// purple
#define _LOCKED_COLOR 153, 16, 212
// dim blueish white
#define _ADVANCED_BACKGROUND_COLOR 45, 51, 50
// deep red
#define _BOOTLOADER_COLOR 255, 12, 12
// deep green
#define _SLEEP_COLOR 12, 255, 12
// pink
#define _RGB_FUNCTION_COLOR 128, 51, 51
// electric blue
#define _FN_KEYS_COLOR 0, 113, 178
// electric blue
#define _MEDIA_COLOR 255, 255, 12

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WINDOWS] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        QK_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_WINDOWS_SUP] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, W_L,     _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_MAC] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        QK_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_ADV,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        T_CTLF4, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LOCKED] = LAYOUT_ansi_67(
        RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          MO_ADV,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADVANCED] = LAYOUT_ansi_67(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______,
        _______, _______, TO_WIN,  _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_SAI, _______, RGB_SPI, _______, RGB_HUI, _______, _______, RGB_VAI, _______, _______,          _______,          _______,
        _______,          _______, RGB_SAD, _______, RGB_SPD, _______, RGB_HUD, TO_MAC,  _______, RGB_VAD, _______,          _______, _______,
        TO_LOK,  _______, _______,                            KC_SLEP,                            _______, _______, _______, KC_MPRV, _______, KC_MNXT
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
                    // Only overtake if shift
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

bool is_leader_listening;

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        is_leader_listening = false;

        // c -> markdown code block
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING("``````" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) "\n\n" SS_TAP(X_LEFT));
        }

        // c, c -> markdown code block but with auto second char (phpstorm)
        SEQ_TWO_KEYS(KC_C, KC_C) {
            SEND_STRING("``` \n\n" SS_TAP(X_LEFT));
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

        leader_end();
    }
}


void leader_start(void) {
    is_leader_listening = true;
}

void leader_end(void) {
    is_leader_listening = false;
}

// *** RGB

bool rgb_matrix_indicators_user(void) {
    //  0,  esc   1,  1     2,  2       3,  3    4,  4    5,  5       6,  6    7,  7    8,  8       9,  9    10, 0     11, -_     12, (=+)   13, BackSpc   14 (rotary encoder)
    //  15, Tab   16, Q     17, W       18. E    19, R    20, T       21, Y    22, U    23, I       24, O    25, P     26, [{     27, ]}     28, \|        29, pgup
    //  30, Caps  31, A     32, S       33, D    34, F    35, G       36, H    37, J    38, K       39, L    40, ;:    41, '"                42, Enter     43, pgdwn
    //  44, Sh_L  45, Z     46, X       47, C    48, V    49, B       50, N    51, M    52, ,<      53, .<   54, /?               55, Sh_R   56, Up
    //  57, Ct_L  58,Win_L  59, Alt_L                     60, SPACE                     61, Alt_R   62, FN             63, Ct_R   64, Left   65, Down      66, Right

    // leader key
    if (is_leader_listening) {
        rgb_matrix_set_color_all(_OFF);

        rgb_matrix_set_color(30, _WHITE); // caps lock
        rgb_matrix_set_color(5, _WHITE); // 5
        rgb_matrix_set_color(47, _WHITE); // c
        rgb_matrix_set_color(50, _WHITE); // n

        return false;
    }

    // by layer
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {

        case _WINDOWS:
        case _WINDOWS_SUP:
            rgb_matrix_set_color_all(_SECONDARY_COLOR);
            break;

        case _MAC:
            rgb_matrix_set_color_all(_PRIMARY_COLOR);
            break;

        case _ADVANCED:
            rgb_matrix_set_color_all(_ADVANCED_BACKGROUND_COLOR);

            // layers
            rgb_matrix_set_color(17, _SECONDARY_COLOR);
            rgb_matrix_set_color(51, _PRIMARY_COLOR);
            rgb_matrix_set_color(57, _LOCKED_COLOR);

            // fn keys
            rgb_matrix_set_color(1, _FN_KEYS_COLOR);
            rgb_matrix_set_color(2, _FN_KEYS_COLOR);
            rgb_matrix_set_color(3, _FN_KEYS_COLOR);
            rgb_matrix_set_color(4, _FN_KEYS_COLOR);
            rgb_matrix_set_color(5, _FN_KEYS_COLOR);
            rgb_matrix_set_color(6, _FN_KEYS_COLOR);
            rgb_matrix_set_color(7, _FN_KEYS_COLOR);
            rgb_matrix_set_color(8, _FN_KEYS_COLOR);
            rgb_matrix_set_color(9, _FN_KEYS_COLOR);
            rgb_matrix_set_color(10, _FN_KEYS_COLOR);
            rgb_matrix_set_color(11, _FN_KEYS_COLOR);
            rgb_matrix_set_color(12, _FN_KEYS_COLOR);

            // rgb functions
            rgb_matrix_set_color(36, _RGB_FUNCTION_COLOR); // H
            rgb_matrix_set_color(32, _RGB_FUNCTION_COLOR); // S
            rgb_matrix_set_color(39, _RGB_FUNCTION_COLOR); // L
            rgb_matrix_set_color(19, _RGB_FUNCTION_COLOR); // R (mode)
            rgb_matrix_set_color(34, _RGB_FUNCTION_COLOR); // F (speed)

            rgb_matrix_set_color(64, _MEDIA_COLOR); // left
            rgb_matrix_set_color(66, _MEDIA_COLOR); // right

            // bootloader
            rgb_matrix_set_color(0, _BOOTLOADER_COLOR);

            // sleep
            rgb_matrix_set_color(60, _SLEEP_COLOR);
            break;

        default:
            break;
    }

    // caps lock
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(29, _WHITE); // PgUp
        rgb_matrix_set_color(43, _WHITE); // PgDn
        rgb_matrix_set_color(30, _WHITE); // CAPS LED
    }

    return false;
}
