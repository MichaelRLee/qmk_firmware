#include QMK_KEYBOARD_H

#define SFT_NUM LT(2, KC_NUM)
#define M1      UC(0x00E9)
#define M2      XXXXXXX
#define M3      KC_DEL
#define M4      KC_BSPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ é │---│Del│Bsp│
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
        M1,      M2,      M3,      M4,
        SFT_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /*
     * ┌───┐───┬───┬───┐
     * │---│---│---│---│
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
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          _______, _______
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │---│---│---│---│
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
    [2] = LAYOUT_numpad_6x4(
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______,
        _______,          KC_COMM, KC_EQL
    )
};

const uint16_t PROGMEM reset_combo[] = {M1, KC_EQL, COMBO_END};
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