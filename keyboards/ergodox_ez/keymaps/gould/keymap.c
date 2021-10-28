#include QMK_KEYBOARD_H
#include "version.h"

#define _BL 0 // Base Layer
#define _ML 1 // Movement Layer
#define _NM 2 // Numbers
#define _FN 3 // Function keys

#define _____ KC_NO

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _BL: Base layer (Default layer)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |        | _NM  |      | LGUI |      |      |      |           |      |      |      | RGUI |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Esc  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |        | _ML  | Alt  | Ctrl |Shift |      |      |           |      |      |Shift |Ctrl  | Alt  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Bckspc |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   Del  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | _NM  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Space |      |------|       |------|        | Enter|
 *                                 | _FN  |      |      |       |      |        |  _FN |
 *                                 `--------------------'       `----------------------'
 */
[_BL] = LAYOUT_ergodox(
  // left hand
  _____,        KC_1,          KC_2,               KC_3,               KC_4,                KC_5,       _____,
  KC_TAB,       LT(_NM,KC_Q),  KC_W,               MT(MOD_LGUI,KC_E),  KC_R,                KC_T,       _____,
  KC_ESC,       LT(_ML,KC_A),  MT(MOD_LALT,KC_S),  MT(MOD_LCTL,KC_D),  MT(MOD_LSFT,KC_F),   KC_G,
  KC_BSPC,      KC_Z,          KC_X,               KC_C,               KC_V,                KC_B,       _____,
  _____,        _____,         _____,              _____,              MO(_NM),

                                                                                            _____,     _____,
                                                                                                       _____,
                                                                       LT(_FN,KC_SPC),      _____,     _____,

  // right hand
  _____,        KC_6,        KC_7,               KC_8,               KC_9,               KC_0,      KC_MINS,
  _____,        KC_Y,        KC_U,               MT(MOD_RGUI,KC_I),  KC_O,               KC_P,      _____,
                KC_H,        MT(MOD_RSFT,KC_J),  MT(MOD_RCTL,KC_K),  MT(MOD_LALT,KC_L),  KC_SCLN,   KC_QUOT,
  _____,       KC_N,        KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,   KC_DEL,
                             _____,              _____,              _____,              _____,     _____,

  _____,        _____,
  _____,
  _____,        _____,       LT(_FN,KC_ENT)
 ),


/* _ML: Movement layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | LGUI |      |      |      |           |      |      | Home |  Up  | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Ctrl |Shift |      |------|           |------|      |  <-  | Down |  ->  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | PgUp |      | PgDn |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_ML] = LAYOUT_ergodox(
  // left hand
  _____,        _____,        _____,              _____,             _____,      _____,       _____,
  _____,        _____,        _____,              KC_TRNS,           _____,      _____,       _____,
  _____,        _____,        KC_TRNS,            KC_TRNS,           KC_TRNS,    _____,
  _____,        _____,        _____,              _____,             _____,      _____,       _____,
  _____,        _____,        _____,              _____,             _____,

                                                                                  _____,     _____,
                                                                                             _____,
                                                                       _____,     _____,     _____,

  // right hand
  _____,        _____,        _____,               _____,             _____,            _____,    _____,
  _____,        _____,        KC_HOME,             KC_UP,             KC_END,           _____,    _____,
                _____,        KC_LEFT,             KC_DOWN,           KC_RIGHT,         _____,    _____,
  _____,        _____,        KC_PGUP,             _____,             KC_PGDN,            _____,     _____,
                              _____,               _____,             _____,           _____,     _____,

  _____,        _____,
  _____,
  _____,        _____,        _____
 ),



/* _NM: Numbers Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  7   |   8  |   9  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | LGUI |      |      |      |           |      |      |  4   |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Ctrl |Shift |      |------|           |------|      |  1   |  2   |   3  |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  0   |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_NM] = LAYOUT_ergodox(
  // left hand
  _____,        _____,        _____,              _____,             _____,      _____,       _____,
  _____,        _____,        _____,              MOD_LGUI,          _____,      _____,       _____,
  _____,        _____,        MOD_LALT,           MOD_LCTL,          MOD_LSFT,   _____,
  _____,        _____,        _____,              _____,             _____,      _____,       _____,
  _____,        _____,        _____,              _____,              _____,

                                                                                  _____,     _____,
                                                                                             _____,
                                                                       _____,     _____,     _____,

  // right hand
  _____,        _____,        KC_7,                KC_8,              KC_9,            _____,    _____,
  _____,        _____,        KC_4,                KC_5,              KC_6,             _____,    _____,
                _____,        KC_1,                KC_2,              KC_3,             _____,    _____,
  _____,        _____,        KC_0,                _____,             _____,             _____,     _____,
                              _____,               _____,             _____,           _____,     _____,

  _____,        _____,
  _____,
  _____,        _____,        _____
),


/* _FN: Functions Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  | F3   |  F4  |  F5  |      |           |      |  F6  |  F7  | F8   | F9   |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | LGUI |      |      |      |           |      |      |      | RGUI |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Alt  | Ctrl |Shift |      |------|           |------|      | Shift| Ctrl |Alt   |      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[_FN] = LAYOUT_ergodox(
  // left hand
  _____,        KC_F1,        KC_F2,              KC_F3,             KC_F4,      KC_F5,       _____,
  _____,        _____,        _____,              MOD_LGUI,          _____,      _____,       _____,
  _____,        _____,        MOD_LALT,           MOD_LCTL,          MOD_LSFT,   _____,
  _____,        _____,        _____,              _____,             _____,      _____,       _____,
  _____,        _____,        _____,              _____,              _____,

                                                                                  _____,     _____,
                                                                                             _____,
                                                                       _____,     _____,     _____,

  // right hand
  _____,        KC_F6,        KC_F7,                KC_F8,              KC_F9,             KC_F10,    KC_F11,
  _____,        _____,        _____,                KC_RGUI,            _____,             _____,     KC_F12,
                _____,        KC_RSFT,              KC_LCTL,            KC_LALT,           _____,     _____,
  _____,        _____,        _____,                _____,              _____,             _____,     _____,
                              _____,                _____,              _____,             _____,     _____,

  _____,        _____,
  _____,
  _____,        _____,        _____
)



};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
