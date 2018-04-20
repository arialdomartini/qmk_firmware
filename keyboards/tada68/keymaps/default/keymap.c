#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _ML 1
#define _FL 2

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------------.
   * |Esc | 1|  2|  3 |  4|  5|  6|  7|  8 |  9|  0|  -|  =|       |~ ` |
   * |------------------------------------------------------------------|
   * |Tab  |  Q|  W|   E|  R|  T|  Y|  U|  I |  O|  P|  [|  ]|  \  |Ins |
   * |     |   |   |LGUI|   |   |   |   |RGUI|   |   |   |   |     |    |
   * |------------------------------------------------------------------|
   * |       |  A|  S|   D|  F|  G|  H|  J|   K|  L|  ;|  '| Enter |CAPS|
   * |       |_ML|ALT|CTL |SFT|   |   |SFT|CTL |ALT|   |   |       |    |
   * |------------------------------------------------------------------|
   * | BackSpc|  Z|  X|   C|  V|  B|  N|  M|  , |  .|  /| Del  | Up|    |
   * |------------------------------------------------------------------|
   * |    |    |    |         Space/_FL      |App |   |    |Lef|Dow|Rig |
   * `------------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_ESC,   KC_1,         KC_2,                KC_3,                 KC_4,                KC_5,   KC_6,   KC_7,               KC_8,                 KC_9,               KC_0,            KC_MINS, KC_EQL,     KC_NO,    KC_GRV, \
  KC_TAB,   KC_Q,         KC_W,                MT(MOD_LGUI,KC_E),    KC_R,                KC_T,   KC_Y,   KC_U,               MT(MOD_RGUI,KC_I),    KC_O,               KC_P,            KC_LBRC, KC_RBRC,    KC_BSLS,  KC_INS , \
  KC_NO,    LT(_ML,KC_A), MT(MOD_LALT,KC_S),   MT(MOD_LCTL, KC_D),   MT(MOD_LSFT, KC_F),  KC_G,   KC_H,   MT(MOD_RSFT, KC_J), MT(MOD_RCTL,KC_K),    MT(MOD_LALT,KC_L),  KC_SCLN,         KC_QUOT,             KC_ENT ,  KC_CAPS, \
  KC_BSPC,  KC_Z,         KC_X,                KC_C,                 KC_V,                KC_B,   KC_N,   KC_M,               KC_COMM,              KC_DOT,             KC_SLSH,         KC_DEL,              KC_UP  ,  KC_NO, \
  KC_NO,    KC_NO,        KC_NO,                         LT(_FL,KC_SPC),                                                      KC_APP,               KC_NO,              KC_NO,           KC_LEFT,             KC_DOWN,  KC_RGHT),

  /* Layer _ML: Movement Layer
   * ,--------------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |    |     |   |   |   |        |    |
   * |--------------------------------------------------------------------|
   * |     |   |   |   |   |   |    | Home|Up |End |   |   |   |     |    |
   * |--------------------------------------------------------------------|
   * |      |   |   |   |   |   |    |<-  |Dn   | ->|    |   |       |    |
   * |--------------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|   |    |PgUp |  |PgDn|  McL |MsU |McR |
   * |--------------------------------------------------------------------|
   * |    |    |    |       Return           |     |   |    |MsL|MsD |MsR |
   * `--------------------------------------------------------------------'
   */
[_ML] = KEYMAP_ANSI(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______ ,\
  _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP  , KC_END ,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, \
  _______, _______, _______, BL_DEC , BL_TOGG, BL_INC , _______, KC_PGUP, _______,  KC_PGDN, _______, KC_BTN1, KC_MS_U, KC_BTN2, \
  _______, _______, _______,                 KC_ENT,                      _______, _______,  _______, KC_MS_L, KC_MS_D, KC_MS_R),

  /* Layer _FL: Function Layer
   * ,------------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9  |F10|F11|F12|        |    |
   * |------------------------------------------------------------------|
   * |     |   |   |   |   |   |    |     |  |   |   |   |   |     |    |
   * |------------------------------------------------------------------|
   * |      |   |   |   |   |   |    |   |    |   |    |   |       |    |
   * |------------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |    |   |   |      |    |    |
   * |------------------------------------------------------------------|
   * |    |    |    |                       |    |   |    |   |    |    |
   * `------------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  _______,  KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10 , KC_F11,  KC_F12 , _______, _______,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______, _______, _______, _______, \
  _______, _______, _______,                 _______,                     _______, _______ , _______, _______, _______, _______)
};



