/*
Copyright 2015 Jun Wako <wakojun@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"

#define _BL 0
#define _ML 1
#define _FL 2

#define _______ KC_TRNS


const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: Default Layer
   * ,--------------------------------------------------------------------.
   * |Esc|  1|  2|    3|  4|  5|  6|  7|    8|  9|  0|  -|  =|  \|  `|    |
   * |--------------------------------------------------------------------|
   * |Tab  |  Q|  W|    E|  R|  T|  Y|  U|    I|  O|  P|  [|  ]|     |Ins |
   * |     |   |   | LGUI|   |   |   |   | RGUI|   |   |   |   |     |    |
   * |--------------------------------------------------------------------|
   * |      |  A|  S|    D|  F|  G|  H|  J|    K|  L|  ;|  '|Enter   |CAPS|
   * |      |_ML|ALT|  CTL|SFT|   |   |SFT| CTL |ALT|   |   |        |    |
   * |--------------------------------------------------------------------|
   * |BKSP|   |  Z|  X|    C|  V|  B|  N|  M|    ,|  .|  /| Del  |Up |    |
   * |--------------------------------------------------------------------|
   * |    |    |    |       Space/_FL    |    |      |    |  |Lef|Dow|Rig |
   * `--------------------------------------------------------------------'
   */



    [_BL] = KEYMAP( \
          KC_ESC,  KC_1,         KC_2,                KC_3,                 KC_4,                KC_5,   KC_6,   KC_7,               KC_8             ,    KC_9,                KC_0,    KC_MINS, KC_EQL,  KC_BSLS,KC_GRV, KC_NO, \
          KC_TAB,  KC_Q,         KC_W,                MT(MOD_LGUI,KC_E),    KC_R,                KC_T,   KC_Y,   KC_U,               MT(MOD_RGUI,KC_I),    KC_O,                KC_P,    KC_LBRC, KC_RBRC, KC_NO,        KC_INS, \
          KC_NO,   LT(_ML,KC_A), MT(MOD_LALT,KC_S),   MT(MOD_LCTL, KC_D),   MT(MOD_LSFT, KC_F),  KC_G,   KC_H,   MT(MOD_RSFT, KC_J), MT(MOD_RCTL,KC_K),    MT(MOD_LALT,KC_L),   KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,         KC_CAPS,\
          KC_BSPC, KC_NO,        KC_Z,                KC_X,                 KC_C,                KC_V,   KC_B,   KC_N,               KC_M             ,    KC_COMM,             KC_DOT,  KC_SLSH, KC_DEL,  KC_UP,          KC_NO,\
          KC_NO,   KC_NO,        KC_NO,                                                     LT(_FL,KC_SPC),                          KC_NO,                KC_NO,               KC_NO,            KC_LEFT, KC_DOWN,        KC_RGHT \
    ),
    /* Layer _ML: Movement Layer
     * ,----------------------------------------------------------------------.
     * |   |   |   |     |   |   |   |    |     |   |    |   |   |   |   |    |
     * |----------------------------------------------------------------------|
     * |     |   |   |     |   |   |   |PgUp| Up  |PgDn|   |   |   |     |    |
     * |----------------------------------------------------------------------|
     * |      |   |   |     |   |   |HOM|Left|Down |Rght|End|   |        |    |
     * |----------------------------------------------------------------------|
     * |    |   |   |   |     |   |   |   |    |     |    |   |   McL|MsU|McR |
     * |----------------------------------------------------------------------|
     * |    |    |    |      Return        |     |      |     |  |MsL|MsD|MsR |
     * `----------------------------------------------------------------------'
     */


    [_ML] = KEYMAP( \
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,\
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_PGUP,  KC_UP,    KC_PGDN,  KC_NO,    KC_NO, KC_NO,   KC_NO,          KC_NO,  \
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,   KC_NO, KC_NO,   KC_NO,          KC_NO,\
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_BTN1, KC_MS_U, KC_BTN2,\
        KC_NO,    KC_NO,    KC_NO,                     KC_ENT,                          KC_NO,    KC_NO,    KC_NO,           KC_MS_L, KC_MS_D, KC_MS_R  \
    ),
    /* Layer _FL: Function Layer
     * ,----------------------------------------------------------------------.
     * |   | F1| F2|   F3| F4| F5| F6|  F7|   F8| F9| F10|F11|F12|   |   |    |
     * |----------------------------------------------------------------------|
     * |     |   |   |     |   |   |   |    |     |    |   |   |   |     |    |
     * |----------------------------------------------------------------------|
     * |      |   |   |     |   |   |   |    |     |    |   |   |        |    |
     * |----------------------------------------------------------------------|
     * |    |   |   |   |     |   |   |   |    |     |    |   |      |   |    |
     * |----------------------------------------------------------------------|
     * |    |    |    |                    |     |      |     |  |   |   |    |
     * `----------------------------------------------------------------------'
     */
    [_FL] = KEYMAP( \
        KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_NO,  KC_NO,  KC_NO,\
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  \
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,\
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,  KC_NO,\
        KC_NO,  KC_NO,  KC_NO,                 KC_NO,            KC_NO,  KC_NO,  KC_NO,       KC_NO ,KC_NO ,KC_NO  \
                    ),
};

const uint16_t fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
};
