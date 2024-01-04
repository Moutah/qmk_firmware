#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// enums
enum layers {
    _LAYER_MAIN,
    _LAYER_SECONDARY,
    _LAYER_WINDOWS_SUP,
    _LAYER_COMMANDS,
    _LAYER_LOCK,
};

enum layers_for_os {
    _FOR_WINDOWS,
    _FOR_MAC,
};

enum custom_keycodes {
    _K_MDC = SAFE_RANGE,
    _K_MDC2,
    _K_RGB,
    _K_MDTB,
    _K_MDA,
    _K_MX_O,
    _K_MX_C,
    _K_AFN,
};

enum rgb_states {
    _RGB_STATE_DEFAULT = SAFE_RANGE,
    _RGB_STATE_OFF,
};

// custom keys
#define TO_MAIN TO(_LAYER_MAIN)
#define TO_SEC TO(_LAYER_SECONDARY)
#define TO_LOK TO(_LAYER_LOCK)
#define MO_WSP MO(_LAYER_WINDOWS_SUP)
#define OS_CMD OSL(_LAYER_COMMANDS)
#define C_HOME LCTL(KC_HOME)
#define C_END LCTL(KC_END)
#define C_SLSH LCTL(KC_SLSH)
#define T_CTLF4 LCTL_T(KC_F4)
#define CAG_M LCAG(KC_M)
#define W_L LGUI(KC_L)
#define HYPR_1 HYPR(KC_1)
#define HYPR_2 HYPR(KC_2)
#define HYPR_3 HYPR(KC_3)
#define HYPR_4 HYPR(KC_4)
#define HYPR_5 HYPR(KC_5)
#define HYPR_6 HYPR(KC_6)
#define HYPR_F1 HYPR(KC_F1)
#define HYPR_F2 HYPR(KC_F2)
#define HYPR_F3 HYPR(KC_F3)
#define HYPR_F4 HYPR(KC_F4)
#define HYPR_F5 HYPR(KC_F5)
#define HYPR_F13 HYPR(KC_F13)
#define HYPR_F14 HYPR(KC_F14)

// user data
typedef union {
    uint32_t key_press_count;
} user_config_t;

int rgb_state;
int base_layer;

// common colors
#define _COLOR_WHITE 255, 255, 255
#define _COLOR_OFF 0, 0, 0

int constrainIntToEightBit(int value, bool is_loop);
void updateHSVBy(int delta_hue, int delta_saturation, int delta_lightness);
void load_user_data(void);
void record_key_pressed(void);
void turnVolume(bool clockwise);
bool handle_custom_keys(uint16_t keycode, keyrecord_t *record, uint8_t mod_state, uint8_t current_layer, uint8_t layer_for);

#endif
