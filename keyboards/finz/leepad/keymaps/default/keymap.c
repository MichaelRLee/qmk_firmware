#include QMK_KEYBOARD_H

#define _NUM LT(2, KC_NUM)
#define _BTAB LSFT(KC_TAB)

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
    [0] = LAYOUT_numpad_6x4(
        KC_CIRC, KC_LPRN, KC_RPRN, KC_PERC,
        _NUM,    KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
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
    [1] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  _BTAB,   KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          _______, _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │Esc│Tab│Tab│Bsp│
     * ├───┼───┼───┼───┤
     * │Num│---│---│---│
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
    [2] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  _BTAB,   KC_BSPC,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          KC_COMM, KC_EQL
    )
};

const uint16_t PROGMEM reset_combo[] = {KC_ESC, KC_EQL, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(reset_combo, RESET)
};

void extended_nulock(led_t led_state){
    led_state.num_lock ? layer_off(1) : layer_on(1);
}

void keyboard_post_init_user(void) {
    extended_nulock(host_keyboard_led_state());
}

bool led_update_user(led_t led_state) {
    extended_nulock(led_state);
    return true;
}
