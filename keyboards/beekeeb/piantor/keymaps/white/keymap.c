#include QMK_KEYBOARD_H
#include "action_layer.h"

#define QWERTY 0
#define COLEMAK_DH 1
#define WORKMAN 2
#define HOME_ROW_MODS 3
#define MIRYOKU_MEDIA 4
#define MIRYOKU_NAV 5
#define MIRYOKU_MOUSE 6
#define MIRYOKU_SYMBOLS 7
#define MIRYOKU_NUMBERS 8
#define MIRYOKU_FUNCTIONS 9
#define MIRYOKU_LEFT_HAND 10
#define MIRYOKU_RIGHT_HAND 11
#define STENO 12

// Custom keycodes
enum custom_keycodes {
  NKRO_ON = SAFE_RANGE,
  NKRO_OFF,
  LKCUR,
  LKOP
};

// Key aliases
#define KC_INS KC_INSERT
#define KC_PSE KC_PAUSE

#define ST_GEMN QK_STENO_GEMINI
#define ST_TXBT QK_STENO_BOLT


// Tap/mod layer change keys
#define TMED LT(MIRYOKU_MEDIA, KC_ESC)
#define TNAV LT(MIRYOKU_NAV, KC_SPC)
#define TMSE LT(MIRYOKU_MOUSE, KC_TAB)
#define TSYM LT(MIRYOKU_SYMBOLS, KC_ENT)
#define TNUM LT(MIRYOKU_NUMBERS, KC_BSPC)
#define TFUN LT(MIRYOKU_FUNCTIONS, KC_DEL)

// "Layer lock" keys
#define TOMED   TO(MIRYOKU_MEDIA)
#define TONAV   TO(MIRYOKU_NAV)
#define TOMSE   TO(MIRYOKU_MOUSE)
#define TOSYM   TO(MIRYOKU_SYMBOLS)
#define TONUM   TO(MIRYOKU_NUMBERS)
#define TOFUN   TO(MIRYOKU_FUNCTIONS)

// Home row mods
#define TGUI MT(MOD_LGUI, KC_TRNS)
#define TALT MT(MOD_LALT, KC_TRNS)
#define TCTL MT(MOD_LCTL, KC_TRNS)
#define TSFT MT(MOD_LSFT, KC_TRNS)

#define TRSFT MT(MOD_RSFT, KC_TRNS)
#define TRCTL MT(MOD_RCTL, KC_TRNS)
#define TRALT MT(MOD_RALT, KC_TRNS)
#define TRGUI MT(MOD_RGUI, KC_TRNS)

// Media keys
#define VOLU KC_AUDIO_VOL_UP
#define VOLD KC_AUDIO_VOL_DOWN
#define PP   KC_MEDIA_PLAY_PAUSE
#define STOP KC_MEDIA_STOP
#define NEXT KC_MEDIA_NEXT_TRACK
#define PREV KC_MEDIA_PREV_TRACK
#define BRUP KC_BRIGHTNESS_UP
#define BRDN KC_BRIGHTNESS_DOWN
#define MUTE KC_AUDIO_MUTE

// Mouse keys
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

// Global mode change keys
//#define TOMBASE TO(MIRYOKU_BASE)
#define TOQWERT TO(QWERTY)
#define TOCOLEM TO(COLEMAK_DH)
#define TOWORKM TO(WORKMAN)
#define TO_STEN TO(STENO)

// Toggle keys
#define TG_STEN TG(STENO)
#define TGHRM TG(HOME_ROW_MODS)

/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
/* /\* Keymap 0: QWERTY */
/*  * */
/*  * ╭────────┬──────┬──────┬──────┬──────┬──────╮                  ╭──────┬──────┬──────┬──────┬──────┬────────╮ */
/*  * │   \    │   Q  │   W  │   E  │   R  │   T  │                  │   Y  │   U  │   I  │   O  │   P  │   -    │ */
/*  * ├────────┼──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┼────────┤ */
/*  * │ Tab    │   A  │   S  │   D  │   F  │   G  │                  │   H  │   J  │   K  │   L  │   ;  │   '    │ */
/*  * ├────────┼──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┼────────┤ */
/*  * │ LShift │   Z  │   X  │   C  │   V  │   B  │                  │   N  │   M  │   ,  │   .  │   /  │ RShift │ */
/*  * └────────┴──────┴──────┴──────┼──────┼──────┼──────╮    ╭──────┼──────┼──────┼──────┴──────┴──────┴────────┘ */
/*  *                               │ Esc  │ Space│ Tab  │    │ Ret  │ BSpc │ Del  │ */
/*  *                               └──────┴──────┴──────┘    └──────┴──────┴──────┘ */
/*  *\/ */
/* [MIRYOKU_BASE]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,       */
/*   KC_TAB,  AGUI,    SALT,    DCTL,    FSFT,    KC_G,                                         KC_H,    JSFT,    KCTL,    ELALT,   SCLNGUI, KC_QUOT, */
/*   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
/*                                       TMED,    TNAV,    TMSE,                       TSYM,    TNUM,    TFUN                                         */

