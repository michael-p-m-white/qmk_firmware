#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_steno.h"
#include "action_layer.h"
#include "quantum_keycodes.h"

/*
Layers?
QWERTY
COLEMAK-DH
WORKMAN(?)
CARPALX-QGMLWY
STENO

Symbols/Function keys?
Command mode - for, i.e., changing default layer, changing NKRO state - or is Magic/Bootmagic/Command sufficient for this?
What to with, e.g., large center keys? Duplicate "\" key on bottom-left row?

 */
#define QWERTY 0
#define COLEMAK_DH 1
#define WORKMAN 2
#define STENO 3
#define SYMB 4 // symbols
#define MIRYOKU_BASE 5
#define MIRYOKU_MEDIA 6
#define MIRYOKU_NAV 7
#define MIRYOKU_MOUSE 8
#define MIRYOKU_SYMBOLS 9
#define MIRYOKU_NUMBERS 10
#define MIRYOKU_FUNCTIONS 11
#define COMMAND 12


// Key aliases
#define KC_INS KC_INSERT
#define KC_PSE KC_PAUSE

#define ST_GEMN QK_STENO_GEMINI
#define ST_TXBT QK_STENO_BOLT



enum custom_keycodes {
  NKRO_ON = SAFE_RANGE,
  NKRO_OFF
};

/*
Missing:
Caps lock
PrintScreen/Pause/Insert
 */

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: QWERTY
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   =    │   1  │   2  │   3  │   4  │   5  │ Esc  │           │ Num  │   6  │   7  │   8  │   9  │   0  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   \    │   Q  │   W  │   E  │   R  │   T  │      │           │  [   │   Y  │   U  │   I  │   O  │   P  │   ]    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Tab    │   A  │   S  │   D  │   F  │   G  ├──────┤           ├──────┤   H  │   J  │   K  │   L  │   ;  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤MO(L4)│           │MO(L5)├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   C  │   V  │   B  │      │           │      │   N  │   M  │   ,  │   .  │   /  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ LGui │   `  │Insert│Pause │PScrn │                                       │Left  │ Down │  Up  │ Right│ RGui │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │ Ctrl │ Alt  │       │ Alt  │  Ctrl  │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │ Home │       │ PgUp │        │      │
 *                                 │ Space│Enter ├──────┤       ├──────┤  Del   │ Bkspc│
 *                                 │      │      │ End  │       │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
[QWERTY] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_NO,
  KC_TAB,          KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_INS,        KC_PSE,  KC_PSCR,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_RBRC,
                KC_H,    KC_J,    KC_K,    KC_L,              KC_SCLN,        KC_QUOT,
  MO(COMMAND),  KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 1: COLEMAK-DH
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   =    │   1  │   2  │   3  │   4  │   5  │ Esc  │           │ Num  │   6  │   7  │   8  │   9  │   0  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   \    │   Q  │   W  │   F  │   P  │   B  │      │           │  [   │   J  │   L  │   U  │   Y  │   ;  │   ]    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Tab    │   A  │   R  │   S  │   T  │   G  ├──────┤           ├──────┤   M  │   N  │   E  │   I  │   O  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤MO(L4)│           │MO(L5)├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   C  │   D  │   V  │      │           │      │   K  │   H  │   ,  │   .  │   /  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ LGui │   `  │Insert│Pause │PScrn │                                       │Left  │ Down │  Up  │ Right│ RGui │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │ Ctrl │ Alt  │       │ Alt  │  Ctrl  │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │ Home │       │ PgUp │        │      │
 *                                 │ Space│Enter ├──────┤       ├──────┤  Del   │ Bkspc│
 *                                 │      │      │ End  │       │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
