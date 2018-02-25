// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define _______ KC_TRNS
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP(
KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,
KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_ENT ,
KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,
KC_ESC ,KC_TAB ,KC_LGUI,KC_LCTL, RAISE ,KC_BSPC, KC_SPC, LOWER ,KC_LSFT,KC_LALT,KC_SCLN,KC_QUOT
),

[_RAISE] = KEYMAP(
KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,
KC_GRV ,KC_TILD,_______,_______,_______,                _______,_______,KC_LBRC,KC_RBRC,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[_LOWER] = KEYMAP(
KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,
_______,_______,_______,_______,_______,                KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[_ADJUST] = KEYMAP(
 RESET ,_______,_______,MU_MOD ,MU_TOG ,                _______,KC_MUTE,KC_VOLD,KC_VOLU,_______,
_______,_______,KC_F14 ,KC_F15 ,RGB_TOG,                _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
)
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}