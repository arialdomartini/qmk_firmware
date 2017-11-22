// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define CURS 3 // movement layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------------------.           ,-------------------------------------------------------.
 * |   =    |   1  |    2   |    3   |   4   |   5  |      |           |      |   6  |   7   |    8   |    9   |   0  |   -    |
 * |--------+------+--------+--------+-------+-------------|           |------+------+-------+--------+--------+------+--------|
 * | Del    |   Q  |    W   | E/LGui |   R   |   T  |  L1  |           |  L1  |   Y  |   U   | I/RGui |    O   |   P  |   \    |
 * |--------+------+--------+--------+-------+------|      |           |      |------+-------+--------+--------+------+--------|
 * | BkSp   |   A  | S/LAlt | D/LCtl | F/LSh |   G  |------|           |------|   H  | J/RSh | K/RCtl | L/RAlt |; / L2| Enter  |
 * |--------+------+--------+--------+-------+------| Hyper|           | Meh  |------+-------+--------+--------+------+--------|
 * |        |   Z  |    X   |    C   |   V   |   B  |      |           |      |   N  |   M   |    ,   |    .   |  /   |        |
 * `--------+------+--------+--------+-------+-------------'           `-------------+-------+--------+--------+------+--------'
 *   |Grv/L1|  '"  |        |        |       |                                       |       |        |    [   |   ]  | ~L1  |
 *   `---------------------------------------'                                       `---------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 | CURS |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_* 
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,          KC_1,         KC_2,               KC_3,                 KC_4,        KC_5,              KC_TRNS
        KC_DELT,         KC_Q,         KC_W,               MT(MOD_LGUI, KC_E),   KC_R,        KC_T,              TG(SYMB),
        KC_BSPC,         KC_A,         MT(MOD_LALT,KC_S),  MT(MOD_LCTL, KC_D),   MT(MOD_LSFT, KC_F),             KC_G,
        KC_TRNS,         KC_Z,         KC_X,               KC_C,                 KC_V,        KC_B,              ALL_T(KC_NO),
        LT(SYMB,KC_GRV), KC_QUOT,      KC_TRNS,            KC_TRNS,              KC_TRNS,
                                                                                              ALT_T(KC_APP),     KC_LGUI,
                                                                                                                 KC_HOME,
                                                                           LT(CURS, KC_SPC),  KC_BSPC,           KC_END,

        // right hand
        KC_TRNS,         KC_6,          KC_7,                KC_8,                 KC_9,                   KC_0,               KC_MINS,
        TG(SYMB),        KC_Y,          KC_U,                MT(MOD_RGUI, KC_I),   KC_O,                   KC_P,               KC_BSLS,
                         KC_H,          MT(MOD_RSFT, KC_J),  MT(MOD_RCTL, KC_K),   MT(MOD_RALT, KC_L),     LT(MDIA, KC_SCLN),  KC_ENT,
        MEH_T(KC_NO),    KC_N,          KC_M,                KC_COMM,              KC_DOT,                 KC_SLSH,            KC_TRNS,
                                        KC_TRNS,             KC_TRNS,              KC_LBRC,                KC_RBRC,            KC_FN1,
        KC_LALT,         CTL_T(KC_ESC),
        KC_PGUP,
        KC_PGDN,KC_TAB, KC_TRNS
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Cursor and movements
 *
 * ,--------------------------------------------------.           ,---------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |       |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+-------+------+--------|
 * |        |      |      | Gui  |      |      |      |           |      |      |      |  Up  |       |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |        |      |  Alt | Ctrl | Shft |      |------|           |------|      | Left | Down | Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+-------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |       |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+-------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |       |      |      |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[CURS] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_RGUI,  KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_RALT, KC_RCTRL, KC_RSHIFT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                            KC_TRNS,   KC_TRNS,
                                                       KC_TRNS,
                                   KC_TRNS, KC_TRNS,   KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_PGUP, KC_UP  , KC_PGDN, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
