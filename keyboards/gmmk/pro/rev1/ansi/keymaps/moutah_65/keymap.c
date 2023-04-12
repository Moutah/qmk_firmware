/**
 * GMMK PRO
 * Moutah 65
 *
 * Based on a 65% layout but for GMMK Pro which is a 75%.
 * Synced with keychron\q2\ansi_encoder\keymaps\moutah_65. Has much brighter RGB values as the leds and keycaps make it dimmer.
 */

#include QMK_KEYBOARD_H
#include "stdio.h"

enum layers {
    _LAYER_WINDOWS,
    _LAYER_WINDOWS_SUP,
    _LAYER_MAC,
    _LAYER_COMMANDS,
    _LAYER_FUNCTIONS,
};

enum custom_keycodes {
    _K_MDC = SAFE_RANGE,
    _K_MDC2,
    _K_RGB,
    _K_MDTB,
    _K_MDA,
    _K_MTRX,
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
#define CAG_M LCAG(KC_M)
#define W_L LGUI(KC_L)

#define _COLOR_WHITE 255, 255, 255
#define _COLOR_OFF 0, 0, 0

// deep blue h:238
#define _COLOR_PRIMARY 8, 9, 38
#define _COLOR_PRIMARY_STRONG 14, 20, 179
// teal h:169
#define _COLOR_SECONDARY 8, 38, 33
#define _COLOR_SECONDARY_STRONG 14, 179, 148
// dim blueish black
#define _COLOR_ADVANCED_BACKGROUND 4, 4, 6
// deep red
#define _COLOR_BOOTLOADER 255, 12, 12
// deep green
#define _COLOR_SLEEP 12, 255, 12
// pink
#define _COLOR_PAGE 220, 54, 54
// electric blue
#define _COLOR_FN_KEYS 4, 72, 217
// yellow
#define _COLOR_MEDIA 220, 200, 4

int rgb_state = _RGB_STATE_DEFAULT;

typedef union {
  uint32_t key_press_count;
} user_config_t;

user_config_t user_config;

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_LAYER_WINDOWS] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          KC_MPLY,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          _K_RGB,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_FUN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_CMD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        KC_LGUI, KC_LALT, KC_LCTL,                            KC_SPC,                             MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_WINDOWS_SUP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, W_L,     _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,  _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_LAYER_MAC] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  CAG_M,            KC_MPLY,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          _K_RGB,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        OS_FUN,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           MO_CMD,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   XXXXXXX,
        T_CTLF4, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LAYER_COMMANDS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, TO_WIN,  XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, RGB_SAI, XXXXXXX, RGB_SPI, XXXXXXX, RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          RGB_SAD, XXXXXXX, RGB_SPD, XXXXXXX, RGB_HUD, XXXXXXX, TO_MAC,  XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_PGUP, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            KC_SLEP,                            XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_PGDN, KC_MNXT
    ),

    [_LAYER_FUNCTIONS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _K_MDTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        KC_CAPS, _K_MDA,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _K_MTRX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, _K_MDC,  XXXXXXX, _K_MDC2, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
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

// *** Metrics

void keyboard_post_init_user(void) {
    user_config.key_press_count = eeconfig_read_user();
    eeconfig_update_user(user_config.key_press_count);
}

// *** Custom keys

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  
    if (record->event.pressed) {
        user_config.key_press_count++;
        eeconfig_update_user(user_config.key_press_count);
    }

    mod_state = get_mods();

    // in RGB EPROM, disable all keys except RGB related ones
    if (rgb_state == _RGB_STATE_EPROM) {
        if (
          keycode != _K_RGB
          && keycode != MO_CMD
          && keycode != RGB_MOD
          && keycode != RGB_SAI
          && keycode != RGB_SAD
          && keycode != RGB_SPI
          && keycode != RGB_HUI
          && keycode != RGB_SPD
          && keycode != RGB_HUD
        ) {
            return false;
        }
    }

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
            
        // markdown table part |---
        case _K_MDTB:
            {
                if (record->event.pressed) {
                    SEND_STRING("| --- ");
                    return true;
                }
            }
            
        // markdown link
        case _K_MDA:
            {
                if (record->event.pressed) {
                    SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
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
            
        // print key press metrics
        case _K_MTRX:
            {
                if (record->event.pressed) {
                    char str[40];
                    sprintf(str, "[GMMK Pro] Key press count: %lu", user_config.key_press_count);
                    SEND_STRING(str);
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

    // standard rgb
    if (rgb_state == _RGB_STATE_EPROM) {
        rgb_matrix_set_color(72, _COLOR_WHITE);
        return false;
    }

    // custom layer rgb
    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case _LAYER_WINDOWS:
        case _LAYER_WINDOWS_SUP:
            rgb_matrix_set_color_all(_COLOR_PRIMARY);
            break;

        case _LAYER_MAC:
            rgb_matrix_set_color_all(_COLOR_SECONDARY);
            break;

        case _LAYER_COMMANDS:
            rgb_matrix_set_color_all(_COLOR_ADVANCED_BACKGROUND);

            // fn keys
            rgb_matrix_set_color(7, _COLOR_FN_KEYS);
            rgb_matrix_set_color(13, _COLOR_FN_KEYS);
            rgb_matrix_set_color(19, _COLOR_FN_KEYS);
            rgb_matrix_set_color(24, _COLOR_FN_KEYS);
            rgb_matrix_set_color(29, _COLOR_FN_KEYS);
            rgb_matrix_set_color(35, _COLOR_FN_KEYS);
            rgb_matrix_set_color(40, _COLOR_FN_KEYS);
            rgb_matrix_set_color(45, _COLOR_FN_KEYS);
            rgb_matrix_set_color(51, _COLOR_FN_KEYS);
            rgb_matrix_set_color(57, _COLOR_FN_KEYS);
            rgb_matrix_set_color(62, _COLOR_FN_KEYS);
            rgb_matrix_set_color(78, _COLOR_FN_KEYS);

            // layers
            rgb_matrix_set_color(14, _COLOR_PRIMARY_STRONG);
            rgb_matrix_set_color(43, _COLOR_SECONDARY_STRONG);

            // music
            rgb_matrix_set_color(95, _COLOR_MEDIA);
            rgb_matrix_set_color(79, _COLOR_MEDIA);

            // page up/down
            rgb_matrix_set_color(94, _COLOR_PAGE);
            rgb_matrix_set_color(97, _COLOR_PAGE);

            // bootloader
            rgb_matrix_set_color(1, _COLOR_BOOTLOADER);

            // sleep
            rgb_matrix_set_color(33, _COLOR_SLEEP);
            break;

        case _LAYER_FUNCTIONS:
            rgb_matrix_set_color_all(_COLOR_ADVANCED_BACKGROUND);

            // fn keys
            rgb_matrix_set_color(7, _COLOR_FN_KEYS);
            rgb_matrix_set_color(13, _COLOR_FN_KEYS);
            rgb_matrix_set_color(19, _COLOR_FN_KEYS);
            rgb_matrix_set_color(24, _COLOR_FN_KEYS);
            rgb_matrix_set_color(29, _COLOR_FN_KEYS);
            rgb_matrix_set_color(35, _COLOR_FN_KEYS);
            rgb_matrix_set_color(40, _COLOR_FN_KEYS);
            rgb_matrix_set_color(45, _COLOR_FN_KEYS);
            rgb_matrix_set_color(51, _COLOR_FN_KEYS);
            rgb_matrix_set_color(57, _COLOR_FN_KEYS);
            rgb_matrix_set_color(62, _COLOR_FN_KEYS);
            rgb_matrix_set_color(78, _COLOR_FN_KEYS);

            rgb_matrix_set_color(3, _COLOR_WHITE); // caps lock

            rgb_matrix_set_color(30, _COLOR_FN_KEYS); // t
            rgb_matrix_set_color(9, _COLOR_FN_KEYS); // a
            rgb_matrix_set_color(32, _COLOR_FN_KEYS); // b
            rgb_matrix_set_color(22, _COLOR_FN_KEYS); // c
            rgb_matrix_set_color(38, _COLOR_FN_KEYS); // n
            break;

        default:
            break;
    }

    // caps lock
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(72, _COLOR_WHITE); // Home
        rgb_matrix_set_color(75, _COLOR_WHITE); // PgUp
        rgb_matrix_set_color(86, _COLOR_WHITE); // PgDn
        rgb_matrix_set_color(82, _COLOR_WHITE); // End

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
        rgb_matrix_set_color(3, _COLOR_WHITE);  // CAPS LED
    }

    return false;
}
