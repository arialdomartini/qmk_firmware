#include "whitefox.h"

#define BASE 0 // default layer
#define CURS 1 // symbols
#define MDIA 2 // media keys

#DEFINE _______ KC_TRNS
#define MY_F MT(MOD_LSFT, KC_F)
#define MY_J MT(MOD_LSFT, KC_J)
#define MY_D MT(MOD_LCTL, KC_D)
#define MY_K MT(MOD_LCTL, KC_K)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,------------------------------------------------------------------------------------------.
     * |Esc|    1|    2|    3|    4|    5|    6|    7|    8|    9|    0|    -|    =|    \|   `|Ins|
     * |------------------------------------------------------------------------------------------|
     * |Tab  |    Q|    W|    E|    R|    T|    Y|    U|    I|    O|    P|    [|    ]|Backs|   Del|
     * |------------------------------------------------------------------------------------------|
     * |CapsLo|    A|    S|D/CTL|F/SFT|    G|    H|J/SFT|D/CTL|    L|    ;|    '|  Enter   |   PgU|
     * |------------------------------------------------------------------------------------------|
     * |Shif|     |    Z|    X|    C|    V|    B|    N|    M|    ,|    .|    /| Shift | Up |   PgD|
     * |------------------------------------------------------------------------------------------|
     * |Ctrl| Gui  |Alt  |           Space                | Fn0 | Alt | Gui |    | Lef | Dow | Rig|
     * `------------------------------------------------------------------------------------------'
     */
    [BASE] = KEYMAP(
        KC_ESC,  KC_1   , KC_2   , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9   , KC_0   , KC_MINS, KC_EQL,  KC_BSLS, KC_GRV , KC_INS,
        KC_TAB,  KC_Q   , KC_W   , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC         , KC_DEL,
        KC_CAPS, KC_A   , KC_S   , MY_D , MY_F , KC_G , KC_H , MY_J , MY_K , KC_L   , KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT          , KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z   , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_UP  , KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC                          , KC_RALT, KC_FN0 , _______, KC_LEFT, KC_DOWN, KC_RGHT),



    [CURS] = KEYMAP(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_VOLD,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(CURSXS),
};