/* ) */
/* , */
/* [MIRYOKU_MEDIA]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                                      */
/*   _______, XXXXXXX, XXXXXXX, XXXXXXX, TOMBASE, TO_STEN,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                      XXXXXXX, PREV,    VOLD,    VOLU,    NEXT,    _______, */
/*   _______, XXXXXXX, XXXXXXX, TOFUN,   TOMED,   XXXXXXX,                                      XXXXXXX, XXXXXXX, BRDN,    BRUP,    XXXXXXX, _______, */
/*                                       XXXXXXX, XXXXXXX, XXXXXXX,                    STOP,    PP,      MUTE                                         */
/* ), */
/* [MIRYOKU_NAV]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TOMBASE, TO_STEN,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                      KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, */
/*   _______, XXXXXXX, XXXXXXX, TONUM,   TONAV,   XXXXXXX,                                      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, */
/*                                       XXXXXXX, XXXXXXX, XXXXXXX,                    KC_ENT,  KC_BSPC, KC_DEL                                       */
/* ), */
/* [MIRYOKU_MOUSE]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   _______, XXXXXXX, XXXXXXX, XXXXXXX, TOMBASE, TO_STEN,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                                      XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______, */
/*   _______, XXXXXXX, XXXXXXX, TOSYM,   TOMSE,   XXXXXXX,                                      XXXXXXX, MW_LEFT, MW_DOWN, MW_UP,   MW_RGHT, _______, */
/*                                       XXXXXXX, XXXXXXX, XXXXXXX,                    MSBTN2,  MSBTN1,  MSBTN3                                       */
  
/* ), */
/* [MIRYOKU_NUMBERS]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                      TO_STEN, TOMBASE, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,                                       XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______, */
/*   _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                                      XXXXXXX, TONUM,   TONAV,   XXXXXXX, XXXXXXX, _______, */
/*                                       KC_DOT,  KC_0,    KC_MINS,                    XXXXXXX, XXXXXXX, XXXXXXX */
/* ), */
/* [MIRYOKU_SYMBOLS]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                      TO_STEN, TOMBASE, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_DQT,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______, */
/*   _______, KC_TILDE,KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                      XXXXXXX, TOSYM,   TOMSE,   XXXXXXX, XXXXXXX, _______, */
/*                                       KC_LPRN,  KC_RPRN, KC_UNDS,                   XXXXXXX, XXXXXXX, XXXXXXX                                        */
/* ), */
/* [MIRYOKU_FUNCTIONS]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                  */
/*   _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_RBRC,                                      TO_STEN, TOMBASE, XXXXXXX, XXXXXXX, XXXXXXX, _______, */
/*   _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_EQL,                                       XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______, */
/*   _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_BSLS,                                      XXXXXXX, TOFUN,   TOMED,   XXXXXXX, XXXXXXX, _______, */
/*                                       KC_APP,  KC_SPC,  KC_TAB,                     XXXXXXX, XXXXXXX, XXXXXXX                                      */
/* ), */
/* [STENO]=LAYOUT_split_3x6_3( */
/*   // left hand                                                                      // right hand                                                 */
/*   ST_GEMN, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB, */
/*   XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                                      STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, */
/*   ST_TXBT, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                                      STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, */
/*                                       TOMBASE, STN_A,   STN_O,                      STN_E,   STN_U,   TOMBASE                                       */
/* ) */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: QWERTY
 *
 * ╭────────┬──────┬──────┬──────┬──────┬──────╮                  ╭──────┬──────┬──────┬──────┬──────┬────────╮
 * │   \    │   Q  │   W  │   E  │   R  │   T  │                  │   Y  │   U  │   I  │   O  │   P  │   -    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ Tab    │   A  │   S  │   D  │   F  │   G  │                  │   H  │   J  │   K  │   L  │   ;  │   '    │
 * ├────────┼──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┼────────┤
 * │ LShift │   Z  │   X  │   C  │   V  │   B  │                  │   N  │   M  │   ,  │   .  │   /  │ RShift │
 * └────────┴──────┴──────┴──────┼──────┼──────┼──────╮    ╭──────┼──────┼──────┼──────┴──────┴──────┴────────┘
 *                               │ Esc  │ Space│ Tab  │    │ Ret  │ BSpc │ Del  │
 *                               └──────┴──────┴──────┘    └──────┴──────┴──────┘
 */