[COLEMAK_DH] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_W,          KC_F,    KC_P,    KC_B,    KC_NO,
  KC_TAB,          KC_A,        KC_R,          KC_S,    KC_T,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_D,    KC_V,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_INS,        KC_PSE,  KC_PSCR,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_J,    KC_L,    KC_U,    KC_Y,              KC_SCLN,        KC_RBRC,
                KC_M,    KC_N,    KC_E,    KC_I,              KC_O,           KC_QUOT,
  MO(COMMAND),  KC_K,    KC_H,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 2: WORKMAN
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │   =    │   1  │   2  │   3  │   4  │   5  │ Esc  │           │ Num  │   6  │   7  │   8  │   9  │   0  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │   \    │   Q  │   D  │   R  │   W  │   B  │  L1  │           │  [   │   J  │   F  │   U  │   P  │   ;  │   ]    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Tab    │   A  │   S  │   H  │   T  │   G  ├──────┤           ├──────┤   Y  │   N  │   E  │   O  │   I  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤MO(L4)│           │MO(L5)├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   M  │   C  │   V  │      │           │      │   K  │   L  │   ,  │   .  │   /  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │ LGui │   `  │Insert│Pause │PScrn │                                       │Left  │ Down │  Up  │ Right│ RGui │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │ Ctrl │ Alt  │       │ Alt  │  Ctrl  │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │ Home │       │ PgUp │        │      │
 *                                 │ Space│Enter ├──────┤       ├──────┤  Del   │ Bkspc│
 *                                 │      │      │ End  │       │ PgDn │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
[WORKMAN] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_D,          KC_R,    KC_W,    KC_B,    KC_NO,
  KC_TAB,          KC_A,        KC_S,          KC_H,    KC_T,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_M,    KC_C,    KC_V,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_INS,        KC_PSE,  KC_PSCR,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_J,    KC_F,    KC_U,    KC_P,              KC_SCLN,        KC_RBRC,
                KC_Y,    KC_N,    KC_E,    KC_O,              KC_I,           KC_QUOT,
  MO(COMMAND),  KC_K,    KC_L,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 3: STENO
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   #  │   #  │   #  │   #  │   #  │      │           │      │   #  │   #  │   #  │   #  │   #  │   #    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   S  │   T  │   P  │   H  │   *  ├──────┤           ├──────┤   *  │   F  │   P  │   L  │   T  │   D    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   S  │   K  │   W  │   R  │   *  │      │           │      │   *  │   R  │   B  │   G  │   S  │   Z    │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │      │      │       │      │        │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │      │       │      │        │      │
 *                                 │  A   │  O   ├──────┤       ├──────┤   E    │  U   │
 *                                 │      │      │      │       │      │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
[STENO] = LAYOUT_ergodox(
  // left hand
  ST_GEMN,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         STN_N1,      STN_N2,        STN_N3,  STN_N4,  STN_N5,  XXXXXXX,
  XXXXXXX,         STN_S1,      STN_TL,        STN_PL,  STN_HL,  STN_ST1,
  XXXXXXX,         STN_S2,      STN_KL,        STN_WL,  STN_RL,  STN_ST2, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        STN_A,   STN_O,   XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,        ST_TXBT,
  XXXXXXX,      STN_N6,  STN_N7,  STN_N8,  STN_N9,      STN_NA,         STN_NB,
                STN_ST3, STN_FR,  STN_PR,  STN_LR,      STN_TR,         STN_DR,
  MO(COMMAND),  STN_ST4, STN_RR,  STN_BR,  STN_GR,      STN_SR,         STN_ZR,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,      XXXXXXX,
  XXXXXXX,
  XXXXXXX,      STN_E,   STN_U
),
/* Keymap 4: Symbol Layer
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │  F1  │  F2  │  F3  │  F4  │  F5  │      │           │      │  F6  │  F7  │  F8  │  F9  │  F10 │   F11  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   !  │  @   │  {   │  }   │   |  │      │           │  [   │  Up  │  7   │   8  │   9  │   *  │   F12  │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   #  │  $   │  (   │  )   │   `  ├──────┤           ├──────┤ Down │  4   │   5  │   6  │   +  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   %  │  ^   │  [   │  ]   │   ~  │      │           │      │  &   │  1   │   2  │   3  │   \  │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │Insert│Pause │PScrn │      │                                       │      │   .  │   0  │   =  │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │      │      │       │      │        │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │      │       │      │        │      │
 *                                 │      │      ├──────┤       ├──────┤        │      │
 *                                 │      │      │      │       │      │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
  KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
  _______, KC_INS,  KC_PSE,  KC_PSCR, _______,
                                               _______, _______,
                                                        _______,
                                      _______, _______, _______,
  // right hand
  TG(SYMB),KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
           KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  _______, KC_DOT,  KC_0,    KC_EQL,  _______,
  _______, _______,
  _______,
  _______, _______, _______
),
/* Keymap 5: COMMAND
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │ DF(0)│ DF(1)│ DF(2)│ DF(3)│ DF(4)│      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      ├──────┤           ├──────┤      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │      │      │       │      │        │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │      │       │      │        │      │
 *                                 │      │      ├──────┤       ├──────┤        │      │
 *                                 │      │      │      │       │      │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
#define TO_QWER TO(QWERTY)
#define TO_COLE TO(COLEMAK_DH)
#define TO_WKMN TO(WORKMAN)
#define TO_MIRY TO(MIRYOKU_BASE)
#define TO_STEN TO(STENO)

[COMMAND] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, TO_QWER, TO_COLE, TO_WKMN, TO_MIRY, TO_STEN, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,
  // right hand
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, NKRO_ON, NKRO_OFF,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX
),
/* Keymap 6: MIRYOKU_BASE
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────┬──────╮           ╭──────┬──────┬──────┬──────┬──────┬──────┬────────╮
 * │        │      │      │      │      │      │      │           │      │      │      │      │      │      │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┼──────┼──────┼────────┤
 * │        │   Q  │   W  │   E  │   R  │   T  │      │           │      │   Y  │   U  │   I  │   O  │   P  │        │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │      ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Tab    │   A  │   S  │   D  │   F  │   G  ├──────┤           ├──────┤   H  │   J  │   K  │   L  │   ;  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤      │           │MO(L5)├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   C  │   V  │   B  │      │           │      │   N  │   M  │   ,  │   .  │   /  │ RShift │
 * ╰─┬──────┼──────┼──────┼──────┼──────┼──────┴──────╯           ╰──────┴──────┼──────┼──────┼──────┼──────┼──────┬─╯
 *   │      │      │      │      │      │                                       │      │      │      │      │      │
 *   ╰──────┴──────┴──────┴──────┴──────╯                                       ╰──────┴──────┴──────┴──────┴──────╯
 *                                        ╭──────┬──────╮       ╭──────┬────────╮
 *                                        │      │      │       │      │        │
 *                                 ╭──────┼──────┼──────│       ├──────┼────────┼──────╮
 *                                 │      │      │      │       │      │        │      │
 *                                 │      │      ├──────┤       ├──────┤        │      │
 *                                 │      │      │      │       │      │        │      │
 *                                 ╰──────┴──────┴──────╯       ╰──────┴────────┴──────╯
 */
