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

enum combo_events {
  COMM_DOT_UNDERSCORE,
  DOT_SLSH_TILD,
  J_K_L_LNG1,
  S_D_F_LNG2,
  COMBO_LENGTH
};

enum layer {
  _BASE,
  _BSDL,
  _NUM,
  _SYM,
  _NAV,
  _GAME
};

enum custom_keycodes {
    OS_MAC = SAFE_RANGE,
    OS_WIN,
    OS_CTL,
};

const uint16_t PROGMEM comm_dot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM dot_slsh[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM j_k_l[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM s_d_f[] = {KC_S, KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMM_DOT_UNDERSCORE] = COMBO(comm_dot, KC_UNDS),
  [DOT_SLSH_TILD] = COMBO(dot_slsh, KC_TILD),
  [J_K_L_LNG1] = COMBO(j_k_l, KC_LNG1),
  [S_D_F_LNG2] = COMBO(s_d_f, KC_LNG2),
};// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [_BASE] = LAYOUT_universal(
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_NO    ,
LT(_NAV,KC_TAB),KC_A    , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_ENT   ,
    KC_LGUI  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , LT(_NUM,KC_SLSH)    , KC_RGUI ,
                          KC_NO    , KC_NO    , KC_RALT  , MO(_SYM) , OS_CTL   ,                  KC_RSFT  , KC_SPC              , XXXXXXX  , XXXXXXX  , MO(_NAV)
  ),

  [_BSDL] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_BTN1  , KC_BTN2  , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
                          KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                  KC_NO    , KC_NO               , XXXXXXX  , XXXXXXX  , KC_NO
  ),

  [_NUM] = LAYOUT_universal(
    KC_NO    , KC_0     , KC_7     , KC_8     , KC_9     , KC_ASTR  ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KC_NO    , KC_0     , KC_4     , KC_5     , KC_6     , KC_PLUS  ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , XXXXXXX  , KC_NO    ,
    KC_NO    , KC_0     , KC_1     , KC_2     , KC_3     , KC_MINS  ,                                        KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
                          KC_COMM  , KC_DOT   , KC_RALT  , MO(_SYM) , OS_CTL   ,                  KC_RSFT  , KC_SPC              , XXXXXXX  , XXXXXXX  , KC_NO
  ),

  [_SYM] = LAYOUT_universal(
    KC_NO    , KC_HASH  , KC_CIRC  , KC_ASTR  , KC_LCBR  , KC_QUOT  ,                                        KC_DQUO  , KC_RCBR  , KC_AMPR  , KC_DLR   , KC_BSLS  , KC_COLN  ,
    MO(_SYM) , KC_PERC  , KC_EXLM  , KC_EQL   , KC_LPRN  , KC_PLUS  ,                                        KC_ENT   , KC_RPRN  , KC_COLN  , KC_QUES  , KC_SCLN  , KC_ENT   ,
    KC_LGUI  , KC_LABK  , KC_PIPE  , KC_MINS  , KC_RABK  , KC_AT    ,                                        KC_GRV   , KC_LBRC  , KC_COMM  , KC_DOT   , KC_RBRC  , KC_NO    ,
                          OS_WIN   , OS_MAC   , KC_RALT  , XXXXXXX  , OS_CTL   ,                  KC_RSFT  , KC_SPC              , XXXXXXX  , XXXXXXX  , AML_TO
  ),

  [_NAV] = LAYOUT_universal(
    KC_NO    , KC_NO     , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,                                        KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO     , KC_NO    , KC_NO    , KC_LGUI  , KC_NO   ,                                        KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_NO    , KC_NO    ,
    KC_NO    , KC_NO     , KC_NO    , KC_NO    , KC_NO    , KC_NO   ,                                        KC_BSPC  , KC_BSPC  , KC_BSPC  , KC_DEL   , KC_NO    , KC_NO    ,
                           KC_NO    , KC_NO    , KC_RALT  , MO(_SYM) , OS_CTL   ,                 KC_RSFT  , KC_NO               , XXXXXXX  , XXXXXXX  , KC_NO
  ),

  [_GAME] = LAYOUT_universal(
    KC_NO    , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_NO    ,
    KC_NO    , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_NO    ,
    KC_NO    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_NO    ,
                          TO(_BASE), TO(_BASE), KC_RALT  , OS_CTL   , OS_CTL  ,                  KC_RSFT  , KC_SPC              , XXXXXXX  , XXXXXXX  , KC_NO
  )
};
// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == _SYM);
    return state;
}

bool is_mac_mode = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_MAC:
            if (record->event.pressed) {
                is_mac_mode = true;
            }
            return false;
        case OS_WIN:
            if (record->event.pressed) {
                is_mac_mode = false;
            }
            return false;
        case OS_CTL:
            if (record->event.pressed) {
                if (is_mac_mode) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                }
            } else {
                if (is_mac_mode) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        default:
            return true;
    }
}


#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