[QWERTY]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  KC_BSLS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                      TMED,    TNAV,    TMSE,                       TSYM,    TNUM,    TFUN

),
[COLEMAK_DH]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
  _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                      _______, _______, _______,                    _______, _______, _______

),
[WORKMAN]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                         KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, _______,
  _______, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,                                         KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    _______,
  _______, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                                         KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                      _______, _______, _______,                    _______, _______, _______

),

[HOME_ROW_MODS]=LAYOUT_split_3x6_3(
  _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
  _______, TGUI,    TALT,    TCTL,    TSFT,    _______,                                      _______, TRSFT,   TRCTL,   TRALT,   TRGUI,   _______,
  _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,                    _______, _______, _______
),
[MIRYOKU_MEDIA]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, PREV,    VOLD,    VOLU,    NEXT,    _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, BRDN,    BRUP,    XXXXXXX, _______,
                                      XXXXXXX, XXXXXXX, XXXXXXX,                    STOP,    PP,      MUTE
),
[MIRYOKU_NAV]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                      XXXXXXX, XXXXXXX, XXXXXXX,                    KC_ENT,  KC_BSPC, KC_DEL
),
[MIRYOKU_MOUSE]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, MW_LEFT, MW_DOWN, MW_UP,   MW_RGHT, _______,
                                      XXXXXXX, XXXXXXX, XXXXXXX,                    MSBTN2,  MSBTN1,  MSBTN3
),
[MIRYOKU_NUMBERS]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                      KC_DOT,  KC_0,    KC_MINS,                    XXXXXXX, XXXXXXX, XXXXXXX
),
[MIRYOKU_SYMBOLS]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_DQT,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_TILDE,KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                      KC_LPRN,  KC_RPRN, KC_UNDS,                   XXXXXXX, XXXXXXX, XXXXXXX
),
[MIRYOKU_FUNCTIONS]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_RBRC,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_EQL,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_BSLS,                                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                      KC_APP,  KC_SPC,  KC_TAB,                     XXXXXXX, XXXXXXX, XXXXXXX
),
[MIRYOKU_LEFT_HAND]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  QK_BOOT, XXXXXXX, TOWORKM, TOCOLEM, TOQWERT, TG_STEN,                                      _______, _______, _______, _______, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, TGHRM,                                        _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, XXXXXXX, LKOP,    LKCUR,   XXXXXXX,                                      _______, _______, _______, _______, _______, _______,
                                      XXXXXXX, XXXXXXX, XXXXXXX,                    _______, _______, _______
),
[MIRYOKU_RIGHT_HAND]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  _______, _______,  _______,   _______,   _______,   _______,                               TG_STEN, TOQWERT, TOCOLEM, TOWORKM, XXXXXXX, _______,
  _______, _______,  _______,   _______,   _______,   _______,                               TGHRM,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
  _______, _______,  _______,   _______,   _______,   _______,                               XXXXXXX, LKCUR,   LKOP,    XXXXXXX, XXXXXXX, _______,
                                           _______,   _______,  _______,            XXXXXXX, XXXXXXX, XXXXXXX
),
[STENO]=LAYOUT_split_3x6_3(
  // left hand                                                                      // right hand
  ST_GEMN, STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,                                       STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
  XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                                      STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  ST_TXBT, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                                      STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                      TG_STEN, STN_A,   STN_O,                      STN_E,   STN_U,   TG_STEN
)
};

layer_state_t layer_mask_off(layer_state_t state, uint8_t layer) {
  return state & (~((layer_state_t)1 << layer));
}