#define TMED LT(MIRYOKU_MEDIA, KC_ESC)
#define TNAV LT(MIRYOKU_NAV, KC_SPC)
#define TMSE LT(MIRYOKU_MOUSE, KC_TAB)
#define TSYM LT(MIRYOKU_SYMBOLS, KC_ENT)
#define TNUM LT(MIRYOKU_NUMBERS, KC_BSPC)
#define TFUN LT(MIRYOKU_FUNCTIONS, KC_DEL)

#define TOMBASE TO(MIRYOKU_BASE)
#define TOMED   TO(MIRYOKU_MEDIA)
#define TONAV   TO(MIRYOKU_NAV)
#define TOMSE   TO(MIRYOKU_MOUSE)
#define TOSYM   TO(MIRYOKU_SYMBOLS)
#define TONUM   TO(MIRYOKU_NUMBERS)
#define TOFUN   TO(MIRYOKU_FUNCTIONS)

#define AGUI MT(MOD_LGUI, KC_A)
#define SALT MT(MOD_LALT, KC_S)
#define DCTL MT(MOD_LCTL, KC_D)
#define FSFT MT(MOD_LSFT, KC_F)

#define JSFT    MT(MOD_RSFT, KC_J)
#define KCTL    MT(MOD_RCTL, KC_K)
#define ELALT    MT(MOD_RALT, KC_L)
#define SCLNGUI MT(MOD_RGUI, KC_SCLN)

[MIRYOKU_BASE] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    XXXXXXX,
  KC_TAB,          AGUI,        SALT,          DCTL,    FSFT,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, TMED,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                         TNAV,   TMSE,    XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           XXXXXXX,
                KC_H,    JSFT,    KCTL,    ELALT,             SCLNGUI,        KC_QUOT,
  MO(COMMAND),  KC_N,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  TFUN,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, TSYM,   TNUM
),
#define VOLU KC_AUDIO_VOL_UP
#define VOLD KC_AUDIO_VOL_DOWN
#define PP   KC_MEDIA_PLAY_PAUSE
#define STOP KC_MEDIA_STOP
#define NEXT KC_MEDIA_NEXT_TRACK
#define PREV KC_MEDIA_PREV_TRACK
#define BRUP KC_BRIGHTNESS_UP
#define BRDN KC_BRIGHTNESS_DOWN
#define MUTE KC_AUDIO_MUTE
[MIRYOKU_MEDIA] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,
  _______,         KC_LGUI,     KC_LALT,       KC_LCTL, KC_LSFT, XXXXXXX,
  _______,         XXXXXXX,     XXXXXXX,       TOFUN,   TOMED,   XXXXXXX, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        XXXXXXX, XXXXXXX, XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                KC_CAPS, PREV,    VOLD,    VOLU,              NEXT,           _______,
  MO(COMMAND),  XXXXXXX, XXXXXXX, BRDN,    BRUP,              XXXXXXX,        _______,
  MUTE,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, STOP,   PP
),
[MIRYOKU_NAV] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         TO(0),       XXXXXXX,       XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,
  _______,         KC_LGUI,     KC_LALT,       KC_LCTL, KC_LSFT, XXXXXXX,
  _______,         XXXXXXX,     XXXXXXX,       TONUM,   TONAV,   XXXXXXX, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        XXXXXXX, XXXXXXX, XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,             KC_RGHT,        _______,
  MO(COMMAND),  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,           KC_END,         XXXXXXX,
  KC_DEL,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, KC_ENT,   KC_BSPC
),
#define MS_UP  KC_MS_UP
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MSBTN1 KC_MS_BTN1
#define MSBTN2 KC_MS_BTN2
#define MSBTN3 KC_MS_BTN3
#define MW_UP  KC_MS_WH_UP
#define MW_DOWN KC_MS_WH_DOWN
#define MW_LEFT KC_MS_WH_LEFT
#define MW_RGHT KC_MS_WH_RIGHT

