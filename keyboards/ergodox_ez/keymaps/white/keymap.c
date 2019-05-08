#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_steno.h"
#include "action_layer.h"

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
#define NORMAN 3
#define CARPALX_QGMLWB 4
#define MALTRON 5
#define STENO 6
#define SYMB 7 // symbols
#define COMMAND 8


// Key aliases
#define KC_INS KC_INSERT
#define KC_PSE KC_PAUSE
#define KC_PSCR KC_PSCREEN


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
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Del   | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_NO,
  KC_TAB,          KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
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
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   F  |   P  |   B  |  L1  |           |  [   |   J  |   L  |   U  |   Y  |   ;  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   R  |   S  |   T  |   G  |------|           |------|   K  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   M  |   H  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Del   | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[COLEMAK_DH] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_W,          KC_F,    KC_P,    KC_B,    KC_NO,
  KC_TAB,          KC_A,        KC_R,          KC_S,    KC_T,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_D,    KC_V,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_J,    KC_L,    KC_U,    KC_Y,              KC_SCLN,        KC_RBRC,
                KC_K,    KC_N,    KC_E,    KC_I,              KC_O,           KC_QUOT,
  MO(COMMAND),  KC_M,    KC_H,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 2: WORKMAN
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   D  |   R  |   W  |   B  |  L1  |           |  [   |   J  |   F  |   U  |   P  |   ;  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Del   | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[WORKMAN] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_D,          KC_R,    KC_W,    KC_B,    KC_NO,
  KC_TAB,          KC_A,        KC_S,          KC_H,    KC_T,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_M,    KC_C,    KC_V,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
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
/* Keymap 2: NORMAN
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   D  |   F  |   K  |  L1  |           |  [   |   J  |   U  |   R  |   L  |   ;  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Del   | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NORMAN] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_W,          KC_D,    KC_F,    KC_K,    KC_NO,
  KC_TAB,          KC_A,        KC_S,          KC_E,    KC_T,    KC_G,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_J,    KC_U,    KC_R,    KC_L,              KC_SCLN,        KC_RBRC,
                KC_Y,    KC_N,    KC_I,    KC_O,              KC_H,           KC_QUOT,
  MO(COMMAND),  KC_P,    KC_M,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 3: CARPALX-QGMLWB
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   G  |   M  |   L  |   W  |  L1  |           |  [   |   B  |   Y  |   U  |   V  |   ;  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   D  |   S  |   T  |   N  |   R  |------|           |------|   I  |   A  |   E  |   O  |   H  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   F  |   J  |      |           |      |   K  |   P  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   | LGui |   `  |   \  | Left | Right|                                       |  Up  | Down |   [  |   ]  | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Enter |------|       |------|  Del   | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[CARPALX_QGMLWB] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_G,          KC_M,    KC_L,    KC_W,    KC_NO,
  KC_TAB,          KC_D,        KC_S,          KC_T,    KC_N,    KC_R,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_F,    KC_J,    MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_LBRC,      KC_B,    KC_Y,    KC_U,    KC_V,              KC_SCLN,        KC_RBRC,
                KC_I,    KC_A,    KC_E,    KC_O,              KC_H,           KC_QUOT,
  MO(COMMAND),  KC_K,    KC_P,    KC_COMM, KC_DOT,            KC_SLSH,        KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_BSPC
),
/* Keymap 4: MALTRON
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | Esc  |           | Num  |   6  |   7  |   8  |   9  |   0  | Bkspc  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   P  |   Y  |   C  |   B  |  L1  |           |  [   |   V  |   M  |   U  |   Z  |   L  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   N  |   I  |   S  |   F  |------|           |------|   D  |   T  |   H  |   O  |   R  |   '    |
 * |--------+------+------+------+------+------|MO(L7)|           | Meh  |------+------+------+------+------+--------|
 * | LShift |   ,  |   .  |   J  |   G  |   ;  |      |           |      |   /  |   W  |   K  |   -  |   X  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui |   `  |   \  | Left | Right|                                       |Left  | Down |  Up  | Right| RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Alt  |       | Alt  |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |Space |Enter |------|       |------|  Del   |  E   |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[MALTRON] = LAYOUT_ergodox(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,
  KC_BSLS,         KC_Q,        KC_P,          KC_Y,    KC_C,    KC_B,    KC_NO,
  KC_TAB,          KC_A,        KC_N,          KC_I,    KC_S,    KC_F,
  KC_LSFT,         KC_COMM,     KC_DOT,        KC_J,    KC_G,    KC_SCLN, MO(SYMB),
  KC_LGUI,         KC_GRV,      KC_BSLS,       KC_LEFT, KC_RGHT,
                                                                 KC_LCTL, KC_LALT,
                                                                          KC_HOME,
                                                         KC_SPC, KC_ENT,  KC_END,
  // right hand
  TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_BSPC,
  KC_LBRC,      KC_V,    KC_M,    KC_U,    KC_Z,              KC_L,           KC_RBRC,
                KC_D,    KC_T,    KC_H,    KC_O,              KC_R,           KC_QUOT,
  MO(COMMAND),  KC_SLSH, KC_W,    KC_K,    KC_MINS,           KC_X,           KC_RSFT,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_RGUI,
  KC_RALT, KC_RCTL,
  KC_PGUP,
  KC_PGDN, KC_DEL, KC_E
),
/* Keymap 5: STENO
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |  A   |  O   |------|       |------|   E    |  U   |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[STENO] = LAYOUT_ergodox(
  // left hand
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,         STN_N1,      STN_N2,        STN_N3,  STN_N4,  STN_N5,  XXXXXXX,
  XXXXXXX,         STN_S1,      STN_TL,        STN_PL,  STN_HL,  STN_ST1, XXXXXXX,
  XXXXXXX,         STN_S2,      STN_KL,        STN_WL,  STN_RL,  STN_ST2,
  XXXXXXX,         XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,
                                                                 XXXXXXX, XXXXXXX,
                                                                          XXXXXXX,
                                                        STN_A,   STN_O,   XXXXXXX,
  // right hand
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,        XXXXXXX,
  XXXXXXX,      STN_N6,  STN_N7,  STN_N8,  STN_N9,      STN_NA,         STN_NB,
                STN_ST3, STN_FR,  STN_PR,  STN_LR,      STN_TR,         STN_DR,         
  MO(COMMAND),  STN_ST4, STN_RR,  STN_BR,  STN_GR,      STN_SR,         STN_ZR,
  XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX,      XXXXXXX,
  XXXXXXX,
  XXXXXXX,      STN_E,   STN_U
),
/* Keymap ??: Symbol Layer

 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Num  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |Insert|Pause |PScrn |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_CAPS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
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
/* Keymap 7: COMMAND
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |DF(0) | DF(1)| DF(2)| DF(3)| DF(4)|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[COMMAND] = LAYOUT_ergodox(
  // left hand
  XXXXXXX, TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               XXXXXXX, XXXXXXX,
                                                        XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,
  // right hand
  XXXXXXX, TO(5),   TO(6),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, NKRO_ON, NKRO_OFF,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,
  XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX
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
