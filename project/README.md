# My Buzzer Toy
It's a simple implementation of the buzzy toy. Pressing buttons the board changes buzzer frequency and led lights. 

## How to Use It
You need to compile timerLib. So follow the steps below:

**make install**

**make**

Then load **project.elf** into your MSP430. 

## What it Does
As stated before, pressing the buttons just generate different frequencies and led light patterns. 
The switches maintain and transition the states to perform different functions.

Bottom switch: Is the START state when the device starts and when pressed. The LED lights are off and buzzer is not used. NOTE: The state transition code for this button is written in assembly.

Top switch 1: Switches to STATE1 when pressed. Only the red LED is on and the buzzer set to 2000 cycles.

Top switch 2: Switches to STATE2 when pressed. Only the green LED is on and the buzzer set to 1000 cycles.

Top switch 3: Switches to STATE3 when pressed. Red and green LEDs flash and the buzzer set to 500 cycles. 

Top switch 4: Switches to STATE4 when pressed. Red and green LEDs are on but dimmed. The buzzer set to 200 cycles.

## To Clean Up
To removes .o and .elf files:

**make clean**