[MIRYOKU_MOUSE] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,
  _______,         KC_LGUI,     KC_LALT,       KC_LCTL, KC_LSFT, XXXXXXX,
  _______,         XXXXXXX,     XXXXXXX,       TOSYM,   TOMSE,   XXXXXXX, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        XXXXXXX, XXXXXXX, XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,             MS_RGHT,        _______,
  MO(COMMAND),  XXXXXXX, MW_LEFT, MW_DOWN, MW_UP,             MW_RGHT,        _______,
  MSBTN3,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, MSBTN2,   MSBTN1
),
[MIRYOKU_NUMBERS] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         KC_LBRC,     KC_7,          KC_8,    KC_9,    KC_RBRC, XXXXXXX,
  _______,         KC_QUOT,     KC_4,          KC_5,    KC_6,    KC_EQL,
  _______,         KC_GRV,      KC_1,          KC_2,    KC_3,    KC_BSLS, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, KC_DOT,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        KC_0,    KC_MINS, XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT,           KC_RGUI,        _______,
  MO(COMMAND),  XXXXXXX, TONUM,   TONAV,   XXXXXXX,           XXXXXXX,        _______,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX,   XXXXXXX
),
[MIRYOKU_SYMBOLS] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         KC_LCBR,     KC_AMPR,       KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX,
  _______,         KC_DQT,      KC_DLR,        KC_PERC, KC_CIRC, KC_PLUS,
  _______,         KC_TILDE,    KC_EXLM,       KC_AT,   KC_HASH, KC_PIPE, XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, KC_LPRN,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        KC_RPRN, KC_UNDS, XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT,           KC_RGUI,        _______,
  MO(COMMAND),  XXXXXXX, TOSYM,   TOMSE,   XXXXXXX,           XXXXXXX,        _______,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX,   XXXXXXX
),
[MIRYOKU_FUNCTIONS] = LAYOUT_ergodox(
  // left hand
                          //_______, KC_INS,  KC_PSE,  KC_PSCR, _______,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         KC_F12,      KC_F7,         KC_F8,   KC_F9,   KC_PSCR, XXXXXXX,
  _______,         KC_F11,      KC_F4,         KC_F5,   KC_F6,   KC_SCRL,
  _______,         KC_F10,      KC_F1,         KC_F2,   KC_F3,   KC_PSE,  XXXXXXX,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, KC_LPRN,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        KC_SPC,  KC_TAB,  XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
  XXXXXXX,      XXXXXXX, TOMBASE, XXXXXXX, XXXXXXX,           XXXXXXX,        XXXXXXX,
                XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT,           KC_RGUI,        _______,
  MO(COMMAND),  XXXXXXX, TOFUN,   TOMED,   XXXXXXX,           XXXXXXX,        _______,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX,   XXXXXXX
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t action_layer;
  uint32_t new_layer_state;

  if (record->event.pressed) {
    switch (keycode) {
    case NKRO_ON:
      keymap_config.nkro = 1;
      return false;
      break;
    case NKRO_OFF:
      keymap_config.nkro = 0;
      return false;
      break;
    case QK_TO ... QK_TO_MAX:
      action_layer = keycode & 0xF;
      new_layer_state = 1UL << action_layer;
      default_layer_set(new_layer_state);
      layer_state_set(new_layer_state);
      return false;
      break;
    default:
      break;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_GEMINI);
#endif
};

// Runs whenever there is a layer state change.
/*
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
*/
