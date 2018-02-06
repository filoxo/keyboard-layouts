// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

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
[_QWERTY] = KEYMAP( /* Qwerty */
   Q   ,   W   ,   E   ,   R   ,   T   ,                   Y   ,   U   ,   I   ,   O   ,   P   ,
   A   ,   S   ,   D   ,   F   ,   G   ,                   H   ,   J   ,   K   ,   L   ,KC_BSLS,
   Z   ,   X   ,   C   ,   V   ,   B   ,                   N   ,   M   ,KC_COMM, KC_DOT,KC_SLSH,
 KC_ESC, KC_TAB,KC_LGUI,KC_LCTL, RAISE ,KC_BSPC, KC_SPC, LOWER ,KC_LSFT,KC_SCLN,KC_QUOT, KC_ENT
),

[_RAISE] = KEYMAP(
   1   ,   2   ,   3   ,   4   ,   5   ,                   6   ,   7   ,   8   ,   9   ,   0   ,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[_LOWER] = KEYMAP(
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
),

[_ADJUST] = KEYMAP(
 RESET ,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
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