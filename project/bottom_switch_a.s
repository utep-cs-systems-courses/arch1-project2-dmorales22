	.arch msp430g2553
	.p2align 1,0
	.text

	.global b_sw1_s
	
b_sw1_s:
	cmp.b #0, r12
	jz end
	mov r14, r13
	ret
end:
	mov r13, r13
	ret
	