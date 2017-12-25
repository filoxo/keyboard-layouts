#include "gherkin.h"
#include "action_layer.h"

//Friendly Layer Names
enum gherkin_layers {
  _QWERTY,
  _UPPERS,
  _FNROW
};

#define BASE TO(_QWERTY)
#define UPPR TO(_UPPERS)
#define FNRW TO(_FNROW)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_ENT,  
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_LGUI,  KC_SPC,   KC_B,     KC_N,     KC_M,     UPPR
  ),
  [_UPPERS] = KEYMAP(
    KC_ESC,   KC_GRV,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_1,     KC_2,     KC_3,     KC_BSPC,
    KC_TAB,   KC_BSLS,  KC_SCLN,  KC_QUOT,  KC_LEFT,  KC_RGHT,  KC_4,     KC_5,     KC_6,     KC_0,
    KC_CAPS,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP  ,  KC_DOWN,  KC_7,     KC_8,     KC_9,     FNRW
  ),
  [_FNROW] = KEYMAP(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MFFD,  KC_MPLY,  KC_MRWD,
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,    BASE
  ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    (void)event;

    switch (id) {

    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        DDRD |= (1 << 5); PORTD &= ~(1 << 5);
    } else {
        DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRB |= (1 << 0); PORTB &= ~(1 << 0);
    } else {
        DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_KANA)) {
        
    } else {
        
    }

}
