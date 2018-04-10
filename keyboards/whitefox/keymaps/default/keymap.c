#include "whitefox.h"

#define BASE 0 // default layer
#define CURS 1 // symbols
#define EXTR 2 // media keys

#define _______ KC_TRNS

// special keys
#define MY_A LT(CURS, KC_A)
#define MY_F MT(MOD_LSFT, KC_F)
#define MY_J MT(MOD_LSFT, KC_J)
#define MY_D MT(MOD_LCTL, KC_D)
#define MY_K MT(MOD_LCTL, KC_K)
#define MY_S MT(MOD_LALT, KC_S)
#define MY_L MT(MOD_LALT, KC_L)

#define MY_FN LT(EXTR, KC_APP)
#define MY_ESC LT(EXTR, KC_ESC)

// macros
#define trigger_time 110
#define T1     M(101)
#define T2     M(102)
#define T3     M(103)
#define T4     M(104)
#define T5     M(105)
#define T6     M(106)
#define T7     M(107)
#define T8     M(108)
#define T9     M(109)
#define T10    M(110)
#define T11    M(111)
#define T12    M(112)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Base Layer
     * ,------------------------------------------------------------------------------------------.
     * |MyEs| 1/F | 2/F | 3/F| 4/F | 5/F | 6/F | 7/F | 8/F | 9/F | 0/F | -/F | =/F |    \|   `|Ins|
     * |------------------------------------------------------------------------------------------|
     * |Tab  |    Q|    W|    E|    R|    T|    Y|    U|    I|    O|    P|    [|    ]|Backs|   Del|
     * |------------------------------------------------------------------------------------------|
     * |Esc   |A/CRS|S/ALT|D/CTL|F/SFT|    G|    H|J/SFT|D/CTL|L/ALT|    ;|    '|  Enter   |   PgU|
     * |------------------------------------------------------------------------------------------|
     * |Backspace |    Z|    X|    C|    V|    B|    N|    M|    ,|    .|    /| Delete| Up |   PgD|
     * |------------------------------------------------------------------------------------------|
     * |    | Gui  |     |           Space                |MyFun|Caps | Gui |    | Lef | Dow | Rig|
     * `------------------------------------------------------------------------------------------'
     */
    [BASE] = KEYMAP(
        MY_ESC , T1     , T2     , T3   , T4   , T5   , T6   , T7   , T8   , T9     , T10     , T11   , T12    , KC_BSLS, KC_GRV , KC_INS,
        KC_TAB , KC_Q   , KC_W   , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSPC         , KC_DEL,
        KC_ESC , MY_A   , MY_S   , MY_D , MY_F , KC_G , KC_H , MY_J , MY_K , MY_L   , KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT          , KC_PGUP,
        KC_BSPC, _______, KC_Z   , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_DEL          , KC_UP  , KC_PGDN,
        _______, KC_LGUI, _______,                  KC_SPC                          , KC_CAPS, MY_FN  , _______, KC_LEFT, KC_DOWN, KC_RGHT),



    /* Layer 1: Cursor Layer
     * ,------------------------------------------------------------------------------------------.
     * |   |     |     |     |     |     |     |     |     |     |     |     |     |     |    |   |
     * |------------------------------------------------------------------------------------------|
     * |     |     |     |     |     |     |     | Home|   Up| End |     |     |     |     |      |
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
        _______, _______, _______, _______, _______, _______, _______, KC_HOME,  KC_UP , KC_END , _______, _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , _______, _______, _______         , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______         , _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______),


    /* Layer 2: Extra Layer
     * ,------------------------------------------------------------------------------------------.
     * |   |     |     |     |     |     |     |     |     |     |     |     |     |     |    |   |
     * |------------------------------------------------------------------------------------------|
     * |VolUp|     |     |     |     |     |     |     | Ins |     |     |     |     |     |VolUp |
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
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, KC_INS , _______, _______, _______, _______, _______         , KC_VOLU,
        KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , KC_MUTE,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______         , _______, KC_VOLD,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______)
};


// macro routines
static uint16_t key_timer;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
		case 101:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F1), END );
				}
				else {
					return MACRO( T(1), END );
				}
			}
			break;
		case 102:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F2), END );
				}
				else {
					return MACRO( T(2), END );
				}
			}
			break;
		case 103:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F3), END );
				}
				else {
					return MACRO( T(3), END );
				}
			}
			break;
		case 104:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F4), END );
				}
				else {
					return MACRO( T(4), END );
				}
			}
			break;
		case 105:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F5), END );
				}
				else {
					return MACRO( T(5), END );
				}
			}
			break;
		case 106:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F6), END );
				}
				else {
					return MACRO( T(6), END );
				}
			}
			break;
		case 107:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F7), END );
				}
				else {
					return MACRO( T(7), END );
				}
			}
			break;
		case 108:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F8), END );
				}
				else {
					return MACRO( T(8), END );
				}
			}
			break;
		case 109:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F9), END );
				}
				else {
					return MACRO( T(9), END );
				}
			}
			break;
		case 110:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F10), END );
				}
				else {
					return MACRO( T(0), END );
				}
			}
			break;
		case 111:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F11), END );
				}
				else {
					return MACRO( T(MINS), END );
				}
			}
			break;
		case 112:
			if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(F12), END );
				}
				else {
					return MACRO( T(EQL), END );
				}
			}
			break;
    case 121:
      if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(ENT), END );
				}
				else {
					return MACRO( T(M), END );
				}
			}
      break;
    case 122:
      if (record->event.pressed) {
				key_timer = timer_read();
			}
			else {
				if (timer_elapsed(key_timer) > trigger_time) {
					return MACRO( T(ESC), END );
				}
				else {
					return MACRO( T(V), END );
				}
			}
      break;
  }
  return MACRO_NONE;
};
