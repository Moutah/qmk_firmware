/**
 * Keychron Q11
 * Moutah
 *
 * Synced with gmmk\pro\rev1\ansi\keymaps\moutah. Has much darker RGB values as the leds and keycaps make it brighter.
 */

#include QMK_KEYBOARD_H
#include "moutah.h"

// blue
#define _COLOR_WINDOWS 72, 72, 255
// teal
#define _COLOR_MAC 0, 172, 42
// dim blueish black
#define _COLOR_ADVANCED_BACKGROUND 2, 2, 3
// deep red
#define _COLOR_BOOTLOADER 255, 12, 12
// deep green
#define _COLOR_SLEEP 12, 255, 12
// pink
#define _COLOR_FN_KEYS 235, 50, 96
// yellow
#define _COLOR_MEDIA 220, 200, 4

// *** Layers

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // mac
    [_LAYER_MAIN] = LAYOUT_91_ansi(
        RGB_TOG, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HYPR_F13, OS_CMD,  KC_MPLY,
        HYPR_F1, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_HOME,
        HYPR_F2, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,
        HYPR_F3, OS_CMD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,            KC_END,
        HYPR_F4, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,  KC_UP,
        HYPR_F5, T_CTLF4, KC_LALT, KC_LGUI, KC_LGUI,          KC_SPC,                    KC_SPC,           KC_RGUI, KC_RALT, KC_RCTL, KC_LEFT,  KC_DOWN, KC_RGHT
    ),

    // windows
    [_LAYER_SECONDARY] = LAYOUT_91_ansi(
        RGB_TOG, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  HYPR_F13, OS_CMD,  KC_MPLY,
        HYPR_F1, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,           KC_HOME,
        HYPR_F2, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,
        HYPR_F3, OS_CMD,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,            KC_END,
        HYPR_F4, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,  KC_UP,
        HYPR_F5, KC_LGUI, KC_LALT, KC_LCTL, KC_LCTL,          KC_SPC,                    KC_SPC,           MO_WSP,  KC_RCTL, KC_RGUI, KC_LEFT,  KC_DOWN, KC_RGHT
     ),

    [_LAYER_WINDOWS_SUP] = LAYOUT_91_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, W_L,     _______, _______,          _______,          _______,
        _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, C_SLSH,           _______, C_HOME,
        _______, _______, _______, _______, _______,          _______,                   _______,          _______, _______, _______, KC_HOME, C_END,   KC_END
    ),

    [_LAYER_COMMANDS] = LAYOUT_91_ansi(
        RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,
        XXXXXXX, XXXXXXX, HYPR_1,  HYPR_2,  HYPR_3,  HYPR_4,  HYPR_5,  HYPR_6,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, TO_SEC,  XXXXXXX, _K_RGB,  _K_MDTB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          _K_MX_C,
        XXXXXXX, XXXXXXX, _K_MDA,  XXXXXXX, XXXXXXX, _K_AFN,  XXXXXXX, XXXXXXX, XXXXXXX, _K_MX_O, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX, KC_CAPS,          XXXXXXX, XXXXXXX, _K_MDC,  XXXXXXX, _K_MDC2, XXXXXXX, TO_MAIN, XXXXXXX, XXXXXXX, XXXXXXX,          KC_CAPS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_SLEP,                   KC_SLEP,          XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, XXXXXXX, KC_MNXT
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

bool rgb_matrix_indicators_user(void) {
    // I have no idea WTF the led indexes are :(

    // (rotary),  0: ESC,     1: F1,      2: F2,     3: F3,   4: F4,     5: F5,     6: F6,  42: F7,  43: F8,    44: F9,     45: F10,   46: F11,   47: F12,    48: INS,       49: DEL,  (rotary),
    //  7: M1,    8: `~,      9: 1,      10: 2,     11: 3,   12: 4,     13: 5,     14: 6,   50: 7,   51: 8,     52: 9,      53: 0,     54: -_,    55: =+,     56: BackSpace,           57: PgUp,
    // 15: M2,   16: TAB,     17: Q,     18: W,     19: E,   20: R,     21: T,     58: Y,   59: U,   60: I,     61: O,      62: P,     63: [,     64: ],      65: ||,                  66: PgDn,
    // 22: M3,   23: Caps,    24: A,     25: S,     26: D,   27: F,     28: G,     67: H,   68: J,   69: K,     70: L,      71: ;:,    72: '",                73: Enter,               74: Home,
    // 29: M4,   30: Shift_L,            31: Z,     32: X,   33: C,     34: V,     35: B,   75: N,   76: M,     77: ,<,     78: .>,    79: ?/,                80: Shift_R,   81: Up,
    // 36: M5,   37: Ctrl_L,  38: WGn_L, 39: Alt_L, 40: Fn,             41: Space,                   82: Space,             83: Win_R, 84: Fn,    85: Ctrl_R, 86: Left,      87: Down, 88: Right

    // (rotary),  0: ESC,     1: F1,      2: F2,     3: F3,   4: F4,     5: F5,     6: F6,  ??: F7,  ??: F8,    ??: F9,     ??: F10,   ??: F11,   ??: F12,    ??: INS,       ??: DEL,  (rotary),
    //  7: M1,    8: `~,      9: 1,      10: 2,     11: 3,   12: 4,     13: 5,     ??: 6,   ??: 7,   ??: 8,     ??: 9,      ??: 0,     ??: -_,    ??: =+,     ??: BackSpace,           ??: PgUp,
    // ??: M2,   ??: TAB,     ??: Q,     ??: W,     ??: E,   ??: R,     ??: T,     ??: Y,   ??: U,   ??: I,     ??: O,      ??: P,     ??: [,     ??: ],      ??: ||,                  ??: PgDn,
    // ??: M3,   ??: Caps,    ??: A,     ??: S,     ??: D,   ??: F,     ??: G,     ??: H,   ??: J,   ??: K,     ??: L,      ??: ??:,    ??: '",                ??: Enter,               ??: Home,
    // ??: M4,   ??: Shift_L,            ??: Z,     ??: X,   ??: C,     ??: V,     ??: B,   ??: N,   ??: M,     ??: ,<,     ??: .>,    ??: ?/,                ??: Shift_R,   ??: Up,
    // ??: M5,   ??: Ctrl_L,  ??: WGn_L, ??: Alt_L, ??: Fn,             ??: Space,                   ??: Space,             ??: Win_R, ??: Fn,    ??: Ctrl_R, ??: Left,      ??: Down, ??: Right


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

            // 0 esc : layer witness
            if (base_layer == _LAYER_MAIN) {
                rgb_matrix_set_color(0, _COLOR_WINDOWS);
            }
            if (base_layer == _LAYER_SECONDARY) {
                rgb_matrix_set_color(0, _COLOR_MAC);
            }
            break;

        default:
            break;
    }

    // caps lock
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(7, _COLOR_WHITE); // M1

        rgb_matrix_set_color(23, _COLOR_WHITE);  // CAPS LED
    }

    return true;
}
