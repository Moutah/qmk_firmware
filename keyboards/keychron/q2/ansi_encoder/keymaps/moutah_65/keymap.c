/**
 * Keychron Q2
 * Moutah 65
 *
 * Synced with gmmk\pro\rev1\ansi\keymaps\moutah_65. Has much darker RGB values as the leds and keycaps make it brighter.
 */

#include QMK_KEYBOARD_H

enum layers {
    _LAYER_MAC,
    _LAYER_WINDOWS,
    _LAYER_WINDOWS_SUP,
    _LAYER_COMMANDS,
    _LAYER_FUNCTIONS,
};

enum custom_keycodes {
    _K_MDC = SAFE_RANGE,
    _K_MDC2,
    _K_RGB,
};

enum rgb_states {
    _RGB_STATE_DEFAULT = SAFE_RANGE,
    _RGB_STATE_OFF,
    _RGB_STATE_EPROM,
};

#define TO_WIN TO(_LAYER_WINDOWS)
#define TO_MAC TO(_LAYER_MAC)
#define MO_WSP MO(_LAYER_WINDOWS_SUP)
#define MO_CMD MO(_LAYER_COMMANDS)
#define OS_FUN OSL(_LAYER_FUNCTIONS)
#define C_HOME LCTL(KC_HOME)
#define C_END LCTL(KC_END)
#define C_SLSH LCTL(KC_SLSH)
#define T_CTLF4 LCTL_T(KC_F4)
#define W_L LGUI(KC_L)

#define _COLOR_WHITE 255, 255, 255
#define _COLOR_OFF 0, 0, 0

// light blue
#define _COLOR_PRIMARY 31, 77, 65
#define _COLOR_PRIMARY_STRONG 51, 128, 107
// deep blue
#define _COLOR_SECONDARY 31, 77, 15
#define _COLOR_SECONDARY_STRONG 50, 128, 24
// dim blueish white
#define _COLOR_ADVANCED_BACKGROUND 25, 26, 26
// deep red
#define _COLOR_BOOTLOADER 255, 12, 12
// deep green
#define _COLOR_SLEEP 12, 255, 12
// pink
#define _COLOR_PAGE 128, 51, 51
// electric blue
#define _COLOR_FN_KEYS 0, 113, 178
// electric blue
#define _COLOR_MEDIA 255, 255, 12

