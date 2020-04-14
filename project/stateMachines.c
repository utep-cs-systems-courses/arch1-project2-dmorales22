#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "p1_interrupt_handler.h"
#include "state_advance_a.h"

int current_state = 0;
int START = 0;
int STATE1 = 1;
int STATE2 = 2;
int STATE3 = 3;
int STATE4 = 4; 

void state_menu()
{
  if(B_SW1_switch_state_down){
    current_state = START;
  }

  if(SW1_switch_state_down) { //If switch 1 on the board is pressed then it changes state to STATE1. 
    current_state = STATE1;
  }

  if(SW2_switch_state_down) { //If switch 2 on the board is pressed then it changes state to STATE2. 
    current_state = STATE2;
  }
  
  if(SW3_switch_state_down) { //If switch 3 on the board is pressed then it changes state to STATE3. 
    current_state = STATE3;
  }

  if(SW4_switch_state_down) { //If switch 4 on the board is pressed then it changes state to STATE4. 
    current_state = STATE4;
  }
}

void flasher_light()		//Uses switch cases to alternate green and red.
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

void state_advance()		/* changes the devices functions with states using switch cases*/
{
  state_advance_s(); //This calls the assembly-variant of code below in state_advance_a.s
  
  /*
  blink_max = 50; 
  switch (current_state) {
  case START: //START state has no lights on and buzzer is silent(to reduce headaches).
    led_update(0,0);
    buzzer_set_period(0); 
    state_menu(); //Every case will run the state_menu so you can change states.
    break;

  case STATE1: //STATE1 sets buzzer to a frequency and red light on.
    led_update(0,1); //Only red light on
    buzzer_set_period(2000);
    state_menu();
    break;

  case STATE2: //STATE2 sets buzzer to a frequency and green light on.
    led_update(1,0);
    buzzer_set_period(1000);
    state_menu();
    break;

  case STATE3:
    blink_max = 50; //Sets the blink_max value for blinking lights. 
    buzzer_set_period(500);
    flasher_light(); //Runs method to allow for blinking lights
    state_menu();
    break;

  case STATE4:
    blink_max = 1; //Sets the blink_max value lowest value to dim the lights.
    buzzer_set_period(200);
    flasher_light(); //Runs flasher method to dim the leds.
    state_menu();
    break;
  }
  */
}