.LC0:
	.ascii	"%d\012\000"
	.align 2

.LC1:
	.ascii "%d\000"
	.align 2
.text
.global main
main:
	@start code here
	bl myScan
	mov r2,r1
	bl myScan 
	mov r3 , r1
	mov r5 , r1
	loop:
	bl myScan
	mov r4 ,r1
	cmp r3 ,r4
	movls r3 ,r4
	cmp r4, r5
	movls r5,r4
	sub r2, r2, #1
	cmp r2,#1
	bne loop
	mov r1 ,r3
	bl myPrint
	mov r1, r5
	bl myPrint
	@end code
	bl exit


.global	myPrint
myPrint:
	@prints an integer present in r1
	stmfd	sp!,{r0,r2,r3,r7, lr}
	add	r7, sp, #0
	adr 	r0, .LC0
	bl	printf
	mov	r0, #0
	ldmfd	sp!,{r0,r2,r3,r7, pc}


.global myScan
myScan:
	@scans an integer and returns it in r1
	stmfd   sp!, {r0,r2,r3,r7, lr}
	sub 	sp, sp, #8
	add     r7, sp, #0
	adr     r0, .LC1
	add	r1, sp, #4
	bl      scanf
	ldr	r1, [sp, #4]
	mov     r0, #0
	add	sp, sp, #8
	ldmfd	sp!,{r0,r2,r3,r7, pc}

