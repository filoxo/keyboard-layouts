#include "gherkin.h"
#include "action_layer.h"

// Friendly layer names
enum gherkin_layers {
  _QWERTY,
  _UPPERS,
  _FNROW
};

// Friendly tap dance action names
enum {
  TD_A_TAB = 0,
  TD_Q_ESC = 1,
  TD_P_BSP = 2
};

#define BASE TO(_QWERTY)
#define UPPR TO(_UPPERS)
#define FNRW TO(_FNROW)
#define SPC_SFT SFT_T(KC_SPC)
#define BSP_CMD GUI_T(KC_BSPC)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
    TD(TD_Q_ESC),KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     TD(TD_P_BSP),
    TD(TD_A_TAB),KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_ENT,
    KC_Z,        KC_X,     KC_C,     KC_V,     BSP_CMD,  SPC_SFT,  KC_B,     KC_N,     KC_M,     UPPR
  ),
  [_UPPERS] = KEYMAP(
    KC_ESC,   KC_GRV,   KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_7,     KC_8,     KC_9,     KC_BSPC,
    KC_TAB,   KC_BSLS,  KC_SCLN,  KC_QUOT,  KC_LEFT,  KC_RGHT,  KC_4,     KC_5,     KC_6,     KC_0,
    KC_CAPS,  KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP  ,  KC_DOWN,  KC_1,     KC_2,     KC_3,     FNRW
  ),
  [_FNROW] = KEYMAP(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_VOLU,  KC_MUTE,
    KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MFFD,  KC_MPLY,  KC_MRWD,
    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_F14,   KC_F15,   BASE
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

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [TD_P_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC)
};

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
