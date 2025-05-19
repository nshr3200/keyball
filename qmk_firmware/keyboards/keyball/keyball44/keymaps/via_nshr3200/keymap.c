/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer {
  _BASE,
  _SYM,
  _NUM,
  _NAV,
  _BSDL,
  _GAME
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [_BASE] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
LT(_BSDL,KC_TAB),KC_A   , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT   ,
    KC_LGUI  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RGUI  ,
                          KC_NO    , KC_NO    , MO(_NUM) , MO(_SYM) , KC_LCTL ,                   KC_RALT  ,  LT(_NAV,KC_SPC)     , XXXXXXX  , XXXXXXX  , TO(_GAME)
  ),

  [_SYM] = LAYOUT_universal(
    KC_NO    , KC_HASH  , KC_CIRC  , KC_ASTR  , KC_LCBR  , KC_QUOT  ,                                        KC_DQUO  , KC_RCBR  , KC_AMPR  , KC_DLR   , KC_BSLS  , KC_COLN  ,
    KC_NO    , KC_PERC  , KC_EXLM  , KC_EQL   , KC_LPRN  , KC_PLUS  ,                                        KC_ENT   , KC_RPRN  , KC_COLN  , KC_QUES  , KC_SCLN  , KC_ENT   ,
    KC_NO    , KC_LABK  , KC_PIPE  , KC_MINS  , KC_RABK  , KC_AT    ,                                        KC_GRV   , KC_LBRC  , KC_COMM  , KC_DOT   , KC_RBRC  , KC_NO    ,
                          KC_NO    , KC_NO    , KC_NO    , XXXXXXX  , KC_NO   ,                  KC_RALT  ,  KC_SPC              , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [_NUM] = LAYOUT_universal(
    KC_NO    , KC_0     , KC_7     , KC_8     , KC_9     , KC_ASTR  ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_0     , KC_4     , KC_5     , KC_6     , KC_PLUS  ,                                        KC_ENT   , KC_NO    , KC_COLN  , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_0     , KC_1     , KC_2     , KC_3     , KC_MINS  ,                                        KC_NO    , KC_NO    , KC_COMM  , KC_DOT   , KC_SLSH  , KC_NO    ,
                          KC_NO    , KC_NO    , XXXXXXX  , KC_NO    , KC_NO    ,                 KC_NO    ,  KC_SPC              , XXXXXXX  , XXXXXXX  , KC_NO
  ),

  [_NAV] = LAYOUT_universal(
    KC_NO    , KC_NO     , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,                                        KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_NO    , KC_NO    ,
    KC_NO    , KC_RALT   , KC_LSFT  , KC_NO    , KC_NO    , KC_LGUI ,                                        KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO     , KC_NO    , KC_LCTL  , KC_NO    , KC_NO   ,                                        KC_NO    , KC_LBRC  , KC_HASH  , KC_RBRC  , KC_NO    , KC_NO    ,
                           KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_NO    ,                 KC_NO    ,  XXXXXXX             , XXXXXXX  , XXXXXXX  , XXXXXXX
  ),

  [_BSDL] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_ENT   , KC_BSPC  , KC_DEL   , KC_NO    , KC_NO    ,
                          KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                  KC_NO    , KC_NO               , XXXXXXX  , XXXXXXX  , KC_NO
  ),

  [_GAME] = LAYOUT_universal(
    KC_NO    , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_NO    ,
    KC_NO    , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_NO       ,
    KC_NO    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_NO    ,
                          TO(_BASE), TO(_BASE), KC_NO    , KC_RSFT  , KC_NO    ,                  KC_NO   ,  KC_SPC              , XXXXXXX  , XXXXXXX  , KC_NO
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef COMBO_ENABLE

const uint16_t PROGMEM my_jq[] = {KC_J, KC_Q, COMBO_END};

combo_t key_combos[] = {
COMBO(my_jq, KC_QUES),
};
#endif
