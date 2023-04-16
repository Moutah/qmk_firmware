#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// enums
enum layers {
    _LAYER_MAIN,
    _LAYER_SECONDARY,
    _LAYER_WINDOWS_SUP,
    _LAYER_COMMANDS,
    _LAYER_FUNCTIONS,
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
    _K_MTRX,
};

enum rgb_states {
    _RGB_STATE_DEFAULT = SAFE_RANGE,
    _RGB_STATE_OFF,
    _RGB_STATE_EPROM,
};

// custom keys
#define TO_MAIN TO(_LAYER_MAIN)
#define TO_SEC TO(_LAYER_SECONDARY)
#define MO_WSP MO(_LAYER_WINDOWS_SUP)
#define MO_CMD MO(_LAYER_COMMANDS)
#define OS_FUN OSL(_LAYER_FUNCTIONS)
#define C_HOME LCTL(KC_HOME)
#define C_END LCTL(KC_END)
#define C_SLSH LCTL(KC_SLSH)
#define T_CTLF4 LCTL_T(KC_F4)
#define CAG_M LCAG(KC_M)
#define W_L LGUI(KC_L)

// user data
typedef union {
    uint32_t key_press_count;
} user_config_t;

int rgb_state;

// common colors
#define _COLOR_WHITE 255, 255, 255
#define _COLOR_OFF 0, 0, 0

void load_user_data(void);
void record_key_pressed(void);
bool handle_custom_keys(uint16_t keycode, keyrecord_t *record, uint8_t mod_state, uint8_t current_layer, uint8_t layer_for);

#endif
