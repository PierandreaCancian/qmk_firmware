/* Copyright 2015-2017 Jack Humbert
 * Copyright 2020 Daniel Reibl <janos.daniel.reibl@protonmail.com>
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
#include <print.h>

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    KC_KITE,
    SAVE_EEP,
    KC_ACC,
    KC_SEC,
    KC_GOOGLE,
    KC_SPOTIFY,
    KC_WHATSAPP,
    KC_TELEGRAM,
    KC_QMK_TLBX
};



enum preonic_layers {
    _QWERTY,
    _SECOND,
    // _RGB,
    _LOWER,
    _RAISE,
    _ACCENTED
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    BACKLIT
};



#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


// [_QWERTY] = LAYOUT_ortho_5x15(
//     KC_ACC,      KC_1,     KC_2,     KC_3,    KC_4,        KC_5,    KC_6,   KC_7,      KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_PGUP, 
//     KC_TAB,      KC_Q,     KC_W,     KC_E,    KC_R,        KC_T,    KC_Y,   KC_U,      KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,  KC_PGDN, 
//     KC_GESC,     KC_A,     KC_S,     KC_D,    KC_F,        KC_G,    KC_H,   KC_J,      KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_ENT,   KC_HOME, 
//     KC_LSFT,     KC_Z,     KC_X,     KC_C,    KC_V,        KC_B,    KC_N,   KC_M,      KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,   KC_NO,
//     KC_LCTL,     KC_LGUI,  KC_LALT,  KC_SEC,  MO(_LOWER),  KC_SPC,  KC_NO,  KC_NO,  KC_SPC,  KC_RGUI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
[_QWERTY] = LAYOUT_ortho_5x15(
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,      KC_5,    KC_6,    KC_7,      KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   MO(_LOWER), 
    KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,    KC_LSFT, KC_Y,      KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NO, 
    KC_ESC,      KC_A,     KC_S,     KC_D,     KC_F,      KC_G,    KC_BSPC, KC_H,      KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_CAPS,  
    KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    KC_ENT,  KC_N,      KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,   KC_LGUI,  KC_NO,  
    KC_LCTL,     KC_SEC,    KC_LGUI,  KC_LALT,  KC_SPC,    KC_SPC,  KC_NO,   KC_SPC,    KC_NO,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_RCTL,  KC_NO),
//               KC_SEC
//              ^^^^^^^^----sends to second 
[_SECOND] = LAYOUT_ortho_5x15(
    KC_GRV,      KC_1,     KC_2,     KC_3,     KC_4,      KC_5,    KC_6,      KC_7,     KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   MO(_LOWER), 
    KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,    KC_LSFT,   KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_NO, 
    KC_ESC,      KC_A,     KC_S,     KC_D,     KC_F,      KC_G,    KC_BSPC,   KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_BSLS,  KC_CAPS,  
    KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,    KC_ENT,    KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,   KC_LGUI,  KC_NO,  
    KC_LCTL,     KC_NO,    KC_LGUI,  KC_LALT,  KC_SPC,    KC_SPC,  KC_KITE,   KC_NO,    KC_NO,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_RCTL,  KC_NO),

// [_SECOND] = LAYOUT_ortho_5x15(
//     KC_NO,   KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
//     KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_F11, KC_F12, KC_P7, KC_P8, KC_P9, KC_PPLS, 
//     KC_CALC, KC_MYCM, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PCMM, 
//     KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PEQL, 
//     KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT),

// [_RGB] = LAYOUT_ortho_5x15(
//     RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, 
//     KC_F1, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
//     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
//     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
//     KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

[_LOWER] = LAYOUT_ortho_5x15( 
    KC_MS_R, DEBUG, EEP_RST, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, 
    KC_NO, KC_QMK_TLBX, KC_WHATSAPP, KC_NO, KC_NO, KC_TELEGRAM, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, 
    KC_NO, KC_NO, KC_SPOTIFY, KC_NO, KC_NO, KC_GOOGLE, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN4, KC_BTN1, KC_MS_U, KC_BTN2, 
    KC_PWR, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN3, KC_MS_L, KC_MS_D, KC_NO ),

[_RAISE] = LAYOUT_ortho_5x15(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_2, KC_0, KC_MINS, KC_EQL, KC_DEL, KC_PGUP,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC, KC_PGDN,
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSLS, KC_ENT, KC_ENT, KC_HOME,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, KC_RSFT, KC_UP, KC_END,
    KC_LCTL, KC_LGUI, KC_LALT, MO(0), MO(0), MO(0), KC_SPC, KC_SPC, KC_RALT, KC_RGUI, MO(0), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
),

[_ACCENTED] = LAYOUT_ortho_5x15(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_LBRACKET, KC_NO, KC_NO, KC_NO, KC_BSLASH, KC_EQUAL, KC_SCOLON, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ACC, KC_QUOTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RGUI, KC_RALT, KC_RCTL, KC_NO, KC_NO, KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    
    switch (keycode) {
        case KC_QMK_TLBX:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "qmk_toolbox" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_GOOGLE:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "google" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_TELEGRAM:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "telegram" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_SPOTIFY:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "spotify" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_WHATSAPP:
            if (record->event.pressed) {
                        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(50) "whatsapp" SS_DELAY(50) SS_TAP(X_ENT));
            }
            break;
        case KC_ACC:
            if (record->event.pressed) {
                        // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
                        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_LALT) SS_UP(X_LSFT));
                        layer_on(_ACCENTED);
            } else {  // at key release
                SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_LALT) SS_UP(X_LSFT));
                layer_off(_ACCENTED);
            }
            break;
        case KC_SEC:
            if (record->event.pressed) {
                //rgb_matrix_mode(RGB_MATRIX_CUSTOM_SECOND);
                layer_on(_SECOND);
            } else {
                //rgb_matrix_mode(sleepmode_before_mode);
                layer_off(_SECOND);
            }
            break;
        }
    return true;
};
