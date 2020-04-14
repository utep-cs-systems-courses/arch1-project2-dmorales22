# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: project.elf 

#additional rules for files
project.elf: ${COMMON_OBJECTS} projectMain.o state_advance_a.o stateMachines.o p1_interrupt_handler.o led.o switches.o buzzer.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

clean:
	rm -rf *.o *.elf h lib timerLib/clocksTimer.o timerLib/sr.o
install:
	(cd timerLib; make install)
