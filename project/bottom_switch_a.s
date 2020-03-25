	.arch msp430g2553
	.p2align 1,0
	.text

	.global b_sw1_s
	
b_sw1_s:
	cmp.b #0, r12 ;; if(B_SW1_switch_state_down != 0)
	jnz end  
	mov r13, r12 ;; return START state if bottom switch is pressed
	ret
end:
	mov r14, r12 ;; Returns current_state if bottom switch not pressed.
	ret
	