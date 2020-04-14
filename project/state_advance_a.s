	.arch msp430g2553
	.p2align 1,0

	.data
state: .word 0

	.text
	.global state_advance_s
state_advance_s:
	mov #50, &blink_max
	cmp #0, &current_state ;if state is 0
	jz START

	cmp #1, &current_state ;if state is 1
	jz STATE1

	cmp #2, &current_state ;if state is 2
	jz STATE2

	cmp #3, &current_state ;if state is 3
	jz STATE3

	cmp #4, &current_state ;if state is 4
	jz STATE4

	jmp end

START: ;Start switch case, C-variant in stateMachines.c
	mov #0, r12
	mov #0, r13
	call #led_update ;led_update(0,0)
	mov #0, r12
	call #buzzer_set_period ;buzzer_set_period(0)
	call #state_menu ;state_menu to switch states
	jmp end

STATE1: 
	mov #0, r12
	mov #1, r13
	call #led_update ;led_update(0,1) red led only
	mov #2000, r12
	call #buzzer_set_period ;buzzer_set_period(2000)
	call #state_menu 
	jmp end

STATE2: 
	mov #1, r12
	mov #0, r13
	call #led_update ;led_update(1,0) green led only
	mov #1000, r12
	call #buzzer_set_period ;buzzer_set_period(1000)
	call #state_menu
	jmp end

STATE3: 
	mov #50, &blink_max ;changes led blinker speed
	mov #500, r12
	call #buzzer_set_period ;buzzer_set_period(500)
	call #flasher_light ;calls method that makes leds flash
	call #state_menu 
	jmp end

STATE4: 
	mov #1, &blink_max ;changes led blinker speed to lowest value
	mov #200, r12
	call #buzzer_set_period ;buzzer_set_period(200)
	call #flasher_light ;uses flasher_light to make the leds appear dim
	call #state_menu
	jmp end

end:
	pop r0 ;ends the program
	