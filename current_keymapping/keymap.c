/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation,  either version 2 of the License,  or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not,  see <http://www.gnu.org/licenses/>.
*/


//includes:
#include "keymap.h"
#include <stdio.h>

// Tap Dance declarations
enum {
    TD_TAB_RIGHT,
    TD_DOT_TAB,
    TD_0_SPC,
    TD_COMMA_ENT
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_TAB_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_TAB,KC_RIGHT),
    [TD_DOT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_TAB),
    [TD_0_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_0,KC_SPC),
    [TD_COMMA_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA,KC_ENT)
};

//KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// QWERTY LAYER
  [QWERTY] = LAYOUT_split_3x6_3(
    //ROW 1
        KC_ESC,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_DELWRD,
    //ROW 2
        KC_TAB,  LCTL_T(KC_A),  LOPT_T(KC_S),  CMD_T(KC_D),  LSFT_T(KC_F),  KC_G,  KC_H,  LSFT_T(KC_J),  CMD_T(KC_K),  LOPT_T(KC_L),  LCTL_T(KC_SCLN),  KC_QUOT,
    //ROW 3
        KC_CAPS,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_GRV,
    //THUBS
        LT(MEDIA,KC_DEL),  LT(NAV,KC_BSPC),  LT(BASESWAP,KC_ENT),  LT(SYM,KC_TAB),  LT(NUM,KC_SPC),  LT(FUN,  KC_ESC)
  ),
// COLEMAK-DHm LAYER
  [COLEMAKDH] = LAYOUT_split_3x6_3(
    //ROW 1
        KC_ESC,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,  KC_J,  KC_L,  KC_U,  KC_Y,  KC_SCLN,  KC_DELWRD,
    //ROW 2
        KC_TAB,  LCTL_T(KC_A),  LOPT_T(KC_R),  CMD_T(KC_S),  LSFT_T(KC_T),  KC_G,  KC_M,  LSFT_T(KC_N),  CMD_T(KC_E),  LOPT_T(KC_I),  LCTL_T(KC_O),  KC_QUOT,
    //ROW 3
        KC_CAPS,  KC_Z,  KC_X,  KC_C,  KC_D,  KC_V,  KC_K,  KC_H,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_GRV,
    //THUBS
        LT(MEDIA,KC_DEL),  LT(NAV,KC_BSPC),  LT(BASESWAP,KC_ENT),  LT(SYM,KC_TAB),  LT(NUM,KC_SPC),  LT(FUN,KC_ESC)
  ),
// MEDIA LAYER
  [MEDIA] = LAYOUT_split_3x6_3(
    //ROW 1
        KC_EJCT,  U_NU,  U_NU,  KC_KB_VOLUME_UP,  U_NU,  U_NU,  U_NU,  U_NU,  KC_KB_VOLUME_UP,  U_NU,  U_NU,  KC_EJCT,
    //ROW 2
        U_NU,  U_NU,  KC_MPRV,  KC_KB_VOLUME_DOWN,  KC_MNXT,  U_NU,  U_NU,  KC_MPRV,  KC_KB_VOLUME_DOWN,  KC_MNXT,  U_NU,  U_NU,
    //ROW 3
        U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //THUBS
        U_NA,  U_NA,  U_NA,  KC_MSTP,  KC_MPLY,  KC_MUTE
  ),
// NAVIGATION LAYER
  [NAV] = LAYOUT_split_3x6_3(
    //ROW 1
        U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  KC_INS,  KC_HOME,  KC_UP,  KC_END,  KC_PAGE_UP,  U_NU,
    //ROW 2
        U_NU,  KC_UNDO,  KC_CUT,  KC_COPY,  KC_PASTE,  KC_AGIN,  U_NU,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_PAGE_DOWN,  U_NU,
    //ROW 3
        U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  KC_AGIN,  KC_PASTE,  KC_COPY,  KC_CUT,  KC_UNDO,  U_NU,
    //THUBS
        U_NA,  U_NA,  U_NA,  U_NU,  U_NU,  U_NU
  ),
// DEFAULT LAYER SWAP (switch from qwerty to colemak-dhm)
  [BASESWAP] = LAYOUT_split_3x6_3(
    //ROW 1
        U_NU,  U_NU,  U_NU,  KC_UP,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //ROW 2
        U_NU,  U_NU,  KC_LEFT,  KC_DOWN,  KC_RIGHT,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //ROW 3
        U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //THUBS
        U_NA,  U_NA,  U_NA,  DF(QWERTY),  DF(COLEMAKDH),  U_NU
  ),
// SYMBOLS LAYER
  [SYM] = LAYOUT_split_3x6_3(
    //ROW 1
        KC_AMPR,  KC_PIPE,  KC_LBRC,  KC_PPLS,  KC_RBRC,  KC_HASH,  KC_PERC,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //ROW 2
        KC_LABK,  KC_RABK,  KC_LPRN,  KC_EQL,  KC_RPRN,  KC_ASTR,  KC_CIRC,  KC_LSFT,  KC_LCMD,  KC_LOPT,  KC_LCTL,  U_NU,
    //ROW 3
        KC_GRV,  KC_BSLS,  KC_LCBR,  KC_MINS,  KC_RCBR,  KC_SLSH,  KC_EXLM,  KC_EXLM,  KC_DLR,  KC_AT,  KC_TILDE,  U_NU,
    //THUBS
        KC_COMMA,  KC_DOT,  KC_SEMICOLON,  U_NA,  U_NA,  U_NA
  ),
