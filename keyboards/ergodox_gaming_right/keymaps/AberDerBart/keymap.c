#include "keymap_int.h"

void ergodox_right_led_1_on(void)    { DDRB |=  (1<<5); PORTB |=  (1<<5); }
void ergodox_right_led_2_on(void)    { DDRB |=  (1<<6); PORTB |=  (1<<6); }
void ergodox_right_led_3_on(void)    { DDRB |=  (1<<7); PORTB |=  (1<<7); }

void ergodox_right_led_1_off(void)   { DDRB &= ~(1<<5); PORTB &= ~(1<<5); }
void ergodox_right_led_2_off(void)   { DDRB &= ~(1<<6); PORTB &= ~(1<<6); }
void ergodox_right_led_3_off(void)   { DDRB &= ~(1<<7); PORTB &= ~(1<<7); }

void keyboard_pre_init_user(void) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
}

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
          break;
      case 1:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          break;
      case 2:
          ergodox_right_led_1_on();
          break;
      case 3:
          ergodox_right_led_2_on();
          break;
      case 4:
          ergodox_right_led_3_on();
          break;
      default:
          break;
  }
  return state;
}

