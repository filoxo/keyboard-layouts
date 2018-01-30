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
#define ____ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_UP UP
#define KC_DOWN DN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      ESC  ,   1   ,   2   ,   3   ,   4   ,   5   ,                     6   ,   7   ,   8   ,   9   ,   0   ,  BSPC ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TILD ,   Q   ,   W   ,   E   ,   R   ,   T   ,                     Y   ,   U   ,   I   ,   O   ,   P   ,  BSLS ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TAB  ,   A   ,   S   ,   D   ,   F   ,   G   ,                     H   ,   J   ,   K   ,   L   ,  SCLN ,  QUOT ,
  //|------|-------|-------|-------|-------|-------|-------   -------|-------|-------|-------|-------|-------|-------|
      LCTL ,   Z   ,   X   ,   C   ,   V   ,   B   ,  UP   ,     DN  ,   N   ,   M   ,  COMM ,  DOT  ,  SLSH ,  RALT ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                     LOWR  , LGUI  , BSPC ,      SPC ,  LSFT ,  RASE
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_LOWER] = KC_KEYMAP(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      TILD , EXLM  ,  AT   , HASH  ,  DLR  , PERC  ,                    CIRC ,  AMPR ,  ASTR ,  LPRN ,  RPRN ,  BSPC ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
       RST ,   1   ,   2   ,   3   ,   4   ,   5   ,                     6   ,   7   ,   8   ,   9   ,   0   ,       ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
       DEL ,       ,  LEFT , RGHT  ,  UP   , LBRC  ,                    RBRC ,   P4  ,   P5  ,   P6  ,  PLUS ,  PIPE ,
  //|------|-------|-------|-------|-------|-------|-------   -------|-------|-------|-------|-------|-------|-------|
      BL_S ,       ,       ,       , DOWN  , LCBR  , LPRN ,     RPRN ,  RCBR ,   P1  ,   P2  ,   P3  ,  MINS ,       ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                           ,       ,  DEL ,      DEL ,       ,   P0 
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_RAISE] = KC_KEYMAP(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
       F1  ,   F2  ,   F3  ,   F4  ,   F5  ,   F6  ,                    F7   ,  F8   ,  F9   ,  F10  ,  F11  ,  F12
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
           ,       ,       ,       ,       ,       ,                    MPRV ,  MPLY ,  MNXT ,  MUTE ,  VOLD ,  VOLU ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
           ,  MPRV ,  MNXT ,  VOLU ,  PGUP ,  UNDS ,                    EQL  , HOME  ,       ,       ,       , BSLS  ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
     MUTE  ,  MSTP , MPLY  , VOLD  ,  PGDN ,  MINS ,      ,          ,  PLUS , END   ,       ,       ,       ,       , 
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                           ,       ,      ,          ,       ,    
  //                               .-------|-------/-----/     \-----|-------|-------.
  ),

  [_ADJUST] = KEYMAP(
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
      ____ ,  ____ ,  ____ ,  ____ ,  ____ ,  ____ ,                    ____ ,  ____ ,  ____ ,  ____ ,  ____ ,  ____ ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
    RGB_TOG,RGB_MOD,RGB_HUI,RGB_SAI,RGB_VAI,  ____ ,                    ____ ,  ____ ,  ____ ,  ____ , ____ ,  ____ ,
  //|------|-------|-------|-------|-------|-------.                 .-------|-------|-------|-------|-------|-------|
     RESET , DEBUG ,RGB_HUD,RGB_SAD,RGB_VAD,  ____ ,                    ____ ,  ____ ,  ____ ,  ____ , ____ ,  ____ ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
    BL_STEP,  ____ ,  ____ ,  ____ ,  ____ ,  ____ ,  ____ ,    ____ ,  ____ ,  ____ ,  ____ ,  ____ , ____ ,  ____ ,
  //|------|-------|-------|-------|-------|-------|------/   \------|-------|-------|-------|-------|-------|-------|
                                      ____ ,  ____ ,  ____ ,    ____ ,  ____ ,  ____
  //                               .-------|-------/-----/     \-----|-------|-------.
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
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