layer_state_t layer_mask_on(layer_state_t state, uint8_t layer) {
  return state | ((layer_state_t)1 << layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t action_layer;
  layer_state_t new_layer_state;

  int normal_layers_mask = 0x7;
  int home_row_mods_mask = 0x8;
  uint32_t miryoku_layers_mask = 0x3F0;
  // Get the action for a key given a layer and key position
  // action_t action_for_key(uint8_t layer, keypos_t key)
  
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
    case LKCUR: {
      // Lock current Miryoku layer. Don't touch the home row mod layer.
      // Make the current set of layers the default. This prevents changes to layer state from the release of momentary layers from doing things I don't want.
      default_layer_set(layer_state);
      /* uint8_t active_miryoku_layer = get_highest_layer(layer_state & miryoku_layers_mask); */
      /* new_layer_state = (layer_state_t)1 << active_miryoku_layer; */
      /* default_layer_set(new_layer_state); */
      /* new_layer_state = new_layer_state | (layer_state & (normal_layers_mask | home_row_mods_mask)); */
      /* layer_state_set(new_layer_state); */
      return false;
      break;
    }
    case LKOP: { 
      uint8_t active_miryoku_layer = get_highest_layer(layer_state & miryoku_layers_mask);
      uint8_t layer_to_set = (((active_miryoku_layer - 3) * 6) % 7) + 3;
      new_layer_state = (layer_state_t)1 << layer_to_set;
      new_layer_state = new_layer_state | (layer_state & (normal_layers_mask | home_row_mods_mask));
      default_layer_set(new_layer_state);
      layer_state_set(new_layer_state);
      return false;
      break;
    }
    case QK_TO ... QK_TO_MAX:
      // Use the TO macro to switch active layers, as I want to use this from momentary
      // layers, and without this the momentary layer restore on release interferes with
      // what I want.
      action_layer = keycode & 0xF;
      new_layer_state = (layer_state_t)1 << action_layer;
      // Preserve home row mod state
      new_layer_state = new_layer_state | (layer_state & home_row_mods_mask);
      default_layer_set(new_layer_state);
      layer_state_set(new_layer_state);
      return false;
      break;
    default:
      break;
    }
  }

  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX: {
    // Is this a mod-tap from the HOME_ROW_MODS layer?
    switch(get_highest_layer(layer_state)) {
    case HOME_ROW_MODS: {
      // Taken from keymap_common.c
      action_t action = {};
      int mod = mod_config((keycode >> 0x8) & 0x1F);
      action_t underlying_key_action = action_for_key(get_highest_layer(layer_state & normal_layers_mask), record->event.key);
      action.code = ACTION_MODS_TAP_KEY(mod, underlying_key_action.code);
      process_action(record, action);
      return false;
      break;
    }
    }
  }
  default:
    break;
  }
  
  return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  return layer_mask_off(state, HOME_ROW_MODS);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  int normal_layers_mask = 0x3FF;
  layer_state_t new_layer_state = state;
  switch(get_highest_layer(state & normal_layers_mask)) {
  case QWERTY:
  case COLEMAK_DH:
  case WORKMAN:
  case HOME_ROW_MODS:
    new_layer_state = layer_mask_off(new_layer_state, MIRYOKU_LEFT_HAND);
    new_layer_state = layer_mask_off(new_layer_state, MIRYOKU_RIGHT_HAND);
    return new_layer_state;
    break;
  case MIRYOKU_MEDIA:
  case MIRYOKU_NAV:
  case MIRYOKU_MOUSE:
    new_layer_state = layer_mask_on(new_layer_state, MIRYOKU_LEFT_HAND);
    new_layer_state = layer_mask_off(new_layer_state, MIRYOKU_RIGHT_HAND);
    return new_layer_state;
    break;
  case MIRYOKU_SYMBOLS:
  case MIRYOKU_NUMBERS:
  case MIRYOKU_FUNCTIONS:
    new_layer_state = layer_mask_off(new_layer_state, MIRYOKU_LEFT_HAND);
    new_layer_state = layer_mask_on(new_layer_state, MIRYOKU_RIGHT_HAND);
    return new_layer_state;
    break;
  default:
    return state;
    break;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  // Do not support "double tap to repeat tap key" for thumb layer keys.
  // This should allow for quicker use of thumb layers.
  switch (keycode) {
  case TMED:
  case TNAV:
  case TMSE:
  case TSYM    :
  case TNUM:
  case TFUN:
    return 0;
  default:
    return QUICK_TAP_TERM;
  }
}

void keyboard_post_init_user(void) {
  layer_on(HOME_ROW_MODS);
#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_BOLT);
#endif
}
