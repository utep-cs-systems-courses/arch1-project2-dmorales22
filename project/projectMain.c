#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

void main(void) 
{  
  configureClocks();
  buzzer_init();
  buzzer_set_period(1000);
  switch_init();
  led_init();

  or_sr(0x18);  // CPU off, GIE on
} 
