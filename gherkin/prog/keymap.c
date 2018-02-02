#include "gherkin.h"
#include "action_layer.h"

// Friendly layer names
enum gherkin_layers {
  _QWERTY,
  _LAYER1,
  _LAYER2,
  _LAYER3
};

#define SPC_GUI GUI_T(KC_SPC)
#define ENT_UPPR LT(UPPR, KC_ENT)
#define BSL_FNRW LT(FNRW, KC_BSLS)
#define BRT_DN KC_F14
#define BRT_UP KC_F15
#define MRWD_BASE LT(BASE, KC_MRWD)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX XXXXXXX

#define SFT_A MT(MOD_LSFT, KC_A)
#define SFT_L MT(MOD_LSFT, KC_L)
#define LT1_ENT LT(1, KC_ENT)
#define LT3_Z LT(3, KC_Z)
#define CTL_X MT(MOD_LCTL, KC_X)
#define ALT_C MT(MOD_LALT, KC_C)
#define GUI_V MT(MOD_LGUI, KC_V)
#define GUI_B MT(MOD_LGUI, KC_B)
#define ALT_N MT(MOD_LALT, KC_N)
#define CTL_M MT(MOD_LCTL, KC_M)
#define LT2_ESC LT(2, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP(
    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,     KC_U,      KC_I,      KC_O,      KC_P, 
    SFT_A,     KC_S,      KC_D,      KC_F,      KC_G,      KC_H,     KC_J,      KC_K,      SFT_L,     LT1_ENT, 
    LT3_Z,     CTL_X,     ALT_C,     GUI_V,     KC_BSPC,   KC_SPC,   GUI_B,     ALT_N,     CTL_M,     LT2_ESC
  )
  [_LAYER1] = KEYMAP(
    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,     KC_7,      KC_8,      KC_9,      KC_0, 
    KC_TAB,    KC_BSLS,   KC_GRV,    KC_MINS,   KC_EQL,    KC_LBRC,  KC_RBRC,   KC_SCLN,   KC_QUOT,   XXXXXXX, 
    KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_MPLY,   KC_BSPC,   KC_SPC,   KC_COMM,   KC_DOT,    KC_SLSH,   XXXXXXX
  ),
  [_LAYER2] = KEYMAP(
    KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,  KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN, 
    KC_TAB,    KC_PIPE,   KC_TILD,   KC_UNDS,   KC_PLUS,   KC_LCBR,  KC_RCBR,   KC_COLN,   KC_DQUO,   XXXXXXX, 
    KC_MUTE,   KC_MPRV,   KC_MNXT,   KC_MPLY,   KC_BSPC,   KC_SPC,   KC_LABK,   KC_RABK,   KC_QUES,   XXXXXXX
  ),
  [_LAYER3] = KEYMAP(
		KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,    KC_F7,     KC_F8,     KC_F9,     KC_F10, 
    KC_F11,    KC_F12,    KC_F13,    KC_F14,    XXXXXXX,   XXXXXXX,  XXXXXXX,   XXXXXXX,   KC_UP,     XXXXXXX, 
    XXXXXXX,   RESET,     XXXXXXX,   XXXXXXX,   KC_BSPC,   KC_SPC,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_RGHT),
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
