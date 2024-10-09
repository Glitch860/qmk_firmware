/* Copyright 2023 Colin Lam (Ploopy Corporation)
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum combo_events {
  COMBO_DEL,
  COMBO_ESC,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_del[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_T, KC_G, COMBO_END};

combo_t key_combos[] = {
  [COMBO_DEL] = COMBO(combo_del, KC_DEL),
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
} 

enum layer_names {
  _BASE,
  _FN1,
  _FN2,
  _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_BASE] = LAYOUT(
        KC_Q,          KC_W, KC_E,    KC_R,          KC_T,                      KC_MS_BTN2,             KC_Y,          KC_U,          KC_I,     KC_O,   KC_P,
        KC_A,          KC_S, KC_D,    KC_F,          KC_G,                      KC_MS_BTN1,             KC_H,          KC_J,          KC_K,     KC_L,   KC_SCLN,
        LSFT_T(KC_Z),  KC_X, KC_C,    KC_V,          KC_B,                      DRAG_SCROLL,            KC_N,          KC_M,          KC_COMMA, KC_DOT, RSFT_T(KC_SLSH),
                             LCTL_T(KC_LGUI), LT(1,KC_BSPC),  LT(2,KC_SPC),                             LT(2,KC_SPC),  LT(1,KC_ENT),  LALT_T(KC_APP)                        
    ),
    [_FN1] = LAYOUT(
        KC_TAB,   KC_HOME, KC_UP,   KC_END,   KC_PSCR,              _______,                  KC_BRIU,  KC_PGUP, KC_UP,   KC_PGDN,  KC_GRV,
        KC_LCTL,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,               _______,                  KC_BRID,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT,
        KC_LSFT, _______,  KC_MUTE, KC_VOLD, KC_VOLU,               _______,                  _______,  _______,  _______,  _______, KC_RSFT,
                          _______, _______, _______,                                          _______, _______,  _______                   
    ),
    [_FN2] = LAYOUT(
        KC_ESC,   KC_DEL,   _______,  KC_LBRC,  KC_MINS,           _______,                   KC_EQL,  KC_RBRC, _______, KC_DEL,  KC_BSLS,
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,              _______,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,           _______,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                             _______, _______, _______,                                       _______, _______,  _______                  
    ),
    [_FN3] = LAYOUT(
        KC_F1,    KC_F2,      KC_F3,      KC_F4,     KC_F5,          _______,                   KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,
        RGB_VAI,  RGB_SAI,    RGB_HUI,    RGB_SPI,   RGB_MOD,        _______,                   RGB_TOG,  _______,  _______, _______, KC_F11, 
        RGB_VAD,  RGB_SAD,    RGB_HUD,    RGB_SPD,   RGB_RMOD,       _______,                   DPI_CONFIG,  _______, _______, _______,  KC_F12,
                                    _______, _______, _______,                                  _______, _______,  _______                   
    )
};
