/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

#define _BASE 0  // Base
#define _SY   1  // Symbols
#define _MO   2  // Movements
#define _NU   3  // Numbers
#define _NU2   6  // Numbers
#define _FN   4  // Function keys
#define _MD   5  // Media

#define MY_W LT(_MD,KC_W)
#define MY_A LT(_MO,KC_A)
#define MY_Q LT(_SY, KC_Q)
#define MY_S MT(MOD_LALT,KC_S)
#define MY_E MT(MOD_LGUI, KC_E)
#define MY_D MT(MOD_LCTL,KC_D)
#define MY_F MT(MOD_LSFT,KC_F)
#define MY_J MT(MOD_RSFT,KC_J)
#define MY_I MT(MOD_RGUI,KC_I)
#define MY_K MT(MOD_RCTL,KC_K)
#define MY_L MT(MOD_LALT,KC_L)
#define MY_SPC LT(_NU,KC_SPC)

#define MY_3 MT(MOD_LGUI,KC_3)
#define MY_8 MT(MOD_RGUI,KC_8)
#define MY_DOT MT(MOD_LALT,KC_DOT)


#define MY_FN MO(_FN)

#define _____ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     |-------+---+---+------+---+---+---+---+------+---+---+------+----+---+---;
     |       |   |   |      |   |   |   |   |      |   |   |      |    |   |   |
     |-------+---+---+------+---+---+---+---+------+---+---+------+----+-------|
     |Tab    | Q | W |  E   | R | T | Y | U |  I   | O | P | [    | ]  |  \    |
     |       |_SY|_MD| LGUI |   |   |   |   | RGUI |   |   |      |    |       |
     |-------+---+---+------+---+---+---+---+------+---+---+------+----+-------|
     | ESC   | A | S |  D   | F | G | H | J |  K   | L | ; | '    |  Enter     |
     |       |_MO|ALT| CTL  |SFT|   |   |SFT| CTL  |ALT|   |      |            |
     |-------+---+---+------+---+---+---+---+------+---+---+------+-----+------|
     |BackSpc| Z | X |  C   | V | B | N | M |  ,   | . | / | Del        |      |
     |-------+---+---+------+---+---+---+---+------+---+---+------+-----+------|

            |------+------+-----------------------+------+------|
            |      |      |       Space/_NU       | App  |      |
            |------+------+-----------------------+------+------|
    */

    [_BASE] = LAYOUT( //  default layer
        _____,   _____, _____, _____, _____, _____, _____, _____, _____,   _____,   _____,    _____,   _____,    _____,    _____,
        KC_TAB,  MY_Q,  MY_W,  MY_E,  KC_R,  KC_T,  KC_Y,  KC_U,  MY_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC,  KC_BSLS,
        KC_ESC,  MY_A,  MY_S,  MY_D,  MY_F,  KC_G,  KC_H,  MY_J,  MY_K,    MY_L,    KC_SCLN,  KC_QUOT, KC_ENT,
        KC_BSPC, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL,  _____,
        _____,   _____,               MY_SPC,                KC_APP,      _____),

    /* Symbols
      |------+-----+-----+-----+----+----+----+----+---+----+----+----+----+----+----|
      |      |     |     |     |    |    |    |    |   |    |    |    |    |    |    |
      |------+-----+-----+-----+----+----+----+----+---+----+----+----+----+----+----|
      |      |     |     | LGUI|    |    | `  | (  | + |  ) | \| |    |    |         |
      |------+-----+-----+-----+----+----+----+----+---+----+----+----+----+----+----|
      |      |     | ALT | CTL | SFT|    | ~  | [  | = |  ] | '  |    |              |
      |------+-----+-----+-----+----+----+----+----+---+----+----+----+----+----+----|
      |      |     |     |     |    |    |    | {  | - |  } | _  |         |    |
      |------+-----+-----+-----+----+----+----+----+---+----+-----+----+----+----+----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+
     */

    [_SY] = LAYOUT(
        _____, _____, _____,   _____,   _____,   _____, _____,  _____,   _____,   _____,   _____,   _____, _____, _____, _____,
        _____, _____, _____,   KC_LGUI, _____,   _____, KC_GRV, KC_LPRN, KC_PLUS, KC_RPRN, KC_BSLS, _____, _____, _____,
        _____, _____, KC_LALT, KC_LCTL, KC_LSFT, _____, KC_TILD,  KC_LBRC, KC_EQL,  KC_RBRC, KC_QUOT, _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____,  KC_LCBR, KC_MINS, KC_RCBR,   KC_UNDS, _____, _____,
        _____, _____,                    _____,               _____,   _____),

    /* Layer _MV: Movement Layer
      |------+-----+-----+-----+----+----+------+----+-----+-----+-------+-----+-----+----+----|
      |      |     |     |     |    |    |      |    |     |     |       |     |     |    |    |
      |------+-----+-----+-----+----+----+------+----+-----+-----+-------+-----+-----+----+----|
      |      |     |     | LGUI|    |    |      |Home| Up  | End | Esc   |     |     |         |
      |------+-----+-----+-----+----+----+------+----+-----+-----+-------+-----+-----+----+----|
      |      |     | ALT | CTL | SFT|    | BckSp| <- | Dn  | ->  | Del   |     |     |         |
      |------+-----+-----+-----+----+----+------+----+-----+-----+-------+-----+-----+----+----|
      |      |     |     |     |    |    |      |PgUp| Ins |PgDn | Tab  |           |         |
      |------+-----+-----+-----+----+----+------+----+-----+-----+-------------------+---------|

                 |------+------+----------------------+------+------+
                 |      |      |       Enter          |      |      |
                 |------+------+----------------------+------+------+

     */

    [_MO] = LAYOUT(
        _____, _____, _____,   _____,   _____,   _____, _____,   _____,   _____,  _____,    _____,    _____, _____, _____, _____,
        _____, _____, _____,   KC_LGUI, _____,   _____, _____,   KC_HOME, KC_UP,   KC_END,   KC_ESC,   _____, _____, _____,
        _____, _____, KC_LALT, KC_LCTL, KC_LSFT, _____, KC_BSPC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,   _____, _____,
        _____, _____, _____,   _____,   _____,   _____, KC_CAPS, KC_PGUP, KC_INS,   KC_PGDN,  KC_TAB,  _____, _____,
        _____, _____,                  KC_ENT,                   _____,   _____),



    /* Numbers
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+----+----+----+----|
      |      |     |     |     |    |    |    |    |     |     |     |    |    |    |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+----+----+----+----|
      |      |     |     | LGUI|    |    |    | 7  |  8  | 9   |     |    |    |         |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+----+----+----+----|
      |      | FN  | ALT | CTL |SFT |    |    | 4  |  5  | 6   | 0   |    |              |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+----+----+----+----|
      |      |     |     |     |    |    |    | 1  |  2  | 3   |     |    |         |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+----+----+----+----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [_NU] = LAYOUT(
        _____, _____, _____,   _____,   _____,   _____, _____,   _____,   _____,   _____,   _____,  _____, _____, _____, _____,
        _____, KC_1,  KC_2,    MY_3,    KC_4,    KC_5,  KC_6,    KC_7,    MY_8,    KC_9,    KC_0,   _____, _____, _____,
        _____, MY_FN, KC_LALT, KC_LCTL, KC_LSFT, _____, KC_BSPC, KC_RSFT, KC_RCTL, MY_DOT,  KC_DEL, _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____,   _____,   _____,   _____,   _____,  _____, _____,
        _____, _____, _____,   _____,   _____),

    /* Numbers
      |------+-----+-----+----+----+----+----+----+----+-----+-----+----+----+----+----|
      |      |     |     |    |    |    |    |    |    |     |     |    |    |    |    |
      |------+-----+-----+----+----+----+----+----+----+-----+-----+----+----+----+----|
      |      |  1  |  2  | 3  | 4  | 5  | 6  | 7  |  8 | 9   |  0  |    |    |         |
      |      |     |     |LGUI|    |    |    |    |RGUI|     |     |    |    |         |
      |------+-----+-----+----+----+----+----+----+----+-----+-----+----+----+----+----|
      |      |     |     |    |    |    |    |    |    |  .  |     |    |              |
      |      | FN  | ALT |CTL |SFT |    |Bsp |SFT |CTL | ALT | Del |    |              |
      |------+-----+-----+----+----+----+----+----+-----+----+-----+----+----+----+----|
      |      |     |     |    |    |    |    |    |     |    |     |    |         |    |
      |------+-----+-----+----+----+----+----+----+-----+----+-----+----+----+----+----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [_NU2] = LAYOUT(
        _____, _____, _____,   _____,   _____,   _____, _____, _____, _____,  _____, _____, _____, _____, _____, _____,
        _____, _____, _____,   KC_LGUI, _____,   _____, _____, KC_7,  KC_8,  KC_9,   _____, _____, _____, _____,
        _____, MY_FN, KC_LALT, KC_LCTL, KC_LSFT, _____, _____, KC_4,  KC_5,  KC_6,   KC_0,  _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____, KC_1,  KC_2,  KC_3,   _____, _____, _____,
        _____, _____, _____,   _____,   _____),

    /* Function keys
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+---+---+----+----|
      |      |     |     |     |    |    |    |    |     |     |     |   |   |    |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+---+---+----+----|
      |      |     |     | LGUI|    |    |    | F7 | F8  | F9  | F12 |   |   |         |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+---+---+----+----|
      |      |     | ALT | CTL |SFT |    |F13 | F4 | F5  | F6  | F10 |   |             |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+---+---+----+----|
      |      |     |     |     |    |    |    | F1 | F2  | F3  | F11 |   |        |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+---+---+----+----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [_FN] = LAYOUT(
        _____, _____,   _____,   _____,   _____,   _____, _____,  _____,  _____,  _____,  _____, _____, _____, _____, _____,
        _____, _____,   _____,   KC_LGUI, _____,   _____, _____,  KC_F7,  KC_F8, KC_F9,  KC_F12,  _____,  _____, _____,
        _____, MO(_FN), KC_LALT, KC_LCTL, KC_LSFT, _____, KC_F13, KC_F1,  KC_F5, KC_F6,  KC_F10,  _____,  _____,
        _____, _____,   _____,   _____,   _____,   _____, _____,  KC_F1,  KC_F2, KC_F3,  KC_F11,  _____,  _____,
        _____, _____,   KC_TRNS, _____,   _____),



    /* Layer _MD: Media Layer
      |------+-----+-----+-----+----+----+----+----+-----+-----+----+----+----+----+----|
      |      |     |     |     |    |    |    |    |     |     |    |    |    |    |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+----+----+----+----+----|
      |      |     |     |     |    |    |    |Play| VOL+|     |    |    |    |         |
      |------+-----+-----+-----+----+----+----+----+-----+-----+----+----+----+----+----|
      |      |     |     |     |    |    |    |<== | VOL-| ==> |    |    |              |
      |------+-----+-----+-----+----+----+----+----+-----+-----+----+----+----+----+----|
      |      |     |     |     |    |    |    |    |     |     |    |    |         |    |
      |------+-----+-----+-----+----+----+----+----+-----+-----+----+----+----+----+----|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [_MD] = LAYOUT(
        _____, _____, _____,   _____,   _____,   _____, _____,   _____,    _____,   _____,    _____,  _____, _____, _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____,   KC_MPLY,  KC_VOLU, _____,    _____, _____, _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____,   KC_MPRV,  KC_VOLD, KC_MNXT,  _____,  _____, _____,
        _____, _____, _____,   _____,   _____,   _____, _____,   _____,    _____,   _____,    _____,  _____, _____,
        _____, _____, _____,  _____,   _____),

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id)
    {
    case 0:
        if (record->event.pressed)
        {
            register_code(KC_RSFT);
        }
        else
        {
            unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};
