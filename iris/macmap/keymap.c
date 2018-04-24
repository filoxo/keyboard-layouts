#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

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

#define KC_ KC_TRNS
#define TRNS KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      ESC  ,   1   ,   2   ,   3   ,   4   ,   5   ,                     6   ,   7   ,   8   ,   9   ,   0   ,  BSPC ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TILD ,   Q   ,   W   ,   E   ,   R   ,   T   ,                     Y   ,   U   ,   I   ,   O   ,   P   ,  BSLS ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TAB  ,   A   ,   S   ,   D   ,   F   ,   G   ,                     H   ,   J   ,   K   ,   L   ,  SCLN ,  QUOT ,
  //|------|-------|-------|-------|-------|-------|-------   -------|-------|-------|-------|-------|-------|-------|
      LCTL ,  LALT ,   Z   ,   X   ,   C   ,   V   ,  RSFT ,    LSFT ,   B   ,   N   ,   M   ,  COMM ,  DOT  ,  SLSH ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                     LOWR  , LGUI  , BSPC ,      SPC ,  ENT  ,  RASE
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_LOWER] = LAYOUT_kc(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TRNS , TRNS  , TRNS  , TRNS  , TRNS  , TRNS  ,                    TRNS ,  TRNS ,  TRNS ,  MINS ,  EQL  ,  DEL  ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TRNS , TRNS  , TRNS  , TRNS  , TRNS  , TRNS  ,                    TRNS ,  TRNS ,  TRNS ,  LCBR ,  RCBR ,  TRNS ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TRNS , TRNS  , TRNS  , TRNS  , TRNS  , TRNS  ,                    LEFT ,  DOWN ,   UP  , RIGHT ,  TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------|-------   -------|-------|-------|-------|-------|-------|-------|
      TRNS , TRNS  , TRNS  , TRNS  , TRNS  , TRNS  , TRNS ,     TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                     TRNS  , TRNS  , DEL  ,     TRNS ,  TRNS ,  TRNS 
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_RAISE] = LAYOUT_kc(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
       F1  ,   F2  ,   F3  ,   F4  ,   F5  ,   F6  ,                    F7   ,  F8   ,  F9   ,  F10  ,  F11  ,  F12  ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TRNS ,  TRNS ,  TRNS ,  F14  ,  F15  ,  TRNS ,                    MPRV ,  MPLY ,  MNXT ,  MUTE ,  VOLD ,  VOLU ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,                    TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
      TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS , TRNS ,     TRNS ,  TRNS ,  TRNS  , TRNS ,  TRNS ,  TRNS ,  TRNS , 
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                      TRNS ,  TRNS , TRNS ,     TRNS ,  TRNS , TRNS
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_ADJUST] = LAYOUT(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
     RESET , DEBUG , TRNS  , TRNS  , TRNS  , TRNS  ,                    TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
     TRNS  ,RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,  TRNS ,                    TRNS ,  TRNS ,  TRNS ,  TRNS , TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
     TRNS  ,RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,  TRNS ,                    TRNS ,  TRNS ,  TRNS ,  TRNS , TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
    BL_STEP, TRNS  , TRNS  , TRNS  , TRNS  , TRNS  , TRNS  ,    TRNS ,  TRNS ,  TRNS ,  TRNS ,  TRNS , TRNS ,  TRNS ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                      TRNS ,  TRNS , TRNS ,     TRNS ,  TRNS ,  TRNS
  //                               .-------|-------/-----/     \-----|-------|-------.
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
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
