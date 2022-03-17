#include QMK_KEYBOARD_H

// Layer names
#define _BASE 0
#define _NUM2 1
#define _NLCK 2
#define _SHFT1 3
#define _SHFT2 4

#define BCK_TAB LSFT(KC_TAB)

// Edit keys here so that reset combo works
#define _RCK1   KC_ESC
#define _RCK2   KC_EQL
#define _RCK2A  KC_ENT

// tap dance
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    SHFT_NUM,
};
#define TD_NUM  TD(SHFT_NUM)

td_state_t cur_dance(qk_tap_dance_state_t *state);
void num_finished(qk_tap_dance_state_t *state, void *user_data);
void num_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ ^ │ ( │ ) │ % │
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │ 0     │ . │   │
     * └───────┴───┴───┘
     */
    [_BASE] = LAYOUT_numpad_6x4(
        KC_CIRC, KC_LPRN, KC_RPRN, KC_PERC,
        TD_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │Del│ ( │ ) │Bsp│
     * ├───┼───┼───┼───┤
     * │---│---│---│---│
     * ├───┼───┼───┼───┤
     * │---│---│---│   │
     * ├───┼───┼───┤---│
     * │---│---│---│   │
     * ├───┼───┼───┼───┤
     * │---│---│---│   │
     * ├───┴───┼───┤ = │
     * │---    │ , │   │
     * └───────┴───┴───┘
     */
    [_NUM2] = LAYOUT_numpad_6x4(
        KC_DEL,  KC_LPRN, KC_RPRN, KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          KC_COMM, KC_EQL
    ),

    /*
     * This layer is enabled when numlock is disabled
     * ┌───┐───┬───┬───┐
     * │Esc│Tab│Tab│Bsp│
     * ├───┼───┼───┼───┤
     * │Num│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [_NLCK] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  BCK_TAB, KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │Esc│ [ │ ] │Bsp│
     * ├───┼───┼───┼───┤
     * │Sft│---│---│---│
     * ├───┼───┼───┼───┤
     * │---│---│---│   │
     * ├───┼───┼───┤---│
     * │---│---│---│   │
     * ├───┼───┼───┼───┤
     * │---│---│---│   │
     * ├───┴───┼───┤ = │
     * │Del    │ , │   │
     * └───────┴───┴───┘
     */
    [_SHFT1] = LAYOUT_numpad_6x4(
        _RCK1,   KC_LBRC, KC_RBRC, KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        KC_DEL,           KC_COMM, _RCK2
    ),

    // Same as _SHFT1, but swaps equal and comma with enter and period
    [_SHFT2] = LAYOUT_numpad_6x4(
        _RCK1,   KC_LBRC, KC_RBRC, KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        KC_DEL,           KC_PDOT, _RCK2A
    ),
};

const uint16_t PROGMEM reset_combo[] = {_RCK1, _RCK2, COMBO_END};
const uint16_t PROGMEM reset_combo2[] = {_RCK1, _RCK2A, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(reset_combo, RESET),
    COMBO(reset_combo2, RESET)
};

void extended_nulock(led_t led_state){
    led_state.num_lock ? layer_off(_NLCK) : layer_on(_NLCK);
}

void keyboard_post_init_user(void) {
    extended_nulock(host_keyboard_led_state());
}

bool led_update_user(led_t led_state) {
    extended_nulock(led_state);
    return true;
}

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        // Permissive hold single hold
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
        else return TD_DOUBLE_HOLD;
    } else return TD_UNKNOWN;
}

static td_tap_t numtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void num_finished(qk_tap_dance_state_t *state, void *user_data) {
    numtap_state.state = cur_dance(state);
    switch (numtap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_NUM); break;
        case TD_SINGLE_HOLD: layer_state_is(_NUM2) ? layer_on(_SHFT2) : layer_on(_SHFT1); break;
        case TD_DOUBLE_TAP: tap_code(KC_CALC); break;
        case TD_DOUBLE_HOLD: layer_state_is(_NUM2) ? layer_off(_NUM2) : layer_on(_NUM2); break;
        default: break;
    }
}

void num_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (numtap_state.state == TD_SINGLE_HOLD) {
        layer_state_is(_SHFT1) ? layer_off(_SHFT1) : layer_off(_SHFT2);
    }
    numtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SHFT_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_finished, num_reset),
};