#include "moutah_65.h"
#include "stdio.h"

user_config_t user_config;

int rgb_state = _RGB_STATE_DEFAULT;

void load_user_data(void) {
    user_config.key_press_count = eeconfig_read_user();
    eeconfig_update_user(user_config.key_press_count);
}

void record_key_pressed(void) {
    user_config.key_press_count++;
    eeconfig_update_user(user_config.key_press_count);
}

bool handle_custom_keys(uint16_t keycode, keyrecord_t *record, uint8_t mod_state, uint8_t current_layer, uint8_t main_layer) {
    // in RGB EPROM, disable all keys except RGB related ones
    if (rgb_state == _RGB_STATE_EPROM) {
        // clang-format off
        if (
          keycode != _K_RGB
          && keycode != MO_CMD
          && keycode != OS_FUN
          && keycode != RGB_MOD
          && keycode != RGB_SAI
          && keycode != RGB_SAD
          && keycode != RGB_SPI
          && keycode != RGB_HUI
          && keycode != RGB_SPD
          && keycode != RGB_HUD
        ) {
            // clang-format on
            return false;
        }
    }

    switch (keycode) {
        case KC_ESC: {
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

        // cycle through rgb state
        case _K_RGB: {
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
        case _K_MTRX: {
            if (record->event.pressed) {
                char str[34];
                sprintf(str, "[Q2] Key press count: %lu", user_config.key_press_count);
                SEND_STRING(str);
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
