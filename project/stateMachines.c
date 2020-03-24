#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "p1_interrupt_handler.h"

static enum {START, STATE1, STATE2, STATE3, STATE4} current_state = START;

char state_menu()
{
  if(SW1_switch_state_down) {
    current_state = STATE1;
    return 1;
  }

  if(SW2_switch_state_down) {
    current_state = STATE2;
    return 1;
  }
  
  if(SW3_switch_state_down) {
    current_state = STATE3;
    return 1;
  }

  if(SW4_switch_state_down) {
    current_state = STATE4;
    return 1;
  }

  if(B_SW1_switch_state_down) {
    current_state= START;
    return 1;
  }
  return 0;
}

void flasher_light()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    led_update(1,0);
    state = 1;
    break;
  case 1:
    led_update(0,1);
    state = 0;
    break;
  }
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  blink_max = 50; 
  switch (current_state) {
  case START:
    led_update(0,0);
    buzzer_set_period(0); 
    changed = state_menu();
    break;

  case STATE1: 
    led_update(0,1);
    buzzer_set_period(1500);
    changed = state_menu();
    break;

  case STATE2:
    led_update(1,0);
    buzzer_set_period(500);
    changed = state_menu();
    break;

  case STATE3:
    blink_max = 50;
    buzzer_set_period(200);
    flasher_light();
    changed = state_menu();
    break;

  case STATE4:
    blink_max = 1;
    buzzer_set_period(180);
    flasher_light();
    changed = state_menu();
    break;
  }
}