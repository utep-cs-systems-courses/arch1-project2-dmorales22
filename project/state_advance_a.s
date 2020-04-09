	.arch msp430g2553
	.p2align 1,0

	.data
state: .word 0

	.text
	.global state_advance_s
state_advance_s:
	mov #50, &blink_max
	mov r12, &state
	
	cmp #5, &state
	jz START

	cmp #1, &state
	jz STATE1

	cmp #2, &state
	jz STATE2

	cmp #3, &state
	jz STATE3

	cmp #4, &state
	jz STATE4

	jmp end

START: 
	mov #0, r12
	mov #0, r13
	call #led_update
	mov #0, r12
	call #buzzer_set_period
	call #state_menu
	jmp end

STATE1: 
	mov #0, r12
	mov #1, r13
	call #led_update
	mov #2000, r12
	call #buzzer_set_period
	call #state_menu
	jmp end

STATE2: 
	mov #1, r12
	mov #0, r13
	call #led_update
	mov #1000, r12
	call #buzzer_set_period
	call #state_menu
	jmp end

STATE3: 
	mov #50, &blink_max
	mov #500, r12
	call #buzzer_set_period
	call #flasher_light
	call #state_menu
	jmp end

STATE4: 
	mov #1, &blink_max
	mov #200, r12
	call #buzzer_set_period
	call #flasher_light
	call #state_menu
	jmp end

end:
	pop r0 
	