#include QMK_KEYBOARD_H

#define _BASE  0
#define _CURS  1
#define _NUM   2
#define _SYMB  3
#define _FUNL  5
#define _FLASH 6

#define _ XXXXXXX 

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))


#define MY_F MT(MOD_LSFT, KC_F)
#define MY_4 MT(MOD_LSFT, KC_4)
#define MY_F4 MT(MOD_LSFT, KC_F4)

#define MY_J MT(MOD_RSFT, KC_J)
#define MY_7 MT(MOD_RSFT, KC_7)
#define MY_F7 MT(MOD_RSFT, KC_F7)

#define MY_D MT(MOD_LCTL, KC_D)
#define MY_3 MT(MOD_LCTL, KC_3)
#define MY_F3 MT(MOD_LCTL, KC_F3)

#define MY_K MT(MOD_RCTL, KC_K)
#define MY_8 MT(MOD_RCTL, KC_8)
#define MY_F8 MT(MOD_RCTL, KC_F8)

#define MY_S MT(MOD_LALT, KC_S)
#define MY_2 MT(MOD_LALT, KC_2)
#define MY_F2 MT(MOD_LALT, KC_F2)


#define MY_L MT(MOD_LALT, KC_L)
#define MY_9 MT(MOD_LALT, KC_9)
#define MY_F9 MT(MOD_LALT, KC_F9)

#define MY_A MT(MOD_LGUI, KC_A)
#define MY_1 MT(MOD_LGUI, KC_1)
#define MY_F1 MT(MOD_LGUI, KC_F1)


#define MY_SCLN MT(MOD_RGUI, KC_SCLN)
#define MY_0 MT(MOD_RGUI, KC_0)
#define MY_F10 MT(MOD_RGUI, KC_F10)




#define MY_DEL LT(_FUNL, KC_DEL)
#define MY_SPC LT(_NUM, KC_SPC)
#define MY_RET LT(_CURS, KC_ENTER)


/* #define MY_Q LT(MEDI, KC_Q) */
/* #define MY_G MT(MOD_HYPR, KC_G) */
/* #define MY_H MT(MOD_HYPR, KC_H) */



enum custom_keycodes {
    MYARROW = SAFE_RANGE,
    MYDARROW
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MYARROW:
        if (record->event.pressed) {
          SEND_STRING("->");
        }
        break;
    case MYDARROW:
        if (record->event.pressed) {
          SEND_STRING("=>");
        }
        break;
  };
  return true;
}





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * | Super|  Alt | Ctrl |Shift |      |           |      | Shift| Ctrl | Alt  | Super|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  | _Flsh| BckSp|      |    |      | Del  |      |
 *                  |      | SYMB | RET  |    |Space | FUNL |      |
 *                  `-------------| CURS |    |NUMB  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_BASE] = LAYOUT_split_3x5_3( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  MY_A,    MY_S,    MY_D,    MY_F,    KC_G,         KC_H,    MY_J,    MY_K,    MY_L,    MY_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
    MO(_FLASH),    LT(_SYMB, KC_BSPC),   MY_RET,       MY_SPC,  MY_DEL,  _______	\
),

/* CURS
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           | =>   | Home |  Up  | End  |  `   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  `   |      |      |      |      |           |      |  <-  |      |  ->  |  '   |
 * |Super |  Alt | Ctrl |Shift |      |           | Ins  |      | Down |      |  "   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           | WCaps| PgUp | CAPS |PgDown|      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |  Tab |      |
 *                  `-------------|      |    |Return|------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_CURS] = LAYOUT_split_3x5_3( \
  _,       _,       _______, _,       _,            MYDARROW,  KC_HOME,  KC_UP,    KC_END,    KC_GRV,  \
  KC_GRV,  _______, _______, _______, _,            KC_INS,    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_QUOTE, \
  _,       _,       _,       _,       _,            CW_TOGG,   KC_PGUP,  KC_CAPS,  KC_PGDN,   KC_BSLS,  \
                    _,       _,       _,            KC_ENTER,  KC_TAB,   _                 \
),

/* NUM
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  !   |  @   |   #  |  $   |  %   |           |      |   -  |  =   |  +   |  *   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |           |  6   |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT_split_3x5_3( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    _,       KC_MINS,   KC_EQL,  KC_PPLS,  KC_ASTR,      \
  MY_1,    MY_2,    MY_3,    MY_4,    KC_5,       KC_6,    MY_7,      MY_8,     MY_9,     MY_0,   \
  KC_CIRC, KC_AMPR, _,       _,          _,       _,       _      ,   KC_COMM,  KC_DOT,   KC_SLSH,      \
                    _,       _______, _,          _,       _,         _ \
),
/* FUNL
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F11 |  F12 |  F12 |  F14 |  F15 |           |  F16 |  F17 |  F18 |  F19 | F20  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------| Esc  |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FUNL] = LAYOUT_split_3x5_3( \
  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,    KC_F16,  KC_F17,   KC_F18,   KC_F19,  KC_F20,   \
  MY_F1,   MY_F2,   MY_F3,   MY_F4,   KC_F5,     KC_F6,   MY_F7,    MY_F8,    MY_F9,   MY_F10,   \
  _,       _,       _,       _,          _,       _,        _,        _,       _,   _,       \
                    _,       KC_ESC,       _,          _,       _,       _ \
),

/* 
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |   _  |  *   |  ~   |  |   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  <   |  {   |  [   |   (  |      |           |      |  )   |   ]  |  }   |   >  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |  \   |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYMB] = LAYOUT_split_3x5_3( \
  _,       _,       _,   _,       _,          MYARROW, KC_UNDS, KC_ASTR,   KC_TILD,  KC_PIPE,   \
  KC_LT,       KC_LCBR, KC_LBRC, KC_LPRN, _,          _,       KC_RPRN, KC_RBRC, KC_RCBR,  KC_GT,    \
  _,       _,       _,       _,       _,          _,       _,       _,       _,        KC_BSLS,   \
                    _,       _, _______,          _,       _,       _ \
),
/* FLASH
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      | Boot |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FLASH] = LAYOUT_split_3x5_3( \
  _,       _,       _,       _,       _,          _,       _,       _,     _,     _,        \
  _,       _,       _,       _,       _,          _,       _,       _,     _,     _,        \
  _,       _,       _,       _,       _,          _,       _,       _,     _,    QK_BOOT,   \
                    _,       _,       _,          _,       _,       _ \
)
};