// NUMBERS LAYER
  [NUM] = LAYOUT_split_3x6_3(
    //ROW 1
        U_NU, KC_LBRC,  KC_7,  KC_8,  KC_9,  KC_RBRC,    U_NU,  KC_PLUS,  KC_ASTERISK,  KC_CIRC,  KC_PERC,  U_NU,
    //ROW 2
        U_NU, KC_LPRN,  KC_4,  KC_5,  KC_6,  KC_RPRN,    TD(TD_TAB_RIGHT),  KC_LSFT,  KC_LCMD,  KC_LOPT,  KC_LCTL,  U_NU,
    //ROW 3
        U_NU,  U_NU,  KC_1,  KC_2,  KC_3,  U_NU,  U_NU,  KC_MINS,  KC_SLSH,  KC_EQL,  U_NU,  U_NU,
    //THUBS
        TD(TD_DOT_TAB),  TD(TD_0_SPC),  TD(TD_COMMA_ENT),  U_NA,  U_NA,  U_NA
  ),
// FUNCTION LAYER
  [FUN] = LAYOUT_split_3x6_3(
    //ROW 1
        KC_F12,  KC_F7,  KC_F8,  KC_F9,  KC_PSCR,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //ROW 2
        KC_F11,  KC_F4,  KC_F5,  KC_F6,  KC_PAUS,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //ROW 3
        KC_F10,  KC_F1,  KC_F2,  KC_F3,  KC_SCRL,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,  U_NU,
    //THUBS
        U_NU,  U_NU,  U_NU,  U_NA,  U_NA,  U_NA
  ),
};



#ifdef OLED_ENABLE

//ROTATE DISPLAY IF NOT MASTER SIDE (LEFT)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

//DISPLAY CURRENT LAYER
void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "),  false);
    switch (layer_state) {
        case QWERTY:
            oled_write_ln_P(PSTR("QWERTY"),  false);
            break;
        case COLEMAKDH:
            oled_write_ln_P(PSTR("COLEMAK"),  false);
            break;
        case MEDIA:
            oled_write_ln_P(PSTR("MEDIA"),  false);
            break;
        case NAV:
            oled_write_ln_P(PSTR("NAVIGATION"),  false);
            break;
        case BASESWAP:
            oled_write_ln_P(PSTR("SWAP"),  false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("SYMBOLS"),  false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("NUMBERS"),  false);
            break;
        case FUN:
            oled_write_ln_P(PSTR("FUNCTIONS"),  false);
            break;
    }
}



//KEY LOGGER STUFF
char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ',  ' ',  ' ',  ' ',  'a',  'b',  'c',  'd',  'e',  'f',
    'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',  'p',
    'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',
    '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',
    'R',  'E',  'B',  'T',  '_',  '-',  '=',  '[',  ']',  '\\',
    '#',  ';',  '\'',  '`',  ',',  '.',  '/',  ' ',  ' ',  ' '};

void set_keylog(uint16_t keycode,  keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str,  sizeof(keylog_str),  "%dx%d,  k%2d : %c",
           record->event.key.row,  record->event.key.col,
           keycode,  name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str,  false);
}


//TODO: WHAT IS THIS??
void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97,  0x98,  0},  {0xb7,  0xb8,  0}},
        {{0x95,  0x96,  0},  {0xb5,  0xb6,  0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0],  false);
        oled_write_ln_P(logo[0][1],  false);
    } else {
        oled_write_ln_P(logo[1][0],  false);
        oled_write_ln_P(logo[1][1],  false);
    }
}


// CORNE LOGO
// void oled_render_logo(void) {
//     static const char PROGMEM crkbd_logo[] = {
//         0x80,  0x81,  0x82,  0x83,  0x84,  0x85,  0x86,  0x87,  0x88,  0x89,  0x8a,  0x8b,  0x8c,  0x8d,  0x8e,  0x8f,  0x90,  0x91,  0x92,  0x93,  0x94,
//         0xa0,  0xa1,  0xa2,  0xa3,  0xa4,  0xa5,  0xa6,  0xa7,  0xa8,  0xa9,  0xaa,  0xab,  0xac,  0xad,  0xae,  0xaf,  0xb0,  0xb1,  0xb2,  0xb3,  0xb4,
//         0xc0,  0xc1,  0xc2,  0xc3,  0xc4,  0xc5,  0xc6,  0xc7,  0xc8,  0xc9,  0xca,  0xcb,  0xcc,  0xcd,  0xce,  0xcf,  0xd0,  0xd1,  0xd2,  0xd3,  0xd4,
//         0};
//     oled_write_P(crkbd_logo,  false);
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        // oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode,  keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode,  record);
  }
  return true;
}
#endif // OLED_ENABLE
