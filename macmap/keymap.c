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
  A_TAB = 0,
  Q_ESC = 1,
  P_BSP = 2,
  DT_CM = 3
};

#define BASE TO(_QWERTY)
#define UPPR TO(_UPPERS)
#define FNRW TO(_FNROW)
#define SPC_GUI GUI_T(KC_SPC)
#define UPPR_ENT LT(UPPR, KC_ENT)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
    TD(Q_ESC),   KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     TD(P_BSP),
    TD(A_TAB),   KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     UPPR_ENT,
    KC_Z,        KC_X,     KC_C,     KC_V,     KC_B,     SPC_GUI,  KC_N,     KC_M,     TD(DT_CM),KC_BSPC
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
  [A_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
  [Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
  [P_BSP] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC),
  [DT_CM] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM)
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
