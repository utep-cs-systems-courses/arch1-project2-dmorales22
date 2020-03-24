#include <msp430.h>
#include "timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

void main(void) 
{  
  configureClocks();
  buzzer_init();
  switch_init();
  led_init();
  enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
} 