int rgb_state = _RGB_STATE_DEFAULT;

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_LAYER_MAC] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_FUN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_CMD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        T_CTLF4, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_WINDOWS] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MPLY,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_FUN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_CMD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_WINDOWS_SUP] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, W_L,     _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_LAYER_COMMANDS] = LAYOUT_ansi_67(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, TO_WIN,  XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_SAI, XXXXXXX, RGB_SPI, XXXXXXX, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          RGB_SAD, XXXXXXX, RGB_SPD, XXXXXXX, RGB_HUD, XXXXXXX, TO_MAC,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_PGUP,
        XXXXXXX, XXXXXXX, XXXXXXX,                            KC_SLEP,                            XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_PGDN, KC_MNXT
    ),

    [_LAYER_FUNCTIONS] = LAYOUT_ansi_67(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, _K_MDC,  XXXXXXX, _K_MDC2, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

        // markdown code block
        case _K_MDC:
            {
                if (record->event.pressed) {
                    SEND_STRING("``````" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) "\n\n" SS_TAP(X_LEFT));
                    return true;
                }
            }
            
        // markdown code block but with auto second char (as ide autocomplete)
        case _K_MDC2:
            {
                if (record->event.pressed) {
                    SEND_STRING("``` \n\n" SS_TAP(X_LEFT));
                    return true;
                }
            }
            
        // cycle through rgb state
        case _K_RGB:
            {
                if (record->event.pressed) {
                    switch (rgb_state) {
                        case _RGB_STATE_DEFAULT:
                            rgb_state = _RGB_STATE_OFF;
                            break;

                        case _RGB_STATE_OFF:
                            rgb_state = _RGB_STATE_EPROM;
                            break;

                        case _RGB_STATE_EPROM:
                            rgb_state = _RGB_STATE_DEFAULT;
                            break;
                    }
                    return true;
                }
            }
            
    }

    uint8_t current_layer = get_highest_layer(layer_state);

    // MAC specific macros
    if (current_layer == _LAYER_MAC) {
        if (record->event.pressed) {
            switch (keycode) {

                case KC_L:
                    {
                        // WIN + L -> WIN + CTRL + L
                        if (mod_state & MOD_MASK_GUI) {
                            add_mods(MOD_MASK_CTRL);
                            tap_code(KC_Q);
                            del_mods(MOD_MASK_CTRL);
                        }
                    }
            }
        }
    }

    // WINDOWS specific macros
    if (current_layer == _LAYER_WINDOWS) {
        if (record->event.pressed) {
            switch (keycode) {

                case KC_LEFT:
                    {
                        if (mod_state & MOD_MASK_GUI) {

                            // WIN + ALT + Left -> WIN + Left
                            if (mod_state & MOD_MASK_ALT) {
                                set_mods(mod_state);
                                tap_code(KC_LEFT);
                                del_mods(MOD_MASK_ALT);
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

// *** RGB

bool rgb_matrix_indicators_user(void) {
    //  0,  esc   1,  1     2,  2       3,  3    4,  4    5,  5       6,  6    7,  7    8,  8       9,  9    10, 0     11, -_     12, (=+)   13, BackSpc   14 (rotary encoder)
    //  15, Tab   16, Q     17, W       18. E    19, R    20, T       21, Y    22, U    23, I       24, O    25, P     26, [{     27, ]}     28, \|        29, pgup
    //  30, Caps  31, A     32, S       33, D    34, F    35, G       36, H    37, J    38, K       39, L    40, ;:    41, '"                42, Enter     43, pgdwn
    //  44, Sh_L  45, Z     46, X       47, C    48, V    49, B       50, N    51, M    52, ,<      53, .<   54, /?               55, Sh_R   56, Up
    //  57, Ct_L  58,Win_L  59, Alt_L                     60, SPACE                     61, Alt_R   62, FN             63, Ct_R   64, Left   65, Down      66, Right

    // no rgb
    if (rgb_state == _RGB_STATE_OFF) {
        rgb_matrix_set_color_all(_COLOR_OFF);
        return false;
    }

    // standard rgb
    if (rgb_state == _RGB_STATE_EPROM) {
        rgb_matrix_set_color(72, _COLOR_WHITE);
        return false;
    }

    // custom layer rgb
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _LAYER_MAC:
            rgb_matrix_set_color_all(_COLOR_PRIMARY);
            break;

        case _LAYER_WINDOWS:
        case _LAYER_WINDOWS_SUP:
            rgb_matrix_set_color_all(_COLOR_SECONDARY);
            break;

        case _LAYER_COMMANDS:
            rgb_matrix_set_color_all(_COLOR_ADVANCED_BACKGROUND);

            // fn keys
            rgb_matrix_set_color(1, _COLOR_FN_KEYS);
            rgb_matrix_set_color(2, _COLOR_FN_KEYS);
            rgb_matrix_set_color(3, _COLOR_FN_KEYS);
            rgb_matrix_set_color(4, _COLOR_FN_KEYS);
            rgb_matrix_set_color(5, _COLOR_FN_KEYS);
            rgb_matrix_set_color(6, _COLOR_FN_KEYS);
            rgb_matrix_set_color(7, _COLOR_FN_KEYS);
            rgb_matrix_set_color(8, _COLOR_FN_KEYS);
            rgb_matrix_set_color(9, _COLOR_FN_KEYS);
            rgb_matrix_set_color(10, _COLOR_FN_KEYS);
            rgb_matrix_set_color(11, _COLOR_FN_KEYS);
            rgb_matrix_set_color(12, _COLOR_FN_KEYS);

            // layers
            rgb_matrix_set_color(51, _COLOR_PRIMARY_STRONG);
            rgb_matrix_set_color(17, _COLOR_SECONDARY_STRONG);

            // music
            rgb_matrix_set_color(64, _COLOR_MEDIA);
            rgb_matrix_set_color(66, _COLOR_MEDIA);

            // page up/down
            rgb_matrix_set_color(56, _COLOR_PAGE);
            rgb_matrix_set_color(65, _COLOR_PAGE);

            // bootloader
            rgb_matrix_set_color(0, _COLOR_BOOTLOADER);

            // sleep
            rgb_matrix_set_color(60, _COLOR_SLEEP);
            break;

        case _LAYER_FUNCTIONS:
            rgb_matrix_set_color_all(_COLOR_ADVANCED_BACKGROUND);

            // fn keys
            rgb_matrix_set_color(1, _COLOR_FN_KEYS);
            rgb_matrix_set_color(2, _COLOR_FN_KEYS);
            rgb_matrix_set_color(3, _COLOR_FN_KEYS);
            rgb_matrix_set_color(4, _COLOR_FN_KEYS);
            rgb_matrix_set_color(5, _COLOR_FN_KEYS);
            rgb_matrix_set_color(6, _COLOR_FN_KEYS);
            rgb_matrix_set_color(7, _COLOR_FN_KEYS);
            rgb_matrix_set_color(8, _COLOR_FN_KEYS);
            rgb_matrix_set_color(9, _COLOR_FN_KEYS);
            rgb_matrix_set_color(10, _COLOR_FN_KEYS);
            rgb_matrix_set_color(11, _COLOR_FN_KEYS);
            rgb_matrix_set_color(12, _COLOR_FN_KEYS);

            rgb_matrix_set_color(30, _COLOR_WHITE); // caps lock

            rgb_matrix_set_color(47, _COLOR_FN_KEYS); // b
            rgb_matrix_set_color(49, _COLOR_FN_KEYS); // c
            rgb_matrix_set_color(50, _COLOR_FN_KEYS); // n
            break;

        default:
            break;
    }

    // caps lock
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(29, _COLOR_WHITE); // PgUp
        rgb_matrix_set_color(43, _COLOR_WHITE); // PgDn
        rgb_matrix_set_color(30, _COLOR_WHITE); // CAPS LED
    }

    return false;
}
