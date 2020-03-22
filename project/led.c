#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_led_state = 0, green_led_state = 0;
unsigned char leds_changed = 0;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output

  SW1_switch_state_changed = 1;
  SW2_switch_state_changed = 1;
  SW3_switch_state_changed = 1;
  SW4_switch_state_changed = 1;
  B_SW1_switch_state_changed = 1;

  led_update();
}

void led_update(){
  if (SW1_switch_state_changed || SW2_switch_state_changed || SW3_switch_state_changed || SW4_switch_state_changed || B_SW1_switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= (SW1_switch_state_down || SW2_switch_state_down || SW3_switch_state_down || SW4_switch_state_down || B_SW1_switch_state_down) ? LED_GREEN : 0;

    ledFlags |= (SW1_switch_state_down || SW2_switch_state_down || SW3_switch_state_down || SW4_switch_state_down || B_SW1_switch_state_down) ? 0 : LED_RED;


    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds

    //P2OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    //P2OUT |= ledFlags;         // set bits for on leds
  }
  
  B_SW1_switch_state_changed = 0; 
  SW1_switch_state_changed = 0; /* effectively boolean */
  SW2_switch_state_changed = 0;
  SW3_switch_state_changed = 0;
  SW4_switch_state_changed = 0;
}