#include QMK_KEYBOARD_H

#define _______ KC_TRNS

#define BASE 0
#define FUNL 1
#define CURS 2
#define MEDI 3
#define TEMP 4
#define DANG 5
#define ONEH 6

#define MY_F MT(MOD_LSFT, KC_F)
#define MY_J MT(MOD_RSFT, KC_J)
#define MY_D MT(MOD_LCTL, KC_D)
#define MY_K MT(MOD_RCTL, KC_K)
#define MY_S MT(MOD_LALT, KC_S)
#define MY_L MT(MOD_LALT, KC_L)
#define MY_E MT(MOD_LGUI, KC_E)
#define MY_I MT(MOD_RGUI, KC_I)
#define MY_SPC LT(FUNL, KC_SPC)
#define MY_A LT(CURS, KC_A)
#define MY_Q LT(MEDI, KC_Q)
#define MY_G MT(MOD_HYPR, KC_G)
#define MY_H MT(MOD_HYPR, KC_H)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_NO  ,  KC_CAPS,
    KC_TAB , MY_Q   , KC_W   , MY_E   , KC_R   , KC_T   , KC_Y   , KC_U   , MY_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,     KC_BSLS     ,
    KC_ESC , MY_A   , MY_S   , MY_D   , MY_F   , MY_G   , MY_H   , MY_J   , MY_K   , MY_L   , KC_SCLN, KC_QUOT,          KC_ENT          ,
    KC_BSPC, KC_NO  , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,       KC_DEL    ,   KC_NO,
    KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                   MY_SPC                   , KC_NO  , KC_NO  , KC_APP , KC_NO  , KC_CAPS,  KC_NO ),

	[FUNL] = LAYOUT(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______,
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, BL_DEC, BL_TOGG, BL_INC, BL_STEP, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	[CURS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_UP , KC_END , KC_INS , _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  [MEDI] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLU, KC_MUTE, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,                   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______, _______, _______),

};
