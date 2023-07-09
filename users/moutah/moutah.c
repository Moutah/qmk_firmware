#include "moutah.h"
#include "stdio.h"

user_config_t user_config;

int rgb_state = _RGB_STATE_DEFAULT;
int base_layer = _LAYER_MAIN;

int constrainIntToEightBit(int value, bool is_loop) {
  if (value < 0) {
    return is_loop ? 255 : 0;
  }

  if (value > 255) {
    return is_loop ? 0 : 255;
  }

  return value;
}

void updateHSVBy(int delta_hue, int delta_saturation, int delta_lightness) {
    uint8_t hue = constrainIntToEightBit(rgblight_get_hue() + delta_hue, true);
    uint8_t sat = constrainIntToEightBit(rgblight_get_sat() + delta_saturation, false);
    uint8_t lightness = constrainIntToEightBit(rgblight_get_val() + delta_lightness, false);

    rgblight_sethsv(hue, sat, lightness);
}

void load_user_data(void) {
    user_config.key_press_count = eeconfig_read_user();
    eeconfig_update_user(user_config.key_press_count);
}

void record_key_pressed(void) {
    user_config.key_press_count++;
    eeconfig_update_user(user_config.key_press_count);
}

void turnVolume(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

bool handle_custom_keys(uint16_t keycode, keyrecord_t *record, uint8_t mod_state, uint8_t current_layer, uint8_t main_layer) {
    switch (keycode) {

        // markdown code block
        case _K_MDC: {
            if (record->event.pressed) {
                SEND_STRING("``````" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) "\n\n" SS_TAP(X_LEFT));
                return true;
            }
        }

        // markdown code block but with auto second char (as ide autocomplete)
        case _K_MDC2: {
            if (record->event.pressed) {
                SEND_STRING("``` \n\n" SS_TAP(X_LEFT));
                return true;
            }
        }

        // markdown table part |---
        case _K_MDTB: {
            if (record->event.pressed) {
                SEND_STRING("| --- ");
                return true;
            }
        }

        // markdown link
        case _K_MDA: {
            if (record->event.pressed) {
                SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return true;
            }
        }

        // arrow function
        case _K_AFN: {
            if (record->event.pressed) {
                SEND_STRING("() => {}" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
                return true;
            }
        }

        // *** Layers

        case TO_MAIN: {
            if (record->event.pressed) {
                base_layer = _LAYER_MAIN;
                return true;
            }
        }

        case TO_SEC: {
            if (record->event.pressed) {
                base_layer = _LAYER_SECONDARY;
                return true;
            }
        }

        // *** Data output

        // print current color HSV
        case _K_RGB: {
            if (record->event.pressed) {
                // Get the current rgblight color components
                uint8_t hue = rgblight_get_hue();
                uint8_t sat = rgblight_get_sat();
                uint8_t lightness = rgblight_get_val();

                char str[24];
                sprintf(str, "H:%u S:%u V:%u", hue, sat, lightness);
                SEND_STRING(str);
                return true;
            }
        }

        // print key press metrics
        case _K_MX_O: {
            if (record->event.pressed) {
                char str[11];
                sprintf(str, "%lu", user_config.key_press_count);
                SEND_STRING(str);
                return true;
            }
        }

        // reset key press metrics
        case _K_MX_C: {
            if (record->event.pressed) {
                user_config.key_press_count = 0;
                eeconfig_update_user(user_config.key_press_count);
                return true;
            }
        }
    }

    // *** MAC specific macros

    // clang-format off
    if (
      (main_layer == _FOR_MAC && current_layer == _LAYER_MAIN)
      || (main_layer == _FOR_WINDOWS && current_layer == _LAYER_SECONDARY)
    ) {
        // clang-format on
        if (record->event.pressed) {
            switch (keycode) {
                case KC_L: {
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

    // *** WINDOWS specific macros

    // clang-format off
    if (
      (main_layer == _FOR_WINDOWS && current_layer == _LAYER_MAIN)
      || (main_layer == _FOR_MAC && current_layer == _LAYER_SECONDARY)
    ) {
        // clang-format on
        if (record->event.pressed) {
            switch (keycode) {
                case KC_LEFT: {
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

                case KC_RIGHT: {
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

                case KC_UP: {
                    // WIN + Up -> WIN + Tab
                    if (mod_state & MOD_MASK_GUI) {
                        tap_code(KC_TAB);
                        return false;
                    }
                }

                case KC_ENT: {
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
}
