#include "whitefox.h"

#define BASE 0 // default layer
#define CURS 1 // symbols
#define EXTR 2 // media keys
#define FLAY 3 // function keys

#define _______ KC_TRNS

// special keys
#define MY_A LT(CURS, KC_A)
#define MY_F MT(MOD_LSFT, KC_F)
#define MY_J MT(MOD_LSFT, KC_J)
#define MY_D MT(MOD_LCTL, KC_D)
#define MY_K MT(MOD_LCTL, KC_K)
#define MY_S MT(MOD_LALT, KC_S)
#define MY_L MT(MOD_LALT, KC_L)

#define MY_E MT(MOD_LGUI, KC_E)
#define MY_I MT(MOD_RGUI, KC_I)

#define MY_FN LT(EXTR, KC_APP)
#define MY_ESC LT(EXTR, KC_ESC)
#define MY_ENT LT(FLAY, KC_ENT)
#define MY_CAPS LT(FLAY, KC_ESC)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Base Layer
     * ,------------------------------------------------------------------------------------------.
     * |MyEs|  1  |  2  |  3 |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  | ` | Ins|
     * |------------------------------------------------------------------------------------------|
     * |Tab  |    Q|    W|E/Gui|    R|    T|    Y|    U|I/Gui|    O|    P|    [|    ]|Backs|   Del|
     * |------------------------------------------------------------------------------------------|
     * |Esc/F |A/CRS|S/ALT|D/CTL|F/SFT|    G|    H|J/SFT|D/CTL|L/ALT|    ;|    '|Enter/Fun |   PgU|
     * |------------------------------------------------------------------------------------------|
     * |Backspace |    Z|    X|    C|    V|    B|    N|    M|    ,|    .|    /| Delete| Up |   PgD|
     * |------------------------------------------------------------------------------------------|
     * |    |      |     |           Space                |MyFun|Caps | Gui |    | Lef | Dow | Rig|
     * `------------------------------------------------------------------------------------------'
     */
    [BASE] = KEYMAP(
        MY_ESC , KC_1   , KC_2   , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSLS, KC_GRV , KC_INS,
        KC_TAB , KC_Q   , KC_W   , MY_E , KC_R , KC_T , KC_Y , KC_U , MY_I , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC         , KC_DEL,
        MY_CAPS, MY_A   , MY_S   , MY_D , MY_F , KC_G , KC_H , MY_J , MY_K , MY_L   , KC_SCLN, KC_QUOT, KC_NUHS, MY_ENT          , KC_PGUP,
        KC_BSPC, _______, KC_Z   , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_DEL          , KC_UP  , KC_PGDN,
        _______, _______, _______,                  KC_SPC                          , KC_CAPS, MY_FN  , _______, KC_LEFT, KC_DOWN, KC_RGHT),



    /* Layer 1: Cursor Layer
     * ,------------------------------------------------------------------------------------------.
     * |   |     |     |     |     |     |     |     |     |     |     |     |     |     |    |   |
     * |------------------------------------------------------------------------------------------|
     * |     |     |     |     |     |     |     | Home|   Up| End | Ins |     |     |     |      |
     * |------------------------------------------------------------------------------------------|
     * |      |     |     |     |     |     |BacSp| Left| Down|Right| Del |     |          |      |
     * |------------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |PageUp|    |PageDn|    |       |    |      |
     * |------------------------------------------------------------------------------------------|
     * |    |      |     |                                |     |     |     |    |     |     |    |
     * `------------------------------------------------------------------------------------------'
     */
    [CURS] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_UP , KC_END , KC_INS , _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______         , _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______),


    /* Layer 2: Extra Layer
     * ,------------------------------------------------------------------------------------------.
     * |   |     |     |     |     |     |     |     |     |     |     |     |     |     |    |   |
     * |------------------------------------------------------------------------------------------|
     * |VolUp|     |     |     |     |     |     |     |     |     |     |     |     |     |VolUp |
     * |------------------------------------------------------------------------------------------|
     * |Mute  |     |     |     |     |     |     |     |     |     |     |     |          | Mute |
     * |------------------------------------------------------------------------------------------|
     * |VolumeDown|     |     |     |     |     |     |      |    |      |    |       |    |VolDow|
     * |------------------------------------------------------------------------------------------|
     * |    |      |     |                                |     |     |     |    |     |     |    |
     * `------------------------------------------------------------------------------------------'
     */
    [EXTR] = KEYMAP(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , KC_VOLU,
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , KC_MUTE,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , _______, KC_VOLD,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______),


    /* Layer 3: Function Layer
     * ,------------------------------------------------------------------------------------------.
     * |   | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |     |    |   |
     * |------------------------------------------------------------------------------------------|
     * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |      |
     * |------------------------------------------------------------------------------------------|
     * |      |     |     |     |     |     |     |     |     |     |     |     |          |      |
     * |------------------------------------------------------------------------------------------|
     * |          |     |     |     |     |     |     |      |    |      |    |       |    |      |
     * |------------------------------------------------------------------------------------------|
     * |    |      |     |                                |     |     |     |    |     |     |    |
     * `------------------------------------------------------------------------------------------'
     */
    [FLAY] = KEYMAP(
        _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______)
};
